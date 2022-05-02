"""
Disassembles Broadway code.

Based on https://gist.github.com/camthesaxman/a36f610dbf4cc53a874322ef146c4123

Changes:
- Blacklisted more instructionss
- Adjusted output to take up fewer bytes
- mwasm support
"""

# Wildcard imports are okay.
# pylint: disable=W0401
# pylint: disable=W0614

import struct

from capstone import *
from capstone.ppc import *

from mkwutil.lib.symbols import SymbolsList


def sign_extend_16(value):
    if value > 0 and (value & 0x8000):
        value -= 0x10000
    return value


def sign_extend_12(value):
    if value > 0 and (value & 0x800):
        value -= 0x1000
    return value


cs = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
cs.detail = True
cs.imm_unsigned = False

blacklistedInsns = {
    # Unsupported instructions
    PPC_INS_VMSUMSHM,
    PPC_INS_VMHADDSHS,
    PPC_INS_XXSLDWI,
    PPC_INS_VSEL,
    PPC_INS_XVSUBSP,
    PPC_INS_XXSEL,
    PPC_INS_XVMULSP,
    PPC_INS_XVDIVSP,
    PPC_INS_VADDUHM,
    PPC_INS_XXPERMDI,
    PPC_INS_XVMADDASP,
    PPC_INS_XVMADDMSP,
    PPC_INS_XVCMPGTSP,
    PPC_INS_XXMRGHD,
    PPC_INS_XSMSUBMDP,
    PPC_INS_XSTDIVDP,
    PPC_INS_XVADDSP,
    PPC_INS_XVCMPEQSP,
    PPC_INS_XVMSUBASP,
    PPC_INS_XVCMPGESP,
    PPC_INS_XSMSUBADP,
    PPC_INS_XSMADDADP,
    PPC_INS_XSCMPODP,
    PPC_INS_XVTDIVSP,
    PPC_INS_VMRGHB,
    PPC_INS_VADDUBM,
    PPC_INS_XSMADDMDP,
    PPC_INS_XSCMPUDP,
    PPC_INS_XVNMADDASP,
    PPC_INS_VADDUWM,
    PPC_INS_XVMSUBMSP,
    PPC_INS_XSNMSUBMDP,
    PPC_INS_XSNMSUBADP,
    PPC_INS_XVCMPEQDP,
    PPC_INS_VPKUHUM,
    PPC_INS_XVCMPGTDP,
    PPC_INS_XVMADDADP,
    PPC_INS_XVMSUBMDP,
    PPC_INS_VMADDFP,
    PPC_INS_XXSPLTW,
    PPC_INS_XVMSUBADP,
    PPC_INS_XVCMPGEDP,
    PPC_INS_XVNMSUBMDP,
    PPC_INS_XVMADDMDP,
    PPC_INS_XXMRGHW,
    PPC_INS_XVTDIVDP,
    PPC_INS_XXMRGLW,
    PPC_INS_XVADDDP,
    PPC_INS_XXLAND,
    PPC_INS_XVNMSUBASP,
    PPC_INS_XVNMSUBMSP,
    PPC_INS_XVNMADDADP,
    PPC_INS_XVNMADDMSP,
    PPC_INS_XSSUBDP,
    # Instructions that Capstone gets wrong
    PPC_INS_MFESR,
    PPC_INS_MFDEAR,
    PPC_INS_MTESR,
    PPC_INS_MTDEAR,
    PPC_INS_MFICCR,
    PPC_INS_MFASR,
}


loadStoreInsns = {
    PPC_INS_LWZ,
    PPC_INS_LMW,
    PPC_INS_LHA,
    PPC_INS_LHAU,
    PPC_INS_LHZ,
    PPC_INS_LHZU,
    PPC_INS_LBZ,
    PPC_INS_LBZU,
    PPC_INS_LFD,
    PPC_INS_LFDU,
    PPC_INS_LFS,
    PPC_INS_LFSU,
    PPC_INS_STW,
    PPC_INS_STWU,
    PPC_INS_STMW,
    PPC_INS_STH,
    PPC_INS_STHU,
    PPC_INS_STB,
    PPC_INS_STBU,
    PPC_INS_STFS,
    PPC_INS_STFSU,
    PPC_INS_STFD,
    PPC_INS_STDU,
}


