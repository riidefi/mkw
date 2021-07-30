from copy import copy
from pathlib import Path

import pytablewriter
from pytablewriter.style import Style
from termcolor import colored

from mkwutil.lib.slices import SliceTable
from mkwutil.sections import Section, REL_SECTIONS, DOL_SECTIONS, DOL_LIBS

from mkwutil.project import *


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


def __to_percent(frac):
    return "%7.3f%%" % (frac * 100)


def analyze(
    name: str,
    split_code: int,
    decomp_code: int,
    decomp_data: int,
    total_code: int,
    total_data: int,
) -> list:
    cells = [""] * 4
    cells[0] = name
    if total_code:
        cells[1] = __to_percent(split_code / total_code)
        cells[2] = __to_percent(decomp_code / total_code)
    if total_data:
        cells[3] = __to_percent(decomp_data / total_data)
    return cells


def percent_decompiled(dir="."):
    dir = Path(dir)

    matrix = []
    # DOL progress.
    dol_split_slices = load_dol_slices()
    dol_blob_slices = load_dol_binary_blob_slices(dir)
    dol_decomp_slices = copy(dol_split_slices)
    mask_binary_blobs(dol_decomp_slices, dol_blob_slices)
    dol_split_code, _ = simple_count(dol_split_slices)
    dol_decomp_code, dol_decomp_data = simple_count(dol_decomp_slices)
    dol_total_code, dol_total_data = binary_total(DOL_SECTIONS)
    matrix.append(
        analyze(
            "DOL",
            dol_split_code,
            dol_decomp_code,
            dol_decomp_data,
            dol_total_code,
            dol_total_data,
        )
    )
    # DOL Libraries.
    for lib in DOL_LIBS:
        assert lib.section == "text", "For now only text section per lib supported"
        lib_split_slices = dol_split_slices.slice(lib.start, lib.stop)
        lib_decomp_slices = dol_decomp_slices.slice(lib.start, lib.stop)
        lib_split_code, _ = simple_count(lib_split_slices)
        lib_decomp_code, _ = simple_count(lib_decomp_slices)
        lib_total_code = len(lib)
        matrix.append(
            analyze(
                "> " + lib.name,
                lib_split_code,
                lib_decomp_code,
                None,
                lib_total_code,
                None,
            )
        )
    # REL progress.
    rel_split_slices = load_rel_slices()
    rel_blob_slices = load_rel_binary_blob_slices(dir)
    rel_decomp_slices = copy(rel_split_slices)
    mask_binary_blobs(rel_decomp_slices, rel_blob_slices)
    rel_split_code, _ = simple_count(rel_split_slices)
    rel_decomp_code, rel_decomp_data = simple_count(rel_decomp_slices)
    rel_total_code, rel_total_data = binary_total(REL_SECTIONS)
    matrix.append(
        analyze(
            "REL",
            rel_split_code,
            rel_decomp_code,
            rel_decomp_data,
            rel_total_code,
            rel_total_data,
        )
    )
    matrix.append(
        [
            colored(cell, attrs=["bold"])
            for cell in analyze(
                "TOTAL",
                dol_split_code + rel_split_code,
                dol_decomp_code + rel_decomp_code,
                dol_decomp_data + rel_decomp_data,
                dol_total_code + rel_total_code,
                dol_total_data + rel_total_data,
            )
        ]
    )
    # Print table.
    print("-" * 50)
    writer = pytablewriter.BorderlessTableWriter(
        headers=["part", "code split", "code decomp", "data decomp"],
        column_styles=[
            Style(align="left"),
            Style(align="right"),
            Style(align="right"),
            Style(align="right"),
        ],
        margin=1,
        value_matrix=matrix,
    )
    writer.write_table()
    print("-" * 50)

    # Player stats.
    print("Player:")
    print(" - %u BR (main.dol)" % (dol_decomp_code / dol_total_code * 4999 + 5000))
    print(" - %u VR (StaticR.rel)" % (rel_decomp_code / rel_total_code * 4999 + 5000))
    print("1 BR = %s lines of asm code." % (0.1 * round(10 * dol_total_code / 4999 / 4)))
    print("1 VR = %s lines of asm code." % (0.1 * round(10 * rel_total_code / 4999 / 4)))


if __name__ == "__main__":
    percent_decompiled()
