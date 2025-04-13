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
config.wibo_tag = "0.6.16"

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
config.shift_jis = False
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
    # "-W all",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-RTTI off",
    # '-pragma "cats off"',  # ???
    # "-pragma \"aggressive_inline on\"",
    # "-pragma \"auto_inline on\"",
    "-inline auto",
    # "-w notinlined -W noimplicitconv -w nounwanted",
    "-nostdinc",
    "-DREVOKART",
    "-func_align 4",
    # "-sym dwarf-2",
    
    "-i ./include",
    "-i ./src",
    "-i lib/MSL/include",
    "-i lib",  # just for now, individual include directories for each lib is tidier

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

# HostSys flags
cflags_host_sys = [
    *cflags_base,
    "-ipa file",
    "-rostr",
    "-str noreuse",
    "-use_lmw_stmw=on",
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
    # "-lang=c99", # needed?
    "-ipa file",
    '-pragma "legacy_struct_alignment on"',
]

# EGG flags
cflags_egg = [
    *cflags_base,
    # "-lang=c99", # needed?
    "-ipa function",
    "-rostr",
    "-use_lmw_stmw=on",
    " -i lib/MSL/include "
    " -i lib " # just for now, individual include directories for each lib is tidier
    " -i ./include -i ./src ",
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
    '-pragma "legacy_struct_alignment on"',
    "-DREL",
]

