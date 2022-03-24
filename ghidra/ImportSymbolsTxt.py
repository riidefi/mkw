##
# Imports symbols.txt from mkw
# @author Richard Patel <me@terorie.dev>
# @category Data
#

from ghidra.program.model.symbol.SourceType import *
import string

functionManager = currentProgram.getFunctionManager()

for line in file(f.absolutePath):
    pieces = line.split()

    addr = toAddr(long(pieces[0], 16))
    name = pieces[1]

    # Skip if not in init or text.
    if not (
        (addr >= 0x80004000 and addr <= 0x80006460)
        or (addr >= 0x800072C0 and addr <= 0x80244DE0)
    ):
        createLabel(addr, name, False)
        print("Created label {} at {}".format(name, addr))
    else:
        func = functionManager.getFunctionAt(addr)
        if func is None:
            func = createFunction(addr, name)
            print("Created function {} at {}".format(name, addr))
        else:
            old_name = func.getName()
            if old_name[4:] in ("LAB_", "UNK_"):
                func.setName(name, USER_DEFINED)
                print("Renamed function {} at {}".format(name, addr))
