#!/usr/bin/env python3
"""
context.py - Symbol context extractor for decomp-toolkit dwarfdump output.

Parses a dwarfdump.txt and produces one context file per function:
  <output_dir>/<source_file_path>/<FunctionName>.c

Also scans a directory of .h files to build a named-struct registry.
Any anonymous struct whose fields match a named struct is replaced with
that struct's name throughout the output.

Usage:
  python context.py --dump dwarfdump.txt --out ./context
  python context.py --dump dwarfdump.txt --out ./context --headers ./include
  python context.py --dump dwarfdump.txt --out ./context --headers ./include --verbose
"""

import os
import re
import sys
import json
import argparse
from pathlib import Path
from dataclasses import dataclass, field

# ---------------------------------------------------------------------------
# PPC -> MIPS register translation
# ---------------------------------------------------------------------------

PPC_TO_MIPS: dict[str, str] = {
    "r0":  "$zero", "r1":  "$at",  "r2":  "$v0",  "r3":  "$v1",
    "r4":  "$a0",   "r5":  "$a1",  "r6":  "$a2",  "r7":  "$a3",
    "r8":  "$t0",   "r9":  "$t1",  "r10": "$t2",  "r11": "$t3",
    "r12": "$t4",   "r13": "$t5",  "r14": "$t6",  "r15": "$t7",
    "r16": "$s0",   "r17": "$s1",  "r18": "$s2",  "r19": "$s3",
    "r20": "$s4",   "r21": "$s5",  "r22": "$s6",  "r23": "$s7",
    "r24": "$t8",   "r25": "$t9",  "r26": "$k0",  "r27": "$k1",
    "r28": "$gp",   "r29": "$sp",  "r30": "$fp",  "r31": "$ra",
}

# Matches a register annotation that can be translated:
#   r4           -> $a0
#   r29+0x40     -> $sp+0x40   (stack slot — translate base only)
# Does NOT match:
#   f0, f12, f20 (float regs — left as-is)
#   r29+0x40     base part translated but offset kept verbatim
_RE_REG_ANNOT = re.compile(
    r'\b(?P<base>r(?:3[01]|[12]?[0-9]))(?P<offset>[+][^,) ]+)?\b'
)


def translate_reg(reg: str, mips_regs: bool) -> str:
    """
    Translate a register annotation string from PPC rN notation to MIPS $name.
    Floats (fN) and stack offsets are handled gracefully:
      - fN             -> left unchanged
      - rN             -> $name
      - rN+0xOFFSET    -> $name+0xOFFSET   (stack slot)
    If mips_regs is False, returns reg unchanged.
    """
    if not mips_regs or not reg:
        return reg

    def _replace(m: re.Match) -> str:
        base   = m.group("base")
        offset = m.group("offset") or ""
        mips   = PPC_TO_MIPS.get(base, base)
        return mips + offset

    return _RE_REG_ANNOT.sub(_replace, reg)


def translate_sig_regs(text: str, mips_regs: bool) -> str:
    """
    Translate register annotations in two styles:
      /* rN */        block-comment style (used in signatures and param lists)
      // rN           line-comment style  (used in body variable declarations)
      // rN+0xOFFSET  stack slot style
    Float registers (fN) are left untouched in both styles.
    """
    if not mips_regs:
        return text

    def _translate_token(reg_token: str) -> str:
        """Translate a single rN or rN+offset token."""
        return _RE_REG_ANNOT.sub(
            lambda mm: PPC_TO_MIPS.get(mm.group("base"), mm.group("base"))
                       + (mm.group("offset") or ""),
            reg_token,
        )

    # 1. Block comments:  /* rN */  /* rN+0xOFFSET */
    def _replace_block(m: re.Match) -> str:
        return f"/* {_translate_token(m.group(1))} */"

    text = re.sub(r'/\*\s*([^*]+?)\s*\*/', _replace_block, text)

    # 2. Line-end comments:  // rN   or   // rN+0xOFFSET
    #    Match only when the token after // looks like a register (rN),
    #    not a float reg (fN) or arbitrary comment text.
    def _replace_line(m: re.Match) -> str:
        return f"// {_translate_token(m.group(1))}"

    text = re.sub(r'//\s*(r(?:3[01]|[12]?[0-9])(?:[+][^\s,)]+)?)', _replace_line, text)

    return text



