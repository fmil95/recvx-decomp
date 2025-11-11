# -*- coding: utf-8 -*-
import os
import re

README_PATH = "README.md"
START_MARKER = "<!-- PROGRESS-START -->"
END_MARKER = "<!-- PROGRESS-END -->"
TARGET_WORD = "matching"

# Ordered categories
directories = {
    r"src/ps2/veronica/prog": {
        "name": "Resident Evil CODE: Veronica X",
        "total": 3842,  # 3876 - 34
        "exclude_files": ["ps2_snddrv.c"],
    },
    r"src/cri/mwlib/ee/lib/libadxe": {
        "name": "CRI ADX (March 13, 2001)",
        "total": 662,
    },
    r"src/ps2/veronica/prog/ps2_snddrv.c": {
        "name": "Tamsoft Sound Driver (EE)",
        "total": 34,
        "single_file": True,
    },
}

grand_total = 0
grand_reference_total = 0
directory_results = {}

# Count matches
for path, info in directories.items():
    ref_total = info["total"]
    display_name = info["name"]
    dir_count = 0

    if info.get("single_file"):  # Tamsoft driver
        try:
            with open(path, "r", encoding="utf-8", errors="ignore") as f:
                dir_count = f.read().count(TARGET_WORD)
        except Exception as e:
            print(f"Error reading {path}: {e}")
    else:  # Folder traversal
        exclude_files = set(info.get("exclude_files", []))
        for root, _, files in os.walk(path):
            for file in files:
                if file.endswith((".c", ".h")) and file not in exclude_files:
                    full_path = os.path.join(root, file)
                    try:
                        with open(full_path, "r", encoding="utf-8", errors="ignore") as f:
                            dir_count += f.read().count(TARGET_WORD)
                    except Exception as e:
                        print(f"Error reading {full_path}: {e}")

    percent = (dir_count / ref_total) * 100 if ref_total else 0
    directory_results[display_name] = {
        "found": dir_count,
        "total": ref_total,
        "percent": percent,
    }

    grand_total += dir_count
    grand_reference_total += ref_total

# Build progress text
lines = []
for path, info in directories.items():
    name = info["name"]
    stats = directory_results[name]
    percent_str = (
        f"{stats['percent']:.2f}".rstrip("0").rstrip(".")
        if stats['percent'] % 1 != 0
        else f"{int(stats['percent'])}"
    )
    lines.append(
        f"{name}: {stats['found']} implemented functions / "
        f"{stats['total']} total ({percent_str}%)"
    )

grand_percent = (grand_total / grand_reference_total) * 100
grand_percent_str = (
    f"{grand_percent:.2f}".rstrip("0").rstrip(".")
    if grand_percent % 1 != 0
    else f"{int(grand_percent)}"
)
lines.append(
    f"\nDecomp progress: {grand_total} implemented functions / {grand_reference_total} total "
    f"({grand_percent_str}%)"
)

progress_text = "\n".join(lines)
wrapped_block = f"```\n{progress_text}\n```"

# Update README
with open(README_PATH, "r", encoding="utf-8") as f:
    content = f.read()

pattern = re.compile(rf"{START_MARKER}.*?{END_MARKER}", re.DOTALL)
replacement = f"{START_MARKER}\n{wrapped_block}\n{END_MARKER}"
updated = re.sub(pattern, replacement, content)

with open(README_PATH, "w", encoding="utf-8") as f:
    f.write(updated)

print(progress_text)
