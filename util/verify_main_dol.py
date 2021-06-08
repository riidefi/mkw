"""
Script to verify the target main.dol for authenticity.
"""

import argparse
import hashlib
from pathlib import Path
import struct


class Segment:
    def __init__(self, begin: int, end: int):
        assert isinstance(begin, int) and isinstance(end, int)
        self.begin = begin
        self.end = end

    def __repr__(self):
        return "(%s, %s)" % (hex(self.begin), hex(self.end))

    def empty(self):
        return self.begin == self.end

    def size(self):
        return self.end - self.begin


class DolBinary:
    def __init__(self, file):
        file = open(file, "rb")
        #text_ofs = [read_u32(file) for _ in range(7)]
        #data_ofs = [read_u32(file) for _ in range(11)]

        text_vaddr = [read_u32(file) for _ in range(7)]
        data_vaddr = [read_u32(file) for _ in range(11)]

        self.text_size = [read_u32(file) for _ in range(7)]
        self.data_size = [read_u32(file) for _ in range(11)]

        self.text_segs = [Segment(x, x + y) for x, y in zip(text_vaddr, self.text_size)]
        self.data_segs = [Segment(x, x + y) for x, y in zip(data_vaddr, self.data_size)]

        bss_vaddr = read_u32(file)
        bss_size = read_u32(file)

        self.bss = Segment(bss_vaddr, bss_vaddr + bss_size)

        self.entry_point = read_u32(file)

        max_vaddr = max(x.end for x in self.text_segs + self.data_segs)
        self.image_base = 0x80000000
        self.image = bytearray(max_vaddr - self.image_base)


def read_u32(f):
    """Reads a big-endian 32-bit integer"""
    return struct.unpack(">I", f.read(4))[0]


def verify_dol(reference, target):
    """Verifies the target main.dol for authenticity."""
    content = open(target, "rb").read()
    ctx = hashlib.sha1(content)
    digest = ctx.hexdigest()
    if digest.lower() == "ac7d72448630ade7655fc8bc5fd7a6543cb53a49":
        print("[DOL] Everything went okay! Output is matching! ^^")
        return

    print("[DOL] Oof: Output doesn't match.")
    want_len = 2766496
    if len(content) != want_len:
        print(f"Mismatched file size: Got {len(content)} ({want_len-len(content)})")

    good = DolBinary(reference)
    bad = DolBinary(target)

    for i, sizes in enumerate(zip(good.text_size, bad.text_size)):
        print(sizes)
    for i, sizes in enumerate(zip(good.data_size, bad.data_size)):
        print(sizes)
    # TODO: Add diff'ing


parser = argparse.ArgumentParser()
parser.add_argument("--reference", type=Path, required=True, help="Path to reference main.dol")
parser.add_argument("--target", type=Path, required=True, help="Path to target main.dol")
args = parser.parse_args()

verify_dol(args.reference, args.target)
