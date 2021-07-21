from bisect import bisect, bisect_left
from copy import copy
import csv
from dataclasses import dataclass, field
import math
from pathlib import Path
from typing import Callable, Generator, Optional


@dataclass
class Slice:
    """A continuous memory region."""

    start: int
    stop: int
    name: str = None
    section: "Section" = None
    tags: set[str] = field(default_factory=set)

    def __post_init__(self):
        assert self.start <= self.stop

    def __contains__(self, key) -> bool:
        if isinstance(key, int):
            return self.start <= key < self.stop
        if isinstance(key, type(self)):
            return self.start <= key.start and self.stop >= key.stop
        return False

    def __len__(self) -> int:
        assert self.start <= self.stop, "Slice has negative length"
        return self.stop - self.start

    def __eq__(self, other: "Slice") -> bool:
        """Checks whether two slices occupy the same region."""
        if not isinstance(other, type(self)):
            return False
        return self.start == other.start and self.stop == other.stop

    def __gt__(self, other: "Slice") -> bool:
        """Checks whether this slice starts after another slice."""
        if not isinstance(other, type(self)):
            return False
        return self.start > other.start

    def __repr__(self) -> str:
        repr = "{ %08x..%08x" % (self.start, self.stop)
        if self.name is not None:
            repr += " " + self.name
        if self.section is not None:
            repr += " (" + self.section + ")"
        repr += " }"
        return repr

    def has_name(self) -> bool:
        """Returns whether the slice is named. Unnamed slices get handled"""
        return self.name is not None

    def __copy__(self) -> "Slice":
        """Returns a copy of the slice."""
        return type(self)(self.start, self.stop, self.name, self.section, self.tags)


@dataclass
class ObjectSlices:
    """ObjectSlices is an immutable view of slices grouped by slice name."""

    objects: dict=field(default_factory=dict)

    def get(self, name: str) -> list[Slice]:
        assert isinstance(name, str)
        return self.objects.get(name)

    def __len__(self) -> int:
        return self.objects.__len__()


