import argparse
import sys

import r2pipe


def disasm_iter(data: bytes, address: int):
    if len(data) < 4:
        return

    r2 = r2pipe.open(f"malloc://{len(data)}", flags=["-m", hex(address)])
    r2.cmd("e asm.arch=ppc")
    r2.cmd("e asm.bits=32")
    r2.cmd("e asm.cpu=ps")
    r2.cmd("e cfg.bigendian=true")
    view = memoryview(data)

    i = address
    while len(view) >= 4:
        word = view[:4].hex()
        view = view[4:]
        r2.cmd(f"wv 0x{word} @{hex(i)}")
        yield r2.cmd(f"pi 1 @{hex(i)}").strip()
        i += 4


def main():
    parser = argparse.ArgumentParser(
        description="Disassemble bytes from stdin using radare2"
    )
    parser.add_argument(
        "-B", "--base", type=str, required=True, help="Base address (hex)"
    )
    args = parser.parse_args()

    data = sys.stdin.buffer.read()
    for ins in disasm_iter(data, int(args.base, 16)):
        print(ins)


if __name__ == "__main__":
    main()
