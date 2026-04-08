#!/usr/bin/env python3
"""
context.py — Symbol context extractor for decomp-toolkit dwarfdump output.

Parses a dwarfdump.txt produced by decomp-toolkit (C-like format with
compile-unit headers, range comments, and register annotations) and produces
one context file per function:

  <output_dir>/<source_file_path>/<FunctionName>.c

Each context file contains:
  - All inline struct / union / enum types declared inside the function
  - All local variables with their types and register assignments
  - The full function signature + body, verbatim

Usage:
  python context.py --dump dwarfdump.txt --out ./context
  python context.py --dump dwarfdump.txt --out ./context --verbose
"""

import os
import re
import sys
import json
import argparse
from pathlib import Path
from dataclasses import dataclass, field


# ---------------------------------------------------------------------------
# Data structures
# ---------------------------------------------------------------------------

@dataclass
class LocalVar:
    name: str
    type_str: str       # full type text (may be anonymous struct/enum)
    register: str       # e.g. "r13", "r2", "" if not annotated
    line: int           # line number inside the dump file


@dataclass
class Function:
    name: str
    signature: str          # e.g. "static void bhEne19_Br00(struct BH_PWORK * ewP)"
    body: str               # everything from '{' to matching '}'
    source_file: str        # original Windows path from compile unit header
    addr_start: str         # e.g. "0x1F0C70"
    addr_end: str           # e.g. "0x1F1370"
    locals: list[LocalVar] = field(default_factory=list)
    dump_line: int = 0


@dataclass
class CompileUnit:
    source_file: str
    producer: str
    language: str
    functions: list[Function] = field(default_factory=list)


# ---------------------------------------------------------------------------
# Path helper
# ---------------------------------------------------------------------------

def normalise_source_path(raw: str) -> str:
    """
    Turn a Windows absolute path into a portable relative path.
    e.g. "C:\\ps2\\veronica\\prog\\en19.c" -> "ps2/veronica/prog/en19.c"
    """
    p = re.sub(r'^[A-Za-z]:[/\\]', '', raw)
    return p.replace('\\', '/')


# ---------------------------------------------------------------------------
# Brace-balanced body extractor
# ---------------------------------------------------------------------------

def extract_balanced(text: str, start: int) -> tuple[str, int]:
    """
    `start` must point at an opening '{'.
    Returns (body_including_outer_braces, pos_after_closing_brace).
    Skips over string literals and char literals to avoid false matches.
    """
    depth = 0
    i = start
    n = len(text)
    in_str = False
    in_chr = False
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

    # Unbalanced — return what we have
    return text[start:], n


# ---------------------------------------------------------------------------
# Patterns
# ---------------------------------------------------------------------------

# The block comment that opens each compile unit
RE_CU_BLOCK = re.compile(
    r'/\*\s*\n'
    r'[ \t]*Compile unit:\s*(?P<src>[^\n]+)\n'
    r'[ \t]*Producer:\s*(?P<producer>[^\n]+)\n'
    r'[ \t]*Language:\s*(?P<language>[^\n]+)\n'
    r'(?:[ \t]*Code range:[^\n]+\n)?'
    r'[ \t]*\*/',
    re.MULTILINE,
)

# Range comment:  // Range: 0x1F0C70 -> 0x1F1370
RE_RANGE = re.compile(
    r'^// Range:\s*(?P<start>0x[0-9A-Fa-f]+)\s*->\s*(?P<end>0x[0-9A-Fa-f]+)',
    re.MULTILINE,
)

# Function signature on the line that follows a range comment.
# Must end with '{' (the opening brace of the body).
# Accepts: optional-qualifiers  return-type  name ( anything ) optional-qualifiers {
RE_FUNC_SIG = re.compile(
    r'^(?P<sig>'
        r'(?:static\s+|inline\s+|extern\s+|__cdecl\s+|__stdcall\s+)*'
        r'(?:const\s+)?'
        r'(?:(?:unsigned|signed|long|short)\s+)*'
        r'\w[\w\s\*:<>]*?'              # return type (non-greedy)
        r'(?P<name>\w+)'                # function name
        r'\s*\([^)]*\)'                 # parameter list
        r'(?:\s*const)?'
    r')\s*\{',
    re.MULTILINE,
)

