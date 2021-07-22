import argparse
import colorsys
from dataclasses import dataclass
from pathlib import Path
import random
import webbrowser

import jinja2

from mkwutil.sections import DOL_LIBS, DOL_SECTIONS
from mkwutil.slices import Slice, SliceTable


DOL_BEGIN = DOL_SECTIONS[0].start
DOL_END = DOL_SECTIONS[-1].stop
DOL_SIZE = DOL_END - DOL_BEGIN


jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "graphic"),
    autoescape=jinja2.select_autoescape(),
)


def make_code_color(hue):
    return colorsys.hsv_to_rgb(hue, 100 / 100, 91.8 / 100)


def make_code_color_hex(hue):
    vals = list(round(i * 255) for i in make_code_color(hue))
    r = f"#%02x%02x%02x" % (vals[0], vals[1], vals[2])
    return r


@dataclass
class Box:
    """A graphical box to display."""

    width: str
    color_code: str
    tooltip: str

    PX_FACTOR = 1 / 2000
    # CODE_COLOR = "#d5feff"
    CODE_COLOR = "hsl(%s, 100, 91.8)"
    UNK_COLOR = "#000000"

    @staticmethod
    def from_slice(_slice: Slice) -> "Box":
        if not _slice.has_name():
            return Box(len(_slice) * Box.PX_FACTOR, Box.UNK_COLOR, "")
        else:
            return Box(
                len(_slice) * Box.PX_FACTOR,
                make_code_color_hex(random.randint(0, 360) / 360),
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


def standard_boxes():
    slices = SliceTable.load_dol_slices(sections=DOL_SECTIONS)
    return map(Box.from_slice, slices)


def lib_boxes():
    slices = SliceTable(sections=DOL_SECTIONS)
    for _slice in DOL_LIBS:
        slices.add(_slice)
    return map(Box.from_slice, slices)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-o", "--output", type=Path, default="./out/website", help="Output dir")
    parser.add_argument("-s", "--silent", action="store_true", help="Don't open web browser")
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    index_path = args.output / "index.html"
    with open(index_path, "w") as file:
        jinja_env.get_template("index.html.j2").stream({
        "dol_decomp": standard_boxes(),
        "dol_libraries": lib_boxes(),
    }).dump(file)
    if not args.silent:
        webbrowser.open(index_path)
