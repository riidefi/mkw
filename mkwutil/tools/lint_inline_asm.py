#!/usr/bin/env python3

"""
A dumb little linter for inline assembly.
"""

from abc import ABC, abstractmethod
import argparse
from dataclasses import dataclass
import os
from pathlib import Path
import re
from typing import Iterator, Optional
import struct
import sys

import colorama
from termcolor import cprint
from mkwutil.lib.dol import DolBinary

from mkwutil.project import read_dol


@dataclass
class LintViolation:
    """An instance of a lint violation."""

    col_start: int
    col_stop: int
    msg: str
    line: int = -1
    file: str = ""
    comment: str = ""


class Source:
    """A source code file, line by line."""

    lines: list[str]

    def __init__(self, path):
        with open(path, "r") as source_file:
            self.lines = [line.rstrip("\r\n") for line in source_file.readlines()]


class BaseLineRule(ABC):
    """Base class for lint rules that operate line-by-line."""

    def process(self, source: Source) -> Iterator[LintViolation]:
        for i, line in enumerate(source.lines):
            violation = self.process_line(line)
            if violation:
                violation.line = i
                yield violation

    @abstractmethod
    def process_line(self, line: str) -> Optional[LintViolation]:
        pass


class BaseRegexRule(BaseLineRule):
    def __init__(self, rule_name: str, pattern: str):
        self.rule_name = rule_name
        self.pattern = re.compile(pattern)

    def process_line(self, line: str) -> Optional[LintViolation]:
        match = self.pattern.match(line)
        if match:
            start, stop = match.span()
            violation = LintViolation(start, stop - 1, self.rule_name)
            self.on_match(match, violation)
            return violation

    def on_match(self, match: re.Match, violation: LintViolation):
        pass


class SdataAbsoluteRefRule(BaseRegexRule):
    def __init__(self, dol: Optional[DolBinary]):
        self.dol = dol
        self.r13 = 0x8038CC00
        super().__init__(
            "sdata/sbss absolute addressing",
            r"^\s+(addi r\d{1,2}, r13, (-?(?:0x)?[0-9a-f]+));.*$",
        )

    def on_match(self, match: re.Match, violation: LintViolation):
        try:
            self._on_match(match, violation)
        except Exception as e:
            violation.comment = str(e)

    def _on_match(self, match: re.Match, violation: LintViolation):
        source = int(match.group(2))
        address = self.r13 + source
        values = ""
        if self.dol:
            data = self.dol.virtual_read(address, 4) or b"\x00\x00\x00\x00"
            values = "~> %#010x " % (struct.unpack(">I", data)[0])
        violation.comment = f"{values}@ {hex(address)}"


class SdataAbsoluteAccessRule(BaseRegexRule):
    def __init__(self, dol: Optional[DolBinary]):
        self.dol = dol
        self.r13 = 0x8038CC00
        super().__init__(
            "sdata/sbss absolute access",
            r"^\s+((lwz|stw|lhz|lha|sth|lbz|stb|lfs|stfs) (?:r|f)\d{1,2}, (-?0x[0-9a-f]+)\(r13\));.*$",
        )

    def on_match(self, match: re.Match, violation: LintViolation):
        try:
            self._on_match(match, violation)
        except Exception as e:
            violation.comment = str(e)

    def _on_match(self, match: re.Match, violation: LintViolation):
        opcode = match.group(2)
        source = int(match.group(3), 16)
        address = self.r13 + source

        values = ""
        if self.dol:
            if opcode == "lwz":
                data = self.dol.virtual_read(address, 4) or b"\x00\x00\x00\x00"
                values = "~> %#010x " % (struct.unpack(">I", data)[0])
            elif opcode == "lhz":
                data = self.dol.virtual_read(address, 2) or b"\x00\x00"
                values = "~> %#06x " % (struct.unpack(">H", data)[0])
            elif opcode == "lha":
                data = self.dol.virtual_read(address, 2) or b"\x00\x00"
                values = "~> %#06x " % (struct.unpack(">h", data)[0])
            elif opcode == "lbz":
                data = self.dol.virtual_read(address, 1) or b"\x00"
                values = "~> %#04x " % data[0]
            elif opcode == "lfs":
                data = self.dol.virtual_read(address, 4)
                item_float = struct.unpack(">f", data)[0]
                item_int = struct.unpack(">I", data)[0]
                values = "~> %ff (%#08x) " % (item_float, item_int)
            elif opcode == "lfd":
                data = self.dol.virtual_read(address, 8)
                item_float = struct.unpack(">d", data)[0]
                item_int = struct.unpack(">Q", data)[0]
                values = "~> %f (%#016x) " % (item_float, item_int)

        violation.comment = f"{values}@ {hex(address)}"


