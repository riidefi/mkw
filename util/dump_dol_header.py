import argparse
from pathlib import Path
import struct

parser = argparse.ArgumentParser()
parser.add_argument("dol", type=Path)
args = parser.parse_args()

section_count = 18

with open(args.dol, "rb") as file:
    offsets = list(struct.iter_unpack(">I", file.read(section_count*4)))
    addresses = list(struct.iter_unpack(">I", file.read(section_count*4)))
    lengths = list(struct.iter_unpack(">I", file.read(section_count*4)))
    bss_address = struct.unpack(">I", file.read(4))
    bss_length = struct.unpack(">I", file.read(4))
    entrypoint = struct.unpack(">I", file.read(4))


print("entrypoint=%08x" % entrypoint[0])
for i in range(section_count):
    print("section=0x%02x offset=0x%08x address=0x%08x length=%08x" % (i, offsets[i][0], addresses[i][0], lengths[i][0]))
print("section=bss address=%08x length=%08x" % (bss_address[0], bss_length[0]))