class SliceTable:
    """A list of contiguous slices for a given range."""

    def __init__(
        self, start=0x8000_0000, stop=math.inf, sections: Optional[list] = None
    ):
        if sections is not None:
            start = sections[0].start
            stop = sections[-1].stop
        assert start < stop, "Non-positive slice table size"
        self.slices = [Slice(start, stop)]
        self.start = start
        self.stop = stop

    def load_path(file_path, sections=None):
        """Loads slices given a path to a CSV file."""
        if sections is not None:
            this = SliceTable(start=sections[0].start, stop=sections[-1].stop)
        else:
            this = SliceTable()
        with open(file_path, "r") as file:
            this.read_from(file)
        if sections is not None:
            this.set_sections(sections)
        return this

    @staticmethod
    def load_dol_slices(sections=None) -> "SliceTable":
        """Loads pack/dol_slices.csv in the default DOL region."""
        return SliceTable.load_path(
            Path(__file__).parent / ".." / "pack" / "dol_slices.csv", sections=sections
        )

    @staticmethod
    def load_rel_slices(sections=None) -> "SliceTable":
        """Loads pack/rel_slices.csv in the default DOL region."""
        return SliceTable.load_path(
            Path(__file__).parent / ".." / "pack" / "rel_slices.csv", sections=sections
        )

    def __contains__(self, _slice: Slice) -> bool:
        """Returns whether the range of a slice lies within the table.
        The table is not actually checked for membership."""
        return self.start <= _slice.start and self.stop >= _slice.stop

    def __iter__(self):
        return self.slices.__iter__()

    def __len__(self) -> int:
        return self.size()

    def size(self) -> int:
        return self.stop - self.start

    def count(self) -> int:
        return len(self.slices)

    def read_from(self, file) -> None:
        for slice in SlicesCSVReader(file):
            self.add(slice)

    def find(self, addr: int) -> tuple[Optional[Slice], Optional[int]]:
        """Returns the slice the address falls into."""
        for i, slice in enumerate(self.slices):
            if addr in slice:
                return slice, i
        return None, None

    def slice(self, start: int, stop: int) -> "SliceTable":
        """Returns a copy of the slice table for a given range."""
        _, start_idx = self.find(start)
        assert start_idx is not None, f"Start {hex(start)} lies outside table."
        new_table = SliceTable(start, stop)
        for _slice in self.slices[start_idx:]:
            if _slice.start < start:
                _slice = copy(_slice)
                _slice.start = start
            if _slice.start >= stop:
                break
            if _slice.stop > stop:
                _slice = copy(_slice)
                _slice.stop = stop
                new_table.add(_slice)
                break
            new_table.add(_slice)
        return new_table

    # def write_to(self, file):
    #    writer = SlicesCSVWriter(file)
    #    for slice in self.slices:
    #        if slice.name is not None:
    #            writer.write(slice)

    def find_parent(self, _slice: Slice) -> Optional[Slice]:
        """Searches for a slice in the table containing the given slice."""
        i = bisect_left(self.slices, _slice)
        if i < len(self.slices):
            return self.slices[i]
        return None

    def sum_named_slices(self) -> int:
        """Returns the sum of the lengths of all named/known slices."""
        t = 0
        for s in self.segs:
            if s.name is not None:
                t += len(s)
        return t

    def filter(self, filter_func: Callable[[Slice], bool]) -> "SliceTable":
        """Returns a new slice table with only slices that passed the filter function."""
        # A more "pythonic" approach to this would be SliceTable([for x in table if x ...])
        filtered = SliceTable(self.start, self.stop)
        for slice in self.slices:
            if slice.name is not None and filter_func(slice):
                filtered.add(slice)
        return filtered

    # Filter function for SliceTable.filter
    ONLY_ENABLED = lambda slice: "enabled" in slice.tags

    def add(self, _slice: Slice) -> None:
        """Adds a slice to the table, changing gaps as appropriate.
        Panics if a named slice overlaps with the slice to be inserted"""
        assert isinstance(_slice, Slice)
        assert(len(_slice) > 0), str(_slice)
        assert _slice in self, "Slice %08x..%08x does not fit in table %08x..%08x" % (
            _slice.start,
            _slice.stop,
            self.start,
            self.stop,
        )
        # Find the slice in which the starting point falls.
        i = bisect(self.slices, _slice) - 1
        target = self.slices[i]
        # If the new slice does not fit in the target slice,
        # the new slice overlaps at least two slices.
        # Because of the invariant that no gaps can share a border,
        # this means the new slice overlaps at least one named slice.
        # TODO This is not true anymore, update logic to overwrite multiple slices.
        assert (
            target.name is None and _slice in target
        ), f"Overlapping slices:\n     new={_slice}\nexisting={target}"
        # Insert left gap.
        if _slice.start > target.start:
            self.slices.insert(i, Slice(target.start, _slice.start))
            i += 1
        # Insert new slice.
        self.slices[i] = _slice
        # Insert right gap.
        if _slice.stop < target.stop:
            self.slices.insert(i + 1, Slice(_slice.stop, target.stop))

    def __repr__(self) -> str:
        return (
            "[\n" + "\n".join(["  " + repr(_slice) for _slice in self.slices]) + "\n]"
        )

    SECTION_ORDER = [
        "init",
        "extab",
        "extabindex",
        "text",
        "ctors",
        "dtors",
        "rodata",
        "data",
        "bss",
        "sdata",
        "sbss",
        "sdata2",
        "sbss2",
    ]

    def object_slices(self, order: list[str] = SECTION_ORDER) -> ObjectSlices:
        """Returns a dict of objects keyed by object name.
        An object is a list of slices in different sections with the same name."""
        # Create sort buckets for each section.
        # TODO A deque might be more appropriate.
        buckets = [[] for _ in range(0, len(order))]
        # Remember the sections of each object.
        object_sections = dict()
        # Transform slices list to buckets / objects.
        for _slice in self.slices:
            if not _slice.has_name():
                continue
            buckets[order.index(_slice.section)].append(_slice)
            sections = object_sections.get(_slice.name, set())
            sections.add(_slice.section)
            object_sections[_slice.name] = sections
        # Sort each bucket.
        for bucket in buckets:
            bucket.sort(key=lambda _slice: _slice.start)
        # Merge buckets.
        objects = ObjectSlices()
        while sum(len(bucket) for bucket in buckets) > 0:
            # Select next object name.
            resolved_row = False
            for i, bucket in enumerate(buckets):
                if len(bucket) == 0:
                    continue
                name = bucket[0].name
                slices = [bucket[0]]
                # Discover dependencies of slice.
                deps_match = True
                for j, dep_bucket in enumerate(buckets):
                    if i == j:
                        continue
                    if order[j] in object_sections[name]:
                        # If the dependency section doesn't contain our object,
                        # try another section first.
                        if dep_bucket[0].name != name:
                            deps_match = False
                            break
                        slices.append(dep_bucket[0])
                # All dependencies match with lowest addresses.
                if deps_match:
                    j = 0
                    for _slice in slices:
                        while (
                            len(buckets[j]) == 0
                            or buckets[j][0].section != _slice.section
                        ):
                            j += 1
                        buckets[j].pop(0)
                    resolved_row = True
                    objects.objects[name] = slices
                    break
            # If no bucket could be resolved, it's impossible to sort
            assert resolved_row, "Merging failed at slices:\n" + "\n".join(
                (
                    f"{hex(bucket[0].start)} {order[i]} = {bucket[0]}"
                    for i, bucket in enumerate(buckets)
                    if len(bucket) > 0
                )
            )
        return objects

    def set_sections(self, sections: list) -> None:
        """Sets the slices' sections based on the given list of sections.
        The sections must be sorted."""
        i = 0
        for slice_idx, _slice in enumerate(self.slices):
            assert i < len(sections)
            # Move on to next section if slice begins outside bounds of last slice.
            while sections[i].stop <= _slice.start:
                i += 1
                assert i < len(sections)
            # Split slice if it beings outside bounds of current slice.
            # i.e. There's a gap between last and current slice.
            if sections[i].start > _slice.start:
                gap_slice = copy(_slice)
                if sections[i].start == _slice.stop:
                    continue
                _slice.start = sections[i].start
                gap_slice.stop = _slice.start
                gap_slice.name = None
                gap_slice.section = None
                assert len(gap_slice) > 0
                self.slices.insert(slice_idx, gap_slice)
                slice_idx += 1
            # Split slice if slice ends outside bounds.
            if _slice.stop > sections[i].stop:
                assert (
                    not _slice.has_name()
                ), "Refusing to split named slice across sections"
                assert i + 1 < len(sections), "Slice ends outside section table"
                # Shrink left slice.
                old_stop = _slice.stop
                _slice.stop = sections[i].stop
                assert len(_slice) > 0
                # Create right slice.
                # This slice will be processed in the next iteration.
                right_slice = copy(_slice)
                right_slice.start = sections[i].stop
                right_slice.stop = old_stop
                assert len(right_slice) > 0
                self.slices.insert(slice_idx + 1, right_slice)
            _slice.section = sections[i].name


