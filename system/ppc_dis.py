# Based on https://gist.github.com/camthesaxman/a36f610dbf4cc53a874322ef146c4123
#
# Changes:
# - Blacklisted more instructionss
# - Adjusted output to take up fewer bytes
# - mwasm support

from capstone import *
from capstone.ppc import *


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
	PPC_INS_VMSUMSHM, PPC_INS_VMHADDSHS, PPC_INS_XXSLDWI, PPC_INS_VSEL,
	PPC_INS_XVSUBSP, PPC_INS_XXSEL, PPC_INS_XVMULSP, PPC_INS_XVDIVSP,
	PPC_INS_VADDUHM, PPC_INS_XXPERMDI, PPC_INS_XVMADDASP, PPC_INS_XVMADDMSP,
	PPC_INS_XVCMPGTSP, PPC_INS_XXMRGHD, PPC_INS_XSMSUBMDP, PPC_INS_XSTDIVDP,
	PPC_INS_XVADDSP, PPC_INS_XVCMPEQSP, PPC_INS_XVMSUBASP, PPC_INS_XVCMPGESP,

	PPC_INS_XSMSUBADP, PPC_INS_XSMADDADP, PPC_INS_XSCMPODP, PPC_INS_XVTDIVSP,
	PPC_INS_VMRGHB, PPC_INS_VADDUBM, PPC_INS_XSMADDMDP, PPC_INS_XSCMPUDP,
	PPC_INS_XVNMADDASP, PPC_INS_VADDUWM, PPC_INS_XVMSUBMSP,
	PPC_INS_XSNMSUBMDP, PPC_INS_XSNMSUBADP, PPC_INS_XVCMPEQDP,
	PPC_INS_VPKUHUM, PPC_INS_XVCMPGTDP, PPC_INS_XVMADDADP, PPC_INS_XVMSUBMDP,
	PPC_INS_VMADDFP, PPC_INS_XXSPLTW, PPC_INS_XVMSUBADP, PPC_INS_XVCMPGEDP,
	PPC_INS_XVNMSUBMDP, PPC_INS_XVMADDMDP, PPC_INS_XXMRGHW,

	PPC_INS_XVTDIVDP, PPC_INS_XXMRGLW, PPC_INS_XVADDDP, PPC_INS_XXLAND,
	PPC_INS_XVNMSUBASP, PPC_INS_XVNMSUBMSP,
	PPC_INS_XVNMADDADP, PPC_INS_XVNMADDMSP,
	PPC_INS_XSSUBDP,


	# Instructions that Capstone gets wrong
	PPC_INS_MFESR, PPC_INS_MFDEAR, PPC_INS_MTESR, PPC_INS_MTDEAR, PPC_INS_MFICCR, PPC_INS_MFASR
}

labels = set()
labelNames = {}


def addr_to_label(addr, insn_addr):
    if addr in labels:
        if addr in labelNames:
            return labelNames[addr]
        else:
            return "lbl_%08X" % addr
    else:
        return hex(addr - insn_addr)

