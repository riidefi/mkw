"""
Script to convert a StaticR.elf to StaticR.rel relocatable file.
"""

import argparse
from pathlib import Path
import struct

from elftools.elf.elffile import ELFFile

from mkwutil.lib.rel import Rel, RelSection
from ppcdis import RelLinker

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


def pack_staticr_rel(elf_path, rel_path, orig_rel_yaml_path, dol_elf_path):
    linker = RelLinker(dol_elf_path, elf_path, 1, num_sections=17, name_offset=0, name_size=66, \
        base_rel_path=orig_rel_yaml_path, ignore_missing=True, ignore_sections=["binary_blobs", "flow_check"])
    linker.link_rel(rel_path)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert StaticR.elf to StaticR.rel")
    parser.add_argument("-o", "--out", type=str, required=True, help="REL output path")
    parser.add_argument("--dol-elf", type=str, required=True, help="main.elf path")
    parser.add_argument("--base-rel", type=str, required=True, help="Base rel yml for sym defs")
    parser.add_argument("input", type=str, help="ELF input path")
    args = parser.parse_args()

    pack_staticr_rel(args.input, args.out, args.base_rel, args.dol_elf)
