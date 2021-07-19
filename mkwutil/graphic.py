import argparse
import colorsys
import csv
import jinja2
from pathlib import Path
import random

from mkwutil.slices import SliceTable


jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "graphic"),
    autoescape=jinja2.select_autoescape(),
)


# CODE_COLOR = "#d5feff"
CODE_COLOR = "hsl(%s, 100, 91.8)"
UNK_COLOR = "#000000"


def make_code_color(hue):
    return colorsys.hsv_to_rgb(hue, 100 / 100, 91.8 / 100)


def make_code_color_hex(hue):
    vals = list(round(i * 255) for i in make_code_color(hue))
    r = f"#%02x%02x%02x" % (vals[0], vals[1], vals[2])
    return r


PX_FACTOR = 1 / 2000


def box_from_code_seg(begin, end, label):
    return build_box(
        abs(end - begin) * PX_FACTOR,
        label,
        make_code_color_hex(random.randint(0, 360) / 360),
    )


def box_from_gap_seg(begin, end):
    return build_box(abs(end - begin) * PX_FACTOR, "gap", UNK_COLOR)


dol_slices_path = Path(__file__) / ".." / ".." / "pack" / "dol_slices.csv"
SPLITS = []
with open(dol_slices_path, "r") as f:
    reader = csv.reader(f)
    assert next(reader) is not None, "empty CSV file"
    for row in reader:
        assert len(row) > 3, "Not enough columns in row"
        if row[1] != "1":
            continue
        addresses = []
        for a in row[3:]:
            addresses.append(int(a, 16) if len(a) > 0 else 0)
        SPLITS.append(addresses)


def populate_mapper(mapper, splits):
    for split in splits:
        file = split[0]
        for i in range(1, len(split), 2):
            sec = [split[i], split[i + 1]]

            if sec[0] == 0:
                assert sec[1] == 0
                continue

            if sec[0] == sec[1]:
                print(
                    "WARN: file %s invalidy configured, begin == end, begin != 0" % file
                )
                continue

            assert sec[1] > sec[0]

            mapper.add_mem_range(sec, file)

    for seg in mapper.segs:
        perc = "-" * int(1 + abs(seg[0] - seg[1]) / 400000)
        print("%s %s %s %s" % (perc, hex(seg[0]), hex(seg[1]), seg[2]))


def size_of_mapper(mapper):
    n_code = 0
    n_unk = 0

    for seg in mapper.segs:
        if seg[2] == "unk":
            n_unk += abs(seg[0] - seg[1])
        else:
            n_code += abs(seg[0] - seg[1])

    return n_code, n_unk


def boxlist_from_mapper(mapper):
    boxes = []

    for seg in mapper.segs:
        if seg[2] == "unk":
            boxes.append(box_from_gap_seg(seg[0], seg[1]))
        else:
            boxes.append(box_from_code_seg(seg[0], seg[1], seg[2]))

    return boxes


def percent_decomp_stats(mapper):
    n_code, n_unk = size_of_mapper(mapper)

    total = n_unk + n_code
    print("Total: %s, real total: %s" % (total, DOL_SIZE))

    print("Code&Data Percent: %s" % (100 * n_code / total))


DOL_BEGIN = 0x80004000
DOL_END = 0x8038917C

DOL_SIZE = DOL_END - DOL_BEGIN


def standard_boxes():
    mapper = RangeMapper(DOL_BEGIN, DOL_END)
    populate_mapper(mapper, SPLITS)

    # percent_decomp_stats(mapper)

    return boxlist_from_mapper(mapper)


LIB_SPLITS = [
    ["NW4R", 0x80021BB0, 0x800BBB80],
    ["RFL", 0x800BBB80, 0x800CC7E4],
    ["DWC", 0x800CC7E4, 0x800EF378],
    ["SPY", 0x800EF378, 0x80123F88],
    ["RVL", 0x80123F88, 0x8020F62C],
    ["EGG", 0x8020F62C, 0x80244DD4],
]


def lib_boxes():
    mapper = RangeMapper(DOL_BEGIN, DOL_END)
    populate_mapper(mapper, LIB_SPLITS)

    return boxlist_from_mapper(mapper)


def get_context():
    dol_decomp_boxes = standard_boxes()
    print(dol_decomp_boxes)
    import os

    os.exit(1)
    return {}


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-o", "--output", type=Path, default="out.html")
    args = parser.parse_args()
    jinja_env.get_template("index.html.j2").stream(get_context()).dump(args.output)