def is_load_store(insn, reg=None):
    """Returns true if the instruction is a load or store with the given register as a base."""
    return insn.id in loadStoreInsns and (
        reg is None or insn.operands[1].mem.base == reg
    )


R2_VALUE = 0x8038EFA0
R13_VALUE = 0x8038CC00


def insn_to_text_capstone(insn, raw, symbols: SymbolsList):
    if symbols and is_load_store(insn, PPC_REG_R2):
        ref = R2_VALUE + sign_extend_16(insn.operands[1].mem.disp)
        if ref < 0x80389180:
            label = symbols.get_or_default(ref).name
            return f"{insn.mnemonic} {insn.reg_name(insn.operands[0].reg)}, {label}@sda21(2)"
    # Sign-extend immediate values because Capstone is an idiot and doesn't do that automatically
    if insn.id in {PPC_INS_ADDI, PPC_INS_ADDIC, PPC_INS_SUBFIC, PPC_INS_MULLI} and (
        insn.operands[2].imm & 0x8000
    ):
        return "%s %s, %s, %i" % (
            insn.mnemonic,
            insn.reg_name(insn.operands[0].reg),
            insn.reg_name(insn.operands[1].value.reg),
            insn.operands[2].imm - 0x10000,
        )
    elif (insn.id == PPC_INS_LI or insn.id == PPC_INS_CMPWI) and (
        insn.operands[1].imm & 0x8000
    ):
        return "%s %s, %i" % (
            insn.mnemonic,
            insn.reg_name(insn.operands[0].reg),
            insn.operands[1].imm - 0x10000,
        )
    # cntlz -> cntlzw
    elif insn.id == PPC_INS_CNTLZW:
        return "cntlzw %s" % insn.op_str
    elif insn.id == PPC_INS_MTICCR:
        return "mtictc %s" % insn.op_str
    # Dunno why GNU assembler doesn't accept this
    elif insn.id == PPC_INS_LMW and insn.operands[0].reg == PPC_REG_R0:
        return ".4byte 0x%08X  /* illegal %s %s */" % (raw, insn.mnemonic, insn.op_str)
    return f"{insn.mnemonic} {insn.op_str}"


def disasm_ps(inst):
    """Disassembles paired-singles instruction."""
    RA = (inst >> 16) & 0x1F
    RB = (inst >> 11) & 0x1F
    FA = (inst >> 16) & 0x1F
    FB = (inst >> 11) & 0x1F
    FC = (inst >> 6) & 0x1F
    FD = (inst >> 21) & 0x1F
    FS = (inst >> 21) & 0x1F
    IX = (inst >> 7) & 0x7
    WX = (inst >> 10) & 0x1

    opcode = (inst >> 1) & 0x1F
    if opcode == 6:  # doesn't seem to be used
        mnemonic = "psq_lux" if inst & 0x40 else "psq_lx"
        return "%s f%i, r%i, r%i, %i, qr%i" % (mnemonic, FD, RA, RB, WX, IX)
    if opcode == 7:
        mnemonic = "psq_stux" if inst & 0x40 else "psq_stx"
        return "%s f%i, r%i, r%i, %i, qr%i" % (mnemonic, FS, RA, RB, WX, IX)
    if opcode == 18:
        return "ps_div f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 20:
        return "ps_sub f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 21:
        return "ps_add f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 23:
        return "ps_sel f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 24:
        return "ps_res f%i, f%i" % (FD, FB)
    if opcode == 25:
        return "ps_mul f%i, f%i, f%i" % (FD, FA, FC)
    if opcode == 26:
        return "ps_rsqrte f%i, f%i" % (FD, FB)
    if opcode == 28:
        return "ps_msub f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 29:
        return "ps_madd f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 30:
        return "ps_nmsub f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 31:
        return "ps_nmadd f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 10:
        return "ps_sum0 f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 11:
        return "ps_sum1 f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 12:
        return "ps_muls0 f%i, f%i, f%i" % (FD, FA, FC)
    if opcode == 13:
        return "ps_muls1 f%i, f%i, f%i" % (FD, FA, FC)
    if opcode == 14:
        return "ps_madds0 f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)
    if opcode == 15:
        return "ps_madds1 f%i, f%i, f%i, f%i" % (FD, FA, FC, FB)

    opcode = (inst >> 1) & 0x3FF
    if opcode == 40:
        return "ps_neg f%i, f%i" % (FD, FB)
    if opcode == 72:
        return "ps_mr f%i, f%i" % (FD, FB)
    if opcode == 136:
        return "ps_nabs f%i, f%i" % (FD, FB)
    if opcode == 264:
        return "ps_abs f%i, f%i" % (FD, FB)
    if opcode in {0, 32, 64, 96}:
        mnemonics = ["ps_cmpu0", "ps_cmpo0", "ps_cmpu1", "ps_cmpo1"]
        mnemonic = mnemonics[(inst >> 6) & 3]
        i = (inst & 0x03800000) >> 23
        return "%s cr%i, f%i, f%i" % (mnemonic, i, FA, FB)
    if opcode == 528:
        return "ps_merge00 f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 560:
        return "ps_merge01 f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 592:
        return "ps_merge10 f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 624:
        return "ps_merge11 f%i, f%i, f%i" % (FD, FA, FB)
    if opcode == 1014:
        if not inst & 0x03E00000:
            if (inst & 1) == 0:
                return "dcbz_l r%i, r%i" % (
                    (inst & 0x001F0000) >> 16,
                    (inst & 0x0000F800) >> 11,
                )
    return None