# ---------------------------------------------------------------------------
# Data structures
# ---------------------------------------------------------------------------

@dataclass
class Field:
    """One field inside a struct: name, raw type string, offset, size."""
    name: str
    type_str: str
    offset: int   # -1 if unknown
    size: int     # -1 if unknown


@dataclass
class StructDef:
    """A struct/union definition, named or anonymous."""
    tag: str            # 'struct' | 'union'
    name: str           # '' for anonymous
    fields: list[Field]
    total_size: int     # -1 if unknown
    raw: str            # verbatim text as it appeared in the dump/header


@dataclass
class LocalVar:
    name: str
    type_str: str
    register: str
    line: int


@dataclass
class Function:
    name: str
    signature: str       # verbatim first line including params
    body: str            # balanced { ... }
    source_file: str
    addr_start: str
    addr_end: str
    locals: list[LocalVar] = field(default_factory=list)
    dump_line: int = 0


@dataclass
class CompileUnit:
    source_file: str
    producer: str
    language: str
    # Structs declared at file scope in this CU (no Code range header)
    file_structs: list[StructDef] = field(default_factory=list)
    functions: list[Function] = field(default_factory=list)


# ---------------------------------------------------------------------------
# Path helper
# ---------------------------------------------------------------------------

def normalise_path(raw: str) -> str:
    p = re.sub(r'^[A-Za-z]:[/\\]', '', raw)
    return p.replace('\\', '/')


# ---------------------------------------------------------------------------
# Brace-balanced extractor
# ---------------------------------------------------------------------------

def extract_balanced(text: str, start: int) -> tuple[str, int]:
    """Given position of '{', return (body_with_braces, pos_after_})."""
    depth, i, n = 0, start, len(text)
    in_str = in_chr = False
    prev = ''
    while i < n:
        c = text[i]
        if c == '"' and prev != '\\' and not in_chr:
            in_str = not in_str
        elif c == "'" and prev != '\\' and not in_str:
            in_chr = not in_chr
        if not in_str and not in_chr:
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
                if depth == 0:
                    return text[start:i + 1], i + 1
        prev = c
        i += 1
    return text[start:], n


# ---------------------------------------------------------------------------
# Struct field parser
# ---------------------------------------------------------------------------

# Matches one field line inside a struct body:
#   <type> <name>; // offset 0xN, size 0xM
# Works for plain types; nested structs are handled separately.
RE_FIELD_SIMPLE = re.compile(
    r'^[ \t]+'
    r'(?P<type>'
        r'(?:(?:signed|unsigned|const|volatile|long|short)\s+)*'
        r'(?:void\s*\*+|float|double|'
        r'(?:struct|union|enum)\s+\w+|'
        r'\w+)'
        r'(?:\s*\*+)?'
    r')\s+'
    r'(?P<name>\w+)'
    r'(?:\s*\[[^\]]*\])?'
    r'\s*;'
    r'(?:\s*//\s*offset\s+(?P<off>0x[0-9A-Fa-f]+),\s*size\s+(?P<sz>0x[0-9A-Fa-f]+))?',
    re.MULTILINE,
)

RE_TOTAL_SIZE = re.compile(r'//\s*total size:\s*(?P<sz>0x[0-9A-Fa-f]+)')


def parse_fields_from_body(body: str) -> list[Field]:
    """
    Extract flat field list from a struct body string (the part inside { }).
    Skips nested struct/union sub-bodies to avoid double-counting.
    """
    fields: list[Field] = []
    # Flatten nested structs: replace their bodies with placeholders so we
    # only match the outermost field declarations.
    flat = _flatten_nested(body)
    for m in RE_FIELD_SIMPLE.finditer(flat):
        off_s = m.group('off')
        sz_s  = m.group('sz')
        fields.append(Field(
            name     = m.group('name'),
            type_str = m.group('type').strip(),
            offset   = int(off_s, 16) if off_s else -1,
            size     = int(sz_s,  16) if sz_s  else -1,
        ))
    return fields


