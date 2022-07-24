from pathlib import Path
from itertools import chain
import argparse

from sources import SOURCES_DOL, SOURCES_REL
from build import CWCC_PATHS, run_windows_cmd

CW_ARGS = [
    # "-I-",
    "-gccinc",
    "-i ./source/ -i ./source/platform",
    "-proc gekko",
    "-W all",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-RTTI off",
    "-w notinlined -W noimplicitconv -w nounwanted",
    "-nostdinc",
    "-msgstyle gcc -lang=c99 -DREVOKART",
    "-func_align 4",
    "-stderr",
    "-E",
]
CWCC_OPT = " ".join(CW_ARGS)


def get_ctx(match: str, out: Path):
    source_header = "source/game/system/ResourceManager.hpp"
    source = next(x for x in chain(SOURCES_DOL, SOURCES_REL) if match in x.src)
    source_header = Path(source.src).with_suffix(".hpp")
    print(f"Generating context for {source_header} at {out}")
    command = f"{CWCC_PATHS[source.cc]} {CWCC_OPT} {source_header} -o {out}"
    lines, retcode = run_windows_cmd(command)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Creates context for source file containing match by running CWCC preprocessor"
    )
    parser.add_argument("match", type=str)
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        default=Path("ctx.hpp"),
        help="Path to output the generated context",
    )
    args = parser.parse_args()
    get_ctx(args.match, args.output)