def insn_to_text(insn, raw):
	# Probably data, not a real instruction
	if insn.id == PPC_INS_BDNZ and (insn.bytes[0] & 1):
		return None
	if insn.id in {PPC_INS_B, PPC_INS_BL, PPC_INS_BDZ, PPC_INS_BDNZ}:
		return "%s %s" % (insn.mnemonic, addr_to_label(insn.operands[0].imm, insn.address))
	elif insn.id == PPC_INS_BC:
		branchPred = '+' if (insn.bytes[1] & 0x20) else ''
		if insn.operands[0].type == PPC_OP_IMM:
			return "%s%s %s" % (insn.mnemonic, branchPred, addr_to_label(insn.operands[0].imm, insn.address))
		elif insn.operands[1].type == PPC_OP_IMM:
			return "%s%s %s, %s" % (insn.mnemonic, branchPred, insn.reg_name(insn.operands[0].value.reg), addr_to_label(insn.operands[1].imm, insn.address))
	
	# Sign-extend immediate values because Capstone is an idiot and doesn't do that automatically
	if insn.id in {PPC_INS_ADDI, PPC_INS_ADDIC, PPC_INS_SUBFIC, PPC_INS_MULLI} and (insn.operands[2].imm & 0x8000):
		return "%s %s, %s, %i" % (insn.mnemonic, insn.reg_name(insn.operands[0].reg), insn.reg_name(insn.operands[1].value.reg), insn.operands[2].imm - 0x10000)
	elif (insn.id == PPC_INS_LI or insn.id == PPC_INS_CMPWI) and (insn.operands[1].imm & 0x8000):
		return "%s %s, %i" % (insn.mnemonic, insn.reg_name(insn.operands[0].reg), insn.operands[1].imm - 0x10000)
	# cntlz -> cntlzw
	elif insn.id == PPC_INS_CNTLZW:
		return "cntlzw %s" % insn.op_str
	elif insn.id == PPC_INS_MTICCR:
		return 'mtictc %s' % insn.op_str
	# Dunno why GNU assembler doesn't accept this
	elif insn.id == PPC_INS_LMW and insn.operands[0].reg == PPC_REG_R0:
		return '.4byte 0x%08X  /* illegal %s %s */' % (raw, insn.mnemonic, insn.op_str)
	return '%s %s' % (insn.mnemonic, insn.op_str)

def disasm_ps(inst):
	RA = ((inst >> 16) & 0x1f)
	RB = ((inst >> 11) & 0x1f)
	FA = ((inst >> 16) & 0x1f)
	FB = ((inst >> 11) & 0x1f)
	FC = ((inst >> 6) & 0x1f)
	FD = ((inst >> 21) & 0x1f)
	FS = ((inst >> 21) & 0x1f)
	IX = ((inst >> 7) & 0x7)
	WX = ((inst >> 10) & 0x1)

	opcode = (inst >> 1) & 0x1F
	if opcode == 6:  # doesn't seem to be used
		mnemonic = 'psq_lux' if inst & 0x40 else 'psq_lx'
		return '%s f%i, r%i, r%i, %i, qr%i' % (mnemonic, FD, RA, RB, WX, IX)
	if opcode == 7:
		mnemonic = 'psq_stux' if inst & 0x40 else 'psq_stx'
		return '%s f%i, r%i, r%i, %i, qr%i' % (mnemonic, FS, RA, RB, WX, IX)
	if opcode == 18:
		return 'ps_div f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 20:
		return 'ps_sub f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 21:
		return 'ps_add f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 23:
		return 'ps_sel f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 24:
		return 'ps_res f%i, f%i' % (FD, FB)
	if opcode == 25:
		return 'ps_mul f%i, f%i, f%i' % (FD, FA, FC)
	if opcode == 26:
		return 'ps_rsqrte f%i, f%i' % (FD, FB)
	if opcode == 28:
		return 'ps_msub f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 29:
		return 'ps_madd f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 30:
		return 'ps_nmsub f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 31:
		return 'ps_nmadd f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 10:
		return 'ps_sum0 f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 11:
		return 'ps_sum1 f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 12:
		return 'ps_muls0 f%i, f%i, f%i' % (FD, FA, FC)
	if opcode == 13:
		return 'ps_muls1 f%i, f%i, f%i' % (FD, FA, FC)
	if opcode == 14:
		return 'ps_madds0 f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)
	if opcode == 15:
		return 'ps_madds1 f%i, f%i, f%i, f%i' % (FD, FA, FC, FB)

	opcode = (inst >> 1) & 0x3FF
	if opcode == 40:
		return 'ps_neg f%i, f%i' % (FD, FB)
	if opcode == 72:
		return 'ps_mr f%i, f%i' % (FD, FB)
	if opcode == 136:
		return 'ps_nabs f%i, f%i' % (FD, FB)
	if opcode == 264:
		return 'ps_abs f%i, f%i' % (FD, FB)
	if opcode in {0, 32, 64, 96}:
		mnemonics = ['ps_cmpu0', 'ps_cmpo0', 'ps_cmpu1', 'ps_cmpo1']
		mnemonic = mnemonics[(inst >> 6) & 3]
		i = (inst & 0x03800000) >> 23
		return '%s cr%i, f%i, f%i' % (mnemonic, i, FA, FB)
	if opcode == 528:
		return 'ps_merge00 f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 560:
		return 'ps_merge01 f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 592:
		return 'ps_merge10 f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 624:
		return 'ps_merge11 f%i, f%i, f%i' % (FD, FA, FB)
	if opcode == 1014:
		if not (inst & 0x03e00000):
			if (inst & 1) == 0:
				return 'dcbz_l r%i, r%i' % ((inst & 0x001f0000) >> 16, (inst & 0x0000f800) >> 11)
	return None

