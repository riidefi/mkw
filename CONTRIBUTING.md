
## High-level workflow
1. Identify and analyze your area of interest in the binary that you want to reverse using your favorite tool. A good idea is to use stebler's public ghidra and annotate the functionality of interest as much as possible before attempting to create matching code.
2. If no C++ slices exist already for that area, create slices that cover the region of code that you are going to work with.
3. For each function you are interested, create a C++ function that produces equivalent assembly code using tools like decomp.me and `diff.py`.
4. In the C++ source files of those slices, replace the inline assembly functions with your C++ implementations.
5. Rename any symbol needed to tie up any new symbol references and definitions you created.
6. Build and verify that your code passes the binary matching tests.
7. Submit a contribution to this repository

## How to guides
### Defining new source files and slices
1. Add a new row to `pack/dol_slices.yml` or `pack/rel_slices.yml` defining the address ranges your TU is going to provide in each section.
2. Add a new entry for your source file in `sources.py` that specifies the desired compiler version and flags your TU is going to be compiled with.

### Function matching tools
- decomp.me is a very cool website in which you can paste target assembly functions and write C++ whose compiled assembly is compared against the target in real time. Most importantly, you can share a link to your scratch with others and collaboratively match functions. This repository offers a script that can generate a scratch for any function with a single command `mkwutil/tools/decompme.py -m <tu> <sym>` where `<tu>` is a regex that matches a TU and `<sym>` is a symbol name or address.
- `diff.py` can offer the same diffing capability as decomp.me offline.
- If you want to inspect compiled code more closely (usually to inspect code or data that spans multiple regions), you can load them in a binary analysis tool (most commonly ghidra). Most often you are interested in a single TU and can load just its corresponding file in `out/`, which gets analysed quickly. Rarely, you are interested to see the entire linked binary, which is `artifacts/target/pal/{main.*, StaticR.*}` (prefer to use the .elf file which will have better support in your analyzer).

### Symbol renaming
There are two scripts for renaming symbols:

- `mkwutil/tools/set_symbol.py` lets you change/set the name of a symbol at a specified address, and refactor all the code base to reflect that change.
- `mkwutil/tools/rel_auto_symbol_update.py` (StaticR.rel only) If everything matches besides relocations, this script can update all symbol names according to the symbol names in the compiled binary. While this script can save a lot of time, make sure to **only** use it with matching assembly otherwise it may change a lot of symbols incorrectly (because it uses the compiled binary's symbol addresses as a reference).

You can use `--help` for how to use those scripts.

## How decomp works
The validity of this decompilation is verified by building two binaries that match byte by byte, `main.dol` and `StaticR.rel`. However, since this decompilation is a work in progress, the code provided in the `source` directory only compiles to part of the target binary and the rest of the binary has to be provided using information from the target binary itself. The way this is achieved, is by specifying precisely which adress range is provided by each one of the implemented translation units (C++ source files). The rest of the binary is provided by disassembling it into assembly files, generated automatically by the build system. At the end, everything is compiled and linked together into the final binaries.

Every step of the process is explained in further detail in the following sections
### Slice definition and assembly generation
The aforementioned slices are defined in `pack/dol_slices.yml` and `pack/rel_slices.yml`. In these files, every provided TU must detail precisely the range of addresses it provides in each section. The rest of the binary is provided by assembly code which is generated from analyzing the target binaries (currently performed by Seeky's ppcdis). This analysis only runs the first time this project builds. You can force a rerun with `--force_analyse` but it should never be mandatory. Whenever the slice definitions change, the assembly files must be regenerated with `--regen_asm`.

### Slice generation and code matching
Each time you define a new TU in the slice files, a new C++ source file is expected to be be found at the specified path during build. The build system is kind enough to provide an `.hpp`/`.cpp` file pair for you which should be matching or very close to matching after running `configure.py` if the expected source file is not found. How does it manage to create a C++ source file that is matching automatically? That is where *partial* decompilation comes in. Using inline assembly syntax, we can implement all the desired functions to fill the TU (.text section of TU). For data, we provide it using typical variable definitions. As we reverse engineer functions, we can simply offer our C++ definitions in leu of inline assembly. As long as the order of definitions is respected, things will continue to match (usually).

### Symbols
We talked about C++ and assembly code, but how does C++ reference assembly symbols and vice versa? To achieve this, we need to control the names of the generated assembly's symbol references/definitions, so that they match the corresponding C++ references/definitions. To this end, we maintain a symbol map file in `pack/symbols.yml` that the disassembler can use to provide a name for all the generated symbol definitions and references. In practise, it is almost never a good idea to manually modify the symbol map because you'll also need to replace every occurence of the symbol name in the entire project's assembly (both inline and in asm files). A better idea is to use the scripts described in *Symbol renaming* that do the replacing for you.

### Compilation & Linking
After everything is setup up, all source files are compiled and all assembly files are assembled, producing object files. The object files are linked into the final ELF binary, maintaining the order that they are defined in the slice definitions.

### ELF to nintendo binary formation conversion (REL/DOL)
In the case of Wii games, there is one more simple step that needs to be performed, which is to convert ELFs into the desired Wii binary format. That is the final artifact that gets compared to the original in the verification step.