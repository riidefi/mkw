from elftools.elf.elffile import ELFFile

from termcolor import colored


def verify_object_file(dst: str, src: str, obj_slices: list):
    """Verifies the section sizes of an object."""
    match = True
    with open(dst, "rb") as f:
        elf_file = ELFFile(f)
        for section in elf_file.iter_sections():
            section_name = section.name.removeprefix(".")
            # Find slice that matches section name.
            _slice = next(
                (_slice for _slice in obj_slices if _slice.section == section_name),
                None,
            )
            if not _slice:
                continue
            want_size = len(_slice)
            have_size = section.data_size
            if want_size != have_size:
                match = False
                warn = "[!] Size mismatch: %s %s want=0x%x got=0x%x" % (
                    src,
                    section_name,
                    want_size,
                    have_size,
                )
                print(colored(warn, "red"))
    return match
