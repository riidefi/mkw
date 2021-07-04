import csv
import os
from pathlib import Path


def process_line(tags, items):
    name = "Untitled"
    start = None
    code_total = 0
    data_total = 0

    for tag, entry in zip(tags, items):
        if tag == "enabled" and entry == 0:
            return
        elif tag == "name":
            name = entry
            continue

        is_code = "text" in tag

        if "Start" in tag:
            if not entry:
                start = None
                continue

            start = int(entry, 16)
            continue

        if "End" in tag and start:
            size = int(entry, 16) - start

            if is_code:
                code_total += size
            else:
                data_total += size

    name = items[1]
    return name, code_total, data_total


def parse_slices(path):
    with open(path, "r") as file:
        lines = file.readlines()

        tags = lines[0].split(",")
        for line in lines[1:]:
            yield process_line(tags, line.split(","))


def simple_count(path):
    code_total = 0
    data_total = 0

    for o_name, o_code_total, o_data_total in parse_slices(path):
        code_total += o_code_total
        data_total += o_data_total

    return code_total, data_total


def segments_of(path):
    with open(path, "r") as file:
        reader = csv.DictReader(file)
        for line in reader:
            is_code = "text" in line["name"]
            yield is_code, int(line["end"], 16) - int(line["start"], 16)


def binary_total(path):
    segments = list(segments_of(path))

    num_code = sum(size if is_code else 0 for is_code, size in segments)
    num_data = sum(size if not is_code else 0 for is_code, size in segments)

    return num_code, num_data


def to_percent(frac):
    return round(frac * 100_000) / 1000


def analyze(prefix, progress, total):
    # 	print("%s %s bytes (%s%%) of code, %s bytes (%s%%) of data decompiled" % (
    # 		prefix,
    # 		progress[0], to_percent(progress[0] / total[0]) if total[0] else '',
    # 		progress[1], to_percent(progress[1] / total[1]) if total[1] else ''
    # 	))
    print(
        "%s %s%% code, %s%% data decompiled"
        % (
            prefix,
            to_percent(progress[0] / total[0]) if total[0] else "",
            to_percent(progress[1] / total[1]) if total[1] else "",
        )
    )

# TODO: This system is garbage.
# Ideally we'd have
#
# { "name": "EGG", "start": ..., "end": ...}
# 
# and it would generate everything for us
#

def get_progress(slices, filter):
    progress = [0, 0]
    for o_name, o_code_total, o_data_total in slices:
        if not filter in o_name:
            continue

        progress[0] += o_code_total
        progress[1] += o_data_total

    return progress

def percent_decompiled(dir="."):
    dir = Path(dir)
    dol_slices_path = dir / "pack" / "dol_slices.csv"
    dol_progress = simple_count(dol_slices_path)
    dol_segments_path = dir / "pack" / "dol_segments.csv"
    dol_total = binary_total(dol_segments_path)
    analyze("[DOL]", dol_progress, dol_total)

    rvl_progress = get_progress(parse_slices(dol_slices_path), "rvl")
    rvl_total = [0x8020F62C - 0x80123F88, None]
    analyze("  -> [RVL]", rvl_progress, rvl_total)

    egg_progress = get_progress(parse_slices(dol_slices_path), "egg")
    egg_total = [0x80244DD4 - 0x8020F62C, None]
    analyze("  -> [EGG]", egg_progress, egg_total)

    spy_progress = get_progress(parse_slices(dol_slices_path), "gamespy")
    spy_total = [0x80123F88 - 0x800EF378, None]
    analyze("  -> [SPY]", spy_progress, spy_total)

    rel_slices_path = dir / "pack" / "rel_slices.csv"
    rel_progress = simple_count(rel_slices_path)
    rel_segments_path = dir / "pack" / "rel_segments.csv"
    rel_total = binary_total(rel_segments_path) 
    analyze("[REL]", rel_progress, rel_total)

    def piecewise_add(x, y):
        return list(a + b for a, b in zip(x, y))

    analyze(
        "--- main.dol + StaticR.rel ---\n",
        piecewise_add(dol_progress, rel_progress),
        piecewise_add(dol_total, rel_total),
    )

    print("------")
    print("Player:")
    print(" - %u BR (main.dol)" % (dol_progress[0] / dol_total[0] * 4999 + 5000))
    print(" - %u VR (StaticR.rel)" % (rel_progress[0] / rel_total[0] * 4999 + 5000))

    print("1 BR = %s lines of asm code." % (.1 * round(10 * dol_total[0] / 4999 / 4)))
    print("1 VR = %s lines of asm code." % (.1 * round(10 * rel_total[0] / 4999 / 4)))


if __name__ == "__main__":
    percent_decompiled()
