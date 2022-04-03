import argparse
from copy import copy
from pathlib import Path

import pytablewriter
from pytablewriter.style import Style
from termcolor import colored

from mkwutil.lib.slices import SliceTable
from mkwutil.sections import Section, DOL_SECTIONS, DOL_LIBS, REL_SECTIONS, REL_DIRS

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


@dataclass
class Stats:
    matrix: list
    dol_decomp_code: int
    dol_total_code: int
    rel_decomp_code: int
    rel_total_code: int

    def print(self):
        # Make last row bold.
        self.matrix[-1] = list(
            map(lambda x: colored(x, attrs=["bold"]), self.matrix[-1])
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
            value_matrix=self.matrix,
        )
        writer.write_table()
        print("-" * 50)

        # Player stats.
        print("Player:")
        print(
            " - %u BR (main.dol)"
            % (self.dol_decomp_code / self.dol_total_code * 4999 + 5000)
        )
        print(
            " - %u VR (StaticR.rel)"
            % (self.rel_decomp_code / self.rel_total_code * 4999 + 5000)
        )
        print(
            "1 BR = %s lines of asm code."
            % (0.1 * round(10 * self.dol_total_code / 4999 / 4))
        )
        print(
            "1 VR = %s lines of asm code."
            % (0.1 * round(10 * self.rel_total_code / 4999 / 4))
        )


def build_stats(dir: Path) -> Stats:
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
    # REL directories.
    for dir in REL_DIRS:
        assert (
            dir.section == "text"
        ), "For now only text section per directory supported"
        dir_split_slices = rel_split_slices.slice(dir.start, dir.stop)
        dir_decomp_slices = rel_decomp_slices.slice(dir.start, dir.stop)
        dir_split_code, _ = simple_count(dir_split_slices)
        dir_decomp_code, _ = simple_count(dir_decomp_slices)
        dir_total_code = len(dir)
        matrix.append(
            analyze(
                "> " + dir.name,
                dir_split_code,
                dir_decomp_code,
                None,
                dir_total_code,
                None,
            )
        )
    matrix.append(
        analyze(
            "TOTAL",
            dol_split_code + rel_split_code,
            dol_decomp_code + rel_decomp_code,
            dol_decomp_data + rel_decomp_data,
            dol_total_code + rel_total_code,
            dol_total_data + rel_total_data,
        )
    )
    return Stats(
        matrix, dol_decomp_code, dol_total_code, rel_decomp_code, rel_total_code
    )


def __main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-s", "--short", action="store_true", help="Only print percentage"
    )
    parser.add_argument("--part", choices=["DOL", "REL"], default=None)
    args = parser.parse_args()
    stats = build_stats(Path())
    if args.short:
        if args.part == "DOL":
            progress = stats.dol_decomp_code / stats.dol_total_code
        elif args.part == "REL":
            progress = stats.rel_decomp_code / stats.rel_total_code
        else:
            decomp_code = stats.dol_decomp_code + stats.rel_decomp_code
            total_code = stats.dol_total_code + stats.rel_total_code
            progress = decomp_code / total_code
        print(__to_percent(progress).strip())
    else:
        stats.print()


if __name__ == "__main__":
    __main()
