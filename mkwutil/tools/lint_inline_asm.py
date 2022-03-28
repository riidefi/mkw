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
import sys

import colorama
from termcolor import cprint


@dataclass
class LintViolation:
    """An instance of a lint violation."""

    col_start: int
    col_stop: int
    msg: str
    line: int = -1
    file: str = ""


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
            return LintViolation(start, stop-1, self.rule_name)


SdataAbsoluteRule = BaseRegexRule(
    "sdata/sbss reference",
    r"^\s+((?:lwz|stw|lhz|lha|sth|lbz|stb) r\d{1,2}, -?0x[0-9a-f]+\(r13\));.*$",
)
Sdata2AbsoluteRule = BaseRegexRule(
    "sdata2 reference",
    r"^\s+((?:lfs|lfd|lhz) [rf]\d{1,2}, -?0x[0-9a-f]+\(r2\));.*$",
)


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
            cprint(line_str[lint.col_stop :])
        else:
            cprint(line_str)


def get_lint_formatter():
    if os.isatty(sys.stdout.fileno()):
        colorama.init()
        return LintPrettyFormatter()
    else:
        return LintBasicFormatter()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, nargs="+", help="File paths to lint")
    args = parser.parse_args()

    # Collect list of source paths, respecting wildcards.
    source_paths = []
    root_dir = Path(".")
    for file_path in args.file:
        source_paths.extend(
            path_obj for path_obj in root_dir.glob(file_path) if path_obj.is_file()
        )

    linters = [
        SdataAbsoluteRule,
        Sdata2AbsoluteRule,
    ]
    formatter = get_lint_formatter()
    for source_path in source_paths:
        source = Source(source_path)
        for linter in linters:
            for violation in linter.process(source):
                violation.file = str(source_path)
                formatter.print(source, violation)


if __name__ == "__main__":
    main()
