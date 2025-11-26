# -*- coding: utf-8 -*-

import os
import re
import sys

# PPC Å® MIPS register translation table
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


def translate_to_mips(line):
    def repl(match):
        reg = match.group(0)
        return PPC_TO_MIPS.get(reg, reg)
    return REGEX_PPC.sub(repl, line)


def sanitize_filename(path):
    base = os.path.basename(path)
    return re.sub(r"[^a-zA-Z0-9._-]", "_", base)


def process_dwarfdump(input_file, do_mips):
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

    # Write output files
    for unit_name, sections in compile_units.items():
        for section in sections:
            while section and section[-1].strip() == "/*":
                section.pop()

        out_path = os.path.join(out_dir, unit_name + ".txt")

        with open(out_path, "w", encoding="utf-8") as out:
            for section in sections:
                for line in section:
                    if do_mips:
                        line = translate_to_mips(line)
                    out.write(line)


if __name__ == "__main__":
    if len(sys.argv) not in (2, 3):
        print("Usage:")
        print("  python context.py <dwarfdump.txt>")
        print("  python context.py -MIPS <dwarfdump.txt>")
        sys.exit(1)

    if len(sys.argv) == 3:
        flag = sys.argv[1]
        infile = sys.argv[2]
        do_mips = (flag == "-MIPS")
    else:
        infile = sys.argv[1]
        do_mips = False

    process_dwarfdump(infile, do_mips)