def _flatten_nested(text: str) -> str:
    """Replace all inner { ... } blocks with a placeholder so the outer
    field regex does not see inner field lines."""
    result = list(text)
    depth = 0
    inside_start = -1
    for i, c in enumerate(text):
        if c == '{':
            depth += 1
            if depth == 2:       # entering a nested block
                inside_start = i
        elif c == '}':
            if depth == 2:       # leaving a nested block
                for j in range(inside_start, i + 1):
                    result[j] = ' '
            depth -= 1
    return ''.join(result)


# ---------------------------------------------------------------------------
# Named struct scanner  (.h files)
# ---------------------------------------------------------------------------

# Matches:  typedef struct TagName { ... } AliasName;
#        or struct TagName { ... };
RE_NAMED_STRUCT_H = re.compile(
    r'(?:typedef\s+)?'
    r'(?P<tag>struct|union)\s+'
    r'(?P<tname>\w+)\s*'
    r'\{(?P<body>[^{}]*(?:\{[^{}]*\}[^{}]*)*)\}'   # one level of nesting
    r'\s*(?P<alias>\w+)?\s*;',
    re.DOTALL,
)


def scan_headers(header_dir: str, verbose: bool = False) -> list[StructDef]:
    """Walk header_dir and collect all named struct/union definitions."""
    named: list[StructDef] = []
    hdir = Path(header_dir)
    if not hdir.is_dir():
        print(f"[warn] --headers path is not a directory: {header_dir}",
              file=sys.stderr)
        return named

    for hfile in sorted(hdir.rglob('*.h')):
        try:
            text = hfile.read_text(encoding='utf-8', errors='replace')
        except OSError:
            continue
        text = _strip_c_comments(text)
        for m in RE_NAMED_STRUCT_H.finditer(text):
            tname = m.group('tname')
            alias = m.group('alias') or ''
            # Prefer the typedef alias as the canonical name when present
            canon = alias if alias and alias != tname else tname
            body  = '{' + m.group('body') + '}'
            flds  = parse_fields_from_body(body)
            sd = StructDef(
                tag        = m.group('tag'),
                name       = canon,
                fields     = flds,
                total_size = -1,
                raw        = m.group(0),
            )
            named.append(sd)
            if verbose:
                print(f"    [header struct] {canon}  ({len(flds)} fields)")

    if verbose:
        print(f"  [headers] {len(named)} named struct(s) from {header_dir}")
    return named


def _strip_c_comments(text: str) -> str:
    result, i, n = [], 0, len(text)
    while i < n:
        if text[i:i+2] == '/*':
            end = text.find('*/', i + 2)
            if end == -1:
                break
            result.append('\n' * text[i:end+2].count('\n'))
            i = end + 2
        elif text[i:i+2] == '//':
            end = text.find('\n', i)
            result.append('\n')
            i = (end + 1) if end != -1 else n
        else:
            result.append(text[i])
            i += 1
    return ''.join(result)


# ---------------------------------------------------------------------------
# Struct fingerprint + matcher
# ---------------------------------------------------------------------------

def _struct_fingerprint(fields: list[Field]) -> tuple:
    """
    Hashable key for a struct.
    Primary key:   (field_name, offset, size)  -- used when offsets are known.
    Fallback key:  (field_name,)               -- used when no offsets present.
    We store BOTH so that dump structs (with offsets) can match header structs
    (without offsets) by field-name sequence alone.
    """
    return tuple((f.name, f.offset, f.size) for f in fields)


def _struct_fingerprint_names_only(fields: list[Field]) -> tuple:
    return tuple(f.name for f in fields)


def build_fingerprint_map(named: list[StructDef]) -> dict[tuple, str]:
    """
    Map fingerprint -> canonical struct name.
    Two entries per struct: one with offsets (all -1 for headers),
    one names-only.  The lookup in replace_anon_structs tries both.
    """
    fp_map: dict[tuple, str] = {}
    for sd in named:
        if not sd.fields:
            continue
        # Full key (offset-based) -- useful when both sides have offsets
        fp_full  = _struct_fingerprint(sd.fields)
        # Names-only key -- used when header lacks offsets
        fp_names = _struct_fingerprint_names_only(sd.fields)
        fp_map[fp_full]  = sd.name
        fp_map[fp_names] = sd.name
    return fp_map


