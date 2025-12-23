import os
import subprocess
import json
import argparse
import sys
import shutil
from pathlib import Path

import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

YAML_FILE = Path("config/SLUS_201.84.yaml")
SECTION_DICT = {
    ".text" : ",\"ax\",@progbits,unique,",
    ".data" : ",\"wa\",@progbits,unique,",
    ".rodata" : ",\"a\",@progbits,unique,",
    ".bss" : ",\"wa\",@nobits,unique,",
}

def load_json(filename):
    """Load JSON data from a file."""
    with open(filename, 'r') as f:
        return json.load(f)


def write_json(filename, data):
    """Write JSON data to a file."""
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)


def run_command(command, env_vars, log_file='elf/report.txt'):
    """Run a shell command with specified environment variables and log output."""

    # Detect Linux environment and use WIBO for windows binaries
    if sys.platform.startswith("linux") and command[0].endswith('.exe'):
        try:
            subprocess.run(["wibo"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        except FileNotFoundError:
            print("ERROR: wibo does not appear to be accessible")
            print("To install it, please download it and put it in your PATH:")
            print(
                "  wget https://github.com/decompals/wibo/releases/download/1.0.0/wibo-x86_64 && chmod +x wibo-x86_64 && sudo mv wibo-x86_64 /usr/bin/wibo"
            )
            sys.exit(1)

        command = ['wibo'] + command

    for cmd in command:
        # Tidy up the output a little
        if cmd.startswith("-L") or cmd.startswith("-I") or cmd.startswith("-D") or cmd.endswith(".c") or cmd.startswith("-lgcc"):
            print(f"\n {cmd}", end="")
        elif cmd.endswith(".lcf"):
            print(f"\n {cmd}", end="\n")
        else:
            print(f" {cmd}", end="")
    print()

    env = os.environ.copy()
    env.update(env_vars)

    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Log the result to file
    with open(log_file, 'a') as f:
        f.write(result.stdout.decode('utf-8'))
        f.write(result.stderr.decode('utf-8'))

    if result.returncode != 0:
        print(f"Error: {result.stderr.decode('utf-8')}")
        return False  # Return False on failure

    return True  # Return True on success


def create_compile_command_entry(compiler, source, object_file, include_dirs, defines):
    """Create a compile command entry for compile_commands.json."""
    valid_include_dirs = [os.path.abspath(inc) for inc in include_dirs if os.path.isdir(inc)]
    invalid_include_dirs = [inc for inc in include_dirs if not os.path.isdir(inc)]
    if invalid_include_dirs:
        print(f"Warning: Invalid include directories: {invalid_include_dirs}")

    return {
        "directory": os.getcwd(),
        "command": ' '.join([compiler, '-c', source, '-o', object_file] +
                            [f'-D{d}' for d in defines] +
                            [f'-I{inc}' for inc in valid_include_dirs]),
        "file": source
    }


def compile_source_files(compiler, sources, compiler_flags, include_dirs, defines, env_vars):
    """Compile all source files and return object file list and compile commands."""
    objects = ["vsm/ps2_vu0.o", "vsm/ps2_vu1.o"]
    compile_commands = []
    build_failed = False

    # --- Directory-to-threshold defaults ---
    threshold_rules = {
        os.path.join("src", "cri", "mwlib", "ee", "lib", "libadxe"): 4,
        os.path.join("src", "ps2", "veronica", "prog"): 0,
    }

    # --- File-specific overrides ---
    file_specific = {
        "adx_mps2.c": 8,     # src\cri\mwlib\ee\lib\libadxe\adx_mps2.c
        "adx_fini.c": 0,     # src\cri\mwlib\ee\lib\libadxe\adx_fini.c
        "adx_fs.c": 0,
        "dvci.c": 0,
        "dvci_sub.c": 0,
        "htci.c": 0,
        "htci_sub.c": 0,
        "sjr_clt.c": 0,
        # add more if needed:
        # "other_file.c": 2,
    }

    log_file = 'elf/report.txt'

    for source in sources:
        normalized_path = source.replace("/", os.sep).replace("\\", os.sep)
        filename = os.path.basename(source)

        # Default: inherit compiler_flags
        local_flags = compiler_flags[:]
        applied_threshold = None

        # Check file-specific rule first
        if filename in file_specific:
            applied_threshold = file_specific[filename]
            local_flags = compiler_flags + [f"-sdatathreshold={applied_threshold}"]
        else:
            # Otherwise, check directory-based rule
            for base, val in threshold_rules.items():
                if base in normalized_path:
                    applied_threshold = val
                    local_flags = compiler_flags + [f"-sdatathreshold={val}"]
                    break

        # --- Logging info about threshold choice ---
        threshold_msg = (
            f"[BUILD] {source} -> using -sdatathreshold={applied_threshold}"
            if applied_threshold is not None
            else f"[BUILD] {source} -> using default threshold"
        )
        print(threshold_msg)
        with open(log_file, 'a') as f:
            f.write(threshold_msg + "\n")
        # -------------------------------------------

        object_file = obj_path_for(source)
        objects.append(object_file)

        compile_command = ([compiler] + local_flags + ["-c", source, "-o", object_file] + [f'-I{inc}' for inc in include_dirs] + [f'-D{d}' for d in defines])

        if not run_command(compile_command, env_vars, log_file):
            build_failed = True

        compile_commands.append(create_compile_command_entry(compiler, source, object_file, include_dirs, defines))

    return objects, compile_commands, build_failed


def compile_assembly_files(assembler, sources, assembler_flags, include_dirs, defines, env_vars):
    """Compile all assembly files and return object file list and compile commands."""
    objects = []
    compile_commands = []
    build_failed = False  # Track if any compilation fails

    for source in sources:
        object_file = obj_path_for(source)
        objects.append(object_file)

        compile_command = [assembler] + assembler_flags + ['-o', object_file , source]

        # Continue compiling even if one source fails
        if not run_command(compile_command, env_vars):
            build_failed = True  # Mark the build as failed if any command fails

        compile_commands.append(create_compile_command_entry(assembler, source, object_file, include_dirs, defines))

    return objects, compile_commands, build_failed


def link_objects(linker, objects, linker_script, linker_flags, libraries, library_dirs, env_vars):
    """Link object files into the final executable."""
    output_elf = "elf/main.elf"
    link_command = [linker] + linker_script + linker_flags + objects + ['-m', '_start', '-o', output_elf] + \
                   [f'-L{lib}' for lib in library_dirs] + libraries

    if not run_command(link_command, env_vars):
        return None  # Return None if linking fails
    return output_elf


def obj_path_for(source):
    """Return the object file path inside the build folder."""
    src_path = Path(source)
    if "expected" in src_path.parts:
        dst_path = src_path.with_suffix(".o")
    else:
        dst_path = Path("build") / src_path.with_suffix(".o")
        dst_path.parent.mkdir(parents=True, exist_ok=True)
    return str(dst_path)


def src_path_for(source):
    """Return the source file path inside the src folder."""
    src_path = Path(source)
    if "expected" in src_path.parts:
        dst_path = src_path.with_suffix(".s")
    else:
        dst_path = src_path.relative_to("build").with_suffix(".c")
    return str(dst_path)


def clean_asm(asm_file: Path):
    with asm_file.open("r", encoding="utf-8") as f:
        lines = f.readlines()

    if lines[0] == "/* PROCESSED FILE */":
        return
    
    out = ["/* PROCESSED FILE */\n"]
    skip = False
    count = 1
    section = ".text"
    for line in lines:
        if line.startswith("/* Automatically generated and unreferenced pad */"):
            continue
        
        if line.startswith("dlabel D_"):
            skip = True
            continue

        if line.startswith("enddlabel D_"):
            skip = True
            continue

        if line.startswith("glabel") or line.startswith("dlabel"):
            out.append(f".section {section}{SECTION_DICT[section]}{count}\n")
            count += 1
            skip = False
        
        if line.startswith("endlabel"):
            out.append(line)
            out.append("\n")
            skip = True

        if line.startswith(".section"):
            section = line[9:].split(",")[0]
            count = 1
            continue
        
        if not skip:
            out.append(line)

    with asm_file.open("w", encoding="utf-8") as f:
        f.writelines(out)


def do_objdiff_setup():
    """Setup objdiff.json and run splat."""
    split.main([YAML_FILE], modes="all", verbose=False, make_full_disasm_for_code=True)

    entries = split.linker_writer.entries

    cfg = {
        "min_version": "1.0.0",
        "custom_make": "python",
        "custom_args": [
            "compile.py",
            "--single-file",
        ],
        "build_target": True,
        "watch_patterns": [
            "*.c",
            "*.h",
            "*.json",
        ],
        "units": [],
    }
    
    build_path = Path("build/src")
    expected_path = Path("build/expected")

    def add_unit(entry: LinkerEntry) -> None:
        if entry.segment.type not in ["c", "cpp"]:
            return
        
        unit_src_path = entry.segment.out_path().relative_to("config")
        if "sce" in unit_src_path.parts:
            return
        
        obj_name = entry.segment.name
        unit_cfg = {
            "name": obj_name,
            "target_path": (expected_path / entry.object_path.relative_to(build_path)).as_posix(),
            "metadata": {
                "source_path": entry.segment.out_path().as_posix()
            },
        }

        if not unit_src_path.exists():
            cfg["units"].append(unit_cfg)
            return

        src_obj_path = entry.object_path

        unit_cfg["base_path"] = src_obj_path.as_posix()
        unit_cfg["complete"] = False # TODO

        cfg["units"].append(unit_cfg)
    
    for unit in entries:
        add_unit(unit)

    with open("objdiff.json", "w", encoding="utf-8") as f:
        json.dump(cfg, f, indent=4)

    print("Fixing asm blobs")
    for unit in cfg["units"]:
        if "veronica" in unit["target_path"]:
            clean_asm(Path(unit["target_path"]).with_suffix(".s"))


def main(args):
    """Main entry point for the build process."""

    if args.setup:
        do_objdiff_setup()

        # Move function asm so people can make scratches
        asm_folder = Path("build/expected/asm")
        if asm_folder.exists():
            shutil.move(asm_folder, "config/asm")
        
        # Remove unused folders
        shutil.rmtree("build/expected/data/", ignore_errors=True)
        shutil.rmtree("config/assets/", ignore_errors=True)
        return

    # Load environment variables from JSON
    env_vars = load_json(args.env_file)

    compiler = env_vars["compiler"]
    linker = env_vars["linker"]
    include_dirs = env_vars["includes"]
    library_dirs = env_vars["libraries"]
    compiler_flags = env_vars["compiler_flags"]
    linker_script = env_vars["linker_script"]
    linker_flags = env_vars["linker_flags"]
    assembler = env_vars.get("assembler", "as")
    assembler_flags = env_vars["assembler_flags"]
    libraries = env_vars["libs"]
    sources = env_vars["source_files"]
    assembly = env_vars.get("assembly_files", [])
    defines = env_vars.get("defines", [])
    skip_linking = False

    if args.single_file:
        # Looks a bit eh, but it's what changes the least code
        src = src_path_for(args.single_file)
        if src.endswith(".s"):
            assembly = [src]
            sources = []
        else:
            assembly = []
            sources = [src]
        skip_linking = True
        
    print(f"Performing compilation with the following parameters:")

    compiler_env = {
        "MWLibraries": ";".join(library_dirs),
        "MWLibraryFiles": ""
    }

    asm_objects, asm_compile_commands, asm_build_failed = compile_assembly_files(assembler, assembly, assembler_flags, include_dirs, defines, compiler_env)

    objects, compile_commands, build_failed = compile_source_files(compiler, sources, compiler_flags, include_dirs, defines, compiler_env)

    objects += asm_objects

    # Even if the compilation fails, we want to generate the compile_commands.json for IDEs
    # write_json('compile_commands.json', compile_commands)

    output_elf = None

    if build_failed or asm_build_failed:
        print(f"Compilation fail. See report.txt for more info.")
        sys.exit(-1)
        return
    
    if not skip_linking:
        linker_env = {
            "MWLibraries": ";".join(library_dirs),
            "MWLibraryFiles": ""
        }

        print(f"Performing linkage with the following parameters:")

        output_elf = link_objects(linker, objects, linker_script, linker_flags, libraries, library_dirs, linker_env)

        if output_elf:
            print(f"Build steps have been successfully completed: {os.path.basename(output_elf)} was generated.")
        else:
            print(f"Linkage fail. See report.txt for more info.")


if __name__ == "__main__":
    # Argument parser setup
    parser = argparse.ArgumentParser(description="Build automation script.")

    parser.add_argument('--env-file', type=str, default='compile_config.json', help="Path to the JSON file containing environment variables.")
    parser.add_argument('--single-file', type=str, help="For objdiff use.")
    parser.add_argument('--setup', action="store_true", help="Generates original asm and objdiff project files.")

    args = parser.parse_args()

    main(args)
