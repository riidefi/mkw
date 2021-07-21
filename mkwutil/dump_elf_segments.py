import argparse
from pathlib import Path
from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser()
parser.add_argument("elf", type=Path)
args = parser.parse_args()

with open(args.elf, "rb") as f:
    elf_file = ELFFile(f)
    for section in elf_file.iter_sections():
        section_name = section.name.removeprefix(".")
        if section_name.strip() == "":
            continue
        print("section=%s data_size=%x" % (section_name, section.data_size))
