
.include "macros.inc"

.section .text, "ax" # 0x8006A518 - 0x800774D0
/* 8006A518  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A51C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A520  80 63 00 00 */	lwz r3, 0(r3)
/* 8006A524  2C 03 00 00 */	cmpwi r3, 0
/* 8006A528  4D 82 00 20 */	beqlr 
/* 8006A52C  38 00 00 00 */	li r0, 0
/* 8006A530  90 03 00 A8 */	stw r0, 0xa8(r3)
/* 8006A534  D0 23 00 AC */	stfs f1, 0xac(r3)
/* 8006A538  D0 43 00 B0 */	stfs f2, 0xb0(r3)
/* 8006A53C  D0 63 00 B4 */	stfs f3, 0xb4(r3)
/* 8006A540  D0 83 00 B8 */	stfs f4, 0xb8(r3)
/* 8006A544  80 03 00 70 */	lwz r0, 0x70(r3)
/* 8006A548  54 00 07 2E */	rlwinm r0, r0, 0, 0x1c, 0x17
/* 8006A54C  60 00 00 20 */	ori r0, r0, 0x20
/* 8006A550  90 03 00 70 */	stw r0, 0x70(r3)
/* 8006A554  4E 80 00 20 */	blr 
/* 8006A558  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A55C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A560  80 63 00 00 */	lwz r3, 0(r3)
/* 8006A564  2C 03 00 00 */	cmpwi r3, 0
/* 8006A568  4D 82 00 20 */	beqlr 
/* 8006A56C  38 00 00 01 */	li r0, 1
/* 8006A570  90 03 00 A8 */	stw r0, 0xa8(r3)
/* 8006A574  D0 23 00 BC */	stfs f1, 0xbc(r3)
/* 8006A578  D0 43 00 C0 */	stfs f2, 0xc0(r3)
/* 8006A57C  D0 63 00 C4 */	stfs f3, 0xc4(r3)
/* 8006A580  D0 83 00 C8 */	stfs f4, 0xc8(r3)
/* 8006A584  D0 A3 00 B4 */	stfs f5, 0xb4(r3)
/* 8006A588  D0 C3 00 B8 */	stfs f6, 0xb8(r3)
/* 8006A58C  80 03 00 70 */	lwz r0, 0x70(r3)
/* 8006A590  54 00 07 2E */	rlwinm r0, r0, 0, 0x1c, 0x17
/* 8006A594  60 00 00 40 */	ori r0, r0, 0x40
/* 8006A598  90 03 00 70 */	stw r0, 0x70(r3)
/* 8006A59C  4E 80 00 20 */	blr 
/* 8006A5A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006A5A4  7C 08 02 A6 */	mflr r0
/* 8006A5A8  2C 04 00 00 */	cmpwi r4, 0
/* 8006A5AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006A5B0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006A5B4  41 82 00 24 */	beq 0x24
/* 8006A5B8  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006A5BC  2C 1F 00 00 */	cmpwi r31, 0
/* 8006A5C0  41 82 00 18 */	beq 0x18
/* 8006A5C4  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006A5C8  48 01 B5 B9 */	bl 0x1b5b8
/* 8006A5CC  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006A5D0  60 00 00 80 */	ori r0, r0, 0x80
/* 8006A5D4  90 1F 00 70 */	stw r0, 0x70(r31)
/* 8006A5D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006A5DC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006A5E0  7C 08 03 A6 */	mtlr r0
/* 8006A5E4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006A5E8  4E 80 00 20 */	blr 
/* 8006A5EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A5F0  80 63 00 00 */	lwz r3, 0(r3)
/* 8006A5F4  2C 03 00 00 */	cmpwi r3, 0
/* 8006A5F8  4D 82 00 20 */	beqlr 
/* 8006A5FC  90 83 00 F4 */	stw r4, 0xf4(r3)
/* 8006A600  90 A3 00 F8 */	stw r5, 0xf8(r3)
/* 8006A604  90 C3 00 FC */	stw r6, 0xfc(r3)
/* 8006A608  90 E3 01 00 */	stw r7, 0x100(r3)
/* 8006A60C  4E 80 00 20 */	blr 
/* 8006A610  80 63 00 00 */	lwz r3, 0(r3)
/* 8006A614  2C 03 00 00 */	cmpwi r3, 0
/* 8006A618  4D 82 00 20 */	beqlr 
/* 8006A61C  90 83 01 04 */	stw r4, 0x104(r3)
/* 8006A620  90 A3 01 08 */	stw r5, 0x108(r3)
/* 8006A624  4E 80 00 20 */	blr 
/* 8006A628  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A62C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A630  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8006A634  7C 08 02 A6 */	mflr r0
/* 8006A638  90 01 00 34 */	stw r0, 0x34(r1)
/* 8006A63C  DB E1 00 28 */	stfd f31, 0x28(r1)
/* 8006A640  FF E0 20 90 */	fmr f31, f4
/* 8006A644  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 8006A648  FF C0 18 90 */	fmr f30, f3
/* 8006A64C  DB A1 00 18 */	stfd f29, 0x18(r1)
/* 8006A650  FF A0 10 90 */	fmr f29, f2
/* 8006A654  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8006A658  80 83 00 00 */	lwz r4, 0(r3)
/* 8006A65C  2C 04 00 00 */	cmpwi r4, 0
/* 8006A660  41 82 00 4C */	beq 0x4c
/* 8006A664  D0 24 00 DC */	stfs f1, 0xdc(r4)
/* 8006A668  D0 44 00 E0 */	stfs f2, 0xe0(r4)
/* 8006A66C  D0 64 00 E4 */	stfs f3, 0xe4(r4)
/* 8006A670  D0 84 00 E8 */	stfs f4, 0xe8(r4)
/* 8006A674  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006A678  2C 1F 00 00 */	cmpwi r31, 0
/* 8006A67C  41 82 00 30 */	beq 0x30
/* 8006A680  4B FB 6D F9 */	bl -0x49208
/* 8006A684  FC 20 E8 90 */	fmr f1, f29
/* 8006A688  90 7F 00 F4 */	stw r3, 0xf4(r31)
/* 8006A68C  4B FB 6D ED */	bl -0x49214
/* 8006A690  FC 20 F0 90 */	fmr f1, f30
/* 8006A694  90 7F 00 F8 */	stw r3, 0xf8(r31)
/* 8006A698  4B FB 6D E1 */	bl -0x49220
/* 8006A69C  FC 20 F8 90 */	fmr f1, f31
/* 8006A6A0  90 7F 00 FC */	stw r3, 0xfc(r31)
/* 8006A6A4  4B FB 6D D5 */	bl -0x4922c
/* 8006A6A8  90 7F 01 00 */	stw r3, 0x100(r31)
/* 8006A6AC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8006A6B0  CB E1 00 28 */	lfd f31, 0x28(r1)
/* 8006A6B4  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 8006A6B8  CB A1 00 18 */	lfd f29, 0x18(r1)
/* 8006A6BC  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8006A6C0  7C 08 03 A6 */	mtlr r0
/* 8006A6C4  38 21 00 30 */	addi r1, r1, 0x30
/* 8006A6C8  4E 80 00 20 */	blr 
/* 8006A6CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A6D0  80 63 00 00 */	lwz r3, 0(r3)
/* 8006A6D4  2C 03 00 00 */	cmpwi r3, 0
/* 8006A6D8  4D 82 00 20 */	beqlr 
/* 8006A6DC  D0 23 00 EC */	stfs f1, 0xec(r3)
/* 8006A6E0  D0 43 00 F0 */	stfs f2, 0xf0(r3)
/* 8006A6E4  4E 80 00 20 */	blr 
/* 8006A6E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A6EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A6F0  80 63 00 00 */	lwz r3, 0(r3)
/* 8006A6F4  2C 03 00 00 */	cmpwi r3, 0
/* 8006A6F8  4D 82 00 20 */	beqlr 
/* 8006A6FC  2C 04 00 00 */	cmpwi r4, 0
/* 8006A700  41 82 00 0C */	beq 0xc
/* 8006A704  C0 03 00 DC */	lfs f0, 0xdc(r3)
/* 8006A708  D0 04 00 00 */	stfs f0, 0(r4)
/* 8006A70C  2C 05 00 00 */	cmpwi r5, 0
/* 8006A710  41 82 00 0C */	beq 0xc
/* 8006A714  C0 03 00 E0 */	lfs f0, 0xe0(r3)
/* 8006A718  D0 05 00 00 */	stfs f0, 0(r5)
/* 8006A71C  2C 06 00 00 */	cmpwi r6, 0
/* 8006A720  41 82 00 0C */	beq 0xc
/* 8006A724  C0 03 00 E4 */	lfs f0, 0xe4(r3)
/* 8006A728  D0 06 00 00 */	stfs f0, 0(r6)
/* 8006A72C  2C 07 00 00 */	cmpwi r7, 0
/* 8006A730  41 82 00 0C */	beq 0xc
/* 8006A734  C0 03 00 E8 */	lfs f0, 0xe8(r3)
/* 8006A738  D0 07 00 00 */	stfs f0, 0(r7)
/* 8006A73C  2C 08 00 00 */	cmpwi r8, 0
/* 8006A740  41 82 00 0C */	beq 0xc
/* 8006A744  C0 03 00 EC */	lfs f0, 0xec(r3)
/* 8006A748  D0 08 00 00 */	stfs f0, 0(r8)
/* 8006A74C  2C 09 00 00 */	cmpwi r9, 0
/* 8006A750  4D 82 00 20 */	beqlr 
/* 8006A754  C0 03 00 F0 */	lfs f0, 0xf0(r3)
/* 8006A758  D0 09 00 00 */	stfs f0, 0(r9)
/* 8006A75C  4E 80 00 20 */	blr 
/* 8006A760  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006A764  7C 08 02 A6 */	mflr r0
/* 8006A768  2C 04 00 00 */	cmpwi r4, 0
/* 8006A76C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006A770  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006A774  93 C1 00 08 */	stw r30, 8(r1)
/* 8006A778  7C 9E 23 78 */	mr r30, r4
/* 8006A77C  41 82 00 2C */	beq 0x2c
/* 8006A780  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006A784  2C 1F 00 00 */	cmpwi r31, 0
/* 8006A788  41 82 00 20 */	beq 0x20
/* 8006A78C  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006A790  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 8006A794  40 82 00 08 */	bne 0x8
/* 8006A798  48 00 04 09 */	bl 0x408
/* 8006A79C  7F E3 FB 78 */	mr r3, r31
/* 8006A7A0  7F C4 F3 78 */	mr r4, r30
/* 8006A7A4  48 12 F5 8D */	bl 0x12f58c
/* 8006A7A8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006A7AC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006A7B0  83 C1 00 08 */	lwz r30, 8(r1)
/* 8006A7B4  7C 08 03 A6 */	mtlr r0
/* 8006A7B8  38 21 00 10 */	addi r1, r1, 0x10
/* 8006A7BC  4E 80 00 20 */	blr 
/* 8006A7C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006A7C4  7C 08 02 A6 */	mflr r0
/* 8006A7C8  2C 04 00 00 */	cmpwi r4, 0
/* 8006A7CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006A7D0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006A7D4  93 C1 00 08 */	stw r30, 8(r1)
/* 8006A7D8  7C 9E 23 78 */	mr r30, r4
/* 8006A7DC  41 82 00 A8 */	beq 0xa8
/* 8006A7E0  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006A7E4  2C 1F 00 00 */	cmpwi r31, 0
/* 8006A7E8  41 82 00 9C */	beq 0x9c
/* 8006A7EC  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006A7F0  54 00 06 31 */	rlwinm. r0, r0, 0, 0x18, 0x18
/* 8006A7F4  40 82 00 84 */	bne 0x84
/* 8006A7F8  80 7F 00 70 */	lwz r3, 0x70(r31)
/* 8006A7FC  54 60 06 73 */	rlwinm. r0, r3, 0, 0x19, 0x19
/* 8006A800  41 82 00 28 */	beq 0x28
/* 8006A804  C0 3F 00 BC */	lfs f1, 0xbc(r31)
/* 8006A808  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006A80C  C0 5F 00 C0 */	lfs f2, 0xc0(r31)
/* 8006A810  C0 7F 00 C4 */	lfs f3, 0xc4(r31)
/* 8006A814  C0 9F 00 C8 */	lfs f4, 0xc8(r31)
/* 8006A818  C0 BF 00 B4 */	lfs f5, 0xb4(r31)
/* 8006A81C  C0 DF 00 B8 */	lfs f6, 0xb8(r31)
/* 8006A820  48 13 03 2D */	bl 0x13032c
/* 8006A824  48 00 00 48 */	b 0x48
/* 8006A828  54 60 06 F7 */	rlwinm. r0, r3, 0, 0x1b, 0x1b
/* 8006A82C  41 82 00 28 */	beq 0x28
/* 8006A830  C0 3F 00 BC */	lfs f1, 0xbc(r31)
/* 8006A834  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006A838  C0 5F 00 C0 */	lfs f2, 0xc0(r31)
/* 8006A83C  C0 7F 00 C4 */	lfs f3, 0xc4(r31)
/* 8006A840  C0 9F 00 C8 */	lfs f4, 0xc8(r31)
/* 8006A844  C0 BF 00 B4 */	lfs f5, 0xb4(r31)
/* 8006A848  C0 DF 00 B8 */	lfs f6, 0xb8(r31)
/* 8006A84C  48 13 01 79 */	bl 0x130178
/* 8006A850  48 00 00 1C */	b 0x1c
/* 8006A854  C0 3F 00 AC */	lfs f1, 0xac(r31)
/* 8006A858  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006A85C  C0 5F 00 B0 */	lfs f2, 0xb0(r31)
/* 8006A860  C0 7F 00 B4 */	lfs f3, 0xb4(r31)
/* 8006A864  C0 9F 00 B8 */	lfs f4, 0xb8(r31)
/* 8006A868  48 13 01 F9 */	bl 0x1301f8
/* 8006A86C  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006A870  60 00 00 80 */	ori r0, r0, 0x80
/* 8006A874  90 1F 00 70 */	stw r0, 0x70(r31)
/* 8006A878  7F C3 F3 78 */	mr r3, r30
/* 8006A87C  38 9F 00 30 */	addi r4, r31, 0x30
/* 8006A880  48 01 B3 01 */	bl 0x1b300
/* 8006A884  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006A888  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006A88C  83 C1 00 08 */	lwz r30, 8(r1)
/* 8006A890  7C 08 03 A6 */	mtlr r0
/* 8006A894  38 21 00 10 */	addi r1, r1, 0x10
/* 8006A898  4E 80 00 20 */	blr 
/* 8006A89C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006A8A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006A8A4  7C 08 02 A6 */	mflr r0
/* 8006A8A8  2C 04 00 00 */	cmpwi r4, 0
/* 8006A8AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006A8B0  41 82 00 B0 */	beq 0xb0
/* 8006A8B4  80 A3 00 00 */	lwz r5, 0(r3)
/* 8006A8B8  2C 05 00 00 */	cmpwi r5, 0
/* 8006A8BC  41 82 00 A4 */	beq 0xa4
/* 8006A8C0  80 65 00 70 */	lwz r3, 0x70(r5)
/* 8006A8C4  54 60 06 73 */	rlwinm. r0, r3, 0, 0x19, 0x19
/* 8006A8C8  41 82 00 34 */	beq 0x34
/* 8006A8CC  C0 05 00 D0 */	lfs f0, 0xd0(r5)
/* 8006A8D0  7C 83 23 78 */	mr r3, r4
/* 8006A8D4  C0 25 00 BC */	lfs f1, 0xbc(r5)
/* 8006A8D8  FC C0 00 50 */	fneg f6, f0
/* 8006A8DC  C0 45 00 C0 */	lfs f2, 0xc0(r5)
/* 8006A8E0  C0 65 00 C4 */	lfs f3, 0xc4(r5)
/* 8006A8E4  C0 85 00 C8 */	lfs f4, 0xc8(r5)
/* 8006A8E8  C0 A5 00 CC */	lfs f5, 0xcc(r5)
/* 8006A8EC  C0 E5 00 D4 */	lfs f7, 0xd4(r5)
/* 8006A8F0  C1 05 00 D8 */	lfs f8, 0xd8(r5)
/* 8006A8F4  48 12 FF A1 */	bl 0x12ffa0
/* 8006A8F8  48 00 00 68 */	b 0x68
/* 8006A8FC  54 60 06 F7 */	rlwinm. r0, r3, 0, 0x1b, 0x1b
/* 8006A900  41 82 00 3C */	beq 0x3c
/* 8006A904  C0 05 00 D8 */	lfs f0, 0xd8(r5)
/* 8006A908  7C 83 23 78 */	mr r3, r4
/* 8006A90C  D0 01 00 08 */	stfs f0, 8(r1)
/* 8006A910  C0 05 00 D0 */	lfs f0, 0xd0(r5)
/* 8006A914  C0 25 00 BC */	lfs f1, 0xbc(r5)
/* 8006A918  FC E0 00 50 */	fneg f7, f0
/* 8006A91C  C0 45 00 C0 */	lfs f2, 0xc0(r5)
/* 8006A920  C0 65 00 C4 */	lfs f3, 0xc4(r5)
/* 8006A924  C0 85 00 C8 */	lfs f4, 0xc8(r5)
/* 8006A928  C0 A5 00 B4 */	lfs f5, 0xb4(r5)
/* 8006A92C  C0 C5 00 CC */	lfs f6, 0xcc(r5)
/* 8006A930  C1 05 00 D4 */	lfs f8, 0xd4(r5)
/* 8006A934  48 12 FD C5 */	bl 0x12fdc4
/* 8006A938  48 00 00 28 */	b 0x28
/* 8006A93C  C0 05 00 D0 */	lfs f0, 0xd0(r5)
/* 8006A940  7C 83 23 78 */	mr r3, r4
/* 8006A944  C0 25 00 AC */	lfs f1, 0xac(r5)
/* 8006A948  FC 80 00 50 */	fneg f4, f0
/* 8006A94C  C0 45 00 B0 */	lfs f2, 0xb0(r5)
/* 8006A950  C0 65 00 CC */	lfs f3, 0xcc(r5)
/* 8006A954  C0 A5 00 D4 */	lfs f5, 0xd4(r5)
/* 8006A958  C0 C5 00 D8 */	lfs f6, 0xd8(r5)
/* 8006A95C  48 12 FE 41 */	bl 0x12fe40
/* 8006A960  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006A964  7C 08 03 A6 */	mtlr r0
/* 8006A968  38 21 00 10 */	addi r1, r1, 0x10
/* 8006A96C  4E 80 00 20 */	blr 
/* 8006A970  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006A974  7C 08 02 A6 */	mflr r0
/* 8006A978  2C 04 00 00 */	cmpwi r4, 0
/* 8006A97C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006A980  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006A984  93 C1 00 08 */	stw r30, 8(r1)
/* 8006A988  7C 9E 23 78 */	mr r30, r4
/* 8006A98C  41 82 00 4C */	beq 0x4c
/* 8006A990  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006A994  2C 1F 00 00 */	cmpwi r31, 0
/* 8006A998  41 82 00 40 */	beq 0x40
/* 8006A99C  7F C3 F3 78 */	mr r3, r30
/* 8006A9A0  48 12 F3 65 */	bl 0x12f364
/* 8006A9A4  C0 1F 00 CC */	lfs f0, 0xcc(r31)
/* 8006A9A8  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8006A9AC  C0 22 8D 10 */	lfs f1, -0x72f0(r2)
/* 8006A9B0  C0 1F 00 D4 */	lfs f0, 0xd4(r31)
/* 8006A9B4  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8006A9B8  C0 02 8D 18 */	lfs f0, -0x72e8(r2)
/* 8006A9BC  C0 5F 00 D0 */	lfs f2, 0xd0(r31)
/* 8006A9C0  FC 40 10 50 */	fneg f2, f2
/* 8006A9C4  D0 5E 00 14 */	stfs f2, 0x14(r30)
/* 8006A9C8  C0 5F 00 D8 */	lfs f2, 0xd8(r31)
/* 8006A9CC  D0 5E 00 1C */	stfs f2, 0x1c(r30)
/* 8006A9D0  D0 3E 00 28 */	stfs f1, 0x28(r30)
/* 8006A9D4  D0 1E 00 2C */	stfs f0, 0x2c(r30)
/* 8006A9D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006A9DC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006A9E0  83 C1 00 08 */	lwz r30, 8(r1)
/* 8006A9E4  7C 08 03 A6 */	mtlr r0
/* 8006A9E8  38 21 00 10 */	addi r1, r1, 0x10
/* 8006A9EC  4E 80 00 20 */	blr 
/* 8006A9F0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006A9F4  7C 08 02 A6 */	mflr r0
/* 8006A9F8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006A9FC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006AA00  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006AA04  2C 1F 00 00 */	cmpwi r31, 0
/* 8006AA08  41 82 00 58 */	beq 0x58
/* 8006AA0C  4B FF 9A 35 */	bl -0x65cc
/* 8006AA10  88 03 00 18 */	lbz r0, 0x18(r3)
/* 8006AA14  2C 00 00 00 */	cmpwi r0, 0
/* 8006AA18  41 82 00 2C */	beq 0x2c
/* 8006AA1C  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006AA20  C0 3F 00 DC */	lfs f1, 0xdc(r31)
/* 8006AA24  C0 5F 00 E0 */	lfs f2, 0xe0(r31)
/* 8006AA28  54 03 C7 FE */	rlwinm r3, r0, 0x18, 0x1f, 0x1f
/* 8006AA2C  C0 7F 00 E4 */	lfs f3, 0xe4(r31)
/* 8006AA30  C0 9F 00 E8 */	lfs f4, 0xe8(r31)
/* 8006AA34  C0 BF 00 EC */	lfs f5, 0xec(r31)
/* 8006AA38  C0 DF 00 F0 */	lfs f6, 0xf0(r31)
/* 8006AA3C  48 10 89 3D */	bl 0x10893c
/* 8006AA40  48 00 00 20 */	b 0x20
/* 8006AA44  C0 3F 00 DC */	lfs f1, 0xdc(r31)
/* 8006AA48  C0 5F 00 E0 */	lfs f2, 0xe0(r31)
/* 8006AA4C  C0 7F 00 E4 */	lfs f3, 0xe4(r31)
/* 8006AA50  C0 9F 00 E8 */	lfs f4, 0xe8(r31)
/* 8006AA54  C0 BF 00 EC */	lfs f5, 0xec(r31)
/* 8006AA58  C0 DF 00 F0 */	lfs f6, 0xf0(r31)
/* 8006AA5C  48 10 89 59 */	bl 0x108958
/* 8006AA60  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006AA64  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006AA68  7C 08 03 A6 */	mtlr r0
/* 8006AA6C  38 21 00 10 */	addi r1, r1, 0x10
/* 8006AA70  4E 80 00 20 */	blr 
/* 8006AA74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AA78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AA7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AA80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006AA84  7C 08 02 A6 */	mflr r0
/* 8006AA88  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006AA8C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006AA90  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006AA94  2C 1F 00 00 */	cmpwi r31, 0
/* 8006AA98  41 82 00 9C */	beq 0x9c
/* 8006AA9C  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006AAA0  54 00 06 31 */	rlwinm. r0, r0, 0, 0x18, 0x18
/* 8006AAA4  40 82 00 84 */	bne 0x84
/* 8006AAA8  80 7F 00 70 */	lwz r3, 0x70(r31)
/* 8006AAAC  54 60 06 73 */	rlwinm. r0, r3, 0, 0x19, 0x19
/* 8006AAB0  41 82 00 28 */	beq 0x28
/* 8006AAB4  C0 3F 00 BC */	lfs f1, 0xbc(r31)
/* 8006AAB8  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006AABC  C0 5F 00 C0 */	lfs f2, 0xc0(r31)
/* 8006AAC0  C0 7F 00 C4 */	lfs f3, 0xc4(r31)
/* 8006AAC4  C0 9F 00 C8 */	lfs f4, 0xc8(r31)
/* 8006AAC8  C0 BF 00 B4 */	lfs f5, 0xb4(r31)
/* 8006AACC  C0 DF 00 B8 */	lfs f6, 0xb8(r31)
/* 8006AAD0  48 13 00 7D */	bl 0x13007c
/* 8006AAD4  48 00 00 48 */	b 0x48
/* 8006AAD8  54 60 06 F7 */	rlwinm. r0, r3, 0, 0x1b, 0x1b
/* 8006AADC  41 82 00 28 */	beq 0x28
/* 8006AAE0  C0 3F 00 BC */	lfs f1, 0xbc(r31)
/* 8006AAE4  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006AAE8  C0 5F 00 C0 */	lfs f2, 0xc0(r31)
/* 8006AAEC  C0 7F 00 C4 */	lfs f3, 0xc4(r31)
/* 8006AAF0  C0 9F 00 C8 */	lfs f4, 0xc8(r31)
/* 8006AAF4  C0 BF 00 B4 */	lfs f5, 0xb4(r31)
/* 8006AAF8  C0 DF 00 B8 */	lfs f6, 0xb8(r31)
/* 8006AAFC  48 12 FE C9 */	bl 0x12fec8
/* 8006AB00  48 00 00 1C */	b 0x1c
/* 8006AB04  C0 3F 00 AC */	lfs f1, 0xac(r31)
/* 8006AB08  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006AB0C  C0 5F 00 B0 */	lfs f2, 0xb0(r31)
/* 8006AB10  C0 7F 00 B4 */	lfs f3, 0xb4(r31)
/* 8006AB14  C0 9F 00 B8 */	lfs f4, 0xb8(r31)
/* 8006AB18  48 12 FF 49 */	bl 0x12ff48
/* 8006AB1C  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006AB20  60 00 00 80 */	ori r0, r0, 0x80
/* 8006AB24  90 1F 00 70 */	stw r0, 0x70(r31)
/* 8006AB28  80 9F 00 A8 */	lwz r4, 0xa8(r31)
/* 8006AB2C  38 7F 00 30 */	addi r3, r31, 0x30
/* 8006AB30  48 10 84 ED */	bl 0x1084ec
/* 8006AB34  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006AB38  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006AB3C  7C 08 03 A6 */	mtlr r0
/* 8006AB40  38 21 00 10 */	addi r1, r1, 0x10
/* 8006AB44  4E 80 00 20 */	blr 
/* 8006AB48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AB4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AB50  80 C3 00 00 */	lwz r6, 0(r3)
/* 8006AB54  2C 06 00 00 */	cmpwi r6, 0
/* 8006AB58  4D 82 00 20 */	beqlr 
/* 8006AB5C  80 66 00 F4 */	lwz r3, 0xf4(r6)
/* 8006AB60  80 86 00 F8 */	lwz r4, 0xf8(r6)
/* 8006AB64  80 A6 00 FC */	lwz r5, 0xfc(r6)
/* 8006AB68  80 C6 01 00 */	lwz r6, 0x100(r6)
/* 8006AB6C  48 10 88 C4 */	b 0x1088c4
/* 8006AB70  4E 80 00 20 */	blr 
/* 8006AB74  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AB78  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AB7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AB80  80 83 00 00 */	lwz r4, 0(r3)
/* 8006AB84  2C 04 00 00 */	cmpwi r4, 0
/* 8006AB88  4D 82 00 20 */	beqlr 
/* 8006AB8C  80 64 01 04 */	lwz r3, 0x104(r4)
/* 8006AB90  80 84 01 08 */	lwz r4, 0x108(r4)
/* 8006AB94  48 10 89 4C */	b 0x10894c
/* 8006AB98  4E 80 00 20 */	blr 
/* 8006AB9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006ABA0  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 8006ABA4  7C 08 02 A6 */	mflr r0
/* 8006ABA8  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 8006ABAC  DB E1 00 90 */	stfd f31, 0x90(r1)
/* 8006ABB0  F3 E1 00 98 */	psq_st f31, 152(r1), 0, qr0
/* 8006ABB4  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 8006ABB8  83 E3 00 00 */	lwz r31, 0(r3)
/* 8006ABBC  80 7F 00 70 */	lwz r3, 0x70(r31)
/* 8006ABC0  54 60 07 FF */	clrlwi. r0, r3, 0x1f
/* 8006ABC4  41 82 00 1C */	beq 0x1c
/* 8006ABC8  7F E3 FB 78 */	mr r3, r31
/* 8006ABCC  38 9F 00 74 */	addi r4, r31, 0x74
/* 8006ABD0  38 BF 00 80 */	addi r5, r31, 0x80
/* 8006ABD4  38 DF 00 8C */	addi r6, r31, 0x8c
/* 8006ABD8  48 12 F9 AD */	bl 0x12f9ac
/* 8006ABDC  48 00 03 B8 */	b 0x3b8
/* 8006ABE0  54 60 07 7B */	rlwinm. r0, r3, 0, 0x1d, 0x1d
/* 8006ABE4  41 82 02 40 */	beq 0x240
/* 8006ABE8  C0 3F 00 74 */	lfs f1, 0x74(r31)
/* 8006ABEC  C0 1F 00 8C */	lfs f0, 0x8c(r31)
/* 8006ABF0  C0 9F 00 7C */	lfs f4, 0x7c(r31)
/* 8006ABF4  EC A1 00 28 */	fsubs f5, f1, f0
/* 8006ABF8  C0 7F 00 94 */	lfs f3, 0x94(r31)
/* 8006ABFC  C0 42 8D 10 */	lfs f2, -0x72f0(r2)
/* 8006AC00  C0 3F 00 78 */	lfs f1, 0x78(r31)
/* 8006AC04  EC 64 18 28 */	fsubs f3, f4, f3
/* 8006AC08  C0 1F 00 90 */	lfs f0, 0x90(r31)
/* 8006AC0C  FC 02 28 00 */	fcmpu cr0, f2, f5
/* 8006AC10  EC 01 00 28 */	fsubs f0, f1, f0
/* 8006AC14  D0 A1 00 7C */	stfs f5, 0x7c(r1)
/* 8006AC18  D0 01 00 80 */	stfs f0, 0x80(r1)
/* 8006AC1C  D0 61 00 84 */	stfs f3, 0x84(r1)
/* 8006AC20  40 82 00 90 */	bne 0x90
/* 8006AC24  FC 02 18 00 */	fcmpu cr0, f2, f3
/* 8006AC28  40 82 00 88 */	bne 0x88
/* 8006AC2C  C0 22 8D 18 */	lfs f1, -0x72e8(r2)
/* 8006AC30  D0 3F 00 00 */	stfs f1, 0(r31)
/* 8006AC34  D0 5F 00 04 */	stfs f2, 4(r31)
/* 8006AC38  D0 5F 00 08 */	stfs f2, 8(r31)
/* 8006AC3C  C0 1F 00 74 */	lfs f0, 0x74(r31)
/* 8006AC40  FC 00 00 50 */	fneg f0, f0
/* 8006AC44  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8006AC48  D0 5F 00 10 */	stfs f2, 0x10(r31)
/* 8006AC4C  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 8006AC50  D0 5F 00 20 */	stfs f2, 0x20(r31)
/* 8006AC54  D0 5F 00 28 */	stfs f2, 0x28(r31)
/* 8006AC58  C0 01 00 80 */	lfs f0, 0x80(r1)
/* 8006AC5C  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 8006AC60  4C 40 13 82 */	cror 2, 0, 2
/* 8006AC64  40 82 00 28 */	bne 0x28
/* 8006AC68  D0 3F 00 18 */	stfs f1, 0x18(r31)
/* 8006AC6C  C0 02 8D 38 */	lfs f0, -0x72c8(r2)
/* 8006AC70  C0 3F 00 7C */	lfs f1, 0x7c(r31)
/* 8006AC74  FC 20 08 50 */	fneg f1, f1
/* 8006AC78  D0 3F 00 1C */	stfs f1, 0x1c(r31)
/* 8006AC7C  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8006AC80  C0 1F 00 78 */	lfs f0, 0x78(r31)
/* 8006AC84  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8006AC88  48 00 03 0C */	b 0x30c
/* 8006AC8C  C0 02 8D 38 */	lfs f0, -0x72c8(r2)
/* 8006AC90  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 8006AC94  C0 1F 00 7C */	lfs f0, 0x7c(r31)
/* 8006AC98  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006AC9C  D0 3F 00 24 */	stfs f1, 0x24(r31)
/* 8006ACA0  C0 1F 00 78 */	lfs f0, 0x78(r31)
/* 8006ACA4  FC 00 00 50 */	fneg f0, f0
/* 8006ACA8  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8006ACAC  48 00 02 E8 */	b 0x2e8
/* 8006ACB0  C0 01 00 7C */	lfs f0, 0x7c(r1)
/* 8006ACB4  38 61 00 7C */	addi r3, r1, 0x7c
/* 8006ACB8  C0 21 00 84 */	lfs f1, 0x84(r1)
/* 8006ACBC  7C 64 1B 78 */	mr r4, r3
/* 8006ACC0  FC 40 00 50 */	fneg f2, f0
/* 8006ACC4  C0 02 8D 10 */	lfs f0, -0x72f0(r2)
/* 8006ACC8  D0 21 00 70 */	stfs f1, 0x70(r1)
/* 8006ACCC  D0 01 00 74 */	stfs f0, 0x74(r1)
/* 8006ACD0  D0 41 00 78 */	stfs f2, 0x78(r1)
/* 8006ACD4  48 12 FF 51 */	bl 0x12ff50
/* 8006ACD8  38 61 00 70 */	addi r3, r1, 0x70
/* 8006ACDC  7C 64 1B 78 */	mr r4, r3
/* 8006ACE0  48 12 FF 45 */	bl 0x12ff44
/* 8006ACE4  38 61 00 7C */	addi r3, r1, 0x7c
/* 8006ACE8  38 81 00 70 */	addi r4, r1, 0x70
/* 8006ACEC  38 A1 00 64 */	addi r5, r1, 0x64
/* 8006ACF0  48 12 FF DD */	bl 0x12ffdc
/* 8006ACF4  C0 3F 00 A4 */	lfs f1, 0xa4(r31)
/* 8006ACF8  38 61 00 24 */	addi r3, r1, 0x24
/* 8006ACFC  C0 02 8D 3C */	lfs f0, -0x72c4(r2)
/* 8006AD00  38 81 00 20 */	addi r4, r1, 0x20
/* 8006AD04  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006AD08  48 01 A4 D9 */	bl 0x1a4d8
/* 8006AD0C  C1 61 00 24 */	lfs f11, 0x24(r1)
/* 8006AD10  38 61 00 58 */	addi r3, r1, 0x58
/* 8006AD14  C0 01 00 64 */	lfs f0, 0x64(r1)
/* 8006AD18  38 81 00 4C */	addi r4, r1, 0x4c
/* 8006AD1C  C1 41 00 20 */	lfs f10, 0x20(r1)
/* 8006AD20  38 A1 00 7C */	addi r5, r1, 0x7c
/* 8006AD24  C0 81 00 70 */	lfs f4, 0x70(r1)
/* 8006AD28  EC 4B 00 32 */	fmuls f2, f11, f0
/* 8006AD2C  EC 2A 00 32 */	fmuls f1, f10, f0
/* 8006AD30  C0 C1 00 6C */	lfs f6, 0x6c(r1)
/* 8006AD34  EC 0A 01 32 */	fmuls f0, f10, f4
/* 8006AD38  C1 01 00 68 */	lfs f8, 0x68(r1)
/* 8006AD3C  C0 A1 00 78 */	lfs f5, 0x78(r1)
/* 8006AD40  EC EB 02 32 */	fmuls f7, f11, f8
/* 8006AD44  ED 22 00 2A */	fadds f9, f2, f0
/* 8006AD48  EC 6B 01 B2 */	fmuls f3, f11, f6
/* 8006AD4C  D0 E1 00 5C */	stfs f7, 0x5c(r1)
/* 8006AD50  EC 4A 01 72 */	fmuls f2, f10, f5
/* 8006AD54  D1 3F 00 00 */	stfs f9, 0(r31)
/* 8006AD58  EC 0B 01 32 */	fmuls f0, f11, f4
/* 8006AD5C  EC 83 10 2A */	fadds f4, f3, f2
/* 8006AD60  D0 FF 00 04 */	stfs f7, 4(r31)
/* 8006AD64  EC 61 00 28 */	fsubs f3, f1, f0
/* 8006AD68  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8006AD6C  EC 2A 01 B2 */	fmuls f1, f10, f6
/* 8006AD70  EC 0B 01 72 */	fmuls f0, f11, f5
/* 8006AD74  D0 81 00 60 */	stfs f4, 0x60(r1)
/* 8006AD78  EC 4A 02 32 */	fmuls f2, f10, f8
/* 8006AD7C  E0 DF 00 78 */	psq_l f6, 120(r31), 0, qr0
/* 8006AD80  E0 83 00 04 */	psq_l f4, 4(r3), 0, qr0
/* 8006AD84  EC 21 00 28 */	fsubs f1, f1, f0
/* 8006AD88  D1 21 00 58 */	stfs f9, 0x58(r1)
/* 8006AD8C  10 C6 01 32 */	ps_mul f6, f6, f4
/* 8006AD90  E0 BF 80 74 */	psq_l f5, 116(r31), 1, qr0
/* 8006AD94  E0 03 80 00 */	psq_l f0, 0(r3), 1, qr0
/* 8006AD98  D0 61 00 4C */	stfs f3, 0x4c(r1)
/* 8006AD9C  10 85 30 3A */	ps_madd f4, f5, f0, f6
/* 8006ADA0  D0 41 00 50 */	stfs f2, 0x50(r1)
/* 8006ADA4  E0 E4 80 00 */	psq_l f7, 0(r4), 1, qr0
/* 8006ADA8  10 04 31 94 */	ps_sum0 f0, f4, f6, f6
/* 8006ADAC  D0 21 00 54 */	stfs f1, 0x54(r1)
/* 8006ADB0  E0 A4 00 04 */	psq_l f5, 4(r4), 0, qr0
/* 8006ADB4  FC 00 00 50 */	fneg f0, f0
/* 8006ADB8  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8006ADBC  D0 7F 00 10 */	stfs f3, 0x10(r31)
/* 8006ADC0  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 8006ADC4  D0 3F 00 18 */	stfs f1, 0x18(r31)
/* 8006ADC8  E0 3F 00 78 */	psq_l f1, 120(r31), 0, qr0
/* 8006ADCC  E0 1F 80 74 */	psq_l f0, 116(r31), 1, qr0
/* 8006ADD0  10 21 01 72 */	ps_mul f1, f1, f5
/* 8006ADD4  10 A0 09 FA */	ps_madd f5, f0, f7, f1
/* 8006ADD8  10 05 08 54 */	ps_sum0 f0, f5, f1, f1
/* 8006ADDC  FC 00 00 50 */	fneg f0, f0
/* 8006ADE0  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006ADE4  C0 01 00 7C */	lfs f0, 0x7c(r1)
/* 8006ADE8  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 8006ADEC  C0 01 00 80 */	lfs f0, 0x80(r1)
/* 8006ADF0  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8006ADF4  C0 01 00 84 */	lfs f0, 0x84(r1)
/* 8006ADF8  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8006ADFC  E0 5F 00 78 */	psq_l f2, 120(r31), 0, qr0
/* 8006AE00  E0 25 00 04 */	psq_l f1, 4(r5), 0, qr0
/* 8006AE04  E0 1F 80 74 */	psq_l f0, 116(r31), 1, qr0
/* 8006AE08  10 42 00 72 */	ps_mul f2, f2, f1
/* 8006AE0C  E0 25 80 00 */	psq_l f1, 0(r5), 1, qr0
/* 8006AE10  10 20 10 7A */	ps_madd f1, f0, f1, f2
/* 8006AE14  10 01 10 94 */	ps_sum0 f0, f1, f2, f2
/* 8006AE18  FC 00 00 50 */	fneg f0, f0
/* 8006AE1C  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8006AE20  48 00 01 74 */	b 0x174
/* 8006AE24  C0 3F 00 98 */	lfs f1, 0x98(r31)
/* 8006AE28  38 61 00 1C */	addi r3, r1, 0x1c
/* 8006AE2C  C0 02 8D 3C */	lfs f0, -0x72c4(r2)
/* 8006AE30  38 81 00 10 */	addi r4, r1, 0x10
/* 8006AE34  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006AE38  48 01 A3 A9 */	bl 0x1a3a8
/* 8006AE3C  C0 3F 00 9C */	lfs f1, 0x9c(r31)
/* 8006AE40  38 61 00 18 */	addi r3, r1, 0x18
/* 8006AE44  C0 02 8D 3C */	lfs f0, -0x72c4(r2)
/* 8006AE48  38 81 00 0C */	addi r4, r1, 0xc
/* 8006AE4C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006AE50  48 01 A3 91 */	bl 0x1a390
/* 8006AE54  C0 3F 00 A0 */	lfs f1, 0xa0(r31)
/* 8006AE58  38 61 00 14 */	addi r3, r1, 0x14
/* 8006AE5C  C0 02 8D 3C */	lfs f0, -0x72c4(r2)
/* 8006AE60  38 81 00 08 */	addi r4, r1, 8
/* 8006AE64  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006AE68  48 01 A3 79 */	bl 0x1a378
/* 8006AE6C  C0 41 00 1C */	lfs f2, 0x1c(r1)
/* 8006AE70  38 61 00 40 */	addi r3, r1, 0x40
/* 8006AE74  C3 E1 00 18 */	lfs f31, 0x18(r1)
/* 8006AE78  38 81 00 34 */	addi r4, r1, 0x34
/* 8006AE7C  C1 81 00 14 */	lfs f12, 0x14(r1)
/* 8006AE80  FC 00 10 50 */	fneg f0, f2
/* 8006AE84  ED A2 07 F2 */	fmuls f13, f2, f31
/* 8006AE88  C1 61 00 0C */	lfs f11, 0xc(r1)
/* 8006AE8C  C1 41 00 08 */	lfs f10, 8(r1)
/* 8006AE90  EC 3F 03 32 */	fmuls f1, f31, f12
/* 8006AE94  C1 01 00 10 */	lfs f8, 0x10(r1)
/* 8006AE98  EC 8C 03 72 */	fmuls f4, f12, f13
/* 8006AE9C  EC 6B 02 B2 */	fmuls f3, f11, f10
/* 8006AEA0  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 8006AEA4  EC 42 02 F2 */	fmuls f2, f2, f11
/* 8006AEA8  38 A1 00 28 */	addi r5, r1, 0x28
/* 8006AEAC  EC E8 03 32 */	fmuls f7, f8, f12
/* 8006AEB0  ED 24 18 2A */	fadds f9, f4, f3
/* 8006AEB4  EC 8C 00 B2 */	fmuls f4, f12, f2
/* 8006AEB8  D0 E1 00 44 */	stfs f7, 0x44(r1)
/* 8006AEBC  EC 7F 02 B2 */	fmuls f3, f31, f10
/* 8006AEC0  D1 3F 00 00 */	stfs f9, 0(r31)
/* 8006AEC4  EC A8 02 B2 */	fmuls f5, f8, f10
/* 8006AEC8  EC 4A 00 B2 */	fmuls f2, f10, f2
/* 8006AECC  EC C4 18 28 */	fsubs f6, f4, f3
/* 8006AED0  D0 FF 00 04 */	stfs f7, 4(r31)
/* 8006AED4  EC 68 07 F2 */	fmuls f3, f8, f31
/* 8006AED8  D0 C1 00 48 */	stfs f6, 0x48(r1)
/* 8006AEDC  EC 82 08 2A */	fadds f4, f2, f1
/* 8006AEE0  EC 48 02 F2 */	fmuls f2, f8, f11
/* 8006AEE4  D0 DF 00 08 */	stfs f6, 8(r31)
/* 8006AEE8  EC CA 03 72 */	fmuls f6, f10, f13
/* 8006AEEC  E0 E3 00 04 */	psq_l f7, 4(r3), 0, qr0
/* 8006AEF0  EC 2B 03 32 */	fmuls f1, f11, f12
/* 8006AEF4  E1 5F 00 78 */	psq_l f10, 120(r31), 0, qr0
/* 8006AEF8  D1 21 00 40 */	stfs f9, 0x40(r1)
/* 8006AEFC  FC 00 00 18 */	frsp f0, f0
/* 8006AF00  11 4A 01 F2 */	ps_mul f10, f10, f7
/* 8006AF04  E0 FF 80 74 */	psq_l f7, 116(r31), 1, qr0
/* 8006AF08  E1 03 80 00 */	psq_l f8, 0(r3), 1, qr0
/* 8006AF0C  EC C6 08 28 */	fsubs f6, f6, f1
/* 8006AF10  D0 41 00 30 */	stfs f2, 0x30(r1)
/* 8006AF14  10 E7 52 3A */	ps_madd f7, f7, f8, f10
/* 8006AF18  D0 61 00 28 */	stfs f3, 0x28(r1)
/* 8006AF1C  E1 65 00 04 */	psq_l f11, 4(r5), 0, qr0
/* 8006AF20  10 27 52 94 */	ps_sum0 f1, f7, f10, f10
/* 8006AF24  D0 C1 00 34 */	stfs f6, 0x34(r1)
/* 8006AF28  E1 25 80 00 */	psq_l f9, 0(r5), 1, qr0
/* 8006AF2C  D0 A1 00 38 */	stfs f5, 0x38(r1)
/* 8006AF30  FC 20 08 50 */	fneg f1, f1
/* 8006AF34  E0 E4 80 00 */	psq_l f7, 0(r4), 1, qr0
/* 8006AF38  D0 81 00 3C */	stfs f4, 0x3c(r1)
/* 8006AF3C  D0 3F 00 0C */	stfs f1, 0xc(r31)
/* 8006AF40  E1 04 00 04 */	psq_l f8, 4(r4), 0, qr0
/* 8006AF44  D0 DF 00 10 */	stfs f6, 0x10(r31)
/* 8006AF48  D0 BF 00 14 */	stfs f5, 0x14(r31)
/* 8006AF4C  D0 9F 00 18 */	stfs f4, 0x18(r31)
/* 8006AF50  E0 9F 00 78 */	psq_l f4, 120(r31), 0, qr0
/* 8006AF54  E0 3F 80 74 */	psq_l f1, 116(r31), 1, qr0
/* 8006AF58  10 84 02 32 */	ps_mul f4, f4, f8
/* 8006AF5C  11 01 21 FA */	ps_madd f8, f1, f7, f4
/* 8006AF60  10 28 21 14 */	ps_sum0 f1, f8, f4, f4
/* 8006AF64  FC 20 08 50 */	fneg f1, f1
/* 8006AF68  D0 3F 00 1C */	stfs f1, 0x1c(r31)
/* 8006AF6C  D0 7F 00 20 */	stfs f3, 0x20(r31)
/* 8006AF70  D0 1F 00 24 */	stfs f0, 0x24(r31)
/* 8006AF74  D0 5F 00 28 */	stfs f2, 0x28(r31)
/* 8006AF78  E0 3F 00 78 */	psq_l f1, 120(r31), 0, qr0
/* 8006AF7C  E0 1F 80 74 */	psq_l f0, 116(r31), 1, qr0
/* 8006AF80  10 21 02 F2 */	ps_mul f1, f1, f11
/* 8006AF84  11 60 0A 7A */	ps_madd f11, f0, f9, f1
/* 8006AF88  10 0B 08 54 */	ps_sum0 f0, f11, f1, f1
/* 8006AF8C  FC 00 00 50 */	fneg f0, f0
/* 8006AF90  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8006AF94  80 1F 00 70 */	lwz r0, 0x70(r31)
/* 8006AF98  60 00 00 08 */	ori r0, r0, 8
/* 8006AF9C  90 1F 00 70 */	stw r0, 0x70(r31)
/* 8006AFA0  E3 E1 00 98 */	psq_l f31, 152(r1), 0, qr0
/* 8006AFA4  CB E1 00 90 */	lfd f31, 0x90(r1)
/* 8006AFA8  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 8006AFAC  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 8006AFB0  7C 08 03 A6 */	mtlr r0
/* 8006AFB4  38 21 00 A0 */	addi r1, r1, 0xa0
/* 8006AFB8  4E 80 00 20 */	blr 
/* 8006AFBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006AFC0  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8006AFC4  7C 08 02 A6 */	mflr r0
/* 8006AFC8  90 01 00 54 */	stw r0, 0x54(r1)
/* 8006AFCC  54 C0 FF 7E */	rlwinm r0, r6, 0x1f, 0x1d, 0x1f
/* 8006AFD0  28 00 00 07 */	cmplwi r0, 7
/* 8006AFD4  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 8006AFD8  7C BF 2B 78 */	mr r31, r5
/* 8006AFDC  93 C1 00 48 */	stw r30, 0x48(r1)
/* 8006AFE0  7C 9E 23 78 */	mr r30, r4
/* 8006AFE4  93 A1 00 44 */	stw r29, 0x44(r1)
/* 8006AFE8  7C 7D 1B 78 */	mr r29, r3
/* 8006AFEC  40 82 00 0C */	bne 0xc
/* 8006AFF0  38 60 00 00 */	li r3, 0
/* 8006AFF4  48 00 01 0C */	b 0x10c
/* 8006AFF8  C0 25 00 08 */	lfs f1, 8(r5)
/* 8006AFFC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B000  C0 02 8D 40 */	lfs f0, -0x72c0(r2)
/* 8006B004  38 81 00 08 */	addi r4, r1, 8
/* 8006B008  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B00C  48 01 A1 D5 */	bl 0x1a1d4
/* 8006B010  2C 1E 00 00 */	cmpwi r30, 0
/* 8006B014  41 82 00 74 */	beq 0x74
/* 8006B018  C0 FF 00 00 */	lfs f7, 0(r31)
/* 8006B01C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006B020  C0 DF 00 04 */	lfs f6, 4(r31)
/* 8006B024  EC 07 00 32 */	fmuls f0, f7, f0
/* 8006B028  C0 62 8D 44 */	lfs f3, -0x72bc(r2)
/* 8006B02C  FC A0 30 50 */	fneg f5, f6
/* 8006B030  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 8006B034  D0 1D 00 00 */	stfs f0, 0(r29)
/* 8006B038  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8006B03C  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006B040  C0 02 8D 48 */	lfs f0, -0x72b8(r2)
/* 8006B044  EC 85 01 32 */	fmuls f4, f5, f4
/* 8006B048  D0 7D 00 08 */	stfs f3, 8(r29)
/* 8006B04C  D0 9D 00 04 */	stfs f4, 4(r29)
/* 8006B050  D0 5D 00 0C */	stfs f2, 0xc(r29)
/* 8006B054  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006B058  EC 47 00 B2 */	fmuls f2, f7, f2
/* 8006B05C  D0 5D 00 10 */	stfs f2, 0x10(r29)
/* 8006B060  C0 41 00 08 */	lfs f2, 8(r1)
/* 8006B064  EC 46 00 B2 */	fmuls f2, f6, f2
/* 8006B068  D0 7D 00 18 */	stfs f3, 0x18(r29)
/* 8006B06C  D0 5D 00 14 */	stfs f2, 0x14(r29)
/* 8006B070  D0 3D 00 1C */	stfs f1, 0x1c(r29)
/* 8006B074  D0 7D 00 20 */	stfs f3, 0x20(r29)
/* 8006B078  D0 7D 00 24 */	stfs f3, 0x24(r29)
/* 8006B07C  D0 1D 00 28 */	stfs f0, 0x28(r29)
/* 8006B080  D0 7D 00 2C */	stfs f3, 0x2c(r29)
/* 8006B084  48 00 00 78 */	b 0x78
/* 8006B088  C0 5F 00 04 */	lfs f2, 4(r31)
/* 8006B08C  7F A4 EB 78 */	mr r4, r29
/* 8006B090  C0 A2 8D 44 */	lfs f5, -0x72bc(r2)
/* 8006B094  7F A5 EB 78 */	mr r5, r29
/* 8006B098  FC 20 10 50 */	fneg f1, f2
/* 8006B09C  C0 61 00 08 */	lfs f3, 8(r1)
/* 8006B0A0  C1 1F 00 00 */	lfs f8, 0(r31)
/* 8006B0A4  38 61 00 10 */	addi r3, r1, 0x10
/* 8006B0A8  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006B0AC  EC 42 00 F2 */	fmuls f2, f2, f3
/* 8006B0B0  EC E8 00 F2 */	fmuls f7, f8, f3
/* 8006B0B4  C0 9F 00 0C */	lfs f4, 0xc(r31)
/* 8006B0B8  EC C1 00 32 */	fmuls f6, f1, f0
/* 8006B0BC  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8006B0C0  EC 68 00 32 */	fmuls f3, f8, f0
/* 8006B0C4  C0 02 8D 48 */	lfs f0, -0x72b8(r2)
/* 8006B0C8  D0 E1 00 10 */	stfs f7, 0x10(r1)
/* 8006B0CC  D0 C1 00 14 */	stfs f6, 0x14(r1)
/* 8006B0D0  D0 A1 00 18 */	stfs f5, 0x18(r1)
/* 8006B0D4  D0 81 00 1C */	stfs f4, 0x1c(r1)
/* 8006B0D8  D0 61 00 20 */	stfs f3, 0x20(r1)
/* 8006B0DC  D0 41 00 24 */	stfs f2, 0x24(r1)
/* 8006B0E0  D0 A1 00 28 */	stfs f5, 0x28(r1)
/* 8006B0E4  D0 21 00 2C */	stfs f1, 0x2c(r1)
/* 8006B0E8  D0 A1 00 30 */	stfs f5, 0x30(r1)
/* 8006B0EC  D0 A1 00 34 */	stfs f5, 0x34(r1)
/* 8006B0F0  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 8006B0F4  D0 A1 00 3C */	stfs f5, 0x3c(r1)
/* 8006B0F8  48 12 EC 6D */	bl 0x12ec6c
/* 8006B0FC  38 60 00 01 */	li r3, 1
/* 8006B100  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8006B104  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 8006B108  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 8006B10C  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 8006B110  7C 08 03 A6 */	mtlr r0
/* 8006B114  38 21 00 50 */	addi r1, r1, 0x50
/* 8006B118  4E 80 00 20 */	blr 
/* 8006B11C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B120  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8006B124  7C 08 02 A6 */	mflr r0
/* 8006B128  90 01 00 64 */	stw r0, 0x64(r1)
/* 8006B12C  39 61 00 60 */	addi r11, r1, 0x60
/* 8006B130  4B FB 64 6D */	bl -0x49b94
/* 8006B134  83 E8 00 00 */	lwz r31, 0(r8)
/* 8006B138  7C 7A 1B 78 */	mr r26, r3
/* 8006B13C  7C 9B 23 78 */	mr r27, r4
/* 8006B140  7C BC 2B 78 */	mr r28, r5
/* 8006B144  57 E0 07 BD */	rlwinm. r0, r31, 0, 0x1e, 0x1e
/* 8006B148  7C FD 3B 78 */	mr r29, r7
/* 8006B14C  7D 1E 43 78 */	mr r30, r8
/* 8006B150  40 82 00 0C */	bne 0xc
/* 8006B154  57 E0 07 7B */	rlwinm. r0, r31, 0, 0x1d, 0x1d
/* 8006B158  41 82 00 30 */	beq 0x30
/* 8006B15C  54 E0 00 43 */	rlwinm. r0, r7, 0, 1, 1
/* 8006B160  41 82 00 14 */	beq 0x14
/* 8006B164  7F 83 E3 78 */	mr r3, r28
/* 8006B168  7F 44 D3 78 */	mr r4, r26
/* 8006B16C  48 12 EB C5 */	bl 0x12ebc4
/* 8006B170  48 00 00 B4 */	b 0xb4
/* 8006B174  7F 43 D3 78 */	mr r3, r26
/* 8006B178  7F 84 E3 78 */	mr r4, r28
/* 8006B17C  7C C5 33 78 */	mr r5, r6
/* 8006B180  48 01 A6 31 */	bl 0x1a630
/* 8006B184  48 00 00 A0 */	b 0xa0
/* 8006B188  57 E0 06 B5 */	rlwinm. r0, r31, 0, 0x1a, 0x1a
/* 8006B18C  41 82 00 60 */	beq 0x60
/* 8006B190  54 E0 00 43 */	rlwinm. r0, r7, 0, 1, 1
/* 8006B194  41 82 00 2C */	beq 0x2c
/* 8006B198  C0 48 00 48 */	lfs f2, 0x48(r8)
/* 8006B19C  7F 84 E3 78 */	mr r4, r28
/* 8006B1A0  C0 28 00 38 */	lfs f1, 0x38(r8)
/* 8006B1A4  38 A1 00 08 */	addi r5, r1, 8
/* 8006B1A8  C0 08 00 28 */	lfs f0, 0x28(r8)
/* 8006B1AC  D0 01 00 08 */	stfs f0, 8(r1)
/* 8006B1B0  D0 21 00 0C */	stfs f1, 0xc(r1)
/* 8006B1B4  D0 41 00 10 */	stfs f2, 0x10(r1)
/* 8006B1B8  48 01 A6 59 */	bl 0x1a658
/* 8006B1BC  48 00 00 68 */	b 0x68
/* 8006B1C0  C0 26 00 00 */	lfs f1, 0(r6)
/* 8006B1C4  38 68 00 1C */	addi r3, r8, 0x1c
/* 8006B1C8  C0 46 00 04 */	lfs f2, 4(r6)
/* 8006B1CC  38 81 00 18 */	addi r4, r1, 0x18
/* 8006B1D0  C0 66 00 08 */	lfs f3, 8(r6)
/* 8006B1D4  48 12 F2 B5 */	bl 0x12f2b4
/* 8006B1D8  7F 83 E3 78 */	mr r3, r28
/* 8006B1DC  7F 45 D3 78 */	mr r5, r26
/* 8006B1E0  38 81 00 18 */	addi r4, r1, 0x18
/* 8006B1E4  48 12 EB 81 */	bl 0x12eb80
/* 8006B1E8  48 00 00 3C */	b 0x3c
/* 8006B1EC  54 E0 00 43 */	rlwinm. r0, r7, 0, 1, 1
/* 8006B1F0  41 82 00 18 */	beq 0x18
/* 8006B1F4  7F 83 E3 78 */	mr r3, r28
/* 8006B1F8  7F 45 D3 78 */	mr r5, r26
/* 8006B1FC  38 88 00 1C */	addi r4, r8, 0x1c
/* 8006B200  48 12 EB 65 */	bl 0x12eb64
/* 8006B204  48 00 00 20 */	b 0x20
/* 8006B208  7F 84 E3 78 */	mr r4, r28
/* 8006B20C  7C C5 33 78 */	mr r5, r6
/* 8006B210  48 01 A5 A1 */	bl 0x1a5a0
/* 8006B214  7F 43 D3 78 */	mr r3, r26
/* 8006B218  7F 45 D3 78 */	mr r5, r26
/* 8006B21C  38 9E 00 1C */	addi r4, r30, 0x1c
/* 8006B220  48 12 EB 45 */	bl 0x12eb44
/* 8006B224  57 E0 07 39 */	rlwinm. r0, r31, 0, 0x1c, 0x1c
/* 8006B228  41 82 00 1C */	beq 0x1c
/* 8006B22C  C0 02 8D 48 */	lfs f0, -0x72b8(r2)
/* 8006B230  67 A4 40 00 */	oris r4, r29, 0x4000
/* 8006B234  D0 1B 00 08 */	stfs f0, 8(r27)
/* 8006B238  D0 1B 00 04 */	stfs f0, 4(r27)
/* 8006B23C  D0 1B 00 00 */	stfs f0, 0(r27)
/* 8006B240  48 00 00 20 */	b 0x20
/* 8006B244  C0 1E 00 04 */	lfs f0, 4(r30)
/* 8006B248  57 A4 00 BE */	clrlwi r4, r29, 2
/* 8006B24C  D0 1B 00 00 */	stfs f0, 0(r27)
/* 8006B250  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8006B254  D0 1B 00 04 */	stfs f0, 4(r27)
/* 8006B258  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 8006B25C  D0 1B 00 08 */	stfs f0, 8(r27)
/* 8006B260  57 E0 06 F7 */	rlwinm. r0, r31, 0, 0x1b, 0x1b
/* 8006B264  54 83 01 3E */	clrlwi r3, r4, 4
/* 8006B268  41 82 00 08 */	beq 0x8
/* 8006B26C  64 83 10 00 */	oris r3, r4, 0x1000
/* 8006B270  39 61 00 60 */	addi r11, r1, 0x60
/* 8006B274  4B FB 63 75 */	bl -0x49c8c
/* 8006B278  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8006B27C  7C 08 03 A6 */	mtlr r0
/* 8006B280  38 21 00 60 */	addi r1, r1, 0x60
/* 8006B284  4E 80 00 20 */	blr 
/* 8006B288  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B28C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B290  C0 24 00 04 */	lfs f1, 4(r4)
/* 8006B294  C0 02 8D 54 */	lfs f0, -0x72ac(r2)
/* 8006B298  C0 42 8D 50 */	lfs f2, -0x72b0(r2)
/* 8006B29C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006B2A0  C0 64 00 00 */	lfs f3, 0(r4)
/* 8006B2A4  D0 63 00 00 */	stfs f3, 0(r3)
/* 8006B2A8  D0 43 00 04 */	stfs f2, 4(r3)
/* 8006B2AC  D0 43 00 08 */	stfs f2, 8(r3)
/* 8006B2B0  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006B2B4  D0 43 00 10 */	stfs f2, 0x10(r3)
/* 8006B2B8  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8006B2BC  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006B2C0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006B2C4  4E 80 00 20 */	blr 
/* 8006B2C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B2CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B2D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006B2D4  7C 08 02 A6 */	mflr r0
/* 8006B2D8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B2DC  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B2E0  38 81 00 08 */	addi r4, r1, 8
/* 8006B2E4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006B2E8  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B2EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B2F0  7C 7F 1B 78 */	mr r31, r3
/* 8006B2F4  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B2F8  48 01 9E E9 */	bl 0x19ee8
/* 8006B2FC  C0 82 8D 5C */	lfs f4, -0x72a4(r2)
/* 8006B300  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006B304  C0 61 00 0C */	lfs f3, 0xc(r1)
/* 8006B308  EC 04 00 72 */	fmuls f0, f4, f1
/* 8006B30C  C0 42 8D 50 */	lfs f2, -0x72b0(r2)
/* 8006B310  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8006B314  D0 3F 00 00 */	stfs f1, 0(r31)
/* 8006B318  EC 84 00 28 */	fsubs f4, f4, f0
/* 8006B31C  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006B320  D0 1F 00 04 */	stfs f0, 4(r31)
/* 8006B324  EC 24 18 28 */	fsubs f1, f4, f3
/* 8006B328  D0 5F 00 08 */	stfs f2, 8(r31)
/* 8006B32C  EC 04 18 2A */	fadds f0, f4, f3
/* 8006B330  D0 3F 00 0C */	stfs f1, 0xc(r31)
/* 8006B334  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006B338  FC 20 08 50 */	fneg f1, f1
/* 8006B33C  D0 3F 00 10 */	stfs f1, 0x10(r31)
/* 8006B340  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006B344  D0 3F 00 14 */	stfs f1, 0x14(r31)
/* 8006B348  D0 5F 00 18 */	stfs f2, 0x18(r31)
/* 8006B34C  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006B350  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006B354  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006B358  7C 08 03 A6 */	mtlr r0
/* 8006B35C  38 21 00 20 */	addi r1, r1, 0x20
/* 8006B360  4E 80 00 20 */	blr 
/* 8006B364  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B368  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B36C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B370  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 8006B374  C0 42 8D 50 */	lfs f2, -0x72b0(r2)
/* 8006B378  FC 20 00 50 */	fneg f1, f0
/* 8006B37C  C0 62 8D 54 */	lfs f3, -0x72ac(r2)
/* 8006B380  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006B384  D0 63 00 00 */	stfs f3, 0(r3)
/* 8006B388  D0 43 00 04 */	stfs f2, 4(r3)
/* 8006B38C  D0 43 00 08 */	stfs f2, 8(r3)
/* 8006B390  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 8006B394  D0 43 00 10 */	stfs f2, 0x10(r3)
/* 8006B398  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006B39C  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006B3A0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006B3A4  4E 80 00 20 */	blr 
/* 8006B3A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B3AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B3B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006B3B4  7C 08 02 A6 */	mflr r0
/* 8006B3B8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B3BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006B3C0  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B3C4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B3C8  7C 9F 23 78 */	mr r31, r4
/* 8006B3CC  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B3D0  38 81 00 08 */	addi r4, r1, 8
/* 8006B3D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006B3D8  7C 7E 1B 78 */	mr r30, r3
/* 8006B3DC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B3E0  48 01 9E 01 */	bl 0x19e00
/* 8006B3E4  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006B3E8  C0 FF 00 04 */	lfs f7, 4(r31)
/* 8006B3EC  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006B3F0  C1 1F 00 00 */	lfs f8, 0(r31)
/* 8006B3F4  ED 67 00 72 */	fmuls f11, f7, f1
/* 8006B3F8  EC 67 00 32 */	fmuls f3, f7, f0
/* 8006B3FC  C0 C2 8D 50 */	lfs f6, -0x72b0(r2)
/* 8006B400  ED 28 00 72 */	fmuls f9, f8, f1
/* 8006B404  C0 22 8D 5C */	lfs f1, -0x72a4(r2)
/* 8006B408  ED 48 00 32 */	fmuls f10, f8, f0
/* 8006B40C  EC 43 58 28 */	fsubs f2, f3, f11
/* 8006B410  FC 60 18 50 */	fneg f3, f3
/* 8006B414  C0 82 8D 60 */	lfs f4, -0x72a0(r2)
/* 8006B418  EC AA 48 2A */	fadds f5, f10, f9
/* 8006B41C  C0 02 8D 54 */	lfs f0, -0x72ac(r2)
/* 8006B420  EC 42 38 28 */	fsubs f2, f2, f7
/* 8006B424  D1 3E 00 00 */	stfs f9, 0(r30)
/* 8006B428  EC A5 40 28 */	fsubs f5, f5, f8
/* 8006B42C  EC 21 00 B2 */	fmuls f1, f1, f2
/* 8006B430  D1 5E 00 04 */	stfs f10, 4(r30)
/* 8006B434  EC 44 01 72 */	fmuls f2, f4, f5
/* 8006B438  D0 DE 00 08 */	stfs f6, 8(r30)
/* 8006B43C  EC 00 08 2A */	fadds f0, f0, f1
/* 8006B440  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 8006B444  D0 7E 00 10 */	stfs f3, 0x10(r30)
/* 8006B448  D1 7E 00 14 */	stfs f11, 0x14(r30)
/* 8006B44C  D0 DE 00 18 */	stfs f6, 0x18(r30)
/* 8006B450  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006B454  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006B458  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006B45C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006B460  7C 08 03 A6 */	mtlr r0
/* 8006B464  38 21 00 20 */	addi r1, r1, 0x20
/* 8006B468  4E 80 00 20 */	blr 
/* 8006B46C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B470  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006B474  7C 08 02 A6 */	mflr r0
/* 8006B478  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B47C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006B480  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B484  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B488  7C 9F 23 78 */	mr r31, r4
/* 8006B48C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B490  38 81 00 08 */	addi r4, r1, 8
/* 8006B494  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006B498  7C 7E 1B 78 */	mr r30, r3
/* 8006B49C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B4A0  48 01 9D 41 */	bl 0x19d40
/* 8006B4A4  C0 A2 8D 5C */	lfs f5, -0x72a4(r2)
/* 8006B4A8  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006B4AC  C0 61 00 0C */	lfs f3, 0xc(r1)
/* 8006B4B0  EC 05 00 72 */	fmuls f0, f5, f1
/* 8006B4B4  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 8006B4B8  D0 3E 00 00 */	stfs f1, 0(r30)
/* 8006B4BC  EC 25 00 F2 */	fmuls f1, f5, f3
/* 8006B4C0  C0 82 8D 50 */	lfs f4, -0x72b0(r2)
/* 8006B4C4  EC A5 00 28 */	fsubs f5, f5, f0
/* 8006B4C8  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006B4CC  D0 1E 00 04 */	stfs f0, 4(r30)
/* 8006B4D0  EC 65 08 28 */	fsubs f3, f5, f1
/* 8006B4D4  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8006B4D8  EC 25 08 2A */	fadds f1, f5, f1
/* 8006B4DC  D0 9E 00 08 */	stfs f4, 8(r30)
/* 8006B4E0  EC 43 10 28 */	fsubs f2, f3, f2
/* 8006B4E4  EC 00 08 2A */	fadds f0, f0, f1
/* 8006B4E8  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 8006B4EC  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006B4F0  FC 20 08 50 */	fneg f1, f1
/* 8006B4F4  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 8006B4F8  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006B4FC  D0 3E 00 14 */	stfs f1, 0x14(r30)
/* 8006B500  D0 9E 00 18 */	stfs f4, 0x18(r30)
/* 8006B504  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006B508  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006B50C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006B510  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006B514  7C 08 03 A6 */	mtlr r0
/* 8006B518  38 21 00 20 */	addi r1, r1, 0x20
/* 8006B51C  4E 80 00 20 */	blr 
/* 8006B520  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006B524  C0 22 8D 54 */	lfs f1, -0x72ac(r2)
/* 8006B528  C0 A2 8D 50 */	lfs f5, -0x72b0(r2)
/* 8006B52C  C0 C4 00 00 */	lfs f6, 0(r4)
/* 8006B530  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006B534  C0 44 00 04 */	lfs f2, 4(r4)
/* 8006B538  FC 80 30 50 */	fneg f4, f6
/* 8006B53C  C0 64 00 0C */	lfs f3, 0xc(r4)
/* 8006B540  EC 02 00 32 */	fmuls f0, f2, f0
/* 8006B544  D0 C3 00 00 */	stfs f6, 0(r3)
/* 8006B548  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8006B54C  D0 A3 00 04 */	stfs f5, 4(r3)
/* 8006B550  EC 01 00 2A */	fadds f0, f1, f0
/* 8006B554  D0 A3 00 08 */	stfs f5, 8(r3)
/* 8006B558  D0 63 00 0C */	stfs f3, 0xc(r3)
/* 8006B55C  D0 A3 00 10 */	stfs f5, 0x10(r3)
/* 8006B560  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 8006B564  D0 A3 00 18 */	stfs f5, 0x18(r3)
/* 8006B568  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006B56C  4E 80 00 20 */	blr 
/* 8006B570  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006B574  7C 08 02 A6 */	mflr r0
/* 8006B578  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B57C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006B580  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B584  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B588  7C 9F 23 78 */	mr r31, r4
/* 8006B58C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B590  38 81 00 08 */	addi r4, r1, 8
/* 8006B594  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006B598  7C 7E 1B 78 */	mr r30, r3
/* 8006B59C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B5A0  48 01 9C 41 */	bl 0x19c40
/* 8006B5A4  C0 A2 8D 5C */	lfs f5, -0x72a4(r2)
/* 8006B5A8  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006B5AC  C0 9F 00 04 */	lfs f4, 4(r31)
/* 8006B5B0  EC 45 00 32 */	fmuls f2, f5, f0
/* 8006B5B4  C0 22 8D 60 */	lfs f1, -0x72a0(r2)
/* 8006B5B8  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006B5BC  FC 60 20 50 */	fneg f3, f4
/* 8006B5C0  C1 3F 00 00 */	lfs f9, 0(r31)
/* 8006B5C4  ED 01 00 32 */	fmuls f8, f1, f0
/* 8006B5C8  EC 42 28 28 */	fsubs f2, f2, f5
/* 8006B5CC  C0 BF 00 0C */	lfs f5, 0xc(r31)
/* 8006B5D0  EC 09 00 32 */	fmuls f0, f9, f0
/* 8006B5D4  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8006B5D8  C0 E2 8D 50 */	lfs f7, -0x72b0(r2)
/* 8006B5DC  EC C8 10 28 */	fsubs f6, f8, f2
/* 8006B5E0  EC 48 10 2A */	fadds f2, f8, f2
/* 8006B5E4  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8006B5E8  C0 02 8D 54 */	lfs f0, -0x72ac(r2)
/* 8006B5EC  C1 01 00 0C */	lfs f8, 0xc(r1)
/* 8006B5F0  EC A6 28 28 */	fsubs f5, f6, f5
/* 8006B5F4  EC 21 10 2A */	fadds f1, f1, f2
/* 8006B5F8  EC C9 02 32 */	fmuls f6, f9, f8
/* 8006B5FC  D0 FE 00 08 */	stfs f7, 8(r30)
/* 8006B600  EC 49 01 72 */	fmuls f2, f9, f5
/* 8006B604  EC 24 00 72 */	fmuls f1, f4, f1
/* 8006B608  D0 DE 00 04 */	stfs f6, 4(r30)
/* 8006B60C  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 8006B610  EC 00 08 2A */	fadds f0, f0, f1
/* 8006B614  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006B618  EC 23 00 72 */	fmuls f1, f3, f1
/* 8006B61C  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 8006B620  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006B624  EC 24 00 72 */	fmuls f1, f4, f1
/* 8006B628  D0 FE 00 18 */	stfs f7, 0x18(r30)
/* 8006B62C  D0 3E 00 14 */	stfs f1, 0x14(r30)
/* 8006B630  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006B634  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006B638  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006B63C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006B640  7C 08 03 A6 */	mtlr r0
/* 8006B644  38 21 00 20 */	addi r1, r1, 0x20
/* 8006B648  4E 80 00 20 */	blr 
/* 8006B64C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B650  C0 A4 00 04 */	lfs f5, 4(r4)
/* 8006B654  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 8006B658  C0 43 00 10 */	lfs f2, 0x10(r3)
/* 8006B65C  EC 20 01 72 */	fmuls f1, f0, f5
/* 8006B660  C0 02 8D 54 */	lfs f0, -0x72ac(r2)
/* 8006B664  EC 82 01 72 */	fmuls f4, f2, f5
/* 8006B668  C0 43 00 18 */	lfs f2, 0x18(r3)
/* 8006B66C  C0 63 00 14 */	lfs f3, 0x14(r3)
/* 8006B670  EC 00 08 2A */	fadds f0, f0, f1
/* 8006B674  EC 22 01 72 */	fmuls f1, f2, f5
/* 8006B678  C1 03 00 00 */	lfs f8, 0(r3)
/* 8006B67C  C1 24 00 00 */	lfs f9, 0(r4)
/* 8006B680  EC 63 01 72 */	fmuls f3, f3, f5
/* 8006B684  C0 E3 00 04 */	lfs f7, 4(r3)
/* 8006B688  C0 C3 00 08 */	lfs f6, 8(r3)
/* 8006B68C  C0 43 00 0C */	lfs f2, 0xc(r3)
/* 8006B690  ED 08 02 72 */	fmuls f8, f8, f9
/* 8006B694  EC E7 02 72 */	fmuls f7, f7, f9
/* 8006B698  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8006B69C  EC C6 02 72 */	fmuls f6, f6, f9
/* 8006B6A0  EC 42 02 72 */	fmuls f2, f2, f9
/* 8006B6A4  D1 03 00 00 */	stfs f8, 0(r3)
/* 8006B6A8  EC 00 28 28 */	fsubs f0, f0, f5
/* 8006B6AC  D0 E3 00 04 */	stfs f7, 4(r3)
/* 8006B6B0  D0 C3 00 08 */	stfs f6, 8(r3)
/* 8006B6B4  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006B6B8  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006B6BC  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 8006B6C0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006B6C4  4E 80 00 20 */	blr 
/* 8006B6C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B6CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B6D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006B6D4  7C 08 02 A6 */	mflr r0
/* 8006B6D8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B6DC  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B6E0  38 81 00 08 */	addi r4, r1, 8
/* 8006B6E4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006B6E8  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B6EC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B6F0  7C 7F 1B 78 */	mr r31, r3
/* 8006B6F4  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B6F8  48 01 9A E9 */	bl 0x19ae8
/* 8006B6FC  C1 41 00 0C */	lfs f10, 0xc(r1)
/* 8006B700  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8006B704  FC 20 50 50 */	fneg f1, f10
/* 8006B708  C0 9F 00 00 */	lfs f4, 0(r31)
/* 8006B70C  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006B710  EC 4A 00 32 */	fmuls f2, f10, f0
/* 8006B714  C1 82 8D 5C */	lfs f12, -0x72a4(r2)
/* 8006B718  EC 65 01 32 */	fmuls f3, f5, f4
/* 8006B71C  EC 21 01 32 */	fmuls f1, f1, f4
/* 8006B720  C1 7F 00 04 */	lfs f11, 4(r31)
/* 8006B724  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006B728  C1 1F 00 14 */	lfs f8, 0x14(r31)
/* 8006B72C  EC 43 10 2A */	fadds f2, f3, f2
/* 8006B730  EC 8C 01 72 */	fmuls f4, f12, f5
/* 8006B734  EC 01 00 2A */	fadds f0, f1, f0
/* 8006B738  D0 5F 00 00 */	stfs f2, 0(r31)
/* 8006B73C  C1 3F 00 08 */	lfs f9, 8(r31)
/* 8006B740  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8006B744  EC 2C 20 28 */	fsubs f1, f12, f4
/* 8006B748  EC 0C 02 B2 */	fmuls f0, f12, f10
/* 8006B74C  C0 61 00 0C */	lfs f3, 0xc(r1)
/* 8006B750  C1 81 00 08 */	lfs f12, 8(r1)
/* 8006B754  FC 40 18 50 */	fneg f2, f3
/* 8006B758  C0 DF 00 18 */	lfs f6, 0x18(r31)
/* 8006B75C  EC 83 02 32 */	fmuls f4, f3, f8
/* 8006B760  C0 FF 00 0C */	lfs f7, 0xc(r31)
/* 8006B764  ED 4C 02 F2 */	fmuls f10, f12, f11
/* 8006B768  C0 BF 00 1C */	lfs f5, 0x1c(r31)
/* 8006B76C  EC 62 02 F2 */	fmuls f3, f2, f11
/* 8006B770  EC 4C 02 32 */	fmuls f2, f12, f8
/* 8006B774  EC 8A 20 2A */	fadds f4, f10, f4
/* 8006B778  EC 43 10 2A */	fadds f2, f3, f2
/* 8006B77C  D0 9F 00 04 */	stfs f4, 4(r31)
/* 8006B780  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 8006B784  C0 61 00 0C */	lfs f3, 0xc(r1)
/* 8006B788  C1 41 00 08 */	lfs f10, 8(r1)
/* 8006B78C  FC 40 18 50 */	fneg f2, f3
/* 8006B790  EC 83 01 B2 */	fmuls f4, f3, f6
/* 8006B794  ED 0A 02 72 */	fmuls f8, f10, f9
/* 8006B798  EC 62 02 72 */	fmuls f3, f2, f9
/* 8006B79C  EC 4A 01 B2 */	fmuls f2, f10, f6
/* 8006B7A0  EC 88 20 2A */	fadds f4, f8, f4
/* 8006B7A4  EC 43 10 2A */	fadds f2, f3, f2
/* 8006B7A8  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8006B7AC  D0 5F 00 18 */	stfs f2, 0x18(r31)
/* 8006B7B0  C0 61 00 0C */	lfs f3, 0xc(r1)
/* 8006B7B4  C1 01 00 08 */	lfs f8, 8(r1)
/* 8006B7B8  FC 40 18 50 */	fneg f2, f3
/* 8006B7BC  EC 83 01 72 */	fmuls f4, f3, f5
/* 8006B7C0  EC C8 01 F2 */	fmuls f6, f8, f7
/* 8006B7C4  EC 62 01 F2 */	fmuls f3, f2, f7
/* 8006B7C8  EC 48 01 72 */	fmuls f2, f8, f5
/* 8006B7CC  EC 86 20 2A */	fadds f4, f6, f4
/* 8006B7D0  EC 43 10 2A */	fadds f2, f3, f2
/* 8006B7D4  EC 61 20 2A */	fadds f3, f1, f4
/* 8006B7D8  EC 21 10 2A */	fadds f1, f1, f2
/* 8006B7DC  EC 43 00 28 */	fsubs f2, f3, f0
/* 8006B7E0  EC 00 08 2A */	fadds f0, f0, f1
/* 8006B7E4  D0 5F 00 0C */	stfs f2, 0xc(r31)
/* 8006B7E8  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006B7EC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006B7F0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006B7F4  7C 08 03 A6 */	mtlr r0
/* 8006B7F8  38 21 00 20 */	addi r1, r1, 0x20
/* 8006B7FC  4E 80 00 20 */	blr 
/* 8006B800  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 8006B804  C0 43 00 0C */	lfs f2, 0xc(r3)
/* 8006B808  FC 60 00 50 */	fneg f3, f0
/* 8006B80C  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 8006B810  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006B814  EC 42 18 2A */	fadds f2, f2, f3
/* 8006B818  EC 01 00 2A */	fadds f0, f1, f0
/* 8006B81C  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006B820  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006B824  4E 80 00 20 */	blr 
/* 8006B828  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B82C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B830  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 8006B834  7C 08 02 A6 */	mflr r0
/* 8006B838  90 01 00 84 */	stw r0, 0x84(r1)
/* 8006B83C  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 8006B840  F3 E1 00 78 */	psq_st f31, 120(r1), 0, qr0
/* 8006B844  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 8006B848  F3 C1 00 68 */	psq_st f30, 104(r1), 0, qr0
/* 8006B84C  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 8006B850  F3 A1 00 58 */	psq_st f29, 88(r1), 0, qr0
/* 8006B854  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 8006B858  F3 81 00 48 */	psq_st f28, 72(r1), 0, qr0
/* 8006B85C  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 8006B860  F3 61 00 38 */	psq_st f27, 56(r1), 0, qr0
/* 8006B864  DB 41 00 20 */	stfd f26, 0x20(r1)
/* 8006B868  F3 41 00 28 */	psq_st f26, 40(r1), 0, qr0
/* 8006B86C  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B870  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B874  7C 9F 23 78 */	mr r31, r4
/* 8006B878  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B87C  38 81 00 08 */	addi r4, r1, 8
/* 8006B880  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006B884  7C 7E 1B 78 */	mr r30, r3
/* 8006B888  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B88C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006B890  48 01 99 51 */	bl 0x19950
/* 8006B894  C0 C1 00 0C */	lfs f6, 0xc(r1)
/* 8006B898  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8006B89C  C0 E1 00 08 */	lfs f7, 8(r1)
/* 8006B8A0  ED 00 01 B2 */	fmuls f8, f0, f6
/* 8006B8A4  C1 42 8D 5C */	lfs f10, -0x72a4(r2)
/* 8006B8A8  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 8006B8AC  EC 60 01 F2 */	fmuls f3, f0, f7
/* 8006B8B0  C0 5E 00 0C */	lfs f2, 0xc(r30)
/* 8006B8B4  EC AA 00 32 */	fmuls f5, f10, f0
/* 8006B8B8  FF C0 40 50 */	fneg f30, f8
/* 8006B8BC  C0 1F 00 00 */	lfs f0, 0(r31)
/* 8006B8C0  EC 81 50 28 */	fsubs f4, f1, f10
/* 8006B8C4  C3 5E 00 00 */	lfs f26, 0(r30)
/* 8006B8C8  ED 02 50 28 */	fsubs f8, f2, f10
/* 8006B8CC  C3 9E 00 10 */	lfs f28, 0x10(r30)
/* 8006B8D0  EC 20 01 F2 */	fmuls f1, f0, f7
/* 8006B8D4  C3 FE 00 04 */	lfs f31, 4(r30)
/* 8006B8D8  EC 40 01 B2 */	fmuls f2, f0, f6
/* 8006B8DC  C1 BE 00 14 */	lfs f13, 0x14(r30)
/* 8006B8E0  EC FE 02 32 */	fmuls f7, f30, f8
/* 8006B8E4  C1 9E 00 08 */	lfs f12, 8(r30)
/* 8006B8E8  EC C3 01 32 */	fmuls f6, f3, f4
/* 8006B8EC  C1 7E 00 18 */	lfs f11, 0x18(r30)
/* 8006B8F0  ED 21 02 32 */	fmuls f9, f1, f8
/* 8006B8F4  ED 02 01 32 */	fmuls f8, f2, f4
/* 8006B8F8  C0 82 8D 54 */	lfs f4, -0x72ac(r2)
/* 8006B8FC  EC C7 30 2A */	fadds f6, f7, f6
/* 8006B900  EC FE 06 B2 */	fmuls f7, f30, f26
/* 8006B904  EF 61 06 B2 */	fmuls f27, f1, f26
/* 8006B908  EC A6 28 28 */	fsubs f5, f6, f5
/* 8006B90C  EC C3 07 32 */	fmuls f6, f3, f28
/* 8006B910  EF A2 07 32 */	fmuls f29, f2, f28
/* 8006B914  EF 44 28 2A */	fadds f26, f4, f5
/* 8006B918  EC 87 30 2A */	fadds f4, f7, f6
/* 8006B91C  EF 7B E8 2A */	fadds f27, f27, f29
/* 8006B920  D3 5E 00 1C */	stfs f26, 0x1c(r30)
/* 8006B924  EC E1 07 F2 */	fmuls f7, f1, f31
/* 8006B928  EC A2 03 72 */	fmuls f5, f2, f13
/* 8006B92C  D0 9E 00 10 */	stfs f4, 0x10(r30)
/* 8006B930  EC DE 07 F2 */	fmuls f6, f30, f31
/* 8006B934  EC 83 03 72 */	fmuls f4, f3, f13
/* 8006B938  D3 7E 00 00 */	stfs f27, 0(r30)
/* 8006B93C  EC E7 28 2A */	fadds f7, f7, f5
/* 8006B940  EC A1 03 32 */	fmuls f5, f1, f12
/* 8006B944  EC C6 20 2A */	fadds f6, f6, f4
/* 8006B948  D0 FE 00 04 */	stfs f7, 4(r30)
/* 8006B94C  EC 22 02 F2 */	fmuls f1, f2, f11
/* 8006B950  EC 43 02 F2 */	fmuls f2, f3, f11
/* 8006B954  D0 DE 00 14 */	stfs f6, 0x14(r30)
/* 8006B958  EC 9E 03 32 */	fmuls f4, f30, f12
/* 8006B95C  EC 65 08 2A */	fadds f3, f5, f1
/* 8006B960  EC 2A 00 32 */	fmuls f1, f10, f0
/* 8006B964  EC 09 40 2A */	fadds f0, f9, f8
/* 8006B968  D0 7E 00 08 */	stfs f3, 8(r30)
/* 8006B96C  EC 44 10 2A */	fadds f2, f4, f2
/* 8006B970  EC 01 00 2A */	fadds f0, f1, f0
/* 8006B974  D0 5E 00 18 */	stfs f2, 0x18(r30)
/* 8006B978  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8006B97C  E3 E1 00 78 */	psq_l f31, 120(r1), 0, qr0
/* 8006B980  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 8006B984  E3 C1 00 68 */	psq_l f30, 104(r1), 0, qr0
/* 8006B988  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 8006B98C  E3 A1 00 58 */	psq_l f29, 88(r1), 0, qr0
/* 8006B990  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 8006B994  E3 81 00 48 */	psq_l f28, 72(r1), 0, qr0
/* 8006B998  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 8006B99C  E3 61 00 38 */	psq_l f27, 56(r1), 0, qr0
/* 8006B9A0  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 8006B9A4  E3 41 00 28 */	psq_l f26, 40(r1), 0, qr0
/* 8006B9A8  CB 41 00 20 */	lfd f26, 0x20(r1)
/* 8006B9AC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006B9B0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006B9B4  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8006B9B8  7C 08 03 A6 */	mtlr r0
/* 8006B9BC  38 21 00 80 */	addi r1, r1, 0x80
/* 8006B9C0  4E 80 00 20 */	blr 
/* 8006B9C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B9C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B9CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006B9D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006B9D4  7C 08 02 A6 */	mflr r0
/* 8006B9D8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006B9DC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006B9E0  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006B9E4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006B9E8  7C 9F 23 78 */	mr r31, r4
/* 8006B9EC  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006B9F0  38 81 00 08 */	addi r4, r1, 8
/* 8006B9F4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006B9F8  7C 7E 1B 78 */	mr r30, r3
/* 8006B9FC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006BA00  48 01 97 E1 */	bl 0x197e0
/* 8006BA04  C0 E1 00 0C */	lfs f7, 0xc(r1)
/* 8006BA08  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 8006BA0C  FC 20 38 50 */	fneg f1, f7
/* 8006BA10  C0 9E 00 00 */	lfs f4, 0(r30)
/* 8006BA14  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006BA18  EC 47 00 32 */	fmuls f2, f7, f0
/* 8006BA1C  C1 22 8D 5C */	lfs f9, -0x72a4(r2)
/* 8006BA20  EC 65 01 32 */	fmuls f3, f5, f4
/* 8006BA24  EC 21 01 32 */	fmuls f1, f1, f4
/* 8006BA28  C0 C2 8D 60 */	lfs f6, -0x72a0(r2)
/* 8006BA2C  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006BA30  C0 9E 00 04 */	lfs f4, 4(r30)
/* 8006BA34  EC 43 10 2A */	fadds f2, f3, f2
/* 8006BA38  C1 5E 00 14 */	lfs f10, 0x14(r30)
/* 8006BA3C  EC 01 00 2A */	fadds f0, f1, f0
/* 8006BA40  D0 5E 00 00 */	stfs f2, 0(r30)
/* 8006BA44  EC 26 01 72 */	fmuls f1, f6, f5
/* 8006BA48  C1 7E 00 08 */	lfs f11, 8(r30)
/* 8006BA4C  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 8006BA50  EC E9 01 F2 */	fmuls f7, f9, f7
/* 8006BA54  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006BA58  C1 A1 00 08 */	lfs f13, 8(r1)
/* 8006BA5C  EC 07 48 28 */	fsubs f0, f7, f9
/* 8006BA60  FC 60 10 50 */	fneg f3, f2
/* 8006BA64  C1 1E 00 18 */	lfs f8, 0x18(r30)
/* 8006BA68  ED 8D 01 32 */	fmuls f12, f13, f4
/* 8006BA6C  C1 3E 00 0C */	lfs f9, 0xc(r30)
/* 8006BA70  EC C2 02 B2 */	fmuls f6, f2, f10
/* 8006BA74  EC 83 01 32 */	fmuls f4, f3, f4
/* 8006BA78  EC 6D 02 B2 */	fmuls f3, f13, f10
/* 8006BA7C  C0 FE 00 1C */	lfs f7, 0x1c(r30)
/* 8006BA80  EC CC 30 2A */	fadds f6, f12, f6
/* 8006BA84  C0 BF 00 0C */	lfs f5, 0xc(r31)
/* 8006BA88  C0 5F 00 10 */	lfs f2, 0x10(r31)
/* 8006BA8C  EC 64 18 2A */	fadds f3, f4, f3
/* 8006BA90  D0 DE 00 04 */	stfs f6, 4(r30)
/* 8006BA94  D0 7E 00 14 */	stfs f3, 0x14(r30)
/* 8006BA98  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006BA9C  C1 81 00 08 */	lfs f12, 8(r1)
/* 8006BAA0  FC 60 20 50 */	fneg f3, f4
/* 8006BAA4  EC C4 02 32 */	fmuls f6, f4, f8
/* 8006BAA8  ED 4C 02 F2 */	fmuls f10, f12, f11
/* 8006BAAC  EC 83 02 F2 */	fmuls f4, f3, f11
/* 8006BAB0  EC 6C 02 32 */	fmuls f3, f12, f8
/* 8006BAB4  EC CA 30 2A */	fadds f6, f10, f6
/* 8006BAB8  EC 64 18 2A */	fadds f3, f4, f3
/* 8006BABC  D0 DE 00 08 */	stfs f6, 8(r30)
/* 8006BAC0  D0 7E 00 18 */	stfs f3, 0x18(r30)
/* 8006BAC4  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006BAC8  C1 41 00 08 */	lfs f10, 8(r1)
/* 8006BACC  FC 60 20 50 */	fneg f3, f4
/* 8006BAD0  EC C4 01 F2 */	fmuls f6, f4, f7
/* 8006BAD4  ED 0A 02 72 */	fmuls f8, f10, f9
/* 8006BAD8  EC 83 02 72 */	fmuls f4, f3, f9
/* 8006BADC  EC 6A 01 F2 */	fmuls f3, f10, f7
/* 8006BAE0  EC C8 30 2A */	fadds f6, f8, f6
/* 8006BAE4  EC 64 18 2A */	fadds f3, f4, f3
/* 8006BAE8  EC 81 30 2A */	fadds f4, f1, f6
/* 8006BAEC  EC 21 18 2A */	fadds f1, f1, f3
/* 8006BAF0  EC 64 00 28 */	fsubs f3, f4, f0
/* 8006BAF4  EC 00 08 2A */	fadds f0, f0, f1
/* 8006BAF8  EC 23 28 28 */	fsubs f1, f3, f5
/* 8006BAFC  EC 02 00 2A */	fadds f0, f2, f0
/* 8006BB00  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 8006BB04  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006BB08  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006BB0C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006BB10  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006BB14  7C 08 03 A6 */	mtlr r0
/* 8006BB18  38 21 00 20 */	addi r1, r1, 0x20
/* 8006BB1C  4E 80 00 20 */	blr 
/* 8006BB20  C0 43 00 1C */	lfs f2, 0x1c(r3)
/* 8006BB24  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006BB28  C0 22 8D 54 */	lfs f1, -0x72ac(r2)
/* 8006BB2C  EC 02 00 2A */	fadds f0, f2, f0
/* 8006BB30  C0 C3 00 0C */	lfs f6, 0xc(r3)
/* 8006BB34  C0 84 00 0C */	lfs f4, 0xc(r4)
/* 8006BB38  C0 A4 00 04 */	lfs f5, 4(r4)
/* 8006BB3C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006BB40  C0 43 00 10 */	lfs f2, 0x10(r3)
/* 8006BB44  EC C6 20 28 */	fsubs f6, f6, f4
/* 8006BB48  C1 44 00 00 */	lfs f10, 0(r4)
/* 8006BB4C  EC 82 01 72 */	fmuls f4, f2, f5
/* 8006BB50  C0 43 00 00 */	lfs f2, 0(r3)
/* 8006BB54  ED 22 02 B2 */	fmuls f9, f2, f10
/* 8006BB58  C0 63 00 14 */	lfs f3, 0x14(r3)
/* 8006BB5C  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006BB60  C1 03 00 04 */	lfs f8, 4(r3)
/* 8006BB64  C0 E3 00 08 */	lfs f7, 8(r3)
/* 8006BB68  EC CA 01 B2 */	fmuls f6, f10, f6
/* 8006BB6C  C0 43 00 18 */	lfs f2, 0x18(r3)
/* 8006BB70  ED 08 02 B2 */	fmuls f8, f8, f10
/* 8006BB74  EC E7 02 B2 */	fmuls f7, f7, f10
/* 8006BB78  D1 23 00 00 */	stfs f9, 0(r3)
/* 8006BB7C  EC 63 01 72 */	fmuls f3, f3, f5
/* 8006BB80  EC 42 01 72 */	fmuls f2, f2, f5
/* 8006BB84  D1 03 00 04 */	stfs f8, 4(r3)
/* 8006BB88  EC 01 00 2A */	fadds f0, f1, f0
/* 8006BB8C  D0 E3 00 08 */	stfs f7, 8(r3)
/* 8006BB90  D0 C3 00 0C */	stfs f6, 0xc(r3)
/* 8006BB94  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8006BB98  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006BB9C  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006BBA0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006BBA4  4E 80 00 20 */	blr 
/* 8006BBA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BBAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BBB0  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 8006BBB4  7C 08 02 A6 */	mflr r0
/* 8006BBB8  90 01 00 84 */	stw r0, 0x84(r1)
/* 8006BBBC  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 8006BBC0  F3 E1 00 78 */	psq_st f31, 120(r1), 0, qr0
/* 8006BBC4  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 8006BBC8  F3 C1 00 68 */	psq_st f30, 104(r1), 0, qr0
/* 8006BBCC  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 8006BBD0  F3 A1 00 58 */	psq_st f29, 88(r1), 0, qr0
/* 8006BBD4  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 8006BBD8  F3 81 00 48 */	psq_st f28, 72(r1), 0, qr0
/* 8006BBDC  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 8006BBE0  F3 61 00 38 */	psq_st f27, 56(r1), 0, qr0
/* 8006BBE4  DB 41 00 20 */	stfd f26, 0x20(r1)
/* 8006BBE8  F3 41 00 28 */	psq_st f26, 40(r1), 0, qr0
/* 8006BBEC  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006BBF0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006BBF4  7C 9F 23 78 */	mr r31, r4
/* 8006BBF8  C0 02 8D 58 */	lfs f0, -0x72a8(r2)
/* 8006BBFC  38 81 00 08 */	addi r4, r1, 8
/* 8006BC00  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006BC04  7C 7E 1B 78 */	mr r30, r3
/* 8006BC08  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006BC0C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006BC10  48 01 95 D1 */	bl 0x195d0
/* 8006BC14  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006BC18  C3 7F 00 04 */	lfs f27, 4(r31)
/* 8006BC1C  C0 E2 8D 5C */	lfs f7, -0x72a4(r2)
/* 8006BC20  EC 9B 00 B2 */	fmuls f4, f27, f2
/* 8006BC24  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 8006BC28  C1 21 00 08 */	lfs f9, 8(r1)
/* 8006BC2C  ED 01 38 28 */	fsubs f8, f1, f7
/* 8006BC30  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8006BC34  C0 1F 00 00 */	lfs f0, 0(r31)
/* 8006BC38  EC A7 08 28 */	fsubs f5, f7, f1
/* 8006BC3C  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8006BC40  C0 DE 00 0C */	lfs f6, 0xc(r30)
/* 8006BC44  FF C0 20 50 */	fneg f30, f4
/* 8006BC48  C3 9E 00 10 */	lfs f28, 0x10(r30)
/* 8006BC4C  ED 47 08 28 */	fsubs f10, f7, f1
/* 8006BC50  EC 7B 02 72 */	fmuls f3, f27, f9
/* 8006BC54  C3 5E 00 00 */	lfs f26, 0(r30)
/* 8006BC58  EC 20 02 72 */	fmuls f1, f0, f9
/* 8006BC5C  ED 26 38 28 */	fsubs f9, f6, f7
/* 8006BC60  C1 BE 00 14 */	lfs f13, 0x14(r30)
/* 8006BC64  EC 87 30 2A */	fadds f4, f7, f6
/* 8006BC68  EC A5 06 F2 */	fmuls f5, f5, f27
/* 8006BC6C  C3 FE 00 04 */	lfs f31, 4(r30)
/* 8006BC70  EC 40 00 B2 */	fmuls f2, f0, f2
/* 8006BC74  EC FE 01 32 */	fmuls f7, f30, f4
/* 8006BC78  C0 82 8D 54 */	lfs f4, -0x72ac(r2)
/* 8006BC7C  EC C3 02 32 */	fmuls f6, f3, f8
/* 8006BC80  EF 61 06 B2 */	fmuls f27, f1, f26
/* 8006BC84  C1 7E 00 18 */	lfs f11, 0x18(r30)
/* 8006BC88  C1 9E 00 08 */	lfs f12, 8(r30)
/* 8006BC8C  EC C7 30 2A */	fadds f6, f7, f6
/* 8006BC90  EC FE 06 B2 */	fmuls f7, f30, f26
/* 8006BC94  EF A2 07 32 */	fmuls f29, f2, f28
/* 8006BC98  EC A6 28 28 */	fsubs f5, f6, f5
/* 8006BC9C  EC C3 07 32 */	fmuls f6, f3, f28
/* 8006BCA0  EF 7B E8 2A */	fadds f27, f27, f29
/* 8006BCA4  EF 44 28 2A */	fadds f26, f4, f5
/* 8006BCA8  EC 87 30 2A */	fadds f4, f7, f6
/* 8006BCAC  D3 7E 00 00 */	stfs f27, 0(r30)
/* 8006BCB0  EC E1 07 F2 */	fmuls f7, f1, f31
/* 8006BCB4  EC A2 03 72 */	fmuls f5, f2, f13
/* 8006BCB8  D0 9E 00 10 */	stfs f4, 0x10(r30)
/* 8006BCBC  ED 21 02 72 */	fmuls f9, f1, f9
/* 8006BCC0  ED 02 02 32 */	fmuls f8, f2, f8
/* 8006BCC4  D3 5E 00 1C */	stfs f26, 0x1c(r30)
/* 8006BCC8  EC E7 28 2A */	fadds f7, f7, f5
/* 8006BCCC  EC A1 03 32 */	fmuls f5, f1, f12
/* 8006BCD0  EC 22 02 F2 */	fmuls f1, f2, f11
/* 8006BCD4  D0 FE 00 04 */	stfs f7, 4(r30)
/* 8006BCD8  EC DE 07 F2 */	fmuls f6, f30, f31
/* 8006BCDC  EC 83 03 72 */	fmuls f4, f3, f13
/* 8006BCE0  EC 43 02 F2 */	fmuls f2, f3, f11
/* 8006BCE4  EC 65 08 2A */	fadds f3, f5, f1
/* 8006BCE8  EC C6 20 2A */	fadds f6, f6, f4
/* 8006BCEC  EC 9E 03 32 */	fmuls f4, f30, f12
/* 8006BCF0  D0 7E 00 08 */	stfs f3, 8(r30)
/* 8006BCF4  EC 2A 00 32 */	fmuls f1, f10, f0
/* 8006BCF8  EC 09 40 2A */	fadds f0, f9, f8
/* 8006BCFC  D0 DE 00 14 */	stfs f6, 0x14(r30)
/* 8006BD00  EC 44 10 2A */	fadds f2, f4, f2
/* 8006BD04  EC 01 00 2A */	fadds f0, f1, f0
/* 8006BD08  D0 5E 00 18 */	stfs f2, 0x18(r30)
/* 8006BD0C  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8006BD10  E3 E1 00 78 */	psq_l f31, 120(r1), 0, qr0
/* 8006BD14  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 8006BD18  E3 C1 00 68 */	psq_l f30, 104(r1), 0, qr0
/* 8006BD1C  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 8006BD20  E3 A1 00 58 */	psq_l f29, 88(r1), 0, qr0
/* 8006BD24  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 8006BD28  E3 81 00 48 */	psq_l f28, 72(r1), 0, qr0
/* 8006BD2C  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 8006BD30  E3 61 00 38 */	psq_l f27, 56(r1), 0, qr0
/* 8006BD34  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 8006BD38  E3 41 00 28 */	psq_l f26, 40(r1), 0, qr0
/* 8006BD3C  CB 41 00 20 */	lfd f26, 0x20(r1)
/* 8006BD40  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006BD44  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006BD48  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8006BD4C  7C 08 03 A6 */	mtlr r0
/* 8006BD50  38 21 00 80 */	addi r1, r1, 0x80
/* 8006BD54  4E 80 00 20 */	blr 
/* 8006BD58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BD5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BD60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006BD64  7C 08 02 A6 */	mflr r0
/* 8006BD68  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006BD6C  54 C0 FF 7E */	rlwinm r0, r6, 0x1f, 0x1d, 0x1f
/* 8006BD70  28 00 00 07 */	cmplwi r0, 7
/* 8006BD74  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006BD78  7C 7F 1B 78 */	mr r31, r3
/* 8006BD7C  40 82 00 0C */	bne 0xc
/* 8006BD80  38 60 00 00 */	li r3, 0
/* 8006BD84  48 00 00 64 */	b 0x64
/* 8006BD88  2C 04 00 00 */	cmpwi r4, 0
/* 8006BD8C  41 82 00 24 */	beq 0x24
/* 8006BD90  3C C0 80 24 */	lis r6, 0x8024
/* 8006BD94  54 00 10 3A */	slwi r0, r0, 2
/* 8006BD98  38 C6 7E C8 */	addi r6, r6, 0x7ec8
/* 8006BD9C  7C A4 2B 78 */	mr r4, r5
/* 8006BDA0  7D 86 00 2E */	lwzx r12, r6, r0
/* 8006BDA4  7D 89 03 A6 */	mtctr r12
/* 8006BDA8  4E 80 04 21 */	bctrl 
/* 8006BDAC  48 00 00 20 */	b 0x20
/* 8006BDB0  3C C0 80 24 */	lis r6, 0x8024
/* 8006BDB4  54 00 10 3A */	slwi r0, r0, 2
/* 8006BDB8  38 C6 7E E4 */	addi r6, r6, 0x7ee4
/* 8006BDBC  7C A4 2B 78 */	mr r4, r5
/* 8006BDC0  7D 86 00 2E */	lwzx r12, r6, r0
/* 8006BDC4  7D 89 03 A6 */	mtctr r12
/* 8006BDC8  4E 80 04 21 */	bctrl 
/* 8006BDCC  C0 22 8D 50 */	lfs f1, -0x72b0(r2)
/* 8006BDD0  38 60 00 01 */	li r3, 1
/* 8006BDD4  C0 02 8D 54 */	lfs f0, -0x72ac(r2)
/* 8006BDD8  D0 3F 00 20 */	stfs f1, 0x20(r31)
/* 8006BDDC  D0 3F 00 24 */	stfs f1, 0x24(r31)
/* 8006BDE0  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8006BDE4  D0 3F 00 2C */	stfs f1, 0x2c(r31)
/* 8006BDE8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006BDEC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006BDF0  7C 08 03 A6 */	mtlr r0
/* 8006BDF4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006BDF8  4E 80 00 20 */	blr 
/* 8006BDFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BE00  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006BE04  7C 08 02 A6 */	mflr r0
/* 8006BE08  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006BE0C  39 61 00 40 */	addi r11, r1, 0x40
/* 8006BE10  4B FB 57 89 */	bl -0x4a878
/* 8006BE14  83 E8 00 00 */	lwz r31, 0(r8)
/* 8006BE18  7C 79 1B 78 */	mr r25, r3
/* 8006BE1C  7C 9A 23 78 */	mr r26, r4
/* 8006BE20  7C BB 2B 78 */	mr r27, r5
/* 8006BE24  57 E0 07 BD */	rlwinm. r0, r31, 0, 0x1e, 0x1e
/* 8006BE28  7C DC 33 78 */	mr r28, r6
/* 8006BE2C  7C FD 3B 78 */	mr r29, r7
/* 8006BE30  7D 1E 43 78 */	mr r30, r8
/* 8006BE34  40 82 00 0C */	bne 0xc
/* 8006BE38  57 E0 07 7B */	rlwinm. r0, r31, 0, 0x1d, 0x1d
/* 8006BE3C  41 82 00 14 */	beq 0x14
/* 8006BE40  7F 63 DB 78 */	mr r3, r27
/* 8006BE44  7F 24 CB 78 */	mr r4, r25
/* 8006BE48  48 12 DE E9 */	bl 0x12dee8
/* 8006BE4C  48 00 00 E4 */	b 0xe4
/* 8006BE50  57 E0 06 B5 */	rlwinm. r0, r31, 0, 0x1a, 0x1a
/* 8006BE54  41 82 00 74 */	beq 0x74
/* 8006BE58  54 E0 00 43 */	rlwinm. r0, r7, 0, 1, 1
/* 8006BE5C  41 82 00 2C */	beq 0x2c
/* 8006BE60  C0 48 00 48 */	lfs f2, 0x48(r8)
/* 8006BE64  7F 64 DB 78 */	mr r4, r27
/* 8006BE68  C0 28 00 38 */	lfs f1, 0x38(r8)
/* 8006BE6C  38 A1 00 14 */	addi r5, r1, 0x14
/* 8006BE70  C0 08 00 28 */	lfs f0, 0x28(r8)
/* 8006BE74  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8006BE78  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 8006BE7C  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 8006BE80  48 01 99 91 */	bl 0x19990
/* 8006BE84  48 00 00 AC */	b 0xac
/* 8006BE88  C0 26 00 08 */	lfs f1, 8(r6)
/* 8006BE8C  7F 64 DB 78 */	mr r4, r27
/* 8006BE90  C0 08 00 48 */	lfs f0, 0x48(r8)
/* 8006BE94  38 A1 00 08 */	addi r5, r1, 8
/* 8006BE98  C0 66 00 04 */	lfs f3, 4(r6)
/* 8006BE9C  EC 81 00 32 */	fmuls f4, f1, f0
/* 8006BEA0  C0 48 00 38 */	lfs f2, 0x38(r8)
/* 8006BEA4  C0 08 00 28 */	lfs f0, 0x28(r8)
/* 8006BEA8  C0 26 00 00 */	lfs f1, 0(r6)
/* 8006BEAC  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8006BEB0  D0 81 00 10 */	stfs f4, 0x10(r1)
/* 8006BEB4  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006BEB8  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 8006BEBC  D0 01 00 08 */	stfs f0, 8(r1)
/* 8006BEC0  48 01 99 51 */	bl 0x19950
/* 8006BEC4  48 00 00 6C */	b 0x6c
/* 8006BEC8  54 E0 00 43 */	rlwinm. r0, r7, 0, 1, 1
/* 8006BECC  41 82 00 18 */	beq 0x18
/* 8006BED0  7F 63 DB 78 */	mr r3, r27
/* 8006BED4  7F 25 CB 78 */	mr r5, r25
/* 8006BED8  38 88 00 1C */	addi r4, r8, 0x1c
/* 8006BEDC  48 12 DE 89 */	bl 0x12de88
/* 8006BEE0  48 00 00 50 */	b 0x50
/* 8006BEE4  7F 24 CB 78 */	mr r4, r25
/* 8006BEE8  38 68 00 1C */	addi r3, r8, 0x1c
/* 8006BEEC  48 12 DE 45 */	bl 0x12de44
/* 8006BEF0  C0 39 00 0C */	lfs f1, 0xc(r25)
/* 8006BEF4  7F 63 DB 78 */	mr r3, r27
/* 8006BEF8  C0 1C 00 00 */	lfs f0, 0(r28)
/* 8006BEFC  7F 24 CB 78 */	mr r4, r25
/* 8006BF00  C0 79 00 1C */	lfs f3, 0x1c(r25)
/* 8006BF04  7F 25 CB 78 */	mr r5, r25
/* 8006BF08  EC 81 00 32 */	fmuls f4, f1, f0
/* 8006BF0C  C0 5C 00 04 */	lfs f2, 4(r28)
/* 8006BF10  C0 39 00 2C */	lfs f1, 0x2c(r25)
/* 8006BF14  C0 1C 00 08 */	lfs f0, 8(r28)
/* 8006BF18  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8006BF1C  D0 99 00 0C */	stfs f4, 0xc(r25)
/* 8006BF20  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006BF24  D0 59 00 1C */	stfs f2, 0x1c(r25)
/* 8006BF28  D0 19 00 2C */	stfs f0, 0x2c(r25)
/* 8006BF2C  48 12 DE 39 */	bl 0x12de38
/* 8006BF30  57 E0 07 39 */	rlwinm. r0, r31, 0, 0x1c, 0x1c
/* 8006BF34  41 82 00 1C */	beq 0x1c
/* 8006BF38  C0 02 8D 54 */	lfs f0, -0x72ac(r2)
/* 8006BF3C  67 A4 40 00 */	oris r4, r29, 0x4000
/* 8006BF40  D0 1A 00 08 */	stfs f0, 8(r26)
/* 8006BF44  D0 1A 00 04 */	stfs f0, 4(r26)
/* 8006BF48  D0 1A 00 00 */	stfs f0, 0(r26)
/* 8006BF4C  48 00 00 20 */	b 0x20
/* 8006BF50  C0 1E 00 04 */	lfs f0, 4(r30)
/* 8006BF54  57 A4 00 BE */	clrlwi r4, r29, 2
/* 8006BF58  D0 1A 00 00 */	stfs f0, 0(r26)
/* 8006BF5C  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8006BF60  D0 1A 00 04 */	stfs f0, 4(r26)
/* 8006BF64  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 8006BF68  D0 1A 00 08 */	stfs f0, 8(r26)
/* 8006BF6C  57 E0 06 F7 */	rlwinm. r0, r31, 0, 0x1b, 0x1b
/* 8006BF70  54 83 01 3E */	clrlwi r3, r4, 4
/* 8006BF74  41 82 00 08 */	beq 0x8
/* 8006BF78  64 83 10 00 */	oris r3, r4, 0x1000
/* 8006BF7C  39 61 00 40 */	addi r11, r1, 0x40
/* 8006BF80  4B FB 56 65 */	bl -0x4a99c
/* 8006BF84  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006BF88  7C 08 03 A6 */	mtlr r0
/* 8006BF8C  38 21 00 40 */	addi r1, r1, 0x40
/* 8006BF90  4E 80 00 20 */	blr 
/* 8006BF94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BF98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BF9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BFA0  C0 24 00 04 */	lfs f1, 4(r4)
/* 8006BFA4  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006BFA8  C0 42 8D 68 */	lfs f2, -0x7298(r2)
/* 8006BFAC  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006BFB0  C0 64 00 00 */	lfs f3, 0(r4)
/* 8006BFB4  D0 63 00 00 */	stfs f3, 0(r3)
/* 8006BFB8  D0 43 00 04 */	stfs f2, 4(r3)
/* 8006BFBC  D0 43 00 08 */	stfs f2, 8(r3)
/* 8006BFC0  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006BFC4  D0 43 00 10 */	stfs f2, 0x10(r3)
/* 8006BFC8  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8006BFCC  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006BFD0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006BFD4  4E 80 00 20 */	blr 
/* 8006BFD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BFDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006BFE0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006BFE4  7C 08 02 A6 */	mflr r0
/* 8006BFE8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006BFEC  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006BFF0  38 81 00 08 */	addi r4, r1, 8
/* 8006BFF4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006BFF8  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006BFFC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C000  7C 7F 1B 78 */	mr r31, r3
/* 8006C004  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C008  48 01 91 D9 */	bl 0x191d8
/* 8006C00C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006C010  D0 1F 00 00 */	stfs f0, 0(r31)
/* 8006C014  C0 42 8D 68 */	lfs f2, -0x7298(r2)
/* 8006C018  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006C01C  C0 22 8D 6C */	lfs f1, -0x7294(r2)
/* 8006C020  FC 00 00 50 */	fneg f0, f0
/* 8006C024  D0 5F 00 08 */	stfs f2, 8(r31)
/* 8006C028  D0 1F 00 04 */	stfs f0, 4(r31)
/* 8006C02C  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006C030  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8006C034  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006C038  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8006C03C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006C040  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8006C044  D0 5F 00 18 */	stfs f2, 0x18(r31)
/* 8006C048  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006C04C  EC 01 00 28 */	fsubs f0, f1, f0
/* 8006C050  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006C054  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C058  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006C05C  7C 08 03 A6 */	mtlr r0
/* 8006C060  38 21 00 20 */	addi r1, r1, 0x20
/* 8006C064  4E 80 00 20 */	blr 
/* 8006C068  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C06C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C070  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 8006C074  C0 42 8D 68 */	lfs f2, -0x7298(r2)
/* 8006C078  FC 20 00 50 */	fneg f1, f0
/* 8006C07C  C0 62 8D 6C */	lfs f3, -0x7294(r2)
/* 8006C080  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006C084  D0 63 00 00 */	stfs f3, 0(r3)
/* 8006C088  D0 43 00 04 */	stfs f2, 4(r3)
/* 8006C08C  D0 43 00 08 */	stfs f2, 8(r3)
/* 8006C090  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 8006C094  D0 43 00 10 */	stfs f2, 0x10(r3)
/* 8006C098  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006C09C  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006C0A0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006C0A4  4E 80 00 20 */	blr 
/* 8006C0A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C0AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C0B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006C0B4  7C 08 02 A6 */	mflr r0
/* 8006C0B8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C0BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006C0C0  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C0C4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C0C8  7C 9F 23 78 */	mr r31, r4
/* 8006C0CC  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C0D0  38 81 00 08 */	addi r4, r1, 8
/* 8006C0D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006C0D8  7C 7E 1B 78 */	mr r30, r3
/* 8006C0DC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C0E0  48 01 91 01 */	bl 0x19100
/* 8006C0E4  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006C0E8  C0 7F 00 04 */	lfs f3, 4(r31)
/* 8006C0EC  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8006C0F0  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006C0F4  EC E3 00 32 */	fmuls f7, f3, f0
/* 8006C0F8  EC A1 00 32 */	fmuls f5, f1, f0
/* 8006C0FC  C0 42 8D 68 */	lfs f2, -0x7298(r2)
/* 8006C100  EC C1 01 32 */	fmuls f6, f1, f4
/* 8006C104  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006C108  FC 20 38 50 */	fneg f1, f7
/* 8006C10C  EC 83 01 32 */	fmuls f4, f3, f4
/* 8006C110  FC 60 30 50 */	fneg f3, f6
/* 8006C114  D0 BE 00 00 */	stfs f5, 0(r30)
/* 8006C118  EC 00 08 2A */	fadds f0, f0, f1
/* 8006C11C  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8006C120  D0 7E 00 04 */	stfs f3, 4(r30)
/* 8006C124  D0 DE 00 0C */	stfs f6, 0xc(r30)
/* 8006C128  D0 9E 00 10 */	stfs f4, 0x10(r30)
/* 8006C12C  D0 FE 00 14 */	stfs f7, 0x14(r30)
/* 8006C130  D0 5E 00 18 */	stfs f2, 0x18(r30)
/* 8006C134  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006C138  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C13C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006C140  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006C144  7C 08 03 A6 */	mtlr r0
/* 8006C148  38 21 00 20 */	addi r1, r1, 0x20
/* 8006C14C  4E 80 00 20 */	blr 
/* 8006C150  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006C154  7C 08 02 A6 */	mflr r0
/* 8006C158  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C15C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006C160  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C164  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C168  7C 9F 23 78 */	mr r31, r4
/* 8006C16C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C170  38 81 00 08 */	addi r4, r1, 8
/* 8006C174  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006C178  7C 7E 1B 78 */	mr r30, r3
/* 8006C17C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C180  48 01 90 61 */	bl 0x19060
/* 8006C184  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006C188  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8006C18C  C0 82 8D 68 */	lfs f4, -0x7298(r2)
/* 8006C190  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006C194  C0 DF 00 0C */	lfs f6, 0xc(r31)
/* 8006C198  FC 00 00 50 */	fneg f0, f0
/* 8006C19C  D0 9E 00 08 */	stfs f4, 8(r30)
/* 8006C1A0  C0 BF 00 10 */	lfs f5, 0x10(r31)
/* 8006C1A4  D0 1E 00 04 */	stfs f0, 4(r30)
/* 8006C1A8  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006C1AC  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006C1B0  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006C1B4  EC 61 01 B2 */	fmuls f3, f1, f6
/* 8006C1B8  EC 22 01 72 */	fmuls f1, f2, f5
/* 8006C1BC  EC 42 18 28 */	fsubs f2, f2, f3
/* 8006C1C0  EC 22 08 28 */	fsubs f1, f2, f1
/* 8006C1C4  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 8006C1C8  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006C1CC  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 8006C1D0  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006C1D4  D0 3E 00 14 */	stfs f1, 0x14(r30)
/* 8006C1D8  D0 9E 00 18 */	stfs f4, 0x18(r30)
/* 8006C1DC  C0 81 00 08 */	lfs f4, 8(r1)
/* 8006C1E0  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006C1E4  FC 60 20 50 */	fneg f3, f4
/* 8006C1E8  EC 41 01 B2 */	fmuls f2, f1, f6
/* 8006C1EC  EC 24 01 72 */	fmuls f1, f4, f5
/* 8006C1F0  EC 43 10 28 */	fsubs f2, f3, f2
/* 8006C1F4  EC 22 08 2A */	fadds f1, f2, f1
/* 8006C1F8  EC 00 08 2A */	fadds f0, f0, f1
/* 8006C1FC  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006C200  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C204  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006C208  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006C20C  7C 08 03 A6 */	mtlr r0
/* 8006C210  38 21 00 20 */	addi r1, r1, 0x20
/* 8006C214  4E 80 00 20 */	blr 
/* 8006C218  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C21C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C220  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006C224  C0 22 8D 6C */	lfs f1, -0x7294(r2)
/* 8006C228  C0 A2 8D 68 */	lfs f5, -0x7298(r2)
/* 8006C22C  C0 C4 00 00 */	lfs f6, 0(r4)
/* 8006C230  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006C234  C0 44 00 04 */	lfs f2, 4(r4)
/* 8006C238  FC 80 30 50 */	fneg f4, f6
/* 8006C23C  C0 64 00 0C */	lfs f3, 0xc(r4)
/* 8006C240  EC 02 00 32 */	fmuls f0, f2, f0
/* 8006C244  D0 C3 00 00 */	stfs f6, 0(r3)
/* 8006C248  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8006C24C  D0 A3 00 04 */	stfs f5, 4(r3)
/* 8006C250  EC 01 00 2A */	fadds f0, f1, f0
/* 8006C254  D0 A3 00 08 */	stfs f5, 8(r3)
/* 8006C258  D0 63 00 0C */	stfs f3, 0xc(r3)
/* 8006C25C  D0 A3 00 10 */	stfs f5, 0x10(r3)
/* 8006C260  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 8006C264  D0 A3 00 18 */	stfs f5, 0x18(r3)
/* 8006C268  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006C26C  4E 80 00 20 */	blr 
/* 8006C270  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006C274  7C 08 02 A6 */	mflr r0
/* 8006C278  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C27C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006C280  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C284  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C288  7C 9F 23 78 */	mr r31, r4
/* 8006C28C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C290  38 81 00 08 */	addi r4, r1, 8
/* 8006C294  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006C298  7C 7E 1B 78 */	mr r30, r3
/* 8006C29C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C2A0  48 01 8F 41 */	bl 0x18f40
/* 8006C2A4  C0 61 00 08 */	lfs f3, 8(r1)
/* 8006C2A8  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8006C2AC  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006C2B0  C0 BF 00 00 */	lfs f5, 0(r31)
/* 8006C2B4  ED 20 00 F2 */	fmuls f9, f0, f3
/* 8006C2B8  ED 40 00 B2 */	fmuls f10, f0, f2
/* 8006C2BC  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8006C2C0  EC E5 00 F2 */	fmuls f7, f5, f3
/* 8006C2C4  C0 C2 8D 68 */	lfs f6, -0x7298(r2)
/* 8006C2C8  ED 05 00 B2 */	fmuls f8, f5, f2
/* 8006C2CC  FC 60 48 50 */	fneg f3, f9
/* 8006C2D0  EC 4A 00 72 */	fmuls f2, f10, f1
/* 8006C2D4  C0 9F 00 10 */	lfs f4, 0x10(r31)
/* 8006C2D8  EC A7 00 72 */	fmuls f5, f7, f1
/* 8006C2DC  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006C2E0  EC 29 01 32 */	fmuls f1, f9, f4
/* 8006C2E4  EC 43 10 28 */	fsubs f2, f3, f2
/* 8006C2E8  EC 68 01 32 */	fmuls f3, f8, f4
/* 8006C2EC  D0 FE 00 00 */	stfs f7, 0(r30)
/* 8006C2F0  EC A8 28 28 */	fsubs f5, f8, f5
/* 8006C2F4  EC 22 08 2A */	fadds f1, f2, f1
/* 8006C2F8  D0 DE 00 08 */	stfs f6, 8(r30)
/* 8006C2FC  FC 80 40 50 */	fneg f4, f8
/* 8006C300  EC 45 18 28 */	fsubs f2, f5, f3
/* 8006C304  D1 5E 00 10 */	stfs f10, 0x10(r30)
/* 8006C308  EC 00 08 2A */	fadds f0, f0, f1
/* 8006C30C  D1 3E 00 14 */	stfs f9, 0x14(r30)
/* 8006C310  D0 9E 00 04 */	stfs f4, 4(r30)
/* 8006C314  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 8006C318  D0 DE 00 18 */	stfs f6, 0x18(r30)
/* 8006C31C  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006C320  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C324  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006C328  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006C32C  7C 08 03 A6 */	mtlr r0
/* 8006C330  38 21 00 20 */	addi r1, r1, 0x20
/* 8006C334  4E 80 00 20 */	blr 
/* 8006C338  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C33C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C340  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 8006C344  C0 22 8D 6C */	lfs f1, -0x7294(r2)
/* 8006C348  C0 A4 00 04 */	lfs f5, 4(r4)
/* 8006C34C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006C350  C0 83 00 10 */	lfs f4, 0x10(r3)
/* 8006C354  C0 63 00 14 */	lfs f3, 0x14(r3)
/* 8006C358  C0 43 00 18 */	lfs f2, 0x18(r3)
/* 8006C35C  EC 84 01 72 */	fmuls f4, f4, f5
/* 8006C360  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006C364  EC 63 01 72 */	fmuls f3, f3, f5
/* 8006C368  C1 03 00 00 */	lfs f8, 0(r3)
/* 8006C36C  EC 42 01 72 */	fmuls f2, f2, f5
/* 8006C370  C1 24 00 00 */	lfs f9, 0(r4)
/* 8006C374  C0 E3 00 04 */	lfs f7, 4(r3)
/* 8006C378  C0 C3 00 08 */	lfs f6, 8(r3)
/* 8006C37C  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 8006C380  ED 08 02 72 */	fmuls f8, f8, f9
/* 8006C384  EC E7 02 72 */	fmuls f7, f7, f9
/* 8006C388  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8006C38C  EC C6 02 72 */	fmuls f6, f6, f9
/* 8006C390  EC A5 02 72 */	fmuls f5, f5, f9
/* 8006C394  D1 03 00 00 */	stfs f8, 0(r3)
/* 8006C398  EC 01 00 2A */	fadds f0, f1, f0
/* 8006C39C  D0 E3 00 04 */	stfs f7, 4(r3)
/* 8006C3A0  D0 C3 00 08 */	stfs f6, 8(r3)
/* 8006C3A4  D0 A3 00 0C */	stfs f5, 0xc(r3)
/* 8006C3A8  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006C3AC  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006C3B0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006C3B4  4E 80 00 20 */	blr 
/* 8006C3B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C3BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C3C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006C3C4  7C 08 02 A6 */	mflr r0
/* 8006C3C8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C3CC  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C3D0  38 81 00 08 */	addi r4, r1, 8
/* 8006C3D4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006C3D8  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C3DC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C3E0  7C 7F 1B 78 */	mr r31, r3
/* 8006C3E4  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C3E8  48 01 8D F9 */	bl 0x18df8
/* 8006C3EC  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006C3F0  C0 5F 00 00 */	lfs f2, 0(r31)
/* 8006C3F4  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006C3F8  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8006C3FC  EC 85 00 B2 */	fmuls f4, f5, f2
/* 8006C400  EC 61 00 B2 */	fmuls f3, f1, f2
/* 8006C404  C1 3F 00 04 */	lfs f9, 4(r31)
/* 8006C408  EC 21 00 32 */	fmuls f1, f1, f0
/* 8006C40C  C0 5F 00 14 */	lfs f2, 0x14(r31)
/* 8006C410  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006C414  C0 FF 00 08 */	lfs f7, 8(r31)
/* 8006C418  EC 84 08 28 */	fsubs f4, f4, f1
/* 8006C41C  C0 3F 00 18 */	lfs f1, 0x18(r31)
/* 8006C420  EC 03 00 2A */	fadds f0, f3, f0
/* 8006C424  C0 BF 00 0C */	lfs f5, 0xc(r31)
/* 8006C428  D0 9F 00 00 */	stfs f4, 0(r31)
/* 8006C42C  C0 7F 00 1C */	lfs f3, 0x1c(r31)
/* 8006C430  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8006C434  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006C438  C1 41 00 08 */	lfs f10, 8(r1)
/* 8006C43C  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006C440  ED 0A 02 72 */	fmuls f8, f10, f9
/* 8006C444  EC C4 00 B2 */	fmuls f6, f4, f2
/* 8006C448  EC 84 02 72 */	fmuls f4, f4, f9
/* 8006C44C  EC 4A 00 B2 */	fmuls f2, f10, f2
/* 8006C450  EC C8 30 28 */	fsubs f6, f8, f6
/* 8006C454  EC 44 10 2A */	fadds f2, f4, f2
/* 8006C458  D0 DF 00 04 */	stfs f6, 4(r31)
/* 8006C45C  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 8006C460  C1 01 00 08 */	lfs f8, 8(r1)
/* 8006C464  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006C468  EC C8 01 F2 */	fmuls f6, f8, f7
/* 8006C46C  EC 82 00 72 */	fmuls f4, f2, f1
/* 8006C470  EC 42 01 F2 */	fmuls f2, f2, f7
/* 8006C474  EC 28 00 72 */	fmuls f1, f8, f1
/* 8006C478  EC 86 20 28 */	fsubs f4, f6, f4
/* 8006C47C  EC 22 08 2A */	fadds f1, f2, f1
/* 8006C480  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8006C484  D0 3F 00 18 */	stfs f1, 0x18(r31)
/* 8006C488  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8006C48C  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006C490  EC 26 00 F2 */	fmuls f1, f6, f3
/* 8006C494  EC 44 01 72 */	fmuls f2, f4, f5
/* 8006C498  EC A6 01 72 */	fmuls f5, f6, f5
/* 8006C49C  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8006C4A0  EC 22 08 2A */	fadds f1, f2, f1
/* 8006C4A4  EC 45 18 28 */	fsubs f2, f5, f3
/* 8006C4A8  EC 21 30 28 */	fsubs f1, f1, f6
/* 8006C4AC  EC 44 10 2A */	fadds f2, f4, f2
/* 8006C4B0  EC 00 08 2A */	fadds f0, f0, f1
/* 8006C4B4  D0 5F 00 0C */	stfs f2, 0xc(r31)
/* 8006C4B8  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006C4BC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C4C0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006C4C4  7C 08 03 A6 */	mtlr r0
/* 8006C4C8  38 21 00 20 */	addi r1, r1, 0x20
/* 8006C4CC  4E 80 00 20 */	blr 
/* 8006C4D0  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 8006C4D4  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 8006C4D8  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 8006C4DC  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006C4E0  EC 43 10 28 */	fsubs f2, f3, f2
/* 8006C4E4  EC 01 00 2A */	fadds f0, f1, f0
/* 8006C4E8  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006C4EC  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006C4F0  4E 80 00 20 */	blr 
/* 8006C4F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C4F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C4FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C500  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006C504  7C 08 02 A6 */	mflr r0
/* 8006C508  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006C50C  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8006C510  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 8006C514  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 8006C518  F3 C1 00 28 */	psq_st f30, 40(r1), 0, qr0
/* 8006C51C  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C520  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C524  7C 9F 23 78 */	mr r31, r4
/* 8006C528  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C52C  38 81 00 08 */	addi r4, r1, 8
/* 8006C530  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006C534  7C 7E 1B 78 */	mr r30, r3
/* 8006C538  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C53C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C540  48 01 8C A1 */	bl 0x18ca0
/* 8006C544  C0 81 00 08 */	lfs f4, 8(r1)
/* 8006C548  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8006C54C  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006C550  EC 40 01 32 */	fmuls f2, f0, f4
/* 8006C554  C0 BF 00 00 */	lfs f5, 0(r31)
/* 8006C558  EC 60 00 72 */	fmuls f3, f0, f1
/* 8006C55C  C0 DE 00 1C */	lfs f6, 0x1c(r30)
/* 8006C560  EC 05 01 32 */	fmuls f0, f5, f4
/* 8006C564  C0 FE 00 0C */	lfs f7, 0xc(r30)
/* 8006C568  EC 25 00 72 */	fmuls f1, f5, f1
/* 8006C56C  C3 DE 00 00 */	lfs f30, 0(r30)
/* 8006C570  EC A3 01 F2 */	fmuls f5, f3, f7
/* 8006C574  C1 BE 00 10 */	lfs f13, 0x10(r30)
/* 8006C578  EC 82 01 B2 */	fmuls f4, f2, f6
/* 8006C57C  C1 7E 00 04 */	lfs f11, 4(r30)
/* 8006C580  EC E0 01 F2 */	fmuls f7, f0, f7
/* 8006C584  C1 5E 00 14 */	lfs f10, 0x14(r30)
/* 8006C588  EC A5 20 2A */	fadds f5, f5, f4
/* 8006C58C  C0 82 8D 6C */	lfs f4, -0x7294(r2)
/* 8006C590  EC C1 01 B2 */	fmuls f6, f1, f6
/* 8006C594  C1 3E 00 08 */	lfs f9, 8(r30)
/* 8006C598  EC A5 10 28 */	fsubs f5, f5, f2
/* 8006C59C  C1 1E 00 18 */	lfs f8, 0x18(r30)
/* 8006C5A0  EC C7 30 28 */	fsubs f6, f7, f6
/* 8006C5A4  EF E0 07 B2 */	fmuls f31, f0, f30
/* 8006C5A8  EC 84 28 2A */	fadds f4, f4, f5
/* 8006C5AC  ED 81 03 72 */	fmuls f12, f1, f13
/* 8006C5B0  D0 9E 00 1C */	stfs f4, 0x1c(r30)
/* 8006C5B4  EC E3 07 B2 */	fmuls f7, f3, f30
/* 8006C5B8  EC 81 02 B2 */	fmuls f4, f1, f10
/* 8006C5BC  EC BF 60 28 */	fsubs f5, f31, f12
/* 8006C5C0  ED 81 30 2A */	fadds f12, f1, f6
/* 8006C5C4  D0 BE 00 00 */	stfs f5, 0(r30)
/* 8006C5C8  EC C2 03 72 */	fmuls f6, f2, f13
/* 8006C5CC  EC A0 02 F2 */	fmuls f5, f0, f11
/* 8006C5D0  D1 9E 00 0C */	stfs f12, 0xc(r30)
/* 8006C5D4  ED 87 30 2A */	fadds f12, f7, f6
/* 8006C5D8  EC C2 02 B2 */	fmuls f6, f2, f10
/* 8006C5DC  ED 45 20 28 */	fsubs f10, f5, f4
/* 8006C5E0  D1 9E 00 10 */	stfs f12, 0x10(r30)
/* 8006C5E4  EC E3 02 F2 */	fmuls f7, f3, f11
/* 8006C5E8  EC A0 02 72 */	fmuls f5, f0, f9
/* 8006C5EC  D1 5E 00 04 */	stfs f10, 4(r30)
/* 8006C5F0  EC 81 02 32 */	fmuls f4, f1, f8
/* 8006C5F4  EC 02 02 32 */	fmuls f0, f2, f8
/* 8006C5F8  EC 23 02 72 */	fmuls f1, f3, f9
/* 8006C5FC  EC C7 30 2A */	fadds f6, f7, f6
/* 8006C600  EC 45 20 28 */	fsubs f2, f5, f4
/* 8006C604  EC 01 00 2A */	fadds f0, f1, f0
/* 8006C608  D0 DE 00 14 */	stfs f6, 0x14(r30)
/* 8006C60C  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8006C610  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8006C614  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 8006C618  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8006C61C  E3 C1 00 28 */	psq_l f30, 40(r1), 0, qr0
/* 8006C620  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 8006C624  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C628  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006C62C  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006C630  7C 08 03 A6 */	mtlr r0
/* 8006C634  38 21 00 40 */	addi r1, r1, 0x40
/* 8006C638  4E 80 00 20 */	blr 
/* 8006C63C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C640  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006C644  7C 08 02 A6 */	mflr r0
/* 8006C648  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C64C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006C650  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C654  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C658  7C 9F 23 78 */	mr r31, r4
/* 8006C65C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C660  38 81 00 08 */	addi r4, r1, 8
/* 8006C664  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006C668  7C 7E 1B 78 */	mr r30, r3
/* 8006C66C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C670  48 01 8B 71 */	bl 0x18b70
/* 8006C674  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006C678  C0 3E 00 00 */	lfs f1, 0(r30)
/* 8006C67C  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006C680  EC 65 00 72 */	fmuls f3, f5, f1
/* 8006C684  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 8006C688  EC 22 00 72 */	fmuls f1, f2, f1
/* 8006C68C  C1 5E 00 04 */	lfs f10, 4(r30)
/* 8006C690  EC 42 00 32 */	fmuls f2, f2, f0
/* 8006C694  C0 9E 00 14 */	lfs f4, 0x14(r30)
/* 8006C698  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006C69C  C1 1E 00 08 */	lfs f8, 8(r30)
/* 8006C6A0  EC 43 10 28 */	fsubs f2, f3, f2
/* 8006C6A4  C0 DE 00 18 */	lfs f6, 0x18(r30)
/* 8006C6A8  EC 61 00 2A */	fadds f3, f1, f0
/* 8006C6AC  D0 5E 00 00 */	stfs f2, 0(r30)
/* 8006C6B0  C0 3E 00 0C */	lfs f1, 0xc(r30)
/* 8006C6B4  D0 7E 00 10 */	stfs f3, 0x10(r30)
/* 8006C6B8  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8006C6BC  C1 61 00 08 */	lfs f11, 8(r1)
/* 8006C6C0  EC A1 00 28 */	fsubs f5, f1, f0
/* 8006C6C4  C0 E1 00 0C */	lfs f7, 0xc(r1)
/* 8006C6C8  ED 2B 02 B2 */	fmuls f9, f11, f10
/* 8006C6CC  C0 5E 00 1C */	lfs f2, 0x1c(r30)
/* 8006C6D0  EC 67 01 32 */	fmuls f3, f7, f4
/* 8006C6D4  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8006C6D8  EC E7 02 B2 */	fmuls f7, f7, f10
/* 8006C6DC  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006C6E0  ED 29 18 28 */	fsubs f9, f9, f3
/* 8006C6E4  EC 8B 01 32 */	fmuls f4, f11, f4
/* 8006C6E8  EC 62 08 2A */	fadds f3, f2, f1
/* 8006C6EC  D1 3E 00 04 */	stfs f9, 4(r30)
/* 8006C6F0  EC 27 20 2A */	fadds f1, f7, f4
/* 8006C6F4  D0 3E 00 14 */	stfs f1, 0x14(r30)
/* 8006C6F8  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006C6FC  C1 21 00 08 */	lfs f9, 8(r1)
/* 8006C700  EC 81 01 B2 */	fmuls f4, f1, f6
/* 8006C704  EC E9 02 32 */	fmuls f7, f9, f8
/* 8006C708  EC 41 02 32 */	fmuls f2, f1, f8
/* 8006C70C  EC 29 01 B2 */	fmuls f1, f9, f6
/* 8006C710  EC 87 20 28 */	fsubs f4, f7, f4
/* 8006C714  EC 22 08 2A */	fadds f1, f2, f1
/* 8006C718  D0 9E 00 08 */	stfs f4, 8(r30)
/* 8006C71C  D0 3E 00 18 */	stfs f1, 0x18(r30)
/* 8006C720  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8006C724  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8006C728  EC 26 00 F2 */	fmuls f1, f6, f3
/* 8006C72C  EC 44 01 72 */	fmuls f2, f4, f5
/* 8006C730  EC A6 01 72 */	fmuls f5, f6, f5
/* 8006C734  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8006C738  EC 22 08 2A */	fadds f1, f2, f1
/* 8006C73C  EC 45 18 28 */	fsubs f2, f5, f3
/* 8006C740  EC 21 30 28 */	fsubs f1, f1, f6
/* 8006C744  EC 44 10 2A */	fadds f2, f4, f2
/* 8006C748  EC 00 08 2A */	fadds f0, f0, f1
/* 8006C74C  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 8006C750  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006C754  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C758  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006C75C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006C760  7C 08 03 A6 */	mtlr r0
/* 8006C764  38 21 00 20 */	addi r1, r1, 0x20
/* 8006C768  4E 80 00 20 */	blr 
/* 8006C76C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C770  C0 43 00 1C */	lfs f2, 0x1c(r3)
/* 8006C774  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006C778  C0 22 8D 6C */	lfs f1, -0x7294(r2)
/* 8006C77C  EC 02 00 2A */	fadds f0, f2, f0
/* 8006C780  C0 C3 00 0C */	lfs f6, 0xc(r3)
/* 8006C784  C0 84 00 0C */	lfs f4, 0xc(r4)
/* 8006C788  C0 A4 00 04 */	lfs f5, 4(r4)
/* 8006C78C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006C790  C0 43 00 10 */	lfs f2, 0x10(r3)
/* 8006C794  EC C6 20 28 */	fsubs f6, f6, f4
/* 8006C798  C1 44 00 00 */	lfs f10, 0(r4)
/* 8006C79C  EC 82 01 72 */	fmuls f4, f2, f5
/* 8006C7A0  C0 43 00 00 */	lfs f2, 0(r3)
/* 8006C7A4  ED 22 02 B2 */	fmuls f9, f2, f10
/* 8006C7A8  C0 63 00 14 */	lfs f3, 0x14(r3)
/* 8006C7AC  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006C7B0  C1 03 00 04 */	lfs f8, 4(r3)
/* 8006C7B4  C0 E3 00 08 */	lfs f7, 8(r3)
/* 8006C7B8  EC CA 01 B2 */	fmuls f6, f10, f6
/* 8006C7BC  C0 43 00 18 */	lfs f2, 0x18(r3)
/* 8006C7C0  ED 08 02 B2 */	fmuls f8, f8, f10
/* 8006C7C4  EC E7 02 B2 */	fmuls f7, f7, f10
/* 8006C7C8  D1 23 00 00 */	stfs f9, 0(r3)
/* 8006C7CC  EC 63 01 72 */	fmuls f3, f3, f5
/* 8006C7D0  EC 42 01 72 */	fmuls f2, f2, f5
/* 8006C7D4  D1 03 00 04 */	stfs f8, 4(r3)
/* 8006C7D8  EC 01 00 2A */	fadds f0, f1, f0
/* 8006C7DC  D0 E3 00 08 */	stfs f7, 8(r3)
/* 8006C7E0  D0 C3 00 0C */	stfs f6, 0xc(r3)
/* 8006C7E4  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8006C7E8  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006C7EC  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006C7F0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006C7F4  4E 80 00 20 */	blr 
/* 8006C7F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C7FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C800  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8006C804  7C 08 02 A6 */	mflr r0
/* 8006C808  90 01 00 54 */	stw r0, 0x54(r1)
/* 8006C80C  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8006C810  F3 E1 00 48 */	psq_st f31, 72(r1), 0, qr0
/* 8006C814  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 8006C818  F3 C1 00 38 */	psq_st f30, 56(r1), 0, qr0
/* 8006C81C  DB A1 00 20 */	stfd f29, 0x20(r1)
/* 8006C820  F3 A1 00 28 */	psq_st f29, 40(r1), 0, qr0
/* 8006C824  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006C828  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006C82C  7C 9F 23 78 */	mr r31, r4
/* 8006C830  C0 02 8D 70 */	lfs f0, -0x7290(r2)
/* 8006C834  38 81 00 08 */	addi r4, r1, 8
/* 8006C838  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006C83C  7C 7E 1B 78 */	mr r30, r3
/* 8006C840  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006C844  38 61 00 0C */	addi r3, r1, 0xc
/* 8006C848  48 01 89 99 */	bl 0x18998
/* 8006C84C  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006C850  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8006C854  C0 C1 00 0C */	lfs f6, 0xc(r1)
/* 8006C858  C1 1F 00 00 */	lfs f8, 0(r31)
/* 8006C85C  EC 40 01 72 */	fmuls f2, f0, f5
/* 8006C860  EC 60 01 B2 */	fmuls f3, f0, f6
/* 8006C864  C0 9E 00 0C */	lfs f4, 0xc(r30)
/* 8006C868  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8006C86C  EC 08 01 72 */	fmuls f0, f8, f5
/* 8006C870  C0 BE 00 1C */	lfs f5, 0x1c(r30)
/* 8006C874  EC E4 08 28 */	fsubs f7, f4, f1
/* 8006C878  EC 28 01 B2 */	fmuls f1, f8, f6
/* 8006C87C  C0 9F 00 10 */	lfs f4, 0x10(r31)
/* 8006C880  C3 BE 00 00 */	lfs f29, 0(r30)
/* 8006C884  EC 85 20 2A */	fadds f4, f5, f4
/* 8006C888  C3 FE 00 10 */	lfs f31, 0x10(r30)
/* 8006C88C  EC C3 01 F2 */	fmuls f6, f3, f7
/* 8006C890  ED 00 01 F2 */	fmuls f8, f0, f7
/* 8006C894  C1 9E 00 04 */	lfs f12, 4(r30)
/* 8006C898  EC A2 01 32 */	fmuls f5, f2, f4
/* 8006C89C  EC E1 01 32 */	fmuls f7, f1, f4
/* 8006C8A0  C1 7E 00 14 */	lfs f11, 0x14(r30)
/* 8006C8A4  EF C0 07 72 */	fmuls f30, f0, f29
/* 8006C8A8  EC A6 28 2A */	fadds f5, f6, f5
/* 8006C8AC  C0 82 8D 6C */	lfs f4, -0x7294(r2)
/* 8006C8B0  EC C8 38 28 */	fsubs f6, f8, f7
/* 8006C8B4  ED A1 07 F2 */	fmuls f13, f1, f31
/* 8006C8B8  C1 5E 00 08 */	lfs f10, 8(r30)
/* 8006C8BC  EC A5 10 28 */	fsubs f5, f5, f2
/* 8006C8C0  ED 01 30 2A */	fadds f8, f1, f6
/* 8006C8C4  C1 3E 00 18 */	lfs f9, 0x18(r30)
/* 8006C8C8  EC FE 68 28 */	fsubs f7, f30, f13
/* 8006C8CC  ED A4 28 2A */	fadds f13, f4, f5
/* 8006C8D0  D1 1E 00 0C */	stfs f8, 0xc(r30)
/* 8006C8D4  EC C2 07 F2 */	fmuls f6, f2, f31
/* 8006C8D8  D0 FE 00 00 */	stfs f7, 0(r30)
/* 8006C8DC  EC E3 07 72 */	fmuls f7, f3, f29
/* 8006C8E0  EC A0 03 32 */	fmuls f5, f0, f12
/* 8006C8E4  EC 81 02 F2 */	fmuls f4, f1, f11
/* 8006C8E8  D1 BE 00 1C */	stfs f13, 0x1c(r30)
/* 8006C8EC  ED 07 30 2A */	fadds f8, f7, f6
/* 8006C8F0  EC E3 03 32 */	fmuls f7, f3, f12
/* 8006C8F4  EC C2 02 F2 */	fmuls f6, f2, f11
/* 8006C8F8  D1 1E 00 10 */	stfs f8, 0x10(r30)
/* 8006C8FC  ED 05 20 28 */	fsubs f8, f5, f4
/* 8006C900  EC A0 02 B2 */	fmuls f5, f0, f10
/* 8006C904  EC 81 02 72 */	fmuls f4, f1, f9
/* 8006C908  D1 1E 00 04 */	stfs f8, 4(r30)
/* 8006C90C  EC 02 02 72 */	fmuls f0, f2, f9
/* 8006C910  EC 23 02 B2 */	fmuls f1, f3, f10
/* 8006C914  EC C7 30 2A */	fadds f6, f7, f6
/* 8006C918  EC 45 20 28 */	fsubs f2, f5, f4
/* 8006C91C  EC 01 00 2A */	fadds f0, f1, f0
/* 8006C920  D0 DE 00 14 */	stfs f6, 0x14(r30)
/* 8006C924  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8006C928  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8006C92C  E3 E1 00 48 */	psq_l f31, 72(r1), 0, qr0
/* 8006C930  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8006C934  E3 C1 00 38 */	psq_l f30, 56(r1), 0, qr0
/* 8006C938  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 8006C93C  E3 A1 00 28 */	psq_l f29, 40(r1), 0, qr0
/* 8006C940  CB A1 00 20 */	lfd f29, 0x20(r1)
/* 8006C944  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006C948  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006C94C  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8006C950  7C 08 03 A6 */	mtlr r0
/* 8006C954  38 21 00 50 */	addi r1, r1, 0x50
/* 8006C958  4E 80 00 20 */	blr 
/* 8006C95C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006C960  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006C964  7C 08 02 A6 */	mflr r0
/* 8006C968  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006C96C  54 C0 FF 7E */	rlwinm r0, r6, 0x1f, 0x1d, 0x1f
/* 8006C970  28 00 00 07 */	cmplwi r0, 7
/* 8006C974  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006C978  7C 7F 1B 78 */	mr r31, r3
/* 8006C97C  40 82 00 0C */	bne 0xc
/* 8006C980  38 60 00 00 */	li r3, 0
/* 8006C984  48 00 00 64 */	b 0x64
/* 8006C988  2C 04 00 00 */	cmpwi r4, 0
/* 8006C98C  41 82 00 24 */	beq 0x24
/* 8006C990  3C C0 80 24 */	lis r6, 0x8024
/* 8006C994  54 00 10 3A */	slwi r0, r0, 2
/* 8006C998  38 C6 7F 00 */	addi r6, r6, 0x7f00
/* 8006C99C  7C A4 2B 78 */	mr r4, r5
/* 8006C9A0  7D 86 00 2E */	lwzx r12, r6, r0
/* 8006C9A4  7D 89 03 A6 */	mtctr r12
/* 8006C9A8  4E 80 04 21 */	bctrl 
/* 8006C9AC  48 00 00 20 */	b 0x20
/* 8006C9B0  3C C0 80 24 */	lis r6, 0x8024
/* 8006C9B4  54 00 10 3A */	slwi r0, r0, 2
/* 8006C9B8  38 C6 7F 1C */	addi r6, r6, 0x7f1c
/* 8006C9BC  7C A4 2B 78 */	mr r4, r5
/* 8006C9C0  7D 86 00 2E */	lwzx r12, r6, r0
/* 8006C9C4  7D 89 03 A6 */	mtctr r12
/* 8006C9C8  4E 80 04 21 */	bctrl 
/* 8006C9CC  C0 22 8D 68 */	lfs f1, -0x7298(r2)
/* 8006C9D0  38 60 00 01 */	li r3, 1
/* 8006C9D4  C0 02 8D 6C */	lfs f0, -0x7294(r2)
/* 8006C9D8  D0 3F 00 20 */	stfs f1, 0x20(r31)
/* 8006C9DC  D0 3F 00 24 */	stfs f1, 0x24(r31)
/* 8006C9E0  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8006C9E4  D0 3F 00 2C */	stfs f1, 0x2c(r31)
/* 8006C9E8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006C9EC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006C9F0  7C 08 03 A6 */	mtlr r0
/* 8006C9F4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006C9F8  4E 80 00 20 */	blr 
/* 8006C9FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CA00  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006CA04  7C 08 02 A6 */	mflr r0
/* 8006CA08  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006CA0C  39 61 00 40 */	addi r11, r1, 0x40
/* 8006CA10  4B FB 4B 89 */	bl -0x4b478
/* 8006CA14  83 E8 00 00 */	lwz r31, 0(r8)
/* 8006CA18  7C 79 1B 78 */	mr r25, r3
/* 8006CA1C  7C 9A 23 78 */	mr r26, r4
/* 8006CA20  7C BB 2B 78 */	mr r27, r5
/* 8006CA24  57 E0 07 BD */	rlwinm. r0, r31, 0, 0x1e, 0x1e
/* 8006CA28  7C DC 33 78 */	mr r28, r6
/* 8006CA2C  7C FD 3B 78 */	mr r29, r7
/* 8006CA30  7D 1E 43 78 */	mr r30, r8
/* 8006CA34  40 82 00 0C */	bne 0xc
/* 8006CA38  57 E0 07 7B */	rlwinm. r0, r31, 0, 0x1d, 0x1d
/* 8006CA3C  41 82 00 14 */	beq 0x14
/* 8006CA40  7F 63 DB 78 */	mr r3, r27
/* 8006CA44  7F 24 CB 78 */	mr r4, r25
/* 8006CA48  48 12 D2 E9 */	bl 0x12d2e8
/* 8006CA4C  48 00 00 E4 */	b 0xe4
/* 8006CA50  57 E0 06 B5 */	rlwinm. r0, r31, 0, 0x1a, 0x1a
/* 8006CA54  41 82 00 74 */	beq 0x74
/* 8006CA58  54 E0 00 01 */	rlwinm. r0, r7, 0, 0, 0
/* 8006CA5C  41 82 00 2C */	beq 0x2c
/* 8006CA60  C0 48 00 48 */	lfs f2, 0x48(r8)
/* 8006CA64  7F 64 DB 78 */	mr r4, r27
/* 8006CA68  C0 28 00 38 */	lfs f1, 0x38(r8)
/* 8006CA6C  38 A1 00 14 */	addi r5, r1, 0x14
/* 8006CA70  C0 08 00 28 */	lfs f0, 0x28(r8)
/* 8006CA74  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8006CA78  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 8006CA7C  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 8006CA80  48 01 8D 91 */	bl 0x18d90
/* 8006CA84  48 00 00 AC */	b 0xac
/* 8006CA88  C0 26 00 08 */	lfs f1, 8(r6)
/* 8006CA8C  7F 64 DB 78 */	mr r4, r27
/* 8006CA90  C0 08 00 48 */	lfs f0, 0x48(r8)
/* 8006CA94  38 A1 00 08 */	addi r5, r1, 8
/* 8006CA98  C0 66 00 04 */	lfs f3, 4(r6)
/* 8006CA9C  EC 81 00 32 */	fmuls f4, f1, f0
/* 8006CAA0  C0 48 00 38 */	lfs f2, 0x38(r8)
/* 8006CAA4  C0 08 00 28 */	lfs f0, 0x28(r8)
/* 8006CAA8  C0 26 00 00 */	lfs f1, 0(r6)
/* 8006CAAC  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8006CAB0  D0 81 00 10 */	stfs f4, 0x10(r1)
/* 8006CAB4  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006CAB8  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 8006CABC  D0 01 00 08 */	stfs f0, 8(r1)
/* 8006CAC0  48 01 8D 51 */	bl 0x18d50
/* 8006CAC4  48 00 00 6C */	b 0x6c
/* 8006CAC8  54 E0 00 01 */	rlwinm. r0, r7, 0, 0, 0
/* 8006CACC  41 82 00 18 */	beq 0x18
/* 8006CAD0  7F 63 DB 78 */	mr r3, r27
/* 8006CAD4  7F 25 CB 78 */	mr r5, r25
/* 8006CAD8  38 88 00 1C */	addi r4, r8, 0x1c
/* 8006CADC  48 12 D2 89 */	bl 0x12d288
/* 8006CAE0  48 00 00 50 */	b 0x50
/* 8006CAE4  7F 24 CB 78 */	mr r4, r25
/* 8006CAE8  38 68 00 1C */	addi r3, r8, 0x1c
/* 8006CAEC  48 12 D2 45 */	bl 0x12d244
/* 8006CAF0  C0 39 00 0C */	lfs f1, 0xc(r25)
/* 8006CAF4  7F 63 DB 78 */	mr r3, r27
/* 8006CAF8  C0 1C 00 00 */	lfs f0, 0(r28)
/* 8006CAFC  7F 24 CB 78 */	mr r4, r25
/* 8006CB00  C0 79 00 1C */	lfs f3, 0x1c(r25)
/* 8006CB04  7F 25 CB 78 */	mr r5, r25
/* 8006CB08  EC 81 00 32 */	fmuls f4, f1, f0
/* 8006CB0C  C0 5C 00 04 */	lfs f2, 4(r28)
/* 8006CB10  C0 39 00 2C */	lfs f1, 0x2c(r25)
/* 8006CB14  C0 1C 00 08 */	lfs f0, 8(r28)
/* 8006CB18  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8006CB1C  D0 99 00 0C */	stfs f4, 0xc(r25)
/* 8006CB20  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006CB24  D0 59 00 1C */	stfs f2, 0x1c(r25)
/* 8006CB28  D0 19 00 2C */	stfs f0, 0x2c(r25)
/* 8006CB2C  48 12 D2 39 */	bl 0x12d238
/* 8006CB30  57 E0 07 39 */	rlwinm. r0, r31, 0, 0x1c, 0x1c
/* 8006CB34  41 82 00 24 */	beq 0x24
/* 8006CB38  C0 5C 00 00 */	lfs f2, 0(r28)
/* 8006CB3C  67 A4 40 00 */	oris r4, r29, 0x4000
/* 8006CB40  C0 3C 00 04 */	lfs f1, 4(r28)
/* 8006CB44  C0 1C 00 08 */	lfs f0, 8(r28)
/* 8006CB48  D0 5A 00 00 */	stfs f2, 0(r26)
/* 8006CB4C  D0 3A 00 04 */	stfs f1, 4(r26)
/* 8006CB50  D0 1A 00 08 */	stfs f0, 8(r26)
/* 8006CB54  48 00 00 38 */	b 0x38
/* 8006CB58  C0 3C 00 00 */	lfs f1, 0(r28)
/* 8006CB5C  57 A4 00 BE */	clrlwi r4, r29, 2
/* 8006CB60  C0 1E 00 04 */	lfs f0, 4(r30)
/* 8006CB64  C0 5C 00 04 */	lfs f2, 4(r28)
/* 8006CB68  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006CB6C  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8006CB70  D0 1A 00 00 */	stfs f0, 0(r26)
/* 8006CB74  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8006CB78  EC 02 00 32 */	fmuls f0, f2, f0
/* 8006CB7C  D0 1A 00 04 */	stfs f0, 4(r26)
/* 8006CB80  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 8006CB84  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006CB88  D0 1A 00 08 */	stfs f0, 8(r26)
/* 8006CB8C  57 E0 06 F7 */	rlwinm. r0, r31, 0, 0x1b, 0x1b
/* 8006CB90  54 83 01 3E */	clrlwi r3, r4, 4
/* 8006CB94  41 82 00 08 */	beq 0x8
/* 8006CB98  64 83 10 00 */	oris r3, r4, 0x1000
/* 8006CB9C  39 61 00 40 */	addi r11, r1, 0x40
/* 8006CBA0  4B FB 4A 45 */	bl -0x4b5bc
/* 8006CBA4  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006CBA8  7C 08 03 A6 */	mtlr r0
/* 8006CBAC  38 21 00 40 */	addi r1, r1, 0x40
/* 8006CBB0  4E 80 00 20 */	blr 
/* 8006CBB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CBB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CBBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CBC0  C0 A4 00 00 */	lfs f5, 0(r4)
/* 8006CBC4  C0 02 8D 80 */	lfs f0, -0x7280(r2)
/* 8006CBC8  C0 24 00 04 */	lfs f1, 4(r4)
/* 8006CBCC  EC 40 28 28 */	fsubs f2, f0, f5
/* 8006CBD0  C0 62 8D 7C */	lfs f3, -0x7284(r2)
/* 8006CBD4  EC 00 08 28 */	fsubs f0, f0, f1
/* 8006CBD8  C0 82 8D 78 */	lfs f4, -0x7288(r2)
/* 8006CBDC  D0 A3 00 00 */	stfs f5, 0(r3)
/* 8006CBE0  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8006CBE4  EC 03 00 32 */	fmuls f0, f3, f0
/* 8006CBE8  D0 83 00 04 */	stfs f4, 4(r3)
/* 8006CBEC  D0 83 00 08 */	stfs f4, 8(r3)
/* 8006CBF0  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006CBF4  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8006CBF8  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8006CBFC  D0 83 00 18 */	stfs f4, 0x18(r3)
/* 8006CC00  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006CC04  4E 80 00 20 */	blr 
/* 8006CC08  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CC0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CC10  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006CC14  7C 08 02 A6 */	mflr r0
/* 8006CC18  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006CC1C  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006CC20  38 81 00 08 */	addi r4, r1, 8
/* 8006CC24  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006CC28  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006CC2C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006CC30  7C 7F 1B 78 */	mr r31, r3
/* 8006CC34  38 61 00 0C */	addi r3, r1, 0xc
/* 8006CC38  48 01 85 A9 */	bl 0x185a8
/* 8006CC3C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CC40  D0 1F 00 00 */	stfs f0, 0(r31)
/* 8006CC44  C0 82 8D 78 */	lfs f4, -0x7288(r2)
/* 8006CC48  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006CC4C  D0 1F 00 04 */	stfs f0, 4(r31)
/* 8006CC50  C0 62 8D 80 */	lfs f3, -0x7280(r2)
/* 8006CC54  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8006CC58  C0 42 8D 88 */	lfs f2, -0x7278(r2)
/* 8006CC5C  C0 21 00 08 */	lfs f1, 8(r1)
/* 8006CC60  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006CC64  EC 01 00 2A */	fadds f0, f1, f0
/* 8006CC68  EC 00 18 28 */	fsubs f0, f0, f3
/* 8006CC6C  EC 02 00 32 */	fmuls f0, f2, f0
/* 8006CC70  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8006CC74  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006CC78  FC 00 00 50 */	fneg f0, f0
/* 8006CC7C  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8006CC80  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CC84  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8006CC88  D0 9F 00 18 */	stfs f4, 0x18(r31)
/* 8006CC8C  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006CC90  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CC94  FC 20 08 50 */	fneg f1, f1
/* 8006CC98  EC 01 00 2A */	fadds f0, f1, f0
/* 8006CC9C  EC 00 18 28 */	fsubs f0, f0, f3
/* 8006CCA0  EC 02 00 32 */	fmuls f0, f2, f0
/* 8006CCA4  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006CCA8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006CCAC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006CCB0  7C 08 03 A6 */	mtlr r0
/* 8006CCB4  38 21 00 20 */	addi r1, r1, 0x20
/* 8006CCB8  4E 80 00 20 */	blr 
/* 8006CCBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CCC0  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 8006CCC4  C0 42 8D 78 */	lfs f2, -0x7288(r2)
/* 8006CCC8  FC 20 00 50 */	fneg f1, f0
/* 8006CCCC  C0 62 8D 80 */	lfs f3, -0x7280(r2)
/* 8006CCD0  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006CCD4  D0 63 00 00 */	stfs f3, 0(r3)
/* 8006CCD8  D0 43 00 04 */	stfs f2, 4(r3)
/* 8006CCDC  D0 43 00 08 */	stfs f2, 8(r3)
/* 8006CCE0  D0 23 00 0C */	stfs f1, 0xc(r3)
/* 8006CCE4  D0 43 00 10 */	stfs f2, 0x10(r3)
/* 8006CCE8  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006CCEC  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006CCF0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006CCF4  4E 80 00 20 */	blr 
/* 8006CCF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CCFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CD00  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006CD04  7C 08 02 A6 */	mflr r0
/* 8006CD08  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006CD0C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006CD10  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006CD14  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006CD18  7C 9F 23 78 */	mr r31, r4
/* 8006CD1C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006CD20  38 81 00 08 */	addi r4, r1, 8
/* 8006CD24  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006CD28  7C 7E 1B 78 */	mr r30, r3
/* 8006CD2C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006CD30  48 01 84 B1 */	bl 0x184b0
/* 8006CD34  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006CD38  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8006CD3C  C0 7F 00 00 */	lfs f3, 0(r31)
/* 8006CD40  C0 41 00 08 */	lfs f2, 8(r1)
/* 8006CD44  ED 20 00 72 */	fmuls f9, f0, f1
/* 8006CD48  EC E3 00 72 */	fmuls f7, f3, f1
/* 8006CD4C  C0 A2 8D 78 */	lfs f5, -0x7288(r2)
/* 8006CD50  EC C3 00 B2 */	fmuls f6, f3, f2
/* 8006CD54  C0 82 8D 80 */	lfs f4, -0x7280(r2)
/* 8006CD58  ED 00 00 B2 */	fmuls f8, f0, f2
/* 8006CD5C  FC 20 48 50 */	fneg f1, f9
/* 8006CD60  EC 46 38 2A */	fadds f2, f6, f7
/* 8006CD64  C0 62 8D 88 */	lfs f3, -0x7278(r2)
/* 8006CD68  D0 DE 00 00 */	stfs f6, 0(r30)
/* 8006CD6C  EC 01 40 2A */	fadds f0, f1, f8
/* 8006CD70  EC 42 20 28 */	fsubs f2, f2, f4
/* 8006CD74  D0 FE 00 04 */	stfs f7, 4(r30)
/* 8006CD78  EC 00 20 28 */	fsubs f0, f0, f4
/* 8006CD7C  D0 BE 00 08 */	stfs f5, 8(r30)
/* 8006CD80  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8006CD84  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 8006CD88  EC 03 00 32 */	fmuls f0, f3, f0
/* 8006CD8C  D0 5E 00 0C */	stfs f2, 0xc(r30)
/* 8006CD90  D1 1E 00 14 */	stfs f8, 0x14(r30)
/* 8006CD94  D0 BE 00 18 */	stfs f5, 0x18(r30)
/* 8006CD98  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006CD9C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006CDA0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006CDA4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006CDA8  7C 08 03 A6 */	mtlr r0
/* 8006CDAC  38 21 00 20 */	addi r1, r1, 0x20
/* 8006CDB0  4E 80 00 20 */	blr 
/* 8006CDB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CDB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CDBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CDC0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006CDC4  7C 08 02 A6 */	mflr r0
/* 8006CDC8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006CDCC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006CDD0  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006CDD4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006CDD8  7C 9F 23 78 */	mr r31, r4
/* 8006CDDC  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006CDE0  38 81 00 08 */	addi r4, r1, 8
/* 8006CDE4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006CDE8  7C 7E 1B 78 */	mr r30, r3
/* 8006CDEC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006CDF0  48 01 83 F1 */	bl 0x183f0
/* 8006CDF4  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CDF8  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8006CDFC  C0 C2 8D 78 */	lfs f6, -0x7288(r2)
/* 8006CE00  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006CE04  D0 1E 00 04 */	stfs f0, 4(r30)
/* 8006CE08  C0 82 8D 7C */	lfs f4, -0x7284(r2)
/* 8006CE0C  D0 DE 00 08 */	stfs f6, 8(r30)
/* 8006CE10  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8006CE14  C0 41 00 08 */	lfs f2, 8(r1)
/* 8006CE18  EC 64 00 2A */	fadds f3, f4, f0
/* 8006CE1C  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8006CE20  FC A0 10 50 */	fneg f5, f2
/* 8006CE24  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006CE28  EC 41 20 28 */	fsubs f2, f1, f4
/* 8006CE2C  EC 25 00 F2 */	fmuls f1, f5, f3
/* 8006CE30  EC 00 00 B2 */	fmuls f0, f0, f2
/* 8006CE34  EC 01 00 2A */	fadds f0, f1, f0
/* 8006CE38  EC 04 00 2A */	fadds f0, f4, f0
/* 8006CE3C  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8006CE40  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006CE44  FC 00 00 50 */	fneg f0, f0
/* 8006CE48  D0 1E 00 10 */	stfs f0, 0x10(r30)
/* 8006CE4C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CE50  D0 1E 00 14 */	stfs f0, 0x14(r30)
/* 8006CE54  D0 DE 00 18 */	stfs f6, 0x18(r30)
/* 8006CE58  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006CE5C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CE60  EC 21 00 F2 */	fmuls f1, f1, f3
/* 8006CE64  EC 00 00 B2 */	fmuls f0, f0, f2
/* 8006CE68  EC 01 00 2A */	fadds f0, f1, f0
/* 8006CE6C  EC 04 00 2A */	fadds f0, f4, f0
/* 8006CE70  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006CE74  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006CE78  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006CE7C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006CE80  7C 08 03 A6 */	mtlr r0
/* 8006CE84  38 21 00 20 */	addi r1, r1, 0x20
/* 8006CE88  4E 80 00 20 */	blr 
/* 8006CE8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CE90  C0 C4 00 00 */	lfs f6, 0(r4)
/* 8006CE94  C0 62 8D 7C */	lfs f3, -0x7284(r2)
/* 8006CE98  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 8006CE9C  FC 80 30 50 */	fneg f4, f6
/* 8006CEA0  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006CEA4  EC 43 08 2A */	fadds f2, f3, f1
/* 8006CEA8  C0 24 00 04 */	lfs f1, 4(r4)
/* 8006CEAC  EC 00 18 28 */	fsubs f0, f0, f3
/* 8006CEB0  C0 A2 8D 78 */	lfs f5, -0x7288(r2)
/* 8006CEB4  D0 C3 00 00 */	stfs f6, 0(r3)
/* 8006CEB8  EC 44 00 B2 */	fmuls f2, f4, f2
/* 8006CEBC  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006CEC0  D0 A3 00 04 */	stfs f5, 4(r3)
/* 8006CEC4  EC 43 10 2A */	fadds f2, f3, f2
/* 8006CEC8  D0 A3 00 08 */	stfs f5, 8(r3)
/* 8006CECC  EC 03 00 2A */	fadds f0, f3, f0
/* 8006CED0  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006CED4  D0 A3 00 10 */	stfs f5, 0x10(r3)
/* 8006CED8  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8006CEDC  D0 A3 00 18 */	stfs f5, 0x18(r3)
/* 8006CEE0  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006CEE4  4E 80 00 20 */	blr 
/* 8006CEE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CEEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CEF0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006CEF4  7C 08 02 A6 */	mflr r0
/* 8006CEF8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006CEFC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006CF00  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006CF04  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006CF08  7C 9F 23 78 */	mr r31, r4
/* 8006CF0C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006CF10  38 81 00 08 */	addi r4, r1, 8
/* 8006CF14  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006CF18  7C 7E 1B 78 */	mr r30, r3
/* 8006CF1C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006CF20  48 01 82 C1 */	bl 0x182c0
/* 8006CF24  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8006CF28  C0 01 00 08 */	lfs f0, 8(r1)
/* 8006CF2C  C0 61 00 0C */	lfs f3, 0xc(r1)
/* 8006CF30  C0 5F 00 04 */	lfs f2, 4(r31)
/* 8006CF34  EC A1 00 32 */	fmuls f5, f1, f0
/* 8006CF38  EC E1 00 F2 */	fmuls f7, f1, f3
/* 8006CF3C  C0 82 8D 7C */	lfs f4, -0x7284(r2)
/* 8006CF40  ED 02 00 32 */	fmuls f8, f2, f0
/* 8006CF44  D0 BE 00 00 */	stfs f5, 0(r30)
/* 8006CF48  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8006CF4C  ED 22 00 F2 */	fmuls f9, f2, f3
/* 8006CF50  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8006CF54  EC 64 08 2A */	fadds f3, f4, f1
/* 8006CF58  FC A0 28 50 */	fneg f5, f5
/* 8006CF5C  C0 C2 8D 78 */	lfs f6, -0x7288(r2)
/* 8006CF60  EC 40 20 28 */	fsubs f2, f0, f4
/* 8006CF64  EC 29 00 F2 */	fmuls f1, f9, f3
/* 8006CF68  D0 FE 00 04 */	stfs f7, 4(r30)
/* 8006CF6C  EC 65 00 F2 */	fmuls f3, f5, f3
/* 8006CF70  EC 08 00 B2 */	fmuls f0, f8, f2
/* 8006CF74  D0 DE 00 08 */	stfs f6, 8(r30)
/* 8006CF78  EC 47 00 B2 */	fmuls f2, f7, f2
/* 8006CF7C  D1 1E 00 14 */	stfs f8, 0x14(r30)
/* 8006CF80  EC 01 00 2A */	fadds f0, f1, f0
/* 8006CF84  FC 20 48 50 */	fneg f1, f9
/* 8006CF88  D0 DE 00 18 */	stfs f6, 0x18(r30)
/* 8006CF8C  EC 43 10 2A */	fadds f2, f3, f2
/* 8006CF90  EC 04 00 2A */	fadds f0, f4, f0
/* 8006CF94  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 8006CF98  EC 24 10 2A */	fadds f1, f4, f2
/* 8006CF9C  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006CFA0  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 8006CFA4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006CFA8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006CFAC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006CFB0  7C 08 03 A6 */	mtlr r0
/* 8006CFB4  38 21 00 20 */	addi r1, r1, 0x20
/* 8006CFB8  4E 80 00 20 */	blr 
/* 8006CFBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006CFC0  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 8006CFC4  C0 C2 8D 7C */	lfs f6, -0x7284(r2)
/* 8006CFC8  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 8006CFCC  EC 21 30 28 */	fsubs f1, f1, f6
/* 8006CFD0  C1 44 00 00 */	lfs f10, 0(r4)
/* 8006CFD4  C0 43 00 00 */	lfs f2, 0(r3)
/* 8006CFD8  EC 00 30 28 */	fsubs f0, f0, f6
/* 8006CFDC  C0 84 00 04 */	lfs f4, 4(r4)
/* 8006CFE0  EC AA 00 72 */	fmuls f5, f10, f1
/* 8006CFE4  ED 22 02 B2 */	fmuls f9, f2, f10
/* 8006CFE8  C1 03 00 04 */	lfs f8, 4(r3)
/* 8006CFEC  EC 04 00 32 */	fmuls f0, f4, f0
/* 8006CFF0  C0 E3 00 08 */	lfs f7, 8(r3)
/* 8006CFF4  C0 63 00 10 */	lfs f3, 0x10(r3)
/* 8006CFF8  C0 43 00 14 */	lfs f2, 0x14(r3)
/* 8006CFFC  C0 23 00 18 */	lfs f1, 0x18(r3)
/* 8006D000  ED 08 02 B2 */	fmuls f8, f8, f10
/* 8006D004  EC E7 02 B2 */	fmuls f7, f7, f10
/* 8006D008  D1 23 00 00 */	stfs f9, 0(r3)
/* 8006D00C  EC A6 28 2A */	fadds f5, f6, f5
/* 8006D010  EC 63 01 32 */	fmuls f3, f3, f4
/* 8006D014  D1 03 00 04 */	stfs f8, 4(r3)
/* 8006D018  EC 42 01 32 */	fmuls f2, f2, f4
/* 8006D01C  EC 21 01 32 */	fmuls f1, f1, f4
/* 8006D020  D0 E3 00 08 */	stfs f7, 8(r3)
/* 8006D024  EC 06 00 2A */	fadds f0, f6, f0
/* 8006D028  D0 A3 00 0C */	stfs f5, 0xc(r3)
/* 8006D02C  D0 63 00 10 */	stfs f3, 0x10(r3)
/* 8006D030  D0 43 00 14 */	stfs f2, 0x14(r3)
/* 8006D034  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 8006D038  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006D03C  4E 80 00 20 */	blr 
/* 8006D040  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006D044  7C 08 02 A6 */	mflr r0
/* 8006D048  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006D04C  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006D050  38 81 00 08 */	addi r4, r1, 8
/* 8006D054  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006D058  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006D05C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006D060  7C 7F 1B 78 */	mr r31, r3
/* 8006D064  38 61 00 0C */	addi r3, r1, 0xc
/* 8006D068  48 01 81 79 */	bl 0x18178
/* 8006D06C  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006D070  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8006D074  FC 20 10 50 */	fneg f1, f2
/* 8006D078  C0 9F 00 00 */	lfs f4, 0(r31)
/* 8006D07C  C0 61 00 08 */	lfs f3, 8(r1)
/* 8006D080  EC 42 00 32 */	fmuls f2, f2, f0
/* 8006D084  C0 E2 8D 7C */	lfs f7, -0x7284(r2)
/* 8006D088  EC 03 00 32 */	fmuls f0, f3, f0
/* 8006D08C  EC 63 01 32 */	fmuls f3, f3, f4
/* 8006D090  C1 5F 00 04 */	lfs f10, 4(r31)
/* 8006D094  EC 21 01 32 */	fmuls f1, f1, f4
/* 8006D098  C0 BF 00 14 */	lfs f5, 0x14(r31)
/* 8006D09C  C1 1F 00 08 */	lfs f8, 8(r31)
/* 8006D0A0  EC 43 10 2A */	fadds f2, f3, f2
/* 8006D0A4  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D0A8  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8006D0AC  D0 5F 00 00 */	stfs f2, 0(r31)
/* 8006D0B0  EC C1 38 28 */	fsubs f6, f1, f7
/* 8006D0B4  C0 9F 00 18 */	lfs f4, 0x18(r31)
/* 8006D0B8  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8006D0BC  C0 1F 00 1C */	lfs f0, 0x1c(r31)
/* 8006D0C0  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006D0C4  EC 60 38 28 */	fsubs f3, f0, f7
/* 8006D0C8  C1 61 00 08 */	lfs f11, 8(r1)
/* 8006D0CC  FC 00 08 50 */	fneg f0, f1
/* 8006D0D0  EC 41 01 72 */	fmuls f2, f1, f5
/* 8006D0D4  ED 2B 02 B2 */	fmuls f9, f11, f10
/* 8006D0D8  EC 20 02 B2 */	fmuls f1, f0, f10
/* 8006D0DC  EC 0B 01 72 */	fmuls f0, f11, f5
/* 8006D0E0  EC 49 10 2A */	fadds f2, f9, f2
/* 8006D0E4  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D0E8  D0 5F 00 04 */	stfs f2, 4(r31)
/* 8006D0EC  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8006D0F0  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006D0F4  C1 21 00 08 */	lfs f9, 8(r1)
/* 8006D0F8  FC 00 08 50 */	fneg f0, f1
/* 8006D0FC  EC 41 01 32 */	fmuls f2, f1, f4
/* 8006D100  EC A9 02 32 */	fmuls f5, f9, f8
/* 8006D104  EC 20 02 32 */	fmuls f1, f0, f8
/* 8006D108  EC 09 01 32 */	fmuls f0, f9, f4
/* 8006D10C  EC 45 10 2A */	fadds f2, f5, f2
/* 8006D110  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D114  D0 5F 00 08 */	stfs f2, 8(r31)
/* 8006D118  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 8006D11C  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006D120  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006D124  FC 00 08 50 */	fneg f0, f1
/* 8006D128  EC 41 00 F2 */	fmuls f2, f1, f3
/* 8006D12C  EC 85 01 B2 */	fmuls f4, f5, f6
/* 8006D130  EC 20 01 B2 */	fmuls f1, f0, f6
/* 8006D134  EC 05 00 F2 */	fmuls f0, f5, f3
/* 8006D138  EC 44 10 2A */	fadds f2, f4, f2
/* 8006D13C  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D140  EC 27 10 2A */	fadds f1, f7, f2
/* 8006D144  EC 07 00 2A */	fadds f0, f7, f0
/* 8006D148  D0 3F 00 0C */	stfs f1, 0xc(r31)
/* 8006D14C  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 8006D150  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006D154  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006D158  7C 08 03 A6 */	mtlr r0
/* 8006D15C  38 21 00 20 */	addi r1, r1, 0x20
/* 8006D160  4E 80 00 20 */	blr 
/* 8006D164  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D168  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D16C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D170  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 8006D174  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 8006D178  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 8006D17C  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006D180  EC 43 10 28 */	fsubs f2, f3, f2
/* 8006D184  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D188  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8006D18C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006D190  4E 80 00 20 */	blr 
/* 8006D194  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D198  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D19C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D1A0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006D1A4  7C 08 02 A6 */	mflr r0
/* 8006D1A8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006D1AC  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8006D1B0  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 8006D1B4  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 8006D1B8  F3 C1 00 28 */	psq_st f30, 40(r1), 0, qr0
/* 8006D1BC  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006D1C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006D1C4  7C 9F 23 78 */	mr r31, r4
/* 8006D1C8  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006D1CC  38 81 00 08 */	addi r4, r1, 8
/* 8006D1D0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006D1D4  7C 7E 1B 78 */	mr r30, r3
/* 8006D1D8  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006D1DC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006D1E0  48 01 80 01 */	bl 0x18000
/* 8006D1E4  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8006D1E8  C0 BF 00 04 */	lfs f5, 4(r31)
/* 8006D1EC  C0 5F 00 00 */	lfs f2, 0(r31)
/* 8006D1F0  ED 05 00 32 */	fmuls f8, f5, f0
/* 8006D1F4  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8006D1F8  EC 22 00 32 */	fmuls f1, f2, f0
/* 8006D1FC  C0 7E 00 0C */	lfs f3, 0xc(r30)
/* 8006D200  C0 E2 8D 7C */	lfs f7, -0x7284(r2)
/* 8006D204  EC 02 01 B2 */	fmuls f0, f2, f6
/* 8006D208  FD 80 40 50 */	fneg f12, f8
/* 8006D20C  C0 5E 00 1C */	lfs f2, 0x1c(r30)
/* 8006D210  EC 83 38 28 */	fsubs f4, f3, f7
/* 8006D214  C3 DE 00 00 */	lfs f30, 0(r30)
/* 8006D218  EC 62 38 28 */	fsubs f3, f2, f7
/* 8006D21C  C1 BE 00 10 */	lfs f13, 0x10(r30)
/* 8006D220  EC 45 01 B2 */	fmuls f2, f5, f6
/* 8006D224  C1 7E 00 04 */	lfs f11, 4(r30)
/* 8006D228  EC C0 01 32 */	fmuls f6, f0, f4
/* 8006D22C  C1 5E 00 14 */	lfs f10, 0x14(r30)
/* 8006D230  EC A1 00 F2 */	fmuls f5, f1, f3
/* 8006D234  C1 3E 00 08 */	lfs f9, 8(r30)
/* 8006D238  EC 8C 01 32 */	fmuls f4, f12, f4
/* 8006D23C  C1 1E 00 18 */	lfs f8, 0x18(r30)
/* 8006D240  EC 62 00 F2 */	fmuls f3, f2, f3
/* 8006D244  EC A6 28 2A */	fadds f5, f6, f5
/* 8006D248  EF E0 07 B2 */	fmuls f31, f0, f30
/* 8006D24C  EC C1 03 72 */	fmuls f6, f1, f13
/* 8006D250  EC 64 18 2A */	fadds f3, f4, f3
/* 8006D254  EC 87 28 2A */	fadds f4, f7, f5
/* 8006D258  EF FF 30 2A */	fadds f31, f31, f6
/* 8006D25C  EC E7 18 2A */	fadds f7, f7, f3
/* 8006D260  D0 9E 00 0C */	stfs f4, 0xc(r30)
/* 8006D264  EC CC 07 B2 */	fmuls f6, f12, f30
/* 8006D268  EC A2 03 72 */	fmuls f5, f2, f13
/* 8006D26C  D0 FE 00 1C */	stfs f7, 0x1c(r30)
/* 8006D270  EC 80 02 F2 */	fmuls f4, f0, f11
/* 8006D274  EC 61 02 B2 */	fmuls f3, f1, f10
/* 8006D278  D3 FE 00 00 */	stfs f31, 0(r30)
/* 8006D27C  EC E6 28 2A */	fadds f7, f6, f5
/* 8006D280  EC CC 02 F2 */	fmuls f6, f12, f11
/* 8006D284  EC A2 02 B2 */	fmuls f5, f2, f10
/* 8006D288  D0 FE 00 10 */	stfs f7, 0x10(r30)
/* 8006D28C  EC E4 18 2A */	fadds f7, f4, f3
/* 8006D290  EC 80 02 72 */	fmuls f4, f0, f9
/* 8006D294  EC 61 02 32 */	fmuls f3, f1, f8
/* 8006D298  D0 FE 00 04 */	stfs f7, 4(r30)
/* 8006D29C  EC 02 02 32 */	fmuls f0, f2, f8
/* 8006D2A0  EC 2C 02 72 */	fmuls f1, f12, f9
/* 8006D2A4  EC A6 28 2A */	fadds f5, f6, f5
/* 8006D2A8  EC 44 18 2A */	fadds f2, f4, f3
/* 8006D2AC  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D2B0  D0 BE 00 14 */	stfs f5, 0x14(r30)
/* 8006D2B4  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8006D2B8  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8006D2BC  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 8006D2C0  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8006D2C4  E3 C1 00 28 */	psq_l f30, 40(r1), 0, qr0
/* 8006D2C8  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 8006D2CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006D2D0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006D2D4  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006D2D8  7C 08 03 A6 */	mtlr r0
/* 8006D2DC  38 21 00 40 */	addi r1, r1, 0x40
/* 8006D2E0  4E 80 00 20 */	blr 
/* 8006D2E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D2E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D2EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D2F0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006D2F4  7C 08 02 A6 */	mflr r0
/* 8006D2F8  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006D2FC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006D300  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006D304  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006D308  7C 9F 23 78 */	mr r31, r4
/* 8006D30C  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006D310  38 81 00 08 */	addi r4, r1, 8
/* 8006D314  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006D318  7C 7E 1B 78 */	mr r30, r3
/* 8006D31C  38 61 00 0C */	addi r3, r1, 0xc
/* 8006D320  48 01 7E C1 */	bl 0x17ec0
/* 8006D324  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006D328  C0 1E 00 10 */	lfs f0, 0x10(r30)
/* 8006D32C  FC 20 10 50 */	fneg f1, f2
/* 8006D330  C0 9E 00 00 */	lfs f4, 0(r30)
/* 8006D334  C0 61 00 08 */	lfs f3, 8(r1)
/* 8006D338  EC 42 00 32 */	fmuls f2, f2, f0
/* 8006D33C  C1 7E 00 04 */	lfs f11, 4(r30)
/* 8006D340  EC 03 00 32 */	fmuls f0, f3, f0
/* 8006D344  EC 63 01 32 */	fmuls f3, f3, f4
/* 8006D348  C1 3E 00 14 */	lfs f9, 0x14(r30)
/* 8006D34C  EC 21 01 32 */	fmuls f1, f1, f4
/* 8006D350  C0 E2 8D 7C */	lfs f7, -0x7284(r2)
/* 8006D354  C1 1E 00 08 */	lfs f8, 8(r30)
/* 8006D358  EC 63 10 2A */	fadds f3, f3, f2
/* 8006D35C  EC 21 00 2A */	fadds f1, f1, f0
/* 8006D360  C0 5E 00 0C */	lfs f2, 0xc(r30)
/* 8006D364  D0 7E 00 00 */	stfs f3, 0(r30)
/* 8006D368  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8006D36C  D0 3E 00 10 */	stfs f1, 0x10(r30)
/* 8006D370  EC 42 00 28 */	fsubs f2, f2, f0
/* 8006D374  C0 3E 00 1C */	lfs f1, 0x1c(r30)
/* 8006D378  C0 A1 00 0C */	lfs f5, 0xc(r1)
/* 8006D37C  C1 81 00 08 */	lfs f12, 8(r1)
/* 8006D380  FC 60 28 50 */	fneg f3, f5
/* 8006D384  C0 1F 00 10 */	lfs f0, 0x10(r31)
/* 8006D388  EC C5 02 72 */	fmuls f6, f5, f9
/* 8006D38C  C0 9E 00 18 */	lfs f4, 0x18(r30)
/* 8006D390  ED 4C 02 F2 */	fmuls f10, f12, f11
/* 8006D394  EC A3 02 F2 */	fmuls f5, f3, f11
/* 8006D398  EC 6C 02 72 */	fmuls f3, f12, f9
/* 8006D39C  EC CA 30 2A */	fadds f6, f10, f6
/* 8006D3A0  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D3A4  EC 25 18 2A */	fadds f1, f5, f3
/* 8006D3A8  D0 DE 00 04 */	stfs f6, 4(r30)
/* 8006D3AC  EC C2 38 28 */	fsubs f6, f2, f7
/* 8006D3B0  D0 3E 00 14 */	stfs f1, 0x14(r30)
/* 8006D3B4  EC 60 38 28 */	fsubs f3, f0, f7
/* 8006D3B8  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006D3BC  C1 21 00 08 */	lfs f9, 8(r1)
/* 8006D3C0  FC 00 08 50 */	fneg f0, f1
/* 8006D3C4  EC 41 01 32 */	fmuls f2, f1, f4
/* 8006D3C8  EC A9 02 32 */	fmuls f5, f9, f8
/* 8006D3CC  EC 20 02 32 */	fmuls f1, f0, f8
/* 8006D3D0  EC 09 01 32 */	fmuls f0, f9, f4
/* 8006D3D4  EC 45 10 2A */	fadds f2, f5, f2
/* 8006D3D8  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D3DC  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8006D3E0  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8006D3E4  C0 21 00 0C */	lfs f1, 0xc(r1)
/* 8006D3E8  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8006D3EC  FC 00 08 50 */	fneg f0, f1
/* 8006D3F0  EC 41 00 F2 */	fmuls f2, f1, f3
/* 8006D3F4  EC 85 01 B2 */	fmuls f4, f5, f6
/* 8006D3F8  EC 20 01 B2 */	fmuls f1, f0, f6
/* 8006D3FC  EC 05 00 F2 */	fmuls f0, f5, f3
/* 8006D400  EC 44 10 2A */	fadds f2, f4, f2
/* 8006D404  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D408  EC 27 10 2A */	fadds f1, f7, f2
/* 8006D40C  EC 07 00 2A */	fadds f0, f7, f0
/* 8006D410  D0 3E 00 0C */	stfs f1, 0xc(r30)
/* 8006D414  D0 1E 00 1C */	stfs f0, 0x1c(r30)
/* 8006D418  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006D41C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006D420  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006D424  7C 08 03 A6 */	mtlr r0
/* 8006D428  38 21 00 20 */	addi r1, r1, 0x20
/* 8006D42C  4E 80 00 20 */	blr 
/* 8006D430  C0 23 00 1C */	lfs f1, 0x1c(r3)
/* 8006D434  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8006D438  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 8006D43C  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 8006D440  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D444  C0 E2 8D 7C */	lfs f7, -0x7284(r2)
/* 8006D448  EC 83 10 28 */	fsubs f4, f3, f2
/* 8006D44C  C0 A4 00 04 */	lfs f5, 4(r4)
/* 8006D450  EC 00 38 28 */	fsubs f0, f0, f7
/* 8006D454  C0 63 00 14 */	lfs f3, 0x14(r3)
/* 8006D458  C0 43 00 10 */	lfs f2, 0x10(r3)
/* 8006D45C  EC C4 38 28 */	fsubs f6, f4, f7
/* 8006D460  EC 05 00 32 */	fmuls f0, f5, f0
/* 8006D464  C1 64 00 00 */	lfs f11, 0(r4)
/* 8006D468  EC 82 01 72 */	fmuls f4, f2, f5
/* 8006D46C  C1 03 00 00 */	lfs f8, 0(r3)
/* 8006D470  EC 4B 01 B2 */	fmuls f2, f11, f6
/* 8006D474  ED 48 02 F2 */	fmuls f10, f8, f11
/* 8006D478  EC 07 00 2A */	fadds f0, f7, f0
/* 8006D47C  C1 23 00 04 */	lfs f9, 4(r3)
/* 8006D480  EC C7 10 2A */	fadds f6, f7, f2
/* 8006D484  C1 03 00 08 */	lfs f8, 8(r3)
/* 8006D488  C0 43 00 18 */	lfs f2, 0x18(r3)
/* 8006D48C  ED 29 02 F2 */	fmuls f9, f9, f11
/* 8006D490  EC E8 02 F2 */	fmuls f7, f8, f11
/* 8006D494  D1 43 00 00 */	stfs f10, 0(r3)
/* 8006D498  EC 63 01 72 */	fmuls f3, f3, f5
/* 8006D49C  EC 42 01 72 */	fmuls f2, f2, f5
/* 8006D4A0  D1 23 00 04 */	stfs f9, 4(r3)
/* 8006D4A4  EC 01 00 32 */	fmuls f0, f1, f0
/* 8006D4A8  D0 E3 00 08 */	stfs f7, 8(r3)
/* 8006D4AC  D0 C3 00 0C */	stfs f6, 0xc(r3)
/* 8006D4B0  D0 83 00 10 */	stfs f4, 0x10(r3)
/* 8006D4B4  D0 63 00 14 */	stfs f3, 0x14(r3)
/* 8006D4B8  D0 43 00 18 */	stfs f2, 0x18(r3)
/* 8006D4BC  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8006D4C0  4E 80 00 20 */	blr 
/* 8006D4C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D4C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D4CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D4D0  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8006D4D4  7C 08 02 A6 */	mflr r0
/* 8006D4D8  90 01 00 54 */	stw r0, 0x54(r1)
/* 8006D4DC  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8006D4E0  F3 E1 00 48 */	psq_st f31, 72(r1), 0, qr0
/* 8006D4E4  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 8006D4E8  F3 C1 00 38 */	psq_st f30, 56(r1), 0, qr0
/* 8006D4EC  DB A1 00 20 */	stfd f29, 0x20(r1)
/* 8006D4F0  F3 A1 00 28 */	psq_st f29, 40(r1), 0, qr0
/* 8006D4F4  C0 24 00 08 */	lfs f1, 8(r4)
/* 8006D4F8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006D4FC  7C 9F 23 78 */	mr r31, r4
/* 8006D500  C0 02 8D 84 */	lfs f0, -0x727c(r2)
/* 8006D504  38 81 00 08 */	addi r4, r1, 8
/* 8006D508  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006D50C  7C 7E 1B 78 */	mr r30, r3
/* 8006D510  EC 20 00 72 */	fmuls f1, f0, f1
/* 8006D514  38 61 00 0C */	addi r3, r1, 0xc
/* 8006D518  48 01 7C C9 */	bl 0x17cc8
/* 8006D51C  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8006D520  C0 BF 00 04 */	lfs f5, 4(r31)
/* 8006D524  C0 3E 00 0C */	lfs f1, 0xc(r30)
/* 8006D528  C0 1F 00 0C */	lfs f0, 0xc(r31)
/* 8006D52C  ED 25 00 B2 */	fmuls f9, f5, f2
/* 8006D530  C1 1F 00 00 */	lfs f8, 0(r31)
/* 8006D534  EC 81 00 28 */	fsubs f4, f1, f0
/* 8006D538  C0 C1 00 08 */	lfs f6, 8(r1)
/* 8006D53C  EC 28 00 B2 */	fmuls f1, f8, f2
/* 8006D540  C0 E2 8D 7C */	lfs f7, -0x7284(r2)
/* 8006D544  EC 08 01 B2 */	fmuls f0, f8, f6
/* 8006D548  C0 7E 00 1C */	lfs f3, 0x1c(r30)
/* 8006D54C  C0 5F 00 10 */	lfs f2, 0x10(r31)
/* 8006D550  FD 80 48 50 */	fneg f12, f9
/* 8006D554  C3 BE 00 00 */	lfs f29, 0(r30)
/* 8006D558  EC 84 38 28 */	fsubs f4, f4, f7
/* 8006D55C  EC 63 10 2A */	fadds f3, f3, f2
/* 8006D560  C3 FE 00 10 */	lfs f31, 0x10(r30)
/* 8006D564  EC 45 01 B2 */	fmuls f2, f5, f6
/* 8006D568  EC C0 01 32 */	fmuls f6, f0, f4
/* 8006D56C  C1 7E 00 04 */	lfs f11, 4(r30)
/* 8006D570  EC 63 38 28 */	fsubs f3, f3, f7
/* 8006D574  EC 8C 01 32 */	fmuls f4, f12, f4
/* 8006D578  C1 5E 00 14 */	lfs f10, 0x14(r30)
/* 8006D57C  EF C0 07 72 */	fmuls f30, f0, f29
/* 8006D580  EC A1 00 F2 */	fmuls f5, f1, f3
/* 8006D584  C1 3E 00 08 */	lfs f9, 8(r30)
/* 8006D588  EC 62 00 F2 */	fmuls f3, f2, f3
/* 8006D58C  ED A1 07 F2 */	fmuls f13, f1, f31
/* 8006D590  C1 1E 00 18 */	lfs f8, 0x18(r30)
/* 8006D594  EC A6 28 2A */	fadds f5, f6, f5
/* 8006D598  EC 64 18 2A */	fadds f3, f4, f3
/* 8006D59C  EC DE 68 2A */	fadds f6, f30, f13
/* 8006D5A0  EC 87 28 2A */	fadds f4, f7, f5
/* 8006D5A4  EC E7 18 2A */	fadds f7, f7, f3
/* 8006D5A8  D0 DE 00 00 */	stfs f6, 0(r30)
/* 8006D5AC  EC CC 07 72 */	fmuls f6, f12, f29
/* 8006D5B0  D0 9E 00 0C */	stfs f4, 0xc(r30)
/* 8006D5B4  EC A2 07 F2 */	fmuls f5, f2, f31
/* 8006D5B8  EC 80 02 F2 */	fmuls f4, f0, f11
/* 8006D5BC  D0 FE 00 1C */	stfs f7, 0x1c(r30)
/* 8006D5C0  EC 61 02 B2 */	fmuls f3, f1, f10
/* 8006D5C4  EC E6 28 2A */	fadds f7, f6, f5
/* 8006D5C8  EC CC 02 F2 */	fmuls f6, f12, f11
/* 8006D5CC  EC A2 02 B2 */	fmuls f5, f2, f10
/* 8006D5D0  D0 FE 00 10 */	stfs f7, 0x10(r30)
/* 8006D5D4  EC E4 18 2A */	fadds f7, f4, f3
/* 8006D5D8  EC 80 02 72 */	fmuls f4, f0, f9
/* 8006D5DC  EC 61 02 32 */	fmuls f3, f1, f8
/* 8006D5E0  D0 FE 00 04 */	stfs f7, 4(r30)
/* 8006D5E4  EC 02 02 32 */	fmuls f0, f2, f8
/* 8006D5E8  EC 2C 02 72 */	fmuls f1, f12, f9
/* 8006D5EC  EC A6 28 2A */	fadds f5, f6, f5
/* 8006D5F0  EC 44 18 2A */	fadds f2, f4, f3
/* 8006D5F4  EC 01 00 2A */	fadds f0, f1, f0
/* 8006D5F8  D0 BE 00 14 */	stfs f5, 0x14(r30)
/* 8006D5FC  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8006D600  D0 1E 00 18 */	stfs f0, 0x18(r30)
/* 8006D604  E3 E1 00 48 */	psq_l f31, 72(r1), 0, qr0
/* 8006D608  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8006D60C  E3 C1 00 38 */	psq_l f30, 56(r1), 0, qr0
/* 8006D610  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 8006D614  E3 A1 00 28 */	psq_l f29, 40(r1), 0, qr0
/* 8006D618  CB A1 00 20 */	lfd f29, 0x20(r1)
/* 8006D61C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006D620  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006D624  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8006D628  7C 08 03 A6 */	mtlr r0
/* 8006D62C  38 21 00 50 */	addi r1, r1, 0x50
/* 8006D630  4E 80 00 20 */	blr 
/* 8006D634  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D638  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D63C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D640  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006D644  7C 08 02 A6 */	mflr r0
/* 8006D648  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006D64C  54 C0 FF 7E */	rlwinm r0, r6, 0x1f, 0x1d, 0x1f
/* 8006D650  28 00 00 07 */	cmplwi r0, 7
/* 8006D654  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006D658  7C 7F 1B 78 */	mr r31, r3
/* 8006D65C  40 82 00 0C */	bne 0xc
/* 8006D660  38 60 00 00 */	li r3, 0
/* 8006D664  48 00 00 64 */	b 0x64
/* 8006D668  2C 04 00 00 */	cmpwi r4, 0
/* 8006D66C  41 82 00 24 */	beq 0x24
/* 8006D670  3C C0 80 24 */	lis r6, 0x8024
/* 8006D674  54 00 10 3A */	slwi r0, r0, 2
/* 8006D678  38 C6 7F 38 */	addi r6, r6, 0x7f38
/* 8006D67C  7C A4 2B 78 */	mr r4, r5
/* 8006D680  7D 86 00 2E */	lwzx r12, r6, r0
/* 8006D684  7D 89 03 A6 */	mtctr r12
/* 8006D688  4E 80 04 21 */	bctrl 
/* 8006D68C  48 00 00 20 */	b 0x20
/* 8006D690  3C C0 80 24 */	lis r6, 0x8024
/* 8006D694  54 00 10 3A */	slwi r0, r0, 2
/* 8006D698  38 C6 7F 54 */	addi r6, r6, 0x7f54
/* 8006D69C  7C A4 2B 78 */	mr r4, r5
/* 8006D6A0  7D 86 00 2E */	lwzx r12, r6, r0
/* 8006D6A4  7D 89 03 A6 */	mtctr r12
/* 8006D6A8  4E 80 04 21 */	bctrl 
/* 8006D6AC  C0 22 8D 78 */	lfs f1, -0x7288(r2)
/* 8006D6B0  38 60 00 01 */	li r3, 1
/* 8006D6B4  C0 02 8D 80 */	lfs f0, -0x7280(r2)
/* 8006D6B8  D0 3F 00 20 */	stfs f1, 0x20(r31)
/* 8006D6BC  D0 3F 00 24 */	stfs f1, 0x24(r31)
/* 8006D6C0  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8006D6C4  D0 3F 00 2C */	stfs f1, 0x2c(r31)
/* 8006D6C8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006D6CC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006D6D0  7C 08 03 A6 */	mtlr r0
/* 8006D6D4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006D6D8  4E 80 00 20 */	blr 
/* 8006D6DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D6E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006D6E4  7C 08 02 A6 */	mflr r0
/* 8006D6E8  2C 05 00 00 */	cmpwi r5, 0
/* 8006D6EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006D6F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006D6F4  7C 7F 1B 78 */	mr r31, r3
/* 8006D6F8  41 82 00 1C */	beq 0x1c
/* 8006D6FC  80 C5 00 00 */	lwz r6, 0(r5)
/* 8006D700  54 C0 07 FF */	clrlwi. r0, r6, 0x1f
/* 8006D704  41 82 00 10 */	beq 0x10
/* 8006D708  54 C0 00 3C */	rlwinm r0, r6, 0, 0, 0x1e
/* 8006D70C  90 05 00 00 */	stw r0, 0(r5)
/* 8006D710  48 00 00 64 */	b 0x64
/* 8006D714  2C 04 00 00 */	cmpwi r4, 0
/* 8006D718  41 82 00 34 */	beq 0x34
/* 8006D71C  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D720  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 8006D724  41 82 00 14 */	beq 0x14
/* 8006D728  7C 83 23 78 */	mr r3, r4
/* 8006D72C  38 9F 00 3C */	addi r4, r31, 0x3c
/* 8006D730  48 12 C6 01 */	bl 0x12c600
/* 8006D734  48 00 00 24 */	b 0x24
/* 8006D738  7C 83 23 78 */	mr r3, r4
/* 8006D73C  38 9F 00 0C */	addi r4, r31, 0xc
/* 8006D740  38 BF 00 3C */	addi r5, r31, 0x3c
/* 8006D744  48 12 C6 21 */	bl 0x12c620
/* 8006D748  48 00 00 10 */	b 0x10
/* 8006D74C  38 63 00 0C */	addi r3, r3, 0xc
/* 8006D750  38 9F 00 3C */	addi r4, r31, 0x3c
/* 8006D754  48 12 C5 DD */	bl 0x12c5dc
/* 8006D758  80 1F 00 CC */	lwz r0, 0xcc(r31)
/* 8006D75C  54 00 00 C7 */	rlwinm. r0, r0, 0, 3, 3
/* 8006D760  41 82 00 14 */	beq 0x14
/* 8006D764  38 7F 00 B4 */	addi r3, r31, 0xb4
/* 8006D768  38 9F 00 9C */	addi r4, r31, 0x9c
/* 8006D76C  38 BF 00 3C */	addi r5, r31, 0x3c
/* 8006D770  48 01 85 21 */	bl 0x18520
/* 8006D774  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006D778  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006D77C  7C 08 03 A6 */	mtlr r0
/* 8006D780  38 21 00 10 */	addi r1, r1, 0x10
/* 8006D784  4E 80 00 20 */	blr 
/* 8006D788  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D78C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D790  7C 65 1B 78 */	mr r5, r3
/* 8006D794  7C 83 23 78 */	mr r3, r4
/* 8006D798  38 85 00 3C */	addi r4, r5, 0x3c
/* 8006D79C  38 A5 00 6C */	addi r5, r5, 0x6c
/* 8006D7A0  48 12 C5 C4 */	b 0x12c5c4
/* 8006D7A4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D7A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D7AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D7B0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006D7B4  7C 08 02 A6 */	mflr r0
/* 8006D7B8  3C C0 80 27 */	lis r6, 0x8027
/* 8006D7BC  38 E0 00 00 */	li r7, 0
/* 8006D7C0  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006D7C4  38 A0 00 80 */	li r5, 0x80
/* 8006D7C8  38 C6 31 4C */	addi r6, r6, 0x314c
/* 8006D7CC  64 E0 80 00 */	oris r0, r7, 0x8000
/* 8006D7D0  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8006D7D4  7C 7F 1B 78 */	mr r31, r3
/* 8006D7D8  90 E3 00 04 */	stw r7, 4(r3)
/* 8006D7DC  90 83 00 08 */	stw r4, 8(r3)
/* 8006D7E0  90 C3 00 00 */	stw r6, 0(r3)
/* 8006D7E4  98 A3 00 D0 */	stb r5, 0xd0(r3)
/* 8006D7E8  98 A3 00 D1 */	stb r5, 0xd1(r3)
/* 8006D7EC  98 E3 00 D2 */	stb r7, 0xd2(r3)
/* 8006D7F0  98 E3 00 D3 */	stb r7, 0xd3(r3)
/* 8006D7F4  90 E3 00 D4 */	stw r7, 0xd4(r3)
/* 8006D7F8  98 E3 00 D8 */	stb r7, 0xd8(r3)
/* 8006D7FC  98 E3 00 D9 */	stb r7, 0xd9(r3)
/* 8006D800  B0 E3 00 DA */	sth r7, 0xda(r3)
/* 8006D804  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D808  38 63 00 0C */	addi r3, r3, 0xc
/* 8006D80C  48 12 C4 F9 */	bl 0x12c4f8
/* 8006D810  38 7F 00 3C */	addi r3, r31, 0x3c
/* 8006D814  48 12 C4 F1 */	bl 0x12c4f0
/* 8006D818  38 7F 00 6C */	addi r3, r31, 0x6c
/* 8006D81C  48 12 C4 E9 */	bl 0x12c4e8
/* 8006D820  C0 02 8D 90 */	lfs f0, -0x7270(r2)
/* 8006D824  7F E3 FB 78 */	mr r3, r31
/* 8006D828  D0 1F 00 9C */	stfs f0, 0x9c(r31)
/* 8006D82C  D0 1F 00 A0 */	stfs f0, 0xa0(r31)
/* 8006D830  D0 1F 00 A4 */	stfs f0, 0xa4(r31)
/* 8006D834  D0 1F 00 A8 */	stfs f0, 0xa8(r31)
/* 8006D838  D0 1F 00 AC */	stfs f0, 0xac(r31)
/* 8006D83C  D0 1F 00 B0 */	stfs f0, 0xb0(r31)
/* 8006D840  D0 1F 00 B4 */	stfs f0, 0xb4(r31)
/* 8006D844  D0 1F 00 B8 */	stfs f0, 0xb8(r31)
/* 8006D848  D0 1F 00 BC */	stfs f0, 0xbc(r31)
/* 8006D84C  D0 1F 00 C0 */	stfs f0, 0xc0(r31)
/* 8006D850  D0 1F 00 C4 */	stfs f0, 0xc4(r31)
/* 8006D854  D0 1F 00 C8 */	stfs f0, 0xc8(r31)
/* 8006D858  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8006D85C  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006D860  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 8006D864  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 8006D868  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8006D86C  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8006D870  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8006D874  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 8006D878  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8006D87C  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8006D880  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8006D884  D0 01 00 08 */	stfs f0, 8(r1)
/* 8006D888  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 8006D88C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8006D890  7C 08 03 A6 */	mtlr r0
/* 8006D894  38 21 00 40 */	addi r1, r1, 0x40
/* 8006D898  4E 80 00 20 */	blr 
/* 8006D89C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006D8A0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006D8A4  7C 08 02 A6 */	mflr r0
/* 8006D8A8  2C 03 00 00 */	cmpwi r3, 0
/* 8006D8AC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006D8B0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006D8B4  7C 7F 1B 78 */	mr r31, r3
/* 8006D8B8  41 82 00 50 */	beq 0x50
/* 8006D8BC  80 A3 00 D4 */	lwz r5, 0xd4(r3)
/* 8006D8C0  3C 80 80 27 */	lis r4, 0x8027
/* 8006D8C4  38 84 31 4C */	addi r4, r4, 0x314c
/* 8006D8C8  90 83 00 00 */	stw r4, 0(r3)
/* 8006D8CC  2C 85 00 00 */	cmpwi cr1, r5, 0
/* 8006D8D0  41 86 00 2C */	beq cr1, 0x2c
/* 8006D8D4  88 03 00 D9 */	lbz r0, 0xd9(r3)
/* 8006D8D8  2C 00 00 01 */	cmpwi r0, 1
/* 8006D8DC  40 82 00 20 */	bne 0x20
/* 8006D8E0  41 86 00 1C */	beq cr1, 0x1c
/* 8006D8E4  81 85 00 00 */	lwz r12, 0(r5)
/* 8006D8E8  7C A3 2B 78 */	mr r3, r5
/* 8006D8EC  38 80 00 01 */	li r4, 1
/* 8006D8F0  81 8C 00 08 */	lwz r12, 8(r12)
/* 8006D8F4  7D 89 03 A6 */	mtctr r12
/* 8006D8F8  4E 80 04 21 */	bctrl 
/* 8006D8FC  7F E3 FB 78 */	mr r3, r31
/* 8006D900  38 80 00 00 */	li r4, 0
/* 8006D904  4B FF 2A 5D */	bl -0xd5a4
/* 8006D908  7F E3 FB 78 */	mr r3, r31
/* 8006D90C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006D910  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006D914  7C 08 03 A6 */	mtlr r0
/* 8006D918  38 21 00 10 */	addi r1, r1, 0x10
/* 8006D91C  4E 80 00 20 */	blr 
/* 8006D920  28 04 00 09 */	cmplwi r4, 9
/* 8006D924  41 81 01 84 */	bgt 0x184
/* 8006D928  3C C0 80 27 */	lis r6, 0x8027
/* 8006D92C  54 80 10 3A */	slwi r0, r4, 2
/* 8006D930  38 C6 30 88 */	addi r6, r6, 0x3088
/* 8006D934  7C C6 00 2E */	lwzx r6, r6, r0
/* 8006D938  7C C9 03 A6 */	mtctr r6
/* 8006D93C  4E 80 04 20 */	bctr 
/* 8006D940  2C 05 00 00 */	cmpwi r5, 0
/* 8006D944  41 82 00 14 */	beq 0x14
/* 8006D948  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D94C  60 00 00 10 */	ori r0, r0, 0x10
/* 8006D950  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D954  48 00 01 5C */	b 0x15c
/* 8006D958  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D95C  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8006D960  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D964  48 00 01 4C */	b 0x14c
/* 8006D968  2C 05 00 00 */	cmpwi r5, 0
/* 8006D96C  41 82 00 14 */	beq 0x14
/* 8006D970  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D974  60 00 00 01 */	ori r0, r0, 1
/* 8006D978  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D97C  48 00 01 34 */	b 0x134
/* 8006D980  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D984  54 00 00 3C */	rlwinm r0, r0, 0, 0, 0x1e
/* 8006D988  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D98C  48 00 01 24 */	b 0x124
/* 8006D990  2C 05 00 00 */	cmpwi r5, 0
/* 8006D994  41 82 00 14 */	beq 0x14
/* 8006D998  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D99C  60 00 00 02 */	ori r0, r0, 2
/* 8006D9A0  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D9A4  48 00 01 0C */	b 0x10c
/* 8006D9A8  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D9AC  54 00 07 FA */	rlwinm r0, r0, 0, 0x1f, 0x1d
/* 8006D9B0  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D9B4  48 00 00 FC */	b 0xfc
/* 8006D9B8  2C 05 00 00 */	cmpwi r5, 0
/* 8006D9BC  41 82 00 14 */	beq 0x14
/* 8006D9C0  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D9C4  60 00 00 04 */	ori r0, r0, 4
/* 8006D9C8  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D9CC  48 00 00 E4 */	b 0xe4
/* 8006D9D0  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D9D4  54 00 07 B8 */	rlwinm r0, r0, 0, 0x1e, 0x1c
/* 8006D9D8  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D9DC  48 00 00 D4 */	b 0xd4
/* 8006D9E0  2C 05 00 00 */	cmpwi r5, 0
/* 8006D9E4  41 82 00 14 */	beq 0x14
/* 8006D9E8  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D9EC  60 00 00 08 */	ori r0, r0, 8
/* 8006D9F0  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006D9F4  48 00 00 BC */	b 0xbc
/* 8006D9F8  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006D9FC  54 00 07 76 */	rlwinm r0, r0, 0, 0x1d, 0x1b
/* 8006DA00  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA04  48 00 00 AC */	b 0xac
/* 8006DA08  2C 05 00 00 */	cmpwi r5, 0
/* 8006DA0C  41 82 00 14 */	beq 0x14
/* 8006DA10  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA14  60 00 00 20 */	ori r0, r0, 0x20
/* 8006DA18  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA1C  48 00 00 94 */	b 0x94
/* 8006DA20  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA24  54 00 06 F2 */	rlwinm r0, r0, 0, 0x1b, 0x19
/* 8006DA28  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA2C  48 00 00 84 */	b 0x84
/* 8006DA30  2C 05 00 00 */	cmpwi r5, 0
/* 8006DA34  41 82 00 14 */	beq 0x14
/* 8006DA38  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA3C  60 00 00 40 */	ori r0, r0, 0x40
/* 8006DA40  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA44  48 00 00 6C */	b 0x6c
/* 8006DA48  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA4C  54 00 06 B0 */	rlwinm r0, r0, 0, 0x1a, 0x18
/* 8006DA50  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA54  48 00 00 5C */	b 0x5c
/* 8006DA58  2C 05 00 00 */	cmpwi r5, 0
/* 8006DA5C  41 82 00 14 */	beq 0x14
/* 8006DA60  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA64  60 00 00 80 */	ori r0, r0, 0x80
/* 8006DA68  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA6C  48 00 00 44 */	b 0x44
/* 8006DA70  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA74  54 00 06 6E */	rlwinm r0, r0, 0, 0x19, 0x17
/* 8006DA78  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA7C  48 00 00 34 */	b 0x34
/* 8006DA80  2C 05 00 00 */	cmpwi r5, 0
/* 8006DA84  41 82 00 14 */	beq 0x14
/* 8006DA88  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA8C  64 00 10 00 */	oris r0, r0, 0x1000
/* 8006DA90  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DA94  48 00 00 1C */	b 0x1c
/* 8006DA98  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DA9C  54 00 01 04 */	rlwinm r0, r0, 0, 4, 2
/* 8006DAA0  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DAA4  48 00 00 0C */	b 0xc
/* 8006DAA8  38 60 00 00 */	li r3, 0
/* 8006DAAC  4E 80 00 20 */	blr 
/* 8006DAB0  38 60 00 01 */	li r3, 1
/* 8006DAB4  4E 80 00 20 */	blr 
/* 8006DAB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DABC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DAC0  2C 05 00 00 */	cmpwi r5, 0
/* 8006DAC4  40 82 00 0C */	bne 0xc
/* 8006DAC8  38 60 00 00 */	li r3, 0
/* 8006DACC  4E 80 00 20 */	blr 
/* 8006DAD0  28 04 00 09 */	cmplwi r4, 9
/* 8006DAD4  41 81 00 AC */	bgt 0xac
/* 8006DAD8  3C C0 80 27 */	lis r6, 0x8027
/* 8006DADC  54 80 10 3A */	slwi r0, r4, 2
/* 8006DAE0  38 C6 30 B0 */	addi r6, r6, 0x30b0
/* 8006DAE4  7C C6 00 2E */	lwzx r6, r6, r0
/* 8006DAE8  7C C9 03 A6 */	mtctr r6
/* 8006DAEC  4E 80 04 20 */	bctr 
/* 8006DAF0  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DAF4  54 00 E7 FE */	rlwinm r0, r0, 0x1c, 0x1f, 0x1f
/* 8006DAF8  90 05 00 00 */	stw r0, 0(r5)
/* 8006DAFC  48 00 00 8C */	b 0x8c
/* 8006DB00  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB04  54 00 07 FE */	clrlwi r0, r0, 0x1f
/* 8006DB08  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB0C  48 00 00 7C */	b 0x7c
/* 8006DB10  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB14  54 00 FF FE */	rlwinm r0, r0, 0x1f, 0x1f, 0x1f
/* 8006DB18  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB1C  48 00 00 6C */	b 0x6c
/* 8006DB20  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB24  54 00 F7 FE */	rlwinm r0, r0, 0x1e, 0x1f, 0x1f
/* 8006DB28  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB2C  48 00 00 5C */	b 0x5c
/* 8006DB30  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB34  54 00 EF FE */	rlwinm r0, r0, 0x1d, 0x1f, 0x1f
/* 8006DB38  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB3C  48 00 00 4C */	b 0x4c
/* 8006DB40  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB44  54 00 DF FE */	rlwinm r0, r0, 0x1b, 0x1f, 0x1f
/* 8006DB48  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB4C  48 00 00 3C */	b 0x3c
/* 8006DB50  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB54  54 00 D7 FE */	rlwinm r0, r0, 0x1a, 0x1f, 0x1f
/* 8006DB58  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB5C  48 00 00 2C */	b 0x2c
/* 8006DB60  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB64  54 00 CF FE */	rlwinm r0, r0, 0x19, 0x1f, 0x1f
/* 8006DB68  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB6C  48 00 00 1C */	b 0x1c
/* 8006DB70  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DB74  54 00 27 FE */	rlwinm r0, r0, 4, 0x1f, 0x1f
/* 8006DB78  90 05 00 00 */	stw r0, 0(r5)
/* 8006DB7C  48 00 00 0C */	b 0xc
/* 8006DB80  38 60 00 00 */	li r3, 0
/* 8006DB84  4E 80 00 20 */	blr 
/* 8006DB88  38 60 00 01 */	li r3, 1
/* 8006DB8C  4E 80 00 20 */	blr 
/* 8006DB90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006DB94  7C 08 02 A6 */	mflr r0
/* 8006DB98  28 04 00 03 */	cmplwi r4, 3
/* 8006DB9C  7C 66 1B 78 */	mr r6, r3
/* 8006DBA0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006DBA4  40 80 00 64 */	bge 0x64
/* 8006DBA8  2C 05 00 00 */	cmpwi r5, 0
/* 8006DBAC  41 82 00 30 */	beq 0x30
/* 8006DBB0  2C 04 00 00 */	cmpwi r4, 0
/* 8006DBB4  40 82 00 10 */	bne 0x10
/* 8006DBB8  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DBBC  54 00 00 7E */	clrlwi r0, r0, 1
/* 8006DBC0  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DBC4  1C 04 00 30 */	mulli r0, r4, 0x30
/* 8006DBC8  7C A3 2B 78 */	mr r3, r5
/* 8006DBCC  7C 86 02 14 */	add r4, r6, r0
/* 8006DBD0  38 84 00 0C */	addi r4, r4, 0xc
/* 8006DBD4  48 12 C1 5D */	bl 0x12c15c
/* 8006DBD8  48 00 00 28 */	b 0x28
/* 8006DBDC  2C 04 00 00 */	cmpwi r4, 0
/* 8006DBE0  40 82 00 10 */	bne 0x10
/* 8006DBE4  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DBE8  64 00 80 00 */	oris r0, r0, 0x8000
/* 8006DBEC  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DBF0  1C 04 00 30 */	mulli r0, r4, 0x30
/* 8006DBF4  7C 63 02 14 */	add r3, r3, r0
/* 8006DBF8  38 63 00 0C */	addi r3, r3, 0xc
/* 8006DBFC  48 12 C1 09 */	bl 0x12c108
/* 8006DC00  38 60 00 01 */	li r3, 1
/* 8006DC04  48 00 00 08 */	b 0x8
/* 8006DC08  38 60 00 00 */	li r3, 0
/* 8006DC0C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006DC10  7C 08 03 A6 */	mtlr r0
/* 8006DC14  38 21 00 10 */	addi r1, r1, 0x10
/* 8006DC18  4E 80 00 20 */	blr 
/* 8006DC1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DC20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006DC24  7C 08 02 A6 */	mflr r0
/* 8006DC28  28 04 00 03 */	cmplwi r4, 3
/* 8006DC2C  7C 66 1B 78 */	mr r6, r3
/* 8006DC30  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006DC34  40 80 00 34 */	bge 0x34
/* 8006DC38  2C 04 00 00 */	cmpwi r4, 0
/* 8006DC3C  40 82 00 10 */	bne 0x10
/* 8006DC40  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DC44  54 00 00 7E */	clrlwi r0, r0, 1
/* 8006DC48  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DC4C  1C 04 00 30 */	mulli r0, r4, 0x30
/* 8006DC50  7C A3 2B 78 */	mr r3, r5
/* 8006DC54  7C 86 02 14 */	add r4, r6, r0
/* 8006DC58  38 84 00 0C */	addi r4, r4, 0xc
/* 8006DC5C  48 12 C0 D5 */	bl 0x12c0d4
/* 8006DC60  38 60 00 01 */	li r3, 1
/* 8006DC64  48 00 00 08 */	b 0x8
/* 8006DC68  38 60 00 00 */	li r3, 0
/* 8006DC6C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006DC70  7C 08 03 A6 */	mtlr r0
/* 8006DC74  38 21 00 10 */	addi r1, r1, 0x10
/* 8006DC78  4E 80 00 20 */	blr 
/* 8006DC7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DC80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006DC84  7C 08 02 A6 */	mflr r0
/* 8006DC88  2C 05 00 00 */	cmpwi r5, 0
/* 8006DC8C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006DC90  41 82 00 28 */	beq 0x28
/* 8006DC94  28 04 00 03 */	cmplwi r4, 3
/* 8006DC98  40 80 00 20 */	bge 0x20
/* 8006DC9C  1C 04 00 30 */	mulli r0, r4, 0x30
/* 8006DCA0  7C A4 2B 78 */	mr r4, r5
/* 8006DCA4  7C 63 02 14 */	add r3, r3, r0
/* 8006DCA8  38 63 00 0C */	addi r3, r3, 0xc
/* 8006DCAC  48 12 C0 85 */	bl 0x12c084
/* 8006DCB0  38 60 00 01 */	li r3, 1
/* 8006DCB4  48 00 00 08 */	b 0x8
/* 8006DCB8  38 60 00 00 */	li r3, 0
/* 8006DCBC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006DCC0  7C 08 03 A6 */	mtlr r0
/* 8006DCC4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006DCC8  4E 80 00 20 */	blr 
/* 8006DCCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DCD0  C0 03 00 98 */	lfs f0, 0x98(r3)
/* 8006DCD4  FC 20 00 50 */	fneg f1, f0
/* 8006DCD8  4E 80 00 20 */	blr 
/* 8006DCDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DCE0  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 8006DCE4  4E 80 00 20 */	blr 
/* 8006DCE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DCEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DCF0  2C 04 00 00 */	cmpwi r4, 0
/* 8006DCF4  40 80 00 0C */	bge 0xc
/* 8006DCF8  38 80 00 00 */	li r4, 0
/* 8006DCFC  48 00 00 10 */	b 0x10
/* 8006DD00  2C 04 00 FF */	cmpwi r4, 0xff
/* 8006DD04  40 81 00 08 */	ble 0x8
/* 8006DD08  38 80 00 FF */	li r4, 0xff
/* 8006DD0C  98 83 00 D0 */	stb r4, 0xd0(r3)
/* 8006DD10  4E 80 00 20 */	blr 
/* 8006DD14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DD18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DD1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DD20  2C 04 00 00 */	cmpwi r4, 0
/* 8006DD24  40 80 00 0C */	bge 0xc
/* 8006DD28  38 80 00 00 */	li r4, 0
/* 8006DD2C  48 00 00 10 */	b 0x10
/* 8006DD30  2C 04 00 FF */	cmpwi r4, 0xff
/* 8006DD34  40 81 00 08 */	ble 0x8
/* 8006DD38  38 80 00 FF */	li r4, 0xff
/* 8006DD3C  98 83 00 D1 */	stb r4, 0xd1(r3)
/* 8006DD40  4E 80 00 20 */	blr 
/* 8006DD44  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DD48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DD4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DD50  54 80 07 FF */	clrlwi. r0, r4, 0x1f
/* 8006DD54  41 82 00 10 */	beq 0x10
/* 8006DD58  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006DD5C  60 00 00 01 */	ori r0, r0, 1
/* 8006DD60  98 03 00 D8 */	stb r0, 0xd8(r3)
/* 8006DD64  54 80 07 BD */	rlwinm. r0, r4, 0, 0x1e, 0x1e
/* 8006DD68  41 82 00 10 */	beq 0x10
/* 8006DD6C  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006DD70  60 00 00 02 */	ori r0, r0, 2
/* 8006DD74  98 03 00 D8 */	stb r0, 0xd8(r3)
/* 8006DD78  54 80 07 7B */	rlwinm. r0, r4, 0, 0x1d, 0x1d
/* 8006DD7C  4D 82 00 20 */	beqlr 
/* 8006DD80  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006DD84  60 00 00 04 */	ori r0, r0, 4
/* 8006DD88  98 03 00 D8 */	stb r0, 0xd8(r3)
/* 8006DD8C  4E 80 00 20 */	blr 
/* 8006DD90  A0 A3 00 DA */	lhz r5, 0xda(r3)
/* 8006DD94  54 80 04 3E */	clrlwi r0, r4, 0x10
/* 8006DD98  7C A0 03 78 */	or r0, r5, r0
/* 8006DD9C  B0 03 00 DA */	sth r0, 0xda(r3)
/* 8006DDA0  4E 80 00 20 */	blr 
/* 8006DDA4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DDA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DDAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DDB0  2C 05 00 00 */	cmpwi r5, 0
/* 8006DDB4  41 82 00 64 */	beq 0x64
/* 8006DDB8  2C 04 00 02 */	cmpwi r4, 2
/* 8006DDBC  40 80 00 54 */	bge 0x54
/* 8006DDC0  1C E4 00 18 */	mulli r7, r4, 0x18
/* 8006DDC4  80 05 00 04 */	lwz r0, 4(r5)
/* 8006DDC8  80 C5 00 00 */	lwz r6, 0(r5)
/* 8006DDCC  38 80 00 09 */	li r4, 9
/* 8006DDD0  7C E3 3A 14 */	add r7, r3, r7
/* 8006DDD4  90 C7 00 9C */	stw r6, 0x9c(r7)
/* 8006DDD8  90 07 00 A0 */	stw r0, 0xa0(r7)
/* 8006DDDC  80 05 00 08 */	lwz r0, 8(r5)
/* 8006DDE0  90 07 00 A4 */	stw r0, 0xa4(r7)
/* 8006DDE4  80 05 00 10 */	lwz r0, 0x10(r5)
/* 8006DDE8  80 C5 00 0C */	lwz r6, 0xc(r5)
/* 8006DDEC  90 C7 00 A8 */	stw r6, 0xa8(r7)
/* 8006DDF0  90 07 00 AC */	stw r0, 0xac(r7)
/* 8006DDF4  80 05 00 14 */	lwz r0, 0x14(r5)
/* 8006DDF8  38 A0 00 01 */	li r5, 1
/* 8006DDFC  90 07 00 B0 */	stw r0, 0xb0(r7)
/* 8006DE00  81 83 00 00 */	lwz r12, 0(r3)
/* 8006DE04  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8006DE08  7D 89 03 A6 */	mtctr r12
/* 8006DE0C  4E 80 04 20 */	bctr 
/* 8006DE10  38 60 00 00 */	li r3, 0
/* 8006DE14  4E 80 00 20 */	blr 
/* 8006DE18  81 83 00 00 */	lwz r12, 0(r3)
/* 8006DE1C  38 80 00 09 */	li r4, 9
/* 8006DE20  38 A0 00 00 */	li r5, 0
/* 8006DE24  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8006DE28  7D 89 03 A6 */	mtctr r12
/* 8006DE2C  4E 80 04 20 */	bctr 
/* 8006DE30  4E 80 00 20 */	blr 
/* 8006DE34  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DE38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DE3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DE40  2C 05 00 00 */	cmpwi r5, 0
/* 8006DE44  41 82 00 54 */	beq 0x54
/* 8006DE48  2C 04 00 02 */	cmpwi r4, 2
/* 8006DE4C  40 80 00 44 */	bge 0x44
/* 8006DE50  1C 04 00 18 */	mulli r0, r4, 0x18
/* 8006DE54  7D 43 02 14 */	add r10, r3, r0
/* 8006DE58  38 60 00 01 */	li r3, 1
/* 8006DE5C  81 2A 00 9C */	lwz r9, 0x9c(r10)
/* 8006DE60  81 0A 00 A0 */	lwz r8, 0xa0(r10)
/* 8006DE64  80 EA 00 A4 */	lwz r7, 0xa4(r10)
/* 8006DE68  80 CA 00 A8 */	lwz r6, 0xa8(r10)
/* 8006DE6C  80 8A 00 AC */	lwz r4, 0xac(r10)
/* 8006DE70  80 0A 00 B0 */	lwz r0, 0xb0(r10)
/* 8006DE74  91 25 00 00 */	stw r9, 0(r5)
/* 8006DE78  91 05 00 04 */	stw r8, 4(r5)
/* 8006DE7C  90 E5 00 08 */	stw r7, 8(r5)
/* 8006DE80  90 C5 00 0C */	stw r6, 0xc(r5)
/* 8006DE84  90 85 00 10 */	stw r4, 0x10(r5)
/* 8006DE88  90 05 00 14 */	stw r0, 0x14(r5)
/* 8006DE8C  4E 80 00 20 */	blr 
/* 8006DE90  38 60 00 00 */	li r3, 0
/* 8006DE94  4E 80 00 20 */	blr 
/* 8006DE98  38 60 00 00 */	li r3, 0
/* 8006DE9C  4E 80 00 20 */	blr 
/* 8006DEA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006DEA4  7C 08 02 A6 */	mflr r0
/* 8006DEA8  7C 8C 23 78 */	mr r12, r4
/* 8006DEAC  7C A4 2B 78 */	mr r4, r5
/* 8006DEB0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006DEB4  7D 89 03 A6 */	mtctr r12
/* 8006DEB8  4E 80 04 21 */	bctrl 
/* 8006DEBC  38 03 FF FF */	addi r0, r3, -1
/* 8006DEC0  7C 00 00 34 */	cntlzw r0, r0
/* 8006DEC4  54 03 D9 7E */	srwi r3, r0, 5
/* 8006DEC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006DECC  7C 08 03 A6 */	mtlr r0
/* 8006DED0  38 21 00 10 */	addi r1, r1, 0x10
/* 8006DED4  4E 80 00 20 */	blr 
/* 8006DED8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DEDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DEE0  3C 04 FF FF */	addis r0, r4, 0xffff
/* 8006DEE4  28 00 00 01 */	cmplwi r0, 1
/* 8006DEE8  40 82 00 2C */	bne 0x2c
/* 8006DEEC  2C 05 00 00 */	cmpwi r5, 0
/* 8006DEF0  41 82 00 14 */	beq 0x14
/* 8006DEF4  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DEF8  60 00 00 60 */	ori r0, r0, 0x60
/* 8006DEFC  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DF00  48 00 00 18 */	b 0x18
/* 8006DF04  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DF08  54 00 06 F0 */	rlwinm r0, r0, 0, 0x1b, 0x18
/* 8006DF0C  90 03 00 CC */	stw r0, 0xcc(r3)
/* 8006DF10  48 00 00 08 */	b 0x8
/* 8006DF14  4B FF FA 0C */	b -0x5f4
/* 8006DF18  38 60 00 01 */	li r3, 1
/* 8006DF1C  4E 80 00 20 */	blr 
/* 8006DF20  2C 05 00 00 */	cmpwi r5, 0
/* 8006DF24  40 82 00 0C */	bne 0xc
/* 8006DF28  38 60 00 00 */	li r3, 0
/* 8006DF2C  4E 80 00 20 */	blr 
/* 8006DF30  3C 04 FF FF */	addis r0, r4, 0xffff
/* 8006DF34  28 00 00 01 */	cmplwi r0, 1
/* 8006DF38  40 82 00 20 */	bne 0x20
/* 8006DF3C  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DF40  54 03 06 74 */	rlwinm r3, r0, 0, 0x19, 0x1a
/* 8006DF44  7C 03 00 D0 */	neg r0, r3
/* 8006DF48  7C 00 1B 78 */	or r0, r0, r3
/* 8006DF4C  54 00 0F FE */	srwi r0, r0, 0x1f
/* 8006DF50  90 05 00 00 */	stw r0, 0(r5)
/* 8006DF54  48 00 00 08 */	b 0x8
/* 8006DF58  4B FF FB 68 */	b -0x498
/* 8006DF5C  38 60 00 01 */	li r3, 1
/* 8006DF60  4E 80 00 20 */	blr 
/* 8006DF64  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DF68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DF6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006DF70  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006DF74  7C 08 02 A6 */	mflr r0
/* 8006DF78  2C 05 00 00 */	cmpwi r5, 0
/* 8006DF7C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006DF80  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006DF84  7C 7F 1B 78 */	mr r31, r3
/* 8006DF88  41 82 00 1C */	beq 0x1c
/* 8006DF8C  80 C5 00 00 */	lwz r6, 0(r5)
/* 8006DF90  54 C0 07 FF */	clrlwi. r0, r6, 0x1f
/* 8006DF94  41 82 00 10 */	beq 0x10
/* 8006DF98  54 C0 00 3C */	rlwinm r0, r6, 0, 0, 0x1e
/* 8006DF9C  90 05 00 00 */	stw r0, 0(r5)
/* 8006DFA0  48 00 00 B0 */	b 0xb0
/* 8006DFA4  2C 05 00 00 */	cmpwi r5, 0
/* 8006DFA8  41 82 00 1C */	beq 0x1c
/* 8006DFAC  80 C5 00 00 */	lwz r6, 0(r5)
/* 8006DFB0  54 C0 07 FF */	clrlwi. r0, r6, 0x1f
/* 8006DFB4  41 82 00 10 */	beq 0x10
/* 8006DFB8  54 C0 00 3C */	rlwinm r0, r6, 0, 0, 0x1e
/* 8006DFBC  90 05 00 00 */	stw r0, 0(r5)
/* 8006DFC0  48 00 00 64 */	b 0x64
/* 8006DFC4  2C 04 00 00 */	cmpwi r4, 0
/* 8006DFC8  41 82 00 34 */	beq 0x34
/* 8006DFCC  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006DFD0  54 00 00 01 */	rlwinm. r0, r0, 0, 0, 0
/* 8006DFD4  41 82 00 14 */	beq 0x14
/* 8006DFD8  7C 83 23 78 */	mr r3, r4
/* 8006DFDC  38 9F 00 3C */	addi r4, r31, 0x3c
/* 8006DFE0  48 12 BD 51 */	bl 0x12bd50
/* 8006DFE4  48 00 00 24 */	b 0x24
/* 8006DFE8  7C 83 23 78 */	mr r3, r4
/* 8006DFEC  38 9F 00 0C */	addi r4, r31, 0xc
/* 8006DFF0  38 BF 00 3C */	addi r5, r31, 0x3c
/* 8006DFF4  48 12 BD 71 */	bl 0x12bd70
/* 8006DFF8  48 00 00 10 */	b 0x10
/* 8006DFFC  38 63 00 0C */	addi r3, r3, 0xc
/* 8006E000  38 9F 00 3C */	addi r4, r31, 0x3c
/* 8006E004  48 12 BD 2D */	bl 0x12bd2c
/* 8006E008  80 1F 00 CC */	lwz r0, 0xcc(r31)
/* 8006E00C  54 00 00 C7 */	rlwinm. r0, r0, 0, 3, 3
/* 8006E010  41 82 00 14 */	beq 0x14
/* 8006E014  38 7F 00 B4 */	addi r3, r31, 0xb4
/* 8006E018  38 9F 00 9C */	addi r4, r31, 0x9c
/* 8006E01C  38 BF 00 3C */	addi r5, r31, 0x3c
/* 8006E020  48 01 7C 71 */	bl 0x17c70
/* 8006E024  38 7F 00 3C */	addi r3, r31, 0x3c
/* 8006E028  38 BF 00 DC */	addi r5, r31, 0xdc
/* 8006E02C  7C 64 1B 78 */	mr r4, r3
/* 8006E030  48 01 77 81 */	bl 0x17780
/* 8006E034  80 1F 00 CC */	lwz r0, 0xcc(r31)
/* 8006E038  54 00 00 C7 */	rlwinm. r0, r0, 0, 3, 3
/* 8006E03C  41 82 00 14 */	beq 0x14
/* 8006E040  38 7F 00 B4 */	addi r3, r31, 0xb4
/* 8006E044  38 9F 00 9C */	addi r4, r31, 0x9c
/* 8006E048  38 BF 00 3C */	addi r5, r31, 0x3c
/* 8006E04C  48 01 7C 45 */	bl 0x17c44
/* 8006E050  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006E054  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006E058  7C 08 03 A6 */	mtlr r0
/* 8006E05C  38 21 00 10 */	addi r1, r1, 0x10
/* 8006E060  4E 80 00 20 */	blr 
/* 8006E064  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E068  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E06C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E070  C0 43 00 DC */	lfs f2, 0xdc(r3)
/* 8006E074  C0 23 00 E0 */	lfs f1, 0xe0(r3)
/* 8006E078  FC 02 08 00 */	fcmpu cr0, f2, f1
/* 8006E07C  40 82 00 2C */	bne 0x2c
/* 8006E080  C0 03 00 E4 */	lfs f0, 0xe4(r3)
/* 8006E084  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8006E088  40 82 00 20 */	bne 0x20
/* 8006E08C  C0 02 8D 94 */	lfs f0, -0x726c(r2)
/* 8006E090  FC 00 10 00 */	fcmpu cr0, f0, f2
/* 8006E094  40 82 00 0C */	bne 0xc
/* 8006E098  38 60 00 00 */	li r3, 0
/* 8006E09C  4E 80 00 20 */	blr 
/* 8006E0A0  38 60 00 01 */	li r3, 1
/* 8006E0A4  4E 80 00 20 */	blr 
/* 8006E0A8  38 60 00 02 */	li r3, 2
/* 8006E0AC  4E 80 00 20 */	blr 
/* 8006E0B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006E0B4  7C 08 02 A6 */	mflr r0
/* 8006E0B8  28 04 00 01 */	cmplwi r4, 1
/* 8006E0BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006E0C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006E0C4  7C DF 33 78 */	mr r31, r6
/* 8006E0C8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006E0CC  7C 7E 1B 78 */	mr r30, r3
/* 8006E0D0  90 A1 00 08 */	stw r5, 8(r1)
/* 8006E0D4  41 82 00 2C */	beq 0x2c
/* 8006E0D8  28 04 00 02 */	cmplwi r4, 2
/* 8006E0DC  41 82 01 14 */	beq 0x114
/* 8006E0E0  28 04 00 04 */	cmplwi r4, 4
/* 8006E0E4  41 82 01 9C */	beq 0x19c
/* 8006E0E8  3C 04 FF FF */	addis r0, r4, 0xffff
/* 8006E0EC  28 00 00 03 */	cmplwi r0, 3
/* 8006E0F0  41 82 02 74 */	beq 0x274
/* 8006E0F4  28 00 00 02 */	cmplwi r0, 2
/* 8006E0F8  41 82 02 78 */	beq 0x278
/* 8006E0FC  48 00 02 78 */	b 0x278
/* 8006E100  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8006E104  7C A6 2B 78 */	mr r6, r5
/* 8006E108  2C 04 00 00 */	cmpwi r4, 0
/* 8006E10C  41 82 00 3C */	beq 0x3c
/* 8006E110  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8006E114  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E118  41 82 00 30 */	beq 0x30
/* 8006E11C  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006E120  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E124  41 82 00 24 */	beq 0x24
/* 8006E128  81 84 00 00 */	lwz r12, 0(r4)
/* 8006E12C  7C 83 23 78 */	mr r3, r4
/* 8006E130  7F C5 F3 78 */	mr r5, r30
/* 8006E134  7F E7 FB 78 */	mr r7, r31
/* 8006E138  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E13C  38 80 00 01 */	li r4, 1
/* 8006E140  7D 89 03 A6 */	mtctr r12
/* 8006E144  4E 80 04 21 */	bctrl 
/* 8006E148  81 9E 00 00 */	lwz r12, 0(r30)
/* 8006E14C  7F C3 F3 78 */	mr r3, r30
/* 8006E150  7F E4 FB 78 */	mr r4, r31
/* 8006E154  38 A1 00 08 */	addi r5, r1, 8
/* 8006E158  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 8006E15C  7D 89 03 A6 */	mtctr r12
/* 8006E160  4E 80 04 21 */	bctrl 
/* 8006E164  80 7E 00 D4 */	lwz r3, 0xd4(r30)
/* 8006E168  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E16C  2C 03 00 00 */	cmpwi r3, 0
/* 8006E170  41 82 00 38 */	beq 0x38
/* 8006E174  A0 1E 00 DA */	lhz r0, 0xda(r30)
/* 8006E178  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E17C  41 82 00 2C */	beq 0x2c
/* 8006E180  88 1E 00 D8 */	lbz r0, 0xd8(r30)
/* 8006E184  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E188  41 82 00 20 */	beq 0x20
/* 8006E18C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E190  7F C5 F3 78 */	mr r5, r30
/* 8006E194  7F E7 FB 78 */	mr r7, r31
/* 8006E198  38 80 00 02 */	li r4, 2
/* 8006E19C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E1A0  7D 89 03 A6 */	mtctr r12
/* 8006E1A4  4E 80 04 21 */	bctrl 
/* 8006E1A8  80 7E 00 D4 */	lwz r3, 0xd4(r30)
/* 8006E1AC  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E1B0  2C 03 00 00 */	cmpwi r3, 0
/* 8006E1B4  41 82 01 C0 */	beq 0x1c0
/* 8006E1B8  A0 1E 00 DA */	lhz r0, 0xda(r30)
/* 8006E1BC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E1C0  41 82 01 B4 */	beq 0x1b4
/* 8006E1C4  88 1E 00 D8 */	lbz r0, 0xd8(r30)
/* 8006E1C8  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E1CC  41 82 01 A8 */	beq 0x1a8
/* 8006E1D0  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E1D4  7F C5 F3 78 */	mr r5, r30
/* 8006E1D8  7F E7 FB 78 */	mr r7, r31
/* 8006E1DC  38 80 00 04 */	li r4, 4
/* 8006E1E0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E1E4  7D 89 03 A6 */	mtctr r12
/* 8006E1E8  4E 80 04 21 */	bctrl 
/* 8006E1EC  48 00 01 88 */	b 0x188
/* 8006E1F0  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8006E1F4  7C A6 2B 78 */	mr r6, r5
/* 8006E1F8  2C 04 00 00 */	cmpwi r4, 0
/* 8006E1FC  41 82 00 3C */	beq 0x3c
/* 8006E200  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8006E204  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E208  41 82 00 30 */	beq 0x30
/* 8006E20C  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006E210  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E214  41 82 00 24 */	beq 0x24
/* 8006E218  81 84 00 00 */	lwz r12, 0(r4)
/* 8006E21C  7C 83 23 78 */	mr r3, r4
/* 8006E220  7F C5 F3 78 */	mr r5, r30
/* 8006E224  7F E7 FB 78 */	mr r7, r31
/* 8006E228  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8006E22C  38 80 00 01 */	li r4, 1
/* 8006E230  7D 89 03 A6 */	mtctr r12
/* 8006E234  4E 80 04 21 */	bctrl 
/* 8006E238  80 7E 00 D4 */	lwz r3, 0xd4(r30)
/* 8006E23C  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E240  2C 03 00 00 */	cmpwi r3, 0
/* 8006E244  41 82 01 30 */	beq 0x130
/* 8006E248  A0 1E 00 DA */	lhz r0, 0xda(r30)
/* 8006E24C  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E250  41 82 01 24 */	beq 0x124
/* 8006E254  88 1E 00 D8 */	lbz r0, 0xd8(r30)
/* 8006E258  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E25C  41 82 01 18 */	beq 0x118
/* 8006E260  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E264  7F C5 F3 78 */	mr r5, r30
/* 8006E268  7F E7 FB 78 */	mr r7, r31
/* 8006E26C  38 80 00 04 */	li r4, 4
/* 8006E270  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8006E274  7D 89 03 A6 */	mtctr r12
/* 8006E278  4E 80 04 21 */	bctrl 
/* 8006E27C  48 00 00 F8 */	b 0xf8
/* 8006E280  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8006E284  7C A6 2B 78 */	mr r6, r5
/* 8006E288  2C 04 00 00 */	cmpwi r4, 0
/* 8006E28C  41 82 00 3C */	beq 0x3c
/* 8006E290  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8006E294  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E298  41 82 00 30 */	beq 0x30
/* 8006E29C  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006E2A0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E2A4  41 82 00 24 */	beq 0x24
/* 8006E2A8  81 84 00 00 */	lwz r12, 0(r4)
/* 8006E2AC  7C 83 23 78 */	mr r3, r4
/* 8006E2B0  7F C5 F3 78 */	mr r5, r30
/* 8006E2B4  7F E7 FB 78 */	mr r7, r31
/* 8006E2B8  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006E2BC  38 80 00 01 */	li r4, 1
/* 8006E2C0  7D 89 03 A6 */	mtctr r12
/* 8006E2C4  4E 80 04 21 */	bctrl 
/* 8006E2C8  7F E3 FB 78 */	mr r3, r31
/* 8006E2CC  38 9E 00 3C */	addi r4, r30, 0x3c
/* 8006E2D0  38 BE 00 6C */	addi r5, r30, 0x6c
/* 8006E2D4  48 12 BA 91 */	bl 0x12ba90
/* 8006E2D8  80 7E 00 D4 */	lwz r3, 0xd4(r30)
/* 8006E2DC  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E2E0  2C 03 00 00 */	cmpwi r3, 0
/* 8006E2E4  41 82 00 38 */	beq 0x38
/* 8006E2E8  A0 1E 00 DA */	lhz r0, 0xda(r30)
/* 8006E2EC  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E2F0  41 82 00 2C */	beq 0x2c
/* 8006E2F4  88 1E 00 D8 */	lbz r0, 0xd8(r30)
/* 8006E2F8  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E2FC  41 82 00 20 */	beq 0x20
/* 8006E300  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E304  7F C5 F3 78 */	mr r5, r30
/* 8006E308  7F E7 FB 78 */	mr r7, r31
/* 8006E30C  38 80 00 02 */	li r4, 2
/* 8006E310  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006E314  7D 89 03 A6 */	mtctr r12
/* 8006E318  4E 80 04 21 */	bctrl 
/* 8006E31C  80 7E 00 D4 */	lwz r3, 0xd4(r30)
/* 8006E320  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E324  2C 03 00 00 */	cmpwi r3, 0
/* 8006E328  41 82 00 4C */	beq 0x4c
/* 8006E32C  A0 1E 00 DA */	lhz r0, 0xda(r30)
/* 8006E330  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E334  41 82 00 40 */	beq 0x40
/* 8006E338  88 1E 00 D8 */	lbz r0, 0xd8(r30)
/* 8006E33C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E340  41 82 00 34 */	beq 0x34
/* 8006E344  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E348  7F C5 F3 78 */	mr r5, r30
/* 8006E34C  7F E7 FB 78 */	mr r7, r31
/* 8006E350  38 80 00 04 */	li r4, 4
/* 8006E354  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006E358  7D 89 03 A6 */	mtctr r12
/* 8006E35C  4E 80 04 21 */	bctrl 
/* 8006E360  48 00 00 14 */	b 0x14
/* 8006E364  38 00 00 00 */	li r0, 0
/* 8006E368  90 03 00 04 */	stw r0, 4(r3)
/* 8006E36C  48 00 00 08 */	b 0x8
/* 8006E370  90 C3 00 04 */	stw r6, 4(r3)
/* 8006E374  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006E378  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006E37C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006E380  7C 08 03 A6 */	mtlr r0
/* 8006E384  38 21 00 20 */	addi r1, r1, 0x20
/* 8006E388  4E 80 00 20 */	blr 
/* 8006E38C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E390  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006E394  7C 08 02 A6 */	mflr r0
/* 8006E398  54 A6 10 3A */	slwi r6, r5, 2
/* 8006E39C  2C 04 00 00 */	cmpwi r4, 0
/* 8006E3A0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006E3A4  38 06 00 EB */	addi r0, r6, 0xeb
/* 8006E3A8  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 8006E3AC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006E3B0  3B E0 00 00 */	li r31, 0
/* 8006E3B4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006E3B8  7C BE 2B 78 */	mr r30, r5
/* 8006E3BC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8006E3C0  7C 7D 1B 78 */	mr r29, r3
/* 8006E3C4  41 82 00 08 */	beq 0x8
/* 8006E3C8  90 04 00 00 */	stw r0, 0(r4)
/* 8006E3CC  2C 03 00 00 */	cmpwi r3, 0
/* 8006E3D0  41 82 00 5C */	beq 0x5c
/* 8006E3D4  7F A3 EB 78 */	mr r3, r29
/* 8006E3D8  7C 04 03 78 */	mr r4, r0
/* 8006E3DC  48 12 B7 BD */	bl 0x12b7bc
/* 8006E3E0  2C 03 00 00 */	cmpwi r3, 0
/* 8006E3E4  7C 7F 1B 78 */	mr r31, r3
/* 8006E3E8  40 82 00 0C */	bne 0xc
/* 8006E3EC  38 60 00 00 */	li r3, 0
/* 8006E3F0  48 00 00 40 */	b 0x40
/* 8006E3F4  41 82 00 38 */	beq 0x38
/* 8006E3F8  7F A4 EB 78 */	mr r4, r29
/* 8006E3FC  4B FF F3 B5 */	bl -0xc4c
/* 8006E400  3C 80 80 27 */	lis r4, 0x8027
/* 8006E404  38 7F 00 E8 */	addi r3, r31, 0xe8
/* 8006E408  38 84 30 D8 */	addi r4, r4, 0x30d8
/* 8006E40C  90 9F 00 00 */	stw r4, 0(r31)
/* 8006E410  38 00 00 00 */	li r0, 0
/* 8006E414  90 7F 00 DC */	stw r3, 0xdc(r31)
/* 8006E418  93 DF 00 E0 */	stw r30, 0xe0(r31)
/* 8006E41C  90 1F 00 E4 */	stw r0, 0xe4(r31)
/* 8006E420  80 1F 00 CC */	lwz r0, 0xcc(r31)
/* 8006E424  64 00 60 00 */	oris r0, r0, 0x6000
/* 8006E428  90 1F 00 CC */	stw r0, 0xcc(r31)
/* 8006E42C  7F E3 FB 78 */	mr r3, r31
/* 8006E430  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006E434  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006E438  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006E43C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8006E440  7C 08 03 A6 */	mtlr r0
/* 8006E444  38 21 00 20 */	addi r1, r1, 0x20
/* 8006E448  4E 80 00 20 */	blr 
/* 8006E44C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E450  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006E454  7C 08 02 A6 */	mflr r0
/* 8006E458  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006E45C  39 61 00 20 */	addi r11, r1, 0x20
/* 8006E460  4B FB 31 41 */	bl -0x4cec0
/* 8006E464  2C 06 00 00 */	cmpwi r6, 0
/* 8006E468  7C 7B 1B 78 */	mr r27, r3
/* 8006E46C  7C 9C 23 78 */	mr r28, r4
/* 8006E470  7C BD 2B 78 */	mr r29, r5
/* 8006E474  41 82 00 7C */	beq 0x7c
/* 8006E478  3B C0 00 00 */	li r30, 0
/* 8006E47C  3B E0 00 00 */	li r31, 0
/* 8006E480  48 00 00 40 */	b 0x40
/* 8006E484  80 7B 00 DC */	lwz r3, 0xdc(r27)
/* 8006E488  7F 84 E3 78 */	mr r4, r28
/* 8006E48C  7F A5 EB 78 */	mr r5, r29
/* 8006E490  38 C0 00 00 */	li r6, 0
/* 8006E494  7C 63 F8 2E */	lwzx r3, r3, r31
/* 8006E498  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E49C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8006E4A0  7D 89 03 A6 */	mtctr r12
/* 8006E4A4  4E 80 04 21 */	bctrl 
/* 8006E4A8  2C 03 00 01 */	cmpwi r3, 1
/* 8006E4AC  40 82 00 0C */	bne 0xc
/* 8006E4B0  38 60 00 01 */	li r3, 1
/* 8006E4B4  48 00 00 BC */	b 0xbc
/* 8006E4B8  3B FF 00 04 */	addi r31, r31, 4
/* 8006E4BC  3B DE 00 01 */	addi r30, r30, 1
/* 8006E4C0  80 1B 00 E4 */	lwz r0, 0xe4(r27)
/* 8006E4C4  7C 1E 00 40 */	cmplw r30, r0
/* 8006E4C8  41 80 FF BC */	blt -0x44
/* 8006E4CC  7F 8C E3 78 */	mr r12, r28
/* 8006E4D0  7F 63 DB 78 */	mr r3, r27
/* 8006E4D4  7F A4 EB 78 */	mr r4, r29
/* 8006E4D8  7D 89 03 A6 */	mtctr r12
/* 8006E4DC  4E 80 04 21 */	bctrl 
/* 8006E4E0  38 03 FF FF */	addi r0, r3, -1
/* 8006E4E4  7C 00 00 34 */	cntlzw r0, r0
/* 8006E4E8  54 03 D9 7E */	srwi r3, r0, 5
/* 8006E4EC  48 00 00 84 */	b 0x84
/* 8006E4F0  7F 8C E3 78 */	mr r12, r28
/* 8006E4F4  7F A4 EB 78 */	mr r4, r29
/* 8006E4F8  7D 89 03 A6 */	mtctr r12
/* 8006E4FC  4E 80 04 21 */	bctrl 
/* 8006E500  2C 03 00 00 */	cmpwi r3, 0
/* 8006E504  40 82 00 60 */	bne 0x60
/* 8006E508  3B C0 00 00 */	li r30, 0
/* 8006E50C  3B E0 00 00 */	li r31, 0
/* 8006E510  48 00 00 40 */	b 0x40
/* 8006E514  80 7B 00 DC */	lwz r3, 0xdc(r27)
/* 8006E518  7F 84 E3 78 */	mr r4, r28
/* 8006E51C  7F A5 EB 78 */	mr r5, r29
/* 8006E520  38 C0 00 00 */	li r6, 0
/* 8006E524  7C 63 F8 2E */	lwzx r3, r3, r31
/* 8006E528  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E52C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8006E530  7D 89 03 A6 */	mtctr r12
/* 8006E534  4E 80 04 21 */	bctrl 
/* 8006E538  2C 03 00 01 */	cmpwi r3, 1
/* 8006E53C  40 82 00 0C */	bne 0xc
/* 8006E540  38 60 00 01 */	li r3, 1
/* 8006E544  48 00 00 2C */	b 0x2c
/* 8006E548  3B FF 00 04 */	addi r31, r31, 4
/* 8006E54C  3B DE 00 01 */	addi r30, r30, 1
/* 8006E550  80 1B 00 E4 */	lwz r0, 0xe4(r27)
/* 8006E554  7C 1E 00 40 */	cmplw r30, r0
/* 8006E558  41 80 FF BC */	blt -0x44
/* 8006E55C  38 60 00 00 */	li r3, 0
/* 8006E560  48 00 00 10 */	b 0x10
/* 8006E564  38 03 FF FF */	addi r0, r3, -1
/* 8006E568  7C 00 00 34 */	cntlzw r0, r0
/* 8006E56C  54 03 D9 7E */	srwi r3, r0, 5
/* 8006E570  39 61 00 20 */	addi r11, r1, 0x20
/* 8006E574  4B FB 30 79 */	bl -0x4cf88
/* 8006E578  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006E57C  7C 08 03 A6 */	mtlr r0
/* 8006E580  38 21 00 20 */	addi r1, r1, 0x20
/* 8006E584  4E 80 00 20 */	blr 
/* 8006E588  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E58C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E590  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006E594  7C 08 02 A6 */	mflr r0
/* 8006E598  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006E59C  39 61 00 20 */	addi r11, r1, 0x20
/* 8006E5A0  4B FB 2F FD */	bl -0x4d004
/* 8006E5A4  7C BF 2B 78 */	mr r31, r5
/* 8006E5A8  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006E5AC  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006E5B0  7C 9E 23 78 */	mr r30, r4
/* 8006E5B4  54 04 00 84 */	rlwinm r4, r0, 0, 2, 2
/* 8006E5B8  54 00 00 42 */	rlwinm r0, r0, 0, 1, 1
/* 8006E5BC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E5C0  7C 7D 1B 78 */	mr r29, r3
/* 8006E5C4  7C 85 00 34 */	cntlzw r5, r4
/* 8006E5C8  7C 00 00 34 */	cntlzw r0, r0
/* 8006E5CC  7F E3 FB 78 */	mr r3, r31
/* 8006E5D0  7F A4 EB 78 */	mr r4, r29
/* 8006E5D4  54 A5 D9 7E */	srwi r5, r5, 5
/* 8006E5D8  54 06 D9 7E */	srwi r6, r0, 5
/* 8006E5DC  7D 89 03 A6 */	mtctr r12
/* 8006E5E0  4E 80 04 21 */	bctrl 
/* 8006E5E4  2C 03 00 00 */	cmpwi r3, 0
/* 8006E5E8  40 82 00 4C */	bne 0x4c
/* 8006E5EC  3B 60 00 00 */	li r27, 0
/* 8006E5F0  3B 80 00 00 */	li r28, 0
/* 8006E5F4  48 00 00 30 */	b 0x30
/* 8006E5F8  80 7D 00 DC */	lwz r3, 0xdc(r29)
/* 8006E5FC  7F C5 F3 78 */	mr r5, r30
/* 8006E600  7F E6 FB 78 */	mr r6, r31
/* 8006E604  38 80 00 05 */	li r4, 5
/* 8006E608  7C 63 E0 2E */	lwzx r3, r3, r28
/* 8006E60C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E610  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E614  7D 89 03 A6 */	mtctr r12
/* 8006E618  4E 80 04 21 */	bctrl 
/* 8006E61C  3B 9C 00 04 */	addi r28, r28, 4
/* 8006E620  3B 7B 00 01 */	addi r27, r27, 1
/* 8006E624  80 1D 00 E4 */	lwz r0, 0xe4(r29)
/* 8006E628  7C 1B 00 40 */	cmplw r27, r0
/* 8006E62C  41 80 FF CC */	blt -0x34
/* 8006E630  48 00 00 60 */	b 0x60
/* 8006E634  2C 03 00 01 */	cmpwi r3, 1
/* 8006E638  40 82 00 58 */	bne 0x58
/* 8006E63C  83 6D 95 60 */	lwz r27, -0x6aa0(r13)
/* 8006E640  38 00 00 00 */	li r0, 0
/* 8006E644  3B 40 00 00 */	li r26, 0
/* 8006E648  3B 80 00 00 */	li r28, 0
/* 8006E64C  90 0D 95 60 */	stw r0, -0x6aa0(r13)
/* 8006E650  48 00 00 30 */	b 0x30
/* 8006E654  80 7D 00 DC */	lwz r3, 0xdc(r29)
/* 8006E658  7F C5 F3 78 */	mr r5, r30
/* 8006E65C  7F E6 FB 78 */	mr r6, r31
/* 8006E660  38 80 00 05 */	li r4, 5
/* 8006E664  7C 63 E0 2E */	lwzx r3, r3, r28
/* 8006E668  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E66C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E670  7D 89 03 A6 */	mtctr r12
/* 8006E674  4E 80 04 21 */	bctrl 
/* 8006E678  3B 9C 00 04 */	addi r28, r28, 4
/* 8006E67C  3B 5A 00 01 */	addi r26, r26, 1
/* 8006E680  80 1D 00 E4 */	lwz r0, 0xe4(r29)
/* 8006E684  7C 1A 00 40 */	cmplw r26, r0
/* 8006E688  41 80 FF CC */	blt -0x34
/* 8006E68C  93 6D 95 60 */	stw r27, -0x6aa0(r13)
/* 8006E690  39 61 00 20 */	addi r11, r1, 0x20
/* 8006E694  4B FB 2F 55 */	bl -0x4d0ac
/* 8006E698  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006E69C  7C 08 03 A6 */	mtlr r0
/* 8006E6A0  38 21 00 20 */	addi r1, r1, 0x20
/* 8006E6A4  4E 80 00 20 */	blr 
/* 8006E6A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E6AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E6B0  28 04 00 09 */	cmplwi r4, 9
/* 8006E6B4  40 80 00 24 */	bge 0x24
/* 8006E6B8  38 E4 FF FF */	addi r7, r4, -1
/* 8006E6BC  39 00 00 01 */	li r8, 1
/* 8006E6C0  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006E6C4  7D 07 38 30 */	slw r7, r8, r7
/* 8006E6C8  7C E0 00 39 */	and. r0, r7, r0
/* 8006E6CC  41 82 00 0C */	beq 0xc
/* 8006E6D0  38 00 00 01 */	li r0, 1
/* 8006E6D4  48 00 00 08 */	b 0x8
/* 8006E6D8  38 00 00 00 */	li r0, 0
/* 8006E6DC  2C 00 00 00 */	cmpwi r0, 0
/* 8006E6E0  4C 82 00 20 */	bnelr 
/* 8006E6E4  48 00 00 0C */	b 0xc
/* 8006E6E8  4E 80 00 20 */	blr 
/* 8006E6EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006E6F0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8006E6F4  7C 08 02 A6 */	mflr r0
/* 8006E6F8  90 01 00 34 */	stw r0, 0x34(r1)
/* 8006E6FC  39 61 00 30 */	addi r11, r1, 0x30
/* 8006E700  4B FB 2E 9D */	bl -0x4d164
/* 8006E704  2C 04 00 05 */	cmpwi r4, 5
/* 8006E708  7C 7D 1B 78 */	mr r29, r3
/* 8006E70C  7C 9A 23 78 */	mr r26, r4
/* 8006E710  7C BE 2B 78 */	mr r30, r5
/* 8006E714  7C DF 33 78 */	mr r31, r6
/* 8006E718  41 82 00 68 */	beq 0x68
/* 8006E71C  40 80 00 28 */	bge 0x28
/* 8006E720  2C 04 00 02 */	cmpwi r4, 2
/* 8006E724  41 82 01 A8 */	beq 0x1a8
/* 8006E728  40 80 00 10 */	bge 0x10
/* 8006E72C  2C 04 00 01 */	cmpwi r4, 1
/* 8006E730  40 80 00 60 */	bge 0x60
/* 8006E734  48 00 03 C4 */	b 0x3c4
/* 8006E738  2C 04 00 04 */	cmpwi r4, 4
/* 8006E73C  40 80 02 64 */	bge 0x264
/* 8006E740  48 00 03 B8 */	b 0x3b8
/* 8006E744  3C A0 00 01 */	lis r5, 1
/* 8006E748  38 05 00 02 */	addi r0, r5, 2
/* 8006E74C  7C 04 00 00 */	cmpw r4, r0
/* 8006E750  41 82 03 A0 */	beq 0x3a0
/* 8006E754  40 80 00 1C */	bge 0x1c
/* 8006E758  38 05 00 01 */	addi r0, r5, 1
/* 8006E75C  7C 04 00 00 */	cmpw r4, r0
/* 8006E760  40 80 03 6C */	bge 0x36c
/* 8006E764  2C 04 00 08 */	cmpwi r4, 8
/* 8006E768  40 80 03 90 */	bge 0x390
/* 8006E76C  48 00 03 D0 */	b 0x3d0
/* 8006E770  38 05 00 04 */	addi r0, r5, 4
/* 8006E774  7C 04 00 00 */	cmpw r4, r0
/* 8006E778  40 80 03 80 */	bge 0x380
/* 8006E77C  48 00 03 68 */	b 0x368
/* 8006E780  7F C4 F3 78 */	mr r4, r30
/* 8006E784  7F E5 FB 78 */	mr r5, r31
/* 8006E788  4B FF FE 09 */	bl -0x1f8
/* 8006E78C  48 00 03 B0 */	b 0x3b0
/* 8006E790  90 A1 00 08 */	stw r5, 8(r1)
/* 8006E794  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8006E798  2C 04 00 00 */	cmpwi r4, 0
/* 8006E79C  41 82 00 40 */	beq 0x40
/* 8006E7A0  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8006E7A4  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E7A8  41 82 00 34 */	beq 0x34
/* 8006E7AC  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006E7B0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E7B4  41 82 00 28 */	beq 0x28
/* 8006E7B8  81 84 00 00 */	lwz r12, 0(r4)
/* 8006E7BC  7C 83 23 78 */	mr r3, r4
/* 8006E7C0  7F A5 EB 78 */	mr r5, r29
/* 8006E7C4  7F C6 F3 78 */	mr r6, r30
/* 8006E7C8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E7CC  7F E7 FB 78 */	mr r7, r31
/* 8006E7D0  38 80 00 01 */	li r4, 1
/* 8006E7D4  7D 89 03 A6 */	mtctr r12
/* 8006E7D8  4E 80 04 21 */	bctrl 
/* 8006E7DC  81 9D 00 00 */	lwz r12, 0(r29)
/* 8006E7E0  7F A3 EB 78 */	mr r3, r29
/* 8006E7E4  7F E4 FB 78 */	mr r4, r31
/* 8006E7E8  38 A1 00 08 */	addi r5, r1, 8
/* 8006E7EC  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 8006E7F0  7D 89 03 A6 */	mtctr r12
/* 8006E7F4  4E 80 04 21 */	bctrl 
/* 8006E7F8  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 8006E7FC  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E800  2C 03 00 00 */	cmpwi r3, 0
/* 8006E804  41 82 00 38 */	beq 0x38
/* 8006E808  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 8006E80C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E810  41 82 00 2C */	beq 0x2c
/* 8006E814  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 8006E818  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E81C  41 82 00 20 */	beq 0x20
/* 8006E820  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E824  7F A5 EB 78 */	mr r5, r29
/* 8006E828  7F E7 FB 78 */	mr r7, r31
/* 8006E82C  38 80 00 02 */	li r4, 2
/* 8006E830  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E834  7D 89 03 A6 */	mtctr r12
/* 8006E838  4E 80 04 21 */	bctrl 
/* 8006E83C  3B 9D 00 3C */	addi r28, r29, 0x3c
/* 8006E840  3B C0 00 00 */	li r30, 0
/* 8006E844  3B 60 00 00 */	li r27, 0
/* 8006E848  48 00 00 30 */	b 0x30
/* 8006E84C  80 7D 00 DC */	lwz r3, 0xdc(r29)
/* 8006E850  7F 86 E3 78 */	mr r6, r28
/* 8006E854  80 A1 00 08 */	lwz r5, 8(r1)
/* 8006E858  38 80 00 01 */	li r4, 1
/* 8006E85C  7C 63 D8 2E */	lwzx r3, r3, r27
/* 8006E860  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E864  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E868  7D 89 03 A6 */	mtctr r12
/* 8006E86C  4E 80 04 21 */	bctrl 
/* 8006E870  3B 7B 00 04 */	addi r27, r27, 4
/* 8006E874  3B DE 00 01 */	addi r30, r30, 1
/* 8006E878  80 1D 00 E4 */	lwz r0, 0xe4(r29)
/* 8006E87C  7C 1E 00 40 */	cmplw r30, r0
/* 8006E880  41 80 FF CC */	blt -0x34
/* 8006E884  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 8006E888  80 C1 00 08 */	lwz r6, 8(r1)
/* 8006E88C  2C 03 00 00 */	cmpwi r3, 0
/* 8006E890  41 82 02 AC */	beq 0x2ac
/* 8006E894  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 8006E898  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E89C  41 82 02 A0 */	beq 0x2a0
/* 8006E8A0  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 8006E8A4  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E8A8  41 82 02 94 */	beq 0x294
/* 8006E8AC  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E8B0  7F A5 EB 78 */	mr r5, r29
/* 8006E8B4  7F E7 FB 78 */	mr r7, r31
/* 8006E8B8  38 80 00 04 */	li r4, 4
/* 8006E8BC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E8C0  7D 89 03 A6 */	mtctr r12
/* 8006E8C4  4E 80 04 21 */	bctrl 
/* 8006E8C8  48 00 02 74 */	b 0x274
/* 8006E8CC  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8006E8D0  2C 04 00 00 */	cmpwi r4, 0
/* 8006E8D4  41 82 00 40 */	beq 0x40
/* 8006E8D8  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8006E8DC  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E8E0  41 82 00 34 */	beq 0x34
/* 8006E8E4  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006E8E8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E8EC  41 82 00 28 */	beq 0x28
/* 8006E8F0  81 84 00 00 */	lwz r12, 0(r4)
/* 8006E8F4  7C 83 23 78 */	mr r3, r4
/* 8006E8F8  7F A5 EB 78 */	mr r5, r29
/* 8006E8FC  7F C6 F3 78 */	mr r6, r30
/* 8006E900  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8006E904  7F E7 FB 78 */	mr r7, r31
/* 8006E908  38 80 00 01 */	li r4, 1
/* 8006E90C  7D 89 03 A6 */	mtctr r12
/* 8006E910  4E 80 04 21 */	bctrl 
/* 8006E914  3B 80 00 00 */	li r28, 0
/* 8006E918  3B 60 00 00 */	li r27, 0
/* 8006E91C  48 00 00 30 */	b 0x30
/* 8006E920  80 7D 00 DC */	lwz r3, 0xdc(r29)
/* 8006E924  7F C5 F3 78 */	mr r5, r30
/* 8006E928  7F E6 FB 78 */	mr r6, r31
/* 8006E92C  38 80 00 02 */	li r4, 2
/* 8006E930  7C 63 D8 2E */	lwzx r3, r3, r27
/* 8006E934  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E938  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006E93C  7D 89 03 A6 */	mtctr r12
/* 8006E940  4E 80 04 21 */	bctrl 
/* 8006E944  3B 7B 00 04 */	addi r27, r27, 4
/* 8006E948  3B 9C 00 01 */	addi r28, r28, 1
/* 8006E94C  80 1D 00 E4 */	lwz r0, 0xe4(r29)
/* 8006E950  7C 1C 00 40 */	cmplw r28, r0
/* 8006E954  41 80 FF CC */	blt -0x34
/* 8006E958  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 8006E95C  2C 03 00 00 */	cmpwi r3, 0
/* 8006E960  41 82 01 DC */	beq 0x1dc
/* 8006E964  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 8006E968  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006E96C  41 82 01 D0 */	beq 0x1d0
/* 8006E970  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 8006E974  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E978  41 82 01 C4 */	beq 0x1c4
/* 8006E97C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006E980  7F A5 EB 78 */	mr r5, r29
/* 8006E984  7F C6 F3 78 */	mr r6, r30
/* 8006E988  7F E7 FB 78 */	mr r7, r31
/* 8006E98C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8006E990  38 80 00 04 */	li r4, 4
/* 8006E994  7D 89 03 A6 */	mtctr r12
/* 8006E998  4E 80 04 21 */	bctrl 
/* 8006E99C  48 00 01 A0 */	b 0x1a0
/* 8006E9A0  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8006E9A4  2C 04 00 00 */	cmpwi r4, 0
/* 8006E9A8  41 82 00 40 */	beq 0x40
/* 8006E9AC  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8006E9B0  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006E9B4  41 82 00 34 */	beq 0x34
/* 8006E9B8  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8006E9BC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006E9C0  41 82 00 28 */	beq 0x28
/* 8006E9C4  81 84 00 00 */	lwz r12, 0(r4)
/* 8006E9C8  7C 83 23 78 */	mr r3, r4
/* 8006E9CC  7F A5 EB 78 */	mr r5, r29
/* 8006E9D0  7F C6 F3 78 */	mr r6, r30
/* 8006E9D4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006E9D8  7F E7 FB 78 */	mr r7, r31
/* 8006E9DC  38 80 00 01 */	li r4, 1
/* 8006E9E0  7D 89 03 A6 */	mtctr r12
/* 8006E9E4  4E 80 04 21 */	bctrl 
/* 8006E9E8  7F E3 FB 78 */	mr r3, r31
/* 8006E9EC  38 9D 00 3C */	addi r4, r29, 0x3c
/* 8006E9F0  38 BD 00 6C */	addi r5, r29, 0x6c
/* 8006E9F4  48 12 B3 71 */	bl 0x12b370
/* 8006E9F8  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 8006E9FC  2C 03 00 00 */	cmpwi r3, 0
/* 8006EA00  41 82 00 3C */	beq 0x3c
/* 8006EA04  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 8006EA08  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006EA0C  41 82 00 30 */	beq 0x30
/* 8006EA10  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 8006EA14  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8006EA18  41 82 00 24 */	beq 0x24
/* 8006EA1C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EA20  7F A5 EB 78 */	mr r5, r29
/* 8006EA24  7F C6 F3 78 */	mr r6, r30
/* 8006EA28  7F E7 FB 78 */	mr r7, r31
/* 8006EA2C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006EA30  38 80 00 02 */	li r4, 2
/* 8006EA34  7D 89 03 A6 */	mtctr r12
/* 8006EA38  4E 80 04 21 */	bctrl 
/* 8006EA3C  3B 80 00 00 */	li r28, 0
/* 8006EA40  3B 60 00 00 */	li r27, 0
/* 8006EA44  48 00 00 30 */	b 0x30
/* 8006EA48  80 7D 00 DC */	lwz r3, 0xdc(r29)
/* 8006EA4C  7F C5 F3 78 */	mr r5, r30
/* 8006EA50  7F E6 FB 78 */	mr r6, r31
/* 8006EA54  38 80 00 04 */	li r4, 4
/* 8006EA58  7C 63 D8 2E */	lwzx r3, r3, r27
/* 8006EA5C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EA60  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006EA64  7D 89 03 A6 */	mtctr r12
/* 8006EA68  4E 80 04 21 */	bctrl 
/* 8006EA6C  3B 7B 00 04 */	addi r27, r27, 4
/* 8006EA70  3B 9C 00 01 */	addi r28, r28, 1
/* 8006EA74  80 1D 00 E4 */	lwz r0, 0xe4(r29)
/* 8006EA78  7C 1C 00 40 */	cmplw r28, r0
/* 8006EA7C  41 80 FF CC */	blt -0x34
/* 8006EA80  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 8006EA84  2C 03 00 00 */	cmpwi r3, 0
/* 8006EA88  41 82 00 B4 */	beq 0xb4
/* 8006EA8C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 8006EA90  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006EA94  41 82 00 A8 */	beq 0xa8
/* 8006EA98  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 8006EA9C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8006EAA0  41 82 00 9C */	beq 0x9c
/* 8006EAA4  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EAA8  7F A5 EB 78 */	mr r5, r29
/* 8006EAAC  7F C6 F3 78 */	mr r6, r30
/* 8006EAB0  7F E7 FB 78 */	mr r7, r31
/* 8006EAB4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006EAB8  38 80 00 04 */	li r4, 4
/* 8006EABC  7D 89 03 A6 */	mtctr r12
/* 8006EAC0  4E 80 04 21 */	bctrl 
/* 8006EAC4  48 00 00 78 */	b 0x78
/* 8006EAC8  48 00 00 74 */	b 0x74
/* 8006EACC  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EAD0  7F E4 FB 78 */	mr r4, r31
/* 8006EAD4  81 8C 00 3C */	lwz r12, 0x3c(r12)
/* 8006EAD8  7D 89 03 A6 */	mtctr r12
/* 8006EADC  4E 80 04 21 */	bctrl 
/* 8006EAE0  48 00 00 5C */	b 0x5c
/* 8006EAE4  38 00 00 00 */	li r0, 0
/* 8006EAE8  90 03 00 04 */	stw r0, 4(r3)
/* 8006EAEC  48 00 00 50 */	b 0x50
/* 8006EAF0  90 C3 00 04 */	stw r6, 4(r3)
/* 8006EAF4  48 00 00 48 */	b 0x48
/* 8006EAF8  3B 60 00 00 */	li r27, 0
/* 8006EAFC  3B 80 00 00 */	li r28, 0
/* 8006EB00  48 00 00 30 */	b 0x30
/* 8006EB04  80 7D 00 DC */	lwz r3, 0xdc(r29)
/* 8006EB08  7F 44 D3 78 */	mr r4, r26
/* 8006EB0C  7F C5 F3 78 */	mr r5, r30
/* 8006EB10  7F E6 FB 78 */	mr r6, r31
/* 8006EB14  7C 63 E0 2E */	lwzx r3, r3, r28
/* 8006EB18  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EB1C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006EB20  7D 89 03 A6 */	mtctr r12
/* 8006EB24  4E 80 04 21 */	bctrl 
/* 8006EB28  3B 9C 00 04 */	addi r28, r28, 4
/* 8006EB2C  3B 7B 00 01 */	addi r27, r27, 1
/* 8006EB30  80 1D 00 E4 */	lwz r0, 0xe4(r29)
/* 8006EB34  7C 1B 00 40 */	cmplw r27, r0
/* 8006EB38  41 80 FF CC */	blt -0x34
/* 8006EB3C  39 61 00 30 */	addi r11, r1, 0x30
/* 8006EB40  4B FB 2A A9 */	bl -0x4d558
/* 8006EB44  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8006EB48  7C 08 03 A6 */	mtlr r0
/* 8006EB4C  38 21 00 30 */	addi r1, r1, 0x30
/* 8006EB50  4E 80 00 20 */	blr 
/* 8006EB54  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EB58  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EB5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EB60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006EB64  7C 08 02 A6 */	mflr r0
/* 8006EB68  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006EB6C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006EB70  7C 7F 1B 78 */	mr r31, r3
/* 8006EB74  80 C3 00 E4 */	lwz r6, 0xe4(r3)
/* 8006EB78  7C 04 30 40 */	cmplw r4, r6
/* 8006EB7C  41 81 01 58 */	bgt 0x158
/* 8006EB80  80 03 00 E0 */	lwz r0, 0xe0(r3)
/* 8006EB84  7C 06 00 40 */	cmplw r6, r0
/* 8006EB88  40 80 01 4C */	bge 0x14c
/* 8006EB8C  2C 05 00 00 */	cmpwi r5, 0
/* 8006EB90  41 82 01 44 */	beq 0x144
/* 8006EB94  80 05 00 04 */	lwz r0, 4(r5)
/* 8006EB98  2C 00 00 00 */	cmpwi r0, 0
/* 8006EB9C  40 82 01 38 */	bne 0x138
/* 8006EBA0  7C 86 20 40 */	cmplw cr1, r6, r4
/* 8006EBA4  40 85 00 EC */	ble cr1, 0xec
/* 8006EBA8  7C 04 30 50 */	subf r0, r4, r6
/* 8006EBAC  38 E4 00 08 */	addi r7, r4, 8
/* 8006EBB0  28 00 00 08 */	cmplwi r0, 8
/* 8006EBB4  40 81 00 B0 */	ble 0xb0
/* 8006EBB8  41 84 00 AC */	blt cr1, 0xac
/* 8006EBBC  38 06 00 07 */	addi r0, r6, 7
/* 8006EBC0  54 C8 10 3A */	slwi r8, r6, 2
/* 8006EBC4  7C 07 00 50 */	subf r0, r7, r0
/* 8006EBC8  54 00 E8 FE */	srwi r0, r0, 3
/* 8006EBCC  7C 09 03 A6 */	mtctr r0
/* 8006EBD0  7C 06 38 40 */	cmplw r6, r7
/* 8006EBD4  40 81 00 90 */	ble 0x90
/* 8006EBD8  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EBDC  38 C6 FF F8 */	addi r6, r6, -8
/* 8006EBE0  7C E0 42 14 */	add r7, r0, r8
/* 8006EBE4  80 07 FF FC */	lwz r0, -4(r7)
/* 8006EBE8  90 07 00 00 */	stw r0, 0(r7)
/* 8006EBEC  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EBF0  7C E0 42 14 */	add r7, r0, r8
/* 8006EBF4  80 07 FF F8 */	lwz r0, -8(r7)
/* 8006EBF8  90 07 FF FC */	stw r0, -4(r7)
/* 8006EBFC  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC00  7C E0 42 14 */	add r7, r0, r8
/* 8006EC04  80 07 FF F4 */	lwz r0, -0xc(r7)
/* 8006EC08  90 07 FF F8 */	stw r0, -8(r7)
/* 8006EC0C  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC10  7C E0 42 14 */	add r7, r0, r8
/* 8006EC14  80 07 FF F0 */	lwz r0, -0x10(r7)
/* 8006EC18  90 07 FF F4 */	stw r0, -0xc(r7)
/* 8006EC1C  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC20  7C E0 42 14 */	add r7, r0, r8
/* 8006EC24  80 07 FF EC */	lwz r0, -0x14(r7)
/* 8006EC28  90 07 FF F0 */	stw r0, -0x10(r7)
/* 8006EC2C  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC30  7C E0 42 14 */	add r7, r0, r8
/* 8006EC34  80 07 FF E8 */	lwz r0, -0x18(r7)
/* 8006EC38  90 07 FF EC */	stw r0, -0x14(r7)
/* 8006EC3C  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC40  7C E0 42 14 */	add r7, r0, r8
/* 8006EC44  80 07 FF E4 */	lwz r0, -0x1c(r7)
/* 8006EC48  90 07 FF E8 */	stw r0, -0x18(r7)
/* 8006EC4C  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC50  7C E0 42 14 */	add r7, r0, r8
/* 8006EC54  39 08 FF E0 */	addi r8, r8, -32
/* 8006EC58  80 07 FF E0 */	lwz r0, -0x20(r7)
/* 8006EC5C  90 07 FF E4 */	stw r0, -0x1c(r7)
/* 8006EC60  42 00 FF 78 */	bdnz -0x88
/* 8006EC64  7C 04 30 50 */	subf r0, r4, r6
/* 8006EC68  54 C7 10 3A */	slwi r7, r6, 2
/* 8006EC6C  7C 09 03 A6 */	mtctr r0
/* 8006EC70  7C 06 20 40 */	cmplw r6, r4
/* 8006EC74  40 81 00 1C */	ble 0x1c
/* 8006EC78  80 03 00 DC */	lwz r0, 0xdc(r3)
/* 8006EC7C  7C C0 3A 14 */	add r6, r0, r7
/* 8006EC80  38 E7 FF FC */	addi r7, r7, -4
/* 8006EC84  80 06 FF FC */	lwz r0, -4(r6)
/* 8006EC88  90 06 00 00 */	stw r0, 0(r6)
/* 8006EC8C  42 00 FF EC */	bdnz -0x14
/* 8006EC90  80 C3 00 DC */	lwz r6, 0xdc(r3)
/* 8006EC94  54 80 10 3A */	slwi r0, r4, 2
/* 8006EC98  3C 80 00 01 */	lis r4, 1
/* 8006EC9C  7C A3 2B 78 */	mr r3, r5
/* 8006ECA0  7C A6 01 2E */	stwx r5, r6, r0
/* 8006ECA4  7F E6 FB 78 */	mr r6, r31
/* 8006ECA8  38 84 00 02 */	addi r4, r4, 2
/* 8006ECAC  38 A0 00 00 */	li r5, 0
/* 8006ECB0  81 83 00 00 */	lwz r12, 0(r3)
/* 8006ECB4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006ECB8  7D 89 03 A6 */	mtctr r12
/* 8006ECBC  4E 80 04 21 */	bctrl 
/* 8006ECC0  80 9F 00 E4 */	lwz r4, 0xe4(r31)
/* 8006ECC4  38 60 00 01 */	li r3, 1
/* 8006ECC8  38 04 00 01 */	addi r0, r4, 1
/* 8006ECCC  90 1F 00 E4 */	stw r0, 0xe4(r31)
/* 8006ECD0  48 00 00 08 */	b 0x8
/* 8006ECD4  38 60 00 00 */	li r3, 0
/* 8006ECD8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006ECDC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006ECE0  7C 08 03 A6 */	mtlr r0
/* 8006ECE4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006ECE8  4E 80 00 20 */	blr 
/* 8006ECEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006ECF0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006ECF4  7C 08 02 A6 */	mflr r0
/* 8006ECF8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006ECFC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006ED00  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006ED04  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8006ED08  7C 9D 23 78 */	mr r29, r4
/* 8006ED0C  93 81 00 10 */	stw r28, 0x10(r1)
/* 8006ED10  7C 7C 1B 78 */	mr r28, r3
/* 8006ED14  80 03 00 E4 */	lwz r0, 0xe4(r3)
/* 8006ED18  7C 04 00 40 */	cmplw r4, r0
/* 8006ED1C  40 80 00 70 */	bge 0x70
/* 8006ED20  80 A3 00 DC */	lwz r5, 0xdc(r3)
/* 8006ED24  54 9F 10 3A */	slwi r31, r4, 2
/* 8006ED28  3C 60 00 01 */	lis r3, 1
/* 8006ED2C  7F 86 E3 78 */	mr r6, r28
/* 8006ED30  7F C5 F8 2E */	lwzx r30, r5, r31
/* 8006ED34  38 83 00 03 */	addi r4, r3, 3
/* 8006ED38  38 A0 00 00 */	li r5, 0
/* 8006ED3C  81 9E 00 00 */	lwz r12, 0(r30)
/* 8006ED40  7F C3 F3 78 */	mr r3, r30
/* 8006ED44  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006ED48  7D 89 03 A6 */	mtctr r12
/* 8006ED4C  4E 80 04 21 */	bctrl 
/* 8006ED50  48 00 00 20 */	b 0x20
/* 8006ED54  60 00 00 00 */	nop 
/* 8006ED58  80 1C 00 DC */	lwz r0, 0xdc(r28)
/* 8006ED5C  3B BD 00 01 */	addi r29, r29, 1
/* 8006ED60  7C 60 FA 14 */	add r3, r0, r31
/* 8006ED64  3B FF 00 04 */	addi r31, r31, 4
/* 8006ED68  80 03 00 04 */	lwz r0, 4(r3)
/* 8006ED6C  90 03 00 00 */	stw r0, 0(r3)
/* 8006ED70  80 7C 00 E4 */	lwz r3, 0xe4(r28)
/* 8006ED74  38 03 FF FF */	addi r0, r3, -1
/* 8006ED78  7C 1D 00 40 */	cmplw r29, r0
/* 8006ED7C  41 80 FF DC */	blt -0x24
/* 8006ED80  90 1C 00 E4 */	stw r0, 0xe4(r28)
/* 8006ED84  7F C3 F3 78 */	mr r3, r30
/* 8006ED88  48 00 00 08 */	b 0x8
/* 8006ED8C  38 60 00 00 */	li r3, 0
/* 8006ED90  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006ED94  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006ED98  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006ED9C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8006EDA0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8006EDA4  7C 08 03 A6 */	mtlr r0
/* 8006EDA8  38 21 00 20 */	addi r1, r1, 0x20
/* 8006EDAC  4E 80 00 20 */	blr 
/* 8006EDB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006EDB4  7C 08 02 A6 */	mflr r0
/* 8006EDB8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006EDBC  80 03 00 E4 */	lwz r0, 0xe4(r3)
/* 8006EDC0  80 C3 00 DC */	lwz r6, 0xdc(r3)
/* 8006EDC4  54 00 10 3A */	slwi r0, r0, 2
/* 8006EDC8  7C C5 33 78 */	mr r5, r6
/* 8006EDCC  7C E6 02 14 */	add r7, r6, r0
/* 8006EDD0  48 00 00 0C */	b 0xc
/* 8006EDD4  60 00 00 00 */	nop 
/* 8006EDD8  38 A5 00 04 */	addi r5, r5, 4
/* 8006EDDC  7C 05 38 40 */	cmplw r5, r7
/* 8006EDE0  41 82 00 10 */	beq 0x10
/* 8006EDE4  80 05 00 00 */	lwz r0, 0(r5)
/* 8006EDE8  7C 00 20 40 */	cmplw r0, r4
/* 8006EDEC  40 82 FF EC */	bne -0x14
/* 8006EDF0  7C 05 38 40 */	cmplw r5, r7
/* 8006EDF4  41 82 00 30 */	beq 0x30
/* 8006EDF8  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EDFC  7C 06 28 50 */	subf r0, r6, r5
/* 8006EE00  7C 00 16 70 */	srawi r0, r0, 2
/* 8006EE04  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 8006EE08  7C 80 01 94 */	addze r4, r0
/* 8006EE0C  7D 89 03 A6 */	mtctr r12
/* 8006EE10  4E 80 04 21 */	bctrl 
/* 8006EE14  7C 03 00 D0 */	neg r0, r3
/* 8006EE18  7C 00 1B 78 */	or r0, r0, r3
/* 8006EE1C  54 03 0F FE */	srwi r3, r0, 0x1f
/* 8006EE20  48 00 00 08 */	b 0x8
/* 8006EE24  38 60 00 00 */	li r3, 0
/* 8006EE28  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006EE2C  7C 08 03 A6 */	mtlr r0
/* 8006EE30  38 21 00 10 */	addi r1, r1, 0x10
/* 8006EE34  4E 80 00 20 */	blr 
/* 8006EE38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EE3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EE40  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8006EE44  7C 08 02 A6 */	mflr r0
/* 8006EE48  90 01 00 24 */	stw r0, 0x24(r1)
/* 8006EE4C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8006EE50  7C DF 33 78 */	mr r31, r6
/* 8006EE54  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8006EE58  7C BE 2B 78 */	mr r30, r5
/* 8006EE5C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8006EE60  7C 7D 1B 78 */	mr r29, r3
/* 8006EE64  4B FF E9 4D */	bl -0x16b4
/* 8006EE68  80 1D 00 CC */	lwz r0, 0xcc(r29)
/* 8006EE6C  3C 60 80 27 */	lis r3, 0x8027
/* 8006EE70  38 63 30 D8 */	addi r3, r3, 0x30d8
/* 8006EE74  38 80 00 00 */	li r4, 0
/* 8006EE78  64 00 60 00 */	oris r0, r0, 0x6000
/* 8006EE7C  90 7D 00 00 */	stw r3, 0(r29)
/* 8006EE80  7F A3 EB 78 */	mr r3, r29
/* 8006EE84  93 DD 00 DC */	stw r30, 0xdc(r29)
/* 8006EE88  93 FD 00 E0 */	stw r31, 0xe0(r29)
/* 8006EE8C  90 9D 00 E4 */	stw r4, 0xe4(r29)
/* 8006EE90  90 1D 00 CC */	stw r0, 0xcc(r29)
/* 8006EE94  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8006EE98  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8006EE9C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8006EEA0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006EEA4  7C 08 03 A6 */	mtlr r0
/* 8006EEA8  38 21 00 20 */	addi r1, r1, 0x20
/* 8006EEAC  4E 80 00 20 */	blr 
/* 8006EEB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006EEB4  7C 08 02 A6 */	mflr r0
/* 8006EEB8  2C 03 00 00 */	cmpwi r3, 0
/* 8006EEBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006EEC0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006EEC4  7C 7F 1B 78 */	mr r31, r3
/* 8006EEC8  41 82 00 88 */	beq 0x88
/* 8006EECC  3C 80 80 27 */	lis r4, 0x8027
/* 8006EED0  38 84 30 D8 */	addi r4, r4, 0x30d8
/* 8006EED4  90 83 00 00 */	stw r4, 0(r3)
/* 8006EED8  48 00 00 1C */	b 0x1c
/* 8006EEDC  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006EEE0  7F E3 FB 78 */	mr r3, r31
/* 8006EEE4  38 84 FF FF */	addi r4, r4, -1
/* 8006EEE8  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 8006EEEC  7D 89 03 A6 */	mtctr r12
/* 8006EEF0  4E 80 04 21 */	bctrl 
/* 8006EEF4  80 9F 00 E4 */	lwz r4, 0xe4(r31)
/* 8006EEF8  2C 04 00 00 */	cmpwi r4, 0
/* 8006EEFC  40 82 FF E0 */	bne -0x20
/* 8006EF00  2C 1F 00 00 */	cmpwi r31, 0
/* 8006EF04  41 82 00 4C */	beq 0x4c
/* 8006EF08  80 7F 00 D4 */	lwz r3, 0xd4(r31)
/* 8006EF0C  3C 80 80 27 */	lis r4, 0x8027
/* 8006EF10  38 84 31 4C */	addi r4, r4, 0x314c
/* 8006EF14  90 9F 00 00 */	stw r4, 0(r31)
/* 8006EF18  2C 83 00 00 */	cmpwi cr1, r3, 0
/* 8006EF1C  41 86 00 28 */	beq cr1, 0x28
/* 8006EF20  88 1F 00 D9 */	lbz r0, 0xd9(r31)
/* 8006EF24  2C 00 00 01 */	cmpwi r0, 1
/* 8006EF28  40 82 00 1C */	bne 0x1c
/* 8006EF2C  41 86 00 18 */	beq cr1, 0x18
/* 8006EF30  81 83 00 00 */	lwz r12, 0(r3)
/* 8006EF34  38 80 00 01 */	li r4, 1
/* 8006EF38  81 8C 00 08 */	lwz r12, 8(r12)
/* 8006EF3C  7D 89 03 A6 */	mtctr r12
/* 8006EF40  4E 80 04 21 */	bctrl 
/* 8006EF44  7F E3 FB 78 */	mr r3, r31
/* 8006EF48  38 80 00 00 */	li r4, 0
/* 8006EF4C  4B FF 14 15 */	bl -0xebec
/* 8006EF50  7F E3 FB 78 */	mr r3, r31
/* 8006EF54  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006EF58  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006EF5C  7C 08 03 A6 */	mtlr r0
/* 8006EF60  38 21 00 10 */	addi r1, r1, 0x10
/* 8006EF64  4E 80 00 20 */	blr 
/* 8006EF68  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EF6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EF70  3C 60 80 24 */	lis r3, 0x8024
/* 8006EF74  80 04 00 00 */	lwz r0, 0(r4)
/* 8006EF78  38 63 7F 90 */	addi r3, r3, 0x7f90
/* 8006EF7C  7C 00 18 40 */	cmplw r0, r3
/* 8006EF80  40 82 00 0C */	bne 0xc
/* 8006EF84  38 60 00 01 */	li r3, 1
/* 8006EF88  4E 80 00 20 */	blr 
/* 8006EF8C  3C 60 80 24 */	lis r3, 0x8024
/* 8006EF90  80 04 00 00 */	lwz r0, 0(r4)
/* 8006EF94  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 8006EF98  7C 00 18 40 */	cmplw r0, r3
/* 8006EF9C  40 82 00 0C */	bne 0xc
/* 8006EFA0  38 60 00 01 */	li r3, 1
/* 8006EFA4  4E 80 00 20 */	blr 
/* 8006EFA8  3C 60 80 24 */	lis r3, 0x8024
/* 8006EFAC  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 8006EFB0  7C 00 18 50 */	subf r0, r0, r3
/* 8006EFB4  7C 00 00 34 */	cntlzw r0, r0
/* 8006EFB8  54 03 D9 7E */	srwi r3, r0, 5
/* 8006EFBC  4E 80 00 20 */	blr 
/* 8006EFC0  3C 60 80 24 */	lis r3, 0x8024
/* 8006EFC4  80 04 00 00 */	lwz r0, 0(r4)
/* 8006EFC8  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 8006EFCC  7C 00 18 40 */	cmplw r0, r3
/* 8006EFD0  40 82 00 0C */	bne 0xc
/* 8006EFD4  38 60 00 01 */	li r3, 1
/* 8006EFD8  4E 80 00 20 */	blr 
/* 8006EFDC  3C 60 80 24 */	lis r3, 0x8024
/* 8006EFE0  80 04 00 00 */	lwz r0, 0(r4)
/* 8006EFE4  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 8006EFE8  7C 00 18 50 */	subf r0, r0, r3
/* 8006EFEC  7C 00 00 34 */	cntlzw r0, r0
/* 8006EFF0  54 03 D9 7E */	srwi r3, r0, 5
/* 8006EFF4  4E 80 00 20 */	blr 
/* 8006EFF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006EFFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F000  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F004  7C 08 02 A6 */	mflr r0
/* 8006F008  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F00C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F010  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006F014  7D 89 03 A6 */	mtctr r12
/* 8006F018  4E 80 04 21 */	bctrl 
/* 8006F01C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F020  38 63 00 04 */	addi r3, r3, 4
/* 8006F024  7C 08 03 A6 */	mtlr r0
/* 8006F028  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F02C  4E 80 00 20 */	blr 
/* 8006F030  3C 60 80 24 */	lis r3, 0x8024
/* 8006F034  38 63 7F 90 */	addi r3, r3, 0x7f90
/* 8006F038  4E 80 00 20 */	blr 
/* 8006F03C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F040  3C 60 80 24 */	lis r3, 0x8024
/* 8006F044  80 04 00 00 */	lwz r0, 0(r4)
/* 8006F048  38 63 7F 80 */	addi r3, r3, 0x7f80
/* 8006F04C  7C 00 18 40 */	cmplw r0, r3
/* 8006F050  40 82 00 0C */	bne 0xc
/* 8006F054  38 60 00 01 */	li r3, 1
/* 8006F058  4E 80 00 20 */	blr 
/* 8006F05C  3C 60 80 24 */	lis r3, 0x8024
/* 8006F060  80 04 00 00 */	lwz r0, 0(r4)
/* 8006F064  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 8006F068  7C 00 18 40 */	cmplw r0, r3
/* 8006F06C  40 82 00 0C */	bne 0xc
/* 8006F070  38 60 00 01 */	li r3, 1
/* 8006F074  4E 80 00 20 */	blr 
/* 8006F078  3C 60 80 24 */	lis r3, 0x8024
/* 8006F07C  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 8006F080  7C 00 18 50 */	subf r0, r0, r3
/* 8006F084  7C 00 00 34 */	cntlzw r0, r0
/* 8006F088  54 03 D9 7E */	srwi r3, r0, 5
/* 8006F08C  4E 80 00 20 */	blr 
/* 8006F090  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F094  7C 08 02 A6 */	mflr r0
/* 8006F098  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F09C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F0A0  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006F0A4  7D 89 03 A6 */	mtctr r12
/* 8006F0A8  4E 80 04 21 */	bctrl 
/* 8006F0AC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F0B0  38 63 00 04 */	addi r3, r3, 4
/* 8006F0B4  7C 08 03 A6 */	mtlr r0
/* 8006F0B8  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F0BC  4E 80 00 20 */	blr 
/* 8006F0C0  3C 60 80 24 */	lis r3, 0x8024
/* 8006F0C4  38 63 7F 80 */	addi r3, r3, 0x7f80
/* 8006F0C8  4E 80 00 20 */	blr 
/* 8006F0CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F0D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F0D4  7C 08 02 A6 */	mflr r0
/* 8006F0D8  2C 03 00 00 */	cmpwi r3, 0
/* 8006F0DC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F0E0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006F0E4  7C 7F 1B 78 */	mr r31, r3
/* 8006F0E8  41 82 00 54 */	beq 0x54
/* 8006F0EC  41 82 00 50 */	beq 0x50
/* 8006F0F0  80 A3 00 D4 */	lwz r5, 0xd4(r3)
/* 8006F0F4  3C 80 80 27 */	lis r4, 0x8027
/* 8006F0F8  38 84 31 4C */	addi r4, r4, 0x314c
/* 8006F0FC  90 83 00 00 */	stw r4, 0(r3)
/* 8006F100  2C 85 00 00 */	cmpwi cr1, r5, 0
/* 8006F104  41 86 00 2C */	beq cr1, 0x2c
/* 8006F108  88 03 00 D9 */	lbz r0, 0xd9(r3)
/* 8006F10C  2C 00 00 01 */	cmpwi r0, 1
/* 8006F110  40 82 00 20 */	bne 0x20
/* 8006F114  41 86 00 1C */	beq cr1, 0x1c
/* 8006F118  81 85 00 00 */	lwz r12, 0(r5)
/* 8006F11C  7C A3 2B 78 */	mr r3, r5
/* 8006F120  38 80 00 01 */	li r4, 1
/* 8006F124  81 8C 00 08 */	lwz r12, 8(r12)
/* 8006F128  7D 89 03 A6 */	mtctr r12
/* 8006F12C  4E 80 04 21 */	bctrl 
/* 8006F130  7F E3 FB 78 */	mr r3, r31
/* 8006F134  38 80 00 00 */	li r4, 0
/* 8006F138  4B FF 12 29 */	bl -0xedd8
/* 8006F13C  7F E3 FB 78 */	mr r3, r31
/* 8006F140  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006F144  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F148  7C 08 03 A6 */	mtlr r0
/* 8006F14C  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F150  4E 80 00 20 */	blr 
/* 8006F154  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F158  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F15C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F160  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F164  7C 08 02 A6 */	mflr r0
/* 8006F168  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F16C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F170  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006F174  7D 89 03 A6 */	mtctr r12
/* 8006F178  4E 80 04 21 */	bctrl 
/* 8006F17C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F180  38 63 00 04 */	addi r3, r3, 4
/* 8006F184  7C 08 03 A6 */	mtlr r0
/* 8006F188  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F18C  4E 80 00 20 */	blr 
/* 8006F190  3C 60 80 24 */	lis r3, 0x8024
/* 8006F194  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 8006F198  4E 80 00 20 */	blr 
/* 8006F19C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F1A0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006F1A4  7C 08 02 A6 */	mflr r0
/* 8006F1A8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006F1AC  39 61 00 40 */	addi r11, r1, 0x40
/* 8006F1B0  4B FB 23 DD */	bl -0x4dc24
/* 8006F1B4  54 AA 10 3A */	slwi r10, r5, 2
/* 8006F1B8  7C B8 2B 78 */	mr r24, r5
/* 8006F1BC  39 4A 28 A7 */	addi r10, r10, 0x28a7
/* 8006F1C0  54 C9 18 38 */	slwi r9, r6, 3
/* 8006F1C4  55 5F 00 3A */	rlwinm r31, r10, 0, 0, 0x1d
/* 8006F1C8  54 E0 10 3A */	slwi r0, r7, 2
/* 8006F1CC  7D 3F 4A 14 */	add r9, r31, r9
/* 8006F1D0  2C 04 00 00 */	cmpwi r4, 0
/* 8006F1D4  39 29 00 03 */	addi r9, r9, 3
/* 8006F1D8  7C 77 1B 78 */	mr r23, r3
/* 8006F1DC  1C A7 00 44 */	mulli r5, r7, 0x44
/* 8006F1E0  7C D9 33 78 */	mr r25, r6
/* 8006F1E4  55 3E 00 3A */	rlwinm r30, r9, 0, 0, 0x1d
/* 8006F1E8  54 DC 10 3A */	slwi r28, r6, 2
/* 8006F1EC  7C BE 2A 14 */	add r5, r30, r5
/* 8006F1F0  7C FA 3B 78 */	mr r26, r7
/* 8006F1F4  38 A5 00 03 */	addi r5, r5, 3
/* 8006F1F8  7D 1B 43 78 */	mr r27, r8
/* 8006F1FC  54 BD 00 3A */	rlwinm r29, r5, 0, 0, 0x1d
/* 8006F200  38 C0 00 00 */	li r6, 0
/* 8006F204  7C BD 02 14 */	add r5, r29, r0
/* 8006F208  38 A5 00 03 */	addi r5, r5, 3
/* 8006F20C  1C 08 00 0C */	mulli r0, r8, 0xc
/* 8006F210  54 B6 00 3A */	rlwinm r22, r5, 0, 0, 0x1d
/* 8006F214  7C B6 02 14 */	add r5, r22, r0
/* 8006F218  38 05 00 03 */	addi r0, r5, 3
/* 8006F21C  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 8006F220  41 82 00 08 */	beq 0x8
/* 8006F224  90 04 00 00 */	stw r0, 0(r4)
/* 8006F228  2C 03 00 00 */	cmpwi r3, 0
/* 8006F22C  41 82 00 90 */	beq 0x90
/* 8006F230  7E E3 BB 78 */	mr r3, r23
/* 8006F234  7C 04 03 78 */	mr r4, r0
/* 8006F238  48 12 A9 61 */	bl 0x12a960
/* 8006F23C  2C 03 00 00 */	cmpwi r3, 0
/* 8006F240  40 82 00 0C */	bne 0xc
/* 8006F244  38 60 00 00 */	li r3, 0
/* 8006F248  48 00 00 78 */	b 0x78
/* 8006F24C  34 A3 28 8C */	addic. r5, r3, 0x288c
/* 8006F250  7C E3 FA 14 */	add r7, r3, r31
/* 8006F254  41 82 00 2C */	beq 0x2c
/* 8006F258  3C C0 80 27 */	lis r6, 0x8027
/* 8006F25C  7C 87 E2 14 */	add r4, r7, r28
/* 8006F260  38 C6 31 80 */	addi r6, r6, 0x3180
/* 8006F264  90 C5 00 00 */	stw r6, 0(r5)
/* 8006F268  38 00 00 00 */	li r0, 0
/* 8006F26C  90 E5 00 04 */	stw r7, 4(r5)
/* 8006F270  90 85 00 08 */	stw r4, 8(r5)
/* 8006F274  93 25 00 0C */	stw r25, 0xc(r5)
/* 8006F278  90 05 00 10 */	stw r0, 0x10(r5)
/* 8006F27C  90 05 00 14 */	stw r0, 0x14(r5)
/* 8006F280  2C 03 00 00 */	cmpwi r3, 0
/* 8006F284  7C 66 1B 78 */	mr r6, r3
/* 8006F288  7D 43 F2 14 */	add r10, r3, r30
/* 8006F28C  7C 03 EA 14 */	add r0, r3, r29
/* 8006F290  7C E3 B2 14 */	add r7, r3, r22
/* 8006F294  41 82 00 28 */	beq 0x28
/* 8006F298  90 01 00 08 */	stw r0, 8(r1)
/* 8006F29C  7E E4 BB 78 */	mr r4, r23
/* 8006F2A0  7F 48 D3 78 */	mr r8, r26
/* 8006F2A4  7F 69 DB 78 */	mr r9, r27
/* 8006F2A8  90 E1 00 0C */	stw r7, 0xc(r1)
/* 8006F2AC  7F 07 C3 78 */	mr r7, r24
/* 8006F2B0  38 C3 28 A4 */	addi r6, r3, 0x28a4
/* 8006F2B4  48 00 0A 9D */	bl 0xa9c
/* 8006F2B8  7C 66 1B 78 */	mr r6, r3
/* 8006F2BC  7C C3 33 78 */	mr r3, r6
/* 8006F2C0  39 61 00 40 */	addi r11, r1, 0x40
/* 8006F2C4  4B FB 23 15 */	bl -0x4dcec
/* 8006F2C8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006F2CC  7C 08 03 A6 */	mtlr r0
/* 8006F2D0  38 21 00 40 */	addi r1, r1, 0x40
/* 8006F2D4  4E 80 00 20 */	blr 
/* 8006F2D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F2DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F2E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F2E4  7C 08 02 A6 */	mflr r0
/* 8006F2E8  28 04 00 09 */	cmplwi r4, 9
/* 8006F2EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F2F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006F2F4  7C 7F 1B 78 */	mr r31, r3
/* 8006F2F8  40 80 00 24 */	bge 0x24
/* 8006F2FC  38 E4 FF FF */	addi r7, r4, -1
/* 8006F300  39 00 00 01 */	li r8, 1
/* 8006F304  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 8006F308  7D 07 38 30 */	slw r7, r8, r7
/* 8006F30C  7C E0 00 39 */	and. r0, r7, r0
/* 8006F310  41 82 00 0C */	beq 0xc
/* 8006F314  38 00 00 01 */	li r0, 1
/* 8006F318  48 00 00 08 */	b 0x8
/* 8006F31C  38 00 00 00 */	li r0, 0
/* 8006F320  2C 00 00 00 */	cmpwi r0, 0
/* 8006F324  40 82 00 50 */	bne 0x50
/* 8006F328  3C 04 FF FF */	addis r0, r4, 0xffff
/* 8006F32C  28 00 00 01 */	cmplwi r0, 1
/* 8006F330  40 82 00 3C */	bne 0x3c
/* 8006F334  80 63 28 88 */	lwz r3, 0x2888(r3)
/* 8006F338  7C 03 30 40 */	cmplw r3, r6
/* 8006F33C  40 82 00 30 */	bne 0x30
/* 8006F340  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F344  3C 80 00 01 */	lis r4, 1
/* 8006F348  7F E6 FB 78 */	mr r6, r31
/* 8006F34C  38 A0 00 00 */	li r5, 0
/* 8006F350  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006F354  38 84 00 03 */	addi r4, r4, 3
/* 8006F358  7D 89 03 A6 */	mtctr r12
/* 8006F35C  4E 80 04 21 */	bctrl 
/* 8006F360  38 00 00 00 */	li r0, 0
/* 8006F364  90 1F 28 88 */	stw r0, 0x2888(r31)
/* 8006F368  48 00 00 0C */	b 0xc
/* 8006F36C  7F E3 FB 78 */	mr r3, r31
/* 8006F370  4B FF F3 81 */	bl -0xc80
/* 8006F374  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F378  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006F37C  7C 08 03 A6 */	mtlr r0
/* 8006F380  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F384  4E 80 00 20 */	blr 
/* 8006F388  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F38C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F390  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F394  7C 08 02 A6 */	mflr r0
/* 8006F398  2C 04 00 00 */	cmpwi r4, 0
/* 8006F39C  7C 65 1B 78 */	mr r5, r3
/* 8006F3A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F3A4  41 80 00 28 */	blt 0x28
/* 8006F3A8  2C 04 00 20 */	cmpwi r4, 0x20
/* 8006F3AC  40 80 00 20 */	bge 0x20
/* 8006F3B0  1C 04 01 0C */	mulli r0, r4, 0x10c
/* 8006F3B4  38 61 00 0C */	addi r3, r1, 0xc
/* 8006F3B8  7C 85 02 14 */	add r4, r5, r0
/* 8006F3BC  38 84 00 F8 */	addi r4, r4, 0xf8
/* 8006F3C0  4B FF AD 01 */	bl -0x5300
/* 8006F3C4  80 63 00 00 */	lwz r3, 0(r3)
/* 8006F3C8  48 00 00 14 */	b 0x14
/* 8006F3CC  38 61 00 08 */	addi r3, r1, 8
/* 8006F3D0  38 80 00 00 */	li r4, 0
/* 8006F3D4  4B FF AC ED */	bl -0x5314
/* 8006F3D8  80 63 00 00 */	lwz r3, 0(r3)
/* 8006F3DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F3E0  7C 08 03 A6 */	mtlr r0
/* 8006F3E4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F3E8  4E 80 00 20 */	blr 
/* 8006F3EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F3F0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F3F4  7C 08 02 A6 */	mflr r0
/* 8006F3F8  7C 64 1B 78 */	mr r4, r3
/* 8006F3FC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F400  38 61 00 08 */	addi r3, r1, 8
/* 8006F404  88 04 00 F4 */	lbz r0, 0xf4(r4)
/* 8006F408  1C 00 01 0C */	mulli r0, r0, 0x10c
/* 8006F40C  7C 84 02 14 */	add r4, r4, r0
/* 8006F410  38 84 00 F8 */	addi r4, r4, 0xf8
/* 8006F414  4B FF AC AD */	bl -0x5354
/* 8006F418  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F41C  80 63 00 00 */	lwz r3, 0(r3)
/* 8006F420  7C 08 03 A6 */	mtlr r0
/* 8006F424  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F428  4E 80 00 20 */	blr 
/* 8006F42C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F430  98 83 00 F4 */	stb r4, 0xf4(r3)
/* 8006F434  4E 80 00 20 */	blr 
/* 8006F438  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F43C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F440  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F444  7C 08 02 A6 */	mflr r0
/* 8006F448  2C 04 00 00 */	cmpwi r4, 0
/* 8006F44C  7C 65 1B 78 */	mr r5, r3
/* 8006F450  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F454  41 80 00 28 */	blt 0x28
/* 8006F458  2C 04 00 20 */	cmpwi r4, 0x20
/* 8006F45C  40 80 00 20 */	bge 0x20
/* 8006F460  1C 04 00 30 */	mulli r0, r4, 0x30
/* 8006F464  38 61 00 0C */	addi r3, r1, 0xc
/* 8006F468  7C 85 02 14 */	add r4, r5, r0
/* 8006F46C  38 84 22 78 */	addi r4, r4, 0x2278
/* 8006F470  48 00 80 61 */	bl 0x8060
/* 8006F474  80 63 00 00 */	lwz r3, 0(r3)
/* 8006F478  48 00 00 14 */	b 0x14
/* 8006F47C  38 61 00 08 */	addi r3, r1, 8
/* 8006F480  38 80 00 00 */	li r4, 0
/* 8006F484  48 00 80 4D */	bl 0x804c
/* 8006F488  80 63 00 00 */	lwz r3, 0(r3)
/* 8006F48C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F490  7C 08 03 A6 */	mtlr r0
/* 8006F494  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F498  4E 80 00 20 */	blr 
/* 8006F49C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F4A0  A0 04 28 7A */	lhz r0, 0x287a(r4)
/* 8006F4A4  7C 05 00 00 */	cmpw r5, r0
/* 8006F4A8  40 80 00 28 */	bge 0x28
/* 8006F4AC  2C 05 00 00 */	cmpwi r5, 0
/* 8006F4B0  41 80 00 20 */	blt 0x20
/* 8006F4B4  1C A5 00 0C */	mulli r5, r5, 0xc
/* 8006F4B8  80 C4 28 84 */	lwz r6, 0x2884(r4)
/* 8006F4BC  38 04 28 78 */	addi r0, r4, 0x2878
/* 8006F4C0  90 03 00 00 */	stw r0, 0(r3)
/* 8006F4C4  7C 06 2A 14 */	add r0, r6, r5
/* 8006F4C8  90 03 00 04 */	stw r0, 4(r3)
/* 8006F4CC  4E 80 00 20 */	blr 
/* 8006F4D0  38 84 28 78 */	addi r4, r4, 0x2878
/* 8006F4D4  38 00 00 00 */	li r0, 0
/* 8006F4D8  90 83 00 00 */	stw r4, 0(r3)
/* 8006F4DC  90 03 00 04 */	stw r0, 4(r3)
/* 8006F4E0  4E 80 00 20 */	blr 
/* 8006F4E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F4E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F4EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F4F0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F4F4  7C 08 02 A6 */	mflr r0
/* 8006F4F8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F4FC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006F500  7C 9F 23 78 */	mr r31, r4
/* 8006F504  93 C1 00 08 */	stw r30, 8(r1)
/* 8006F508  7C 7E 1B 78 */	mr r30, r3
/* 8006F50C  80 03 28 88 */	lwz r0, 0x2888(r3)
/* 8006F510  2C 00 00 00 */	cmpwi r0, 0
/* 8006F514  41 82 00 34 */	beq 0x34
/* 8006F518  41 82 00 30 */	beq 0x30
/* 8006F51C  7C 03 03 78 */	mr r3, r0
/* 8006F520  3C 80 00 01 */	lis r4, 1
/* 8006F524  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F528  7F C6 F3 78 */	mr r6, r30
/* 8006F52C  38 84 00 03 */	addi r4, r4, 3
/* 8006F530  38 A0 00 00 */	li r5, 0
/* 8006F534  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006F538  7D 89 03 A6 */	mtctr r12
/* 8006F53C  4E 80 04 21 */	bctrl 
/* 8006F540  38 00 00 00 */	li r0, 0
/* 8006F544  90 1E 28 88 */	stw r0, 0x2888(r30)
/* 8006F548  93 FE 28 88 */	stw r31, 0x2888(r30)
/* 8006F54C  3C 80 00 01 */	lis r4, 1
/* 8006F550  7F E3 FB 78 */	mr r3, r31
/* 8006F554  7F C6 F3 78 */	mr r6, r30
/* 8006F558  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006F55C  38 84 00 02 */	addi r4, r4, 2
/* 8006F560  38 A0 00 00 */	li r5, 0
/* 8006F564  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006F568  7D 89 03 A6 */	mtctr r12
/* 8006F56C  4E 80 04 21 */	bctrl 
/* 8006F570  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006F574  38 60 00 01 */	li r3, 1
/* 8006F578  83 C1 00 08 */	lwz r30, 8(r1)
/* 8006F57C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F580  7C 08 03 A6 */	mtlr r0
/* 8006F584  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F588  4E 80 00 20 */	blr 
/* 8006F58C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F590  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F594  7C 08 02 A6 */	mflr r0
/* 8006F598  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F59C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006F5A0  7C 7F 1B 78 */	mr r31, r3
/* 8006F5A4  80 03 28 88 */	lwz r0, 0x2888(r3)
/* 8006F5A8  2C 00 00 00 */	cmpwi r0, 0
/* 8006F5AC  41 82 00 18 */	beq 0x18
/* 8006F5B0  7C 03 03 78 */	mr r3, r0
/* 8006F5B4  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F5B8  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 8006F5BC  7D 89 03 A6 */	mtctr r12
/* 8006F5C0  4E 80 04 21 */	bctrl 
/* 8006F5C4  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006F5C8  7F E3 FB 78 */	mr r3, r31
/* 8006F5CC  38 80 00 08 */	li r4, 8
/* 8006F5D0  38 A0 00 00 */	li r5, 0
/* 8006F5D4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006F5D8  38 C0 00 00 */	li r6, 0
/* 8006F5DC  7D 89 03 A6 */	mtctr r12
/* 8006F5E0  4E 80 04 21 */	bctrl 
/* 8006F5E4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F5E8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006F5EC  7C 08 03 A6 */	mtlr r0
/* 8006F5F0  38 21 00 10 */	addi r1, r1, 0x10
/* 8006F5F4  4E 80 00 20 */	blr 
/* 8006F5F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F5FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F600  94 21 FF 30 */	stwu r1, -0xd0(r1)
/* 8006F604  7C 08 02 A6 */	mflr r0
/* 8006F608  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8006F60C  DB E1 00 C0 */	stfd f31, 0xc0(r1)
/* 8006F610  F3 E1 00 C8 */	psq_st f31, 200(r1), 0, qr0
/* 8006F614  DB C1 00 B0 */	stfd f30, 0xb0(r1)
/* 8006F618  F3 C1 00 B8 */	psq_st f30, 184(r1), 0, qr0
/* 8006F61C  DB A1 00 A0 */	stfd f29, 0xa0(r1)
/* 8006F620  F3 A1 00 A8 */	psq_st f29, 168(r1), 0, qr0
/* 8006F624  39 61 00 A0 */	addi r11, r1, 0xa0
/* 8006F628  4B FB 1F 69 */	bl -0x4e098
/* 8006F62C  7C 77 1B 78 */	mr r23, r3
/* 8006F630  38 61 00 10 */	addi r3, r1, 0x10
/* 8006F634  88 17 00 F4 */	lbz r0, 0xf4(r23)
/* 8006F638  1C 00 01 0C */	mulli r0, r0, 0x10c
/* 8006F63C  7C 97 02 14 */	add r4, r23, r0
/* 8006F640  38 84 00 F8 */	addi r4, r4, 0xf8
/* 8006F644  4B FF AA 7D */	bl -0x5584
/* 8006F648  80 03 00 00 */	lwz r0, 0(r3)
/* 8006F64C  38 61 00 28 */	addi r3, r1, 0x28
/* 8006F650  90 01 00 28 */	stw r0, 0x28(r1)
/* 8006F654  4B FF B3 9D */	bl -0x4c64
/* 8006F658  38 61 00 28 */	addi r3, r1, 0x28
/* 8006F65C  4B FF B4 25 */	bl -0x4bdc
/* 8006F660  38 61 00 28 */	addi r3, r1, 0x28
/* 8006F664  4B FF B4 ED */	bl -0x4b14
/* 8006F668  38 61 00 28 */	addi r3, r1, 0x28
/* 8006F66C  4B FF B5 15 */	bl -0x4aec
/* 8006F670  3B 17 00 F8 */	addi r24, r23, 0xf8
/* 8006F674  3B 20 00 00 */	li r25, 0
/* 8006F678  7F 04 C3 78 */	mr r4, r24
/* 8006F67C  38 61 00 18 */	addi r3, r1, 0x18
/* 8006F680  4B FF AA 41 */	bl -0x55c0
/* 8006F684  88 17 00 F4 */	lbz r0, 0xf4(r23)
/* 8006F688  7F 24 CB 78 */	mr r4, r25
/* 8006F68C  7C 19 00 50 */	subf r0, r25, r0
/* 8006F690  7C 00 00 34 */	cntlzw r0, r0
/* 8006F694  54 05 D9 7E */	srwi r5, r0, 5
/* 8006F698  4B FF 4A 39 */	bl -0xb5c8
/* 8006F69C  3B 39 00 01 */	addi r25, r25, 1
/* 8006F6A0  3B 18 01 0C */	addi r24, r24, 0x10c
/* 8006F6A4  2C 19 00 20 */	cmpwi r25, 0x20
/* 8006F6A8  41 80 FF D0 */	blt -0x30
/* 8006F6AC  80 A1 00 28 */	lwz r5, 0x28(r1)
/* 8006F6B0  38 00 00 08 */	li r0, 8
/* 8006F6B4  C3 E2 8D 98 */	lfs f31, -0x7268(r2)
/* 8006F6B8  3B B7 22 78 */	addi r29, r23, 0x2278
/* 8006F6BC  80 65 00 A8 */	lwz r3, 0xa8(r5)
/* 8006F6C0  3B E1 00 0C */	addi r31, r1, 0xc
/* 8006F6C4  C3 C5 00 B4 */	lfs f30, 0xb4(r5)
/* 8006F6C8  3B C1 00 08 */	addi r30, r1, 8
/* 8006F6CC  38 83 FF FF */	addi r4, r3, -1
/* 8006F6D0  20 63 00 01 */	subfic r3, r3, 1
/* 8006F6D4  7C 83 1B 78 */	or r3, r4, r3
/* 8006F6D8  C3 A5 00 B8 */	lfs f29, 0xb8(r5)
/* 8006F6DC  7C 63 FE 70 */	srawi r3, r3, 0x1f
/* 8006F6E0  3B 40 00 00 */	li r26, 0
/* 8006F6E4  7C 1B 18 78 */	andc r27, r0, r3
/* 8006F6E8  3B 20 00 00 */	li r25, 0
/* 8006F6EC  3B 00 00 00 */	li r24, 0
/* 8006F6F0  3B 80 00 00 */	li r28, 0
/* 8006F6F4  7F A4 EB 78 */	mr r4, r29
/* 8006F6F8  38 61 00 24 */	addi r3, r1, 0x24
/* 8006F6FC  48 00 7D D5 */	bl 0x7dd4
/* 8006F700  80 81 00 24 */	lwz r4, 0x24(r1)
/* 8006F704  2C 04 00 00 */	cmpwi r4, 0
/* 8006F708  41 82 00 10 */	beq 0x10
/* 8006F70C  80 61 00 24 */	lwz r3, 0x24(r1)
/* 8006F710  D3 C3 00 0C */	stfs f30, 0xc(r3)
/* 8006F714  D3 A4 00 10 */	stfs f29, 0x10(r4)
/* 8006F718  80 61 00 24 */	lwz r3, 0x24(r1)
/* 8006F71C  80 03 00 00 */	lwz r0, 0(r3)
/* 8006F720  2C 00 00 00 */	cmpwi r0, 0
/* 8006F724  41 82 00 10 */	beq 0x10
/* 8006F728  54 00 07 76 */	rlwinm r0, r0, 0, 0x1d, 0x1b
/* 8006F72C  7F 60 03 78 */	or r0, r27, r0
/* 8006F730  90 03 00 00 */	stw r0, 0(r3)
/* 8006F734  80 81 00 24 */	lwz r4, 0x24(r1)
/* 8006F738  38 60 00 00 */	li r3, 0
/* 8006F73C  2C 04 00 00 */	cmpwi r4, 0
/* 8006F740  41 82 00 14 */	beq 0x14
/* 8006F744  88 04 00 18 */	lbz r0, 0x18(r4)
/* 8006F748  28 00 00 01 */	cmplwi r0, 1
/* 8006F74C  40 82 00 08 */	bne 0x8
/* 8006F750  38 60 00 01 */	li r3, 1
/* 8006F754  2C 03 00 00 */	cmpwi r3, 0
/* 8006F758  41 82 00 74 */	beq 0x74
/* 8006F75C  2C 18 00 00 */	cmpwi r24, 0
/* 8006F760  40 82 00 58 */	bne 0x58
/* 8006F764  38 61 00 28 */	addi r3, r1, 0x28
/* 8006F768  38 81 00 30 */	addi r4, r1, 0x30
/* 8006F76C  4B FF B0 55 */	bl -0x4fac
/* 8006F770  38 61 00 28 */	addi r3, r1, 0x28
/* 8006F774  38 81 00 1C */	addi r4, r1, 0x1c
/* 8006F778  38 C1 00 20 */	addi r6, r1, 0x20
/* 8006F77C  38 A0 00 00 */	li r5, 0
/* 8006F780  38 E0 00 00 */	li r7, 0
/* 8006F784  39 00 00 00 */	li r8, 0
/* 8006F788  39 20 00 00 */	li r9, 0
/* 8006F78C  4B FF AF 65 */	bl -0x509c
/* 8006F790  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 8006F794  F0 1F B0 00 */	psq_st f0, 0(r31), 1, qr3
/* 8006F798  C0 21 00 20 */	lfs f1, 0x20(r1)
/* 8006F79C  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 8006F7A0  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8006F7A4  A3 41 00 0C */	lhz r26, 0xc(r1)
/* 8006F7A8  EC 00 08 2A */	fadds f0, f0, f1
/* 8006F7AC  F0 1E B0 00 */	psq_st f0, 0(r30), 1, qr3
/* 8006F7B0  3B 00 00 01 */	li r24, 1
/* 8006F7B4  A3 21 00 08 */	lhz r25, 8(r1)
/* 8006F7B8  7F 44 D3 78 */	mr r4, r26
/* 8006F7BC  7F 25 CB 78 */	mr r5, r25
/* 8006F7C0  38 61 00 24 */	addi r3, r1, 0x24
/* 8006F7C4  38 C1 00 30 */	addi r6, r1, 0x30
/* 8006F7C8  48 00 7D E9 */	bl 0x7de8
/* 8006F7CC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8006F7D0  7F 84 E3 78 */	mr r4, r28
/* 8006F7D4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F7D8  38 61 00 14 */	addi r3, r1, 0x14
/* 8006F7DC  4B FF 46 65 */	bl -0xb99c
/* 8006F7E0  3B 9C 00 01 */	addi r28, r28, 1
/* 8006F7E4  3B BD 00 30 */	addi r29, r29, 0x30
/* 8006F7E8  2C 1C 00 20 */	cmpwi r28, 0x20
/* 8006F7EC  41 80 FF 08 */	blt -0xf8
/* 8006F7F0  38 77 28 78 */	addi r3, r23, 0x2878
/* 8006F7F4  4B FF 47 AD */	bl -0xb854
/* 8006F7F8  E3 E1 00 C8 */	psq_l f31, 200(r1), 0, qr0
/* 8006F7FC  CB E1 00 C0 */	lfd f31, 0xc0(r1)
/* 8006F800  E3 C1 00 B8 */	psq_l f30, 184(r1), 0, qr0
/* 8006F804  CB C1 00 B0 */	lfd f30, 0xb0(r1)
/* 8006F808  E3 A1 00 A8 */	psq_l f29, 168(r1), 0, qr0
/* 8006F80C  39 61 00 A0 */	addi r11, r1, 0xa0
/* 8006F810  CB A1 00 A0 */	lfd f29, 0xa0(r1)
/* 8006F814  4B FB 1D C9 */	bl -0x4e238
/* 8006F818  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 8006F81C  7C 08 03 A6 */	mtlr r0
/* 8006F820  38 21 00 D0 */	addi r1, r1, 0xd0
/* 8006F824  4E 80 00 20 */	blr 
/* 8006F828  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F82C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F830  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8006F834  7C 08 02 A6 */	mflr r0
/* 8006F838  90 01 00 34 */	stw r0, 0x34(r1)
/* 8006F83C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8006F840  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8006F844  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8006F848  93 81 00 20 */	stw r28, 0x20(r1)
/* 8006F84C  7C 7C 1B 78 */	mr r28, r3
/* 8006F850  80 03 28 88 */	lwz r0, 0x2888(r3)
/* 8006F854  2C 00 00 00 */	cmpwi r0, 0
/* 8006F858  41 82 01 40 */	beq 0x140
/* 8006F85C  7C 03 03 78 */	mr r3, r0
/* 8006F860  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F864  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 8006F868  7D 89 03 A6 */	mtctr r12
/* 8006F86C  4E 80 04 21 */	bctrl 
/* 8006F870  7C 7F 1B 78 */	mr r31, r3
/* 8006F874  80 7C 28 88 */	lwz r3, 0x2888(r28)
/* 8006F878  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F87C  81 8C 00 5C */	lwz r12, 0x5c(r12)
/* 8006F880  7D 89 03 A6 */	mtctr r12
/* 8006F884  4E 80 04 21 */	bctrl 
/* 8006F888  90 61 00 1C */	stw r3, 0x1c(r1)
/* 8006F88C  80 7C 28 88 */	lwz r3, 0x2888(r28)
/* 8006F890  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F894  81 8C 00 60 */	lwz r12, 0x60(r12)
/* 8006F898  7D 89 03 A6 */	mtctr r12
/* 8006F89C  4E 80 04 21 */	bctrl 
/* 8006F8A0  2C 1F 00 00 */	cmpwi r31, 0
/* 8006F8A4  90 61 00 18 */	stw r3, 0x18(r1)
/* 8006F8A8  41 82 00 10 */	beq 0x10
/* 8006F8AC  80 7C 28 88 */	lwz r3, 0x2888(r28)
/* 8006F8B0  38 9C 28 78 */	addi r4, r28, 0x2878
/* 8006F8B4  4B FE F7 3D */	bl -0x108c4
/* 8006F8B8  80 81 00 1C */	lwz r4, 0x1c(r1)
/* 8006F8BC  2C 04 00 00 */	cmpwi r4, 0
/* 8006F8C0  41 82 00 68 */	beq 0x68
/* 8006F8C4  80 0D 81 40 */	lwz r0, -0x7ec0(r13)
/* 8006F8C8  38 6D 81 40 */	addi r3, r13, -32448
/* 8006F8CC  7C 04 00 40 */	cmplw r4, r0
/* 8006F8D0  40 80 00 08 */	bge 0x8
/* 8006F8D4  38 61 00 1C */	addi r3, r1, 0x1c
/* 8006F8D8  83 C3 00 00 */	lwz r30, 0(r3)
/* 8006F8DC  3B FC 22 78 */	addi r31, r28, 0x2278
/* 8006F8E0  3B A0 00 00 */	li r29, 0
/* 8006F8E4  48 00 00 3C */	b 0x3c
/* 8006F8E8  7F E4 FB 78 */	mr r4, r31
/* 8006F8EC  38 61 00 14 */	addi r3, r1, 0x14
/* 8006F8F0  48 00 7B E1 */	bl 0x7be0
/* 8006F8F4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F8F8  7F A5 EB 78 */	mr r5, r29
/* 8006F8FC  90 01 00 0C */	stw r0, 0xc(r1)
/* 8006F900  38 81 00 0C */	addi r4, r1, 0xc
/* 8006F904  80 7C 28 88 */	lwz r3, 0x2888(r28)
/* 8006F908  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F90C  81 8C 00 70 */	lwz r12, 0x70(r12)
/* 8006F910  7D 89 03 A6 */	mtctr r12
/* 8006F914  4E 80 04 21 */	bctrl 
/* 8006F918  3B FF 00 30 */	addi r31, r31, 0x30
/* 8006F91C  3B BD 00 01 */	addi r29, r29, 1
/* 8006F920  7C 1D F0 40 */	cmplw r29, r30
/* 8006F924  41 80 FF C4 */	blt -0x3c
/* 8006F928  80 81 00 18 */	lwz r4, 0x18(r1)
/* 8006F92C  2C 04 00 00 */	cmpwi r4, 0
/* 8006F930  41 82 00 68 */	beq 0x68
/* 8006F934  80 0D 81 44 */	lwz r0, -0x7ebc(r13)
/* 8006F938  38 6D 81 44 */	addi r3, r13, -32444
/* 8006F93C  7C 04 00 40 */	cmplw r4, r0
/* 8006F940  40 80 00 08 */	bge 0x8
/* 8006F944  38 61 00 18 */	addi r3, r1, 0x18
/* 8006F948  83 A3 00 00 */	lwz r29, 0(r3)
/* 8006F94C  3B FC 00 F8 */	addi r31, r28, 0xf8
/* 8006F950  3B C0 00 00 */	li r30, 0
/* 8006F954  48 00 00 3C */	b 0x3c
/* 8006F958  7F E4 FB 78 */	mr r4, r31
/* 8006F95C  38 61 00 10 */	addi r3, r1, 0x10
/* 8006F960  4B FF A7 61 */	bl -0x58a0
/* 8006F964  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8006F968  7F C5 F3 78 */	mr r5, r30
/* 8006F96C  90 01 00 08 */	stw r0, 8(r1)
/* 8006F970  38 81 00 08 */	addi r4, r1, 8
/* 8006F974  80 7C 28 88 */	lwz r3, 0x2888(r28)
/* 8006F978  81 83 00 00 */	lwz r12, 0(r3)
/* 8006F97C  81 8C 00 74 */	lwz r12, 0x74(r12)
/* 8006F980  7D 89 03 A6 */	mtctr r12
/* 8006F984  4E 80 04 21 */	bctrl 
/* 8006F988  3B FF 01 0C */	addi r31, r31, 0x10c
/* 8006F98C  3B DE 00 01 */	addi r30, r30, 1
/* 8006F990  7C 1E E8 40 */	cmplw r30, r29
/* 8006F994  41 80 FF C4 */	blt -0x3c
/* 8006F998  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8006F99C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8006F9A0  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8006F9A4  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8006F9A8  83 81 00 20 */	lwz r28, 0x20(r1)
/* 8006F9AC  7C 08 03 A6 */	mtlr r0
/* 8006F9B0  38 21 00 30 */	addi r1, r1, 0x30
/* 8006F9B4  4E 80 00 20 */	blr 
/* 8006F9B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F9BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006F9C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006F9C4  7C 08 02 A6 */	mflr r0
/* 8006F9C8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006F9CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006F9D0  7C 7F 1B 78 */	mr r31, r3
/* 8006F9D4  4B FF FE 5D */	bl -0x1a4
/* 8006F9D8  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006F9DC  7F E3 FB 78 */	mr r3, r31
/* 8006F9E0  38 80 00 01 */	li r4, 1
/* 8006F9E4  38 A0 00 00 */	li r5, 0
/* 8006F9E8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006F9EC  38 C0 00 00 */	li r6, 0
/* 8006F9F0  7D 89 03 A6 */	mtctr r12
/* 8006F9F4  4E 80 04 21 */	bctrl 
/* 8006F9F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006F9FC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006FA00  7C 08 03 A6 */	mtlr r0
/* 8006FA04  38 21 00 10 */	addi r1, r1, 0x10
/* 8006FA08  4E 80 00 20 */	blr 
/* 8006FA0C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FA10  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FA14  38 80 00 02 */	li r4, 2
/* 8006FA18  38 A0 00 00 */	li r5, 0
/* 8006FA1C  38 C0 00 00 */	li r6, 0
/* 8006FA20  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006FA24  7D 89 03 A6 */	mtctr r12
/* 8006FA28  4E 80 04 20 */	bctr 
/* 8006FA2C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FA30  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FA34  38 80 00 03 */	li r4, 3
/* 8006FA38  38 A0 00 00 */	li r5, 0
/* 8006FA3C  38 C0 00 00 */	li r6, 0
/* 8006FA40  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006FA44  7D 89 03 A6 */	mtctr r12
/* 8006FA48  4E 80 04 20 */	bctr 
/* 8006FA4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FA50  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8006FA54  7C 08 02 A6 */	mflr r0
/* 8006FA58  90 01 00 54 */	stw r0, 0x54(r1)
/* 8006FA5C  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 8006FA60  7C 7F 1B 78 */	mr r31, r3
/* 8006FA64  48 0F E9 09 */	bl 0xfe908
/* 8006FA68  88 1F 00 F4 */	lbz r0, 0xf4(r31)
/* 8006FA6C  38 61 00 08 */	addi r3, r1, 8
/* 8006FA70  1C 00 01 0C */	mulli r0, r0, 0x10c
/* 8006FA74  7C 9F 02 14 */	add r4, r31, r0
/* 8006FA78  38 84 00 F8 */	addi r4, r4, 0xf8
/* 8006FA7C  4B FF A6 45 */	bl -0x59bc
/* 8006FA80  80 03 00 00 */	lwz r0, 0(r3)
/* 8006FA84  38 61 00 0C */	addi r3, r1, 0xc
/* 8006FA88  90 01 00 0C */	stw r0, 0xc(r1)
/* 8006FA8C  38 81 00 10 */	addi r4, r1, 0x10
/* 8006FA90  4B FF AC D1 */	bl -0x5330
/* 8006FA94  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006FA98  7F E3 FB 78 */	mr r3, r31
/* 8006FA9C  38 C1 00 10 */	addi r6, r1, 0x10
/* 8006FAA0  38 80 00 04 */	li r4, 4
/* 8006FAA4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006FAA8  38 A0 00 00 */	li r5, 0
/* 8006FAAC  7D 89 03 A6 */	mtctr r12
/* 8006FAB0  4E 80 04 21 */	bctrl 
/* 8006FAB4  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8006FAB8  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 8006FABC  7C 08 03 A6 */	mtlr r0
/* 8006FAC0  38 21 00 50 */	addi r1, r1, 0x50
/* 8006FAC4  4E 80 00 20 */	blr 
/* 8006FAC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FACC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FAD0  94 21 FE C0 */	stwu r1, -0x140(r1)
/* 8006FAD4  7C 08 02 A6 */	mflr r0
/* 8006FAD8  90 01 01 44 */	stw r0, 0x144(r1)
/* 8006FADC  93 E1 01 3C */	stw r31, 0x13c(r1)
/* 8006FAE0  7C 7F 1B 78 */	mr r31, r3
/* 8006FAE4  80 63 00 E8 */	lwz r3, 0xe8(r3)
/* 8006FAE8  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FAEC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8006FAF0  7D 89 03 A6 */	mtctr r12
/* 8006FAF4  4E 80 04 21 */	bctrl 
/* 8006FAF8  88 1F 00 F4 */	lbz r0, 0xf4(r31)
/* 8006FAFC  38 61 00 08 */	addi r3, r1, 8
/* 8006FB00  1C 00 01 0C */	mulli r0, r0, 0x10c
/* 8006FB04  7C 9F 02 14 */	add r4, r31, r0
/* 8006FB08  38 84 00 F8 */	addi r4, r4, 0xf8
/* 8006FB0C  4B FF A5 B5 */	bl -0x5a4c
/* 8006FB10  80 03 00 00 */	lwz r0, 0(r3)
/* 8006FB14  38 61 00 0C */	addi r3, r1, 0xc
/* 8006FB18  90 01 00 0C */	stw r0, 0xc(r1)
/* 8006FB1C  38 81 00 10 */	addi r4, r1, 0x10
/* 8006FB20  4B FF AC 41 */	bl -0x53c0
/* 8006FB24  80 A1 00 0C */	lwz r5, 0xc(r1)
/* 8006FB28  80 05 00 70 */	lwz r0, 0x70(r5)
/* 8006FB2C  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 8006FB30  41 82 00 24 */	beq 0x24
/* 8006FB34  C0 25 00 AC */	lfs f1, 0xac(r5)
/* 8006FB38  38 61 00 40 */	addi r3, r1, 0x40
/* 8006FB3C  C0 45 00 B0 */	lfs f2, 0xb0(r5)
/* 8006FB40  38 81 00 10 */	addi r4, r1, 0x10
/* 8006FB44  C0 65 00 B4 */	lfs f3, 0xb4(r5)
/* 8006FB48  C0 85 00 B8 */	lfs f4, 0xb8(r5)
/* 8006FB4C  48 01 63 25 */	bl 0x16324
/* 8006FB50  48 00 00 28 */	b 0x28
/* 8006FB54  C0 25 00 BC */	lfs f1, 0xbc(r5)
/* 8006FB58  38 61 00 40 */	addi r3, r1, 0x40
/* 8006FB5C  C0 45 00 C0 */	lfs f2, 0xc0(r5)
/* 8006FB60  38 81 00 10 */	addi r4, r1, 0x10
/* 8006FB64  C0 65 00 C4 */	lfs f3, 0xc4(r5)
/* 8006FB68  C0 85 00 C8 */	lfs f4, 0xc8(r5)
/* 8006FB6C  C0 A5 00 B4 */	lfs f5, 0xb4(r5)
/* 8006FB70  C0 C5 00 B8 */	lfs f6, 0xb8(r5)
/* 8006FB74  48 01 63 BD */	bl 0x163bc
/* 8006FB78  38 01 00 40 */	addi r0, r1, 0x40
/* 8006FB7C  90 0D 95 60 */	stw r0, -0x6aa0(r13)
/* 8006FB80  7F E3 FB 78 */	mr r3, r31
/* 8006FB84  38 80 00 05 */	li r4, 5
/* 8006FB88  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006FB8C  38 A0 00 00 */	li r5, 0
/* 8006FB90  80 DF 00 E8 */	lwz r6, 0xe8(r31)
/* 8006FB94  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006FB98  7D 89 03 A6 */	mtctr r12
/* 8006FB9C  4E 80 04 21 */	bctrl 
/* 8006FBA0  38 00 00 00 */	li r0, 0
/* 8006FBA4  90 0D 95 60 */	stw r0, -0x6aa0(r13)
/* 8006FBA8  83 E1 01 3C */	lwz r31, 0x13c(r1)
/* 8006FBAC  80 01 01 44 */	lwz r0, 0x144(r1)
/* 8006FBB0  7C 08 03 A6 */	mtlr r0
/* 8006FBB4  38 21 01 40 */	addi r1, r1, 0x140
/* 8006FBB8  4E 80 00 20 */	blr 
/* 8006FBBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FBC0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006FBC4  7C 08 02 A6 */	mflr r0
/* 8006FBC8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006FBCC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006FBD0  7C 7F 1B 78 */	mr r31, r3
/* 8006FBD4  80 63 00 E8 */	lwz r3, 0xe8(r3)
/* 8006FBD8  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FBDC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8006FBE0  7D 89 03 A6 */	mtctr r12
/* 8006FBE4  4E 80 04 21 */	bctrl 
/* 8006FBE8  81 9F 00 00 */	lwz r12, 0(r31)
/* 8006FBEC  3C 80 00 01 */	lis r4, 1
/* 8006FBF0  7F E3 FB 78 */	mr r3, r31
/* 8006FBF4  80 DF 00 E8 */	lwz r6, 0xe8(r31)
/* 8006FBF8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006FBFC  38 84 00 04 */	addi r4, r4, 4
/* 8006FC00  38 A0 00 00 */	li r5, 0
/* 8006FC04  7D 89 03 A6 */	mtctr r12
/* 8006FC08  4E 80 04 21 */	bctrl 
/* 8006FC0C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006FC10  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006FC14  7C 08 03 A6 */	mtlr r0
/* 8006FC18  38 21 00 10 */	addi r1, r1, 0x10
/* 8006FC1C  4E 80 00 20 */	blr 
/* 8006FC20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006FC24  7C 08 02 A6 */	mflr r0
/* 8006FC28  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006FC2C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006FC30  7C 7F 1B 78 */	mr r31, r3
/* 8006FC34  4B FF F9 CD */	bl -0x634
/* 8006FC38  80 1F 00 F0 */	lwz r0, 0xf0(r31)
/* 8006FC3C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006FC40  41 82 00 20 */	beq 0x20
/* 8006FC44  80 7F 00 E8 */	lwz r3, 0xe8(r31)
/* 8006FC48  38 9F 00 EC */	addi r4, r31, 0xec
/* 8006FC4C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FC50  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8006FC54  7D 89 03 A6 */	mtctr r12
/* 8006FC58  4E 80 04 21 */	bctrl 
/* 8006FC5C  48 00 00 1C */	b 0x1c
/* 8006FC60  80 7F 00 E8 */	lwz r3, 0xe8(r31)
/* 8006FC64  38 80 00 00 */	li r4, 0
/* 8006FC68  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FC6C  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8006FC70  7D 89 03 A6 */	mtctr r12
/* 8006FC74  4E 80 04 21 */	bctrl 
/* 8006FC78  38 60 00 04 */	li r3, 4
/* 8006FC7C  4B FF 47 D5 */	bl -0xb82c
/* 8006FC80  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006FC84  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006FC88  7C 08 03 A6 */	mtlr r0
/* 8006FC8C  38 21 00 10 */	addi r1, r1, 0x10
/* 8006FC90  4E 80 00 20 */	blr 
/* 8006FC94  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FC98  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FC9C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FCA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006FCA4  7C 08 02 A6 */	mflr r0
/* 8006FCA8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006FCAC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006FCB0  7C 7F 1B 78 */	mr r31, r3
/* 8006FCB4  4B FF F9 4D */	bl -0x6b4
/* 8006FCB8  80 1F 00 F0 */	lwz r0, 0xf0(r31)
/* 8006FCBC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8006FCC0  41 82 00 20 */	beq 0x20
/* 8006FCC4  80 7F 00 E8 */	lwz r3, 0xe8(r31)
/* 8006FCC8  38 9F 00 EC */	addi r4, r31, 0xec
/* 8006FCCC  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FCD0  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8006FCD4  7D 89 03 A6 */	mtctr r12
/* 8006FCD8  4E 80 04 21 */	bctrl 
/* 8006FCDC  48 00 00 1C */	b 0x1c
/* 8006FCE0  80 7F 00 E8 */	lwz r3, 0xe8(r31)
/* 8006FCE4  38 80 00 00 */	li r4, 0
/* 8006FCE8  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FCEC  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8006FCF0  7D 89 03 A6 */	mtctr r12
/* 8006FCF4  4E 80 04 21 */	bctrl 
/* 8006FCF8  38 60 00 04 */	li r3, 4
/* 8006FCFC  4B FF 47 55 */	bl -0xb8ac
/* 8006FD00  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006FD04  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006FD08  7C 08 03 A6 */	mtlr r0
/* 8006FD0C  38 21 00 10 */	addi r1, r1, 0x10
/* 8006FD10  4E 80 00 20 */	blr 
/* 8006FD14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FD18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FD1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FD20  2C 04 00 00 */	cmpwi r4, 0
/* 8006FD24  41 82 00 18 */	beq 0x18
/* 8006FD28  80 03 00 F0 */	lwz r0, 0xf0(r3)
/* 8006FD2C  90 A3 00 EC */	stw r5, 0xec(r3)
/* 8006FD30  60 00 00 01 */	ori r0, r0, 1
/* 8006FD34  90 03 00 F0 */	stw r0, 0xf0(r3)
/* 8006FD38  4E 80 00 20 */	blr 
/* 8006FD3C  80 03 00 F0 */	lwz r0, 0xf0(r3)
/* 8006FD40  54 00 00 3C */	rlwinm r0, r0, 0, 0, 0x1e
/* 8006FD44  90 03 00 F0 */	stw r0, 0xf0(r3)
/* 8006FD48  4E 80 00 20 */	blr 
/* 8006FD4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FD50  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8006FD54  7C 08 02 A6 */	mflr r0
/* 8006FD58  90 01 00 34 */	stw r0, 0x34(r1)
/* 8006FD5C  39 61 00 30 */	addi r11, r1, 0x30
/* 8006FD60  4B FB 18 35 */	bl -0x4e7cc
/* 8006FD64  83 A1 00 38 */	lwz r29, 0x38(r1)
/* 8006FD68  7C B9 2B 78 */	mr r25, r5
/* 8006FD6C  7C C5 33 78 */	mr r5, r6
/* 8006FD70  83 C1 00 3C */	lwz r30, 0x3c(r1)
/* 8006FD74  7C 78 1B 78 */	mr r24, r3
/* 8006FD78  7C E6 3B 78 */	mr r6, r7
/* 8006FD7C  7D 1A 43 78 */	mr r26, r8
/* 8006FD80  7D 3B 4B 78 */	mr r27, r9
/* 8006FD84  7D 5C 53 78 */	mr r28, r10
/* 8006FD88  4B FF F0 B9 */	bl -0xf48
/* 8006FD8C  3C 60 80 27 */	lis r3, 0x8027
/* 8006FD90  3B E0 00 00 */	li r31, 0
/* 8006FD94  38 63 31 B0 */	addi r3, r3, 0x31b0
/* 8006FD98  38 00 00 02 */	li r0, 2
/* 8006FD9C  90 78 00 00 */	stw r3, 0(r24)
/* 8006FDA0  7F 84 E3 78 */	mr r4, r28
/* 8006FDA4  7F A5 EB 78 */	mr r5, r29
/* 8006FDA8  7F 46 D3 78 */	mr r6, r26
/* 8006FDAC  93 38 00 E8 */	stw r25, 0xe8(r24)
/* 8006FDB0  7F C7 F3 78 */	mr r7, r30
/* 8006FDB4  7F 68 DB 78 */	mr r8, r27
/* 8006FDB8  38 78 28 78 */	addi r3, r24, 0x2878
/* 8006FDBC  90 18 00 EC */	stw r0, 0xec(r24)
/* 8006FDC0  93 F8 00 F0 */	stw r31, 0xf0(r24)
/* 8006FDC4  9B F8 00 F4 */	stb r31, 0xf4(r24)
/* 8006FDC8  48 00 7B 69 */	bl 0x7b68
/* 8006FDCC  93 F8 28 88 */	stw r31, 0x2888(r24)
/* 8006FDD0  3B C0 00 00 */	li r30, 0
/* 8006FDD4  3B E0 00 00 */	li r31, 0
/* 8006FDD8  7C 98 FA 14 */	add r4, r24, r31
/* 8006FDDC  38 61 00 0C */	addi r3, r1, 0xc
/* 8006FDE0  38 84 00 F8 */	addi r4, r4, 0xf8
/* 8006FDE4  4B FF A2 DD */	bl -0x5d24
/* 8006FDE8  38 61 00 0C */	addi r3, r1, 0xc
/* 8006FDEC  4B FF A2 E5 */	bl -0x5d1c
/* 8006FDF0  3B DE 00 01 */	addi r30, r30, 1
/* 8006FDF4  3B FF 01 0C */	addi r31, r31, 0x10c
/* 8006FDF8  28 1E 00 20 */	cmplwi r30, 0x20
/* 8006FDFC  41 80 FF DC */	blt -0x24
/* 8006FE00  3B C0 00 00 */	li r30, 0
/* 8006FE04  3B E0 00 00 */	li r31, 0
/* 8006FE08  7C 98 FA 14 */	add r4, r24, r31
/* 8006FE0C  38 61 00 08 */	addi r3, r1, 8
/* 8006FE10  38 84 22 78 */	addi r4, r4, 0x2278
/* 8006FE14  48 00 76 BD */	bl 0x76bc
/* 8006FE18  38 61 00 08 */	addi r3, r1, 8
/* 8006FE1C  48 00 76 C5 */	bl 0x76c4
/* 8006FE20  3B DE 00 01 */	addi r30, r30, 1
/* 8006FE24  3B FF 00 30 */	addi r31, r31, 0x30
/* 8006FE28  28 1E 00 20 */	cmplwi r30, 0x20
/* 8006FE2C  41 80 FF DC */	blt -0x24
/* 8006FE30  39 61 00 30 */	addi r11, r1, 0x30
/* 8006FE34  7F 03 C3 78 */	mr r3, r24
/* 8006FE38  4B FB 17 A9 */	bl -0x4e858
/* 8006FE3C  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8006FE40  7C 08 03 A6 */	mtlr r0
/* 8006FE44  38 21 00 30 */	addi r1, r1, 0x30
/* 8006FE48  4E 80 00 20 */	blr 
/* 8006FE4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FE50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006FE54  7C 08 02 A6 */	mflr r0
/* 8006FE58  2C 03 00 00 */	cmpwi r3, 0
/* 8006FE5C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8006FE60  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8006FE64  7C 7F 1B 78 */	mr r31, r3
/* 8006FE68  41 82 00 4C */	beq 0x4c
/* 8006FE6C  80 03 28 88 */	lwz r0, 0x2888(r3)
/* 8006FE70  3C 80 80 27 */	lis r4, 0x8027
/* 8006FE74  38 84 31 B0 */	addi r4, r4, 0x31b0
/* 8006FE78  90 83 00 00 */	stw r4, 0(r3)
/* 8006FE7C  2C 00 00 00 */	cmpwi r0, 0
/* 8006FE80  41 82 00 28 */	beq 0x28
/* 8006FE84  7C 03 03 78 */	mr r3, r0
/* 8006FE88  3C 80 00 01 */	lis r4, 1
/* 8006FE8C  81 83 00 00 */	lwz r12, 0(r3)
/* 8006FE90  7F E6 FB 78 */	mr r6, r31
/* 8006FE94  38 84 00 03 */	addi r4, r4, 3
/* 8006FE98  38 A0 00 00 */	li r5, 0
/* 8006FE9C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8006FEA0  7D 89 03 A6 */	mtctr r12
/* 8006FEA4  4E 80 04 21 */	bctrl 
/* 8006FEA8  7F E3 FB 78 */	mr r3, r31
/* 8006FEAC  38 80 00 00 */	li r4, 0
/* 8006FEB0  4B FF F0 01 */	bl -0x1000
/* 8006FEB4  7F E3 FB 78 */	mr r3, r31
/* 8006FEB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8006FEBC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8006FEC0  7C 08 03 A6 */	mtlr r0
/* 8006FEC4  38 21 00 10 */	addi r1, r1, 0x10
/* 8006FEC8  4E 80 00 20 */	blr 
/* 8006FECC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8006FED0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8006FED4  7C 08 02 A6 */	mflr r0
/* 8006FED8  90 01 00 44 */	stw r0, 0x44(r1)
/* 8006FEDC  39 61 00 40 */	addi r11, r1, 0x40
/* 8006FEE0  4B FB 16 C1 */	bl -0x4e940
/* 8006FEE4  80 0D 95 60 */	lwz r0, -0x6aa0(r13)
/* 8006FEE8  7C 7B 1B 78 */	mr r27, r3
/* 8006FEEC  7C 9C 23 78 */	mr r28, r4
/* 8006FEF0  7C BD 2B 78 */	mr r29, r5
/* 8006FEF4  2C 00 00 00 */	cmpwi r0, 0
/* 8006FEF8  7C DE 33 78 */	mr r30, r6
/* 8006FEFC  3B E0 00 00 */	li r31, 0
/* 8006FF00  41 82 00 64 */	beq 0x64
/* 8006FF04  81 9C 00 00 */	lwz r12, 0(r28)
/* 8006FF08  7F 83 E3 78 */	mr r3, r28
/* 8006FF0C  38 A1 00 08 */	addi r5, r1, 8
/* 8006FF10  38 80 00 09 */	li r4, 9
/* 8006FF14  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8006FF18  7D 89 03 A6 */	mtctr r12
/* 8006FF1C  4E 80 04 21 */	bctrl 
/* 8006FF20  80 01 00 08 */	lwz r0, 8(r1)
/* 8006FF24  2C 00 00 00 */	cmpwi r0, 0
/* 8006FF28  41 82 00 3C */	beq 0x3c
/* 8006FF2C  7F 83 E3 78 */	mr r3, r28
/* 8006FF30  38 A1 00 10 */	addi r5, r1, 0x10
/* 8006FF34  38 80 00 01 */	li r4, 1
/* 8006FF38  4B FF DF 09 */	bl -0x20f8
/* 8006FF3C  80 6D 95 60 */	lwz r3, -0x6aa0(r13)
/* 8006FF40  38 81 00 10 */	addi r4, r1, 0x10
/* 8006FF44  48 01 66 CD */	bl 0x166cc
/* 8006FF48  2C 03 00 00 */	cmpwi r3, 0
/* 8006FF4C  40 82 00 0C */	bne 0xc
/* 8006FF50  38 60 00 02 */	li r3, 2
/* 8006FF54  48 00 00 84 */	b 0x84
/* 8006FF58  2C 03 00 01 */	cmpwi r3, 1
/* 8006FF5C  40 82 00 08 */	bne 0x8
/* 8006FF60  3B E0 00 01 */	li r31, 1
/* 8006FF64  2C 1D 00 00 */	cmpwi r29, 0
/* 8006FF68  41 82 00 34 */	beq 0x34
/* 8006FF6C  80 7B 00 10 */	lwz r3, 0x10(r27)
/* 8006FF70  80 1B 00 0C */	lwz r0, 0xc(r27)
/* 8006FF74  7C 03 00 40 */	cmplw r3, r0
/* 8006FF78  40 80 00 1C */	bge 0x1c
/* 8006FF7C  80 9B 00 04 */	lwz r4, 4(r27)
/* 8006FF80  54 60 10 3A */	slwi r0, r3, 2
/* 8006FF84  38 63 00 01 */	addi r3, r3, 1
/* 8006FF88  7F 84 01 2E */	stwx r28, r4, r0
/* 8006FF8C  90 7B 00 10 */	stw r3, 0x10(r27)
/* 8006FF90  48 00 00 0C */	b 0xc
/* 8006FF94  7F E3 FB 78 */	mr r3, r31
/* 8006FF98  48 00 00 40 */	b 0x40
/* 8006FF9C  2C 1E 00 00 */	cmpwi r30, 0
/* 8006FFA0  41 82 00 34 */	beq 0x34
/* 8006FFA4  80 7B 00 14 */	lwz r3, 0x14(r27)
/* 8006FFA8  80 1B 00 0C */	lwz r0, 0xc(r27)
/* 8006FFAC  7C 03 00 40 */	cmplw r3, r0
/* 8006FFB0  40 80 00 1C */	bge 0x1c
/* 8006FFB4  80 9B 00 08 */	lwz r4, 8(r27)
/* 8006FFB8  54 60 10 3A */	slwi r0, r3, 2
/* 8006FFBC  38 63 00 01 */	addi r3, r3, 1
/* 8006FFC0  7F 84 01 2E */	stwx r28, r4, r0
/* 8006FFC4  90 7B 00 14 */	stw r3, 0x14(r27)
/* 8006FFC8  48 00 00 0C */	b 0xc
/* 8006FFCC  7F E3 FB 78 */	mr r3, r31
/* 8006FFD0  48 00 00 08 */	b 0x8
/* 8006FFD4  7F E3 FB 78 */	mr r3, r31
/* 8006FFD8  39 61 00 40 */	addi r11, r1, 0x40
/* 8006FFDC  4B FB 16 11 */	bl -0x4e9f0
/* 8006FFE0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8006FFE4  7C 08 03 A6 */	mtlr r0
/* 8006FFE8  38 21 00 40 */	addi r1, r1, 0x40
/* 8006FFEC  4E 80 00 20 */	blr 
/* 8006FFF0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8006FFF4  7C 08 02 A6 */	mflr r0
/* 8006FFF8  3C A0 80 07 */	lis r5, 0x8007
/* 8006FFFC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80070000  38 A5 00 50 */	addi r5, r5, 0x50
/* 80070004  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80070008  7C 7F 1B 78 */	mr r31, r3
/* 8007000C  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 80070010  80 63 00 04 */	lwz r3, 4(r3)
/* 80070014  54 00 10 3A */	slwi r0, r0, 2
/* 80070018  7C 83 02 14 */	add r4, r3, r0
/* 8007001C  48 00 00 B5 */	bl 0xb4
/* 80070020  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80070024  3C A0 80 07 */	lis r5, 0x8007
/* 80070028  80 7F 00 08 */	lwz r3, 8(r31)
/* 8007002C  38 A5 00 90 */	addi r5, r5, 0x90
/* 80070030  54 00 10 3A */	slwi r0, r0, 2
/* 80070034  7C 83 02 14 */	add r4, r3, r0
/* 80070038  48 00 00 99 */	bl 0x98
/* 8007003C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80070040  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80070044  7C 08 03 A6 */	mtlr r0
/* 80070048  38 21 00 10 */	addi r1, r1, 0x10
/* 8007004C  4E 80 00 20 */	blr 
/* 80070050  88 03 00 D0 */	lbz r0, 0xd0(r3)
/* 80070054  88 A4 00 D0 */	lbz r5, 0xd0(r4)
/* 80070058  7C 00 28 00 */	cmpw r0, r5
/* 8007005C  40 82 00 1C */	bne 0x1c
/* 80070060  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 80070064  C0 04 00 98 */	lfs f0, 0x98(r4)
/* 80070068  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8007006C  7C 60 00 26 */	mfcr r3
/* 80070070  54 63 17 FE */	rlwinm r3, r3, 2, 0x1f, 0x1f
/* 80070074  4E 80 00 20 */	blr 
/* 80070078  7C A0 02 78 */	xor r0, r5, r0
/* 8007007C  7C 03 0E 70 */	srawi r3, r0, 1
/* 80070080  7C 00 28 38 */	and r0, r0, r5
/* 80070084  7C 00 18 50 */	subf r0, r0, r3
/* 80070088  54 03 0F FE */	srwi r3, r0, 0x1f
/* 8007008C  4E 80 00 20 */	blr 
/* 80070090  88 03 00 D1 */	lbz r0, 0xd1(r3)
/* 80070094  88 A4 00 D1 */	lbz r5, 0xd1(r4)
/* 80070098  7C 00 28 00 */	cmpw r0, r5
/* 8007009C  40 82 00 1C */	bne 0x1c
/* 800700A0  C0 23 00 98 */	lfs f1, 0x98(r3)
/* 800700A4  C0 04 00 98 */	lfs f0, 0x98(r4)
/* 800700A8  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 800700AC  7C 60 00 26 */	mfcr r3
/* 800700B0  54 63 0F FE */	srwi r3, r3, 0x1f
/* 800700B4  4E 80 00 20 */	blr 
/* 800700B8  7C A0 02 78 */	xor r0, r5, r0
/* 800700BC  7C 03 0E 70 */	srawi r3, r0, 1
/* 800700C0  7C 00 28 38 */	and r0, r0, r5
/* 800700C4  7C 00 18 50 */	subf r0, r0, r3
/* 800700C8  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800700CC  4E 80 00 20 */	blr 
/* 800700D0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800700D4  7C 08 02 A6 */	mflr r0
/* 800700D8  90 01 00 34 */	stw r0, 0x34(r1)
/* 800700DC  39 61 00 30 */	addi r11, r1, 0x30
/* 800700E0  4B FB 14 BD */	bl -0x4eb44
/* 800700E4  3C C0 66 66 */	lis r6, 0x6666
/* 800700E8  90 A1 00 08 */	stw r5, 8(r1)
/* 800700EC  7C 7C 1B 78 */	mr r28, r3
/* 800700F0  7C 9D 23 78 */	mr r29, r4
/* 800700F4  3B E6 66 67 */	addi r31, r6, 0x6667
/* 800700F8  7C 1C E8 50 */	subf r0, r28, r29
/* 800700FC  7C 00 16 70 */	srawi r0, r0, 2
/* 80070100  7C E0 01 94 */	addze r7, r0
/* 80070104  2C 07 00 01 */	cmpwi r7, 1
/* 80070108  40 81 03 30 */	ble 0x330
/* 8007010C  2C 07 00 14 */	cmpwi r7, 0x14
/* 80070110  41 81 00 7C */	bgt 0x7c
/* 80070114  7C 1C E8 40 */	cmplw r28, r29
/* 80070118  41 82 03 20 */	beq 0x320
/* 8007011C  3B DD FF FC */	addi r30, r29, -4
/* 80070120  48 00 00 60 */	b 0x60
/* 80070124  7C 1C E8 40 */	cmplw r28, r29
/* 80070128  7F 9F E3 78 */	mr r31, r28
/* 8007012C  41 82 00 38 */	beq 0x38
/* 80070130  3B 7C 00 04 */	addi r27, r28, 4
/* 80070134  48 00 00 28 */	b 0x28
/* 80070138  81 81 00 08 */	lwz r12, 8(r1)
/* 8007013C  80 7B 00 00 */	lwz r3, 0(r27)
/* 80070140  80 9F 00 00 */	lwz r4, 0(r31)
/* 80070144  7D 89 03 A6 */	mtctr r12
/* 80070148  4E 80 04 21 */	bctrl 
/* 8007014C  2C 03 00 00 */	cmpwi r3, 0
/* 80070150  41 82 00 08 */	beq 0x8
/* 80070154  7F 7F DB 78 */	mr r31, r27
/* 80070158  3B 7B 00 04 */	addi r27, r27, 4
/* 8007015C  7C 1B E8 40 */	cmplw r27, r29
/* 80070160  40 82 FF D8 */	bne -0x28
/* 80070164  7C 1F E0 40 */	cmplw r31, r28
/* 80070168  41 82 00 14 */	beq 0x14
/* 8007016C  80 7F 00 00 */	lwz r3, 0(r31)
/* 80070170  80 1C 00 00 */	lwz r0, 0(r28)
/* 80070174  90 1F 00 00 */	stw r0, 0(r31)
/* 80070178  90 7C 00 00 */	stw r3, 0(r28)
/* 8007017C  3B 9C 00 04 */	addi r28, r28, 4
/* 80070180  7C 1C F0 40 */	cmplw r28, r30
/* 80070184  40 82 FF A0 */	bne -0x60
/* 80070188  48 00 02 B0 */	b 0x2b0
/* 8007018C  80 8D 81 48 */	lwz r4, -0x7eb8(r13)
/* 80070190  7C E0 16 70 */	srawi r0, r7, 2
/* 80070194  7C A0 01 94 */	addze r5, r0
/* 80070198  7C 1F 20 96 */	mulhw r0, r31, r4
/* 8007019C  38 C4 00 01 */	addi r6, r4, 1
/* 800701A0  2C 06 00 05 */	cmpwi r6, 5
/* 800701A4  7C 00 0E 70 */	srawi r0, r0, 1
/* 800701A8  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800701AC  7C 00 1A 14 */	add r0, r0, r3
/* 800701B0  1C 00 00 05 */	mulli r0, r0, 5
/* 800701B4  7C 00 20 50 */	subf r0, r0, r4
/* 800701B8  7C 05 02 14 */	add r0, r5, r0
/* 800701BC  54 00 10 3A */	slwi r0, r0, 2
/* 800701C0  7C 7C 02 14 */	add r3, r28, r0
/* 800701C4  41 80 00 08 */	blt 0x8
/* 800701C8  38 C0 FF FC */	li r6, -4
/* 800701CC  7C 9F 30 96 */	mulhw r4, r31, r6
/* 800701D0  38 06 00 01 */	addi r0, r6, 1
/* 800701D4  54 E5 10 3A */	slwi r5, r7, 2
/* 800701D8  90 0D 81 48 */	stw r0, -0x7eb8(r13)
/* 800701DC  2C 00 00 05 */	cmpwi r0, 5
/* 800701E0  7C 07 28 50 */	subf r0, r7, r5
/* 800701E4  7C 00 16 70 */	srawi r0, r0, 2
/* 800701E8  7C A0 01 94 */	addze r5, r0
/* 800701EC  7C 80 0E 70 */	srawi r0, r4, 1
/* 800701F0  54 04 0F FE */	srwi r4, r0, 0x1f
/* 800701F4  7C 00 22 14 */	add r0, r0, r4
/* 800701F8  1C 00 00 05 */	mulli r0, r0, 5
/* 800701FC  7C 00 30 50 */	subf r0, r0, r6
/* 80070200  7C 05 02 14 */	add r0, r5, r0
/* 80070204  54 00 10 3A */	slwi r0, r0, 2
/* 80070208  7C 9C 02 14 */	add r4, r28, r0
/* 8007020C  41 80 00 0C */	blt 0xc
/* 80070210  38 C0 FF FC */	li r6, -4
/* 80070214  90 CD 81 48 */	stw r6, -0x7eb8(r13)
/* 80070218  3B 5D FF FC */	addi r26, r29, -4
/* 8007021C  38 C1 00 08 */	addi r6, r1, 8
/* 80070220  7F 45 D3 78 */	mr r5, r26
/* 80070224  48 00 05 AD */	bl 0x5ac
/* 80070228  7F 9E E3 78 */	mr r30, r28
/* 8007022C  7F 5B D3 78 */	mr r27, r26
/* 80070230  48 00 00 08 */	b 0x8
/* 80070234  3B DE 00 04 */	addi r30, r30, 4
/* 80070238  81 81 00 08 */	lwz r12, 8(r1)
/* 8007023C  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070240  80 9A 00 00 */	lwz r4, 0(r26)
/* 80070244  7D 89 03 A6 */	mtctr r12
/* 80070248  4E 80 04 21 */	bctrl 
/* 8007024C  2C 03 00 00 */	cmpwi r3, 0
/* 80070250  40 82 FF E4 */	bne -0x1c
/* 80070254  3B 7B FF FC */	addi r27, r27, -4
/* 80070258  7C 1E D8 40 */	cmplw r30, r27
/* 8007025C  41 82 00 20 */	beq 0x20
/* 80070260  81 81 00 08 */	lwz r12, 8(r1)
/* 80070264  80 7B 00 00 */	lwz r3, 0(r27)
/* 80070268  80 9A 00 00 */	lwz r4, 0(r26)
/* 8007026C  7D 89 03 A6 */	mtctr r12
/* 80070270  4E 80 04 21 */	bctrl 
/* 80070274  2C 03 00 00 */	cmpwi r3, 0
/* 80070278  41 82 FF DC */	beq -0x24
/* 8007027C  7C 1E D8 40 */	cmplw r30, r27
/* 80070280  40 80 00 78 */	bge 0x78
/* 80070284  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070288  80 1B 00 00 */	lwz r0, 0(r27)
/* 8007028C  90 1E 00 00 */	stw r0, 0(r30)
/* 80070290  3B DE 00 04 */	addi r30, r30, 4
/* 80070294  90 7B 00 00 */	stw r3, 0(r27)
/* 80070298  48 00 00 08 */	b 0x8
/* 8007029C  3B DE 00 04 */	addi r30, r30, 4
/* 800702A0  81 81 00 08 */	lwz r12, 8(r1)
/* 800702A4  80 7E 00 00 */	lwz r3, 0(r30)
/* 800702A8  80 9A 00 00 */	lwz r4, 0(r26)
/* 800702AC  7D 89 03 A6 */	mtctr r12
/* 800702B0  4E 80 04 21 */	bctrl 
/* 800702B4  2C 03 00 00 */	cmpwi r3, 0
/* 800702B8  40 82 FF E4 */	bne -0x1c
/* 800702BC  81 81 00 08 */	lwz r12, 8(r1)
/* 800702C0  84 7B FF FC */	lwzu r3, -4(r27)
/* 800702C4  80 9A 00 00 */	lwz r4, 0(r26)
/* 800702C8  7D 89 03 A6 */	mtctr r12
/* 800702CC  4E 80 04 21 */	bctrl 
/* 800702D0  2C 03 00 00 */	cmpwi r3, 0
/* 800702D4  41 82 FF E8 */	beq -0x18
/* 800702D8  7C 1E D8 40 */	cmplw r30, r27
/* 800702DC  40 80 00 1C */	bge 0x1c
/* 800702E0  80 7E 00 00 */	lwz r3, 0(r30)
/* 800702E4  80 1B 00 00 */	lwz r0, 0(r27)
/* 800702E8  90 1E 00 00 */	stw r0, 0(r30)
/* 800702EC  3B DE 00 04 */	addi r30, r30, 4
/* 800702F0  90 7B 00 00 */	stw r3, 0(r27)
/* 800702F4  4B FF FF AC */	b -0x54
/* 800702F8  7C 1E E0 40 */	cmplw r30, r28
/* 800702FC  40 82 00 EC */	bne 0xec
/* 80070300  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070304  80 1A 00 00 */	lwz r0, 0(r26)
/* 80070308  90 1E 00 00 */	stw r0, 0(r30)
/* 8007030C  90 7A 00 00 */	stw r3, 0(r26)
/* 80070310  81 81 00 08 */	lwz r12, 8(r1)
/* 80070314  80 7C 00 00 */	lwz r3, 0(r28)
/* 80070318  80 9D FF FC */	lwz r4, -4(r29)
/* 8007031C  7D 89 03 A6 */	mtctr r12
/* 80070320  3B DE 00 04 */	addi r30, r30, 4
/* 80070324  3B 7D FF FC */	addi r27, r29, -4
/* 80070328  4E 80 04 21 */	bctrl 
/* 8007032C  2C 03 00 00 */	cmpwi r3, 0
/* 80070330  40 82 00 48 */	bne 0x48
/* 80070334  48 00 00 08 */	b 0x8
/* 80070338  3B DE 00 04 */	addi r30, r30, 4
/* 8007033C  7C 1E E8 40 */	cmplw r30, r29
/* 80070340  41 82 00 20 */	beq 0x20
/* 80070344  81 81 00 08 */	lwz r12, 8(r1)
/* 80070348  80 7C 00 00 */	lwz r3, 0(r28)
/* 8007034C  80 9E 00 00 */	lwz r4, 0(r30)
/* 80070350  7D 89 03 A6 */	mtctr r12
/* 80070354  4E 80 04 21 */	bctrl 
/* 80070358  2C 03 00 00 */	cmpwi r3, 0
/* 8007035C  41 82 FF DC */	beq -0x24
/* 80070360  7C 1E D8 40 */	cmplw r30, r27
/* 80070364  40 80 00 14 */	bge 0x14
/* 80070368  80 7E 00 00 */	lwz r3, 0(r30)
/* 8007036C  80 1B 00 00 */	lwz r0, 0(r27)
/* 80070370  90 1E 00 00 */	stw r0, 0(r30)
/* 80070374  90 7B 00 00 */	stw r3, 0(r27)
/* 80070378  7C 1E D8 40 */	cmplw r30, r27
/* 8007037C  40 80 00 64 */	bge 0x64
/* 80070380  48 00 00 08 */	b 0x8
/* 80070384  3B DE 00 04 */	addi r30, r30, 4
/* 80070388  81 81 00 08 */	lwz r12, 8(r1)
/* 8007038C  80 7C 00 00 */	lwz r3, 0(r28)
/* 80070390  80 9E 00 00 */	lwz r4, 0(r30)
/* 80070394  7D 89 03 A6 */	mtctr r12
/* 80070398  4E 80 04 21 */	bctrl 
/* 8007039C  2C 03 00 00 */	cmpwi r3, 0
/* 800703A0  41 82 FF E4 */	beq -0x1c
/* 800703A4  81 81 00 08 */	lwz r12, 8(r1)
/* 800703A8  80 7C 00 00 */	lwz r3, 0(r28)
/* 800703AC  84 9B FF FC */	lwzu r4, -4(r27)
/* 800703B0  7D 89 03 A6 */	mtctr r12
/* 800703B4  4E 80 04 21 */	bctrl 
/* 800703B8  2C 03 00 00 */	cmpwi r3, 0
/* 800703BC  40 82 FF E8 */	bne -0x18
/* 800703C0  7C 1E D8 40 */	cmplw r30, r27
/* 800703C4  40 80 00 1C */	bge 0x1c
/* 800703C8  80 7E 00 00 */	lwz r3, 0(r30)
/* 800703CC  80 1B 00 00 */	lwz r0, 0(r27)
/* 800703D0  90 1E 00 00 */	stw r0, 0(r30)
/* 800703D4  3B DE 00 04 */	addi r30, r30, 4
/* 800703D8  90 7B 00 00 */	stw r3, 0(r27)
/* 800703DC  4B FF FF AC */	b -0x54
/* 800703E0  7F DC F3 78 */	mr r28, r30
/* 800703E4  4B FF FD 14 */	b -0x2ec
/* 800703E8  7C 7C F0 50 */	subf r3, r28, r30
/* 800703EC  7C 1E E8 50 */	subf r0, r30, r29
/* 800703F0  7C 63 16 70 */	srawi r3, r3, 2
/* 800703F4  7C 63 01 94 */	addze r3, r3
/* 800703F8  7C 00 16 70 */	srawi r0, r0, 2
/* 800703FC  7C 00 01 94 */	addze r0, r0
/* 80070400  7C 03 00 00 */	cmpw r3, r0
/* 80070404  40 80 00 1C */	bge 0x1c
/* 80070408  7F 83 E3 78 */	mr r3, r28
/* 8007040C  7F C4 F3 78 */	mr r4, r30
/* 80070410  38 A1 00 08 */	addi r5, r1, 8
/* 80070414  48 00 00 3D */	bl 0x3c
/* 80070418  7F DC F3 78 */	mr r28, r30
/* 8007041C  4B FF FC DC */	b -0x324
/* 80070420  7F C3 F3 78 */	mr r3, r30
/* 80070424  7F A4 EB 78 */	mr r4, r29
/* 80070428  38 A1 00 08 */	addi r5, r1, 8
/* 8007042C  48 00 00 25 */	bl 0x24
/* 80070430  7F DD F3 78 */	mr r29, r30
/* 80070434  4B FF FC C4 */	b -0x33c
/* 80070438  39 61 00 30 */	addi r11, r1, 0x30
/* 8007043C  4B FB 11 AD */	bl -0x4ee54
/* 80070440  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80070444  7C 08 03 A6 */	mtlr r0
/* 80070448  38 21 00 30 */	addi r1, r1, 0x30
/* 8007044C  4E 80 00 20 */	blr 
/* 80070450  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80070454  7C 08 02 A6 */	mflr r0
/* 80070458  90 01 00 34 */	stw r0, 0x34(r1)
/* 8007045C  39 61 00 30 */	addi r11, r1, 0x30
/* 80070460  4B FB 11 39 */	bl -0x4eec8
/* 80070464  3C C0 66 66 */	lis r6, 0x6666
/* 80070468  7C 7B 1B 78 */	mr r27, r3
/* 8007046C  7C 9C 23 78 */	mr r28, r4
/* 80070470  7C BD 2B 78 */	mr r29, r5
/* 80070474  3B E6 66 67 */	addi r31, r6, 0x6667
/* 80070478  7C 1B E0 50 */	subf r0, r27, r28
/* 8007047C  7C 00 16 70 */	srawi r0, r0, 2
/* 80070480  7C E0 01 94 */	addze r7, r0
/* 80070484  2C 07 00 01 */	cmpwi r7, 1
/* 80070488  40 81 03 30 */	ble 0x330
/* 8007048C  2C 07 00 14 */	cmpwi r7, 0x14
/* 80070490  41 81 00 7C */	bgt 0x7c
/* 80070494  7C 1B E0 40 */	cmplw r27, r28
/* 80070498  41 82 03 20 */	beq 0x320
/* 8007049C  3B DC FF FC */	addi r30, r28, -4
/* 800704A0  48 00 00 60 */	b 0x60
/* 800704A4  7C 1B E0 40 */	cmplw r27, r28
/* 800704A8  7F 7F DB 78 */	mr r31, r27
/* 800704AC  41 82 00 38 */	beq 0x38
/* 800704B0  3B 5B 00 04 */	addi r26, r27, 4
/* 800704B4  48 00 00 28 */	b 0x28
/* 800704B8  81 9D 00 00 */	lwz r12, 0(r29)
/* 800704BC  80 7A 00 00 */	lwz r3, 0(r26)
/* 800704C0  80 9F 00 00 */	lwz r4, 0(r31)
/* 800704C4  7D 89 03 A6 */	mtctr r12
/* 800704C8  4E 80 04 21 */	bctrl 
/* 800704CC  2C 03 00 00 */	cmpwi r3, 0
/* 800704D0  41 82 00 08 */	beq 0x8
/* 800704D4  7F 5F D3 78 */	mr r31, r26
/* 800704D8  3B 5A 00 04 */	addi r26, r26, 4
/* 800704DC  7C 1A E0 40 */	cmplw r26, r28
/* 800704E0  40 82 FF D8 */	bne -0x28
/* 800704E4  7C 1F D8 40 */	cmplw r31, r27
/* 800704E8  41 82 00 14 */	beq 0x14
/* 800704EC  80 7F 00 00 */	lwz r3, 0(r31)
/* 800704F0  80 1B 00 00 */	lwz r0, 0(r27)
/* 800704F4  90 1F 00 00 */	stw r0, 0(r31)
/* 800704F8  90 7B 00 00 */	stw r3, 0(r27)
/* 800704FC  3B 7B 00 04 */	addi r27, r27, 4
/* 80070500  7C 1B F0 40 */	cmplw r27, r30
/* 80070504  40 82 FF A0 */	bne -0x60
/* 80070508  48 00 02 B0 */	b 0x2b0
/* 8007050C  80 8D 81 4C */	lwz r4, -0x7eb4(r13)
/* 80070510  7C E0 16 70 */	srawi r0, r7, 2
/* 80070514  7C A0 01 94 */	addze r5, r0
/* 80070518  7C 1F 20 96 */	mulhw r0, r31, r4
/* 8007051C  38 C4 00 01 */	addi r6, r4, 1
/* 80070520  2C 06 00 05 */	cmpwi r6, 5
/* 80070524  7C 00 0E 70 */	srawi r0, r0, 1
/* 80070528  54 03 0F FE */	srwi r3, r0, 0x1f
/* 8007052C  7C 00 1A 14 */	add r0, r0, r3
/* 80070530  1C 00 00 05 */	mulli r0, r0, 5
/* 80070534  7C 00 20 50 */	subf r0, r0, r4
/* 80070538  7C 05 02 14 */	add r0, r5, r0
/* 8007053C  54 00 10 3A */	slwi r0, r0, 2
/* 80070540  7C 7B 02 14 */	add r3, r27, r0
/* 80070544  41 80 00 08 */	blt 0x8
/* 80070548  38 C0 FF FC */	li r6, -4
/* 8007054C  7C 9F 30 96 */	mulhw r4, r31, r6
/* 80070550  38 06 00 01 */	addi r0, r6, 1
/* 80070554  54 E5 10 3A */	slwi r5, r7, 2
/* 80070558  90 0D 81 4C */	stw r0, -0x7eb4(r13)
/* 8007055C  2C 00 00 05 */	cmpwi r0, 5
/* 80070560  7C 07 28 50 */	subf r0, r7, r5
/* 80070564  7C 00 16 70 */	srawi r0, r0, 2
/* 80070568  7C A0 01 94 */	addze r5, r0
/* 8007056C  7C 80 0E 70 */	srawi r0, r4, 1
/* 80070570  54 04 0F FE */	srwi r4, r0, 0x1f
/* 80070574  7C 00 22 14 */	add r0, r0, r4
/* 80070578  1C 00 00 05 */	mulli r0, r0, 5
/* 8007057C  7C 00 30 50 */	subf r0, r0, r6
/* 80070580  7C 05 02 14 */	add r0, r5, r0
/* 80070584  54 00 10 3A */	slwi r0, r0, 2
/* 80070588  7C 9B 02 14 */	add r4, r27, r0
/* 8007058C  41 80 00 0C */	blt 0xc
/* 80070590  38 C0 FF FC */	li r6, -4
/* 80070594  90 CD 81 4C */	stw r6, -0x7eb4(r13)
/* 80070598  3B 3C FF FC */	addi r25, r28, -4
/* 8007059C  7F A6 EB 78 */	mr r6, r29
/* 800705A0  7F 25 CB 78 */	mr r5, r25
/* 800705A4  48 00 02 2D */	bl 0x22c
/* 800705A8  7F 7E DB 78 */	mr r30, r27
/* 800705AC  7F 3A CB 78 */	mr r26, r25
/* 800705B0  48 00 00 08 */	b 0x8
/* 800705B4  3B DE 00 04 */	addi r30, r30, 4
/* 800705B8  81 9D 00 00 */	lwz r12, 0(r29)
/* 800705BC  80 7E 00 00 */	lwz r3, 0(r30)
/* 800705C0  80 99 00 00 */	lwz r4, 0(r25)
/* 800705C4  7D 89 03 A6 */	mtctr r12
/* 800705C8  4E 80 04 21 */	bctrl 
/* 800705CC  2C 03 00 00 */	cmpwi r3, 0
/* 800705D0  40 82 FF E4 */	bne -0x1c
/* 800705D4  3B 5A FF FC */	addi r26, r26, -4
/* 800705D8  7C 1E D0 40 */	cmplw r30, r26
/* 800705DC  41 82 00 20 */	beq 0x20
/* 800705E0  81 9D 00 00 */	lwz r12, 0(r29)
/* 800705E4  80 7A 00 00 */	lwz r3, 0(r26)
/* 800705E8  80 99 00 00 */	lwz r4, 0(r25)
/* 800705EC  7D 89 03 A6 */	mtctr r12
/* 800705F0  4E 80 04 21 */	bctrl 
/* 800705F4  2C 03 00 00 */	cmpwi r3, 0
/* 800705F8  41 82 FF DC */	beq -0x24
/* 800705FC  7C 1E D0 40 */	cmplw r30, r26
/* 80070600  40 80 00 78 */	bge 0x78
/* 80070604  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070608  80 1A 00 00 */	lwz r0, 0(r26)
/* 8007060C  90 1E 00 00 */	stw r0, 0(r30)
/* 80070610  3B DE 00 04 */	addi r30, r30, 4
/* 80070614  90 7A 00 00 */	stw r3, 0(r26)
/* 80070618  48 00 00 08 */	b 0x8
/* 8007061C  3B DE 00 04 */	addi r30, r30, 4
/* 80070620  81 9D 00 00 */	lwz r12, 0(r29)
/* 80070624  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070628  80 99 00 00 */	lwz r4, 0(r25)
/* 8007062C  7D 89 03 A6 */	mtctr r12
/* 80070630  4E 80 04 21 */	bctrl 
/* 80070634  2C 03 00 00 */	cmpwi r3, 0
/* 80070638  40 82 FF E4 */	bne -0x1c
/* 8007063C  81 9D 00 00 */	lwz r12, 0(r29)
/* 80070640  84 7A FF FC */	lwzu r3, -4(r26)
/* 80070644  80 99 00 00 */	lwz r4, 0(r25)
/* 80070648  7D 89 03 A6 */	mtctr r12
/* 8007064C  4E 80 04 21 */	bctrl 
/* 80070650  2C 03 00 00 */	cmpwi r3, 0
/* 80070654  41 82 FF E8 */	beq -0x18
/* 80070658  7C 1E D0 40 */	cmplw r30, r26
/* 8007065C  40 80 00 1C */	bge 0x1c
/* 80070660  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070664  80 1A 00 00 */	lwz r0, 0(r26)
/* 80070668  90 1E 00 00 */	stw r0, 0(r30)
/* 8007066C  3B DE 00 04 */	addi r30, r30, 4
/* 80070670  90 7A 00 00 */	stw r3, 0(r26)
/* 80070674  4B FF FF AC */	b -0x54
/* 80070678  7C 1E D8 40 */	cmplw r30, r27
/* 8007067C  40 82 00 EC */	bne 0xec
/* 80070680  80 7E 00 00 */	lwz r3, 0(r30)
/* 80070684  80 19 00 00 */	lwz r0, 0(r25)
/* 80070688  90 1E 00 00 */	stw r0, 0(r30)
/* 8007068C  90 79 00 00 */	stw r3, 0(r25)
/* 80070690  81 9D 00 00 */	lwz r12, 0(r29)
/* 80070694  80 7B 00 00 */	lwz r3, 0(r27)
/* 80070698  80 9C FF FC */	lwz r4, -4(r28)
/* 8007069C  7D 89 03 A6 */	mtctr r12
/* 800706A0  3B DE 00 04 */	addi r30, r30, 4
/* 800706A4  3B 5C FF FC */	addi r26, r28, -4
/* 800706A8  4E 80 04 21 */	bctrl 
/* 800706AC  2C 03 00 00 */	cmpwi r3, 0
/* 800706B0  40 82 00 48 */	bne 0x48
/* 800706B4  48 00 00 08 */	b 0x8
/* 800706B8  3B DE 00 04 */	addi r30, r30, 4
/* 800706BC  7C 1E E0 40 */	cmplw r30, r28
/* 800706C0  41 82 00 20 */	beq 0x20
/* 800706C4  81 9D 00 00 */	lwz r12, 0(r29)
/* 800706C8  80 7B 00 00 */	lwz r3, 0(r27)
/* 800706CC  80 9E 00 00 */	lwz r4, 0(r30)
/* 800706D0  7D 89 03 A6 */	mtctr r12
/* 800706D4  4E 80 04 21 */	bctrl 
/* 800706D8  2C 03 00 00 */	cmpwi r3, 0
/* 800706DC  41 82 FF DC */	beq -0x24
/* 800706E0  7C 1E D0 40 */	cmplw r30, r26
/* 800706E4  40 80 00 14 */	bge 0x14
/* 800706E8  80 7E 00 00 */	lwz r3, 0(r30)
/* 800706EC  80 1A 00 00 */	lwz r0, 0(r26)
/* 800706F0  90 1E 00 00 */	stw r0, 0(r30)
/* 800706F4  90 7A 00 00 */	stw r3, 0(r26)
/* 800706F8  7C 1E D0 40 */	cmplw r30, r26
/* 800706FC  40 80 00 64 */	bge 0x64
/* 80070700  48 00 00 08 */	b 0x8
/* 80070704  3B DE 00 04 */	addi r30, r30, 4
/* 80070708  81 9D 00 00 */	lwz r12, 0(r29)
/* 8007070C  80 7B 00 00 */	lwz r3, 0(r27)
/* 80070710  80 9E 00 00 */	lwz r4, 0(r30)
/* 80070714  7D 89 03 A6 */	mtctr r12
/* 80070718  4E 80 04 21 */	bctrl 
/* 8007071C  2C 03 00 00 */	cmpwi r3, 0
/* 80070720  41 82 FF E4 */	beq -0x1c
/* 80070724  81 9D 00 00 */	lwz r12, 0(r29)
/* 80070728  80 7B 00 00 */	lwz r3, 0(r27)
/* 8007072C  84 9A FF FC */	lwzu r4, -4(r26)
/* 80070730  7D 89 03 A6 */	mtctr r12
/* 80070734  4E 80 04 21 */	bctrl 
/* 80070738  2C 03 00 00 */	cmpwi r3, 0
/* 8007073C  40 82 FF E8 */	bne -0x18
/* 80070740  7C 1E D0 40 */	cmplw r30, r26
/* 80070744  40 80 00 1C */	bge 0x1c
/* 80070748  80 7E 00 00 */	lwz r3, 0(r30)
/* 8007074C  80 1A 00 00 */	lwz r0, 0(r26)
/* 80070750  90 1E 00 00 */	stw r0, 0(r30)
/* 80070754  3B DE 00 04 */	addi r30, r30, 4
/* 80070758  90 7A 00 00 */	stw r3, 0(r26)
/* 8007075C  4B FF FF AC */	b -0x54
/* 80070760  7F DB F3 78 */	mr r27, r30
/* 80070764  4B FF FD 14 */	b -0x2ec
/* 80070768  7C 7B F0 50 */	subf r3, r27, r30
/* 8007076C  7C 1E E0 50 */	subf r0, r30, r28
/* 80070770  7C 63 16 70 */	srawi r3, r3, 2
/* 80070774  7C 63 01 94 */	addze r3, r3
/* 80070778  7C 00 16 70 */	srawi r0, r0, 2
/* 8007077C  7C 00 01 94 */	addze r0, r0
/* 80070780  7C 03 00 00 */	cmpw r3, r0
/* 80070784  40 80 00 1C */	bge 0x1c
/* 80070788  7F 63 DB 78 */	mr r3, r27
/* 8007078C  7F C4 F3 78 */	mr r4, r30
/* 80070790  7F A5 EB 78 */	mr r5, r29
/* 80070794  4B FF FC BD */	bl -0x344
/* 80070798  7F DB F3 78 */	mr r27, r30
/* 8007079C  4B FF FC DC */	b -0x324
/* 800707A0  7F C3 F3 78 */	mr r3, r30
/* 800707A4  7F 84 E3 78 */	mr r4, r28
/* 800707A8  7F A5 EB 78 */	mr r5, r29
/* 800707AC  4B FF FC A5 */	bl -0x35c
/* 800707B0  7F DC F3 78 */	mr r28, r30
/* 800707B4  4B FF FC C4 */	b -0x33c
/* 800707B8  39 61 00 30 */	addi r11, r1, 0x30
/* 800707BC  4B FB 0E 29 */	bl -0x4f1d8
/* 800707C0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800707C4  7C 08 03 A6 */	mtlr r0
/* 800707C8  38 21 00 30 */	addi r1, r1, 0x30
/* 800707CC  4E 80 00 20 */	blr 
/* 800707D0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800707D4  7C 08 02 A6 */	mflr r0
/* 800707D8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800707DC  39 61 00 20 */	addi r11, r1, 0x20
/* 800707E0  4B FB 0D C1 */	bl -0x4f240
/* 800707E4  81 86 00 00 */	lwz r12, 0(r6)
/* 800707E8  7C 7B 1B 78 */	mr r27, r3
/* 800707EC  7C 9C 23 78 */	mr r28, r4
/* 800707F0  7C BD 2B 78 */	mr r29, r5
/* 800707F4  7C DE 33 78 */	mr r30, r6
/* 800707F8  80 65 00 00 */	lwz r3, 0(r5)
/* 800707FC  80 9B 00 00 */	lwz r4, 0(r27)
/* 80070800  7D 89 03 A6 */	mtctr r12
/* 80070804  4E 80 04 21 */	bctrl 
/* 80070808  81 9E 00 00 */	lwz r12, 0(r30)
/* 8007080C  7C 60 00 34 */	cntlzw r0, r3
/* 80070810  54 1F D9 7E */	srwi r31, r0, 5
/* 80070814  80 7C 00 00 */	lwz r3, 0(r28)
/* 80070818  80 9D 00 00 */	lwz r4, 0(r29)
/* 8007081C  7D 89 03 A6 */	mtctr r12
/* 80070820  4E 80 04 21 */	bctrl 
/* 80070824  2C 1F 00 00 */	cmpwi r31, 0
/* 80070828  7C 60 00 34 */	cntlzw r0, r3
/* 8007082C  54 00 D9 7E */	srwi r0, r0, 5
/* 80070830  41 82 00 0C */	beq 0xc
/* 80070834  2C 00 00 00 */	cmpwi r0, 0
/* 80070838  40 82 00 80 */	bne 0x80
/* 8007083C  2C 1F 00 00 */	cmpwi r31, 0
/* 80070840  40 82 00 20 */	bne 0x20
/* 80070844  2C 00 00 00 */	cmpwi r0, 0
/* 80070848  40 82 00 18 */	bne 0x18
/* 8007084C  80 7B 00 00 */	lwz r3, 0(r27)
/* 80070850  80 1C 00 00 */	lwz r0, 0(r28)
/* 80070854  90 1B 00 00 */	stw r0, 0(r27)
/* 80070858  90 7C 00 00 */	stw r3, 0(r28)
/* 8007085C  48 00 00 5C */	b 0x5c
/* 80070860  81 9E 00 00 */	lwz r12, 0(r30)
/* 80070864  80 7C 00 00 */	lwz r3, 0(r28)
/* 80070868  80 9B 00 00 */	lwz r4, 0(r27)
/* 8007086C  7D 89 03 A6 */	mtctr r12
/* 80070870  4E 80 04 21 */	bctrl 
/* 80070874  2C 03 00 00 */	cmpwi r3, 0
/* 80070878  41 82 00 14 */	beq 0x14
/* 8007087C  80 7B 00 00 */	lwz r3, 0(r27)
/* 80070880  80 1C 00 00 */	lwz r0, 0(r28)
/* 80070884  90 1B 00 00 */	stw r0, 0(r27)
/* 80070888  90 7C 00 00 */	stw r3, 0(r28)
/* 8007088C  2C 1F 00 00 */	cmpwi r31, 0
/* 80070890  41 82 00 18 */	beq 0x18
/* 80070894  80 7C 00 00 */	lwz r3, 0(r28)
/* 80070898  80 1D 00 00 */	lwz r0, 0(r29)
/* 8007089C  90 1C 00 00 */	stw r0, 0(r28)
/* 800708A0  90 7D 00 00 */	stw r3, 0(r29)
/* 800708A4  48 00 00 14 */	b 0x14
/* 800708A8  80 7B 00 00 */	lwz r3, 0(r27)
/* 800708AC  80 1D 00 00 */	lwz r0, 0(r29)
/* 800708B0  90 1B 00 00 */	stw r0, 0(r27)
/* 800708B4  90 7D 00 00 */	stw r3, 0(r29)
/* 800708B8  39 61 00 20 */	addi r11, r1, 0x20
/* 800708BC  4B FB 0D 31 */	bl -0x4f2d0
/* 800708C0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800708C4  7C 08 03 A6 */	mtlr r0
/* 800708C8  38 21 00 20 */	addi r1, r1, 0x20
/* 800708CC  4E 80 00 20 */	blr 
/* 800708D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800708D4  7C 08 02 A6 */	mflr r0
/* 800708D8  3C A0 80 07 */	lis r5, 0x8007
/* 800708DC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800708E0  38 A5 09 30 */	addi r5, r5, 0x930
/* 800708E4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800708E8  7C 7F 1B 78 */	mr r31, r3
/* 800708EC  80 1F 00 10 */	lwz r0, 0x10(r31)
/* 800708F0  80 63 00 04 */	lwz r3, 4(r3)
/* 800708F4  54 00 10 3A */	slwi r0, r0, 2
/* 800708F8  7C 83 02 14 */	add r4, r3, r0
/* 800708FC  4B FF F7 D5 */	bl -0x82c
/* 80070900  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80070904  3C A0 80 07 */	lis r5, 0x8007
/* 80070908  80 7F 00 08 */	lwz r3, 8(r31)
/* 8007090C  38 A5 09 C0 */	addi r5, r5, 0x9c0
/* 80070910  54 00 10 3A */	slwi r0, r0, 2
/* 80070914  7C 83 02 14 */	add r4, r3, r0
/* 80070918  4B FF F7 B9 */	bl -0x848
/* 8007091C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80070920  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80070924  7C 08 03 A6 */	mtlr r0
/* 80070928  38 21 00 10 */	addi r1, r1, 0x10
/* 8007092C  4E 80 00 20 */	blr 
/* 80070930  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80070934  7C 08 02 A6 */	mflr r0
/* 80070938  90 01 00 24 */	stw r0, 0x24(r1)
/* 8007093C  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 80070940  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80070944  7C 7F 1B 78 */	mr r31, r3
/* 80070948  88 03 00 D0 */	lbz r0, 0xd0(r3)
/* 8007094C  88 A4 00 D0 */	lbz r5, 0xd0(r4)
/* 80070950  7C 00 28 00 */	cmpw r0, r5
/* 80070954  40 82 00 40 */	bne 0x40
/* 80070958  81 84 00 00 */	lwz r12, 0(r4)
/* 8007095C  7C 83 23 78 */	mr r3, r4
/* 80070960  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 80070964  7D 89 03 A6 */	mtctr r12
/* 80070968  4E 80 04 21 */	bctrl 
/* 8007096C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80070970  FF E0 08 90 */	fmr f31, f1
/* 80070974  7F E3 FB 78 */	mr r3, r31
/* 80070978  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8007097C  7D 89 03 A6 */	mtctr r12
/* 80070980  4E 80 04 21 */	bctrl 
/* 80070984  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 80070988  7C 60 00 26 */	mfcr r3
/* 8007098C  54 63 0F FE */	srwi r3, r3, 0x1f
/* 80070990  48 00 00 18 */	b 0x18
/* 80070994  7C A0 02 78 */	xor r0, r5, r0
/* 80070998  7C 03 0E 70 */	srawi r3, r0, 1
/* 8007099C  7C 00 28 38 */	and r0, r0, r5
/* 800709A0  7C 00 18 50 */	subf r0, r0, r3
/* 800709A4  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800709A8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800709AC  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 800709B0  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 800709B4  7C 08 03 A6 */	mtlr r0
/* 800709B8  38 21 00 20 */	addi r1, r1, 0x20
/* 800709BC  4E 80 00 20 */	blr 
/* 800709C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800709C4  7C 08 02 A6 */	mflr r0
/* 800709C8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800709CC  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 800709D0  93 E1 00 14 */	stw r31, 0x14(r1)
/* 800709D4  7C 7F 1B 78 */	mr r31, r3
/* 800709D8  88 03 00 D1 */	lbz r0, 0xd1(r3)
/* 800709DC  88 A4 00 D1 */	lbz r5, 0xd1(r4)
/* 800709E0  7C 00 28 00 */	cmpw r0, r5
/* 800709E4  40 82 00 40 */	bne 0x40
/* 800709E8  81 84 00 00 */	lwz r12, 0(r4)
/* 800709EC  7C 83 23 78 */	mr r3, r4
/* 800709F0  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 800709F4  7D 89 03 A6 */	mtctr r12
/* 800709F8  4E 80 04 21 */	bctrl 
/* 800709FC  81 9F 00 00 */	lwz r12, 0(r31)
/* 80070A00  FF E0 08 90 */	fmr f31, f1
/* 80070A04  7F E3 FB 78 */	mr r3, r31
/* 80070A08  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 80070A0C  7D 89 03 A6 */	mtctr r12
/* 80070A10  4E 80 04 21 */	bctrl 
/* 80070A14  FC 01 F8 40 */	fcmpo cr0, f1, f31
/* 80070A18  7C 60 00 26 */	mfcr r3
/* 80070A1C  54 63 0F FE */	srwi r3, r3, 0x1f
/* 80070A20  48 00 00 18 */	b 0x18
/* 80070A24  7C A0 02 78 */	xor r0, r5, r0
/* 80070A28  7C 03 0E 70 */	srawi r3, r0, 1
/* 80070A2C  7C 00 28 38 */	and r0, r0, r5
/* 80070A30  7C 00 18 50 */	subf r0, r0, r3
/* 80070A34  54 03 0F FE */	srwi r3, r0, 0x1f
/* 80070A38  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80070A3C  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 80070A40  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80070A44  7C 08 03 A6 */	mtlr r0
/* 80070A48  38 21 00 20 */	addi r1, r1, 0x20
/* 80070A4C  4E 80 00 20 */	blr 
/* 80070A50  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80070A54  7C 08 02 A6 */	mflr r0
/* 80070A58  90 01 00 14 */	stw r0, 0x14(r1)
/* 80070A5C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80070A60  7C BF 2B 78 */	mr r31, r5
/* 80070A64  7C 85 23 78 */	mr r5, r4
/* 80070A68  93 C1 00 08 */	stw r30, 8(r1)
/* 80070A6C  7C 7E 1B 78 */	mr r30, r3
/* 80070A70  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 80070A74  80 63 00 04 */	lwz r3, 4(r3)
/* 80070A78  54 00 10 3A */	slwi r0, r0, 2
/* 80070A7C  7C 83 02 14 */	add r4, r3, r0
/* 80070A80  4B FF F6 51 */	bl -0x9b0
/* 80070A84  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 80070A88  7F E5 FB 78 */	mr r5, r31
/* 80070A8C  80 7E 00 08 */	lwz r3, 8(r30)
/* 80070A90  54 00 10 3A */	slwi r0, r0, 2
/* 80070A94  7C 83 02 14 */	add r4, r3, r0
/* 80070A98  4B FF F6 39 */	bl -0x9c8
/* 80070A9C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80070AA0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80070AA4  83 C1 00 08 */	lwz r30, 8(r1)
/* 80070AA8  7C 08 03 A6 */	mtlr r0
/* 80070AAC  38 21 00 10 */	addi r1, r1, 0x10
/* 80070AB0  4E 80 00 20 */	blr 
/* 80070AB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070AB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070ABC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070AC0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80070AC4  7C 08 02 A6 */	mflr r0
/* 80070AC8  90 01 00 24 */	stw r0, 0x24(r1)
/* 80070ACC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80070AD0  3B E0 00 00 */	li r31, 0
/* 80070AD4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80070AD8  3B C0 00 00 */	li r30, 0
/* 80070ADC  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80070AE0  7C 9D 23 78 */	mr r29, r4
/* 80070AE4  93 81 00 10 */	stw r28, 0x10(r1)
/* 80070AE8  7C 7C 1B 78 */	mr r28, r3
/* 80070AEC  48 00 00 30 */	b 0x30
/* 80070AF0  80 7C 00 04 */	lwz r3, 4(r28)
/* 80070AF4  7F A6 EB 78 */	mr r6, r29
/* 80070AF8  38 80 00 06 */	li r4, 6
/* 80070AFC  38 A0 00 00 */	li r5, 0
/* 80070B00  7C 63 F8 2E */	lwzx r3, r3, r31
/* 80070B04  81 83 00 00 */	lwz r12, 0(r3)
/* 80070B08  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80070B0C  7D 89 03 A6 */	mtctr r12
/* 80070B10  3B DE 00 01 */	addi r30, r30, 1
/* 80070B14  3B FF 00 04 */	addi r31, r31, 4
/* 80070B18  4E 80 04 21 */	bctrl 
/* 80070B1C  80 1C 00 10 */	lwz r0, 0x10(r28)
/* 80070B20  7C 1E 00 40 */	cmplw r30, r0
/* 80070B24  40 82 FF CC */	bne -0x34
/* 80070B28  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80070B2C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80070B30  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80070B34  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80070B38  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80070B3C  7C 08 03 A6 */	mtlr r0
/* 80070B40  38 21 00 20 */	addi r1, r1, 0x20
/* 80070B44  4E 80 00 20 */	blr 
/* 80070B48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070B4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070B50  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80070B54  7C 08 02 A6 */	mflr r0
/* 80070B58  90 01 00 24 */	stw r0, 0x24(r1)
/* 80070B5C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80070B60  3B E0 00 00 */	li r31, 0
/* 80070B64  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80070B68  3B C0 00 00 */	li r30, 0
/* 80070B6C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80070B70  7C 9D 23 78 */	mr r29, r4
/* 80070B74  93 81 00 10 */	stw r28, 0x10(r1)
/* 80070B78  7C 7C 1B 78 */	mr r28, r3
/* 80070B7C  48 00 00 30 */	b 0x30
/* 80070B80  80 7C 00 08 */	lwz r3, 8(r28)
/* 80070B84  7F A6 EB 78 */	mr r6, r29
/* 80070B88  38 80 00 07 */	li r4, 7
/* 80070B8C  38 A0 00 00 */	li r5, 0
/* 80070B90  7C 63 F8 2E */	lwzx r3, r3, r31
/* 80070B94  81 83 00 00 */	lwz r12, 0(r3)
/* 80070B98  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80070B9C  7D 89 03 A6 */	mtctr r12
/* 80070BA0  3B DE 00 01 */	addi r30, r30, 1
/* 80070BA4  3B FF 00 04 */	addi r31, r31, 4
/* 80070BA8  4E 80 04 21 */	bctrl 
/* 80070BAC  80 1C 00 14 */	lwz r0, 0x14(r28)
/* 80070BB0  7C 1E 00 40 */	cmplw r30, r0
/* 80070BB4  40 82 FF CC */	bne -0x34
/* 80070BB8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80070BBC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80070BC0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80070BC4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80070BC8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80070BCC  7C 08 03 A6 */	mtlr r0
/* 80070BD0  38 21 00 20 */	addi r1, r1, 0x20
/* 80070BD4  4E 80 00 20 */	blr 
/* 80070BD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070BDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070BE0  38 60 00 00 */	li r3, 0
/* 80070BE4  4E 80 00 20 */	blr 
/* 80070BE8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070BEC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070BF0  3C E0 80 27 */	lis r7, 0x8027
/* 80070BF4  38 00 00 00 */	li r0, 0
/* 80070BF8  38 E7 31 80 */	addi r7, r7, 0x3180
/* 80070BFC  90 E3 00 00 */	stw r7, 0(r3)
/* 80070C00  90 83 00 04 */	stw r4, 4(r3)
/* 80070C04  90 A3 00 08 */	stw r5, 8(r3)
/* 80070C08  90 C3 00 0C */	stw r6, 0xc(r3)
/* 80070C0C  90 03 00 10 */	stw r0, 0x10(r3)
/* 80070C10  90 03 00 14 */	stw r0, 0x14(r3)
/* 80070C14  4E 80 00 20 */	blr 
/* 80070C18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070C1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070C20  38 00 00 00 */	li r0, 0
/* 80070C24  90 03 00 14 */	stw r0, 0x14(r3)
/* 80070C28  90 03 00 10 */	stw r0, 0x10(r3)
/* 80070C2C  4E 80 00 20 */	blr 
/* 80070C30  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80070C34  7C 08 02 A6 */	mflr r0
/* 80070C38  2C 03 00 00 */	cmpwi r3, 0
/* 80070C3C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80070C40  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80070C44  7C 7F 1B 78 */	mr r31, r3
/* 80070C48  41 82 00 10 */	beq 0x10
/* 80070C4C  2C 04 00 00 */	cmpwi r4, 0
/* 80070C50  40 81 00 08 */	ble 0x8
/* 80070C54  48 1B 91 C1 */	bl 0x1b91c0
/* 80070C58  7F E3 FB 78 */	mr r3, r31
/* 80070C5C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80070C60  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80070C64  7C 08 03 A6 */	mtlr r0
/* 80070C68  38 21 00 10 */	addi r1, r1, 0x10
/* 80070C6C  4E 80 00 20 */	blr 
/* 80070C70  3C 60 80 24 */	lis r3, 0x8024
/* 80070C74  80 04 00 00 */	lwz r0, 0(r4)
/* 80070C78  38 63 7F A0 */	addi r3, r3, 0x7fa0
/* 80070C7C  7C 00 18 40 */	cmplw r0, r3
/* 80070C80  40 82 00 0C */	bne 0xc
/* 80070C84  38 60 00 01 */	li r3, 1
/* 80070C88  4E 80 00 20 */	blr 
/* 80070C8C  3C 60 80 24 */	lis r3, 0x8024
/* 80070C90  80 04 00 00 */	lwz r0, 0(r4)
/* 80070C94  38 63 7F 90 */	addi r3, r3, 0x7f90
/* 80070C98  7C 00 18 40 */	cmplw r0, r3
/* 80070C9C  40 82 00 0C */	bne 0xc
/* 80070CA0  38 60 00 01 */	li r3, 1
/* 80070CA4  4E 80 00 20 */	blr 
/* 80070CA8  3C 60 80 24 */	lis r3, 0x8024
/* 80070CAC  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 80070CB0  7C 00 18 40 */	cmplw r0, r3
/* 80070CB4  40 82 00 0C */	bne 0xc
/* 80070CB8  38 60 00 01 */	li r3, 1
/* 80070CBC  4E 80 00 20 */	blr 
/* 80070CC0  3C 60 80 24 */	lis r3, 0x8024
/* 80070CC4  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 80070CC8  7C 00 18 50 */	subf r0, r0, r3
/* 80070CCC  7C 00 00 34 */	cntlzw r0, r0
/* 80070CD0  54 03 D9 7E */	srwi r3, r0, 5
/* 80070CD4  4E 80 00 20 */	blr 
/* 80070CD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070CDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070CE0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80070CE4  7C 08 02 A6 */	mflr r0
/* 80070CE8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80070CEC  81 83 00 00 */	lwz r12, 0(r3)
/* 80070CF0  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80070CF4  7D 89 03 A6 */	mtctr r12
/* 80070CF8  4E 80 04 21 */	bctrl 
/* 80070CFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80070D00  38 63 00 04 */	addi r3, r3, 4
/* 80070D04  7C 08 03 A6 */	mtlr r0
/* 80070D08  38 21 00 10 */	addi r1, r1, 0x10
/* 80070D0C  4E 80 00 20 */	blr 
/* 80070D10  3C 60 80 24 */	lis r3, 0x8024
/* 80070D14  38 63 7F A0 */	addi r3, r3, 0x7fa0
/* 80070D18  4E 80 00 20 */	blr 
/* 80070D1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070D20  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80070D24  7C 08 02 A6 */	mflr r0
/* 80070D28  90 01 00 44 */	stw r0, 0x44(r1)
/* 80070D2C  39 61 00 40 */	addi r11, r1, 0x40
/* 80070D30  4B FB 08 5D */	bl -0x4f7a4
/* 80070D34  81 25 00 00 */	lwz r9, 0(r5)
/* 80070D38  7C 79 1B 78 */	mr r25, r3
/* 80070D3C  7C BA 2B 78 */	mr r26, r5
/* 80070D40  7C DB 33 78 */	mr r27, r6
/* 80070D44  2C 09 00 00 */	cmpwi r9, 0
/* 80070D48  40 82 00 0C */	bne 0xc
/* 80070D4C  38 60 00 00 */	li r3, 0
/* 80070D50  48 00 01 4C */	b 0x14c
/* 80070D54  2C 06 00 00 */	cmpwi r6, 0
/* 80070D58  40 82 00 0C */	bne 0xc
/* 80070D5C  3B 60 00 01 */	li r27, 1
/* 80070D60  48 00 00 10 */	b 0x10
/* 80070D64  2C 06 00 10 */	cmpwi r6, 0x10
/* 80070D68  40 81 00 08 */	ble 0x8
/* 80070D6C  3B 60 00 10 */	li r27, 0x10
/* 80070D70  83 E9 00 68 */	lwz r31, 0x68(r9)
/* 80070D74  39 09 00 4C */	addi r8, r9, 0x4c
/* 80070D78  88 A9 00 6C */	lbz r5, 0x6c(r9)
/* 80070D7C  38 00 00 00 */	li r0, 0
/* 80070D80  1C DF 00 30 */	mulli r6, r31, 0x30
/* 80070D84  80 E9 00 70 */	lwz r7, 0x70(r9)
/* 80070D88  2C 05 00 00 */	cmpwi r5, 0
/* 80070D8C  7C E8 38 2E */	lwzx r7, r8, r7
/* 80070D90  38 A6 00 1F */	addi r5, r6, 0x1f
/* 80070D94  54 A5 00 34 */	rlwinm r5, r5, 0, 0, 0x1a
/* 80070D98  54 EA 10 3A */	slwi r10, r7, 2
/* 80070D9C  7D 1B 29 D6 */	mullw r8, r27, r5
/* 80070DA0  1C C7 00 30 */	mulli r6, r7, 0x30
/* 80070DA4  1C BF 00 24 */	mulli r5, r31, 0x24
/* 80070DA8  41 82 00 14 */	beq 0x14
/* 80070DAC  38 A5 00 1F */	addi r5, r5, 0x1f
/* 80070DB0  54 A5 00 34 */	rlwinm r5, r5, 0, 0, 0x1a
/* 80070DB4  7F DB 29 D6 */	mullw r30, r27, r5
/* 80070DB8  48 00 00 08 */	b 0x8
/* 80070DBC  3B C0 00 00 */	li r30, 0
/* 80070DC0  38 A6 01 5F */	addi r5, r6, 0x15f
/* 80070DC4  88 E9 00 6D */	lbz r7, 0x6d(r9)
/* 80070DC8  54 BD 00 34 */	rlwinm r29, r5, 0, 0, 0x1a
/* 80070DCC  2C 04 00 00 */	cmpwi r4, 0
/* 80070DD0  7C BD 52 14 */	add r5, r29, r10
/* 80070DD4  7C C7 00 D0 */	neg r6, r7
/* 80070DD8  38 A5 00 1F */	addi r5, r5, 0x1f
/* 80070DDC  54 BC 00 34 */	rlwinm r28, r5, 0, 0, 0x1a
/* 80070DE0  7C C6 3B 78 */	or r6, r6, r7
/* 80070DE4  7C BC 42 14 */	add r5, r28, r8
/* 80070DE8  38 A5 00 1F */	addi r5, r5, 0x1f
/* 80070DEC  7C C6 FE 70 */	srawi r6, r6, 0x1f
/* 80070DF0  54 B7 00 34 */	rlwinm r23, r5, 0, 0, 0x1a
/* 80070DF4  7C B7 F2 14 */	add r5, r23, r30
/* 80070DF8  7D 18 30 38 */	and r24, r8, r6
/* 80070DFC  38 A5 00 1F */	addi r5, r5, 0x1f
/* 80070E00  54 B6 00 34 */	rlwinm r22, r5, 0, 0, 0x1a
/* 80070E04  7C B6 C2 14 */	add r5, r22, r24
/* 80070E08  38 A5 00 1F */	addi r5, r5, 0x1f
/* 80070E0C  54 A5 00 34 */	rlwinm r5, r5, 0, 0, 0x1a
/* 80070E10  41 82 00 08 */	beq 0x8
/* 80070E14  90 A4 00 00 */	stw r5, 0(r4)
/* 80070E18  2C 03 00 00 */	cmpwi r3, 0
/* 80070E1C  41 82 00 7C */	beq 0x7c
/* 80070E20  7F 23 CB 78 */	mr r3, r25
/* 80070E24  7C A4 2B 78 */	mr r4, r5
/* 80070E28  48 12 8D 71 */	bl 0x128d70
/* 80070E2C  2C 03 00 00 */	cmpwi r3, 0
/* 80070E30  40 82 00 0C */	bne 0xc
/* 80070E34  38 60 00 00 */	li r3, 0
/* 80070E38  48 00 00 64 */	b 0x64
/* 80070E3C  7C 60 1B 78 */	mr r0, r3
/* 80070E40  41 82 00 58 */	beq 0x58
/* 80070E44  2C 18 00 00 */	cmpwi r24, 0
/* 80070E48  41 82 00 0C */	beq 0xc
/* 80070E4C  7D 43 B2 14 */	add r10, r3, r22
/* 80070E50  48 00 00 08 */	b 0x8
/* 80070E54  39 40 00 00 */	li r10, 0
/* 80070E58  2C 1E 00 00 */	cmpwi r30, 0
/* 80070E5C  41 82 00 0C */	beq 0xc
/* 80070E60  7D 23 BA 14 */	add r9, r3, r23
/* 80070E64  48 00 00 08 */	b 0x8
/* 80070E68  39 20 00 00 */	li r9, 0
/* 80070E6C  80 1A 00 00 */	lwz r0, 0(r26)
/* 80070E70  7F 24 CB 78 */	mr r4, r25
/* 80070E74  90 01 00 10 */	stw r0, 0x10(r1)
/* 80070E78  38 A1 00 10 */	addi r5, r1, 0x10
/* 80070E7C  38 C3 01 40 */	addi r6, r3, 0x140
/* 80070E80  7C E3 EA 14 */	add r7, r3, r29
/* 80070E84  93 61 00 08 */	stw r27, 8(r1)
/* 80070E88  7D 03 E2 14 */	add r8, r3, r28
/* 80070E8C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80070E90  48 00 1B E1 */	bl 0x1be0
/* 80070E94  7C 60 1B 78 */	mr r0, r3
/* 80070E98  7C 03 03 78 */	mr r3, r0
/* 80070E9C  39 61 00 40 */	addi r11, r1, 0x40
/* 80070EA0  4B FB 07 39 */	bl -0x4f8c8
/* 80070EA4  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80070EA8  7C 08 03 A6 */	mtlr r0
/* 80070EAC  38 21 00 40 */	addi r1, r1, 0x40
/* 80070EB0  4E 80 00 20 */	blr 
/* 80070EB4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070EB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070EBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80070EC0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80070EC4  7C 08 02 A6 */	mflr r0
/* 80070EC8  90 01 00 44 */	stw r0, 0x44(r1)
/* 80070ECC  39 61 00 40 */	addi r11, r1, 0x40
/* 80070ED0  4B FB 06 CD */	bl -0x4f934
/* 80070ED4  90 81 00 08 */	stw r4, 8(r1)
/* 80070ED8  7C BA 2B 78 */	mr r26, r5
/* 80070EDC  7C 7E 1B 78 */	mr r30, r3
/* 80070EE0  80 A3 00 D4 */	lwz r5, 0xd4(r3)
/* 80070EE4  2C 05 00 00 */	cmpwi r5, 0
/* 80070EE8  41 82 00 40 */	beq 0x40
/* 80070EEC  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80070EF0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80070EF4  41 82 00 34 */	beq 0x34
/* 80070EF8  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80070EFC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80070F00  41 82 00 28 */	beq 0x28
/* 80070F04  7C A3 2B 78 */	mr r3, r5
/* 80070F08  7C 86 23 78 */	mr r6, r4
/* 80070F0C  81 83 00 00 */	lwz r12, 0(r3)
/* 80070F10  7F C5 F3 78 */	mr r5, r30
/* 80070F14  7F 47 D3 78 */	mr r7, r26
/* 80070F18  38 80 00 01 */	li r4, 1
/* 80070F1C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80070F20  7D 89 03 A6 */	mtctr r12
/* 80070F24  4E 80 04 21 */	bctrl 
/* 80070F28  81 9E 00 00 */	lwz r12, 0(r30)
/* 80070F2C  7F C3 F3 78 */	mr r3, r30
/* 80070F30  7F 44 D3 78 */	mr r4, r26
/* 80070F34  38 A1 00 08 */	addi r5, r1, 8
/* 80070F38  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80070F3C  7D 89 03 A6 */	mtctr r12
/* 80070F40  4E 80 04 21 */	bctrl 
/* 80070F44  80 7E 00 D4 */	lwz r3, 0xd4(r30)
/* 80070F48  80 C1 00 08 */	lwz r6, 8(r1)
/* 80070F4C  2C 03 00 00 */	cmpwi r3, 0
/* 80070F50  41 82 00 38 */	beq 0x38
/* 80070F54  A0 1E 00 DA */	lhz r0, 0xda(r30)
/* 80070F58  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80070F5C  41 82 00 2C */	beq 0x2c
/* 80070F60  88 1E 00 D8 */	lbz r0, 0xd8(r30)
/* 80070F64  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80070F68  41 82 00 20 */	beq 0x20
/* 80070F6C  81 83 00 00 */	lwz r12, 0(r3)
/* 80070F70  7F C5 F3 78 */	mr r5, r30
/* 80070F74  7F 47 D3 78 */	mr r7, r26
/* 80070F78  38 80 00 02 */	li r4, 2
/* 80070F7C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80070F80  7D 89 03 A6 */	mtctr r12
/* 80070F84  4E 80 04 21 */	bctrl 
/* 80070F88  80 7E 00 E8 */	lwz r3, 0xe8(r30)
/* 80070F8C  3B E0 00 00 */	li r31, 0
/* 80070F90  38 63 00 4C */	addi r3, r3, 0x4c
/* 80070F94  80 03 00 24 */	lwz r0, 0x24(r3)
/* 80070F98  7F 83 00 2E */	lwzx r28, r3, r0
/* 80070F9C  38 1C FF F7 */	addi r0, r28, -9
/* 80070FA0  28 00 01 4C */	cmplwi r0, 0x14c
/* 80070FA4  41 81 00 34 */	bgt 0x34
/* 80070FA8  48 04 08 C9 */	bl 0x408c8
/* 80070FAC  28 03 00 01 */	cmplwi r3, 1
/* 80070FB0  7C 7F 1B 78 */	mr r31, r3
/* 80070FB4  40 82 00 24 */	bne 0x24
/* 80070FB8  80 1E 01 04 */	lwz r0, 0x104(r30)
/* 80070FBC  1C 9C 00 30 */	mulli r4, r28, 0x30
/* 80070FC0  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 80070FC4  60 00 00 01 */	ori r0, r0, 1
/* 80070FC8  90 1E 01 04 */	stw r0, 0x104(r30)
/* 80070FCC  48 13 06 35 */	bl 0x130634
/* 80070FD0  3F 60 E0 00 */	lis r27, 0xe000
/* 80070FD4  48 00 00 14 */	b 0x14
/* 80070FD8  80 1E 01 04 */	lwz r0, 0x104(r30)
/* 80070FDC  83 7E 00 EC */	lwz r27, 0xec(r30)
/* 80070FE0  54 00 00 3C */	rlwinm r0, r0, 0, 0, 0x1e
/* 80070FE4  90 1E 01 04 */	stw r0, 0x104(r30)
/* 80070FE8  7F C3 F3 78 */	mr r3, r30
/* 80070FEC  4B FF D0 85 */	bl -0x2f7c
/* 80070FF0  81 9E 00 00 */	lwz r12, 0(r30)
/* 80070FF4  3C 80 00 02 */	lis r4, 2
/* 80070FF8  7C 7D 1B 78 */	mr r29, r3
/* 80070FFC  7F C3 F3 78 */	mr r3, r30
/* 80071000  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80071004  38 84 00 01 */	addi r4, r4, 1
/* 80071008  38 A1 00 18 */	addi r5, r1, 0x18
/* 8007100C  3F 40 F0 00 */	lis r26, 0xf000
/* 80071010  7D 89 03 A6 */	mtctr r12
/* 80071014  4E 80 04 21 */	bctrl 
/* 80071018  2C 1D 00 01 */	cmpwi r29, 1
/* 8007101C  40 82 00 0C */	bne 0xc
/* 80071020  3F 40 30 00 */	lis r26, 0x3000
/* 80071024  48 00 00 10 */	b 0x10
/* 80071028  2C 1D 00 02 */	cmpwi r29, 2
/* 8007102C  40 82 00 08 */	bne 0x8
/* 80071030  3B 40 00 00 */	li r26, 0
/* 80071034  80 01 00 18 */	lwz r0, 0x18(r1)
/* 80071038  2C 00 00 00 */	cmpwi r0, 0
/* 8007103C  41 82 00 08 */	beq 0x8
/* 80071040  67 5A 08 00 */	oris r26, r26, 0x800
/* 80071044  80 BE 01 1C */	lwz r5, 0x11c(r30)
/* 80071048  2C 05 00 00 */	cmpwi r5, 0
/* 8007104C  41 82 00 48 */	beq 0x48
/* 80071050  A0 9E 01 22 */	lhz r4, 0x122(r30)
/* 80071054  7F 63 DB 78 */	mr r3, r27
/* 80071058  88 1E 01 20 */	lbz r0, 0x120(r30)
/* 8007105C  7F 4A D3 78 */	mr r10, r26
/* 80071060  98 01 00 24 */	stb r0, 0x24(r1)
/* 80071064  38 DE 00 3C */	addi r6, r30, 0x3c
/* 80071068  38 E1 00 14 */	addi r7, r1, 0x14
/* 8007106C  39 21 00 20 */	addi r9, r1, 0x20
/* 80071070  90 A1 00 20 */	stw r5, 0x20(r1)
/* 80071074  B0 81 00 26 */	sth r4, 0x26(r1)
/* 80071078  81 1E 01 24 */	lwz r8, 0x124(r30)
/* 8007107C  80 1E 00 E8 */	lwz r0, 0xe8(r30)
/* 80071080  90 01 00 14 */	stw r0, 0x14(r1)
/* 80071084  80 9E 00 F0 */	lwz r4, 0xf0(r30)
/* 80071088  80 BE 01 08 */	lwz r5, 0x108(r30)
/* 8007108C  4B FF 69 15 */	bl -0x96ec
/* 80071090  48 00 00 30 */	b 0x30
/* 80071094  81 1E 01 24 */	lwz r8, 0x124(r30)
/* 80071098  7F 63 DB 78 */	mr r3, r27
/* 8007109C  80 1E 00 E8 */	lwz r0, 0xe8(r30)
/* 800710A0  7F 4A D3 78 */	mr r10, r26
/* 800710A4  90 01 00 10 */	stw r0, 0x10(r1)
/* 800710A8  38 DE 00 3C */	addi r6, r30, 0x3c
/* 800710AC  38 E1 00 10 */	addi r7, r1, 0x10
/* 800710B0  39 20 00 00 */	li r9, 0
/* 800710B4  80 9E 00 F0 */	lwz r4, 0xf0(r30)
/* 800710B8  80 BE 01 08 */	lwz r5, 0x108(r30)
/* 800710BC  4B FF 68 E5 */	bl -0x971c
/* 800710C0  80 DE 01 0C */	lwz r6, 0x10c(r30)
/* 800710C4  2C 06 00 00 */	cmpwi r6, 0
/* 800710C8  41 82 00 1C */	beq 0x1c
/* 800710CC  80 1E 00 E8 */	lwz r0, 0xe8(r30)
/* 800710D0  7F 63 DB 78 */	mr r3, r27
/* 800710D4  90 01 00 0C */	stw r0, 0xc(r1)
/* 800710D8  38 A1 00 0C */	addi r5, r1, 0xc
/* 800710DC  80 9E 00 F0 */	lwz r4, 0xf0(r30)
/* 800710E0  4B FF 6E 91 */	bl -0x9170
/* 800710E4  2C 1F 00 00 */	cmpwi r31, 0
/* 800710E8  41 82 00 18 */	beq 0x18
/* 800710EC  1C BC 00 30 */	mulli r5, r28, 0x30
/* 800710F0  80 7E 00 EC */	lwz r3, 0xec(r30)
/* 800710F4  3C 80 E0 00 */	lis r4, 0xe000
/* 800710F8  48 04 08 49 */	bl 0x40848
/* 800710FC  48 04 07 E5 */	bl 0x407e4
/* 80071100  39 61 00 40 */	addi r11, r1, 0x40
/* 80071104  4B FB 04 E5 */	bl -0x4fb1c
/* 80071108  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8007110C  7C 08 03 A6 */	mtlr r0
/* 80071110  38 21 00 40 */	addi r1, r1, 0x40
/* 80071114  4E 80 00 20 */	blr 
/* 80071118  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007111C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80071120  7C 64 1B 78 */	mr r4, r3
/* 80071124  81 85 00 00 */	lwz r12, 0(r5)
/* 80071128  80 04 00 CC */	lwz r0, 0xcc(r4)
/* 8007112C  7C A3 2B 78 */	mr r3, r5
/* 80071130  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80071134  54 05 00 84 */	rlwinm r5, r0, 0, 2, 2
/* 80071138  54 00 00 42 */	rlwinm r0, r0, 0, 1, 1
/* 8007113C  7C A5 00 34 */	cntlzw r5, r5
/* 80071140  7C 00 00 34 */	cntlzw r0, r0
/* 80071144  54 A5 D9 7E */	srwi r5, r5, 5
/* 80071148  54 06 D9 7E */	srwi r6, r0, 5
/* 8007114C  7D 89 03 A6 */	mtctr r12
/* 80071150  4E 80 04 20 */	bctr 
/* 80071154  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80071158  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007115C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80071160  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80071164  7C 08 02 A6 */	mflr r0
/* 80071168  90 01 00 34 */	stw r0, 0x34(r1)
/* 8007116C  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80071170  7C BF 2B 78 */	mr r31, r5
/* 80071174  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80071178  7C 9E 23 78 */	mr r30, r4
/* 8007117C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80071180  7C 7D 1B 78 */	mr r29, r3
/* 80071184  88 E3 01 01 */	lbz r7, 0x101(r3)
/* 80071188  88 C3 01 00 */	lbz r6, 0x100(r3)
/* 8007118C  38 87 00 01 */	addi r4, r7, 1
/* 80071190  80 E3 00 D4 */	lwz r7, 0xd4(r3)
/* 80071194  7C 04 33 D6 */	divw r0, r4, r6
/* 80071198  2C 07 00 00 */	cmpwi r7, 0
/* 8007119C  7C 00 31 D6 */	mullw r0, r0, r6
/* 800711A0  7C 00 20 50 */	subf r0, r0, r4
/* 800711A4  98 03 01 01 */	stb r0, 0x101(r3)
/* 800711A8  41 82 00 40 */	beq 0x40
/* 800711AC  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 800711B0  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 800711B4  41 82 00 34 */	beq 0x34
/* 800711B8  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 800711BC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 800711C0  41 82 00 28 */	beq 0x28
/* 800711C4  81 87 00 00 */	lwz r12, 0(r7)
/* 800711C8  7C E3 3B 78 */	mr r3, r7
/* 800711CC  7F A5 EB 78 */	mr r5, r29
/* 800711D0  7F C6 F3 78 */	mr r6, r30
/* 800711D4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800711D8  7F E7 FB 78 */	mr r7, r31
/* 800711DC  38 80 00 01 */	li r4, 1
/* 800711E0  7D 89 03 A6 */	mtctr r12
/* 800711E4  4E 80 04 21 */	bctrl 
/* 800711E8  7F A3 EB 78 */	mr r3, r29
/* 800711EC  7F E4 FB 78 */	mr r4, r31
/* 800711F0  4B FF C5 A1 */	bl -0x3a60
/* 800711F4  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 800711F8  2C 03 00 00 */	cmpwi r3, 0
/* 800711FC  41 82 00 3C */	beq 0x3c
/* 80071200  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80071204  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80071208  41 82 00 30 */	beq 0x30
/* 8007120C  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80071210  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80071214  41 82 00 24 */	beq 0x24
/* 80071218  81 83 00 00 */	lwz r12, 0(r3)
/* 8007121C  7F A5 EB 78 */	mr r5, r29
/* 80071220  7F C6 F3 78 */	mr r6, r30
/* 80071224  7F E7 FB 78 */	mr r7, r31
/* 80071228  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8007122C  38 80 00 02 */	li r4, 2
/* 80071230  7D 89 03 A6 */	mtctr r12
/* 80071234  4E 80 04 21 */	bctrl 
/* 80071238  48 04 06 39 */	bl 0x40638
/* 8007123C  2C 03 00 00 */	cmpwi r3, 0
/* 80071240  41 82 01 6C */	beq 0x16c
/* 80071244  80 1D 01 04 */	lwz r0, 0x104(r29)
/* 80071248  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8007124C  41 82 00 B8 */	beq 0xb8
/* 80071250  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071254  80 7D 00 EC */	lwz r3, 0xec(r29)
/* 80071258  1C 80 00 30 */	mulli r4, r0, 0x30
/* 8007125C  48 13 04 01 */	bl 0x130400
/* 80071260  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 80071264  2C 05 00 00 */	cmpwi r5, 0
/* 80071268  41 82 00 24 */	beq 0x24
/* 8007126C  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071270  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071274  1C 60 00 24 */	mulli r3, r0, 0x24
/* 80071278  38 03 00 1F */	addi r0, r3, 0x1f
/* 8007127C  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071280  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071284  7C 85 02 14 */	add r4, r5, r0
/* 80071288  48 00 00 08 */	b 0x8
/* 8007128C  38 80 00 00 */	li r4, 0
/* 80071290  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 80071294  2C 06 00 00 */	cmpwi r6, 0
/* 80071298  41 82 00 24 */	beq 0x24
/* 8007129C  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800712A0  88 BD 01 01 */	lbz r5, 0x101(r29)
/* 800712A4  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800712A8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800712AC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800712B0  7C 05 01 D6 */	mullw r0, r5, r0
/* 800712B4  7D 46 02 14 */	add r10, r6, r0
/* 800712B8  48 00 00 08 */	b 0x8
/* 800712BC  39 40 00 00 */	li r10, 0
/* 800712C0  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 800712C4  7F E8 FB 78 */	mr r8, r31
/* 800712C8  90 01 00 10 */	stw r0, 0x10(r1)
/* 800712CC  39 21 00 10 */	addi r9, r1, 0x10
/* 800712D0  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800712D4  89 7D 01 01 */	lbz r11, 0x101(r29)
/* 800712D8  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800712DC  81 9D 00 F4 */	lwz r12, 0xf4(r29)
/* 800712E0  80 BD 00 EC */	lwz r5, 0xec(r29)
/* 800712E4  80 DD 00 F0 */	lwz r6, 0xf0(r29)
/* 800712E8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800712EC  A0 FD 01 02 */	lhz r7, 0x102(r29)
/* 800712F0  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800712F4  7C 0B 01 D6 */	mullw r0, r11, r0
/* 800712F8  7C 6C 02 14 */	add r3, r12, r0
/* 800712FC  4B FF 5F 75 */	bl -0xa08c
/* 80071300  48 00 00 A4 */	b 0xa4
/* 80071304  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 80071308  2C 05 00 00 */	cmpwi r5, 0
/* 8007130C  41 82 00 24 */	beq 0x24
/* 80071310  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071314  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071318  1C 60 00 24 */	mulli r3, r0, 0x24
/* 8007131C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071320  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071324  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071328  7C 85 02 14 */	add r4, r5, r0
/* 8007132C  48 00 00 08 */	b 0x8
/* 80071330  38 80 00 00 */	li r4, 0
/* 80071334  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 80071338  2C 06 00 00 */	cmpwi r6, 0
/* 8007133C  41 82 00 24 */	beq 0x24
/* 80071340  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071344  88 BD 01 01 */	lbz r5, 0x101(r29)
/* 80071348  1C 60 00 30 */	mulli r3, r0, 0x30
/* 8007134C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071350  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071354  7C 05 01 D6 */	mullw r0, r5, r0
/* 80071358  7D 46 02 14 */	add r10, r6, r0
/* 8007135C  48 00 00 08 */	b 0x8
/* 80071360  39 40 00 00 */	li r10, 0
/* 80071364  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071368  7F E8 FB 78 */	mr r8, r31
/* 8007136C  90 01 00 0C */	stw r0, 0xc(r1)
/* 80071370  39 21 00 0C */	addi r9, r1, 0xc
/* 80071374  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071378  89 7D 01 01 */	lbz r11, 0x101(r29)
/* 8007137C  1C 60 00 30 */	mulli r3, r0, 0x30
/* 80071380  81 9D 00 F4 */	lwz r12, 0xf4(r29)
/* 80071384  80 BD 00 EC */	lwz r5, 0xec(r29)
/* 80071388  80 DD 00 F0 */	lwz r6, 0xf0(r29)
/* 8007138C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071390  A0 FD 01 02 */	lhz r7, 0x102(r29)
/* 80071394  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071398  7C 0B 01 D6 */	mullw r0, r11, r0
/* 8007139C  7C 6C 02 14 */	add r3, r12, r0
/* 800713A0  4B FF 5A 31 */	bl -0xa5d0
/* 800713A4  48 04 05 3D */	bl 0x4053c
/* 800713A8  48 00 00 A4 */	b 0xa4
/* 800713AC  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 800713B0  2C 05 00 00 */	cmpwi r5, 0
/* 800713B4  41 82 00 24 */	beq 0x24
/* 800713B8  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800713BC  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 800713C0  1C 60 00 24 */	mulli r3, r0, 0x24
/* 800713C4  38 03 00 1F */	addi r0, r3, 0x1f
/* 800713C8  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800713CC  7C 04 01 D6 */	mullw r0, r4, r0
/* 800713D0  7C 85 02 14 */	add r4, r5, r0
/* 800713D4  48 00 00 08 */	b 0x8
/* 800713D8  38 80 00 00 */	li r4, 0
/* 800713DC  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 800713E0  2C 06 00 00 */	cmpwi r6, 0
/* 800713E4  41 82 00 24 */	beq 0x24
/* 800713E8  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800713EC  88 BD 01 01 */	lbz r5, 0x101(r29)
/* 800713F0  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800713F4  38 03 00 1F */	addi r0, r3, 0x1f
/* 800713F8  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800713FC  7C 05 01 D6 */	mullw r0, r5, r0
/* 80071400  7D 46 02 14 */	add r10, r6, r0
/* 80071404  48 00 00 08 */	b 0x8
/* 80071408  39 40 00 00 */	li r10, 0
/* 8007140C  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071410  7F E8 FB 78 */	mr r8, r31
/* 80071414  90 01 00 08 */	stw r0, 8(r1)
/* 80071418  39 21 00 08 */	addi r9, r1, 8
/* 8007141C  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071420  89 7D 01 01 */	lbz r11, 0x101(r29)
/* 80071424  1C 60 00 30 */	mulli r3, r0, 0x30
/* 80071428  81 9D 00 F4 */	lwz r12, 0xf4(r29)
/* 8007142C  80 BD 00 EC */	lwz r5, 0xec(r29)
/* 80071430  80 DD 00 F0 */	lwz r6, 0xf0(r29)
/* 80071434  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071438  A0 FD 01 02 */	lhz r7, 0x102(r29)
/* 8007143C  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071440  7C 0B 01 D6 */	mullw r0, r11, r0
/* 80071444  7C 6C 02 14 */	add r3, r12, r0
/* 80071448  4B FF 56 59 */	bl -0xa9a8
/* 8007144C  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80071450  2C 03 00 00 */	cmpwi r3, 0
/* 80071454  41 82 00 3C */	beq 0x3c
/* 80071458  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 8007145C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80071460  41 82 00 30 */	beq 0x30
/* 80071464  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80071468  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8007146C  41 82 00 24 */	beq 0x24
/* 80071470  81 83 00 00 */	lwz r12, 0(r3)
/* 80071474  7F A5 EB 78 */	mr r5, r29
/* 80071478  7F C6 F3 78 */	mr r6, r30
/* 8007147C  7F E7 FB 78 */	mr r7, r31
/* 80071480  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80071484  38 80 00 04 */	li r4, 4
/* 80071488  7D 89 03 A6 */	mtctr r12
/* 8007148C  4E 80 04 21 */	bctrl 
/* 80071490  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80071494  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80071498  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8007149C  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800714A0  7C 08 03 A6 */	mtlr r0
/* 800714A4  38 21 00 30 */	addi r1, r1, 0x30
/* 800714A8  4E 80 00 20 */	blr 
/* 800714AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800714B0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800714B4  7C 08 02 A6 */	mflr r0
/* 800714B8  28 04 00 09 */	cmplwi r4, 9
/* 800714BC  90 01 00 44 */	stw r0, 0x44(r1)
/* 800714C0  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 800714C4  7C DF 33 78 */	mr r31, r6
/* 800714C8  93 C1 00 38 */	stw r30, 0x38(r1)
/* 800714CC  7C BE 2B 78 */	mr r30, r5
/* 800714D0  93 A1 00 34 */	stw r29, 0x34(r1)
/* 800714D4  7C 7D 1B 78 */	mr r29, r3
/* 800714D8  40 80 00 24 */	bge 0x24
/* 800714DC  38 A4 FF FF */	addi r5, r4, -1
/* 800714E0  38 C0 00 01 */	li r6, 1
/* 800714E4  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 800714E8  7C C5 28 30 */	slw r5, r6, r5
/* 800714EC  7C A0 00 39 */	and. r0, r5, r0
/* 800714F0  41 82 00 0C */	beq 0xc
/* 800714F4  38 00 00 01 */	li r0, 1
/* 800714F8  48 00 00 08 */	b 0x8
/* 800714FC  38 00 00 00 */	li r0, 0
/* 80071500  2C 00 00 00 */	cmpwi r0, 0
/* 80071504  40 82 08 20 */	bne 0x820
/* 80071508  2C 04 00 06 */	cmpwi r4, 6
/* 8007150C  41 82 04 DC */	beq 0x4dc
/* 80071510  40 80 00 2C */	bge 0x2c
/* 80071514  2C 04 00 03 */	cmpwi r4, 3
/* 80071518  41 82 07 FC */	beq 0x7fc
/* 8007151C  40 80 00 14 */	bge 0x14
/* 80071520  2C 04 00 01 */	cmpwi r4, 1
/* 80071524  41 82 00 74 */	beq 0x74
/* 80071528  40 80 00 E4 */	bge 0xe4
/* 8007152C  48 00 07 E8 */	b 0x7e8
/* 80071530  2C 04 00 05 */	cmpwi r4, 5
/* 80071534  40 80 00 2C */	bge 0x2c
/* 80071538  48 00 01 A0 */	b 0x1a0
/* 8007153C  3C A0 00 01 */	lis r5, 1
/* 80071540  38 05 00 01 */	addi r0, r5, 1
/* 80071544  7C 04 00 00 */	cmpw r4, r0
/* 80071548  41 82 07 B0 */	beq 0x7b0
/* 8007154C  40 80 07 C8 */	bge 0x7c8
/* 80071550  2C 04 00 08 */	cmpwi r4, 8
/* 80071554  41 82 07 14 */	beq 0x714
/* 80071558  40 80 07 BC */	bge 0x7bc
/* 8007155C  48 00 05 CC */	b 0x5cc
/* 80071560  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80071564  7F E3 FB 78 */	mr r3, r31
/* 80071568  81 9F 00 00 */	lwz r12, 0(r31)
/* 8007156C  7F A4 EB 78 */	mr r4, r29
/* 80071570  54 05 00 84 */	rlwinm r5, r0, 0, 2, 2
/* 80071574  54 00 00 42 */	rlwinm r0, r0, 0, 1, 1
/* 80071578  7C A5 00 34 */	cntlzw r5, r5
/* 8007157C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80071580  7C 00 00 34 */	cntlzw r0, r0
/* 80071584  54 A5 D9 7E */	srwi r5, r5, 5
/* 80071588  54 06 D9 7E */	srwi r6, r0, 5
/* 8007158C  7D 89 03 A6 */	mtctr r12
/* 80071590  4E 80 04 21 */	bctrl 
/* 80071594  48 00 07 90 */	b 0x790
/* 80071598  7F A3 EB 78 */	mr r3, r29
/* 8007159C  7F C4 F3 78 */	mr r4, r30
/* 800715A0  7F E5 FB 78 */	mr r5, r31
/* 800715A4  4B FF F9 1D */	bl -0x6e4
/* 800715A8  80 9D 01 28 */	lwz r4, 0x128(r29)
/* 800715AC  2C 04 00 00 */	cmpwi r4, 0
/* 800715B0  41 82 00 14 */	beq 0x14
/* 800715B4  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 800715B8  38 61 00 20 */	addi r3, r1, 0x20
/* 800715BC  90 01 00 20 */	stw r0, 0x20(r1)
/* 800715C0  4B FE 59 51 */	bl -0x1a6b0
/* 800715C4  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 800715C8  2C 03 00 00 */	cmpwi r3, 0
/* 800715CC  41 82 07 58 */	beq 0x758
/* 800715D0  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 800715D4  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 800715D8  41 82 07 4C */	beq 0x74c
/* 800715DC  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 800715E0  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 800715E4  41 82 07 40 */	beq 0x740
/* 800715E8  81 83 00 00 */	lwz r12, 0(r3)
/* 800715EC  7F A5 EB 78 */	mr r5, r29
/* 800715F0  7F C6 F3 78 */	mr r6, r30
/* 800715F4  7F E7 FB 78 */	mr r7, r31
/* 800715F8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800715FC  38 80 00 04 */	li r4, 4
/* 80071600  7D 89 03 A6 */	mtctr r12
/* 80071604  4E 80 04 21 */	bctrl 
/* 80071608  48 00 07 1C */	b 0x71c
/* 8007160C  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 80071610  2C 04 00 00 */	cmpwi r4, 0
/* 80071614  41 82 00 40 */	beq 0x40
/* 80071618  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8007161C  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80071620  41 82 00 34 */	beq 0x34
/* 80071624  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80071628  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8007162C  41 82 00 28 */	beq 0x28
/* 80071630  81 84 00 00 */	lwz r12, 0(r4)
/* 80071634  7C 83 23 78 */	mr r3, r4
/* 80071638  7F A5 EB 78 */	mr r5, r29
/* 8007163C  7F C6 F3 78 */	mr r6, r30
/* 80071640  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80071644  7F E7 FB 78 */	mr r7, r31
/* 80071648  38 80 00 01 */	li r4, 1
/* 8007164C  7D 89 03 A6 */	mtctr r12
/* 80071650  4E 80 04 21 */	bctrl 
/* 80071654  80 9D 01 30 */	lwz r4, 0x130(r29)
/* 80071658  2C 04 00 00 */	cmpwi r4, 0
/* 8007165C  40 82 00 1C */	bne 0x1c
/* 80071660  80 1D 01 34 */	lwz r0, 0x134(r29)
/* 80071664  2C 00 00 00 */	cmpwi r0, 0
/* 80071668  40 82 00 10 */	bne 0x10
/* 8007166C  80 1D 01 2C */	lwz r0, 0x12c(r29)
/* 80071670  2C 00 00 00 */	cmpwi r0, 0
/* 80071674  41 82 00 1C */	beq 0x1c
/* 80071678  80 DD 01 2C */	lwz r6, 0x12c(r29)
/* 8007167C  38 61 00 1C */	addi r3, r1, 0x1c
/* 80071680  80 BD 01 34 */	lwz r5, 0x134(r29)
/* 80071684  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071688  90 01 00 1C */	stw r0, 0x1c(r1)
/* 8007168C  48 00 56 35 */	bl 0x5634
/* 80071690  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80071694  2C 03 00 00 */	cmpwi r3, 0
/* 80071698  41 82 06 8C */	beq 0x68c
/* 8007169C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 800716A0  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 800716A4  41 82 06 80 */	beq 0x680
/* 800716A8  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 800716AC  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 800716B0  41 82 06 74 */	beq 0x674
/* 800716B4  81 83 00 00 */	lwz r12, 0(r3)
/* 800716B8  7F A5 EB 78 */	mr r5, r29
/* 800716BC  7F C6 F3 78 */	mr r6, r30
/* 800716C0  7F E7 FB 78 */	mr r7, r31
/* 800716C4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 800716C8  38 80 00 04 */	li r4, 4
/* 800716CC  7D 89 03 A6 */	mtctr r12
/* 800716D0  4E 80 04 21 */	bctrl 
/* 800716D4  48 00 06 50 */	b 0x650
/* 800716D8  88 A3 01 01 */	lbz r5, 0x101(r3)
/* 800716DC  88 83 01 00 */	lbz r4, 0x100(r3)
/* 800716E0  38 A5 00 01 */	addi r5, r5, 1
/* 800716E4  80 C3 00 D4 */	lwz r6, 0xd4(r3)
/* 800716E8  7C 05 23 D6 */	divw r0, r5, r4
/* 800716EC  2C 06 00 00 */	cmpwi r6, 0
/* 800716F0  7C 00 21 D6 */	mullw r0, r0, r4
/* 800716F4  7C 00 28 50 */	subf r0, r0, r5
/* 800716F8  98 03 01 01 */	stb r0, 0x101(r3)
/* 800716FC  41 82 00 40 */	beq 0x40
/* 80071700  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80071704  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80071708  41 82 00 34 */	beq 0x34
/* 8007170C  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80071710  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80071714  41 82 00 28 */	beq 0x28
/* 80071718  81 86 00 00 */	lwz r12, 0(r6)
/* 8007171C  7C C3 33 78 */	mr r3, r6
/* 80071720  7F A5 EB 78 */	mr r5, r29
/* 80071724  7F C6 F3 78 */	mr r6, r30
/* 80071728  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8007172C  7F E7 FB 78 */	mr r7, r31
/* 80071730  38 80 00 01 */	li r4, 1
/* 80071734  7D 89 03 A6 */	mtctr r12
/* 80071738  4E 80 04 21 */	bctrl 
/* 8007173C  7F A3 EB 78 */	mr r3, r29
/* 80071740  7F E4 FB 78 */	mr r4, r31
/* 80071744  4B FF C0 4D */	bl -0x3fb4
/* 80071748  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 8007174C  2C 03 00 00 */	cmpwi r3, 0
/* 80071750  41 82 00 3C */	beq 0x3c
/* 80071754  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80071758  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8007175C  41 82 00 30 */	beq 0x30
/* 80071760  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80071764  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80071768  41 82 00 24 */	beq 0x24
/* 8007176C  81 83 00 00 */	lwz r12, 0(r3)
/* 80071770  7F A5 EB 78 */	mr r5, r29
/* 80071774  7F C6 F3 78 */	mr r6, r30
/* 80071778  7F E7 FB 78 */	mr r7, r31
/* 8007177C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80071780  38 80 00 02 */	li r4, 2
/* 80071784  7D 89 03 A6 */	mtctr r12
/* 80071788  4E 80 04 21 */	bctrl 
/* 8007178C  48 04 00 E5 */	bl 0x400e4
/* 80071790  2C 03 00 00 */	cmpwi r3, 0
/* 80071794  41 82 01 6C */	beq 0x16c
/* 80071798  80 1D 01 04 */	lwz r0, 0x104(r29)
/* 8007179C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 800717A0  41 82 00 B8 */	beq 0xb8
/* 800717A4  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800717A8  80 7D 00 EC */	lwz r3, 0xec(r29)
/* 800717AC  1C 80 00 30 */	mulli r4, r0, 0x30
/* 800717B0  48 12 FE AD */	bl 0x12feac
/* 800717B4  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 800717B8  2C 05 00 00 */	cmpwi r5, 0
/* 800717BC  41 82 00 24 */	beq 0x24
/* 800717C0  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800717C4  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 800717C8  1C 60 00 24 */	mulli r3, r0, 0x24
/* 800717CC  38 03 00 1F */	addi r0, r3, 0x1f
/* 800717D0  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800717D4  7C 04 01 D6 */	mullw r0, r4, r0
/* 800717D8  7C 85 02 14 */	add r4, r5, r0
/* 800717DC  48 00 00 08 */	b 0x8
/* 800717E0  38 80 00 00 */	li r4, 0
/* 800717E4  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 800717E8  2C 06 00 00 */	cmpwi r6, 0
/* 800717EC  41 82 00 24 */	beq 0x24
/* 800717F0  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800717F4  88 BD 01 01 */	lbz r5, 0x101(r29)
/* 800717F8  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800717FC  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071800  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071804  7C 05 01 D6 */	mullw r0, r5, r0
/* 80071808  7D 46 02 14 */	add r10, r6, r0
/* 8007180C  48 00 00 08 */	b 0x8
/* 80071810  39 40 00 00 */	li r10, 0
/* 80071814  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071818  7F E8 FB 78 */	mr r8, r31
/* 8007181C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80071820  39 21 00 10 */	addi r9, r1, 0x10
/* 80071824  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071828  89 7D 01 01 */	lbz r11, 0x101(r29)
/* 8007182C  1C 60 00 30 */	mulli r3, r0, 0x30
/* 80071830  81 9D 00 F4 */	lwz r12, 0xf4(r29)
/* 80071834  80 BD 00 EC */	lwz r5, 0xec(r29)
/* 80071838  80 DD 00 F0 */	lwz r6, 0xf0(r29)
/* 8007183C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071840  A0 FD 01 02 */	lhz r7, 0x102(r29)
/* 80071844  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071848  7C 0B 01 D6 */	mullw r0, r11, r0
/* 8007184C  7C 6C 02 14 */	add r3, r12, r0
/* 80071850  4B FF 5A 21 */	bl -0xa5e0
/* 80071854  48 00 00 A4 */	b 0xa4
/* 80071858  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 8007185C  2C 05 00 00 */	cmpwi r5, 0
/* 80071860  41 82 00 24 */	beq 0x24
/* 80071864  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071868  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 8007186C  1C 60 00 24 */	mulli r3, r0, 0x24
/* 80071870  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071874  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071878  7C 04 01 D6 */	mullw r0, r4, r0
/* 8007187C  7C 85 02 14 */	add r4, r5, r0
/* 80071880  48 00 00 08 */	b 0x8
/* 80071884  38 80 00 00 */	li r4, 0
/* 80071888  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 8007188C  2C 06 00 00 */	cmpwi r6, 0
/* 80071890  41 82 00 24 */	beq 0x24
/* 80071894  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071898  88 BD 01 01 */	lbz r5, 0x101(r29)
/* 8007189C  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800718A0  38 03 00 1F */	addi r0, r3, 0x1f
/* 800718A4  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800718A8  7C 05 01 D6 */	mullw r0, r5, r0
/* 800718AC  7D 46 02 14 */	add r10, r6, r0
/* 800718B0  48 00 00 08 */	b 0x8
/* 800718B4  39 40 00 00 */	li r10, 0
/* 800718B8  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 800718BC  7F E8 FB 78 */	mr r8, r31
/* 800718C0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800718C4  39 21 00 14 */	addi r9, r1, 0x14
/* 800718C8  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 800718CC  89 7D 01 01 */	lbz r11, 0x101(r29)
/* 800718D0  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800718D4  81 9D 00 F4 */	lwz r12, 0xf4(r29)
/* 800718D8  80 BD 00 EC */	lwz r5, 0xec(r29)
/* 800718DC  80 DD 00 F0 */	lwz r6, 0xf0(r29)
/* 800718E0  38 03 00 1F */	addi r0, r3, 0x1f
/* 800718E4  A0 FD 01 02 */	lhz r7, 0x102(r29)
/* 800718E8  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800718EC  7C 0B 01 D6 */	mullw r0, r11, r0
/* 800718F0  7C 6C 02 14 */	add r3, r12, r0
/* 800718F4  4B FF 54 DD */	bl -0xab24
/* 800718F8  48 03 FF E9 */	bl 0x3ffe8
/* 800718FC  48 00 00 A4 */	b 0xa4
/* 80071900  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 80071904  2C 05 00 00 */	cmpwi r5, 0
/* 80071908  41 82 00 24 */	beq 0x24
/* 8007190C  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071910  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071914  1C 60 00 24 */	mulli r3, r0, 0x24
/* 80071918  38 03 00 1F */	addi r0, r3, 0x1f
/* 8007191C  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071920  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071924  7C 85 02 14 */	add r4, r5, r0
/* 80071928  48 00 00 08 */	b 0x8
/* 8007192C  38 80 00 00 */	li r4, 0
/* 80071930  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 80071934  2C 06 00 00 */	cmpwi r6, 0
/* 80071938  41 82 00 24 */	beq 0x24
/* 8007193C  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071940  88 BD 01 01 */	lbz r5, 0x101(r29)
/* 80071944  1C 60 00 30 */	mulli r3, r0, 0x30
/* 80071948  38 03 00 1F */	addi r0, r3, 0x1f
/* 8007194C  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071950  7C 05 01 D6 */	mullw r0, r5, r0
/* 80071954  7D 46 02 14 */	add r10, r6, r0
/* 80071958  48 00 00 08 */	b 0x8
/* 8007195C  39 40 00 00 */	li r10, 0
/* 80071960  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071964  7F E8 FB 78 */	mr r8, r31
/* 80071968  90 01 00 18 */	stw r0, 0x18(r1)
/* 8007196C  39 21 00 18 */	addi r9, r1, 0x18
/* 80071970  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071974  89 7D 01 01 */	lbz r11, 0x101(r29)
/* 80071978  1C 60 00 30 */	mulli r3, r0, 0x30
/* 8007197C  81 9D 00 F4 */	lwz r12, 0xf4(r29)
/* 80071980  80 BD 00 EC */	lwz r5, 0xec(r29)
/* 80071984  80 DD 00 F0 */	lwz r6, 0xf0(r29)
/* 80071988  38 03 00 1F */	addi r0, r3, 0x1f
/* 8007198C  A0 FD 01 02 */	lhz r7, 0x102(r29)
/* 80071990  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071994  7C 0B 01 D6 */	mullw r0, r11, r0
/* 80071998  7C 6C 02 14 */	add r3, r12, r0
/* 8007199C  4B FF 51 05 */	bl -0xaefc
/* 800719A0  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 800719A4  2C 03 00 00 */	cmpwi r3, 0
/* 800719A8  41 82 03 7C */	beq 0x37c
/* 800719AC  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 800719B0  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 800719B4  41 82 03 70 */	beq 0x370
/* 800719B8  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 800719BC  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 800719C0  41 82 03 64 */	beq 0x364
/* 800719C4  81 83 00 00 */	lwz r12, 0(r3)
/* 800719C8  7F A5 EB 78 */	mr r5, r29
/* 800719CC  7F C6 F3 78 */	mr r6, r30
/* 800719D0  7F E7 FB 78 */	mr r7, r31
/* 800719D4  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800719D8  38 80 00 04 */	li r4, 4
/* 800719DC  7D 89 03 A6 */	mtctr r12
/* 800719E0  4E 80 04 21 */	bctrl 
/* 800719E4  48 00 03 40 */	b 0x340
/* 800719E8  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 800719EC  2C 04 00 00 */	cmpwi r4, 0
/* 800719F0  41 82 00 40 */	beq 0x40
/* 800719F4  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 800719F8  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 800719FC  41 82 00 34 */	beq 0x34
/* 80071A00  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80071A04  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80071A08  41 82 00 28 */	beq 0x28
/* 80071A0C  81 84 00 00 */	lwz r12, 0(r4)
/* 80071A10  7C 83 23 78 */	mr r3, r4
/* 80071A14  7F A5 EB 78 */	mr r5, r29
/* 80071A18  7F C6 F3 78 */	mr r6, r30
/* 80071A1C  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80071A20  7F E7 FB 78 */	mr r7, r31
/* 80071A24  38 80 00 01 */	li r4, 1
/* 80071A28  7D 89 03 A6 */	mtctr r12
/* 80071A2C  4E 80 04 21 */	bctrl 
/* 80071A30  2C 1F 00 00 */	cmpwi r31, 0
/* 80071A34  41 82 00 0C */	beq 0xc
/* 80071A38  81 5F 00 00 */	lwz r10, 0(r31)
/* 80071A3C  48 00 00 08 */	b 0x8
/* 80071A40  81 5D 01 18 */	lwz r10, 0x118(r29)
/* 80071A44  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 80071A48  2C 05 00 00 */	cmpwi r5, 0
/* 80071A4C  41 82 00 24 */	beq 0x24
/* 80071A50  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071A54  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071A58  1C 60 00 24 */	mulli r3, r0, 0x24
/* 80071A5C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071A60  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071A64  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071A68  7C A5 02 14 */	add r5, r5, r0
/* 80071A6C  48 00 00 08 */	b 0x8
/* 80071A70  38 A0 00 00 */	li r5, 0
/* 80071A74  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 80071A78  2C 06 00 00 */	cmpwi r6, 0
/* 80071A7C  41 82 00 24 */	beq 0x24
/* 80071A80  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071A84  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071A88  1C 60 00 30 */	mulli r3, r0, 0x30
/* 80071A8C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071A90  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071A94  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071A98  7C C6 02 14 */	add r6, r6, r0
/* 80071A9C  48 00 00 08 */	b 0x8
/* 80071AA0  38 C0 00 00 */	li r6, 0
/* 80071AA4  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071AA8  38 61 00 0C */	addi r3, r1, 0xc
/* 80071AAC  89 3D 01 01 */	lbz r9, 0x101(r29)
/* 80071AB0  39 00 00 00 */	li r8, 0
/* 80071AB4  1C 80 00 30 */	mulli r4, r0, 0x30
/* 80071AB8  80 FD 01 10 */	lwz r7, 0x110(r29)
/* 80071ABC  81 7D 00 F4 */	lwz r11, 0xf4(r29)
/* 80071AC0  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071AC4  38 84 00 1F */	addi r4, r4, 0x1f
/* 80071AC8  90 01 00 0C */	stw r0, 0xc(r1)
/* 80071ACC  54 80 00 34 */	rlwinm r0, r4, 0, 0, 0x1a
/* 80071AD0  7C 09 01 D6 */	mullw r0, r9, r0
/* 80071AD4  39 20 00 00 */	li r9, 0
/* 80071AD8  7C 8B 02 14 */	add r4, r11, r0
/* 80071ADC  4B FF 75 25 */	bl -0x8adc
/* 80071AE0  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80071AE4  2C 03 00 00 */	cmpwi r3, 0
/* 80071AE8  41 82 02 3C */	beq 0x23c
/* 80071AEC  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80071AF0  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 80071AF4  41 82 02 30 */	beq 0x230
/* 80071AF8  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80071AFC  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80071B00  41 82 02 24 */	beq 0x224
/* 80071B04  81 83 00 00 */	lwz r12, 0(r3)
/* 80071B08  7F A5 EB 78 */	mr r5, r29
/* 80071B0C  7F C6 F3 78 */	mr r6, r30
/* 80071B10  7F E7 FB 78 */	mr r7, r31
/* 80071B14  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80071B18  38 80 00 04 */	li r4, 4
/* 80071B1C  7D 89 03 A6 */	mtctr r12
/* 80071B20  4E 80 04 21 */	bctrl 
/* 80071B24  48 00 02 00 */	b 0x200
/* 80071B28  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 80071B2C  2C 04 00 00 */	cmpwi r4, 0
/* 80071B30  41 82 00 40 */	beq 0x40
/* 80071B34  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80071B38  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80071B3C  41 82 00 34 */	beq 0x34
/* 80071B40  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80071B44  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80071B48  41 82 00 28 */	beq 0x28
/* 80071B4C  81 84 00 00 */	lwz r12, 0(r4)
/* 80071B50  7C 83 23 78 */	mr r3, r4
/* 80071B54  7F A5 EB 78 */	mr r5, r29
/* 80071B58  7F C6 F3 78 */	mr r6, r30
/* 80071B5C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80071B60  7F E7 FB 78 */	mr r7, r31
/* 80071B64  38 80 00 01 */	li r4, 1
/* 80071B68  7D 89 03 A6 */	mtctr r12
/* 80071B6C  4E 80 04 21 */	bctrl 
/* 80071B70  2C 1F 00 00 */	cmpwi r31, 0
/* 80071B74  41 82 00 0C */	beq 0xc
/* 80071B78  81 5F 00 00 */	lwz r10, 0(r31)
/* 80071B7C  48 00 00 08 */	b 0x8
/* 80071B80  81 5D 01 18 */	lwz r10, 0x118(r29)
/* 80071B84  80 BD 00 F8 */	lwz r5, 0xf8(r29)
/* 80071B88  2C 05 00 00 */	cmpwi r5, 0
/* 80071B8C  41 82 00 24 */	beq 0x24
/* 80071B90  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071B94  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071B98  1C 60 00 24 */	mulli r3, r0, 0x24
/* 80071B9C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071BA0  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071BA4  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071BA8  7C A5 02 14 */	add r5, r5, r0
/* 80071BAC  48 00 00 08 */	b 0x8
/* 80071BB0  38 A0 00 00 */	li r5, 0
/* 80071BB4  80 DD 00 FC */	lwz r6, 0xfc(r29)
/* 80071BB8  2C 06 00 00 */	cmpwi r6, 0
/* 80071BBC  41 82 00 24 */	beq 0x24
/* 80071BC0  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071BC4  88 9D 01 01 */	lbz r4, 0x101(r29)
/* 80071BC8  1C 60 00 30 */	mulli r3, r0, 0x30
/* 80071BCC  38 03 00 1F */	addi r0, r3, 0x1f
/* 80071BD0  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071BD4  7C 04 01 D6 */	mullw r0, r4, r0
/* 80071BD8  7C C6 02 14 */	add r6, r6, r0
/* 80071BDC  48 00 00 08 */	b 0x8
/* 80071BE0  38 C0 00 00 */	li r6, 0
/* 80071BE4  A0 1D 01 02 */	lhz r0, 0x102(r29)
/* 80071BE8  38 61 00 08 */	addi r3, r1, 8
/* 80071BEC  89 3D 01 01 */	lbz r9, 0x101(r29)
/* 80071BF0  38 E0 00 00 */	li r7, 0
/* 80071BF4  1C 80 00 30 */	mulli r4, r0, 0x30
/* 80071BF8  81 1D 01 14 */	lwz r8, 0x114(r29)
/* 80071BFC  81 7D 00 F4 */	lwz r11, 0xf4(r29)
/* 80071C00  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80071C04  38 84 00 1F */	addi r4, r4, 0x1f
/* 80071C08  90 01 00 08 */	stw r0, 8(r1)
/* 80071C0C  54 80 00 34 */	rlwinm r0, r4, 0, 0, 0x1a
/* 80071C10  7C 09 01 D6 */	mullw r0, r9, r0
/* 80071C14  39 20 00 00 */	li r9, 0
/* 80071C18  7C 8B 02 14 */	add r4, r11, r0
/* 80071C1C  4B FF 73 E5 */	bl -0x8c1c
/* 80071C20  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80071C24  2C 03 00 00 */	cmpwi r3, 0
/* 80071C28  41 82 00 FC */	beq 0xfc
/* 80071C2C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80071C30  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80071C34  41 82 00 F0 */	beq 0xf0
/* 80071C38  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80071C3C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80071C40  41 82 00 E4 */	beq 0xe4
/* 80071C44  81 83 00 00 */	lwz r12, 0(r3)
/* 80071C48  7F A5 EB 78 */	mr r5, r29
/* 80071C4C  7F C6 F3 78 */	mr r6, r30
/* 80071C50  7F E7 FB 78 */	mr r7, r31
/* 80071C54  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80071C58  38 80 00 04 */	li r4, 4
/* 80071C5C  7D 89 03 A6 */	mtctr r12
/* 80071C60  4E 80 04 21 */	bctrl 
/* 80071C64  48 00 00 C0 */	b 0xc0
/* 80071C68  80 63 01 24 */	lwz r3, 0x124(r3)
/* 80071C6C  2C 03 00 00 */	cmpwi r3, 0
/* 80071C70  41 82 00 14 */	beq 0x14
/* 80071C74  81 83 00 00 */	lwz r12, 0(r3)
/* 80071C78  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80071C7C  7D 89 03 A6 */	mtctr r12
/* 80071C80  4E 80 04 21 */	bctrl 
/* 80071C84  80 7D 01 28 */	lwz r3, 0x128(r29)
/* 80071C88  2C 03 00 00 */	cmpwi r3, 0
/* 80071C8C  41 82 00 14 */	beq 0x14
/* 80071C90  81 83 00 00 */	lwz r12, 0(r3)
/* 80071C94  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80071C98  7D 89 03 A6 */	mtctr r12
/* 80071C9C  4E 80 04 21 */	bctrl 
/* 80071CA0  80 7D 01 2C */	lwz r3, 0x12c(r29)
/* 80071CA4  2C 03 00 00 */	cmpwi r3, 0
/* 80071CA8  41 82 00 14 */	beq 0x14
/* 80071CAC  81 83 00 00 */	lwz r12, 0(r3)
/* 80071CB0  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80071CB4  7D 89 03 A6 */	mtctr r12
/* 80071CB8  4E 80 04 21 */	bctrl 
/* 80071CBC  80 7D 01 30 */	lwz r3, 0x130(r29)
/* 80071CC0  2C 03 00 00 */	cmpwi r3, 0
/* 80071CC4  41 82 00 14 */	beq 0x14
/* 80071CC8  81 83 00 00 */	lwz r12, 0(r3)
/* 80071CCC  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80071CD0  7D 89 03 A6 */	mtctr r12
/* 80071CD4  4E 80 04 21 */	bctrl 
/* 80071CD8  80 7D 01 34 */	lwz r3, 0x134(r29)
/* 80071CDC  2C 03 00 00 */	cmpwi r3, 0
/* 80071CE0  41 82 00 44 */	beq 0x44
/* 80071CE4  81 83 00 00 */	lwz r12, 0(r3)
/* 80071CE8  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80071CEC  7D 89 03 A6 */	mtctr r12
/* 80071CF0  4E 80 04 21 */	bctrl 
/* 80071CF4  48 00 00 30 */	b 0x30
/* 80071CF8  81 9D 00 00 */	lwz r12, 0(r29)
/* 80071CFC  7F A3 EB 78 */	mr r3, r29
/* 80071D00  7F E4 FB 78 */	mr r4, r31
/* 80071D04  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80071D08  7D 89 03 A6 */	mtctr r12
/* 80071D0C  4E 80 04 21 */	bctrl 
/* 80071D10  48 00 00 14 */	b 0x14
/* 80071D14  7F A3 EB 78 */	mr r3, r29
/* 80071D18  7F C5 F3 78 */	mr r5, r30
/* 80071D1C  7F E6 FB 78 */	mr r6, r31
/* 80071D20  4B FF C3 91 */	bl -0x3c70
/* 80071D24  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80071D28  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 80071D2C  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 80071D30  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 80071D34  7C 08 03 A6 */	mtlr r0
/* 80071D38  38 21 00 40 */	addi r1, r1, 0x40
/* 80071D3C  4E 80 00 20 */	blr 
/* 80071D40  3C 04 FF FE */	addis r0, r4, 0xfffe
/* 80071D44  28 00 00 01 */	cmplwi r0, 1
/* 80071D48  40 82 00 2C */	bne 0x2c
/* 80071D4C  2C 05 00 00 */	cmpwi r5, 0
/* 80071D50  41 82 00 14 */	beq 0x14
/* 80071D54  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80071D58  60 00 01 00 */	ori r0, r0, 0x100
/* 80071D5C  90 03 00 CC */	stw r0, 0xcc(r3)
/* 80071D60  48 00 00 18 */	b 0x18
/* 80071D64  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80071D68  54 00 06 2C */	rlwinm r0, r0, 0, 0x18, 0x16
/* 80071D6C  90 03 00 CC */	stw r0, 0xcc(r3)
/* 80071D70  48 00 00 08 */	b 0x8
/* 80071D74  4B FF C1 6C */	b -0x3e94
/* 80071D78  38 60 00 01 */	li r3, 1
/* 80071D7C  4E 80 00 20 */	blr 
/* 80071D80  2C 05 00 00 */	cmpwi r5, 0
/* 80071D84  40 82 00 0C */	bne 0xc
/* 80071D88  38 60 00 00 */	li r3, 0
/* 80071D8C  4E 80 00 20 */	blr 
/* 80071D90  3C 04 FF FE */	addis r0, r4, 0xfffe
/* 80071D94  28 00 00 01 */	cmplwi r0, 1
/* 80071D98  40 82 00 14 */	bne 0x14
/* 80071D9C  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80071DA0  54 00 C7 FE */	rlwinm r0, r0, 0x18, 0x1f, 0x1f
/* 80071DA4  90 05 00 00 */	stw r0, 0(r5)
/* 80071DA8  48 00 00 08 */	b 0x8
/* 80071DAC  4B FF C1 74 */	b -0x3e8c
/* 80071DB0  38 60 00 01 */	li r3, 1
/* 80071DB4  4E 80 00 20 */	blr 
/* 80071DB8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80071DBC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80071DC0  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 80071DC4  7C 08 02 A6 */	mflr r0
/* 80071DC8  2C 04 00 00 */	cmpwi r4, 0
/* 80071DCC  90 01 00 84 */	stw r0, 0x84(r1)
/* 80071DD0  93 E1 00 7C */	stw r31, 0x7c(r1)
/* 80071DD4  7C BF 2B 78 */	mr r31, r5
/* 80071DD8  93 C1 00 78 */	stw r30, 0x78(r1)
/* 80071DDC  93 A1 00 74 */	stw r29, 0x74(r1)
/* 80071DE0  7C 9D 23 78 */	mr r29, r4
/* 80071DE4  93 81 00 70 */	stw r28, 0x70(r1)
/* 80071DE8  7C 7C 1B 78 */	mr r28, r3
/* 80071DEC  41 82 00 F0 */	beq 0xf0
/* 80071DF0  80 03 00 E8 */	lwz r0, 0xe8(r3)
/* 80071DF4  7C C4 33 78 */	mr r4, r6
/* 80071DF8  90 01 00 08 */	stw r0, 8(r1)
/* 80071DFC  38 61 00 08 */	addi r3, r1, 8
/* 80071E00  4B FD C5 A1 */	bl -0x23a60
/* 80071E04  2C 03 00 00 */	cmpwi r3, 0
/* 80071E08  41 82 00 D4 */	beq 0xd4
/* 80071E0C  41 82 00 0C */	beq 0xc
/* 80071E10  83 C3 00 10 */	lwz r30, 0x10(r3)
/* 80071E14  48 00 00 08 */	b 0x8
/* 80071E18  3B C0 00 00 */	li r30, 0
/* 80071E1C  2C 1F 00 01 */	cmpwi r31, 1
/* 80071E20  41 82 00 10 */	beq 0x10
/* 80071E24  2C 1F 00 02 */	cmpwi r31, 2
/* 80071E28  41 82 00 24 */	beq 0x24
/* 80071E2C  48 00 00 B0 */	b 0xb0
/* 80071E30  1C 1E 00 30 */	mulli r0, r30, 0x30
/* 80071E34  80 7C 00 EC */	lwz r3, 0xec(r28)
/* 80071E38  7F A4 EB 78 */	mr r4, r29
/* 80071E3C  7C 63 02 14 */	add r3, r3, r0
/* 80071E40  48 12 7E F1 */	bl 0x127ef0
/* 80071E44  38 60 00 01 */	li r3, 1
/* 80071E48  48 00 00 98 */	b 0x98
/* 80071E4C  80 7C 00 E8 */	lwz r3, 0xe8(r28)
/* 80071E50  80 03 00 68 */	lwz r0, 0x68(r3)
/* 80071E54  7C 1E 00 40 */	cmplw r30, r0
/* 80071E58  40 80 00 3C */	bge 0x3c
/* 80071E5C  A0 1C 01 02 */	lhz r0, 0x102(r28)
/* 80071E60  1C 7E 00 30 */	mulli r3, r30, 0x30
/* 80071E64  88 DC 01 01 */	lbz r6, 0x101(r28)
/* 80071E68  7F A4 EB 78 */	mr r4, r29
/* 80071E6C  80 FC 00 F4 */	lwz r7, 0xf4(r28)
/* 80071E70  1C A0 00 30 */	mulli r5, r0, 0x30
/* 80071E74  38 05 00 1F */	addi r0, r5, 0x1f
/* 80071E78  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80071E7C  7C 06 01 D6 */	mullw r0, r6, r0
/* 80071E80  7C 07 02 14 */	add r0, r7, r0
/* 80071E84  7C 63 02 14 */	add r3, r3, r0
/* 80071E88  48 12 7E A9 */	bl 0x127ea8
/* 80071E8C  38 60 00 01 */	li r3, 1
/* 80071E90  48 00 00 50 */	b 0x50
/* 80071E94  3B FC 00 6C */	addi r31, r28, 0x6c
/* 80071E98  38 7C 00 3C */	addi r3, r28, 0x3c
/* 80071E9C  38 81 00 40 */	addi r4, r1, 0x40
/* 80071EA0  48 12 81 29 */	bl 0x128128
/* 80071EA4  2C 03 00 00 */	cmpwi r3, 0
/* 80071EA8  41 82 00 34 */	beq 0x34
/* 80071EAC  7F E3 FB 78 */	mr r3, r31
/* 80071EB0  38 81 00 40 */	addi r4, r1, 0x40
/* 80071EB4  38 A1 00 10 */	addi r5, r1, 0x10
/* 80071EB8  48 12 7E AD */	bl 0x127eac
/* 80071EBC  1C 1E 00 30 */	mulli r0, r30, 0x30
/* 80071EC0  80 9C 00 EC */	lwz r4, 0xec(r28)
/* 80071EC4  7F A5 EB 78 */	mr r5, r29
/* 80071EC8  38 61 00 10 */	addi r3, r1, 0x10
/* 80071ECC  7C 84 02 14 */	add r4, r4, r0
/* 80071ED0  48 12 7E 95 */	bl 0x127e94
/* 80071ED4  38 60 00 01 */	li r3, 1
/* 80071ED8  48 00 00 08 */	b 0x8
/* 80071EDC  38 60 00 00 */	li r3, 0
/* 80071EE0  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80071EE4  83 E1 00 7C */	lwz r31, 0x7c(r1)
/* 80071EE8  83 C1 00 78 */	lwz r30, 0x78(r1)
/* 80071EEC  83 A1 00 74 */	lwz r29, 0x74(r1)
/* 80071EF0  83 81 00 70 */	lwz r28, 0x70(r1)
/* 80071EF4  7C 08 03 A6 */	mtlr r0
/* 80071EF8  38 21 00 80 */	addi r1, r1, 0x80
/* 80071EFC  4E 80 00 20 */	blr 
/* 80071F00  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80071F04  7C 08 02 A6 */	mflr r0
/* 80071F08  2C 04 00 00 */	cmpwi r4, 0
/* 80071F0C  90 01 00 44 */	stw r0, 0x44(r1)
/* 80071F10  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80071F14  7C 9F 23 78 */	mr r31, r4
/* 80071F18  93 C1 00 38 */	stw r30, 0x38(r1)
/* 80071F1C  7C 7E 1B 78 */	mr r30, r3
/* 80071F20  93 A1 00 34 */	stw r29, 0x34(r1)
/* 80071F24  41 82 00 10 */	beq 0x10
/* 80071F28  80 04 00 04 */	lwz r0, 4(r4)
/* 80071F2C  2C 80 00 00 */	cmpwi cr1, r0, 0
/* 80071F30  41 86 00 0C */	beq cr1, 0xc
/* 80071F34  38 60 00 00 */	li r3, 0
/* 80071F38  48 00 05 BC */	b 0x5bc
/* 80071F3C  2C 85 00 00 */	cmpwi cr1, r5, 0
/* 80071F40  41 86 00 30 */	beq cr1, 0x30
/* 80071F44  2C 85 00 01 */	cmpwi cr1, r5, 1
/* 80071F48  41 86 00 80 */	beq cr1, 0x80
/* 80071F4C  2C 85 00 02 */	cmpwi cr1, r5, 2
/* 80071F50  41 86 00 D0 */	beq cr1, 0xd0
/* 80071F54  2C 85 00 03 */	cmpwi cr1, r5, 3
/* 80071F58  41 86 01 20 */	beq cr1, 0x120
/* 80071F5C  2C 85 00 04 */	cmpwi cr1, r5, 4
/* 80071F60  41 86 01 70 */	beq cr1, 0x170
/* 80071F64  2C 85 00 06 */	cmpwi cr1, r5, 6
/* 80071F68  41 86 01 BC */	beq cr1, 0x1bc
/* 80071F6C  48 00 03 68 */	b 0x368
/* 80071F70  3B A0 00 00 */	li r29, 0
/* 80071F74  41 82 00 34 */	beq 0x34
/* 80071F78  3C 80 80 24 */	lis r4, 0x8024
/* 80071F7C  7F E3 FB 78 */	mr r3, r31
/* 80071F80  38 84 76 08 */	addi r4, r4, 0x7608
/* 80071F84  90 81 00 2C */	stw r4, 0x2c(r1)
/* 80071F88  38 81 00 2C */	addi r4, r1, 0x2c
/* 80071F8C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80071F90  81 8C 00 08 */	lwz r12, 8(r12)
/* 80071F94  7D 89 03 A6 */	mtctr r12
/* 80071F98  4E 80 04 21 */	bctrl 
/* 80071F9C  2C 03 00 00 */	cmpwi r3, 0
/* 80071FA0  41 82 00 08 */	beq 0x8
/* 80071FA4  3B A0 00 01 */	li r29, 1
/* 80071FA8  2C 1D 00 00 */	cmpwi r29, 0
/* 80071FAC  41 82 00 0C */	beq 0xc
/* 80071FB0  7F FD FB 78 */	mr r29, r31
/* 80071FB4  48 00 00 08 */	b 0x8
/* 80071FB8  3B A0 00 00 */	li r29, 0
/* 80071FBC  2C 1D 00 00 */	cmpwi r29, 0
/* 80071FC0  40 82 03 1C */	bne 0x31c
/* 80071FC4  48 00 03 10 */	b 0x310
/* 80071FC8  3B A0 00 00 */	li r29, 0
/* 80071FCC  41 82 00 34 */	beq 0x34
/* 80071FD0  3C 80 80 24 */	lis r4, 0x8024
/* 80071FD4  7F E3 FB 78 */	mr r3, r31
/* 80071FD8  38 84 74 C0 */	addi r4, r4, 0x74c0
/* 80071FDC  90 81 00 28 */	stw r4, 0x28(r1)
/* 80071FE0  38 81 00 28 */	addi r4, r1, 0x28
/* 80071FE4  81 9F 00 00 */	lwz r12, 0(r31)
/* 80071FE8  81 8C 00 08 */	lwz r12, 8(r12)
/* 80071FEC  7D 89 03 A6 */	mtctr r12
/* 80071FF0  4E 80 04 21 */	bctrl 
/* 80071FF4  2C 03 00 00 */	cmpwi r3, 0
/* 80071FF8  41 82 00 08 */	beq 0x8
/* 80071FFC  3B A0 00 01 */	li r29, 1
/* 80072000  2C 1D 00 00 */	cmpwi r29, 0
/* 80072004  41 82 00 0C */	beq 0xc
/* 80072008  7F FD FB 78 */	mr r29, r31
/* 8007200C  48 00 00 08 */	b 0x8
/* 80072010  3B A0 00 00 */	li r29, 0
/* 80072014  2C 1D 00 00 */	cmpwi r29, 0
/* 80072018  40 82 03 30 */	bne 0x330
/* 8007201C  48 00 02 B8 */	b 0x2b8
/* 80072020  3B A0 00 00 */	li r29, 0
/* 80072024  41 82 00 34 */	beq 0x34
/* 80072028  3C 80 80 24 */	lis r4, 0x8024
/* 8007202C  7F E3 FB 78 */	mr r3, r31
/* 80072030  38 84 74 D0 */	addi r4, r4, 0x74d0
/* 80072034  90 81 00 24 */	stw r4, 0x24(r1)
/* 80072038  38 81 00 24 */	addi r4, r1, 0x24
/* 8007203C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072040  81 8C 00 08 */	lwz r12, 8(r12)
/* 80072044  7D 89 03 A6 */	mtctr r12
/* 80072048  4E 80 04 21 */	bctrl 
/* 8007204C  2C 03 00 00 */	cmpwi r3, 0
/* 80072050  41 82 00 08 */	beq 0x8
/* 80072054  3B A0 00 01 */	li r29, 1
/* 80072058  2C 1D 00 00 */	cmpwi r29, 0
/* 8007205C  41 82 00 0C */	beq 0xc
/* 80072060  7F FD FB 78 */	mr r29, r31
/* 80072064  48 00 00 08 */	b 0x8
/* 80072068  3B A0 00 00 */	li r29, 0
/* 8007206C  2C 1D 00 00 */	cmpwi r29, 0
/* 80072070  40 82 03 44 */	bne 0x344
/* 80072074  48 00 02 60 */	b 0x260
/* 80072078  3B A0 00 00 */	li r29, 0
/* 8007207C  41 82 00 34 */	beq 0x34
/* 80072080  3C 80 80 24 */	lis r4, 0x8024
/* 80072084  7F E3 FB 78 */	mr r3, r31
/* 80072088  38 84 75 38 */	addi r4, r4, 0x7538
/* 8007208C  90 81 00 20 */	stw r4, 0x20(r1)
/* 80072090  38 81 00 20 */	addi r4, r1, 0x20
/* 80072094  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072098  81 8C 00 08 */	lwz r12, 8(r12)
/* 8007209C  7D 89 03 A6 */	mtctr r12
/* 800720A0  4E 80 04 21 */	bctrl 
/* 800720A4  2C 03 00 00 */	cmpwi r3, 0
/* 800720A8  41 82 00 08 */	beq 0x8
/* 800720AC  3B A0 00 01 */	li r29, 1
/* 800720B0  2C 1D 00 00 */	cmpwi r29, 0
/* 800720B4  41 82 00 0C */	beq 0xc
/* 800720B8  7F FD FB 78 */	mr r29, r31
/* 800720BC  48 00 00 08 */	b 0x8
/* 800720C0  3B A0 00 00 */	li r29, 0
/* 800720C4  2C 1D 00 00 */	cmpwi r29, 0
/* 800720C8  40 82 03 58 */	bne 0x358
/* 800720CC  48 00 02 08 */	b 0x208
/* 800720D0  3B A0 00 00 */	li r29, 0
/* 800720D4  41 82 00 34 */	beq 0x34
/* 800720D8  3C 80 80 24 */	lis r4, 0x8024
/* 800720DC  7F E3 FB 78 */	mr r3, r31
/* 800720E0  38 84 75 A0 */	addi r4, r4, 0x75a0
/* 800720E4  90 81 00 1C */	stw r4, 0x1c(r1)
/* 800720E8  38 81 00 1C */	addi r4, r1, 0x1c
/* 800720EC  81 9F 00 00 */	lwz r12, 0(r31)
/* 800720F0  81 8C 00 08 */	lwz r12, 8(r12)
/* 800720F4  7D 89 03 A6 */	mtctr r12
/* 800720F8  4E 80 04 21 */	bctrl 
/* 800720FC  2C 03 00 00 */	cmpwi r3, 0
/* 80072100  41 82 00 08 */	beq 0x8
/* 80072104  3B A0 00 01 */	li r29, 1
/* 80072108  2C 1D 00 00 */	cmpwi r29, 0
/* 8007210C  41 82 00 08 */	beq 0x8
/* 80072110  48 00 00 08 */	b 0x8
/* 80072114  3B E0 00 00 */	li r31, 0
/* 80072118  2C 1F 00 00 */	cmpwi r31, 0
/* 8007211C  40 82 03 70 */	bne 0x370
/* 80072120  48 00 01 B4 */	b 0x1b4
/* 80072124  3B A0 00 00 */	li r29, 0
/* 80072128  41 82 00 34 */	beq 0x34
/* 8007212C  3C 80 80 24 */	lis r4, 0x8024
/* 80072130  7F E3 FB 78 */	mr r3, r31
/* 80072134  38 84 76 08 */	addi r4, r4, 0x7608
/* 80072138  90 81 00 18 */	stw r4, 0x18(r1)
/* 8007213C  38 81 00 18 */	addi r4, r1, 0x18
/* 80072140  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072144  81 8C 00 08 */	lwz r12, 8(r12)
/* 80072148  7D 89 03 A6 */	mtctr r12
/* 8007214C  4E 80 04 21 */	bctrl 
/* 80072150  2C 03 00 00 */	cmpwi r3, 0
/* 80072154  41 82 00 08 */	beq 0x8
/* 80072158  3B A0 00 01 */	li r29, 1
/* 8007215C  2C 1D 00 00 */	cmpwi r29, 0
/* 80072160  41 82 00 0C */	beq 0xc
/* 80072164  7F FD FB 78 */	mr r29, r31
/* 80072168  48 00 00 08 */	b 0x8
/* 8007216C  3B A0 00 00 */	li r29, 0
/* 80072170  2C 1D 00 00 */	cmpwi r29, 0
/* 80072174  40 82 01 68 */	bne 0x168
/* 80072178  2C 1F 00 00 */	cmpwi r31, 0
/* 8007217C  3B A0 00 00 */	li r29, 0
/* 80072180  41 82 00 34 */	beq 0x34
/* 80072184  3C 80 80 24 */	lis r4, 0x8024
/* 80072188  7F E3 FB 78 */	mr r3, r31
/* 8007218C  38 84 74 C0 */	addi r4, r4, 0x74c0
/* 80072190  90 81 00 14 */	stw r4, 0x14(r1)
/* 80072194  38 81 00 14 */	addi r4, r1, 0x14
/* 80072198  81 9F 00 00 */	lwz r12, 0(r31)
/* 8007219C  81 8C 00 08 */	lwz r12, 8(r12)
/* 800721A0  7D 89 03 A6 */	mtctr r12
/* 800721A4  4E 80 04 21 */	bctrl 
/* 800721A8  2C 03 00 00 */	cmpwi r3, 0
/* 800721AC  41 82 00 08 */	beq 0x8
/* 800721B0  3B A0 00 01 */	li r29, 1
/* 800721B4  2C 1D 00 00 */	cmpwi r29, 0
/* 800721B8  41 82 00 0C */	beq 0xc
/* 800721BC  7F FD FB 78 */	mr r29, r31
/* 800721C0  48 00 00 08 */	b 0x8
/* 800721C4  3B A0 00 00 */	li r29, 0
/* 800721C8  2C 1D 00 00 */	cmpwi r29, 0
/* 800721CC  40 82 01 7C */	bne 0x17c
/* 800721D0  2C 1F 00 00 */	cmpwi r31, 0
/* 800721D4  3B A0 00 00 */	li r29, 0
/* 800721D8  41 82 00 34 */	beq 0x34
/* 800721DC  3C 80 80 24 */	lis r4, 0x8024
/* 800721E0  7F E3 FB 78 */	mr r3, r31
/* 800721E4  38 84 74 D0 */	addi r4, r4, 0x74d0
/* 800721E8  90 81 00 10 */	stw r4, 0x10(r1)
/* 800721EC  38 81 00 10 */	addi r4, r1, 0x10
/* 800721F0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800721F4  81 8C 00 08 */	lwz r12, 8(r12)
/* 800721F8  7D 89 03 A6 */	mtctr r12
/* 800721FC  4E 80 04 21 */	bctrl 
/* 80072200  2C 03 00 00 */	cmpwi r3, 0
/* 80072204  41 82 00 08 */	beq 0x8
/* 80072208  3B A0 00 01 */	li r29, 1
/* 8007220C  2C 1D 00 00 */	cmpwi r29, 0
/* 80072210  41 82 00 0C */	beq 0xc
/* 80072214  7F FD FB 78 */	mr r29, r31
/* 80072218  48 00 00 08 */	b 0x8
/* 8007221C  3B A0 00 00 */	li r29, 0
/* 80072220  2C 1D 00 00 */	cmpwi r29, 0
/* 80072224  40 82 01 90 */	bne 0x190
/* 80072228  2C 1F 00 00 */	cmpwi r31, 0
/* 8007222C  3B A0 00 00 */	li r29, 0
/* 80072230  41 82 00 34 */	beq 0x34
/* 80072234  3C 80 80 24 */	lis r4, 0x8024
/* 80072238  7F E3 FB 78 */	mr r3, r31
/* 8007223C  38 84 75 38 */	addi r4, r4, 0x7538
/* 80072240  90 81 00 0C */	stw r4, 0xc(r1)
/* 80072244  38 81 00 0C */	addi r4, r1, 0xc
/* 80072248  81 9F 00 00 */	lwz r12, 0(r31)
/* 8007224C  81 8C 00 08 */	lwz r12, 8(r12)
/* 80072250  7D 89 03 A6 */	mtctr r12
/* 80072254  4E 80 04 21 */	bctrl 
/* 80072258  2C 03 00 00 */	cmpwi r3, 0
/* 8007225C  41 82 00 08 */	beq 0x8
/* 80072260  3B A0 00 01 */	li r29, 1
/* 80072264  2C 1D 00 00 */	cmpwi r29, 0
/* 80072268  41 82 00 0C */	beq 0xc
/* 8007226C  7F FD FB 78 */	mr r29, r31
/* 80072270  48 00 00 08 */	b 0x8
/* 80072274  3B A0 00 00 */	li r29, 0
/* 80072278  2C 1D 00 00 */	cmpwi r29, 0
/* 8007227C  40 82 01 A4 */	bne 0x1a4
/* 80072280  2C 1F 00 00 */	cmpwi r31, 0
/* 80072284  3B A0 00 00 */	li r29, 0
/* 80072288  41 82 00 34 */	beq 0x34
/* 8007228C  3C 80 80 24 */	lis r4, 0x8024
/* 80072290  7F E3 FB 78 */	mr r3, r31
/* 80072294  38 84 75 A0 */	addi r4, r4, 0x75a0
/* 80072298  90 81 00 08 */	stw r4, 8(r1)
/* 8007229C  38 81 00 08 */	addi r4, r1, 8
/* 800722A0  81 9F 00 00 */	lwz r12, 0(r31)
/* 800722A4  81 8C 00 08 */	lwz r12, 8(r12)
/* 800722A8  7D 89 03 A6 */	mtctr r12
/* 800722AC  4E 80 04 21 */	bctrl 
/* 800722B0  2C 03 00 00 */	cmpwi r3, 0
/* 800722B4  41 82 00 08 */	beq 0x8
/* 800722B8  3B A0 00 01 */	li r29, 1
/* 800722BC  2C 1D 00 00 */	cmpwi r29, 0
/* 800722C0  41 82 00 08 */	beq 0x8
/* 800722C4  48 00 00 08 */	b 0x8
/* 800722C8  3B E0 00 00 */	li r31, 0
/* 800722CC  2C 1F 00 00 */	cmpwi r31, 0
/* 800722D0  40 82 01 BC */	bne 0x1bc
/* 800722D4  38 60 00 00 */	li r3, 0
/* 800722D8  48 00 02 1C */	b 0x21c
/* 800722DC  7F A3 EB 78 */	mr r3, r29
/* 800722E0  38 80 00 04 */	li r4, 4
/* 800722E4  4B FE E2 BD */	bl -0x11d44
/* 800722E8  2C 03 00 00 */	cmpwi r3, 0
/* 800722EC  40 82 00 0C */	bne 0xc
/* 800722F0  38 60 00 00 */	li r3, 0
/* 800722F4  48 00 02 00 */	b 0x200
/* 800722F8  80 9E 01 24 */	lwz r4, 0x124(r30)
/* 800722FC  2C 04 00 00 */	cmpwi r4, 0
/* 80072300  41 82 00 18 */	beq 0x18
/* 80072304  81 9E 00 00 */	lwz r12, 0(r30)
/* 80072308  7F C3 F3 78 */	mr r3, r30
/* 8007230C  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072310  7D 89 03 A6 */	mtctr r12
/* 80072314  4E 80 04 21 */	bctrl 
/* 80072318  93 BE 01 24 */	stw r29, 0x124(r30)
/* 8007231C  3C 80 00 01 */	lis r4, 1
/* 80072320  7F A3 EB 78 */	mr r3, r29
/* 80072324  7F C6 F3 78 */	mr r6, r30
/* 80072328  81 9D 00 00 */	lwz r12, 0(r29)
/* 8007232C  38 84 00 02 */	addi r4, r4, 2
/* 80072330  38 A0 00 00 */	li r5, 0
/* 80072334  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80072338  7D 89 03 A6 */	mtctr r12
/* 8007233C  4E 80 04 21 */	bctrl 
/* 80072340  38 60 00 01 */	li r3, 1
/* 80072344  48 00 01 B0 */	b 0x1b0
/* 80072348  7F A3 EB 78 */	mr r3, r29
/* 8007234C  38 80 00 04 */	li r4, 4
/* 80072350  4B FE E2 51 */	bl -0x11db0
/* 80072354  2C 03 00 00 */	cmpwi r3, 0
/* 80072358  40 82 00 0C */	bne 0xc
/* 8007235C  38 60 00 00 */	li r3, 0
/* 80072360  48 00 01 94 */	b 0x194
/* 80072364  80 9E 01 28 */	lwz r4, 0x128(r30)
/* 80072368  2C 04 00 00 */	cmpwi r4, 0
/* 8007236C  41 82 00 18 */	beq 0x18
/* 80072370  81 9E 00 00 */	lwz r12, 0(r30)
/* 80072374  7F C3 F3 78 */	mr r3, r30
/* 80072378  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 8007237C  7D 89 03 A6 */	mtctr r12
/* 80072380  4E 80 04 21 */	bctrl 
/* 80072384  93 BE 01 28 */	stw r29, 0x128(r30)
/* 80072388  3C 80 00 01 */	lis r4, 1
/* 8007238C  7F A3 EB 78 */	mr r3, r29
/* 80072390  7F C6 F3 78 */	mr r6, r30
/* 80072394  81 9D 00 00 */	lwz r12, 0(r29)
/* 80072398  38 84 00 02 */	addi r4, r4, 2
/* 8007239C  38 A0 00 00 */	li r5, 0
/* 800723A0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800723A4  7D 89 03 A6 */	mtctr r12
/* 800723A8  4E 80 04 21 */	bctrl 
/* 800723AC  38 60 00 01 */	li r3, 1
/* 800723B0  48 00 01 44 */	b 0x144
/* 800723B4  7F A3 EB 78 */	mr r3, r29
/* 800723B8  38 80 00 04 */	li r4, 4
/* 800723BC  4B FE E1 E5 */	bl -0x11e1c
/* 800723C0  2C 03 00 00 */	cmpwi r3, 0
/* 800723C4  40 82 00 0C */	bne 0xc
/* 800723C8  38 60 00 00 */	li r3, 0
/* 800723CC  48 00 01 28 */	b 0x128
/* 800723D0  80 9E 01 2C */	lwz r4, 0x12c(r30)
/* 800723D4  2C 04 00 00 */	cmpwi r4, 0
/* 800723D8  41 82 00 18 */	beq 0x18
/* 800723DC  81 9E 00 00 */	lwz r12, 0(r30)
/* 800723E0  7F C3 F3 78 */	mr r3, r30
/* 800723E4  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800723E8  7D 89 03 A6 */	mtctr r12
/* 800723EC  4E 80 04 21 */	bctrl 
/* 800723F0  93 BE 01 2C */	stw r29, 0x12c(r30)
/* 800723F4  3C 80 00 01 */	lis r4, 1
/* 800723F8  7F A3 EB 78 */	mr r3, r29
/* 800723FC  7F C6 F3 78 */	mr r6, r30
/* 80072400  81 9D 00 00 */	lwz r12, 0(r29)
/* 80072404  38 84 00 02 */	addi r4, r4, 2
/* 80072408  38 A0 00 00 */	li r5, 0
/* 8007240C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80072410  7D 89 03 A6 */	mtctr r12
/* 80072414  4E 80 04 21 */	bctrl 
/* 80072418  38 60 00 01 */	li r3, 1
/* 8007241C  48 00 00 D8 */	b 0xd8
/* 80072420  7F A3 EB 78 */	mr r3, r29
/* 80072424  38 80 00 04 */	li r4, 4
/* 80072428  4B FE E1 79 */	bl -0x11e88
/* 8007242C  2C 03 00 00 */	cmpwi r3, 0
/* 80072430  40 82 00 0C */	bne 0xc
/* 80072434  38 60 00 00 */	li r3, 0
/* 80072438  48 00 00 BC */	b 0xbc
/* 8007243C  80 9E 01 30 */	lwz r4, 0x130(r30)
/* 80072440  2C 04 00 00 */	cmpwi r4, 0
/* 80072444  41 82 00 18 */	beq 0x18
/* 80072448  81 9E 00 00 */	lwz r12, 0(r30)
/* 8007244C  7F C3 F3 78 */	mr r3, r30
/* 80072450  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072454  7D 89 03 A6 */	mtctr r12
/* 80072458  4E 80 04 21 */	bctrl 
/* 8007245C  93 BE 01 30 */	stw r29, 0x130(r30)
/* 80072460  3C 80 00 01 */	lis r4, 1
/* 80072464  7F A3 EB 78 */	mr r3, r29
/* 80072468  7F C6 F3 78 */	mr r6, r30
/* 8007246C  81 9D 00 00 */	lwz r12, 0(r29)
/* 80072470  38 84 00 02 */	addi r4, r4, 2
/* 80072474  38 A0 00 00 */	li r5, 0
/* 80072478  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8007247C  7D 89 03 A6 */	mtctr r12
/* 80072480  4E 80 04 21 */	bctrl 
/* 80072484  38 60 00 01 */	li r3, 1
/* 80072488  48 00 00 6C */	b 0x6c
/* 8007248C  7F E3 FB 78 */	mr r3, r31
/* 80072490  38 80 00 04 */	li r4, 4
/* 80072494  4B FE E1 0D */	bl -0x11ef4
/* 80072498  2C 03 00 00 */	cmpwi r3, 0
/* 8007249C  40 82 00 0C */	bne 0xc
/* 800724A0  38 60 00 00 */	li r3, 0
/* 800724A4  48 00 00 50 */	b 0x50
/* 800724A8  80 9E 01 34 */	lwz r4, 0x134(r30)
/* 800724AC  2C 04 00 00 */	cmpwi r4, 0
/* 800724B0  41 82 00 18 */	beq 0x18
/* 800724B4  81 9E 00 00 */	lwz r12, 0(r30)
/* 800724B8  7F C3 F3 78 */	mr r3, r30
/* 800724BC  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800724C0  7D 89 03 A6 */	mtctr r12
/* 800724C4  4E 80 04 21 */	bctrl 
/* 800724C8  93 FE 01 34 */	stw r31, 0x134(r30)
/* 800724CC  3C 80 00 01 */	lis r4, 1
/* 800724D0  7F E3 FB 78 */	mr r3, r31
/* 800724D4  7F C6 F3 78 */	mr r6, r30
/* 800724D8  81 9F 00 00 */	lwz r12, 0(r31)
/* 800724DC  38 84 00 02 */	addi r4, r4, 2
/* 800724E0  38 A0 00 00 */	li r5, 0
/* 800724E4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800724E8  7D 89 03 A6 */	mtctr r12
/* 800724EC  4E 80 04 21 */	bctrl 
/* 800724F0  38 60 00 01 */	li r3, 1
/* 800724F4  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800724F8  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 800724FC  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 80072500  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 80072504  7C 08 03 A6 */	mtlr r0
/* 80072508  38 21 00 40 */	addi r1, r1, 0x40
/* 8007250C  4E 80 00 20 */	blr 
/* 80072510  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072514  7C 08 02 A6 */	mflr r0
/* 80072518  2C 04 00 00 */	cmpwi r4, 0
/* 8007251C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80072520  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80072524  7C 7F 1B 78 */	mr r31, r3
/* 80072528  40 82 00 0C */	bne 0xc
/* 8007252C  38 60 00 00 */	li r3, 0
/* 80072530  48 00 01 44 */	b 0x144
/* 80072534  80 03 01 24 */	lwz r0, 0x124(r3)
/* 80072538  7C 04 00 40 */	cmplw r4, r0
/* 8007253C  40 82 00 38 */	bne 0x38
/* 80072540  7C 03 03 78 */	mr r3, r0
/* 80072544  3C 80 00 01 */	lis r4, 1
/* 80072548  81 83 00 00 */	lwz r12, 0(r3)
/* 8007254C  7F E6 FB 78 */	mr r6, r31
/* 80072550  38 84 00 03 */	addi r4, r4, 3
/* 80072554  38 A0 00 00 */	li r5, 0
/* 80072558  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8007255C  7D 89 03 A6 */	mtctr r12
/* 80072560  4E 80 04 21 */	bctrl 
/* 80072564  38 00 00 00 */	li r0, 0
/* 80072568  90 1F 01 24 */	stw r0, 0x124(r31)
/* 8007256C  38 60 00 01 */	li r3, 1
/* 80072570  48 00 01 04 */	b 0x104
/* 80072574  80 03 01 28 */	lwz r0, 0x128(r3)
/* 80072578  7C 04 00 40 */	cmplw r4, r0
/* 8007257C  40 82 00 38 */	bne 0x38
/* 80072580  7C 03 03 78 */	mr r3, r0
/* 80072584  3C 80 00 01 */	lis r4, 1
/* 80072588  81 83 00 00 */	lwz r12, 0(r3)
/* 8007258C  7F E6 FB 78 */	mr r6, r31
/* 80072590  38 84 00 03 */	addi r4, r4, 3
/* 80072594  38 A0 00 00 */	li r5, 0
/* 80072598  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8007259C  7D 89 03 A6 */	mtctr r12
/* 800725A0  4E 80 04 21 */	bctrl 
/* 800725A4  38 00 00 00 */	li r0, 0
/* 800725A8  90 1F 01 28 */	stw r0, 0x128(r31)
/* 800725AC  38 60 00 01 */	li r3, 1
/* 800725B0  48 00 00 C4 */	b 0xc4
/* 800725B4  80 03 01 2C */	lwz r0, 0x12c(r3)
/* 800725B8  7C 04 00 40 */	cmplw r4, r0
/* 800725BC  40 82 00 38 */	bne 0x38
/* 800725C0  7C 03 03 78 */	mr r3, r0
/* 800725C4  3C 80 00 01 */	lis r4, 1
/* 800725C8  81 83 00 00 */	lwz r12, 0(r3)
/* 800725CC  7F E6 FB 78 */	mr r6, r31
/* 800725D0  38 84 00 03 */	addi r4, r4, 3
/* 800725D4  38 A0 00 00 */	li r5, 0
/* 800725D8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800725DC  7D 89 03 A6 */	mtctr r12
/* 800725E0  4E 80 04 21 */	bctrl 
/* 800725E4  38 00 00 00 */	li r0, 0
/* 800725E8  90 1F 01 2C */	stw r0, 0x12c(r31)
/* 800725EC  38 60 00 01 */	li r3, 1
/* 800725F0  48 00 00 84 */	b 0x84
/* 800725F4  80 03 01 30 */	lwz r0, 0x130(r3)
/* 800725F8  7C 04 00 40 */	cmplw r4, r0
/* 800725FC  40 82 00 38 */	bne 0x38
/* 80072600  7C 03 03 78 */	mr r3, r0
/* 80072604  3C 80 00 01 */	lis r4, 1
/* 80072608  81 83 00 00 */	lwz r12, 0(r3)
/* 8007260C  7F E6 FB 78 */	mr r6, r31
/* 80072610  38 84 00 03 */	addi r4, r4, 3
/* 80072614  38 A0 00 00 */	li r5, 0
/* 80072618  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8007261C  7D 89 03 A6 */	mtctr r12
/* 80072620  4E 80 04 21 */	bctrl 
/* 80072624  38 00 00 00 */	li r0, 0
/* 80072628  90 1F 01 30 */	stw r0, 0x130(r31)
/* 8007262C  38 60 00 01 */	li r3, 1
/* 80072630  48 00 00 44 */	b 0x44
/* 80072634  80 63 01 34 */	lwz r3, 0x134(r3)
/* 80072638  7C 04 18 40 */	cmplw r4, r3
/* 8007263C  40 82 00 34 */	bne 0x34
/* 80072640  81 83 00 00 */	lwz r12, 0(r3)
/* 80072644  3C 80 00 01 */	lis r4, 1
/* 80072648  7F E6 FB 78 */	mr r6, r31
/* 8007264C  38 A0 00 00 */	li r5, 0
/* 80072650  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80072654  38 84 00 03 */	addi r4, r4, 3
/* 80072658  7D 89 03 A6 */	mtctr r12
/* 8007265C  4E 80 04 21 */	bctrl 
/* 80072660  38 00 00 00 */	li r0, 0
/* 80072664  90 1F 01 34 */	stw r0, 0x134(r31)
/* 80072668  38 60 00 01 */	li r3, 1
/* 8007266C  48 00 00 08 */	b 0x8
/* 80072670  38 60 00 00 */	li r3, 0
/* 80072674  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80072678  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8007267C  7C 08 03 A6 */	mtlr r0
/* 80072680  38 21 00 10 */	addi r1, r1, 0x10
/* 80072684  4E 80 00 20 */	blr 
/* 80072688  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007268C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072690  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072694  7C 08 02 A6 */	mflr r0
/* 80072698  2C 04 00 00 */	cmpwi r4, 0
/* 8007269C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800726A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800726A4  3B E0 00 00 */	li r31, 0
/* 800726A8  41 82 00 28 */	beq 0x28
/* 800726AC  2C 04 00 01 */	cmpwi r4, 1
/* 800726B0  41 82 00 3C */	beq 0x3c
/* 800726B4  2C 04 00 02 */	cmpwi r4, 2
/* 800726B8  41 82 00 50 */	beq 0x50
/* 800726BC  2C 04 00 03 */	cmpwi r4, 3
/* 800726C0  41 82 00 64 */	beq 0x64
/* 800726C4  2C 04 00 04 */	cmpwi r4, 4
/* 800726C8  41 82 00 78 */	beq 0x78
/* 800726CC  48 00 00 8C */	b 0x8c
/* 800726D0  81 83 00 00 */	lwz r12, 0(r3)
/* 800726D4  83 E3 01 24 */	lwz r31, 0x124(r3)
/* 800726D8  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800726DC  7F E4 FB 78 */	mr r4, r31
/* 800726E0  7D 89 03 A6 */	mtctr r12
/* 800726E4  4E 80 04 21 */	bctrl 
/* 800726E8  48 00 00 70 */	b 0x70
/* 800726EC  81 83 00 00 */	lwz r12, 0(r3)
/* 800726F0  83 E3 01 28 */	lwz r31, 0x128(r3)
/* 800726F4  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800726F8  7F E4 FB 78 */	mr r4, r31
/* 800726FC  7D 89 03 A6 */	mtctr r12
/* 80072700  4E 80 04 21 */	bctrl 
/* 80072704  48 00 00 54 */	b 0x54
/* 80072708  81 83 00 00 */	lwz r12, 0(r3)
/* 8007270C  83 E3 01 2C */	lwz r31, 0x12c(r3)
/* 80072710  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072714  7F E4 FB 78 */	mr r4, r31
/* 80072718  7D 89 03 A6 */	mtctr r12
/* 8007271C  4E 80 04 21 */	bctrl 
/* 80072720  48 00 00 38 */	b 0x38
/* 80072724  81 83 00 00 */	lwz r12, 0(r3)
/* 80072728  83 E3 01 30 */	lwz r31, 0x130(r3)
/* 8007272C  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072730  7F E4 FB 78 */	mr r4, r31
/* 80072734  7D 89 03 A6 */	mtctr r12
/* 80072738  4E 80 04 21 */	bctrl 
/* 8007273C  48 00 00 1C */	b 0x1c
/* 80072740  81 83 00 00 */	lwz r12, 0(r3)
/* 80072744  83 E3 01 34 */	lwz r31, 0x134(r3)
/* 80072748  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 8007274C  7F E4 FB 78 */	mr r4, r31
/* 80072750  7D 89 03 A6 */	mtctr r12
/* 80072754  4E 80 04 21 */	bctrl 
/* 80072758  7F E3 FB 78 */	mr r3, r31
/* 8007275C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80072760  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80072764  7C 08 03 A6 */	mtlr r0
/* 80072768  38 21 00 10 */	addi r1, r1, 0x10
/* 8007276C  4E 80 00 20 */	blr 
/* 80072770  2C 04 00 00 */	cmpwi r4, 0
/* 80072774  41 82 00 28 */	beq 0x28
/* 80072778  2C 04 00 01 */	cmpwi r4, 1
/* 8007277C  41 82 00 28 */	beq 0x28
/* 80072780  2C 04 00 02 */	cmpwi r4, 2
/* 80072784  41 82 00 28 */	beq 0x28
/* 80072788  2C 04 00 03 */	cmpwi r4, 3
/* 8007278C  41 82 00 28 */	beq 0x28
/* 80072790  2C 04 00 04 */	cmpwi r4, 4
/* 80072794  41 82 00 28 */	beq 0x28
/* 80072798  48 00 00 2C */	b 0x2c
/* 8007279C  80 63 01 24 */	lwz r3, 0x124(r3)
/* 800727A0  4E 80 00 20 */	blr 
/* 800727A4  80 63 01 28 */	lwz r3, 0x128(r3)
/* 800727A8  4E 80 00 20 */	blr 
/* 800727AC  80 63 01 2C */	lwz r3, 0x12c(r3)
/* 800727B0  4E 80 00 20 */	blr 
/* 800727B4  80 63 01 30 */	lwz r3, 0x130(r3)
/* 800727B8  4E 80 00 20 */	blr 
/* 800727BC  80 63 01 34 */	lwz r3, 0x134(r3)
/* 800727C0  4E 80 00 20 */	blr 
/* 800727C4  38 60 00 00 */	li r3, 0
/* 800727C8  4E 80 00 20 */	blr 
/* 800727CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800727D0  2C 04 00 00 */	cmpwi r4, 0
/* 800727D4  41 82 00 28 */	beq 0x28
/* 800727D8  2C 04 00 01 */	cmpwi r4, 1
/* 800727DC  41 82 00 28 */	beq 0x28
/* 800727E0  2C 04 00 02 */	cmpwi r4, 2
/* 800727E4  41 82 00 28 */	beq 0x28
/* 800727E8  2C 04 00 03 */	cmpwi r4, 3
/* 800727EC  41 82 00 28 */	beq 0x28
/* 800727F0  2C 04 00 04 */	cmpwi r4, 4
/* 800727F4  41 82 00 28 */	beq 0x28
/* 800727F8  48 00 00 2C */	b 0x2c
/* 800727FC  80 63 01 24 */	lwz r3, 0x124(r3)
/* 80072800  4E 80 00 20 */	blr 
/* 80072804  80 63 01 28 */	lwz r3, 0x128(r3)
/* 80072808  4E 80 00 20 */	blr 
/* 8007280C  80 63 01 2C */	lwz r3, 0x12c(r3)
/* 80072810  4E 80 00 20 */	blr 
/* 80072814  80 63 01 30 */	lwz r3, 0x130(r3)
/* 80072818  4E 80 00 20 */	blr 
/* 8007281C  80 63 01 34 */	lwz r3, 0x134(r3)
/* 80072820  4E 80 00 20 */	blr 
/* 80072824  38 60 00 00 */	li r3, 0
/* 80072828  4E 80 00 20 */	blr 
/* 8007282C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072830  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072834  7C 08 02 A6 */	mflr r0
/* 80072838  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007283C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80072840  7C 7F 1B 78 */	mr r31, r3
/* 80072844  80 03 01 24 */	lwz r0, 0x124(r3)
/* 80072848  2C 00 00 00 */	cmpwi r0, 0
/* 8007284C  41 82 00 18 */	beq 0x18
/* 80072850  7C 03 03 78 */	mr r3, r0
/* 80072854  81 83 00 00 */	lwz r12, 0(r3)
/* 80072858  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8007285C  7D 89 03 A6 */	mtctr r12
/* 80072860  4E 80 04 21 */	bctrl 
/* 80072864  80 7F 01 28 */	lwz r3, 0x128(r31)
/* 80072868  2C 03 00 00 */	cmpwi r3, 0
/* 8007286C  41 82 00 14 */	beq 0x14
/* 80072870  81 83 00 00 */	lwz r12, 0(r3)
/* 80072874  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80072878  7D 89 03 A6 */	mtctr r12
/* 8007287C  4E 80 04 21 */	bctrl 
/* 80072880  80 7F 01 2C */	lwz r3, 0x12c(r31)
/* 80072884  2C 03 00 00 */	cmpwi r3, 0
/* 80072888  41 82 00 14 */	beq 0x14
/* 8007288C  81 83 00 00 */	lwz r12, 0(r3)
/* 80072890  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80072894  7D 89 03 A6 */	mtctr r12
/* 80072898  4E 80 04 21 */	bctrl 
/* 8007289C  80 7F 01 30 */	lwz r3, 0x130(r31)
/* 800728A0  2C 03 00 00 */	cmpwi r3, 0
/* 800728A4  41 82 00 14 */	beq 0x14
/* 800728A8  81 83 00 00 */	lwz r12, 0(r3)
/* 800728AC  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 800728B0  7D 89 03 A6 */	mtctr r12
/* 800728B4  4E 80 04 21 */	bctrl 
/* 800728B8  80 7F 01 34 */	lwz r3, 0x134(r31)
/* 800728BC  2C 03 00 00 */	cmpwi r3, 0
/* 800728C0  41 82 00 14 */	beq 0x14
/* 800728C4  81 83 00 00 */	lwz r12, 0(r3)
/* 800728C8  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 800728CC  7D 89 03 A6 */	mtctr r12
/* 800728D0  4E 80 04 21 */	bctrl 
/* 800728D4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800728D8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800728DC  7C 08 03 A6 */	mtlr r0
/* 800728E0  38 21 00 10 */	addi r1, r1, 0x10
/* 800728E4  4E 80 00 20 */	blr 
/* 800728E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800728EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800728F0  54 80 07 FF */	clrlwi. r0, r4, 0x1f
/* 800728F4  41 82 00 10 */	beq 0x10
/* 800728F8  88 03 01 20 */	lbz r0, 0x120(r3)
/* 800728FC  60 00 00 01 */	ori r0, r0, 1
/* 80072900  98 03 01 20 */	stb r0, 0x120(r3)
/* 80072904  54 80 07 BD */	rlwinm. r0, r4, 0, 0x1e, 0x1e
/* 80072908  41 82 00 10 */	beq 0x10
/* 8007290C  88 03 01 20 */	lbz r0, 0x120(r3)
/* 80072910  60 00 00 02 */	ori r0, r0, 2
/* 80072914  98 03 01 20 */	stb r0, 0x120(r3)
/* 80072918  54 80 07 7B */	rlwinm. r0, r4, 0, 0x1d, 0x1d
/* 8007291C  4D 82 00 20 */	beqlr 
/* 80072920  88 03 01 20 */	lbz r0, 0x120(r3)
/* 80072924  60 00 00 04 */	ori r0, r0, 4
/* 80072928  98 03 01 20 */	stb r0, 0x120(r3)
/* 8007292C  4E 80 00 20 */	blr 
/* 80072930  54 80 07 FF */	clrlwi. r0, r4, 0x1f
/* 80072934  41 82 00 10 */	beq 0x10
/* 80072938  88 03 01 20 */	lbz r0, 0x120(r3)
/* 8007293C  54 00 06 3C */	rlwinm r0, r0, 0, 0x18, 0x1e
/* 80072940  98 03 01 20 */	stb r0, 0x120(r3)
/* 80072944  54 80 07 BD */	rlwinm. r0, r4, 0, 0x1e, 0x1e
/* 80072948  41 82 00 10 */	beq 0x10
/* 8007294C  88 03 01 20 */	lbz r0, 0x120(r3)
/* 80072950  54 00 07 FA */	rlwinm r0, r0, 0, 0x1f, 0x1d
/* 80072954  98 03 01 20 */	stb r0, 0x120(r3)
/* 80072958  54 80 07 7B */	rlwinm. r0, r4, 0, 0x1d, 0x1d
/* 8007295C  4D 82 00 20 */	beqlr 
/* 80072960  88 03 01 20 */	lbz r0, 0x120(r3)
/* 80072964  54 00 07 B8 */	rlwinm r0, r0, 0, 0x1e, 0x1c
/* 80072968  98 03 01 20 */	stb r0, 0x120(r3)
/* 8007296C  4E 80 00 20 */	blr 
/* 80072970  A0 03 01 02 */	lhz r0, 0x102(r3)
/* 80072974  88 A3 01 01 */	lbz r5, 0x101(r3)
/* 80072978  1C 80 00 30 */	mulli r4, r0, 0x30
/* 8007297C  80 63 00 F4 */	lwz r3, 0xf4(r3)
/* 80072980  38 04 00 1F */	addi r0, r4, 0x1f
/* 80072984  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80072988  7C 05 01 D6 */	mullw r0, r5, r0
/* 8007298C  7C 63 02 14 */	add r3, r3, r0
/* 80072990  4E 80 00 20 */	blr 
/* 80072994  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072998  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007299C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800729A0  80 A3 00 F8 */	lwz r5, 0xf8(r3)
/* 800729A4  2C 05 00 00 */	cmpwi r5, 0
/* 800729A8  41 82 00 24 */	beq 0x24
/* 800729AC  A0 03 01 02 */	lhz r0, 0x102(r3)
/* 800729B0  88 83 01 01 */	lbz r4, 0x101(r3)
/* 800729B4  1C 60 00 24 */	mulli r3, r0, 0x24
/* 800729B8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800729BC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800729C0  7C 04 01 D6 */	mullw r0, r4, r0
/* 800729C4  7C 65 02 14 */	add r3, r5, r0
/* 800729C8  4E 80 00 20 */	blr 
/* 800729CC  38 60 00 00 */	li r3, 0
/* 800729D0  4E 80 00 20 */	blr 
/* 800729D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800729D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800729DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800729E0  80 A3 00 FC */	lwz r5, 0xfc(r3)
/* 800729E4  2C 05 00 00 */	cmpwi r5, 0
/* 800729E8  41 82 00 24 */	beq 0x24
/* 800729EC  A0 03 01 02 */	lhz r0, 0x102(r3)
/* 800729F0  88 83 01 01 */	lbz r4, 0x101(r3)
/* 800729F4  1C 60 00 30 */	mulli r3, r0, 0x30
/* 800729F8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800729FC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80072A00  7C 04 01 D6 */	mullw r0, r4, r0
/* 80072A04  7C 65 02 14 */	add r3, r5, r0
/* 80072A08  4E 80 00 20 */	blr 
/* 80072A0C  38 60 00 00 */	li r3, 0
/* 80072A10  4E 80 00 20 */	blr 
/* 80072A14  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072A18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072A1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072A20  2C 04 00 00 */	cmpwi r4, 0
/* 80072A24  41 82 00 20 */	beq 0x20
/* 80072A28  2C 04 00 01 */	cmpwi r4, 1
/* 80072A2C  41 82 00 20 */	beq 0x20
/* 80072A30  2C 04 00 02 */	cmpwi r4, 2
/* 80072A34  41 82 00 20 */	beq 0x20
/* 80072A38  2C 04 00 03 */	cmpwi r4, 3
/* 80072A3C  41 82 00 20 */	beq 0x20
/* 80072A40  48 00 00 24 */	b 0x24
/* 80072A44  80 63 01 08 */	lwz r3, 0x108(r3)
/* 80072A48  4E 80 00 20 */	blr 
/* 80072A4C  80 63 01 0C */	lwz r3, 0x10c(r3)
/* 80072A50  4E 80 00 20 */	blr 
/* 80072A54  80 63 01 10 */	lwz r3, 0x110(r3)
/* 80072A58  4E 80 00 20 */	blr 
/* 80072A5C  80 63 01 14 */	lwz r3, 0x114(r3)
/* 80072A60  4E 80 00 20 */	blr 
/* 80072A64  38 60 00 00 */	li r3, 0
/* 80072A68  4E 80 00 20 */	blr 
/* 80072A6C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072A70  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80072A74  7C 08 02 A6 */	mflr r0
/* 80072A78  90 01 00 54 */	stw r0, 0x54(r1)
/* 80072A7C  39 61 00 50 */	addi r11, r1, 0x50
/* 80072A80  4B FA EB 0D */	bl -0x514f4
/* 80072A84  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80072A88  7C 7C 1B 78 */	mr r28, r3
/* 80072A8C  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 80072A90  7C BD 2B 78 */	mr r29, r5
/* 80072A94  7C D6 33 78 */	mr r22, r6
/* 80072A98  7C F7 3B 78 */	mr r23, r7
/* 80072A9C  7D 18 43 78 */	mr r24, r8
/* 80072AA0  7D 39 4B 78 */	mr r25, r9
/* 80072AA4  7D 5A 53 78 */	mr r26, r10
/* 80072AA8  4B FF AD 09 */	bl -0x52f8
/* 80072AAC  C0 02 8D A0 */	lfs f0, -0x7260(r2)
/* 80072AB0  3C A0 80 27 */	lis r5, 0x8027
/* 80072AB4  38 A5 32 00 */	addi r5, r5, 0x3200
/* 80072AB8  D0 1C 00 DC */	stfs f0, 0xdc(r28)
/* 80072ABC  3C 80 80 27 */	lis r4, 0x8027
/* 80072AC0  3B 60 00 00 */	li r27, 0
/* 80072AC4  D0 1C 00 E0 */	stfs f0, 0xe0(r28)
/* 80072AC8  7F A3 EB 78 */	mr r3, r29
/* 80072ACC  38 84 31 F0 */	addi r4, r4, 0x31f0
/* 80072AD0  D0 1C 00 E4 */	stfs f0, 0xe4(r28)
/* 80072AD4  90 BC 00 00 */	stw r5, 0(r28)
/* 80072AD8  80 1D 00 00 */	lwz r0, 0(r29)
/* 80072ADC  90 1C 00 E8 */	stw r0, 0xe8(r28)
/* 80072AE0  92 DC 00 EC */	stw r22, 0xec(r28)
/* 80072AE4  92 FC 00 F0 */	stw r23, 0xf0(r28)
/* 80072AE8  93 1C 00 F4 */	stw r24, 0xf4(r28)
/* 80072AEC  93 3C 00 F8 */	stw r25, 0xf8(r28)
/* 80072AF0  93 5C 00 FC */	stw r26, 0xfc(r28)
/* 80072AF4  9B DC 01 00 */	stb r30, 0x100(r28)
/* 80072AF8  9B 7C 01 01 */	stb r27, 0x101(r28)
/* 80072AFC  B3 FC 01 02 */	sth r31, 0x102(r28)
/* 80072B00  93 7C 01 04 */	stw r27, 0x104(r28)
/* 80072B04  4B FD B7 4D */	bl -0x248b4
/* 80072B08  90 7C 01 08 */	stw r3, 0x108(r28)
/* 80072B0C  7F A3 EB 78 */	mr r3, r29
/* 80072B10  38 8D 81 50 */	addi r4, r13, -32432
/* 80072B14  4B FD B7 3D */	bl -0x248c4
/* 80072B18  90 7C 01 0C */	stw r3, 0x10c(r28)
/* 80072B1C  7F A3 EB 78 */	mr r3, r29
/* 80072B20  38 8D 81 58 */	addi r4, r13, -32424
/* 80072B24  4B FD B7 2D */	bl -0x248d4
/* 80072B28  90 7C 01 10 */	stw r3, 0x110(r28)
/* 80072B2C  7F A3 EB 78 */	mr r3, r29
/* 80072B30  38 8D 81 60 */	addi r4, r13, -32416
/* 80072B34  4B FD B7 1D */	bl -0x248e4
/* 80072B38  80 1C 01 10 */	lwz r0, 0x110(r28)
/* 80072B3C  38 80 00 02 */	li r4, 2
/* 80072B40  90 7C 01 14 */	stw r3, 0x114(r28)
/* 80072B44  2C 00 00 00 */	cmpwi r0, 0
/* 80072B48  90 9C 01 18 */	stw r4, 0x118(r28)
/* 80072B4C  93 7C 01 1C */	stw r27, 0x11c(r28)
/* 80072B50  9B 7C 01 20 */	stb r27, 0x120(r28)
/* 80072B54  9B 7C 01 21 */	stb r27, 0x121(r28)
/* 80072B58  B3 7C 01 22 */	sth r27, 0x122(r28)
/* 80072B5C  93 7C 01 24 */	stw r27, 0x124(r28)
/* 80072B60  93 7C 01 28 */	stw r27, 0x128(r28)
/* 80072B64  93 7C 01 2C */	stw r27, 0x12c(r28)
/* 80072B68  93 7C 01 30 */	stw r27, 0x130(r28)
/* 80072B6C  93 7C 01 34 */	stw r27, 0x134(r28)
/* 80072B70  41 82 00 14 */	beq 0x14
/* 80072B74  80 1C 00 CC */	lwz r0, 0xcc(r28)
/* 80072B78  54 00 00 C2 */	rlwinm r0, r0, 0, 3, 1
/* 80072B7C  90 1C 00 CC */	stw r0, 0xcc(r28)
/* 80072B80  48 00 00 10 */	b 0x10
/* 80072B84  80 1C 00 CC */	lwz r0, 0xcc(r28)
/* 80072B88  64 00 20 00 */	oris r0, r0, 0x2000
/* 80072B8C  90 1C 00 CC */	stw r0, 0xcc(r28)
/* 80072B90  80 1C 01 14 */	lwz r0, 0x114(r28)
/* 80072B94  2C 00 00 00 */	cmpwi r0, 0
/* 80072B98  41 82 00 14 */	beq 0x14
/* 80072B9C  80 1C 00 CC */	lwz r0, 0xcc(r28)
/* 80072BA0  54 00 00 80 */	rlwinm r0, r0, 0, 2, 0
/* 80072BA4  90 1C 00 CC */	stw r0, 0xcc(r28)
/* 80072BA8  48 00 00 10 */	b 0x10
/* 80072BAC  80 1C 00 CC */	lwz r0, 0xcc(r28)
/* 80072BB0  64 00 40 00 */	oris r0, r0, 0x4000
/* 80072BB4  90 1C 00 CC */	stw r0, 0xcc(r28)
/* 80072BB8  80 7C 00 F4 */	lwz r3, 0xf4(r28)
/* 80072BBC  2C 03 00 00 */	cmpwi r3, 0
/* 80072BC0  41 82 00 18 */	beq 0x18
/* 80072BC4  1C 9F 00 30 */	mulli r4, r31, 0x30
/* 80072BC8  38 04 00 1F */	addi r0, r4, 0x1f
/* 80072BCC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80072BD0  7C 9E 01 D6 */	mullw r4, r30, r0
/* 80072BD4  48 12 EA 2D */	bl 0x12ea2c
/* 80072BD8  80 7C 00 F8 */	lwz r3, 0xf8(r28)
/* 80072BDC  2C 03 00 00 */	cmpwi r3, 0
/* 80072BE0  41 82 00 18 */	beq 0x18
/* 80072BE4  1C 9F 00 24 */	mulli r4, r31, 0x24
/* 80072BE8  38 04 00 1F */	addi r0, r4, 0x1f
/* 80072BEC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80072BF0  7C 9E 01 D6 */	mullw r4, r30, r0
/* 80072BF4  48 12 EA 0D */	bl 0x12ea0c
/* 80072BF8  80 7C 00 FC */	lwz r3, 0xfc(r28)
/* 80072BFC  2C 03 00 00 */	cmpwi r3, 0
/* 80072C00  41 82 00 18 */	beq 0x18
/* 80072C04  1C 9F 00 30 */	mulli r4, r31, 0x30
/* 80072C08  38 04 00 1F */	addi r0, r4, 0x1f
/* 80072C0C  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80072C10  7C 9E 01 D6 */	mullw r4, r30, r0
/* 80072C14  48 12 E9 ED */	bl 0x12e9ec
/* 80072C18  80 7D 00 00 */	lwz r3, 0(r29)
/* 80072C1C  88 03 00 6E */	lbz r0, 0x6e(r3)
/* 80072C20  38 C3 00 4C */	addi r6, r3, 0x4c
/* 80072C24  2C 00 00 00 */	cmpwi r0, 0
/* 80072C28  41 82 00 44 */	beq 0x44
/* 80072C2C  C0 06 00 28 */	lfs f0, 0x28(r6)
/* 80072C30  7F 83 E3 78 */	mr r3, r28
/* 80072C34  D0 01 00 08 */	stfs f0, 8(r1)
/* 80072C38  38 A1 00 08 */	addi r5, r1, 8
/* 80072C3C  38 80 00 00 */	li r4, 0
/* 80072C40  C0 06 00 2C */	lfs f0, 0x2c(r6)
/* 80072C44  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 80072C48  C0 06 00 30 */	lfs f0, 0x30(r6)
/* 80072C4C  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 80072C50  C0 06 00 34 */	lfs f0, 0x34(r6)
/* 80072C54  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 80072C58  C0 06 00 38 */	lfs f0, 0x38(r6)
/* 80072C5C  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 80072C60  C0 06 00 3C */	lfs f0, 0x3c(r6)
/* 80072C64  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 80072C68  4B FF B1 49 */	bl -0x4eb8
/* 80072C6C  39 61 00 50 */	addi r11, r1, 0x50
/* 80072C70  7F 83 E3 78 */	mr r3, r28
/* 80072C74  4B FA E9 65 */	bl -0x5169c
/* 80072C78  80 01 00 54 */	lwz r0, 0x54(r1)
/* 80072C7C  7C 08 03 A6 */	mtlr r0
/* 80072C80  38 21 00 50 */	addi r1, r1, 0x50
/* 80072C84  4E 80 00 20 */	blr 
/* 80072C88  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072C8C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072C90  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072C94  7C 08 02 A6 */	mflr r0
/* 80072C98  2C 03 00 00 */	cmpwi r3, 0
/* 80072C9C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80072CA0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80072CA4  7C 7F 1B 78 */	mr r31, r3
/* 80072CA8  41 82 00 F0 */	beq 0xf0
/* 80072CAC  88 03 01 21 */	lbz r0, 0x121(r3)
/* 80072CB0  3C 80 80 27 */	lis r4, 0x8027
/* 80072CB4  38 84 32 00 */	addi r4, r4, 0x3200
/* 80072CB8  90 83 00 00 */	stw r4, 0(r3)
/* 80072CBC  2C 00 00 01 */	cmpwi r0, 1
/* 80072CC0  40 82 00 24 */	bne 0x24
/* 80072CC4  80 63 01 1C */	lwz r3, 0x11c(r3)
/* 80072CC8  2C 03 00 00 */	cmpwi r3, 0
/* 80072CCC  41 82 00 18 */	beq 0x18
/* 80072CD0  81 83 00 00 */	lwz r12, 0(r3)
/* 80072CD4  38 80 00 01 */	li r4, 1
/* 80072CD8  81 8C 00 08 */	lwz r12, 8(r12)
/* 80072CDC  7D 89 03 A6 */	mtctr r12
/* 80072CE0  4E 80 04 21 */	bctrl 
/* 80072CE4  80 9F 01 24 */	lwz r4, 0x124(r31)
/* 80072CE8  2C 04 00 00 */	cmpwi r4, 0
/* 80072CEC  41 82 00 18 */	beq 0x18
/* 80072CF0  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072CF4  7F E3 FB 78 */	mr r3, r31
/* 80072CF8  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072CFC  7D 89 03 A6 */	mtctr r12
/* 80072D00  4E 80 04 21 */	bctrl 
/* 80072D04  80 9F 01 28 */	lwz r4, 0x128(r31)
/* 80072D08  2C 04 00 00 */	cmpwi r4, 0
/* 80072D0C  41 82 00 18 */	beq 0x18
/* 80072D10  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072D14  7F E3 FB 78 */	mr r3, r31
/* 80072D18  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072D1C  7D 89 03 A6 */	mtctr r12
/* 80072D20  4E 80 04 21 */	bctrl 
/* 80072D24  80 9F 01 2C */	lwz r4, 0x12c(r31)
/* 80072D28  2C 04 00 00 */	cmpwi r4, 0
/* 80072D2C  41 82 00 18 */	beq 0x18
/* 80072D30  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072D34  7F E3 FB 78 */	mr r3, r31
/* 80072D38  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072D3C  7D 89 03 A6 */	mtctr r12
/* 80072D40  4E 80 04 21 */	bctrl 
/* 80072D44  80 9F 01 30 */	lwz r4, 0x130(r31)
/* 80072D48  2C 04 00 00 */	cmpwi r4, 0
/* 80072D4C  41 82 00 18 */	beq 0x18
/* 80072D50  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072D54  7F E3 FB 78 */	mr r3, r31
/* 80072D58  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072D5C  7D 89 03 A6 */	mtctr r12
/* 80072D60  4E 80 04 21 */	bctrl 
/* 80072D64  80 9F 01 34 */	lwz r4, 0x134(r31)
/* 80072D68  2C 04 00 00 */	cmpwi r4, 0
/* 80072D6C  41 82 00 18 */	beq 0x18
/* 80072D70  81 9F 00 00 */	lwz r12, 0(r31)
/* 80072D74  7F E3 FB 78 */	mr r3, r31
/* 80072D78  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80072D7C  7D 89 03 A6 */	mtctr r12
/* 80072D80  4E 80 04 21 */	bctrl 
/* 80072D84  2C 1F 00 00 */	cmpwi r31, 0
/* 80072D88  41 82 00 10 */	beq 0x10
/* 80072D8C  7F E3 FB 78 */	mr r3, r31
/* 80072D90  38 80 00 00 */	li r4, 0
/* 80072D94  4B FF AB 0D */	bl -0x54f4
/* 80072D98  7F E3 FB 78 */	mr r3, r31
/* 80072D9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80072DA0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80072DA4  7C 08 03 A6 */	mtlr r0
/* 80072DA8  38 21 00 10 */	addi r1, r1, 0x10
/* 80072DAC  4E 80 00 20 */	blr 
/* 80072DB0  3C 60 80 24 */	lis r3, 0x8024
/* 80072DB4  80 04 00 00 */	lwz r0, 0(r4)
/* 80072DB8  38 63 7F B0 */	addi r3, r3, 0x7fb0
/* 80072DBC  7C 00 18 40 */	cmplw r0, r3
/* 80072DC0  40 82 00 0C */	bne 0xc
/* 80072DC4  38 60 00 01 */	li r3, 1
/* 80072DC8  4E 80 00 20 */	blr 
/* 80072DCC  3C 60 80 24 */	lis r3, 0x8024
/* 80072DD0  80 04 00 00 */	lwz r0, 0(r4)
/* 80072DD4  38 63 7F 80 */	addi r3, r3, 0x7f80
/* 80072DD8  7C 00 18 40 */	cmplw r0, r3
/* 80072DDC  40 82 00 0C */	bne 0xc
/* 80072DE0  38 60 00 01 */	li r3, 1
/* 80072DE4  4E 80 00 20 */	blr 
/* 80072DE8  3C 60 80 24 */	lis r3, 0x8024
/* 80072DEC  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 80072DF0  7C 00 18 40 */	cmplw r0, r3
/* 80072DF4  40 82 00 0C */	bne 0xc
/* 80072DF8  38 60 00 01 */	li r3, 1
/* 80072DFC  4E 80 00 20 */	blr 
/* 80072E00  3C 60 80 24 */	lis r3, 0x8024
/* 80072E04  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 80072E08  7C 00 18 50 */	subf r0, r0, r3
/* 80072E0C  7C 00 00 34 */	cntlzw r0, r0
/* 80072E10  54 03 D9 7E */	srwi r3, r0, 5
/* 80072E14  4E 80 00 20 */	blr 
/* 80072E18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072E1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072E20  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072E24  7C 08 02 A6 */	mflr r0
/* 80072E28  90 01 00 14 */	stw r0, 0x14(r1)
/* 80072E2C  81 83 00 00 */	lwz r12, 0(r3)
/* 80072E30  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80072E34  7D 89 03 A6 */	mtctr r12
/* 80072E38  4E 80 04 21 */	bctrl 
/* 80072E3C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80072E40  38 63 00 04 */	addi r3, r3, 4
/* 80072E44  7C 08 03 A6 */	mtlr r0
/* 80072E48  38 21 00 10 */	addi r1, r1, 0x10
/* 80072E4C  4E 80 00 20 */	blr 
/* 80072E50  3C 60 80 24 */	lis r3, 0x8024
/* 80072E54  38 63 7F B0 */	addi r3, r3, 0x7fb0
/* 80072E58  4E 80 00 20 */	blr 
/* 80072E5C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072E60  80 A3 00 00 */	lwz r5, 0(r3)
/* 80072E64  2C 05 00 00 */	cmpwi r5, 0
/* 80072E68  41 82 00 38 */	beq 0x38
/* 80072E6C  80 03 00 08 */	lwz r0, 8(r3)
/* 80072E70  2C 00 00 00 */	cmpwi r0, 0
/* 80072E74  41 82 00 2C */	beq 0x2c
/* 80072E78  2C 04 00 00 */	cmpwi r4, 0
/* 80072E7C  41 82 00 1C */	beq 0x1c
/* 80072E80  80 03 00 04 */	lwz r0, 4(r3)
/* 80072E84  80 A5 01 40 */	lwz r5, 0x140(r5)
/* 80072E88  54 04 10 3A */	slwi r4, r0, 2
/* 80072E8C  7C 05 20 2E */	lwzx r0, r5, r4
/* 80072E90  60 00 00 01 */	ori r0, r0, 1
/* 80072E94  7C 05 21 2E */	stwx r0, r5, r4
/* 80072E98  80 63 00 08 */	lwz r3, 8(r3)
/* 80072E9C  4E 80 00 20 */	blr 
/* 80072EA0  38 60 00 00 */	li r3, 0
/* 80072EA4  4E 80 00 20 */	blr 
/* 80072EA8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072EAC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072EB0  80 A3 00 00 */	lwz r5, 0(r3)
/* 80072EB4  2C 05 00 00 */	cmpwi r5, 0
/* 80072EB8  41 82 00 38 */	beq 0x38
/* 80072EBC  80 03 00 24 */	lwz r0, 0x24(r3)
/* 80072EC0  2C 00 00 00 */	cmpwi r0, 0
/* 80072EC4  41 82 00 2C */	beq 0x2c
/* 80072EC8  2C 04 00 00 */	cmpwi r4, 0
/* 80072ECC  41 82 00 1C */	beq 0x1c
/* 80072ED0  80 03 00 04 */	lwz r0, 4(r3)
/* 80072ED4  80 A5 01 40 */	lwz r5, 0x140(r5)
/* 80072ED8  54 04 10 3A */	slwi r4, r0, 2
/* 80072EDC  7C 05 20 2E */	lwzx r0, r5, r4
/* 80072EE0  60 00 01 00 */	ori r0, r0, 0x100
/* 80072EE4  7C 05 21 2E */	stwx r0, r5, r4
/* 80072EE8  80 63 00 24 */	lwz r3, 0x24(r3)
/* 80072EEC  4E 80 00 20 */	blr 
/* 80072EF0  38 60 00 00 */	li r3, 0
/* 80072EF4  4E 80 00 20 */	blr 
/* 80072EF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072EFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80072F00  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072F04  7C 08 02 A6 */	mflr r0
/* 80072F08  7C 65 1B 78 */	mr r5, r3
/* 80072F0C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80072F10  80 83 00 00 */	lwz r4, 0(r3)
/* 80072F14  2C 04 00 00 */	cmpwi r4, 0
/* 80072F18  41 82 00 34 */	beq 0x34
/* 80072F1C  80 03 00 10 */	lwz r0, 0x10(r3)
/* 80072F20  2C 00 00 00 */	cmpwi r0, 0
/* 80072F24  41 82 00 0C */	beq 0xc
/* 80072F28  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80072F2C  48 00 00 24 */	b 0x24
/* 80072F30  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 80072F34  38 61 00 08 */	addi r3, r1, 8
/* 80072F38  90 01 00 08 */	stw r0, 8(r1)
/* 80072F3C  80 85 00 04 */	lwz r4, 4(r5)
/* 80072F40  4B FD BA B1 */	bl -0x24550
/* 80072F44  38 63 01 A8 */	addi r3, r3, 0x1a8
/* 80072F48  48 00 00 08 */	b 0x8
/* 80072F4C  38 60 00 00 */	li r3, 0
/* 80072F50  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80072F54  7C 08 03 A6 */	mtlr r0
/* 80072F58  38 21 00 10 */	addi r1, r1, 0x10
/* 80072F5C  4E 80 00 20 */	blr 
/* 80072F60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072F64  7C 08 02 A6 */	mflr r0
/* 80072F68  7C 65 1B 78 */	mr r5, r3
/* 80072F6C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80072F70  80 83 00 00 */	lwz r4, 0(r3)
/* 80072F74  2C 04 00 00 */	cmpwi r4, 0
/* 80072F78  41 82 00 34 */	beq 0x34
/* 80072F7C  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 80072F80  2C 00 00 00 */	cmpwi r0, 0
/* 80072F84  41 82 00 0C */	beq 0xc
/* 80072F88  80 63 00 1C */	lwz r3, 0x1c(r3)
/* 80072F8C  48 00 00 24 */	b 0x24
/* 80072F90  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 80072F94  38 61 00 08 */	addi r3, r1, 8
/* 80072F98  90 01 00 08 */	stw r0, 8(r1)
/* 80072F9C  80 85 00 04 */	lwz r4, 4(r5)
/* 80072FA0  4B FD BA 51 */	bl -0x245b0
/* 80072FA4  38 63 00 1C */	addi r3, r3, 0x1c
/* 80072FA8  48 00 00 08 */	b 0x8
/* 80072FAC  38 60 00 00 */	li r3, 0
/* 80072FB0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80072FB4  7C 08 03 A6 */	mtlr r0
/* 80072FB8  38 21 00 10 */	addi r1, r1, 0x10
/* 80072FBC  4E 80 00 20 */	blr 
/* 80072FC0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80072FC4  7C 08 02 A6 */	mflr r0
/* 80072FC8  7C 65 1B 78 */	mr r5, r3
/* 80072FCC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80072FD0  80 83 00 00 */	lwz r4, 0(r3)
/* 80072FD4  2C 04 00 00 */	cmpwi r4, 0
/* 80072FD8  41 82 00 4C */	beq 0x4c
/* 80072FDC  80 03 00 24 */	lwz r0, 0x24(r3)
/* 80072FE0  2C 00 00 00 */	cmpwi r0, 0
/* 80072FE4  41 82 00 0C */	beq 0xc
/* 80072FE8  80 63 00 24 */	lwz r3, 0x24(r3)
/* 80072FEC  48 00 00 3C */	b 0x3c
/* 80072FF0  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 80072FF4  38 61 00 08 */	addi r3, r1, 8
/* 80072FF8  90 01 00 08 */	stw r0, 8(r1)
/* 80072FFC  80 85 00 04 */	lwz r4, 4(r5)
/* 80073000  4B FD B9 F1 */	bl -0x24610
/* 80073004  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80073008  2C 00 00 00 */	cmpwi r0, 0
/* 8007300C  41 82 00 0C */	beq 0xc
/* 80073010  7C 63 02 14 */	add r3, r3, r0
/* 80073014  48 00 00 08 */	b 0x8
/* 80073018  38 60 00 00 */	li r3, 0
/* 8007301C  38 63 00 20 */	addi r3, r3, 0x20
/* 80073020  48 00 00 08 */	b 0x8
/* 80073024  38 60 00 00 */	li r3, 0
/* 80073028  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007302C  7C 08 03 A6 */	mtlr r0
/* 80073030  38 21 00 10 */	addi r1, r1, 0x10
/* 80073034  4E 80 00 20 */	blr 
/* 80073038  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007303C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80073040  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80073044  7C 08 02 A6 */	mflr r0
/* 80073048  7C 65 1B 78 */	mr r5, r3
/* 8007304C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80073050  80 83 00 00 */	lwz r4, 0(r3)
/* 80073054  2C 04 00 00 */	cmpwi r4, 0
/* 80073058  41 82 00 3C */	beq 0x3c
/* 8007305C  80 03 00 30 */	lwz r0, 0x30(r3)
/* 80073060  2C 00 00 00 */	cmpwi r0, 0
/* 80073064  41 82 00 0C */	beq 0xc
/* 80073068  80 63 00 30 */	lwz r3, 0x30(r3)
/* 8007306C  48 00 00 2C */	b 0x2c
/* 80073070  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 80073074  38 61 00 08 */	addi r3, r1, 8
/* 80073078  90 01 00 08 */	stw r0, 8(r1)
/* 8007307C  80 85 00 04 */	lwz r4, 4(r5)
/* 80073080  4B FD B9 71 */	bl -0x24690
/* 80073084  90 61 00 0C */	stw r3, 0xc(r1)
/* 80073088  38 61 00 0C */	addi r3, r1, 0xc
/* 8007308C  4B FD F1 35 */	bl -0x20ecc
/* 80073090  48 00 00 08 */	b 0x8
/* 80073094  38 60 00 00 */	li r3, 0
/* 80073098  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8007309C  7C 08 03 A6 */	mtlr r0
/* 800730A0  38 21 00 10 */	addi r1, r1, 0x10
/* 800730A4  4E 80 00 20 */	blr 
/* 800730A8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800730AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800730B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800730B4  7C 08 02 A6 */	mflr r0
/* 800730B8  2C 04 00 00 */	cmpwi r4, 0
/* 800730BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800730C0  38 00 00 00 */	li r0, 0
/* 800730C4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800730C8  7C BF 2B 78 */	mr r31, r5
/* 800730CC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800730D0  7C 9E 23 78 */	mr r30, r4
/* 800730D4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800730D8  7C 7D 1B 78 */	mr r29, r3
/* 800730DC  93 81 00 10 */	stw r28, 0x10(r1)
/* 800730E0  3B 80 00 00 */	li r28, 0
/* 800730E4  90 03 00 08 */	stw r0, 8(r3)
/* 800730E8  90 03 00 0C */	stw r0, 0xc(r3)
/* 800730EC  90 03 00 10 */	stw r0, 0x10(r3)
/* 800730F0  90 03 00 14 */	stw r0, 0x14(r3)
/* 800730F4  90 03 00 18 */	stw r0, 0x18(r3)
/* 800730F8  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800730FC  90 03 00 20 */	stw r0, 0x20(r3)
/* 80073100  90 03 00 24 */	stw r0, 0x24(r3)
/* 80073104  90 03 00 28 */	stw r0, 0x28(r3)
/* 80073108  90 03 00 2C */	stw r0, 0x2c(r3)
/* 8007310C  90 03 00 30 */	stw r0, 0x30(r3)
/* 80073110  41 82 00 24 */	beq 0x24
/* 80073114  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 80073118  7F E4 FB 78 */	mr r4, r31
/* 8007311C  90 01 00 08 */	stw r0, 8(r1)
/* 80073120  38 61 00 08 */	addi r3, r1, 8
/* 80073124  4B FD B8 CD */	bl -0x24734
/* 80073128  2C 03 00 00 */	cmpwi r3, 0
/* 8007312C  41 82 00 08 */	beq 0x8
/* 80073130  3B 80 00 01 */	li r28, 1
/* 80073134  2C 1C 00 00 */	cmpwi r28, 0
/* 80073138  41 82 01 9C */	beq 0x19c
/* 8007313C  93 DD 00 00 */	stw r30, 0(r29)
/* 80073140  93 FD 00 04 */	stw r31, 4(r29)
/* 80073144  80 7E 01 4C */	lwz r3, 0x14c(r30)
/* 80073148  2C 03 00 00 */	cmpwi r3, 0
/* 8007314C  41 82 00 14 */	beq 0x14
/* 80073150  1C 1F 01 04 */	mulli r0, r31, 0x104
/* 80073154  7C 03 02 14 */	add r0, r3, r0
/* 80073158  90 1D 00 08 */	stw r0, 8(r29)
/* 8007315C  48 00 00 0C */	b 0xc
/* 80073160  38 00 00 00 */	li r0, 0
/* 80073164  90 1D 00 08 */	stw r0, 8(r29)
/* 80073168  80 7E 01 50 */	lwz r3, 0x150(r30)
/* 8007316C  2C 03 00 00 */	cmpwi r3, 0
/* 80073170  41 82 00 14 */	beq 0x14
/* 80073174  1C 1F 00 64 */	mulli r0, r31, 0x64
/* 80073178  7C 03 02 14 */	add r0, r3, r0
/* 8007317C  90 1D 00 0C */	stw r0, 0xc(r29)
/* 80073180  48 00 00 0C */	b 0xc
/* 80073184  38 00 00 00 */	li r0, 0
/* 80073188  90 1D 00 0C */	stw r0, 0xc(r29)
/* 8007318C  80 7E 01 54 */	lwz r3, 0x154(r30)
/* 80073190  2C 03 00 00 */	cmpwi r3, 0
/* 80073194  41 82 00 14 */	beq 0x14
/* 80073198  1C 1F 02 48 */	mulli r0, r31, 0x248
/* 8007319C  7C 03 02 14 */	add r0, r3, r0
/* 800731A0  90 1D 00 10 */	stw r0, 0x10(r29)
/* 800731A4  48 00 00 0C */	b 0xc
/* 800731A8  38 00 00 00 */	li r0, 0
/* 800731AC  90 1D 00 10 */	stw r0, 0x10(r29)
/* 800731B0  80 7E 01 58 */	lwz r3, 0x158(r30)
/* 800731B4  2C 03 00 00 */	cmpwi r3, 0
/* 800731B8  41 82 00 14 */	beq 0x14
/* 800731BC  1C 1F 00 28 */	mulli r0, r31, 0x28
/* 800731C0  7C 03 02 14 */	add r0, r3, r0
/* 800731C4  90 1D 00 14 */	stw r0, 0x14(r29)
/* 800731C8  48 00 00 0C */	b 0xc
/* 800731CC  38 00 00 00 */	li r0, 0
/* 800731D0  90 1D 00 14 */	stw r0, 0x14(r29)
/* 800731D4  80 7E 01 5C */	lwz r3, 0x15c(r30)
/* 800731D8  2C 03 00 00 */	cmpwi r3, 0
/* 800731DC  41 82 00 14 */	beq 0x14
/* 800731E0  57 E0 18 38 */	slwi r0, r31, 3
/* 800731E4  7C 03 02 14 */	add r0, r3, r0
/* 800731E8  90 1D 00 18 */	stw r0, 0x18(r29)
/* 800731EC  48 00 00 0C */	b 0xc
/* 800731F0  38 00 00 00 */	li r0, 0
/* 800731F4  90 1D 00 18 */	stw r0, 0x18(r29)
/* 800731F8  80 7E 01 60 */	lwz r3, 0x160(r30)
/* 800731FC  2C 03 00 00 */	cmpwi r3, 0
/* 80073200  41 82 00 14 */	beq 0x14
/* 80073204  1C 1F 00 0C */	mulli r0, r31, 0xc
/* 80073208  7C 03 02 14 */	add r0, r3, r0
/* 8007320C  90 1D 00 1C */	stw r0, 0x1c(r29)
/* 80073210  48 00 00 0C */	b 0xc
/* 80073214  38 00 00 00 */	li r0, 0
/* 80073218  90 1D 00 1C */	stw r0, 0x1c(r29)
/* 8007321C  80 7E 01 64 */	lwz r3, 0x164(r30)
/* 80073220  2C 03 00 00 */	cmpwi r3, 0
/* 80073224  41 82 00 14 */	beq 0x14
/* 80073228  57 E0 28 34 */	slwi r0, r31, 5
/* 8007322C  7C 03 02 14 */	add r0, r3, r0
/* 80073230  90 1D 00 20 */	stw r0, 0x20(r29)
/* 80073234  48 00 00 0C */	b 0xc
/* 80073238  38 00 00 00 */	li r0, 0
/* 8007323C  90 1D 00 20 */	stw r0, 0x20(r29)
/* 80073240  80 7E 01 68 */	lwz r3, 0x168(r30)
/* 80073244  2C 03 00 00 */	cmpwi r3, 0
/* 80073248  41 82 00 14 */	beq 0x14
/* 8007324C  57 E0 38 30 */	slwi r0, r31, 7
/* 80073250  7C 03 02 14 */	add r0, r3, r0
/* 80073254  90 1D 00 24 */	stw r0, 0x24(r29)
/* 80073258  48 00 00 0C */	b 0xc
/* 8007325C  38 00 00 00 */	li r0, 0
/* 80073260  90 1D 00 24 */	stw r0, 0x24(r29)
/* 80073264  80 7E 01 6C */	lwz r3, 0x16c(r30)
/* 80073268  2C 03 00 00 */	cmpwi r3, 0
/* 8007326C  41 82 00 14 */	beq 0x14
/* 80073270  57 E0 30 32 */	slwi r0, r31, 6
/* 80073274  7C 03 02 14 */	add r0, r3, r0
/* 80073278  90 1D 00 28 */	stw r0, 0x28(r29)
/* 8007327C  48 00 00 0C */	b 0xc
/* 80073280  38 00 00 00 */	li r0, 0
/* 80073284  90 1D 00 28 */	stw r0, 0x28(r29)
/* 80073288  80 7E 01 70 */	lwz r3, 0x170(r30)
/* 8007328C  2C 03 00 00 */	cmpwi r3, 0
/* 80073290  41 82 00 14 */	beq 0x14
/* 80073294  1C 1F 00 A0 */	mulli r0, r31, 0xa0
/* 80073298  7C 03 02 14 */	add r0, r3, r0
/* 8007329C  90 1D 00 2C */	stw r0, 0x2c(r29)
/* 800732A0  48 00 00 0C */	b 0xc
/* 800732A4  38 00 00 00 */	li r0, 0
/* 800732A8  90 1D 00 2C */	stw r0, 0x2c(r29)
/* 800732AC  80 7E 01 74 */	lwz r3, 0x174(r30)
/* 800732B0  2C 03 00 00 */	cmpwi r3, 0
/* 800732B4  41 82 00 14 */	beq 0x14
/* 800732B8  57 E0 48 2C */	slwi r0, r31, 9
/* 800732BC  7C 03 02 14 */	add r0, r3, r0
/* 800732C0  90 1D 00 30 */	stw r0, 0x30(r29)
/* 800732C4  48 00 00 48 */	b 0x48
/* 800732C8  38 00 00 00 */	li r0, 0
/* 800732CC  90 1D 00 30 */	stw r0, 0x30(r29)
/* 800732D0  48 00 00 3C */	b 0x3c
/* 800732D4  38 00 00 00 */	li r0, 0
/* 800732D8  90 1D 00 00 */	stw r0, 0(r29)
/* 800732DC  93 FD 00 04 */	stw r31, 4(r29)
/* 800732E0  90 1D 00 08 */	stw r0, 8(r29)
/* 800732E4  90 1D 00 0C */	stw r0, 0xc(r29)
/* 800732E8  90 1D 00 10 */	stw r0, 0x10(r29)
/* 800732EC  90 1D 00 14 */	stw r0, 0x14(r29)
/* 800732F0  90 1D 00 18 */	stw r0, 0x18(r29)
/* 800732F4  90 1D 00 1C */	stw r0, 0x1c(r29)
/* 800732F8  90 1D 00 20 */	stw r0, 0x20(r29)
/* 800732FC  90 1D 00 24 */	stw r0, 0x24(r29)
/* 80073300  90 1D 00 28 */	stw r0, 0x28(r29)
/* 80073304  90 1D 00 2C */	stw r0, 0x2c(r29)
/* 80073308  90 1D 00 30 */	stw r0, 0x30(r29)
/* 8007330C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80073310  7F A3 EB 78 */	mr r3, r29
/* 80073314  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80073318  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8007331C  83 81 00 10 */	lwz r28, 0x10(r1)
/* 80073320  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80073324  7C 08 03 A6 */	mtlr r0
/* 80073328  38 21 00 20 */	addi r1, r1, 0x20
/* 8007332C  4E 80 00 20 */	blr 
/* 80073330  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80073334  7C 08 02 A6 */	mflr r0
/* 80073338  80 83 00 00 */	lwz r4, 0(r3)
/* 8007333C  7C 65 1B 78 */	mr r5, r3
/* 80073340  90 01 00 14 */	stw r0, 0x14(r1)
/* 80073344  2C 04 00 00 */	cmpwi r4, 0
/* 80073348  41 82 00 54 */	beq 0x54
/* 8007334C  80 63 00 08 */	lwz r3, 8(r3)
/* 80073350  2C 03 00 00 */	cmpwi r3, 0
/* 80073354  41 82 00 18 */	beq 0x18
/* 80073358  88 63 00 00 */	lbz r3, 0(r3)
/* 8007335C  7C 03 00 D0 */	neg r0, r3
/* 80073360  7C 00 1B 78 */	or r0, r0, r3
/* 80073364  54 03 0F FE */	srwi r3, r0, 0x1f
/* 80073368  48 00 00 38 */	b 0x38
/* 8007336C  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 80073370  38 61 00 08 */	addi r3, r1, 8
/* 80073374  90 01 00 08 */	stw r0, 8(r1)
/* 80073378  80 85 00 04 */	lwz r4, 4(r5)
/* 8007337C  4B FD B0 25 */	bl -0x24fdc
/* 80073380  2C 03 00 00 */	cmpwi r3, 0
/* 80073384  41 82 00 10 */	beq 0x10
/* 80073388  80 03 00 14 */	lwz r0, 0x14(r3)
/* 8007338C  54 03 C7 FE */	rlwinm r3, r0, 0x18, 0x1f, 0x1f
/* 80073390  48 00 00 10 */	b 0x10
/* 80073394  38 60 00 00 */	li r3, 0
/* 80073398  48 00 00 08 */	b 0x8
/* 8007339C  38 60 00 00 */	li r3, 0
/* 800733A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800733A4  7C 08 03 A6 */	mtlr r0
/* 800733A8  38 21 00 10 */	addi r1, r1, 0x10
/* 800733AC  4E 80 00 20 */	blr 
/* 800733B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800733B4  7C 08 02 A6 */	mflr r0
/* 800733B8  2C 04 00 00 */	cmpwi r4, 0
/* 800733BC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800733C0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800733C4  3B E0 00 00 */	li r31, 0
/* 800733C8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800733CC  7C BE 2B 78 */	mr r30, r5
/* 800733D0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800733D4  7C 9D 23 78 */	mr r29, r4
/* 800733D8  93 81 00 10 */	stw r28, 0x10(r1)
/* 800733DC  7C 7C 1B 78 */	mr r28, r3
/* 800733E0  41 82 00 24 */	beq 0x24
/* 800733E4  80 04 00 E8 */	lwz r0, 0xe8(r4)
/* 800733E8  7F C4 F3 78 */	mr r4, r30
/* 800733EC  90 01 00 08 */	stw r0, 8(r1)
/* 800733F0  38 61 00 08 */	addi r3, r1, 8
/* 800733F4  4B FD AF AD */	bl -0x25054
/* 800733F8  2C 03 00 00 */	cmpwi r3, 0
/* 800733FC  41 82 00 08 */	beq 0x8
/* 80073400  3B E0 00 01 */	li r31, 1
/* 80073404  2C 1F 00 00 */	cmpwi r31, 0
/* 80073408  41 82 00 30 */	beq 0x30
/* 8007340C  93 BC 00 00 */	stw r29, 0(r28)
/* 80073410  93 DC 00 04 */	stw r30, 4(r28)
/* 80073414  80 1D 01 48 */	lwz r0, 0x148(r29)
/* 80073418  2C 00 00 00 */	cmpwi r0, 0
/* 8007341C  41 82 00 10 */	beq 0x10
/* 80073420  7C 00 F2 14 */	add r0, r0, r30
/* 80073424  90 1C 00 08 */	stw r0, 8(r28)
/* 80073428  48 00 00 20 */	b 0x20
/* 8007342C  38 00 00 00 */	li r0, 0
/* 80073430  90 1C 00 08 */	stw r0, 8(r28)
/* 80073434  48 00 00 14 */	b 0x14
/* 80073438  38 00 00 00 */	li r0, 0
/* 8007343C  90 1C 00 00 */	stw r0, 0(r28)
/* 80073440  93 DC 00 04 */	stw r30, 4(r28)
/* 80073444  90 1C 00 08 */	stw r0, 8(r28)
/* 80073448  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8007344C  7F 83 E3 78 */	mr r3, r28
/* 80073450  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80073454  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80073458  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8007345C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80073460  7C 08 03 A6 */	mtlr r0
/* 80073464  38 21 00 20 */	addi r1, r1, 0x20
/* 80073468  4E 80 00 20 */	blr 
/* 8007346C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80073470  94 21 FE B0 */	stwu r1, -0x150(r1)
/* 80073474  7C 08 02 A6 */	mflr r0
/* 80073478  90 01 01 54 */	stw r0, 0x154(r1)
/* 8007347C  39 61 01 50 */	addi r11, r1, 0x150
/* 80073480  4B FA E0 ED */	bl -0x51f14
/* 80073484  81 05 00 00 */	lwz r8, 0(r5)
/* 80073488  7C 7C 1B 78 */	mr r28, r3
/* 8007348C  90 81 00 10 */	stw r4, 0x10(r1)
/* 80073490  7C BD 2B 78 */	mr r29, r5
/* 80073494  2C 08 00 00 */	cmpwi r8, 0
/* 80073498  7C DE 33 78 */	mr r30, r6
/* 8007349C  7C FF 3B 78 */	mr r31, r7
/* 800734A0  40 82 00 0C */	bne 0xc
/* 800734A4  38 60 00 00 */	li r3, 0
/* 800734A8  48 00 0B 38 */	b 0xb38
/* 800734AC  2C 07 00 00 */	cmpwi r7, 0
/* 800734B0  40 82 00 0C */	bne 0xc
/* 800734B4  3B E0 00 01 */	li r31, 1
/* 800734B8  48 00 00 10 */	b 0x10
/* 800734BC  2C 07 00 10 */	cmpwi r7, 0x10
/* 800734C0  40 81 00 08 */	ble 0x8
/* 800734C4  3B E0 00 10 */	li r31, 0x10
/* 800734C8  80 08 00 70 */	lwz r0, 0x70(r8)
/* 800734CC  38 88 00 4C */	addi r4, r8, 0x4c
/* 800734D0  83 68 00 68 */	lwz r27, 0x68(r8)
/* 800734D4  7F A3 EB 78 */	mr r3, r29
/* 800734D8  7D E4 00 2E */	lwzx r15, r4, r0
/* 800734DC  3A 00 00 00 */	li r16, 0
/* 800734E0  4B FD B5 71 */	bl -0x24a90
/* 800734E4  7C 6E 1B 78 */	mr r14, r3
/* 800734E8  7F A3 EB 78 */	mr r3, r29
/* 800734EC  4B FD AF 15 */	bl -0x250ec
/* 800734F0  1C BB 00 30 */	mulli r5, r27, 0x30
/* 800734F4  80 DD 00 00 */	lwz r6, 0(r29)
/* 800734F8  55 FA 10 3A */	slwi r26, r15, 2
/* 800734FC  88 06 00 6C */	lbz r0, 0x6c(r6)
/* 80073500  38 A5 00 1F */	addi r5, r5, 0x1f
/* 80073504  54 A4 00 34 */	rlwinm r4, r5, 0, 0, 0x1a
/* 80073508  2C 00 00 00 */	cmpwi r0, 0
/* 8007350C  7E FF 21 D6 */	mullw r23, r31, r4
/* 80073510  1C 0F 00 30 */	mulli r0, r15, 0x30
/* 80073514  90 01 00 8C */	stw r0, 0x8c(r1)
/* 80073518  1C 9B 00 24 */	mulli r4, r27, 0x24
/* 8007351C  41 82 00 18 */	beq 0x18
/* 80073520  38 04 00 1F */	addi r0, r4, 0x1f
/* 80073524  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80073528  7C 1F 01 D6 */	mullw r0, r31, r0
/* 8007352C  90 01 00 F8 */	stw r0, 0xf8(r1)
/* 80073530  48 00 00 0C */	b 0xc
/* 80073534  38 00 00 00 */	li r0, 0
/* 80073538  90 01 00 F8 */	stw r0, 0xf8(r1)
/* 8007353C  57 C0 07 FF */	clrlwi. r0, r30, 0x1f
/* 80073540  88 86 00 6D */	lbz r4, 0x6d(r6)
/* 80073544  55 C0 10 3A */	slwi r0, r14, 2
/* 80073548  90 01 00 88 */	stw r0, 0x88(r1)
/* 8007354C  7C 04 00 D0 */	neg r0, r4
/* 80073550  7C 00 23 78 */	or r0, r0, r4
/* 80073554  7C 00 FE 70 */	srawi r0, r0, 0x1f
/* 80073558  7E E0 00 38 */	and r0, r23, r0
/* 8007355C  90 01 00 F4 */	stw r0, 0xf4(r1)
/* 80073560  41 82 00 10 */	beq 0x10
/* 80073564  1C 0E 01 04 */	mulli r0, r14, 0x104
/* 80073568  90 01 00 F0 */	stw r0, 0xf0(r1)
/* 8007356C  48 00 00 0C */	b 0xc
/* 80073570  38 00 00 00 */	li r0, 0
/* 80073574  90 01 00 F0 */	stw r0, 0xf0(r1)
/* 80073578  57 C0 07 BD */	rlwinm. r0, r30, 0, 0x1e, 0x1e
/* 8007357C  41 82 00 10 */	beq 0x10
/* 80073580  1C 0E 00 64 */	mulli r0, r14, 0x64
/* 80073584  90 01 00 EC */	stw r0, 0xec(r1)
/* 80073588  48 00 00 0C */	b 0xc
/* 8007358C  38 00 00 00 */	li r0, 0
/* 80073590  90 01 00 EC */	stw r0, 0xec(r1)
/* 80073594  57 C0 07 7B */	rlwinm. r0, r30, 0, 0x1d, 0x1d
/* 80073598  41 82 00 10 */	beq 0x10
/* 8007359C  1C 0E 02 48 */	mulli r0, r14, 0x248
/* 800735A0  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 800735A4  48 00 00 0C */	b 0xc
/* 800735A8  38 00 00 00 */	li r0, 0
/* 800735AC  90 01 00 E8 */	stw r0, 0xe8(r1)
/* 800735B0  57 C0 07 39 */	rlwinm. r0, r30, 0, 0x1c, 0x1c
/* 800735B4  41 82 00 10 */	beq 0x10
/* 800735B8  1C 0E 00 28 */	mulli r0, r14, 0x28
/* 800735BC  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 800735C0  48 00 00 0C */	b 0xc
/* 800735C4  38 00 00 00 */	li r0, 0
/* 800735C8  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 800735CC  57 C0 06 B5 */	rlwinm. r0, r30, 0, 0x1a, 0x1a
/* 800735D0  57 C4 E7 FE */	rlwinm r4, r30, 0x1c, 0x1f, 0x1f
/* 800735D4  55 C0 18 38 */	slwi r0, r14, 3
/* 800735D8  7C 84 00 D0 */	neg r4, r4
/* 800735DC  7C 00 20 38 */	and r0, r0, r4
/* 800735E0  90 01 00 E0 */	stw r0, 0xe0(r1)
/* 800735E4  41 82 00 10 */	beq 0x10
/* 800735E8  1C 0E 00 0C */	mulli r0, r14, 0xc
/* 800735EC  90 01 00 DC */	stw r0, 0xdc(r1)
/* 800735F0  48 00 00 0C */	b 0xc
/* 800735F4  38 00 00 00 */	li r0, 0
/* 800735F8  90 01 00 DC */	stw r0, 0xdc(r1)
/* 800735FC  57 C0 05 6B */	rlwinm. r0, r30, 0, 0x15, 0x15
/* 80073600  57 C6 D7 FE */	rlwinm r6, r30, 0x1a, 0x1f, 0x1f
/* 80073604  57 C5 CF FE */	rlwinm r5, r30, 0x19, 0x1f, 0x1f
/* 80073608  57 C4 C7 FE */	rlwinm r4, r30, 0x18, 0x1f, 0x1f
/* 8007360C  57 C0 BF FE */	rlwinm r0, r30, 0x17, 0x1f, 0x1f
/* 80073610  7D 46 00 D0 */	neg r10, r6
/* 80073614  7D 25 00 D0 */	neg r9, r5
/* 80073618  7C E4 00 D0 */	neg r7, r4
/* 8007361C  7C A0 00 D0 */	neg r5, r0
/* 80073620  7C 60 50 38 */	and r0, r3, r10
/* 80073624  55 C8 28 34 */	slwi r8, r14, 5
/* 80073628  90 01 00 D8 */	stw r0, 0xd8(r1)
/* 8007362C  7D 00 48 38 */	and r0, r8, r9
/* 80073630  55 C6 38 30 */	slwi r6, r14, 7
/* 80073634  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 80073638  7C C0 38 38 */	and r0, r6, r7
/* 8007363C  55 C4 30 32 */	slwi r4, r14, 6
/* 80073640  90 01 00 D0 */	stw r0, 0xd0(r1)
/* 80073644  7C 80 28 38 */	and r0, r4, r5
/* 80073648  90 01 00 CC */	stw r0, 0xcc(r1)
/* 8007364C  41 82 00 10 */	beq 0x10
/* 80073650  1C 0E 00 A0 */	mulli r0, r14, 0xa0
/* 80073654  90 01 00 C8 */	stw r0, 0xc8(r1)
/* 80073658  48 00 00 0C */	b 0xc
/* 8007365C  38 00 00 00 */	li r0, 0
/* 80073660  90 01 00 C8 */	stw r0, 0xc8(r1)
/* 80073664  57 C0 04 E7 */	rlwinm. r0, r30, 0, 0x13, 0x13
/* 80073668  55 C3 48 2C */	slwi r3, r14, 9
/* 8007366C  57 C0 AF FE */	rlwinm r0, r30, 0x15, 0x1f, 0x1f
/* 80073670  3A C0 00 00 */	li r22, 0
/* 80073674  7C 80 00 D0 */	neg r4, r0
/* 80073678  38 00 00 00 */	li r0, 0
/* 8007367C  90 01 00 84 */	stw r0, 0x84(r1)
/* 80073680  7C 60 20 38 */	and r0, r3, r4
/* 80073684  90 01 00 C4 */	stw r0, 0xc4(r1)
/* 80073688  41 82 00 94 */	beq 0x94
/* 8007368C  7F A3 EB 78 */	mr r3, r29
/* 80073690  4B FD AE C1 */	bl -0x25140
/* 80073694  7C 71 1B 78 */	mr r17, r3
/* 80073698  7F A3 EB 78 */	mr r3, r29
/* 8007369C  4B FD B4 B5 */	bl -0x24b4c
/* 800736A0  56 20 10 3A */	slwi r0, r17, 2
/* 800736A4  90 01 00 84 */	stw r0, 0x84(r1)
/* 800736A8  7C 6F 1B 78 */	mr r15, r3
/* 800736AC  3A 40 00 00 */	li r18, 0
/* 800736B0  48 00 00 64 */	b 0x64
/* 800736B4  7F A3 EB 78 */	mr r3, r29
/* 800736B8  7E 44 93 78 */	mr r4, r18
/* 800736BC  4B FD AE 35 */	bl -0x251cc
/* 800736C0  7C 6E 1B 78 */	mr r14, r3
/* 800736C4  3A 60 00 00 */	li r19, 0
/* 800736C8  48 00 00 28 */	b 0x28
/* 800736CC  7F A3 EB 78 */	mr r3, r29
/* 800736D0  7E 64 9B 78 */	mr r4, r19
/* 800736D4  4B FD B4 1D */	bl -0x24be4
/* 800736D8  90 61 00 38 */	stw r3, 0x38(r1)
/* 800736DC  38 61 00 38 */	addi r3, r1, 0x38
/* 800736E0  4B FD BC F1 */	bl -0x24310
/* 800736E4  7C 0E 18 40 */	cmplw r14, r3
/* 800736E8  41 82 00 10 */	beq 0x10
/* 800736EC  3A 73 00 01 */	addi r19, r19, 1
/* 800736F0  7C 13 78 40 */	cmplw r19, r15
/* 800736F4  41 80 FF D8 */	blt -0x28
/* 800736F8  7C 13 78 40 */	cmplw r19, r15
/* 800736FC  41 82 00 14 */	beq 0x14
/* 80073700  80 6E 00 00 */	lwz r3, 0(r14)
/* 80073704  38 03 00 1F */	addi r0, r3, 0x1f
/* 80073708  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 8007370C  7E D6 02 14 */	add r22, r22, r0
/* 80073710  3A 52 00 01 */	addi r18, r18, 1
/* 80073714  7C 12 88 40 */	cmplw r18, r17
/* 80073718  41 80 FF 9C */	blt -0x64
/* 8007371C  57 C0 04 A5 */	rlwinm. r0, r30, 0, 0x12, 0x12
/* 80073720  3A A0 00 00 */	li r21, 0
/* 80073724  38 00 00 00 */	li r0, 0
/* 80073728  90 01 00 80 */	stw r0, 0x80(r1)
/* 8007372C  41 82 00 94 */	beq 0x94
/* 80073730  7F A3 EB 78 */	mr r3, r29
/* 80073734  4B FD AF 6D */	bl -0x25094
/* 80073738  7C 71 1B 78 */	mr r17, r3
/* 8007373C  7F A3 EB 78 */	mr r3, r29
/* 80073740  4B FD B4 11 */	bl -0x24bf0
/* 80073744  56 20 10 3A */	slwi r0, r17, 2
/* 80073748  90 01 00 80 */	stw r0, 0x80(r1)
/* 8007374C  7C 6F 1B 78 */	mr r15, r3
/* 80073750  3A 40 00 00 */	li r18, 0
/* 80073754  48 00 00 64 */	b 0x64
/* 80073758  7F A3 EB 78 */	mr r3, r29
/* 8007375C  7E 44 93 78 */	mr r4, r18
/* 80073760  4B FD AE E1 */	bl -0x25120
/* 80073764  7C 6E 1B 78 */	mr r14, r3
/* 80073768  3A 60 00 00 */	li r19, 0
/* 8007376C  48 00 00 28 */	b 0x28
/* 80073770  7F A3 EB 78 */	mr r3, r29
/* 80073774  7E 64 9B 78 */	mr r4, r19
/* 80073778  4B FD B3 79 */	bl -0x24c88
/* 8007377C  90 61 00 34 */	stw r3, 0x34(r1)
/* 80073780  38 61 00 34 */	addi r3, r1, 0x34
/* 80073784  4B FD BC 9D */	bl -0x24364
/* 80073788  7C 0E 18 40 */	cmplw r14, r3
/* 8007378C  41 82 00 10 */	beq 0x10
/* 80073790  3A 73 00 01 */	addi r19, r19, 1
/* 80073794  7C 13 78 40 */	cmplw r19, r15
/* 80073798  41 80 FF D8 */	blt -0x28
/* 8007379C  7C 13 78 40 */	cmplw r19, r15
/* 800737A0  41 82 00 14 */	beq 0x14
/* 800737A4  80 6E 00 00 */	lwz r3, 0(r14)
/* 800737A8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800737AC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800737B0  7E B5 02 14 */	add r21, r21, r0
/* 800737B4  3A 52 00 01 */	addi r18, r18, 1
/* 800737B8  7C 12 88 40 */	cmplw r18, r17
/* 800737BC  41 80 FF 9C */	blt -0x64
/* 800737C0  57 C0 04 63 */	rlwinm. r0, r30, 0, 0x11, 0x11
/* 800737C4  3A 80 00 00 */	li r20, 0
/* 800737C8  3A 60 00 00 */	li r19, 0
/* 800737CC  41 82 00 B8 */	beq 0xb8
/* 800737D0  7F A3 EB 78 */	mr r3, r29
/* 800737D4  4B FD B0 1D */	bl -0x24fe4
/* 800737D8  7C 71 1B 78 */	mr r17, r3
/* 800737DC  7F A3 EB 78 */	mr r3, r29
/* 800737E0  4B FD B3 71 */	bl -0x24c90
/* 800737E4  7C 6F 1B 78 */	mr r15, r3
/* 800737E8  56 34 10 3A */	slwi r20, r17, 2
/* 800737EC  3B 00 00 00 */	li r24, 0
/* 800737F0  48 00 00 8C */	b 0x8c
/* 800737F4  7F A3 EB 78 */	mr r3, r29
/* 800737F8  7F 04 C3 78 */	mr r4, r24
/* 800737FC  4B FD AF 95 */	bl -0x2506c
/* 80073800  7C 6E 1B 78 */	mr r14, r3
/* 80073804  3B 20 00 00 */	li r25, 0
/* 80073808  48 00 00 50 */	b 0x50
/* 8007380C  7F A3 EB 78 */	mr r3, r29
/* 80073810  7F 24 CB 78 */	mr r4, r25
/* 80073814  4B FD B2 DD */	bl -0x24d24
/* 80073818  90 61 00 30 */	stw r3, 0x30(r1)
/* 8007381C  38 61 00 30 */	addi r3, r1, 0x30
/* 80073820  3A 40 00 01 */	li r18, 1
/* 80073824  38 80 00 00 */	li r4, 0
/* 80073828  4B FD BC 59 */	bl -0x243a8
/* 8007382C  7C 0E 18 40 */	cmplw r14, r3
/* 80073830  41 82 00 1C */	beq 0x1c
/* 80073834  38 61 00 30 */	addi r3, r1, 0x30
/* 80073838  38 80 00 01 */	li r4, 1
/* 8007383C  4B FD BC 45 */	bl -0x243bc
/* 80073840  7C 0E 18 40 */	cmplw r14, r3
/* 80073844  41 82 00 08 */	beq 0x8
/* 80073848  3A 40 00 00 */	li r18, 0
/* 8007384C  2C 12 00 00 */	cmpwi r18, 0
/* 80073850  40 82 00 10 */	bne 0x10
/* 80073854  3B 39 00 01 */	addi r25, r25, 1
/* 80073858  7C 19 78 40 */	cmplw r25, r15
/* 8007385C  41 80 FF B0 */	blt -0x50
/* 80073860  7C 19 78 40 */	cmplw r25, r15
/* 80073864  41 82 00 14 */	beq 0x14
/* 80073868  80 6E 00 00 */	lwz r3, 0(r14)
/* 8007386C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80073870  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80073874  7E 73 02 14 */	add r19, r19, r0
/* 80073878  3B 18 00 01 */	addi r24, r24, 1
/* 8007387C  7C 18 88 40 */	cmplw r24, r17
/* 80073880  41 80 FF 74 */	blt -0x8c
/* 80073884  80 61 00 8C */	lwz r3, 0x8c(r1)
/* 80073888  80 01 00 10 */	lwz r0, 0x10(r1)
/* 8007388C  38 63 01 BF */	addi r3, r3, 0x1bf
/* 80073890  2C 00 00 00 */	cmpwi r0, 0
/* 80073894  54 60 00 34 */	rlwinm r0, r3, 0, 0, 0x1a
/* 80073898  90 01 00 C0 */	stw r0, 0xc0(r1)
/* 8007389C  7C 60 D2 14 */	add r3, r0, r26
/* 800738A0  38 03 00 1F */	addi r0, r3, 0x1f
/* 800738A4  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800738A8  90 01 00 BC */	stw r0, 0xbc(r1)
/* 800738AC  7C 60 BA 14 */	add r3, r0, r23
/* 800738B0  38 03 00 1F */	addi r0, r3, 0x1f
/* 800738B4  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800738B8  90 01 00 B8 */	stw r0, 0xb8(r1)
/* 800738BC  7C 03 03 78 */	mr r3, r0
/* 800738C0  80 01 00 F8 */	lwz r0, 0xf8(r1)
/* 800738C4  7C 63 02 14 */	add r3, r3, r0
/* 800738C8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800738CC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800738D0  90 01 00 B4 */	stw r0, 0xb4(r1)
/* 800738D4  7C 03 03 78 */	mr r3, r0
/* 800738D8  80 01 00 F4 */	lwz r0, 0xf4(r1)
/* 800738DC  7C 63 02 14 */	add r3, r3, r0
/* 800738E0  38 03 00 03 */	addi r0, r3, 3
/* 800738E4  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 800738E8  90 01 00 B0 */	stw r0, 0xb0(r1)
/* 800738EC  7C 03 03 78 */	mr r3, r0
/* 800738F0  80 01 00 88 */	lwz r0, 0x88(r1)
/* 800738F4  7C 63 02 14 */	add r3, r3, r0
/* 800738F8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800738FC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80073900  90 01 00 AC */	stw r0, 0xac(r1)
/* 80073904  7C 03 03 78 */	mr r3, r0
/* 80073908  80 01 00 F0 */	lwz r0, 0xf0(r1)
/* 8007390C  7C 63 02 14 */	add r3, r3, r0
/* 80073910  38 03 00 03 */	addi r0, r3, 3
/* 80073914  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80073918  90 01 00 A8 */	stw r0, 0xa8(r1)
/* 8007391C  7C 03 03 78 */	mr r3, r0
/* 80073920  80 01 00 EC */	lwz r0, 0xec(r1)
/* 80073924  7C 63 02 14 */	add r3, r3, r0
/* 80073928  38 03 00 03 */	addi r0, r3, 3
/* 8007392C  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80073930  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 80073934  7C 03 03 78 */	mr r3, r0
/* 80073938  80 01 00 E8 */	lwz r0, 0xe8(r1)
/* 8007393C  7C 63 02 14 */	add r3, r3, r0
/* 80073940  38 03 00 03 */	addi r0, r3, 3
/* 80073944  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80073948  90 01 00 A0 */	stw r0, 0xa0(r1)
/* 8007394C  7C 03 03 78 */	mr r3, r0
/* 80073950  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 80073954  7C 63 02 14 */	add r3, r3, r0
/* 80073958  38 03 00 03 */	addi r0, r3, 3
/* 8007395C  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80073960  90 01 00 9C */	stw r0, 0x9c(r1)
/* 80073964  7C 03 03 78 */	mr r3, r0
/* 80073968  80 01 00 E0 */	lwz r0, 0xe0(r1)
/* 8007396C  7C 63 02 14 */	add r3, r3, r0
/* 80073970  38 03 00 03 */	addi r0, r3, 3
/* 80073974  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80073978  90 01 00 98 */	stw r0, 0x98(r1)
/* 8007397C  7C 03 03 78 */	mr r3, r0
/* 80073980  80 01 00 DC */	lwz r0, 0xdc(r1)
/* 80073984  7C 63 02 14 */	add r3, r3, r0
/* 80073988  38 03 00 03 */	addi r0, r3, 3
/* 8007398C  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80073990  90 01 00 94 */	stw r0, 0x94(r1)
/* 80073994  7C 03 03 78 */	mr r3, r0
/* 80073998  80 01 00 D8 */	lwz r0, 0xd8(r1)
/* 8007399C  7C 63 02 14 */	add r3, r3, r0
/* 800739A0  38 03 00 1F */	addi r0, r3, 0x1f
/* 800739A4  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 800739A8  90 01 00 90 */	stw r0, 0x90(r1)
/* 800739AC  7C 03 03 78 */	mr r3, r0
/* 800739B0  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 800739B4  7C 63 02 14 */	add r3, r3, r0
/* 800739B8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800739BC  54 0E 00 34 */	rlwinm r14, r0, 0, 0, 0x1a
/* 800739C0  80 01 00 D0 */	lwz r0, 0xd0(r1)
/* 800739C4  7C 6E 02 14 */	add r3, r14, r0
/* 800739C8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800739CC  54 1A 00 34 */	rlwinm r26, r0, 0, 0, 0x1a
/* 800739D0  80 01 00 CC */	lwz r0, 0xcc(r1)
/* 800739D4  7C 7A 02 14 */	add r3, r26, r0
/* 800739D8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800739DC  54 19 00 34 */	rlwinm r25, r0, 0, 0, 0x1a
/* 800739E0  80 01 00 C8 */	lwz r0, 0xc8(r1)
/* 800739E4  7C 79 02 14 */	add r3, r25, r0
/* 800739E8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800739EC  54 18 00 34 */	rlwinm r24, r0, 0, 0, 0x1a
/* 800739F0  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 800739F4  7C 78 02 14 */	add r3, r24, r0
/* 800739F8  38 03 00 1F */	addi r0, r3, 0x1f
/* 800739FC  54 17 00 34 */	rlwinm r23, r0, 0, 0, 0x1a
/* 80073A00  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80073A04  7E 57 02 14 */	add r18, r23, r0
/* 80073A08  80 01 00 80 */	lwz r0, 0x80(r1)
/* 80073A0C  7E 32 02 14 */	add r17, r18, r0
/* 80073A10  7C 71 A2 14 */	add r3, r17, r20
/* 80073A14  38 03 00 1F */	addi r0, r3, 0x1f
/* 80073A18  54 0F 00 34 */	rlwinm r15, r0, 0, 0, 0x1a
/* 80073A1C  7C 6F B2 14 */	add r3, r15, r22
/* 80073A20  38 03 00 1F */	addi r0, r3, 0x1f
/* 80073A24  54 16 00 34 */	rlwinm r22, r0, 0, 0, 0x1a
/* 80073A28  7C 76 AA 14 */	add r3, r22, r21
/* 80073A2C  38 03 00 1F */	addi r0, r3, 0x1f
/* 80073A30  54 15 00 34 */	rlwinm r21, r0, 0, 0, 0x1a
/* 80073A34  7C 75 9A 14 */	add r3, r21, r19
/* 80073A38  38 03 00 1F */	addi r0, r3, 0x1f
/* 80073A3C  54 04 00 34 */	rlwinm r4, r0, 0, 0, 0x1a
/* 80073A40  41 82 00 0C */	beq 0xc
/* 80073A44  80 61 00 10 */	lwz r3, 0x10(r1)
/* 80073A48  90 83 00 00 */	stw r4, 0(r3)
/* 80073A4C  2C 1C 00 00 */	cmpwi r28, 0
/* 80073A50  41 82 05 8C */	beq 0x58c
/* 80073A54  7F 83 E3 78 */	mr r3, r28
/* 80073A58  48 12 61 41 */	bl 0x126140
/* 80073A5C  2C 03 00 00 */	cmpwi r3, 0
/* 80073A60  7C 70 1B 78 */	mr r16, r3
/* 80073A64  40 82 00 0C */	bne 0xc
/* 80073A68  38 60 00 00 */	li r3, 0
/* 80073A6C  48 00 05 74 */	b 0x574
/* 80073A70  57 D3 01 CF */	rlwinm. r19, r30, 0, 7, 7
/* 80073A74  38 00 00 00 */	li r0, 0
/* 80073A78  90 01 00 40 */	stw r0, 0x40(r1)
/* 80073A7C  40 82 00 0C */	bne 0xc
/* 80073A80  60 00 00 01 */	ori r0, r0, 1
/* 80073A84  90 01 00 40 */	stw r0, 0x40(r1)
/* 80073A88  80 01 00 D8 */	lwz r0, 0xd8(r1)
/* 80073A8C  2C 00 00 00 */	cmpwi r0, 0
/* 80073A90  41 82 00 10 */	beq 0x10
/* 80073A94  80 01 00 94 */	lwz r0, 0x94(r1)
/* 80073A98  7C 83 02 14 */	add r4, r3, r0
/* 80073A9C  48 00 00 08 */	b 0x8
/* 80073AA0  38 80 00 00 */	li r4, 0
/* 80073AA4  80 01 00 F0 */	lwz r0, 0xf0(r1)
/* 80073AA8  90 81 00 44 */	stw r4, 0x44(r1)
/* 80073AAC  2C 00 00 00 */	cmpwi r0, 0
/* 80073AB0  41 82 00 10 */	beq 0x10
/* 80073AB4  80 01 00 AC */	lwz r0, 0xac(r1)
/* 80073AB8  7C 83 02 14 */	add r4, r3, r0
/* 80073ABC  48 00 00 08 */	b 0x8
/* 80073AC0  38 80 00 00 */	li r4, 0
/* 80073AC4  80 01 00 EC */	lwz r0, 0xec(r1)
/* 80073AC8  90 81 00 48 */	stw r4, 0x48(r1)
/* 80073ACC  2C 00 00 00 */	cmpwi r0, 0
/* 80073AD0  41 82 00 10 */	beq 0x10
/* 80073AD4  80 01 00 A8 */	lwz r0, 0xa8(r1)
/* 80073AD8  7C 83 02 14 */	add r4, r3, r0
/* 80073ADC  48 00 00 08 */	b 0x8
/* 80073AE0  38 80 00 00 */	li r4, 0
/* 80073AE4  80 01 00 E8 */	lwz r0, 0xe8(r1)
/* 80073AE8  90 81 00 4C */	stw r4, 0x4c(r1)
/* 80073AEC  2C 00 00 00 */	cmpwi r0, 0
/* 80073AF0  41 82 00 10 */	beq 0x10
/* 80073AF4  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 80073AF8  7C 83 02 14 */	add r4, r3, r0
/* 80073AFC  48 00 00 08 */	b 0x8
/* 80073B00  38 80 00 00 */	li r4, 0
/* 80073B04  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 80073B08  90 81 00 50 */	stw r4, 0x50(r1)
/* 80073B0C  2C 00 00 00 */	cmpwi r0, 0
/* 80073B10  41 82 00 10 */	beq 0x10
/* 80073B14  80 01 00 A0 */	lwz r0, 0xa0(r1)
/* 80073B18  7C 83 02 14 */	add r4, r3, r0
/* 80073B1C  48 00 00 08 */	b 0x8
/* 80073B20  38 80 00 00 */	li r4, 0
/* 80073B24  80 01 00 E0 */	lwz r0, 0xe0(r1)
/* 80073B28  90 81 00 54 */	stw r4, 0x54(r1)
/* 80073B2C  2C 00 00 00 */	cmpwi r0, 0
/* 80073B30  41 82 00 10 */	beq 0x10
/* 80073B34  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 80073B38  7C 83 02 14 */	add r4, r3, r0
/* 80073B3C  48 00 00 08 */	b 0x8
/* 80073B40  38 80 00 00 */	li r4, 0
/* 80073B44  80 01 00 DC */	lwz r0, 0xdc(r1)
/* 80073B48  90 81 00 58 */	stw r4, 0x58(r1)
/* 80073B4C  2C 00 00 00 */	cmpwi r0, 0
/* 80073B50  41 82 00 10 */	beq 0x10
/* 80073B54  80 01 00 98 */	lwz r0, 0x98(r1)
/* 80073B58  7C 83 02 14 */	add r4, r3, r0
/* 80073B5C  48 00 00 08 */	b 0x8
/* 80073B60  38 80 00 00 */	li r4, 0
/* 80073B64  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 80073B68  90 81 00 5C */	stw r4, 0x5c(r1)
/* 80073B6C  2C 00 00 00 */	cmpwi r0, 0
/* 80073B70  41 82 00 10 */	beq 0x10
/* 80073B74  80 01 00 90 */	lwz r0, 0x90(r1)
/* 80073B78  7C 83 02 14 */	add r4, r3, r0
/* 80073B7C  48 00 00 08 */	b 0x8
/* 80073B80  38 80 00 00 */	li r4, 0
/* 80073B84  80 01 00 D0 */	lwz r0, 0xd0(r1)
/* 80073B88  90 81 00 60 */	stw r4, 0x60(r1)
/* 80073B8C  2C 00 00 00 */	cmpwi r0, 0
/* 80073B90  41 82 00 0C */	beq 0xc
/* 80073B94  7C 83 72 14 */	add r4, r3, r14
/* 80073B98  48 00 00 08 */	b 0x8
/* 80073B9C  38 80 00 00 */	li r4, 0
/* 80073BA0  80 01 00 CC */	lwz r0, 0xcc(r1)
/* 80073BA4  90 81 00 64 */	stw r4, 0x64(r1)
/* 80073BA8  2C 00 00 00 */	cmpwi r0, 0
/* 80073BAC  41 82 00 0C */	beq 0xc
/* 80073BB0  7C 83 D2 14 */	add r4, r3, r26
/* 80073BB4  48 00 00 08 */	b 0x8
/* 80073BB8  38 80 00 00 */	li r4, 0
/* 80073BBC  80 01 00 C8 */	lwz r0, 0xc8(r1)
/* 80073BC0  90 81 00 68 */	stw r4, 0x68(r1)
/* 80073BC4  2C 00 00 00 */	cmpwi r0, 0
/* 80073BC8  41 82 00 0C */	beq 0xc
/* 80073BCC  7C 83 CA 14 */	add r4, r3, r25
/* 80073BD0  48 00 00 08 */	b 0x8
/* 80073BD4  38 80 00 00 */	li r4, 0
/* 80073BD8  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 80073BDC  90 81 00 6C */	stw r4, 0x6c(r1)
/* 80073BE0  2C 00 00 00 */	cmpwi r0, 0
/* 80073BE4  41 82 00 0C */	beq 0xc
/* 80073BE8  7C 83 C2 14 */	add r4, r3, r24
/* 80073BEC  48 00 00 08 */	b 0x8
/* 80073BF0  38 80 00 00 */	li r4, 0
/* 80073BF4  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80073BF8  90 81 00 70 */	stw r4, 0x70(r1)
/* 80073BFC  2C 00 00 00 */	cmpwi r0, 0
/* 80073C00  41 82 00 0C */	beq 0xc
/* 80073C04  7C 83 BA 14 */	add r4, r3, r23
/* 80073C08  48 00 00 08 */	b 0x8
/* 80073C0C  38 80 00 00 */	li r4, 0
/* 80073C10  80 01 00 80 */	lwz r0, 0x80(r1)
/* 80073C14  90 81 00 74 */	stw r4, 0x74(r1)
/* 80073C18  2C 00 00 00 */	cmpwi r0, 0
/* 80073C1C  41 82 00 0C */	beq 0xc
/* 80073C20  7C 03 92 14 */	add r0, r3, r18
/* 80073C24  48 00 00 08 */	b 0x8
/* 80073C28  38 00 00 00 */	li r0, 0
/* 80073C2C  2C 14 00 00 */	cmpwi r20, 0
/* 80073C30  90 01 00 78 */	stw r0, 0x78(r1)
/* 80073C34  41 82 00 0C */	beq 0xc
/* 80073C38  7C 03 8A 14 */	add r0, r3, r17
/* 80073C3C  48 00 00 08 */	b 0x8
/* 80073C40  38 00 00 00 */	li r0, 0
/* 80073C44  82 41 00 74 */	lwz r18, 0x74(r1)
/* 80073C48  90 01 00 7C */	stw r0, 0x7c(r1)
/* 80073C4C  2C 12 00 00 */	cmpwi r18, 0
/* 80073C50  41 82 00 B4 */	beq 0xb4
/* 80073C54  7F A3 EB 78 */	mr r3, r29
/* 80073C58  4B FD A8 F9 */	bl -0x25708
/* 80073C5C  7C 71 1B 78 */	mr r17, r3
/* 80073C60  7F A3 EB 78 */	mr r3, r29
/* 80073C64  4B FD AE ED */	bl -0x25114
/* 80073C68  7C 6E 1B 78 */	mr r14, r3
/* 80073C6C  3A 80 00 00 */	li r20, 0
/* 80073C70  48 00 00 8C */	b 0x8c
/* 80073C74  7F A3 EB 78 */	mr r3, r29
/* 80073C78  7E 84 A3 78 */	mr r4, r20
/* 80073C7C  4B FD A8 75 */	bl -0x2578c
/* 80073C80  90 61 00 2C */	stw r3, 0x2c(r1)
/* 80073C84  3A E0 00 00 */	li r23, 0
/* 80073C88  48 00 00 2C */	b 0x2c
/* 80073C8C  7F A3 EB 78 */	mr r3, r29
/* 80073C90  7E E4 BB 78 */	mr r4, r23
/* 80073C94  4B FD AE 5D */	bl -0x251a4
/* 80073C98  90 61 00 28 */	stw r3, 0x28(r1)
/* 80073C9C  38 61 00 28 */	addi r3, r1, 0x28
/* 80073CA0  4B FD B7 31 */	bl -0x248d0
/* 80073CA4  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80073CA8  7C 00 18 40 */	cmplw r0, r3
/* 80073CAC  41 82 00 10 */	beq 0x10
/* 80073CB0  3A F7 00 01 */	addi r23, r23, 1
/* 80073CB4  7C 17 70 40 */	cmplw r23, r14
/* 80073CB8  41 80 FF D4 */	blt -0x2c
/* 80073CBC  7C 17 70 40 */	cmplw r23, r14
/* 80073CC0  41 82 00 2C */	beq 0x2c
/* 80073CC4  7C 90 7A 14 */	add r4, r16, r15
/* 80073CC8  90 92 00 00 */	stw r4, 0(r18)
/* 80073CCC  38 61 00 2C */	addi r3, r1, 0x2c
/* 80073CD0  80 A1 00 2C */	lwz r5, 0x2c(r1)
/* 80073CD4  80 A5 00 00 */	lwz r5, 0(r5)
/* 80073CD8  38 05 00 1F */	addi r0, r5, 0x1f
/* 80073CDC  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80073CE0  7D EF 02 14 */	add r15, r15, r0
/* 80073CE4  4B FD E8 5D */	bl -0x217a4
/* 80073CE8  48 00 00 0C */	b 0xc
/* 80073CEC  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80073CF0  90 12 00 00 */	stw r0, 0(r18)
/* 80073CF4  3A 52 00 04 */	addi r18, r18, 4
/* 80073CF8  3A 94 00 01 */	addi r20, r20, 1
/* 80073CFC  7C 14 88 40 */	cmplw r20, r17
/* 80073D00  41 80 FF 74 */	blt -0x8c
/* 80073D04  82 21 00 78 */	lwz r17, 0x78(r1)
/* 80073D08  2C 11 00 00 */	cmpwi r17, 0
/* 80073D0C  41 82 00 B4 */	beq 0xb4
/* 80073D10  7F A3 EB 78 */	mr r3, r29
/* 80073D14  4B FD A9 8D */	bl -0x25674
/* 80073D18  7C 6F 1B 78 */	mr r15, r3
/* 80073D1C  7F A3 EB 78 */	mr r3, r29
/* 80073D20  4B FD AE 31 */	bl -0x251d0
/* 80073D24  7C 6E 1B 78 */	mr r14, r3
/* 80073D28  3A 40 00 00 */	li r18, 0
/* 80073D2C  48 00 00 8C */	b 0x8c
/* 80073D30  7F A3 EB 78 */	mr r3, r29
/* 80073D34  7E 44 93 78 */	mr r4, r18
/* 80073D38  4B FD A9 09 */	bl -0x256f8
/* 80073D3C  90 61 00 24 */	stw r3, 0x24(r1)
/* 80073D40  3A 80 00 00 */	li r20, 0
/* 80073D44  48 00 00 2C */	b 0x2c
/* 80073D48  7F A3 EB 78 */	mr r3, r29
/* 80073D4C  7E 84 A3 78 */	mr r4, r20
/* 80073D50  4B FD AD A1 */	bl -0x25260
/* 80073D54  90 61 00 20 */	stw r3, 0x20(r1)
/* 80073D58  38 61 00 20 */	addi r3, r1, 0x20
/* 80073D5C  4B FD B6 C5 */	bl -0x2493c
/* 80073D60  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80073D64  7C 00 18 40 */	cmplw r0, r3
/* 80073D68  41 82 00 10 */	beq 0x10
/* 80073D6C  3A 94 00 01 */	addi r20, r20, 1
/* 80073D70  7C 14 70 40 */	cmplw r20, r14
/* 80073D74  41 80 FF D4 */	blt -0x2c
/* 80073D78  7C 14 70 40 */	cmplw r20, r14
/* 80073D7C  41 82 00 2C */	beq 0x2c
/* 80073D80  7C 90 B2 14 */	add r4, r16, r22
/* 80073D84  90 91 00 00 */	stw r4, 0(r17)
/* 80073D88  38 61 00 24 */	addi r3, r1, 0x24
/* 80073D8C  80 A1 00 24 */	lwz r5, 0x24(r1)
/* 80073D90  80 A5 00 00 */	lwz r5, 0(r5)
/* 80073D94  38 05 00 1F */	addi r0, r5, 0x1f
/* 80073D98  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80073D9C  7E D6 02 14 */	add r22, r22, r0
/* 80073DA0  4B FD E8 81 */	bl -0x21780
/* 80073DA4  48 00 00 0C */	b 0xc
/* 80073DA8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80073DAC  90 11 00 00 */	stw r0, 0(r17)
/* 80073DB0  3A 31 00 04 */	addi r17, r17, 4
/* 80073DB4  3A 52 00 01 */	addi r18, r18, 1
/* 80073DB8  7C 12 78 40 */	cmplw r18, r15
/* 80073DBC  41 80 FF 74 */	blt -0x8c
/* 80073DC0  82 21 00 7C */	lwz r17, 0x7c(r1)
/* 80073DC4  2C 11 00 00 */	cmpwi r17, 0
/* 80073DC8  41 82 00 E0 */	beq 0xe0
/* 80073DCC  7F A3 EB 78 */	mr r3, r29
/* 80073DD0  4B FD AA 21 */	bl -0x255e0
/* 80073DD4  7C 6F 1B 78 */	mr r15, r3
/* 80073DD8  7F A3 EB 78 */	mr r3, r29
/* 80073DDC  4B FD AD 75 */	bl -0x2528c
/* 80073DE0  7C 6E 1B 78 */	mr r14, r3
/* 80073DE4  3A 40 00 00 */	li r18, 0
/* 80073DE8  48 00 00 B8 */	b 0xb8
/* 80073DEC  7F A3 EB 78 */	mr r3, r29
/* 80073DF0  7E 44 93 78 */	mr r4, r18
/* 80073DF4  4B FD A9 9D */	bl -0x25664
/* 80073DF8  90 61 00 1C */	stw r3, 0x1c(r1)
/* 80073DFC  3A C0 00 00 */	li r22, 0
/* 80073E00  48 00 00 58 */	b 0x58
/* 80073E04  7F A3 EB 78 */	mr r3, r29
/* 80073E08  7E C4 B3 78 */	mr r4, r22
/* 80073E0C  4B FD AC E5 */	bl -0x2531c
/* 80073E10  90 61 00 18 */	stw r3, 0x18(r1)
/* 80073E14  38 61 00 18 */	addi r3, r1, 0x18
/* 80073E18  3A 80 00 01 */	li r20, 1
/* 80073E1C  38 80 00 00 */	li r4, 0
/* 80073E20  4B FD B6 61 */	bl -0x249a0
/* 80073E24  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80073E28  7C 00 18 40 */	cmplw r0, r3
/* 80073E2C  41 82 00 20 */	beq 0x20
/* 80073E30  38 61 00 18 */	addi r3, r1, 0x18
/* 80073E34  38 80 00 01 */	li r4, 1
/* 80073E38  4B FD B6 49 */	bl -0x249b8
/* 80073E3C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80073E40  7C 00 18 40 */	cmplw r0, r3
/* 80073E44  41 82 00 08 */	beq 0x8
/* 80073E48  3A 80 00 00 */	li r20, 0
/* 80073E4C  2C 14 00 00 */	cmpwi r20, 0
/* 80073E50  40 82 00 10 */	bne 0x10
/* 80073E54  3A D6 00 01 */	addi r22, r22, 1
/* 80073E58  7C 16 70 40 */	cmplw r22, r14
/* 80073E5C  41 80 FF A8 */	blt -0x58
/* 80073E60  7C 16 70 40 */	cmplw r22, r14
/* 80073E64  41 82 00 2C */	beq 0x2c
/* 80073E68  7C 90 AA 14 */	add r4, r16, r21
/* 80073E6C  90 91 00 00 */	stw r4, 0(r17)
/* 80073E70  38 61 00 1C */	addi r3, r1, 0x1c
/* 80073E74  80 A1 00 1C */	lwz r5, 0x1c(r1)
/* 80073E78  80 A5 00 00 */	lwz r5, 0(r5)
/* 80073E7C  38 05 00 1F */	addi r0, r5, 0x1f
/* 80073E80  54 00 00 34 */	rlwinm r0, r0, 0, 0, 0x1a
/* 80073E84  7E B5 02 14 */	add r21, r21, r0
/* 80073E88  4B FD E8 79 */	bl -0x21788
/* 80073E8C  48 00 00 0C */	b 0xc
/* 80073E90  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80073E94  90 11 00 00 */	stw r0, 0(r17)
/* 80073E98  3A 31 00 04 */	addi r17, r17, 4
/* 80073E9C  3A 52 00 01 */	addi r18, r18, 1
/* 80073EA0  7C 12 78 40 */	cmplw r18, r15
/* 80073EA4  41 80 FF 48 */	blt -0xb8
/* 80073EA8  2C 13 00 00 */	cmpwi r19, 0
/* 80073EAC  39 C0 00 00 */	li r14, 0
/* 80073EB0  41 82 00 08 */	beq 0x8
/* 80073EB4  61 CE 00 01 */	ori r14, r14, 1
/* 80073EB8  2C 10 00 00 */	cmpwi r16, 0
/* 80073EBC  41 82 01 18 */	beq 0x118
/* 80073EC0  80 01 00 F8 */	lwz r0, 0xf8(r1)
/* 80073EC4  80 7D 00 00 */	lwz r3, 0(r29)
/* 80073EC8  2C 00 00 00 */	cmpwi r0, 0
/* 80073ECC  41 82 00 10 */	beq 0x10
/* 80073ED0  80 01 00 B8 */	lwz r0, 0xb8(r1)
/* 80073ED4  7D 30 02 14 */	add r9, r16, r0
/* 80073ED8  48 00 00 08 */	b 0x8
/* 80073EDC  39 20 00 00 */	li r9, 0
/* 80073EE0  80 01 00 F4 */	lwz r0, 0xf4(r1)
/* 80073EE4  2C 00 00 00 */	cmpwi r0, 0
/* 80073EE8  41 82 00 10 */	beq 0x10
/* 80073EEC  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 80073EF0  7D 50 02 14 */	add r10, r16, r0
/* 80073EF4  48 00 00 08 */	b 0x8
/* 80073EF8  39 40 00 00 */	li r10, 0
/* 80073EFC  90 61 00 14 */	stw r3, 0x14(r1)
/* 80073F00  7E 03 83 78 */	mr r3, r16
/* 80073F04  80 01 00 C0 */	lwz r0, 0xc0(r1)
/* 80073F08  7F 84 E3 78 */	mr r4, r28
/* 80073F0C  93 E1 00 08 */	stw r31, 8(r1)
/* 80073F10  38 A1 00 14 */	addi r5, r1, 0x14
/* 80073F14  7C F0 02 14 */	add r7, r16, r0
/* 80073F18  80 01 00 BC */	lwz r0, 0xbc(r1)
/* 80073F1C  93 61 00 0C */	stw r27, 0xc(r1)
/* 80073F20  38 D0 01 A0 */	addi r6, r16, 0x1a0
/* 80073F24  7D 10 02 14 */	add r8, r16, r0
/* 80073F28  4B FF EB 49 */	bl -0x14b8
/* 80073F2C  3C 80 80 27 */	lis r4, 0x8027
/* 80073F30  80 01 00 B0 */	lwz r0, 0xb0(r1)
/* 80073F34  38 84 32 48 */	addi r4, r4, 0x3248
/* 80073F38  90 90 00 00 */	stw r4, 0(r16)
/* 80073F3C  38 60 00 00 */	li r3, 0
/* 80073F40  7C 10 02 14 */	add r0, r16, r0
/* 80073F44  90 70 01 38 */	stw r3, 0x138(r16)
/* 80073F48  80 A1 00 40 */	lwz r5, 0x40(r1)
/* 80073F4C  90 70 01 3C */	stw r3, 0x13c(r16)
/* 80073F50  80 81 00 44 */	lwz r4, 0x44(r1)
/* 80073F54  90 10 01 40 */	stw r0, 0x140(r16)
/* 80073F58  80 61 00 48 */	lwz r3, 0x48(r1)
/* 80073F5C  90 B0 01 44 */	stw r5, 0x144(r16)
/* 80073F60  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80073F64  90 90 01 48 */	stw r4, 0x148(r16)
/* 80073F68  80 A1 00 50 */	lwz r5, 0x50(r1)
/* 80073F6C  90 70 01 4C */	stw r3, 0x14c(r16)
/* 80073F70  80 81 00 54 */	lwz r4, 0x54(r1)
/* 80073F74  90 10 01 50 */	stw r0, 0x150(r16)
/* 80073F78  80 61 00 58 */	lwz r3, 0x58(r1)
/* 80073F7C  90 B0 01 54 */	stw r5, 0x154(r16)
/* 80073F80  80 01 00 5C */	lwz r0, 0x5c(r1)
/* 80073F84  90 90 01 58 */	stw r4, 0x158(r16)
/* 80073F88  80 A1 00 60 */	lwz r5, 0x60(r1)
/* 80073F8C  90 70 01 5C */	stw r3, 0x15c(r16)
/* 80073F90  80 81 00 64 */	lwz r4, 0x64(r1)
/* 80073F94  90 10 01 60 */	stw r0, 0x160(r16)
/* 80073F98  80 61 00 68 */	lwz r3, 0x68(r1)
/* 80073F9C  90 B0 01 64 */	stw r5, 0x164(r16)
/* 80073FA0  80 01 00 6C */	lwz r0, 0x6c(r1)
/* 80073FA4  90 90 01 68 */	stw r4, 0x168(r16)
/* 80073FA8  80 A1 00 70 */	lwz r5, 0x70(r1)
/* 80073FAC  90 70 01 6C */	stw r3, 0x16c(r16)
/* 80073FB0  80 81 00 74 */	lwz r4, 0x74(r1)
/* 80073FB4  90 10 01 70 */	stw r0, 0x170(r16)
/* 80073FB8  80 61 00 78 */	lwz r3, 0x78(r1)
/* 80073FBC  90 B0 01 74 */	stw r5, 0x174(r16)
/* 80073FC0  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 80073FC4  90 90 01 78 */	stw r4, 0x178(r16)
/* 80073FC8  90 70 01 7C */	stw r3, 0x17c(r16)
/* 80073FCC  90 10 01 80 */	stw r0, 0x180(r16)
/* 80073FD0  91 D0 01 84 */	stw r14, 0x184(r16)
/* 80073FD4  7E 03 83 78 */	mr r3, r16
/* 80073FD8  48 00 0C C9 */	bl 0xcc8
/* 80073FDC  7E 03 83 78 */	mr r3, r16
/* 80073FE0  39 61 01 50 */	addi r11, r1, 0x150
/* 80073FE4  4B FA D5 D5 */	bl -0x52a2c
/* 80073FE8  80 01 01 54 */	lwz r0, 0x154(r1)
/* 80073FEC  7C 08 03 A6 */	mtlr r0
/* 80073FF0  38 21 01 50 */	addi r1, r1, 0x150
/* 80073FF4  4E 80 00 20 */	blr 
/* 80073FF8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80073FFC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80074000  94 21 FD B0 */	stwu r1, -0x250(r1)
/* 80074004  7C 08 02 A6 */	mflr r0
/* 80074008  90 01 02 54 */	stw r0, 0x254(r1)
/* 8007400C  39 61 02 50 */	addi r11, r1, 0x250
/* 80074010  4B FA D5 5D */	bl -0x52aa4
/* 80074014  80 C3 00 D4 */	lwz r6, 0xd4(r3)
/* 80074018  7C 70 1B 78 */	mr r16, r3
/* 8007401C  90 81 00 08 */	stw r4, 8(r1)
/* 80074020  2C 06 00 00 */	cmpwi r6, 0
/* 80074024  90 A1 00 0C */	stw r5, 0xc(r1)
/* 80074028  41 82 00 40 */	beq 0x40
/* 8007402C  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80074030  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80074034  41 82 00 34 */	beq 0x34
/* 80074038  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 8007403C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80074040  41 82 00 28 */	beq 0x28
/* 80074044  81 86 00 00 */	lwz r12, 0(r6)
/* 80074048  7C C3 33 78 */	mr r3, r6
/* 8007404C  7C 86 23 78 */	mr r6, r4
/* 80074050  7E 05 83 78 */	mr r5, r16
/* 80074054  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80074058  38 80 00 01 */	li r4, 1
/* 8007405C  80 E1 00 0C */	lwz r7, 0xc(r1)
/* 80074060  7D 89 03 A6 */	mtctr r12
/* 80074064  4E 80 04 21 */	bctrl 
/* 80074068  80 10 00 E8 */	lwz r0, 0xe8(r16)
/* 8007406C  38 61 00 60 */	addi r3, r1, 0x60
/* 80074070  90 01 00 60 */	stw r0, 0x60(r1)
/* 80074074  4B FD A9 DD */	bl -0x25624
/* 80074078  3B A1 00 E4 */	addi r29, r1, 0xe4
/* 8007407C  38 01 00 C8 */	addi r0, r1, 0xc8
/* 80074080  7C 80 E8 50 */	subf r4, r0, r29
/* 80074084  3B C1 01 04 */	addi r30, r1, 0x104
/* 80074088  38 01 00 E8 */	addi r0, r1, 0xe8
/* 8007408C  90 61 02 04 */	stw r3, 0x204(r1)
/* 80074090  7C C0 F0 50 */	subf r6, r0, r30
/* 80074094  38 A4 00 03 */	addi r5, r4, 3
/* 80074098  54 80 00 00 */	rlwinm r0, r4, 0, 0, 0
/* 8007409C  90 01 02 00 */	stw r0, 0x200(r1)
/* 800740A0  7C A3 16 70 */	srawi r3, r5, 2
/* 800740A4  38 E6 00 03 */	addi r7, r6, 3
/* 800740A8  7C 83 01 94 */	addze r4, r3
/* 800740AC  54 A0 00 00 */	rlwinm r0, r5, 0, 0, 0
/* 800740B0  7C E3 16 70 */	srawi r3, r7, 2
/* 800740B4  90 01 01 FC */	stw r0, 0x1fc(r1)
/* 800740B8  7C 63 01 94 */	addze r3, r3
/* 800740BC  3A A4 00 01 */	addi r21, r4, 1
/* 800740C0  3A 63 00 01 */	addi r19, r3, 1
/* 800740C4  54 94 00 00 */	rlwinm r20, r4, 0, 0, 0
/* 800740C8  56 A0 00 00 */	rlwinm r0, r21, 0, 0, 0
/* 800740CC  90 01 01 F8 */	stw r0, 0x1f8(r1)
/* 800740D0  54 C0 00 00 */	rlwinm r0, r6, 0, 0, 0
/* 800740D4  54 72 00 00 */	rlwinm r18, r3, 0, 0, 0
/* 800740D8  90 01 01 F4 */	stw r0, 0x1f4(r1)
/* 800740DC  54 E0 00 00 */	rlwinm r0, r7, 0, 0, 0
/* 800740E0  56 6E 00 00 */	rlwinm r14, r19, 0, 0, 0
/* 800740E4  3A 20 00 00 */	li r17, 0
/* 800740E8  90 01 01 F0 */	stw r0, 0x1f0(r1)
/* 800740EC  3B 80 00 00 */	li r28, 0
/* 800740F0  3B 60 00 00 */	li r27, 0
/* 800740F4  3B 40 00 00 */	li r26, 0
/* 800740F8  3B 20 00 00 */	li r25, 0
/* 800740FC  3B 00 00 00 */	li r24, 0
/* 80074100  3A E0 00 00 */	li r23, 0
/* 80074104  3A C0 00 00 */	li r22, 0
/* 80074108  3B E0 00 00 */	li r31, 0
/* 8007410C  48 00 05 FC */	b 0x5fc
/* 80074110  7E 24 8B 78 */	mr r4, r17
/* 80074114  38 61 00 60 */	addi r3, r1, 0x60
/* 80074118  4B FD A8 D9 */	bl -0x25728
/* 8007411C  80 90 01 40 */	lwz r4, 0x140(r16)
/* 80074120  7C 6F 1B 78 */	mr r15, r3
/* 80074124  7C 04 E0 2E */	lwzx r0, r4, r28
/* 80074128  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8007412C  41 82 00 14 */	beq 0x14
/* 80074130  7E 03 83 78 */	mr r3, r16
/* 80074134  7E 24 8B 78 */	mr r4, r17
/* 80074138  38 A0 00 01 */	li r5, 1
/* 8007413C  48 00 0F 05 */	bl 0xf04
/* 80074140  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074144  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074148  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8007414C  41 82 00 14 */	beq 0x14
/* 80074150  7E 03 83 78 */	mr r3, r16
/* 80074154  7E 24 8B 78 */	mr r4, r17
/* 80074158  38 A0 00 02 */	li r5, 2
/* 8007415C  48 00 0E E5 */	bl 0xee4
/* 80074160  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074164  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074168  54 00 05 AD */	rlwinm. r0, r0, 0, 0x16, 0x16
/* 8007416C  41 82 00 14 */	beq 0x14
/* 80074170  7E 03 83 78 */	mr r3, r16
/* 80074174  7E 24 8B 78 */	mr r4, r17
/* 80074178  38 A0 02 00 */	li r5, 0x200
/* 8007417C  48 00 0E C5 */	bl 0xec4
/* 80074180  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074184  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074188  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8007418C  41 82 00 14 */	beq 0x14
/* 80074190  7E 03 83 78 */	mr r3, r16
/* 80074194  7E 24 8B 78 */	mr r4, r17
/* 80074198  38 A0 00 04 */	li r5, 4
/* 8007419C  48 00 0E A5 */	bl 0xea4
/* 800741A0  80 70 01 40 */	lwz r3, 0x140(r16)
/* 800741A4  7C 03 E0 2E */	lwzx r0, r3, r28
/* 800741A8  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 800741AC  41 82 00 14 */	beq 0x14
/* 800741B0  7E 03 83 78 */	mr r3, r16
/* 800741B4  7E 24 8B 78 */	mr r4, r17
/* 800741B8  38 A0 00 08 */	li r5, 8
/* 800741BC  48 00 0E 85 */	bl 0xe84
/* 800741C0  80 70 01 40 */	lwz r3, 0x140(r16)
/* 800741C4  7C 03 E0 2E */	lwzx r0, r3, r28
/* 800741C8  54 00 05 EF */	rlwinm. r0, r0, 0, 0x17, 0x17
/* 800741CC  41 82 00 14 */	beq 0x14
/* 800741D0  7E 03 83 78 */	mr r3, r16
/* 800741D4  7E 24 8B 78 */	mr r4, r17
/* 800741D8  38 A0 01 00 */	li r5, 0x100
/* 800741DC  48 00 0E 65 */	bl 0xe64
/* 800741E0  80 70 01 40 */	lwz r3, 0x140(r16)
/* 800741E4  7C 03 E0 2E */	lwzx r0, r3, r28
/* 800741E8  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 800741EC  41 82 00 14 */	beq 0x14
/* 800741F0  7E 03 83 78 */	mr r3, r16
/* 800741F4  7E 24 8B 78 */	mr r4, r17
/* 800741F8  38 A0 00 10 */	li r5, 0x10
/* 800741FC  48 00 0E 45 */	bl 0xe44
/* 80074200  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074204  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074208  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 8007420C  41 82 00 14 */	beq 0x14
/* 80074210  7E 03 83 78 */	mr r3, r16
/* 80074214  7E 24 8B 78 */	mr r4, r17
/* 80074218  38 A0 00 20 */	li r5, 0x20
/* 8007421C  48 00 0E 25 */	bl 0xe24
/* 80074220  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074224  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074228  54 00 06 31 */	rlwinm. r0, r0, 0, 0x18, 0x18
/* 8007422C  41 82 00 14 */	beq 0x14
/* 80074230  7E 03 83 78 */	mr r3, r16
/* 80074234  7E 24 8B 78 */	mr r4, r17
/* 80074238  38 A0 00 80 */	li r5, 0x80
/* 8007423C  48 00 0E 05 */	bl 0xe04
/* 80074240  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074244  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074248  54 00 05 6B */	rlwinm. r0, r0, 0, 0x15, 0x15
/* 8007424C  41 82 00 14 */	beq 0x14
/* 80074250  7E 03 83 78 */	mr r3, r16
/* 80074254  7E 24 8B 78 */	mr r4, r17
/* 80074258  38 A0 04 00 */	li r5, 0x400
/* 8007425C  48 00 0D E5 */	bl 0xde4
/* 80074260  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074264  7C 03 E0 2E */	lwzx r0, r3, r28
/* 80074268  54 00 05 29 */	rlwinm. r0, r0, 0, 0x14, 0x14
/* 8007426C  41 82 00 14 */	beq 0x14
/* 80074270  7E 03 83 78 */	mr r3, r16
/* 80074274  7E 24 8B 78 */	mr r4, r17
/* 80074278  38 A0 08 00 */	li r5, 0x800
/* 8007427C  48 00 0D C5 */	bl 0xdc4
/* 80074280  80 70 01 30 */	lwz r3, 0x130(r16)
/* 80074284  2C 03 00 00 */	cmpwi r3, 0
/* 80074288  41 82 02 9C */	beq 0x29c
/* 8007428C  7E 24 8B 78 */	mr r4, r17
/* 80074290  4B FE 46 81 */	bl -0x1b980
/* 80074294  2C 03 00 00 */	cmpwi r3, 0
/* 80074298  41 82 02 8C */	beq 0x28c
/* 8007429C  38 81 00 C8 */	addi r4, r1, 0xc8
/* 800742A0  93 E1 00 C4 */	stw r31, 0xc4(r1)
/* 800742A4  7C 04 E8 40 */	cmplw r4, r29
/* 800742A8  40 80 00 F0 */	bge 0xf0
/* 800742AC  2C 15 00 08 */	cmpwi r21, 8
/* 800742B0  40 81 00 C4 */	ble 0xc4
/* 800742B4  7C 80 23 78 */	mr r0, r4
/* 800742B8  38 60 00 00 */	li r3, 0
/* 800742BC  7C 00 E8 40 */	cmplw r0, r29
/* 800742C0  38 A0 00 00 */	li r5, 0
/* 800742C4  41 81 00 30 */	bgt 0x30
/* 800742C8  80 01 02 00 */	lwz r0, 0x200(r1)
/* 800742CC  38 C0 00 01 */	li r6, 1
/* 800742D0  2C 00 00 00 */	cmpwi r0, 0
/* 800742D4  40 82 00 14 */	bne 0x14
/* 800742D8  80 01 01 FC */	lwz r0, 0x1fc(r1)
/* 800742DC  2C 00 00 00 */	cmpwi r0, 0
/* 800742E0  41 82 00 08 */	beq 0x8
/* 800742E4  38 C0 00 00 */	li r6, 0
/* 800742E8  2C 06 00 00 */	cmpwi r6, 0
/* 800742EC  41 82 00 08 */	beq 0x8
/* 800742F0  38 A0 00 01 */	li r5, 1
/* 800742F4  2C 05 00 00 */	cmpwi r5, 0
/* 800742F8  41 82 00 2C */	beq 0x2c
/* 800742FC  2C 14 00 00 */	cmpwi r20, 0
/* 80074300  38 A0 00 01 */	li r5, 1
/* 80074304  40 82 00 14 */	bne 0x14
/* 80074308  80 01 01 F8 */	lwz r0, 0x1f8(r1)
/* 8007430C  7C 14 00 00 */	cmpw r20, r0
/* 80074310  41 82 00 08 */	beq 0x8
/* 80074314  38 A0 00 00 */	li r5, 0
/* 80074318  2C 05 00 00 */	cmpwi r5, 0
/* 8007431C  41 82 00 08 */	beq 0x8
/* 80074320  38 60 00 01 */	li r3, 1
/* 80074324  2C 03 00 00 */	cmpwi r3, 0
/* 80074328  41 82 00 4C */	beq 0x4c
/* 8007432C  38 61 00 C4 */	addi r3, r1, 0xc4
/* 80074330  38 03 00 1F */	addi r0, r3, 0x1f
/* 80074334  7C 04 00 50 */	subf r0, r4, r0
/* 80074338  54 00 D9 7E */	srwi r0, r0, 5
/* 8007433C  7C 09 03 A6 */	mtctr r0
/* 80074340  7C 60 1B 78 */	mr r0, r3
/* 80074344  7C 04 00 40 */	cmplw r4, r0
/* 80074348  40 80 00 2C */	bge 0x2c
/* 8007434C  93 E4 00 00 */	stw r31, 0(r4)
/* 80074350  93 E4 00 04 */	stw r31, 4(r4)
/* 80074354  93 E4 00 08 */	stw r31, 8(r4)
/* 80074358  93 E4 00 0C */	stw r31, 0xc(r4)
/* 8007435C  93 E4 00 10 */	stw r31, 0x10(r4)
/* 80074360  93 E4 00 14 */	stw r31, 0x14(r4)
/* 80074364  93 E4 00 18 */	stw r31, 0x18(r4)
/* 80074368  93 E4 00 1C */	stw r31, 0x1c(r4)
/* 8007436C  38 84 00 20 */	addi r4, r4, 0x20
/* 80074370  42 00 FF DC */	bdnz -0x24
/* 80074374  38 1D 00 03 */	addi r0, r29, 3
/* 80074378  7C 04 00 50 */	subf r0, r4, r0
/* 8007437C  54 00 F0 BE */	srwi r0, r0, 2
/* 80074380  7C 09 03 A6 */	mtctr r0
/* 80074384  7C 04 E8 40 */	cmplw r4, r29
/* 80074388  40 80 00 10 */	bge 0x10
/* 8007438C  93 E4 00 00 */	stw r31, 0(r4)
/* 80074390  38 84 00 04 */	addi r4, r4, 4
/* 80074394  42 00 FF F8 */	bdnz -0x8
/* 80074398  38 61 00 E8 */	addi r3, r1, 0xe8
/* 8007439C  93 E1 00 E4 */	stw r31, 0xe4(r1)
/* 800743A0  7C 03 F0 40 */	cmplw r3, r30
/* 800743A4  40 80 00 E4 */	bge 0xe4
/* 800743A8  2C 13 00 08 */	cmpwi r19, 8
/* 800743AC  40 81 00 B8 */	ble 0xb8
/* 800743B0  7C 60 1B 78 */	mr r0, r3
/* 800743B4  38 80 00 00 */	li r4, 0
/* 800743B8  7C 00 F0 40 */	cmplw r0, r30
/* 800743BC  38 A0 00 00 */	li r5, 0
/* 800743C0  41 81 00 30 */	bgt 0x30
/* 800743C4  80 01 01 F4 */	lwz r0, 0x1f4(r1)
/* 800743C8  38 C0 00 01 */	li r6, 1
/* 800743CC  2C 00 00 00 */	cmpwi r0, 0
/* 800743D0  40 82 00 14 */	bne 0x14
/* 800743D4  80 01 01 F0 */	lwz r0, 0x1f0(r1)
/* 800743D8  2C 00 00 00 */	cmpwi r0, 0
/* 800743DC  41 82 00 08 */	beq 0x8
/* 800743E0  38 C0 00 00 */	li r6, 0
/* 800743E4  2C 06 00 00 */	cmpwi r6, 0
/* 800743E8  41 82 00 08 */	beq 0x8
/* 800743EC  38 A0 00 01 */	li r5, 1
/* 800743F0  2C 05 00 00 */	cmpwi r5, 0
/* 800743F4  41 82 00 28 */	beq 0x28
/* 800743F8  2C 12 00 00 */	cmpwi r18, 0
/* 800743FC  38 00 00 01 */	li r0, 1
/* 80074400  40 82 00 10 */	bne 0x10
/* 80074404  7C 12 70 00 */	cmpw r18, r14
/* 80074408  41 82 00 08 */	beq 0x8
/* 8007440C  38 00 00 00 */	li r0, 0
/* 80074410  2C 00 00 00 */	cmpwi r0, 0
/* 80074414  41 82 00 08 */	beq 0x8
/* 80074418  38 80 00 01 */	li r4, 1
/* 8007441C  2C 04 00 00 */	cmpwi r4, 0
/* 80074420  41 82 00 44 */	beq 0x44
/* 80074424  38 1D 00 1F */	addi r0, r29, 0x1f
/* 80074428  7C 03 00 50 */	subf r0, r3, r0
/* 8007442C  54 00 D9 7E */	srwi r0, r0, 5
/* 80074430  7C 09 03 A6 */	mtctr r0
/* 80074434  7C 03 E8 40 */	cmplw r3, r29
/* 80074438  40 80 00 2C */	bge 0x2c
/* 8007443C  93 E3 00 00 */	stw r31, 0(r3)
/* 80074440  93 E3 00 04 */	stw r31, 4(r3)
/* 80074444  93 E3 00 08 */	stw r31, 8(r3)
/* 80074448  93 E3 00 0C */	stw r31, 0xc(r3)
/* 8007444C  93 E3 00 10 */	stw r31, 0x10(r3)
/* 80074450  93 E3 00 14 */	stw r31, 0x14(r3)
/* 80074454  93 E3 00 18 */	stw r31, 0x18(r3)
/* 80074458  93 E3 00 1C */	stw r31, 0x1c(r3)
/* 8007445C  38 63 00 20 */	addi r3, r3, 0x20
/* 80074460  42 00 FF DC */	bdnz -0x24
/* 80074464  38 1E 00 03 */	addi r0, r30, 3
/* 80074468  7C 03 00 50 */	subf r0, r3, r0
/* 8007446C  54 00 F0 BE */	srwi r0, r0, 2
/* 80074470  7C 09 03 A6 */	mtctr r0
/* 80074474  7C 03 F0 40 */	cmplw r3, r30
/* 80074478  40 80 00 10 */	bge 0x10
/* 8007447C  93 E3 00 00 */	stw r31, 0(r3)
/* 80074480  38 63 00 04 */	addi r3, r3, 4
/* 80074484  42 00 FF F8 */	bdnz -0x8
/* 80074488  80 70 01 30 */	lwz r3, 0x130(r16)
/* 8007448C  7E 25 8B 78 */	mr r5, r17
/* 80074490  38 81 00 C0 */	addi r4, r1, 0xc0
/* 80074494  81 83 00 00 */	lwz r12, 0(r3)
/* 80074498  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 8007449C  7D 89 03 A6 */	mtctr r12
/* 800744A0  4E 80 04 21 */	bctrl 
/* 800744A4  80 10 01 4C */	lwz r0, 0x14c(r16)
/* 800744A8  2C 00 00 00 */	cmpwi r0, 0
/* 800744AC  41 82 00 14 */	beq 0x14
/* 800744B0  7C 00 DA 14 */	add r0, r0, r27
/* 800744B4  90 01 00 54 */	stw r0, 0x54(r1)
/* 800744B8  38 81 00 54 */	addi r4, r1, 0x54
/* 800744BC  48 00 00 10 */	b 0x10
/* 800744C0  38 0F 00 40 */	addi r0, r15, 0x40
/* 800744C4  90 01 00 50 */	stw r0, 0x50(r1)
/* 800744C8  38 81 00 50 */	addi r4, r1, 0x50
/* 800744CC  80 B0 01 50 */	lwz r5, 0x150(r16)
/* 800744D0  80 04 00 00 */	lwz r0, 0(r4)
/* 800744D4  2C 05 00 00 */	cmpwi r5, 0
/* 800744D8  41 82 00 14 */	beq 0x14
/* 800744DC  7C 85 D2 14 */	add r4, r5, r26
/* 800744E0  90 81 00 4C */	stw r4, 0x4c(r1)
/* 800744E4  38 81 00 4C */	addi r4, r1, 0x4c
/* 800744E8  48 00 00 10 */	b 0x10
/* 800744EC  38 8F 01 44 */	addi r4, r15, 0x144
/* 800744F0  90 81 00 48 */	stw r4, 0x48(r1)
/* 800744F4  38 81 00 48 */	addi r4, r1, 0x48
/* 800744F8  80 84 00 00 */	lwz r4, 0(r4)
/* 800744FC  7C 65 1B 78 */	mr r5, r3
/* 80074500  90 81 00 40 */	stw r4, 0x40(r1)
/* 80074504  38 61 00 44 */	addi r3, r1, 0x44
/* 80074508  38 81 00 40 */	addi r4, r1, 0x40
/* 8007450C  90 01 00 44 */	stw r0, 0x44(r1)
/* 80074510  4B FE 54 91 */	bl -0x1ab70
/* 80074514  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074518  7C 03 E0 2E */	lwzx r0, r3, r28
/* 8007451C  60 00 00 03 */	ori r0, r0, 3
/* 80074520  7C 03 E1 2E */	stwx r0, r3, r28
/* 80074524  80 70 01 34 */	lwz r3, 0x134(r16)
/* 80074528  2C 03 00 00 */	cmpwi r3, 0
/* 8007452C  41 82 00 D8 */	beq 0xd8
/* 80074530  7E 24 8B 78 */	mr r4, r17
/* 80074534  4B FE 59 DD */	bl -0x1a624
/* 80074538  2C 03 00 00 */	cmpwi r3, 0
/* 8007453C  41 82 00 C8 */	beq 0xc8
/* 80074540  80 70 01 34 */	lwz r3, 0x134(r16)
/* 80074544  7E 25 8B 78 */	mr r5, r17
/* 80074548  38 81 01 08 */	addi r4, r1, 0x108
/* 8007454C  81 83 00 00 */	lwz r12, 0(r3)
/* 80074550  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80074554  7D 89 03 A6 */	mtctr r12
/* 80074558  4E 80 04 21 */	bctrl 
/* 8007455C  80 10 01 54 */	lwz r0, 0x154(r16)
/* 80074560  2C 00 00 00 */	cmpwi r0, 0
/* 80074564  41 82 00 14 */	beq 0x14
/* 80074568  7C 00 CA 14 */	add r0, r0, r25
/* 8007456C  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80074570  38 81 00 3C */	addi r4, r1, 0x3c
/* 80074574  48 00 00 10 */	b 0x10
/* 80074578  38 0F 01 A8 */	addi r0, r15, 0x1a8
/* 8007457C  90 01 00 38 */	stw r0, 0x38(r1)
/* 80074580  38 81 00 38 */	addi r4, r1, 0x38
/* 80074584  80 B0 01 6C */	lwz r5, 0x16c(r16)
/* 80074588  80 04 00 00 */	lwz r0, 0(r4)
/* 8007458C  2C 05 00 00 */	cmpwi r5, 0
/* 80074590  41 82 00 14 */	beq 0x14
/* 80074594  7C 85 C2 14 */	add r4, r5, r24
/* 80074598  90 81 00 34 */	stw r4, 0x34(r1)
/* 8007459C  38 81 00 34 */	addi r4, r1, 0x34
/* 800745A0  48 00 00 28 */	b 0x28
/* 800745A4  80 8F 00 3C */	lwz r4, 0x3c(r15)
/* 800745A8  2C 04 00 00 */	cmpwi r4, 0
/* 800745AC  41 82 00 0C */	beq 0xc
/* 800745B0  7C 8F 22 14 */	add r4, r15, r4
/* 800745B4  48 00 00 08 */	b 0x8
/* 800745B8  38 80 00 00 */	li r4, 0
/* 800745BC  38 84 00 A0 */	addi r4, r4, 0xa0
/* 800745C0  90 81 00 30 */	stw r4, 0x30(r1)
/* 800745C4  38 81 00 30 */	addi r4, r1, 0x30
/* 800745C8  80 C4 00 00 */	lwz r6, 0(r4)
/* 800745CC  7C 65 1B 78 */	mr r5, r3
/* 800745D0  90 C1 00 5C */	stw r6, 0x5c(r1)
/* 800745D4  38 61 00 2C */	addi r3, r1, 0x2c
/* 800745D8  38 81 00 28 */	addi r4, r1, 0x28
/* 800745DC  90 C1 00 28 */	stw r6, 0x28(r1)
/* 800745E0  90 01 00 2C */	stw r0, 0x2c(r1)
/* 800745E4  4B FE 6A 4D */	bl -0x195b4
/* 800745E8  38 61 00 5C */	addi r3, r1, 0x5c
/* 800745EC  38 80 00 00 */	li r4, 0
/* 800745F0  4B FD BE A1 */	bl -0x24160
/* 800745F4  80 70 01 40 */	lwz r3, 0x140(r16)
/* 800745F8  7C 03 E0 2E */	lwzx r0, r3, r28
/* 800745FC  60 00 02 04 */	ori r0, r0, 0x204
/* 80074600  7C 03 E1 2E */	stwx r0, r3, r28
/* 80074604  80 70 01 2C */	lwz r3, 0x12c(r16)
/* 80074608  2C 03 00 00 */	cmpwi r3, 0
/* 8007460C  41 82 00 DC */	beq 0xdc
/* 80074610  7E 24 8B 78 */	mr r4, r17
/* 80074614  4B FE 2A 4D */	bl -0x1d5b4
/* 80074618  2C 03 00 00 */	cmpwi r3, 0
/* 8007461C  41 82 00 CC */	beq 0xcc
/* 80074620  80 10 01 68 */	lwz r0, 0x168(r16)
/* 80074624  2C 00 00 00 */	cmpwi r0, 0
/* 80074628  41 82 00 14 */	beq 0x14
/* 8007462C  7C 00 BA 14 */	add r0, r0, r23
/* 80074630  90 01 00 24 */	stw r0, 0x24(r1)
/* 80074634  38 61 00 24 */	addi r3, r1, 0x24
/* 80074638  48 00 00 28 */	b 0x28
/* 8007463C  80 0F 00 3C */	lwz r0, 0x3c(r15)
/* 80074640  2C 00 00 00 */	cmpwi r0, 0
/* 80074644  41 82 00 0C */	beq 0xc
/* 80074648  7C 6F 02 14 */	add r3, r15, r0
/* 8007464C  48 00 00 08 */	b 0x8
/* 80074650  38 60 00 00 */	li r3, 0
/* 80074654  38 03 00 20 */	addi r0, r3, 0x20
/* 80074658  90 01 00 20 */	stw r0, 0x20(r1)
/* 8007465C  38 61 00 20 */	addi r3, r1, 0x20
/* 80074660  80 03 00 00 */	lwz r0, 0(r3)
/* 80074664  90 01 00 58 */	stw r0, 0x58(r1)
/* 80074668  80 10 01 58 */	lwz r0, 0x158(r16)
/* 8007466C  2C 00 00 00 */	cmpwi r0, 0
/* 80074670  41 82 00 14 */	beq 0x14
/* 80074674  7C 00 B2 14 */	add r0, r0, r22
/* 80074678  90 01 00 1C */	stw r0, 0x1c(r1)
/* 8007467C  38 C1 00 1C */	addi r6, r1, 0x1c
/* 80074680  48 00 00 10 */	b 0x10
/* 80074684  38 0F 03 F0 */	addi r0, r15, 0x3f0
/* 80074688  90 01 00 18 */	stw r0, 0x18(r1)
/* 8007468C  38 C1 00 18 */	addi r6, r1, 0x18
/* 80074690  80 70 01 2C */	lwz r3, 0x12c(r16)
/* 80074694  7E 25 8B 78 */	mr r5, r17
/* 80074698  38 81 00 64 */	addi r4, r1, 0x64
/* 8007469C  81 E6 00 00 */	lwz r15, 0(r6)
/* 800746A0  81 83 00 00 */	lwz r12, 0(r3)
/* 800746A4  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800746A8  7D 89 03 A6 */	mtctr r12
/* 800746AC  4E 80 04 21 */	bctrl 
/* 800746B0  80 01 00 58 */	lwz r0, 0x58(r1)
/* 800746B4  7C 65 1B 78 */	mr r5, r3
/* 800746B8  90 01 00 10 */	stw r0, 0x10(r1)
/* 800746BC  38 61 00 14 */	addi r3, r1, 0x14
/* 800746C0  38 81 00 10 */	addi r4, r1, 0x10
/* 800746C4  91 E1 00 14 */	stw r15, 0x14(r1)
/* 800746C8  4B FE 3A 19 */	bl -0x1c5e8
/* 800746CC  38 61 00 58 */	addi r3, r1, 0x58
/* 800746D0  38 80 00 00 */	li r4, 0
/* 800746D4  4B FD BD 9D */	bl -0x24264
/* 800746D8  80 70 01 40 */	lwz r3, 0x140(r16)
/* 800746DC  7C 03 E0 2E */	lwzx r0, r3, r28
/* 800746E0  60 00 01 08 */	ori r0, r0, 0x108
/* 800746E4  7C 03 E1 2E */	stwx r0, r3, r28
/* 800746E8  3B 9C 00 04 */	addi r28, r28, 4
/* 800746EC  3B 7B 01 04 */	addi r27, r27, 0x104
/* 800746F0  3B 5A 00 64 */	addi r26, r26, 0x64
/* 800746F4  3B 39 02 48 */	addi r25, r25, 0x248
/* 800746F8  3B 18 00 40 */	addi r24, r24, 0x40
/* 800746FC  3A F7 00 80 */	addi r23, r23, 0x80
/* 80074700  3A D6 00 28 */	addi r22, r22, 0x28
/* 80074704  3A 31 00 01 */	addi r17, r17, 1
/* 80074708  80 01 02 04 */	lwz r0, 0x204(r1)
/* 8007470C  7C 11 00 40 */	cmplw r17, r0
/* 80074710  41 80 FA 00 */	blt -0x600
/* 80074714  80 70 00 D4 */	lwz r3, 0xd4(r16)
/* 80074718  2C 03 00 00 */	cmpwi r3, 0
/* 8007471C  41 82 00 3C */	beq 0x3c
/* 80074720  A0 10 00 DA */	lhz r0, 0xda(r16)
/* 80074724  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80074728  41 82 00 30 */	beq 0x30
/* 8007472C  88 10 00 D8 */	lbz r0, 0xd8(r16)
/* 80074730  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80074734  41 82 00 24 */	beq 0x24
/* 80074738  81 83 00 00 */	lwz r12, 0(r3)
/* 8007473C  7E 05 83 78 */	mr r5, r16
/* 80074740  80 C1 00 08 */	lwz r6, 8(r1)
/* 80074744  38 80 00 04 */	li r4, 4
/* 80074748  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8007474C  80 E1 00 0C */	lwz r7, 0xc(r1)
/* 80074750  7D 89 03 A6 */	mtctr r12
/* 80074754  4E 80 04 21 */	bctrl 
/* 80074758  39 61 02 50 */	addi r11, r1, 0x250
/* 8007475C  4B FA CE 5D */	bl -0x531a4
/* 80074760  80 01 02 54 */	lwz r0, 0x254(r1)
/* 80074764  7C 08 03 A6 */	mtlr r0
/* 80074768  38 21 02 50 */	addi r1, r1, 0x250
/* 8007476C  4E 80 00 20 */	blr 
/* 80074770  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80074774  7C 08 02 A6 */	mflr r0
/* 80074778  90 01 00 44 */	stw r0, 0x44(r1)
/* 8007477C  39 61 00 40 */	addi r11, r1, 0x40
/* 80074780  4B FA CE 19 */	bl -0x531e8
/* 80074784  28 04 00 09 */	cmplwi r4, 9
/* 80074788  7C 7D 1B 78 */	mr r29, r3
/* 8007478C  7C BE 2B 78 */	mr r30, r5
/* 80074790  7C DF 33 78 */	mr r31, r6
/* 80074794  40 80 00 24 */	bge 0x24
/* 80074798  38 A4 FF FF */	addi r5, r4, -1
/* 8007479C  38 C0 00 01 */	li r6, 1
/* 800747A0  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 800747A4  7C C5 28 30 */	slw r5, r6, r5
/* 800747A8  7C A0 00 39 */	and. r0, r5, r0
/* 800747AC  41 82 00 0C */	beq 0xc
/* 800747B0  38 00 00 01 */	li r0, 1
/* 800747B4  48 00 00 08 */	b 0x8
/* 800747B8  38 00 00 00 */	li r0, 0
/* 800747BC  2C 00 00 00 */	cmpwi r0, 0
/* 800747C0  40 82 04 48 */	bne 0x448
/* 800747C4  2C 04 00 06 */	cmpwi r4, 6
/* 800747C8  41 82 01 D8 */	beq 0x1d8
/* 800747CC  40 80 00 2C */	bge 0x2c
/* 800747D0  2C 04 00 03 */	cmpwi r4, 3
/* 800747D4  41 82 03 F8 */	beq 0x3f8
/* 800747D8  40 80 00 14 */	bge 0x14
/* 800747DC  2C 04 00 01 */	cmpwi r4, 1
/* 800747E0  41 82 00 50 */	beq 0x50
/* 800747E4  40 80 01 94 */	bge 0x194
/* 800747E8  48 00 04 10 */	b 0x410
/* 800747EC  2C 04 00 05 */	cmpwi r4, 5
/* 800747F0  40 80 00 2C */	bge 0x2c
/* 800747F4  48 00 01 98 */	b 0x198
/* 800747F8  3C A0 00 01 */	lis r5, 1
/* 800747FC  38 05 00 01 */	addi r0, r5, 1
/* 80074800  7C 04 00 00 */	cmpw r4, r0
/* 80074804  41 82 03 AC */	beq 0x3ac
/* 80074808  40 80 03 F0 */	bge 0x3f0
/* 8007480C  2C 04 00 08 */	cmpwi r4, 8
/* 80074810  41 82 03 78 */	beq 0x378
/* 80074814  40 80 03 E4 */	bge 0x3e4
/* 80074818  48 00 02 7C */	b 0x27c
/* 8007481C  7F A3 EB 78 */	mr r3, r29
/* 80074820  7F C4 F3 78 */	mr r4, r30
/* 80074824  7F E5 FB 78 */	mr r5, r31
/* 80074828  4B FF C8 F9 */	bl -0x3708
/* 8007482C  48 00 03 DC */	b 0x3dc
/* 80074830  7F A3 EB 78 */	mr r3, r29
/* 80074834  7F C4 F3 78 */	mr r4, r30
/* 80074838  7F E5 FB 78 */	mr r5, r31
/* 8007483C  4B FF C6 85 */	bl -0x397c
/* 80074840  80 7D 01 3C */	lwz r3, 0x13c(r29)
/* 80074844  54 60 07 BD */	rlwinm. r0, r3, 0, 0x1e, 0x1e
/* 80074848  40 82 00 9C */	bne 0x9c
/* 8007484C  54 60 07 FF */	clrlwi. r0, r3, 0x1f
/* 80074850  41 82 00 94 */	beq 0x94
/* 80074854  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80074858  38 61 00 1C */	addi r3, r1, 0x1c
/* 8007485C  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80074860  4B FD 9B A1 */	bl -0x26460
/* 80074864  80 1D 01 48 */	lwz r0, 0x148(r29)
/* 80074868  7C 7A 1B 78 */	mr r26, r3
/* 8007486C  2C 00 00 00 */	cmpwi r0, 0
/* 80074870  41 82 00 68 */	beq 0x68
/* 80074874  2C 03 00 00 */	cmpwi r3, 0
/* 80074878  3B 20 00 00 */	li r25, 0
/* 8007487C  41 82 00 5C */	beq 0x5c
/* 80074880  3B 60 00 00 */	li r27, 0
/* 80074884  3B 80 00 01 */	li r28, 1
/* 80074888  48 00 00 48 */	b 0x48
/* 8007488C  7F 24 CB 78 */	mr r4, r25
/* 80074890  38 61 00 1C */	addi r3, r1, 0x1c
/* 80074894  4B FD 9B 0D */	bl -0x264f4
/* 80074898  2C 03 00 00 */	cmpwi r3, 0
/* 8007489C  41 82 00 10 */	beq 0x10
/* 800748A0  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800748A4  54 00 C7 FE */	rlwinm r0, r0, 0x18, 0x1f, 0x1f
/* 800748A8  48 00 00 08 */	b 0x8
/* 800748AC  38 00 00 00 */	li r0, 0
/* 800748B0  2C 00 00 00 */	cmpwi r0, 0
/* 800748B4  41 82 00 10 */	beq 0x10
/* 800748B8  80 7D 01 48 */	lwz r3, 0x148(r29)
/* 800748BC  7F 83 C9 AE */	stbx r28, r3, r25
/* 800748C0  48 00 00 0C */	b 0xc
/* 800748C4  80 7D 01 48 */	lwz r3, 0x148(r29)
/* 800748C8  7F 63 C9 AE */	stbx r27, r3, r25
/* 800748CC  3B 39 00 01 */	addi r25, r25, 1
/* 800748D0  7C 19 D0 40 */	cmplw r25, r26
/* 800748D4  41 80 FF B8 */	blt -0x48
/* 800748D8  80 1D 01 3C */	lwz r0, 0x13c(r29)
/* 800748DC  54 00 00 3C */	rlwinm r0, r0, 0, 0, 0x1e
/* 800748E0  90 1D 01 3C */	stw r0, 0x13c(r29)
/* 800748E4  80 BD 01 28 */	lwz r5, 0x128(r29)
/* 800748E8  2C 05 00 00 */	cmpwi r5, 0
/* 800748EC  41 82 00 44 */	beq 0x44
/* 800748F0  80 7D 01 48 */	lwz r3, 0x148(r29)
/* 800748F4  2C 03 00 00 */	cmpwi r3, 0
/* 800748F8  41 82 00 24 */	beq 0x24
/* 800748FC  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80074900  38 81 00 14 */	addi r4, r1, 0x14
/* 80074904  90 01 00 14 */	stw r0, 0x14(r1)
/* 80074908  4B FE 26 C9 */	bl -0x1d938
/* 8007490C  80 1D 01 3C */	lwz r0, 0x13c(r29)
/* 80074910  60 00 00 01 */	ori r0, r0, 1
/* 80074914  90 1D 01 3C */	stw r0, 0x13c(r29)
/* 80074918  48 00 00 18 */	b 0x18
/* 8007491C  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80074920  7C A4 2B 78 */	mr r4, r5
/* 80074924  90 01 00 18 */	stw r0, 0x18(r1)
/* 80074928  38 61 00 18 */	addi r3, r1, 0x18
/* 8007492C  4B FE 25 E5 */	bl -0x1da1c
/* 80074930  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80074934  2C 03 00 00 */	cmpwi r3, 0
/* 80074938  41 82 02 D0 */	beq 0x2d0
/* 8007493C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80074940  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80074944  41 82 02 C4 */	beq 0x2c4
/* 80074948  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 8007494C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80074950  41 82 02 B8 */	beq 0x2b8
/* 80074954  81 83 00 00 */	lwz r12, 0(r3)
/* 80074958  7F A5 EB 78 */	mr r5, r29
/* 8007495C  7F C6 F3 78 */	mr r6, r30
/* 80074960  7F E7 FB 78 */	mr r7, r31
/* 80074964  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80074968  38 80 00 04 */	li r4, 4
/* 8007496C  7D 89 03 A6 */	mtctr r12
/* 80074970  4E 80 04 21 */	bctrl 
/* 80074974  48 00 02 94 */	b 0x294
/* 80074978  7F A3 EB 78 */	mr r3, r29
/* 8007497C  7F C4 F3 78 */	mr r4, r30
/* 80074980  7F E5 FB 78 */	mr r5, r31
/* 80074984  4B FF F6 7D */	bl -0x984
/* 80074988  48 00 02 80 */	b 0x280
/* 8007498C  7F A3 EB 78 */	mr r3, r29
/* 80074990  7F C4 F3 78 */	mr r4, r30
/* 80074994  7F E5 FB 78 */	mr r5, r31
/* 80074998  4B FF C7 C9 */	bl -0x3838
/* 8007499C  48 00 02 6C */	b 0x26c
/* 800749A0  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 800749A4  2C 04 00 00 */	cmpwi r4, 0
/* 800749A8  41 82 00 40 */	beq 0x40
/* 800749AC  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 800749B0  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 800749B4  41 82 00 34 */	beq 0x34
/* 800749B8  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 800749BC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 800749C0  41 82 00 28 */	beq 0x28
/* 800749C4  81 84 00 00 */	lwz r12, 0(r4)
/* 800749C8  7C 83 23 78 */	mr r3, r4
/* 800749CC  7F A5 EB 78 */	mr r5, r29
/* 800749D0  7F C6 F3 78 */	mr r6, r30
/* 800749D4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 800749D8  7F E7 FB 78 */	mr r7, r31
/* 800749DC  38 80 00 01 */	li r4, 1
/* 800749E0  7D 89 03 A6 */	mtctr r12
/* 800749E4  4E 80 04 21 */	bctrl 
/* 800749E8  2C 1F 00 00 */	cmpwi r31, 0
/* 800749EC  41 82 00 0C */	beq 0xc
/* 800749F0  83 3F 00 00 */	lwz r25, 0(r31)
/* 800749F4  48 00 00 08 */	b 0x8
/* 800749F8  83 3D 01 18 */	lwz r25, 0x118(r29)
/* 800749FC  83 5D 01 10 */	lwz r26, 0x110(r29)
/* 80074A00  7F A3 EB 78 */	mr r3, r29
/* 80074A04  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80074A08  90 01 00 10 */	stw r0, 0x10(r1)
/* 80074A0C  4B FF DF D5 */	bl -0x202c
/* 80074A10  7C 7C 1B 78 */	mr r28, r3
/* 80074A14  7F A3 EB 78 */	mr r3, r29
/* 80074A18  4B FF DF 89 */	bl -0x2078
/* 80074A1C  7C 7B 1B 78 */	mr r27, r3
/* 80074A20  7F A3 EB 78 */	mr r3, r29
/* 80074A24  4B FF DF 4D */	bl -0x20b4
/* 80074A28  7C 64 1B 78 */	mr r4, r3
/* 80074A2C  7F 65 DB 78 */	mr r5, r27
/* 80074A30  7F 86 E3 78 */	mr r6, r28
/* 80074A34  7F 47 D3 78 */	mr r7, r26
/* 80074A38  7F 2A CB 78 */	mr r10, r25
/* 80074A3C  38 61 00 10 */	addi r3, r1, 0x10
/* 80074A40  39 3D 01 44 */	addi r9, r29, 0x144
/* 80074A44  39 00 00 00 */	li r8, 0
/* 80074A48  4B FF 45 B9 */	bl -0xba48
/* 80074A4C  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80074A50  2C 03 00 00 */	cmpwi r3, 0
/* 80074A54  41 82 01 B4 */	beq 0x1b4
/* 80074A58  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80074A5C  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 80074A60  41 82 01 A8 */	beq 0x1a8
/* 80074A64  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80074A68  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80074A6C  41 82 01 9C */	beq 0x19c
/* 80074A70  81 83 00 00 */	lwz r12, 0(r3)
/* 80074A74  7F A5 EB 78 */	mr r5, r29
/* 80074A78  7F C6 F3 78 */	mr r6, r30
/* 80074A7C  7F E7 FB 78 */	mr r7, r31
/* 80074A80  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80074A84  38 80 00 04 */	li r4, 4
/* 80074A88  7D 89 03 A6 */	mtctr r12
/* 80074A8C  4E 80 04 21 */	bctrl 
/* 80074A90  48 00 01 78 */	b 0x178
/* 80074A94  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 80074A98  2C 04 00 00 */	cmpwi r4, 0
/* 80074A9C  41 82 00 40 */	beq 0x40
/* 80074AA0  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80074AA4  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80074AA8  41 82 00 34 */	beq 0x34
/* 80074AAC  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80074AB0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80074AB4  41 82 00 28 */	beq 0x28
/* 80074AB8  81 84 00 00 */	lwz r12, 0(r4)
/* 80074ABC  7C 83 23 78 */	mr r3, r4
/* 80074AC0  7F A5 EB 78 */	mr r5, r29
/* 80074AC4  7F C6 F3 78 */	mr r6, r30
/* 80074AC8  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80074ACC  7F E7 FB 78 */	mr r7, r31
/* 80074AD0  38 80 00 01 */	li r4, 1
/* 80074AD4  7D 89 03 A6 */	mtctr r12
/* 80074AD8  4E 80 04 21 */	bctrl 
/* 80074ADC  2C 1F 00 00 */	cmpwi r31, 0
/* 80074AE0  41 82 00 0C */	beq 0xc
/* 80074AE4  83 3F 00 00 */	lwz r25, 0(r31)
/* 80074AE8  48 00 00 08 */	b 0x8
/* 80074AEC  83 3D 01 18 */	lwz r25, 0x118(r29)
/* 80074AF0  83 5D 01 14 */	lwz r26, 0x114(r29)
/* 80074AF4  7F A3 EB 78 */	mr r3, r29
/* 80074AF8  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 80074AFC  90 01 00 0C */	stw r0, 0xc(r1)
/* 80074B00  4B FF DE E1 */	bl -0x2120
/* 80074B04  7C 7B 1B 78 */	mr r27, r3
/* 80074B08  7F A3 EB 78 */	mr r3, r29
/* 80074B0C  4B FF DE 95 */	bl -0x216c
/* 80074B10  7C 7C 1B 78 */	mr r28, r3
/* 80074B14  7F A3 EB 78 */	mr r3, r29
/* 80074B18  4B FF DE 59 */	bl -0x21a8
/* 80074B1C  7C 64 1B 78 */	mr r4, r3
/* 80074B20  7F 85 E3 78 */	mr r5, r28
/* 80074B24  7F 66 DB 78 */	mr r6, r27
/* 80074B28  7F 48 D3 78 */	mr r8, r26
/* 80074B2C  7F 2A CB 78 */	mr r10, r25
/* 80074B30  38 61 00 0C */	addi r3, r1, 0xc
/* 80074B34  39 3D 01 44 */	addi r9, r29, 0x144
/* 80074B38  38 E0 00 00 */	li r7, 0
/* 80074B3C  4B FF 44 C5 */	bl -0xbb3c
/* 80074B40  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80074B44  2C 03 00 00 */	cmpwi r3, 0
/* 80074B48  41 82 00 C0 */	beq 0xc0
/* 80074B4C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80074B50  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80074B54  41 82 00 B4 */	beq 0xb4
/* 80074B58  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80074B5C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80074B60  41 82 00 A8 */	beq 0xa8
/* 80074B64  81 83 00 00 */	lwz r12, 0(r3)
/* 80074B68  7F A5 EB 78 */	mr r5, r29
/* 80074B6C  7F C6 F3 78 */	mr r6, r30
/* 80074B70  7F E7 FB 78 */	mr r7, r31
/* 80074B74  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80074B78  38 80 00 04 */	li r4, 4
/* 80074B7C  7D 89 03 A6 */	mtctr r12
/* 80074B80  4E 80 04 21 */	bctrl 
/* 80074B84  48 00 00 84 */	b 0x84
/* 80074B88  7F A3 EB 78 */	mr r3, r29
/* 80074B8C  4B FF DC A5 */	bl -0x235c
/* 80074B90  80 7D 01 38 */	lwz r3, 0x138(r29)
/* 80074B94  2C 03 00 00 */	cmpwi r3, 0
/* 80074B98  41 82 00 70 */	beq 0x70
/* 80074B9C  81 83 00 00 */	lwz r12, 0(r3)
/* 80074BA0  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80074BA4  7D 89 03 A6 */	mtctr r12
/* 80074BA8  4E 80 04 21 */	bctrl 
/* 80074BAC  48 00 00 5C */	b 0x5c
/* 80074BB0  81 9D 00 00 */	lwz r12, 0(r29)
/* 80074BB4  7F A3 EB 78 */	mr r3, r29
/* 80074BB8  7F E4 FB 78 */	mr r4, r31
/* 80074BBC  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80074BC0  7D 89 03 A6 */	mtctr r12
/* 80074BC4  4E 80 04 21 */	bctrl 
/* 80074BC8  48 00 00 40 */	b 0x40
/* 80074BCC  80 83 01 38 */	lwz r4, 0x138(r3)
/* 80074BD0  2C 04 00 00 */	cmpwi r4, 0
/* 80074BD4  41 82 00 34 */	beq 0x34
/* 80074BD8  80 03 00 E8 */	lwz r0, 0xe8(r3)
/* 80074BDC  38 61 00 08 */	addi r3, r1, 8
/* 80074BE0  90 01 00 08 */	stw r0, 8(r1)
/* 80074BE4  80 BD 01 78 */	lwz r5, 0x178(r29)
/* 80074BE8  80 DD 01 7C */	lwz r6, 0x17c(r29)
/* 80074BEC  80 FD 01 80 */	lwz r7, 0x180(r29)
/* 80074BF0  48 00 35 21 */	bl 0x3520
/* 80074BF4  48 00 00 14 */	b 0x14
/* 80074BF8  7F A3 EB 78 */	mr r3, r29
/* 80074BFC  7F C5 F3 78 */	mr r5, r30
/* 80074C00  7F E6 FB 78 */	mr r6, r31
/* 80074C04  4B FF 94 AD */	bl -0x6b54
/* 80074C08  39 61 00 40 */	addi r11, r1, 0x40
/* 80074C0C  4B FA C9 D9 */	bl -0x53628
/* 80074C10  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80074C14  7C 08 03 A6 */	mtlr r0
/* 80074C18  38 21 00 40 */	addi r1, r1, 0x40
/* 80074C1C  4E 80 00 20 */	blr 
/* 80074C20  3C 04 FF FD */	addis r0, r4, 0xfffd
/* 80074C24  28 00 00 01 */	cmplwi r0, 1
/* 80074C28  40 82 00 2C */	bne 0x2c
/* 80074C2C  2C 05 00 00 */	cmpwi r5, 0
/* 80074C30  41 82 00 14 */	beq 0x14
/* 80074C34  80 03 01 3C */	lwz r0, 0x13c(r3)
/* 80074C38  54 00 07 FA */	rlwinm r0, r0, 0, 0x1f, 0x1d
/* 80074C3C  90 03 01 3C */	stw r0, 0x13c(r3)
/* 80074C40  48 00 00 18 */	b 0x18
/* 80074C44  80 03 01 3C */	lwz r0, 0x13c(r3)
/* 80074C48  60 00 00 02 */	ori r0, r0, 2
/* 80074C4C  90 03 01 3C */	stw r0, 0x13c(r3)
/* 80074C50  48 00 00 08 */	b 0x8
/* 80074C54  4B FF D0 EC */	b -0x2f14
/* 80074C58  38 60 00 01 */	li r3, 1
/* 80074C5C  4E 80 00 20 */	blr 
/* 80074C60  2C 05 00 00 */	cmpwi r5, 0
/* 80074C64  40 82 00 0C */	bne 0xc
/* 80074C68  38 60 00 00 */	li r3, 0
/* 80074C6C  4E 80 00 20 */	blr 
/* 80074C70  3C 04 FF FD */	addis r0, r4, 0xfffd
/* 80074C74  28 00 00 01 */	cmplwi r0, 1
/* 80074C78  40 82 00 1C */	bne 0x1c
/* 80074C7C  80 03 01 3C */	lwz r0, 0x13c(r3)
/* 80074C80  54 00 07 BC */	rlwinm r0, r0, 0, 0x1e, 0x1e
/* 80074C84  7C 00 00 34 */	cntlzw r0, r0
/* 80074C88  54 00 D9 7E */	srwi r0, r0, 5
/* 80074C8C  90 05 00 00 */	stw r0, 0(r5)
/* 80074C90  48 00 00 08 */	b 0x8
/* 80074C94  4B FF D0 EC */	b -0x2f14
/* 80074C98  38 60 00 01 */	li r3, 1
/* 80074C9C  4E 80 00 20 */	blr 
/* 80074CA0  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 80074CA4  7C 08 02 A6 */	mflr r0
/* 80074CA8  90 01 00 94 */	stw r0, 0x94(r1)
/* 80074CAC  39 61 00 90 */	addi r11, r1, 0x90
/* 80074CB0  4B FA C8 C5 */	bl -0x5373c
/* 80074CB4  80 03 00 E8 */	lwz r0, 0xe8(r3)
/* 80074CB8  7C 70 1B 78 */	mr r16, r3
/* 80074CBC  90 01 00 4C */	stw r0, 0x4c(r1)
/* 80074CC0  38 61 00 4C */	addi r3, r1, 0x4c
/* 80074CC4  4B FD 9D 8D */	bl -0x26274
/* 80074CC8  7C 7E 1B 78 */	mr r30, r3
/* 80074CCC  38 61 00 4C */	addi r3, r1, 0x4c
/* 80074CD0  4B FD 97 31 */	bl -0x268d0
/* 80074CD4  80 10 01 48 */	lwz r0, 0x148(r16)
/* 80074CD8  7C 73 1B 78 */	mr r19, r3
/* 80074CDC  2C 00 00 00 */	cmpwi r0, 0
/* 80074CE0  41 82 00 68 */	beq 0x68
/* 80074CE4  2C 03 00 00 */	cmpwi r3, 0
/* 80074CE8  3A 80 00 00 */	li r20, 0
/* 80074CEC  41 82 00 5C */	beq 0x5c
/* 80074CF0  3A 20 00 00 */	li r17, 0
/* 80074CF4  3A 40 00 01 */	li r18, 1
/* 80074CF8  48 00 00 48 */	b 0x48
/* 80074CFC  7E 84 A3 78 */	mr r4, r20
/* 80074D00  38 61 00 4C */	addi r3, r1, 0x4c
/* 80074D04  4B FD 96 9D */	bl -0x26964
/* 80074D08  2C 03 00 00 */	cmpwi r3, 0
/* 80074D0C  41 82 00 10 */	beq 0x10
/* 80074D10  80 03 00 14 */	lwz r0, 0x14(r3)
/* 80074D14  54 00 C7 FE */	rlwinm r0, r0, 0x18, 0x1f, 0x1f
/* 80074D18  48 00 00 08 */	b 0x8
/* 80074D1C  38 00 00 00 */	li r0, 0
/* 80074D20  2C 00 00 00 */	cmpwi r0, 0
/* 80074D24  41 82 00 10 */	beq 0x10
/* 80074D28  80 70 01 48 */	lwz r3, 0x148(r16)
/* 80074D2C  7E 43 A1 AE */	stbx r18, r3, r20
/* 80074D30  48 00 00 0C */	b 0xc
/* 80074D34  80 70 01 48 */	lwz r3, 0x148(r16)
/* 80074D38  7E 23 A1 AE */	stbx r17, r3, r20
/* 80074D3C  3A 94 00 01 */	addi r20, r20, 1
/* 80074D40  7C 14 98 40 */	cmplw r20, r19
/* 80074D44  41 80 FF B8 */	blt -0x48
/* 80074D48  3A 20 00 00 */	li r17, 0
/* 80074D4C  3B A0 00 00 */	li r29, 0
/* 80074D50  3B 80 00 00 */	li r28, 0
/* 80074D54  3B 60 00 00 */	li r27, 0
/* 80074D58  3B 40 00 00 */	li r26, 0
/* 80074D5C  3B 20 00 00 */	li r25, 0
/* 80074D60  3B 00 00 00 */	li r24, 0
/* 80074D64  3A E0 00 00 */	li r23, 0
/* 80074D68  3A C0 00 00 */	li r22, 0
/* 80074D6C  3A A0 00 00 */	li r21, 0
/* 80074D70  3A 80 00 00 */	li r20, 0
/* 80074D74  3A 60 00 00 */	li r19, 0
/* 80074D78  3A 40 00 00 */	li r18, 0
/* 80074D7C  3B E0 00 00 */	li r31, 0
/* 80074D80  48 00 02 9C */	b 0x29c
/* 80074D84  7E 24 8B 78 */	mr r4, r17
/* 80074D88  38 61 00 4C */	addi r3, r1, 0x4c
/* 80074D8C  4B FD 9C 65 */	bl -0x2639c
/* 80074D90  90 61 00 48 */	stw r3, 0x48(r1)
/* 80074D94  80 70 01 40 */	lwz r3, 0x140(r16)
/* 80074D98  7F E3 E9 2E */	stwx r31, r3, r29
/* 80074D9C  80 10 01 4C */	lwz r0, 0x14c(r16)
/* 80074DA0  2C 00 00 00 */	cmpwi r0, 0
/* 80074DA4  41 82 00 1C */	beq 0x1c
/* 80074DA8  80 A1 00 48 */	lwz r5, 0x48(r1)
/* 80074DAC  7C 80 E2 14 */	add r4, r0, r28
/* 80074DB0  38 61 00 44 */	addi r3, r1, 0x44
/* 80074DB4  38 05 00 40 */	addi r0, r5, 0x40
/* 80074DB8  90 01 00 44 */	stw r0, 0x44(r1)
/* 80074DBC  4B FD B9 45 */	bl -0x246bc
/* 80074DC0  80 10 01 50 */	lwz r0, 0x150(r16)
/* 80074DC4  2C 00 00 00 */	cmpwi r0, 0
/* 80074DC8  41 82 00 1C */	beq 0x1c
/* 80074DCC  80 A1 00 48 */	lwz r5, 0x48(r1)
/* 80074DD0  7C 80 DA 14 */	add r4, r0, r27
/* 80074DD4  38 61 00 40 */	addi r3, r1, 0x40
/* 80074DD8  38 05 01 44 */	addi r0, r5, 0x144
/* 80074DDC  90 01 00 40 */	stw r0, 0x40(r1)
/* 80074DE0  4B FD BA 51 */	bl -0x245b0
/* 80074DE4  80 10 01 54 */	lwz r0, 0x154(r16)
/* 80074DE8  2C 00 00 00 */	cmpwi r0, 0
/* 80074DEC  41 82 00 1C */	beq 0x1c
/* 80074DF0  80 A1 00 48 */	lwz r5, 0x48(r1)
/* 80074DF4  7C 80 D2 14 */	add r4, r0, r26
/* 80074DF8  38 61 00 3C */	addi r3, r1, 0x3c
/* 80074DFC  38 05 01 A8 */	addi r0, r5, 0x1a8
/* 80074E00  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80074E04  4B FD BA BD */	bl -0x24544
/* 80074E08  80 10 01 58 */	lwz r0, 0x158(r16)
/* 80074E0C  2C 00 00 00 */	cmpwi r0, 0
/* 80074E10  41 82 00 1C */	beq 0x1c
/* 80074E14  80 A1 00 48 */	lwz r5, 0x48(r1)
/* 80074E18  7C 80 CA 14 */	add r4, r0, r25
/* 80074E1C  38 61 00 38 */	addi r3, r1, 0x38
/* 80074E20  38 05 03 F0 */	addi r0, r5, 0x3f0
/* 80074E24  90 01 00 38 */	stw r0, 0x38(r1)
/* 80074E28  4B FD C9 C9 */	bl -0x23638
/* 80074E2C  80 10 01 5C */	lwz r0, 0x15c(r16)
/* 80074E30  2C 00 00 00 */	cmpwi r0, 0
/* 80074E34  41 82 00 1C */	beq 0x1c
/* 80074E38  80 A1 00 48 */	lwz r5, 0x48(r1)
/* 80074E3C  7C 80 C2 14 */	add r4, r0, r24
/* 80074E40  38 61 00 34 */	addi r3, r1, 0x34
/* 80074E44  38 05 00 14 */	addi r0, r5, 0x14
/* 80074E48  90 01 00 34 */	stw r0, 0x34(r1)
/* 80074E4C  4B FD BD 05 */	bl -0x242fc
/* 80074E50  80 10 01 60 */	lwz r0, 0x160(r16)
/* 80074E54  2C 00 00 00 */	cmpwi r0, 0
/* 80074E58  41 82 00 1C */	beq 0x1c
/* 80074E5C  80 A1 00 48 */	lwz r5, 0x48(r1)
/* 80074E60  7C 80 BA 14 */	add r4, r0, r23
/* 80074E64  38 61 00 30 */	addi r3, r1, 0x30
/* 80074E68  38 05 00 1C */	addi r0, r5, 0x1c
/* 80074E6C  90 01 00 30 */	stw r0, 0x30(r1)
/* 80074E70  4B FD BE 01 */	bl -0x24200
/* 80074E74  80 10 01 64 */	lwz r0, 0x164(r16)
/* 80074E78  2C 00 00 00 */	cmpwi r0, 0
/* 80074E7C  41 82 00 44 */	beq 0x44
/* 80074E80  80 61 00 48 */	lwz r3, 0x48(r1)
/* 80074E84  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80074E88  2C 00 00 00 */	cmpwi r0, 0
/* 80074E8C  41 82 00 0C */	beq 0xc
/* 80074E90  7C 03 02 14 */	add r0, r3, r0
/* 80074E94  48 00 00 08 */	b 0x8
/* 80074E98  38 00 00 00 */	li r0, 0
/* 80074E9C  90 01 00 28 */	stw r0, 0x28(r1)
/* 80074EA0  38 61 00 28 */	addi r3, r1, 0x28
/* 80074EA4  80 10 01 64 */	lwz r0, 0x164(r16)
/* 80074EA8  7C 80 B2 14 */	add r4, r0, r22
/* 80074EAC  4B FD B6 85 */	bl -0x2497c
/* 80074EB0  90 61 00 2C */	stw r3, 0x2c(r1)
/* 80074EB4  38 61 00 2C */	addi r3, r1, 0x2c
/* 80074EB8  38 80 00 00 */	li r4, 0
/* 80074EBC  4B FD B5 95 */	bl -0x24a6c
/* 80074EC0  80 10 01 68 */	lwz r0, 0x168(r16)
/* 80074EC4  2C 00 00 00 */	cmpwi r0, 0
/* 80074EC8  41 82 00 48 */	beq 0x48
/* 80074ECC  80 61 00 48 */	lwz r3, 0x48(r1)
/* 80074ED0  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80074ED4  2C 00 00 00 */	cmpwi r0, 0
/* 80074ED8  41 82 00 0C */	beq 0xc
/* 80074EDC  7C 63 02 14 */	add r3, r3, r0
/* 80074EE0  48 00 00 08 */	b 0x8
/* 80074EE4  38 60 00 00 */	li r3, 0
/* 80074EE8  38 03 00 20 */	addi r0, r3, 0x20
/* 80074EEC  90 01 00 20 */	stw r0, 0x20(r1)
/* 80074EF0  38 61 00 20 */	addi r3, r1, 0x20
/* 80074EF4  80 10 01 68 */	lwz r0, 0x168(r16)
/* 80074EF8  7C 80 AA 14 */	add r4, r0, r21
/* 80074EFC  4B FD B6 75 */	bl -0x2498c
/* 80074F00  90 61 00 24 */	stw r3, 0x24(r1)
/* 80074F04  38 61 00 24 */	addi r3, r1, 0x24
/* 80074F08  38 80 00 00 */	li r4, 0
/* 80074F0C  4B FD B5 65 */	bl -0x24a9c
/* 80074F10  80 10 01 6C */	lwz r0, 0x16c(r16)
/* 80074F14  2C 00 00 00 */	cmpwi r0, 0
/* 80074F18  41 82 00 48 */	beq 0x48
/* 80074F1C  80 61 00 48 */	lwz r3, 0x48(r1)
/* 80074F20  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80074F24  2C 00 00 00 */	cmpwi r0, 0
/* 80074F28  41 82 00 0C */	beq 0xc
/* 80074F2C  7C 63 02 14 */	add r3, r3, r0
/* 80074F30  48 00 00 08 */	b 0x8
/* 80074F34  38 60 00 00 */	li r3, 0
/* 80074F38  38 03 00 A0 */	addi r0, r3, 0xa0
/* 80074F3C  90 01 00 18 */	stw r0, 0x18(r1)
/* 80074F40  38 61 00 18 */	addi r3, r1, 0x18
/* 80074F44  80 10 01 6C */	lwz r0, 0x16c(r16)
/* 80074F48  7C 80 A2 14 */	add r4, r0, r20
/* 80074F4C  4B FD B6 65 */	bl -0x2499c
/* 80074F50  90 61 00 1C */	stw r3, 0x1c(r1)
/* 80074F54  38 61 00 1C */	addi r3, r1, 0x1c
/* 80074F58  38 80 00 00 */	li r4, 0
/* 80074F5C  4B FD B5 35 */	bl -0x24acc
/* 80074F60  80 10 01 70 */	lwz r0, 0x170(r16)
/* 80074F64  2C 00 00 00 */	cmpwi r0, 0
/* 80074F68  41 82 00 48 */	beq 0x48
/* 80074F6C  80 61 00 48 */	lwz r3, 0x48(r1)
/* 80074F70  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80074F74  2C 00 00 00 */	cmpwi r0, 0
/* 80074F78  41 82 00 0C */	beq 0xc
/* 80074F7C  7C 63 02 14 */	add r3, r3, r0
/* 80074F80  48 00 00 08 */	b 0x8
/* 80074F84  38 60 00 00 */	li r3, 0
/* 80074F88  38 03 00 E0 */	addi r0, r3, 0xe0
/* 80074F8C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80074F90  38 61 00 10 */	addi r3, r1, 0x10
/* 80074F94  80 10 01 70 */	lwz r0, 0x170(r16)
/* 80074F98  7C 80 9A 14 */	add r4, r0, r19
/* 80074F9C  4B FD B6 55 */	bl -0x249ac
/* 80074FA0  90 61 00 14 */	stw r3, 0x14(r1)
/* 80074FA4  38 61 00 14 */	addi r3, r1, 0x14
/* 80074FA8  38 80 00 00 */	li r4, 0
/* 80074FAC  4B FD B5 05 */	bl -0x24afc
/* 80074FB0  80 10 01 74 */	lwz r0, 0x174(r16)
/* 80074FB4  2C 00 00 00 */	cmpwi r0, 0
/* 80074FB8  41 82 00 30 */	beq 0x30
/* 80074FBC  38 61 00 48 */	addi r3, r1, 0x48
/* 80074FC0  4B FD D2 01 */	bl -0x22e00
/* 80074FC4  90 61 00 08 */	stw r3, 8(r1)
/* 80074FC8  38 61 00 08 */	addi r3, r1, 8
/* 80074FCC  80 10 01 74 */	lwz r0, 0x174(r16)
/* 80074FD0  7C 80 92 14 */	add r4, r0, r18
/* 80074FD4  4B FD B3 CD */	bl -0x24c34
/* 80074FD8  90 61 00 0C */	stw r3, 0xc(r1)
/* 80074FDC  38 61 00 0C */	addi r3, r1, 0xc
/* 80074FE0  38 80 00 00 */	li r4, 0
/* 80074FE4  4B FD B4 2D */	bl -0x24bd4
/* 80074FE8  3B BD 00 04 */	addi r29, r29, 4
/* 80074FEC  3B 9C 01 04 */	addi r28, r28, 0x104
/* 80074FF0  3B 7B 00 64 */	addi r27, r27, 0x64
/* 80074FF4  3B 5A 02 48 */	addi r26, r26, 0x248
/* 80074FF8  3B 39 00 28 */	addi r25, r25, 0x28
/* 80074FFC  3B 18 00 08 */	addi r24, r24, 8
/* 80075000  3A F7 00 0C */	addi r23, r23, 0xc
/* 80075004  3A D6 00 20 */	addi r22, r22, 0x20
/* 80075008  3A B5 00 80 */	addi r21, r21, 0x80
/* 8007500C  3A 94 00 40 */	addi r20, r20, 0x40
/* 80075010  3A 73 00 A0 */	addi r19, r19, 0xa0
/* 80075014  3A 52 02 00 */	addi r18, r18, 0x200
/* 80075018  3A 31 00 01 */	addi r17, r17, 1
/* 8007501C  7C 11 F0 40 */	cmplw r17, r30
/* 80075020  41 80 FD 64 */	blt -0x29c
/* 80075024  39 61 00 90 */	addi r11, r1, 0x90
/* 80075028  4B FA C5 99 */	bl -0x53a68
/* 8007502C  80 01 00 94 */	lwz r0, 0x94(r1)
/* 80075030  7C 08 03 A6 */	mtlr r0
/* 80075034  38 21 00 90 */	addi r1, r1, 0x90
/* 80075038  4E 80 00 20 */	blr 
/* 8007503C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075040  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80075044  7C 08 02 A6 */	mflr r0
/* 80075048  90 01 00 64 */	stw r0, 0x64(r1)
/* 8007504C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 80075050  7C BF 2B 78 */	mr r31, r5
/* 80075054  93 C1 00 58 */	stw r30, 0x58(r1)
/* 80075058  7C 9E 23 78 */	mr r30, r4
/* 8007505C  93 A1 00 54 */	stw r29, 0x54(r1)
/* 80075060  7C 7D 1B 78 */	mr r29, r3
/* 80075064  80 03 00 E8 */	lwz r0, 0xe8(r3)
/* 80075068  38 61 00 48 */	addi r3, r1, 0x48
/* 8007506C  90 01 00 48 */	stw r0, 0x48(r1)
/* 80075070  4B FD 99 81 */	bl -0x26680
/* 80075074  57 E0 07 FF */	clrlwi. r0, r31, 0x1f
/* 80075078  90 61 00 4C */	stw r3, 0x4c(r1)
/* 8007507C  41 82 00 28 */	beq 0x28
/* 80075080  80 9D 01 4C */	lwz r4, 0x14c(r29)
/* 80075084  2C 04 00 00 */	cmpwi r4, 0
/* 80075088  41 82 00 1C */	beq 0x1c
/* 8007508C  1C 1E 01 04 */	mulli r0, r30, 0x104
/* 80075090  38 63 00 40 */	addi r3, r3, 0x40
/* 80075094  90 61 00 44 */	stw r3, 0x44(r1)
/* 80075098  38 61 00 44 */	addi r3, r1, 0x44
/* 8007509C  7C 84 02 14 */	add r4, r4, r0
/* 800750A0  4B FD B6 61 */	bl -0x249a0
/* 800750A4  57 E0 07 BD */	rlwinm. r0, r31, 0, 0x1e, 0x1e
/* 800750A8  41 82 00 2C */	beq 0x2c
/* 800750AC  80 BD 01 50 */	lwz r5, 0x150(r29)
/* 800750B0  2C 05 00 00 */	cmpwi r5, 0
/* 800750B4  41 82 00 20 */	beq 0x20
/* 800750B8  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 800750BC  1C 1E 00 64 */	mulli r0, r30, 0x64
/* 800750C0  38 61 00 40 */	addi r3, r1, 0x40
/* 800750C4  38 84 01 44 */	addi r4, r4, 0x144
/* 800750C8  90 81 00 40 */	stw r4, 0x40(r1)
/* 800750CC  7C 85 02 14 */	add r4, r5, r0
/* 800750D0  4B FD B7 61 */	bl -0x248a0
/* 800750D4  57 E0 07 7B */	rlwinm. r0, r31, 0, 0x1d, 0x1d
/* 800750D8  41 82 00 2C */	beq 0x2c
/* 800750DC  80 BD 01 54 */	lwz r5, 0x154(r29)
/* 800750E0  2C 05 00 00 */	cmpwi r5, 0
/* 800750E4  41 82 00 20 */	beq 0x20
/* 800750E8  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 800750EC  1C 1E 02 48 */	mulli r0, r30, 0x248
/* 800750F0  38 61 00 3C */	addi r3, r1, 0x3c
/* 800750F4  38 84 01 A8 */	addi r4, r4, 0x1a8
/* 800750F8  90 81 00 3C */	stw r4, 0x3c(r1)
/* 800750FC  7C 85 02 14 */	add r4, r5, r0
/* 80075100  4B FD B7 C1 */	bl -0x24840
/* 80075104  57 E0 07 39 */	rlwinm. r0, r31, 0, 0x1c, 0x1c
/* 80075108  41 82 00 2C */	beq 0x2c
/* 8007510C  80 BD 01 58 */	lwz r5, 0x158(r29)
/* 80075110  2C 05 00 00 */	cmpwi r5, 0
/* 80075114  41 82 00 20 */	beq 0x20
/* 80075118  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 8007511C  1C 1E 00 28 */	mulli r0, r30, 0x28
/* 80075120  38 61 00 38 */	addi r3, r1, 0x38
/* 80075124  38 84 03 F0 */	addi r4, r4, 0x3f0
/* 80075128  90 81 00 38 */	stw r4, 0x38(r1)
/* 8007512C  7C 85 02 14 */	add r4, r5, r0
/* 80075130  4B FD C6 C1 */	bl -0x23940
/* 80075134  57 E0 06 F7 */	rlwinm. r0, r31, 0, 0x1b, 0x1b
/* 80075138  41 82 00 2C */	beq 0x2c
/* 8007513C  80 BD 01 5C */	lwz r5, 0x15c(r29)
/* 80075140  2C 05 00 00 */	cmpwi r5, 0
/* 80075144  41 82 00 20 */	beq 0x20
/* 80075148  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 8007514C  57 C0 18 38 */	slwi r0, r30, 3
/* 80075150  38 61 00 34 */	addi r3, r1, 0x34
/* 80075154  38 84 00 14 */	addi r4, r4, 0x14
/* 80075158  90 81 00 34 */	stw r4, 0x34(r1)
/* 8007515C  7C 85 02 14 */	add r4, r5, r0
/* 80075160  4B FD B9 F1 */	bl -0x24610
/* 80075164  57 E0 06 B5 */	rlwinm. r0, r31, 0, 0x1a, 0x1a
/* 80075168  41 82 00 2C */	beq 0x2c
/* 8007516C  80 BD 01 60 */	lwz r5, 0x160(r29)
/* 80075170  2C 05 00 00 */	cmpwi r5, 0
/* 80075174  41 82 00 20 */	beq 0x20
/* 80075178  80 81 00 4C */	lwz r4, 0x4c(r1)
/* 8007517C  1C 1E 00 0C */	mulli r0, r30, 0xc
/* 80075180  38 61 00 30 */	addi r3, r1, 0x30
/* 80075184  38 84 00 1C */	addi r4, r4, 0x1c
/* 80075188  90 81 00 30 */	stw r4, 0x30(r1)
/* 8007518C  7C 85 02 14 */	add r4, r5, r0
/* 80075190  4B FD BA E1 */	bl -0x24520
/* 80075194  57 E0 06 31 */	rlwinm. r0, r31, 0, 0x18, 0x18
/* 80075198  41 82 00 54 */	beq 0x54
/* 8007519C  80 1D 01 64 */	lwz r0, 0x164(r29)
/* 800751A0  2C 00 00 00 */	cmpwi r0, 0
/* 800751A4  41 82 00 48 */	beq 0x48
/* 800751A8  80 61 00 4C */	lwz r3, 0x4c(r1)
/* 800751AC  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 800751B0  2C 00 00 00 */	cmpwi r0, 0
/* 800751B4  41 82 00 0C */	beq 0xc
/* 800751B8  7C 03 02 14 */	add r0, r3, r0
/* 800751BC  48 00 00 08 */	b 0x8
/* 800751C0  38 00 00 00 */	li r0, 0
/* 800751C4  90 01 00 28 */	stw r0, 0x28(r1)
/* 800751C8  57 C0 28 34 */	slwi r0, r30, 5
/* 800751CC  38 61 00 28 */	addi r3, r1, 0x28
/* 800751D0  80 9D 01 64 */	lwz r4, 0x164(r29)
/* 800751D4  7C 84 02 14 */	add r4, r4, r0
/* 800751D8  4B FD B3 59 */	bl -0x24ca8
/* 800751DC  90 61 00 2C */	stw r3, 0x2c(r1)
/* 800751E0  38 61 00 2C */	addi r3, r1, 0x2c
/* 800751E4  38 80 00 00 */	li r4, 0
/* 800751E8  4B FD B2 69 */	bl -0x24d98
/* 800751EC  57 E0 05 EF */	rlwinm. r0, r31, 0, 0x17, 0x17
/* 800751F0  41 82 00 58 */	beq 0x58
/* 800751F4  80 1D 01 68 */	lwz r0, 0x168(r29)
/* 800751F8  2C 00 00 00 */	cmpwi r0, 0
/* 800751FC  41 82 00 4C */	beq 0x4c
/* 80075200  80 61 00 4C */	lwz r3, 0x4c(r1)
/* 80075204  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80075208  2C 00 00 00 */	cmpwi r0, 0
/* 8007520C  41 82 00 0C */	beq 0xc
/* 80075210  7C 63 02 14 */	add r3, r3, r0
/* 80075214  48 00 00 08 */	b 0x8
/* 80075218  38 60 00 00 */	li r3, 0
/* 8007521C  38 03 00 20 */	addi r0, r3, 0x20
/* 80075220  90 01 00 20 */	stw r0, 0x20(r1)
/* 80075224  57 C0 38 30 */	slwi r0, r30, 7
/* 80075228  38 61 00 20 */	addi r3, r1, 0x20
/* 8007522C  80 9D 01 68 */	lwz r4, 0x168(r29)
/* 80075230  7C 84 02 14 */	add r4, r4, r0
/* 80075234  4B FD B3 3D */	bl -0x24cc4
/* 80075238  90 61 00 24 */	stw r3, 0x24(r1)
/* 8007523C  38 61 00 24 */	addi r3, r1, 0x24
/* 80075240  38 80 00 00 */	li r4, 0
/* 80075244  4B FD B2 2D */	bl -0x24dd4
/* 80075248  57 E0 05 AD */	rlwinm. r0, r31, 0, 0x16, 0x16
/* 8007524C  41 82 00 58 */	beq 0x58
/* 80075250  80 1D 01 6C */	lwz r0, 0x16c(r29)
/* 80075254  2C 00 00 00 */	cmpwi r0, 0
/* 80075258  41 82 00 4C */	beq 0x4c
/* 8007525C  80 61 00 4C */	lwz r3, 0x4c(r1)
/* 80075260  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 80075264  2C 00 00 00 */	cmpwi r0, 0
/* 80075268  41 82 00 0C */	beq 0xc
/* 8007526C  7C 63 02 14 */	add r3, r3, r0
/* 80075270  48 00 00 08 */	b 0x8
/* 80075274  38 60 00 00 */	li r3, 0
/* 80075278  38 03 00 A0 */	addi r0, r3, 0xa0
/* 8007527C  90 01 00 18 */	stw r0, 0x18(r1)
/* 80075280  57 C0 30 32 */	slwi r0, r30, 6
/* 80075284  38 61 00 18 */	addi r3, r1, 0x18
/* 80075288  80 9D 01 6C */	lwz r4, 0x16c(r29)
/* 8007528C  7C 84 02 14 */	add r4, r4, r0
/* 80075290  4B FD B3 21 */	bl -0x24ce0
/* 80075294  90 61 00 1C */	stw r3, 0x1c(r1)
/* 80075298  38 61 00 1C */	addi r3, r1, 0x1c
/* 8007529C  38 80 00 00 */	li r4, 0
/* 800752A0  4B FD B1 F1 */	bl -0x24e10
/* 800752A4  57 E0 05 6B */	rlwinm. r0, r31, 0, 0x15, 0x15
/* 800752A8  41 82 00 58 */	beq 0x58
/* 800752AC  80 1D 01 70 */	lwz r0, 0x170(r29)
/* 800752B0  2C 00 00 00 */	cmpwi r0, 0
/* 800752B4  41 82 00 4C */	beq 0x4c
/* 800752B8  80 61 00 4C */	lwz r3, 0x4c(r1)
/* 800752BC  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 800752C0  2C 00 00 00 */	cmpwi r0, 0
/* 800752C4  41 82 00 0C */	beq 0xc
/* 800752C8  7C 63 02 14 */	add r3, r3, r0
/* 800752CC  48 00 00 08 */	b 0x8
/* 800752D0  38 60 00 00 */	li r3, 0
/* 800752D4  38 03 00 E0 */	addi r0, r3, 0xe0
/* 800752D8  90 01 00 10 */	stw r0, 0x10(r1)
/* 800752DC  1C 1E 00 A0 */	mulli r0, r30, 0xa0
/* 800752E0  38 61 00 10 */	addi r3, r1, 0x10
/* 800752E4  80 9D 01 70 */	lwz r4, 0x170(r29)
/* 800752E8  7C 84 02 14 */	add r4, r4, r0
/* 800752EC  4B FD B3 05 */	bl -0x24cfc
/* 800752F0  90 61 00 14 */	stw r3, 0x14(r1)
/* 800752F4  38 61 00 14 */	addi r3, r1, 0x14
/* 800752F8  38 80 00 00 */	li r4, 0
/* 800752FC  4B FD B1 B5 */	bl -0x24e4c
/* 80075300  57 E0 05 29 */	rlwinm. r0, r31, 0, 0x14, 0x14
/* 80075304  41 82 00 40 */	beq 0x40
/* 80075308  80 1D 01 74 */	lwz r0, 0x174(r29)
/* 8007530C  2C 00 00 00 */	cmpwi r0, 0
/* 80075310  41 82 00 34 */	beq 0x34
/* 80075314  38 61 00 4C */	addi r3, r1, 0x4c
/* 80075318  4B FD CE A9 */	bl -0x23158
/* 8007531C  90 61 00 08 */	stw r3, 8(r1)
/* 80075320  57 C0 48 2C */	slwi r0, r30, 9
/* 80075324  38 61 00 08 */	addi r3, r1, 8
/* 80075328  80 9D 01 74 */	lwz r4, 0x174(r29)
/* 8007532C  7C 84 02 14 */	add r4, r4, r0
/* 80075330  4B FD B0 71 */	bl -0x24f90
/* 80075334  90 61 00 0C */	stw r3, 0xc(r1)
/* 80075338  38 61 00 0C */	addi r3, r1, 0xc
/* 8007533C  38 80 00 00 */	li r4, 0
/* 80075340  4B FD B0 D1 */	bl -0x24f30
/* 80075344  80 9D 01 40 */	lwz r4, 0x140(r29)
/* 80075348  57 C3 10 3A */	slwi r3, r30, 2
/* 8007534C  7C 04 18 2E */	lwzx r0, r4, r3
/* 80075350  7C 00 F8 78 */	andc r0, r0, r31
/* 80075354  7C 04 19 2E */	stwx r0, r4, r3
/* 80075358  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 8007535C  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 80075360  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 80075364  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80075368  7C 08 03 A6 */	mtlr r0
/* 8007536C  38 21 00 60 */	addi r1, r1, 0x60
/* 80075370  4E 80 00 20 */	blr 
/* 80075374  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075378  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007537C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075380  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80075384  7C 08 02 A6 */	mflr r0
/* 80075388  2C 84 00 00 */	cmpwi cr1, r4, 0
/* 8007538C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80075390  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80075394  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80075398  7C BE 2B 78 */	mr r30, r5
/* 8007539C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800753A0  7C 9D 23 78 */	mr r29, r4
/* 800753A4  93 81 00 10 */	stw r28, 0x10(r1)
/* 800753A8  7C 7C 1B 78 */	mr r28, r3
/* 800753AC  41 86 01 14 */	beq cr1, 0x114
/* 800753B0  80 04 00 04 */	lwz r0, 4(r4)
/* 800753B4  2C 00 00 00 */	cmpwi r0, 0
/* 800753B8  40 82 01 08 */	bne 0x108
/* 800753BC  38 05 FF FB */	addi r0, r5, -5
/* 800753C0  28 00 00 01 */	cmplwi r0, 1
/* 800753C4  41 81 00 F4 */	bgt 0xf4
/* 800753C8  3B E0 00 00 */	li r31, 0
/* 800753CC  41 86 00 34 */	beq cr1, 0x34
/* 800753D0  3C 80 80 24 */	lis r4, 0x8024
/* 800753D4  7F A3 EB 78 */	mr r3, r29
/* 800753D8  38 84 76 58 */	addi r4, r4, 0x7658
/* 800753DC  90 81 00 08 */	stw r4, 8(r1)
/* 800753E0  38 81 00 08 */	addi r4, r1, 8
/* 800753E4  81 9D 00 00 */	lwz r12, 0(r29)
/* 800753E8  81 8C 00 08 */	lwz r12, 8(r12)
/* 800753EC  7D 89 03 A6 */	mtctr r12
/* 800753F0  4E 80 04 21 */	bctrl 
/* 800753F4  2C 03 00 00 */	cmpwi r3, 0
/* 800753F8  41 82 00 08 */	beq 0x8
/* 800753FC  3B E0 00 01 */	li r31, 1
/* 80075400  2C 1F 00 00 */	cmpwi r31, 0
/* 80075404  41 82 00 0C */	beq 0xc
/* 80075408  7F BF EB 78 */	mr r31, r29
/* 8007540C  48 00 00 08 */	b 0x8
/* 80075410  3B E0 00 00 */	li r31, 0
/* 80075414  2C 1F 00 00 */	cmpwi r31, 0
/* 80075418  41 82 00 7C */	beq 0x7c
/* 8007541C  7F E3 FB 78 */	mr r3, r31
/* 80075420  38 80 00 04 */	li r4, 4
/* 80075424  4B FE B1 7D */	bl -0x14e84
/* 80075428  2C 03 00 00 */	cmpwi r3, 0
/* 8007542C  40 82 00 0C */	bne 0xc
/* 80075430  38 60 00 00 */	li r3, 0
/* 80075434  48 00 00 90 */	b 0x90
/* 80075438  80 9C 01 38 */	lwz r4, 0x138(r28)
/* 8007543C  2C 04 00 00 */	cmpwi r4, 0
/* 80075440  41 82 00 18 */	beq 0x18
/* 80075444  81 9C 00 00 */	lwz r12, 0(r28)
/* 80075448  7F 83 E3 78 */	mr r3, r28
/* 8007544C  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80075450  7D 89 03 A6 */	mtctr r12
/* 80075454  4E 80 04 21 */	bctrl 
/* 80075458  93 FC 01 38 */	stw r31, 0x138(r28)
/* 8007545C  3C 80 00 01 */	lis r4, 1
/* 80075460  7F E3 FB 78 */	mr r3, r31
/* 80075464  7F 86 E3 78 */	mr r6, r28
/* 80075468  81 9F 00 00 */	lwz r12, 0(r31)
/* 8007546C  38 84 00 02 */	addi r4, r4, 2
/* 80075470  38 A0 00 00 */	li r5, 0
/* 80075474  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80075478  7D 89 03 A6 */	mtctr r12
/* 8007547C  4E 80 04 21 */	bctrl 
/* 80075480  80 1C 01 44 */	lwz r0, 0x144(r28)
/* 80075484  38 60 00 01 */	li r3, 1
/* 80075488  54 00 00 3C */	rlwinm r0, r0, 0, 0, 0x1e
/* 8007548C  90 1C 01 44 */	stw r0, 0x144(r28)
/* 80075490  48 00 00 34 */	b 0x34
/* 80075494  2C 1E 00 06 */	cmpwi r30, 6
/* 80075498  40 82 00 18 */	bne 0x18
/* 8007549C  7F 83 E3 78 */	mr r3, r28
/* 800754A0  7F A4 EB 78 */	mr r4, r29
/* 800754A4  7F C5 F3 78 */	mr r5, r30
/* 800754A8  4B FF CA 59 */	bl -0x35a8
/* 800754AC  48 00 00 18 */	b 0x18
/* 800754B0  38 60 00 00 */	li r3, 0
/* 800754B4  48 00 00 10 */	b 0x10
/* 800754B8  4B FF CA 49 */	bl -0x35b8
/* 800754BC  48 00 00 08 */	b 0x8
/* 800754C0  38 60 00 00 */	li r3, 0
/* 800754C4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800754C8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800754CC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800754D0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800754D4  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800754D8  7C 08 03 A6 */	mtlr r0
/* 800754DC  38 21 00 20 */	addi r1, r1, 0x20
/* 800754E0  4E 80 00 20 */	blr 
/* 800754E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800754E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800754EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800754F0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800754F4  7C 08 02 A6 */	mflr r0
/* 800754F8  2C 04 00 00 */	cmpwi r4, 0
/* 800754FC  90 01 00 44 */	stw r0, 0x44(r1)
/* 80075500  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80075504  7C 7F 1B 78 */	mr r31, r3
/* 80075508  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8007550C  93 A1 00 34 */	stw r29, 0x34(r1)
/* 80075510  93 81 00 30 */	stw r28, 0x30(r1)
/* 80075514  40 82 00 0C */	bne 0xc
/* 80075518  38 60 00 00 */	li r3, 0
/* 8007551C  48 00 01 AC */	b 0x1ac
/* 80075520  80 03 01 38 */	lwz r0, 0x138(r3)
/* 80075524  7C 04 00 40 */	cmplw r4, r0
/* 80075528  40 82 01 9C */	bne 0x19c
/* 8007552C  7C 03 03 78 */	mr r3, r0
/* 80075530  3C 80 00 01 */	lis r4, 1
/* 80075534  81 83 00 00 */	lwz r12, 0(r3)
/* 80075538  7F E6 FB 78 */	mr r6, r31
/* 8007553C  38 84 00 03 */	addi r4, r4, 3
/* 80075540  38 A0 00 00 */	li r5, 0
/* 80075544  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80075548  7D 89 03 A6 */	mtctr r12
/* 8007554C  4E 80 04 21 */	bctrl 
/* 80075550  80 1F 01 84 */	lwz r0, 0x184(r31)
/* 80075554  38 60 00 00 */	li r3, 0
/* 80075558  90 7F 01 38 */	stw r3, 0x138(r31)
/* 8007555C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80075560  40 82 00 18 */	bne 0x18
/* 80075564  80 1F 01 44 */	lwz r0, 0x144(r31)
/* 80075568  38 60 00 01 */	li r3, 1
/* 8007556C  60 00 00 01 */	ori r0, r0, 1
/* 80075570  90 1F 01 44 */	stw r0, 0x144(r31)
/* 80075574  48 00 01 54 */	b 0x154
/* 80075578  80 1F 01 78 */	lwz r0, 0x178(r31)
/* 8007557C  2C 00 00 00 */	cmpwi r0, 0
/* 80075580  41 82 00 64 */	beq 0x64
/* 80075584  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 80075588  38 61 00 1C */	addi r3, r1, 0x1c
/* 8007558C  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80075590  4B FD 8F C1 */	bl -0x27040
/* 80075594  7C 7E 1B 78 */	mr r30, r3
/* 80075598  3B 80 00 00 */	li r28, 0
/* 8007559C  3B A0 00 00 */	li r29, 0
/* 800755A0  48 00 00 3C */	b 0x3c
/* 800755A4  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 800755A8  7F 84 E3 78 */	mr r4, r28
/* 800755AC  90 01 00 18 */	stw r0, 0x18(r1)
/* 800755B0  38 61 00 18 */	addi r3, r1, 0x18
/* 800755B4  4B FD 8F 3D */	bl -0x270c4
/* 800755B8  90 61 00 28 */	stw r3, 0x28(r1)
/* 800755BC  80 9F 01 78 */	lwz r4, 0x178(r31)
/* 800755C0  7C 84 E8 2E */	lwzx r4, r4, r29
/* 800755C4  7C 03 20 40 */	cmplw r3, r4
/* 800755C8  41 82 00 0C */	beq 0xc
/* 800755CC  38 61 00 28 */	addi r3, r1, 0x28
/* 800755D0  4B FD CF 71 */	bl -0x23090
/* 800755D4  3B BD 00 04 */	addi r29, r29, 4
/* 800755D8  3B 9C 00 01 */	addi r28, r28, 1
/* 800755DC  7C 1C F0 40 */	cmplw r28, r30
/* 800755E0  41 80 FF C4 */	blt -0x3c
/* 800755E4  80 1F 01 7C */	lwz r0, 0x17c(r31)
/* 800755E8  2C 00 00 00 */	cmpwi r0, 0
/* 800755EC  41 82 00 64 */	beq 0x64
/* 800755F0  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 800755F4  38 61 00 14 */	addi r3, r1, 0x14
/* 800755F8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800755FC  4B FD 90 A5 */	bl -0x26f5c
/* 80075600  7C 7E 1B 78 */	mr r30, r3
/* 80075604  3B 80 00 00 */	li r28, 0
/* 80075608  3B A0 00 00 */	li r29, 0
/* 8007560C  48 00 00 3C */	b 0x3c
/* 80075610  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 80075614  7F 84 E3 78 */	mr r4, r28
/* 80075618  90 01 00 10 */	stw r0, 0x10(r1)
/* 8007561C  38 61 00 10 */	addi r3, r1, 0x10
/* 80075620  4B FD 90 21 */	bl -0x26fe0
/* 80075624  90 61 00 24 */	stw r3, 0x24(r1)
/* 80075628  80 9F 01 7C */	lwz r4, 0x17c(r31)
/* 8007562C  7C 84 E8 2E */	lwzx r4, r4, r29
/* 80075630  7C 03 20 40 */	cmplw r3, r4
/* 80075634  41 82 00 0C */	beq 0xc
/* 80075638  38 61 00 24 */	addi r3, r1, 0x24
/* 8007563C  4B FD CF E5 */	bl -0x2301c
/* 80075640  3B BD 00 04 */	addi r29, r29, 4
/* 80075644  3B 9C 00 01 */	addi r28, r28, 1
/* 80075648  7C 1C F0 40 */	cmplw r28, r30
/* 8007564C  41 80 FF C4 */	blt -0x3c
/* 80075650  80 1F 01 80 */	lwz r0, 0x180(r31)
/* 80075654  2C 00 00 00 */	cmpwi r0, 0
/* 80075658  41 82 00 64 */	beq 0x64
/* 8007565C  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 80075660  38 61 00 0C */	addi r3, r1, 0xc
/* 80075664  90 01 00 0C */	stw r0, 0xc(r1)
/* 80075668  4B FD 91 89 */	bl -0x26e78
/* 8007566C  7C 7E 1B 78 */	mr r30, r3
/* 80075670  3B 80 00 00 */	li r28, 0
/* 80075674  3B A0 00 00 */	li r29, 0
/* 80075678  48 00 00 3C */	b 0x3c
/* 8007567C  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 80075680  7F 84 E3 78 */	mr r4, r28
/* 80075684  90 01 00 08 */	stw r0, 8(r1)
/* 80075688  38 61 00 08 */	addi r3, r1, 8
/* 8007568C  4B FD 91 05 */	bl -0x26efc
/* 80075690  90 61 00 20 */	stw r3, 0x20(r1)
/* 80075694  80 9F 01 80 */	lwz r4, 0x180(r31)
/* 80075698  7C 84 E8 2E */	lwzx r4, r4, r29
/* 8007569C  7C 03 20 40 */	cmplw r3, r4
/* 800756A0  41 82 00 0C */	beq 0xc
/* 800756A4  38 61 00 20 */	addi r3, r1, 0x20
/* 800756A8  4B FD D0 59 */	bl -0x22fa8
/* 800756AC  3B BD 00 04 */	addi r29, r29, 4
/* 800756B0  3B 9C 00 01 */	addi r28, r28, 1
/* 800756B4  7C 1C F0 40 */	cmplw r28, r30
/* 800756B8  41 80 FF C4 */	blt -0x3c
/* 800756BC  38 60 00 01 */	li r3, 1
/* 800756C0  48 00 00 08 */	b 0x8
/* 800756C4  4B FF CE 4D */	bl -0x31b4
/* 800756C8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800756CC  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 800756D0  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 800756D4  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 800756D8  83 81 00 30 */	lwz r28, 0x30(r1)
/* 800756DC  7C 08 03 A6 */	mtlr r0
/* 800756E0  38 21 00 40 */	addi r1, r1, 0x40
/* 800756E4  4E 80 00 20 */	blr 
/* 800756E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800756EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800756F0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800756F4  7C 08 02 A6 */	mflr r0
/* 800756F8  2C 04 00 05 */	cmpwi r4, 5
/* 800756FC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80075700  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80075704  40 82 00 24 */	bne 0x24
/* 80075708  81 83 00 00 */	lwz r12, 0(r3)
/* 8007570C  83 E3 01 38 */	lwz r31, 0x138(r3)
/* 80075710  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80075714  7F E4 FB 78 */	mr r4, r31
/* 80075718  7D 89 03 A6 */	mtctr r12
/* 8007571C  4E 80 04 21 */	bctrl 
/* 80075720  7F E3 FB 78 */	mr r3, r31
/* 80075724  48 00 00 08 */	b 0x8
/* 80075728  4B FF CF 69 */	bl -0x3098
/* 8007572C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80075730  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80075734  7C 08 03 A6 */	mtlr r0
/* 80075738  38 21 00 10 */	addi r1, r1, 0x10
/* 8007573C  4E 80 00 20 */	blr 
/* 80075740  2C 04 00 05 */	cmpwi r4, 5
/* 80075744  40 82 00 0C */	bne 0xc
/* 80075748  80 63 01 38 */	lwz r3, 0x138(r3)
/* 8007574C  4E 80 00 20 */	blr 
/* 80075750  4B FF D0 20 */	b -0x2fe0
/* 80075754  4E 80 00 20 */	blr 
/* 80075758  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007575C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075760  2C 04 00 05 */	cmpwi r4, 5
/* 80075764  40 82 00 0C */	bne 0xc
/* 80075768  80 63 01 38 */	lwz r3, 0x138(r3)
/* 8007576C  4E 80 00 20 */	blr 
/* 80075770  4B FF D0 60 */	b -0x2fa0
/* 80075774  4E 80 00 20 */	blr 
/* 80075778  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007577C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075780  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80075784  7C 08 02 A6 */	mflr r0
/* 80075788  2C 03 00 00 */	cmpwi r3, 0
/* 8007578C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80075790  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80075794  7C 7F 1B 78 */	mr r31, r3
/* 80075798  41 82 00 38 */	beq 0x38
/* 8007579C  80 83 01 38 */	lwz r4, 0x138(r3)
/* 800757A0  3C A0 80 27 */	lis r5, 0x8027
/* 800757A4  38 A5 32 48 */	addi r5, r5, 0x3248
/* 800757A8  90 A3 00 00 */	stw r5, 0(r3)
/* 800757AC  2C 04 00 00 */	cmpwi r4, 0
/* 800757B0  41 82 00 14 */	beq 0x14
/* 800757B4  81 83 00 00 */	lwz r12, 0(r3)
/* 800757B8  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 800757BC  7D 89 03 A6 */	mtctr r12
/* 800757C0  4E 80 04 21 */	bctrl 
/* 800757C4  7F E3 FB 78 */	mr r3, r31
/* 800757C8  38 80 00 00 */	li r4, 0
/* 800757CC  4B FF D4 C5 */	bl -0x2b3c
/* 800757D0  7F E3 FB 78 */	mr r3, r31
/* 800757D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800757D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800757DC  7C 08 03 A6 */	mtlr r0
/* 800757E0  38 21 00 10 */	addi r1, r1, 0x10
/* 800757E4  4E 80 00 20 */	blr 
/* 800757E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800757EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800757F0  3C 60 80 24 */	lis r3, 0x8024
/* 800757F4  80 04 00 00 */	lwz r0, 0(r4)
/* 800757F8  38 63 7F C8 */	addi r3, r3, 0x7fc8
/* 800757FC  7C 00 18 40 */	cmplw r0, r3
/* 80075800  40 82 00 0C */	bne 0xc
/* 80075804  38 60 00 01 */	li r3, 1
/* 80075808  4E 80 00 20 */	blr 
/* 8007580C  3C 60 80 24 */	lis r3, 0x8024
/* 80075810  80 04 00 00 */	lwz r0, 0(r4)
/* 80075814  38 63 7F B0 */	addi r3, r3, 0x7fb0
/* 80075818  7C 00 18 40 */	cmplw r0, r3
/* 8007581C  40 82 00 0C */	bne 0xc
/* 80075820  38 60 00 01 */	li r3, 1
/* 80075824  4E 80 00 20 */	blr 
/* 80075828  3C 60 80 24 */	lis r3, 0x8024
/* 8007582C  38 63 7F 80 */	addi r3, r3, 0x7f80
/* 80075830  7C 00 18 40 */	cmplw r0, r3
/* 80075834  40 82 00 0C */	bne 0xc
/* 80075838  38 60 00 01 */	li r3, 1
/* 8007583C  4E 80 00 20 */	blr 
/* 80075840  3C 60 80 24 */	lis r3, 0x8024
/* 80075844  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 80075848  7C 00 18 40 */	cmplw r0, r3
/* 8007584C  40 82 00 0C */	bne 0xc
/* 80075850  38 60 00 01 */	li r3, 1
/* 80075854  4E 80 00 20 */	blr 
/* 80075858  3C 60 80 24 */	lis r3, 0x8024
/* 8007585C  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 80075860  7C 00 18 50 */	subf r0, r0, r3
/* 80075864  7C 00 00 34 */	cntlzw r0, r0
/* 80075868  54 03 D9 7E */	srwi r3, r0, 5
/* 8007586C  4E 80 00 20 */	blr 
/* 80075870  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80075874  7C 08 02 A6 */	mflr r0
/* 80075878  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007587C  81 83 00 00 */	lwz r12, 0(r3)
/* 80075880  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80075884  7D 89 03 A6 */	mtctr r12
/* 80075888  4E 80 04 21 */	bctrl 
/* 8007588C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80075890  38 63 00 04 */	addi r3, r3, 4
/* 80075894  7C 08 03 A6 */	mtlr r0
/* 80075898  38 21 00 10 */	addi r1, r1, 0x10
/* 8007589C  4E 80 00 20 */	blr 
/* 800758A0  3C 60 80 24 */	lis r3, 0x8024
/* 800758A4  38 63 7F C8 */	addi r3, r3, 0x7fc8
/* 800758A8  4E 80 00 20 */	blr 
/* 800758AC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800758B0  38 60 00 00 */	li r3, 0
/* 800758B4  4E 80 00 20 */	blr 
/* 800758B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800758BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800758C0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800758C4  7C 08 02 A6 */	mflr r0
/* 800758C8  90 01 00 34 */	stw r0, 0x34(r1)
/* 800758CC  39 61 00 30 */	addi r11, r1, 0x30
/* 800758D0  4B FA BC CD */	bl -0x54334
/* 800758D4  7C 7A 1B 78 */	mr r26, r3
/* 800758D8  80 63 00 08 */	lwz r3, 8(r3)
/* 800758DC  7C 9B 23 78 */	mr r27, r4
/* 800758E0  7C BC 2B 78 */	mr r28, r5
/* 800758E4  81 83 00 00 */	lwz r12, 0(r3)
/* 800758E8  7C DD 33 78 */	mr r29, r6
/* 800758EC  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 800758F0  7D 89 03 A6 */	mtctr r12
/* 800758F4  4E 80 04 21 */	bctrl 
/* 800758F8  2C 03 00 00 */	cmpwi r3, 0
/* 800758FC  40 82 00 28 */	bne 0x28
/* 80075900  80 7A 00 08 */	lwz r3, 8(r26)
/* 80075904  7F 64 DB 78 */	mr r4, r27
/* 80075908  7F 85 E3 78 */	mr r5, r28
/* 8007590C  7F A6 EB 78 */	mr r6, r29
/* 80075910  81 83 00 00 */	lwz r12, 0(r3)
/* 80075914  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80075918  7D 89 03 A6 */	mtctr r12
/* 8007591C  4E 80 04 21 */	bctrl 
/* 80075920  48 00 00 B8 */	b 0xb8
/* 80075924  2C 1B 00 00 */	cmpwi r27, 0
/* 80075928  83 DA 00 08 */	lwz r30, 8(r26)
/* 8007592C  3B E0 00 00 */	li r31, 0
/* 80075930  41 82 00 34 */	beq 0x34
/* 80075934  3C 80 80 24 */	lis r4, 0x8024
/* 80075938  7F 63 DB 78 */	mr r3, r27
/* 8007593C  38 84 7F D8 */	addi r4, r4, 0x7fd8
/* 80075940  90 81 00 08 */	stw r4, 8(r1)
/* 80075944  38 81 00 08 */	addi r4, r1, 8
/* 80075948  81 9B 00 00 */	lwz r12, 0(r27)
/* 8007594C  81 8C 00 08 */	lwz r12, 8(r12)
/* 80075950  7D 89 03 A6 */	mtctr r12
/* 80075954  4E 80 04 21 */	bctrl 
/* 80075958  2C 03 00 00 */	cmpwi r3, 0
/* 8007595C  41 82 00 08 */	beq 0x8
/* 80075960  3B E0 00 01 */	li r31, 1
/* 80075964  2C 1F 00 00 */	cmpwi r31, 0
/* 80075968  41 82 00 0C */	beq 0xc
/* 8007596C  7F 64 DB 78 */	mr r4, r27
/* 80075970  48 00 00 08 */	b 0x8
/* 80075974  38 80 00 00 */	li r4, 0
/* 80075978  2C 04 00 00 */	cmpwi r4, 0
/* 8007597C  3B E0 00 00 */	li r31, 0
/* 80075980  41 82 00 28 */	beq 0x28
/* 80075984  81 9E 00 00 */	lwz r12, 0(r30)
/* 80075988  7F C3 F3 78 */	mr r3, r30
/* 8007598C  80 84 00 E8 */	lwz r4, 0xe8(r4)
/* 80075990  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80075994  7D 89 03 A6 */	mtctr r12
/* 80075998  4E 80 04 21 */	bctrl 
/* 8007599C  2C 03 00 00 */	cmpwi r3, 0
/* 800759A0  41 82 00 08 */	beq 0x8
/* 800759A4  3B E0 00 01 */	li r31, 1
/* 800759A8  2C 1F 00 00 */	cmpwi r31, 0
/* 800759AC  41 82 00 0C */	beq 0xc
/* 800759B0  38 60 00 00 */	li r3, 0
/* 800759B4  48 00 00 24 */	b 0x24
/* 800759B8  80 7A 00 04 */	lwz r3, 4(r26)
/* 800759BC  7F 64 DB 78 */	mr r4, r27
/* 800759C0  7F 85 E3 78 */	mr r5, r28
/* 800759C4  7F A6 EB 78 */	mr r6, r29
/* 800759C8  81 83 00 00 */	lwz r12, 0(r3)
/* 800759CC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800759D0  7D 89 03 A6 */	mtctr r12
/* 800759D4  4E 80 04 21 */	bctrl 
/* 800759D8  39 61 00 30 */	addi r11, r1, 0x30
/* 800759DC  4B FA BC 0D */	bl -0x543f4
/* 800759E0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800759E4  7C 08 03 A6 */	mtlr r0
/* 800759E8  38 21 00 30 */	addi r1, r1, 0x30
/* 800759EC  4E 80 00 20 */	blr 
/* 800759F0  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 800759F4  7C 87 23 78 */	mr r7, r4
/* 800759F8  2C 00 00 00 */	cmpwi r0, 0
/* 800759FC  4D 82 00 20 */	beqlr 
/* 80075A00  80 A3 00 10 */	lwz r5, 0x10(r3)
/* 80075A04  7C 04 03 78 */	mr r4, r0
/* 80075A08  80 C3 00 04 */	lwz r6, 4(r3)
/* 80075A0C  39 00 00 01 */	li r8, 1
/* 80075A10  48 00 01 D0 */	b 0x1d0
/* 80075A14  4E 80 00 20 */	blr 
/* 80075A18  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075A1C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075A20  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80075A24  7C 87 23 78 */	mr r7, r4
/* 80075A28  2C 00 00 00 */	cmpwi r0, 0
/* 80075A2C  4D 82 00 20 */	beqlr 
/* 80075A30  80 A3 00 14 */	lwz r5, 0x14(r3)
/* 80075A34  7C 04 03 78 */	mr r4, r0
/* 80075A38  80 C3 00 08 */	lwz r6, 8(r3)
/* 80075A3C  39 00 00 00 */	li r8, 0
/* 80075A40  48 00 01 A0 */	b 0x1a0
/* 80075A44  4E 80 00 20 */	blr 
/* 80075A48  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075A4C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075A50  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80075A54  7C 08 02 A6 */	mflr r0
/* 80075A58  90 01 00 34 */	stw r0, 0x34(r1)
/* 80075A5C  39 61 00 30 */	addi r11, r1, 0x30
/* 80075A60  4B FA BB 39 */	bl -0x544c8
/* 80075A64  2C 04 00 00 */	cmpwi r4, 0
/* 80075A68  7C 79 1B 78 */	mr r25, r3
/* 80075A6C  7C 9A 23 78 */	mr r26, r4
/* 80075A70  3B E0 00 00 */	li r31, 0
/* 80075A74  41 82 00 34 */	beq 0x34
/* 80075A78  3C 80 80 24 */	lis r4, 0x8024
/* 80075A7C  7F 43 D3 78 */	mr r3, r26
/* 80075A80  38 84 7F B0 */	addi r4, r4, 0x7fb0
/* 80075A84  90 81 00 08 */	stw r4, 8(r1)
/* 80075A88  38 81 00 08 */	addi r4, r1, 8
/* 80075A8C  81 9A 00 00 */	lwz r12, 0(r26)
/* 80075A90  81 8C 00 08 */	lwz r12, 8(r12)
/* 80075A94  7D 89 03 A6 */	mtctr r12
/* 80075A98  4E 80 04 21 */	bctrl 
/* 80075A9C  2C 03 00 00 */	cmpwi r3, 0
/* 80075AA0  41 82 00 08 */	beq 0x8
/* 80075AA4  3B E0 00 01 */	li r31, 1
/* 80075AA8  2C 1F 00 00 */	cmpwi r31, 0
/* 80075AAC  41 82 00 08 */	beq 0x8
/* 80075AB0  48 00 00 08 */	b 0x8
/* 80075AB4  3B 40 00 00 */	li r26, 0
/* 80075AB8  2C 1A 00 00 */	cmpwi r26, 0
/* 80075ABC  3B E0 00 00 */	li r31, 0
/* 80075AC0  3B C0 00 00 */	li r30, 0
/* 80075AC4  3B A0 00 00 */	li r29, 0
/* 80075AC8  3B 80 00 00 */	li r28, 0
/* 80075ACC  3B 60 00 00 */	li r27, 0
/* 80075AD0  41 82 00 28 */	beq 0x28
/* 80075AD4  81 99 00 00 */	lwz r12, 0(r25)
/* 80075AD8  7F 23 CB 78 */	mr r3, r25
/* 80075ADC  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80075AE0  7D 89 03 A6 */	mtctr r12
/* 80075AE4  4E 80 04 21 */	bctrl 
/* 80075AE8  80 1A 00 E8 */	lwz r0, 0xe8(r26)
/* 80075AEC  7C 00 18 40 */	cmplw r0, r3
/* 80075AF0  40 82 00 08 */	bne 0x8
/* 80075AF4  3B 60 00 01 */	li r27, 1
/* 80075AF8  2C 1B 00 00 */	cmpwi r27, 0
/* 80075AFC  41 82 00 28 */	beq 0x28
/* 80075B00  81 9A 00 00 */	lwz r12, 0(r26)
/* 80075B04  7F 43 D3 78 */	mr r3, r26
/* 80075B08  38 80 00 02 */	li r4, 2
/* 80075B0C  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80075B10  7D 89 03 A6 */	mtctr r12
/* 80075B14  4E 80 04 21 */	bctrl 
/* 80075B18  2C 03 00 00 */	cmpwi r3, 0
/* 80075B1C  40 82 00 08 */	bne 0x8
/* 80075B20  3B 80 00 01 */	li r28, 1
/* 80075B24  2C 1C 00 00 */	cmpwi r28, 0
/* 80075B28  41 82 00 28 */	beq 0x28
/* 80075B2C  81 9A 00 00 */	lwz r12, 0(r26)
/* 80075B30  7F 43 D3 78 */	mr r3, r26
/* 80075B34  38 80 00 03 */	li r4, 3
/* 80075B38  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80075B3C  7D 89 03 A6 */	mtctr r12
/* 80075B40  4E 80 04 21 */	bctrl 
/* 80075B44  2C 03 00 00 */	cmpwi r3, 0
/* 80075B48  40 82 00 08 */	bne 0x8
/* 80075B4C  3B A0 00 01 */	li r29, 1
/* 80075B50  2C 1D 00 00 */	cmpwi r29, 0
/* 80075B54  41 82 00 28 */	beq 0x28
/* 80075B58  81 9A 00 00 */	lwz r12, 0(r26)
/* 80075B5C  7F 43 D3 78 */	mr r3, r26
/* 80075B60  38 80 00 04 */	li r4, 4
/* 80075B64  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80075B68  7D 89 03 A6 */	mtctr r12
/* 80075B6C  4E 80 04 21 */	bctrl 
/* 80075B70  2C 03 00 00 */	cmpwi r3, 0
/* 80075B74  40 82 00 08 */	bne 0x8
/* 80075B78  3B C0 00 01 */	li r30, 1
/* 80075B7C  2C 1E 00 00 */	cmpwi r30, 0
/* 80075B80  41 82 00 28 */	beq 0x28
/* 80075B84  81 9A 00 00 */	lwz r12, 0(r26)
/* 80075B88  7F 43 D3 78 */	mr r3, r26
/* 80075B8C  38 80 00 05 */	li r4, 5
/* 80075B90  81 8C 00 40 */	lwz r12, 0x40(r12)
/* 80075B94  7D 89 03 A6 */	mtctr r12
/* 80075B98  4E 80 04 21 */	bctrl 
/* 80075B9C  2C 03 00 00 */	cmpwi r3, 0
/* 80075BA0  40 82 00 08 */	bne 0x8
/* 80075BA4  3B E0 00 01 */	li r31, 1
/* 80075BA8  7F E0 00 34 */	cntlzw r0, r31
/* 80075BAC  39 61 00 30 */	addi r11, r1, 0x30
/* 80075BB0  54 03 D9 7E */	srwi r3, r0, 5
/* 80075BB4  4B FA BA 31 */	bl -0x545d0
/* 80075BB8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80075BBC  7C 08 03 A6 */	mtlr r0
/* 80075BC0  38 21 00 30 */	addi r1, r1, 0x30
/* 80075BC4  4E 80 00 20 */	blr 
/* 80075BC8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075BCC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075BD0  80 63 00 18 */	lwz r3, 0x18(r3)
/* 80075BD4  4E 80 00 20 */	blr 
/* 80075BD8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075BDC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80075BE0  94 21 FF 50 */	stwu r1, -0xb0(r1)
/* 80075BE4  7C 08 02 A6 */	mflr r0
/* 80075BE8  90 01 00 B4 */	stw r0, 0xb4(r1)
/* 80075BEC  39 61 00 B0 */	addi r11, r1, 0xb0
/* 80075BF0  4B FA B9 7D */	bl -0x54684
/* 80075BF4  2C 07 00 00 */	cmpwi r7, 0
/* 80075BF8  90 61 00 08 */	stw r3, 8(r1)
/* 80075BFC  7C 93 23 78 */	mr r19, r4
/* 80075C00  7C B4 2B 78 */	mr r20, r5
/* 80075C04  90 C1 00 0C */	stw r6, 0xc(r1)
/* 80075C08  7C F5 3B 78 */	mr r21, r7
/* 80075C0C  7D 0E 43 78 */	mr r14, r8
/* 80075C10  3B 20 00 00 */	li r25, 0
/* 80075C14  3B 60 00 00 */	li r27, 0
/* 80075C18  41 82 00 14 */	beq 0x14
/* 80075C1C  80 07 00 00 */	lwz r0, 0(r7)
/* 80075C20  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80075C24  41 82 00 08 */	beq 0x8
/* 80075C28  3B 60 00 01 */	li r27, 1
/* 80075C2C  3F E0 80 24 */	lis r31, 0x8024
/* 80075C30  3E 00 80 24 */	lis r16, 0x8024
/* 80075C34  3B FF 7F C8 */	addi r31, r31, 0x7fc8
/* 80075C38  3A 10 7F B0 */	addi r16, r16, 0x7fb0
/* 80075C3C  48 00 03 70 */	b 0x370
/* 80075C40  80 61 00 08 */	lwz r3, 8(r1)
/* 80075C44  81 83 00 00 */	lwz r12, 0(r3)
/* 80075C48  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80075C4C  7D 89 03 A6 */	mtctr r12
/* 80075C50  4E 80 04 21 */	bctrl 
/* 80075C54  88 13 00 01 */	lbz r0, 1(r19)
/* 80075C58  90 61 00 48 */	stw r3, 0x48(r1)
/* 80075C5C  38 61 00 48 */	addi r3, r1, 0x48
/* 80075C60  88 93 00 02 */	lbz r4, 2(r19)
/* 80075C64  50 04 44 2E */	rlwimi r4, r0, 8, 0x10, 0x17
/* 80075C68  4B FD 8D 29 */	bl -0x272d8
/* 80075C6C  7C 7C 1B 78 */	mr r28, r3
/* 80075C70  80 61 00 08 */	lwz r3, 8(r1)
/* 80075C74  81 83 00 00 */	lwz r12, 0(r3)
/* 80075C78  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80075C7C  7D 89 03 A6 */	mtctr r12
/* 80075C80  4E 80 04 21 */	bctrl 
/* 80075C84  88 13 00 03 */	lbz r0, 3(r19)
/* 80075C88  90 61 00 44 */	stw r3, 0x44(r1)
/* 80075C8C  38 61 00 44 */	addi r3, r1, 0x44
/* 80075C90  88 93 00 04 */	lbz r4, 4(r19)
/* 80075C94  50 04 44 2E */	rlwimi r4, r0, 8, 0x10, 0x17
/* 80075C98  4B FD 8D F9 */	bl -0x27208
/* 80075C9C  7C 7D 1B 78 */	mr r29, r3
/* 80075CA0  80 61 00 08 */	lwz r3, 8(r1)
/* 80075CA4  81 83 00 00 */	lwz r12, 0(r3)
/* 80075CA8  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 80075CAC  7D 89 03 A6 */	mtctr r12
/* 80075CB0  4E 80 04 21 */	bctrl 
/* 80075CB4  88 13 00 05 */	lbz r0, 5(r19)
/* 80075CB8  90 61 00 40 */	stw r3, 0x40(r1)
/* 80075CBC  38 61 00 40 */	addi r3, r1, 0x40
/* 80075CC0  88 93 00 06 */	lbz r4, 6(r19)
/* 80075CC4  50 04 44 2E */	rlwimi r4, r0, 8, 0x10, 0x17
/* 80075CC8  4B FD 86 79 */	bl -0x27988
/* 80075CCC  83 41 00 0C */	lwz r26, 0xc(r1)
/* 80075CD0  7C 7E 1B 78 */	mr r30, r3
/* 80075CD4  3B 00 00 01 */	li r24, 1
/* 80075CD8  3A E0 00 00 */	li r23, 0
/* 80075CDC  48 00 02 C0 */	b 0x2c0
/* 80075CE0  2C 0E 00 00 */	cmpwi r14, 0
/* 80075CE4  80 7A 00 00 */	lwz r3, 0(r26)
/* 80075CE8  38 80 00 07 */	li r4, 7
/* 80075CEC  41 82 00 08 */	beq 0x8
/* 80075CF0  38 80 00 06 */	li r4, 6
/* 80075CF4  81 83 00 00 */	lwz r12, 0(r3)
/* 80075CF8  38 A1 00 4C */	addi r5, r1, 0x4c
/* 80075CFC  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 80075D00  7D 89 03 A6 */	mtctr r12
/* 80075D04  4E 80 04 21 */	bctrl 
/* 80075D08  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 80075D0C  2C 00 00 00 */	cmpwi r0, 0
/* 80075D10  40 82 02 84 */	bne 0x284
/* 80075D14  2C 15 00 00 */	cmpwi r21, 0
/* 80075D18  3A C0 00 01 */	li r22, 1
/* 80075D1C  41 82 00 14 */	beq 0x14
/* 80075D20  80 15 00 00 */	lwz r0, 0(r21)
/* 80075D24  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 80075D28  41 82 00 08 */	beq 0x8
/* 80075D2C  62 D6 00 08 */	ori r22, r22, 8
/* 80075D30  81 FA 00 00 */	lwz r15, 0(r26)
/* 80075D34  3A 20 00 00 */	li r17, 0
/* 80075D38  2C 0F 00 00 */	cmpwi r15, 0
/* 80075D3C  41 82 00 2C */	beq 0x2c
/* 80075D40  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80075D44  7D E3 7B 78 */	mr r3, r15
/* 80075D48  38 81 00 14 */	addi r4, r1, 0x14
/* 80075D4C  81 8F 00 00 */	lwz r12, 0(r15)
/* 80075D50  81 8C 00 08 */	lwz r12, 8(r12)
/* 80075D54  7D 89 03 A6 */	mtctr r12
/* 80075D58  4E 80 04 21 */	bctrl 
/* 80075D5C  2C 03 00 00 */	cmpwi r3, 0
/* 80075D60  41 82 00 08 */	beq 0x8
/* 80075D64  3A 20 00 01 */	li r17, 1
/* 80075D68  2C 11 00 00 */	cmpwi r17, 0
/* 80075D6C  41 82 00 08 */	beq 0x8
/* 80075D70  48 00 00 08 */	b 0x8
/* 80075D74  39 E0 00 00 */	li r15, 0
/* 80075D78  2C 0F 00 00 */	cmpwi r15, 0
/* 80075D7C  41 82 00 F0 */	beq 0xf0
/* 80075D80  2C 1E 00 00 */	cmpwi r30, 0
/* 80075D84  7D E4 7B 78 */	mr r4, r15
/* 80075D88  38 61 00 50 */	addi r3, r1, 0x50
/* 80075D8C  41 82 00 0C */	beq 0xc
/* 80075D90  80 BE 00 0C */	lwz r5, 0xc(r30)
/* 80075D94  48 00 00 08 */	b 0x8
/* 80075D98  38 A0 00 00 */	li r5, 0
/* 80075D9C  4B FF D6 15 */	bl -0x29ec
/* 80075DA0  4B FF D5 91 */	bl -0x2a70
/* 80075DA4  2C 03 00 00 */	cmpwi r3, 0
/* 80075DA8  41 82 01 E8 */	beq 0x1e8
/* 80075DAC  7D E3 7B 78 */	mr r3, r15
/* 80075DB0  4B FF CC 31 */	bl -0x33d0
/* 80075DB4  7C 72 1B 78 */	mr r18, r3
/* 80075DB8  7D E3 7B 78 */	mr r3, r15
/* 80075DBC  4B FF CB E5 */	bl -0x341c
/* 80075DC0  7C 71 1B 78 */	mr r17, r3
/* 80075DC4  7D E3 7B 78 */	mr r3, r15
/* 80075DC8  4B FF CB A9 */	bl -0x3458
/* 80075DCC  7E 24 8B 78 */	mr r4, r17
/* 80075DD0  7E 45 93 78 */	mr r5, r18
/* 80075DD4  4B FE DD ED */	bl -0x12214
/* 80075DD8  2C 15 00 00 */	cmpwi r21, 0
/* 80075DDC  40 82 00 14 */	bne 0x14
/* 80075DE0  80 0F 01 18 */	lwz r0, 0x118(r15)
/* 80075DE4  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 80075DE8  41 82 00 08 */	beq 0x8
/* 80075DEC  62 D6 00 08 */	ori r22, r22, 8
/* 80075DF0  2C 1B 00 00 */	cmpwi r27, 0
/* 80075DF4  93 A1 00 2C */	stw r29, 0x2c(r1)
/* 80075DF8  38 00 00 00 */	li r0, 0
/* 80075DFC  93 C1 00 30 */	stw r30, 0x30(r1)
/* 80075E00  93 81 00 34 */	stw r28, 0x34(r1)
/* 80075E04  93 A1 00 38 */	stw r29, 0x38(r1)
/* 80075E08  40 82 00 14 */	bne 0x14
/* 80075E0C  2C 18 00 00 */	cmpwi r24, 0
/* 80075E10  41 82 00 0C */	beq 0xc
/* 80075E14  7C 1C C8 40 */	cmplw r28, r25
/* 80075E18  40 82 00 08 */	bne 0x8
/* 80075E1C  38 00 00 01 */	li r0, 1
/* 80075E20  2C 00 00 00 */	cmpwi r0, 0
/* 80075E24  41 82 00 0C */	beq 0xc
/* 80075E28  38 00 00 00 */	li r0, 0
/* 80075E2C  48 00 00 08 */	b 0x8
/* 80075E30  7F 80 E3 78 */	mr r0, r28
/* 80075E34  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80075E38  38 61 00 34 */	addi r3, r1, 0x34
/* 80075E3C  38 81 00 30 */	addi r4, r1, 0x30
/* 80075E40  38 A1 00 2C */	addi r5, r1, 0x2c
/* 80075E44  4B FF 24 0D */	bl -0xdbf4
/* 80075E48  7C 69 1B 78 */	mr r9, r3
/* 80075E4C  38 81 00 38 */	addi r4, r1, 0x38
/* 80075E50  7E C7 B3 78 */	mr r7, r22
/* 80075E54  38 61 00 3C */	addi r3, r1, 0x3c
/* 80075E58  38 A0 00 00 */	li r5, 0
/* 80075E5C  38 C0 00 00 */	li r6, 0
/* 80075E60  39 00 00 00 */	li r8, 0
/* 80075E64  4B FE F1 6D */	bl -0x10e94
/* 80075E68  48 00 01 28 */	b 0x128
/* 80075E6C  2C 1E 00 00 */	cmpwi r30, 0
/* 80075E70  41 82 00 10 */	beq 0x10
/* 80075E74  80 1E 00 14 */	lwz r0, 0x14(r30)
/* 80075E78  54 00 C7 FE */	rlwinm r0, r0, 0x18, 0x1f, 0x1f
/* 80075E7C  48 00 00 08 */	b 0x8
/* 80075E80  38 00 00 00 */	li r0, 0
/* 80075E84  2C 00 00 00 */	cmpwi r0, 0
/* 80075E88  41 82 01 08 */	beq 0x108
/* 80075E8C  81 FA 00 00 */	lwz r15, 0(r26)
/* 80075E90  3A 20 00 00 */	li r17, 0
/* 80075E94  2C 0F 00 00 */	cmpwi r15, 0
/* 80075E98  41 82 00 2C */	beq 0x2c
/* 80075E9C  92 01 00 10 */	stw r16, 0x10(r1)
/* 80075EA0  7D E3 7B 78 */	mr r3, r15
/* 80075EA4  38 81 00 10 */	addi r4, r1, 0x10
/* 80075EA8  81 8F 00 00 */	lwz r12, 0(r15)
/* 80075EAC  81 8C 00 08 */	lwz r12, 8(r12)
/* 80075EB0  7D 89 03 A6 */	mtctr r12
/* 80075EB4  4E 80 04 21 */	bctrl 
/* 80075EB8  2C 03 00 00 */	cmpwi r3, 0
/* 80075EBC  41 82 00 08 */	beq 0x8
/* 80075EC0  3A 20 00 01 */	li r17, 1
/* 80075EC4  2C 11 00 00 */	cmpwi r17, 0
/* 80075EC8  41 82 00 08 */	beq 0x8
/* 80075ECC  48 00 00 08 */	b 0x8
/* 80075ED0  39 E0 00 00 */	li r15, 0
/* 80075ED4  7D E3 7B 78 */	mr r3, r15
/* 80075ED8  4B FF CB 09 */	bl -0x34f8
/* 80075EDC  7C 71 1B 78 */	mr r17, r3
/* 80075EE0  7D E3 7B 78 */	mr r3, r15
/* 80075EE4  4B FF CA BD */	bl -0x3544
/* 80075EE8  7C 72 1B 78 */	mr r18, r3
/* 80075EEC  7D E3 7B 78 */	mr r3, r15
/* 80075EF0  4B FF CA 81 */	bl -0x3580
/* 80075EF4  7E 44 93 78 */	mr r4, r18
/* 80075EF8  7E 25 8B 78 */	mr r5, r17
/* 80075EFC  4B FE DC C5 */	bl -0x1233c
/* 80075F00  2C 15 00 00 */	cmpwi r21, 0
/* 80075F04  40 82 00 14 */	bne 0x14
/* 80075F08  80 0F 01 18 */	lwz r0, 0x118(r15)
/* 80075F0C  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 80075F10  41 82 00 08 */	beq 0x8
/* 80075F14  62 D6 00 08 */	ori r22, r22, 8
/* 80075F18  2C 1B 00 00 */	cmpwi r27, 0
/* 80075F1C  93 A1 00 18 */	stw r29, 0x18(r1)
/* 80075F20  38 00 00 00 */	li r0, 0
/* 80075F24  93 C1 00 1C */	stw r30, 0x1c(r1)
/* 80075F28  93 81 00 20 */	stw r28, 0x20(r1)
/* 80075F2C  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80075F30  40 82 00 14 */	bne 0x14
/* 80075F34  2C 18 00 00 */	cmpwi r24, 0
/* 80075F38  41 82 00 0C */	beq 0xc
/* 80075F3C  7C 1C C8 40 */	cmplw r28, r25
/* 80075F40  40 82 00 08 */	bne 0x8
/* 80075F44  38 00 00 01 */	li r0, 1
/* 80075F48  2C 00 00 00 */	cmpwi r0, 0
/* 80075F4C  41 82 00 0C */	beq 0xc
/* 80075F50  38 00 00 00 */	li r0, 0
/* 80075F54  48 00 00 08 */	b 0x8
/* 80075F58  7F 80 E3 78 */	mr r0, r28
/* 80075F5C  90 01 00 28 */	stw r0, 0x28(r1)
/* 80075F60  38 61 00 20 */	addi r3, r1, 0x20
/* 80075F64  38 81 00 1C */	addi r4, r1, 0x1c
/* 80075F68  38 A1 00 18 */	addi r5, r1, 0x18
/* 80075F6C  4B FF 22 E5 */	bl -0xdd1c
/* 80075F70  7C 69 1B 78 */	mr r9, r3
/* 80075F74  38 81 00 24 */	addi r4, r1, 0x24
/* 80075F78  7E C7 B3 78 */	mr r7, r22
/* 80075F7C  38 61 00 28 */	addi r3, r1, 0x28
/* 80075F80  38 A0 00 00 */	li r5, 0
/* 80075F84  38 C0 00 00 */	li r6, 0
/* 80075F88  39 00 00 00 */	li r8, 0
/* 80075F8C  4B FE F0 45 */	bl -0x10fbc
/* 80075F90  3B 00 00 00 */	li r24, 0
/* 80075F94  3B 5A 00 04 */	addi r26, r26, 4
/* 80075F98  3A F7 00 01 */	addi r23, r23, 1
/* 80075F9C  7C 17 A0 40 */	cmplw r23, r20
/* 80075FA0  41 80 FD 40 */	blt -0x2c0
/* 80075FA4  7F 99 E3 78 */	mr r25, r28
/* 80075FA8  3A 73 00 08 */	addi r19, r19, 8
/* 80075FAC  88 13 00 00 */	lbz r0, 0(r19)
/* 80075FB0  28 00 00 01 */	cmplwi r0, 1
/* 80075FB4  40 82 FC 8C */	bne -0x374
/* 80075FB8  39 61 00 B0 */	addi r11, r1, 0xb0
/* 80075FBC  4B FA B5 FD */	bl -0x54a04
/* 80075FC0  80 01 00 B4 */	lwz r0, 0xb4(r1)
/* 80075FC4  7C 08 03 A6 */	mtlr r0
/* 80075FC8  38 21 00 B0 */	addi r1, r1, 0xb0
/* 80075FCC  4E 80 00 20 */	blr 
/* 80075FD0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80075FD4  7C 08 02 A6 */	mflr r0
/* 80075FD8  90 01 00 24 */	stw r0, 0x24(r1)
/* 80075FDC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80075FE0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80075FE4  7C 9E 23 78 */	mr r30, r4
/* 80075FE8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80075FEC  7C 7D 1B 78 */	mr r29, r3
/* 80075FF0  7F C3 F3 78 */	mr r3, r30
/* 80075FF4  81 9E 00 00 */	lwz r12, 0(r30)
/* 80075FF8  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 80075FFC  7D 89 03 A6 */	mtctr r12
/* 80076000  4E 80 04 21 */	bctrl 
/* 80076004  81 9D 00 00 */	lwz r12, 0(r29)
/* 80076008  7C 7F 1B 78 */	mr r31, r3
/* 8007600C  7F A3 EB 78 */	mr r3, r29
/* 80076010  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 80076014  7D 89 03 A6 */	mtctr r12
/* 80076018  4E 80 04 21 */	bctrl 
/* 8007601C  7C 03 F8 40 */	cmplw r3, r31
/* 80076020  40 82 00 1C */	bne 0x1c
/* 80076024  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 80076028  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 8007602C  7C 03 00 40 */	cmplw r3, r0
/* 80076030  40 82 00 0C */	bne 0xc
/* 80076034  38 60 00 01 */	li r3, 1
/* 80076038  48 00 00 08 */	b 0x8
/* 8007603C  38 60 00 00 */	li r3, 0
/* 80076040  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80076044  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80076048  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8007604C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80076050  7C 08 03 A6 */	mtlr r0
/* 80076054  38 21 00 20 */	addi r1, r1, 0x20
/* 80076058  4E 80 00 20 */	blr 
/* 8007605C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076060  3C 60 53 47 */	lis r3, 0x5347
/* 80076064  38 63 45 58 */	addi r3, r3, 0x4558
/* 80076068  4E 80 00 20 */	blr 
/* 8007606C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076070  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80076074  7C 08 02 A6 */	mflr r0
/* 80076078  90 01 00 34 */	stw r0, 0x34(r1)
/* 8007607C  39 61 00 30 */	addi r11, r1, 0x30
/* 80076080  4B FA B5 15 */	bl -0x54aec
/* 80076084  54 A8 10 3A */	slwi r8, r5, 2
/* 80076088  54 C0 18 38 */	slwi r0, r6, 3
/* 8007608C  39 08 00 EF */	addi r8, r8, 0xef
/* 80076090  2C 04 00 00 */	cmpwi r4, 0
/* 80076094  55 1C 00 3A */	rlwinm r28, r8, 0, 0, 0x1d
/* 80076098  7C 7E 1B 78 */	mr r30, r3
/* 8007609C  7D 1C 02 14 */	add r8, r28, r0
/* 800760A0  7C BF 2B 78 */	mr r31, r5
/* 800760A4  38 08 00 03 */	addi r0, r8, 3
/* 800760A8  7C D8 33 78 */	mr r24, r6
/* 800760AC  54 1D 00 3A */	rlwinm r29, r0, 0, 0, 0x1d
/* 800760B0  7C F9 3B 78 */	mr r25, r7
/* 800760B4  38 1D 00 27 */	addi r0, r29, 0x27
/* 800760B8  54 DB 10 3A */	slwi r27, r6, 2
/* 800760BC  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 800760C0  3B 40 00 00 */	li r26, 0
/* 800760C4  41 82 00 08 */	beq 0x8
/* 800760C8  90 04 00 00 */	stw r0, 0(r4)
/* 800760CC  2C 03 00 00 */	cmpwi r3, 0
/* 800760D0  41 82 00 DC */	beq 0xdc
/* 800760D4  7F C3 F3 78 */	mr r3, r30
/* 800760D8  7C 04 03 78 */	mr r4, r0
/* 800760DC  48 12 3A BD */	bl 0x123abc
/* 800760E0  2C 03 00 00 */	cmpwi r3, 0
/* 800760E4  7C 7A 1B 78 */	mr r26, r3
/* 800760E8  40 82 00 0C */	bne 0xc
/* 800760EC  38 60 00 00 */	li r3, 0
/* 800760F0  48 00 00 C0 */	b 0xc0
/* 800760F4  7F A3 EA 15 */	add. r29, r3, r29
/* 800760F8  7C 83 E2 14 */	add r4, r3, r28
/* 800760FC  41 82 00 78 */	beq 0x78
/* 80076100  80 19 00 00 */	lwz r0, 0(r25)
/* 80076104  7F A3 EB 78 */	mr r3, r29
/* 80076108  90 01 00 08 */	stw r0, 8(r1)
/* 8007610C  7F 06 C3 78 */	mr r6, r24
/* 80076110  7C A4 DA 14 */	add r5, r4, r27
/* 80076114  4B FF AA DD */	bl -0x5524
/* 80076118  3C 60 80 27 */	lis r3, 0x8027
/* 8007611C  38 63 32 90 */	addi r3, r3, 0x3290
/* 80076120  90 7D 00 00 */	stw r3, 0(r29)
/* 80076124  80 01 00 08 */	lwz r0, 8(r1)
/* 80076128  90 1D 00 18 */	stw r0, 0x18(r29)
/* 8007612C  80 01 00 08 */	lwz r0, 8(r1)
/* 80076130  2C 00 00 00 */	cmpwi r0, 0
/* 80076134  41 82 00 14 */	beq 0x14
/* 80076138  38 61 00 08 */	addi r3, r1, 8
/* 8007613C  38 8D 81 68 */	addi r4, r13, -32408
/* 80076140  4B FD 81 11 */	bl -0x27ef0
/* 80076144  48 00 00 08 */	b 0x8
/* 80076148  38 60 00 00 */	li r3, 0
/* 8007614C  90 7D 00 1C */	stw r3, 0x1c(r29)
/* 80076150  80 01 00 08 */	lwz r0, 8(r1)
/* 80076154  2C 00 00 00 */	cmpwi r0, 0
/* 80076158  41 82 00 14 */	beq 0x14
/* 8007615C  38 61 00 08 */	addi r3, r1, 8
/* 80076160  38 8D 81 70 */	addi r4, r13, -32400
/* 80076164  4B FD 80 ED */	bl -0x27f14
/* 80076168  48 00 00 08 */	b 0x8
/* 8007616C  38 60 00 00 */	li r3, 0
/* 80076170  90 7D 00 20 */	stw r3, 0x20(r29)
/* 80076174  2C 1A 00 00 */	cmpwi r26, 0
/* 80076178  41 82 00 34 */	beq 0x34
/* 8007617C  7F 43 D3 78 */	mr r3, r26
/* 80076180  7F C4 F3 78 */	mr r4, r30
/* 80076184  7F E6 FB 78 */	mr r6, r31
/* 80076188  38 BA 00 EC */	addi r5, r26, 0xec
/* 8007618C  4B FF 8C B5 */	bl -0x734c
/* 80076190  3C 60 80 27 */	lis r3, 0x8027
/* 80076194  38 63 32 F8 */	addi r3, r3, 0x32f8
/* 80076198  90 7A 00 00 */	stw r3, 0(r26)
/* 8007619C  93 BA 00 E8 */	stw r29, 0xe8(r26)
/* 800761A0  80 1A 00 CC */	lwz r0, 0xcc(r26)
/* 800761A4  54 00 00 C0 */	rlwinm r0, r0, 0, 3, 0
/* 800761A8  90 1A 00 CC */	stw r0, 0xcc(r26)
/* 800761AC  7F 43 D3 78 */	mr r3, r26
/* 800761B0  39 61 00 30 */	addi r11, r1, 0x30
/* 800761B4  4B FA B4 2D */	bl -0x54bd4
/* 800761B8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800761BC  7C 08 03 A6 */	mtlr r0
/* 800761C0  38 21 00 30 */	addi r1, r1, 0x30
/* 800761C4  4E 80 00 20 */	blr 
/* 800761C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800761CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800761D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800761D4  7C 08 02 A6 */	mflr r0
/* 800761D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800761DC  80 04 00 00 */	lwz r0, 0(r4)
/* 800761E0  38 81 00 08 */	addi r4, r1, 8
/* 800761E4  90 01 00 08 */	stw r0, 8(r1)
/* 800761E8  80 63 00 E8 */	lwz r3, 0xe8(r3)
/* 800761EC  81 83 00 00 */	lwz r12, 0(r3)
/* 800761F0  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 800761F4  7D 89 03 A6 */	mtctr r12
/* 800761F8  4E 80 04 21 */	bctrl 
/* 800761FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80076200  7C 08 03 A6 */	mtlr r0
/* 80076204  38 21 00 10 */	addi r1, r1, 0x10
/* 80076208  4E 80 00 20 */	blr 
/* 8007620C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076210  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80076214  7C 08 02 A6 */	mflr r0
/* 80076218  2C 03 00 00 */	cmpwi r3, 0
/* 8007621C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80076220  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80076224  7C 7F 1B 78 */	mr r31, r3
/* 80076228  41 82 00 10 */	beq 0x10
/* 8007622C  2C 04 00 00 */	cmpwi r4, 0
/* 80076230  40 81 00 08 */	ble 0x8
/* 80076234  48 1B 3B E1 */	bl 0x1b3be0
/* 80076238  7F E3 FB 78 */	mr r3, r31
/* 8007623C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80076240  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80076244  7C 08 03 A6 */	mtlr r0
/* 80076248  38 21 00 10 */	addi r1, r1, 0x10
/* 8007624C  4E 80 00 20 */	blr 
/* 80076250  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80076254  7C 08 02 A6 */	mflr r0
/* 80076258  90 01 00 34 */	stw r0, 0x34(r1)
/* 8007625C  39 61 00 30 */	addi r11, r1, 0x30
/* 80076260  4B FA B3 3D */	bl -0x54cc4
/* 80076264  28 04 00 09 */	cmplwi r4, 9
/* 80076268  7C 7C 1B 78 */	mr r28, r3
/* 8007626C  7C 9D 23 78 */	mr r29, r4
/* 80076270  7C BE 2B 78 */	mr r30, r5
/* 80076274  7C DF 33 78 */	mr r31, r6
/* 80076278  40 80 00 24 */	bge 0x24
/* 8007627C  38 E4 FF FF */	addi r7, r4, -1
/* 80076280  39 00 00 01 */	li r8, 1
/* 80076284  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80076288  7D 07 38 30 */	slw r7, r8, r7
/* 8007628C  7C E0 00 39 */	and. r0, r7, r0
/* 80076290  41 82 00 0C */	beq 0xc
/* 80076294  38 00 00 01 */	li r0, 1
/* 80076298  48 00 00 08 */	b 0x8
/* 8007629C  38 00 00 00 */	li r0, 0
/* 800762A0  2C 00 00 00 */	cmpwi r0, 0
/* 800762A4  40 82 02 BC */	bne 0x2bc
/* 800762A8  28 04 00 05 */	cmplwi r4, 5
/* 800762AC  41 82 00 24 */	beq 0x24
/* 800762B0  3C 04 FF FF */	addis r0, r4, 0xffff
/* 800762B4  28 00 00 04 */	cmplwi r0, 4
/* 800762B8  41 82 00 C0 */	beq 0xc0
/* 800762BC  28 04 00 06 */	cmplwi r4, 6
/* 800762C0  41 82 01 3C */	beq 0x13c
/* 800762C4  28 04 00 07 */	cmplwi r4, 7
/* 800762C8  41 82 01 DC */	beq 0x1dc
/* 800762CC  48 00 02 80 */	b 0x280
/* 800762D0  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 800762D4  7F E3 FB 78 */	mr r3, r31
/* 800762D8  81 9F 00 00 */	lwz r12, 0(r31)
/* 800762DC  7F 84 E3 78 */	mr r4, r28
/* 800762E0  54 05 00 84 */	rlwinm r5, r0, 0, 2, 2
/* 800762E4  54 00 00 42 */	rlwinm r0, r0, 0, 1, 1
/* 800762E8  7C A5 00 34 */	cntlzw r5, r5
/* 800762EC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 800762F0  7C 00 00 34 */	cntlzw r0, r0
/* 800762F4  54 A5 D9 7E */	srwi r5, r5, 5
/* 800762F8  54 06 D9 7E */	srwi r6, r0, 5
/* 800762FC  7D 89 03 A6 */	mtctr r12
/* 80076300  4E 80 04 21 */	bctrl 
/* 80076304  80 7C 00 E8 */	lwz r3, 0xe8(r28)
/* 80076308  81 83 00 00 */	lwz r12, 0(r3)
/* 8007630C  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80076310  7D 89 03 A6 */	mtctr r12
/* 80076314  4E 80 04 21 */	bctrl 
/* 80076318  80 1C 00 E8 */	lwz r0, 0xe8(r28)
/* 8007631C  3C 60 80 27 */	lis r3, 0x8027
/* 80076320  38 63 32 CC */	addi r3, r3, 0x32cc
/* 80076324  90 01 00 10 */	stw r0, 0x10(r1)
/* 80076328  3B 40 00 00 */	li r26, 0
/* 8007632C  3B 60 00 00 */	li r27, 0
/* 80076330  90 61 00 08 */	stw r3, 8(r1)
/* 80076334  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80076338  48 00 00 30 */	b 0x30
/* 8007633C  80 7C 00 DC */	lwz r3, 0xdc(r28)
/* 80076340  7F A4 EB 78 */	mr r4, r29
/* 80076344  7F C5 F3 78 */	mr r5, r30
/* 80076348  38 C1 00 08 */	addi r6, r1, 8
/* 8007634C  7C 63 D8 2E */	lwzx r3, r3, r27
/* 80076350  81 83 00 00 */	lwz r12, 0(r3)
/* 80076354  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80076358  7D 89 03 A6 */	mtctr r12
/* 8007635C  4E 80 04 21 */	bctrl 
/* 80076360  3B 7B 00 04 */	addi r27, r27, 4
/* 80076364  3B 5A 00 01 */	addi r26, r26, 1
/* 80076368  80 1C 00 E4 */	lwz r0, 0xe4(r28)
/* 8007636C  7C 1A 00 40 */	cmplw r26, r0
/* 80076370  41 80 FF CC */	blt -0x34
/* 80076374  48 00 01 EC */	b 0x1ec
/* 80076378  2C 05 00 00 */	cmpwi r5, 0
/* 8007637C  41 82 00 18 */	beq 0x18
/* 80076380  28 05 00 01 */	cmplwi r5, 1
/* 80076384  41 82 00 28 */	beq 0x28
/* 80076388  28 05 00 02 */	cmplwi r5, 2
/* 8007638C  41 82 00 38 */	beq 0x38
/* 80076390  48 00 00 54 */	b 0x54
/* 80076394  80 63 00 E8 */	lwz r3, 0xe8(r3)
/* 80076398  81 83 00 00 */	lwz r12, 0(r3)
/* 8007639C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 800763A0  7D 89 03 A6 */	mtctr r12
/* 800763A4  4E 80 04 21 */	bctrl 
/* 800763A8  48 00 00 3C */	b 0x3c
/* 800763AC  80 63 00 E8 */	lwz r3, 0xe8(r3)
/* 800763B0  81 83 00 00 */	lwz r12, 0(r3)
/* 800763B4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 800763B8  7D 89 03 A6 */	mtctr r12
/* 800763BC  4E 80 04 21 */	bctrl 
/* 800763C0  48 00 00 24 */	b 0x24
/* 800763C4  80 63 00 E8 */	lwz r3, 0xe8(r3)
/* 800763C8  80 A6 00 04 */	lwz r5, 4(r6)
/* 800763CC  81 83 00 00 */	lwz r12, 0(r3)
/* 800763D0  80 85 00 00 */	lwz r4, 0(r5)
/* 800763D4  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 800763D8  80 A5 00 04 */	lwz r5, 4(r5)
/* 800763DC  7D 89 03 A6 */	mtctr r12
/* 800763E0  4E 80 04 21 */	bctrl 
/* 800763E4  7F 83 E3 78 */	mr r3, r28
/* 800763E8  7F A4 EB 78 */	mr r4, r29
/* 800763EC  7F C5 F3 78 */	mr r5, r30
/* 800763F0  7F E6 FB 78 */	mr r6, r31
/* 800763F4  4B FF 82 FD */	bl -0x7d04
/* 800763F8  48 00 01 68 */	b 0x168
/* 800763FC  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 80076400  2C 04 00 00 */	cmpwi r4, 0
/* 80076404  41 82 00 40 */	beq 0x40
/* 80076408  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 8007640C  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 80076410  41 82 00 34 */	beq 0x34
/* 80076414  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80076418  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8007641C  41 82 00 28 */	beq 0x28
/* 80076420  81 84 00 00 */	lwz r12, 0(r4)
/* 80076424  7C 83 23 78 */	mr r3, r4
/* 80076428  7F 85 E3 78 */	mr r5, r28
/* 8007642C  7F C6 F3 78 */	mr r6, r30
/* 80076430  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80076434  7F E7 FB 78 */	mr r7, r31
/* 80076438  38 80 00 01 */	li r4, 1
/* 8007643C  7D 89 03 A6 */	mtctr r12
/* 80076440  4E 80 04 21 */	bctrl 
/* 80076444  80 7C 00 E8 */	lwz r3, 0xe8(r28)
/* 80076448  7F E4 FB 78 */	mr r4, r31
/* 8007644C  81 83 00 00 */	lwz r12, 0(r3)
/* 80076450  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 80076454  7D 89 03 A6 */	mtctr r12
/* 80076458  4E 80 04 21 */	bctrl 
/* 8007645C  80 7C 00 D4 */	lwz r3, 0xd4(r28)
/* 80076460  2C 03 00 00 */	cmpwi r3, 0
/* 80076464  41 82 00 FC */	beq 0xfc
/* 80076468  A0 1C 00 DA */	lhz r0, 0xda(r28)
/* 8007646C  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 80076470  41 82 00 F0 */	beq 0xf0
/* 80076474  88 1C 00 D8 */	lbz r0, 0xd8(r28)
/* 80076478  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8007647C  41 82 00 E4 */	beq 0xe4
/* 80076480  81 83 00 00 */	lwz r12, 0(r3)
/* 80076484  7F 85 E3 78 */	mr r5, r28
/* 80076488  7F C6 F3 78 */	mr r6, r30
/* 8007648C  7F E7 FB 78 */	mr r7, r31
/* 80076490  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80076494  38 80 00 04 */	li r4, 4
/* 80076498  7D 89 03 A6 */	mtctr r12
/* 8007649C  4E 80 04 21 */	bctrl 
/* 800764A0  48 00 00 C0 */	b 0xc0
/* 800764A4  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 800764A8  2C 04 00 00 */	cmpwi r4, 0
/* 800764AC  41 82 00 40 */	beq 0x40
/* 800764B0  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 800764B4  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 800764B8  41 82 00 34 */	beq 0x34
/* 800764BC  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 800764C0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 800764C4  41 82 00 28 */	beq 0x28
/* 800764C8  81 84 00 00 */	lwz r12, 0(r4)
/* 800764CC  7C 83 23 78 */	mr r3, r4
/* 800764D0  7F 85 E3 78 */	mr r5, r28
/* 800764D4  7F C6 F3 78 */	mr r6, r30
/* 800764D8  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 800764DC  7F E7 FB 78 */	mr r7, r31
/* 800764E0  38 80 00 01 */	li r4, 1
/* 800764E4  7D 89 03 A6 */	mtctr r12
/* 800764E8  4E 80 04 21 */	bctrl 
/* 800764EC  80 7C 00 E8 */	lwz r3, 0xe8(r28)
/* 800764F0  7F E4 FB 78 */	mr r4, r31
/* 800764F4  81 83 00 00 */	lwz r12, 0(r3)
/* 800764F8  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 800764FC  7D 89 03 A6 */	mtctr r12
/* 80076500  4E 80 04 21 */	bctrl 
/* 80076504  80 7C 00 D4 */	lwz r3, 0xd4(r28)
/* 80076508  2C 03 00 00 */	cmpwi r3, 0
/* 8007650C  41 82 00 54 */	beq 0x54
/* 80076510  A0 1C 00 DA */	lhz r0, 0xda(r28)
/* 80076514  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80076518  41 82 00 48 */	beq 0x48
/* 8007651C  88 1C 00 D8 */	lbz r0, 0xd8(r28)
/* 80076520  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80076524  41 82 00 3C */	beq 0x3c
/* 80076528  81 83 00 00 */	lwz r12, 0(r3)
/* 8007652C  7F 85 E3 78 */	mr r5, r28
/* 80076530  7F C6 F3 78 */	mr r6, r30
/* 80076534  7F E7 FB 78 */	mr r7, r31
/* 80076538  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8007653C  38 80 00 04 */	li r4, 4
/* 80076540  7D 89 03 A6 */	mtctr r12
/* 80076544  4E 80 04 21 */	bctrl 
/* 80076548  48 00 00 18 */	b 0x18
/* 8007654C  7F 83 E3 78 */	mr r3, r28
/* 80076550  7F A4 EB 78 */	mr r4, r29
/* 80076554  7F C5 F3 78 */	mr r5, r30
/* 80076558  7F E6 FB 78 */	mr r6, r31
/* 8007655C  4B FF 81 95 */	bl -0x7e6c
/* 80076560  39 61 00 30 */	addi r11, r1, 0x30
/* 80076564  4B FA B0 85 */	bl -0x54f7c
/* 80076568  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8007656C  7C 08 03 A6 */	mtlr r0
/* 80076570  38 21 00 30 */	addi r1, r1, 0x30
/* 80076574  4E 80 00 20 */	blr 
/* 80076578  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007657C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076580  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80076584  7C 08 02 A6 */	mflr r0
/* 80076588  2C 03 00 00 */	cmpwi r3, 0
/* 8007658C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80076590  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80076594  7C 7F 1B 78 */	mr r31, r3
/* 80076598  41 82 00 0C */	beq 0xc
/* 8007659C  38 80 00 00 */	li r4, 0
/* 800765A0  4B FF 89 11 */	bl -0x76f0
/* 800765A4  7F E3 FB 78 */	mr r3, r31
/* 800765A8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800765AC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800765B0  7C 08 03 A6 */	mtlr r0
/* 800765B4  38 21 00 10 */	addi r1, r1, 0x10
/* 800765B8  4E 80 00 20 */	blr 
/* 800765BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800765C0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800765C4  7C 08 02 A6 */	mflr r0
/* 800765C8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800765CC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800765D0  7C 9F 23 78 */	mr r31, r4
/* 800765D4  93 C1 00 08 */	stw r30, 8(r1)
/* 800765D8  7C 7E 1B 78 */	mr r30, r3
/* 800765DC  80 A4 00 00 */	lwz r5, 0(r4)
/* 800765E0  80 03 00 18 */	lwz r0, 0x18(r3)
/* 800765E4  7C 05 00 40 */	cmplw r5, r0
/* 800765E8  41 82 00 64 */	beq 0x64
/* 800765EC  2C 05 00 00 */	cmpwi r5, 0
/* 800765F0  41 82 00 14 */	beq 0x14
/* 800765F4  7F E3 FB 78 */	mr r3, r31
/* 800765F8  38 8D 81 80 */	addi r4, r13, -32384
/* 800765FC  4B FD 7C 55 */	bl -0x283ac
/* 80076600  48 00 00 08 */	b 0x8
/* 80076604  38 60 00 00 */	li r3, 0
/* 80076608  90 7E 00 1C */	stw r3, 0x1c(r30)
/* 8007660C  80 1F 00 00 */	lwz r0, 0(r31)
/* 80076610  2C 00 00 00 */	cmpwi r0, 0
/* 80076614  41 82 00 14 */	beq 0x14
/* 80076618  7F E3 FB 78 */	mr r3, r31
/* 8007661C  38 8D 81 78 */	addi r4, r13, -32392
/* 80076620  4B FD 7C 31 */	bl -0x283d0
/* 80076624  48 00 00 08 */	b 0x8
/* 80076628  38 60 00 00 */	li r3, 0
/* 8007662C  90 7E 00 20 */	stw r3, 0x20(r30)
/* 80076630  7F C3 F3 78 */	mr r3, r30
/* 80076634  80 1F 00 00 */	lwz r0, 0(r31)
/* 80076638  90 1E 00 18 */	stw r0, 0x18(r30)
/* 8007663C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80076640  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80076644  7D 89 03 A6 */	mtctr r12
/* 80076648  4E 80 04 21 */	bctrl 
/* 8007664C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80076650  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80076654  83 C1 00 08 */	lwz r30, 8(r1)
/* 80076658  7C 08 03 A6 */	mtlr r0
/* 8007665C  38 21 00 10 */	addi r1, r1, 0x10
/* 80076660  4E 80 00 20 */	blr 
/* 80076664  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076668  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007666C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076670  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80076674  7C 08 02 A6 */	mflr r0
/* 80076678  2C 03 00 00 */	cmpwi r3, 0
/* 8007667C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80076680  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80076684  7C 7F 1B 78 */	mr r31, r3
/* 80076688  41 82 00 10 */	beq 0x10
/* 8007668C  2C 04 00 00 */	cmpwi r4, 0
/* 80076690  40 81 00 08 */	ble 0x8
/* 80076694  48 1B 37 81 */	bl 0x1b3780
/* 80076698  7F E3 FB 78 */	mr r3, r31
/* 8007669C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800766A0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800766A4  7C 08 03 A6 */	mtlr r0
/* 800766A8  38 21 00 10 */	addi r1, r1, 0x10
/* 800766AC  4E 80 00 20 */	blr 
/* 800766B0  4E 80 00 20 */	blr 
/* 800766B4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766B8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766C0  4E 80 00 20 */	blr 
/* 800766C4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766D0  4E 80 00 20 */	blr 
/* 800766D4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766D8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766E0  4E 80 00 20 */	blr 
/* 800766E4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766E8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766EC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766F0  4E 80 00 20 */	blr 
/* 800766F4  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766F8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800766FC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076700  4E 80 00 20 */	blr 
/* 80076704  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076708  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007670C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076710  3C 60 80 24 */	lis r3, 0x8024
/* 80076714  80 04 00 00 */	lwz r0, 0(r4)
/* 80076718  38 63 7F D8 */	addi r3, r3, 0x7fd8
/* 8007671C  7C 00 18 40 */	cmplw r0, r3
/* 80076720  40 82 00 0C */	bne 0xc
/* 80076724  38 60 00 01 */	li r3, 1
/* 80076728  4E 80 00 20 */	blr 
/* 8007672C  3C 60 80 24 */	lis r3, 0x8024
/* 80076730  80 04 00 00 */	lwz r0, 0(r4)
/* 80076734  38 63 7F 90 */	addi r3, r3, 0x7f90
/* 80076738  7C 00 18 40 */	cmplw r0, r3
/* 8007673C  40 82 00 0C */	bne 0xc
/* 80076740  38 60 00 01 */	li r3, 1
/* 80076744  4E 80 00 20 */	blr 
/* 80076748  3C 60 80 24 */	lis r3, 0x8024
/* 8007674C  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 80076750  7C 00 18 40 */	cmplw r0, r3
/* 80076754  40 82 00 0C */	bne 0xc
/* 80076758  38 60 00 01 */	li r3, 1
/* 8007675C  4E 80 00 20 */	blr 
/* 80076760  3C 60 80 24 */	lis r3, 0x8024
/* 80076764  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 80076768  7C 00 18 50 */	subf r0, r0, r3
/* 8007676C  7C 00 00 34 */	cntlzw r0, r0
/* 80076770  54 03 D9 7E */	srwi r3, r0, 5
/* 80076774  4E 80 00 20 */	blr 
/* 80076778  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007677C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076780  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80076784  7C 08 02 A6 */	mflr r0
/* 80076788  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007678C  81 83 00 00 */	lwz r12, 0(r3)
/* 80076790  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80076794  7D 89 03 A6 */	mtctr r12
/* 80076798  4E 80 04 21 */	bctrl 
/* 8007679C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800767A0  38 63 00 04 */	addi r3, r3, 4
/* 800767A4  7C 08 03 A6 */	mtlr r0
/* 800767A8  38 21 00 10 */	addi r1, r1, 0x10
/* 800767AC  4E 80 00 20 */	blr 
/* 800767B0  3C 60 80 24 */	lis r3, 0x8024
/* 800767B4  38 63 7F D8 */	addi r3, r3, 0x7fd8
/* 800767B8  4E 80 00 20 */	blr 
/* 800767BC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800767C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800767C4  7C 08 02 A6 */	mflr r0
/* 800767C8  90 01 00 24 */	stw r0, 0x24(r1)
/* 800767CC  39 61 00 20 */	addi r11, r1, 0x20
/* 800767D0  4B FA AD D1 */	bl -0x55230
/* 800767D4  80 06 00 00 */	lwz r0, 0(r6)
/* 800767D8  7C 7B 1B 78 */	mr r27, r3
/* 800767DC  7C BF 2B 78 */	mr r31, r5
/* 800767E0  7C DE 33 78 */	mr r30, r6
/* 800767E4  2C 00 00 00 */	cmpwi r0, 0
/* 800767E8  7C FC 3B 78 */	mr r28, r7
/* 800767EC  40 82 00 0C */	bne 0xc
/* 800767F0  38 60 00 00 */	li r3, 0
/* 800767F4  48 00 00 D0 */	b 0xd0
/* 800767F8  2C 04 00 00 */	cmpwi r4, 0
/* 800767FC  3B A0 00 00 */	li r29, 0
/* 80076800  41 82 00 0C */	beq 0xc
/* 80076804  38 00 00 F0 */	li r0, 0xf0
/* 80076808  90 04 00 00 */	stw r0, 0(r4)
/* 8007680C  2C 03 00 00 */	cmpwi r3, 0
/* 80076810  41 82 00 B0 */	beq 0xb0
/* 80076814  7F 63 DB 78 */	mr r3, r27
/* 80076818  38 80 00 F0 */	li r4, 0xf0
/* 8007681C  48 12 33 7D */	bl 0x12337c
/* 80076820  2C 03 00 00 */	cmpwi r3, 0
/* 80076824  7C 7D 1B 78 */	mr r29, r3
/* 80076828  40 82 00 0C */	bne 0xc
/* 8007682C  38 60 00 00 */	li r3, 0
/* 80076830  48 00 00 94 */	b 0x94
/* 80076834  41 82 00 8C */	beq 0x8c
/* 80076838  83 FF 00 00 */	lwz r31, 0(r31)
/* 8007683C  7F 64 DB 78 */	mr r4, r27
/* 80076840  83 DE 00 00 */	lwz r30, 0(r30)
/* 80076844  4B FF 6F 6D */	bl -0x9094
/* 80076848  3C 80 80 27 */	lis r4, 0x8027
/* 8007684C  3C 60 80 27 */	lis r3, 0x8027
/* 80076850  38 84 31 18 */	addi r4, r4, 0x3118
/* 80076854  90 9D 00 00 */	stw r4, 0(r29)
/* 80076858  C0 02 8D A8 */	lfs f0, -0x7258(r2)
/* 8007685C  38 63 33 38 */	addi r3, r3, 0x3338
/* 80076860  D0 1D 00 DC */	stfs f0, 0xdc(r29)
/* 80076864  2C 1C 00 00 */	cmpwi r28, 0
/* 80076868  D0 1D 00 E0 */	stfs f0, 0xe0(r29)
/* 8007686C  D0 1D 00 E4 */	stfs f0, 0xe4(r29)
/* 80076870  90 7D 00 00 */	stw r3, 0(r29)
/* 80076874  93 FD 00 E8 */	stw r31, 0xe8(r29)
/* 80076878  93 DD 00 EC */	stw r30, 0xec(r29)
/* 8007687C  40 82 00 14 */	bne 0x14
/* 80076880  80 1D 00 CC */	lwz r0, 0xcc(r29)
/* 80076884  64 00 20 00 */	oris r0, r0, 0x2000
/* 80076888  90 1D 00 CC */	stw r0, 0xcc(r29)
/* 8007688C  48 00 00 10 */	b 0x10
/* 80076890  80 1D 00 CC */	lwz r0, 0xcc(r29)
/* 80076894  54 00 00 C2 */	rlwinm r0, r0, 0, 3, 1
/* 80076898  90 1D 00 CC */	stw r0, 0xcc(r29)
/* 8007689C  2C 1C 00 00 */	cmpwi r28, 0
/* 800768A0  41 82 00 14 */	beq 0x14
/* 800768A4  80 1D 00 CC */	lwz r0, 0xcc(r29)
/* 800768A8  64 00 40 00 */	oris r0, r0, 0x4000
/* 800768AC  90 1D 00 CC */	stw r0, 0xcc(r29)
/* 800768B0  48 00 00 10 */	b 0x10
/* 800768B4  80 1D 00 CC */	lwz r0, 0xcc(r29)
/* 800768B8  54 00 00 80 */	rlwinm r0, r0, 0, 2, 0
/* 800768BC  90 1D 00 CC */	stw r0, 0xcc(r29)
/* 800768C0  7F A3 EB 78 */	mr r3, r29
/* 800768C4  39 61 00 20 */	addi r11, r1, 0x20
/* 800768C8  4B FA AD 25 */	bl -0x552dc
/* 800768CC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800768D0  7C 08 03 A6 */	mtlr r0
/* 800768D4  38 21 00 20 */	addi r1, r1, 0x20
/* 800768D8  4E 80 00 20 */	blr 
/* 800768DC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800768E0  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 800768E4  7C 08 02 A6 */	mflr r0
/* 800768E8  90 01 00 84 */	stw r0, 0x84(r1)
/* 800768EC  39 61 00 80 */	addi r11, r1, 0x80
/* 800768F0  4B FA AC A9 */	bl -0x55358
/* 800768F4  28 04 00 09 */	cmplwi r4, 9
/* 800768F8  7C 7D 1B 78 */	mr r29, r3
/* 800768FC  7C BE 2B 78 */	mr r30, r5
/* 80076900  7C DF 33 78 */	mr r31, r6
/* 80076904  40 80 00 24 */	bge 0x24
/* 80076908  38 A4 FF FF */	addi r5, r4, -1
/* 8007690C  38 C0 00 01 */	li r6, 1
/* 80076910  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80076914  7C C5 28 30 */	slw r5, r6, r5
/* 80076918  7C A0 00 39 */	and. r0, r5, r0
/* 8007691C  41 82 00 0C */	beq 0xc
/* 80076920  38 00 00 01 */	li r0, 1
/* 80076924  48 00 00 08 */	b 0x8
/* 80076928  38 00 00 00 */	li r0, 0
/* 8007692C  2C 00 00 00 */	cmpwi r0, 0
/* 80076930  40 82 02 88 */	bne 0x288
/* 80076934  28 04 00 05 */	cmplwi r4, 5
/* 80076938  41 82 00 18 */	beq 0x18
/* 8007693C  28 04 00 06 */	cmplwi r4, 6
/* 80076940  41 82 00 48 */	beq 0x48
/* 80076944  28 04 00 07 */	cmplwi r4, 7
/* 80076948  41 82 01 50 */	beq 0x150
/* 8007694C  48 00 02 5C */	b 0x25c
/* 80076950  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80076954  7F E3 FB 78 */	mr r3, r31
/* 80076958  81 9F 00 00 */	lwz r12, 0(r31)
/* 8007695C  7F A4 EB 78 */	mr r4, r29
/* 80076960  54 05 00 84 */	rlwinm r5, r0, 0, 2, 2
/* 80076964  54 00 00 42 */	rlwinm r0, r0, 0, 1, 1
/* 80076968  7C A5 00 34 */	cntlzw r5, r5
/* 8007696C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80076970  7C 00 00 34 */	cntlzw r0, r0
/* 80076974  54 A5 D9 7E */	srwi r5, r5, 5
/* 80076978  54 06 D9 7E */	srwi r6, r0, 5
/* 8007697C  7D 89 03 A6 */	mtctr r12
/* 80076980  4E 80 04 21 */	bctrl 
/* 80076984  48 00 02 34 */	b 0x234
/* 80076988  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 8007698C  2C 04 00 00 */	cmpwi r4, 0
/* 80076990  41 82 00 40 */	beq 0x40
/* 80076994  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80076998  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 8007699C  41 82 00 34 */	beq 0x34
/* 800769A0  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 800769A4  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 800769A8  41 82 00 28 */	beq 0x28
/* 800769AC  81 84 00 00 */	lwz r12, 0(r4)
/* 800769B0  7C 83 23 78 */	mr r3, r4
/* 800769B4  7F A5 EB 78 */	mr r5, r29
/* 800769B8  7F C6 F3 78 */	mr r6, r30
/* 800769BC  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 800769C0  7F E7 FB 78 */	mr r7, r31
/* 800769C4  38 80 00 01 */	li r4, 1
/* 800769C8  7D 89 03 A6 */	mtctr r12
/* 800769CC  4E 80 04 21 */	bctrl 
/* 800769D0  2C 1F 00 00 */	cmpwi r31, 0
/* 800769D4  41 82 00 0C */	beq 0xc
/* 800769D8  80 7F 00 00 */	lwz r3, 0(r31)
/* 800769DC  48 00 00 08 */	b 0x8
/* 800769E0  38 60 00 00 */	li r3, 0
/* 800769E4  54 60 07 7B */	rlwinm. r0, r3, 0, 0x1d, 0x1d
/* 800769E8  83 9D 00 E8 */	lwz r28, 0xe8(r29)
/* 800769EC  83 7D 00 EC */	lwz r27, 0xec(r29)
/* 800769F0  3B 20 00 01 */	li r25, 1
/* 800769F4  41 82 00 08 */	beq 0x8
/* 800769F8  3B 80 00 00 */	li r28, 0
/* 800769FC  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 80076A00  41 82 00 08 */	beq 0x8
/* 80076A04  63 39 00 08 */	ori r25, r25, 8
/* 80076A08  3B 5D 00 6C */	addi r26, r29, 0x6c
/* 80076A0C  38 61 00 3C */	addi r3, r1, 0x3c
/* 80076A10  7F 44 D3 78 */	mr r4, r26
/* 80076A14  48 00 EC 1D */	bl 0xec1c
/* 80076A18  7F 43 D3 78 */	mr r3, r26
/* 80076A1C  38 81 00 3C */	addi r4, r1, 0x3c
/* 80076A20  38 A0 00 00 */	li r5, 0
/* 80076A24  4B FE D1 9D */	bl -0x12e64
/* 80076A28  93 61 00 14 */	stw r27, 0x14(r1)
/* 80076A2C  7F 45 D3 78 */	mr r5, r26
/* 80076A30  7F 46 D3 78 */	mr r6, r26
/* 80076A34  7F 27 CB 78 */	mr r7, r25
/* 80076A38  93 81 00 10 */	stw r28, 0x10(r1)
/* 80076A3C  38 61 00 10 */	addi r3, r1, 0x10
/* 80076A40  38 81 00 14 */	addi r4, r1, 0x14
/* 80076A44  39 00 00 00 */	li r8, 0
/* 80076A48  39 20 00 00 */	li r9, 0
/* 80076A4C  4B FE E5 85 */	bl -0x11a7c
/* 80076A50  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80076A54  2C 03 00 00 */	cmpwi r3, 0
/* 80076A58  41 82 01 60 */	beq 0x160
/* 80076A5C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80076A60  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 80076A64  41 82 01 54 */	beq 0x154
/* 80076A68  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80076A6C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80076A70  41 82 01 48 */	beq 0x148
/* 80076A74  81 83 00 00 */	lwz r12, 0(r3)
/* 80076A78  7F A5 EB 78 */	mr r5, r29
/* 80076A7C  7F C6 F3 78 */	mr r6, r30
/* 80076A80  7F E7 FB 78 */	mr r7, r31
/* 80076A84  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 80076A88  38 80 00 04 */	li r4, 4
/* 80076A8C  7D 89 03 A6 */	mtctr r12
/* 80076A90  4E 80 04 21 */	bctrl 
/* 80076A94  48 00 01 24 */	b 0x124
/* 80076A98  80 83 00 D4 */	lwz r4, 0xd4(r3)
/* 80076A9C  2C 04 00 00 */	cmpwi r4, 0
/* 80076AA0  41 82 00 40 */	beq 0x40
/* 80076AA4  A0 03 00 DA */	lhz r0, 0xda(r3)
/* 80076AA8  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80076AAC  41 82 00 34 */	beq 0x34
/* 80076AB0  88 03 00 D8 */	lbz r0, 0xd8(r3)
/* 80076AB4  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80076AB8  41 82 00 28 */	beq 0x28
/* 80076ABC  81 84 00 00 */	lwz r12, 0(r4)
/* 80076AC0  7C 83 23 78 */	mr r3, r4
/* 80076AC4  7F A5 EB 78 */	mr r5, r29
/* 80076AC8  7F C6 F3 78 */	mr r6, r30
/* 80076ACC  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80076AD0  7F E7 FB 78 */	mr r7, r31
/* 80076AD4  38 80 00 01 */	li r4, 1
/* 80076AD8  7D 89 03 A6 */	mtctr r12
/* 80076ADC  4E 80 04 21 */	bctrl 
/* 80076AE0  2C 1F 00 00 */	cmpwi r31, 0
/* 80076AE4  41 82 00 0C */	beq 0xc
/* 80076AE8  80 7F 00 00 */	lwz r3, 0(r31)
/* 80076AEC  48 00 00 08 */	b 0x8
/* 80076AF0  38 60 00 00 */	li r3, 0
/* 80076AF4  54 60 07 7B */	rlwinm. r0, r3, 0, 0x1d, 0x1d
/* 80076AF8  83 7D 00 E8 */	lwz r27, 0xe8(r29)
/* 80076AFC  83 9D 00 EC */	lwz r28, 0xec(r29)
/* 80076B00  3B 40 00 01 */	li r26, 1
/* 80076B04  41 82 00 08 */	beq 0x8
/* 80076B08  3B 60 00 00 */	li r27, 0
/* 80076B0C  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 80076B10  41 82 00 08 */	beq 0x8
/* 80076B14  63 5A 00 08 */	ori r26, r26, 8
/* 80076B18  3B 3D 00 6C */	addi r25, r29, 0x6c
/* 80076B1C  38 61 00 18 */	addi r3, r1, 0x18
/* 80076B20  7F 24 CB 78 */	mr r4, r25
/* 80076B24  48 00 EB 0D */	bl 0xeb0c
/* 80076B28  7F 23 CB 78 */	mr r3, r25
/* 80076B2C  38 81 00 18 */	addi r4, r1, 0x18
/* 80076B30  38 A0 00 00 */	li r5, 0
/* 80076B34  4B FE D0 8D */	bl -0x12f74
/* 80076B38  93 81 00 0C */	stw r28, 0xc(r1)
/* 80076B3C  7F 25 CB 78 */	mr r5, r25
/* 80076B40  7F 26 CB 78 */	mr r6, r25
/* 80076B44  7F 47 D3 78 */	mr r7, r26
/* 80076B48  93 61 00 08 */	stw r27, 8(r1)
/* 80076B4C  38 61 00 08 */	addi r3, r1, 8
/* 80076B50  38 81 00 0C */	addi r4, r1, 0xc
/* 80076B54  39 00 00 00 */	li r8, 0
/* 80076B58  39 20 00 00 */	li r9, 0
/* 80076B5C  4B FE E4 75 */	bl -0x11b8c
/* 80076B60  80 7D 00 D4 */	lwz r3, 0xd4(r29)
/* 80076B64  2C 03 00 00 */	cmpwi r3, 0
/* 80076B68  41 82 00 50 */	beq 0x50
/* 80076B6C  A0 1D 00 DA */	lhz r0, 0xda(r29)
/* 80076B70  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80076B74  41 82 00 44 */	beq 0x44
/* 80076B78  88 1D 00 D8 */	lbz r0, 0xd8(r29)
/* 80076B7C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80076B80  41 82 00 38 */	beq 0x38
/* 80076B84  81 83 00 00 */	lwz r12, 0(r3)
/* 80076B88  7F A5 EB 78 */	mr r5, r29
/* 80076B8C  7F C6 F3 78 */	mr r6, r30
/* 80076B90  7F E7 FB 78 */	mr r7, r31
/* 80076B94  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 80076B98  38 80 00 04 */	li r4, 4
/* 80076B9C  7D 89 03 A6 */	mtctr r12
/* 80076BA0  4E 80 04 21 */	bctrl 
/* 80076BA4  48 00 00 14 */	b 0x14
/* 80076BA8  7F A3 EB 78 */	mr r3, r29
/* 80076BAC  7F C5 F3 78 */	mr r5, r30
/* 80076BB0  7F E6 FB 78 */	mr r6, r31
/* 80076BB4  4B FF 74 FD */	bl -0x8b04
/* 80076BB8  39 61 00 80 */	addi r11, r1, 0x80
/* 80076BBC  4B FA AA 29 */	bl -0x555d8
/* 80076BC0  80 01 00 84 */	lwz r0, 0x84(r1)
/* 80076BC4  7C 08 03 A6 */	mtlr r0
/* 80076BC8  38 21 00 80 */	addi r1, r1, 0x80
/* 80076BCC  4E 80 00 20 */	blr 
/* 80076BD0  3C 60 80 24 */	lis r3, 0x8024
/* 80076BD4  80 04 00 00 */	lwz r0, 0(r4)
/* 80076BD8  38 63 7F E8 */	addi r3, r3, 0x7fe8
/* 80076BDC  7C 00 18 40 */	cmplw r0, r3
/* 80076BE0  40 82 00 0C */	bne 0xc
/* 80076BE4  38 60 00 01 */	li r3, 1
/* 80076BE8  4E 80 00 20 */	blr 
/* 80076BEC  3C 60 80 24 */	lis r3, 0x8024
/* 80076BF0  80 04 00 00 */	lwz r0, 0(r4)
/* 80076BF4  38 63 7F 80 */	addi r3, r3, 0x7f80
/* 80076BF8  7C 00 18 40 */	cmplw r0, r3
/* 80076BFC  40 82 00 0C */	bne 0xc
/* 80076C00  38 60 00 01 */	li r3, 1
/* 80076C04  4E 80 00 20 */	blr 
/* 80076C08  3C 60 80 24 */	lis r3, 0x8024
/* 80076C0C  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 80076C10  7C 00 18 40 */	cmplw r0, r3
/* 80076C14  40 82 00 0C */	bne 0xc
/* 80076C18  38 60 00 01 */	li r3, 1
/* 80076C1C  4E 80 00 20 */	blr 
/* 80076C20  3C 60 80 24 */	lis r3, 0x8024
/* 80076C24  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 80076C28  7C 00 18 50 */	subf r0, r0, r3
/* 80076C2C  7C 00 00 34 */	cntlzw r0, r0
/* 80076C30  54 03 D9 7E */	srwi r3, r0, 5
/* 80076C34  4E 80 00 20 */	blr 
/* 80076C38  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076C3C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076C40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80076C44  7C 08 02 A6 */	mflr r0
/* 80076C48  90 01 00 14 */	stw r0, 0x14(r1)
/* 80076C4C  81 83 00 00 */	lwz r12, 0(r3)
/* 80076C50  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80076C54  7D 89 03 A6 */	mtctr r12
/* 80076C58  4E 80 04 21 */	bctrl 
/* 80076C5C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80076C60  38 63 00 04 */	addi r3, r3, 4
/* 80076C64  7C 08 03 A6 */	mtlr r0
/* 80076C68  38 21 00 10 */	addi r1, r1, 0x10
/* 80076C6C  4E 80 00 20 */	blr 
/* 80076C70  3C 60 80 24 */	lis r3, 0x8024
/* 80076C74  38 63 7F E8 */	addi r3, r3, 0x7fe8
/* 80076C78  4E 80 00 20 */	blr 
/* 80076C7C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80076C80  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80076C84  7C 08 02 A6 */	mflr r0
/* 80076C88  2C 03 00 00 */	cmpwi r3, 0
/* 80076C8C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80076C90  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80076C94  7C 7F 1B 78 */	mr r31, r3
/* 80076C98  41 82 00 10 */	beq 0x10
/* 80076C9C  41 82 00 0C */	beq 0xc
/* 80076CA0  38 80 00 00 */	li r4, 0
/* 80076CA4  4B FF 6B FD */	bl -0x9404
/* 80076CA8  7F E3 FB 78 */	mr r3, r31
/* 80076CAC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80076CB0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80076CB4  7C 08 03 A6 */	mtlr r0
/* 80076CB8  38 21 00 10 */	addi r1, r1, 0x10
/* 80076CBC  4E 80 00 20 */	blr 
/* 80076CC0  94 21 FD F0 */	stwu r1, -0x210(r1)
/* 80076CC4  7C 08 02 A6 */	mflr r0
/* 80076CC8  90 01 02 14 */	stw r0, 0x214(r1)
/* 80076CCC  39 61 02 10 */	addi r11, r1, 0x210
/* 80076CD0  4B FA A8 9D */	bl -0x55764
/* 80076CD4  7C 6F 1B 78 */	mr r15, r3
/* 80076CD8  7C 90 23 78 */	mr r16, r4
/* 80076CDC  7C B1 2B 78 */	mr r17, r5
/* 80076CE0  7C D2 33 78 */	mr r18, r6
/* 80076CE4  4B FD 7D 6D */	bl -0x28294
/* 80076CE8  3B 61 00 A8 */	addi r27, r1, 0xa8
/* 80076CEC  38 01 00 8C */	addi r0, r1, 0x8c
/* 80076CF0  7C 80 D8 50 */	subf r4, r0, r27
/* 80076CF4  3B 81 00 C8 */	addi r28, r1, 0xc8
/* 80076CF8  38 01 00 AC */	addi r0, r1, 0xac
/* 80076CFC  90 61 01 B8 */	stw r3, 0x1b8(r1)
/* 80076D00  7C C0 E0 50 */	subf r6, r0, r28
/* 80076D04  38 A4 00 03 */	addi r5, r4, 3
/* 80076D08  54 80 00 00 */	rlwinm r0, r4, 0, 0, 0
/* 80076D0C  90 01 01 B4 */	stw r0, 0x1b4(r1)
/* 80076D10  7C A3 16 70 */	srawi r3, r5, 2
/* 80076D14  38 E6 00 03 */	addi r7, r6, 3
/* 80076D18  7C 83 01 94 */	addze r4, r3
/* 80076D1C  54 A0 00 00 */	rlwinm r0, r5, 0, 0, 0
/* 80076D20  7C E3 16 70 */	srawi r3, r7, 2
/* 80076D24  90 01 01 B0 */	stw r0, 0x1b0(r1)
/* 80076D28  7C 63 01 94 */	addze r3, r3
/* 80076D2C  3B 44 00 01 */	addi r26, r4, 1
/* 80076D30  3B 03 00 01 */	addi r24, r3, 1
/* 80076D34  54 99 00 00 */	rlwinm r25, r4, 0, 0, 0
/* 80076D38  57 4E 00 00 */	rlwinm r14, r26, 0, 0, 0
/* 80076D3C  54 D7 00 00 */	rlwinm r23, r6, 0, 0, 0
/* 80076D40  54 F6 00 00 */	rlwinm r22, r7, 0, 0, 0
/* 80076D44  54 75 00 00 */	rlwinm r21, r3, 0, 0, 0
/* 80076D48  57 14 00 00 */	rlwinm r20, r24, 0, 0, 0
/* 80076D4C  3A 60 00 00 */	li r19, 0
/* 80076D50  3B A0 00 00 */	li r29, 0
/* 80076D54  48 00 03 58 */	b 0x358
/* 80076D58  7D E3 7B 78 */	mr r3, r15
/* 80076D5C  7E 64 9B 78 */	mr r4, r19
/* 80076D60  4B FD 7C 91 */	bl -0x28370
/* 80076D64  2C 10 00 00 */	cmpwi r16, 0
/* 80076D68  7C 7F 1B 78 */	mr r31, r3
/* 80076D6C  41 82 02 34 */	beq 0x234
/* 80076D70  7E 03 83 78 */	mr r3, r16
/* 80076D74  7E 64 9B 78 */	mr r4, r19
/* 80076D78  4B FE 1B 99 */	bl -0x1e468
/* 80076D7C  2C 03 00 00 */	cmpwi r3, 0
/* 80076D80  41 82 02 20 */	beq 0x220
/* 80076D84  38 81 00 8C */	addi r4, r1, 0x8c
/* 80076D88  93 A1 00 88 */	stw r29, 0x88(r1)
/* 80076D8C  7C 04 D8 40 */	cmplw r4, r27
/* 80076D90  40 80 00 EC */	bge 0xec
/* 80076D94  2C 1A 00 08 */	cmpwi r26, 8
/* 80076D98  40 81 00 C0 */	ble 0xc0
/* 80076D9C  7C 80 23 78 */	mr r0, r4
/* 80076DA0  38 60 00 00 */	li r3, 0
/* 80076DA4  7C 00 D8 40 */	cmplw r0, r27
/* 80076DA8  38 A0 00 00 */	li r5, 0
/* 80076DAC  41 81 00 30 */	bgt 0x30
/* 80076DB0  80 01 01 B4 */	lwz r0, 0x1b4(r1)
/* 80076DB4  38 C0 00 01 */	li r6, 1
/* 80076DB8  2C 00 00 00 */	cmpwi r0, 0
/* 80076DBC  40 82 00 14 */	bne 0x14
/* 80076DC0  80 01 01 B0 */	lwz r0, 0x1b0(r1)
/* 80076DC4  2C 00 00 00 */	cmpwi r0, 0
/* 80076DC8  41 82 00 08 */	beq 0x8
/* 80076DCC  38 C0 00 00 */	li r6, 0
/* 80076DD0  2C 06 00 00 */	cmpwi r6, 0
/* 80076DD4  41 82 00 08 */	beq 0x8
/* 80076DD8  38 A0 00 01 */	li r5, 1
/* 80076DDC  2C 05 00 00 */	cmpwi r5, 0
/* 80076DE0  41 82 00 28 */	beq 0x28
/* 80076DE4  2C 19 00 00 */	cmpwi r25, 0
/* 80076DE8  38 00 00 01 */	li r0, 1
/* 80076DEC  40 82 00 10 */	bne 0x10
/* 80076DF0  7C 19 70 00 */	cmpw r25, r14
/* 80076DF4  41 82 00 08 */	beq 0x8
/* 80076DF8  38 00 00 00 */	li r0, 0
/* 80076DFC  2C 00 00 00 */	cmpwi r0, 0
/* 80076E00  41 82 00 08 */	beq 0x8
/* 80076E04  38 60 00 01 */	li r3, 1
/* 80076E08  2C 03 00 00 */	cmpwi r3, 0
/* 80076E0C  41 82 00 4C */	beq 0x4c
/* 80076E10  38 61 00 88 */	addi r3, r1, 0x88
/* 80076E14  38 03 00 1F */	addi r0, r3, 0x1f
/* 80076E18  7C 04 00 50 */	subf r0, r4, r0
/* 80076E1C  54 00 D9 7E */	srwi r0, r0, 5
/* 80076E20  7C 09 03 A6 */	mtctr r0
/* 80076E24  7C 60 1B 78 */	mr r0, r3
/* 80076E28  7C 04 00 40 */	cmplw r4, r0
/* 80076E2C  40 80 00 2C */	bge 0x2c
/* 80076E30  93 A4 00 00 */	stw r29, 0(r4)
/* 80076E34  93 A4 00 04 */	stw r29, 4(r4)
/* 80076E38  93 A4 00 08 */	stw r29, 8(r4)
/* 80076E3C  93 A4 00 0C */	stw r29, 0xc(r4)
/* 80076E40  93 A4 00 10 */	stw r29, 0x10(r4)
/* 80076E44  93 A4 00 14 */	stw r29, 0x14(r4)
/* 80076E48  93 A4 00 18 */	stw r29, 0x18(r4)
/* 80076E4C  93 A4 00 1C */	stw r29, 0x1c(r4)
/* 80076E50  38 84 00 20 */	addi r4, r4, 0x20
/* 80076E54  42 00 FF DC */	bdnz -0x24
/* 80076E58  38 1B 00 03 */	addi r0, r27, 3
/* 80076E5C  7C 04 00 50 */	subf r0, r4, r0
/* 80076E60  54 00 F0 BE */	srwi r0, r0, 2
/* 80076E64  7C 09 03 A6 */	mtctr r0
/* 80076E68  7C 04 D8 40 */	cmplw r4, r27
/* 80076E6C  40 80 00 10 */	bge 0x10
/* 80076E70  93 A4 00 00 */	stw r29, 0(r4)
/* 80076E74  38 84 00 04 */	addi r4, r4, 4
/* 80076E78  42 00 FF F8 */	bdnz -0x8
/* 80076E7C  38 61 00 AC */	addi r3, r1, 0xac
/* 80076E80  93 A1 00 A8 */	stw r29, 0xa8(r1)
/* 80076E84  7C 03 E0 40 */	cmplw r3, r28
/* 80076E88  40 80 00 DC */	bge 0xdc
/* 80076E8C  2C 18 00 08 */	cmpwi r24, 8
/* 80076E90  40 81 00 B0 */	ble 0xb0
/* 80076E94  7C 60 1B 78 */	mr r0, r3
/* 80076E98  38 80 00 00 */	li r4, 0
/* 80076E9C  7C 00 E0 40 */	cmplw r0, r28
/* 80076EA0  38 00 00 00 */	li r0, 0
/* 80076EA4  41 81 00 28 */	bgt 0x28
/* 80076EA8  2C 17 00 00 */	cmpwi r23, 0
/* 80076EAC  38 A0 00 01 */	li r5, 1
/* 80076EB0  40 82 00 10 */	bne 0x10
/* 80076EB4  2C 16 00 00 */	cmpwi r22, 0
/* 80076EB8  41 82 00 08 */	beq 0x8
/* 80076EBC  38 A0 00 00 */	li r5, 0
/* 80076EC0  2C 05 00 00 */	cmpwi r5, 0
/* 80076EC4  41 82 00 08 */	beq 0x8
/* 80076EC8  38 80 00 01 */	li r4, 1
/* 80076ECC  2C 04 00 00 */	cmpwi r4, 0
/* 80076ED0  41 82 00 28 */	beq 0x28
/* 80076ED4  2C 15 00 00 */	cmpwi r21, 0
/* 80076ED8  38 80 00 01 */	li r4, 1
/* 80076EDC  40 82 00 10 */	bne 0x10
/* 80076EE0  7C 15 A0 00 */	cmpw r21, r20
/* 80076EE4  41 82 00 08 */	beq 0x8
/* 80076EE8  38 80 00 00 */	li r4, 0
/* 80076EEC  2C 04 00 00 */	cmpwi r4, 0
/* 80076EF0  41 82 00 08 */	beq 0x8
/* 80076EF4  38 00 00 01 */	li r0, 1
/* 80076EF8  2C 00 00 00 */	cmpwi r0, 0
/* 80076EFC  41 82 00 44 */	beq 0x44
/* 80076F00  38 1B 00 1F */	addi r0, r27, 0x1f
/* 80076F04  7C 03 00 50 */	subf r0, r3, r0
/* 80076F08  54 00 D9 7E */	srwi r0, r0, 5
/* 80076F0C  7C 09 03 A6 */	mtctr r0
/* 80076F10  7C 03 D8 40 */	cmplw r3, r27
/* 80076F14  40 80 00 2C */	bge 0x2c
/* 80076F18  93 A3 00 00 */	stw r29, 0(r3)
/* 80076F1C  93 A3 00 04 */	stw r29, 4(r3)
/* 80076F20  93 A3 00 08 */	stw r29, 8(r3)
/* 80076F24  93 A3 00 0C */	stw r29, 0xc(r3)
/* 80076F28  93 A3 00 10 */	stw r29, 0x10(r3)
/* 80076F2C  93 A3 00 14 */	stw r29, 0x14(r3)
/* 80076F30  93 A3 00 18 */	stw r29, 0x18(r3)
/* 80076F34  93 A3 00 1C */	stw r29, 0x1c(r3)
/* 80076F38  38 63 00 20 */	addi r3, r3, 0x20
/* 80076F3C  42 00 FF DC */	bdnz -0x24
/* 80076F40  38 1C 00 03 */	addi r0, r28, 3
/* 80076F44  7C 03 00 50 */	subf r0, r3, r0
/* 80076F48  54 00 F0 BE */	srwi r0, r0, 2
/* 80076F4C  7C 09 03 A6 */	mtctr r0
/* 80076F50  7C 03 E0 40 */	cmplw r3, r28
/* 80076F54  40 80 00 10 */	bge 0x10
/* 80076F58  93 A3 00 00 */	stw r29, 0(r3)
/* 80076F5C  38 63 00 04 */	addi r3, r3, 4
/* 80076F60  42 00 FF F8 */	bdnz -0x8
/* 80076F64  81 90 00 00 */	lwz r12, 0(r16)
/* 80076F68  7E 03 83 78 */	mr r3, r16
/* 80076F6C  7E 65 9B 78 */	mr r5, r19
/* 80076F70  38 81 00 84 */	addi r4, r1, 0x84
/* 80076F74  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80076F78  7D 89 03 A6 */	mtctr r12
/* 80076F7C  4E 80 04 21 */	bctrl 
/* 80076F80  38 9F 01 44 */	addi r4, r31, 0x144
/* 80076F84  38 1F 00 40 */	addi r0, r31, 0x40
/* 80076F88  90 81 00 18 */	stw r4, 0x18(r1)
/* 80076F8C  7C 65 1B 78 */	mr r5, r3
/* 80076F90  38 61 00 1C */	addi r3, r1, 0x1c
/* 80076F94  38 81 00 18 */	addi r4, r1, 0x18
/* 80076F98  90 01 00 1C */	stw r0, 0x1c(r1)
/* 80076F9C  4B FE 2A 05 */	bl -0x1d5fc
/* 80076FA0  2C 11 00 00 */	cmpwi r17, 0
/* 80076FA4  41 82 00 80 */	beq 0x80
/* 80076FA8  7E 23 8B 78 */	mr r3, r17
/* 80076FAC  7E 64 9B 78 */	mr r4, r19
/* 80076FB0  4B FE 2F 61 */	bl -0x1d0a0
/* 80076FB4  2C 03 00 00 */	cmpwi r3, 0
/* 80076FB8  41 82 00 6C */	beq 0x6c
/* 80076FBC  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80076FC0  3B DF 01 A8 */	addi r30, r31, 0x1a8
/* 80076FC4  2C 00 00 00 */	cmpwi r0, 0
/* 80076FC8  41 82 00 0C */	beq 0xc
/* 80076FCC  7C 7F 02 14 */	add r3, r31, r0
/* 80076FD0  48 00 00 08 */	b 0x8
/* 80076FD4  38 60 00 00 */	li r3, 0
/* 80076FD8  38 03 00 A0 */	addi r0, r3, 0xa0
/* 80076FDC  90 01 00 24 */	stw r0, 0x24(r1)
/* 80076FE0  7E 23 8B 78 */	mr r3, r17
/* 80076FE4  7E 65 9B 78 */	mr r5, r19
/* 80076FE8  81 91 00 00 */	lwz r12, 0(r17)
/* 80076FEC  38 81 00 C8 */	addi r4, r1, 0xc8
/* 80076FF0  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80076FF4  7D 89 03 A6 */	mtctr r12
/* 80076FF8  4E 80 04 21 */	bctrl 
/* 80076FFC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80077000  7C 65 1B 78 */	mr r5, r3
/* 80077004  90 01 00 10 */	stw r0, 0x10(r1)
/* 80077008  38 61 00 14 */	addi r3, r1, 0x14
/* 8007700C  38 81 00 10 */	addi r4, r1, 0x10
/* 80077010  93 C1 00 14 */	stw r30, 0x14(r1)
/* 80077014  4B FE 40 1D */	bl -0x1bfe4
/* 80077018  38 61 00 24 */	addi r3, r1, 0x24
/* 8007701C  38 80 00 00 */	li r4, 0
/* 80077020  4B FD 94 71 */	bl -0x26b90
/* 80077024  2C 12 00 00 */	cmpwi r18, 0
/* 80077028  41 82 00 80 */	beq 0x80
/* 8007702C  7E 43 93 78 */	mr r3, r18
/* 80077030  7E 64 9B 78 */	mr r4, r19
/* 80077034  4B FE 00 2D */	bl -0x1ffd4
/* 80077038  2C 03 00 00 */	cmpwi r3, 0
/* 8007703C  41 82 00 6C */	beq 0x6c
/* 80077040  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 80077044  2C 00 00 00 */	cmpwi r0, 0
/* 80077048  41 82 00 0C */	beq 0xc
/* 8007704C  7C 7F 02 14 */	add r3, r31, r0
/* 80077050  48 00 00 08 */	b 0x8
/* 80077054  38 60 00 00 */	li r3, 0
/* 80077058  38 03 00 20 */	addi r0, r3, 0x20
/* 8007705C  90 01 00 20 */	stw r0, 0x20(r1)
/* 80077060  7E 43 93 78 */	mr r3, r18
/* 80077064  7E 65 9B 78 */	mr r5, r19
/* 80077068  81 92 00 00 */	lwz r12, 0(r18)
/* 8007706C  3B DF 03 F0 */	addi r30, r31, 0x3f0
/* 80077070  38 81 00 28 */	addi r4, r1, 0x28
/* 80077074  81 8C 00 38 */	lwz r12, 0x38(r12)
/* 80077078  7D 89 03 A6 */	mtctr r12
/* 8007707C  4E 80 04 21 */	bctrl 
/* 80077080  80 01 00 20 */	lwz r0, 0x20(r1)
/* 80077084  7C 65 1B 78 */	mr r5, r3
/* 80077088  90 01 00 08 */	stw r0, 8(r1)
/* 8007708C  38 61 00 0C */	addi r3, r1, 0xc
/* 80077090  38 81 00 08 */	addi r4, r1, 8
/* 80077094  93 C1 00 0C */	stw r30, 0xc(r1)
/* 80077098  4B FE 10 49 */	bl -0x1efb8
/* 8007709C  38 61 00 20 */	addi r3, r1, 0x20
/* 800770A0  38 80 00 00 */	li r4, 0
/* 800770A4  4B FD 93 CD */	bl -0x26c34
/* 800770A8  3A 73 00 01 */	addi r19, r19, 1
/* 800770AC  80 01 01 B8 */	lwz r0, 0x1b8(r1)
/* 800770B0  7C 13 00 40 */	cmplw r19, r0
/* 800770B4  41 80 FC A4 */	blt -0x35c
/* 800770B8  39 61 02 10 */	addi r11, r1, 0x210
/* 800770BC  4B FA A4 FD */	bl -0x55b04
/* 800770C0  80 01 02 14 */	lwz r0, 0x214(r1)
/* 800770C4  7C 08 03 A6 */	mtlr r0
/* 800770C8  38 21 02 10 */	addi r1, r1, 0x210
/* 800770CC  4E 80 00 20 */	blr 
/* 800770D0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800770D4  7C 08 02 A6 */	mflr r0
/* 800770D8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800770DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800770E0  7C 7F 1B 78 */	mr r31, r3
/* 800770E4  80 6D 81 88 */	lwz r3, -0x7e78(r13)
/* 800770E8  48 12 94 1D */	bl 0x12941c
/* 800770EC  2C 1F 00 00 */	cmpwi r31, 0
/* 800770F0  41 82 00 0C */	beq 0xc
/* 800770F4  48 03 A6 9D */	bl 0x3a69c
/* 800770F8  48 00 00 08 */	b 0x8
/* 800770FC  48 03 A6 F5 */	bl 0x3a6f4
/* 80077100  38 60 00 04 */	li r3, 4
/* 80077104  64 63 00 04 */	oris r3, r3, 4
/* 80077108  7C 72 E3 A6 */	mtspr 0x392, r3
/* 8007710C  38 60 00 05 */	li r3, 5
/* 80077110  64 63 00 05 */	oris r3, r3, 5
/* 80077114  7C 73 E3 A6 */	mtspr 0x393, r3
/* 80077118  38 60 00 06 */	li r3, 6
/* 8007711C  64 63 00 06 */	oris r3, r3, 6
/* 80077120  7C 74 E3 A6 */	mtspr 0x394, r3
/* 80077124  38 60 00 07 */	li r3, 7
/* 80077128  64 63 00 07 */	oris r3, r3, 7
/* 8007712C  7C 75 E3 A6 */	mtspr 0x395, r3
/* 80077130  3C 80 05 07 */	lis r4, 0x507
/* 80077134  38 04 05 07 */	addi r0, r4, 0x507
/* 80077138  7C 16 E3 A6 */	mtspr 0x396, r0
/* 8007713C  3C 80 08 07 */	lis r4, 0x807
/* 80077140  38 04 08 07 */	addi r0, r4, 0x807
/* 80077144  7C 17 E3 A6 */	mtspr 0x397, r0
/* 80077148  48 14 3B 91 */	bl 0x143b90
/* 8007714C  2C 03 00 00 */	cmpwi r3, 0
/* 80077150  41 82 00 20 */	beq 0x20
/* 80077154  28 03 00 01 */	cmplwi r3, 1
/* 80077158  41 82 00 24 */	beq 0x24
/* 8007715C  28 03 00 05 */	cmplwi r3, 5
/* 80077160  41 82 00 28 */	beq 0x28
/* 80077164  28 03 00 02 */	cmplwi r3, 2
/* 80077168  41 82 00 2C */	beq 0x2c
/* 8007716C  48 00 00 34 */	b 0x34
/* 80077170  3C 60 80 29 */	lis r3, 0x8029
/* 80077174  38 63 A2 48 */	addi r3, r3, -23992
/* 80077178  48 00 00 30 */	b 0x30
/* 8007717C  3C 60 80 29 */	lis r3, 0x8029
/* 80077180  38 63 A2 FC */	addi r3, r3, -23812
/* 80077184  48 00 00 24 */	b 0x24
/* 80077188  3C 60 80 29 */	lis r3, 0x8029
/* 8007718C  38 63 A3 38 */	addi r3, r3, -23752
/* 80077190  48 00 00 18 */	b 0x18
/* 80077194  3C 60 80 29 */	lis r3, 0x8029
/* 80077198  38 63 A2 C0 */	addi r3, r3, -23872
/* 8007719C  48 00 00 0C */	b 0xc
/* 800771A0  3C 60 80 29 */	lis r3, 0x8029
/* 800771A4  38 63 A2 48 */	addi r3, r3, -23992
/* 800771A8  4B FE D0 99 */	bl -0x12f68
/* 800771AC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800771B0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800771B4  7C 08 03 A6 */	mtlr r0
/* 800771B8  38 21 00 10 */	addi r1, r1, 0x10
/* 800771BC  4E 80 00 20 */	blr 
/* 800771C0  38 60 07 FF */	li r3, 0x7ff
/* 800771C4  4B FE D2 8C */	b -0x12d74
/* 800771C8  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800771CC  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 800771D0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800771D4  7C 08 02 A6 */	mflr r0
/* 800771D8  90 01 00 34 */	stw r0, 0x34(r1)
/* 800771DC  39 61 00 30 */	addi r11, r1, 0x30
/* 800771E0  4B FA A3 B9 */	bl -0x55c48
/* 800771E4  38 08 00 03 */	addi r0, r8, 3
/* 800771E8  2C 04 00 00 */	cmpwi r4, 0
/* 800771EC  54 1F 00 3A */	rlwinm r31, r0, 0, 0, 0x1d
/* 800771F0  7C 79 1B 78 */	mr r25, r3
/* 800771F4  38 1F 00 F7 */	addi r0, r31, 0xf7
/* 800771F8  7C BA 2B 78 */	mr r26, r5
/* 800771FC  7C DB 33 78 */	mr r27, r6
/* 80077200  7C FC 3B 78 */	mr r28, r7
/* 80077204  54 00 00 3A */	rlwinm r0, r0, 0, 0, 0x1d
/* 80077208  3B C0 00 00 */	li r30, 0
/* 8007720C  41 82 00 08 */	beq 0x8
/* 80077210  90 04 00 00 */	stw r0, 0(r4)
/* 80077214  2C 03 00 00 */	cmpwi r3, 0
/* 80077218  41 82 00 AC */	beq 0xac
/* 8007721C  7F 23 CB 78 */	mr r3, r25
/* 80077220  7C 04 03 78 */	mr r4, r0
/* 80077224  48 12 29 75 */	bl 0x122974
/* 80077228  2C 03 00 00 */	cmpwi r3, 0
/* 8007722C  7C 7D 1B 78 */	mr r29, r3
/* 80077230  41 82 00 94 */	beq 0x94
/* 80077234  2C 1F 00 00 */	cmpwi r31, 0
/* 80077238  41 82 00 0C */	beq 0xc
/* 8007723C  3B E3 00 F4 */	addi r31, r3, 0xf4
/* 80077240  48 00 00 08 */	b 0x8
/* 80077244  3B E0 00 00 */	li r31, 0
/* 80077248  2C 03 00 00 */	cmpwi r3, 0
/* 8007724C  7F BE EB 78 */	mr r30, r29
/* 80077250  41 82 00 74 */	beq 0x74
/* 80077254  7F A3 EB 78 */	mr r3, r29
/* 80077258  7F 24 CB 78 */	mr r4, r25
/* 8007725C  4B FF 65 55 */	bl -0x9aac
/* 80077260  3C 80 80 27 */	lis r4, 0x8027
/* 80077264  3C 60 80 27 */	lis r3, 0x8027
/* 80077268  38 84 31 18 */	addi r4, r4, 0x3118
/* 8007726C  90 9D 00 00 */	stw r4, 0(r29)
/* 80077270  C0 02 8D B0 */	lfs f0, -0x7250(r2)
/* 80077274  38 63 33 B8 */	addi r3, r3, 0x33b8
/* 80077278  D0 1D 00 DC */	stfs f0, 0xdc(r29)
/* 8007727C  38 00 00 00 */	li r0, 0
/* 80077280  2C 1B 00 00 */	cmpwi r27, 0
/* 80077284  D0 1D 00 E0 */	stfs f0, 0xe0(r29)
/* 80077288  D0 1D 00 E4 */	stfs f0, 0xe4(r29)
/* 8007728C  90 7D 00 00 */	stw r3, 0(r29)
/* 80077290  90 1D 00 E8 */	stw r0, 0xe8(r29)
/* 80077294  93 5D 00 EC */	stw r26, 0xec(r29)
/* 80077298  93 FD 00 F0 */	stw r31, 0xf0(r29)
/* 8007729C  41 82 00 10 */	beq 0x10
/* 800772A0  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 800772A4  60 00 00 01 */	ori r0, r0, 1
/* 800772A8  90 1D 00 E8 */	stw r0, 0xe8(r29)
/* 800772AC  2C 1C 00 00 */	cmpwi r28, 0
/* 800772B0  41 82 00 10 */	beq 0x10
/* 800772B4  80 1D 00 E8 */	lwz r0, 0xe8(r29)
/* 800772B8  60 00 00 02 */	ori r0, r0, 2
/* 800772BC  90 1D 00 E8 */	stw r0, 0xe8(r29)
/* 800772C0  7F BE EB 78 */	mr r30, r29
/* 800772C4  39 61 00 30 */	addi r11, r1, 0x30
/* 800772C8  7F C3 F3 78 */	mr r3, r30
/* 800772CC  4B FA A3 19 */	bl -0x55ce8
/* 800772D0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800772D4  7C 08 03 A6 */	mtlr r0
/* 800772D8  38 21 00 30 */	addi r1, r1, 0x30
/* 800772DC  4E 80 00 20 */	blr 
/* 800772E0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800772E4  7C 08 02 A6 */	mflr r0
/* 800772E8  28 04 00 09 */	cmplwi r4, 9
/* 800772EC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800772F0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800772F4  7C 7F 1B 78 */	mr r31, r3
/* 800772F8  40 80 00 24 */	bge 0x24
/* 800772FC  38 E4 FF FF */	addi r7, r4, -1
/* 80077300  39 00 00 01 */	li r8, 1
/* 80077304  80 03 00 CC */	lwz r0, 0xcc(r3)
/* 80077308  7D 07 38 30 */	slw r7, r8, r7
/* 8007730C  7C E0 00 39 */	and. r0, r7, r0
/* 80077310  41 82 00 0C */	beq 0xc
/* 80077314  38 00 00 01 */	li r0, 1
/* 80077318  48 00 00 08 */	b 0x8
/* 8007731C  38 00 00 00 */	li r0, 0
/* 80077320  2C 00 00 00 */	cmpwi r0, 0
/* 80077324  40 82 00 A8 */	bne 0xa8
/* 80077328  28 04 00 05 */	cmplwi r4, 5
/* 8007732C  41 82 00 18 */	beq 0x18
/* 80077330  28 04 00 06 */	cmplwi r4, 6
/* 80077334  41 82 00 38 */	beq 0x38
/* 80077338  28 04 00 07 */	cmplwi r4, 7
/* 8007733C  41 82 00 5C */	beq 0x5c
/* 80077340  48 00 00 84 */	b 0x84
/* 80077344  81 86 00 00 */	lwz r12, 0(r6)
/* 80077348  7C C3 33 78 */	mr r3, r6
/* 8007734C  80 1F 00 E8 */	lwz r0, 0xe8(r31)
/* 80077350  7F E4 FB 78 */	mr r4, r31
/* 80077354  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80077358  54 06 FF FE */	rlwinm r6, r0, 0x1f, 0x1f, 0x1f
/* 8007735C  54 05 07 FE */	clrlwi r5, r0, 0x1f
/* 80077360  7D 89 03 A6 */	mtctr r12
/* 80077364  4E 80 04 21 */	bctrl 
/* 80077368  48 00 00 64 */	b 0x64
/* 8007736C  80 03 00 EC */	lwz r0, 0xec(r3)
/* 80077370  2C 00 00 00 */	cmpwi r0, 0
/* 80077374  41 82 00 58 */	beq 0x58
/* 80077378  38 60 07 FF */	li r3, 0x7ff
/* 8007737C  4B FE D0 D5 */	bl -0x12f2c
/* 80077380  81 9F 00 EC */	lwz r12, 0xec(r31)
/* 80077384  7F E3 FB 78 */	mr r3, r31
/* 80077388  38 80 00 01 */	li r4, 1
/* 8007738C  7D 89 03 A6 */	mtctr r12
/* 80077390  4E 80 04 21 */	bctrl 
/* 80077394  48 00 00 38 */	b 0x38
/* 80077398  80 03 00 EC */	lwz r0, 0xec(r3)
/* 8007739C  2C 00 00 00 */	cmpwi r0, 0
/* 800773A0  41 82 00 2C */	beq 0x2c
/* 800773A4  38 60 07 FF */	li r3, 0x7ff
/* 800773A8  4B FE D0 A9 */	bl -0x12f58
/* 800773AC  81 9F 00 EC */	lwz r12, 0xec(r31)
/* 800773B0  7F E3 FB 78 */	mr r3, r31
/* 800773B4  38 80 00 00 */	li r4, 0
/* 800773B8  7D 89 03 A6 */	mtctr r12
/* 800773BC  4E 80 04 21 */	bctrl 
/* 800773C0  48 00 00 0C */	b 0xc
/* 800773C4  7F E3 FB 78 */	mr r3, r31
/* 800773C8  4B FF 6C E9 */	bl -0x9318
/* 800773CC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800773D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800773D4  7C 08 03 A6 */	mtlr r0
/* 800773D8  38 21 00 10 */	addi r1, r1, 0x10
/* 800773DC  4E 80 00 20 */	blr 
/* 800773E0  3C 60 80 25 */	lis r3, 0x8025
/* 800773E4  80 04 00 00 */	lwz r0, 0(r4)
/* 800773E8  38 63 80 00 */	addi r3, r3, -32768
/* 800773EC  7C 00 18 40 */	cmplw r0, r3
/* 800773F0  40 82 00 0C */	bne 0xc
/* 800773F4  38 60 00 01 */	li r3, 1
/* 800773F8  4E 80 00 20 */	blr 
/* 800773FC  3C 60 80 24 */	lis r3, 0x8024
/* 80077400  80 04 00 00 */	lwz r0, 0(r4)
/* 80077404  38 63 7F 80 */	addi r3, r3, 0x7f80
/* 80077408  7C 00 18 40 */	cmplw r0, r3
/* 8007740C  40 82 00 0C */	bne 0xc
/* 80077410  38 60 00 01 */	li r3, 1
/* 80077414  4E 80 00 20 */	blr 
/* 80077418  3C 60 80 24 */	lis r3, 0x8024
/* 8007741C  38 63 7F 70 */	addi r3, r3, 0x7f70
/* 80077420  7C 00 18 40 */	cmplw r0, r3
/* 80077424  40 82 00 0C */	bne 0xc
/* 80077428  38 60 00 01 */	li r3, 1
/* 8007742C  4E 80 00 20 */	blr 
/* 80077430  3C 60 80 24 */	lis r3, 0x8024
/* 80077434  38 63 76 C8 */	addi r3, r3, 0x76c8
/* 80077438  7C 00 18 50 */	subf r0, r0, r3
/* 8007743C  7C 00 00 34 */	cntlzw r0, r0
/* 80077440  54 03 D9 7E */	srwi r3, r0, 5
/* 80077444  4E 80 00 20 */	blr 
/* 80077448  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 8007744C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80077450  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80077454  7C 08 02 A6 */	mflr r0
/* 80077458  90 01 00 14 */	stw r0, 0x14(r1)
/* 8007745C  81 83 00 00 */	lwz r12, 0(r3)
/* 80077460  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80077464  7D 89 03 A6 */	mtctr r12
/* 80077468  4E 80 04 21 */	bctrl 
/* 8007746C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80077470  38 63 00 04 */	addi r3, r3, 4
/* 80077474  7C 08 03 A6 */	mtlr r0
/* 80077478  38 21 00 10 */	addi r1, r1, 0x10
/* 8007747C  4E 80 00 20 */	blr 
/* 80077480  3C 60 80 25 */	lis r3, 0x8025
/* 80077484  38 63 80 00 */	addi r3, r3, -32768
/* 80077488  4E 80 00 20 */	blr 
/* 8007748C  00 00 00 00 */	.4byte 0x00000000  /* unknown instruction */
/* 80077490  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80077494  7C 08 02 A6 */	mflr r0
/* 80077498  2C 03 00 00 */	cmpwi r3, 0
/* 8007749C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800774A0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800774A4  7C 7F 1B 78 */	mr r31, r3
/* 800774A8  41 82 00 10 */	beq 0x10
/* 800774AC  41 82 00 0C */	beq 0xc
/* 800774B0  38 80 00 00 */	li r4, 0
/* 800774B4  4B FF 63 ED */	bl -0x9c14
/* 800774B8  7F E3 FB 78 */	mr r3, r31
/* 800774BC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800774C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800774C4  7C 08 03 A6 */	mtlr r0
/* 800774C8  38 21 00 10 */	addi r1, r1, 0x10
/* 800774CC  4E 80 00 20 */	blr 
