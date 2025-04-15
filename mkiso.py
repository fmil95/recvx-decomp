import io
import struct
import argparse
from pathlib import Path
from dataclasses import dataclass, field
from typing import BinaryIO

SCRIPT_DIR = Path("./").resolve()
REPLACEMENTS = {
    "SLUS_201.84"                   : "elf/main.elf",
    "PS2_DATA/MODULES/IOPRP213.IMG" : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/ioprp20.img",
    "PS2_DATA/MODULES/SIO2MAN.IRX"  : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/sio2man.irx",
    "PS2_DATA/MODULES/PADMAN.IRX"   : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/padman.irx",
    "PS2_DATA/MODULES/MCMAN.IRX"    : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/mcman.irx",
    "PS2_DATA/MODULES/MCSERV.IRX"   : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/mcserv.irx",
    "PS2_DATA/MODULES/LIBSD.IRX"    : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/libsd.irx",
    "PS2_DATA/MODULES/MODHSYN.IRX"  : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/modhsyn.irx",
    "PS2_DATA/MODULES/MODMIDI.IRX"  : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/modmidi.irx",
    "PS2_DATA/MODULES/MODMSIN.IRX"  : "include/recvx-decomp-ps2_sdk/usr/local/sce/iop/modules/modmsin.irx",
    # "PS2_DATA/MODULES/TSNDDRV.IRX"  : "tsnddrv.irx",
}

SECTOR_SIZE = 0x800
READ_CHUNK = 0x50_0000 # 5MiB
SYSTEM_AREA_SIZE = 0x10 * SECTOR_SIZE
LAYER0_PVD_LOCATION = SYSTEM_AREA_SIZE
MAX_VOLUME_SECTOR_COUNT = 0x1FD060
MAX_VOLUME_SIZE = MAX_VOLUME_SECTOR_COUNT * SECTOR_SIZE
VOLUME_ALIGN = 0x8000
PAD_NONE = 0
PAD_20MB = 1
PAD_VOLUME = 2

def align(x: int, alg: int) -> int:
    return (x + (alg-1)) & ~(alg-1)


@dataclass
class FileListData:
    path: Path
    inode: int
    lba: int = 0
    size: int = 0


@dataclass
class FileListInfo:
    files: list[FileListData]
    total_inodes: int

@dataclass
class IsoLayer:
    header: bytes = b""
    footer: bytes = b""
    offset: int = 0
    meta: FileListInfo = field(default_factory=lambda: FileListInfo([], 0))

@dataclass
class Iso:
    has_second_layer: bool = False
    layers: list[IsoLayer] = field(default_factory=lambda: [IsoLayer(), IsoLayer()])


def main():
    args = get_arguments()

    if args.mode == "extract":
        dump_iso(args.iso, args.filelist, args.files, args.dry)
        print("dumping finished")
    else:
        if args.with_padding:
            pad_mode = PAD_20MB
        elif args.max_size:
            pad_mode = PAD_VOLUME
        else:
            pad_mode = PAD_NONE

        rebuild_iso(args.filelist, args.files, args.output, pad_mode)
        print("rebuild finished")


def get_arguments(argv=None):
    # Init argument parser
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "-m",
        "--mode",
        choices=["extract", "insert"],
        required=True,
        metavar="operation",
        help="Options: extract, insert",
    )

    parser.add_argument(
        "--iso",
        required=False,
        type=Path,
        metavar="original_iso",
        help="input game iso file path",
    )

    group = parser.add_mutually_exclusive_group()
    
    group.add_argument(
        "--with-padding",
        required=False,
        action="store_true",
        help="flag to control outermost iso padding",
    )
    
    group.add_argument(
        "--max-size",
        required=False,
        action="store_true",
        help="flag to make the biggest iso possible",
    )

    parser.add_argument(
        "--dry",
        required=False,
        action="store_false",
        help="dry run, parses the iso without saving the files",
    )

    args = parser.parse_args()
    curr_dir = Path("./").resolve()

    if args.mode == "extract":
        if not args.iso:
            parser.error("Missing 'iso' argument in extract mode")
        else:
            args.iso = args.iso.resolve()

    args.filelist = curr_dir / "elf" / "iso" / "RECVX_FILELIST.TXT"
    args.files = curr_dir / "elf" / "iso" / "data"
    args.output = curr_dir / "elf" / "iso" / "RECVX_NEW.iso"

    return args


