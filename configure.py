#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "RMCP01",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20240706"
config.dtk_tag = "v1.3.0"
config.objdiff_tag = "v2.4.0"
config.sjiswrap_tag = "v1.2.0"
config.wibo_tag = "0.6.11"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
    f"--defsym VERSION_{config.version}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-linkmode moreram",
]
config.rel_strip_partial = False
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-align powerpc",
    "-enc SJIS",
    # "-I-",
    "-gccinc",
    # "-inline deferred",
    "-proc gekko",
    "-enum int",
    "-O4,p",
    "-inline auto",
#    "-W all",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-RTTI off",
    #'-pragma "cats off"',  # ???
    # "-pragma \"aggressive_inline on\"",
    # "-pragma \"auto_inline on\"",
    "-inline auto",
#    "-w notinlined -W noimplicitconv -w nounwanted",
    "-nostdinc",
    "-DREVOKART",
    "-func_align 4",
    #"-sym dwarf-2",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-inline auto",
]

# MSL flags
cflags_msl = [
    *cflags_base,
    "-lang=c99",
    "-ipa file",
    "-i lib/MSL/include"
]

# RVL flags
cflags_rvl = [
    *cflags_base,
    "-lang=c99",
    "-ipa file",
]

# RFL flags
cflags_rfl = cflags_rvl

# SPY flags
cflags_spy = [
    *cflags_rvl,
    "-w nounusedexpr -w nounusedarg",
]

# NW4R flags
cflags_nw4r = [
    *cflags_base,
#    "-lang=c99", # needed?
    "-ipa file",
    "-pragma \"legacy_struct_alignment on\"",
]

# EGG flags
cflags_egg = [
    *cflags_base,
#    "-lang=c99", # needed?
    "-ipa function",
    "-rostr",
    "-use_lmw_stmw=on",
]

# DOL flags
cflags_dol = [
    *cflags_base,
    "-ipa file",
    "-rostr",
    "-str noreuse",
    "-use_lmw_stmw=on"
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

# StaticR flags
cflags_staticr = [
    *cflags_rel,
    "-ipa file",
    "-rostr",
    "-str noreuse",
    "-use_lmw_stmw=on",
    "-lang=c++",
    "-pragma \"legacy_struct_alignment on\"",

    " -i lib/MSL/include "
    " -i lib " # just for now, individual include directories for each lib is tidier
    " -i ./include -i ./src ",

    "-DREL",
]

config.linker_version = "Wii/0x4201_127"


# Helper function for Revolution libraries
def RevolutionLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "src_dir": "lib/Runtime.PPCEABI.H",
        "objects": [
            Object(NonMatching, "global_destructor_chain.c"),
            Object(NonMatching, "__init_cpp_exceptions.cpp"),
#            Object(NonMatching, "Runtime.PPCEABI.H/ExceptionPPC.cpp"),
        ],
    },
    {
        "lib": "MSL_C",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_msl,
        "progress_category": "sdk",
        "src_dir": "lib/MSL/src",
        "objects": [
            Object(NonMatching, "ansi_files.c"),
            Object(NonMatching, "float.c"),
            Object(NonMatching, "mem.c"),
            Object(NonMatching, "mem_cpy.c"),
            Object(NonMatching, "qsort.c"),
            Object(Matching, "rand.c"),
            Object(Matching, "wchar.c"),
            Object(NonMatching, "va_arg.c"),
        ],
    },
    {
        "lib": "StaticR",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_staticr,
        "progress_category": "game",
        "src_dir": "src",
        "objects": [
            Object(Matching, "util/ModuleSymbols.cpp"),
            Object(NonMatching, "system/CourseMap.cpp"),
            Object(Matching, "system/DvdArchive.cpp"),
            Object(Matching, "system/LocalizedArchive.cpp"),
            Object(Matching, "system/MultiDvdArchive.cpp"),
        ],
    },
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects

# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
