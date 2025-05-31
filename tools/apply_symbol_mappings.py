"""
copies mapped symbols from objdiff.json to symbols.txt

objdiff allows one to map symbols from the programmer's decompiled binary to the original target binary.
this script will find those mapped symbols, and write the programmer's updated names to `symbols.txt`.

example: say you have changed the signature/name of a function from foo(short) -> bar(long).
now, the symbol from your new object is `bar__Fl`, but symbols.txt still says `foo__Fs`.
objdiff allows you to map `bar__Fl` in your new object to `foo__Fs` in the target object.
this script will automatically replace `foo__Fs` with `bar__Fl` in `symbols.txt`.
"""

import json

with open("./objdiff.json") as f:
    objdiff_config = json.load(f)

units = objdiff_config["units"]

symbol_mappings = {}
for unit in units:
    symbol_mapping = unit.get("symbol_mappings")
    if symbol_mapping is None:
        continue
    symbol_mappings.update(symbol_mapping)
    del unit['symbol_mappings']


def process_symbols_txt(symbols_txt_path):
    with open(symbols_txt_path) as f:
        symbols = f.readlines()



    for i, line in enumerate(symbols):
        tokens = line.split()
        old_symbol = tokens[0]

        new_symbol = symbol_mappings.get(old_symbol)

        if new_symbol is None:
            continue

        tokens[0] = new_symbol
        symbols[i] = " ".join(tokens) + "\n"
    
    with open(symbols_txt_path, "w") as f:
        f.writelines(symbols)
        
process_symbols_txt("./config/RMCP01/module/symbols.txt")
process_symbols_txt("./config/RMCP01/symbols.txt")



with open("./objdiff.json", "w") as f:
    json.dump(objdiff_config, f)