# ---------------------------------------------------------------------------
# Anonymous struct replacement
# ---------------------------------------------------------------------------

# Matches an anonymous struct/union block anywhere in text:
#   struct /* @anonN */ { ... }
RE_ANON_STRUCT = re.compile(
    r'(?P<tag>struct|union)\s+/\*[^*]*\*/\s*\{',
)


def replace_anon_structs(text: str, fp_map: dict[tuple, str]) -> str:
    """
    Walk `text` and replace every anonymous struct literal whose field
    fingerprint matches a known named struct with just `struct KnownName`.
    Unknown anonymous structs are left verbatim.
    """
    if not fp_map:
        return text

    result = []
    pos = 0
    while pos < len(text):
        m = RE_ANON_STRUCT.search(text, pos)
        if not m:
            result.append(text[pos:])
            break

        # Everything before this match
        result.append(text[pos:m.start()])

        # Extract the balanced body starting at the '{'
        brace_pos = text.index('{', m.start())
        body, end_pos = extract_balanced(text, brace_pos)

        # Parse fields; try offset-based key first, then names-only
        fields   = parse_fields_from_body(body)
        fp_full  = _struct_fingerprint(fields)
        fp_names = _struct_fingerprint_names_only(fields)
        canon    = fp_map.get(fp_full) or fp_map.get(fp_names)

        if canon:
            result.append(f"{m.group('tag')} {canon}")
            # Skip past the closing '}' — but keep any trailing text
            # (e.g. "* varName; // offset ...") that followed the body
            pos = end_pos
        else:
            # Unknown — keep verbatim up through the opening brace
            result.append(text[m.start():brace_pos + 1])
            pos = brace_pos + 1

    return ''.join(result)


# ---------------------------------------------------------------------------
# Compile-unit header pattern
# ---------------------------------------------------------------------------

# Matches with OR without the "Code range:" line
RE_CU_BLOCK = re.compile(
    r'/\*\s*\n'
    r'[ \t]*Compile unit:\s*(?P<src>[^\n]+)\n'
    r'[ \t]*Producer:\s*(?P<producer>[^\n]+)\n'
    r'[ \t]*Language:\s*(?P<language>[^\n]+)\n'
    r'(?:[ \t]*Code range:[^\n]+\n)?'   # optional
    r'[ \t]*\*/',
    re.MULTILINE,
)

RE_RANGE = re.compile(
    r'^// Range:\s*(?P<start>0x[0-9A-Fa-f]+)\s*->\s*(?P<end>0x[0-9A-Fa-f]+)',
    re.MULTILINE,
)

# Function signature: ends with '{' on the same logical line
# Params may span multiple lines (inline struct definitions), so we
# match up to the first '{' that follows the closing ')'.
RE_FUNC_SIG_START = re.compile(
    r'^(?P<ret>'
        r'(?:static\s+|inline\s+|extern\s+)*'
        r'(?:const\s+)?'
        r'(?:(?:unsigned|signed|long|short)\s+)*'
        r'\w[\w\s\*]*?'
    r')'
    r'(?P<name>\w+)'
    r'\s*\(',
    re.MULTILINE,
)

RE_LOCAL_VAR = re.compile(
    r'^(?P<indent>[ \t]+)'
    r'(?P<type>'
        r'(?:(?:signed|unsigned|const|volatile|long|short)\s+)*'
        r'(?:'
            r'struct\s+/\*[^*]*\*/|'
            r'struct\s+\w+|'
            r'union\s+/\*[^*]*\*/|'
            r'union\s+\w+|'
            r'enum\s+/\*[^*]*\*/|'
            r'enum\s+\w+|'
            r'\w+'
        r')'
        r'(?:\s*\*+\s*|\s+)'
        r'(?:\(\s*\*\s*)?'
    r')'
    r'(?P<name>\w+)'
    r'(?:\s*\)\s*\([^)]*\))?'
    r'(?:\s*\[[^\]]*\])?'
    r'\s*;'
    r'(?:\s*//\s*(?P<reg>\S+))?',
    re.MULTILINE,
)