cflags_staticr_gekko = [
    *cflags_staticr,
    "-DGEKKO",
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
        "lib": "HostSys",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_host_sys,
        "progress_category": "game",
        "src_dir": "src",
        "objects": [
            Object(Matching, "host_system/SystemResource.cpp"),
            Object(NonMatching, "host_system/RKSystem.cpp"),
        ],
    },
    {
        "lib": "TRK",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(Matching, "runtime/__mem.c"),
            Object(Matching, "runtime/__ppc_eabi_init.c"),
            Object(Matching, "runtime/__start.c"),
            Object(NonMatching, "runtime/eabi.c"),
        ],
    },
    {
        "lib": "arc",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(Matching, "rvl/arc/rvlArchive.c"),
        ],
    },
    {
        "lib": "ax",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(NonMatching, "rvl/ax/rvlAx.c"),
            Object(NonMatching, "rvl/ax/rvlAxAlloc.c"),
            Object(NonMatching, "rvl/ax/rvlAxAux.c"),
            Object(NonMatching, "rvl/ax/rvlAxCl.c"),
            Object(Matching, "rvl/ax/rvlAxComp.c"),
            Object(Matching, "rvl/ax/rvlAxDspCode.c"),
            Object(NonMatching, "rvl/ax/rvlAxOut.c"),
            Object(NonMatching, "rvl/ax/rvlAxSpb.c"),
            Object(NonMatching, "rvl/ax/rvlAxVpb.c"),
            Object(NonMatching, "rvl/ax/rvlAxProf.c"),
        ],
    },
    {
        "lib": "ax_fx",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(NonMatching, "rvl/axfx/rvlAxFxReverbHi.c"),
            Object(NonMatching, "rvl/axfx/rvlAxFxReverbHiExp.c"),
            Object(NonMatching, "rvl/axfx/rvlAxFxReverbHiExpDpl2.c"),
            Object(NonMatching, "rvl/axfx/rvlAxFxReverbStdExp.c"),
            Object(NonMatching, "rvl/axfx/rvlAxFx.c"),
        ],
    },
    {
        "lib": "base",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(Matching, "rvl/base/ppcArch.c"),
        ],
    },
    {
        "lib": "ipc",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(Matching, "rvl/ipc/ipcMain.c"),
        ],
    },
    {
        "lib": "mem",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(NonMatching, "rvl/mem/rvlMemHeap.cpp"),
            Object(Matching, "rvl/mem/rvlMemExpHeap.c"),
            Object(Matching, "rvl/mem/rvlMemFrmHeap.cpp"),
            Object(Matching, "rvl/mem/rvlMemUnitHeap.cpp"),
            Object(Matching, "rvl/mem/rvlMemAllocator.cpp"),
            Object(Matching, "rvl/mem/rvlMemList.cpp"),
        ],
    },
    {
        "lib": "mtx",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(Matching, "rvl/mtx/rvlMtx.c"),
            Object(Matching, "rvl/mtx/rvlMtx2.c"),
            Object(Matching, "rvl/mtx/rvlVec.c"),
            Object(Matching, "rvl/mtx/rvlQuat.c"),
        ],
    },
    {
        "lib": "os",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(Matching, "rvl/os/osAlarm.c"),
            Object(NonMatching, "rvl/os/osCache.c"),
            Object(NonMatching, "rvl/os/osContext.c"),
            Object(NonMatching, "rvl/os/osInterrupt.c"),
        ],
    },
    {
        "lib": "pad",# inline noaudo
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
        Object(Matching, "rvl/pad/rvlPadClamp.c"),
        Object(NonMatching, "rvl/pad/rvlPad.c"),
        ],
    },
    {
        "lib": "si",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
        Object(NonMatching, "rvl/si/siBios.c"),
        ],
    },
    {
        "lib": "tpl",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
        Object(Matching, "rvl/tpl/tpl.c"),
        ],
    },
    {
        "lib": "so",
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rvl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
        Object(Matching, "rvl/so/soCommon.c"),
        Object(NonMatching, "rvl/so/soBasic.c"),
        ],
    },
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "src_dir": "lib",
        "objects": [
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
            Object(NonMatching, "Runtime.PPCEABI.H/ExceptionPPC.cpp"),
        ],
    },
    {
        "lib": "MSL_C",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_msl,
        "progress_category": "sdk",
        "src_dir": "lib",
        "objects": [
            Object(NonMatching, "MSL/src/ansi_files.c"),
            Object(NonMatching, "MSL/src/float.c"),
            Object(NonMatching, "MSL/src/mem.c"),
            Object(NonMatching, "MSL/src/mem_cpy.c"),
            Object(NonMatching, "MSL/src/qsort.c"),
            Object(Matching, "MSL/src/rand.c"),
            Object(Matching, "MSL/src/wchar.c"),
            Object(NonMatching, "MSL/src/va_arg.c"),
        ],
    },
    {
        "lib": "EGG",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_egg,
        "progress_category": "egg",
        "src_dir": "lib/egg",
        "objects": [
            Object(Matching, "core/eggXfb.cpp"),
        ],
    },
    {
        "lib": "StaticR",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_staticr,
        "progress_category": "game",
        "src_dir": "src",
        "objects": [
            Object(NonMatching, "system/CourseCheckpoints.cpp"),
            Object(NonMatching, "system/CourseMap.cpp"),
            Object(Matching, "system/DvdArchive.cpp"),
            Object(NonMatching, "system/GhostFile.cpp"),
            Object(NonMatching, "system/KPadController.cpp"),
            Object(Matching, "system/LocalizedArchive.cpp"),
            Object(Matching, "system/MultiDvdArchive.cpp"),
            Object(NonMatching, "system/NandUtil.cpp"),
            Object(Matching, "system/Rating.cpp"),
            Object(NonMatching, "system/RaceConfig.cpp"),
            Object(NonMatching, "system/RaceManager.cpp"),
            Object(Matching, "system/ResourceManager.cpp"),
            Object(Matching, "system/ResourceManagerUnk80542868.cpp"),

            Object(Matching, "util/Random.cpp"),
            Object(Matching, "util/ModuleSymbols.cpp"),

            Object(NonMatching, "kart/KartCollide.cpp"),
            Object(NonMatching, "kart/KartMove.cpp"),
            Object(NonMatching, "kart/KartObjectProxy.cpp"),
            Object(NonMatching, "kart/KartSettings.cpp"),
            Object(NonMatching, "kart/KartState.cpp"),
            Object(NonMatching, "kart/KartSus.cpp"),
            Object(NonMatching, "kart/KartWheelPhysics.cpp"),
            Object(NonMatching, "kart/KartPhysics.cpp"),
            Object(Matching, "kart/KartPhysicsInstance.cpp"),
            Object(NonMatching, "kart/KartDynamics.cpp"),
            Object(NonMatching, "kart/KartHitbox.cpp"),

            Object(Matching, "ui/ControlGroup.cpp"),
            Object(Matching, "ui/MessageGroup.cpp"),
            Object(NonMatching, "ui/SectionAutogens.cpp"),

            Object(Equivalent, "enemy/AI.cpp"),
            Object(Equivalent, "enemy/AITrickHandler.cpp"),

            Object(Matching, "geo/BoxColManager.cpp"),
            Object(Matching, "geo/BoxColUnit.cpp"),
        ],
    },
    {
        "lib": "KCOL",
        "mw_version": "Wii/0x4201_127",
        "cflags": cflags_staticr_gekko,
        "progress_category": "game",
        "src_dir": "src",
        "objects": [
            Object(NonMatching, "field/CourseModel.cpp"),
            Object(Matching, "field/CollisionEntries.cpp"),
            Object(NonMatching, "field/RKGndCol.cpp"),
            Object(Matching, "field/CourseColManager.cpp"),
            Object(Matching, "field/ObjColManager.cpp"),
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
    ProgressCategory("egg", "EGG"),
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
