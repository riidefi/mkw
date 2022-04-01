import argparse
from dataclasses import dataclass
from pathlib import Path
import struct
from typing import Iterator

from elftools.elf.elffile import ELFFile, Section as ELFSection


@dataclass
class BinaryPatch:
    vaddr: int
    size: int
    val: int

    LAYOUT = ">IIQ"

    def from_struct_fields(fields) -> "BinaryPatch":
        return BinaryPatch(fields[0], fields[1], fields[2])


def load_binary_patches(elf: ELFFile) -> Iterator[BinaryPatch]:
    patches: ELFSection = elf.get_section_by_name("mkw_patches")
    if not patches:
        return
    for patch_fields in struct.iter_unpack(BinaryPatch.LAYOUT, patches.data()):
        yield BinaryPatch.from_struct_fields(patch_fields)


def patch_elf(elf_file):
    elf = ELFFile(elf_file)
    for patch in load_binary_patches(elf):
        offsets = list(elf.address_offsets(patch.vaddr, patch.size))
        if len(offsets) != 1 or patch.size > 8:
            continue
        file_offset = offsets[0]
        elf_file.seek(file_offset)
        elf_file.write(struct.pack(">Q", patch.val)[8 - patch.size :])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("elf", type=Path)
    args = parser.parse_args()
    with open(args.elf, "rb+") as elf_file:
        patch_elf(elf_file)


if __name__ == "__main__":
    main()
