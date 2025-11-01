import os
import subprocess
import json
import argparse
import shutil

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
    objects = []
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

        object_file = source.replace(".c", ".o")
        crt0_dest = os.path.join("elf", "crt0.o")
        objects.append(crt0_dest)
        objects.append("elf/ps2_vu0.o")
        objects.append("elf/ps2_vu1.o")
        objects.append(object_file)

        compile_command = [compiler] + local_flags + ['-c', source, '-o', object_file] + \
                          [f'-I{inc}' for inc in include_dirs] + [f'-D{d}' for d in defines]

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
        object_file = source.replace(".s", ".o")
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


def main(args):
    """Main entry point for the build process."""

    # Load environment variables from JSON
    env_vars = load_json(args.env_file)

    compiler = env_vars["compiler"]
    linker = env_vars["linker"]
    include_dirs = env_vars["includes"]
    library_dirs = env_vars["libraries"]
    compiler_flags = env_vars["compiler_flags"]
    linker_script = env_vars["linker_script"]
    linker_flags = env_vars["linker_flags"]
    libraries = env_vars["libs"]
    sources = env_vars["source_files"]
    assembly = env_vars.get("assembly_files", [])
    defines = env_vars.get("defines", [])

    print(f"Performing compilation with the following parameters:");

    compiler_env = {
        "MWLibraries": ";".join(library_dirs),
        "MWLibraryFiles": ""
    }

    assembler = env_vars.get("assembler", "as")

    asm_objects, asm_compile_commands, asm_build_failed = compile_assembly_files(assembler, assembly, [], include_dirs, defines, compiler_env)

    objects, compile_commands, build_failed = compile_source_files(compiler, sources, compiler_flags, include_dirs, defines, compiler_env)

    objects += asm_objects

    # Even if the compilation fails, we want to generate the compile_commands.json for IDEs
    # write_json('compile_commands.json', compile_commands)

    output_elf = None

    if not build_failed:
        linker_env = {
            "MWLibraries": ";".join(library_dirs),
            "MWLibraryFiles": ""
        }

        crt0_src = "include/recvx-decomp-ps2_sdk/usr/local/sce/ee/lib/crt0.o"
        crt0_dest = "elf/crt0.o"

        os.makedirs("elf", exist_ok=True)

        if os.path.exists(crt0_src):
            if not os.path.exists(crt0_dest):
                shutil.copy(crt0_src, crt0_dest)
        else:
            print(f"Warning: {crt0_src} not found ? skipping crt0.o")

        objects = [obj for obj in objects if not obj.endswith("crt0.o")]
        
        objects.insert(0, crt0_dest)

        print(f"Performing linkage with the following parameters:")

        output_elf = link_objects(linker, objects, linker_script, linker_flags, libraries, library_dirs, linker_env)

        if output_elf:
            print(f"Build steps have been successfully completed: {os.path.basename(output_elf)} was generated.")
        else:
            print(f"Linkage fail. See report.txt for more info.")
    else:
        print(f"Compilation fail. See report.txt for more info.")

    crt0_file = "include/recvx-decomp-ps2_sdk/usr/local/sce/ee/lib/crt0.o"

    destination_directory = "elf/"

    os.makedirs(destination_directory, exist_ok=True)

    destination_file = os.path.join(destination_directory, "crt0.o")

    if os.path.exists(destination_file):
        os.remove(destination_file)
    if os.path.exists(crt0_file):
        shutil.move(crt0_file, destination_directory)

    for source in sources:
        object_file = source.replace(".c", ".o")

        if os.path.exists(object_file):
            destination = os.path.join("elf", os.path.basename(object_file))

            shutil.move(object_file, destination)


if __name__ == "__main__":
    # Argument parser setup
    parser = argparse.ArgumentParser(description="Build automation script.")

    parser.add_argument('--env-file', type=str, default='compile_config.json', help="Path to the JSON file containing environment variables.")
    
    args = parser.parse_args()

    main(args)

