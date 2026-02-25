from __future__ import annotations
import os
import subprocess
import json
import argparse
import sys
import shutil
from pathlib import Path

import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry
from splat.util.symbols import Symbol

from dataclasses import dataclass
from concurrent.futures import ThreadPoolExecutor
import threading

ROOT_DIR = Path(__file__).parent
LOG_FILE = ROOT_DIR / "elf/report.txt"
ELF_FILE = ROOT_DIR / "elf/main.elf"
VERBOSE_PRINT = False

YAML_FILE = Path("config/SLUS_201.84.yaml")
SECTION_DICT = {
    ".text" : ",\"ax\",@progbits,unique,",
    ".data" : ",\"wa\",@progbits,unique,",
    ".rodata" : ",\"a\",@progbits,unique,",
    ".bss" : ",\"wa\",@nobits,unique,",
}

IS_LINUX = sys.platform.startswith("linux")
COMPILE_ENV = os.environ | {"MWCIncludes": ""}
ASSEMBLER_CANDIDATES = [
    "mips-linux-gnu-as",
    "mipsel-linux-gnu-as",
    "mips64-linux-gnu-as",
]
print_lock = threading.Lock()
log_lock = threading.Lock()

@dataclass
class Compiler:
    name: str
    is_assembler: bool
    program: Path
    flags: list[str]
    includes: list[str]
    defines: list[str]

    def get_sdata_flag(self, value: int) -> str:
        if self.name == "mwcc":
            return f"-sdatathreshold={value}"
        else:
            return f"-G{value}"

    def compile(self, src: Path, obj: Path, extra_flags: list[str] = list()) -> bool:
        """Compiles the given source file with an optional extra flag list."""
        compile_command = [str(self.program)]
        compile_command += self.flags
        compile_command += extra_flags
        if self.is_assembler:
            compile_command += ["-o", obj.as_posix(), src.as_posix()]
        else:
            compile_command += ["-c", src.as_posix(), "-o", obj.as_posix()]
        compile_command += [f'-I{inc}' for inc in self.includes]
        compile_command += [f'-D{d}' for d in self.defines]

        return run_command(compile_command)


@dataclass
class CompileUnit:
    src_path: Path
    obj_path: Path
    compiler: Compiler
    sdata_size: int | None = None

    def compile(self):
        """Compiles this CompileUnit."""
        
        extra_flags = list()
        if self.sdata_size is not None:
            extra_flags.append(self.compiler.get_sdata_flag(self.sdata_size))

        return self.compiler.compile(self.src_path, self.obj_path, extra_flags)


def load_json(filename):
    """Load JSON data from a file."""
    with open(filename, 'r') as f:
        return json.load(f)


def run_command(command) -> bool:
    """Run a shell command."""

    if IS_LINUX and command[0].endswith('.exe'):
        command = ['wibo'] + command

    extra = list()
    if VERBOSE_PRINT:
        msg = ""
        for cmd in command:
            if cmd.startswith("-L") or cmd.startswith("-I") or cmd.startswith("-D") or cmd.endswith(".c") or cmd.startswith("-lgcc"):
                msg += f"\n {cmd}"
            elif cmd.endswith(".lcf"):
                msg += f"\n {cmd}\n"
            else:
                msg += f" {cmd}"
        log_me(msg)
    
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, env=COMPILE_ENV)
    extra.append(result.stdout)
    extra.append(result.stderr)

    if result.returncode != 0:
        log_me(f"Error: {result.stderr}", extra)
        return False  # Return False on failure
    else:
        log_me("", extra)
        return True  # Return True on success


def link_objects(linker, objects, linker_script, linker_flags, libraries, library_dirs) -> bool:
    """Link object files into the final executable."""
    
    link_command = [linker]
    link_command += linker_script
    link_command += linker_flags
    link_command += objects
    link_command += ['-o', ELF_FILE.as_posix()]
    link_command += [f'-L{lib}' for lib in library_dirs]
    link_command += libraries

    if not run_command(link_command):
        return False # Return False if link fails
    return True