def disasm_ps_mem(inst, idx):
    """Disassembles special ps_mem instruction."""
    RA = (inst >> 16) & 0x1F
    RS = (inst >> 21) & 0x1F
    I = (inst >> 12) & 0x7
    W = (inst >> 15) & 0x1
    disp = sign_extend_12(inst & 0xFFF)
    if idx == 56:
        mnemonic = "psq_l"
    if idx == 57:
        mnemonic = "psq_lu"
    if idx == 60:
        mnemonic = "psq_st"
    if idx == 61:
        mnemonic = "psq_stu"
    return "%s f%i, %i(r%i), %i, qr%i" % (mnemonic, RS, disp, RA, W, I)


def disasm_fcmp(inst):
    """Disassembles special fcmp instruction."""
    crd = (inst & 0x03800000) >> 23
    a = (inst & 0x001F0000) >> 16
    b = (inst & 0x0000F800) >> 11
    return "fcmpo cr%i, f%i, f%i" % (crd, a, b)


def disasm_mspr(inst, mode):
    """Disassembles special mspr instruction."""
    if inst & 1:
        return None
    d = (inst & 0x03E00000) >> 21
    a = (inst & 0x001F0000) >> 16
    b = (inst & 0x0000F800) >> 11
    spr = (b << 5) + a
    if mode:
        return "mtspr 0x%X, r%i" % (spr, d)
    else:
        return "mfspr r%i, 0x%X" % (d, spr)


def disasm_mcrxr(inst):
    """Disassembles special mcrxr instruction."""
    if inst & 0x007FF801:
        return None
    crd = (inst & 0x03800000) >> 23
    return "mcrxr cr%i" % crd


def insn_to_text(insn, raw, symbols):
    """Disassembles instruction."""
    asm = None
    if insn is not None:
        asm = insn_to_text_capstone(insn, raw, symbols)
    else:  # Capstone couldn't disassemble it
        idx = (raw & 0xFC000000) >> 26
        idx2 = (raw & 0x000007FE) >> 1
        # mtspr
        if idx == 31 and idx2 == 467:
            asm = disasm_mspr(raw, 1)
        # mfspr
        elif idx == 31 and idx2 == 339:
            asm = disasm_mspr(raw, 0)
        # mcrxr
        elif idx == 31 and idx2 == 512:
            asm = disasm_mcrxr(raw)
        # fcmpo
        elif idx == 63 and idx2 == 32:
            asm = disasm_fcmp(raw)
        # Paired singles
        elif idx == 4:
            asm = disasm_ps(raw)
        elif idx in {56, 57, 60, 61}:
            asm = disasm_ps_mem(raw, idx)
    if asm is None:
        if raw == 0:
            asm = ".4byte 0"
        else:
            asm = ".4byte 0x%08X  /* unknown instruction */" % raw
    return asm