# Local variable line inside a function body:
#   <indent> <type> <name> [array] ; [// register]
# The type may be "struct /* @anonN */" or a plain identifier.
RE_LOCAL_VAR = re.compile(
    r'^(?P<indent>[ \t]+)'
    r'(?P<type>'
        r'(?:(?:signed|unsigned|const|volatile|long|short)\s+)*'
        r'(?:'
            r'struct\s+/\*[^*]*\*/|'
            r'union\s+/\*[^*]*\*/|'
            r'enum\s+/\*[^*]*\*/|'
            r'\w+'
        r')'
        r'(?:\s*\*+\s*|\s+)'
        r'(?:\(\s*\*\s*)?'              # optional function-pointer opening
    r')'
    r'(?P<name>\w+)'
    r'(?:\s*\)\s*\([^)]*\))?'          # function-pointer closing + params
    r'(?:\s*\[[^\]]*\])?'              # optional array subscript
    r'\s*;'
    r'(?:\s*//\s*(?P<reg>\S+))?',      # optional  // rN  register annotation
    re.MULTILINE,
)


# ---------------------------------------------------------------------------
# Parser
# ---------------------------------------------------------------------------

def parse_dump(dump_text: str, verbose: bool = False) -> list[CompileUnit]:
    units: list[CompileUnit] = []

    cu_matches = list(RE_CU_BLOCK.finditer(dump_text))
    if not cu_matches:
        print("[warn] No compile-unit headers found in dump.", file=sys.stderr)
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

        pos = 0
        while pos < len(segment):
            # Find the next // Range: comment
            range_m = RE_RANGE.search(segment, pos)
            if not range_m:
                break

            # The function signature must appear within a short window after
            # the range comment (allow blank lines / other range comments
            # that decomp-toolkit sometimes emits inside nested blocks)
            window_start = range_m.end()
            window_end   = min(window_start + 512, len(segment))
            window       = segment[window_start:window_end]

            sig_m = RE_FUNC_SIG.search(window)
            if not sig_m:
                pos = range_m.end()
                continue

            # Locate the '{' in the original segment text
            brace_abs = window_start + sig_m.end() - 1   # sig ends just after '{'

            body_text, body_end_rel = extract_balanced(segment, brace_abs)
            body_end_abs = body_end_rel  # relative to segment

            # Compute the line in the full dump for the function start
            dump_offset = seg_start + range_m.start()
            dump_line   = dump_text[:dump_offset].count('\n') + 1

            func = Function(
                name        = sig_m.group('name'),
                signature   = sig_m.group('sig').strip(),
                body        = body_text,
                source_file = cu.source_file,
                addr_start  = range_m.group('start'),
                addr_end    = range_m.group('end'),
                dump_line   = dump_line,
            )

            # Collect local variables from the body
            for lm in RE_LOCAL_VAR.finditer(body_text):
                # Skip lines that are deeply nested (offset > 1 indent level)
                # to avoid picking up struct field declarations
                indent_len = len(lm.group('indent'))
                if indent_len > 12:
                    # Heuristic: real locals in decomp-toolkit output are usually
                    # indented 4-12 spaces; struct fields inside anon structs
                    # are indented further.
                    continue
                func.locals.append(LocalVar(
                    name     = lm.group('name'),
                    type_str = lm.group('type').strip(),
                    register = (lm.group('reg') or '').strip(),
                    line     = dump_line + body_text[:lm.start()].count('\n'),
                ))

            cu.functions.append(func)

            if verbose:
                loc_count = len(func.locals)
                print(f"    [fn] {func.name:<40} "
                      f"{func.addr_start}->{func.addr_end}  "
                      f"{loc_count} local(s)")

            pos = body_end_abs

        units.append(cu)

    return units


# ---------------------------------------------------------------------------
# Context file writer
# ---------------------------------------------------------------------------

