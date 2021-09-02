"Script for checking that headers can be compiled with clang."


from pathlib import Path
import subprocess


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

def check_headers(extension, flags):
    source = ""
    for path in Path("source").rglob("*." + extension):
        source += "#include <"
        source += str(path).removeprefix("source/")
        source += ">\n"

    subprocess.run(
        ["clang"] + flags + ["-", "-o", "/dev/null"],
        text=True,
        input=source,
    )

check_headers("h", CFLAGS)
check_headers("hpp", CXXFLAGS)
