# -*- coding: utf-8 -*-
import os
import re

README_PATH = "README.md"
START_MARKER = "<!-- PROGRESS-START -->"
END_MARKER = "<!-- PROGRESS-END -->"
TARGET_WORD = "matching"

directories = {
    r"src/ps2/veronica/prog": {
        "name": "Resident Evil CODE: Veronica X",
        "total": 3876
    },
    r"src/cri/mwlib/ee/lib/libadxe": {
        "name": "CRI ADX (March 13, 2001)",
        "total": 653
    }
}

grand_total = 0
grand_reference_total = 0
directory_results = {}

# Count matches
for directory, info in directories.items():
    ref_total = info["total"]
    display_name = info["name"]
    dir_count = 0

    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith((".c", ".h")):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
                        dir_count += f.read().count(TARGET_WORD)
                except Exception as e:
                    print(f"Error reading {file_path}: {e}")

    percent = (dir_count / ref_total) * 100
    directory_results[display_name] = {
        "found": dir_count,
        "total": ref_total,
        "percent": percent,
    }
    grand_total += dir_count
    grand_reference_total += ref_total

# Build progress text
lines = []
for name, stats in directory_results.items():
    lines.append(f"{name}: {stats['found']} implemented functions / {stats['total']} total ({stats['percent']:.2f}%)")
lines.append(
    f"\nDecomp progress: {grand_total} implemented functions / {grand_reference_total} total "
    f"({(grand_total / grand_reference_total) * 100:.2f}%)"
)
progress_text = "\n".join(lines)

# Replace only the section between markers
with open(README_PATH, "r", encoding="utf-8") as f:
    content = f.read()

pattern = re.compile(
    rf"{START_MARKER}.*?{END_MARKER}",
    re.DOTALL,
)

new_content = re.sub(
    pattern,
    f"{START_MARKER}\n{progress_text}\n{END_MARKER}",
    content,
)

with open(README_PATH, "w", encoding="utf-8") as f:
    f.write(new_content)

print(progress_text)
