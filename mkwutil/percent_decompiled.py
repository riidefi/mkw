from copy import copy
from pathlib import Path

import pytablewriter
from pytablewriter.style import Style
from termcolor import colored

from mkwutil.slices import SliceTable
from mkwutil.sections import Section, REL_SECTIONS, DOL_SECTIONS, DOL_LIBS


def simple_count(slices: SliceTable) -> tuple[int, int]:
    """Returns the number of code and data bytes part of named slices."""
    code_total, data_total = 0, 0
    for _slice in slices:
        if not _slice.has_name():
            continue
        if _slice.section in ("init", "text"):
            code_total += len(_slice)
        else:
            data_total += len(_slice)
    return code_total, data_total


def binary_total(sections: list[Section]) -> tuple[int, int]:
    """Returns the number of code and data bytes in the binary."""
    code_total, data_total = 0, 0
    for section in sections:
        if section.name in ("init", "text"):
            code_total += len(section)
        else:
            data_total += len(section)
    return code_total, data_total


def to_percent(frac):
    return "%7.3f%%" % (frac * 100)


def analyze(prefix, progress, total):
    cells = [""] * 3
    cells[0] = prefix
    if total[0]:
        cells[1] = to_percent(progress[0] / total[0])
    if total[1]:
        cells[2] = to_percent(progress[1] / total[1])
    return cells


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

    matrix = []
    # DOL progress.
    dol_slices = SliceTable.load_dol_slices()
    dol_progress = simple_count(dol_slices)
    dol_total = binary_total(DOL_SECTIONS)
    matrix.append(analyze("DOL", dol_progress, dol_total))
    # DOL Libraries.
    for lib in DOL_LIBS:
        assert lib.section == "text", "For now only text section per lib supported"
        lib_progress = simple_count(dol_slices.slice(lib.start, lib.stop))
        lib_total = (len(lib), None)
        matrix.append(analyze("> " + lib.name, lib_progress, lib_total))
    # REL progress.
    rel_slices = SliceTable.load_rel_slices()
    rel_progress = simple_count(rel_slices)
    rel_total = binary_total(REL_SECTIONS)
    matrix.append(analyze("REL", rel_progress, rel_total))
    # Total progress.
    def piecewise_add(x, y):
        return list(a + b for a, b in zip(x, y))

    matrix.append(
        [
            colored(cell, attrs=["bold"])
            for cell in analyze(
                "TOTAL",
                piecewise_add(dol_progress, rel_progress),
                piecewise_add(dol_total, rel_total),
            )
        ]
    )
    # Print table.
    print("-" * 31)
    writer = pytablewriter.BorderlessTableWriter(
        headers=["part", "code", "data"],
        column_styles=[
            Style(align="left"),
            Style(align="right"),
            Style(align="right"),
        ],
        margin=1,
        value_matrix=matrix,
    )
    writer.write_table()
    print("-" * 31)

    # Player stats.
    print("Player:")
    print(" - %u BR (main.dol)" % (dol_progress[0] / dol_total[0] * 4999 + 5000))
    print(" - %u VR (StaticR.rel)" % (rel_progress[0] / rel_total[0] * 4999 + 5000))
    print("1 BR = %s lines of asm code." % (0.1 * round(10 * dol_total[0] / 4999 / 4)))
    print("1 VR = %s lines of asm code." % (0.1 * round(10 * rel_total[0] / 4999 / 4)))


if __name__ == "__main__":
    percent_decompiled()