def write_context_file(func: Function, out_path: Path) -> None:
    out_path.parent.mkdir(parents=True, exist_ok=True)

    L: list[str] = []
    a = L.append

    bar = '=' * 70

    a(f"/* {bar} */")
    a(f"/* context.py — auto-generated, do not edit manually               */")
    a(f"/* {bar} */")
    a(f"/*")
    a(f"   source   : {func.source_file}")
    a(f"   range    : {func.addr_start} -> {func.addr_end}")
    a(f"   function : {func.name}")
    a(f"*/")
    a("")

    # -- Local variables table ------------------------------------------------
    if func.locals:
        a("/* -- local variables " + "-" * 49 + " */")
        a("/*")
        name_w = max(len(lv.name) for lv in func.locals) + 2
        type_w = max(len(lv.type_str) for lv in func.locals) + 2
        for lv in func.locals:
            reg = f"// {lv.register}" if lv.register else ""
            a(f"   {lv.name:<{name_w}} {lv.type_str:<{type_w}} {reg}".rstrip())
        a("*/")
        a("")

    # -- Full function verbatim -----------------------------------------------
    a("/* -- function " + "-" * 56 + " */")
    a(func.signature)
    a(func.body)
    a("")

    out_path.write_text('\n'.join(L), encoding='utf-8')


# ---------------------------------------------------------------------------
# JSON index
# ---------------------------------------------------------------------------

def write_index(units: list[CompileUnit], out_dir: Path) -> None:
    index: dict = {}
    for cu in units:
        rel = normalise_source_path(cu.source_file)
        index[rel] = {
            'source_file': cu.source_file,
            'producer':    cu.producer,
            'language':    cu.language,
            'functions': [
                {
                    'name':      f.name,
                    'signature': f.signature,
                    'range':     f"{f.addr_start}->{f.addr_end}",
                    'dump_line': f.dump_line,
                    'locals': [
                        {'name': lv.name, 'type': lv.type_str, 'reg': lv.register}
                        for lv in f.locals
                    ],
                }
                for f in cu.functions
            ],
        }

    idx_path = out_dir / '_index.json'
    idx_path.write_text(json.dumps(index, indent=2, ensure_ascii=False),
                        encoding='utf-8')
    print(f"[index] {idx_path}")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def run(dump_path: str, out_dir: str, verbose: bool = False) -> None:
    out = Path(out_dir)
    out.mkdir(parents=True, exist_ok=True)

    print(f"[read]  {dump_path}")
    dump_text = Path(dump_path).read_text(encoding='utf-8', errors='replace')

    print(f"[parse] scanning compile units …")
    units = parse_dump(dump_text, verbose=verbose)

    if not units:
        print("[warn]  Nothing parsed — check that the dump format matches.")
        return

    total_fn = sum(len(cu.functions) for cu in units)
    print(f"[parse] {len(units)} compile unit(s), {total_fn} function(s)")

    written = 0
    for cu in units:
        if not cu.functions:
            continue

        # Mirror source path as output folder
        # "C:\ps2\veronica\prog\en19.c"  ->  <out>/ps2/veronica/prog/en19/
        rel_src = normalise_source_path(cu.source_file)
        rel_src_no_ext = str(Path(rel_src).with_suffix(''))
        func_dir = out / rel_src_no_ext

        for func in cu.functions:
            out_file = func_dir / f"{func.name}.c"
            if verbose:
                print(f"  [write] {out_file.relative_to(out)}")
            write_context_file(func, out_file)
            written += 1

    write_index(units, out)
    print(f"[done]  {written} context file(s) → {out_dir}/")


def main() -> None:
    ap = argparse.ArgumentParser(
        description='Build per-function context files from a decomp-toolkit dwarfdump.'
    )
    ap.add_argument('--dump', required=True,
                    help='Path to the dwarfdump.txt produced by decomp-toolkit')
    ap.add_argument('--out', default='./context',
                    help='Output root directory (default: ./context)')
    ap.add_argument('--verbose', '-v', action='store_true',
                    help='Print every compile unit and function as it is processed')
    args = ap.parse_args()

    if not os.path.isfile(args.dump):
        print(f"[error] File not found: {args.dump}", file=sys.stderr)
        sys.exit(1)

    run(args.dump, args.out, verbose=args.verbose)


if __name__ == '__main__':
    main()