# ---------------------------------------------------------------------------
# Function signature extractor
# ---------------------------------------------------------------------------

def extract_function_from(segment: str, range_end: int) -> tuple[str, str, str, int] | None:
    """
    Starting just after a // Range: comment, find the function signature
    and body. The signature may contain multi-line inline struct definitions
    in its parameter list.

    Returns (name, signature_text, body_text, pos_after_body) or None.
    """
    # Find the function name + opening paren
    sig_m = RE_FUNC_SIG_START.search(segment, range_end)
    if not sig_m:
        return None

    # Now find the matching ')' for the param list, then the '{' after it.
    # We need to handle nested parens (function-pointer params).
    paren_start = segment.index('(', sig_m.start())
    depth, i, n = 0, paren_start, len(segment)
    while i < n:
        if segment[i] == '(':
            depth += 1
        elif segment[i] == ')':
            depth -= 1
            if depth == 0:
                param_end = i
                break
        i += 1
    else:
        return None

    # Skip optional qualifiers between ')' and '{'
    brace_search = segment[param_end + 1:]
    brace_rel    = brace_search.find('{')
    if brace_rel == -1:
        return None

    brace_abs = param_end + 1 + brace_rel

    # The full signature is everything from the function name to just before '{'
    sig_text = segment[sig_m.start():brace_abs].rstrip()
    name     = sig_m.group('name')

    body, end_pos = extract_balanced(segment, brace_abs)

    return name, sig_text, body, end_pos


# ---------------------------------------------------------------------------
# Main parser
# ---------------------------------------------------------------------------

def parse_dump(dump_text: str, verbose: bool = False) -> list[CompileUnit]:
    units: list[CompileUnit] = []
    cu_matches = list(RE_CU_BLOCK.finditer(dump_text))

    if not cu_matches:
        print("[warn] No compile-unit headers found.", file=sys.stderr)
        return units

    for idx, cu_m in enumerate(cu_matches):
        seg_start = cu_m.end()
        seg_end   = cu_matches[idx + 1].start() if idx + 1 < len(cu_matches) else len(dump_text)
        segment   = dump_text[seg_start:seg_end]

        cu = CompileUnit(
            source_file = cu_m.group('src').strip(),
            producer    = cu_m.group('producer').strip(),
            language    = cu_m.group('language').strip(),
        )

        if verbose:
            print(f"  [cu] {cu.source_file}")

        # Check if this CU has a Range comment (i.e. contains a function)
        range_m = RE_RANGE.search(segment)

        if range_m is None:
            # This is a file-scope CU: it contains only type declarations,
            # no functions.  We still want to record it so its structs can
            # be used for matching, but we produce no function files from it.
            units.append(cu)
            if verbose:
                print(f"    [file-scope CU, no functions]")
            continue

        # Parse all functions in this segment
        pos = 0
        while pos < len(segment):
            range_m = RE_RANGE.search(segment, pos)
            if not range_m:
                break

            result = extract_function_from(segment, range_m.end())
            if result is None:
                pos = range_m.end()
                continue

            name, sig_text, body, end_pos = result

            dump_offset = seg_start + range_m.start()
            dump_line   = dump_text[:dump_offset].count('\n') + 1

            func = Function(
                name        = name,
                signature   = sig_text,
                body        = body,
                source_file = cu.source_file,
                addr_start  = range_m.group('start'),
                addr_end    = range_m.group('end'),
                dump_line   = dump_line,
            )

            # Locals: only lines indented <=12 spaces to skip struct fields
            for lm in RE_LOCAL_VAR.finditer(body):
                if len(lm.group('indent')) > 12:
                    continue
                func.locals.append(LocalVar(
                    name     = lm.group('name'),
                    type_str = lm.group('type').strip(),
                    register = (lm.group('reg') or '').strip(),
                    line     = dump_line + body[:lm.start()].count('\n'),
                ))

            cu.functions.append(func)

            if verbose:
                print(f"    [fn] {func.name:<40} "
                      f"{func.addr_start}->{func.addr_end}  "
                      f"{len(func.locals)} local(s)")

            pos = end_pos

        units.append(cu)

    return units


