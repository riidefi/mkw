
# Performs preprocessing for disassembly
from pathlib import Path

from ppcdis import Analyser
from ppcdis.binaryyml import load_binary_yml
from mkwutil.project import read_symbol_map


def analyse_bins():
    thispath = Path('./mkwutil/ppcdis_adapter')
    rel_labelspath = thispath / 'rel_labels.pickle'
    rel_relocspath = thispath / 'rel_relocs.pickle'
    rel_overridespath = thispath / 'rel_overrides.yaml'
    dol_labelspath = thispath / 'dol_labels.pickle'
    dol_relocspath = thispath / 'dol_relocs.pickle'
    dol_overridespath = thispath / 'dol_overrides.yaml'
    dolpath = thispath / 'dol.yaml'
    relpath = thispath / 'rel.yaml'
    dolbin = load_binary_yml(dolpath)
    relbin = load_binary_yml(relpath)

    pack_dir = Path("./pack")
    symbols = read_symbol_map(pack_dir / "symbols.txt")
    sympath = Path(thispath / 'symbol_map.yml')
    symbols.write_to_yaml(sympath)

    extra_labels = None
    thorough = False
    quiet = False

    if not (rel_labelspath.exists() and rel_relocspath.exists()):
        relanl = Analyser(relbin, rel_overridespath, extra_labels, thorough, quiet)
        relanl.output(rel_labelspath, rel_relocspath)

    if not (dol_labelspath.exists() and dol_relocspath.exists()):
        dolanl = Analyser(dolbin, dol_overridespath, extra_labels, thorough, quiet)
        dolanl.output(dol_labelspath, dol_relocspath)


if __name__ == '__main__':
    analyse_bins()
