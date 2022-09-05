
# Performs preprocessing for disassembly
from pathlib import Path

from ppcdis import Analyser, dump_rel_externs
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
    externspath = thispath / 'externs.pickle'
    dolbin = load_binary_yml(dolpath)
    relbin = load_binary_yml(relpath)

    extra_labels = [externspath]
    thorough = False
    quiet = False

    if not externspath.exists():
        dump_rel_externs(externspath, [relbin])

    if not (rel_labelspath.exists() and rel_relocspath.exists()):
        relanl = Analyser(relbin, rel_overridespath, extra_labels, thorough, quiet)
        relanl.output(rel_labelspath, rel_relocspath)

    if not (dol_labelspath.exists() and dol_relocspath.exists()):
        dolanl = Analyser(dolbin, dol_overridespath, extra_labels, thorough, quiet)
        dolanl.output(dol_labelspath, dol_relocspath)


if __name__ == '__main__':
    analyse_bins()