# entryPoint = base.entry_point
# # Add entry point
# labels.add(entryPoint)
# labelNames[entryPoint] = '__start'


class Instruction:
    """A Broadway CPU instruction and its location."""

    def __init__(
        self, address, insn, bytes, labels=(), symbols=None, abs_branch=False
    ):
        self.address = address
        self.insn = insn
        self.bytes = bytes
        self.labels = labels
        self.symbols = symbols
        self.abs_branch = abs_branch

    def prefix_text(self):
        # return '/* %08X */' % address
        return "/* %08X  %02X %02X %02X %02X */\t" % (
            self.address,
            self.bytes[0],
            self.bytes[1],
            self.bytes[2],
            self.bytes[3],
        )

    def disassemble(self):
        return self.prefix_text() + self.disassemble_inner()

    def disassemble_inner(self):
        """Returns inline disassembly of instruction."""
        # Nice address reference for branch instructions.
        branch_info = self.disassemble_branch()
        if branch_info is not None:
            branch_text, addr = branch_info
            return f"{branch_text} {self.reference_addr(addr)}"
        # Fall back to generic diassembly.
        raw = struct.unpack(">I", self.bytes)[0]
        asm = insn_to_text(self.insn, raw, self.symbols)
        return asm.strip()

    def disassemble_branch(self):
        """Helper to split a branch-to-immediate instruction into text and address."""
        if self.insn is None:
            return None
        if self.insn.id in {PPC_INS_B, PPC_INS_BL, PPC_INS_BDZ, PPC_INS_BDNZ}:
            return self.insn.mnemonic, self.insn.operands[0].imm
        elif self.insn.id == PPC_INS_BC:
            branch_pred = "+" if (self.insn.bytes[1] & 0x20) else ""
            if self.insn.operands[0].type == PPC_OP_IMM:
                return f"{self.insn.mnemonic}{branch_pred}", self.insn.operands[0].imm
            elif self.insn.operands[1].type == PPC_OP_IMM:
                reg_name = self.insn.reg_name(self.insn.operands[0].value.reg)
                return (
                    f"{self.insn.mnemonic}{branch_pred} {reg_name},",
                    self.insn.operands[1].imm,
                )
        return None

    def reference_addr(self, addr):
        """Get a nice reference to immediate address from operand (label or symbol)."""
        if addr in self.labels:
            return label_name(addr)
        if self.symbols:
            sym = self.symbols.get(addr)
            if sym is not None:
                return sym.name
        if self.abs_branch:
            return hex(addr)
        else:
            return hex(addr - self.address)


def label_name(addr):
    return "lbl_%08x" % (addr)


class InlineInstruction(Instruction):
    """A Broadway CPU instruction in the context of C/C++ inline assembly."""

    def __init__(self, address, insn, bytes, labels, symbols):
        super().__init__(address, insn, bytes, labels, symbols, True)

    def prefix_text(self):
        """Override to have no prefix."""
        return ""


def disasm_iter(data, address, symbols):
    """Returns an iterator over every instruction in the specified code section."""
    assert address % 4 == 0, "Code is not aligned"
    assert len(data) % 4 == 0, "Odd code length"
    # Repeatedly invoke capstone.
    i = 0
    while i < len(data):
        # Invoke capstone.
        for insn in cs.disasm(data[i:], address):
            address = insn.address
            yield Instruction(
                address,
                insn if insn.id not in blacklistedInsns else None,
                insn.bytes,
                (),
                symbols,
            )
            i += 4
            address += 4
        if i < len(data):
            # Capstone aborts at unknown instructions.
            # Emit custom instruction.
            yield Instruction(
                address,
                None,
                data[i : i + 4],
                (),
                symbols,
            )
            address += 4
            i += 4
