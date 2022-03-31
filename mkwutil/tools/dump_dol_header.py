import argparse
from pathlib import Path
import struct

from mkwutil.lib.dol import DolBinary


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("dol", type=Path)
    args = parser.parse_args()

    with open(args.dol, "rb") as file:
        dol = DolBinary(file, read_body=False)

    print("entrypoint=%08x" % (dol.entry_point))
    for i, segment in enumerate(dol.segments):
        if segment.size() == 0:
            print("section=%#02x" % (i))
            continue
        print(
            "section=%#02x offset=%#08x start=%#08x stop=%#08x length=%08x"
            % (
                i,
                segment.offset,
                segment.start,
                segment.stop,
                segment.size(),
            )
        )
    print(
        "section=bss start=%08x stop=%08x length=%08x"
        % (dol.bss.start, dol.bss.stop, dol.bss.size())
    )


if __name__ == "__main__":
    main()
