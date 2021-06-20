
.include "macros.inc"

.section .text, "ax" # 0x8019A9C4 - 0x8019AA60
/* 8019A9C4  EC 04 18 28 */	fsubs f0, f4, f3
/* 8019A9C8  C1 22 98 F8 */	lfs f9, -0x6708(r2)
/* 8019A9CC  C1 62 98 F0 */	lfs f11, -0x6710(r2)
/* 8019A9D0  ED 01 10 28 */	fsubs f8, f1, f2
/* 8019A9D4  EC E6 28 28 */	fsubs f7, f6, f5
/* 8019A9D8  C1 42 98 F4 */	lfs f10, -0x670c(r2)
/* 8019A9DC  ED 8B 00 24 */	fdivs f12, f11, f0
/* 8019A9E0  C0 02 98 FC */	lfs f0, -0x6704(r2)
/* 8019A9E4  D1 23 00 04 */	stfs f9, 4(r3)
/* 8019A9E8  D0 03 00 38 */	stfs f0, 0x38(r3)
/* 8019A9EC  D1 23 00 0C */	stfs f9, 0xc(r3)
/* 8019A9F0  D1 23 00 10 */	stfs f9, 0x10(r3)
/* 8019A9F4  ED 0B 40 24 */	fdivs f8, f11, f8
/* 8019A9F8  D1 23 00 1C */	stfs f9, 0x1c(r3)
/* 8019A9FC  D1 23 00 20 */	stfs f9, 0x20(r3)
/* 8019AA00  D1 23 00 24 */	stfs f9, 0x24(r3)
/* 8019AA04  D1 23 00 30 */	stfs f9, 0x30(r3)
/* 8019AA08  D1 23 00 34 */	stfs f9, 0x34(r3)
/* 8019AA0C  EC 01 10 2A */	fadds f0, f1, f2
/* 8019AA10  D1 23 00 3C */	stfs f9, 0x3c(r3)
/* 8019AA14  EC 64 18 2A */	fadds f3, f4, f3
/* 8019AA18  ED 4A 01 72 */	fmuls f10, f10, f5
/* 8019AA1C  EC 08 00 32 */	fmuls f0, f8, f0
/* 8019AA20  EC 4C 00 F2 */	fmuls f2, f12, f3
/* 8019AA24  EC 2A 02 32 */	fmuls f1, f10, f8
/* 8019AA28  EC 8A 03 32 */	fmuls f4, f10, f12
/* 8019AA2C  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 8019AA30  EC C6 01 72 */	fmuls f6, f6, f5
/* 8019AA34  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8019AA38  EC 6B 38 24 */	fdivs f3, f11, f7
/* 8019AA3C  D0 83 00 00 */	stfs f4, 0(r3)
/* 8019AA40  D0 43 00 08 */	stfs f2, 8(r3)
/* 8019AA44  FC 20 28 50 */	fneg f1, f5
/* 8019AA48  FC 00 30 50 */	fneg f0, f6
/* 8019AA4C  EC 21 00 F2 */	fmuls f1, f1, f3
/* 8019AA50  EC 03 00 32 */	fmuls f0, f3, f0
/* 8019AA54  D0 23 00 28 */	stfs f1, 0x28(r3)
/* 8019AA58  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 8019AA5C  4E 80 00 20 */	blr 
