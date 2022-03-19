"""
Script to convert a StaticR.elf to StaticR.rel relocatable file.
"""

import argparse
from pathlib import Path
import struct

from elftools.elf.elffile import ELFFile

from .lib.rel import Rel, RelSection

SYMS = {
    "debug__Q22UI9UIControlFv": 0x8063CFFC,
    "solve_propagate__Q22UI9UIControlFv": 0x8063D3CC,
    "onGroupAttached__Q22UI9UIControlFPQ22UI12ControlGroupUl": 0x8063D398,
    "ResourceManager_getFile": 0x805411FC,
    "unk_8052758c": 0x8052758C,
    "unk_805336a4": 0x805336A4,
    "unk_8053572c": 0x8053572C,
    "unk_8054a9b8": 0x8054A9B8,
}


R_PPC_NONE = 0
R_PPC_ADDR32 = 1
R_PPC_ADDR24 = 2
R_PPC_ADDR16 = 3
R_PPC_ADDR16_LO = 4
R_PPC_ADDR16_HI = 5
R_PPC_ADDR16_HA = 6
R_PPC_ADDR14 = 7
R_PPC_ADDR14_BRTAKEN = 8
R_PPC_ADDR14_BRNKTAKEN = 9
R_PPC_REL24 = 10
R_PPC_REL14 = 11
R_PPC_REL32 = 26


def read_elf_sec(elf, name):
    """Constructs a RelSection for the given ELF section name."""
    elf_sec = elf.get_section_by_name(name)

    data = elf_sec.data()

    sec = RelSection()
    sec.data = bytearray(data)
    sec.length = len(data)

    # Added
    sec.name = name

    return sec


def pack_staticr_rel(elf_path, rel_path, orig_dir):
    rel = Rel()

    # TODO hardcoded path
    orig_dir = Path(orig_dir)
    rel.load_reloc(0, orig_dir / "pal" / "rel" / "dol_rel.bin")
    rel.load_reloc(1, orig_dir / "pal" / "rel" / "rel_abs.bin")

    with open(elf_path, "rb") as f:
        elf = ELFFile(f)

        rel.section_info[1] = read_elf_sec(elf, ".text")
        rel.section_info[2] = read_elf_sec(elf, ".ctors")
        rel.section_info[3] = read_elf_sec(elf, ".dtors")
        rel.section_info[4] = read_elf_sec(elf, ".rodata")
        rel.section_info[5] = read_elf_sec(elf, ".data")
        rel.section_info[6] = read_elf_sec(elf, ".bss")

        # Jump to _Unresolved
        _unresolved = 0x805553B0
        text = rel.section_info[1]

        # SHT_RELA
        relocs = elf.get_section_by_name(".rela.text")

        if relocs:
            for reloc_acc in relocs.iter_relocations():
                reloc = reloc_acc.entry
                if reloc.r_info_type == R_PPC_REL24:
                    instruction = struct.unpack(
                        ">I", text.data[reloc.r_offset : reloc.r_offset + 4]
                    )[0]
                    text_start = 0x805103B4
                    instruction_addr = text_start + reloc.r_offset

                    sym_tab = elf.get_section(relocs.header.sh_link)
                    r_symbol = reloc.r_info_sym # reloc.r_info >> 8
                    symbol = sym_tab.get_symbol(r_symbol)

                    st_value = symbol['st_value']

                    if symbol.name in SYMS:
                        st_value = SYMS[symbol.name] - text_start

                    target = _unresolved

                    if st_value != 0:
                        print(f"[cross-link] to {symbol.name}")

                        target = text_start + st_value

                    delta = target - instruction_addr
                    new_ins = (instruction & ~0x03FFFFFC) | (delta & 0x03FFFFFC)

                    # print(hex(instruction))
                    # print(hex(new_ins))

                    packed = struct.pack(">I", new_ins)
                    for i in range(4):
                        text.data[reloc.r_offset + i] = packed[i]

    rel.section_info[1].executable = True
    rel.section_info[1].offset = 0xD4
    rel.section_info[2].offset = 0x37F120
    rel.section_info[3].offset = 0x37F424
    rel.section_info[4].offset = 0x37F440
    rel.section_info[5].offset = 0x3A28F0
    rel.section_info[6].offset = 0

    # This seems to affect tz, but absolutely no one else?
    # Hack: Fix .bss size
    rel.section_info[6].length = 0x78B0

    rel.imps[0].moduleId = 1
    rel.imps[0].offset = 0x3CD104
    rel.imps[1].moduleId = 0
    rel.imps[1].offset = 0x4820F4

    with open(rel_path, "wb") as file:
        rel.reconstruct(file)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert StaticR.elf to StaticR.rel")
    parser.add_argument("-o", "--out", type=str, required=True, help="REL output path")
    parser.add_argument("input", type=str, help="ELF input path")
    args = parser.parse_args()

    pack_staticr_rel(args.input, args.out, "./artifacts/orig")
