"""
Use this to quickly add a new C source to slices and sources.
This action gets extremely repetitive while splitting.
"""

import argparse
from pathlib import Path
import re
from typing import Optional

from mkwutil.lib.slices import Slice
from mkwutil.project import load_dol_slices, save_dol_slices

parser = argparse.ArgumentParser(description="Add new file to slices and sources.py")
parser.add_argument(
    "--group",
    type=str,
    required=True,
    help="Group in sources.py, e.g. SOURCES_RVL_OS",
)
parser.add_argument(
    "--path", type=str, required=True, help="File path, e.g. source/rvl/os/osAlarm.c"
)
parser.add_argument(
    "--text", type=str, required=True, help="Text range, e.g. 0x12345678..0x12345678"
)
args = parser.parse_args()

# Parse text range
[text_start, text_stop] = args.text.split("..", 2)
text_start = int(text_start, 16)
text_stop = int(text_stop, 16)

# Add entry to slices.csv
slices = load_dol_slices()
new_slice = Slice(
    start=text_start, stop=text_stop, name=args.path, section="text", tags=["enabled"]
)
try:
    slices.add(new_slice)
    print(f"Added slice: {new_slice}")
except AssertionError:
    print(f"Slice is already tracked or overlapping, ignoring: {new_slice}")
objects = slices.object_slices()
save_dol_slices(objects)


class SourcesPy:
    """Hacky ugly thing to manipulate the sources.py Python file,
    depends on black formatting."""

    def __init__(self):
        self.path = Path(__file__).parents[2] / "sources.py"
        self.lines = open(self.path).readlines()

    def save(self):
        with open(self.path, "w", newline="\n") as sources_file:
            for line in self.lines:
                print(line, end="", file=sources_file)

    def find_source_group(self, group: str) -> Optional[range]:
        start = self._find_source_group_start(group)
        if start is None:
            return None
        match_group_end = re.compile(r"\]$")
        for (i, line) in enumerate(self.lines[start:]):
            if match_group_end.match(line):
                return range(start, start + i)
        raise AssertionError("cannot find end of source group")

    def _find_source_group_start(self, group: str) -> Optional[int]:
        match_group_start = re.compile(f"^{group} = \[$")
        for (i, line) in enumerate(self.lines):
            if match_group_start.match(line):
                return i + 1
        return None

    def add_source_entry(self, group: str, name: str):
        srcgroup_line_range = self.find_source_group(group)
        # TODO if group is not found, create it
        assert srcgroup_line_range is not None, "group not found"
        for i in srcgroup_line_range:
            if name in self.lines[i]:
                print(f"Source {name} already in {group}")
                return
        self.lines.insert(
            srcgroup_line_range.stop,
            f"""    Source(src="{name}", cc='4199_60831', opts=RVL_OPTS),\n""",
        )
        print(f"Added {name} to {group}")
        return


sources = SourcesPy()
sources.add_source_entry(args.group, args.path)
sources.save()
