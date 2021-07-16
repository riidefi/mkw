from bisect import bisect, bisect_left
import csv


class Slice:
    def __init__(self, start, stop, name=None, section=None, flags=set()):
        assert start <= stop, "Slice has negative length"
        self.start = start
        self.stop = stop
        self.name = name
        self.section = section
        self.flags = flags

    def __contains__(self, key):
        if not isinstance(key, Slice):
            return False
        return self.start <= key.start and self.stop >= key.stop

    def __len__(self):
        assert self.start <= self.stop, "Slice has negative length"
        return self.stop - self.start

    def __eq__(self, other):
        """Checks whether two slices occupy the same region."""
        if not isinstance(other, Slice):
            return False
        return self.start == other.start and self.stop == other.stop

    def __gt__(self, other):
        """Checks whether this slice starts after another slice."""
        if not isinstance(other, Slice):
            return False
        return self.start > other.start

    def __repr__(self):
        repr = "{ %08x..%08x" % (self.start, self.stop)
        if self.name is not None:
            repr += " " + self.name
        if self.section is not None:
            repr += " (" + self.section + ")"
        repr += "}"
        return repr


class SliceTable:
    """A list of contiguous slices for a given range."""

    def __init__(self, start, stop):
        assert start < stop, "Non-positive slice table size"
        self.slices = [Slice(start, stop)]
        self.start = start
        self.stop = stop

    def __contains__(self, slice):
        """Returns whether the range of a slice lies within the table.
        The table is not actually checked for membership."""
        return self.start <= slice.start and self.stop >= slice.stop

    def __iter__(self):
        return self.slices.__iter__()

    def __len__(self):
        return self.size()

    def size(self):
        return self.stop - self.start

    def count(self):
        return len(self.slices)

    def read_from(self, file):
        for slice in SlicesCSVReader(file):
            self.add(slice)

    # def write_to(self, file):
    #    writer = SlicesCSVWriter(file)
    #    for slice in self.slices:
    #        if slice.name is not None:
    #            writer.write(slice)

    def find_parent(self, slice):
        """Searches for a slice in the table containing the given slice."""
        i = bisect_left(self.slices, slice)
        if i < len(self.slices):
            return self.slices[i]
        return None

    def sum_named_slices(self):
        """Returns the sum of the lengths of all named/known slices."""
        t = 0
        for s in self.segs:
            if s.name is not None:
                t += len(s)
        return t

    def filter(self, filter_func):
        """Returns a new slice table with only slices that passed the filter function."""
        # A more "pythonic" approach to this would be SliceTable([for x in table if x ...])
        filtered = SliceTable(self.start, self.stop)
        for slice in self.slices:
            if slice.name is not None and filter_func(slice):
                filtered.add(slice)
        return filtered

    def add(self, slice):
        """Adds a slice to the table, changing gaps as appropriate.
        Panics if a named slice overlaps with the slice to be inserted"""
        assert slice in self, "Slice does not fit in table"
        # Find the slice in which the starting point falls.
        i = bisect(self.slices, slice) - 1
        target = self.slices[i]
        # If the new slice does not fit in the target slice,
        # the new slice overlaps at least two slices.
        # Because of the invariant that no gaps can share a border,
        # this means the new slice overlaps at least one named slice.
        assert (
            target.name is None and slice in target
        ), f"Overlapping slices:\n     new={slice}\nexisting={target}"
        # Inserting an unnamed slice is a no-op.
        if slice.name is None:
            return
        # Insert left gap.
        if slice.start > target.start:
            self.slices.insert(i, Slice(target.start, slice.start))
            i += 1
        # Insert new slice.
        self.slices[i] = slice
        # Insert right gap.
        if slice.stop < target.stop:
            self.slices.insert(i + 1, Slice(slice.stop, target.stop))


# Filter function for SliceTable.filter
only_enabled: lambda slice: "enabled" in slice.tags


class SlicesCSVReader:
    """Reads a list of slices from slices.csv."""

    def __init__(self, file):
        self.reader = csv.reader(file)
        # Read CSV header.
        header = self.reader.__next__()
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

    def __iter__(self):
        """Returns all slices in the file."""
        for row in self.reader:
            for slice in self.parse_row(row):
                yield slice

    def parse_row(self, row):
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
