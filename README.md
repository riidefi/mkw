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
- CodeWarrior compilers (in `tools`)
- Python3:
  - `pip insall pyelftools`
  - `pip install capstone`
- Bash
- GNU Make
- Place a copy of Mario Kart Wii's PAL binaries: 
  - `artifacts/orig/pal/main.dol`
  - `artifacts/orig/pal/StaticR.rel`

## Building
Run `make build` to build the game and verify build authenticity. Final results:
  - `artifacts/target/pal/main.dol`
  - `artifacts/target/pal/StaticR.rel`

Other useful commands:
- `make clean` removes binaries and object files.
- `make prune` removes binaries, object files and auto-generated source code.

## Contributing
- Do not manually adjust assembly (`asm`) files. They are auto-generated.
- To add a new decompiled section, modify the slice tables:
  - [pack/dol_slices.csv](./pack/dol_slices.csv)
  - [pack/rel_slices.csv](./pack/rel_slices.csv)
- Entries must be sorted in the spreadsheet (current limitation).
- Assembly files will be regenerated next time you run `make build`.

## .rel support
Most of Mario Kart Wii's game code is located inside a relocatable module (StaticR.rel for release builds). The decompilation builds this. 

## Troubleshooting

Common build errors you might encounter.

**No rule to make target 'asm/dol'**

Problem: You are missing the original game's `main.dol` and `StaticR.rel`.
Therefore the build system can't generate the assembly binary blobs.
Place them into `./artifacts/orig/pal` to fix this issue.