def check_pvd(fp: BinaryIO, pvd_loc: int) -> bool:
    fp.seek(pvd_loc)
    vd_type, vd_id = struct.unpack("<B5s", fp.read(6))
    if vd_type == 1 and vd_id == b"CD001":
        return True
    else:
        return False


def dump_dir_records(iso: BinaryIO, pvd_loc: int, pvd_off: int) -> FileListInfo:
    path_parts = []
    record_ends = []
    record_pos = []
    file_info = FileListInfo([], 0)

    # get the root directory record off the PVD
    iso.seek(pvd_loc + 0x9E)
    dr_data_pos, dr_data_len = struct.unpack("<I4xI", iso.read(12))
    dr_data_pos *= SECTOR_SIZE
    dr_data_pos += pvd_off
    record_ends.append(dr_data_pos + dr_data_len)
    record_pos.append(0)

    iso.seek(dr_data_pos)

    # Traverse directory records recursively
    # Did I mention that I won't do function recursion?
    while True:
        # Have we reached the end of current dir record?
        if iso.tell() >= record_ends[-1]:
            if len(record_ends) == 1:
                # If it's the last one, we finished
                break
            else:
                # Otherwise keep reading the previous one
                record_ends.pop()
                path_parts.pop()
                iso.seek(record_pos.pop())
                continue

        # Parse the record
        inode = iso.tell()

        dr_len = struct.unpack("<B", iso.read(1))[0]
        if dr_len == 0:
            # Found a 0-sized entry but record is not over
            # align to boundary or bail out otherwise
            if inode < record_ends[-1]:
                iso.seek(align(iso.tell(), SECTOR_SIZE))
                continue
            else:
                print("ERROR: Invalid directory record found")
                exit(1)

        dr_blob = iso.read(dr_len - 1)

        (
            dr_ea_len,
            dr_data_pos,
            dr_data_len,
            dr_flags,
            dr_inter,
            dr_volume,
            dr_name_len,
        ) = struct.unpack_from("<BI4xI4x7xBHH2xB", dr_blob)

        assert dr_ea_len == 0, "ISOs with extra attributes are not supported!"
        assert dr_inter == 0, "Interleaved ISOs are not supported!"
        assert dr_volume == 1, "multi-volume ISOs are not supported!"
        assert (dr_flags & 0b1000000) == 0, "4GiB+ files are not supported!"

        # the dir records always en on even addresses
        if (iso.tell() % 2) != 0:
            iso.read(1)

        dr_data_pos *= 0x800
        dr_data_pos += pvd_off

        dr_name = dr_blob[32 : 32 + dr_name_len]

        # record with these names are the '.' and '..'
        # directories respectively, so skip them
        if dr_name == b"\x00" or dr_name == b"\x01":
            continue

        dr_name = dr_name.decode()
        if dr_name.endswith(";1"):
            dr_name = dr_name[:-2]
        path_parts.append(dr_name)

        file_info.total_inodes += 1

        # is it a directory?
        if (dr_flags & 0b10) != 0:
            # Go to its directory record
            record_pos.append(iso.tell())
            record_ends.append(dr_data_pos + dr_data_len)
            iso.seek(dr_data_pos)
            continue
        else:
            # Otherwise dump the file
            fp = "/".join(path_parts)

            file_info.files.append(
                FileListData(Path(fp), inode - pvd_off, dr_data_pos, dr_data_len)
            )
            path_parts.pop()

    return file_info


