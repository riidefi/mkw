# mkw
A matching decompilation of Mario Kart Wii. All code in this repository will compile 1:1 to the original game.
It produces the following .dol:
mkw_pal.dol: `sha1: ac7d72448630ade7655fc8bc5fd7a6543cb53a49`

## Accuracy
The primary priority is to maintain absolute code accuracy. To automate verification of this, a special linker setup is used to emplace compiled code back into the original executable, forming a new executable. This new executable is hashed to ensure it matches the original. Once all code is decompiled, this setup will build a new executable from scratch, sampling none of the original.

## Code Quality
I have written code to be as readable and maintainable as possible. While the original access modifiers and trivial encapsulations have been lost to the optimizer, I have reconstructed both to minimize unsafe data exposure. Common sense debug assertions have been added, enforcing unchecked preconditions.

### Modern C++isms
While the original game was written and compiled as C++03, several modern C++ features have been used to aid readability and increase code quality. All are define'd out when compiling for C++03. For example: strongly typed null pointers with `nullptr` and the `override` specifier.

## Documentation
Every fully understood piece of reverse engineered data has been documented in a consistent doxygen style.

## Building
Create a root-level folder named `tools`. Place elf2dol, mwldeppc and mwcceppc in it. Then run `python3 build.py` 