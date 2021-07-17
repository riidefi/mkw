"""
DOL binary executable parser.
"""

import struct


class DolSegment:
    """Describes a DOL segment."""

    def __init__(self, start: int, stop: int, offset=None):
        assert isinstance(start, int) and isinstance(stop, int)
        assert start <= stop
        self.start = start
        self.stop = stop
        self.offset = offset
        self.data = None

    def __repr__(self):
        return "%08x..%08x" % (self.start, self.stop)

    def empty(self):
        """Returns whether the segment is empty."""
        return self.start == self.stop

    def size(self):
        """Returns the length of the segment in bytes."""
        return self.stop - self.start

    def __len__(self):
        return self.size()

    def __contains__(self, key):
        return isinstance(key, int) and self.start <= key < self.stop

    def virtual_read(self, vaddr, size):
        """Returns the bytes at the given virtual address."""
        if self.data is None:
            return None
        assert vaddr in self, f"Virtual address {vaddr} not within segment {self}"
        offset = vaddr - self.start
        assert (
            offset + size <= self.stop
        ), f"Out-of-bounds read: {offset + size} > {self.stop}"
        result = self.data[offset : offset + size]
        assert len(result) == size
        return result


class DolBinary:
    """Describes a DOL executable."""

    SECTION_COUNT = 18

    def __init__(self, file, read_body=True):
        # Read header.
        section_offsets = list(
            bin[0]
            for bin in struct.iter_unpack(">I", file.read(DolBinary.SECTION_COUNT * 4))
        )
        section_addrs = list(
            bin[0]
            for bin in struct.iter_unpack(">I", file.read(DolBinary.SECTION_COUNT * 4))
        )
        section_lens = list(
            bin[0]
            for bin in struct.iter_unpack(">I", file.read(DolBinary.SECTION_COUNT * 4))
        )
        self.segments = []
        for i in range(0, DolBinary.SECTION_COUNT):
            self.segments.append(
                DolSegment(
                    section_addrs[i],
                    section_addrs[i] + section_lens[i],
                    section_offsets[i],
                )
            )
        bss_addr, bss_len = struct.unpack(">II", file.read(8))
        self.bss = DolSegment(bss_addr, bss_addr + bss_len)
        self.entry_point = struct.unpack(">I", file.read(4))[0]
        # Determine bounds.
        self.start = 0x8000_0000
        self.stop = max([seg.stop for seg in self.segments])
        self.stop = max(self.stop, self.bss.stop)
        # Read segment content.
        if read_body:
            for segment in self.segments:
                if len(segment) <= 0:
                    continue
                file.seek(segment.offset)
                segment.data = file.read(segment.size())

    def virtual_read(self, vaddr, size):
        """Returns the bytes at the given virtual address. Must span exactly one segment."""
        segment = next((seg for seg in self.segments if vaddr in seg), None)
        if segment is None:
            return None
        return segment.virtual_read(vaddr, size)
