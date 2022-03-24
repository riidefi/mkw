"""
Attempts to detect TU boundaries by looking at sdata access patterns.
"""

import argparse
from dataclasses import dataclass, field
from pathlib import Path
from re import I
import struct
import sys
from typing import Optional, Iterable, Iterator

from mkwutil.lib.dol import DolBinary, DolSegment
from mkwutil.project import read_dol


@dataclass
class SdataAccess:
    at: int
    target: int
    size: int = 4

    def __str__(self) -> str:
        return "%08x %08x" % (self.target, self.at)


@dataclass
class SdataSite:
    at: int
    refs: set[int] = field(default_factory=lambda: set())
    value: Optional[int] = None
    size: Optional[int] = None

    def add(self, access: SdataAccess):
        if self.size is not None and self.size != access.size:
            print("WARN: access size mismatch", file=sys.stderr)
            self.size = 4
        else:
            self.size = access.size
        self.refs.add(access.at)

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

        if word >> 26 in (32, 34, 36, 38, 40, 44, 48, 52):
            # lwz, lbz, stw, stb, lhz, sth, lfs, stfs opcodes
            access_size = 4
        elif word >> 26 in (50, 54):
            # lfd, stfd opcodes
            access_size = 8
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
        offset_uimm = word & 0xFFFF
        offset = struct.unpack(">h", struct.pack(">H", (offset_uimm)))[0]
        offset = offset & ~3

        return SdataAccess(at, base + offset, size=access_size)


class SdataAccessIndexer:
    def __init__(self):
        self.sites = dict()

    def add(self, access: SdataAccess):
        site: SdataSite = self.sites.setdefault(access.target, SdataSite(access.target))
        site.add(access)

    def linear_pass(self, dol: DolBinary) -> Iterator[SdataAccess]:
        last = None
        for site in sorted(self.sites.values()):
            if site.at >= 0x80389140:
                break
            site.read_from(dol)
            if last is None:
                last = site.at
            while last < site.at:
                assert last % 4 == 0
                last += 4
                if last + (site.size or 4) < site.at:
                    yield SdataSite(at=last, value=dol.virtual_read_word(last))
            yield site


class Sdata2TUDetector:
    def __init__(self, sites: Iterable[SdataSite]):
        self.sites = sites

    def _reset_tu(self):
        self.tu = []
        self.vals = set()
        self.found_padding = False

    def run(self):
        self._reset_tu()
        for site in self.sites:
            if site.at < 0x80386FA0:
                continue
            if self.found_padding:
                self._next_tu()
            self._next_site(site)

    def tu_spread(sites) -> tuple[int, int]:
        min_ref = 0xFFFF_FFFF_FFFF_FFFF
        max_ref = 0
        for site in sites:
            for ref in site.refs:
                min_ref = min(min_ref, ref)
                max_ref = max(max_ref, ref)
        return min_ref, max_ref

    def _dump_tu(self):
        if len(self.tu) == 0:
            return
        min_text, max_text = Sdata2TUDetector.tu_spread(self.tu)
        if max_text == 0:
            return
        print(
            "%08x..%08x %08x..%08x"
            % (self.tu[0].at, self.tu[-1].at, min_text, max_text)
        )

    def _next_tu(self):
        self._dump_tu()
        self._reset_tu()

    def _next_site(self, site: SdataSite):
        if site.value in self.vals:
            if site.value == 0 and len(site.refs) == 0 and site.at % 8 == 4:
                self.found_padding = True
                return
            self._next_tu()
        self.vals.add(site.value)
        self.tu.append(site)


def main():
    parser = argparse.ArgumentParser(description="TU detect text padding heuristic")
    parser.add_argument("--all", action="store_true", help="Print all")
    args = parser.parse_args()

    dol = read_dol(Path("./artifacts/orig/pal/main.dol"))
    text_segment = dol.segments[DolSegment.NAMES.index("text")]

    # Linear pass over text section for xrefs and index them by sdata address.
    scanner = SdataAccessScanner(text_segment)
    indexer = SdataAccessIndexer()
    for access in scanner.scan():
        indexer.add(access)

    # Linear pass over sdata section.
    sites = list(indexer.linear_pass(dol))
    for site in sites:
        print(site)
    print()

    # sdata2 section detect
    detector = Sdata2TUDetector(sites)
    detector.run()


if __name__ == "__main__":
    main()
