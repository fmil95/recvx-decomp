import os
import subprocess
import json
import argparse
import sys

def load_json(filename):
    """Load JSON data from a file."""
    with open(filename, 'r') as f:
        return json.load(f)


def write_json(filename, data):
    """Write JSON data to a file."""
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)


def run_command(command, env_vars, log_file='compiling/report.txt'):
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
    build_failed = False  # Track if any compilation fails

    for source in sources:
        object_file = source.replace(".c", ".o")
        objects.append(object_file)

        compile_command = [compiler] + compiler_flags + ['-c', source, '-o', object_file] + \
                          [f'-I{inc}' for inc in include_dirs] + [f'-D{d}' for d in defines]

        # Continue compiling even if one source fails
        if not run_command(compile_command, env_vars):
            build_failed = True  # Mark the build as failed if any command fails

        compile_commands.append(create_compile_command_entry(compiler, source, object_file, include_dirs, defines))

    return objects, compile_commands, build_failed


def link_objects(linker, objects, linker_flags, libraries, library_dirs, env_vars):
    """Link object files into the final executable."""
    output_elf = "main.elf"
    link_command = [linker] + linker_flags + objects + ['-o', output_elf] + \
                   [f'-L{lib}' for lib in library_dirs] + libraries

    if not run_command(link_command, env_vars):
        return None  # Return None if linking fails
    return output_elf


def main(args):
    """Main entry point for the build process."""
    
    # Print system init text 
    print(f"Starting RE: CVX decompile build system ...\n");
    print(f"Initializing compiler ...\n");

    # Load environment variables from JSON
    env_vars = load_json(args.env_file)

    compiler = env_vars["compiler"]
    linker = env_vars["linker"]
    include_dirs = env_vars["includes"]
    library_dirs = env_vars["libraries"]
    compiler_flags = env_vars["compiler_flags"]
    linker_flags = env_vars["linker_flags"]
    libraries = env_vars["libs"]
    sources = env_vars["source_files"]
    defines = env_vars.get("defines", [])
    
    print(f"Performing compilation with the following parameters:\n");
    
    # Compile source files
    compiler_env = {
        "MWLibraries": ";".join(library_dirs),
        "MWLibraryFiles": ""
    }
    objects, compile_commands, build_failed = compile_source_files(compiler, sources, compiler_flags, include_dirs, defines, compiler_env)

    # Even if the compilation fails, we want to generate the compile_commands.json for IDEs
    write_json('compiling/compile_commands.json', compile_commands)

    print(f"\nInitializing linker ...\n");

    # If the compilation succeeded, attempt to link the objects and print final result
    if not build_failed:
        linker_env = {
            "MWLibraries": ";".join(library_dirs),
            "MWLibraryFiles": ""
        }

        print(f"Performing linkage with the following parameters:\n");

        output_elf = link_objects(linker, objects, linker_flags, libraries, library_dirs, linker_env)

        if output_elf:
            print(f"\nBuild steps have been successfully completed.")
            print(f"\n{output_elf} was generated.")
        else:
            print(f"\nLinkage fail. See report.txt for more info.")
    else:
        print(f"\nCompilation fail. See report.txt for more info.")


if __name__ == "__main__":
    # Argument parser setup
    parser = argparse.ArgumentParser(description="Build automation script.")

    parser.add_argument('--env-file', type=str, default='compile_config.json', help="Path to the JSON file containing environment variables.")
    
    args = parser.parse_args()

    main(args)

