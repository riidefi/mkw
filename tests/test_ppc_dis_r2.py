from mkwutil.lib.ppc_dis_r2 import disasm_iter


def test_disasm_iter():
    insns = list(disasm_iter(bytes.fromhex("10c104a0 e0630014"), 0x80199FD4))
    assert insns == ["ps_merge10 fr6 fr1 fr0", "psq_l fr3 0x17(r1) 0x0"]
