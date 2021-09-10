"Script for checking that headers can be compiled with clang."


from pathlib import Path
import subprocess
import sys


COMMONFLAGS = [
    "-c",
    "-fshort-wchar",
    "-I", "source",
    "-I", "source/platform",
    "-nostdinc",
    "-target", "ppc-none-eabi",
    "-Wall",
    "-Wno-unused-private-field",
    "-Wextra",
    "-Wpedantic",
    "-Wno-c99-extensions",
    "-Werror",
]

CFLAGS = COMMONFLAGS + [
    "-x", "c",
    "-std=c18",
]

CXXFLAGS = COMMONFLAGS + [
    "-fno-exceptions",
    "-x", "c++",
]

if sys.platform == "win32" or sys.platform == "msys":
    DEV_NULL = "NUL"
else:
    DEV_NULL = "/dev/null"


def check_headers(extension, flags):
    source = ""
    for path in Path("source").rglob("*." + extension):
        source += "#include \""
        source += str(path).removeprefix("source/")
        source += "\"\n"

    process = subprocess.run(
        ["clang"] + flags + ["-", "-o", DEV_NULL],
        text=True,
        input=source,
    )

    return process.returncode

c_ret = check_headers("h", CFLAGS)
cpp_ret = check_headers("hpp", CXXFLAGS)

if c_ret != 0 or cpp_ret != 0:
    sys.exit(1)