# ---------------------------------------------------------------------------
# Context file writer
# ---------------------------------------------------------------------------

def write_context_file(
        func: Function,
        out_path: Path,
        fp_map: dict[tuple, str],
        func_sig_index: dict[str, str] | None = None,
        header_func_index: dict[str, str] | None = None,
        asm_dir: str | None = None,
        mips_regs: bool = False,
) -> None:
    out_path.parent.mkdir(parents=True, exist_ok=True)

    func_sig_index    = func_sig_index    or {}
    header_func_index = header_func_index or {}

    # Apply struct substitution then optional register translation
    sig  = translate_sig_regs(replace_anon_structs(func.signature, fp_map), mips_regs)
    body = translate_sig_regs(replace_anon_structs(func.body,      fp_map), mips_regs)

    # Resolve callees from .s file
    callee_rows: list[tuple[str, str | None, str]] = []
    if asm_dir:
        targets = read_jal_targets(func, asm_dir, verbose=False)
        if targets:
            callee_rows = resolve_callees(
                targets, func_sig_index, header_func_index, fp_map)

    L: list[str] = []
    a = L.append

    a(f"/* {'=' * 70} */")
    a(f"/* context.py -- auto-generated                                         */")
    a(f"/* {'=' * 70} */")
    a(f"/*")
    a(f"   source   : {func.source_file}")
    a(f"   range    : {func.addr_start} -> {func.addr_end}")
    a(f"   function : {func.name}")
    a(f"*/")
    a("")

    # -- Local variables ------------------------------------------------------
    if func.locals:
        a("/* -- local variables " + "-" * 49 + " */")
        a("/*")
        nw = max(len(lv.name) for lv in func.locals) + 2
        tw = max(len(replace_anon_structs(lv.type_str, fp_map))
                 for lv in func.locals) + 2
        for lv in func.locals:
            t   = replace_anon_structs(lv.type_str, fp_map)
            reg = f"// {translate_reg(lv.register, mips_regs)}" if lv.register else ""
            a(f"   {lv.name:<{nw}} {t:<{tw}} {reg}".rstrip())
        a("*/")
        a("")

    # -- Called functions -----------------------------------------------------
    if callee_rows:
        a("/* -- called functions " + "-" * 48 + " */")
        for name, sig_c, source in callee_rows:
            if source == 'unknown':
                a(f"/* TODO: unknown extern -- {name} */")
            else:
                a(f"/* [{source}] */")
                a(f"{sig_c};")
        a("")

    # -- Function body --------------------------------------------------------
    a("/* -- function " + "-" * 56 + " */")
    a(sig)
    a(body)
    a("")

    out_path.write_text('\n'.join(L), encoding='utf-8')


# ---------------------------------------------------------------------------
# JSON index
# ---------------------------------------------------------------------------

def write_index(units: list[CompileUnit], out_dir: Path) -> None:
    index: dict = {}
    for cu in units:
        rel = normalise_path(cu.source_file)
        entry = index.setdefault(rel, {
            'source_file': cu.source_file,
            'producer':    cu.producer,
            'language':    cu.language,
            'functions':   [],
        })
        for f in cu.functions:
            entry['functions'].append({
                'name':      f.name,
                'signature': f.signature,
                'range':     f"{f.addr_start}->{f.addr_end}",
                'dump_line': f.dump_line,
                'locals':    [{'name': lv.name, 'type': lv.type_str,
                               'reg': lv.register} for lv in f.locals],
            })

    idx = out_dir / '_index.json'
    idx.write_text(json.dumps(index, indent=2, ensure_ascii=False),
                   encoding='utf-8')
    print(f"[index] {idx}")



# ---------------------------------------------------------------------------
# .s file reader  —  extract jal call targets
# ---------------------------------------------------------------------------

