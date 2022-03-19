import argparse
import colorsys
from dataclasses import dataclass
from io import StringIO
from pathlib import Path
import random
import webbrowser

import jinja2
from pytablewriter import HtmlTableWriter
from pytablewriter.style import Style

from mkwutil.sections import DOL_LIBS, DOL_SECTIONS, REL_SECTIONS, REL_DIRS
from mkwutil.lib.slices import Slice, SliceTable
import mkwutil.project as project
from mkwutil.progress.percent_decompiled import build_stats


random.seed("OwO")
current_hue = 360.0 * random.random()


DOL_BEGIN = DOL_SECTIONS[0].start
DOL_END = DOL_SECTIONS[-1].stop
DOL_SIZE = DOL_END - DOL_BEGIN


jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "progress/graphic"),
    autoescape=jinja2.select_autoescape(),
)


def make_code_color_hex():
    global current_hue

    hue = current_hue
    color = colorsys.hsv_to_rgb(hue / 360, 100 / 100, 91.8 / 100)
    vals = list(round(i * 255) for i in color)
    r = f"#%02x%02x%02x" % (vals[0], vals[1], vals[2])

    current_hue = (current_hue + 90.0 + 180.0 * random.random()) % 360.0

    return r


@dataclass
class Box:
    """A graphical box to display."""

    width: str
    color_code: str
    tooltip: str

    PX_FACTOR = 1 / 2000
    UNK_COLOR = "#000000"

    @staticmethod
    def from_slice(_slice: Slice) -> "Box":
        if not _slice.has_name():
            return Box(len(_slice) * Box.PX_FACTOR, Box.UNK_COLOR, "")
        else:
            return Box(
                len(_slice) * Box.PX_FACTOR,
                make_code_color_hex(),
                _slice.name,
            )


def size_of_mapper(slices: SliceTable) -> tuple[int, int]:
    n_code = 0
    n_unk = 0
    for _slice in slices:
        if not _slice.has_name():
            n_unk += len(_slice)
        else:
            n_code += len(_slice)
    return n_code, n_unk


def percent_decomp_stats(slices: SliceTable) -> None:
    """Prints percent stats of slices."""
    n_code, n_unk = size_of_mapper(slices)

    total = n_unk + n_code
    print("Total: %s, real total: %s" % (total, DOL_SIZE))

    print("Code&Data Percent: %s" % (100 * n_code / total))

def dol_boxes():
    slices = project.load_dol_slices(sections=DOL_SECTIONS)
    return map(Box.from_slice, slices)

def rel_boxes():
    slices = project.load_rel_slices(sections=REL_SECTIONS)
    return map(Box.from_slice, slices)

def section_to_slice(s):
    return Slice(name=s.name, start=s.start, stop=s.stop, section=s.type)

def dol_section_boxes():
    slices = SliceTable(sections=DOL_SECTIONS)
    for s in DOL_SECTIONS:
        slices.add(section_to_slice(s))
    return map(Box.from_slice, slices)

def rel_section_boxes():
    slices = SliceTable(sections=REL_SECTIONS)
    for s in REL_SECTIONS:
        slices.add(section_to_slice(s))
    return map(Box.from_slice, slices)

def dol_lib_boxes():
    slices = SliceTable(sections=DOL_SECTIONS)
    for _slice in DOL_LIBS:
        slices.add(_slice)
    return map(Box.from_slice, slices)

def rel_dir_boxes():
    slices = SliceTable(sections=REL_DIRS)
    for _slice in REL_DIRS:
        slices.add(_slice)
    return map(Box.from_slice, slices)


def percent_decompiled_table() -> str:
    stats = build_stats(Path())
    writer = HtmlTableWriter(
        headers=["part", "code split", "code decomp", "data decomp"],
        column_styles=[
            Style(align="left"),
            Style(align="right"),
            Style(align="right"),
            Style(align="right"),
        ],
        margin=10,
        value_matrix=stats.matrix,
    )
    writer.stream = StringIO()
    writer.write_table()
    return writer.stream.getvalue()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-o", "--output", type=Path, default="./out/website", help="Output dir"
    )
    parser.add_argument(
        "-s", "--silent", action="store_true", help="Don't open web browser"
    )
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    index_path = args.output / "index.html"
    with open(index_path, "w") as file:
        jinja_env.get_template("index.html.j2").stream(
            {
                "percents_table": percent_decompiled_table(),
                "dol_decomp": dol_boxes(),
                "dol_libraries": dol_lib_boxes(),
                "dol_sections": dol_section_boxes(),
                "rel_decomp": rel_boxes(),
                "rel_sections": rel_section_boxes(),
                "rel_directories": rel_dir_boxes(),
            }
        ).dump(file)
    if not args.silent:
        webbrowser.open(index_path)