def save_iso_files(
    iso: BinaryIO, file_info: FileListInfo, base_folder: Path
) -> None:
    for file in file_info.files:
        print(f"SAVING {file.path.as_posix()}")

        final_path = base_folder / file.path
        final_path.parent.mkdir(exist_ok=True, parents=True)
        iso.seek(file.lba)

        with open(final_path, "wb+") as f:
            for _ in range(file.size // READ_CHUNK):
                f.write(iso.read(READ_CHUNK))

            if (file.size % READ_CHUNK) != 0:
                f.write(iso.read(file.size % READ_CHUNK))



def check_iso(iso: BinaryIO) -> int:
    # Sanity check
    assert check_pvd(iso, LAYER0_PVD_LOCATION), "No valid PVD found in Layer0!"

    iso.seek(LAYER0_PVD_LOCATION + 0x50)
    pvd0_sector_count = struct.unpack("<I", iso.read(4))[0]
    iso.seek(0, io.SEEK_END)
    iso_sector_count = iso.tell() // SECTOR_SIZE
    
    assert iso_sector_count == pvd0_sector_count, "Dual layer ISO Detected, RE:CVX is a single layer image!"

    return iso_sector_count * SECTOR_SIZE


def dump_iso(iso_path: Path, filelist: Path, iso_files: Path, save_files: bool) -> None:
    if iso_path.exists() is False:
        print(f"Could not to find '{iso_path.name}'!")
        return

    with open(iso_path, "rb") as iso:
        check_iso(iso)

        layer0_data = dump_dir_records(iso, LAYER0_PVD_LOCATION, 0)
        header_end = consume_iso_header(iso, 0, layer0_data.total_inodes)

        # The files are ordered based on their disc position
        layer0_data.files.sort(key=lambda x: x.lba) 

        if save_files:
            # save files (if requested)
            save_iso_files(iso, layer0_data, iso_files)

            # Save IMS
            with open(iso_files / "_header.ims", "wb") as f:
                # Header
                iso.seek(0)
                f.write(iso.read(header_end))

                # Last sector
                iso.seek(-SECTOR_SIZE, 2)
                f.write(iso.read(SECTOR_SIZE)) 

            # Save filelist
            with open(filelist, "w", encoding="utf8") as f:
                for d in layer0_data.files:
                    f.write(f"|{d.inode}||{iso_files.name}/{d.path.as_posix()}|\n")
                f.write(f"//{layer0_data.total_inodes}")
        else:
            # if not then show found data
            for file in layer0_data.files:
                print(
                    f"FOUND {file.path.as_posix()} at 0x{file.lba:08X} with size {file.size} bytes"
                )


def parse_filelist(file_info: FileListInfo, lines: list[str]) -> None:
    for line in lines[:-1]:
        data = [x for x in line.split("|") if x]
        p = Path(data[1])
        file_info.files.append(FileListData(Path(*p.parts[1:]), int(data[0])))

    if lines[-1].startswith("//") is False:
        print("Could not to find inode total!")
        return
    
    file_info.total_inodes = int(lines[-1][2:])


def consume_iso_header(iso: BinaryIO, pvd_off: int, inodes: int) -> int:
    iso.seek(pvd_off)
    i = 0
    data_start = -1
    for lba in range(7862):
        udf_check = struct.unpack("<269x18s1761x", iso.read(SECTOR_SIZE))[0]
        if udf_check == b"*UDF DVD CGMS Info":
            i += 1

        if i == inodes + 1:
            data_start = (lba + 1) * SECTOR_SIZE
            break
    else:
        print(
            "ERROR: Couldn't get all the UDF file chunk, original tool would've looped here"
        )
        print("Closing instead...")
        exit(1)

    return data_start


def validate_rebuild(filelist: Path, iso_files: Path) -> bool:
    if filelist.exists() is False:
        print(f"Could not to find the '{filelist.name}' files log!")
        return False

    if iso_files.exists() is False:
        print(f"Could not to find the '{iso_files.name}' files directory!")
        return False

    if iso_files.is_dir() is False:
        print(f"'{iso_files.name}' is not a directory!")
        return False
    
    return True


def write_new_pvd(iso: BinaryIO, iso_files: Path, add_padding: int, layer_info: IsoLayer, pvd_loc: int) -> int:
    iso.write(layer_info.header)

    for inode in layer_info.meta.files:

        start_pos = iso.tell()
        if str(inode.path) in REPLACEMENTS:
            fp = SCRIPT_DIR / REPLACEMENTS[str(inode.path)]
            print(f"Inserting {REPLACEMENTS[str(inode.path)]} (replaces {str(inode.path)})...")
        else:
            fp = iso_files / inode.path
            print(f"Inserting {str(inode.path)}...")

        if fp.exists() is False:
            print(f"File '{fp.as_posix()}' not found!")
            exit(1)

        with open(fp, "rb") as g:
            while data := g.read(0x80000):
                iso.write(data)

        end_pos = iso.tell()

        # Align to next LBA
        al_end = align(end_pos, SECTOR_SIZE)
        iso.write(b"\x00" * (al_end - end_pos))

        end_save = iso.tell()

        new_lba = (start_pos - pvd_loc + SYSTEM_AREA_SIZE) // 0x800
        new_size = end_pos - start_pos
        iso.seek(inode.inode + pvd_loc - SYSTEM_AREA_SIZE + 2)

        iso.write(struct.pack("<I", new_lba))
        iso.write(struct.pack(">I", new_lba))
        iso.write(struct.pack("<I", new_size))
        iso.write(struct.pack(">I", new_size))

        iso.seek(end_save)

    # Align to 0x8000
    end_pos = iso.tell()
    if (end_pos % VOLUME_ALIGN) == 0:
        al_end = align(end_pos + SECTOR_SIZE, VOLUME_ALIGN)
    else:
        al_end = align(end_pos, VOLUME_ALIGN)

    iso.write(b"\x00" * (al_end - end_pos - SECTOR_SIZE))

    # Sony's cdvdgen tool starting with v2.00 by default adds
    # a 20MiB padding to the end of the PVD, add it here if requested
    if add_padding == PAD_20MB:
        iso.write(b"\x00" * 0x140_0000)
    elif add_padding == PAD_VOLUME:
        empty_sector = b"\x00" * SECTOR_SIZE
        while (iso.tell() - pvd_loc + SYSTEM_AREA_SIZE) < (MAX_VOLUME_SIZE - SECTOR_SIZE):
            iso.write(empty_sector)
        

    # Last LBA includes the anchor
    last_pvd_lba = ((iso.tell() - pvd_loc + SYSTEM_AREA_SIZE) // 0x800) + 1

    # Check if we didn't go over the maximum
    assert last_pvd_lba <= MAX_VOLUME_SECTOR_COUNT, "Iso image would go over the maximum allowed size!"

    iso.write(layer_info.footer)
    iso.seek(pvd_loc + 0x50)
    iso.write(struct.pack("<I", last_pvd_lba))
    iso.write(struct.pack(">I", last_pvd_lba))
    iso.seek(-0x7F4, io.SEEK_END)
    iso.write(struct.pack("<I", last_pvd_lba-1))
    
    iso.seek(0, io.SEEK_END)
    return iso.tell()


def rebuild_iso(filelist: Path, iso_files: Path, output: Path, add_padding: int) -> None:
    # Validate args
    if not validate_rebuild(filelist, iso_files):
        return
    

    # Parse filelist file
    with open(filelist, "r") as f:
        lines = f.readlines()

    iso_info = Iso()
    iso_info.has_second_layer = False

    parse_filelist(iso_info.layers[0].meta, lines[:])
    
    with open(iso_files / "_header.ims", "rb") as head:
        head.seek(0, io.SEEK_END)
        head_size = head.tell() - SECTOR_SIZE
        head.seek(0)
        iso_info.layers[0].header = head.read(head_size)
        iso_info.layers[0].footer = head.read(SECTOR_SIZE)

    with open(output, "wb+") as f:
        write_new_pvd(f, iso_files, add_padding, iso_info.layers[0], SYSTEM_AREA_SIZE)


if __name__ == "__main__":
    main()