class Sdata2AbsoluteAccessRule(BaseRegexRule):
    def __init__(self, dol: Optional[DolBinary]):
        self.dol = dol
        self.r2 = 0x8038EFA0
        super().__init__(
            "sdata2 absolute access",
            r"^\s+((lfs|lfd|lhz) [rf]\d{1,2}, (-?0x[0-9a-f]+)\(r2\));.*$",
        )

    def on_match(self, match: re.Match, violation: LintViolation):
        try:
            self._on_match(match, violation)
        except Exception as e:
            violation.comment = str(e)

    def _on_match(self, match: re.Match, violation: LintViolation):
        opcode = match.group(2)
        source = int(match.group(3), 16)
        address = self.r2 + source

        values = ""
        if self.dol:
            if opcode == "lfs":
                data = self.dol.virtual_read(address, 4)
                item_float = struct.unpack(">f", data)[0]
                item_int = struct.unpack(">I", data)[0]
                values = "~> %ff (%#08x) " % (item_float, item_int)
            elif opcode == "lfd":
                data = self.dol.virtual_read(address, 8)
                item_float = struct.unpack(">d", data)[0]
                item_int = struct.unpack(">Q", data)[0]
                values = "~> %f (%#016x) " % (item_float, item_int)

        violation.comment = f"{values}@ {hex(address)}"


class LintBasicFormatter:
    def print(self, source: Source, lint: LintViolation):
        print(f"{lint.file}:{lint.line+1} {lint.msg}")


class LintPrettyFormatter:
    def print(self, source: Source, lint: LintViolation):
        cprint(f"{lint.msg}", "white", attrs=["bold"], end="")
        cprint(f" in {lint.file}:{lint.line+1}", "white")
        self._print_line(source, lint, lint.line - 1)
        self._print_line(source, lint, lint.line)
        self._print_line(source, lint, lint.line + 1)
        print()

    def _print_line(self, source: Source, lint: LintViolation, line: int):
        if source.lines[line] is None:
            return
        cprint("% 5d > " % (line + 1), "white", attrs=["dark"], end="")
        line_str = source.lines[line]
        if lint.line == line:
            cprint(line_str[: lint.col_start], end="")
            cprint(
                line_str[lint.col_start : lint.col_stop], "red", attrs=["bold"], end=""
            )
            cprint(line_str[lint.col_stop :], end="")
            if len(lint.comment) > 0:
                cprint(" " + lint.comment, "blue", end="")
            print()
        else:
            cprint(line_str)


def get_lint_formatter(pretty, ugly):
    if (pretty or os.isatty(sys.stdout.fileno())) and not ugly:
        colorama.init(strip=False)
        return LintPrettyFormatter()
    else:
        return LintBasicFormatter()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, nargs="+", help="File paths to lint")
    parser.add_argument("--short", action="store_true", help="Short output")
    parser.add_argument("--pretty", action="store_true", help="Force enable color")
    args = parser.parse_args()

    dol = read_dol()
    try:
        dol = read_dol()
    except:
        dol = None
        print("WARN: running without DOL")

    # Collect list of source paths, respecting wildcards.
    source_paths = []
    root_dir = Path(".")
    for file_path in args.file:
        source_paths.extend(
            path_obj for path_obj in root_dir.glob(file_path) if path_obj.is_file()
        )

    linters = [
        SdataAbsoluteAccessRule(dol),
        SdataAbsoluteRefRule(dol),
        Sdata2AbsoluteAccessRule(dol),
    ]
    formatter = get_lint_formatter(args.pretty, args.short)
    for source_path in source_paths:
        source = Source(source_path)
        for linter in linters:
            for violation in linter.process(source):
                violation.file = str(source_path)
                formatter.print(source, violation)


if __name__ == "__main__":
    main()
