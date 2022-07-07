from argparse import ArgumentParser
import os
from pathlib import Path

DEVKITPPC = Path(os.environ.get("DEVKITPPC", "./tools/devkitppc"))


def apply(config: dict, args):
    if args.rel:
        config["mapfile"] = "artifacts/target/pal/staticR.map"
        config["myimg"] = "artifacts/target/pal/staticR.rel"
        config["baseimg"] = "artifacts/orig/pal/staticR.rel"
    else:
        config["mapfile"] = "artifacts/target/pal/main.map"
        config["myimg"] = "artifacts/target/pal/main.dol"
        config["baseimg"] = "artifacts/orig/pal/main.dol"
    config["makeflags"] = []
    config["source_directories"] = ["source"]
    config["arch"] = "ppc"
    config["map_format"] = "mw"  # gnu or mw
    config["mw_build_dir"] = "out"  # only needed for mw map format
    config["makeflags"] = []
    config["objdump_executable"] = DEVKITPPC / "bin" / "powerpc-eabi-objdump.exe"

def add_custom_arguments(parser: ArgumentParser):
    parser.add_argument("-r", "--rel", action="store_true", help="(MKW) Diff a function in staticR.rel")
