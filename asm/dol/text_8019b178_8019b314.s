.include "macros.inc"

.section .text, "ax" # { 8019b178..8019b314 (text) }
/* 8019B178  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8019B17C  7C 08 02 A6 */	mflr r0
/* 8019B180  90 01 00 64 */	stw r0, 0x64(r1)
/* 8019B184  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 8019B188  F3 E1 00 58 */	psq_st f31, 88(r1), 0, qr0
/* 8019B18C  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 8019B190  F3 C1 00 48 */	psq_st f30, 72(r1), 0, qr0
/* 8019B194  DB A1 00 30 */	stfd f29, 0x30(r1)
/* 8019B198  F3 A1 00 38 */	psq_st f29, 56(r1), 0, qr0
/* 8019B19C  DB 81 00 20 */	stfd f28, 0x20(r1)
/* 8019B1A0  F3 81 00 28 */	psq_st f28, 40(r1), 0, qr0
/* 8019B1A4  FF E0 08 90 */	fmr f31, f1
/* 8019B1A8  C0 83 00 00 */	lfs f4, 0(r3)
/* 8019B1AC  C0 64 00 00 */	lfs f3, 0(r4)
/* 8019B1B0  C0 43 00 04 */	lfs f2, 4(r3)
/* 8019B1B4  C0 04 00 04 */	lfs f0, 4(r4)
/* 8019B1B8  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8019B1BC  C0 83 00 08 */	lfs f4, 8(r3)
/* 8019B1C0  EC 02 00 32 */	fmuls f0, f2, f0
/* 8019B1C4  C0 44 00 08 */	lfs f2, 8(r4)
/* 8019B1C8  C0 C3 00 0C */	lfs f6, 0xc(r3)
/* 8019B1CC  EC 84 00 B2 */	fmuls f4, f4, f2
/* 8019B1D0  C0 A4 00 0C */	lfs f5, 0xc(r4)
/* 8019B1D4  EC 43 00 2A */	fadds f2, f3, f0
/* 8019B1D8  EC 66 01 72 */	fmuls f3, f6, f5
/* 8019B1DC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8019B1E0  C0 02 99 20 */	lfs f0, -0x66e0(r2)
/* 8019B1E4  EC 44 10 2A */	fadds f2, f4, f2
/* 8019B1E8  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8019B1EC  C3 C2 99 1C */	lfs f30, -0x66e4(r2)
/* 8019B1F0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8019B1F4  7C 7D 1B 78 */	mr r29, r3
/* 8019B1F8  EC 43 10 2A */	fadds f2, f3, f2
/* 8019B1FC  7C 9E 23 78 */	mr r30, r4
/* 8019B200  7C BF 2B 78 */	mr r31, r5
/* 8019B204  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8019B208  40 80 00 0C */	bge 0xc
/* 8019B20C  FC 40 10 50 */	fneg f2, f2
/* 8019B210  FF C0 F0 50 */	fneg f30, f30
/* 8019B214  C0 02 99 2C */	lfs f0, -0x66d4(r2)
/* 8019B218  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8019B21C  4C 40 13 82 */	cror 2, 0, 2
/* 8019B220  40 82 00 4C */	bne 0x4c
/* 8019B224  FC 20 10 90 */	fmr f1, f2
/* 8019B228  4B E8 09 B5 */	bl -0x17f64c
/* 8019B22C  FF A0 08 18 */	frsp f29, f1
/* 8019B230  FC 20 E8 90 */	fmr f1, f29
/* 8019B234  4B E8 08 65 */	bl -0x17f79c
/* 8019B238  C0 02 99 1C */	lfs f0, -0x66e4(r2)
/* 8019B23C  FF 80 08 18 */	frsp f28, f1
/* 8019B240  EC 00 F8 28 */	fsubs f0, f0, f31
/* 8019B244  EC 20 07 72 */	fmuls f1, f0, f29
/* 8019B248  4B E8 08 51 */	bl -0x17f7b0
/* 8019B24C  FC 00 08 18 */	frsp f0, f1
/* 8019B250  EC 3F 07 72 */	fmuls f1, f31, f29
/* 8019B254  EF E0 E0 24 */	fdivs f31, f0, f28
/* 8019B258  4B E8 08 41 */	bl -0x17f7c0
/* 8019B25C  FC 00 08 18 */	frsp f0, f1
/* 8019B260  EC 00 E0 24 */	fdivs f0, f0, f28
/* 8019B264  EF DE 00 32 */	fmuls f30, f30, f0
/* 8019B268  48 00 00 10 */	b 0x10
/* 8019B26C  C0 02 99 1C */	lfs f0, -0x66e4(r2)
/* 8019B270  EF DE 00 72 */	fmuls f30, f30, f1
/* 8019B274  EF E0 08 28 */	fsubs f31, f0, f1
/* 8019B278  C0 1D 00 00 */	lfs f0, 0(r29)
/* 8019B27C  C0 5E 00 00 */	lfs f2, 0(r30)
/* 8019B280  C0 3D 00 04 */	lfs f1, 4(r29)
/* 8019B284  EC FF 00 32 */	fmuls f7, f31, f0
/* 8019B288  C0 1E 00 04 */	lfs f0, 4(r30)
/* 8019B28C  EC DE 00 B2 */	fmuls f6, f30, f2
/* 8019B290  C0 7D 00 08 */	lfs f3, 8(r29)
/* 8019B294  EC BF 00 72 */	fmuls f5, f31, f1
/* 8019B298  EC 9E 00 32 */	fmuls f4, f30, f0
/* 8019B29C  C0 5E 00 08 */	lfs f2, 8(r30)
/* 8019B2A0  EC 7F 00 F2 */	fmuls f3, f31, f3
/* 8019B2A4  C0 3D 00 0C */	lfs f1, 0xc(r29)
/* 8019B2A8  EC C7 30 2A */	fadds f6, f7, f6
/* 8019B2AC  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 8019B2B0  EC 5E 00 B2 */	fmuls f2, f30, f2
/* 8019B2B4  EC 85 20 2A */	fadds f4, f5, f4
/* 8019B2B8  D0 DF 00 00 */	stfs f6, 0(r31)
/* 8019B2BC  EC 3F 00 72 */	fmuls f1, f31, f1
/* 8019B2C0  EC 1E 00 32 */	fmuls f0, f30, f0
/* 8019B2C4  EC 43 10 2A */	fadds f2, f3, f2
/* 8019B2C8  D0 9F 00 04 */	stfs f4, 4(r31)
/* 8019B2CC  EC 01 00 2A */	fadds f0, f1, f0
/* 8019B2D0  D0 5F 00 08 */	stfs f2, 8(r31)
/* 8019B2D4  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 8019B2D8  E3 E1 00 58 */	psq_l f31, 88(r1), 0, qr0
/* 8019B2DC  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 8019B2E0  E3 C1 00 48 */	psq_l f30, 72(r1), 0, qr0
/* 8019B2E4  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 8019B2E8  E3 A1 00 38 */	psq_l f29, 56(r1), 0, qr0
/* 8019B2EC  CB A1 00 30 */	lfd f29, 0x30(r1)
/* 8019B2F0  E3 81 00 28 */	psq_l f28, 40(r1), 0, qr0
/* 8019B2F4  CB 81 00 20 */	lfd f28, 0x20(r1)
/* 8019B2F8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8019B2FC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8019B300  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8019B304  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8019B308  7C 08 03 A6 */	mtlr r0
/* 8019B30C  38 21 00 60 */	addi r1, r1, 0x60
/* 8019B310  4E 80 00 20 */	blr
