"""
Script to convert a main.elf to main.dol executable.
"""

import argparse
import io
from elftools.elf.constants import P_FLAGS
from elftools.elf.elffile import ELFFile


def segment_is_dummy(seg):
    """Returns whether segment contains dummy info."""
    return seg["p_vaddr"] in (0xA000_0000, 0xB000_0000)  # Binary blobs section


def segment_is_text(seg):
    """Returns whether segment is executable text."""
    return not segment_is_dummy(seg) and seg["p_flags"] & P_FLAGS.PF_X == P_FLAGS.PF_X


def segment_is_data(seg):
    """Returns whether segment is data."""
    return (
        not segment_is_dummy(seg)
        and not segment_is_text(seg)
        and not segment_is_bss(seg)
    )


def segment_is_bss(seg):
    """Returns whether segment is bss."""
    return seg["p_filesz"] == 0


def write_to_dol_header(file, offset, val):
    """Writes a 4 byte value to DOL."""
    file.seek(offset)
    file.write(val.to_bytes(4, byteorder="big"))
    file.seek(0, io.SEEK_END)


def write_segment_to_dol(idx, segment, dol_file):
    """Writes a segment to DOL file."""
    write_to_dol_header(dol_file, 0x00 + 0x04 * idx, dol_file.tell())
    write_to_dol_header(dol_file, 0x48 + 0x04 * idx, segment["p_vaddr"])
    # align filesz to 0x20
    filesz = ((segment["p_filesz"] + 0x1F) >> 5) << 5
    write_to_dol_header(dol_file, 0x90 + 0x04 * idx, filesz)

    dol_file.write(segment.data())
    # align current dol size to 0x20
    size = 0x20 - dol_file.tell() & 0x1F
    dol_file.write(bytes([0x00] * size))


def elf_to_dol(elf_file_path, dol_file_path):
    """Ports a DOL file to a dummy ELF file."""
    with open(elf_file_path, "rb") as elf_raw_file, open(
        dol_file_path, "wb"
    ) as dol_file:
        elf_file = ELFFile(elf_raw_file)
        num_segments = elf_file.num_segments()

        dol_file.write(bytes([0x00] * 0x100))

        idx = 0
        for i in range(num_segments):
            segment = elf_file.get_segment(i)
            if not segment_is_text(segment):
                continue
            write_segment_to_dol(idx, segment, dol_file)
            idx += 1

        idx = 7
        for i in range(num_segments):
            segment = elf_file.get_segment(i)
            if not segment_is_data(segment):
                continue
            write_segment_to_dol(idx, segment, dol_file)
            idx += 1

        bss_start = 0
        bss_end = 0
        for i in range(num_segments):
            segment = elf_file.get_segment(i)
            if not segment_is_bss(segment):
                continue
            if bss_start == 0:
                bss_start = segment["p_vaddr"]
            bss_end = segment["p_vaddr"] + segment["p_memsz"]
        write_to_dol_header(dol_file, 0xD8, bss_start)
        bss_size = bss_end - bss_start
        write_to_dol_header(dol_file, 0xDC, bss_size)

        write_to_dol_header(dol_file, 0xE0, elf_file["e_entry"])


def pack_main_dol(src, dst):
    """Performs the full ELF to DOL conversion."""
    # TODO Why do we garble the ELF here?
    with open(src, "r+b") as dolf:
        dolf.seek(0x18)
        dolf.write(bytes([0x80, 0x00, 0x60, 0xA4]))
    elf_to_dol(src, dst)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert main.elf to main.dol")
    parser.add_argument("-o", "--out", type=str, required=True, help="DOL output path")
    parser.add_argument("input", type=str, help="ELF input path")
    args = parser.parse_args()

    pack_main_dol(args.input, args.out)
