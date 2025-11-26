# -*- coding: utf-8 -*-

import os
import re
import sys

# PPC ? MIPS register translation table
PPC_TO_MIPS = {
    "r0":  "$zero",
    "r1":  "$at",
    "r2":  "$v0",
    "r3":  "$v1",
    "r4":  "$a0",
    "r5":  "$a1",
    "r6":  "$a2",
    "r7":  "$a3",
    "r8":  "$t0",
    "r9":  "$t1",
    "r10": "$t2",
    "r11": "$t3",
    "r12": "$t4",
    "r13": "$t5",
    "r14": "$t6",
    "r15": "$t7",
    "r16": "$s0",
    "r17": "$s1",
    "r18": "$s2",
    "r19": "$s3",
    "r20": "$s4",
    "r21": "$s5",
    "r22": "$s6",
    "r23": "$s7",
    "r24": "$t8",
    "r25": "$t9",
    "r26": "$k0",
    "r27": "$k1",
    "r28": "$gp",
    "r29": "$sp",
    "r30": "$fp",
    "r31": "$ra",
}

# Matches r0..r31 exactly
REGEX_PPC = re.compile(r"\br([0-9]|[12][0-9]|3[01])\b")


def translate_to_mips_in_comments(line, in_block_comment):
    """
    Replace PPC regs only inside comments.
    Handles:
      // single-line
      /* block comments */ possibly multiline
    """
    new_line = line
    output = ""
    i = 0
    length = len(new_line)

    while i < length:
        if in_block_comment:
            end = new_line.find("*/", i)
            if end == -1:
                # Entire rest of the line is inside comment
                part = new_line[i:]
                part = REGEX_PPC.sub(lambda m: PPC_TO_MIPS.get(m.group(0), m.group(0)), part)
                output += part
                return output, True
            else:
                # Replace until end of comment
                part = new_line[i:end+2]
                part = REGEX_PPC.sub(lambda m: PPC_TO_MIPS.get(m.group(0), m.group(0)), part)
                output += part
                i = end + 2
                in_block_comment = False
                continue

        # Not currently inside a block comment
        idx_line_comment = new_line.find("//", i)
        idx_block_comment = new_line.find("/*", i)

        # If no comment ahead, output the rest unchanged
        if idx_line_comment == -1 and idx_block_comment == -1:
            output += new_line[i:]
            break

        # Case 1: Next comment is //
        if idx_line_comment != -1 and (idx_block_comment == -1 or idx_line_comment < idx_block_comment):
            # Copy before comment
            output += new_line[i:idx_line_comment]
            # Replace inside // comment
            comment = new_line[idx_line_comment:]
            comment = REGEX_PPC.sub(lambda m: PPC_TO_MIPS.get(m.group(0), m.group(0)), comment)
            output += comment
            return output, in_block_comment

        # Case 2: Next comment is /*
        if idx_block_comment != -1 and (idx_line_comment == -1 or idx_block_comment < idx_line_comment):
            output += new_line[i:idx_block_comment]
            i = idx_block_comment
            # Now we are entering a block comment
            in_block_comment = True
            continue

    return output, in_block_comment


def sanitize_filename(path):
    base = os.path.basename(path)
    return re.sub(r"[^a-zA-Z0-9._-]", "_", base)


def process_dwarfdump(input_file, do_mips, do_cut):
    with open(input_file, "r", encoding="utf-8", errors="ignore") as f:
        lines = f.readlines()

    out_dir = "context"

    if os.path.exists(out_dir):
        for name in os.listdir(out_dir):
            os.remove(os.path.join(out_dir, name))
    else:
        os.makedirs(out_dir)

    compile_units = {}
    current_unit = None
    buffer = []
    prev_line = None

    for line in lines:
        match = re.match(r"\s*Compile unit:\s*(.*)", line)
        if match:
            if current_unit:
                compile_units.setdefault(current_unit, []).append(buffer)

            fullpath = match.group(1).strip()
            current_unit = sanitize_filename(fullpath)

            buffer = []
            if prev_line is not None and prev_line.strip().startswith("/*"):
                buffer.append(prev_line)

            buffer.append(line)
        else:
            if current_unit:
                buffer.append(line)

        prev_line = line

    if current_unit:
        compile_units.setdefault(current_unit, []).append(buffer)

    # -------------------------
    # CUT MODE
    # -------------------------
    if do_cut:
        for unit_name, sections in compile_units.items():
            types_sections = []
            decls_sections = []

            for section in sections:
                text = "".join(section)
                if "Code range:" in text:
                    decls_sections.append(section)
                else:
                    types_sections.append(section)

            def clean(sec):
                while sec and sec[-1].strip() == "/*":
                    sec.pop()

            # Write types
            if types_sections:
                out_path = os.path.join(out_dir, unit_name + "_types.c.txt")
                with open(out_path, "w", encoding="utf-8") as out:
                    in_block_comment = False
                    for section in types_sections:
                        clean(section)
                        for line in section:
                            if do_mips:
                                line, in_block_comment = translate_to_mips_in_comments(
                                    line, in_block_comment
                                )
                            out.write(line)

            # Write decls
            if decls_sections:
                out_path = os.path.join(out_dir, unit_name + "_decls.c.txt")
                with open(out_path, "w", encoding="utf-8") as out:
                    in_block_comment = False
                    for section in decls_sections:
                        clean(section)
                        for line in section:
                            if do_mips:
                                line, in_block_comment = translate_to_mips_in_comments(
                                    line, in_block_comment
                                )
                            out.write(line)

        return

    # -------------------------
    # ORIGINAL MODE
    # -------------------------
    for unit_name, sections in compile_units.items():
        for section in sections:
            while section and section[-1].strip() == "/*":
                section.pop()

        out_path = os.path.join(out_dir, unit_name + ".txt")

        with open(out_path, "w", encoding="utf-8") as out:
            in_block_comment = False
            for section in sections:
                for line in section:
                    if do_mips:
                        line, in_block_comment = translate_to_mips_in_comments(
                            line, in_block_comment
                        )
                    out.write(line)


# -------------------------
# Command line handling
# -------------------------
if __name__ == "__main__":
    if len(sys.argv) not in (2, 3, 4):
        print("Usage:")
        print("  python context.py <dwarfdump.txt>")
        print("  python context.py -MIPS <dwarfdump.txt>")
        print("  python context.py -cut <dwarfdump.txt>")
        print("  python context.py -MIPS -cut <dwarfdump.txt>")
        sys.exit(1)

    do_mips = False    # translate registers (inside comments only)
    do_cut = False     # split decls/types
    infile = None

    for arg in sys.argv[1:]:
        if arg == "-MIPS":
            do_mips = True
        elif arg == "-cut":
            do_cut = True
        else:
            infile = arg

    if infile is None:
        print("Missing input file.")
        sys.exit(1)

    process_dwarfdump(infile, do_mips, do_cut)
