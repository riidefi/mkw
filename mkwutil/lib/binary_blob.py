import re
from typing import Generator

from mkwutil.lib.slices import *

from elftools.elf.elffile import ELFFile, Section as ELFSection

MATCH_BINARY_BLOB = re.compile(
    rb"BINARY_BLOB: (.+)\t(0x[0-9a-f]{8})\t(0x[0-9a-f]{8})\n"
)


def __load_binary_blob_slices(elf_file) -> Generator[Slice, None, None]:
    elf = ELFFile(elf_file)
    blobs: ELFSection = elf.get_section_by_name("binary_blobs")
    if not blobs:
        return
    for match in MATCH_BINARY_BLOB.finditer(blobs.data()):
        name = match.group(1).decode("ascii")
        start, stop = int(match.group(2), 16), int(match.group(3), 16)
        yield Slice(start, stop, name)


def load_binary_blob_slices(elf_path: Path) -> list[Slice]:
    """Loads all inline assembly slices from the ELF."""
    with open(elf_path, "rb") as file:
        return list(__load_binary_blob_slices(file))


def mask_binary_blobs(main_slices: SliceTable, blob_slices: list[Slice]) -> None:
    """Inserts a gap into the given slice table for each blob slice.
    This is used to remove all inline ASM slices from the slice table, leaving only actual C/C++ code."""
    for _slice in blob_slices:
        # print("Ignoring", _slice)
        main_slices.remove(_slice=_slice)
    # print(main_slices)
