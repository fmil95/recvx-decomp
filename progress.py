# -*- coding: utf-8 -*-
import os

# Directories mapped to their friendly names and total occurrences
directories = {
    r"src\ps2\veronica\prog": {
        "name": "Resident Evil CODE: Veronica X",
        "total": 3876
    },
    r"src\cri\mwlib\ee\lib\libadxe": {
        "name": "CRI ADX (March 13, 2001)",
        "total": 653
    }
}

target_word = "matching"
grand_total = 0
grand_reference_total = 0
directory_results = {}

# Walk through each directory
for directory, info in directories.items():
    reference_total = info["total"]
    display_name = info["name"]
    dir_count = 0
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith((".c", ".h")):  
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                        count = content.count(target_word)
                        dir_count += count
                except Exception as e:
                    print(f"Error reading {file_path}: {e}")
    percentage = (dir_count / reference_total) * 100
    directory_results[display_name] = {
        "found": dir_count,
        "reference_total": reference_total,
        "percentage": percentage
    }
    grand_total += dir_count
    grand_reference_total += reference_total

# Final summary 
for name, stats in directory_results.items():
    print(f"{name}: {stats['found']} implemented functions / {stats['reference_total']} total "
          f"({stats['percentage']:.2f}%)")

print(f"\nDecomp progress: {grand_total} implemented functions / {grand_reference_total} total "
      f"({(grand_total / grand_reference_total) * 100:.2f}%)")