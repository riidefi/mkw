import argparse
from pathlib import Path

from mkwutil.dol import DolBinary

def __read_dol(dol_path: Path) -> DolBinary:
    with open(dol_path, "rb") as file:
        dol = DolBinary(file)
        return dol
    raise RuntimeError("Cannot find DOL")

def main():
    parser = argparse.ArgumentParser()
    args = parser.parse_args()
    
    dol = __read_dol(Path() / "artifacts" / "orig" / "pal" / "main.dol")
    print(dol)

if __name__ == "__main__":
    main()
