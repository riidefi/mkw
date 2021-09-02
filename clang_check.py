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

    subprocess.run(
        ["clang"] + flags + ["-", "-o", DEV_NULL],
        text=True,
        input=source,
    )

check_headers("h", CFLAGS)
check_headers("hpp", CXXFLAGS)
