"""
Attempts to detect TU boundaries by looking at sdata access patterns.
"""

import argparse
from dataclasses import dataclass, field
from pathlib import Path
from re import I
import struct
import sys
from typing import Optional, Iterator

from mkwutil.lib.dol import DolBinary, DolSegment
from mkwutil.project import read_dol


@dataclass
class SdataAccess:
    at: int
    target: int
    size: int = 4
    ps_ext: bool = False

    def __str__(self) -> str:
        return "%08x %08x" % (self.target, self.at)


@dataclass
class SdataSite:
    at: int
    refs: set[int] = field(default_factory=lambda: set())
    value: Optional[int] = None
    size: Optional[int] = None
    ps_ext: bool = False

    def add(self, access: SdataAccess):
        if self.size is not None and self.size != access.size:
            print("WARN: access size mismatch", file=sys.stderr)
            self.size = 4
        else:
            self.size = access.size
        self.refs.add(access.at)
        self.ps_ext = self.ps_ext or access.ps_ext

    def read_from(self, bin: DolBinary):
        if self.size == 8:
            self.value = bin.virtual_read_dword(self.at)
        else:
            self.value = bin.virtual_read_word(self.at)

    def __str__(self) -> str:
        if self.value is None:
            value_str = "????????"
        elif self.size == 8:
            value_str = "%016x" % (self.value)
        else:
            value_str = "%08x" % (self.value) + " " * 8
        if len(self.refs) > 0:
            ret = "%08x %s % 4d %08x..%08x" % (
                self.at,
                value_str,
                len(self.refs),
                min(self.refs),
                max(self.refs),
            )
        else:
            ret = "%08x %s" % (self.at, value_str)
        if self.ps_ext:
            ret += " (psq)"
        return ret

    def __lt__(self, other) -> bool:
        return self.at < other.at


class SdataAccessScanner:
    R2 = 0x8038EFA0
    R13 = 0x8038CC00

    def __init__(self, segment: DolSegment):
        self.segment = segment
        self.pointer = self.segment.start

    def scan(self) -> Iterator[SdataAccess]:
        while self.pointer < self.segment.stop:
            access = self._next()
            if access is not None:
                yield access

    def _next(self) -> Optional[SdataAccess]:
        assert self.pointer % 4 == 0
        at = self.pointer
        self.pointer += 4
        blob = self.segment.virtual_read(at, 4)
        word = struct.unpack(">I", blob)[0]

        ps_ext = False
        if word >> 26 in (32, 34, 36, 38, 40, 44, 48, 52):
            # lwz, lbz, stw, stb, lhz, sth, lfs, stfs opcodes
            access_size = 4
        elif word >> 26 in (50, 54):
            # lfd, stfd opcodes
            access_size = 8
        elif word >> 26 in (56, 60):
            # psq_l, psq_st
            access_size = 4
            ps_ext = True
        else:
            return
        # r2 or r13
        rT = word >> 16 & 0b11111
        if rT == 2:
            base = SdataAccessScanner.R2
        elif rT == 13:
            base = SdataAccessScanner.R13
        else:
            return
        # offset
        if not ps_ext:
            offset_uimm = word & 0xFFFF
            offset = struct.unpack(">h", struct.pack(">H", (offset_uimm)))[0]
            offset = offset & ~3
        else:
            offset_uimm = word & 0x1FFF
            offset = offset & ~3

        return SdataAccess(at, base + offset, size=access_size, ps_ext=ps_ext)


class SdataAccessIndexer:
    def __init__(self):
        self.sites = dict()

    def add(self, access: SdataAccess):
        site: SdataSite = self.sites.setdefault(access.target, SdataSite(access.target))
        site.add(access)


def main():
    parser = argparse.ArgumentParser(description="TU detect text padding heuristic")
    parser.add_argument("--all", action="store_true", help="Print all")
    args = parser.parse_args()

    dol = read_dol(Path("./artifacts/orig/pal/main.dol"))
    text_segment = dol.segments[DolSegment.NAMES.index("text")]

    scanner = SdataAccessScanner(text_segment)
    indexer = SdataAccessIndexer()
    for access in scanner.scan():
        indexer.add(access)
    last = None
    for site in sorted(indexer.sites.values()):
        if site.at >= 0x80389140:
            break
        site.read_from(dol)
        if last is None:
            last = site.at
        while last < site.at:
            assert last % 4 == 0
            last += 4
            if last + (site.size or 4) < site.at:
                print(SdataSite(at=last, value=dol.virtual_read_word(last)))
        print(site)


if __name__ == "__main__":
    main()