RE_JAL = re.compile(r'(?:^[ \t]*(?:/\*[^*]*\*/\s*)?|\s)jal\s+(?P<target>\w+)', re.MULTILINE)


def asm_path_for(func: "Function", asm_dir: str) -> Path | None:
    """
    Derive the .s file path for a function. Tries two layouts:
      1. <asm_dir>/ps2/veronica/prog/en19/bhEne19_Br00.s   (normal: subfolder per source file)
      2. <asm_dir>/ps2/veronica/prog/en19.s                 (flat: single .s for the whole file)
    Returns the first path that exists, or the primary path if neither exists.
    """
    rel  = normalise_path(func.source_file)   # ps2/veronica/prog/en19.c
    stem = Path(rel).with_suffix('')           # ps2/veronica/prog/en19
    primary  = Path(asm_dir) / stem / f"{func.name}.s"
    fallback = Path(asm_dir) / f"{stem}.s"
    if primary.is_file():
        return primary
    if fallback.is_file():
        return fallback
    return primary   # return primary so the miss message is informative


_asm_miss_count = 0
_asm_hit_count  = 0

def read_jal_targets(func: "Function", asm_dir: str,
                     verbose: bool = False) -> list[str]:
    """Return sorted unique list of function names called via jal in the .s."""
    global _asm_miss_count, _asm_hit_count
    s_path = asm_path_for(func, asm_dir)
    if s_path is None or not s_path.is_file():
        _asm_miss_count += 1
        if _asm_miss_count <= 3:
            print(f"  [asm] not found: {s_path}", file=sys.stderr)
        elif _asm_miss_count == 4:
            print(f"  [asm] (further misses suppressed)", file=sys.stderr)
        return []
    _asm_hit_count += 1
    try:
        text = s_path.read_text(encoding='utf-8', errors='replace')
    except OSError:
        return []
    targets = {m.group('target') for m in RE_JAL.finditer(text)}
    targets.discard(func.name)   # ignore self-calls / tail calls
    return sorted(targets)


# ---------------------------------------------------------------------------
# Header function declaration scanner
# ---------------------------------------------------------------------------

# Matches a function declaration (not a definition) in a header:
#   returntype funcname ( params );
RE_HDR_FUNC_DECL = re.compile(
    r'^[ \t]*'
    r'(?:extern\s+)?'
    r'(?:static\s+)?'
    r'(?:inline\s+)?'
    r'(?:const\s+)?'
    r'(?:(?:unsigned|signed|long|short)\s+)*'
    r'(?:\w[\w\s\*:<>]*?)'          # return type (non-greedy)
    r'(?P<n>\w+)'                      # function name
    r'\s*\('
    r'(?P<params>[^)]*)'
    r'\)'
    r'\s*;',
    re.MULTILINE,
)


def scan_header_functions(header_dir: str,
                          verbose: bool = False) -> dict[str, str]:
    """
    Scan all .h files under header_dir and return
    { function_name: full_declaration_line }.
    """
    result: dict[str, str] = {}
    hdir = Path(header_dir)
    if not hdir.is_dir():
        return result

    for hfile in sorted(hdir.rglob('*.h')):
        try:
            raw = hfile.read_text(encoding='utf-8', errors='replace')
        except OSError:
            continue
        clean = _strip_c_comments(raw)
        for m in RE_HDR_FUNC_DECL.finditer(clean):
            name = m.group('n')
            # Prefer first occurrence (typically the most authoritative header)
            if name not in result:
                result[name] = m.group(0).strip().rstrip(';')

    return result


# ---------------------------------------------------------------------------
# Callee resolution
# ---------------------------------------------------------------------------

def resolve_callees(
    targets: list[str],
    func_sig_index: dict[str, str],
    header_func_index: dict[str, str],
    fp_map: dict[tuple, str],
) -> list[tuple[str, str | None, str]]:
    """
    For each called function name return a tuple:
      (name, signature_or_None, source)
    where source is one of: 'dump' | 'header' | 'unknown'
    """
    rows = []
    for name in targets:
        if name in func_sig_index:
            sig = replace_anon_structs(func_sig_index[name], fp_map)
            rows.append((name, sig, 'dump'))
        elif name in header_func_index:
            sig = header_func_index[name]
            rows.append((name, sig, 'header'))
        else:
            rows.append((name, None, 'unknown'))
    return rows

