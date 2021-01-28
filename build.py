import os

DEVKITPPC = "C:\\devkitPro\\devkitPPC"

GCC = os.path.join(DEVKITPPC, "bin\\powerpc-eabi-gcc.exe")
GAS = os.path.join(DEVKITPPC, "bin\\powerpc-eabi-as.exe")

MWLD = "tools\\mwldeppc.exe"

ELF2DOL = "tools\\elf2dol.exe"

def command(cmd):
	print(cmd)
	os.system(cmd)

def assemble(dst, src):
	cmd = GAS + " %s -mgekko -o %s" % (src, dst)
	command(cmd)

def link(dst, objs, lcf):
	cmd = MWLD + " %s -o %s -lcf %s" % (' '.join(objs), dst, lcf)
	command(cmd)

def make_obj(src):
	substitutions = (
		'.cpp', '.asm', '.c', '.s'
	)
	for s in substitutions:
		src = src.replace(s, '.o')
	return src

def build():
	asm_files = [x.strip() for x in open('build/asm_files.txt', 'r').readlines()]
	# src_files = [x.strip() for x in open('build/src_files.txt', 'r').readlines()]
	o_files = ["out/" + x.strip() for x in open('build/o_files.txt', 'r').readlines()]

	try:
		os.mkdir("out")
	except: pass

	for asm in asm_files:
		assemble("out/" + make_obj(asm).replace("asm/", ""), asm)

	link('out/built.elf', o_files, "build/link.lcf")

	with open('out/built.elf', 'r+b') as elf:
		elf.seek(0x18)
		elf.write(bytes([0x80, 0x00, 0x60, 0xA4]))

	try:
		os.mkdir("target")
	except: pass
	command(ELF2DOL + " out/built.elf target/mkw_pal.dol -v -v")

	# This is a bug with elf2dol; this works fine with makedol
	# for now I'll just patch it...
	with open('target/mkw_pal.dol', 'r+b') as dol:
		dol.seek(0xDC)
		# bss_size
		dol.write(bytes([0x00, 0x0E, 0x50, 0xFC]))

	import hashlib
	ctx = hashlib.sha1(open('target/mkw_pal.dol', 'rb').read())
	digest = ctx.hexdigest()
	if digest.lower() == 'ac7d72448630ade7655fc8bc5fd7a6543cb53a49':
		print("Everything went okay! Output is matching! ^^")
		return

	print("Oof: Output doesn't match.")
	# TODO: Add diff'ing

build()