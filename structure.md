# Project Structure

## Build parts

### `./artifacts`: Build final outputs

Contains the reference artifacts from the original game, and the generated final output.

- `./artifacts/orig/pal/main.dol`: Reference main executable.
- `./artifacts/orig/pal/StaticR.rel`: Reference library.
- `./artifacts/orig/pal/rel/*.bin`: Segments of reference library.
- `./artifacts/target/pal/main.dol`: Ouptut main executable.
- `./artifacts/target/pal/StaticR.rel`: Output library.

### `./pack`: Link instructions

Specifies which sections are decompiled and holds information needed to reconstruct final binaries.

- `./pack/dol_segments.csv`: Table of main.dol segments
- `./pack/dol_slices.csv`: Table of main.dol decompiled sections
- `./pack/dol_objects.txt`: List of main.dol reconstructed objects (in order)
- `./pack/rel_segments.csv`: Table of StaticR.rel segments
- `./pack/rel_slices.csv`: Table of StaticR.rel decompiled sections
- `./pack/dol_objects.txt`: List of StaticR.rel reconstructed objects (in order)

### `./asm`: Binary blobs

Contains diassembled binary blobs.

- `./asm/dol/*.bin`: Main binary blobs.
- `./asm/dol/*.s`: Main assembly script.
- `./asm/dol/*.o`: Main binary blob object for linking.
- `./asm/rel/*.bin`: Library binary blobs.
- `./asm/rel/*.s`: Library assembly script.
- `./asm/rel/*.o`: Library binary blob object for linking.

### `./source`: Source code

Reconstructed/decompiled source code.

- `./source/**/*.{h,c}`: C headers / code.
- `./source/**/*.{hpp,cpp}`: C++ headers / code.
- `./source/**/*.o`: Compiled C/C++ code.

### `./tools`: Compiler tooling

Default path of various compiler tooling.

### `./util`: Python utilities

Various Python utilities.

- `./*.py`: Python programs
- `./mkw`: Package with useful bits