# ---------------------------------------------------------------------------
# Orchestrator
# ---------------------------------------------------------------------------

def run(dump_path: str, out_dir: str,
        header_dir: str | None, asm_dir: str | None,
        verbose: bool, mips_regs: bool = False) -> None:
    out = Path(out_dir)
    out.mkdir(parents=True, exist_ok=True)

    # Build named-struct registry from headers
    named_structs: list[StructDef] = []
    if header_dir:
        print(f"[headers] scanning {header_dir} ...")
        named_structs = scan_headers(header_dir, verbose=verbose)
    fp_map = build_fingerprint_map(named_structs)
    if fp_map:
        print(f"[headers] {len(fp_map)} unique struct fingerprint(s) loaded")

    print(f"[read]  {dump_path}")
    dump_text = Path(dump_path).read_text(encoding='utf-8', errors='replace')

    print(f"[parse] scanning compile units ...")
    units = parse_dump(dump_text, verbose=verbose)

    if not units:
        print("[warn]  Nothing parsed.")
        return

    total_fn = sum(len(cu.functions) for cu in units)
    total_cu = len(units)
    print(f"[parse] {total_cu} compile unit(s), {total_fn} function(s)")

    # Build a project-wide function index: name -> signature
    # Used to resolve jal call targets in .s files.
    func_sig_index: dict[str, str] = {}
    for cu in units:
        for f in cu.functions:
            if f.name not in func_sig_index:
                func_sig_index[f.name] = f.signature

    # Also scan headers for function declarations not in the dump
    header_func_index: dict[str, str] = {}
    if header_dir:
        header_func_index = scan_header_functions(header_dir, verbose=verbose)
        if header_func_index:
            print(f"[headers] {len(header_func_index)} function declaration(s) from headers")

    # Show the user what the first .s path will look like so they can verify
    if asm_dir:
        for cu in units:
            for f in cu.functions:
                expected = asm_path_for(f, asm_dir)
                print(f"[asm]   first expected .s path: {expected}")
                print(f"[asm]   exists: {expected.is_file()}")
                break
            else:
                continue
            break

    written = 0
    for cu in units:
        if not cu.functions:
            continue
        # Group functions under their source file (strip extension for folder)
        rel_src = normalise_path(cu.source_file)
        func_dir = out / str(Path(rel_src).with_suffix(''))

        for func in cu.functions:
            out_file = func_dir / f"{func.name}.c"
            if verbose:
                print(f"  [write] {out_file.relative_to(out)}")
            write_context_file(func, out_file, fp_map,
                               func_sig_index, header_func_index,
                               asm_dir, mips_regs=mips_regs)
            written += 1

    write_index(units, out)
    if asm_dir:
        print(f"[asm]   {_asm_hit_count} .s file(s) found, {_asm_miss_count} missing")
    print(f"[done]  {written} context file(s) -> {out_dir}/")


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main() -> None:
    ap = argparse.ArgumentParser(
        description='Build per-function context files from a decomp-toolkit dwarfdump.'
    )
    ap.add_argument('--dump',    required=True,
                    help='Path to the dwarfdump.txt file')
    ap.add_argument('--out',     default='./context',
                    help='Output root directory (default: ./context)')
    ap.add_argument('--headers', default=None,
                    help='Directory of .h files to scan for named struct definitions')
    ap.add_argument('--asm', default=None,
                    help='Root of the asm directory (e.g. config/asm)')
    ap.add_argument('--mips-regs', action='store_true',
                    help='Translate PPC rN register annotations to MIPS $name in output')
    ap.add_argument('--verbose', '-v', action='store_true')
    args = ap.parse_args()

    if not os.path.isfile(args.dump):
        print(f"[error] File not found: {args.dump}", file=sys.stderr)
        sys.exit(1)

    run(args.dump, args.out, args.headers, args.asm, args.verbose,
        mips_regs=args.mips_regs)


if __name__ == '__main__':
    main()