class SlicesCSVReader:
    """Reads a list of slices from slices.csv."""

    def __init__(self, file):
        self.reader = csv.reader(file)
        # Read CSV header.
        header = next(self.reader)
        self.cols = len(header)
        # The name field separates tags and ranges.
        name_idx = header.index("name")
        self.tag_idx = header[:name_idx]
        section_fields = header[name_idx + 1 :]
        assert (
            len(section_fields) > 0 and len(section_fields) % 2 == 0
        ), "Odd number of fields"
        # Remember section names.
        self.sections = []
        for i in range(0, len(section_fields), 2):
            assert section_fields[i].endswith("Start")
            assert section_fields[i + 1].endswith("End")
            section = section_fields[i].removesuffix("Start")
            assert section == section_fields[i + 1].removesuffix("End")
            self.sections.append(section)

    def __iter__(self) -> Generator[Slice, None, None]:
        """Returns all slices in the file."""
        for row in self.reader:
            for slice in self.parse_row(row):
                yield slice

    def parse_row(self, row: str) -> Generator[Slice, None, None]:
        """Returns all slices in a row."""
        if len(row) == 0:
            return
        assert len(row) == self.cols, "Unexpected number of fields"
        # Read flags.
        flags = set()
        for i, tag in enumerate(self.tag_idx):
            if row[i] == "1":
                flags.add(tag)
        # Read name.
        name = row[len(self.tag_idx)]
        # Read section ranges.
        ranges = row[len(self.tag_idx) + 1 :]
        for i, section in enumerate(self.sections):
            start_str, stop_str = ranges[2 * i : 2 * i + 2]
            start_str = start_str.strip()
            stop_str = stop_str.strip()
            if start_str == "":
                continue
            assert stop_str != ""
            start = int(start_str.strip(), 16)
            stop = int(stop_str, 16)
            yield Slice(start, stop, name, section, flags)
