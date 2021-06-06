# mkw
A matching decompilation of Mario Kart Wii. All code in this repository will compile 1:1 to the original game.
It produces the following files:
mkw_pal.dol: `sha1: ac7d72448630ade7655fc8bc5fd7a6543cb53a49`
StaticR.rel: `sha1: 887bcc076781f5b005cc317a6e3cc8fd5f911300`

## Accuracy
The primary priority is to maintain absolute code accuracy. To automate verification of this, a special linker setup is used to emplace compiled code back into the original executable, forming a new executable. This new executable is hashed to ensure it matches the original. Once all code is decompiled, this setup will build a new executable from scratch, sampling none of the original.

## Code Quality
I have written code to be as readable and maintainable as possible. While the original access modifiers and trivial encapsulations have been lost to the optimizer, I have reconstructed both to minimize unsafe data exposure. Common sense debug assertions have been added, enforcing unchecked preconditions.

### Modern C++isms
While the original game was written and compiled as C++03, several modern C++ features have been used to aid readability and increase code quality. All are define'd out when compiling for C++03. For example: strongly typed null pointers with `nullptr` and the `override` specifier.

## Documentation
Every fully understood piece of reverse engineered data has been documented in a consistent doxygen style.

## Dependencies
- DevKitPro (for the ppc-eabi assembler)
- Python3:
  - `pip insall pyelftools`
  - `pip install capstone` (for `gen_asm.py` only)
- Place a copy of Mario Kart Wii's PAL .dol file in `artifacts/pal` as `main.dol` and REL as `StaticR.rel`. (`gen_asm.py` only)
- Run `python3 system/rel_repack.py` to dump binary blobs for further tooling.

## Building
- Place the specified CodeWarrior versions in the respective subfolders in the `tools` directory. Then run `python3 build.py` 

## Contributing
- Do not manually adjust assembly files; rather add a new entry to [system/slices.csv](https://github.com/riidefi/mkw/blob/master/system/slices.csv) for main.dol and [system/rel_slices.csv](https://github.com/riidefi/mkw/blob/master/system/rel_slices.csv) for StaticR.rel.
- Entries must be sorted in the spreadsheet (current limitation).
- Run `gen_asm.py` from the `system` directory to regenerate assembly segments every time either file is editeds.

## .rel support
Most of Mario Kart Wii's game code is located inside a relocatable module (StaticR.rel for release builds). The decompilation builds this. 