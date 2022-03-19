# Project Structure

## Build parts

### `./artifacts`: Build final outputs

Contains the reference artifacts from the original game, and the generated final output.

- `./artifacts/orig/pal/main.dol`: Reference main executable.
- `./artifacts/orig/pal/StaticR.rel`: Reference library.
- `./artifacts/orig/pal/rel/*.bin`: Segments of reference library.
- `./artifacts/target/pal/main.dol`: Ouptut main executable.
- `./artifacts/target/pal/StaticR.rel`: Output library.

### `./build.py`: Main build script

Uses `mkwutil` to rebuild MKW from decompiled sources and verifies the result.

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

### `./out`: Object files

Compiled / assembled object files.

- `./out/*.o`: C/C++ reconstructed sources.
- `./out/dol/*.o`: DOL binary blobs.
- `./out/rel/*.o`: REL binary blobs.

### `./tools`: Compiler tooling

Default path of various compiler tooling.

### `./mkwutil`: Python code

The `mkwutil` Python package contains tooling for building and verifying artifacts.

The Python files here implement parts of the build process.
You can run them individually using `python -m mkwutil.<name>`.
Please refer to their `--help` section or source code for usage instructions.

#### `./mkwutil/lib`: Shared library code

Various Python utilities.
- `./slices.py` maintains a memory map of code / data areas.
  Its primary purpose is to keep track which memory ranges are decompiled.
  Data is persisted using the `slices.csv` format.
- `./symbols.py`: Symbol list
- `./dol.py`: main.dol binary file format
- `./rel.py`: *.rel binary file format
- `./binary_blob.py`: Binary blob (inline ASM) masking
  to improve `percent_decompiled` accuracy.
- `./verify_binary.py`: Binary verification subroutines

#### `./mkwutil/progress`: Decompile progress

Tools to calculate and visualize the progress of the project.

#### `./mkwutil/tools`: Miscellaneous tools

Dumping ground for tools outside of the build process.

#### `./codes`: Miscellaneous patches to the game code

Dumping ground for source code patches/diffs.
