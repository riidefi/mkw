from elftools.elf.elffile import ELFFile

def verify_object_file(dst, src, obj_slice):
    match = True
    with open(dst, 'rb') as f:
        elf_file = ELFFile(f)
        for section in elf_file.iter_sections():
            section_name = section.name.removeprefix(".")
            part = obj_slice.segments.get(section_name)
            if not part:
                continue
            want_size = part.size()
            have_size = section.data_size
            if want_size != have_size:
                match = False
                print("[!] %s %s want=0x%x got=0x%x" % (src, section_name, want_size, have_size))
    return match