def obj_path_for(src_path: Path) -> Path:
    """Return the object file path inside the build folder."""
    if "expected" in src_path.parts:
        dst_path = src_path.with_suffix(".o")
    else:
        dst_path = Path("build") / src_path.with_suffix(".o")
    return dst_path


def clean_asm(asm_file: Path, symbols: dict[int, list[Symbol]]):
    with asm_file.open("r", encoding="utf-8") as f:
        lines = f.readlines()

    out = ["\n.include \"macro.inc\"\n"]
    skip = False
    get_pos = False
    count = 1
    section = ".text"
    last_section = 0
    last_name = ""
    for line in lines:
        if line.startswith("/* Automatically generated and unreferenced pad */"):
            continue
        
        if line.startswith("dlabel D_"):
            continue

        if line.startswith("enddlabel"):
            continue

        if line.startswith("  jlabel"):
            out.append(line.replace("jlabel", "ljlabel"))
            continue

        if get_pos and line.startswith("    /* "):
            s = line.split(" ")
            if ".space" in line:
                pos = s[5]
            else:
                pos = s[6]
            sym = symbols[int(pos, base=16)][0]
            if sym.user_declared:
                out.append(f".size {last_name}, {sym.given_size}\n")
            get_pos = False

        if line.startswith("glabel") or line.startswith("dlabel"):
            get_pos = True
            last_name = line[7:].split(",")[0].strip()
            out.append(f".section {section}{SECTION_DICT[section]}{count}\n")
            last_section = len(out) - 1
            count += 1
            skip = False

        if line.startswith("endlabel"):
            out[last_section] += ".balign 16\n"
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
    split.main([YAML_FILE], modes="all", verbose=False, use_cache=False, disassemble_all=True, make_full_disasm_for_code=True)

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
        "progress_categories": [
            {
                "id": "game",
                "name": "Main Game"
            },
            {
                "id": "cri",
                "name": "CRI Middleware (ADX - EE)"
            },
            {
                "id": "tamsoft",
                "name": "Tamsoft Sound Driver (EE)"
            }
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

        if "cri" in unit_src_path.parts:
            category = "cri"
        elif "veronica" in unit_src_path.parts:
            if unit_src_path.name == "ps2_snddrv.c":
                category = "tamsoft"
            else:
                category = "game"
        
        obj_name = entry.segment.name
        unit_cfg = {
            "name": obj_name,
            "target_path": (expected_path / entry.object_path.relative_to(build_path)).as_posix(),
            "metadata": {
                "source_path": entry.segment.out_path().as_posix(),
                "progress_categories": [
                    category
                ]
            },
        }

        if not unit_src_path.exists():
            cfg["units"].append(unit_cfg)
            return

        src_obj_path = entry.object_path

        unit_cfg["base_path"] = src_obj_path.as_posix()

        cfg["units"].append(unit_cfg)
    
    for unit in entries:
        add_unit(unit)

    with open("objdiff.json", "w", encoding="utf-8") as f:
        json.dump(cfg, f, indent=4)

    print("Fixing asm blobs")
    for unit in cfg["units"]:
        # hack...
        if "adx_qtbl.o" in unit["target_path"]:
            with open(Path(unit["target_path"]).with_suffix(".s"), "r+", ) as f:
                content = f.read()
                f.seek(0, 0)
                f.write(".include \"macro.inc\"\n" + content)
        elif "veronica" in unit["target_path"]:
            clean_asm(Path(unit["target_path"]).with_suffix(".s"), split.symbols.all_symbols_dict)


def resolve_linux_tools() -> Path:
    try:
        subprocess.run(["wibo"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    except FileNotFoundError:
        print("ERROR: wibo does not appear to be accessible")
        print("To install it, please download it and put it in your PATH:")
        print(
            "  wget https://github.com/decompals/wibo/releases/download/1.0.0/wibo-x86_64 && chmod +x wibo-x86_64 && sudo mv wibo-x86_64 /usr/bin/wibo"
        )
        sys.exit(-1)
    
    for assembler in ASSEMBLER_CANDIDATES:
        try:
            subprocess.run(
                [assembler, "--version"],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
            break
        except FileNotFoundError:
            pass
    else:
        as_list = "\n".join(ASSEMBLER_CANDIDATES)
        print("ERROR: GNU AS for mips does not appear to be accessible")
        print("Please download it for you distro and put it in your PATH")
        print("We tried to search for either of these:")
        print(f"{as_list}")
        sys.exit(-1)
    
    return Path(assembler)


def cfg_get_compilers(config: dict) -> dict[str, Compiler]:
    compilers: dict[str, Compiler] = dict() 
    
    comm_defines = config["defines"]
    comm_includes = config["common_includes"]

    for compiler in config["compilers"]:
        name = compiler["name"]
        if not IS_LINUX:
            path = Path(compiler["path_win"])
        else:
            path = Path(compiler["path_linux"])

        is_assembler = compiler["is_assembler"]
        fags = compiler["default_flags"]
        includes = compiler["includes"] + comm_includes
        if is_assembler:
            defines = list()
        else:
            defines = comm_defines
        compilers[name] = Compiler(name, is_assembler, path, fags, includes, defines)
    
    return compilers


def cfg_get_current_objects(config: dict, compilers: dict[str, Compiler]) -> dict[Path, CompileUnit]:
    override_map = dict()
    for folder, values in config["source_overrides"].items():
        fp = Path(folder)
        compiler = compilers[values["compiler"]]
        sdata = values["sdata"]["*"]
        for f in fp.rglob("*"):
            override_map[f] = {"compiler": compiler, "sdata": sdata}
        
        for f, v in values["sdata"].items():
            if f == "*":
                continue
            f = fp / f
            override_map[f]["sdata"] = v

    compiled_files: dict[Path, CompileUnit] = dict()
    for file in config["source_files"]:
        src_path = Path(file)
        obj_path = obj_path_for(src_path)
        
        compiler = compilers["gnu-as"]
        sdata = None
        
        if src_path in override_map:
            compiler = override_map[src_path]["compiler"]
            sdata = override_map[src_path]["sdata"]
        elif src_path.suffix == ".vsm":
            compiler = compilers["dvp-as"]
        elif src_path.suffix == ".s":
            compiler = compilers["gnu-as"]
        
        compiled_files[obj_path] = CompileUnit(src_path, obj_path, compiler, sdata)
    
    return compiled_files


def cfg_get_expected_objects(config: dict, compilers: dict[str, Compiler]) -> dict[Path, CompileUnit]:
    expected_files: dict[Path, CompileUnit] = dict()
    exp = Path("build/expected")
    for file in config["source_files"]:
        src_path = Path(file)
        if src_path.is_relative_to("src") and src_path.suffix == ".c":
            src_path = exp / src_path.with_suffix(".s").relative_to("src")
            obj_path = obj_path_for(src_path)
            expected_files[obj_path] = CompileUnit(src_path, obj_path, compilers["gnu-as"])
    
    return expected_files


def log_me(msg: str, extra: list[str] = list(), both: bool = False):
    """Dumb log utility, msg is printed to stdout, while extras are """
    """saved to the log file, use both True save both"""

    with print_lock:
        if msg:
            print(msg)
    
    with log_lock, LOG_FILE.open('a') as f:
        if both and msg: 
            f.write(msg)
        if extra:
            f.write("\n".join(extra))
        f.flush()


def compile_all(objects: list[CompileUnit], parallel: bool = False) -> bool:
    def compile_shim(obj: CompileUnit):
        obj.obj_path.parent.mkdir(parents=True, exist_ok=True)
        msg = f"[BUILD] {obj.compiler.name} {obj.src_path.as_posix()}"
        if obj.sdata_size is not None:
            msg += f" using -sdatathreshold={obj.sdata_size}"
        log_me(msg, both = True)
        ok = obj.compile()
        if not ok:
            log_me(f"FAILED: {obj.src_path.as_posix()}", both = True)
            raise RuntimeError(obj.src_path.as_posix())

    try:
        if parallel:
            with ThreadPoolExecutor(max_workers=8) as pool:
                list(pool.map(compile_shim, objects))
        else:
            for obj in objects:
                compile_shim(obj)
        return False
    except RuntimeError:
        return True

def main(args):
    """Main entry point for the build process."""

    if args.verbose:
        global VERBOSE_PRINT
        VERBOSE_PRINT = True

    if args.setup:
        do_objdiff_setup()
        
        # remove unused folders
        shutil.rmtree("build/expected/data/", ignore_errors=True)
        shutil.rmtree("config/assets/", ignore_errors=True)
    
        # Move function asm so people can make scratches
        asm_folder = Path("build/expected/asm")
        if asm_folder.exists():
            shutil.rmtree("config/asm", ignore_errors=True)
            shutil.move(asm_folder, "config/asm")
        return

    raw_cfg = load_json(args.env_file)
    compilers = cfg_get_compilers(raw_cfg)
    current_objects = cfg_get_current_objects(raw_cfg, compilers)
    expected_objects = cfg_get_expected_objects(raw_cfg, compilers)
    all_objects = current_objects | expected_objects

    # Perform wibo+assembler checks for linux
    if IS_LINUX:
        compilers["gnu-as"].program = resolve_linux_tools()
    
    build_failed = False
    skip_linking = False

    if args.progress:
        compile_list = all_objects.values()
    else:
        compile_list = current_objects.values()
    
    if args.single_file:
        obj = all_objects.get(args.single_file, None)
        if obj is not None:
            skip_linking = True
            build_failed = not obj.compile()
        else:
            print(f"Don't know how make file {args.single_file.as_posix()}")
            sys.exit(-2)
    else:
        build_failed = compile_all(compile_list)

    if build_failed:
        print("Compilation fail. See report.txt for more info.")
        sys.exit(-1)
        return

    # All built okay so run obdiff to get report.json
    if args.progress:
        if IS_LINUX:
            report_cmd = ["compiler/linux/objdiff-cli"]
        else:
            report_cmd = ["compiler/windows/objdiff-cli.exe"]
        report_cmd.append("report")
        report_cmd.append("generate")
        report_cmd.append("-o")
        report_cmd.append("report.json")
        report_cmd.append("-f")
        report_cmd.append("json-pretty")
        run_command(report_cmd)
        print("Progress Report saved to report.json")
        return
    
    if skip_linking:
        return
    
    linker = raw_cfg["linker"]
    linker_script = raw_cfg["linker_script"]
    linker_flags = raw_cfg["linker_flags"]
    libraries = raw_cfg["libs"]
    library_dirs = raw_cfg["libraries"]

    objects = [o.as_posix() for o in current_objects.keys()]

    print(f"[LINK] linking {ELF_FILE.name}...")

    success = link_objects(linker, objects, linker_script, linker_flags, libraries, library_dirs)

    if success:
        print(f"Build steps have been successfully completed: {ELF_FILE.name} was generated.")
    else:
        print("Linkage fail. See report.txt for more info.")

    return

if __name__ == "__main__":
    # Argument parser setup
    parser = argparse.ArgumentParser(description="Build automation script.")

    parser.add_argument('--env-file', type=Path, default='compile_config.json', help="Path to the JSON file containing environment variables.")
    parser.add_argument('--single-file', type=Path, help="For objdiff use.")
    parser.add_argument('--setup', action="store_true", help="Generates original asm and objdiff project files.")
    parser.add_argument('--progress', action="store_true", help="Make all the objects needed for progress reporting.")
    parser.add_argument('--verbose', action="store_true", help="More info for each command.")

    args = parser.parse_args()

    main(args)