def disasm_ps_mem(inst, idx):
	RA = ((inst >> 16) & 0x1f)
	RS = ((inst >> 21) & 0x1f)
	I = ((inst >> 12) & 0x7)
	W = ((inst >> 15) & 0x1)
	disp = sign_extend_12(inst & 0xFFF)
	if idx == 56:
		mnemonic = 'psq_l'
	if idx == 57:
		mnemonic = 'psq_lu'
	if idx == 60:
		mnemonic = 'psq_st'
	if idx == 61:
		mnemonic = 'psq_stu'
	return '%s f%i, %i(r%i), %i, qr%i' % (mnemonic, RS, disp, RA, W, I)

def disasm_fcmp(inst):
	crd = (inst & 0x03800000) >> 23
	a = (inst & 0x001f0000) >> 16
	b = (inst & 0x0000f800) >> 11
	return 'fcmpo cr%i, f%i, f%i' % (crd, a, b)

def disasm_mspr(inst, mode):
	if (inst & 1):
		return None
	d = (inst & 0x03e00000) >> 21
	a = (inst & 0x001f0000) >> 16
	b = (inst & 0x0000f800) >>11
	spr = (b << 5) + a
	if mode:
		return 'mtspr 0x%X, r%i' % (spr, d)
	else:
		return 'mfspr r%i, 0x%X' % (d, spr)

def disasm_mcrxr(inst):
	if (inst & 0x007ff801):
		return None
	crd = (inst & 0x03800000) >> 23
	return 'mcrxr cr%i' % crd

# Disassemble code
def disassemble_callback(filecontent, address, offset, insn, bytes):
	prefixComment = '/* %08X  %02X %02X %02X %02X */' % (address, bytes[0], bytes[1], bytes[2], bytes[3])
	#prefixComment = '/* %08X */' % address
	asm = None
	def read_u32b(filecontent, offset):
		return (filecontent[offset + 0] << 24) | (filecontent[offset + 1] << 16) | (filecontent[offset + 2] << 8) | filecontent[offset + 3]

	raw = read_u32b(filecontent, offset)
	if insn != None:
		asm = insn_to_text(insn, raw)
	else:  # Capstone couldn't disassemble it 
		idx = (raw & 0xfc000000) >> 26
		idx2 = (raw & 0x000007fe) >> 1
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
	if asm == None:
		asm = '.4byte 0x%08X  /* unknown instruction */' % raw
	print('%s\t%s' % (prefixComment, asm))


'''
entryPoint = base.entry_point
# Add entry point
labels.add(entryPoint)
labelNames[entryPoint] = '__start'
'''

# Calls callback for every instruction in the specified code section
def disasm_iter(filecontent, offset, address, size, callback):
	if size == 0:
		return
	start = address
	end = address + size
	while address < end:
		code = filecontent[offset + (address-start) : offset + size]
		for insn in cs.disasm(code, address):
			address = insn.address
			if insn.id in blacklistedInsns:
				callback(filecontent, address, offset + address - start, None, insn.bytes)
			else:
				callback(filecontent, address, offset + address - start, insn, insn.bytes)
			address += 4
		if address < end:
			o = offset + address - start
			callback(filecontent, address, offset + address - start, None, filecontent[o : o + 4])
			address += 4