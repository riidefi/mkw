.include "macros.inc"

.section .text, "ax" # { 80239e10..80242498 (text) }
/* 80239E10  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 80239E14  7C 08 02 A6 */	mflr r0
/* 80239E18  90 01 00 64 */	stw r0, 0x64(r1)
/* 80239E1C  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 80239E20  F3 E1 00 58 */	psq_st f31, 88(r1), 0, qr0
/* 80239E24  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 80239E28  F3 C1 00 48 */	psq_st f30, 72(r1), 0, qr0
/* 80239E2C  DB A1 00 30 */	stfd f29, 0x30(r1)
/* 80239E30  F3 A1 00 38 */	psq_st f29, 56(r1), 0, qr0
/* 80239E34  DB 81 00 20 */	stfd f28, 0x20(r1)
/* 80239E38  F3 81 00 28 */	psq_st f28, 40(r1), 0, qr0
/* 80239E3C  DB 61 00 10 */	stfd f27, 0x10(r1)
/* 80239E40  F3 61 00 18 */	psq_st f27, 24(r1), 0, qr0
/* 80239E44  C0 22 A0 40 */	lfs f1, -0x5fc0(r2)
/* 80239E48  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80239E4C  7C 9F 23 78 */	mr r31, r4
/* 80239E50  C0 04 00 08 */	lfs f0, 8(r4)
/* 80239E54  93 C1 00 08 */	stw r30, 8(r1)
/* 80239E58  7C 7E 1B 78 */	mr r30, r3
/* 80239E5C  EC 21 00 32 */	fmuls f1, f1, f0
/* 80239E60  4B FF 5A 0D */	bl -0xa5f4
/* 80239E64  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239E68  FF 60 08 90 */	fmr f27, f1
/* 80239E6C  C0 1F 00 04 */	lfs f0, 4(r31)
/* 80239E70  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239E74  4B FF 59 F9 */	bl -0xa608
/* 80239E78  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239E7C  FF 80 08 90 */	fmr f28, f1
/* 80239E80  C0 1F 00 00 */	lfs f0, 0(r31)
/* 80239E84  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239E88  4B FF 59 E5 */	bl -0xa61c
/* 80239E8C  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239E90  FF A0 08 90 */	fmr f29, f1
/* 80239E94  C0 1F 00 08 */	lfs f0, 8(r31)
/* 80239E98  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239E9C  4B FF 59 C5 */	bl -0xa63c
/* 80239EA0  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239EA4  FF C0 08 90 */	fmr f30, f1
/* 80239EA8  C0 1F 00 04 */	lfs f0, 4(r31)
/* 80239EAC  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239EB0  4B FF 59 B1 */	bl -0xa650
/* 80239EB4  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239EB8  FF E0 08 90 */	fmr f31, f1
/* 80239EBC  C0 1F 00 00 */	lfs f0, 0(r31)
/* 80239EC0  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239EC4  4B FF 59 9D */	bl -0xa664
/* 80239EC8  EC 1B 07 32 */	fmuls f0, f27, f28
/* 80239ECC  EC BE 07 F2 */	fmuls f5, f30, f31
/* 80239ED0  EC DB 07 F2 */	fmuls f6, f27, f31
/* 80239ED4  EC 80 07 72 */	fmuls f4, f0, f29
/* 80239ED8  EC 65 00 72 */	fmuls f3, f5, f1
/* 80239EDC  EC 40 00 72 */	fmuls f2, f0, f1
/* 80239EE0  EC 05 07 72 */	fmuls f0, f5, f29
/* 80239EE4  EC A4 18 2A */	fadds f5, f4, f3
/* 80239EE8  EC FE 07 32 */	fmuls f7, f30, f28
/* 80239EEC  D0 BE 00 0C */	stfs f5, 0xc(r30)
/* 80239EF0  EC A2 00 28 */	fsubs f5, f2, f0
/* 80239EF4  EC 86 07 72 */	fmuls f4, f6, f29
/* 80239EF8  EC 67 00 72 */	fmuls f3, f7, f1
/* 80239EFC  D0 BE 00 00 */	stfs f5, 0(r30)
/* 80239F00  EC 06 00 72 */	fmuls f0, f6, f1
/* 80239F04  EC 47 07 72 */	fmuls f2, f7, f29
/* 80239F08  EC 24 18 2A */	fadds f1, f4, f3
/* 80239F0C  EC 02 00 28 */	fsubs f0, f2, f0
/* 80239F10  D0 3E 00 04 */	stfs f1, 4(r30)
/* 80239F14  D0 1E 00 08 */	stfs f0, 8(r30)
/* 80239F18  E3 E1 00 58 */	psq_l f31, 88(r1), 0, qr0
/* 80239F1C  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 80239F20  E3 C1 00 48 */	psq_l f30, 72(r1), 0, qr0
/* 80239F24  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 80239F28  E3 A1 00 38 */	psq_l f29, 56(r1), 0, qr0
/* 80239F2C  CB A1 00 30 */	lfd f29, 0x30(r1)
/* 80239F30  E3 81 00 28 */	psq_l f28, 40(r1), 0, qr0
/* 80239F34  CB 81 00 20 */	lfd f28, 0x20(r1)
/* 80239F38  E3 61 00 18 */	psq_l f27, 24(r1), 0, qr0
/* 80239F3C  CB 61 00 10 */	lfd f27, 0x10(r1)
/* 80239F40  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80239F44  83 C1 00 08 */	lwz r30, 8(r1)
/* 80239F48  80 01 00 64 */	lwz r0, 0x64(r1)
/* 80239F4C  7C 08 03 A6 */	mtlr r0
/* 80239F50  38 21 00 60 */	addi r1, r1, 0x60
/* 80239F54  4E 80 00 20 */	blr
/* 80239F58  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 80239F5C  7C 08 02 A6 */	mflr r0
/* 80239F60  90 01 00 74 */	stw r0, 0x74(r1)
/* 80239F64  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 80239F68  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 80239F6C  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 80239F70  F3 C1 00 58 */	psq_st f30, 88(r1), 0, qr0
/* 80239F74  DB A1 00 40 */	stfd f29, 0x40(r1)
/* 80239F78  F3 A1 00 48 */	psq_st f29, 72(r1), 0, qr0
/* 80239F7C  DB 81 00 30 */	stfd f28, 0x30(r1)
/* 80239F80  F3 81 00 38 */	psq_st f28, 56(r1), 0, qr0
/* 80239F84  DB 61 00 20 */	stfd f27, 0x20(r1)
/* 80239F88  F3 61 00 28 */	psq_st f27, 40(r1), 0, qr0
/* 80239F8C  FC 00 18 18 */	frsp f0, f3
/* 80239F90  C0 82 A0 40 */	lfs f4, -0x5fc0(r2)
/* 80239F94  D0 21 00 08 */	stfs f1, 8(r1)
/* 80239F98  EC 24 00 32 */	fmuls f1, f4, f0
/* 80239F9C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80239FA0  7C 7F 1B 78 */	mr r31, r3
/* 80239FA4  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 80239FA8  D0 61 00 10 */	stfs f3, 0x10(r1)
/* 80239FAC  4B FF 58 C1 */	bl -0xa740
/* 80239FB0  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239FB4  FF 60 08 90 */	fmr f27, f1
/* 80239FB8  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 80239FBC  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239FC0  4B FF 58 AD */	bl -0xa754
/* 80239FC4  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239FC8  FF 80 08 90 */	fmr f28, f1
/* 80239FCC  C0 01 00 08 */	lfs f0, 8(r1)
/* 80239FD0  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239FD4  4B FF 58 99 */	bl -0xa768
/* 80239FD8  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239FDC  FF A0 08 90 */	fmr f29, f1
/* 80239FE0  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 80239FE4  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239FE8  4B FF 58 79 */	bl -0xa788
/* 80239FEC  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 80239FF0  FF C0 08 90 */	fmr f30, f1
/* 80239FF4  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 80239FF8  EC 22 00 32 */	fmuls f1, f2, f0
/* 80239FFC  4B FF 58 65 */	bl -0xa79c
/* 8023A000  C0 42 A0 40 */	lfs f2, -0x5fc0(r2)
/* 8023A004  FF E0 08 90 */	fmr f31, f1
/* 8023A008  C0 01 00 08 */	lfs f0, 8(r1)
/* 8023A00C  EC 22 00 32 */	fmuls f1, f2, f0
/* 8023A010  4B FF 58 51 */	bl -0xa7b0
/* 8023A014  EC 5B 07 32 */	fmuls f2, f27, f28
/* 8023A018  EC 1E 07 F2 */	fmuls f0, f30, f31
/* 8023A01C  EC FB 07 F2 */	fmuls f7, f27, f31
/* 8023A020  EC 82 07 72 */	fmuls f4, f2, f29
/* 8023A024  EC 60 00 72 */	fmuls f3, f0, f1
/* 8023A028  EC DE 07 32 */	fmuls f6, f30, f28
/* 8023A02C  EC 42 00 72 */	fmuls f2, f2, f1
/* 8023A030  EC A4 18 2A */	fadds f5, f4, f3
/* 8023A034  EC 00 07 72 */	fmuls f0, f0, f29
/* 8023A038  D0 BF 00 0C */	stfs f5, 0xc(r31)
/* 8023A03C  EC 87 07 72 */	fmuls f4, f7, f29
/* 8023A040  EC 66 00 72 */	fmuls f3, f6, f1
/* 8023A044  EC A2 00 28 */	fsubs f5, f2, f0
/* 8023A048  EC 07 00 72 */	fmuls f0, f7, f1
/* 8023A04C  EC 46 07 72 */	fmuls f2, f6, f29
/* 8023A050  D0 BF 00 00 */	stfs f5, 0(r31)
/* 8023A054  EC 24 18 2A */	fadds f1, f4, f3
/* 8023A058  EC 02 00 28 */	fsubs f0, f2, f0
/* 8023A05C  D0 3F 00 04 */	stfs f1, 4(r31)
/* 8023A060  D0 1F 00 08 */	stfs f0, 8(r31)
/* 8023A064  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 8023A068  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 8023A06C  E3 C1 00 58 */	psq_l f30, 88(r1), 0, qr0
/* 8023A070  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 8023A074  E3 A1 00 48 */	psq_l f29, 72(r1), 0, qr0
/* 8023A078  CB A1 00 40 */	lfd f29, 0x40(r1)
/* 8023A07C  E3 81 00 38 */	psq_l f28, 56(r1), 0, qr0
/* 8023A080  CB 81 00 30 */	lfd f28, 0x30(r1)
/* 8023A084  E3 61 00 28 */	psq_l f27, 40(r1), 0, qr0
/* 8023A088  CB 61 00 20 */	lfd f27, 0x20(r1)
/* 8023A08C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023A090  80 01 00 74 */	lwz r0, 0x74(r1)
/* 8023A094  7C 08 03 A6 */	mtlr r0
/* 8023A098  38 21 00 70 */	addi r1, r1, 0x70
/* 8023A09C  4E 80 00 20 */	blr
/* 8023A0A0  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8023A0A4  7C 08 02 A6 */	mflr r0
/* 8023A0A8  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023A0AC  DB E1 00 20 */	stfd f31, 0x20(r1)
/* 8023A0B0  F3 E1 00 28 */	psq_st f31, 40(r1), 0, qr0
/* 8023A0B4  DB C1 00 10 */	stfd f30, 0x10(r1)
/* 8023A0B8  F3 C1 00 18 */	psq_st f30, 24(r1), 0, qr0
/* 8023A0BC  C0 02 A0 40 */	lfs f0, -0x5fc0(r2)
/* 8023A0C0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023A0C4  7C 9F 23 78 */	mr r31, r4
/* 8023A0C8  EF C0 00 72 */	fmuls f30, f0, f1
/* 8023A0CC  93 C1 00 08 */	stw r30, 8(r1)
/* 8023A0D0  7C 7E 1B 78 */	mr r30, r3
/* 8023A0D4  FC 20 F0 90 */	fmr f1, f30
/* 8023A0D8  4B FF 57 95 */	bl -0xa86c
/* 8023A0DC  FF E0 08 90 */	fmr f31, f1
/* 8023A0E0  FC 20 F0 90 */	fmr f1, f30
/* 8023A0E4  4B FF 57 7D */	bl -0xa884
/* 8023A0E8  C0 7F 00 08 */	lfs f3, 8(r31)
/* 8023A0EC  C0 5F 00 04 */	lfs f2, 4(r31)
/* 8023A0F0  C0 1F 00 00 */	lfs f0, 0(r31)
/* 8023A0F4  EC 61 00 F2 */	fmuls f3, f1, f3
/* 8023A0F8  EC 41 00 B2 */	fmuls f2, f1, f2
/* 8023A0FC  D3 FE 00 0C */	stfs f31, 0xc(r30)
/* 8023A100  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023A104  D0 5E 00 04 */	stfs f2, 4(r30)
/* 8023A108  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8023A10C  D0 7E 00 08 */	stfs f3, 8(r30)
/* 8023A110  E3 E1 00 28 */	psq_l f31, 40(r1), 0, qr0
/* 8023A114  CB E1 00 20 */	lfd f31, 0x20(r1)
/* 8023A118  E3 C1 00 18 */	psq_l f30, 24(r1), 0, qr0
/* 8023A11C  CB C1 00 10 */	lfd f30, 0x10(r1)
/* 8023A120  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023A124  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023A128  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8023A12C  7C 08 03 A6 */	mtlr r0
/* 8023A130  38 21 00 30 */	addi r1, r1, 0x30
/* 8023A134  4E 80 00 20 */	blr
/* 8023A138  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023A13C  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023A140  EC 41 00 72 */	fmuls f2, f1, f1
/* 8023A144  C0 63 00 08 */	lfs f3, 8(r3)
/* 8023A148  EC 20 00 32 */	fmuls f1, f0, f0
/* 8023A14C  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8023A150  EC 63 00 F2 */	fmuls f3, f3, f3
/* 8023A154  EC 00 00 32 */	fmuls f0, f0, f0
/* 8023A158  EC 22 08 2A */	fadds f1, f2, f1
/* 8023A15C  EC 23 08 2A */	fadds f1, f3, f1
/* 8023A160  EC 20 08 2A */	fadds f1, f0, f1
/* 8023A164  4E 80 00 20 */	blr
/* 8023A168  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023A16C  7C 08 02 A6 */	mflr r0
/* 8023A170  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023A174  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023A178  7C 7F 1B 78 */	mr r31, r3
/* 8023A17C  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023A180  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023A184  EC 61 00 72 */	fmuls f3, f1, f1
/* 8023A188  C0 83 00 08 */	lfs f4, 8(r3)
/* 8023A18C  EC 40 00 32 */	fmuls f2, f0, f0
/* 8023A190  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 8023A194  EC 84 01 32 */	fmuls f4, f4, f4
/* 8023A198  C0 02 A0 4C */	lfs f0, -0x5fb4(r2)
/* 8023A19C  EC 43 10 2A */	fadds f2, f3, f2
/* 8023A1A0  EC 21 00 72 */	fmuls f1, f1, f1
/* 8023A1A4  EC 44 10 2A */	fadds f2, f4, f2
/* 8023A1A8  EC 21 10 2A */	fadds f1, f1, f2
/* 8023A1AC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A1B0  40 81 00 4C */	ble 0x4c
/* 8023A1B4  4B FF 56 59 */	bl -0xa9a8
/* 8023A1B8  C0 02 A0 48 */	lfs f0, -0x5fb8(r2)
/* 8023A1BC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A1C0  40 81 00 3C */	ble 0x3c
/* 8023A1C4  C0 02 A0 50 */	lfs f0, -0x5fb0(r2)
/* 8023A1C8  C0 7F 00 0C */	lfs f3, 0xc(r31)
/* 8023A1CC  EC 80 08 24 */	fdivs f4, f0, f1
/* 8023A1D0  C0 5F 00 00 */	lfs f2, 0(r31)
/* 8023A1D4  C0 3F 00 04 */	lfs f1, 4(r31)
/* 8023A1D8  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8023A1DC  EC 63 01 32 */	fmuls f3, f3, f4
/* 8023A1E0  EC 42 01 32 */	fmuls f2, f2, f4
/* 8023A1E4  EC 21 01 32 */	fmuls f1, f1, f4
/* 8023A1E8  D0 7F 00 0C */	stfs f3, 0xc(r31)
/* 8023A1EC  EC 00 01 32 */	fmuls f0, f0, f4
/* 8023A1F0  D0 5F 00 00 */	stfs f2, 0(r31)
/* 8023A1F4  D0 3F 00 04 */	stfs f1, 4(r31)
/* 8023A1F8  D0 1F 00 08 */	stfs f0, 8(r31)
/* 8023A1FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023A200  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023A204  7C 08 03 A6 */	mtlr r0
/* 8023A208  38 21 00 10 */	addi r1, r1, 0x10
/* 8023A20C  4E 80 00 20 */	blr
/* 8023A210  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023A214  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023A218  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023A21C  EC 41 00 72 */	fmuls f2, f1, f1
/* 8023A220  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 8023A224  EC 00 00 32 */	fmuls f0, f0, f0
/* 8023A228  C0 63 00 08 */	lfs f3, 8(r3)
/* 8023A22C  C0 E3 00 00 */	lfs f7, 0(r3)
/* 8023A230  EC 24 01 32 */	fmuls f1, f4, f4
/* 8023A234  EC 42 00 2A */	fadds f2, f2, f0
/* 8023A238  C0 C3 00 04 */	lfs f6, 4(r3)
/* 8023A23C  EC 63 00 F2 */	fmuls f3, f3, f3
/* 8023A240  C0 A3 00 08 */	lfs f5, 8(r3)
/* 8023A244  FC E0 38 50 */	fneg f7, f7
/* 8023A248  C0 02 A0 48 */	lfs f0, -0x5fb8(r2)
/* 8023A24C  EC 43 10 2A */	fadds f2, f3, f2
/* 8023A250  D0 E1 00 08 */	stfs f7, 8(r1)
/* 8023A254  FC 60 28 50 */	fneg f3, f5
/* 8023A258  FC C0 30 50 */	fneg f6, f6
/* 8023A25C  D0 81 00 14 */	stfs f4, 0x14(r1)
/* 8023A260  EC A1 10 2A */	fadds f5, f1, f2
/* 8023A264  D0 C1 00 0C */	stfs f6, 0xc(r1)
/* 8023A268  FC 05 00 40 */	fcmpo cr0, f5, f0
/* 8023A26C  D0 61 00 10 */	stfs f3, 0x10(r1)
/* 8023A270  40 81 00 3C */	ble 0x3c
/* 8023A274  C0 02 A0 50 */	lfs f0, -0x5fb0(r2)
/* 8023A278  FC 40 38 18 */	frsp f2, f7
/* 8023A27C  FC 20 30 18 */	frsp f1, f6
/* 8023A280  EC A0 28 24 */	fdivs f5, f0, f5
/* 8023A284  FC 00 18 18 */	frsp f0, f3
/* 8023A288  EC 65 00 B2 */	fmuls f3, f5, f2
/* 8023A28C  EC 45 00 72 */	fmuls f2, f5, f1
/* 8023A290  EC 25 00 32 */	fmuls f1, f5, f0
/* 8023A294  D0 64 00 00 */	stfs f3, 0(r4)
/* 8023A298  EC 05 01 32 */	fmuls f0, f5, f4
/* 8023A29C  D0 44 00 04 */	stfs f2, 4(r4)
/* 8023A2A0  D0 24 00 08 */	stfs f1, 8(r4)
/* 8023A2A4  D0 04 00 0C */	stfs f0, 0xc(r4)
/* 8023A2A8  48 00 00 20 */	b 0x20
/* 8023A2AC  FC 40 38 18 */	frsp f2, f7
/* 8023A2B0  D0 84 00 0C */	stfs f4, 0xc(r4)
/* 8023A2B4  FC 20 30 18 */	frsp f1, f6
/* 8023A2B8  FC 00 18 18 */	frsp f0, f3
/* 8023A2BC  D0 44 00 00 */	stfs f2, 0(r4)
/* 8023A2C0  D0 24 00 04 */	stfs f1, 4(r4)
/* 8023A2C4  D0 04 00 08 */	stfs f0, 8(r4)
/* 8023A2C8  38 21 00 20 */	addi r1, r1, 0x20
/* 8023A2CC  4E 80 00 20 */	blr
/* 8023A2D0  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8023A2D4  7C 08 02 A6 */	mflr r0
/* 8023A2D8  90 01 00 54 */	stw r0, 0x54(r1)
/* 8023A2DC  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8023A2E0  F3 E1 00 48 */	psq_st f31, 72(r1), 0, qr0
/* 8023A2E4  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 8023A2E8  F3 C1 00 38 */	psq_st f30, 56(r1), 0, qr0
/* 8023A2EC  7C 80 23 78 */	mr r0, r4
/* 8023A2F0  7C 64 1B 78 */	mr r4, r3
/* 8023A2F4  38 C1 00 08 */	addi r6, r1, 8
/* 8023A2F8  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8023A2FC  7C BF 2B 78 */	mr r31, r5
/* 8023A300  7C 05 03 78 */	mr r5, r0
/* 8023A304  C0 43 00 00 */	lfs f2, 0(r3)
/* 8023A308  C0 23 00 08 */	lfs f1, 8(r3)
/* 8023A30C  FC 60 10 50 */	fneg f3, f2
/* 8023A310  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023A314  FC 20 08 50 */	fneg f1, f1
/* 8023A318  FC 40 00 50 */	fneg f2, f0
/* 8023A31C  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8023A320  D0 61 00 18 */	stfs f3, 0x18(r1)
/* 8023A324  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 8023A328  D0 21 00 20 */	stfs f1, 0x20(r1)
/* 8023A32C  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8023A330  48 00 02 11 */	bl 0x210
/* 8023A334  C1 81 00 10 */	lfs f12, 0x10(r1)
/* 8023A338  C0 E1 00 24 */	lfs f7, 0x24(r1)
/* 8023A33C  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8023A340  C3 E1 00 1C */	lfs f31, 0x1c(r1)
/* 8023A344  EC 6C 01 F2 */	fmuls f3, f12, f7
/* 8023A348  C3 C1 00 08 */	lfs f30, 8(r1)
/* 8023A34C  C1 61 00 20 */	lfs f11, 0x20(r1)
/* 8023A350  EC A1 07 F2 */	fmuls f5, f1, f31
/* 8023A354  C1 21 00 0C */	lfs f9, 0xc(r1)
/* 8023A358  EC 9E 01 F2 */	fmuls f4, f30, f7
/* 8023A35C  EC 01 02 F2 */	fmuls f0, f1, f11
/* 8023A360  C1 01 00 18 */	lfs f8, 0x18(r1)
/* 8023A364  EC C9 01 F2 */	fmuls f6, f9, f7
/* 8023A368  ED BE 07 F2 */	fmuls f13, f30, f31
/* 8023A36C  ED 43 00 2A */	fadds f10, f3, f0
/* 8023A370  EC 61 02 32 */	fmuls f3, f1, f8
/* 8023A374  EC 21 01 F2 */	fmuls f1, f1, f7
/* 8023A378  EC 1E 02 32 */	fmuls f0, f30, f8
/* 8023A37C  EC C6 28 2A */	fadds f6, f6, f5
/* 8023A380  EC 64 18 2A */	fadds f3, f4, f3
/* 8023A384  EC A9 02 F2 */	fmuls f5, f9, f11
/* 8023A388  EC 21 00 28 */	fsubs f1, f1, f0
/* 8023A38C  EC 09 07 F2 */	fmuls f0, f9, f31
/* 8023A390  EC 65 18 2A */	fadds f3, f5, f3
/* 8023A394  EC 4C 07 F2 */	fmuls f2, f12, f31
/* 8023A398  EC 21 00 28 */	fsubs f1, f1, f0
/* 8023A39C  EC 0C 02 F2 */	fmuls f0, f12, f11
/* 8023A3A0  EC EC 02 32 */	fmuls f7, f12, f8
/* 8023A3A4  EC 89 02 32 */	fmuls f4, f9, f8
/* 8023A3A8  ED 03 10 28 */	fsubs f8, f3, f2
/* 8023A3AC  EC AD 50 2A */	fadds f5, f13, f10
/* 8023A3B0  EC 01 00 28 */	fsubs f0, f1, f0
/* 8023A3B4  D1 01 00 08 */	stfs f8, 8(r1)
/* 8023A3B8  EC 67 30 2A */	fadds f3, f7, f6
/* 8023A3BC  EC 5E 02 F2 */	fmuls f2, f30, f11
/* 8023A3C0  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8023A3C4  EC 85 20 28 */	fsubs f4, f5, f4
/* 8023A3C8  EC 43 10 28 */	fsubs f2, f3, f2
/* 8023A3CC  D0 81 00 10 */	stfs f4, 0x10(r1)
/* 8023A3D0  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 8023A3D4  D1 1F 00 00 */	stfs f8, 0(r31)
/* 8023A3D8  D0 5F 00 04 */	stfs f2, 4(r31)
/* 8023A3DC  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8023A3E0  E3 E1 00 48 */	psq_l f31, 72(r1), 0, qr0
/* 8023A3E4  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8023A3E8  E3 C1 00 38 */	psq_l f30, 56(r1), 0, qr0
/* 8023A3EC  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 8023A3F0  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8023A3F4  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8023A3F8  7C 08 03 A6 */	mtlr r0
/* 8023A3FC  38 21 00 50 */	addi r1, r1, 0x50
/* 8023A400  4E 80 00 20 */	blr
/* 8023A404  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8023A408  7C 08 02 A6 */	mflr r0
/* 8023A40C  90 01 00 54 */	stw r0, 0x54(r1)
/* 8023A410  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8023A414  F3 E1 00 48 */	psq_st f31, 72(r1), 0, qr0
/* 8023A418  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 8023A41C  F3 C1 00 38 */	psq_st f30, 56(r1), 0, qr0
/* 8023A420  38 C1 00 08 */	addi r6, r1, 8
/* 8023A424  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8023A428  7C BF 2B 78 */	mr r31, r5
/* 8023A42C  7C 85 23 78 */	mr r5, r4
/* 8023A430  38 81 00 18 */	addi r4, r1, 0x18
/* 8023A434  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8023A438  7C 7E 1B 78 */	mr r30, r3
/* 8023A43C  C0 03 00 00 */	lfs f0, 0(r3)
/* 8023A440  FC 00 00 50 */	fneg f0, f0
/* 8023A444  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8023A448  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023A44C  FC 00 00 50 */	fneg f0, f0
/* 8023A450  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8023A454  C0 03 00 08 */	lfs f0, 8(r3)
/* 8023A458  FC 00 00 50 */	fneg f0, f0
/* 8023A45C  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8023A460  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8023A464  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 8023A468  48 00 00 D9 */	bl 0xd8
/* 8023A46C  C1 81 00 10 */	lfs f12, 0x10(r1)
/* 8023A470  C0 FE 00 0C */	lfs f7, 0xc(r30)
/* 8023A474  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8023A478  C3 FE 00 04 */	lfs f31, 4(r30)
/* 8023A47C  EC 6C 01 F2 */	fmuls f3, f12, f7
/* 8023A480  C3 C1 00 08 */	lfs f30, 8(r1)
/* 8023A484  C1 7E 00 08 */	lfs f11, 8(r30)
/* 8023A488  EC A1 07 F2 */	fmuls f5, f1, f31
/* 8023A48C  C1 21 00 0C */	lfs f9, 0xc(r1)
/* 8023A490  EC 9E 01 F2 */	fmuls f4, f30, f7
/* 8023A494  EC 01 02 F2 */	fmuls f0, f1, f11
/* 8023A498  C1 1E 00 00 */	lfs f8, 0(r30)
/* 8023A49C  EC C9 01 F2 */	fmuls f6, f9, f7
/* 8023A4A0  ED BE 07 F2 */	fmuls f13, f30, f31
/* 8023A4A4  ED 43 00 2A */	fadds f10, f3, f0
/* 8023A4A8  EC 61 02 32 */	fmuls f3, f1, f8
/* 8023A4AC  EC 21 01 F2 */	fmuls f1, f1, f7
/* 8023A4B0  EC 1E 02 32 */	fmuls f0, f30, f8
/* 8023A4B4  EC C6 28 2A */	fadds f6, f6, f5
/* 8023A4B8  EC 64 18 2A */	fadds f3, f4, f3
/* 8023A4BC  EC A9 02 F2 */	fmuls f5, f9, f11
/* 8023A4C0  EC 21 00 28 */	fsubs f1, f1, f0
/* 8023A4C4  EC 09 07 F2 */	fmuls f0, f9, f31
/* 8023A4C8  EC 65 18 2A */	fadds f3, f5, f3
/* 8023A4CC  EC 4C 07 F2 */	fmuls f2, f12, f31
/* 8023A4D0  EC 21 00 28 */	fsubs f1, f1, f0
/* 8023A4D4  EC 0C 02 F2 */	fmuls f0, f12, f11
/* 8023A4D8  EC EC 02 32 */	fmuls f7, f12, f8
/* 8023A4DC  EC 89 02 32 */	fmuls f4, f9, f8
/* 8023A4E0  ED 03 10 28 */	fsubs f8, f3, f2
/* 8023A4E4  EC AD 50 2A */	fadds f5, f13, f10
/* 8023A4E8  EC 01 00 28 */	fsubs f0, f1, f0
/* 8023A4EC  D1 01 00 08 */	stfs f8, 8(r1)
/* 8023A4F0  EC 67 30 2A */	fadds f3, f7, f6
/* 8023A4F4  EC 5E 02 F2 */	fmuls f2, f30, f11
/* 8023A4F8  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8023A4FC  EC 85 20 28 */	fsubs f4, f5, f4
/* 8023A500  EC 43 10 28 */	fsubs f2, f3, f2
/* 8023A504  D0 81 00 10 */	stfs f4, 0x10(r1)
/* 8023A508  D0 41 00 0C */	stfs f2, 0xc(r1)
/* 8023A50C  D1 1F 00 00 */	stfs f8, 0(r31)
/* 8023A510  D0 5F 00 04 */	stfs f2, 4(r31)
/* 8023A514  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8023A518  E3 E1 00 48 */	psq_l f31, 72(r1), 0, qr0
/* 8023A51C  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8023A520  E3 C1 00 38 */	psq_l f30, 56(r1), 0, qr0
/* 8023A524  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 8023A528  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8023A52C  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8023A530  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8023A534  7C 08 03 A6 */	mtlr r0
/* 8023A538  38 21 00 50 */	addi r1, r1, 0x50
/* 8023A53C  4E 80 00 20 */	blr
/* 8023A540  C0 E4 00 00 */	lfs f7, 0(r4)
/* 8023A544  C0 C5 00 00 */	lfs f6, 0(r5)
/* 8023A548  C0 A4 00 04 */	lfs f5, 4(r4)
/* 8023A54C  C0 85 00 04 */	lfs f4, 4(r5)
/* 8023A550  EC 67 01 B2 */	fmuls f3, f7, f6
/* 8023A554  C1 44 00 08 */	lfs f10, 8(r4)
/* 8023A558  EC 05 01 B2 */	fmuls f0, f5, f6
/* 8023A55C  EC 45 01 32 */	fmuls f2, f5, f4
/* 8023A560  C1 25 00 08 */	lfs f9, 8(r5)
/* 8023A564  EC 27 01 32 */	fmuls f1, f7, f4
/* 8023A568  ED 0A 02 72 */	fmuls f8, f10, f9
/* 8023A56C  C1 64 00 0C */	lfs f11, 0xc(r4)
/* 8023A570  EC 43 10 2A */	fadds f2, f3, f2
/* 8023A574  ED 81 00 28 */	fsubs f12, f1, f0
/* 8023A578  EC 27 02 72 */	fmuls f1, f7, f9
/* 8023A57C  EC 68 10 2A */	fadds f3, f8, f2
/* 8023A580  EC 4A 01 B2 */	fmuls f2, f10, f6
/* 8023A584  EC 0B 02 72 */	fmuls f0, f11, f9
/* 8023A588  FC 60 18 50 */	fneg f3, f3
/* 8023A58C  EC E2 08 28 */	fsubs f7, f2, f1
/* 8023A590  D0 66 00 0C */	stfs f3, 0xc(r6)
/* 8023A594  EC 0C 00 2A */	fadds f0, f12, f0
/* 8023A598  EC 2B 01 32 */	fmuls f1, f11, f4
/* 8023A59C  D0 06 00 08 */	stfs f0, 8(r6)
/* 8023A5A0  EC 65 02 72 */	fmuls f3, f5, f9
/* 8023A5A4  EC 4A 01 32 */	fmuls f2, f10, f4
/* 8023A5A8  EC 27 08 2A */	fadds f1, f7, f1
/* 8023A5AC  EC 0B 01 B2 */	fmuls f0, f11, f6
/* 8023A5B0  EC 43 10 28 */	fsubs f2, f3, f2
/* 8023A5B4  D0 26 00 04 */	stfs f1, 4(r6)
/* 8023A5B8  EC 02 00 2A */	fadds f0, f2, f0
/* 8023A5BC  D0 06 00 00 */	stfs f0, 0(r6)
/* 8023A5C0  4E 80 00 20 */	blr
/* 8023A5C4  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8023A5C8  7C 08 02 A6 */	mflr r0
/* 8023A5CC  90 01 00 54 */	stw r0, 0x54(r1)
/* 8023A5D0  DB E1 00 40 */	stfd f31, 0x40(r1)
/* 8023A5D4  F3 E1 00 48 */	psq_st f31, 72(r1), 0, qr0
/* 8023A5D8  DB C1 00 30 */	stfd f30, 0x30(r1)
/* 8023A5DC  F3 C1 00 38 */	psq_st f30, 56(r1), 0, qr0
/* 8023A5E0  DB A1 00 20 */	stfd f29, 0x20(r1)
/* 8023A5E4  F3 A1 00 28 */	psq_st f29, 40(r1), 0, qr0
/* 8023A5E8  FF E0 08 90 */	fmr f31, f1
/* 8023A5EC  C0 63 00 00 */	lfs f3, 0(r3)
/* 8023A5F0  C0 44 00 00 */	lfs f2, 0(r4)
/* 8023A5F4  C0 23 00 04 */	lfs f1, 4(r3)
/* 8023A5F8  C0 04 00 04 */	lfs f0, 4(r4)
/* 8023A5FC  EC 43 00 B2 */	fmuls f2, f3, f2
/* 8023A600  C0 63 00 08 */	lfs f3, 8(r3)
/* 8023A604  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023A608  C0 24 00 08 */	lfs f1, 8(r4)
/* 8023A60C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023A610  EC 63 00 72 */	fmuls f3, f3, f1
/* 8023A614  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 8023A618  EC 22 00 2A */	fadds f1, f2, f0
/* 8023A61C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023A620  7C BE 2B 78 */	mr r30, r5
/* 8023A624  C0 84 00 0C */	lfs f4, 0xc(r4)
/* 8023A628  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023A62C  EC 23 08 2A */	fadds f1, f3, f1
/* 8023A630  EC 45 01 32 */	fmuls f2, f5, f4
/* 8023A634  C0 02 A0 50 */	lfs f0, -0x5fb0(r2)
/* 8023A638  93 81 00 10 */	stw r28, 0x10(r1)
/* 8023A63C  7C 7C 1B 78 */	mr r28, r3
/* 8023A640  7C 9D 23 78 */	mr r29, r4
/* 8023A644  EC 22 08 2A */	fadds f1, f2, f1
/* 8023A648  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A64C  40 81 00 0C */	ble 0xc
/* 8023A650  FC 20 00 90 */	fmr f1, f0
/* 8023A654  48 00 00 14 */	b 0x14
/* 8023A658  C0 02 A0 54 */	lfs f0, -0x5fac(r2)
/* 8023A65C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A660  40 80 00 08 */	bge 0x8
/* 8023A664  FC 20 00 90 */	fmr f1, f0
/* 8023A668  C8 02 A0 58 */	lfd f0, -0x5fa8(r2)
/* 8023A66C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A670  40 80 00 10 */	bge 0x10
/* 8023A674  FC 20 08 50 */	fneg f1, f1
/* 8023A678  3B E0 00 01 */	li r31, 1
/* 8023A67C  48 00 00 08 */	b 0x8
/* 8023A680  3B E0 00 00 */	li r31, 0
/* 8023A684  4B FF 52 3D */	bl -0xadc4
/* 8023A688  FF C0 08 90 */	fmr f30, f1
/* 8023A68C  4B FF 51 D5 */	bl -0xae2c
/* 8023A690  C0 02 A0 48 */	lfs f0, -0x5fb8(r2)
/* 8023A694  FC 40 08 90 */	fmr f2, f1
/* 8023A698  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A69C  40 81 00 08 */	ble 0x8
/* 8023A6A0  48 00 00 08 */	b 0x8
/* 8023A6A4  FC 40 08 50 */	fneg f2, f1
/* 8023A6A8  C0 02 A0 60 */	lfs f0, -0x5fa0(r2)
/* 8023A6AC  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8023A6B0  40 80 00 10 */	bge 0x10
/* 8023A6B4  C0 02 A0 50 */	lfs f0, -0x5fb0(r2)
/* 8023A6B8  EF C0 F8 28 */	fsubs f30, f0, f31
/* 8023A6BC  48 00 00 28 */	b 0x28
/* 8023A6C0  C0 02 A0 50 */	lfs f0, -0x5fb0(r2)
/* 8023A6C4  EF BF 07 B2 */	fmuls f29, f31, f30
/* 8023A6C8  EF E0 08 24 */	fdivs f31, f0, f1
/* 8023A6CC  EC 3E E8 28 */	fsubs f1, f30, f29
/* 8023A6D0  4B FF 51 91 */	bl -0xae70
/* 8023A6D4  EF DF 00 72 */	fmuls f30, f31, f1
/* 8023A6D8  FC 20 E8 90 */	fmr f1, f29
/* 8023A6DC  4B FF 51 85 */	bl -0xae7c
/* 8023A6E0  EF FF 00 72 */	fmuls f31, f31, f1
/* 8023A6E4  2C 1F 00 00 */	cmpwi r31, 0
/* 8023A6E8  41 82 00 08 */	beq 0x8
/* 8023A6EC  FF E0 F8 50 */	fneg f31, f31
/* 8023A6F0  C0 1C 00 00 */	lfs f0, 0(r28)
/* 8023A6F4  C0 5D 00 00 */	lfs f2, 0(r29)
/* 8023A6F8  C0 3C 00 04 */	lfs f1, 4(r28)
/* 8023A6FC  EC FE 00 32 */	fmuls f7, f30, f0
/* 8023A700  C0 1D 00 04 */	lfs f0, 4(r29)
/* 8023A704  EC DF 00 B2 */	fmuls f6, f31, f2
/* 8023A708  C0 7C 00 08 */	lfs f3, 8(r28)
/* 8023A70C  EC BE 00 72 */	fmuls f5, f30, f1
/* 8023A710  EC 9F 00 32 */	fmuls f4, f31, f0
/* 8023A714  C0 5D 00 08 */	lfs f2, 8(r29)
/* 8023A718  EC 7E 00 F2 */	fmuls f3, f30, f3
/* 8023A71C  C0 3C 00 0C */	lfs f1, 0xc(r28)
/* 8023A720  EC C7 30 2A */	fadds f6, f7, f6
/* 8023A724  C0 1D 00 0C */	lfs f0, 0xc(r29)
/* 8023A728  EC 5F 00 B2 */	fmuls f2, f31, f2
/* 8023A72C  D0 DE 00 00 */	stfs f6, 0(r30)
/* 8023A730  EC 85 20 2A */	fadds f4, f5, f4
/* 8023A734  EC 3E 00 72 */	fmuls f1, f30, f1
/* 8023A738  EC 1F 00 32 */	fmuls f0, f31, f0
/* 8023A73C  D0 9E 00 04 */	stfs f4, 4(r30)
/* 8023A740  EC 43 10 2A */	fadds f2, f3, f2
/* 8023A744  EC 01 00 2A */	fadds f0, f1, f0
/* 8023A748  D0 5E 00 08 */	stfs f2, 8(r30)
/* 8023A74C  D0 1E 00 0C */	stfs f0, 0xc(r30)
/* 8023A750  E3 E1 00 48 */	psq_l f31, 72(r1), 0, qr0
/* 8023A754  CB E1 00 40 */	lfd f31, 0x40(r1)
/* 8023A758  E3 C1 00 38 */	psq_l f30, 56(r1), 0, qr0
/* 8023A75C  CB C1 00 30 */	lfd f30, 0x30(r1)
/* 8023A760  E3 A1 00 28 */	psq_l f29, 40(r1), 0, qr0
/* 8023A764  CB A1 00 20 */	lfd f29, 0x20(r1)
/* 8023A768  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023A76C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023A770  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023A774  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8023A778  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8023A77C  7C 08 03 A6 */	mtlr r0
/* 8023A780  38 21 00 50 */	addi r1, r1, 0x50
/* 8023A784  4E 80 00 20 */	blr
/* 8023A788  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8023A78C  7C 08 02 A6 */	mflr r0
/* 8023A790  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023A794  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8023A798  7C BF 2B 78 */	mr r31, r5
/* 8023A79C  93 C1 00 28 */	stw r30, 0x28(r1)
/* 8023A7A0  7C 9E 23 78 */	mr r30, r4
/* 8023A7A4  93 A1 00 24 */	stw r29, 0x24(r1)
/* 8023A7A8  7C 7D 1B 78 */	mr r29, r3
/* 8023A7AC  38 61 00 08 */	addi r3, r1, 8
/* 8023A7B0  4B FD A1 B9 */	bl -0x25e48
/* 8023A7B4  C0 7E 00 00 */	lfs f3, 0(r30)
/* 8023A7B8  C0 5F 00 00 */	lfs f2, 0(r31)
/* 8023A7BC  C0 3E 00 04 */	lfs f1, 4(r30)
/* 8023A7C0  C0 1F 00 04 */	lfs f0, 4(r31)
/* 8023A7C4  EC 63 00 B2 */	fmuls f3, f3, f2
/* 8023A7C8  C0 9E 00 08 */	lfs f4, 8(r30)
/* 8023A7CC  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023A7D0  C0 3F 00 08 */	lfs f1, 8(r31)
/* 8023A7D4  C0 42 A0 50 */	lfs f2, -0x5fb0(r2)
/* 8023A7D8  EC 84 00 72 */	fmuls f4, f4, f1
/* 8023A7DC  C0 22 A0 44 */	lfs f1, -0x5fbc(r2)
/* 8023A7E0  EC 63 00 2A */	fadds f3, f3, f0
/* 8023A7E4  C0 02 A0 48 */	lfs f0, -0x5fb8(r2)
/* 8023A7E8  EC 64 18 2A */	fadds f3, f4, f3
/* 8023A7EC  EC 42 18 2A */	fadds f2, f2, f3
/* 8023A7F0  EC 21 00 B2 */	fmuls f1, f1, f2
/* 8023A7F4  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A7F8  40 80 00 08 */	bge 0x8
/* 8023A7FC  FC 20 00 90 */	fmr f1, f0
/* 8023A800  4B FF 50 0D */	bl -0xaff4
/* 8023A804  C0 02 A0 4C */	lfs f0, -0x5fb4(r2)
/* 8023A808  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023A80C  4C 40 13 82 */	cror 2, 0, 2
/* 8023A810  40 82 00 20 */	bne 0x20
/* 8023A814  C0 02 A0 48 */	lfs f0, -0x5fb8(r2)
/* 8023A818  C0 22 A0 50 */	lfs f1, -0x5fb0(r2)
/* 8023A81C  D0 3D 00 0C */	stfs f1, 0xc(r29)
/* 8023A820  D0 1D 00 00 */	stfs f0, 0(r29)
/* 8023A824  D0 1D 00 04 */	stfs f0, 4(r29)
/* 8023A828  D0 1D 00 08 */	stfs f0, 8(r29)
/* 8023A82C  48 00 00 3C */	b 0x3c
/* 8023A830  C0 42 A0 50 */	lfs f2, -0x5fb0(r2)
/* 8023A834  C0 02 A0 40 */	lfs f0, -0x5fc0(r2)
/* 8023A838  EC 82 08 24 */	fdivs f4, f2, f1
/* 8023A83C  C0 61 00 10 */	lfs f3, 0x10(r1)
/* 8023A840  C0 41 00 0C */	lfs f2, 0xc(r1)
/* 8023A844  EC 00 00 72 */	fmuls f0, f0, f1
/* 8023A848  EC 63 01 32 */	fmuls f3, f3, f4
/* 8023A84C  D0 1D 00 0C */	stfs f0, 0xc(r29)
/* 8023A850  EC 22 01 32 */	fmuls f1, f2, f4
/* 8023A854  C0 01 00 08 */	lfs f0, 8(r1)
/* 8023A858  EC 00 01 32 */	fmuls f0, f0, f4
/* 8023A85C  D0 3D 00 04 */	stfs f1, 4(r29)
/* 8023A860  D0 1D 00 00 */	stfs f0, 0(r29)
/* 8023A864  D0 7D 00 08 */	stfs f3, 8(r29)
/* 8023A868  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8023A86C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8023A870  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 8023A874  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 8023A878  7C 08 03 A6 */	mtlr r0
/* 8023A87C  38 21 00 30 */	addi r1, r1, 0x30
/* 8023A880  4E 80 00 20 */	blr
/* 8023A884  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023A888  7C 08 02 A6 */	mflr r0
/* 8023A88C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023A890  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023A894  7C 7F 1B 78 */	mr r31, r3
/* 8023A898  80 0D A2 F8 */	lwz r0, -0x5d08(r13)
/* 8023A89C  2C 00 00 00 */	cmpwi r0, 0
/* 8023A8A0  40 82 00 34 */	bne 0x34
/* 8023A8A4  2C 03 00 00 */	cmpwi r3, 0
/* 8023A8A8  40 82 00 08 */	bne 0x8
/* 8023A8AC  83 ED A2 A0 */	lwz r31, -0x5d60(r13)
/* 8023A8B0  7F E4 FB 78 */	mr r4, r31
/* 8023A8B4  38 60 00 14 */	li r3, 0x14
/* 8023A8B8  38 A0 00 04 */	li r5, 4
/* 8023A8BC  4B FE F5 25 */	bl -0x10adc
/* 8023A8C0  2C 03 00 00 */	cmpwi r3, 0
/* 8023A8C4  41 82 00 0C */	beq 0xc
/* 8023A8C8  7F E4 FB 78 */	mr r4, r31
/* 8023A8CC  48 00 03 0D */	bl 0x30c
/* 8023A8D0  90 6D A2 F8 */	stw r3, -0x5d08(r13)
/* 8023A8D4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023A8D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023A8DC  80 6D A2 F8 */	lwz r3, -0x5d08(r13)
/* 8023A8E0  7C 08 03 A6 */	mtlr r0
/* 8023A8E4  38 21 00 10 */	addi r1, r1, 0x10
/* 8023A8E8  4E 80 00 20 */	blr
/* 8023A8EC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8023A8F0  7C 08 02 A6 */	mflr r0
/* 8023A8F4  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023A8F8  BF 21 00 14 */	stmw r25, 0x14(r1)
/* 8023A8FC  7C 9F 23 78 */	mr r31, r4
/* 8023A900  7C A4 2B 78 */	mr r4, r5
/* 8023A904  7C C5 33 78 */	mr r5, r6
/* 8023A908  7C 7E 1B 78 */	mr r30, r3
/* 8023A90C  7C E6 3B 78 */	mr r6, r7
/* 8023A910  81 1F 00 04 */	lwz r8, 4(r31)
/* 8023A914  38 08 FF FF */	addi r0, r8, -1
/* 8023A918  90 03 00 04 */	stw r0, 4(r3)
/* 8023A91C  80 63 00 10 */	lwz r3, 0x10(r3)
/* 8023A920  4B F6 3F 61 */	bl -0x9c0a0
/* 8023A924  7F E3 FB 78 */	mr r3, r31
/* 8023A928  4B F7 CA E9 */	bl -0x83518
/* 8023A92C  7F E3 FB 78 */	mr r3, r31
/* 8023A930  38 80 00 00 */	li r4, 0
/* 8023A934  4B F7 CB F1 */	bl -0x83410
/* 8023A938  80 83 00 00 */	lwz r4, 0(r3)
/* 8023A93C  38 A0 60 00 */	li r5, 0x6000
/* 8023A940  80 DE 00 10 */	lwz r6, 0x10(r30)
/* 8023A944  80 84 00 08 */	lwz r4, 8(r4)
/* 8023A948  38 66 00 A0 */	addi r3, r6, 0xa0
/* 8023A94C  4B DC B5 E9 */	bl -0x234a18
/* 8023A950  3B 20 00 00 */	li r25, 0
/* 8023A954  3B 60 00 00 */	li r27, 0
/* 8023A958  3B 40 00 00 */	li r26, 0
/* 8023A95C  3B 80 00 03 */	li r28, 3
/* 8023A960  3B A0 00 02 */	li r29, 2
/* 8023A964  48 00 00 5C */	b 0x5c
/* 8023A968  7F E3 FB 78 */	mr r3, r31
/* 8023A96C  38 99 00 01 */	addi r4, r25, 1
/* 8023A970  4B F7 CB B5 */	bl -0x8344c
/* 8023A974  2C 03 00 00 */	cmpwi r3, 0
/* 8023A978  41 82 00 3C */	beq 0x3c
/* 8023A97C  80 1E 00 10 */	lwz r0, 0x10(r30)
/* 8023A980  38 A0 12 00 */	li r5, 0x1200
/* 8023A984  80 63 00 00 */	lwz r3, 0(r3)
/* 8023A988  7C C0 DA 14 */	add r6, r0, r27
/* 8023A98C  80 83 00 08 */	lwz r4, 8(r3)
/* 8023A990  38 66 60 A0 */	addi r3, r6, 0x60a0
/* 8023A994  4B DC B5 A1 */	bl -0x234a60
/* 8023A998  80 BE 00 10 */	lwz r5, 0x10(r30)
/* 8023A99C  7F 83 D0 30 */	slw r3, r28, r26
/* 8023A9A0  7F A0 D0 30 */	slw r0, r29, r26
/* 8023A9A4  A0 85 00 08 */	lhz r4, 8(r5)
/* 8023A9A8  7C 83 18 78 */	andc r3, r4, r3
/* 8023A9AC  7C 60 03 78 */	or r0, r3, r0
/* 8023A9B0  B0 05 00 08 */	sth r0, 8(r5)
/* 8023A9B4  3B 7B 12 00 */	addi r27, r27, 0x1200
/* 8023A9B8  3B 5A 00 02 */	addi r26, r26, 2
/* 8023A9BC  3B 39 00 01 */	addi r25, r25, 1
/* 8023A9C0  80 1E 00 04 */	lwz r0, 4(r30)
/* 8023A9C4  7C 19 00 40 */	cmplw r25, r0
/* 8023A9C8  41 80 FF A0 */	blt -0x60
/* 8023A9CC  28 00 00 08 */	cmplwi r0, 8
/* 8023A9D0  40 80 00 20 */	bge 0x20
/* 8023A9D4  80 BE 00 10 */	lwz r5, 0x10(r30)
/* 8023A9D8  54 00 08 3C */	slwi r0, r0, 1
/* 8023A9DC  38 60 00 03 */	li r3, 3
/* 8023A9E0  A0 85 00 08 */	lhz r4, 8(r5)
/* 8023A9E4  7C 60 00 30 */	slw r0, r3, r0
/* 8023A9E8  7C 80 00 78 */	andc r0, r4, r0
/* 8023A9EC  B0 05 00 08 */	sth r0, 8(r5)
/* 8023A9F0  BB 21 00 14 */	lmw r25, 0x14(r1)
/* 8023A9F4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8023A9F8  7C 08 03 A6 */	mtlr r0
/* 8023A9FC  38 21 00 30 */	addi r1, r1, 0x30
/* 8023AA00  4E 80 00 20 */	blr
/* 8023AA04  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023AA08  7C 08 02 A6 */	mflr r0
/* 8023AA0C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023AA10  38 81 00 08 */	addi r4, r1, 8
/* 8023AA14  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023AA18  7C 7F 1B 78 */	mr r31, r3
/* 8023AA1C  80 6D 93 A8 */	lwz r3, -0x6c58(r13)
/* 8023AA20  4B F6 3D 51 */	bl -0x9c2b0
/* 8023AA24  2C 03 00 00 */	cmpwi r3, 0
/* 8023AA28  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8023AA2C  40 82 00 14 */	bne 0x14
/* 8023AA30  38 00 00 00 */	li r0, 0
/* 8023AA34  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AA38  38 60 00 01 */	li r3, 1
/* 8023AA3C  48 00 00 28 */	b 0x28
/* 8023AA40  2C 03 FF F4 */	cmpwi r3, -12
/* 8023AA44  40 82 00 14 */	bne 0x14
/* 8023AA48  38 00 00 00 */	li r0, 0
/* 8023AA4C  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AA50  38 60 00 00 */	li r3, 0
/* 8023AA54  48 00 00 10 */	b 0x10
/* 8023AA58  38 00 00 01 */	li r0, 1
/* 8023AA5C  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AA60  38 60 00 00 */	li r3, 0
/* 8023AA64  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023AA68  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023AA6C  7C 08 03 A6 */	mtlr r0
/* 8023AA70  38 21 00 20 */	addi r1, r1, 0x20
/* 8023AA74  4E 80 00 20 */	blr
/* 8023AA78  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 8023AA7C  7C 08 02 A6 */	mflr r0
/* 8023AA80  38 CD 93 A8 */	addi r6, r13, -27736
/* 8023AA84  90 01 00 54 */	stw r0, 0x54(r1)
/* 8023AA88  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 8023AA8C  7C 7F 1B 78 */	mr r31, r3
/* 8023AA90  80 66 00 04 */	lwz r3, 4(r6)
/* 8023AA94  4B F6 09 A9 */	bl -0x9f658
/* 8023AA98  2C 03 00 00 */	cmpwi r3, 0
/* 8023AA9C  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8023AAA0  41 82 00 1C */	beq 0x1c
/* 8023AAA4  2C 03 FF FA */	cmpwi r3, -6
/* 8023AAA8  41 82 00 14 */	beq 0x14
/* 8023AAAC  38 00 00 01 */	li r0, 1
/* 8023AAB0  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AAB4  38 60 00 00 */	li r3, 0
/* 8023AAB8  48 00 00 88 */	b 0x88
/* 8023AABC  7F E3 FB 78 */	mr r3, r31
/* 8023AAC0  38 80 00 01 */	li r4, 1
/* 8023AAC4  48 00 01 79 */	bl 0x178
/* 8023AAC8  88 1F 00 08 */	lbz r0, 8(r31)
/* 8023AACC  2C 00 00 00 */	cmpwi r0, 0
/* 8023AAD0  41 82 00 0C */	beq 0xc
/* 8023AAD4  38 60 00 00 */	li r3, 0
/* 8023AAD8  48 00 00 68 */	b 0x68
/* 8023AADC  38 61 00 08 */	addi r3, r1, 8
/* 8023AAE0  4B F6 39 2D */	bl -0x9c6d4
/* 8023AAE4  2C 03 00 00 */	cmpwi r3, 0
/* 8023AAE8  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8023AAEC  41 82 00 14 */	beq 0x14
/* 8023AAF0  38 00 00 01 */	li r0, 1
/* 8023AAF4  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AAF8  38 60 00 00 */	li r3, 0
/* 8023AAFC  48 00 00 44 */	b 0x44
/* 8023AB00  38 6D 93 A8 */	addi r3, r13, -27736
/* 8023AB04  38 81 00 08 */	addi r4, r1, 8
/* 8023AB08  80 63 00 04 */	lwz r3, 4(r3)
/* 8023AB0C  4B F6 13 DD */	bl -0x9ec24
/* 8023AB10  2C 03 00 00 */	cmpwi r3, 0
/* 8023AB14  90 7F 00 0C */	stw r3, 0xc(r31)
/* 8023AB18  41 82 00 1C */	beq 0x1c
/* 8023AB1C  2C 03 FF FA */	cmpwi r3, -6
/* 8023AB20  41 82 00 14 */	beq 0x14
/* 8023AB24  38 00 00 01 */	li r0, 1
/* 8023AB28  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AB2C  38 60 00 00 */	li r3, 0
/* 8023AB30  48 00 00 10 */	b 0x10
/* 8023AB34  38 00 00 00 */	li r0, 0
/* 8023AB38  98 1F 00 08 */	stb r0, 8(r31)
/* 8023AB3C  38 60 00 01 */	li r3, 1
/* 8023AB40  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8023AB44  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 8023AB48  7C 08 03 A6 */	mtlr r0
/* 8023AB4C  38 21 00 50 */	addi r1, r1, 0x50
/* 8023AB50  4E 80 00 20 */	blr
/* 8023AB54  38 80 00 00 */	li r4, 0
/* 8023AB58  48 00 00 E4 */	b 0xe4
/* 8023AB5C  88 63 00 08 */	lbz r3, 8(r3)
/* 8023AB60  4E 80 00 20 */	blr
/* 8023AB64  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AB68  7C 08 02 A6 */	mflr r0
/* 8023AB6C  2C 03 00 00 */	cmpwi r3, 0
/* 8023AB70  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AB74  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AB78  7C 9F 23 78 */	mr r31, r4
/* 8023AB7C  93 C1 00 08 */	stw r30, 8(r1)
/* 8023AB80  7C 7E 1B 78 */	mr r30, r3
/* 8023AB84  41 82 00 38 */	beq 0x38
/* 8023AB88  80 03 00 10 */	lwz r0, 0x10(r3)
/* 8023AB8C  3C 80 80 2A */	lis r4, 0x802a
/* 8023AB90  38 84 3D D0 */	addi r4, r4, 0x3dd0
/* 8023AB94  90 83 00 00 */	stw r4, 0(r3)
/* 8023AB98  2C 00 00 00 */	cmpwi r0, 0
/* 8023AB9C  41 82 00 10 */	beq 0x10
/* 8023ABA0  7C 03 03 78 */	mr r3, r0
/* 8023ABA4  38 80 00 00 */	li r4, 0
/* 8023ABA8  4B FE EF DD */	bl -0x11024
/* 8023ABAC  2C 1F 00 00 */	cmpwi r31, 0
/* 8023ABB0  40 81 00 0C */	ble 0xc
/* 8023ABB4  7F C3 F3 78 */	mr r3, r30
/* 8023ABB8  4B FE F2 5D */	bl -0x10da4
/* 8023ABBC  7F C3 F3 78 */	mr r3, r30
/* 8023ABC0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023ABC4  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023ABC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023ABCC  7C 08 03 A6 */	mtlr r0
/* 8023ABD0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023ABD4  4E 80 00 20 */	blr
/* 8023ABD8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023ABDC  7C 08 02 A6 */	mflr r0
/* 8023ABE0  3C C0 80 2A */	lis r6, 0x802a
/* 8023ABE4  7C 85 23 78 */	mr r5, r4
/* 8023ABE8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023ABEC  38 00 00 00 */	li r0, 0
/* 8023ABF0  38 C6 3D D0 */	addi r6, r6, 0x3dd0
/* 8023ABF4  38 E0 00 08 */	li r7, 8
/* 8023ABF8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023ABFC  7C 7F 1B 78 */	mr r31, r3
/* 8023AC00  38 80 00 20 */	li r4, 0x20
/* 8023AC04  90 C3 00 00 */	stw r6, 0(r3)
/* 8023AC08  3C C0 00 01 */	lis r6, 1
/* 8023AC0C  90 E3 00 04 */	stw r7, 4(r3)
/* 8023AC10  98 03 00 08 */	stb r0, 8(r3)
/* 8023AC14  90 03 00 0C */	stw r0, 0xc(r3)
/* 8023AC18  38 66 F0 A0 */	addi r3, r6, -3936
/* 8023AC1C  4B FE EB F9 */	bl -0x11408
/* 8023AC20  90 7F 00 10 */	stw r3, 0x10(r31)
/* 8023AC24  7F E3 FB 78 */	mr r3, r31
/* 8023AC28  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AC2C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AC30  7C 08 03 A6 */	mtlr r0
/* 8023AC34  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AC38  4E 80 00 20 */	blr
/* 8023AC3C  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 8023AC40  7C 08 02 A6 */	mflr r0
/* 8023AC44  38 A0 00 02 */	li r5, 2
/* 8023AC48  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 8023AC4C  54 80 10 3A */	slwi r0, r4, 2
/* 8023AC50  38 8D 93 A8 */	addi r4, r13, -27736
/* 8023AC54  93 E1 00 9C */	stw r31, 0x9c(r1)
/* 8023AC58  93 C1 00 98 */	stw r30, 0x98(r1)
/* 8023AC5C  7C 7E 1B 78 */	mr r30, r3
/* 8023AC60  7C 64 00 2E */	lwzx r3, r4, r0
/* 8023AC64  38 81 00 08 */	addi r4, r1, 8
/* 8023AC68  4B F6 1B 99 */	bl -0x9e468
/* 8023AC6C  2C 03 00 00 */	cmpwi r3, 0
/* 8023AC70  90 7E 00 0C */	stw r3, 0xc(r30)
/* 8023AC74  41 82 00 14 */	beq 0x14
/* 8023AC78  38 00 00 01 */	li r0, 1
/* 8023AC7C  98 1E 00 08 */	stb r0, 8(r30)
/* 8023AC80  38 60 00 00 */	li r3, 0
/* 8023AC84  48 00 00 74 */	b 0x74
/* 8023AC88  80 1E 00 04 */	lwz r0, 4(r30)
/* 8023AC8C  38 61 00 08 */	addi r3, r1, 8
/* 8023AC90  80 9E 00 10 */	lwz r4, 0x10(r30)
/* 8023AC94  1C A0 12 00 */	mulli r5, r0, 0x1200
/* 8023AC98  3B E5 60 A0 */	addi r31, r5, 0x60a0
/* 8023AC9C  7F E5 FB 78 */	mr r5, r31
/* 8023ACA0  4B F6 0B E5 */	bl -0x9f41c
/* 8023ACA4  7C 03 F8 40 */	cmplw r3, r31
/* 8023ACA8  90 7E 00 0C */	stw r3, 0xc(r30)
/* 8023ACAC  41 82 00 1C */	beq 0x1c
/* 8023ACB0  38 00 00 01 */	li r0, 1
/* 8023ACB4  98 1E 00 08 */	stb r0, 8(r30)
/* 8023ACB8  38 61 00 08 */	addi r3, r1, 8
/* 8023ACBC  4B F6 1D C5 */	bl -0x9e23c
/* 8023ACC0  38 60 00 00 */	li r3, 0
/* 8023ACC4  48 00 00 34 */	b 0x34
/* 8023ACC8  38 61 00 08 */	addi r3, r1, 8
/* 8023ACCC  4B F6 1D B5 */	bl -0x9e24c
/* 8023ACD0  2C 03 00 00 */	cmpwi r3, 0
/* 8023ACD4  90 7E 00 0C */	stw r3, 0xc(r30)
/* 8023ACD8  41 82 00 14 */	beq 0x14
/* 8023ACDC  38 00 00 01 */	li r0, 1
/* 8023ACE0  98 1E 00 08 */	stb r0, 8(r30)
/* 8023ACE4  38 60 00 00 */	li r3, 0
/* 8023ACE8  48 00 00 10 */	b 0x10
/* 8023ACEC  38 00 00 00 */	li r0, 0
/* 8023ACF0  98 1E 00 08 */	stb r0, 8(r30)
/* 8023ACF4  38 60 00 01 */	li r3, 1
/* 8023ACF8  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 8023ACFC  83 E1 00 9C */	lwz r31, 0x9c(r1)
/* 8023AD00  83 C1 00 98 */	lwz r30, 0x98(r1)
/* 8023AD04  7C 08 03 A6 */	mtlr r0
/* 8023AD08  38 21 00 A0 */	addi r1, r1, 0xa0
/* 8023AD0C  4E 80 00 20 */	blr
/* 8023AD10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AD14  7C 08 02 A6 */	mflr r0
/* 8023AD18  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AD1C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AD20  7C 7F 1B 78 */	mr r31, r3
/* 8023AD24  4B FD F3 CD */	bl -0x20c34
/* 8023AD28  3C 60 80 2A */	lis r3, 0x802a
/* 8023AD2C  38 80 00 00 */	li r4, 0
/* 8023AD30  38 63 3D E0 */	addi r3, r3, 0x3de0
/* 8023AD34  90 7F 00 00 */	stw r3, 0(r31)
/* 8023AD38  38 00 FF FF */	li r0, -1
/* 8023AD3C  80 AD A2 A0 */	lwz r5, -0x5d60(r13)
/* 8023AD40  7F E3 FB 78 */	mr r3, r31
/* 8023AD44  90 BF 00 10 */	stw r5, 0x10(r31)
/* 8023AD48  80 AD A3 04 */	lwz r5, -0x5cfc(r13)
/* 8023AD4C  90 BF 00 14 */	stw r5, 0x14(r31)
/* 8023AD50  80 AD A3 08 */	lwz r5, -0x5cf8(r13)
/* 8023AD54  90 BF 00 18 */	stw r5, 0x18(r31)
/* 8023AD58  80 AD A3 0C */	lwz r5, -0x5cf4(r13)
/* 8023AD5C  90 BF 00 1C */	stw r5, 0x1c(r31)
/* 8023AD60  90 9F 00 20 */	stw r4, 0x20(r31)
/* 8023AD64  90 9F 00 24 */	stw r4, 0x24(r31)
/* 8023AD68  90 1F 00 28 */	stw r0, 0x28(r31)
/* 8023AD6C  90 9F 00 2C */	stw r4, 0x2c(r31)
/* 8023AD70  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AD74  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AD78  7C 08 03 A6 */	mtlr r0
/* 8023AD7C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AD80  4E 80 00 20 */	blr
/* 8023AD84  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AD88  7C 08 02 A6 */	mflr r0
/* 8023AD8C  2C 03 00 00 */	cmpwi r3, 0
/* 8023AD90  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AD94  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AD98  7C 9F 23 78 */	mr r31, r4
/* 8023AD9C  93 C1 00 08 */	stw r30, 8(r1)
/* 8023ADA0  7C 7E 1B 78 */	mr r30, r3
/* 8023ADA4  41 82 00 1C */	beq 0x1c
/* 8023ADA8  38 80 00 00 */	li r4, 0
/* 8023ADAC  4B FD F3 99 */	bl -0x20c68
/* 8023ADB0  2C 1F 00 00 */	cmpwi r31, 0
/* 8023ADB4  40 81 00 0C */	ble 0xc
/* 8023ADB8  7F C3 F3 78 */	mr r3, r30
/* 8023ADBC  4B FE F0 59 */	bl -0x10fa8
/* 8023ADC0  7F C3 F3 78 */	mr r3, r30
/* 8023ADC4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023ADC8  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023ADCC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023ADD0  7C 08 03 A6 */	mtlr r0
/* 8023ADD4  38 21 00 10 */	addi r1, r1, 0x10
/* 8023ADD8  4E 80 00 20 */	blr
/* 8023ADDC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023ADE0  7C 08 02 A6 */	mflr r0
/* 8023ADE4  3D 80 80 2A */	lis r12, 0x802a
/* 8023ADE8  38 A0 FF FF */	li r5, -1
/* 8023ADEC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023ADF0  39 8C 3E 08 */	addi r12, r12, 0x3e08
/* 8023ADF4  38 C0 00 00 */	li r6, 0
/* 8023ADF8  38 00 00 01 */	li r0, 1
/* 8023ADFC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AE00  7C 7F 1B 78 */	mr r31, r3
/* 8023AE04  91 83 00 00 */	stw r12, 0(r3)
/* 8023AE08  90 83 00 04 */	stw r4, 4(r3)
/* 8023AE0C  90 C3 00 0C */	stw r6, 0xc(r3)
/* 8023AE10  90 A3 00 1C */	stw r5, 0x1c(r3)
/* 8023AE14  90 A3 00 18 */	stw r5, 0x18(r3)
/* 8023AE18  90 A3 00 14 */	stw r5, 0x14(r3)
/* 8023AE1C  90 A3 00 20 */	stw r5, 0x20(r3)
/* 8023AE20  90 C3 00 24 */	stw r6, 0x24(r3)
/* 8023AE24  90 03 00 28 */	stw r0, 0x28(r3)
/* 8023AE28  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8023AE2C  7D 89 03 A6 */	mtctr r12
/* 8023AE30  4E 80 04 21 */	bctrl
/* 8023AE34  7F E3 FB 78 */	mr r3, r31
/* 8023AE38  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AE3C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AE40  7C 08 03 A6 */	mtlr r0
/* 8023AE44  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AE48  4E 80 00 20 */	blr
/* 8023AE4C  80 63 00 24 */	lwz r3, 0x24(r3)
/* 8023AE50  81 83 00 00 */	lwz r12, 0(r3)
/* 8023AE54  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023AE58  7D 89 03 A6 */	mtctr r12
/* 8023AE5C  4E 80 04 20 */	bctr
/* 8023AE60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AE64  7C 08 02 A6 */	mflr r0
/* 8023AE68  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AE6C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AE70  7C 7F 1B 78 */	mr r31, r3
/* 8023AE74  81 83 00 00 */	lwz r12, 0(r3)
/* 8023AE78  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023AE7C  7D 89 03 A6 */	mtctr r12
/* 8023AE80  4E 80 04 21 */	bctrl
/* 8023AE84  81 9F 00 00 */	lwz r12, 0(r31)
/* 8023AE88  7F E3 FB 78 */	mr r3, r31
/* 8023AE8C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8023AE90  7D 89 03 A6 */	mtctr r12
/* 8023AE94  4E 80 04 21 */	bctrl
/* 8023AE98  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AE9C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AEA0  7C 08 03 A6 */	mtlr r0
/* 8023AEA4  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AEA8  4E 80 00 20 */	blr
/* 8023AEAC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AEB0  7C 08 02 A6 */	mflr r0
/* 8023AEB4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AEB8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AEBC  7C 7F 1B 78 */	mr r31, r3
/* 8023AEC0  81 83 00 00 */	lwz r12, 0(r3)
/* 8023AEC4  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8023AEC8  7D 89 03 A6 */	mtctr r12
/* 8023AECC  4E 80 04 21 */	bctrl
/* 8023AED0  81 9F 00 00 */	lwz r12, 0(r31)
/* 8023AED4  7F E3 FB 78 */	mr r3, r31
/* 8023AED8  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023AEDC  7D 89 03 A6 */	mtctr r12
/* 8023AEE0  4E 80 04 21 */	bctrl
/* 8023AEE4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AEE8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AEEC  7C 08 03 A6 */	mtlr r0
/* 8023AEF0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AEF4  4E 80 00 20 */	blr
/* 8023AEF8  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023AEFC  2C 03 00 00 */	cmpwi r3, 0
/* 8023AF00  4D 82 00 20 */	beqlr
/* 8023AF04  81 83 00 00 */	lwz r12, 0(r3)
/* 8023AF08  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023AF0C  7D 89 03 A6 */	mtctr r12
/* 8023AF10  4E 80 04 20 */	bctr
/* 8023AF14  4E 80 00 20 */	blr
/* 8023AF18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AF1C  7C 08 02 A6 */	mflr r0
/* 8023AF20  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AF24  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AF28  3B E0 00 00 */	li r31, 0
/* 8023AF2C  93 C1 00 08 */	stw r30, 8(r1)
/* 8023AF30  7C 7E 1B 78 */	mr r30, r3
/* 8023AF34  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8023AF38  2C 00 FF FF */	cmpwi r0, -1
/* 8023AF3C  40 82 00 2C */	bne 0x2c
/* 8023AF40  80 63 00 24 */	lwz r3, 0x24(r3)
/* 8023AF44  81 83 00 00 */	lwz r12, 0(r3)
/* 8023AF48  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8023AF4C  7D 89 03 A6 */	mtctr r12
/* 8023AF50  4E 80 04 21 */	bctrl
/* 8023AF54  2C 03 00 00 */	cmpwi r3, 0
/* 8023AF58  41 82 00 10 */	beq 0x10
/* 8023AF5C  38 00 00 03 */	li r0, 3
/* 8023AF60  90 1E 00 20 */	stw r0, 0x20(r30)
/* 8023AF64  3B E0 00 01 */	li r31, 1
/* 8023AF68  7F E3 FB 78 */	mr r3, r31
/* 8023AF6C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AF70  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023AF74  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AF78  7C 08 03 A6 */	mtlr r0
/* 8023AF7C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AF80  4E 80 00 20 */	blr
/* 8023AF84  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023AF88  7C 08 02 A6 */	mflr r0
/* 8023AF8C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023AF90  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023AF94  7C 9F 23 78 */	mr r31, r4
/* 8023AF98  93 C1 00 08 */	stw r30, 8(r1)
/* 8023AF9C  7C 7E 1B 78 */	mr r30, r3
/* 8023AFA0  48 00 00 10 */	b 0x10
/* 8023AFA4  7F C3 F3 78 */	mr r3, r30
/* 8023AFA8  38 80 00 01 */	li r4, 1
/* 8023AFAC  48 00 03 01 */	bl 0x300
/* 8023AFB0  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 8023AFB4  2C 00 00 00 */	cmpwi r0, 0
/* 8023AFB8  40 82 FF EC */	bne -0x14
/* 8023AFBC  7F C3 F3 78 */	mr r3, r30
/* 8023AFC0  7F E4 FB 78 */	mr r4, r31
/* 8023AFC4  48 00 00 1D */	bl 0x1c
/* 8023AFC8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023AFCC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023AFD0  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023AFD4  7C 08 03 A6 */	mtlr r0
/* 8023AFD8  38 21 00 10 */	addi r1, r1, 0x10
/* 8023AFDC  4E 80 00 20 */	blr
/* 8023AFE0  90 83 00 14 */	stw r4, 0x14(r3)
/* 8023AFE4  48 00 00 80 */	b 0x80
/* 8023AFE8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023AFEC  7C 08 02 A6 */	mflr r0
/* 8023AFF0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023AFF4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023AFF8  3B E0 00 00 */	li r31, 0
/* 8023AFFC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B000  7C 9E 23 78 */	mr r30, r4
/* 8023B004  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B008  7C 7D 1B 78 */	mr r29, r3
/* 8023B00C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8023B010  2C 00 FF FF */	cmpwi r0, -1
/* 8023B014  40 82 00 30 */	bne 0x30
/* 8023B018  80 63 00 24 */	lwz r3, 0x24(r3)
/* 8023B01C  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B020  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8023B024  7D 89 03 A6 */	mtctr r12
/* 8023B028  4E 80 04 21 */	bctrl
/* 8023B02C  2C 03 00 00 */	cmpwi r3, 0
/* 8023B030  41 82 00 14 */	beq 0x14
/* 8023B034  38 00 00 01 */	li r0, 1
/* 8023B038  93 DD 00 14 */	stw r30, 0x14(r29)
/* 8023B03C  3B E0 00 01 */	li r31, 1
/* 8023B040  90 1D 00 20 */	stw r0, 0x20(r29)
/* 8023B044  7F E3 FB 78 */	mr r3, r31
/* 8023B048  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B04C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B050  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B054  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B058  7C 08 03 A6 */	mtlr r0
/* 8023B05C  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B060  4E 80 00 20 */	blr
/* 8023B064  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B068  7C 08 02 A6 */	mflr r0
/* 8023B06C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B070  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B074  3B E0 00 00 */	li r31, 0
/* 8023B078  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B07C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B080  7C 7D 1B 78 */	mr r29, r3
/* 8023B084  80 83 00 0C */	lwz r4, 0xc(r3)
/* 8023B088  2C 04 00 00 */	cmpwi r4, 0
/* 8023B08C  41 82 00 08 */	beq 0x8
/* 8023B090  83 E4 00 20 */	lwz r31, 0x20(r4)
/* 8023B094  2C 04 00 00 */	cmpwi r4, 0
/* 8023B098  41 82 00 14 */	beq 0x14
/* 8023B09C  7F A3 EB 78 */	mr r3, r29
/* 8023B0A0  48 00 03 51 */	bl 0x350
/* 8023B0A4  38 00 00 00 */	li r0, 0
/* 8023B0A8  90 1D 00 0C */	stw r0, 0xc(r29)
/* 8023B0AC  83 DD 00 14 */	lwz r30, 0x14(r29)
/* 8023B0B0  7F A3 EB 78 */	mr r3, r29
/* 8023B0B4  48 00 08 5D */	bl 0x85c
/* 8023B0B8  7F A3 EB 78 */	mr r3, r29
/* 8023B0BC  7F C4 F3 78 */	mr r4, r30
/* 8023B0C0  7F E5 FB 78 */	mr r5, r31
/* 8023B0C4  48 00 00 21 */	bl 0x20
/* 8023B0C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B0CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B0D0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B0D4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B0D8  7C 08 03 A6 */	mtlr r0
/* 8023B0DC  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B0E0  4E 80 00 20 */	blr
/* 8023B0E4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8023B0E8  7C 08 02 A6 */	mflr r0
/* 8023B0EC  2C 05 00 00 */	cmpwi r5, 0
/* 8023B0F0  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023B0F4  BE C1 00 08 */	stmw r22, 8(r1)
/* 8023B0F8  7C 7D 1B 78 */	mr r29, r3
/* 8023B0FC  7C 9E 23 78 */	mr r30, r4
/* 8023B100  7C BF 2B 78 */	mr r31, r5
/* 8023B104  41 82 00 14 */	beq 0x14
/* 8023B108  83 45 00 14 */	lwz r26, 0x14(r5)
/* 8023B10C  83 25 00 18 */	lwz r25, 0x18(r5)
/* 8023B110  83 05 00 1C */	lwz r24, 0x1c(r5)
/* 8023B114  48 00 00 14 */	b 0x14
/* 8023B118  80 8D A3 60 */	lwz r4, -0x5ca0(r13)
/* 8023B11C  83 44 00 18 */	lwz r26, 0x18(r4)
/* 8023B120  83 24 00 1C */	lwz r25, 0x1c(r4)
/* 8023B124  83 04 00 20 */	lwz r24, 0x20(r4)
/* 8023B128  80 03 00 28 */	lwz r0, 0x28(r3)
/* 8023B12C  2C 00 00 00 */	cmpwi r0, 0
/* 8023B130  40 82 00 0C */	bne 0xc
/* 8023B134  7F 5C D3 78 */	mr r28, r26
/* 8023B138  48 00 00 08 */	b 0x8
/* 8023B13C  7F 3C CB 78 */	mr r28, r25
/* 8023B140  A0 1C 00 1C */	lhz r0, 0x1c(r28)
/* 8023B144  54 1B 07 FF */	clrlwi. r27, r0, 0x1f
/* 8023B148  41 82 00 10 */	beq 0x10
/* 8023B14C  A0 1C 00 1C */	lhz r0, 0x1c(r28)
/* 8023B150  54 00 04 3C */	rlwinm r0, r0, 0, 0x10, 0x1e
/* 8023B154  B0 1C 00 1C */	sth r0, 0x1c(r28)
/* 8023B158  A0 AD A3 00 */	lhz r5, -0x5d00(r13)
/* 8023B15C  7F 84 E3 78 */	mr r4, r28
/* 8023B160  38 60 FF FF */	li r3, -1
/* 8023B164  4B FE B9 65 */	bl -0x1469c
/* 8023B168  7C 1C C8 40 */	cmplw r28, r25
/* 8023B16C  7C 77 1B 78 */	mr r23, r3
/* 8023B170  3A C0 00 00 */	li r22, 0
/* 8023B174  40 82 00 20 */	bne 0x20
/* 8023B178  A0 AD A3 00 */	lhz r5, -0x5d00(r13)
/* 8023B17C  7F 44 D3 78 */	mr r4, r26
/* 8023B180  38 60 FF FF */	li r3, -1
/* 8023B184  4B FE B9 45 */	bl -0x146bc
/* 8023B188  7C 79 1B 78 */	mr r25, r3
/* 8023B18C  7E FA BB 78 */	mr r26, r23
/* 8023B190  48 00 00 1C */	b 0x1c
/* 8023B194  A0 AD A3 00 */	lhz r5, -0x5d00(r13)
/* 8023B198  7F 24 CB 78 */	mr r4, r25
/* 8023B19C  38 60 FF FF */	li r3, -1
/* 8023B1A0  4B FE B9 29 */	bl -0x146d8
/* 8023B1A4  7C 7A 1B 78 */	mr r26, r3
/* 8023B1A8  7E F9 BB 78 */	mr r25, r23
/* 8023B1AC  2C 18 00 00 */	cmpwi r24, 0
/* 8023B1B0  41 82 00 18 */	beq 0x18
/* 8023B1B4  A0 AD A3 00 */	lhz r5, -0x5d00(r13)
/* 8023B1B8  7F 04 C3 78 */	mr r4, r24
/* 8023B1BC  38 60 FF FF */	li r3, -1
/* 8023B1C0  4B FE B9 09 */	bl -0x146f8
/* 8023B1C4  7C 76 1B 78 */	mr r22, r3
/* 8023B1C8  2C 1B 00 00 */	cmpwi r27, 0
/* 8023B1CC  93 2D A3 04 */	stw r25, -0x5cfc(r13)
/* 8023B1D0  93 4D A3 08 */	stw r26, -0x5cf8(r13)
/* 8023B1D4  92 CD A3 0C */	stw r22, -0x5cf4(r13)
/* 8023B1D8  41 82 00 10 */	beq 0x10
/* 8023B1DC  A0 1C 00 1C */	lhz r0, 0x1c(r28)
/* 8023B1E0  60 00 00 01 */	ori r0, r0, 1
/* 8023B1E4  B0 1C 00 1C */	sth r0, 0x1c(r28)
/* 8023B1E8  7E E3 BB 78 */	mr r3, r23
/* 8023B1EC  4B FE EB 89 */	bl -0x11478
/* 8023B1F0  80 7D 00 04 */	lwz r3, 4(r29)
/* 8023B1F4  7F C4 F3 78 */	mr r4, r30
/* 8023B1F8  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B1FC  81 8C 00 08 */	lwz r12, 8(r12)
/* 8023B200  7D 89 03 A6 */	mtctr r12
/* 8023B204  4E 80 04 21 */	bctrl
/* 8023B208  2C 1F 00 00 */	cmpwi r31, 0
/* 8023B20C  41 82 00 08 */	beq 0x8
/* 8023B210  90 7F 00 24 */	stw r3, 0x24(r31)
/* 8023B214  90 7D 00 0C */	stw r3, 0xc(r29)
/* 8023B218  93 C3 00 28 */	stw r30, 0x28(r3)
/* 8023B21C  93 E3 00 20 */	stw r31, 0x20(r3)
/* 8023B220  93 A3 00 2C */	stw r29, 0x2c(r3)
/* 8023B224  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B228  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 8023B22C  7D 89 03 A6 */	mtctr r12
/* 8023B230  4E 80 04 21 */	bctrl
/* 8023B234  BA C1 00 08 */	lmw r22, 8(r1)
/* 8023B238  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8023B23C  7C 08 03 A6 */	mtlr r0
/* 8023B240  38 21 00 30 */	addi r1, r1, 0x30
/* 8023B244  4E 80 00 20 */	blr
/* 8023B248  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B24C  7C 08 02 A6 */	mflr r0
/* 8023B250  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B254  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B258  7C BF 2B 78 */	mr r31, r5
/* 8023B25C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B260  7C 9E 23 78 */	mr r30, r4
/* 8023B264  7F E4 FB 78 */	mr r4, r31
/* 8023B268  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B26C  7C 7D 1B 78 */	mr r29, r3
/* 8023B270  48 00 06 BD */	bl 0x6bc
/* 8023B274  93 DD 00 14 */	stw r30, 0x14(r29)
/* 8023B278  7F A3 EB 78 */	mr r3, r29
/* 8023B27C  48 00 06 95 */	bl 0x694
/* 8023B280  7F A3 EB 78 */	mr r3, r29
/* 8023B284  7F C4 F3 78 */	mr r4, r30
/* 8023B288  7F E5 FB 78 */	mr r5, r31
/* 8023B28C  4B FF FE 59 */	bl -0x1a8
/* 8023B290  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B294  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B298  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B29C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B2A0  7C 08 03 A6 */	mtlr r0
/* 8023B2A4  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B2A8  4E 80 00 20 */	blr
/* 8023B2AC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B2B0  7C 08 02 A6 */	mflr r0
/* 8023B2B4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B2B8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B2BC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B2C0  3B C0 00 00 */	li r30, 0
/* 8023B2C4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B2C8  7C 7D 1B 78 */	mr r29, r3
/* 8023B2CC  80 A3 00 0C */	lwz r5, 0xc(r3)
/* 8023B2D0  2C 05 00 00 */	cmpwi r5, 0
/* 8023B2D4  41 82 00 50 */	beq 0x50
/* 8023B2D8  83 E5 00 20 */	lwz r31, 0x20(r5)
/* 8023B2DC  2C 1F 00 00 */	cmpwi r31, 0
/* 8023B2E0  41 82 00 24 */	beq 0x24
/* 8023B2E4  80 9F 00 24 */	lwz r4, 0x24(r31)
/* 8023B2E8  3B C0 00 01 */	li r30, 1
/* 8023B2EC  48 00 01 05 */	bl 0x104
/* 8023B2F0  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 8023B2F4  7F A3 EB 78 */	mr r3, r29
/* 8023B2F8  90 1D 00 14 */	stw r0, 0x14(r29)
/* 8023B2FC  48 00 06 15 */	bl 0x614
/* 8023B300  48 00 00 24 */	b 0x24
/* 8023B304  2C 04 00 00 */	cmpwi r4, 0
/* 8023B308  41 82 00 1C */	beq 0x1c
/* 8023B30C  7C A4 2B 78 */	mr r4, r5
/* 8023B310  48 00 00 E1 */	bl 0xe0
/* 8023B314  38 00 FF FF */	li r0, -1
/* 8023B318  90 1D 00 14 */	stw r0, 0x14(r29)
/* 8023B31C  7F A3 EB 78 */	mr r3, r29
/* 8023B320  48 00 05 F1 */	bl 0x5f0
/* 8023B324  7F C3 F3 78 */	mr r3, r30
/* 8023B328  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B32C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B330  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B334  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B338  7C 08 03 A6 */	mtlr r0
/* 8023B33C  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B340  4E 80 00 20 */	blr
/* 8023B344  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B348  7C 08 02 A6 */	mflr r0
/* 8023B34C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B350  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B354  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B358  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B35C  3B A0 00 00 */	li r29, 0
/* 8023B360  93 81 00 10 */	stw r28, 0x10(r1)
/* 8023B364  7C 7C 1B 78 */	mr r28, r3
/* 8023B368  48 00 05 D9 */	bl 0x5d8
/* 8023B36C  2C 03 00 00 */	cmpwi r3, 0
/* 8023B370  7C 7F 1B 78 */	mr r31, r3
/* 8023B374  41 82 00 58 */	beq 0x58
/* 8023B378  3B A0 00 01 */	li r29, 1
/* 8023B37C  48 00 00 38 */	b 0x38
/* 8023B380  80 7C 00 0C */	lwz r3, 0xc(r28)
/* 8023B384  2C 03 00 00 */	cmpwi r3, 0
/* 8023B388  41 82 00 2C */	beq 0x2c
/* 8023B38C  83 C3 00 20 */	lwz r30, 0x20(r3)
/* 8023B390  2C 1E 00 00 */	cmpwi r30, 0
/* 8023B394  41 82 00 20 */	beq 0x20
/* 8023B398  80 9E 00 24 */	lwz r4, 0x24(r30)
/* 8023B39C  7F 83 E3 78 */	mr r3, r28
/* 8023B3A0  48 00 00 51 */	bl 0x50
/* 8023B3A4  80 1E 00 28 */	lwz r0, 0x28(r30)
/* 8023B3A8  7F 83 E3 78 */	mr r3, r28
/* 8023B3AC  90 1C 00 14 */	stw r0, 0x14(r28)
/* 8023B3B0  48 00 05 61 */	bl 0x560
/* 8023B3B4  80 7F 00 28 */	lwz r3, 0x28(r31)
/* 8023B3B8  80 1C 00 18 */	lwz r0, 0x18(r28)
/* 8023B3BC  7C 03 00 00 */	cmpw r3, r0
/* 8023B3C0  40 82 FF C0 */	bne -0x40
/* 8023B3C4  7F 83 E3 78 */	mr r3, r28
/* 8023B3C8  48 00 01 A1 */	bl 0x1a0
/* 8023B3CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B3D0  7F A3 EB 78 */	mr r3, r29
/* 8023B3D4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B3D8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B3DC  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8023B3E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B3E4  7C 08 03 A6 */	mtlr r0
/* 8023B3E8  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B3EC  4E 80 00 20 */	blr
/* 8023B3F0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B3F4  7C 08 02 A6 */	mflr r0
/* 8023B3F8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B3FC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B400  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B404  7C 9E 23 78 */	mr r30, r4
/* 8023B408  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B40C  7C 7D 1B 78 */	mr r29, r3
/* 8023B410  7F C3 F3 78 */	mr r3, r30
/* 8023B414  81 9E 00 00 */	lwz r12, 0(r30)
/* 8023B418  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8023B41C  7D 89 03 A6 */	mtctr r12
/* 8023B420  4E 80 04 21 */	bctrl
/* 8023B424  4B F3 32 31 */	bl -0xccdd0
/* 8023B428  4B F3 36 89 */	bl -0xcc978
/* 8023B42C  80 9E 00 24 */	lwz r4, 0x24(r30)
/* 8023B430  2C 04 00 00 */	cmpwi r4, 0
/* 8023B434  41 82 00 0C */	beq 0xc
/* 8023B438  7F A3 EB 78 */	mr r3, r29
/* 8023B43C  4B FF FF B5 */	bl -0x4c
/* 8023B440  4B F3 32 15 */	bl -0xccdec
/* 8023B444  4B F3 36 6D */	bl -0xcc994
/* 8023B448  80 7D 00 04 */	lwz r3, 4(r29)
/* 8023B44C  83 FE 00 20 */	lwz r31, 0x20(r30)
/* 8023B450  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B454  80 9E 00 28 */	lwz r4, 0x28(r30)
/* 8023B458  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023B45C  7D 89 03 A6 */	mtctr r12
/* 8023B460  4E 80 04 21 */	bctrl
/* 8023B464  2C 1F 00 00 */	cmpwi r31, 0
/* 8023B468  38 00 00 00 */	li r0, 0
/* 8023B46C  90 1D 00 0C */	stw r0, 0xc(r29)
/* 8023B470  41 82 00 0C */	beq 0xc
/* 8023B474  90 1F 00 24 */	stw r0, 0x24(r31)
/* 8023B478  93 FD 00 0C */	stw r31, 0xc(r29)
/* 8023B47C  80 7E 00 1C */	lwz r3, 0x1c(r30)
/* 8023B480  2C 03 00 00 */	cmpwi r3, 0
/* 8023B484  41 82 00 14 */	beq 0x14
/* 8023B488  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B48C  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B490  7D 89 03 A6 */	mtctr r12
/* 8023B494  4E 80 04 21 */	bctrl
/* 8023B498  80 9E 00 10 */	lwz r4, 0x10(r30)
/* 8023B49C  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 8023B4A0  7C 03 20 40 */	cmplw r3, r4
/* 8023B4A4  40 82 00 30 */	bne 0x30
/* 8023B4A8  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8023B4AC  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B4B0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B4B4  7D 89 03 A6 */	mtctr r12
/* 8023B4B8  4E 80 04 21 */	bctrl
/* 8023B4BC  80 7E 00 14 */	lwz r3, 0x14(r30)
/* 8023B4C0  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B4C4  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B4C8  7D 89 03 A6 */	mtctr r12
/* 8023B4CC  4E 80 04 21 */	bctrl
/* 8023B4D0  48 00 00 34 */	b 0x34
/* 8023B4D4  80 1E 00 18 */	lwz r0, 0x18(r30)
/* 8023B4D8  7C 00 20 40 */	cmplw r0, r4
/* 8023B4DC  40 82 00 28 */	bne 0x28
/* 8023B4E0  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B4E4  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B4E8  7D 89 03 A6 */	mtctr r12
/* 8023B4EC  4E 80 04 21 */	bctrl
/* 8023B4F0  80 7E 00 18 */	lwz r3, 0x18(r30)
/* 8023B4F4  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B4F8  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B4FC  7D 89 03 A6 */	mtctr r12
/* 8023B500  4E 80 04 21 */	bctrl
/* 8023B504  2C 1F 00 00 */	cmpwi r31, 0
/* 8023B508  41 82 00 0C */	beq 0xc
/* 8023B50C  83 FF 00 10 */	lwz r31, 0x10(r31)
/* 8023B510  48 00 00 24 */	b 0x24
/* 8023B514  80 1D 00 28 */	lwz r0, 0x28(r29)
/* 8023B518  2C 00 00 00 */	cmpwi r0, 0
/* 8023B51C  40 82 00 10 */	bne 0x10
/* 8023B520  80 6D A3 60 */	lwz r3, -0x5ca0(r13)
/* 8023B524  83 E3 00 18 */	lwz r31, 0x18(r3)
/* 8023B528  48 00 00 0C */	b 0xc
/* 8023B52C  80 6D A3 60 */	lwz r3, -0x5ca0(r13)
/* 8023B530  83 E3 00 1C */	lwz r31, 0x1c(r3)
/* 8023B534  4B F3 31 21 */	bl -0xccee0
/* 8023B538  4B F3 35 79 */	bl -0xcca88
/* 8023B53C  7F E3 FB 78 */	mr r3, r31
/* 8023B540  4B FE E8 35 */	bl -0x117cc
/* 8023B544  4B F3 31 11 */	bl -0xccef0
/* 8023B548  4B F3 35 69 */	bl -0xcca98
/* 8023B54C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B550  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B554  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B558  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B55C  7C 08 03 A6 */	mtlr r0
/* 8023B560  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B564  4E 80 00 20 */	blr
/* 8023B568  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023B56C  2C 03 00 00 */	cmpwi r3, 0
/* 8023B570  4D 82 00 20 */	beqlr
/* 8023B574  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B578  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8023B57C  7D 89 03 A6 */	mtctr r12
/* 8023B580  4E 80 04 20 */	bctr
/* 8023B584  4E 80 00 20 */	blr
/* 8023B588  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023B58C  2C 03 00 00 */	cmpwi r3, 0
/* 8023B590  4D 82 00 20 */	beqlr
/* 8023B594  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B598  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023B59C  7D 89 03 A6 */	mtctr r12
/* 8023B5A0  4E 80 04 20 */	bctr
/* 8023B5A4  4E 80 00 20 */	blr
/* 8023B5A8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B5AC  7C 08 02 A6 */	mflr r0
/* 8023B5B0  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B5B4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B5B8  7C 7F 1B 78 */	mr r31, r3
/* 8023B5BC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023B5C0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023B5C4  93 81 00 10 */	stw r28, 0x10(r1)
/* 8023B5C8  80 03 00 24 */	lwz r0, 0x24(r3)
/* 8023B5CC  2C 00 00 00 */	cmpwi r0, 0
/* 8023B5D0  41 82 02 10 */	beq 0x210
/* 8023B5D4  7C 03 03 78 */	mr r3, r0
/* 8023B5D8  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B5DC  81 8C 00 18 */	lwz r12, 0x18(r12)
/* 8023B5E0  7D 89 03 A6 */	mtctr r12
/* 8023B5E4  4E 80 04 21 */	bctrl
/* 8023B5E8  2C 03 00 00 */	cmpwi r3, 0
/* 8023B5EC  41 82 01 F4 */	beq 0x1f4
/* 8023B5F0  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 8023B5F4  2C 00 00 00 */	cmpwi r0, 0
/* 8023B5F8  41 82 00 28 */	beq 0x28
/* 8023B5FC  2C 00 00 01 */	cmpwi r0, 1
/* 8023B600  41 82 00 C8 */	beq 0xc8
/* 8023B604  2C 00 00 02 */	cmpwi r0, 2
/* 8023B608  41 82 01 0C */	beq 0x10c
/* 8023B60C  2C 00 00 04 */	cmpwi r0, 4
/* 8023B610  41 82 01 2C */	beq 0x12c
/* 8023B614  2C 00 00 03 */	cmpwi r0, 3
/* 8023B618  41 82 01 A4 */	beq 0x1a4
/* 8023B61C  48 00 01 BC */	b 0x1bc
/* 8023B620  83 BF 00 14 */	lwz r29, 0x14(r31)
/* 8023B624  3B C0 FF FF */	li r30, -1
/* 8023B628  48 00 00 4C */	b 0x4c
/* 8023B62C  2C 04 00 00 */	cmpwi r4, 0
/* 8023B630  41 82 00 44 */	beq 0x44
/* 8023B634  83 84 00 20 */	lwz r28, 0x20(r4)
/* 8023B638  2C 1C 00 00 */	cmpwi r28, 0
/* 8023B63C  41 82 00 24 */	beq 0x24
/* 8023B640  80 9C 00 24 */	lwz r4, 0x24(r28)
/* 8023B644  7F E3 FB 78 */	mr r3, r31
/* 8023B648  4B FF FD A9 */	bl -0x258
/* 8023B64C  80 1C 00 28 */	lwz r0, 0x28(r28)
/* 8023B650  7F E3 FB 78 */	mr r3, r31
/* 8023B654  90 1F 00 14 */	stw r0, 0x14(r31)
/* 8023B658  48 00 02 B9 */	bl 0x2b8
/* 8023B65C  48 00 00 18 */	b 0x18
/* 8023B660  7F E3 FB 78 */	mr r3, r31
/* 8023B664  4B FF FD 8D */	bl -0x274
/* 8023B668  93 DF 00 14 */	stw r30, 0x14(r31)
/* 8023B66C  7F E3 FB 78 */	mr r3, r31
/* 8023B670  48 00 02 A1 */	bl 0x2a0
/* 8023B674  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8023B678  2C 04 00 00 */	cmpwi r4, 0
/* 8023B67C  40 82 FF B0 */	bne -0x50
/* 8023B680  93 BF 00 14 */	stw r29, 0x14(r31)
/* 8023B684  3B C0 00 00 */	li r30, 0
/* 8023B688  41 82 00 08 */	beq 0x8
/* 8023B68C  83 C4 00 20 */	lwz r30, 0x20(r4)
/* 8023B690  2C 04 00 00 */	cmpwi r4, 0
/* 8023B694  41 82 00 14 */	beq 0x14
/* 8023B698  7F E3 FB 78 */	mr r3, r31
/* 8023B69C  4B FF FD 55 */	bl -0x2ac
/* 8023B6A0  38 00 00 00 */	li r0, 0
/* 8023B6A4  90 1F 00 0C */	stw r0, 0xc(r31)
/* 8023B6A8  83 BF 00 14 */	lwz r29, 0x14(r31)
/* 8023B6AC  7F E3 FB 78 */	mr r3, r31
/* 8023B6B0  48 00 02 61 */	bl 0x260
/* 8023B6B4  7F E3 FB 78 */	mr r3, r31
/* 8023B6B8  7F A4 EB 78 */	mr r4, r29
/* 8023B6BC  7F C5 F3 78 */	mr r5, r30
/* 8023B6C0  4B FF FA 25 */	bl -0x5dc
/* 8023B6C4  48 00 01 14 */	b 0x114
/* 8023B6C8  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8023B6CC  3B C0 00 00 */	li r30, 0
/* 8023B6D0  2C 04 00 00 */	cmpwi r4, 0
/* 8023B6D4  41 82 00 08 */	beq 0x8
/* 8023B6D8  83 C4 00 20 */	lwz r30, 0x20(r4)
/* 8023B6DC  2C 04 00 00 */	cmpwi r4, 0
/* 8023B6E0  41 82 00 14 */	beq 0x14
/* 8023B6E4  7F E3 FB 78 */	mr r3, r31
/* 8023B6E8  4B FF FD 09 */	bl -0x2f8
/* 8023B6EC  38 00 00 00 */	li r0, 0
/* 8023B6F0  90 1F 00 0C */	stw r0, 0xc(r31)
/* 8023B6F4  83 BF 00 14 */	lwz r29, 0x14(r31)
/* 8023B6F8  7F E3 FB 78 */	mr r3, r31
/* 8023B6FC  48 00 02 15 */	bl 0x214
/* 8023B700  7F E3 FB 78 */	mr r3, r31
/* 8023B704  7F A4 EB 78 */	mr r4, r29
/* 8023B708  7F C5 F3 78 */	mr r5, r30
/* 8023B70C  4B FF F9 D9 */	bl -0x628
/* 8023B710  48 00 00 C8 */	b 0xc8
/* 8023B714  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 8023B718  7F E3 FB 78 */	mr r3, r31
/* 8023B71C  48 00 02 11 */	bl 0x210
/* 8023B720  7F E3 FB 78 */	mr r3, r31
/* 8023B724  48 00 01 ED */	bl 0x1ec
/* 8023B728  80 9F 00 18 */	lwz r4, 0x18(r31)
/* 8023B72C  7F E3 FB 78 */	mr r3, r31
/* 8023B730  80 BF 00 10 */	lwz r5, 0x10(r31)
/* 8023B734  4B FF F9 B1 */	bl -0x650
/* 8023B738  48 00 00 A0 */	b 0xa0
/* 8023B73C  80 9F 00 14 */	lwz r4, 0x14(r31)
/* 8023B740  7F E3 FB 78 */	mr r3, r31
/* 8023B744  48 00 01 FD */	bl 0x1fc
/* 8023B748  2C 03 00 00 */	cmpwi r3, 0
/* 8023B74C  7C 7E 1B 78 */	mr r30, r3
/* 8023B750  41 82 00 88 */	beq 0x88
/* 8023B754  48 00 00 38 */	b 0x38
/* 8023B758  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8023B75C  2C 03 00 00 */	cmpwi r3, 0
/* 8023B760  41 82 00 2C */	beq 0x2c
/* 8023B764  83 83 00 20 */	lwz r28, 0x20(r3)
/* 8023B768  2C 1C 00 00 */	cmpwi r28, 0
/* 8023B76C  41 82 00 20 */	beq 0x20
/* 8023B770  80 9C 00 24 */	lwz r4, 0x24(r28)
/* 8023B774  7F E3 FB 78 */	mr r3, r31
/* 8023B778  4B FF FC 79 */	bl -0x388
/* 8023B77C  80 1C 00 28 */	lwz r0, 0x28(r28)
/* 8023B780  7F E3 FB 78 */	mr r3, r31
/* 8023B784  90 1F 00 14 */	stw r0, 0x14(r31)
/* 8023B788  48 00 01 89 */	bl 0x188
/* 8023B78C  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 8023B790  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 8023B794  7C 03 00 00 */	cmpw r3, r0
/* 8023B798  40 82 FF C0 */	bne -0x40
/* 8023B79C  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8023B7A0  2C 03 00 00 */	cmpwi r3, 0
/* 8023B7A4  41 82 00 34 */	beq 0x34
/* 8023B7A8  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B7AC  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8023B7B0  7D 89 03 A6 */	mtctr r12
/* 8023B7B4  4E 80 04 21 */	bctrl
/* 8023B7B8  48 00 00 20 */	b 0x20
/* 8023B7BC  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8023B7C0  2C 03 00 00 */	cmpwi r3, 0
/* 8023B7C4  41 82 00 14 */	beq 0x14
/* 8023B7C8  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B7CC  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B7D0  7D 89 03 A6 */	mtctr r12
/* 8023B7D4  4E 80 04 21 */	bctrl
/* 8023B7D8  38 00 FF FF */	li r0, -1
/* 8023B7DC  90 1F 00 20 */	stw r0, 0x20(r31)
/* 8023B7E0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B7E4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B7E8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023B7EC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023B7F0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8023B7F4  7C 08 03 A6 */	mtlr r0
/* 8023B7F8  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B7FC  4E 80 00 20 */	blr
/* 8023B800  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023B804  7C 08 02 A6 */	mflr r0
/* 8023B808  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023B80C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023B810  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023B814  2C 03 00 00 */	cmpwi r3, 0
/* 8023B818  41 82 00 64 */	beq 0x64
/* 8023B81C  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B820  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023B824  7D 89 03 A6 */	mtctr r12
/* 8023B828  4E 80 04 21 */	bctrl
/* 8023B82C  80 6D A3 60 */	lwz r3, -0x5ca0(r13)
/* 8023B830  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B834  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023B838  7D 89 03 A6 */	mtctr r12
/* 8023B83C  4E 80 04 21 */	bctrl
/* 8023B840  7C 7F 1B 78 */	mr r31, r3
/* 8023B844  80 6D A3 60 */	lwz r3, -0x5ca0(r13)
/* 8023B848  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B84C  81 8C 00 08 */	lwz r12, 8(r12)
/* 8023B850  7D 89 03 A6 */	mtctr r12
/* 8023B854  4E 80 04 21 */	bctrl
/* 8023B858  88 03 00 04 */	lbz r0, 4(r3)
/* 8023B85C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023B860  41 82 00 1C */	beq 0x1c
/* 8023B864  88 1F 00 09 */	lbz r0, 9(r31)
/* 8023B868  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023B86C  40 82 00 10 */	bne 0x10
/* 8023B870  88 1F 00 09 */	lbz r0, 9(r31)
/* 8023B874  60 00 00 01 */	ori r0, r0, 1
/* 8023B878  98 1F 00 09 */	stb r0, 9(r31)
/* 8023B87C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023B880  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023B884  7C 08 03 A6 */	mtlr r0
/* 8023B888  38 21 00 10 */	addi r1, r1, 0x10
/* 8023B88C  4E 80 00 20 */	blr
/* 8023B890  80 63 00 24 */	lwz r3, 0x24(r3)
/* 8023B894  2C 03 00 00 */	cmpwi r3, 0
/* 8023B898  4D 82 00 20 */	beqlr
/* 8023B89C  81 83 00 00 */	lwz r12, 0(r3)
/* 8023B8A0  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023B8A4  7D 89 03 A6 */	mtctr r12
/* 8023B8A8  4E 80 04 20 */	bctr
/* 8023B8AC  4E 80 00 20 */	blr
/* 8023B8B0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023B8B4  7C 08 02 A6 */	mflr r0
/* 8023B8B8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023B8BC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023B8C0  7C 7F 1B 78 */	mr r31, r3
/* 8023B8C4  38 60 00 24 */	li r3, 0x24
/* 8023B8C8  4B FE E5 05 */	bl -0x11afc
/* 8023B8CC  2C 03 00 00 */	cmpwi r3, 0
/* 8023B8D0  41 82 00 28 */	beq 0x28
/* 8023B8D4  C0 22 A0 68 */	lfs f1, -0x5f98(r2)
/* 8023B8D8  38 00 00 00 */	li r0, 0
/* 8023B8DC  90 01 00 08 */	stw r0, 8(r1)
/* 8023B8E0  38 81 00 08 */	addi r4, r1, 8
/* 8023B8E4  FC 40 08 90 */	fmr f2, f1
/* 8023B8E8  C0 62 A0 6C */	lfs f3, -0x5f94(r2)
/* 8023B8EC  C0 82 A0 70 */	lfs f4, -0x5f90(r2)
/* 8023B8F0  38 A0 00 00 */	li r5, 0
/* 8023B8F4  4B FD 98 75 */	bl -0x2678c
/* 8023B8F8  90 7F 00 24 */	stw r3, 0x24(r31)
/* 8023B8FC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023B900  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023B904  7C 08 03 A6 */	mtlr r0
/* 8023B908  38 21 00 20 */	addi r1, r1, 0x20
/* 8023B90C  4E 80 00 20 */	blr
/* 8023B910  80 A3 00 18 */	lwz r5, 0x18(r3)
/* 8023B914  38 00 FF FF */	li r0, -1
/* 8023B918  80 83 00 14 */	lwz r4, 0x14(r3)
/* 8023B91C  90 A3 00 1C */	stw r5, 0x1c(r3)
/* 8023B920  90 83 00 18 */	stw r4, 0x18(r3)
/* 8023B924  90 03 00 14 */	stw r0, 0x14(r3)
/* 8023B928  4E 80 00 20 */	blr
/* 8023B92C  81 84 00 00 */	lwz r12, 0(r4)
/* 8023B930  7C 83 23 78 */	mr r3, r4
/* 8023B934  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8023B938  7D 89 03 A6 */	mtctr r12
/* 8023B93C  4E 80 04 20 */	bctr
/* 8023B940  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023B944  38 A0 00 00 */	li r5, 0
/* 8023B948  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8023B94C  48 00 00 1C */	b 0x1c
/* 8023B950  80 03 00 28 */	lwz r0, 0x28(r3)
/* 8023B954  7C 04 00 00 */	cmpw r4, r0
/* 8023B958  40 82 00 0C */	bne 0xc
/* 8023B95C  38 A0 00 01 */	li r5, 1
/* 8023B960  48 00 00 10 */	b 0x10
/* 8023B964  80 63 00 20 */	lwz r3, 0x20(r3)
/* 8023B968  2C 03 00 00 */	cmpwi r3, 0
/* 8023B96C  40 82 FF E4 */	bne -0x1c
/* 8023B970  2C 05 00 00 */	cmpwi r5, 0
/* 8023B974  4C 82 00 20 */	bnelr
/* 8023B978  38 60 00 00 */	li r3, 0
/* 8023B97C  4E 80 00 20 */	blr
/* 8023B980  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023B984  7C 08 02 A6 */	mflr r0
/* 8023B988  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023B98C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023B990  7C 7F 1B 78 */	mr r31, r3
/* 8023B994  48 00 0D 01 */	bl 0xd00
/* 8023B998  3C E0 80 2A */	lis r7, 0x802a
/* 8023B99C  39 00 00 00 */	li r8, 0
/* 8023B9A0  38 E7 3E 58 */	addi r7, r7, 0x3e58
/* 8023B9A4  38 00 00 01 */	li r0, 1
/* 8023B9A8  38 C7 00 38 */	addi r6, r7, 0x38
/* 8023B9AC  91 1F 00 B8 */	stw r8, 0xb8(r31)
/* 8023B9B0  38 7F 00 B8 */	addi r3, r31, 0xb8
/* 8023B9B4  38 80 00 02 */	li r4, 2
/* 8023B9B8  B1 1F 00 BC */	sth r8, 0xbc(r31)
/* 8023B9BC  38 A0 00 00 */	li r5, 0
/* 8023B9C0  90 FF 00 B4 */	stw r7, 0xb4(r31)
/* 8023B9C4  90 DF 00 C0 */	stw r6, 0xc0(r31)
/* 8023B9C8  91 1F 00 C4 */	stw r8, 0xc4(r31)
/* 8023B9CC  91 1F 00 C8 */	stw r8, 0xc8(r31)
/* 8023B9D0  B0 1F 00 CC */	sth r0, 0xcc(r31)
/* 8023B9D4  4B FE E6 89 */	bl -0x11978
/* 8023B9D8  38 7F 00 B8 */	addi r3, r31, 0xb8
/* 8023B9DC  38 80 00 00 */	li r4, 0
/* 8023B9E0  38 A0 00 65 */	li r5, 0x65
/* 8023B9E4  38 C0 00 00 */	li r6, 0
/* 8023B9E8  4B FE E7 7D */	bl -0x11884
/* 8023B9EC  38 7F 00 B8 */	addi r3, r31, 0xb8
/* 8023B9F0  38 80 00 01 */	li r4, 1
/* 8023B9F4  38 A0 00 84 */	li r5, 0x84
/* 8023B9F8  38 C0 00 00 */	li r6, 0
/* 8023B9FC  4B FE E7 69 */	bl -0x11898
/* 8023BA00  7F E3 FB 78 */	mr r3, r31
/* 8023BA04  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023BA08  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023BA0C  7C 08 03 A6 */	mtlr r0
/* 8023BA10  38 21 00 10 */	addi r1, r1, 0x10
/* 8023BA14  4E 80 00 20 */	blr
/* 8023BA18  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023BA1C  7C 08 02 A6 */	mflr r0
/* 8023BA20  2C 03 00 00 */	cmpwi r3, 0
/* 8023BA24  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023BA28  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 8023BA2C  7C 7B 1B 78 */	mr r27, r3
/* 8023BA30  7C 9C 23 78 */	mr r28, r4
/* 8023BA34  41 82 00 C4 */	beq 0xc4
/* 8023BA38  3C 80 80 2A */	lis r4, 0x802a
/* 8023BA3C  3B A0 00 00 */	li r29, 0
/* 8023BA40  38 84 3E 58 */	addi r4, r4, 0x3e58
/* 8023BA44  90 83 00 B4 */	stw r4, 0xb4(r3)
/* 8023BA48  38 04 00 38 */	addi r0, r4, 0x38
/* 8023BA4C  3B C0 00 00 */	li r30, 0
/* 8023BA50  90 03 00 C0 */	stw r0, 0xc0(r3)
/* 8023BA54  3B E0 00 00 */	li r31, 0
/* 8023BA58  48 00 00 3C */	b 0x3c
/* 8023BA5C  80 7B 00 C4 */	lwz r3, 0xc4(r27)
/* 8023BA60  7C 63 F0 2E */	lwzx r3, r3, r30
/* 8023BA64  2C 03 00 00 */	cmpwi r3, 0
/* 8023BA68  41 82 00 24 */	beq 0x24
/* 8023BA6C  41 82 00 18 */	beq 0x18
/* 8023BA70  81 83 00 04 */	lwz r12, 4(r3)
/* 8023BA74  38 80 00 01 */	li r4, 1
/* 8023BA78  81 8C 00 08 */	lwz r12, 8(r12)
/* 8023BA7C  7D 89 03 A6 */	mtctr r12
/* 8023BA80  4E 80 04 21 */	bctrl
/* 8023BA84  80 7B 00 C4 */	lwz r3, 0xc4(r27)
/* 8023BA88  7F E3 F1 2E */	stwx r31, r3, r30
/* 8023BA8C  3B DE 00 04 */	addi r30, r30, 4
/* 8023BA90  3B BD 00 01 */	addi r29, r29, 1
/* 8023BA94  81 9B 00 B4 */	lwz r12, 0xb4(r27)
/* 8023BA98  7F 63 DB 78 */	mr r3, r27
/* 8023BA9C  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023BAA0  7D 89 03 A6 */	mtctr r12
/* 8023BAA4  4E 80 04 21 */	bctrl
/* 8023BAA8  54 60 04 3E */	clrlwi r0, r3, 0x10
/* 8023BAAC  7C 1D 00 00 */	cmpw r29, r0
/* 8023BAB0  41 80 FF AC */	blt -0x54
/* 8023BAB4  80 7B 00 C4 */	lwz r3, 0xc4(r27)
/* 8023BAB8  4B FE E4 29 */	bl -0x11bd8
/* 8023BABC  3B E0 00 00 */	li r31, 0
/* 8023BAC0  93 FB 00 C4 */	stw r31, 0xc4(r27)
/* 8023BAC4  80 7B 00 C8 */	lwz r3, 0xc8(r27)
/* 8023BAC8  4B FE E4 19 */	bl -0x11be8
/* 8023BACC  93 FB 00 C8 */	stw r31, 0xc8(r27)
/* 8023BAD0  38 7B 00 B8 */	addi r3, r27, 0xb8
/* 8023BAD4  38 80 00 00 */	li r4, 0
/* 8023BAD8  4B FE E4 D5 */	bl -0x11b2c
/* 8023BADC  7F 63 DB 78 */	mr r3, r27
/* 8023BAE0  38 80 00 00 */	li r4, 0
/* 8023BAE4  48 00 0C 65 */	bl 0xc64
/* 8023BAE8  2C 1C 00 00 */	cmpwi r28, 0
/* 8023BAEC  40 81 00 0C */	ble 0xc
/* 8023BAF0  7F 63 DB 78 */	mr r3, r27
/* 8023BAF4  4B FE E3 21 */	bl -0x11ce0
/* 8023BAF8  7F 63 DB 78 */	mr r3, r27
/* 8023BAFC  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 8023BB00  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023BB04  7C 08 03 A6 */	mtlr r0
/* 8023BB08  38 21 00 20 */	addi r1, r1, 0x20
/* 8023BB0C  4E 80 00 20 */	blr
/* 8023BB10  38 60 00 06 */	li r3, 6
/* 8023BB14  4E 80 00 20 */	blr
/* 8023BB18  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8023BB1C  7C 08 02 A6 */	mflr r0
/* 8023BB20  90 01 00 64 */	stw r0, 0x64(r1)
/* 8023BB24  BD C1 00 18 */	stmw r14, 0x18(r1)
/* 8023BB28  7C 6F 1B 78 */	mr r15, r3
/* 8023BB2C  48 00 0C FD */	bl 0xcfc
/* 8023BB30  81 8F 00 B4 */	lwz r12, 0xb4(r15)
/* 8023BB34  7D E3 7B 78 */	mr r3, r15
/* 8023BB38  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023BB3C  7D 89 03 A6 */	mtctr r12
/* 8023BB40  4E 80 04 21 */	bctrl
/* 8023BB44  54 63 13 BA */	rlwinm r3, r3, 2, 0xe, 0x1d
/* 8023BB48  4B FE E2 A9 */	bl -0x11d58
/* 8023BB4C  90 6F 00 C4 */	stw r3, 0xc4(r15)
/* 8023BB50  3A 20 00 00 */	li r17, 0
/* 8023BB54  3A 00 00 00 */	li r16, 0
/* 8023BB58  39 C0 00 00 */	li r14, 0
/* 8023BB5C  48 00 00 14 */	b 0x14
/* 8023BB60  80 6F 00 C4 */	lwz r3, 0xc4(r15)
/* 8023BB64  3A 31 00 01 */	addi r17, r17, 1
/* 8023BB68  7D C3 81 2E */	stwx r14, r3, r16
/* 8023BB6C  3A 10 00 04 */	addi r16, r16, 4
/* 8023BB70  81 8F 00 B4 */	lwz r12, 0xb4(r15)
/* 8023BB74  7D E3 7B 78 */	mr r3, r15
/* 8023BB78  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023BB7C  7D 89 03 A6 */	mtctr r12
/* 8023BB80  4E 80 04 21 */	bctrl
/* 8023BB84  54 60 04 3E */	clrlwi r0, r3, 0x10
/* 8023BB88  7C 11 00 00 */	cmpw r17, r0
/* 8023BB8C  41 80 FF D4 */	blt -0x2c
/* 8023BB90  81 8F 00 B4 */	lwz r12, 0xb4(r15)
/* 8023BB94  7D E3 7B 78 */	mr r3, r15
/* 8023BB98  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 8023BB9C  7D 89 03 A6 */	mtctr r12
/* 8023BBA0  4E 80 04 21 */	bctrl
/* 8023BBA4  54 64 04 3E */	clrlwi r4, r3, 0x10
/* 8023BBA8  54 60 13 BA */	rlwinm r0, r3, 2, 0xe, 0x1d
/* 8023BBAC  7C 64 00 50 */	subf r3, r4, r0
/* 8023BBB0  4B FE E2 41 */	bl -0x11dc0
/* 8023BBB4  90 6F 00 C8 */	stw r3, 0xc8(r15)
/* 8023BBB8  3A 00 00 00 */	li r16, 0
/* 8023BBBC  3B E0 00 00 */	li r31, 0
/* 8023BBC0  3B C0 00 1A */	li r30, 0x1a
/* 8023BBC4  39 C0 00 31 */	li r14, 0x31
/* 8023BBC8  3B 80 00 01 */	li r28, 1
/* 8023BBCC  3B A0 00 18 */	li r29, 0x18
/* 8023BBD0  3B 40 00 33 */	li r26, 0x33
/* 8023BBD4  3B 60 00 4A */	li r27, 0x4a
/* 8023BBD8  3B 00 00 4D */	li r24, 0x4d
/* 8023BBDC  3B 20 00 64 */	li r25, 0x64
/* 8023BBE0  3A C0 00 34 */	li r22, 0x34
/* 8023BBE4  3A E0 00 4B */	li r23, 0x4b
/* 8023BBE8  3A 80 00 1B */	li r20, 0x1b
/* 8023BBEC  3A A0 00 32 */	li r21, 0x32
/* 8023BBF0  3A 40 00 02 */	li r18, 2
/* 8023BBF4  3A 60 00 19 */	li r19, 0x19
/* 8023BBF8  3E 20 80 2A */	lis r17, 0x802a
/* 8023BBFC  48 00 00 FC */	b 0xfc
/* 8023BC00  56 05 04 3E */	clrlwi r5, r16, 0x10
/* 8023BC04  56 00 13 BA */	rlwinm r0, r16, 2, 0xe, 0x1d
/* 8023BC08  88 C2 A0 79 */	lbz r6, -0x5f87(r2)
/* 8023BC0C  7C 05 00 50 */	subf r0, r5, r0
/* 8023BC10  88 82 A0 7A */	lbz r4, -0x5f86(r2)
/* 8023BC14  28 05 00 09 */	cmplwi r5, 9
/* 8023BC18  88 E2 A0 78 */	lbz r7, -0x5f88(r2)
/* 8023BC1C  80 6F 00 C8 */	lwz r3, 0xc8(r15)
/* 8023BC20  98 E1 00 08 */	stb r7, 8(r1)
/* 8023BC24  7C E3 01 EE */	stbux r7, r3, r0
/* 8023BC28  98 C3 00 01 */	stb r6, 1(r3)
/* 8023BC2C  98 C1 00 09 */	stb r6, 9(r1)
/* 8023BC30  98 81 00 0A */	stb r4, 0xa(r1)
/* 8023BC34  98 83 00 02 */	stb r4, 2(r3)
/* 8023BC38  41 81 00 BC */	bgt 0xbc
/* 8023BC3C  38 91 3E 30 */	addi r4, r17, 0x3e30
/* 8023BC40  54 A0 10 3A */	slwi r0, r5, 2
/* 8023BC44  7C 84 00 2E */	lwzx r4, r4, r0
/* 8023BC48  7C 89 03 A6 */	mtctr r4
/* 8023BC4C  4E 80 04 20 */	bctr
/* 8023BC50  9A 43 00 00 */	stb r18, 0(r3)
/* 8023BC54  9A 63 00 01 */	stb r19, 1(r3)
/* 8023BC58  48 00 00 9C */	b 0x9c
/* 8023BC5C  9A 83 00 00 */	stb r20, 0(r3)
/* 8023BC60  9A A3 00 01 */	stb r21, 1(r3)
/* 8023BC64  48 00 00 90 */	b 0x90
/* 8023BC68  9A C3 00 00 */	stb r22, 0(r3)
/* 8023BC6C  9A E3 00 01 */	stb r23, 1(r3)
/* 8023BC70  48 00 00 84 */	b 0x84
/* 8023BC74  9B 03 00 00 */	stb r24, 0(r3)
/* 8023BC78  9B 23 00 01 */	stb r25, 1(r3)
/* 8023BC7C  48 00 00 78 */	b 0x78
/* 8023BC80  9B 43 00 00 */	stb r26, 0(r3)
/* 8023BC84  9B 63 00 01 */	stb r27, 1(r3)
/* 8023BC88  9B E3 00 02 */	stb r31, 2(r3)
/* 8023BC8C  48 00 00 68 */	b 0x68
/* 8023BC90  9B 83 00 00 */	stb r28, 0(r3)
/* 8023BC94  9B A3 00 01 */	stb r29, 1(r3)
/* 8023BC98  9B E3 00 02 */	stb r31, 2(r3)
/* 8023BC9C  48 00 00 58 */	b 0x58
/* 8023BCA0  9B C3 00 00 */	stb r30, 0(r3)
/* 8023BCA4  99 C3 00 01 */	stb r14, 1(r3)
/* 8023BCA8  9B E3 00 02 */	stb r31, 2(r3)
/* 8023BCAC  48 00 00 48 */	b 0x48
/* 8023BCB0  38 00 00 4C */	li r0, 0x4c
/* 8023BCB4  98 03 00 00 */	stb r0, 0(r3)
/* 8023BCB8  38 00 00 63 */	li r0, 0x63
/* 8023BCBC  98 03 00 01 */	stb r0, 1(r3)
/* 8023BCC0  9B E3 00 02 */	stb r31, 2(r3)
/* 8023BCC4  48 00 00 30 */	b 0x30
/* 8023BCC8  38 00 00 66 */	li r0, 0x66
/* 8023BCCC  98 03 00 00 */	stb r0, 0(r3)
/* 8023BCD0  38 00 00 7D */	li r0, 0x7d
/* 8023BCD4  98 03 00 01 */	stb r0, 1(r3)
/* 8023BCD8  9B E3 00 02 */	stb r31, 2(r3)
/* 8023BCDC  48 00 00 18 */	b 0x18
/* 8023BCE0  38 00 00 87 */	li r0, 0x87
/* 8023BCE4  98 03 00 00 */	stb r0, 0(r3)
/* 8023BCE8  38 00 00 9E */	li r0, 0x9e
/* 8023BCEC  98 03 00 01 */	stb r0, 1(r3)
/* 8023BCF0  9B E3 00 02 */	stb r31, 2(r3)
/* 8023BCF4  3A 10 00 01 */	addi r16, r16, 1
/* 8023BCF8  81 8F 00 B4 */	lwz r12, 0xb4(r15)
/* 8023BCFC  7D E3 7B 78 */	mr r3, r15
/* 8023BD00  81 8C 00 50 */	lwz r12, 0x50(r12)
/* 8023BD04  7D 89 03 A6 */	mtctr r12
/* 8023BD08  4E 80 04 21 */	bctrl
/* 8023BD0C  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023BD10  56 00 04 3E */	clrlwi r0, r16, 0x10
/* 8023BD14  7C 00 18 40 */	cmplw r0, r3
/* 8023BD18  41 80 FE E8 */	blt -0x118
/* 8023BD1C  B9 C1 00 18 */	lmw r14, 0x18(r1)
/* 8023BD20  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8023BD24  7C 08 03 A6 */	mtlr r0
/* 8023BD28  38 21 00 60 */	addi r1, r1, 0x60
/* 8023BD2C  4E 80 00 20 */	blr
/* 8023BD30  38 60 00 0A */	li r3, 0xa
/* 8023BD34  4E 80 00 20 */	blr
/* 8023BD38  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023BD3C  7C 08 02 A6 */	mflr r0
/* 8023BD40  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023BD44  BF 41 00 08 */	stmw r26, 8(r1)
/* 8023BD48  7C 7B 1B 78 */	mr r27, r3
/* 8023BD4C  7C 9C 23 78 */	mr r28, r4
/* 8023BD50  7C BD 2B 78 */	mr r29, r5
/* 8023BD54  3B C0 00 00 */	li r30, 0
/* 8023BD58  3B E0 00 01 */	li r31, 1
/* 8023BD5C  48 00 02 AC */	b 0x2ac
/* 8023BD60  57 C3 04 3E */	clrlwi r3, r30, 0x10
/* 8023BD64  7F E0 18 30 */	slw r0, r31, r3
/* 8023BD68  7F 80 00 39 */	and. r0, r28, r0
/* 8023BD6C  41 82 02 98 */	beq 0x298
/* 8023BD70  38 03 FF FF */	addi r0, r3, -1
/* 8023BD74  28 00 00 01 */	cmplwi r0, 1
/* 8023BD78  40 81 00 4C */	ble 0x4c
/* 8023BD7C  2C 03 00 00 */	cmpwi r3, 0
/* 8023BD80  41 82 00 20 */	beq 0x20
/* 8023BD84  2C 03 00 03 */	cmpwi r3, 3
/* 8023BD88  41 82 00 60 */	beq 0x60
/* 8023BD8C  2C 03 00 04 */	cmpwi r3, 4
/* 8023BD90  41 82 00 7C */	beq 0x7c
/* 8023BD94  2C 03 00 05 */	cmpwi r3, 5
/* 8023BD98  41 82 00 98 */	beq 0x98
/* 8023BD9C  48 00 00 B4 */	b 0xb4
/* 8023BDA0  38 60 00 34 */	li r3, 0x34
/* 8023BDA4  4B FE E0 29 */	bl -0x11fd8
/* 8023BDA8  2C 03 00 00 */	cmpwi r3, 0
/* 8023BDAC  41 82 00 08 */	beq 0x8
/* 8023BDB0  4B FE 5A 8D */	bl -0x1a574
/* 8023BDB4  80 9B 00 C4 */	lwz r4, 0xc4(r27)
/* 8023BDB8  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023BDBC  7C 64 01 2E */	stwx r3, r4, r0
/* 8023BDC0  48 00 00 90 */	b 0x90
/* 8023BDC4  38 60 00 34 */	li r3, 0x34
/* 8023BDC8  4B FE E0 05 */	bl -0x11ffc
/* 8023BDCC  2C 03 00 00 */	cmpwi r3, 0
/* 8023BDD0  41 82 00 08 */	beq 0x8
/* 8023BDD4  4B FE 4F 15 */	bl -0x1b0ec
/* 8023BDD8  80 9B 00 C4 */	lwz r4, 0xc4(r27)
/* 8023BDDC  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023BDE0  7C 64 01 2E */	stwx r3, r4, r0
/* 8023BDE4  48 00 00 6C */	b 0x6c
/* 8023BDE8  38 60 00 18 */	li r3, 0x18
/* 8023BDEC  4B FE DF E1 */	bl -0x12020
/* 8023BDF0  2C 03 00 00 */	cmpwi r3, 0
/* 8023BDF4  41 82 00 08 */	beq 0x8
/* 8023BDF8  4B FE 4C 4D */	bl -0x1b3b4
/* 8023BDFC  80 9B 00 C4 */	lwz r4, 0xc4(r27)
/* 8023BE00  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023BE04  7C 64 01 2E */	stwx r3, r4, r0
/* 8023BE08  48 00 00 48 */	b 0x48
/* 8023BE0C  38 60 00 CC */	li r3, 0xcc
/* 8023BE10  4B FE DF BD */	bl -0x12044
/* 8023BE14  2C 03 00 00 */	cmpwi r3, 0
/* 8023BE18  41 82 00 08 */	beq 0x8
/* 8023BE1C  4B FE 07 51 */	bl -0x1f8b0
/* 8023BE20  80 9B 00 C4 */	lwz r4, 0xc4(r27)
/* 8023BE24  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023BE28  7C 64 01 2E */	stwx r3, r4, r0
/* 8023BE2C  48 00 00 24 */	b 0x24
/* 8023BE30  38 60 00 8C */	li r3, 0x8c
/* 8023BE34  4B FE DF 99 */	bl -0x12068
/* 8023BE38  2C 03 00 00 */	cmpwi r3, 0
/* 8023BE3C  41 82 00 08 */	beq 0x8
/* 8023BE40  4B FE 2A 8D */	bl -0x1d574
/* 8023BE44  80 9B 00 C4 */	lwz r4, 0xc4(r27)
/* 8023BE48  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023BE4C  7C 64 01 2E */	stwx r3, r4, r0
/* 8023BE50  80 7B 00 C4 */	lwz r3, 0xc4(r27)
/* 8023BE54  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023BE58  7F A4 EB 78 */	mr r4, r29
/* 8023BE5C  7F 43 00 2E */	lwzx r26, r3, r0
/* 8023BE60  7F 43 D3 78 */	mr r3, r26
/* 8023BE64  4B FE 05 0D */	bl -0x1faf4
/* 8023BE68  57 C0 04 3F */	clrlwi. r0, r30, 0x10
/* 8023BE6C  41 82 00 30 */	beq 0x30
/* 8023BE70  2C 00 00 01 */	cmpwi r0, 1
/* 8023BE74  41 82 00 68 */	beq 0x68
/* 8023BE78  2C 00 00 03 */	cmpwi r0, 3
/* 8023BE7C  41 82 00 A0 */	beq 0xa0
/* 8023BE80  2C 00 00 02 */	cmpwi r0, 2
/* 8023BE84  41 82 00 C4 */	beq 0xc4
/* 8023BE88  2C 00 00 04 */	cmpwi r0, 4
/* 8023BE8C  41 82 00 FC */	beq 0xfc
/* 8023BE90  2C 00 00 05 */	cmpwi r0, 5
/* 8023BE94  41 82 01 34 */	beq 0x134
/* 8023BE98  48 00 01 6C */	b 0x16c
/* 8023BE9C  38 7A 00 08 */	addi r3, r26, 8
/* 8023BEA0  38 80 00 00 */	li r4, 0
/* 8023BEA4  38 A0 00 01 */	li r5, 1
/* 8023BEA8  38 C0 00 01 */	li r6, 1
/* 8023BEAC  4B FE E2 B9 */	bl -0x11d48
/* 8023BEB0  38 7A 00 08 */	addi r3, r26, 8
/* 8023BEB4  38 80 00 01 */	li r4, 1
/* 8023BEB8  38 A0 00 1A */	li r5, 0x1a
/* 8023BEBC  38 C0 00 01 */	li r6, 1
/* 8023BEC0  4B FE E2 A5 */	bl -0x11d5c
/* 8023BEC4  38 7A 00 08 */	addi r3, r26, 8
/* 8023BEC8  38 80 00 02 */	li r4, 2
/* 8023BECC  38 A0 00 4B */	li r5, 0x4b
/* 8023BED0  38 C0 00 00 */	li r6, 0
/* 8023BED4  4B FE E2 91 */	bl -0x11d70
/* 8023BED8  48 00 01 2C */	b 0x12c
/* 8023BEDC  38 7A 00 08 */	addi r3, r26, 8
/* 8023BEE0  38 80 00 00 */	li r4, 0
/* 8023BEE4  38 A0 00 00 */	li r5, 0
/* 8023BEE8  38 C0 00 01 */	li r6, 1
/* 8023BEEC  4B FE E2 79 */	bl -0x11d88
/* 8023BEF0  38 7A 00 08 */	addi r3, r26, 8
/* 8023BEF4  38 80 00 01 */	li r4, 1
/* 8023BEF8  38 A0 00 33 */	li r5, 0x33
/* 8023BEFC  38 C0 00 01 */	li r6, 1
/* 8023BF00  4B FE E2 65 */	bl -0x11d9c
/* 8023BF04  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF08  38 80 00 02 */	li r4, 2
/* 8023BF0C  38 A0 00 4C */	li r5, 0x4c
/* 8023BF10  38 C0 00 01 */	li r6, 1
/* 8023BF14  4B FE E2 51 */	bl -0x11db0
/* 8023BF18  48 00 00 EC */	b 0xec
/* 8023BF1C  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF20  38 80 00 00 */	li r4, 0
/* 8023BF24  38 A0 00 7E */	li r5, 0x7e
/* 8023BF28  38 C0 00 00 */	li r6, 0
/* 8023BF2C  4B FE E2 39 */	bl -0x11dc8
/* 8023BF30  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF34  38 80 00 01 */	li r4, 1
/* 8023BF38  38 A0 00 81 */	li r5, 0x81
/* 8023BF3C  38 C0 00 00 */	li r6, 0
/* 8023BF40  4B FE E2 25 */	bl -0x11ddc
/* 8023BF44  48 00 00 C0 */	b 0xc0
/* 8023BF48  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF4C  38 80 00 00 */	li r4, 0
/* 8023BF50  38 A0 00 00 */	li r5, 0
/* 8023BF54  38 C0 00 00 */	li r6, 0
/* 8023BF58  4B FE E2 0D */	bl -0x11df4
/* 8023BF5C  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF60  38 80 00 01 */	li r4, 1
/* 8023BF64  38 A0 00 19 */	li r5, 0x19
/* 8023BF68  38 C0 00 00 */	li r6, 0
/* 8023BF6C  4B FE E1 F9 */	bl -0x11e08
/* 8023BF70  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF74  38 80 00 02 */	li r4, 2
/* 8023BF78  38 A0 00 32 */	li r5, 0x32
/* 8023BF7C  38 C0 00 00 */	li r6, 0
/* 8023BF80  4B FE E1 E5 */	bl -0x11e1c
/* 8023BF84  48 00 00 80 */	b 0x80
/* 8023BF88  38 7A 00 08 */	addi r3, r26, 8
/* 8023BF8C  38 80 00 00 */	li r4, 0
/* 8023BF90  38 A0 00 7F */	li r5, 0x7f
/* 8023BF94  38 C0 00 00 */	li r6, 0
/* 8023BF98  4B FE E1 CD */	bl -0x11e34
/* 8023BF9C  38 7A 00 08 */	addi r3, r26, 8
/* 8023BFA0  38 80 00 01 */	li r4, 1
/* 8023BFA4  38 A0 00 82 */	li r5, 0x82
/* 8023BFA8  38 C0 00 00 */	li r6, 0
/* 8023BFAC  4B FE E1 B9 */	bl -0x11e48
/* 8023BFB0  38 7A 00 08 */	addi r3, r26, 8
/* 8023BFB4  38 80 00 02 */	li r4, 2
/* 8023BFB8  38 A0 00 86 */	li r5, 0x86
/* 8023BFBC  38 C0 00 00 */	li r6, 0
/* 8023BFC0  4B FE E1 A5 */	bl -0x11e5c
/* 8023BFC4  48 00 00 40 */	b 0x40
/* 8023BFC8  38 7A 00 08 */	addi r3, r26, 8
/* 8023BFCC  38 80 00 00 */	li r4, 0
/* 8023BFD0  38 A0 00 80 */	li r5, 0x80
/* 8023BFD4  38 C0 00 00 */	li r6, 0
/* 8023BFD8  4B FE E1 8D */	bl -0x11e74
/* 8023BFDC  38 7A 00 08 */	addi r3, r26, 8
/* 8023BFE0  38 80 00 01 */	li r4, 1
/* 8023BFE4  38 A0 00 83 */	li r5, 0x83
/* 8023BFE8  38 C0 00 00 */	li r6, 0
/* 8023BFEC  4B FE E1 79 */	bl -0x11e88
/* 8023BFF0  38 7A 00 08 */	addi r3, r26, 8
/* 8023BFF4  38 80 00 02 */	li r4, 2
/* 8023BFF8  38 A0 00 85 */	li r5, 0x85
/* 8023BFFC  38 C0 00 00 */	li r6, 0
/* 8023C000  4B FE E1 65 */	bl -0x11e9c
/* 8023C004  3B DE 00 01 */	addi r30, r30, 1
/* 8023C008  81 9B 00 B4 */	lwz r12, 0xb4(r27)
/* 8023C00C  7F 63 DB 78 */	mr r3, r27
/* 8023C010  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023C014  7D 89 03 A6 */	mtctr r12
/* 8023C018  4E 80 04 21 */	bctrl
/* 8023C01C  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023C020  57 C0 04 3E */	clrlwi r0, r30, 0x10
/* 8023C024  7C 00 18 40 */	cmplw r0, r3
/* 8023C028  41 80 FD 38 */	blt -0x2c8
/* 8023C02C  A0 1B 00 14 */	lhz r0, 0x14(r27)
/* 8023C030  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8023C034  B0 1B 00 14 */	sth r0, 0x14(r27)
/* 8023C038  BB 41 00 08 */	lmw r26, 8(r1)
/* 8023C03C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023C040  7C 08 03 A6 */	mtlr r0
/* 8023C044  38 21 00 20 */	addi r1, r1, 0x20
/* 8023C048  4E 80 00 20 */	blr
/* 8023C04C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C050  7C 08 02 A6 */	mflr r0
/* 8023C054  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C058  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C05C  3B E0 00 00 */	li r31, 0
/* 8023C060  93 C1 00 08 */	stw r30, 8(r1)
/* 8023C064  7C 7E 1B 78 */	mr r30, r3
/* 8023C068  48 00 00 28 */	b 0x28
/* 8023C06C  80 7E 00 C4 */	lwz r3, 0xc4(r30)
/* 8023C070  57 E0 13 BA */	rlwinm r0, r31, 2, 0xe, 0x1d
/* 8023C074  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023C078  2C 03 00 00 */	cmpwi r3, 0
/* 8023C07C  41 82 00 10 */	beq 0x10
/* 8023C080  80 9E 00 00 */	lwz r4, 0(r30)
/* 8023C084  38 63 00 08 */	addi r3, r3, 8
/* 8023C088  4B FE E1 89 */	bl -0x11e78
/* 8023C08C  3B FF 00 01 */	addi r31, r31, 1
/* 8023C090  81 9E 00 B4 */	lwz r12, 0xb4(r30)
/* 8023C094  7F C3 F3 78 */	mr r3, r30
/* 8023C098  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023C09C  7D 89 03 A6 */	mtctr r12
/* 8023C0A0  4E 80 04 21 */	bctrl
/* 8023C0A4  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023C0A8  57 E0 04 3E */	clrlwi r0, r31, 0x10
/* 8023C0AC  7C 00 18 40 */	cmplw r0, r3
/* 8023C0B0  41 80 FF BC */	blt -0x44
/* 8023C0B4  80 9E 00 00 */	lwz r4, 0(r30)
/* 8023C0B8  38 7E 00 B8 */	addi r3, r30, 0xb8
/* 8023C0BC  4B FE E1 55 */	bl -0x11eac
/* 8023C0C0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C0C4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C0C8  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023C0CC  7C 08 03 A6 */	mtlr r0
/* 8023C0D0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C0D4  4E 80 00 20 */	blr
/* 8023C0D8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C0DC  7C 08 02 A6 */	mflr r0
/* 8023C0E0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C0E4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C0E8  3B E0 00 00 */	li r31, 0
/* 8023C0EC  93 C1 00 08 */	stw r30, 8(r1)
/* 8023C0F0  7C 7E 1B 78 */	mr r30, r3
/* 8023C0F4  48 00 00 28 */	b 0x28
/* 8023C0F8  80 7E 00 C4 */	lwz r3, 0xc4(r30)
/* 8023C0FC  57 E0 13 BA */	rlwinm r0, r31, 2, 0xe, 0x1d
/* 8023C100  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023C104  2C 03 00 00 */	cmpwi r3, 0
/* 8023C108  41 82 00 10 */	beq 0x10
/* 8023C10C  80 9E 00 00 */	lwz r4, 0(r30)
/* 8023C110  38 63 00 08 */	addi r3, r3, 8
/* 8023C114  4B FE E1 81 */	bl -0x11e80
/* 8023C118  3B FF 00 01 */	addi r31, r31, 1
/* 8023C11C  81 9E 00 B4 */	lwz r12, 0xb4(r30)
/* 8023C120  7F C3 F3 78 */	mr r3, r30
/* 8023C124  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023C128  7D 89 03 A6 */	mtctr r12
/* 8023C12C  4E 80 04 21 */	bctrl
/* 8023C130  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023C134  57 E0 04 3E */	clrlwi r0, r31, 0x10
/* 8023C138  7C 00 18 40 */	cmplw r0, r3
/* 8023C13C  41 80 FF BC */	blt -0x44
/* 8023C140  80 9E 00 00 */	lwz r4, 0(r30)
/* 8023C144  38 7E 00 B8 */	addi r3, r30, 0xb8
/* 8023C148  4B FE E1 4D */	bl -0x11eb4
/* 8023C14C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C150  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C154  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023C158  7C 08 03 A6 */	mtlr r0
/* 8023C15C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C160  4E 80 00 20 */	blr
/* 8023C164  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023C168  7C 08 02 A6 */	mflr r0
/* 8023C16C  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023C170  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023C174  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023C178  7C 9E 23 78 */	mr r30, r4
/* 8023C17C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023C180  7C 7D 1B 78 */	mr r29, r3
/* 8023C184  80 03 00 00 */	lwz r0, 0(r3)
/* 8023C188  7C 04 00 40 */	cmplw r4, r0
/* 8023C18C  41 82 00 D4 */	beq 0xd4
/* 8023C190  3B E0 00 00 */	li r31, 0
/* 8023C194  48 00 00 28 */	b 0x28
/* 8023C198  80 7D 00 C4 */	lwz r3, 0xc4(r29)
/* 8023C19C  57 E0 13 BA */	rlwinm r0, r31, 2, 0xe, 0x1d
/* 8023C1A0  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023C1A4  2C 03 00 00 */	cmpwi r3, 0
/* 8023C1A8  41 82 00 10 */	beq 0x10
/* 8023C1AC  80 9D 00 00 */	lwz r4, 0(r29)
/* 8023C1B0  38 63 00 08 */	addi r3, r3, 8
/* 8023C1B4  4B FE E0 E1 */	bl -0x11f20
/* 8023C1B8  3B FF 00 01 */	addi r31, r31, 1
/* 8023C1BC  81 9D 00 B4 */	lwz r12, 0xb4(r29)
/* 8023C1C0  7F A3 EB 78 */	mr r3, r29
/* 8023C1C4  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023C1C8  7D 89 03 A6 */	mtctr r12
/* 8023C1CC  4E 80 04 21 */	bctrl
/* 8023C1D0  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023C1D4  57 E0 04 3E */	clrlwi r0, r31, 0x10
/* 8023C1D8  7C 00 18 40 */	cmplw r0, r3
/* 8023C1DC  41 80 FF BC */	blt -0x44
/* 8023C1E0  80 9D 00 00 */	lwz r4, 0(r29)
/* 8023C1E4  38 7D 00 B8 */	addi r3, r29, 0xb8
/* 8023C1E8  4B FE E0 AD */	bl -0x11f54
/* 8023C1EC  7F A3 EB 78 */	mr r3, r29
/* 8023C1F0  7F C4 F3 78 */	mr r4, r30
/* 8023C1F4  48 00 0C D5 */	bl 0xcd4
/* 8023C1F8  7C 7E 1B 78 */	mr r30, r3
/* 8023C1FC  3B E0 00 00 */	li r31, 0
/* 8023C200  48 00 00 28 */	b 0x28
/* 8023C204  80 7D 00 C4 */	lwz r3, 0xc4(r29)
/* 8023C208  57 E0 13 BA */	rlwinm r0, r31, 2, 0xe, 0x1d
/* 8023C20C  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023C210  2C 03 00 00 */	cmpwi r3, 0
/* 8023C214  41 82 00 10 */	beq 0x10
/* 8023C218  80 9D 00 00 */	lwz r4, 0(r29)
/* 8023C21C  38 63 00 08 */	addi r3, r3, 8
/* 8023C220  4B FE DF F1 */	bl -0x12010
/* 8023C224  3B FF 00 01 */	addi r31, r31, 1
/* 8023C228  81 9D 00 B4 */	lwz r12, 0xb4(r29)
/* 8023C22C  7F A3 EB 78 */	mr r3, r29
/* 8023C230  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023C234  7D 89 03 A6 */	mtctr r12
/* 8023C238  4E 80 04 21 */	bctrl
/* 8023C23C  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023C240  57 E0 04 3E */	clrlwi r0, r31, 0x10
/* 8023C244  7C 00 18 40 */	cmplw r0, r3
/* 8023C248  41 80 FF BC */	blt -0x44
/* 8023C24C  80 9D 00 00 */	lwz r4, 0(r29)
/* 8023C250  38 7D 00 B8 */	addi r3, r29, 0xb8
/* 8023C254  4B FE DF BD */	bl -0x12044
/* 8023C258  7F C3 F3 78 */	mr r3, r30
/* 8023C25C  48 00 00 08 */	b 0x8
/* 8023C260  7F C3 F3 78 */	mr r3, r30
/* 8023C264  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023C268  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023C26C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023C270  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023C274  7C 08 03 A6 */	mtlr r0
/* 8023C278  38 21 00 20 */	addi r1, r1, 0x20
/* 8023C27C  4E 80 00 20 */	blr
/* 8023C280  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C284  7C 08 02 A6 */	mflr r0
/* 8023C288  2C 04 00 00 */	cmpwi r4, 0
/* 8023C28C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C290  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C294  7C 7F 1B 78 */	mr r31, r3
/* 8023C298  41 82 00 10 */	beq 0x10
/* 8023C29C  2C 04 00 01 */	cmpwi r4, 1
/* 8023C2A0  41 82 00 5C */	beq 0x5c
/* 8023C2A4  48 00 00 70 */	b 0x70
/* 8023C2A8  A0 03 00 CC */	lhz r0, 0xcc(r3)
/* 8023C2AC  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023C2B0  41 82 00 64 */	beq 0x64
/* 8023C2B4  80 63 00 C4 */	lwz r3, 0xc4(r3)
/* 8023C2B8  38 80 00 00 */	li r4, 0
/* 8023C2BC  80 63 00 10 */	lwz r3, 0x10(r3)
/* 8023C2C0  2C 03 00 00 */	cmpwi r3, 0
/* 8023C2C4  41 82 00 14 */	beq 0x14
/* 8023C2C8  A0 03 00 18 */	lhz r0, 0x18(r3)
/* 8023C2CC  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 8023C2D0  41 82 00 08 */	beq 0x8
/* 8023C2D4  38 80 00 01 */	li r4, 1
/* 8023C2D8  7F E5 FB 78 */	mr r5, r31
/* 8023C2DC  38 60 00 03 */	li r3, 3
/* 8023C2E0  48 00 40 79 */	bl 0x4078
/* 8023C2E4  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8023C2E8  38 9F 00 D0 */	addi r4, r31, 0xd0
/* 8023C2EC  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023C2F0  7D 89 03 A6 */	mtctr r12
/* 8023C2F4  4E 80 04 21 */	bctrl
/* 8023C2F8  48 00 00 1C */	b 0x1c
/* 8023C2FC  A0 03 00 CC */	lhz r0, 0xcc(r3)
/* 8023C300  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023C304  41 82 00 10 */	beq 0x10
/* 8023C308  7F E4 FB 78 */	mr r4, r31
/* 8023C30C  38 60 00 03 */	li r3, 3
/* 8023C310  48 00 45 35 */	bl 0x4534
/* 8023C314  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C318  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C31C  7C 08 03 A6 */	mtlr r0
/* 8023C320  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C324  4E 80 00 20 */	blr
/* 8023C328  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C32C  7C 08 02 A6 */	mflr r0
/* 8023C330  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C334  34 01 00 09 */	addic. r0, r1, 9
/* 8023C338  41 82 00 18 */	beq 0x18
/* 8023C33C  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C340  80 E3 00 C8 */	lwz r7, 0xc8(r3)
/* 8023C344  7C 05 00 50 */	subf r0, r5, r0
/* 8023C348  7C 07 00 AE */	lbzx r0, r7, r0
/* 8023C34C  98 01 00 09 */	stb r0, 9(r1)
/* 8023C350  34 01 00 08 */	addic. r0, r1, 8
/* 8023C354  41 82 00 1C */	beq 0x1c
/* 8023C358  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C35C  80 63 00 C8 */	lwz r3, 0xc8(r3)
/* 8023C360  7C 05 00 50 */	subf r0, r5, r0
/* 8023C364  7C 63 02 14 */	add r3, r3, r0
/* 8023C368  88 03 00 01 */	lbz r0, 1(r3)
/* 8023C36C  98 01 00 08 */	stb r0, 8(r1)
/* 8023C370  88 01 00 09 */	lbz r0, 9(r1)
/* 8023C374  7C 83 23 78 */	mr r3, r4
/* 8023C378  7C 00 32 14 */	add r0, r0, r6
/* 8023C37C  54 04 06 3E */	clrlwi r4, r0, 0x18
/* 8023C380  4B E3 19 71 */	bl -0x1ce690
/* 8023C384  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C388  7C 08 03 A6 */	mtlr r0
/* 8023C38C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C390  4E 80 00 20 */	blr
/* 8023C394  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C398  7C 08 02 A6 */	mflr r0
/* 8023C39C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C3A0  34 01 00 09 */	addic. r0, r1, 9
/* 8023C3A4  41 82 00 18 */	beq 0x18
/* 8023C3A8  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C3AC  80 E3 00 C8 */	lwz r7, 0xc8(r3)
/* 8023C3B0  7C 05 00 50 */	subf r0, r5, r0
/* 8023C3B4  7C 07 00 AE */	lbzx r0, r7, r0
/* 8023C3B8  98 01 00 09 */	stb r0, 9(r1)
/* 8023C3BC  34 01 00 08 */	addic. r0, r1, 8
/* 8023C3C0  41 82 00 1C */	beq 0x1c
/* 8023C3C4  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C3C8  80 63 00 C8 */	lwz r3, 0xc8(r3)
/* 8023C3CC  7C 05 00 50 */	subf r0, r5, r0
/* 8023C3D0  7C 63 02 14 */	add r3, r3, r0
/* 8023C3D4  88 03 00 01 */	lbz r0, 1(r3)
/* 8023C3D8  98 01 00 08 */	stb r0, 8(r1)
/* 8023C3DC  88 01 00 09 */	lbz r0, 9(r1)
/* 8023C3E0  7C 83 23 78 */	mr r3, r4
/* 8023C3E4  7C 00 32 14 */	add r0, r0, r6
/* 8023C3E8  54 04 06 3E */	clrlwi r4, r0, 0x18
/* 8023C3EC  4B E3 19 35 */	bl -0x1ce6cc
/* 8023C3F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C3F4  7C 08 03 A6 */	mtlr r0
/* 8023C3F8  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C3FC  4E 80 00 20 */	blr
/* 8023C400  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C404  7C 08 02 A6 */	mflr r0
/* 8023C408  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C40C  34 01 00 09 */	addic. r0, r1, 9
/* 8023C410  41 82 00 18 */	beq 0x18
/* 8023C414  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C418  81 03 00 C8 */	lwz r8, 0xc8(r3)
/* 8023C41C  7C 05 00 50 */	subf r0, r5, r0
/* 8023C420  7C 08 00 AE */	lbzx r0, r8, r0
/* 8023C424  98 01 00 09 */	stb r0, 9(r1)
/* 8023C428  34 01 00 08 */	addic. r0, r1, 8
/* 8023C42C  41 82 00 1C */	beq 0x1c
/* 8023C430  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C434  81 03 00 C8 */	lwz r8, 0xc8(r3)
/* 8023C438  7C 05 00 50 */	subf r0, r5, r0
/* 8023C43C  7D 08 02 14 */	add r8, r8, r0
/* 8023C440  88 08 00 01 */	lbz r0, 1(r8)
/* 8023C444  98 01 00 08 */	stb r0, 8(r1)
/* 8023C448  54 A0 10 3A */	slwi r0, r5, 2
/* 8023C44C  80 63 00 C8 */	lwz r3, 0xc8(r3)
/* 8023C450  7C 05 00 50 */	subf r0, r5, r0
/* 8023C454  89 01 00 09 */	lbz r8, 9(r1)
/* 8023C458  7C A3 02 14 */	add r5, r3, r0
/* 8023C45C  7C 83 23 78 */	mr r3, r4
/* 8023C460  7C 08 32 14 */	add r0, r8, r6
/* 8023C464  88 C5 00 02 */	lbz r6, 2(r5)
/* 8023C468  7C E4 3B 78 */	mr r4, r7
/* 8023C46C  54 05 06 3E */	clrlwi r5, r0, 0x18
/* 8023C470  4B FE DC F5 */	bl -0x1230c
/* 8023C474  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C478  7C 08 03 A6 */	mtlr r0
/* 8023C47C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C480  4E 80 00 20 */	blr
/* 8023C484  80 63 00 C4 */	lwz r3, 0xc4(r3)
/* 8023C488  80 63 00 14 */	lwz r3, 0x14(r3)
/* 8023C48C  2C 03 00 00 */	cmpwi r3, 0
/* 8023C490  4D 82 00 20 */	beqlr
/* 8023C494  4B FE 27 34 */	b -0x1d8cc
/* 8023C498  4E 80 00 20 */	blr
/* 8023C49C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C4A0  7C 08 02 A6 */	mflr r0
/* 8023C4A4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C4A8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C4AC  7C 7F 1B 78 */	mr r31, r3
/* 8023C4B0  93 C1 00 08 */	stw r30, 8(r1)
/* 8023C4B4  48 00 08 21 */	bl 0x820
/* 8023C4B8  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 8023C4BC  80 83 00 10 */	lwz r4, 0x10(r3)
/* 8023C4C0  2C 04 00 00 */	cmpwi r4, 0
/* 8023C4C4  41 82 00 60 */	beq 0x60
/* 8023C4C8  A0 1F 00 CC */	lhz r0, 0xcc(r31)
/* 8023C4CC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023C4D0  41 82 00 48 */	beq 0x48
/* 8023C4D4  80 63 00 14 */	lwz r3, 0x14(r3)
/* 8023C4D8  2C 03 00 00 */	cmpwi r3, 0
/* 8023C4DC  41 82 00 2C */	beq 0x2c
/* 8023C4E0  88 03 00 00 */	lbz r0, 0(r3)
/* 8023C4E4  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023C4E8  41 82 00 20 */	beq 0x20
/* 8023C4EC  A0 03 00 18 */	lhz r0, 0x18(r3)
/* 8023C4F0  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023C4F4  40 82 00 14 */	bne 0x14
/* 8023C4F8  A0 04 00 18 */	lhz r0, 0x18(r4)
/* 8023C4FC  60 00 00 08 */	ori r0, r0, 8
/* 8023C500  B0 04 00 18 */	sth r0, 0x18(r4)
/* 8023C504  48 00 00 20 */	b 0x20
/* 8023C508  A0 04 00 18 */	lhz r0, 0x18(r4)
/* 8023C50C  54 00 07 76 */	rlwinm r0, r0, 0, 0x1d, 0x1b
/* 8023C510  B0 04 00 18 */	sth r0, 0x18(r4)
/* 8023C514  48 00 00 10 */	b 0x10
/* 8023C518  A0 04 00 18 */	lhz r0, 0x18(r4)
/* 8023C51C  54 00 07 76 */	rlwinm r0, r0, 0, 0x1d, 0x1b
/* 8023C520  B0 04 00 18 */	sth r0, 0x18(r4)
/* 8023C524  3C 60 80 38 */	lis r3, 0x8038
/* 8023C528  38 9F 00 48 */	addi r4, r31, 0x48
/* 8023C52C  38 63 44 18 */	addi r3, r3, 0x4418
/* 8023C530  48 00 13 11 */	bl 0x1310
/* 8023C534  3B C0 00 00 */	li r30, 0
/* 8023C538  48 00 00 20 */	b 0x20
/* 8023C53C  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 8023C540  57 C0 13 BA */	rlwinm r0, r30, 2, 0xe, 0x1d
/* 8023C544  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023C548  2C 03 00 00 */	cmpwi r3, 0
/* 8023C54C  41 82 00 08 */	beq 0x8
/* 8023C550  4B FD FF 6D */	bl -0x20094
/* 8023C554  3B DE 00 01 */	addi r30, r30, 1
/* 8023C558  81 9F 00 B4 */	lwz r12, 0xb4(r31)
/* 8023C55C  7F E3 FB 78 */	mr r3, r31
/* 8023C560  81 8C 00 4C */	lwz r12, 0x4c(r12)
/* 8023C564  7D 89 03 A6 */	mtctr r12
/* 8023C568  4E 80 04 21 */	bctrl
/* 8023C56C  54 63 04 3E */	clrlwi r3, r3, 0x10
/* 8023C570  57 C0 04 3E */	clrlwi r0, r30, 0x10
/* 8023C574  7C 00 18 40 */	cmplw r0, r3
/* 8023C578  41 80 FF C4 */	blt -0x3c
/* 8023C57C  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 8023C580  80 63 00 00 */	lwz r3, 0(r3)
/* 8023C584  2C 03 00 00 */	cmpwi r3, 0
/* 8023C588  41 82 00 20 */	beq 0x20
/* 8023C58C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8023C590  38 A2 A0 7C */	addi r5, r2, -24452
/* 8023C594  38 63 00 08 */	addi r3, r3, 8
/* 8023C598  38 80 00 02 */	li r4, 2
/* 8023C59C  7C A5 00 AE */	lbzx r5, r5, r0
/* 8023C5A0  38 C0 00 00 */	li r6, 0
/* 8023C5A4  4B FE DB C1 */	bl -0x12440
/* 8023C5A8  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 8023C5AC  38 80 00 00 */	li r4, 0
/* 8023C5B0  80 A3 00 08 */	lwz r5, 8(r3)
/* 8023C5B4  2C 05 00 00 */	cmpwi r5, 0
/* 8023C5B8  41 82 00 14 */	beq 0x14
/* 8023C5BC  88 05 00 00 */	lbz r0, 0(r5)
/* 8023C5C0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023C5C4  41 82 00 08 */	beq 0x8
/* 8023C5C8  38 80 00 01 */	li r4, 1
/* 8023C5CC  80 A3 00 04 */	lwz r5, 4(r3)
/* 8023C5D0  2C 05 00 00 */	cmpwi r5, 0
/* 8023C5D4  41 82 00 44 */	beq 0x44
/* 8023C5D8  2C 04 00 00 */	cmpwi r4, 0
/* 8023C5DC  38 60 00 00 */	li r3, 0
/* 8023C5E0  41 82 00 14 */	beq 0x14
/* 8023C5E4  A0 1F 00 CC */	lhz r0, 0xcc(r31)
/* 8023C5E8  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023C5EC  41 82 00 08 */	beq 0x8
/* 8023C5F0  38 60 00 01 */	li r3, 1
/* 8023C5F4  2C 03 00 00 */	cmpwi r3, 0
/* 8023C5F8  41 82 00 14 */	beq 0x14
/* 8023C5FC  A0 05 00 14 */	lhz r0, 0x14(r5)
/* 8023C600  60 00 00 10 */	ori r0, r0, 0x10
/* 8023C604  B0 05 00 14 */	sth r0, 0x14(r5)
/* 8023C608  48 00 00 10 */	b 0x10
/* 8023C60C  A0 05 00 14 */	lhz r0, 0x14(r5)
/* 8023C610  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8023C614  B0 05 00 14 */	sth r0, 0x14(r5)
/* 8023C618  2C 04 00 00 */	cmpwi r4, 0
/* 8023C61C  41 82 00 34 */	beq 0x34
/* 8023C620  A0 1F 00 CC */	lhz r0, 0xcc(r31)
/* 8023C624  80 7F 00 C4 */	lwz r3, 0xc4(r31)
/* 8023C628  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023C62C  80 63 00 08 */	lwz r3, 8(r3)
/* 8023C630  40 82 00 14 */	bne 0x14
/* 8023C634  A0 03 00 14 */	lhz r0, 0x14(r3)
/* 8023C638  60 00 00 04 */	ori r0, r0, 4
/* 8023C63C  B0 03 00 14 */	sth r0, 0x14(r3)
/* 8023C640  48 00 00 10 */	b 0x10
/* 8023C644  A0 03 00 14 */	lhz r0, 0x14(r3)
/* 8023C648  54 00 07 B8 */	rlwinm r0, r0, 0, 0x1e, 0x1c
/* 8023C64C  B0 03 00 14 */	sth r0, 0x14(r3)
/* 8023C650  A0 7F 00 CC */	lhz r3, 0xcc(r31)
/* 8023C654  80 0D 93 B0 */	lwz r0, -0x6c50(r13)
/* 8023C658  54 63 07 39 */	rlwinm. r3, r3, 0, 0x1c, 0x1c
/* 8023C65C  54 03 07 76 */	rlwinm r3, r0, 0, 0x1d, 0x1b
/* 8023C660  41 82 00 08 */	beq 0x8
/* 8023C664  60 03 00 08 */	ori r3, r0, 8
/* 8023C668  90 6D 93 B0 */	stw r3, -0x6c50(r13)
/* 8023C66C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C670  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023C674  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C678  7C 08 03 A6 */	mtlr r0
/* 8023C67C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C680  4E 80 00 20 */	blr
/* 8023C684  38 63 FF 48 */	addi r3, r3, -184
/* 8023C688  4B FF F3 90 */	b -0xc70
/* 8023C68C  38 63 FF 48 */	addi r3, r3, -184
/* 8023C690  4B FF FB F0 */	b -0x410
/* 8023C694  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023C698  7C 08 02 A6 */	mflr r0
/* 8023C69C  3C E0 80 2A */	lis r7, 0x802a
/* 8023C6A0  38 C0 00 00 */	li r6, 0
/* 8023C6A4  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023C6A8  38 E7 3E B0 */	addi r7, r7, 0x3eb0
/* 8023C6AC  38 A0 1F F7 */	li r5, 0x1ff7
/* 8023C6B0  38 00 00 3F */	li r0, 0x3f
/* 8023C6B4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023C6B8  7C 9F 23 78 */	mr r31, r4
/* 8023C6BC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023C6C0  7C 7E 1B 78 */	mr r30, r3
/* 8023C6C4  90 E3 00 B4 */	stw r7, 0xb4(r3)
/* 8023C6C8  90 83 00 00 */	stw r4, 0(r3)
/* 8023C6CC  90 C3 00 04 */	stw r6, 4(r3)
/* 8023C6D0  90 C3 00 08 */	stw r6, 8(r3)
/* 8023C6D4  90 C3 00 0C */	stw r6, 0xc(r3)
/* 8023C6D8  B0 A3 00 10 */	sth r5, 0x10(r3)
/* 8023C6DC  B0 C3 00 12 */	sth r6, 0x12(r3)
/* 8023C6E0  B0 03 00 14 */	sth r0, 0x14(r3)
/* 8023C6E4  38 63 00 48 */	addi r3, r3, 0x48
/* 8023C6E8  48 00 0B CD */	bl 0xbcc
/* 8023C6EC  80 9E 00 00 */	lwz r4, 0(r30)
/* 8023C6F0  7F E3 FB 78 */	mr r3, r31
/* 8023C6F4  88 84 00 F4 */	lbz r4, 0xf4(r4)
/* 8023C6F8  4B E3 2C 99 */	bl -0x1cd368
/* 8023C6FC  90 61 00 08 */	stw r3, 8(r1)
/* 8023C700  38 61 00 08 */	addi r3, r1, 8
/* 8023C704  38 9E 00 18 */	addi r4, r30, 0x18
/* 8023C708  4B E2 E0 59 */	bl -0x1d1fa8
/* 8023C70C  38 60 00 48 */	li r3, 0x48
/* 8023C710  4B FE D6 BD */	bl -0x12944
/* 8023C714  2C 03 00 00 */	cmpwi r3, 0
/* 8023C718  41 82 00 08 */	beq 0x8
/* 8023C71C  48 00 38 09 */	bl 0x3808
/* 8023C720  38 00 00 00 */	li r0, 0
/* 8023C724  90 7E 00 0C */	stw r3, 0xc(r30)
/* 8023C728  7F C3 F3 78 */	mr r3, r30
/* 8023C72C  90 1E 00 B0 */	stw r0, 0xb0(r30)
/* 8023C730  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023C734  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023C738  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023C73C  7C 08 03 A6 */	mtlr r0
/* 8023C740  38 21 00 20 */	addi r1, r1, 0x20
/* 8023C744  4E 80 00 20 */	blr
/* 8023C748  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C74C  7C 08 02 A6 */	mflr r0
/* 8023C750  2C 03 00 00 */	cmpwi r3, 0
/* 8023C754  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C758  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C75C  7C 9F 23 78 */	mr r31, r4
/* 8023C760  93 C1 00 08 */	stw r30, 8(r1)
/* 8023C764  7C 7E 1B 78 */	mr r30, r3
/* 8023C768  41 82 00 64 */	beq 0x64
/* 8023C76C  A0 03 00 12 */	lhz r0, 0x12(r3)
/* 8023C770  3C 80 80 2A */	lis r4, 0x802a
/* 8023C774  38 84 3E B0 */	addi r4, r4, 0x3eb0
/* 8023C778  90 83 00 B4 */	stw r4, 0xb4(r3)
/* 8023C77C  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 8023C780  40 82 00 14 */	bne 0x14
/* 8023C784  81 83 00 B4 */	lwz r12, 0xb4(r3)
/* 8023C788  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023C78C  7D 89 03 A6 */	mtctr r12
/* 8023C790  4E 80 04 21 */	bctrl
/* 8023C794  80 7E 00 0C */	lwz r3, 0xc(r30)
/* 8023C798  2C 03 00 00 */	cmpwi r3, 0
/* 8023C79C  41 82 00 18 */	beq 0x18
/* 8023C7A0  81 83 00 44 */	lwz r12, 0x44(r3)
/* 8023C7A4  38 80 00 01 */	li r4, 1
/* 8023C7A8  81 8C 00 08 */	lwz r12, 8(r12)
/* 8023C7AC  7D 89 03 A6 */	mtctr r12
/* 8023C7B0  4E 80 04 21 */	bctrl
/* 8023C7B4  2C 1F 00 00 */	cmpwi r31, 0
/* 8023C7B8  38 00 00 00 */	li r0, 0
/* 8023C7BC  90 1E 00 0C */	stw r0, 0xc(r30)
/* 8023C7C0  40 81 00 0C */	ble 0xc
/* 8023C7C4  7F C3 F3 78 */	mr r3, r30
/* 8023C7C8  4B FE D6 4D */	bl -0x129b4
/* 8023C7CC  7F C3 F3 78 */	mr r3, r30
/* 8023C7D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C7D4  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023C7D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C7DC  7C 08 03 A6 */	mtlr r0
/* 8023C7E0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C7E4  4E 80 00 20 */	blr
/* 8023C7E8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C7EC  7C 08 02 A6 */	mflr r0
/* 8023C7F0  2C 03 00 00 */	cmpwi r3, 0
/* 8023C7F4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C7F8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C7FC  7C 7F 1B 78 */	mr r31, r3
/* 8023C800  41 82 00 10 */	beq 0x10
/* 8023C804  2C 04 00 00 */	cmpwi r4, 0
/* 8023C808  40 81 00 08 */	ble 0x8
/* 8023C80C  4B FE D6 09 */	bl -0x129f8
/* 8023C810  7F E3 FB 78 */	mr r3, r31
/* 8023C814  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C818  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C81C  7C 08 03 A6 */	mtlr r0
/* 8023C820  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C824  4E 80 00 20 */	blr
/* 8023C828  A0 03 00 12 */	lhz r0, 0x12(r3)
/* 8023C82C  60 00 00 08 */	ori r0, r0, 8
/* 8023C830  B0 03 00 12 */	sth r0, 0x12(r3)
/* 8023C834  4E 80 00 20 */	blr
/* 8023C838  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C83C  7C 08 02 A6 */	mflr r0
/* 8023C840  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C844  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C848  7C 7F 1B 78 */	mr r31, r3
/* 8023C84C  A0 03 00 12 */	lhz r0, 0x12(r3)
/* 8023C850  60 00 00 10 */	ori r0, r0, 0x10
/* 8023C854  B0 03 00 12 */	sth r0, 0x12(r3)
/* 8023C858  80 6D A2 E8 */	lwz r3, -0x5d18(r13)
/* 8023C85C  2C 03 00 00 */	cmpwi r3, 0
/* 8023C860  41 82 00 18 */	beq 0x18
/* 8023C864  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8023C868  4B FF BD 9D */	bl -0x4264
/* 8023C86C  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023C870  54 00 07 B8 */	rlwinm r0, r0, 0, 0x1e, 0x1c
/* 8023C874  B0 1F 00 12 */	sth r0, 0x12(r31)
/* 8023C878  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C87C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C880  7C 08 03 A6 */	mtlr r0
/* 8023C884  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C888  4E 80 00 20 */	blr
/* 8023C88C  90 83 00 04 */	stw r4, 4(r3)
/* 8023C890  4E 80 00 20 */	blr
/* 8023C894  90 83 00 08 */	stw r4, 8(r3)
/* 8023C898  4E 80 00 20 */	blr
/* 8023C89C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C8A0  7C 08 02 A6 */	mflr r0
/* 8023C8A4  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C8A8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C8AC  7C 7F 1B 78 */	mr r31, r3
/* 8023C8B0  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023C8B4  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 8023C8B8  41 82 00 0C */	beq 0xc
/* 8023C8BC  80 63 00 00 */	lwz r3, 0(r3)
/* 8023C8C0  4B E3 2C D1 */	bl -0x1cd330
/* 8023C8C4  81 9F 00 B4 */	lwz r12, 0xb4(r31)
/* 8023C8C8  7F E3 FB 78 */	mr r3, r31
/* 8023C8CC  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8023C8D0  7D 89 03 A6 */	mtctr r12
/* 8023C8D4  4E 80 04 21 */	bctrl
/* 8023C8D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C8DC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C8E0  7C 08 03 A6 */	mtlr r0
/* 8023C8E4  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C8E8  4E 80 00 20 */	blr
/* 8023C8EC  4E 80 00 20 */	blr
/* 8023C8F0  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023C8F4  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 8023C8F8  4D 82 00 20 */	beqlr
/* 8023C8FC  80 63 00 00 */	lwz r3, 0(r3)
/* 8023C900  4B E3 31 10 */	b -0x1ccef0
/* 8023C904  4E 80 00 20 */	blr
/* 8023C908  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023C90C  54 00 06 31 */	rlwinm. r0, r0, 0, 0x18, 0x18
/* 8023C910  4D 82 00 20 */	beqlr
/* 8023C914  80 63 00 00 */	lwz r3, 0(r3)
/* 8023C918  4B E3 31 18 */	b -0x1ccee8
/* 8023C91C  4E 80 00 20 */	blr
/* 8023C920  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023C924  7C 08 02 A6 */	mflr r0
/* 8023C928  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023C92C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023C930  7C 7F 1B 78 */	mr r31, r3
/* 8023C934  81 83 00 B4 */	lwz r12, 0xb4(r3)
/* 8023C938  81 8C 00 20 */	lwz r12, 0x20(r12)
/* 8023C93C  7D 89 03 A6 */	mtctr r12
/* 8023C940  4E 80 04 21 */	bctrl
/* 8023C944  A0 1F 00 10 */	lhz r0, 0x10(r31)
/* 8023C948  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 8023C94C  41 82 00 18 */	beq 0x18
/* 8023C950  80 7F 00 00 */	lwz r3, 0(r31)
/* 8023C954  4B E3 30 6D */	bl -0x1ccf94
/* 8023C958  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023C95C  60 00 00 02 */	ori r0, r0, 2
/* 8023C960  B0 1F 00 12 */	sth r0, 0x12(r31)
/* 8023C964  81 9F 00 B4 */	lwz r12, 0xb4(r31)
/* 8023C968  7F E3 FB 78 */	mr r3, r31
/* 8023C96C  81 8C 00 24 */	lwz r12, 0x24(r12)
/* 8023C970  7D 89 03 A6 */	mtctr r12
/* 8023C974  4E 80 04 21 */	bctrl
/* 8023C978  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023C97C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023C980  7C 08 03 A6 */	mtlr r0
/* 8023C984  38 21 00 10 */	addi r1, r1, 0x10
/* 8023C988  4E 80 00 20 */	blr
/* 8023C98C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023C990  7C 08 02 A6 */	mflr r0
/* 8023C994  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023C998  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023C99C  7C DF 33 78 */	mr r31, r6
/* 8023C9A0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023C9A4  7C BE 2B 78 */	mr r30, r5
/* 8023C9A8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023C9AC  7C 9D 23 78 */	mr r29, r4
/* 8023C9B0  93 81 00 10 */	stw r28, 0x10(r1)
/* 8023C9B4  7C 7C 1B 78 */	mr r28, r3
/* 8023C9B8  A0 03 00 12 */	lhz r0, 0x12(r3)
/* 8023C9BC  54 00 04 3C */	rlwinm r0, r0, 0, 0x10, 0x1e
/* 8023C9C0  B0 03 00 12 */	sth r0, 0x12(r3)
/* 8023C9C4  80 63 00 00 */	lwz r3, 0(r3)
/* 8023C9C8  4B E3 29 C9 */	bl -0x1cd638
/* 8023C9CC  90 61 00 08 */	stw r3, 8(r1)
/* 8023C9D0  7F C4 F3 78 */	mr r4, r30
/* 8023C9D4  38 61 00 08 */	addi r3, r1, 8
/* 8023C9D8  4B E2 DA F9 */	bl -0x1d2508
/* 8023C9DC  81 9C 00 B4 */	lwz r12, 0xb4(r28)
/* 8023C9E0  7F 83 E3 78 */	mr r3, r28
/* 8023C9E4  7F E5 FB 78 */	mr r5, r31
/* 8023C9E8  57 A4 06 3E */	clrlwi r4, r29, 0x18
/* 8023C9EC  81 8C 00 28 */	lwz r12, 0x28(r12)
/* 8023C9F0  7D 89 03 A6 */	mtctr r12
/* 8023C9F4  4E 80 04 21 */	bctrl
/* 8023C9F8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023C9FC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023CA00  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023CA04  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023CA08  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8023CA0C  7C 08 03 A6 */	mtlr r0
/* 8023CA10  38 21 00 20 */	addi r1, r1, 0x20
/* 8023CA14  4E 80 00 20 */	blr
/* 8023CA18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CA1C  7C 08 02 A6 */	mflr r0
/* 8023CA20  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CA24  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CA28  7C 7F 1B 78 */	mr r31, r3
/* 8023CA2C  81 83 00 B4 */	lwz r12, 0xb4(r3)
/* 8023CA30  81 8C 00 2C */	lwz r12, 0x2c(r12)
/* 8023CA34  7D 89 03 A6 */	mtctr r12
/* 8023CA38  4E 80 04 21 */	bctrl
/* 8023CA3C  A0 9F 00 10 */	lhz r4, 0x10(r31)
/* 8023CA40  38 60 00 00 */	li r3, 0
/* 8023CA44  54 80 05 EF */	rlwinm. r0, r4, 0, 0x17, 0x17
/* 8023CA48  41 82 00 14 */	beq 0x14
/* 8023CA4C  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023CA50  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023CA54  41 82 00 08 */	beq 0x8
/* 8023CA58  38 60 00 01 */	li r3, 1
/* 8023CA5C  2C 03 00 00 */	cmpwi r3, 0
/* 8023CA60  41 82 00 14 */	beq 0x14
/* 8023CA64  54 80 04 21 */	rlwinm. r0, r4, 0, 0x10, 0x10
/* 8023CA68  40 82 00 0C */	bne 0xc
/* 8023CA6C  80 7F 00 00 */	lwz r3, 0(r31)
/* 8023CA70  4B E3 2F E1 */	bl -0x1cd020
/* 8023CA74  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CA78  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CA7C  7C 08 03 A6 */	mtlr r0
/* 8023CA80  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CA84  4E 80 00 20 */	blr
/* 8023CA88  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023CA8C  54 00 05 AD */	rlwinm. r0, r0, 0, 0x16, 0x16
/* 8023CA90  4D 82 00 20 */	beqlr
/* 8023CA94  80 63 00 00 */	lwz r3, 0(r3)
/* 8023CA98  4B E3 30 38 */	b -0x1ccfc8
/* 8023CA9C  4E 80 00 20 */	blr
/* 8023CAA0  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023CAA4  54 00 05 6B */	rlwinm. r0, r0, 0, 0x15, 0x15
/* 8023CAA8  4D 82 00 20 */	beqlr
/* 8023CAAC  80 63 00 00 */	lwz r3, 0(r3)
/* 8023CAB0  4B E3 31 10 */	b -0x1ccef0
/* 8023CAB4  4E 80 00 20 */	blr
/* 8023CAB8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CABC  7C 08 02 A6 */	mflr r0
/* 8023CAC0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CAC4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CAC8  7C 7F 1B 78 */	mr r31, r3
/* 8023CACC  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023CAD0  54 00 05 29 */	rlwinm. r0, r0, 0, 0x14, 0x14
/* 8023CAD4  41 82 00 14 */	beq 0x14
/* 8023CAD8  38 80 00 01 */	li r4, 1
/* 8023CADC  48 00 03 FD */	bl 0x3fc
/* 8023CAE0  80 7F 00 00 */	lwz r3, 0(r31)
/* 8023CAE4  4B E3 31 3D */	bl -0x1ccec4
/* 8023CAE8  81 9F 00 B4 */	lwz r12, 0xb4(r31)
/* 8023CAEC  7F E3 FB 78 */	mr r3, r31
/* 8023CAF0  81 8C 00 30 */	lwz r12, 0x30(r12)
/* 8023CAF4  7D 89 03 A6 */	mtctr r12
/* 8023CAF8  4E 80 04 21 */	bctrl
/* 8023CAFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CB00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CB04  7C 08 03 A6 */	mtlr r0
/* 8023CB08  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CB0C  4E 80 00 20 */	blr
/* 8023CB10  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CB14  7C 08 02 A6 */	mflr r0
/* 8023CB18  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CB1C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CB20  7C 7F 1B 78 */	mr r31, r3
/* 8023CB24  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023CB28  54 00 04 E7 */	rlwinm. r0, r0, 0, 0x13, 0x13
/* 8023CB2C  41 82 00 14 */	beq 0x14
/* 8023CB30  38 80 00 00 */	li r4, 0
/* 8023CB34  48 00 03 A5 */	bl 0x3a4
/* 8023CB38  80 7F 00 00 */	lwz r3, 0(r31)
/* 8023CB3C  4B E3 31 65 */	bl -0x1cce9c
/* 8023CB40  81 9F 00 B4 */	lwz r12, 0xb4(r31)
/* 8023CB44  7F E3 FB 78 */	mr r3, r31
/* 8023CB48  81 8C 00 34 */	lwz r12, 0x34(r12)
/* 8023CB4C  7D 89 03 A6 */	mtctr r12
/* 8023CB50  4E 80 04 21 */	bctrl
/* 8023CB54  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CB58  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CB5C  7C 08 03 A6 */	mtlr r0
/* 8023CB60  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CB64  4E 80 00 20 */	blr
/* 8023CB68  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CB6C  7C 08 02 A6 */	mflr r0
/* 8023CB70  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CB74  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CB78  7C 7F 1B 78 */	mr r31, r3
/* 8023CB7C  80 03 00 04 */	lwz r0, 4(r3)
/* 8023CB80  2C 00 00 00 */	cmpwi r0, 0
/* 8023CB84  41 82 00 10 */	beq 0x10
/* 8023CB88  80 9F 00 00 */	lwz r4, 0(r31)
/* 8023CB8C  7C 03 03 78 */	mr r3, r0
/* 8023CB90  4B FE DA 2D */	bl -0x125d4
/* 8023CB94  80 7F 00 08 */	lwz r3, 8(r31)
/* 8023CB98  2C 03 00 00 */	cmpwi r3, 0
/* 8023CB9C  41 82 00 08 */	beq 0x8
/* 8023CBA0  4B FE A6 BD */	bl -0x15944
/* 8023CBA4  38 7F 00 18 */	addi r3, r31, 0x18
/* 8023CBA8  4B F5 D1 5D */	bl -0xa2ea4
/* 8023CBAC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CBB0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CBB4  7C 08 03 A6 */	mtlr r0
/* 8023CBB8  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CBBC  4E 80 00 20 */	blr
/* 8023CBC0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CBC4  7C 08 02 A6 */	mflr r0
/* 8023CBC8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CBCC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CBD0  7C 7F 1B 78 */	mr r31, r3
/* 8023CBD4  A0 03 00 10 */	lhz r0, 0x10(r3)
/* 8023CBD8  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023CBDC  41 82 00 60 */	beq 0x60
/* 8023CBE0  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023CBE4  48 00 33 A5 */	bl 0x33a4
/* 8023CBE8  A0 1F 00 10 */	lhz r0, 0x10(r31)
/* 8023CBEC  54 03 07 7B */	rlwinm. r3, r0, 0, 0x1d, 0x1d
/* 8023CBF0  41 82 00 20 */	beq 0x20
/* 8023CBF4  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023CBF8  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023CBFC  40 82 00 14 */	bne 0x14
/* 8023CC00  80 6D A2 E8 */	lwz r3, -0x5d18(r13)
/* 8023CC04  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8023CC08  4B FF B9 B1 */	bl -0x4650
/* 8023CC0C  48 00 00 30 */	b 0x30
/* 8023CC10  2C 03 00 00 */	cmpwi r3, 0
/* 8023CC14  40 82 00 28 */	bne 0x28
/* 8023CC18  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023CC1C  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023CC20  41 82 00 1C */	beq 0x1c
/* 8023CC24  80 6D A2 E8 */	lwz r3, -0x5d18(r13)
/* 8023CC28  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 8023CC2C  4B FF B9 D9 */	bl -0x4628
/* 8023CC30  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023CC34  54 00 07 B8 */	rlwinm r0, r0, 0, 0x1e, 0x1c
/* 8023CC38  B0 1F 00 12 */	sth r0, 0x12(r31)
/* 8023CC3C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CC40  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CC44  7C 08 03 A6 */	mtlr r0
/* 8023CC48  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CC4C  4E 80 00 20 */	blr
/* 8023CC50  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023CC54  7C 08 02 A6 */	mflr r0
/* 8023CC58  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023CC5C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023CC60  7C 9F 23 78 */	mr r31, r4
/* 8023CC64  7C A4 2B 78 */	mr r4, r5
/* 8023CC68  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023CC6C  7C 7E 1B 78 */	mr r30, r3
/* 8023CC70  38 63 00 48 */	addi r3, r3, 0x48
/* 8023CC74  48 00 0B CD */	bl 0xbcc
/* 8023CC78  80 7E 00 00 */	lwz r3, 0(r30)
/* 8023CC7C  7F E4 FB 78 */	mr r4, r31
/* 8023CC80  4B E3 27 B1 */	bl -0x1cd850
/* 8023CC84  80 7E 00 00 */	lwz r3, 0(r30)
/* 8023CC88  4B E3 27 69 */	bl -0x1cd898
/* 8023CC8C  90 61 00 0C */	stw r3, 0xc(r1)
/* 8023CC90  38 61 00 0C */	addi r3, r1, 0xc
/* 8023CC94  38 9E 00 18 */	addi r4, r30, 0x18
/* 8023CC98  4B E2 DA C9 */	bl -0x1d2538
/* 8023CC9C  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8023CCA0  38 7E 00 48 */	addi r3, r30, 0x48
/* 8023CCA4  90 01 00 08 */	stw r0, 8(r1)
/* 8023CCA8  38 81 00 08 */	addi r4, r1, 8
/* 8023CCAC  81 9E 00 80 */	lwz r12, 0x80(r30)
/* 8023CCB0  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023CCB4  7D 89 03 A6 */	mtctr r12
/* 8023CCB8  4E 80 04 21 */	bctrl
/* 8023CCBC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023CCC0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023CCC4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023CCC8  7C 08 03 A6 */	mtlr r0
/* 8023CCCC  38 21 00 20 */	addi r1, r1, 0x20
/* 8023CCD0  4E 80 00 20 */	blr
/* 8023CCD4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CCD8  7C 08 02 A6 */	mflr r0
/* 8023CCDC  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CCE0  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CCE4  7C 7F 1B 78 */	mr r31, r3
/* 8023CCE8  38 9F 00 18 */	addi r4, r31, 0x18
/* 8023CCEC  80 A3 00 00 */	lwz r5, 0(r3)
/* 8023CCF0  88 65 00 F4 */	lbz r3, 0xf4(r5)
/* 8023CCF4  38 BF 00 48 */	addi r5, r31, 0x48
/* 8023CCF8  4B FE C7 69 */	bl -0x13898
/* 8023CCFC  48 00 35 E5 */	bl 0x35e4
/* 8023CD00  3C 80 80 38 */	lis r4, 0x8038
/* 8023CD04  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 8023CD08  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 8023CD0C  38 84 41 40 */	addi r4, r4, 0x4140
/* 8023CD10  90 04 00 04 */	stw r0, 4(r4)
/* 8023CD14  90 64 00 00 */	stw r3, 0(r4)
/* 8023CD18  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 8023CD1C  80 1F 00 24 */	lwz r0, 0x24(r31)
/* 8023CD20  90 04 00 0C */	stw r0, 0xc(r4)
/* 8023CD24  90 64 00 08 */	stw r3, 8(r4)
/* 8023CD28  80 7F 00 28 */	lwz r3, 0x28(r31)
/* 8023CD2C  80 1F 00 2C */	lwz r0, 0x2c(r31)
/* 8023CD30  90 04 00 14 */	stw r0, 0x14(r4)
/* 8023CD34  90 64 00 10 */	stw r3, 0x10(r4)
/* 8023CD38  80 7F 00 30 */	lwz r3, 0x30(r31)
/* 8023CD3C  80 1F 00 34 */	lwz r0, 0x34(r31)
/* 8023CD40  90 04 00 1C */	stw r0, 0x1c(r4)
/* 8023CD44  90 64 00 18 */	stw r3, 0x18(r4)
/* 8023CD48  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8023CD4C  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8023CD50  90 04 00 24 */	stw r0, 0x24(r4)
/* 8023CD54  90 64 00 20 */	stw r3, 0x20(r4)
/* 8023CD58  80 7F 00 40 */	lwz r3, 0x40(r31)
/* 8023CD5C  80 1F 00 44 */	lwz r0, 0x44(r31)
/* 8023CD60  90 04 00 2C */	stw r0, 0x2c(r4)
/* 8023CD64  90 64 00 28 */	stw r3, 0x28(r4)
/* 8023CD68  80 7F 00 04 */	lwz r3, 4(r31)
/* 8023CD6C  2C 03 00 00 */	cmpwi r3, 0
/* 8023CD70  41 82 00 14 */	beq 0x14
/* 8023CD74  80 DF 00 00 */	lwz r6, 0(r31)
/* 8023CD78  38 9F 00 18 */	addi r4, r31, 0x18
/* 8023CD7C  88 A6 00 F4 */	lbz r5, 0xf4(r6)
/* 8023CD80  4B FE D9 35 */	bl -0x126cc
/* 8023CD84  80 7F 00 08 */	lwz r3, 8(r31)
/* 8023CD88  2C 03 00 00 */	cmpwi r3, 0
/* 8023CD8C  41 82 00 18 */	beq 0x18
/* 8023CD90  38 9F 00 48 */	addi r4, r31, 0x48
/* 8023CD94  4B FE A4 E1 */	bl -0x15b20
/* 8023CD98  80 7F 00 08 */	lwz r3, 8(r31)
/* 8023CD9C  80 9F 00 00 */	lwz r4, 0(r31)
/* 8023CDA0  4B FE A5 19 */	bl -0x15ae8
/* 8023CDA4  48 00 48 45 */	bl 0x4844
/* 8023CDA8  80 1F 00 04 */	lwz r0, 4(r31)
/* 8023CDAC  2C 00 00 00 */	cmpwi r0, 0
/* 8023CDB0  41 82 00 38 */	beq 0x38
/* 8023CDB4  A0 1F 00 10 */	lhz r0, 0x10(r31)
/* 8023CDB8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023CDBC  41 82 00 2C */	beq 0x2c
/* 8023CDC0  38 7F 00 48 */	addi r3, r31, 0x48
/* 8023CDC4  48 00 0E 15 */	bl 0xe14
/* 8023CDC8  80 9F 00 04 */	lwz r4, 4(r31)
/* 8023CDCC  7C 65 1B 78 */	mr r5, r3
/* 8023CDD0  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023CDD4  80 64 00 20 */	lwz r3, 0x20(r4)
/* 8023CDD8  C0 45 00 04 */	lfs f2, 4(r5)
/* 8023CDDC  C0 65 00 08 */	lfs f3, 8(r5)
/* 8023CDE0  C0 85 00 0C */	lfs f4, 0xc(r5)
/* 8023CDE4  4B FF 1F 3D */	bl -0xe0c4
/* 8023CDE8  A0 1F 00 10 */	lhz r0, 0x10(r31)
/* 8023CDEC  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023CDF0  41 82 00 1C */	beq 0x1c
/* 8023CDF4  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023CDF8  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023CDFC  40 82 00 10 */	bne 0x10
/* 8023CE00  80 7F 00 0C */	lwz r3, 0xc(r31)
/* 8023CE04  38 9F 00 48 */	addi r4, r31, 0x48
/* 8023CE08  48 00 32 41 */	bl 0x3240
/* 8023CE0C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CE10  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CE14  7C 08 03 A6 */	mtlr r0
/* 8023CE18  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CE1C  4E 80 00 20 */	blr
/* 8023CE20  4E 80 00 20 */	blr
/* 8023CE24  4E 80 00 20 */	blr
/* 8023CE28  A0 A3 00 10 */	lhz r5, 0x10(r3)
/* 8023CE2C  38 80 00 00 */	li r4, 0
/* 8023CE30  54 A0 05 EF */	rlwinm. r0, r5, 0, 0x17, 0x17
/* 8023CE34  41 82 00 14 */	beq 0x14
/* 8023CE38  A0 03 00 12 */	lhz r0, 0x12(r3)
/* 8023CE3C  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023CE40  41 82 00 08 */	beq 0x8
/* 8023CE44  38 80 00 01 */	li r4, 1
/* 8023CE48  2C 04 00 00 */	cmpwi r4, 0
/* 8023CE4C  4D 82 00 20 */	beqlr
/* 8023CE50  54 A0 04 21 */	rlwinm. r0, r5, 0, 0x10, 0x10
/* 8023CE54  4D 82 00 20 */	beqlr
/* 8023CE58  80 63 00 00 */	lwz r3, 0(r3)
/* 8023CE5C  4B E3 2B F4 */	b -0x1cd40c
/* 8023CE60  4E 80 00 20 */	blr
/* 8023CE64  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023CE68  7C 08 02 A6 */	mflr r0
/* 8023CE6C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023CE70  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023CE74  7C 7F 1B 78 */	mr r31, r3
/* 8023CE78  80 03 00 04 */	lwz r0, 4(r3)
/* 8023CE7C  2C 00 00 00 */	cmpwi r0, 0
/* 8023CE80  41 82 00 0C */	beq 0xc
/* 8023CE84  7C 03 03 78 */	mr r3, r0
/* 8023CE88  4B FE D8 F9 */	bl -0x12708
/* 8023CE8C  80 7F 00 08 */	lwz r3, 8(r31)
/* 8023CE90  2C 03 00 00 */	cmpwi r3, 0
/* 8023CE94  41 82 00 10 */	beq 0x10
/* 8023CE98  88 03 00 04 */	lbz r0, 4(r3)
/* 8023CE9C  54 00 07 B8 */	rlwinm r0, r0, 0, 0x1e, 0x1c
/* 8023CEA0  98 03 00 04 */	stb r0, 4(r3)
/* 8023CEA4  A0 1F 00 12 */	lhz r0, 0x12(r31)
/* 8023CEA8  60 00 00 01 */	ori r0, r0, 1
/* 8023CEAC  54 00 07 FA */	rlwinm r0, r0, 0, 0x1f, 0x1d
/* 8023CEB0  B0 1F 00 12 */	sth r0, 0x12(r31)
/* 8023CEB4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023CEB8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023CEBC  7C 08 03 A6 */	mtlr r0
/* 8023CEC0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023CEC4  4E 80 00 20 */	blr
/* 8023CEC8  7C 65 1B 78 */	mr r5, r3
/* 8023CECC  80 63 00 00 */	lwz r3, 0(r3)
/* 8023CED0  90 85 00 00 */	stw r4, 0(r5)
/* 8023CED4  4E 80 00 20 */	blr
/* 8023CED8  2C 04 00 00 */	cmpwi r4, 0
/* 8023CEDC  38 A0 00 00 */	li r5, 0
/* 8023CEE0  41 82 00 30 */	beq 0x30
/* 8023CEE4  A0 63 00 14 */	lhz r3, 0x14(r3)
/* 8023CEE8  54 60 07 FF */	clrlwi. r0, r3, 0x1f
/* 8023CEEC  41 82 00 08 */	beq 0x8
/* 8023CEF0  60 A5 00 01 */	ori r5, r5, 1
/* 8023CEF4  54 60 07 BD */	rlwinm. r0, r3, 0, 0x1e, 0x1e
/* 8023CEF8  41 82 00 08 */	beq 0x8
/* 8023CEFC  60 A5 00 02 */	ori r5, r5, 2
/* 8023CF00  54 60 07 7B */	rlwinm. r0, r3, 0, 0x1d, 0x1d
/* 8023CF04  41 82 00 34 */	beq 0x34
/* 8023CF08  60 A5 00 04 */	ori r5, r5, 4
/* 8023CF0C  48 00 00 2C */	b 0x2c
/* 8023CF10  A0 63 00 14 */	lhz r3, 0x14(r3)
/* 8023CF14  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 8023CF18  41 82 00 08 */	beq 0x8
/* 8023CF1C  60 A5 00 01 */	ori r5, r5, 1
/* 8023CF20  54 60 06 F7 */	rlwinm. r0, r3, 0, 0x1b, 0x1b
/* 8023CF24  41 82 00 08 */	beq 0x8
/* 8023CF28  60 A5 00 02 */	ori r5, r5, 2
/* 8023CF2C  54 60 06 B5 */	rlwinm. r0, r3, 0, 0x1a, 0x1a
/* 8023CF30  41 82 00 08 */	beq 0x8
/* 8023CF34  60 A5 00 04 */	ori r5, r5, 4
/* 8023CF38  90 AD A2 88 */	stw r5, -0x5d78(r13)
/* 8023CF3C  7C 83 23 78 */	mr r3, r4
/* 8023CF40  38 80 00 01 */	li r4, 1
/* 8023CF44  4B FE C5 38 */	b -0x13ac8
/* 8023CF48  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8023CF4C  7C 08 02 A6 */	mflr r0
/* 8023CF50  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023CF54  BF 61 00 1C */	stmw r27, 0x1c(r1)
/* 8023CF58  7C 7E 1B 78 */	mr r30, r3
/* 8023CF5C  7C BB 2B 78 */	mr r27, r5
/* 8023CF60  7C DF 33 78 */	mr r31, r6
/* 8023CF64  80 03 00 04 */	lwz r0, 4(r3)
/* 8023CF68  7C 83 23 78 */	mr r3, r4
/* 8023CF6C  2C 00 00 00 */	cmpwi r0, 0
/* 8023CF70  41 82 00 0C */	beq 0xc
/* 8023CF74  2C 04 00 00 */	cmpwi r4, 0
/* 8023CF78  40 80 00 0C */	bge 0xc
/* 8023CF7C  38 60 00 00 */	li r3, 0
/* 8023CF80  48 00 01 64 */	b 0x164
/* 8023CF84  80 9E 00 00 */	lwz r4, 0(r30)
/* 8023CF88  7C 65 1B 78 */	mr r5, r3
/* 8023CF8C  38 61 00 08 */	addi r3, r1, 8
/* 8023CF90  3B 80 00 00 */	li r28, 0
/* 8023CF94  3B A0 00 00 */	li r29, 0
/* 8023CF98  4B E3 25 09 */	bl -0x1cdaf8
/* 8023CF9C  2C 1B 00 00 */	cmpwi r27, 0
/* 8023CFA0  41 82 01 14 */	beq 0x114
/* 8023CFA4  38 00 00 02 */	li r0, 2
/* 8023CFA8  38 80 00 00 */	li r4, 0
/* 8023CFAC  7C 09 03 A6 */	mtctr r0
/* 8023CFB0  80 61 00 0C */	lwz r3, 0xc(r1)
/* 8023CFB4  7C 03 20 AE */	lbzx r0, r3, r4
/* 8023CFB8  7C 00 07 74 */	extsb r0, r0
/* 8023CFBC  2C 00 FF FF */	cmpwi r0, -1
/* 8023CFC0  41 82 00 2C */	beq 0x2c
/* 8023CFC4  80 7E 00 04 */	lwz r3, 4(r30)
/* 8023CFC8  54 00 13 BA */	rlwinm r0, r0, 2, 0xe, 0x1d
/* 8023CFCC  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023CFD0  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023CFD4  A0 03 00 76 */	lhz r0, 0x76(r3)
/* 8023CFD8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023CFDC  41 82 00 10 */	beq 0x10
/* 8023CFE0  7C 7B E9 2E */	stwx r3, r27, r29
/* 8023CFE4  3B 9C 00 01 */	addi r28, r28, 1
/* 8023CFE8  3B BD 00 04 */	addi r29, r29, 4
/* 8023CFEC  80 61 00 0C */	lwz r3, 0xc(r1)
/* 8023CFF0  38 84 00 01 */	addi r4, r4, 1
/* 8023CFF4  7C 03 20 AE */	lbzx r0, r3, r4
/* 8023CFF8  7C 00 07 74 */	extsb r0, r0
/* 8023CFFC  2C 00 FF FF */	cmpwi r0, -1
/* 8023D000  41 82 00 2C */	beq 0x2c
/* 8023D004  80 7E 00 04 */	lwz r3, 4(r30)
/* 8023D008  54 00 13 BA */	rlwinm r0, r0, 2, 0xe, 0x1d
/* 8023D00C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023D010  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023D014  A0 03 00 76 */	lhz r0, 0x76(r3)
/* 8023D018  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023D01C  41 82 00 10 */	beq 0x10
/* 8023D020  7C 7B E9 2E */	stwx r3, r27, r29
/* 8023D024  3B 9C 00 01 */	addi r28, r28, 1
/* 8023D028  3B BD 00 04 */	addi r29, r29, 4
/* 8023D02C  80 61 00 0C */	lwz r3, 0xc(r1)
/* 8023D030  38 84 00 01 */	addi r4, r4, 1
/* 8023D034  7C 03 20 AE */	lbzx r0, r3, r4
/* 8023D038  7C 00 07 74 */	extsb r0, r0
/* 8023D03C  2C 00 FF FF */	cmpwi r0, -1
/* 8023D040  41 82 00 2C */	beq 0x2c
/* 8023D044  80 7E 00 04 */	lwz r3, 4(r30)
/* 8023D048  54 00 13 BA */	rlwinm r0, r0, 2, 0xe, 0x1d
/* 8023D04C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023D050  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023D054  A0 03 00 76 */	lhz r0, 0x76(r3)
/* 8023D058  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023D05C  41 82 00 10 */	beq 0x10
/* 8023D060  7C 7B E9 2E */	stwx r3, r27, r29
/* 8023D064  3B 9C 00 01 */	addi r28, r28, 1
/* 8023D068  3B BD 00 04 */	addi r29, r29, 4
/* 8023D06C  80 61 00 0C */	lwz r3, 0xc(r1)
/* 8023D070  38 84 00 01 */	addi r4, r4, 1
/* 8023D074  7C 03 20 AE */	lbzx r0, r3, r4
/* 8023D078  7C 00 07 74 */	extsb r0, r0
/* 8023D07C  2C 00 FF FF */	cmpwi r0, -1
/* 8023D080  41 82 00 2C */	beq 0x2c
/* 8023D084  80 7E 00 04 */	lwz r3, 4(r30)
/* 8023D088  54 00 13 BA */	rlwinm r0, r0, 2, 0xe, 0x1d
/* 8023D08C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 8023D090  7C 63 00 2E */	lwzx r3, r3, r0
/* 8023D094  A0 03 00 76 */	lhz r0, 0x76(r3)
/* 8023D098  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023D09C  41 82 00 10 */	beq 0x10
/* 8023D0A0  7C 7B E9 2E */	stwx r3, r27, r29
/* 8023D0A4  3B 9C 00 01 */	addi r28, r28, 1
/* 8023D0A8  3B BD 00 04 */	addi r29, r29, 4
/* 8023D0AC  38 84 00 01 */	addi r4, r4, 1
/* 8023D0B0  42 00 FF 00 */	bdnz -0x100
/* 8023D0B4  2C 1F 00 00 */	cmpwi r31, 0
/* 8023D0B8  41 82 00 28 */	beq 0x28
/* 8023D0BC  80 61 00 0C */	lwz r3, 0xc(r1)
/* 8023D0C0  88 63 00 08 */	lbz r3, 8(r3)
/* 8023D0C4  7C 60 07 74 */	extsb r0, r3
/* 8023D0C8  2C 00 FF FF */	cmpwi r0, -1
/* 8023D0CC  41 82 00 0C */	beq 0xc
/* 8023D0D0  90 7F 00 00 */	stw r3, 0(r31)
/* 8023D0D4  48 00 00 0C */	b 0xc
/* 8023D0D8  38 00 FF FF */	li r0, -1
/* 8023D0DC  90 1F 00 00 */	stw r0, 0(r31)
/* 8023D0E0  7F 83 E3 78 */	mr r3, r28
/* 8023D0E4  BB 61 00 1C */	lmw r27, 0x1c(r1)
/* 8023D0E8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8023D0EC  7C 08 03 A6 */	mtlr r0
/* 8023D0F0  38 21 00 30 */	addi r1, r1, 0x30
/* 8023D0F4  4E 80 00 20 */	blr
/* 8023D0F8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023D0FC  7C 08 02 A6 */	mflr r0
/* 8023D100  A1 23 00 00 */	lhz r9, 0(r3)
/* 8023D104  3D 00 80 2A */	lis r8, 0x802a
/* 8023D108  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023D10C  3C 00 43 30 */	lis r0, 0x4330
/* 8023D110  A0 E4 00 00 */	lhz r7, 0(r4)
/* 8023D114  38 C8 3E E8 */	addi r6, r8, 0x3ee8
/* 8023D118  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023D11C  7C BF 2B 78 */	mr r31, r5
/* 8023D120  A0 A3 00 02 */	lhz r5, 2(r3)
/* 8023D124  A1 4D A3 48 */	lhz r10, -0x5cb8(r13)
/* 8023D128  90 01 00 08 */	stw r0, 8(r1)
/* 8023D12C  A1 6D A3 4A */	lhz r11, -0x5cb6(r13)
/* 8023D130  91 41 00 0C */	stw r10, 0xc(r1)
/* 8023D134  A0 64 00 02 */	lhz r3, 2(r4)
/* 8023D138  90 01 00 10 */	stw r0, 0x10(r1)
/* 8023D13C  C8 41 00 08 */	lfd f2, 8(r1)
/* 8023D140  91 21 00 14 */	stw r9, 0x14(r1)
/* 8023D144  C9 42 A0 88 */	lfd f10, -0x5f78(r2)
/* 8023D148  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023D14C  91 61 00 0C */	stw r11, 0xc(r1)
/* 8023D150  EC 82 50 28 */	fsubs f4, f2, f10
/* 8023D154  EC 60 50 28 */	fsubs f3, f0, f10
/* 8023D158  88 0D A3 30 */	lbz r0, -0x5cd0(r13)
/* 8023D15C  C8 21 00 08 */	lfd f1, 8(r1)
/* 8023D160  90 E1 00 14 */	stw r7, 0x14(r1)
/* 8023D164  7C 00 07 75 */	extsb. r0, r0
/* 8023D168  ED 24 18 24 */	fdivs f9, f4, f3
/* 8023D16C  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023D170  91 41 00 0C */	stw r10, 0xc(r1)
/* 8023D174  C8 A1 00 08 */	lfd f5, 8(r1)
/* 8023D178  90 A1 00 14 */	stw r5, 0x14(r1)
/* 8023D17C  C8 81 00 10 */	lfd f4, 0x10(r1)
/* 8023D180  EC 41 50 28 */	fsubs f2, f1, f10
/* 8023D184  91 61 00 0C */	stw r11, 0xc(r1)
/* 8023D188  EC 00 50 28 */	fsubs f0, f0, f10
/* 8023D18C  C8 21 00 08 */	lfd f1, 8(r1)
/* 8023D190  EC E5 50 28 */	fsubs f7, f5, f10
/* 8023D194  EC C4 50 28 */	fsubs f6, f4, f10
/* 8023D198  ED 02 00 24 */	fdivs f8, f2, f0
/* 8023D19C  90 61 00 14 */	stw r3, 0x14(r1)
/* 8023D1A0  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023D1A4  91 41 00 0C */	stw r10, 0xc(r1)
/* 8023D1A8  C8 61 00 08 */	lfd f3, 8(r1)
/* 8023D1AC  91 41 00 14 */	stw r10, 0x14(r1)
/* 8023D1B0  C8 41 00 10 */	lfd f2, 0x10(r1)
/* 8023D1B4  EC C7 30 24 */	fdivs f6, f7, f6
/* 8023D1B8  91 61 00 0C */	stw r11, 0xc(r1)
/* 8023D1BC  91 61 00 14 */	stw r11, 0x14(r1)
/* 8023D1C0  B1 28 3E E8 */	sth r9, 0x3ee8(r8)
/* 8023D1C4  B0 E6 00 02 */	sth r7, 2(r6)
/* 8023D1C8  B0 A6 00 0C */	sth r5, 0xc(r6)
/* 8023D1CC  EC A1 50 28 */	fsubs f5, f1, f10
/* 8023D1D0  C8 21 00 08 */	lfd f1, 8(r1)
/* 8023D1D4  EC 80 50 28 */	fsubs f4, f0, f10
/* 8023D1D8  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023D1DC  EC 63 50 28 */	fsubs f3, f3, f10
/* 8023D1E0  B0 66 00 0E */	sth r3, 0xe(r6)
/* 8023D1E4  EC 42 50 28 */	fsubs f2, f2, f10
/* 8023D1E8  B1 46 00 18 */	sth r10, 0x18(r6)
/* 8023D1EC  EC 85 20 24 */	fdivs f4, f5, f4
/* 8023D1F0  B1 66 00 1A */	sth r11, 0x1a(r6)
/* 8023D1F4  D1 26 00 04 */	stfs f9, 4(r6)
/* 8023D1F8  D1 06 00 08 */	stfs f8, 8(r6)
/* 8023D1FC  D0 C6 00 10 */	stfs f6, 0x10(r6)
/* 8023D200  D0 86 00 14 */	stfs f4, 0x14(r6)
/* 8023D204  EC 43 10 24 */	fdivs f2, f3, f2
/* 8023D208  D0 46 00 1C */	stfs f2, 0x1c(r6)
/* 8023D20C  EC 21 50 28 */	fsubs f1, f1, f10
/* 8023D210  EC 00 50 28 */	fsubs f0, f0, f10
/* 8023D214  EC 01 00 24 */	fdivs f0, f1, f0
/* 8023D218  D0 06 00 20 */	stfs f0, 0x20(r6)
/* 8023D21C  40 82 00 18 */	bne 0x18
/* 8023D220  3C 60 80 38 */	lis r3, 0x8038
/* 8023D224  38 63 43 B0 */	addi r3, r3, 0x43b0
/* 8023D228  48 00 00 8D */	bl 0x8c
/* 8023D22C  38 00 00 01 */	li r0, 1
/* 8023D230  98 0D A3 30 */	stb r0, -0x5cd0(r13)
/* 8023D234  3C 60 80 38 */	lis r3, 0x8038
/* 8023D238  38 00 00 00 */	li r0, 0
/* 8023D23C  38 83 43 B0 */	addi r4, r3, 0x43b0
/* 8023D240  90 03 43 B0 */	stw r0, 0x43b0(r3)
/* 8023D244  80 04 00 04 */	lwz r0, 4(r4)
/* 8023D248  2C 00 00 01 */	cmpwi r0, 1
/* 8023D24C  41 82 00 18 */	beq 0x18
/* 8023D250  A0 64 00 34 */	lhz r3, 0x34(r4)
/* 8023D254  38 00 00 01 */	li r0, 1
/* 8023D258  90 04 00 04 */	stw r0, 4(r4)
/* 8023D25C  60 60 00 01 */	ori r0, r3, 1
/* 8023D260  B0 04 00 34 */	sth r0, 0x34(r4)
/* 8023D264  3C 60 80 38 */	lis r3, 0x8038
/* 8023D268  2C 1F 00 00 */	cmpwi r31, 0
/* 8023D26C  38 63 43 B0 */	addi r3, r3, 0x43b0
/* 8023D270  C0 22 A0 80 */	lfs f1, -0x5f80(r2)
/* 8023D274  C0 02 A0 84 */	lfs f0, -0x5f7c(r2)
/* 8023D278  D0 23 00 18 */	stfs f1, 0x18(r3)
/* 8023D27C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8023D280  40 82 00 08 */	bne 0x8
/* 8023D284  48 00 00 08 */	b 0x8
/* 8023D288  7F E3 FB 78 */	mr r3, r31
/* 8023D28C  90 6D A3 14 */	stw r3, -0x5cec(r13)
/* 8023D290  38 00 00 00 */	li r0, 0
/* 8023D294  90 03 00 3C */	stw r0, 0x3c(r3)
/* 8023D298  80 6D A3 10 */	lwz r3, -0x5cf0(r13)
/* 8023D29C  48 00 11 F1 */	bl 0x11f0
/* 8023D2A0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023D2A4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023D2A8  7C 08 03 A6 */	mtlr r0
/* 8023D2AC  38 21 00 20 */	addi r1, r1, 0x20
/* 8023D2B0  4E 80 00 20 */	blr
/* 8023D2B4  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 8023D2B8  7C 08 02 A6 */	mflr r0
/* 8023D2BC  3C A0 80 2A */	lis r5, 0x802a
/* 8023D2C0  C8 82 A0 88 */	lfd f4, -0x5f78(r2)
/* 8023D2C4  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023D2C8  3C 00 43 30 */	lis r0, 0x4330
/* 8023D2CC  38 A5 3E E8 */	addi r5, r5, 0x3ee8
/* 8023D2D0  C0 22 A0 90 */	lfs f1, -0x5f70(r2)
/* 8023D2D4  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8023D2D8  7C 7F 1B 78 */	mr r31, r3
/* 8023D2DC  C0 42 A0 94 */	lfs f2, -0x5f6c(r2)
/* 8023D2E0  80 8D A3 10 */	lwz r4, -0x5cf0(r13)
/* 8023D2E4  90 01 00 10 */	stw r0, 0x10(r1)
/* 8023D2E8  1C C4 00 0C */	mulli r6, r4, 0xc
/* 8023D2EC  90 01 00 18 */	stw r0, 0x18(r1)
/* 8023D2F0  7C 85 32 14 */	add r4, r5, r6
/* 8023D2F4  7C 05 32 2E */	lhzx r0, r5, r6
/* 8023D2F8  A0 84 00 02 */	lhz r4, 2(r4)
/* 8023D2FC  38 A1 00 08 */	addi r5, r1, 8
/* 8023D300  90 81 00 14 */	stw r4, 0x14(r1)
/* 8023D304  38 80 00 01 */	li r4, 1
/* 8023D308  38 C0 00 01 */	li r6, 1
/* 8023D30C  90 01 00 1C */	stw r0, 0x1c(r1)
/* 8023D310  C8 61 00 10 */	lfd f3, 0x10(r1)
/* 8023D314  C8 01 00 18 */	lfd f0, 0x18(r1)
/* 8023D318  EC 63 20 28 */	fsubs f3, f3, f4
/* 8023D31C  EC 00 20 28 */	fsubs f0, f0, f4
/* 8023D320  D0 61 00 0C */	stfs f3, 0xc(r1)
/* 8023D324  D0 01 00 08 */	stfs f0, 8(r1)
/* 8023D328  4B FE A3 99 */	bl -0x15c68
/* 8023D32C  C0 02 A0 80 */	lfs f0, -0x5f80(r2)
/* 8023D330  3C 60 80 2A */	lis r3, 0x802a
/* 8023D334  38 63 3F 0C */	addi r3, r3, 0x3f0c
/* 8023D338  38 00 00 00 */	li r0, 0
/* 8023D33C  90 7F 00 38 */	stw r3, 0x38(r31)
/* 8023D340  90 1F 00 3C */	stw r0, 0x3c(r31)
/* 8023D344  D0 1F 00 40 */	stfs f0, 0x40(r31)
/* 8023D348  D0 1F 00 44 */	stfs f0, 0x44(r31)
/* 8023D34C  80 6D A3 14 */	lwz r3, -0x5cec(r13)
/* 8023D350  7C 00 18 40 */	cmplw r0, r3
/* 8023D354  41 82 00 14 */	beq 0x14
/* 8023D358  A0 1F 00 34 */	lhz r0, 0x34(r31)
/* 8023D35C  90 7F 00 3C */	stw r3, 0x3c(r31)
/* 8023D360  60 00 00 01 */	ori r0, r0, 1
/* 8023D364  B0 1F 00 34 */	sth r0, 0x34(r31)
/* 8023D368  7F E3 FB 78 */	mr r3, r31
/* 8023D36C  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 8023D370  80 01 00 34 */	lwz r0, 0x34(r1)
/* 8023D374  7C 08 03 A6 */	mtlr r0
/* 8023D378  38 21 00 30 */	addi r1, r1, 0x30
/* 8023D37C  4E 80 00 20 */	blr
/* 8023D380  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8023D384  7C 08 02 A6 */	mflr r0
/* 8023D388  90 01 00 44 */	stw r0, 0x44(r1)
/* 8023D38C  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8023D390  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 8023D394  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 8023D398  F3 C1 00 28 */	psq_st f30, 40(r1), 0, qr0
/* 8023D39C  FF C0 08 90 */	fmr f30, f1
/* 8023D3A0  FF E0 10 90 */	fmr f31, f2
/* 8023D3A4  7C A6 2B 78 */	mr r6, r5
/* 8023D3A8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023D3AC  7C 9F 23 78 */	mr r31, r4
/* 8023D3B0  C0 22 A0 90 */	lfs f1, -0x5f70(r2)
/* 8023D3B4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023D3B8  C0 42 A0 94 */	lfs f2, -0x5f6c(r2)
/* 8023D3BC  7C 7E 1B 78 */	mr r30, r3
/* 8023D3C0  D0 61 00 08 */	stfs f3, 8(r1)
/* 8023D3C4  38 A1 00 08 */	addi r5, r1, 8
/* 8023D3C8  38 80 00 01 */	li r4, 1
/* 8023D3CC  D0 81 00 0C */	stfs f4, 0xc(r1)
/* 8023D3D0  4B FE A2 F1 */	bl -0x15d10
/* 8023D3D4  3C 60 80 2A */	lis r3, 0x802a
/* 8023D3D8  2C 1F 00 00 */	cmpwi r31, 0
/* 8023D3DC  38 63 3F 0C */	addi r3, r3, 0x3f0c
/* 8023D3E0  38 00 00 00 */	li r0, 0
/* 8023D3E4  90 7E 00 38 */	stw r3, 0x38(r30)
/* 8023D3E8  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 8023D3EC  D3 DE 00 40 */	stfs f30, 0x40(r30)
/* 8023D3F0  D3 FE 00 44 */	stfs f31, 0x44(r30)
/* 8023D3F4  41 82 00 08 */	beq 0x8
/* 8023D3F8  48 00 00 08 */	b 0x8
/* 8023D3FC  83 ED A3 14 */	lwz r31, -0x5cec(r13)
/* 8023D400  80 1E 00 3C */	lwz r0, 0x3c(r30)
/* 8023D404  7C 00 F8 40 */	cmplw r0, r31
/* 8023D408  41 82 00 14 */	beq 0x14
/* 8023D40C  A0 1E 00 34 */	lhz r0, 0x34(r30)
/* 8023D410  93 FE 00 3C */	stw r31, 0x3c(r30)
/* 8023D414  60 00 00 01 */	ori r0, r0, 1
/* 8023D418  B0 1E 00 34 */	sth r0, 0x34(r30)
/* 8023D41C  7F C3 F3 78 */	mr r3, r30
/* 8023D420  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 8023D424  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8023D428  E3 C1 00 28 */	psq_l f30, 40(r1), 0, qr0
/* 8023D42C  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 8023D430  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023D434  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023D438  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8023D43C  7C 08 03 A6 */	mtlr r0
/* 8023D440  38 21 00 40 */	addi r1, r1, 0x40
/* 8023D444  4E 80 00 20 */	blr
/* 8023D448  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023D44C  7C 08 02 A6 */	mflr r0
/* 8023D450  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023D454  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023D458  7C 9F 23 78 */	mr r31, r4
/* 8023D45C  93 C1 00 08 */	stw r30, 8(r1)
/* 8023D460  7C 7E 1B 78 */	mr r30, r3
/* 8023D464  4B FE A2 C1 */	bl -0x15d40
/* 8023D468  3C 80 80 2A */	lis r4, 0x802a
/* 8023D46C  7F C3 F3 78 */	mr r3, r30
/* 8023D470  38 84 3F 0C */	addi r4, r4, 0x3f0c
/* 8023D474  90 9E 00 38 */	stw r4, 0x38(r30)
/* 8023D478  80 1F 00 3C */	lwz r0, 0x3c(r31)
/* 8023D47C  90 1E 00 3C */	stw r0, 0x3c(r30)
/* 8023D480  80 9F 00 40 */	lwz r4, 0x40(r31)
/* 8023D484  80 1F 00 44 */	lwz r0, 0x44(r31)
/* 8023D488  90 1E 00 44 */	stw r0, 0x44(r30)
/* 8023D48C  90 9E 00 40 */	stw r4, 0x40(r30)
/* 8023D490  80 9F 00 48 */	lwz r4, 0x48(r31)
/* 8023D494  80 1F 00 4C */	lwz r0, 0x4c(r31)
/* 8023D498  90 1E 00 4C */	stw r0, 0x4c(r30)
/* 8023D49C  90 9E 00 48 */	stw r4, 0x48(r30)
/* 8023D4A0  80 9F 00 50 */	lwz r4, 0x50(r31)
/* 8023D4A4  80 1F 00 54 */	lwz r0, 0x54(r31)
/* 8023D4A8  90 1E 00 54 */	stw r0, 0x54(r30)
/* 8023D4AC  90 9E 00 50 */	stw r4, 0x50(r30)
/* 8023D4B0  80 9F 00 58 */	lwz r4, 0x58(r31)
/* 8023D4B4  80 1F 00 5C */	lwz r0, 0x5c(r31)
/* 8023D4B8  90 1E 00 5C */	stw r0, 0x5c(r30)
/* 8023D4BC  90 9E 00 58 */	stw r4, 0x58(r30)
/* 8023D4C0  80 9F 00 60 */	lwz r4, 0x60(r31)
/* 8023D4C4  80 1F 00 64 */	lwz r0, 0x64(r31)
/* 8023D4C8  90 1E 00 64 */	stw r0, 0x64(r30)
/* 8023D4CC  90 9E 00 60 */	stw r4, 0x60(r30)
/* 8023D4D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023D4D4  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023D4D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023D4DC  7C 08 03 A6 */	mtlr r0
/* 8023D4E0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023D4E4  4E 80 00 20 */	blr
/* 8023D4E8  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8023D4EC  7C 08 02 A6 */	mflr r0
/* 8023D4F0  90 01 00 64 */	stw r0, 0x64(r1)
/* 8023D4F4  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 8023D4F8  F3 E1 00 58 */	psq_st f31, 88(r1), 0, qr0
/* 8023D4FC  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 8023D500  F3 C1 00 48 */	psq_st f30, 72(r1), 0, qr0
/* 8023D504  DB A1 00 30 */	stfd f29, 0x30(r1)
/* 8023D508  F3 A1 00 38 */	psq_st f29, 56(r1), 0, qr0
/* 8023D50C  DB 81 00 20 */	stfd f28, 0x20(r1)
/* 8023D510  F3 81 00 28 */	psq_st f28, 40(r1), 0, qr0
/* 8023D514  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023D518  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023D51C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023D520  93 81 00 10 */	stw r28, 0x10(r1)
/* 8023D524  7C 7C 1B 78 */	mr r28, r3
/* 8023D528  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023D52C  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 8023D530  40 82 00 78 */	bne 0x78
/* 8023D534  38 ED A2 50 */	addi r7, r13, -23984
/* 8023D538  38 CD A2 58 */	addi r6, r13, -23976
/* 8023D53C  38 AD A3 28 */	addi r5, r13, -23768
/* 8023D540  38 8D A3 20 */	addi r4, r13, -23776
/* 8023D544  C3 ED A2 50 */	lfs f31, -0x5db0(r13)
/* 8023D548  C0 0D A3 20 */	lfs f0, -0x5ce0(r13)
/* 8023D54C  C3 C7 00 04 */	lfs f30, 4(r7)
/* 8023D550  C0 24 00 04 */	lfs f1, 4(r4)
/* 8023D554  C3 AD A2 58 */	lfs f29, -0x5da8(r13)
/* 8023D558  C0 4D A3 28 */	lfs f2, -0x5cd8(r13)
/* 8023D55C  C3 86 00 04 */	lfs f28, 4(r6)
/* 8023D560  C0 65 00 04 */	lfs f3, 4(r5)
/* 8023D564  D0 0D A2 50 */	stfs f0, -0x5db0(r13)
/* 8023D568  D0 27 00 04 */	stfs f1, 4(r7)
/* 8023D56C  D0 4D A2 58 */	stfs f2, -0x5da8(r13)
/* 8023D570  D0 66 00 04 */	stfs f3, 4(r6)
/* 8023D574  80 03 00 00 */	lwz r0, 0(r3)
/* 8023D578  2C 00 00 00 */	cmpwi r0, 0
/* 8023D57C  40 82 00 0C */	bne 0xc
/* 8023D580  4B FE A2 51 */	bl -0x15db0
/* 8023D584  48 00 00 08 */	b 0x8
/* 8023D588  4B FE A2 1D */	bl -0x15de4
/* 8023D58C  38 8D A2 50 */	addi r4, r13, -23984
/* 8023D590  38 6D A2 58 */	addi r3, r13, -23976
/* 8023D594  D3 ED A2 50 */	stfs f31, -0x5db0(r13)
/* 8023D598  D3 C4 00 04 */	stfs f30, 4(r4)
/* 8023D59C  D3 AD A2 58 */	stfs f29, -0x5da8(r13)
/* 8023D5A0  D3 83 00 04 */	stfs f28, 4(r3)
/* 8023D5A4  48 00 00 1C */	b 0x1c
/* 8023D5A8  80 03 00 00 */	lwz r0, 0(r3)
/* 8023D5AC  2C 00 00 00 */	cmpwi r0, 0
/* 8023D5B0  40 82 00 0C */	bne 0xc
/* 8023D5B4  4B FE A2 1D */	bl -0x15de4
/* 8023D5B8  48 00 00 08 */	b 0x8
/* 8023D5BC  4B FE A1 E9 */	bl -0x15e18
/* 8023D5C0  7F 83 E3 78 */	mr r3, r28
/* 8023D5C4  48 00 06 15 */	bl 0x614
/* 8023D5C8  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023D5CC  7C 7C 1B 78 */	mr r28, r3
/* 8023D5D0  C0 43 00 04 */	lfs f2, 4(r3)
/* 8023D5D4  C0 63 00 08 */	lfs f3, 8(r3)
/* 8023D5D8  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 8023D5DC  C0 A3 00 10 */	lfs f5, 0x10(r3)
/* 8023D5E0  C0 C3 00 14 */	lfs f6, 0x14(r3)
/* 8023D5E4  48 00 42 ED */	bl 0x42ec
/* 8023D5E8  C0 3C 00 0C */	lfs f1, 0xc(r28)
/* 8023D5EC  4B DE 3E 8D */	bl -0x21c174
/* 8023D5F0  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8023D5F4  7C 7D 1B 78 */	mr r29, r3
/* 8023D5F8  4B DE 3E 81 */	bl -0x21c180
/* 8023D5FC  C0 3C 00 04 */	lfs f1, 4(r28)
/* 8023D600  7C 7E 1B 78 */	mr r30, r3
/* 8023D604  4B DE 3E 75 */	bl -0x21c18c
/* 8023D608  C0 3C 00 00 */	lfs f1, 0(r28)
/* 8023D60C  7C 7F 1B 78 */	mr r31, r3
/* 8023D610  4B DE 3E 69 */	bl -0x21c198
/* 8023D614  7F E4 FB 78 */	mr r4, r31
/* 8023D618  7F C5 F3 78 */	mr r5, r30
/* 8023D61C  7F A6 EB 78 */	mr r6, r29
/* 8023D620  48 00 43 DD */	bl 0x43dc
/* 8023D624  80 7C 00 18 */	lwz r3, 0x18(r28)
/* 8023D628  80 9C 00 1C */	lwz r4, 0x1c(r28)
/* 8023D62C  48 00 44 A1 */	bl 0x44a0
/* 8023D630  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 8023D634  60 00 00 40 */	ori r0, r0, 0x40
/* 8023D638  B0 0D 93 B8 */	sth r0, -0x6c48(r13)
/* 8023D63C  E3 E1 00 58 */	psq_l f31, 88(r1), 0, qr0
/* 8023D640  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 8023D644  E3 C1 00 48 */	psq_l f30, 72(r1), 0, qr0
/* 8023D648  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 8023D64C  E3 A1 00 38 */	psq_l f29, 56(r1), 0, qr0
/* 8023D650  CB A1 00 30 */	lfd f29, 0x30(r1)
/* 8023D654  E3 81 00 28 */	psq_l f28, 40(r1), 0, qr0
/* 8023D658  CB 81 00 20 */	lfd f28, 0x20(r1)
/* 8023D65C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023D660  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023D664  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023D668  83 81 00 10 */	lwz r28, 0x10(r1)
/* 8023D66C  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8023D670  7C 08 03 A6 */	mtlr r0
/* 8023D674  38 21 00 60 */	addi r1, r1, 0x60
/* 8023D678  4E 80 00 20 */	blr
/* 8023D67C  94 21 FF 90 */	stwu r1, -0x70(r1)
/* 8023D680  7C 08 02 A6 */	mflr r0
/* 8023D684  90 01 00 74 */	stw r0, 0x74(r1)
/* 8023D688  DB E1 00 60 */	stfd f31, 0x60(r1)
/* 8023D68C  F3 E1 00 68 */	psq_st f31, 104(r1), 0, qr0
/* 8023D690  DB C1 00 50 */	stfd f30, 0x50(r1)
/* 8023D694  F3 C1 00 58 */	psq_st f30, 88(r1), 0, qr0
/* 8023D698  DB A1 00 40 */	stfd f29, 0x40(r1)
/* 8023D69C  F3 A1 00 48 */	psq_st f29, 72(r1), 0, qr0
/* 8023D6A0  DB 81 00 30 */	stfd f28, 0x30(r1)
/* 8023D6A4  F3 81 00 38 */	psq_st f28, 56(r1), 0, qr0
/* 8023D6A8  39 61 00 30 */	addi r11, r1, 0x30
/* 8023D6AC  4B DE 3E F5 */	bl -0x21c10c
/* 8023D6B0  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023D6B4  7C 7C 1B 78 */	mr r28, r3
/* 8023D6B8  7C 9B 23 78 */	mr r27, r4
/* 8023D6BC  54 00 06 73 */	rlwinm. r0, r0, 0, 0x19, 0x19
/* 8023D6C0  40 82 00 8C */	bne 0x8c
/* 8023D6C4  39 0D A2 50 */	addi r8, r13, -23984
/* 8023D6C8  38 ED A2 58 */	addi r7, r13, -23976
/* 8023D6CC  38 CD A3 28 */	addi r6, r13, -23768
/* 8023D6D0  38 AD A3 20 */	addi r5, r13, -23776
/* 8023D6D4  C3 CD A2 50 */	lfs f30, -0x5db0(r13)
/* 8023D6D8  C0 0D A3 20 */	lfs f0, -0x5ce0(r13)
/* 8023D6DC  C3 E8 00 04 */	lfs f31, 4(r8)
/* 8023D6E0  C0 25 00 04 */	lfs f1, 4(r5)
/* 8023D6E4  C3 AD A2 58 */	lfs f29, -0x5da8(r13)
/* 8023D6E8  C0 4D A3 28 */	lfs f2, -0x5cd8(r13)
/* 8023D6EC  C3 87 00 04 */	lfs f28, 4(r7)
/* 8023D6F0  C0 66 00 04 */	lfs f3, 4(r6)
/* 8023D6F4  D0 0D A2 50 */	stfs f0, -0x5db0(r13)
/* 8023D6F8  D0 28 00 04 */	stfs f1, 4(r8)
/* 8023D6FC  D0 4D A2 58 */	stfs f2, -0x5da8(r13)
/* 8023D700  D0 67 00 04 */	stfs f3, 4(r7)
/* 8023D704  80 03 00 00 */	lwz r0, 0(r3)
/* 8023D708  80 84 00 00 */	lwz r4, 0(r4)
/* 8023D70C  2C 00 00 00 */	cmpwi r0, 0
/* 8023D710  40 82 00 14 */	bne 0x14
/* 8023D714  90 81 00 10 */	stw r4, 0x10(r1)
/* 8023D718  38 81 00 10 */	addi r4, r1, 0x10
/* 8023D71C  4B FE A1 4D */	bl -0x15eb4
/* 8023D720  48 00 00 10 */	b 0x10
/* 8023D724  90 81 00 14 */	stw r4, 0x14(r1)
/* 8023D728  38 81 00 14 */	addi r4, r1, 0x14
/* 8023D72C  4B FE A0 D1 */	bl -0x15f30
/* 8023D730  38 8D A2 50 */	addi r4, r13, -23984
/* 8023D734  38 6D A2 58 */	addi r3, r13, -23976
/* 8023D738  D3 CD A2 50 */	stfs f30, -0x5db0(r13)
/* 8023D73C  D3 E4 00 04 */	stfs f31, 4(r4)
/* 8023D740  D3 AD A2 58 */	stfs f29, -0x5da8(r13)
/* 8023D744  D3 83 00 04 */	stfs f28, 4(r3)
/* 8023D748  48 00 00 30 */	b 0x30
/* 8023D74C  80 03 00 00 */	lwz r0, 0(r3)
/* 8023D750  80 84 00 00 */	lwz r4, 0(r4)
/* 8023D754  2C 00 00 00 */	cmpwi r0, 0
/* 8023D758  40 82 00 14 */	bne 0x14
/* 8023D75C  90 81 00 08 */	stw r4, 8(r1)
/* 8023D760  38 81 00 08 */	addi r4, r1, 8
/* 8023D764  4B FE A1 05 */	bl -0x15efc
/* 8023D768  48 00 00 10 */	b 0x10
/* 8023D76C  90 81 00 0C */	stw r4, 0xc(r1)
/* 8023D770  38 81 00 0C */	addi r4, r1, 0xc
/* 8023D774  4B FE A0 89 */	bl -0x15f78
/* 8023D778  7F 83 E3 78 */	mr r3, r28
/* 8023D77C  48 00 04 5D */	bl 0x45c
/* 8023D780  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 8023D784  7C 7C 1B 78 */	mr r28, r3
/* 8023D788  C0 63 00 08 */	lfs f3, 8(r3)
/* 8023D78C  C0 43 00 04 */	lfs f2, 4(r3)
/* 8023D790  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023D794  C3 C3 00 14 */	lfs f30, 0x14(r3)
/* 8023D798  C3 E3 00 10 */	lfs f31, 0x10(r3)
/* 8023D79C  7F 63 DB 78 */	mr r3, r27
/* 8023D7A0  4B E2 CE 91 */	bl -0x1d3170
/* 8023D7A4  FC 20 F8 90 */	fmr f1, f31
/* 8023D7A8  7F 63 DB 78 */	mr r3, r27
/* 8023D7AC  FC 40 F0 90 */	fmr f2, f30
/* 8023D7B0  4B E2 CF 21 */	bl -0x1d30e0
/* 8023D7B4  C0 3C 00 0C */	lfs f1, 0xc(r28)
/* 8023D7B8  4B DE 3C C1 */	bl -0x21c340
/* 8023D7BC  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8023D7C0  7C 7D 1B 78 */	mr r29, r3
/* 8023D7C4  4B DE 3C B5 */	bl -0x21c34c
/* 8023D7C8  C0 3C 00 04 */	lfs f1, 4(r28)
/* 8023D7CC  7C 7E 1B 78 */	mr r30, r3
/* 8023D7D0  4B DE 3C A9 */	bl -0x21c358
/* 8023D7D4  C0 3C 00 00 */	lfs f1, 0(r28)
/* 8023D7D8  7C 7F 1B 78 */	mr r31, r3
/* 8023D7DC  4B DE 3C 9D */	bl -0x21c364
/* 8023D7E0  7C 64 1B 78 */	mr r4, r3
/* 8023D7E4  7F 63 DB 78 */	mr r3, r27
/* 8023D7E8  7F E5 FB 78 */	mr r5, r31
/* 8023D7EC  7F C6 F3 78 */	mr r6, r30
/* 8023D7F0  7F A7 EB 78 */	mr r7, r29
/* 8023D7F4  4B E2 CD FD */	bl -0x1d3204
/* 8023D7F8  80 9C 00 18 */	lwz r4, 0x18(r28)
/* 8023D7FC  7F 63 DB 78 */	mr r3, r27
/* 8023D800  80 BC 00 1C */	lwz r5, 0x1c(r28)
/* 8023D804  4B E2 CE 0D */	bl -0x1d31f4
/* 8023D808  E3 E1 00 68 */	psq_l f31, 104(r1), 0, qr0
/* 8023D80C  CB E1 00 60 */	lfd f31, 0x60(r1)
/* 8023D810  E3 C1 00 58 */	psq_l f30, 88(r1), 0, qr0
/* 8023D814  CB C1 00 50 */	lfd f30, 0x50(r1)
/* 8023D818  E3 A1 00 48 */	psq_l f29, 72(r1), 0, qr0
/* 8023D81C  CB A1 00 40 */	lfd f29, 0x40(r1)
/* 8023D820  E3 81 00 38 */	psq_l f28, 56(r1), 0, qr0
/* 8023D824  39 61 00 30 */	addi r11, r1, 0x30
/* 8023D828  CB 81 00 30 */	lfd f28, 0x30(r1)
/* 8023D82C  4B DE 3D C1 */	bl -0x21c240
/* 8023D830  80 01 00 74 */	lwz r0, 0x74(r1)
/* 8023D834  7C 08 03 A6 */	mtlr r0
/* 8023D838  38 21 00 70 */	addi r1, r1, 0x70
/* 8023D83C  4E 80 00 20 */	blr
/* 8023D840  80 04 00 00 */	lwz r0, 0(r4)
/* 8023D844  90 03 00 00 */	stw r0, 0(r3)
/* 8023D848  80 04 00 04 */	lwz r0, 4(r4)
/* 8023D84C  90 03 00 04 */	stw r0, 4(r3)
/* 8023D850  C0 04 00 08 */	lfs f0, 8(r4)
/* 8023D854  D0 03 00 08 */	stfs f0, 8(r3)
/* 8023D858  C0 04 00 0C */	lfs f0, 0xc(r4)
/* 8023D85C  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8023D860  C0 04 00 10 */	lfs f0, 0x10(r4)
/* 8023D864  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 8023D868  C0 04 00 14 */	lfs f0, 0x14(r4)
/* 8023D86C  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 8023D870  C0 04 00 18 */	lfs f0, 0x18(r4)
/* 8023D874  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 8023D878  C0 04 00 1C */	lfs f0, 0x1c(r4)
/* 8023D87C  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8023D880  C0 04 00 20 */	lfs f0, 0x20(r4)
/* 8023D884  D0 03 00 20 */	stfs f0, 0x20(r3)
/* 8023D888  C0 04 00 24 */	lfs f0, 0x24(r4)
/* 8023D88C  D0 03 00 24 */	stfs f0, 0x24(r3)
/* 8023D890  C0 04 00 28 */	lfs f0, 0x28(r4)
/* 8023D894  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8023D898  C0 04 00 2C */	lfs f0, 0x2c(r4)
/* 8023D89C  D0 03 00 2C */	stfs f0, 0x2c(r3)
/* 8023D8A0  C0 04 00 30 */	lfs f0, 0x30(r4)
/* 8023D8A4  D0 03 00 30 */	stfs f0, 0x30(r3)
/* 8023D8A8  A0 04 00 34 */	lhz r0, 0x34(r4)
/* 8023D8AC  B0 03 00 34 */	sth r0, 0x34(r3)
/* 8023D8B0  C0 04 00 40 */	lfs f0, 0x40(r4)
/* 8023D8B4  D0 03 00 40 */	stfs f0, 0x40(r3)
/* 8023D8B8  C0 04 00 44 */	lfs f0, 0x44(r4)
/* 8023D8BC  D0 03 00 44 */	stfs f0, 0x44(r3)
/* 8023D8C0  80 A4 00 48 */	lwz r5, 0x48(r4)
/* 8023D8C4  80 04 00 4C */	lwz r0, 0x4c(r4)
/* 8023D8C8  90 03 00 4C */	stw r0, 0x4c(r3)
/* 8023D8CC  90 A3 00 48 */	stw r5, 0x48(r3)
/* 8023D8D0  80 A4 00 50 */	lwz r5, 0x50(r4)
/* 8023D8D4  80 04 00 54 */	lwz r0, 0x54(r4)
/* 8023D8D8  90 03 00 54 */	stw r0, 0x54(r3)
/* 8023D8DC  90 A3 00 50 */	stw r5, 0x50(r3)
/* 8023D8E0  80 A4 00 58 */	lwz r5, 0x58(r4)
/* 8023D8E4  80 04 00 5C */	lwz r0, 0x5c(r4)
/* 8023D8E8  90 03 00 5C */	stw r0, 0x5c(r3)
/* 8023D8EC  90 A3 00 58 */	stw r5, 0x58(r3)
/* 8023D8F0  80 04 00 60 */	lwz r0, 0x60(r4)
/* 8023D8F4  90 03 00 60 */	stw r0, 0x60(r3)
/* 8023D8F8  80 04 00 64 */	lwz r0, 0x64(r4)
/* 8023D8FC  90 03 00 64 */	stw r0, 0x64(r3)
/* 8023D900  80 84 00 3C */	lwz r4, 0x3c(r4)
/* 8023D904  2C 04 00 00 */	cmpwi r4, 0
/* 8023D908  41 82 00 08 */	beq 0x8
/* 8023D90C  48 00 00 08 */	b 0x8
/* 8023D910  80 8D A3 14 */	lwz r4, -0x5cec(r13)
/* 8023D914  80 03 00 3C */	lwz r0, 0x3c(r3)
/* 8023D918  7C 00 20 40 */	cmplw r0, r4
/* 8023D91C  4D 82 00 20 */	beqlr
/* 8023D920  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023D924  90 83 00 3C */	stw r4, 0x3c(r3)
/* 8023D928  60 00 00 01 */	ori r0, r0, 1
/* 8023D92C  B0 03 00 34 */	sth r0, 0x34(r3)
/* 8023D930  4E 80 00 20 */	blr
/* 8023D934  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8023D938  7C 08 02 A6 */	mflr r0
/* 8023D93C  3C 80 43 30 */	lis r4, 0x4330
/* 8023D940  90 01 00 44 */	stw r0, 0x44(r1)
/* 8023D944  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8023D948  3B E3 00 48 */	addi r31, r3, 0x48
/* 8023D94C  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8023D950  3B C3 00 4C */	addi r30, r3, 0x4c
/* 8023D954  93 A1 00 34 */	stw r29, 0x34(r1)
/* 8023D958  93 81 00 30 */	stw r28, 0x30(r1)
/* 8023D95C  7C 7C 1B 78 */	mr r28, r3
/* 8023D960  A0 A3 00 34 */	lhz r5, 0x34(r3)
/* 8023D964  90 81 00 08 */	stw r4, 8(r1)
/* 8023D968  54 A0 06 B5 */	rlwinm. r0, r5, 0, 0x1a, 0x1a
/* 8023D96C  90 81 00 10 */	stw r4, 0x10(r1)
/* 8023D970  40 82 00 18 */	bne 0x18
/* 8023D974  54 A0 07 39 */	rlwinm. r0, r5, 0, 0x1c, 0x1c
/* 8023D978  38 00 00 02 */	li r0, 2
/* 8023D97C  40 82 00 10 */	bne 0x10
/* 8023D980  80 0D A3 10 */	lwz r0, -0x5cf0(r13)
/* 8023D984  48 00 00 08 */	b 0x8
/* 8023D988  38 00 00 00 */	li r0, 0
/* 8023D98C  80 A3 00 3C */	lwz r5, 0x3c(r3)
/* 8023D990  3C 80 80 2A */	lis r4, 0x802a
/* 8023D994  1C 00 00 0C */	mulli r0, r0, 0xc
/* 8023D998  2C 05 00 00 */	cmpwi r5, 0
/* 8023D99C  38 84 3E E8 */	addi r4, r4, 0x3ee8
/* 8023D9A0  7F A4 02 14 */	add r29, r4, r0
/* 8023D9A4  40 82 00 2C */	bne 0x2c
/* 8023D9A8  C0 43 00 40 */	lfs f2, 0x40(r3)
/* 8023D9AC  38 8D A3 20 */	addi r4, r13, -23776
/* 8023D9B0  C0 0D A3 20 */	lfs f0, -0x5ce0(r13)
/* 8023D9B4  C0 23 00 44 */	lfs f1, 0x44(r3)
/* 8023D9B8  EC 02 00 32 */	fmuls f0, f2, f0
/* 8023D9BC  D0 1F 00 00 */	stfs f0, 0(r31)
/* 8023D9C0  C0 04 00 04 */	lfs f0, 4(r4)
/* 8023D9C4  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023D9C8  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8023D9CC  48 00 00 1C */	b 0x1c
/* 8023D9D0  C0 3C 00 40 */	lfs f1, 0x40(r28)
/* 8023D9D4  7C A3 2B 78 */	mr r3, r5
/* 8023D9D8  C0 5C 00 44 */	lfs f2, 0x44(r28)
/* 8023D9DC  7F E4 FB 78 */	mr r4, r31
/* 8023D9E0  7F C5 F3 78 */	mr r5, r30
/* 8023D9E4  48 00 0C 1D */	bl 0xc1c
/* 8023D9E8  C0 5F 00 00 */	lfs f2, 0(r31)
/* 8023D9EC  38 00 00 00 */	li r0, 0
/* 8023D9F0  C0 02 A0 80 */	lfs f0, -0x5f80(r2)
/* 8023D9F4  90 1C 00 64 */	stw r0, 0x64(r28)
/* 8023D9F8  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8023D9FC  90 1C 00 60 */	stw r0, 0x60(r28)
/* 8023DA00  40 80 00 3C */	bge 0x3c
/* 8023DA04  FC 00 10 1E */	fctiwz f0, f2
/* 8023DA08  C8 22 A0 98 */	lfd f1, -0x5f68(r2)
/* 8023DA0C  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 8023DA10  80 61 00 1C */	lwz r3, 0x1c(r1)
/* 8023DA14  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8023DA18  90 01 00 0C */	stw r0, 0xc(r1)
/* 8023DA1C  7C 63 00 D0 */	neg r3, r3
/* 8023DA20  C8 01 00 08 */	lfd f0, 8(r1)
/* 8023DA24  54 60 07 FE */	clrlwi r0, r3, 0x1f
/* 8023DA28  7C 00 18 50 */	subf r0, r0, r3
/* 8023DA2C  90 1C 00 60 */	stw r0, 0x60(r28)
/* 8023DA30  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023DA34  EC 02 00 28 */	fsubs f0, f2, f0
/* 8023DA38  D0 1F 00 00 */	stfs f0, 0(r31)
/* 8023DA3C  C0 5E 00 00 */	lfs f2, 0(r30)
/* 8023DA40  C0 02 A0 80 */	lfs f0, -0x5f80(r2)
/* 8023DA44  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 8023DA48  40 80 00 3C */	bge 0x3c
/* 8023DA4C  FC 00 10 1E */	fctiwz f0, f2
/* 8023DA50  C8 22 A0 98 */	lfd f1, -0x5f68(r2)
/* 8023DA54  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 8023DA58  80 61 00 1C */	lwz r3, 0x1c(r1)
/* 8023DA5C  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 8023DA60  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023DA64  7C 63 00 D0 */	neg r3, r3
/* 8023DA68  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023DA6C  54 60 07 FE */	clrlwi r0, r3, 0x1f
/* 8023DA70  7C 00 18 50 */	subf r0, r0, r3
/* 8023DA74  90 1C 00 64 */	stw r0, 0x64(r28)
/* 8023DA78  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023DA7C  EC 02 00 28 */	fsubs f0, f2, f0
/* 8023DA80  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8023DA84  A0 1C 00 34 */	lhz r0, 0x34(r28)
/* 8023DA88  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023DA8C  41 82 00 60 */	beq 0x60
/* 8023DA90  C0 9F 00 00 */	lfs f4, 0(r31)
/* 8023DA94  C0 3E 00 00 */	lfs f1, 0(r30)
/* 8023DA98  FC 40 20 1E */	fctiwz f2, f4
/* 8023DA9C  C8 62 A0 98 */	lfd f3, -0x5f68(r2)
/* 8023DAA0  FC 00 08 1E */	fctiwz f0, f1
/* 8023DAA4  D8 41 00 18 */	stfd f2, 0x18(r1)
/* 8023DAA8  D8 01 00 20 */	stfd f0, 0x20(r1)
/* 8023DAAC  80 61 00 1C */	lwz r3, 0x1c(r1)
/* 8023DAB0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023DAB4  54 63 07 FE */	clrlwi r3, r3, 0x1f
/* 8023DAB8  54 00 07 FE */	clrlwi r0, r0, 0x1f
/* 8023DABC  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8023DAC0  90 61 00 0C */	stw r3, 0xc(r1)
/* 8023DAC4  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8023DAC8  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023DACC  C8 41 00 08 */	lfd f2, 8(r1)
/* 8023DAD0  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023DAD4  EC 42 18 28 */	fsubs f2, f2, f3
/* 8023DAD8  EC 00 18 28 */	fsubs f0, f0, f3
/* 8023DADC  EC 44 10 28 */	fsubs f2, f4, f2
/* 8023DAE0  EC 01 00 28 */	fsubs f0, f1, f0
/* 8023DAE4  D0 5F 00 00 */	stfs f2, 0(r31)
/* 8023DAE8  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8023DAEC  C0 3D 00 04 */	lfs f1, 4(r29)
/* 8023DAF0  C0 1C 00 08 */	lfs f0, 8(r28)
/* 8023DAF4  A0 1C 00 34 */	lhz r0, 0x34(r28)
/* 8023DAF8  EC 81 00 32 */	fmuls f4, f1, f0
/* 8023DAFC  C0 1C 00 0C */	lfs f0, 0xc(r28)
/* 8023DB00  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023DB04  D0 9C 00 50 */	stfs f4, 0x50(r28)
/* 8023DB08  C0 3D 00 08 */	lfs f1, 8(r29)
/* 8023DB0C  EC 61 00 32 */	fmuls f3, f1, f0
/* 8023DB10  D0 7C 00 54 */	stfs f3, 0x54(r28)
/* 8023DB14  41 82 00 58 */	beq 0x58
/* 8023DB18  FC 20 20 1E */	fctiwz f1, f4
/* 8023DB1C  C8 42 A0 98 */	lfd f2, -0x5f68(r2)
/* 8023DB20  FC 00 18 1E */	fctiwz f0, f3
/* 8023DB24  D8 21 00 20 */	stfd f1, 0x20(r1)
/* 8023DB28  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 8023DB2C  80 61 00 24 */	lwz r3, 0x24(r1)
/* 8023DB30  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8023DB34  54 63 07 BE */	clrlwi r3, r3, 0x1e
/* 8023DB38  54 00 07 BE */	clrlwi r0, r0, 0x1e
/* 8023DB3C  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8023DB40  90 61 00 0C */	stw r3, 0xc(r1)
/* 8023DB44  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8023DB48  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023DB4C  C8 21 00 08 */	lfd f1, 8(r1)
/* 8023DB50  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023DB54  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023DB58  EC 00 10 28 */	fsubs f0, f0, f2
/* 8023DB5C  EC 24 08 28 */	fsubs f1, f4, f1
/* 8023DB60  EC 03 00 28 */	fsubs f0, f3, f0
/* 8023DB64  D0 3C 00 50 */	stfs f1, 0x50(r28)
/* 8023DB68  D0 1C 00 54 */	stfs f0, 0x54(r28)
/* 8023DB6C  C0 3C 00 50 */	lfs f1, 0x50(r28)
/* 8023DB70  C0 1C 00 54 */	lfs f0, 0x54(r28)
/* 8023DB74  FC 20 08 1E */	fctiwz f1, f1
/* 8023DB78  C8 42 A0 98 */	lfd f2, -0x5f68(r2)
/* 8023DB7C  FC 00 00 1E */	fctiwz f0, f0
/* 8023DB80  D8 21 00 20 */	stfd f1, 0x20(r1)
/* 8023DB84  D8 01 00 18 */	stfd f0, 0x18(r1)
/* 8023DB88  80 61 00 24 */	lwz r3, 0x24(r1)
/* 8023DB8C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 8023DB90  6C 63 80 00 */	xoris r3, r3, 0x8000
/* 8023DB94  90 61 00 0C */	stw r3, 0xc(r1)
/* 8023DB98  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8023DB9C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023DBA0  C8 21 00 08 */	lfd f1, 8(r1)
/* 8023DBA4  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023DBA8  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023DBAC  EC 00 10 28 */	fsubs f0, f0, f2
/* 8023DBB0  D0 3C 00 50 */	stfs f1, 0x50(r28)
/* 8023DBB4  D0 1C 00 54 */	stfs f0, 0x54(r28)
/* 8023DBB8  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8023DBBC  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 8023DBC0  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 8023DBC4  83 81 00 30 */	lwz r28, 0x30(r1)
/* 8023DBC8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8023DBCC  7C 08 03 A6 */	mtlr r0
/* 8023DBD0  38 21 00 40 */	addi r1, r1, 0x40
/* 8023DBD4  4E 80 00 20 */	blr
/* 8023DBD8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023DBDC  7C 08 02 A6 */	mflr r0
/* 8023DBE0  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023DBE4  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023DBE8  7C 7F 1B 78 */	mr r31, r3
/* 8023DBEC  48 00 00 49 */	bl 0x48
/* 8023DBF0  2C 03 00 00 */	cmpwi r3, 0
/* 8023DBF4  41 82 00 28 */	beq 0x28
/* 8023DBF8  7F E3 FB 78 */	mr r3, r31
/* 8023DBFC  4B FF FD 39 */	bl -0x2c8
/* 8023DC00  A0 1F 00 34 */	lhz r0, 0x34(r31)
/* 8023DC04  C0 22 A0 80 */	lfs f1, -0x5f80(r2)
/* 8023DC08  C0 02 A0 84 */	lfs f0, -0x5f7c(r2)
/* 8023DC0C  54 00 04 3C */	rlwinm r0, r0, 0, 0x10, 0x1e
/* 8023DC10  D0 3F 00 58 */	stfs f1, 0x58(r31)
/* 8023DC14  D0 1F 00 5C */	stfs f0, 0x5c(r31)
/* 8023DC18  B0 1F 00 34 */	sth r0, 0x34(r31)
/* 8023DC1C  38 7F 00 48 */	addi r3, r31, 0x48
/* 8023DC20  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023DC24  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023DC28  7C 08 03 A6 */	mtlr r0
/* 8023DC2C  38 21 00 10 */	addi r1, r1, 0x10
/* 8023DC30  4E 80 00 20 */	blr
/* 8023DC34  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023DC38  7C 08 02 A6 */	mflr r0
/* 8023DC3C  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023DC40  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023DC44  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DC48  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DC4C  41 82 00 0C */	beq 0xc
/* 8023DC50  38 60 00 01 */	li r3, 1
/* 8023DC54  48 00 01 60 */	b 0x160
/* 8023DC58  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DC5C  2C 03 00 00 */	cmpwi r3, 0
/* 8023DC60  41 82 01 50 */	beq 0x150
/* 8023DC64  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DC68  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DC6C  41 82 00 0C */	beq 0xc
/* 8023DC70  38 60 00 01 */	li r3, 1
/* 8023DC74  48 00 01 40 */	b 0x140
/* 8023DC78  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DC7C  2C 03 00 00 */	cmpwi r3, 0
/* 8023DC80  41 82 01 28 */	beq 0x128
/* 8023DC84  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DC88  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DC8C  41 82 00 0C */	beq 0xc
/* 8023DC90  38 60 00 01 */	li r3, 1
/* 8023DC94  48 00 01 20 */	b 0x120
/* 8023DC98  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DC9C  2C 03 00 00 */	cmpwi r3, 0
/* 8023DCA0  41 82 01 00 */	beq 0x100
/* 8023DCA4  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DCA8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DCAC  41 82 00 0C */	beq 0xc
/* 8023DCB0  38 60 00 01 */	li r3, 1
/* 8023DCB4  48 00 01 00 */	b 0x100
/* 8023DCB8  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DCBC  2C 03 00 00 */	cmpwi r3, 0
/* 8023DCC0  41 82 00 D8 */	beq 0xd8
/* 8023DCC4  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DCC8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DCCC  41 82 00 0C */	beq 0xc
/* 8023DCD0  38 60 00 01 */	li r3, 1
/* 8023DCD4  48 00 00 E0 */	b 0xe0
/* 8023DCD8  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DCDC  2C 03 00 00 */	cmpwi r3, 0
/* 8023DCE0  41 82 00 B0 */	beq 0xb0
/* 8023DCE4  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DCE8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DCEC  41 82 00 0C */	beq 0xc
/* 8023DCF0  38 60 00 01 */	li r3, 1
/* 8023DCF4  48 00 00 C0 */	b 0xc0
/* 8023DCF8  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DCFC  2C 03 00 00 */	cmpwi r3, 0
/* 8023DD00  41 82 00 88 */	beq 0x88
/* 8023DD04  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DD08  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DD0C  41 82 00 0C */	beq 0xc
/* 8023DD10  38 60 00 01 */	li r3, 1
/* 8023DD14  48 00 00 A0 */	b 0xa0
/* 8023DD18  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023DD1C  2C 03 00 00 */	cmpwi r3, 0
/* 8023DD20  41 82 00 60 */	beq 0x60
/* 8023DD24  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DD28  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023DD2C  41 82 00 0C */	beq 0xc
/* 8023DD30  38 60 00 01 */	li r3, 1
/* 8023DD34  48 00 00 80 */	b 0x80
/* 8023DD38  83 E3 00 3C */	lwz r31, 0x3c(r3)
/* 8023DD3C  2C 1F 00 00 */	cmpwi r31, 0
/* 8023DD40  41 82 00 38 */	beq 0x38
/* 8023DD44  7F E3 FB 78 */	mr r3, r31
/* 8023DD48  48 00 00 81 */	bl 0x80
/* 8023DD4C  2C 03 00 00 */	cmpwi r3, 0
/* 8023DD50  41 82 00 0C */	beq 0xc
/* 8023DD54  38 60 00 01 */	li r3, 1
/* 8023DD58  48 00 00 5C */	b 0x5c
/* 8023DD5C  80 7F 00 3C */	lwz r3, 0x3c(r31)
/* 8023DD60  2C 03 00 00 */	cmpwi r3, 0
/* 8023DD64  41 82 00 0C */	beq 0xc
/* 8023DD68  4B FF FE CD */	bl -0x134
/* 8023DD6C  48 00 00 48 */	b 0x48
/* 8023DD70  38 60 00 00 */	li r3, 0
/* 8023DD74  48 00 00 40 */	b 0x40
/* 8023DD78  38 60 00 00 */	li r3, 0
/* 8023DD7C  48 00 00 38 */	b 0x38
/* 8023DD80  38 60 00 00 */	li r3, 0
/* 8023DD84  48 00 00 30 */	b 0x30
/* 8023DD88  38 60 00 00 */	li r3, 0
/* 8023DD8C  48 00 00 28 */	b 0x28
/* 8023DD90  38 60 00 00 */	li r3, 0
/* 8023DD94  48 00 00 20 */	b 0x20
/* 8023DD98  38 60 00 00 */	li r3, 0
/* 8023DD9C  48 00 00 18 */	b 0x18
/* 8023DDA0  38 60 00 00 */	li r3, 0
/* 8023DDA4  48 00 00 10 */	b 0x10
/* 8023DDA8  38 60 00 00 */	li r3, 0
/* 8023DDAC  48 00 00 08 */	b 0x8
/* 8023DDB0  38 60 00 00 */	li r3, 0
/* 8023DDB4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023DDB8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023DDBC  7C 08 03 A6 */	mtlr r0
/* 8023DDC0  38 21 00 10 */	addi r1, r1, 0x10
/* 8023DDC4  4E 80 00 20 */	blr
/* 8023DDC8  A0 03 00 34 */	lhz r0, 0x34(r3)
/* 8023DDCC  54 03 07 FE */	clrlwi r3, r0, 0x1f
/* 8023DDD0  4E 80 00 20 */	blr
/* 8023DDD4  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8023DDD8  7C 08 02 A6 */	mflr r0
/* 8023DDDC  90 01 00 44 */	stw r0, 0x44(r1)
/* 8023DDE0  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8023DDE4  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 8023DDE8  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 8023DDEC  F3 C1 00 28 */	psq_st f30, 40(r1), 0, qr0
/* 8023DDF0  DB A1 00 10 */	stfd f29, 0x10(r1)
/* 8023DDF4  F3 A1 00 18 */	psq_st f29, 24(r1), 0, qr0
/* 8023DDF8  FC 00 18 90 */	fmr f0, f3
/* 8023DDFC  FF A0 08 90 */	fmr f29, f1
/* 8023DE00  C0 62 A0 84 */	lfs f3, -0x5f7c(r2)
/* 8023DE04  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023DE08  FF E0 20 90 */	fmr f31, f4
/* 8023DE0C  FF C0 10 90 */	fmr f30, f2
/* 8023DE10  93 C1 00 08 */	stw r30, 8(r1)
/* 8023DE14  FC 20 00 90 */	fmr f1, f0
/* 8023DE18  7C 9F 23 78 */	mr r31, r4
/* 8023DE1C  7C 7E 1B 78 */	mr r30, r3
/* 8023DE20  FC 40 F8 90 */	fmr f2, f31
/* 8023DE24  7F E3 FB 78 */	mr r3, r31
/* 8023DE28  4B F5 C6 39 */	bl -0xa39c8
/* 8023DE2C  D3 BF 00 0C */	stfs f29, 0xc(r31)
/* 8023DE30  80 1E 00 04 */	lwz r0, 4(r30)
/* 8023DE34  2C 00 00 00 */	cmpwi r0, 0
/* 8023DE38  40 82 00 08 */	bne 0x8
/* 8023DE3C  EF DE F8 28 */	fsubs f30, f30, f31
/* 8023DE40  C0 02 A0 80 */	lfs f0, -0x5f80(r2)
/* 8023DE44  D3 DF 00 1C */	stfs f30, 0x1c(r31)
/* 8023DE48  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8023DE4C  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 8023DE50  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8023DE54  E3 C1 00 28 */	psq_l f30, 40(r1), 0, qr0
/* 8023DE58  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 8023DE5C  E3 A1 00 18 */	psq_l f29, 24(r1), 0, qr0
/* 8023DE60  CB A1 00 10 */	lfd f29, 0x10(r1)
/* 8023DE64  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023DE68  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023DE6C  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8023DE70  7C 08 03 A6 */	mtlr r0
/* 8023DE74  38 21 00 40 */	addi r1, r1, 0x40
/* 8023DE78  4E 80 00 20 */	blr
/* 8023DE7C  94 21 FF 20 */	stwu r1, -0xe0(r1)
/* 8023DE80  7C 08 02 A6 */	mflr r0
/* 8023DE84  90 01 00 E4 */	stw r0, 0xe4(r1)
/* 8023DE88  DB E1 00 D0 */	stfd f31, 0xd0(r1)
/* 8023DE8C  F3 E1 00 D8 */	psq_st f31, 216(r1), 0, qr0
/* 8023DE90  DB C1 00 C0 */	stfd f30, 0xc0(r1)
/* 8023DE94  F3 C1 00 C8 */	psq_st f30, 200(r1), 0, qr0
/* 8023DE98  2C 04 00 00 */	cmpwi r4, 0
/* 8023DE9C  93 E1 00 BC */	stw r31, 0xbc(r1)
/* 8023DEA0  7C BF 2B 78 */	mr r31, r5
/* 8023DEA4  93 C1 00 B8 */	stw r30, 0xb8(r1)
/* 8023DEA8  7C 9E 23 78 */	mr r30, r4
/* 8023DEAC  93 A1 00 B4 */	stw r29, 0xb4(r1)
/* 8023DEB0  7C 7D 1B 78 */	mr r29, r3
/* 8023DEB4  93 81 00 B0 */	stw r28, 0xb0(r1)
/* 8023DEB8  41 82 01 58 */	beq 0x158
/* 8023DEBC  83 83 00 3C */	lwz r28, 0x3c(r3)
/* 8023DEC0  38 01 00 48 */	addi r0, r1, 0x48
/* 8023DEC4  C0 63 00 0C */	lfs f3, 0xc(r3)
/* 8023DEC8  38 A1 00 10 */	addi r5, r1, 0x10
/* 8023DECC  C0 03 00 08 */	lfs f0, 8(r3)
/* 8023DED0  38 80 00 01 */	li r4, 1
/* 8023DED4  C3 C3 00 44 */	lfs f30, 0x44(r3)
/* 8023DED8  38 C0 00 01 */	li r6, 1
/* 8023DEDC  C3 E3 00 40 */	lfs f31, 0x40(r3)
/* 8023DEE0  7C 03 03 78 */	mr r3, r0
/* 8023DEE4  C0 22 A0 90 */	lfs f1, -0x5f70(r2)
/* 8023DEE8  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8023DEEC  C0 42 A0 94 */	lfs f2, -0x5f6c(r2)
/* 8023DEF0  D0 61 00 14 */	stfs f3, 0x14(r1)
/* 8023DEF4  4B FE 97 CD */	bl -0x16834
/* 8023DEF8  3C 60 80 2A */	lis r3, 0x802a
/* 8023DEFC  2C 1C 00 00 */	cmpwi r28, 0
/* 8023DF00  38 63 3F 0C */	addi r3, r3, 0x3f0c
/* 8023DF04  38 00 00 00 */	li r0, 0
/* 8023DF08  90 61 00 80 */	stw r3, 0x80(r1)
/* 8023DF0C  90 01 00 84 */	stw r0, 0x84(r1)
/* 8023DF10  D3 E1 00 88 */	stfs f31, 0x88(r1)
/* 8023DF14  D3 C1 00 8C */	stfs f30, 0x8c(r1)
/* 8023DF18  41 82 00 08 */	beq 0x8
/* 8023DF1C  48 00 00 08 */	b 0x8
/* 8023DF20  83 8D A3 14 */	lwz r28, -0x5cec(r13)
/* 8023DF24  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8023DF28  7C 00 E0 40 */	cmplw r0, r28
/* 8023DF2C  41 82 00 14 */	beq 0x14
/* 8023DF30  A0 01 00 7C */	lhz r0, 0x7c(r1)
/* 8023DF34  93 81 00 84 */	stw r28, 0x84(r1)
/* 8023DF38  60 00 00 01 */	ori r0, r0, 1
/* 8023DF3C  B0 01 00 7C */	sth r0, 0x7c(r1)
/* 8023DF40  A0 1D 00 34 */	lhz r0, 0x34(r29)
/* 8023DF44  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 8023DF48  41 82 00 24 */	beq 0x24
/* 8023DF4C  A0 61 00 7C */	lhz r3, 0x7c(r1)
/* 8023DF50  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 8023DF54  40 82 00 0C */	bne 0xc
/* 8023DF58  60 60 00 01 */	ori r0, r3, 1
/* 8023DF5C  B0 01 00 7C */	sth r0, 0x7c(r1)
/* 8023DF60  A0 01 00 7C */	lhz r0, 0x7c(r1)
/* 8023DF64  60 00 00 08 */	ori r0, r0, 8
/* 8023DF68  B0 01 00 7C */	sth r0, 0x7c(r1)
/* 8023DF6C  A0 81 00 7C */	lhz r4, 0x7c(r1)
/* 8023DF70  38 00 00 00 */	li r0, 0
/* 8023DF74  C0 22 A0 80 */	lfs f1, -0x5f80(r2)
/* 8023DF78  38 61 00 48 */	addi r3, r1, 0x48
/* 8023DF7C  C0 02 A0 84 */	lfs f0, -0x5f7c(r2)
/* 8023DF80  60 84 00 40 */	ori r4, r4, 0x40
/* 8023DF84  D0 21 00 60 */	stfs f1, 0x60(r1)
/* 8023DF88  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 8023DF8C  B0 81 00 7C */	sth r4, 0x7c(r1)
/* 8023DF90  90 01 00 48 */	stw r0, 0x48(r1)
/* 8023DF94  4B FF F5 55 */	bl -0xaac
/* 8023DF98  C3 DD 00 0C */	lfs f30, 0xc(r29)
/* 8023DF9C  38 61 00 18 */	addi r3, r1, 0x18
/* 8023DFA0  C0 3D 00 08 */	lfs f1, 8(r29)
/* 8023DFA4  FC 40 F0 90 */	fmr f2, f30
/* 8023DFA8  C0 62 A0 84 */	lfs f3, -0x5f7c(r2)
/* 8023DFAC  4B F5 C4 B5 */	bl -0xa3b4c
/* 8023DFB0  80 01 00 4C */	lwz r0, 0x4c(r1)
/* 8023DFB4  C0 22 A0 80 */	lfs f1, -0x5f80(r2)
/* 8023DFB8  2C 00 00 00 */	cmpwi r0, 0
/* 8023DFBC  D0 21 00 24 */	stfs f1, 0x24(r1)
/* 8023DFC0  40 82 00 08 */	bne 0x8
/* 8023DFC4  EC 21 F0 28 */	fsubs f1, f1, f30
/* 8023DFC8  C0 02 A0 80 */	lfs f0, -0x5f80(r2)
/* 8023DFCC  38 E1 00 08 */	addi r7, r1, 8
/* 8023DFD0  89 7F 00 00 */	lbz r11, 0(r31)
/* 8023DFD4  57 C6 F7 FE */	rlwinm r6, r30, 0x1e, 0x1f, 0x1f
/* 8023DFD8  89 5F 00 01 */	lbz r10, 1(r31)
/* 8023DFDC  57 C5 FF FE */	rlwinm r5, r30, 0x1f, 0x1f, 0x1f
/* 8023DFE0  89 3F 00 02 */	lbz r9, 2(r31)
/* 8023DFE4  38 61 00 18 */	addi r3, r1, 0x18
/* 8023DFE8  88 1F 00 03 */	lbz r0, 3(r31)
/* 8023DFEC  57 C4 07 FE */	clrlwi r4, r30, 0x1f
/* 8023DFF0  D0 21 00 34 */	stfs f1, 0x34(r1)
/* 8023DFF4  39 00 00 01 */	li r8, 1
/* 8023DFF8  D0 01 00 44 */	stfs f0, 0x44(r1)
/* 8023DFFC  99 61 00 08 */	stb r11, 8(r1)
/* 8023E000  99 41 00 09 */	stb r10, 9(r1)
/* 8023E004  99 21 00 0A */	stb r9, 0xa(r1)
/* 8023E008  98 01 00 0B */	stb r0, 0xb(r1)
/* 8023E00C  4B FD CD 6D */	bl -0x23294
/* 8023E010  E3 E1 00 D8 */	psq_l f31, 216(r1), 0, qr0
/* 8023E014  CB E1 00 D0 */	lfd f31, 0xd0(r1)
/* 8023E018  E3 C1 00 C8 */	psq_l f30, 200(r1), 0, qr0
/* 8023E01C  CB C1 00 C0 */	lfd f30, 0xc0(r1)
/* 8023E020  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 8023E024  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 8023E028  83 A1 00 B4 */	lwz r29, 0xb4(r1)
/* 8023E02C  80 01 00 E4 */	lwz r0, 0xe4(r1)
/* 8023E030  83 81 00 B0 */	lwz r28, 0xb0(r1)
/* 8023E034  7C 08 03 A6 */	mtlr r0
/* 8023E038  38 21 00 E0 */	addi r1, r1, 0xe0
/* 8023E03C  4E 80 00 20 */	blr
/* 8023E040  94 21 FF 30 */	stwu r1, -0xd0(r1)
/* 8023E044  7C 08 02 A6 */	mflr r0
/* 8023E048  90 01 00 D4 */	stw r0, 0xd4(r1)
/* 8023E04C  DB E1 00 C0 */	stfd f31, 0xc0(r1)
/* 8023E050  F3 E1 00 C8 */	psq_st f31, 200(r1), 0, qr0
/* 8023E054  DB C1 00 B0 */	stfd f30, 0xb0(r1)
/* 8023E058  F3 C1 00 B8 */	psq_st f30, 184(r1), 0, qr0
/* 8023E05C  DB A1 00 A0 */	stfd f29, 0xa0(r1)
/* 8023E060  F3 A1 00 A8 */	psq_st f29, 168(r1), 0, qr0
/* 8023E064  DB 81 00 90 */	stfd f28, 0x90(r1)
/* 8023E068  F3 81 00 98 */	psq_st f28, 152(r1), 0, qr0
/* 8023E06C  DB 61 00 80 */	stfd f27, 0x80(r1)
/* 8023E070  F3 61 00 88 */	psq_st f27, 136(r1), 0, qr0
/* 8023E074  DB 41 00 70 */	stfd f26, 0x70(r1)
/* 8023E078  F3 41 00 78 */	psq_st f26, 120(r1), 0, qr0
/* 8023E07C  DB 21 00 60 */	stfd f25, 0x60(r1)
/* 8023E080  F3 21 00 68 */	psq_st f25, 104(r1), 0, qr0
/* 8023E084  DB 01 00 50 */	stfd f24, 0x50(r1)
/* 8023E088  F3 01 00 58 */	psq_st f24, 88(r1), 0, qr0
/* 8023E08C  39 61 00 50 */	addi r11, r1, 0x50
/* 8023E090  4B DE 34 FD */	bl -0x21cb04
/* 8023E094  83 C3 00 3C */	lwz r30, 0x3c(r3)
/* 8023E098  7C 76 1B 78 */	mr r22, r3
/* 8023E09C  7C 97 23 78 */	mr r23, r4
/* 8023E0A0  7C B8 2B 78 */	mr r24, r5
/* 8023E0A4  2C 1E 00 00 */	cmpwi r30, 0
/* 8023E0A8  41 82 02 FC */	beq 0x2fc
/* 8023E0AC  83 BE 00 3C */	lwz r29, 0x3c(r30)
/* 8023E0B0  2C 1D 00 00 */	cmpwi r29, 0
/* 8023E0B4  41 82 02 7C */	beq 0x27c
/* 8023E0B8  83 9D 00 3C */	lwz r28, 0x3c(r29)
/* 8023E0BC  2C 1C 00 00 */	cmpwi r28, 0
/* 8023E0C0  41 82 02 14 */	beq 0x214
/* 8023E0C4  83 7C 00 3C */	lwz r27, 0x3c(r28)
/* 8023E0C8  2C 1B 00 00 */	cmpwi r27, 0
/* 8023E0CC  41 82 01 AC */	beq 0x1ac
/* 8023E0D0  83 5B 00 3C */	lwz r26, 0x3c(r27)
/* 8023E0D4  2C 1A 00 00 */	cmpwi r26, 0
/* 8023E0D8  41 82 01 44 */	beq 0x144
/* 8023E0DC  83 3A 00 3C */	lwz r25, 0x3c(r26)
/* 8023E0E0  2C 19 00 00 */	cmpwi r25, 0
/* 8023E0E4  41 82 00 CC */	beq 0xcc
/* 8023E0E8  7F 23 CB 78 */	mr r3, r25
/* 8023E0EC  48 00 03 99 */	bl 0x398
/* 8023E0F0  2C 03 00 00 */	cmpwi r3, 0
/* 8023E0F4  7C 7F 1B 78 */	mr r31, r3
/* 8023E0F8  41 82 00 4C */	beq 0x4c
/* 8023E0FC  38 81 00 08 */	addi r4, r1, 8
/* 8023E100  38 A1 00 0C */	addi r5, r1, 0xc
/* 8023E104  4B FF FF 3D */	bl -0xc4
/* 8023E108  C0 39 00 40 */	lfs f1, 0x40(r25)
/* 8023E10C  7F E3 FB 78 */	mr r3, r31
/* 8023E110  C0 59 00 44 */	lfs f2, 0x44(r25)
/* 8023E114  38 81 00 10 */	addi r4, r1, 0x10
/* 8023E118  38 A1 00 14 */	addi r5, r1, 0x14
/* 8023E11C  48 00 03 1D */	bl 0x31c
/* 8023E120  C0 61 00 10 */	lfs f3, 0x10(r1)
/* 8023E124  C0 41 00 08 */	lfs f2, 8(r1)
/* 8023E128  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8023E12C  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8023E130  EC 43 10 2A */	fadds f2, f3, f2
/* 8023E134  EC 01 00 2A */	fadds f0, f1, f0
/* 8023E138  D0 41 00 10 */	stfs f2, 0x10(r1)
/* 8023E13C  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8023E140  48 00 00 14 */	b 0x14
/* 8023E144  C0 19 00 40 */	lfs f0, 0x40(r25)
/* 8023E148  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 8023E14C  C0 19 00 44 */	lfs f0, 0x44(r25)
/* 8023E150  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 8023E154  80 19 00 04 */	lwz r0, 4(r25)
/* 8023E158  C0 5A 00 44 */	lfs f2, 0x44(r26)
/* 8023E15C  2C 00 00 01 */	cmpwi r0, 1
/* 8023E160  C0 3A 00 40 */	lfs f1, 0x40(r26)
/* 8023E164  40 82 00 10 */	bne 0x10
/* 8023E168  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 8023E16C  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 8023E170  48 00 00 1C */	b 0x1c
/* 8023E174  2C 00 00 00 */	cmpwi r0, 0
/* 8023E178  40 82 00 14 */	bne 0x14
/* 8023E17C  7F 23 CB 78 */	mr r3, r25
/* 8023E180  38 81 00 18 */	addi r4, r1, 0x18
/* 8023E184  38 A1 00 1C */	addi r5, r1, 0x1c
/* 8023E188  48 00 02 85 */	bl 0x284
/* 8023E18C  C0 61 00 18 */	lfs f3, 0x18(r1)
/* 8023E190  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 8023E194  C0 41 00 1C */	lfs f2, 0x1c(r1)
/* 8023E198  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8023E19C  EC 03 00 2A */	fadds f0, f3, f0
/* 8023E1A0  EC 22 08 2A */	fadds f1, f2, f1
/* 8023E1A4  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8023E1A8  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 8023E1AC  48 00 00 14 */	b 0x14
/* 8023E1B0  C0 1A 00 40 */	lfs f0, 0x40(r26)
/* 8023E1B4  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 8023E1B8  C0 3A 00 44 */	lfs f1, 0x44(r26)
/* 8023E1BC  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 8023E1C0  80 1A 00 04 */	lwz r0, 4(r26)
/* 8023E1C4  C0 DB 00 44 */	lfs f6, 0x44(r27)
/* 8023E1C8  2C 00 00 01 */	cmpwi r0, 1
/* 8023E1CC  C0 BB 00 40 */	lfs f5, 0x40(r27)
/* 8023E1D0  40 82 00 10 */	bne 0x10
/* 8023E1D4  FF 40 28 90 */	fmr f26, f5
/* 8023E1D8  FF 60 30 90 */	fmr f27, f6
/* 8023E1DC  48 00 00 2C */	b 0x2c
/* 8023E1E0  2C 00 00 00 */	cmpwi r0, 0
/* 8023E1E4  40 82 00 24 */	bne 0x24
/* 8023E1E8  C0 82 A0 A0 */	lfs f4, -0x5f60(r2)
/* 8023E1EC  C0 5A 00 0C */	lfs f2, 0xc(r26)
/* 8023E1F0  C0 7A 00 08 */	lfs f3, 8(r26)
/* 8023E1F4  EC 44 00 B2 */	fmuls f2, f4, f2
/* 8023E1F8  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8023E1FC  EC 46 10 28 */	fsubs f2, f6, f2
/* 8023E200  EF 45 18 2A */	fadds f26, f5, f3
/* 8023E204  FF 60 10 50 */	fneg f27, f2
/* 8023E208  FC 40 00 18 */	frsp f2, f0
/* 8023E20C  FC 00 08 18 */	frsp f0, f1
/* 8023E210  EF 5A 10 2A */	fadds f26, f26, f2
/* 8023E214  EF 7B 00 2A */	fadds f27, f27, f0
/* 8023E218  48 00 00 0C */	b 0xc
/* 8023E21C  C3 5B 00 40 */	lfs f26, 0x40(r27)
/* 8023E220  C3 7B 00 44 */	lfs f27, 0x44(r27)
/* 8023E224  80 1B 00 04 */	lwz r0, 4(r27)
/* 8023E228  C0 9C 00 44 */	lfs f4, 0x44(r28)
/* 8023E22C  2C 00 00 01 */	cmpwi r0, 1
/* 8023E230  C0 7C 00 40 */	lfs f3, 0x40(r28)
/* 8023E234  40 82 00 10 */	bne 0x10
/* 8023E238  FF 80 18 90 */	fmr f28, f3
/* 8023E23C  FF A0 20 90 */	fmr f29, f4
/* 8023E240  48 00 00 2C */	b 0x2c
/* 8023E244  2C 00 00 00 */	cmpwi r0, 0
/* 8023E248  40 82 00 24 */	bne 0x24
/* 8023E24C  C0 42 A0 A0 */	lfs f2, -0x5f60(r2)
/* 8023E250  C0 1B 00 0C */	lfs f0, 0xc(r27)
/* 8023E254  C0 3B 00 08 */	lfs f1, 8(r27)
/* 8023E258  EC 02 00 32 */	fmuls f0, f2, f0
/* 8023E25C  EC 22 00 72 */	fmuls f1, f2, f1
/* 8023E260  EC 04 00 28 */	fsubs f0, f4, f0
/* 8023E264  EF 83 08 2A */	fadds f28, f3, f1
/* 8023E268  FF A0 00 50 */	fneg f29, f0
/* 8023E26C  EF 9C D0 2A */	fadds f28, f28, f26
/* 8023E270  EF BD D8 2A */	fadds f29, f29, f27
/* 8023E274  48 00 00 0C */	b 0xc
/* 8023E278  C3 9C 00 40 */	lfs f28, 0x40(r28)
/* 8023E27C  C3 BC 00 44 */	lfs f29, 0x44(r28)
/* 8023E280  80 1C 00 04 */	lwz r0, 4(r28)
/* 8023E284  C0 9D 00 44 */	lfs f4, 0x44(r29)
/* 8023E288  2C 00 00 01 */	cmpwi r0, 1
/* 8023E28C  C0 7D 00 40 */	lfs f3, 0x40(r29)
/* 8023E290  40 82 00 10 */	bne 0x10
/* 8023E294  FF C0 18 90 */	fmr f30, f3
/* 8023E298  FF E0 20 90 */	fmr f31, f4
/* 8023E29C  48 00 00 2C */	b 0x2c
/* 8023E2A0  2C 00 00 00 */	cmpwi r0, 0
/* 8023E2A4  40 82 00 24 */	bne 0x24
/* 8023E2A8  C0 42 A0 A0 */	lfs f2, -0x5f60(r2)
/* 8023E2AC  C0 1C 00 0C */	lfs f0, 0xc(r28)
/* 8023E2B0  C0 3C 00 08 */	lfs f1, 8(r28)
/* 8023E2B4  EC 02 00 32 */	fmuls f0, f2, f0
/* 8023E2B8  EC 22 00 72 */	fmuls f1, f2, f1
/* 8023E2BC  EC 04 00 28 */	fsubs f0, f4, f0
/* 8023E2C0  EF C3 08 2A */	fadds f30, f3, f1
/* 8023E2C4  FF E0 00 50 */	fneg f31, f0
/* 8023E2C8  EF DE E0 2A */	fadds f30, f30, f28
/* 8023E2CC  EF FF E8 2A */	fadds f31, f31, f29
/* 8023E2D0  48 00 00 0C */	b 0xc
/* 8023E2D4  C3 DD 00 40 */	lfs f30, 0x40(r29)
/* 8023E2D8  C3 FD 00 44 */	lfs f31, 0x44(r29)
/* 8023E2DC  80 1D 00 04 */	lwz r0, 4(r29)
/* 8023E2E0  C0 9E 00 44 */	lfs f4, 0x44(r30)
/* 8023E2E4  2C 00 00 01 */	cmpwi r0, 1
/* 8023E2E8  C0 7E 00 40 */	lfs f3, 0x40(r30)
/* 8023E2EC  40 82 00 10 */	bne 0x10
/* 8023E2F0  FF 20 18 90 */	fmr f25, f3
/* 8023E2F4  FF 00 20 90 */	fmr f24, f4
/* 8023E2F8  48 00 00 2C */	b 0x2c
/* 8023E2FC  2C 00 00 00 */	cmpwi r0, 0
/* 8023E300  40 82 00 24 */	bne 0x24
/* 8023E304  C0 42 A0 A0 */	lfs f2, -0x5f60(r2)
/* 8023E308  C0 1D 00 0C */	lfs f0, 0xc(r29)
/* 8023E30C  C0 3D 00 08 */	lfs f1, 8(r29)
/* 8023E310  EC 02 00 32 */	fmuls f0, f2, f0
/* 8023E314  EC 22 00 72 */	fmuls f1, f2, f1
/* 8023E318  EC 04 00 28 */	fsubs f0, f4, f0
/* 8023E31C  EF 23 08 2A */	fadds f25, f3, f1
/* 8023E320  FF 00 00 50 */	fneg f24, f0
/* 8023E324  EF 39 F0 2A */	fadds f25, f25, f30
/* 8023E328  EF 18 F8 2A */	fadds f24, f24, f31
/* 8023E32C  48 00 00 0C */	b 0xc
/* 8023E330  C3 3E 00 40 */	lfs f25, 0x40(r30)
/* 8023E334  C3 1E 00 44 */	lfs f24, 0x44(r30)
/* 8023E338  80 1E 00 04 */	lwz r0, 4(r30)
/* 8023E33C  C0 76 00 44 */	lfs f3, 0x44(r22)
/* 8023E340  2C 00 00 01 */	cmpwi r0, 1
/* 8023E344  C0 56 00 40 */	lfs f2, 0x40(r22)
/* 8023E348  40 82 00 10 */	bne 0x10
/* 8023E34C  D0 57 00 00 */	stfs f2, 0(r23)
/* 8023E350  D0 78 00 00 */	stfs f3, 0(r24)
/* 8023E354  48 00 00 34 */	b 0x34
/* 8023E358  2C 00 00 00 */	cmpwi r0, 0
/* 8023E35C  40 82 00 2C */	bne 0x2c
/* 8023E360  C0 22 A0 A0 */	lfs f1, -0x5f60(r2)
/* 8023E364  C0 1E 00 08 */	lfs f0, 8(r30)
/* 8023E368  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023E36C  EC 02 00 2A */	fadds f0, f2, f0
/* 8023E370  D0 17 00 00 */	stfs f0, 0(r23)
/* 8023E374  C0 1E 00 0C */	lfs f0, 0xc(r30)
/* 8023E378  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023E37C  EC 03 00 28 */	fsubs f0, f3, f0
/* 8023E380  FC 00 00 50 */	fneg f0, f0
/* 8023E384  D0 18 00 00 */	stfs f0, 0(r24)
/* 8023E388  C0 17 00 00 */	lfs f0, 0(r23)
/* 8023E38C  EC 00 C8 2A */	fadds f0, f0, f25
/* 8023E390  D0 17 00 00 */	stfs f0, 0(r23)
/* 8023E394  C0 18 00 00 */	lfs f0, 0(r24)
/* 8023E398  EC 00 C0 2A */	fadds f0, f0, f24
/* 8023E39C  D0 18 00 00 */	stfs f0, 0(r24)
/* 8023E3A0  48 00 00 14 */	b 0x14
/* 8023E3A4  C0 03 00 40 */	lfs f0, 0x40(r3)
/* 8023E3A8  D0 04 00 00 */	stfs f0, 0(r4)
/* 8023E3AC  C0 03 00 44 */	lfs f0, 0x44(r3)
/* 8023E3B0  D0 05 00 00 */	stfs f0, 0(r5)
/* 8023E3B4  E3 E1 00 C8 */	psq_l f31, 200(r1), 0, qr0
/* 8023E3B8  CB E1 00 C0 */	lfd f31, 0xc0(r1)
/* 8023E3BC  E3 C1 00 B8 */	psq_l f30, 184(r1), 0, qr0
/* 8023E3C0  CB C1 00 B0 */	lfd f30, 0xb0(r1)
/* 8023E3C4  E3 A1 00 A8 */	psq_l f29, 168(r1), 0, qr0
/* 8023E3C8  CB A1 00 A0 */	lfd f29, 0xa0(r1)
/* 8023E3CC  E3 81 00 98 */	psq_l f28, 152(r1), 0, qr0
/* 8023E3D0  CB 81 00 90 */	lfd f28, 0x90(r1)
/* 8023E3D4  E3 61 00 88 */	psq_l f27, 136(r1), 0, qr0
/* 8023E3D8  CB 61 00 80 */	lfd f27, 0x80(r1)
/* 8023E3DC  E3 41 00 78 */	psq_l f26, 120(r1), 0, qr0
/* 8023E3E0  CB 41 00 70 */	lfd f26, 0x70(r1)
/* 8023E3E4  E3 21 00 68 */	psq_l f25, 104(r1), 0, qr0
/* 8023E3E8  CB 21 00 60 */	lfd f25, 0x60(r1)
/* 8023E3EC  E3 01 00 58 */	psq_l f24, 88(r1), 0, qr0
/* 8023E3F0  39 61 00 50 */	addi r11, r1, 0x50
/* 8023E3F4  CB 01 00 50 */	lfd f24, 0x50(r1)
/* 8023E3F8  4B DE 31 E1 */	bl -0x21ce20
/* 8023E3FC  80 01 00 D4 */	lwz r0, 0xd4(r1)
/* 8023E400  7C 08 03 A6 */	mtlr r0
/* 8023E404  38 21 00 D0 */	addi r1, r1, 0xd0
/* 8023E408  4E 80 00 20 */	blr
/* 8023E40C  C0 62 A0 A0 */	lfs f3, -0x5f60(r2)
/* 8023E410  C0 03 00 08 */	lfs f0, 8(r3)
/* 8023E414  EC 03 00 32 */	fmuls f0, f3, f0
/* 8023E418  EC 01 00 2A */	fadds f0, f1, f0
/* 8023E41C  D0 04 00 00 */	stfs f0, 0(r4)
/* 8023E420  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8023E424  EC 03 00 32 */	fmuls f0, f3, f0
/* 8023E428  EC 02 00 28 */	fsubs f0, f2, f0
/* 8023E42C  FC 00 00 50 */	fneg f0, f0
/* 8023E430  D0 05 00 00 */	stfs f0, 0(r5)
/* 8023E434  4E 80 00 20 */	blr
/* 8023E438  80 03 00 04 */	lwz r0, 4(r3)
/* 8023E43C  2C 00 00 01 */	cmpwi r0, 1
/* 8023E440  40 82 00 10 */	bne 0x10
/* 8023E444  D0 24 00 00 */	stfs f1, 0(r4)
/* 8023E448  D0 45 00 00 */	stfs f2, 0(r5)
/* 8023E44C  4E 80 00 20 */	blr
/* 8023E450  2C 00 00 00 */	cmpwi r0, 0
/* 8023E454  4C 82 00 20 */	bnelr
/* 8023E458  C0 62 A0 A0 */	lfs f3, -0x5f60(r2)
/* 8023E45C  C0 03 00 08 */	lfs f0, 8(r3)
/* 8023E460  EC 03 00 32 */	fmuls f0, f3, f0
/* 8023E464  EC 01 00 2A */	fadds f0, f1, f0
/* 8023E468  D0 04 00 00 */	stfs f0, 0(r4)
/* 8023E46C  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 8023E470  EC 03 00 32 */	fmuls f0, f3, f0
/* 8023E474  EC 02 00 28 */	fsubs f0, f2, f0
/* 8023E478  FC 00 00 50 */	fneg f0, f0
/* 8023E47C  D0 05 00 00 */	stfs f0, 0(r5)
/* 8023E480  4E 80 00 20 */	blr
/* 8023E484  80 63 00 3C */	lwz r3, 0x3c(r3)
/* 8023E488  4E 80 00 20 */	blr
/* 8023E48C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023E490  7C 08 02 A6 */	mflr r0
/* 8023E494  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023E498  80 CD A3 14 */	lwz r6, -0x5cec(r13)
/* 8023E49C  90 6D A3 10 */	stw r3, -0x5cf0(r13)
/* 8023E4A0  2C 06 00 00 */	cmpwi r6, 0
/* 8023E4A4  41 82 00 70 */	beq 0x70
/* 8023E4A8  1C 83 00 0C */	mulli r4, r3, 0xc
/* 8023E4AC  3C 60 43 30 */	lis r3, 0x4330
/* 8023E4B0  3C A0 80 2A */	lis r5, 0x802a
/* 8023E4B4  A0 06 00 34 */	lhz r0, 0x34(r6)
/* 8023E4B8  90 61 00 08 */	stw r3, 8(r1)
/* 8023E4BC  38 A5 3E E8 */	addi r5, r5, 0x3ee8
/* 8023E4C0  7C 85 22 2E */	lhzx r4, r5, r4
/* 8023E4C4  60 00 00 01 */	ori r0, r0, 1
/* 8023E4C8  90 81 00 0C */	stw r4, 0xc(r1)
/* 8023E4CC  C8 22 A0 88 */	lfd f1, -0x5f78(r2)
/* 8023E4D0  C8 01 00 08 */	lfd f0, 8(r1)
/* 8023E4D4  B0 06 00 34 */	sth r0, 0x34(r6)
/* 8023E4D8  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023E4DC  90 61 00 10 */	stw r3, 0x10(r1)
/* 8023E4E0  D0 06 00 08 */	stfs f0, 8(r6)
/* 8023E4E4  80 0D A3 10 */	lwz r0, -0x5cf0(r13)
/* 8023E4E8  80 8D A3 14 */	lwz r4, -0x5cec(r13)
/* 8023E4EC  1C 60 00 0C */	mulli r3, r0, 0xc
/* 8023E4F0  A0 04 00 34 */	lhz r0, 0x34(r4)
/* 8023E4F4  7C 65 1A 14 */	add r3, r5, r3
/* 8023E4F8  60 00 00 01 */	ori r0, r0, 1
/* 8023E4FC  A0 63 00 02 */	lhz r3, 2(r3)
/* 8023E500  90 61 00 14 */	stw r3, 0x14(r1)
/* 8023E504  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023E508  B0 04 00 34 */	sth r0, 0x34(r4)
/* 8023E50C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023E510  D0 04 00 0C */	stfs f0, 0xc(r4)
/* 8023E514  81 8D A3 18 */	lwz r12, -0x5ce8(r13)
/* 8023E518  2C 0C 00 00 */	cmpwi r12, 0
/* 8023E51C  41 82 00 10 */	beq 0x10
/* 8023E520  80 6D A3 1C */	lwz r3, -0x5ce4(r13)
/* 8023E524  7D 89 03 A6 */	mtctr r12
/* 8023E528  4E 80 04 21 */	bctrl
/* 8023E52C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023E530  7C 08 03 A6 */	mtlr r0
/* 8023E534  38 21 00 20 */	addi r1, r1, 0x20
/* 8023E538  4E 80 00 20 */	blr
/* 8023E53C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023E540  7C 08 02 A6 */	mflr r0
/* 8023E544  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023E548  4B F7 36 9D */	bl -0x8c964
/* 8023E54C  54 63 06 3E */	clrlwi r3, r3, 0x18
/* 8023E550  80 CD A3 14 */	lwz r6, -0x5cec(r13)
/* 8023E554  7C 03 00 D0 */	neg r0, r3
/* 8023E558  7C 00 1B 78 */	or r0, r0, r3
/* 8023E55C  2C 06 00 00 */	cmpwi r6, 0
/* 8023E560  54 00 0F FE */	srwi r0, r0, 0x1f
/* 8023E564  90 0D A3 10 */	stw r0, -0x5cf0(r13)
/* 8023E568  41 82 00 70 */	beq 0x70
/* 8023E56C  1C 80 00 0C */	mulli r4, r0, 0xc
/* 8023E570  3C 60 43 30 */	lis r3, 0x4330
/* 8023E574  3C A0 80 2A */	lis r5, 0x802a
/* 8023E578  A0 06 00 34 */	lhz r0, 0x34(r6)
/* 8023E57C  90 61 00 08 */	stw r3, 8(r1)
/* 8023E580  38 A5 3E E8 */	addi r5, r5, 0x3ee8
/* 8023E584  7C 85 22 2E */	lhzx r4, r5, r4
/* 8023E588  60 00 00 01 */	ori r0, r0, 1
/* 8023E58C  90 81 00 0C */	stw r4, 0xc(r1)
/* 8023E590  C8 22 A0 88 */	lfd f1, -0x5f78(r2)
/* 8023E594  C8 01 00 08 */	lfd f0, 8(r1)
/* 8023E598  B0 06 00 34 */	sth r0, 0x34(r6)
/* 8023E59C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023E5A0  90 61 00 10 */	stw r3, 0x10(r1)
/* 8023E5A4  D0 06 00 08 */	stfs f0, 8(r6)
/* 8023E5A8  80 0D A3 10 */	lwz r0, -0x5cf0(r13)
/* 8023E5AC  80 8D A3 14 */	lwz r4, -0x5cec(r13)
/* 8023E5B0  1C 60 00 0C */	mulli r3, r0, 0xc
/* 8023E5B4  A0 04 00 34 */	lhz r0, 0x34(r4)
/* 8023E5B8  7C 65 1A 14 */	add r3, r5, r3
/* 8023E5BC  60 00 00 01 */	ori r0, r0, 1
/* 8023E5C0  A0 63 00 02 */	lhz r3, 2(r3)
/* 8023E5C4  90 61 00 14 */	stw r3, 0x14(r1)
/* 8023E5C8  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 8023E5CC  B0 04 00 34 */	sth r0, 0x34(r4)
/* 8023E5D0  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023E5D4  D0 04 00 0C */	stfs f0, 0xc(r4)
/* 8023E5D8  81 8D A3 18 */	lwz r12, -0x5ce8(r13)
/* 8023E5DC  2C 0C 00 00 */	cmpwi r12, 0
/* 8023E5E0  41 82 00 10 */	beq 0x10
/* 8023E5E4  80 6D A3 1C */	lwz r3, -0x5ce4(r13)
/* 8023E5E8  7D 89 03 A6 */	mtctr r12
/* 8023E5EC  4E 80 04 21 */	bctrl
/* 8023E5F0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023E5F4  7C 08 03 A6 */	mtlr r0
/* 8023E5F8  38 21 00 20 */	addi r1, r1, 0x20
/* 8023E5FC  4E 80 00 20 */	blr
/* 8023E600  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8023E604  7C 08 02 A6 */	mflr r0
/* 8023E608  90 01 00 44 */	stw r0, 0x44(r1)
/* 8023E60C  DB E1 00 30 */	stfd f31, 0x30(r1)
/* 8023E610  F3 E1 00 38 */	psq_st f31, 56(r1), 0, qr0
/* 8023E614  DB C1 00 20 */	stfd f30, 0x20(r1)
/* 8023E618  F3 C1 00 28 */	psq_st f30, 40(r1), 0, qr0
/* 8023E61C  FF C0 08 90 */	fmr f30, f1
/* 8023E620  FF E0 10 90 */	fmr f31, f2
/* 8023E624  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023E628  7C BF 2B 78 */	mr r31, r5
/* 8023E62C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023E630  7C 9E 23 78 */	mr r30, r4
/* 8023E634  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023E638  7C 7D 1B 78 */	mr r29, r3
/* 8023E63C  4B FF FA 05 */	bl -0x5fc
/* 8023E640  80 1D 00 04 */	lwz r0, 4(r29)
/* 8023E644  2C 00 00 01 */	cmpwi r0, 1
/* 8023E648  40 82 00 08 */	bne 0x8
/* 8023E64C  48 00 00 2C */	b 0x2c
/* 8023E650  2C 00 00 00 */	cmpwi r0, 0
/* 8023E654  40 82 00 24 */	bne 0x24
/* 8023E658  C0 42 A0 A0 */	lfs f2, -0x5f60(r2)
/* 8023E65C  C0 1D 00 0C */	lfs f0, 0xc(r29)
/* 8023E660  C0 3D 00 08 */	lfs f1, 8(r29)
/* 8023E664  EC 02 00 32 */	fmuls f0, f2, f0
/* 8023E668  EC 22 00 72 */	fmuls f1, f2, f1
/* 8023E66C  EC 1F 00 28 */	fsubs f0, f31, f0
/* 8023E670  EF DE 08 2A */	fadds f30, f30, f1
/* 8023E674  FF E0 00 50 */	fneg f31, f0
/* 8023E678  A0 7D 00 34 */	lhz r3, 0x34(r29)
/* 8023E67C  54 60 06 B5 */	rlwinm. r0, r3, 0, 0x1a, 0x1a
/* 8023E680  40 82 00 18 */	bne 0x18
/* 8023E684  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 8023E688  38 00 00 02 */	li r0, 2
/* 8023E68C  40 82 00 10 */	bne 0x10
/* 8023E690  80 0D A3 10 */	lwz r0, -0x5cf0(r13)
/* 8023E694  48 00 00 08 */	b 0x8
/* 8023E698  38 00 00 00 */	li r0, 0
/* 8023E69C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 8023E6A0  C0 1E 00 00 */	lfs f0, 0(r30)
/* 8023E6A4  3C 60 80 2A */	lis r3, 0x802a
/* 8023E6A8  EC 20 F0 2A */	fadds f1, f0, f30
/* 8023E6AC  38 63 3E E8 */	addi r3, r3, 0x3ee8
/* 8023E6B0  7C 63 02 14 */	add r3, r3, r0
/* 8023E6B4  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023E6B8  EC 00 00 72 */	fmuls f0, f0, f1
/* 8023E6BC  D0 1E 00 00 */	stfs f0, 0(r30)
/* 8023E6C0  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8023E6C4  C0 03 00 08 */	lfs f0, 8(r3)
/* 8023E6C8  EC 21 F8 2A */	fadds f1, f1, f31
/* 8023E6CC  EC 00 00 72 */	fmuls f0, f0, f1
/* 8023E6D0  D0 1F 00 00 */	stfs f0, 0(r31)
/* 8023E6D4  E3 E1 00 38 */	psq_l f31, 56(r1), 0, qr0
/* 8023E6D8  CB E1 00 30 */	lfd f31, 0x30(r1)
/* 8023E6DC  E3 C1 00 28 */	psq_l f30, 40(r1), 0, qr0
/* 8023E6E0  CB C1 00 20 */	lfd f30, 0x20(r1)
/* 8023E6E4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023E6E8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 8023E6EC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8023E6F0  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8023E6F4  7C 08 03 A6 */	mtlr r0
/* 8023E6F8  38 21 00 40 */	addi r1, r1, 0x40
/* 8023E6FC  4E 80 00 20 */	blr
/* 8023E700  C0 22 A0 84 */	lfs f1, -0x5f7c(r2)
/* 8023E704  38 8D A3 20 */	addi r4, r13, -23776
/* 8023E708  C0 02 A0 80 */	lfs f0, -0x5f80(r2)
/* 8023E70C  38 6D A3 28 */	addi r3, r13, -23768
/* 8023E710  D0 2D A3 20 */	stfs f1, -0x5ce0(r13)
/* 8023E714  D0 24 00 04 */	stfs f1, 4(r4)
/* 8023E718  D0 0D A3 28 */	stfs f0, -0x5cd8(r13)
/* 8023E71C  D0 03 00 04 */	stfs f0, 4(r3)
/* 8023E720  4E 80 00 20 */	blr
/* 8023E724  3C 80 80 2A */	lis r4, 0x802a
/* 8023E728  38 00 00 01 */	li r0, 1
/* 8023E72C  38 84 3F 20 */	addi r4, r4, 0x3f20
/* 8023E730  90 83 00 04 */	stw r4, 4(r3)
/* 8023E734  98 03 00 00 */	stb r0, 0(r3)
/* 8023E738  4E 80 00 20 */	blr
/* 8023E73C  3C 60 80 38 */	lis r3, 0x8038
/* 8023E740  38 63 44 18 */	addi r3, r3, 0x4418
/* 8023E744  4B FF EB 70 */	b -0x1490
/* 8023E748  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023E74C  7C 08 02 A6 */	mflr r0
/* 8023E750  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023E754  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023E758  7C 7F 1B 78 */	mr r31, r3
/* 8023E75C  4B FF FF C9 */	bl -0x38
/* 8023E760  C0 42 A0 B0 */	lfs f2, -0x5f50(r2)
/* 8023E764  3C 60 80 2A */	lis r3, 0x802a
/* 8023E768  C0 22 A0 B4 */	lfs f1, -0x5f4c(r2)
/* 8023E76C  38 80 00 00 */	li r4, 0
/* 8023E770  C0 02 A0 B8 */	lfs f0, -0x5f48(r2)
/* 8023E774  38 63 3F 30 */	addi r3, r3, 0x3f30
/* 8023E778  38 00 00 03 */	li r0, 3
/* 8023E77C  90 7F 00 04 */	stw r3, 4(r31)
/* 8023E780  38 60 00 50 */	li r3, 0x50
/* 8023E784  98 1F 00 08 */	stb r0, 8(r31)
/* 8023E788  98 9F 00 09 */	stb r4, 9(r31)
/* 8023E78C  90 9F 00 0C */	stw r4, 0xc(r31)
/* 8023E790  D0 5F 00 14 */	stfs f2, 0x14(r31)
/* 8023E794  D0 5F 00 18 */	stfs f2, 0x18(r31)
/* 8023E798  D0 3F 00 1C */	stfs f1, 0x1c(r31)
/* 8023E79C  D0 5F 00 20 */	stfs f2, 0x20(r31)
/* 8023E7A0  D0 3F 00 24 */	stfs f1, 0x24(r31)
/* 8023E7A4  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8023E7A8  88 02 A0 AC */	lbz r0, -0x5f54(r2)
/* 8023E7AC  98 1F 00 2C */	stb r0, 0x2c(r31)
/* 8023E7B0  88 02 A0 AD */	lbz r0, -0x5f53(r2)
/* 8023E7B4  98 1F 00 2D */	stb r0, 0x2d(r31)
/* 8023E7B8  88 02 A0 AE */	lbz r0, -0x5f52(r2)
/* 8023E7BC  98 1F 00 2E */	stb r0, 0x2e(r31)
/* 8023E7C0  88 02 A0 AF */	lbz r0, -0x5f51(r2)
/* 8023E7C4  98 1F 00 2F */	stb r0, 0x2f(r31)
/* 8023E7C8  90 9F 00 38 */	stw r4, 0x38(r31)
/* 8023E7CC  4B FE B6 01 */	bl -0x14a00
/* 8023E7D0  2C 03 00 00 */	cmpwi r3, 0
/* 8023E7D4  41 82 00 08 */	beq 0x8
/* 8023E7D8  4B FF 7A 79 */	bl -0x8588
/* 8023E7DC  90 7F 00 30 */	stw r3, 0x30(r31)
/* 8023E7E0  38 60 00 70 */	li r3, 0x70
/* 8023E7E4  4B FE B5 E9 */	bl -0x14a18
/* 8023E7E8  2C 03 00 00 */	cmpwi r3, 0
/* 8023E7EC  7C 65 1B 78 */	mr r5, r3
/* 8023E7F0  41 82 00 0C */	beq 0xc
/* 8023E7F4  4B FF 69 FD */	bl -0x9604
/* 8023E7F8  7C 65 1B 78 */	mr r5, r3
/* 8023E7FC  90 BF 00 34 */	stw r5, 0x34(r31)
/* 8023E800  38 80 00 02 */	li r4, 2
/* 8023E804  38 00 00 04 */	li r0, 4
/* 8023E808  7F E3 FB 78 */	mr r3, r31
/* 8023E80C  90 85 00 00 */	stw r4, 0(r5)
/* 8023E810  80 9F 00 34 */	lwz r4, 0x34(r31)
/* 8023E814  98 04 00 30 */	stb r0, 0x30(r4)
/* 8023E818  88 C2 A0 A9 */	lbz r6, -0x5f57(r2)
/* 8023E81C  88 A2 A0 AA */	lbz r5, -0x5f56(r2)
/* 8023E820  88 02 A0 AB */	lbz r0, -0x5f55(r2)
/* 8023E824  88 E2 A0 A8 */	lbz r7, -0x5f58(r2)
/* 8023E828  80 9F 00 34 */	lwz r4, 0x34(r31)
/* 8023E82C  98 01 00 0B */	stb r0, 0xb(r1)
/* 8023E830  98 E4 00 31 */	stb r7, 0x31(r4)
/* 8023E834  98 C4 00 32 */	stb r6, 0x32(r4)
/* 8023E838  98 A4 00 33 */	stb r5, 0x33(r4)
/* 8023E83C  98 04 00 34 */	stb r0, 0x34(r4)
/* 8023E840  80 9F 00 34 */	lwz r4, 0x34(r31)
/* 8023E844  C0 1F 00 20 */	lfs f0, 0x20(r31)
/* 8023E848  D0 04 00 3C */	stfs f0, 0x3c(r4)
/* 8023E84C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8023E850  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8023E854  98 E1 00 08 */	stb r7, 8(r1)
/* 8023E858  98 C1 00 09 */	stb r6, 9(r1)
/* 8023E85C  98 A1 00 0A */	stb r5, 0xa(r1)
/* 8023E860  7C 08 03 A6 */	mtlr r0
/* 8023E864  38 21 00 20 */	addi r1, r1, 0x20
/* 8023E868  4E 80 00 20 */	blr
/* 8023E86C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023E870  7C 08 02 A6 */	mflr r0
/* 8023E874  2C 03 00 00 */	cmpwi r3, 0
/* 8023E878  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023E87C  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023E880  7C 9F 23 78 */	mr r31, r4
/* 8023E884  93 C1 00 08 */	stw r30, 8(r1)
/* 8023E888  7C 7E 1B 78 */	mr r30, r3
/* 8023E88C  41 82 00 64 */	beq 0x64
/* 8023E890  80 03 00 30 */	lwz r0, 0x30(r3)
/* 8023E894  3C 80 80 2A */	lis r4, 0x802a
/* 8023E898  38 84 3F 30 */	addi r4, r4, 0x3f30
/* 8023E89C  90 83 00 04 */	stw r4, 4(r3)
/* 8023E8A0  2C 00 00 00 */	cmpwi r0, 0
/* 8023E8A4  41 82 00 1C */	beq 0x1c
/* 8023E8A8  7C 03 03 78 */	mr r3, r0
/* 8023E8AC  38 80 00 01 */	li r4, 1
/* 8023E8B0  81 83 00 24 */	lwz r12, 0x24(r3)
/* 8023E8B4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8023E8B8  7D 89 03 A6 */	mtctr r12
/* 8023E8BC  4E 80 04 21 */	bctrl
/* 8023E8C0  80 7E 00 34 */	lwz r3, 0x34(r30)
/* 8023E8C4  2C 03 00 00 */	cmpwi r3, 0
/* 8023E8C8  41 82 00 18 */	beq 0x18
/* 8023E8CC  81 83 00 24 */	lwz r12, 0x24(r3)
/* 8023E8D0  38 80 00 01 */	li r4, 1
/* 8023E8D4  81 8C 00 08 */	lwz r12, 8(r12)
/* 8023E8D8  7D 89 03 A6 */	mtctr r12
/* 8023E8DC  4E 80 04 21 */	bctrl
/* 8023E8E0  2C 1F 00 00 */	cmpwi r31, 0
/* 8023E8E4  40 81 00 0C */	ble 0xc
/* 8023E8E8  7F C3 F3 78 */	mr r3, r30
/* 8023E8EC  4B FE B5 29 */	bl -0x14ad8
/* 8023E8F0  7F C3 F3 78 */	mr r3, r30
/* 8023E8F4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023E8F8  83 C1 00 08 */	lwz r30, 8(r1)
/* 8023E8FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023E900  7C 08 03 A6 */	mtlr r0
/* 8023E904  38 21 00 10 */	addi r1, r1, 0x10
/* 8023E908  4E 80 00 20 */	blr
/* 8023E90C  94 21 FE F0 */	stwu r1, -0x110(r1)
/* 8023E910  7C 08 02 A6 */	mflr r0
/* 8023E914  90 01 01 14 */	stw r0, 0x114(r1)
/* 8023E918  DB E1 01 00 */	stfd f31, 0x100(r1)
/* 8023E91C  F3 E1 01 08 */	psq_st f31, 264(r1), 0, qr0
/* 8023E920  DB C1 00 F0 */	stfd f30, 0xf0(r1)
/* 8023E924  F3 C1 00 F8 */	psq_st f30, 248(r1), 0, qr0
/* 8023E928  DB A1 00 E0 */	stfd f29, 0xe0(r1)
/* 8023E92C  F3 A1 00 E8 */	psq_st f29, 232(r1), 0, qr0
/* 8023E930  DB 81 00 D0 */	stfd f28, 0xd0(r1)
/* 8023E934  F3 81 00 D8 */	psq_st f28, 216(r1), 0, qr0
/* 8023E938  39 61 00 D0 */	addi r11, r1, 0xd0
/* 8023E93C  4B DE 2C 49 */	bl -0x21d3b8
/* 8023E940  88 03 00 00 */	lbz r0, 0(r3)
/* 8023E944  3C 80 43 30 */	lis r4, 0x4330
/* 8023E948  90 81 00 60 */	stw r4, 0x60(r1)
/* 8023E94C  7C 74 1B 78 */	mr r20, r3
/* 8023E950  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023E954  90 81 00 68 */	stw r4, 0x68(r1)
/* 8023E958  41 82 06 00 */	beq 0x600
/* 8023E95C  4B F3 27 B5 */	bl -0xcd84c
/* 8023E960  3E A0 80 38 */	lis r21, 0x8038
/* 8023E964  38 75 44 18 */	addi r3, r21, 0x4418
/* 8023E968  4B FF 67 95 */	bl -0x986c
/* 8023E96C  38 75 44 18 */	addi r3, r21, 0x4418
/* 8023E970  4B FF F2 69 */	bl -0xd98
/* 8023E974  38 95 44 18 */	addi r4, r21, 0x4418
/* 8023E978  C0 F4 00 14 */	lfs f7, 0x14(r20)
/* 8023E97C  C0 14 00 18 */	lfs f0, 0x18(r20)
/* 8023E980  3F C0 80 38 */	lis r30, 0x8038
/* 8023E984  C0 64 00 08 */	lfs f3, 8(r4)
/* 8023E988  3B DE 45 20 */	addi r30, r30, 0x4520
/* 8023E98C  C0 44 00 0C */	lfs f2, 0xc(r4)
/* 8023E990  EF 80 38 24 */	fdivs f28, f0, f7
/* 8023E994  C0 C3 00 08 */	lfs f6, 8(r3)
/* 8023E998  7C 7F 1B 78 */	mr r31, r3
/* 8023E99C  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023E9A0  3A C0 00 06 */	li r22, 6
/* 8023E9A4  C0 A3 00 0C */	lfs f5, 0xc(r3)
/* 8023E9A8  FC 60 18 1E */	fctiwz f3, f3
/* 8023E9AC  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023E9B0  FC 40 10 1E */	fctiwz f2, f2
/* 8023E9B4  C8 82 A0 C8 */	lfd f4, -0x5f38(r2)
/* 8023E9B8  D8 61 00 80 */	stfd f3, 0x80(r1)
/* 8023E9BC  EC 65 01 F2 */	fmuls f3, f5, f7
/* 8023E9C0  D8 41 00 88 */	stfd f2, 0x88(r1)
/* 8023E9C4  EC C6 01 F2 */	fmuls f6, f6, f7
/* 8023E9C8  80 01 00 84 */	lwz r0, 0x84(r1)
/* 8023E9CC  FC A0 18 1E */	fctiwz f5, f3
/* 8023E9D0  FC 20 08 1E */	fctiwz f1, f1
/* 8023E9D4  80 61 00 8C */	lwz r3, 0x8c(r1)
/* 8023E9D8  54 00 04 3E */	clrlwi r0, r0, 0x10
/* 8023E9DC  90 01 00 64 */	stw r0, 0x64(r1)
/* 8023E9E0  54 60 04 3E */	clrlwi r0, r3, 0x10
/* 8023E9E4  FC C0 30 1E */	fctiwz f6, f6
/* 8023E9E8  90 01 00 6C */	stw r0, 0x6c(r1)
/* 8023E9EC  FC 00 00 1E */	fctiwz f0, f0
/* 8023E9F0  C8 61 00 60 */	lfd f3, 0x60(r1)
/* 8023E9F4  38 60 00 01 */	li r3, 1
/* 8023E9F8  C8 41 00 68 */	lfd f2, 0x68(r1)
/* 8023E9FC  EC 63 20 28 */	fsubs f3, f3, f4
/* 8023EA00  D8 C1 00 70 */	stfd f6, 0x70(r1)
/* 8023EA04  EC 42 20 28 */	fsubs f2, f2, f4
/* 8023EA08  C3 A2 A0 B0 */	lfs f29, -0x5f50(r2)
/* 8023EA0C  D8 A1 00 78 */	stfd f5, 0x78(r1)
/* 8023EA10  EF E7 00 F2 */	fmuls f31, f7, f3
/* 8023EA14  D8 21 00 90 */	stfd f1, 0x90(r1)
/* 8023EA18  EF C7 00 B2 */	fmuls f30, f7, f2
/* 8023EA1C  83 41 00 74 */	lwz r26, 0x74(r1)
/* 8023EA20  D8 01 00 98 */	stfd f0, 0x98(r1)
/* 8023EA24  83 21 00 7C */	lwz r25, 0x7c(r1)
/* 8023EA28  83 01 00 94 */	lwz r24, 0x94(r1)
/* 8023EA2C  82 E1 00 9C */	lwz r23, 0x9c(r1)
/* 8023EA30  8B BE 00 0C */	lbz r29, 0xc(r30)
/* 8023EA34  4B F3 3D 99 */	bl -0xcc268
/* 8023EA38  38 00 00 01 */	li r0, 1
/* 8023EA3C  98 1E 00 0C */	stb r0, 0xc(r30)
/* 8023EA40  8B 9E 00 0D */	lbz r28, 0xd(r30)
/* 8023EA44  38 60 00 00 */	li r3, 0
/* 8023EA48  4B F3 3D B1 */	bl -0xcc250
/* 8023EA4C  3A A0 00 00 */	li r21, 0
/* 8023EA50  9A BE 00 0D */	stb r21, 0xd(r30)
/* 8023EA54  8B 7E 00 0E */	lbz r27, 0xe(r30)
/* 8023EA58  38 60 00 00 */	li r3, 0
/* 8023EA5C  4B F3 3E D5 */	bl -0xcc12c
/* 8023EA60  9A BE 00 0E */	stb r21, 0xe(r30)
/* 8023EA64  3A A0 00 00 */	li r21, 0
/* 8023EA68  88 14 00 08 */	lbz r0, 8(r20)
/* 8023EA6C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023EA70  41 82 00 7C */	beq 0x7c
/* 8023EA74  57 40 04 3F */	clrlwi. r0, r26, 0x10
/* 8023EA78  41 82 00 0C */	beq 0xc
/* 8023EA7C  57 20 04 3F */	clrlwi. r0, r25, 0x10
/* 8023EA80  40 82 00 0C */	bne 0xc
/* 8023EA84  3A A0 00 00 */	li r21, 0
/* 8023EA88  48 00 00 4C */	b 0x4c
/* 8023EA8C  48 00 46 E9 */	bl 0x46e8
/* 8023EA90  B3 43 00 00 */	sth r26, 0(r3)
/* 8023EA94  7C 75 1B 78 */	mr r21, r3
/* 8023EA98  B3 23 00 02 */	sth r25, 2(r3)
/* 8023EA9C  9A C3 00 05 */	stb r22, 5(r3)
/* 8023EAA0  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8023EAA4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023EAA8  7D 89 03 A6 */	mtctr r12
/* 8023EAAC  4E 80 04 21 */	bctrl
/* 8023EAB0  A0 75 00 00 */	lhz r3, 0(r21)
/* 8023EAB4  38 C0 00 00 */	li r6, 0
/* 8023EAB8  A0 95 00 02 */	lhz r4, 2(r21)
/* 8023EABC  38 E0 00 01 */	li r7, 1
/* 8023EAC0  88 B5 00 05 */	lbz r5, 5(r21)
/* 8023EAC4  4B F3 1B 51 */	bl -0xce4b0
/* 8023EAC8  7C 64 1B 78 */	mr r4, r3
/* 8023EACC  7E A3 AB 78 */	mr r3, r21
/* 8023EAD0  48 00 46 CD */	bl 0x46cc
/* 8023EAD4  7E A3 AB 78 */	mr r3, r21
/* 8023EAD8  57 04 04 3E */	clrlwi r4, r24, 0x10
/* 8023EADC  56 E5 04 3E */	clrlwi r5, r23, 0x10
/* 8023EAE0  38 C0 00 00 */	li r6, 0
/* 8023EAE4  38 E0 00 06 */	li r7, 6
/* 8023EAE8  4B FD 61 8D */	bl -0x29e74
/* 8023EAEC  C0 1F 00 08 */	lfs f0, 8(r31)
/* 8023EAF0  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8023EAF4  FC 00 00 1E */	fctiwz f0, f0
/* 8023EAF8  FC 20 08 1E */	fctiwz f1, f1
/* 8023EAFC  D8 01 00 90 */	stfd f0, 0x90(r1)
/* 8023EB00  83 C1 00 94 */	lwz r30, 0x94(r1)
/* 8023EB04  D8 21 00 98 */	stfd f1, 0x98(r1)
/* 8023EB08  57 C0 04 3F */	clrlwi. r0, r30, 0x10
/* 8023EB0C  83 E1 00 9C */	lwz r31, 0x9c(r1)
/* 8023EB10  41 82 00 0C */	beq 0xc
/* 8023EB14  57 E0 04 3F */	clrlwi. r0, r31, 0x10
/* 8023EB18  40 82 00 0C */	bne 0xc
/* 8023EB1C  3B C0 00 00 */	li r30, 0
/* 8023EB20  48 00 00 50 */	b 0x50
/* 8023EB24  48 00 46 51 */	bl 0x4650
/* 8023EB28  B3 C3 00 00 */	sth r30, 0(r3)
/* 8023EB2C  38 00 00 03 */	li r0, 3
/* 8023EB30  7C 7E 1B 78 */	mr r30, r3
/* 8023EB34  B3 E3 00 02 */	sth r31, 2(r3)
/* 8023EB38  98 03 00 05 */	stb r0, 5(r3)
/* 8023EB3C  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8023EB40  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023EB44  7D 89 03 A6 */	mtctr r12
/* 8023EB48  4E 80 04 21 */	bctrl
/* 8023EB4C  A0 7E 00 00 */	lhz r3, 0(r30)
/* 8023EB50  38 C0 00 00 */	li r6, 0
/* 8023EB54  A0 9E 00 02 */	lhz r4, 2(r30)
/* 8023EB58  38 E0 00 01 */	li r7, 1
/* 8023EB5C  88 BE 00 05 */	lbz r5, 5(r30)
/* 8023EB60  4B F3 1A B5 */	bl -0xce54c
/* 8023EB64  7C 64 1B 78 */	mr r4, r3
/* 8023EB68  7F C3 F3 78 */	mr r3, r30
/* 8023EB6C  48 00 46 31 */	bl 0x4630
/* 8023EB70  3B E0 00 00 */	li r31, 0
/* 8023EB74  9B FE 00 08 */	stb r31, 8(r30)
/* 8023EB78  7F C3 F3 78 */	mr r3, r30
/* 8023EB7C  57 04 04 3E */	clrlwi r4, r24, 0x10
/* 8023EB80  9B FE 00 09 */	stb r31, 9(r30)
/* 8023EB84  56 E5 04 3E */	clrlwi r5, r23, 0x10
/* 8023EB88  38 C0 00 00 */	li r6, 0
/* 8023EB8C  38 E0 00 13 */	li r7, 0x13
/* 8023EB90  4B FD 60 E5 */	bl -0x29f1c
/* 8023EB94  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EB98  FC 20 F8 90 */	fmr f1, f31
/* 8023EB9C  80 14 00 0C */	lwz r0, 0xc(r20)
/* 8023EBA0  FC 40 F0 90 */	fmr f2, f30
/* 8023EBA4  90 03 00 28 */	stw r0, 0x28(r3)
/* 8023EBA8  C0 82 A0 BC */	lfs f4, -0x5f44(r2)
/* 8023EBAC  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EBB0  C0 02 A0 C0 */	lfs f0, -0x5f40(r2)
/* 8023EBB4  D3 83 00 40 */	stfs f28, 0x40(r3)
/* 8023EBB8  C0 74 00 24 */	lfs f3, 0x24(r20)
/* 8023EBBC  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EBC0  EC 64 00 F2 */	fmuls f3, f4, f3
/* 8023EBC4  FC 60 18 1E */	fctiwz f3, f3
/* 8023EBC8  D8 61 00 98 */	stfd f3, 0x98(r1)
/* 8023EBCC  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 8023EBD0  B0 03 00 34 */	sth r0, 0x34(r3)
/* 8023EBD4  C0 74 00 28 */	lfs f3, 0x28(r20)
/* 8023EBD8  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EBDC  FC 60 18 50 */	fneg f3, f3
/* 8023EBE0  EC 00 00 F2 */	fmuls f0, f0, f3
/* 8023EBE4  D0 03 00 38 */	stfs f0, 0x38(r3)
/* 8023EBE8  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EBEC  93 C3 00 04 */	stw r30, 4(r3)
/* 8023EBF0  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EBF4  93 E3 00 08 */	stw r31, 8(r3)
/* 8023EBF8  80 74 00 30 */	lwz r3, 0x30(r20)
/* 8023EBFC  81 83 00 24 */	lwz r12, 0x24(r3)
/* 8023EC00  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023EC04  7D 89 03 A6 */	mtctr r12
/* 8023EC08  4E 80 04 21 */	bctrl
/* 8023EC0C  88 14 00 08 */	lbz r0, 8(r20)
/* 8023EC10  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 8023EC14  41 82 01 30 */	beq 0x130
/* 8023EC18  57 40 04 3F */	clrlwi. r0, r26, 0x10
/* 8023EC1C  41 82 00 0C */	beq 0xc
/* 8023EC20  57 20 04 3F */	clrlwi. r0, r25, 0x10
/* 8023EC24  40 82 00 0C */	bne 0xc
/* 8023EC28  3B E0 00 00 */	li r31, 0
/* 8023EC2C  48 00 00 4C */	b 0x4c
/* 8023EC30  48 00 45 45 */	bl 0x4544
/* 8023EC34  B3 43 00 00 */	sth r26, 0(r3)
/* 8023EC38  7C 7F 1B 78 */	mr r31, r3
/* 8023EC3C  B3 23 00 02 */	sth r25, 2(r3)
/* 8023EC40  9A C3 00 05 */	stb r22, 5(r3)
/* 8023EC44  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8023EC48  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023EC4C  7D 89 03 A6 */	mtctr r12
/* 8023EC50  4E 80 04 21 */	bctrl
/* 8023EC54  A0 7F 00 00 */	lhz r3, 0(r31)
/* 8023EC58  38 C0 00 00 */	li r6, 0
/* 8023EC5C  A0 9F 00 02 */	lhz r4, 2(r31)
/* 8023EC60  38 E0 00 01 */	li r7, 1
/* 8023EC64  88 BF 00 05 */	lbz r5, 5(r31)
/* 8023EC68  4B F3 19 AD */	bl -0xce654
/* 8023EC6C  7C 64 1B 78 */	mr r4, r3
/* 8023EC70  7F E3 FB 78 */	mr r3, r31
/* 8023EC74  48 00 45 29 */	bl 0x4528
/* 8023EC78  88 BF 00 14 */	lbz r5, 0x14(r31)
/* 8023EC7C  7F E3 FB 78 */	mr r3, r31
/* 8023EC80  88 02 9B 18 */	lbz r0, -0x64e8(r2)
/* 8023EC84  57 04 04 3E */	clrlwi r4, r24, 0x10
/* 8023EC88  60 A5 00 08 */	ori r5, r5, 8
/* 8023EC8C  98 BF 00 14 */	stb r5, 0x14(r31)
/* 8023EC90  89 02 9B 19 */	lbz r8, -0x64e7(r2)
/* 8023EC94  56 E5 04 3E */	clrlwi r5, r23, 0x10
/* 8023EC98  98 1F 00 20 */	stb r0, 0x20(r31)
/* 8023EC9C  38 C0 00 00 */	li r6, 0
/* 8023ECA0  88 02 9B 1A */	lbz r0, -0x64e6(r2)
/* 8023ECA4  38 E0 00 06 */	li r7, 6
/* 8023ECA8  99 1F 00 21 */	stb r8, 0x21(r31)
/* 8023ECAC  89 02 9B 1B */	lbz r8, -0x64e5(r2)
/* 8023ECB0  98 1F 00 22 */	stb r0, 0x22(r31)
/* 8023ECB4  88 02 9B 1C */	lbz r0, -0x64e4(r2)
/* 8023ECB8  99 1F 00 23 */	stb r8, 0x23(r31)
/* 8023ECBC  89 02 9B 1D */	lbz r8, -0x64e3(r2)
/* 8023ECC0  98 1F 00 24 */	stb r0, 0x24(r31)
/* 8023ECC4  88 02 9B 1E */	lbz r0, -0x64e2(r2)
/* 8023ECC8  99 1F 00 25 */	stb r8, 0x25(r31)
/* 8023ECCC  98 1F 00 26 */	stb r0, 0x26(r31)
/* 8023ECD0  4B FD 5F A5 */	bl -0x2a05c
/* 8023ECD4  C0 62 A0 C4 */	lfs f3, -0x5f3c(r2)
/* 8023ECD8  38 00 00 01 */	li r0, 1
/* 8023ECDC  C0 14 00 1C */	lfs f0, 0x1c(r20)
/* 8023ECE0  EC 3F 07 72 */	fmuls f1, f31, f29
/* 8023ECE4  80 74 00 34 */	lwz r3, 0x34(r20)
/* 8023ECE8  EC 5E 07 72 */	fmuls f2, f30, f29
/* 8023ECEC  EC 03 00 32 */	fmuls f0, f3, f0
/* 8023ECF0  FC 00 00 1E */	fctiwz f0, f0
/* 8023ECF4  D8 01 00 98 */	stfd f0, 0x98(r1)
/* 8023ECF8  80 81 00 9C */	lwz r4, 0x9c(r1)
/* 8023ECFC  98 83 00 31 */	stb r4, 0x31(r3)
/* 8023ED00  98 83 00 32 */	stb r4, 0x32(r3)
/* 8023ED04  98 83 00 33 */	stb r4, 0x33(r3)
/* 8023ED08  98 83 00 34 */	stb r4, 0x34(r3)
/* 8023ED0C  80 74 00 34 */	lwz r3, 0x34(r20)
/* 8023ED10  C0 14 00 20 */	lfs f0, 0x20(r20)
/* 8023ED14  D0 03 00 3C */	stfs f0, 0x3c(r3)
/* 8023ED18  80 74 00 34 */	lwz r3, 0x34(r20)
/* 8023ED1C  93 E3 00 04 */	stw r31, 4(r3)
/* 8023ED20  80 74 00 34 */	lwz r3, 0x34(r20)
/* 8023ED24  90 03 00 08 */	stw r0, 8(r3)
/* 8023ED28  80 74 00 34 */	lwz r3, 0x34(r20)
/* 8023ED2C  81 83 00 24 */	lwz r12, 0x24(r3)
/* 8023ED30  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023ED34  7D 89 03 A6 */	mtctr r12
/* 8023ED38  4E 80 04 21 */	bctrl
/* 8023ED3C  7F E3 FB 78 */	mr r3, r31
/* 8023ED40  48 00 42 51 */	bl 0x4250
/* 8023ED44  57 40 04 3E */	clrlwi r0, r26, 0x10
/* 8023ED48  90 01 00 64 */	stw r0, 0x64(r1)
/* 8023ED4C  C8 22 A0 C8 */	lfd f1, -0x5f38(r2)
/* 8023ED50  C8 01 00 60 */	lfd f0, 0x60(r1)
/* 8023ED54  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023ED58  EC 00 07 72 */	fmuls f0, f0, f29
/* 8023ED5C  FC 00 00 1E */	fctiwz f0, f0
/* 8023ED60  D8 01 00 98 */	stfd f0, 0x98(r1)
/* 8023ED64  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 8023ED68  54 00 04 3F */	clrlwi. r0, r0, 0x10
/* 8023ED6C  41 82 00 2C */	beq 0x2c
/* 8023ED70  57 20 04 3E */	clrlwi r0, r25, 0x10
/* 8023ED74  90 01 00 6C */	stw r0, 0x6c(r1)
/* 8023ED78  C8 01 00 68 */	lfd f0, 0x68(r1)
/* 8023ED7C  EC 00 08 28 */	fsubs f0, f0, f1
/* 8023ED80  EC 00 07 72 */	fmuls f0, f0, f29
/* 8023ED84  FC 00 00 1E */	fctiwz f0, f0
/* 8023ED88  D8 01 00 98 */	stfd f0, 0x98(r1)
/* 8023ED8C  80 01 00 9C */	lwz r0, 0x9c(r1)
/* 8023ED90  54 00 04 3F */	clrlwi. r0, r0, 0x10
/* 8023ED94  40 82 00 0C */	bne 0xc
/* 8023ED98  3B E0 00 00 */	li r31, 0
/* 8023ED9C  48 00 00 94 */	b 0x94
/* 8023EDA0  48 00 43 D5 */	bl 0x43d4
/* 8023EDA4  57 40 04 3E */	clrlwi r0, r26, 0x10
/* 8023EDA8  90 01 00 64 */	stw r0, 0x64(r1)
/* 8023EDAC  57 20 04 3E */	clrlwi r0, r25, 0x10
/* 8023EDB0  C8 42 A0 C8 */	lfd f2, -0x5f38(r2)
/* 8023EDB4  90 01 00 6C */	stw r0, 0x6c(r1)
/* 8023EDB8  38 00 00 01 */	li r0, 1
/* 8023EDBC  C8 21 00 60 */	lfd f1, 0x60(r1)
/* 8023EDC0  7C 7F 1B 78 */	mr r31, r3
/* 8023EDC4  C8 01 00 68 */	lfd f0, 0x68(r1)
/* 8023EDC8  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023EDCC  EC 00 10 28 */	fsubs f0, f0, f2
/* 8023EDD0  EC 21 07 72 */	fmuls f1, f1, f29
/* 8023EDD4  EC 00 07 72 */	fmuls f0, f0, f29
/* 8023EDD8  FC 20 08 1E */	fctiwz f1, f1
/* 8023EDDC  FC 00 00 1E */	fctiwz f0, f0
/* 8023EDE0  D8 21 00 98 */	stfd f1, 0x98(r1)
/* 8023EDE4  80 81 00 9C */	lwz r4, 0x9c(r1)
/* 8023EDE8  D8 01 00 90 */	stfd f0, 0x90(r1)
/* 8023EDEC  B0 83 00 00 */	sth r4, 0(r3)
/* 8023EDF0  80 81 00 94 */	lwz r4, 0x94(r1)
/* 8023EDF4  B0 83 00 02 */	sth r4, 2(r3)
/* 8023EDF8  98 03 00 05 */	stb r0, 5(r3)
/* 8023EDFC  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8023EE00  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023EE04  7D 89 03 A6 */	mtctr r12
/* 8023EE08  4E 80 04 21 */	bctrl
/* 8023EE0C  A0 7F 00 00 */	lhz r3, 0(r31)
/* 8023EE10  38 C0 00 00 */	li r6, 0
/* 8023EE14  A0 9F 00 02 */	lhz r4, 2(r31)
/* 8023EE18  38 E0 00 01 */	li r7, 1
/* 8023EE1C  88 BF 00 05 */	lbz r5, 5(r31)
/* 8023EE20  4B F3 17 F5 */	bl -0xce80c
/* 8023EE24  7C 64 1B 78 */	mr r4, r3
/* 8023EE28  7F E3 FB 78 */	mr r3, r31
/* 8023EE2C  48 00 43 71 */	bl 0x4370
/* 8023EE30  93 F4 00 38 */	stw r31, 0x38(r20)
/* 8023EE34  57 04 04 3E */	clrlwi r4, r24, 0x10
/* 8023EE38  88 02 9B 18 */	lbz r0, -0x64e8(r2)
/* 8023EE3C  56 E5 04 3E */	clrlwi r5, r23, 0x10
/* 8023EE40  88 7F 00 14 */	lbz r3, 0x14(r31)
/* 8023EE44  38 C0 00 00 */	li r6, 0
/* 8023EE48  89 02 9B 19 */	lbz r8, -0x64e7(r2)
/* 8023EE4C  38 E0 00 28 */	li r7, 0x28
/* 8023EE50  60 63 00 08 */	ori r3, r3, 8
/* 8023EE54  98 7F 00 14 */	stb r3, 0x14(r31)
/* 8023EE58  88 62 9B 1A */	lbz r3, -0x64e6(r2)
/* 8023EE5C  98 1F 00 20 */	stb r0, 0x20(r31)
/* 8023EE60  88 02 9B 1B */	lbz r0, -0x64e5(r2)
/* 8023EE64  99 1F 00 21 */	stb r8, 0x21(r31)
/* 8023EE68  89 02 9B 1C */	lbz r8, -0x64e4(r2)
/* 8023EE6C  98 7F 00 22 */	stb r3, 0x22(r31)
/* 8023EE70  88 62 9B 1D */	lbz r3, -0x64e3(r2)
/* 8023EE74  98 1F 00 23 */	stb r0, 0x23(r31)
/* 8023EE78  88 02 9B 1E */	lbz r0, -0x64e2(r2)
/* 8023EE7C  99 1F 00 24 */	stb r8, 0x24(r31)
/* 8023EE80  98 7F 00 25 */	stb r3, 0x25(r31)
/* 8023EE84  98 1F 00 26 */	stb r0, 0x26(r31)
/* 8023EE88  80 74 00 38 */	lwz r3, 0x38(r20)
/* 8023EE8C  4B FD 5D E9 */	bl -0x2a218
/* 8023EE90  7F C3 F3 78 */	mr r3, r30
/* 8023EE94  48 00 40 FD */	bl 0x40fc
/* 8023EE98  88 14 00 08 */	lbz r0, 8(r20)
/* 8023EE9C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023EEA0  41 82 00 8C */	beq 0x8c
/* 8023EEA4  FC 20 F8 90 */	fmr f1, f31
/* 8023EEA8  C0 62 A0 B0 */	lfs f3, -0x5f50(r2)
/* 8023EEAC  FC 40 F0 90 */	fmr f2, f30
/* 8023EEB0  38 61 00 30 */	addi r3, r1, 0x30
/* 8023EEB4  4B F5 B5 AD */	bl -0xa4a54
/* 8023EEB8  81 95 00 10 */	lwz r12, 0x10(r21)
/* 8023EEBC  7E A3 AB 78 */	mr r3, r21
/* 8023EEC0  38 81 00 10 */	addi r4, r1, 0x10
/* 8023EEC4  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023EEC8  7D 89 03 A6 */	mtctr r12
/* 8023EECC  4E 80 04 21 */	bctrl
/* 8023EED0  38 61 00 10 */	addi r3, r1, 0x10
/* 8023EED4  38 80 00 00 */	li r4, 0
/* 8023EED8  4B F3 20 55 */	bl -0xcdfac
/* 8023EEDC  38 60 00 01 */	li r3, 1
/* 8023EEE0  38 80 00 01 */	li r4, 1
/* 8023EEE4  38 A0 00 00 */	li r5, 0
/* 8023EEE8  4B FD B7 19 */	bl -0x248e8
/* 8023EEEC  38 60 00 0C */	li r3, 0xc
/* 8023EEF0  4B FD D2 29 */	bl -0x22dd8
/* 8023EEF4  89 02 9B A4 */	lbz r8, -0x645c(r2)
/* 8023EEF8  38 81 00 30 */	addi r4, r1, 0x30
/* 8023EEFC  88 E2 9B A5 */	lbz r7, -0x645b(r2)
/* 8023EF00  38 A1 00 08 */	addi r5, r1, 8
/* 8023EF04  88 C2 9B A6 */	lbz r6, -0x645a(r2)
/* 8023EF08  38 60 00 10 */	li r3, 0x10
/* 8023EF0C  88 02 9B A7 */	lbz r0, -0x6459(r2)
/* 8023EF10  99 01 00 08 */	stb r8, 8(r1)
/* 8023EF14  98 E1 00 09 */	stb r7, 9(r1)
/* 8023EF18  98 C1 00 0A */	stb r6, 0xa(r1)
/* 8023EF1C  98 01 00 0B */	stb r0, 0xb(r1)
/* 8023EF20  4B FD D1 39 */	bl -0x22ec8
/* 8023EF24  7E A3 AB 78 */	mr r3, r21
/* 8023EF28  48 00 40 69 */	bl 0x4068
/* 8023EF2C  7F 63 DB 78 */	mr r3, r27
/* 8023EF30  4B F3 3A 01 */	bl -0xcc600
/* 8023EF34  3E 80 80 38 */	lis r20, 0x8038
/* 8023EF38  7F 83 E3 78 */	mr r3, r28
/* 8023EF3C  3A 94 45 20 */	addi r20, r20, 0x4520
/* 8023EF40  9B 74 00 0E */	stb r27, 0xe(r20)
/* 8023EF44  4B F3 38 B5 */	bl -0xcc74c
/* 8023EF48  9B 94 00 0D */	stb r28, 0xd(r20)
/* 8023EF4C  7F A3 EB 78 */	mr r3, r29
/* 8023EF50  4B F3 38 7D */	bl -0xcc784
/* 8023EF54  9B B4 00 0C */	stb r29, 0xc(r20)
/* 8023EF58  E3 E1 01 08 */	psq_l f31, 264(r1), 0, qr0
/* 8023EF5C  CB E1 01 00 */	lfd f31, 0x100(r1)
/* 8023EF60  E3 C1 00 F8 */	psq_l f30, 248(r1), 0, qr0
/* 8023EF64  CB C1 00 F0 */	lfd f30, 0xf0(r1)
/* 8023EF68  E3 A1 00 E8 */	psq_l f29, 232(r1), 0, qr0
/* 8023EF6C  CB A1 00 E0 */	lfd f29, 0xe0(r1)
/* 8023EF70  E3 81 00 D8 */	psq_l f28, 216(r1), 0, qr0
/* 8023EF74  39 61 00 D0 */	addi r11, r1, 0xd0
/* 8023EF78  CB 81 00 D0 */	lfd f28, 0xd0(r1)
/* 8023EF7C  4B DE 26 55 */	bl -0x21d9ac
/* 8023EF80  80 01 01 14 */	lwz r0, 0x114(r1)
/* 8023EF84  7C 08 03 A6 */	mtlr r0
/* 8023EF88  38 21 01 10 */	addi r1, r1, 0x110
/* 8023EF8C  4E 80 00 20 */	blr
/* 8023EF90  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 8023EF94  7C 08 02 A6 */	mflr r0
/* 8023EF98  90 01 00 94 */	stw r0, 0x94(r1)
/* 8023EF9C  93 E1 00 8C */	stw r31, 0x8c(r1)
/* 8023EFA0  7C 7F 1B 78 */	mr r31, r3
/* 8023EFA4  93 C1 00 88 */	stw r30, 0x88(r1)
/* 8023EFA8  88 03 00 00 */	lbz r0, 0(r3)
/* 8023EFAC  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023EFB0  41 82 01 7C */	beq 0x17c
/* 8023EFB4  4B F3 21 5D */	bl -0xcdea4
/* 8023EFB8  3F C0 80 38 */	lis r30, 0x8038
/* 8023EFBC  38 7E 44 18 */	addi r3, r30, 0x4418
/* 8023EFC0  4B FF 61 3D */	bl -0x9ec4
/* 8023EFC4  38 BE 44 18 */	addi r5, r30, 0x4418
/* 8023EFC8  3C 80 43 30 */	lis r4, 0x4330
/* 8023EFCC  C0 25 00 0C */	lfs f1, 0xc(r5)
/* 8023EFD0  38 61 00 30 */	addi r3, r1, 0x30
/* 8023EFD4  C0 05 00 08 */	lfs f0, 8(r5)
/* 8023EFD8  FC 20 08 1E */	fctiwz f1, f1
/* 8023EFDC  90 81 00 70 */	stw r4, 0x70(r1)
/* 8023EFE0  FC 00 00 1E */	fctiwz f0, f0
/* 8023EFE4  C8 42 A0 C8 */	lfd f2, -0x5f38(r2)
/* 8023EFE8  D8 21 00 60 */	stfd f1, 0x60(r1)
/* 8023EFEC  C0 62 A0 B0 */	lfs f3, -0x5f50(r2)
/* 8023EFF0  D8 01 00 68 */	stfd f0, 0x68(r1)
/* 8023EFF4  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8023EFF8  80 A1 00 6C */	lwz r5, 0x6c(r1)
/* 8023EFFC  54 00 04 3E */	clrlwi r0, r0, 0x10
/* 8023F000  90 01 00 7C */	stw r0, 0x7c(r1)
/* 8023F004  54 A0 04 3E */	clrlwi r0, r5, 0x10
/* 8023F008  90 01 00 74 */	stw r0, 0x74(r1)
/* 8023F00C  90 81 00 78 */	stw r4, 0x78(r1)
/* 8023F010  C8 21 00 70 */	lfd f1, 0x70(r1)
/* 8023F014  C8 01 00 78 */	lfd f0, 0x78(r1)
/* 8023F018  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023F01C  EC 40 10 28 */	fsubs f2, f0, f2
/* 8023F020  4B F5 B4 41 */	bl -0xa4bc0
/* 8023F024  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8023F028  38 81 00 10 */	addi r4, r1, 0x10
/* 8023F02C  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8023F030  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 8023F034  7D 89 03 A6 */	mtctr r12
/* 8023F038  4E 80 04 21 */	bctrl
/* 8023F03C  38 61 00 10 */	addi r3, r1, 0x10
/* 8023F040  38 80 00 00 */	li r4, 0
/* 8023F044  4B F3 1E E9 */	bl -0xce118
/* 8023F048  38 60 00 01 */	li r3, 1
/* 8023F04C  38 80 00 01 */	li r4, 1
/* 8023F050  38 A0 00 01 */	li r5, 1
/* 8023F054  4B FD B5 AD */	bl -0x24a54
/* 8023F058  88 1F 00 2C */	lbz r0, 0x2c(r31)
/* 8023F05C  38 81 00 0C */	addi r4, r1, 0xc
/* 8023F060  98 01 00 0C */	stb r0, 0xc(r1)
/* 8023F064  38 60 00 00 */	li r3, 0
/* 8023F068  88 1F 00 2D */	lbz r0, 0x2d(r31)
/* 8023F06C  98 01 00 0D */	stb r0, 0xd(r1)
/* 8023F070  88 1F 00 2E */	lbz r0, 0x2e(r31)
/* 8023F074  98 01 00 0E */	stb r0, 0xe(r1)
/* 8023F078  88 1F 00 2F */	lbz r0, 0x2f(r31)
/* 8023F07C  98 01 00 0F */	stb r0, 0xf(r1)
/* 8023F080  4B F3 2E 55 */	bl -0xcd1ac
/* 8023F084  38 60 00 00 */	li r3, 0
/* 8023F088  38 80 00 0C */	li r4, 0xc
/* 8023F08C  4B F3 2E A5 */	bl -0xcd15c
/* 8023F090  38 60 00 00 */	li r3, 0
/* 8023F094  38 80 00 1C */	li r4, 0x1c
/* 8023F098  4B F3 2E E9 */	bl -0xcd118
/* 8023F09C  38 60 00 00 */	li r3, 0
/* 8023F0A0  38 80 00 0F */	li r4, 0xf
/* 8023F0A4  38 A0 00 0F */	li r5, 0xf
/* 8023F0A8  38 C0 00 0F */	li r6, 0xf
/* 8023F0AC  38 E0 00 0E */	li r7, 0xe
/* 8023F0B0  4B F3 2C 31 */	bl -0xcd3d0
/* 8023F0B4  38 60 00 00 */	li r3, 0
/* 8023F0B8  38 80 00 07 */	li r4, 7
/* 8023F0BC  38 A0 00 06 */	li r5, 6
/* 8023F0C0  38 C0 00 04 */	li r6, 4
/* 8023F0C4  38 E0 00 07 */	li r7, 7
/* 8023F0C8  4B F3 2C 59 */	bl -0xcd3a8
/* 8023F0CC  88 FF 00 09 */	lbz r7, 9(r31)
/* 8023F0D0  38 60 00 07 */	li r3, 7
/* 8023F0D4  38 80 00 00 */	li r4, 0
/* 8023F0D8  38 A0 00 00 */	li r5, 0
/* 8023F0DC  38 C0 00 04 */	li r6, 4
/* 8023F0E0  4B F3 2F A9 */	bl -0xcd058
/* 8023F0E4  88 1F 00 08 */	lbz r0, 8(r31)
/* 8023F0E8  38 60 00 00 */	li r3, 0
/* 8023F0EC  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023F0F0  41 82 00 08 */	beq 0x8
/* 8023F0F4  38 60 00 0C */	li r3, 0xc
/* 8023F0F8  4B FD D0 21 */	bl -0x22fe0
/* 8023F0FC  89 02 9B A4 */	lbz r8, -0x645c(r2)
/* 8023F100  38 81 00 30 */	addi r4, r1, 0x30
/* 8023F104  88 E2 9B A5 */	lbz r7, -0x645b(r2)
/* 8023F108  38 A1 00 08 */	addi r5, r1, 8
/* 8023F10C  88 C2 9B A6 */	lbz r6, -0x645a(r2)
/* 8023F110  38 60 00 10 */	li r3, 0x10
/* 8023F114  88 02 9B A7 */	lbz r0, -0x6459(r2)
/* 8023F118  99 01 00 08 */	stb r8, 8(r1)
/* 8023F11C  98 E1 00 09 */	stb r7, 9(r1)
/* 8023F120  98 C1 00 0A */	stb r6, 0xa(r1)
/* 8023F124  98 01 00 0B */	stb r0, 0xb(r1)
/* 8023F128  4B FD CF 31 */	bl -0x230d0
/* 8023F12C  80 7F 00 38 */	lwz r3, 0x38(r31)
/* 8023F130  2C 03 00 00 */	cmpwi r3, 0
/* 8023F134  41 82 00 10 */	beq 0x10
/* 8023F138  48 00 3E 59 */	bl 0x3e58
/* 8023F13C  38 00 00 00 */	li r0, 0
/* 8023F140  90 1F 00 38 */	stw r0, 0x38(r31)
/* 8023F144  80 01 00 94 */	lwz r0, 0x94(r1)
/* 8023F148  83 E1 00 8C */	lwz r31, 0x8c(r1)
/* 8023F14C  83 C1 00 88 */	lwz r30, 0x88(r1)
/* 8023F150  7C 08 03 A6 */	mtlr r0
/* 8023F154  38 21 00 90 */	addi r1, r1, 0x90
/* 8023F158  4E 80 00 20 */	blr
/* 8023F15C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8023F160  7C 08 02 A6 */	mflr r0
/* 8023F164  90 01 00 14 */	stw r0, 0x14(r1)
/* 8023F168  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8023F16C  7C 7F 1B 78 */	mr r31, r3
/* 8023F170  A0 03 00 68 */	lhz r0, 0x68(r3)
/* 8023F174  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 8023F178  41 82 00 A4 */	beq 0xa4
/* 8023F17C  80 03 01 14 */	lwz r0, 0x114(r3)
/* 8023F180  2C 00 00 00 */	cmpwi r0, 0
/* 8023F184  40 82 00 90 */	bne 0x90
/* 8023F188  80 83 01 0C */	lwz r4, 0x10c(r3)
/* 8023F18C  C0 03 01 18 */	lfs f0, 0x118(r3)
/* 8023F190  D0 04 00 3C */	stfs f0, 0x3c(r4)
/* 8023F194  88 03 01 1C */	lbz r0, 0x11c(r3)
/* 8023F198  98 04 00 31 */	stb r0, 0x31(r4)
/* 8023F19C  98 04 00 32 */	stb r0, 0x32(r4)
/* 8023F1A0  98 04 00 33 */	stb r0, 0x33(r4)
/* 8023F1A4  98 04 00 34 */	stb r0, 0x34(r4)
/* 8023F1A8  80 83 01 0C */	lwz r4, 0x10c(r3)
/* 8023F1AC  C0 03 01 20 */	lfs f0, 0x120(r3)
/* 8023F1B0  D0 04 00 4C */	stfs f0, 0x4c(r4)
/* 8023F1B4  88 03 01 24 */	lbz r0, 0x124(r3)
/* 8023F1B8  98 04 00 41 */	stb r0, 0x41(r4)
/* 8023F1BC  98 04 00 42 */	stb r0, 0x42(r4)
/* 8023F1C0  98 04 00 43 */	stb r0, 0x43(r4)
/* 8023F1C4  98 04 00 44 */	stb r0, 0x44(r4)
/* 8023F1C8  C0 23 00 6C */	lfs f1, 0x6c(r3)
/* 8023F1CC  4B FF 20 21 */	bl -0xdfe0
/* 8023F1D0  7F E3 FB 78 */	mr r3, r31
/* 8023F1D4  48 00 00 5D */	bl 0x5c
/* 8023F1D8  38 82 A1 D8 */	addi r4, r2, -24104
/* 8023F1DC  88 7F 00 14 */	lbz r3, 0x14(r31)
/* 8023F1E0  A0 1F 00 68 */	lhz r0, 0x68(r31)
/* 8023F1E4  88 E2 A1 D8 */	lbz r7, -0x5e28(r2)
/* 8023F1E8  60 63 00 07 */	ori r3, r3, 7
/* 8023F1EC  88 C4 00 01 */	lbz r6, 1(r4)
/* 8023F1F0  54 00 07 76 */	rlwinm r0, r0, 0, 0x1d, 0x1b
/* 8023F1F4  88 A4 00 02 */	lbz r5, 2(r4)
/* 8023F1F8  88 84 00 03 */	lbz r4, 3(r4)
/* 8023F1FC  98 FF 00 15 */	stb r7, 0x15(r31)
/* 8023F200  98 DF 00 16 */	stb r6, 0x16(r31)
/* 8023F204  98 BF 00 17 */	stb r5, 0x17(r31)
/* 8023F208  98 9F 00 18 */	stb r4, 0x18(r31)
/* 8023F20C  98 7F 00 14 */	stb r3, 0x14(r31)
/* 8023F210  B0 1F 00 68 */	sth r0, 0x68(r31)
/* 8023F214  7F E3 FB 78 */	mr r3, r31
/* 8023F218  48 00 02 8D */	bl 0x28c
/* 8023F21C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8023F220  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8023F224  7C 08 03 A6 */	mtlr r0
/* 8023F228  38 21 00 10 */	addi r1, r1, 0x10
/* 8023F22C  4E 80 00 20 */	blr
/* 8023F230  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8023F234  7C 08 02 A6 */	mflr r0
/* 8023F238  90 01 00 64 */	stw r0, 0x64(r1)
/* 8023F23C  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 8023F240  F3 E1 00 58 */	psq_st f31, 88(r1), 0, qr0
/* 8023F244  C0 02 A0 D4 */	lfs f0, -0x5f2c(r2)
/* 8023F248  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 8023F24C  3B E3 00 7C */	addi r31, r3, 0x7c
/* 8023F250  93 C1 00 48 */	stw r30, 0x48(r1)
/* 8023F254  7C 7E 1B 78 */	mr r30, r3
/* 8023F258  C0 23 00 64 */	lfs f1, 0x64(r3)
/* 8023F25C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8023F260  40 81 02 1C */	ble 0x21c
/* 8023F264  A0 03 00 68 */	lhz r0, 0x68(r3)
/* 8023F268  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023F26C  40 82 00 0C */	bne 0xc
/* 8023F270  C3 E2 A0 D0 */	lfs f31, -0x5f30(r2)
/* 8023F274  48 00 00 08 */	b 0x8
/* 8023F278  C3 E2 A0 E0 */	lfs f31, -0x5f20(r2)
/* 8023F27C  38 63 00 70 */	addi r3, r3, 0x70
/* 8023F280  4B F5 B9 E9 */	bl -0xa4618
/* 8023F284  C1 42 A0 D8 */	lfs f10, -0x5f28(r2)
/* 8023F288  C0 BE 00 78 */	lfs f5, 0x78(r30)
/* 8023F28C  EC CA 08 24 */	fdivs f6, f10, f1
/* 8023F290  C0 3E 00 74 */	lfs f1, 0x74(r30)
/* 8023F294  C0 9E 00 70 */	lfs f4, 0x70(r30)
/* 8023F298  C0 02 A0 E4 */	lfs f0, -0x5f1c(r2)
/* 8023F29C  C0 62 A0 E0 */	lfs f3, -0x5f20(r2)
/* 8023F2A0  C0 42 A0 D4 */	lfs f2, -0x5f2c(r2)
/* 8023F2A4  ED 21 01 B2 */	fmuls f9, f1, f6
/* 8023F2A8  C0 22 A0 D0 */	lfs f1, -0x5f30(r2)
/* 8023F2AC  ED 04 01 B2 */	fmuls f8, f4, f6
/* 8023F2B0  EC A5 01 B2 */	fmuls f5, f5, f6
/* 8023F2B4  D1 21 00 30 */	stfs f9, 0x30(r1)
/* 8023F2B8  FC 80 4A 10 */	fabs f4, f9
/* 8023F2BC  D1 01 00 2C */	stfs f8, 0x2c(r1)
/* 8023F2C0  D0 A1 00 34 */	stfs f5, 0x34(r1)
/* 8023F2C4  FC 04 00 40 */	fcmpo cr0, f4, f0
/* 8023F2C8  C0 1E 00 64 */	lfs f0, 0x64(r30)
/* 8023F2CC  C0 DE 00 60 */	lfs f6, 0x60(r30)
/* 8023F2D0  EC 63 00 32 */	fmuls f3, f3, f0
/* 8023F2D4  C0 9E 00 5C */	lfs f4, 0x5c(r30)
/* 8023F2D8  C0 1E 00 58 */	lfs f0, 0x58(r30)
/* 8023F2DC  EC E5 00 F2 */	fmuls f7, f5, f3
/* 8023F2E0  D0 41 00 14 */	stfs f2, 0x14(r1)
/* 8023F2E4  EC A9 00 F2 */	fmuls f5, f9, f3
/* 8023F2E8  EC 68 00 F2 */	fmuls f3, f8, f3
/* 8023F2EC  D0 21 00 18 */	stfs f1, 0x18(r1)
/* 8023F2F0  EC C6 38 2A */	fadds f6, f6, f7
/* 8023F2F4  EC 84 28 2A */	fadds f4, f4, f5
/* 8023F2F8  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 8023F2FC  EC 00 18 2A */	fadds f0, f0, f3
/* 8023F300  D0 81 00 24 */	stfs f4, 0x24(r1)
/* 8023F304  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 8023F308  D0 C1 00 28 */	stfs f6, 0x28(r1)
/* 8023F30C  40 81 00 1C */	ble 0x1c
/* 8023F310  FC 09 10 40 */	fcmpo cr0, f9, f2
/* 8023F314  D0 41 00 18 */	stfs f2, 0x18(r1)
/* 8023F318  40 81 00 08 */	ble 0x8
/* 8023F31C  48 00 00 08 */	b 0x8
/* 8023F320  FD 40 08 90 */	fmr f10, f1
/* 8023F324  D1 41 00 1C */	stfs f10, 0x1c(r1)
/* 8023F328  38 61 00 14 */	addi r3, r1, 0x14
/* 8023F32C  38 81 00 2C */	addi r4, r1, 0x2c
/* 8023F330  38 A1 00 08 */	addi r5, r1, 8
/* 8023F334  4B F5 B9 99 */	bl -0xa4668
/* 8023F338  38 61 00 08 */	addi r3, r1, 8
/* 8023F33C  7C 64 1B 78 */	mr r4, r3
/* 8023F340  4B F5 B8 E5 */	bl -0xa471c
/* 8023F344  38 61 00 2C */	addi r3, r1, 0x2c
/* 8023F348  38 81 00 08 */	addi r4, r1, 8
/* 8023F34C  38 A1 00 14 */	addi r5, r1, 0x14
/* 8023F350  4B F5 B9 7D */	bl -0xa4684
/* 8023F354  A0 7E 00 00 */	lhz r3, 0(r30)
/* 8023F358  3C 00 43 30 */	lis r0, 0x4330
/* 8023F35C  90 61 00 3C */	stw r3, 0x3c(r1)
/* 8023F360  C8 62 A0 E8 */	lfd f3, -0x5f18(r2)
/* 8023F364  90 01 00 38 */	stw r0, 0x38(r1)
/* 8023F368  C0 22 A0 E0 */	lfs f1, -0x5f20(r2)
/* 8023F36C  C8 41 00 38 */	lfd f2, 0x38(r1)
/* 8023F370  C0 1E 00 64 */	lfs f0, 0x64(r30)
/* 8023F374  EC 42 18 28 */	fsubs f2, f2, f3
/* 8023F378  C0 62 A0 D0 */	lfs f3, -0x5f30(r2)
/* 8023F37C  EC 01 00 32 */	fmuls f0, f1, f0
/* 8023F380  C0 81 00 08 */	lfs f4, 8(r1)
/* 8023F384  C0 21 00 20 */	lfs f1, 0x20(r1)
/* 8023F388  EC BF 00 B2 */	fmuls f5, f31, f2
/* 8023F38C  EC 60 00 F2 */	fmuls f3, f0, f3
/* 8023F390  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 8023F394  C0 41 00 28 */	lfs f2, 0x28(r1)
/* 8023F398  EC 65 18 24 */	fdivs f3, f5, f3
/* 8023F39C  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8023F3A0  D0 9F 00 00 */	stfs f4, 0(r31)
/* 8023F3A4  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8023F3A8  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8023F3AC  D0 9F 00 04 */	stfs f4, 4(r31)
/* 8023F3B0  C0 81 00 10 */	lfs f4, 0x10(r1)
/* 8023F3B4  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8023F3B8  D0 9F 00 08 */	stfs f4, 8(r31)
/* 8023F3BC  C0 A1 00 08 */	lfs f5, 8(r1)
/* 8023F3C0  C0 81 00 0C */	lfs f4, 0xc(r1)
/* 8023F3C4  C0 C1 00 10 */	lfs f6, 0x10(r1)
/* 8023F3C8  EC A1 01 72 */	fmuls f5, f1, f5
/* 8023F3CC  EC 80 01 32 */	fmuls f4, f0, f4
/* 8023F3D0  EC C2 01 B2 */	fmuls f6, f2, f6
/* 8023F3D4  EC 85 20 2A */	fadds f4, f5, f4
/* 8023F3D8  EC 86 20 2A */	fadds f4, f6, f4
/* 8023F3DC  FC 80 20 50 */	fneg f4, f4
/* 8023F3E0  EC 83 01 32 */	fmuls f4, f3, f4
/* 8023F3E4  D0 9F 00 0C */	stfs f4, 0xc(r31)
/* 8023F3E8  C0 81 00 14 */	lfs f4, 0x14(r1)
/* 8023F3EC  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8023F3F0  D0 9F 00 10 */	stfs f4, 0x10(r31)
/* 8023F3F4  C0 81 00 18 */	lfs f4, 0x18(r1)
/* 8023F3F8  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8023F3FC  D0 9F 00 14 */	stfs f4, 0x14(r31)
/* 8023F400  C0 81 00 1C */	lfs f4, 0x1c(r1)
/* 8023F404  EC 84 00 F2 */	fmuls f4, f4, f3
/* 8023F408  D0 9F 00 18 */	stfs f4, 0x18(r31)
/* 8023F40C  C0 A1 00 14 */	lfs f5, 0x14(r1)
/* 8023F410  C0 81 00 18 */	lfs f4, 0x18(r1)
/* 8023F414  C0 C1 00 1C */	lfs f6, 0x1c(r1)
/* 8023F418  EC A1 01 72 */	fmuls f5, f1, f5
/* 8023F41C  EC 80 01 32 */	fmuls f4, f0, f4
/* 8023F420  EC C2 01 B2 */	fmuls f6, f2, f6
/* 8023F424  EC 85 20 2A */	fadds f4, f5, f4
/* 8023F428  EC 86 20 2A */	fadds f4, f6, f4
/* 8023F42C  FC 80 20 50 */	fneg f4, f4
/* 8023F430  EC 63 01 32 */	fmuls f3, f3, f4
/* 8023F434  D0 7F 00 1C */	stfs f3, 0x1c(r31)
/* 8023F438  C0 61 00 2C */	lfs f3, 0x2c(r1)
/* 8023F43C  D0 7F 00 20 */	stfs f3, 0x20(r31)
/* 8023F440  C0 61 00 30 */	lfs f3, 0x30(r1)
/* 8023F444  D0 7F 00 24 */	stfs f3, 0x24(r31)
/* 8023F448  C0 61 00 34 */	lfs f3, 0x34(r1)
/* 8023F44C  D0 7F 00 28 */	stfs f3, 0x28(r31)
/* 8023F450  C0 81 00 2C */	lfs f4, 0x2c(r1)
/* 8023F454  C0 61 00 30 */	lfs f3, 0x30(r1)
/* 8023F458  C0 A1 00 34 */	lfs f5, 0x34(r1)
/* 8023F45C  EC 21 01 32 */	fmuls f1, f1, f4
/* 8023F460  EC 00 00 F2 */	fmuls f0, f0, f3
/* 8023F464  EC 42 01 72 */	fmuls f2, f2, f5
/* 8023F468  EC 01 00 2A */	fadds f0, f1, f0
/* 8023F46C  EC 02 00 2A */	fadds f0, f2, f0
/* 8023F470  FC 00 00 50 */	fneg f0, f0
/* 8023F474  D0 1F 00 2C */	stfs f0, 0x2c(r31)
/* 8023F478  48 00 00 0C */	b 0xc
/* 8023F47C  7F E3 FB 78 */	mr r3, r31
/* 8023F480  4B F5 A8 85 */	bl -0xa577c
/* 8023F484  E3 E1 00 58 */	psq_l f31, 88(r1), 0, qr0
/* 8023F488  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8023F48C  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 8023F490  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 8023F494  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 8023F498  7C 08 03 A6 */	mtlr r0
/* 8023F49C  38 21 00 60 */	addi r1, r1, 0x60
/* 8023F4A0  4E 80 00 20 */	blr
/* 8023F4A4  94 21 FF 40 */	stwu r1, -0xc0(r1)
/* 8023F4A8  7C 08 02 A6 */	mflr r0
/* 8023F4AC  3C 80 43 30 */	lis r4, 0x4330
/* 8023F4B0  90 01 00 C4 */	stw r0, 0xc4(r1)
/* 8023F4B4  93 E1 00 BC */	stw r31, 0xbc(r1)
/* 8023F4B8  93 C1 00 B8 */	stw r30, 0xb8(r1)
/* 8023F4BC  93 A1 00 B4 */	stw r29, 0xb4(r1)
/* 8023F4C0  93 81 00 B0 */	stw r28, 0xb0(r1)
/* 8023F4C4  7C 7C 1B 78 */	mr r28, r3
/* 8023F4C8  80 03 01 14 */	lwz r0, 0x114(r3)
/* 8023F4CC  90 81 00 98 */	stw r4, 0x98(r1)
/* 8023F4D0  2C 00 00 00 */	cmpwi r0, 0
/* 8023F4D4  90 81 00 A0 */	stw r4, 0xa0(r1)
/* 8023F4D8  41 82 00 EC */	beq 0xec
/* 8023F4DC  80 A3 01 14 */	lwz r5, 0x114(r3)
/* 8023F4E0  A0 05 00 68 */	lhz r0, 0x68(r5)
/* 8023F4E4  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023F4E8  40 82 00 0C */	bne 0xc
/* 8023F4EC  C0 62 A0 DC */	lfs f3, -0x5f24(r2)
/* 8023F4F0  48 00 00 08 */	b 0x8
/* 8023F4F4  C0 62 A0 D0 */	lfs f3, -0x5f30(r2)
/* 8023F4F8  A0 85 00 00 */	lhz r4, 0(r5)
/* 8023F4FC  38 61 00 68 */	addi r3, r1, 0x68
/* 8023F500  A0 05 00 02 */	lhz r0, 2(r5)
/* 8023F504  90 81 00 9C */	stw r4, 0x9c(r1)
/* 8023F508  C8 42 A0 E8 */	lfd f2, -0x5f18(r2)
/* 8023F50C  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 8023F510  C8 21 00 98 */	lfd f1, 0x98(r1)
/* 8023F514  C8 01 00 A0 */	lfd f0, 0xa0(r1)
/* 8023F518  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023F51C  C0 A2 A0 DC */	lfs f5, -0x5f24(r2)
/* 8023F520  EC 00 10 28 */	fsubs f0, f0, f2
/* 8023F524  C0 C2 A0 F0 */	lfs f6, -0x5f10(r2)
/* 8023F528  FC E0 28 90 */	fmr f7, f5
/* 8023F52C  EC 83 00 72 */	fmuls f4, f3, f1
/* 8023F530  EC 23 00 32 */	fmuls f1, f3, f0
/* 8023F534  FD 00 28 90 */	fmr f8, f5
/* 8023F538  FC 60 20 50 */	fneg f3, f4
/* 8023F53C  FC 40 08 50 */	fneg f2, f1
/* 8023F540  4B F5 B3 55 */	bl -0xa4cac
/* 8023F544  38 7C 00 DC */	addi r3, r28, 0xdc
/* 8023F548  38 81 00 38 */	addi r4, r1, 0x38
/* 8023F54C  4B F5 AA 7D */	bl -0xa5584
/* 8023F550  80 7C 01 14 */	lwz r3, 0x114(r28)
/* 8023F554  38 81 00 08 */	addi r4, r1, 8
/* 8023F558  38 63 00 7C */	addi r3, r3, 0x7c
/* 8023F55C  4B F5 AA 6D */	bl -0xa5594
/* 8023F560  38 81 00 08 */	addi r4, r1, 8
/* 8023F564  38 61 00 38 */	addi r3, r1, 0x38
/* 8023F568  7C 85 23 78 */	mr r5, r4
/* 8023F56C  4B F5 A7 F9 */	bl -0xa5808
/* 8023F570  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 8023F574  38 81 00 08 */	addi r4, r1, 8
/* 8023F578  C0 82 A0 D8 */	lfs f4, -0x5f28(r2)
/* 8023F57C  7C 85 23 78 */	mr r5, r4
/* 8023F580  C0 41 00 2C */	lfs f2, 0x2c(r1)
/* 8023F584  38 7C 00 DC */	addi r3, r28, 0xdc
/* 8023F588  EC 60 01 32 */	fmuls f3, f0, f4
/* 8023F58C  C0 21 00 30 */	lfs f1, 0x30(r1)
/* 8023F590  C0 01 00 34 */	lfs f0, 0x34(r1)
/* 8023F594  EC 42 01 32 */	fmuls f2, f2, f4
/* 8023F598  EC 21 01 32 */	fmuls f1, f1, f4
/* 8023F59C  D0 61 00 28 */	stfs f3, 0x28(r1)
/* 8023F5A0  EC 00 01 32 */	fmuls f0, f0, f4
/* 8023F5A4  D0 41 00 2C */	stfs f2, 0x2c(r1)
/* 8023F5A8  D0 21 00 30 */	stfs f1, 0x30(r1)
/* 8023F5AC  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8023F5B0  4B F5 A7 B5 */	bl -0xa584c
/* 8023F5B4  38 61 00 08 */	addi r3, r1, 8
/* 8023F5B8  38 9C 00 7C */	addi r4, r28, 0x7c
/* 8023F5BC  4B F5 AA 0D */	bl -0xa55f4
/* 8023F5C0  48 00 00 68 */	b 0x68
/* 8023F5C4  A0 03 00 68 */	lhz r0, 0x68(r3)
/* 8023F5C8  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 8023F5CC  40 82 00 0C */	bne 0xc
/* 8023F5D0  C0 62 A0 DC */	lfs f3, -0x5f24(r2)
/* 8023F5D4  48 00 00 08 */	b 0x8
/* 8023F5D8  C0 62 A0 D0 */	lfs f3, -0x5f30(r2)
/* 8023F5DC  A0 83 00 00 */	lhz r4, 0(r3)
/* 8023F5E0  A0 03 00 02 */	lhz r0, 2(r3)
/* 8023F5E4  38 61 00 68 */	addi r3, r1, 0x68
/* 8023F5E8  90 81 00 9C */	stw r4, 0x9c(r1)
/* 8023F5EC  C8 42 A0 E8 */	lfd f2, -0x5f18(r2)
/* 8023F5F0  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 8023F5F4  C8 21 00 98 */	lfd f1, 0x98(r1)
/* 8023F5F8  C8 01 00 A0 */	lfd f0, 0xa0(r1)
/* 8023F5FC  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023F600  C0 A2 A0 DC */	lfs f5, -0x5f24(r2)
/* 8023F604  EC 00 10 28 */	fsubs f0, f0, f2
/* 8023F608  C0 C2 A0 F0 */	lfs f6, -0x5f10(r2)
/* 8023F60C  FC E0 28 90 */	fmr f7, f5
/* 8023F610  EC 83 00 72 */	fmuls f4, f3, f1
/* 8023F614  EC 23 00 32 */	fmuls f1, f3, f0
/* 8023F618  FD 00 28 90 */	fmr f8, f5
/* 8023F61C  FC 60 20 50 */	fneg f3, f4
/* 8023F620  FC 40 08 50 */	fneg f2, f1
/* 8023F624  4B F5 B2 71 */	bl -0xa4d90
/* 8023F628  38 61 00 68 */	addi r3, r1, 0x68
/* 8023F62C  38 9C 00 7C */	addi r4, r28, 0x7c
/* 8023F630  38 BC 00 AC */	addi r5, r28, 0xac
/* 8023F634  4B F5 A7 31 */	bl -0xa58d0
/* 8023F638  7F 9F E3 78 */	mr r31, r28
/* 8023F63C  3B DC 01 2C */	addi r30, r28, 0x12c
/* 8023F640  3B A0 00 00 */	li r29, 0
/* 8023F644  48 00 00 20 */	b 0x20
/* 8023F648  88 9F 01 30 */	lbz r4, 0x130(r31)
/* 8023F64C  7F C3 F3 78 */	mr r3, r30
/* 8023F650  38 BC 00 AC */	addi r5, r28, 0xac
/* 8023F654  4B E1 13 4D */	bl -0x1eecb4
/* 8023F658  3B FF 00 08 */	addi r31, r31, 8
/* 8023F65C  3B DE 00 08 */	addi r30, r30, 8
/* 8023F660  3B BD 00 01 */	addi r29, r29, 1
/* 8023F664  88 1C 01 28 */	lbz r0, 0x128(r28)
/* 8023F668  7C 1D 00 00 */	cmpw r29, r0
/* 8023F66C  41 80 FF DC */	blt -0x24
/* 8023F670  80 01 00 C4 */	lwz r0, 0xc4(r1)
/* 8023F674  83 E1 00 BC */	lwz r31, 0xbc(r1)
/* 8023F678  83 C1 00 B8 */	lwz r30, 0xb8(r1)
/* 8023F67C  83 A1 00 B4 */	lwz r29, 0xb4(r1)
/* 8023F680  83 81 00 B0 */	lwz r28, 0xb0(r1)
/* 8023F684  7C 08 03 A6 */	mtlr r0
/* 8023F688  38 21 00 C0 */	addi r1, r1, 0xc0
/* 8023F68C  4E 80 00 20 */	blr
/* 8023F690  94 21 FD 50 */	stwu r1, -0x2b0(r1)
/* 8023F694  7C 08 02 A6 */	mflr r0
/* 8023F698  90 01 02 B4 */	stw r0, 0x2b4(r1)
/* 8023F69C  DB E1 02 A0 */	stfd f31, 0x2a0(r1)
/* 8023F6A0  F3 E1 02 A8 */	psq_st f31, 680(r1), 0, qr0
/* 8023F6A4  DB C1 02 90 */	stfd f30, 0x290(r1)
/* 8023F6A8  F3 C1 02 98 */	psq_st f30, 664(r1), 0, qr0
/* 8023F6AC  DB A1 02 80 */	stfd f29, 0x280(r1)
/* 8023F6B0  F3 A1 02 88 */	psq_st f29, 648(r1), 0, qr0
/* 8023F6B4  39 61 02 80 */	addi r11, r1, 0x280
/* 8023F6B8  4B DE 1E DD */	bl -0x21e124
/* 8023F6BC  80 83 00 7C */	lwz r4, 0x7c(r3)
/* 8023F6C0  7C 7D 1B 78 */	mr r29, r3
/* 8023F6C4  80 03 00 80 */	lwz r0, 0x80(r3)
/* 8023F6C8  90 01 00 1C */	stw r0, 0x1c(r1)
/* 8023F6CC  90 81 00 18 */	stw r4, 0x18(r1)
/* 8023F6D0  80 83 00 84 */	lwz r4, 0x84(r3)
/* 8023F6D4  80 03 00 88 */	lwz r0, 0x88(r3)
/* 8023F6D8  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023F6DC  90 81 00 20 */	stw r4, 0x20(r1)
/* 8023F6E0  80 83 00 8C */	lwz r4, 0x8c(r3)
/* 8023F6E4  80 03 00 90 */	lwz r0, 0x90(r3)
/* 8023F6E8  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8023F6EC  90 81 00 28 */	stw r4, 0x28(r1)
/* 8023F6F0  80 83 00 94 */	lwz r4, 0x94(r3)
/* 8023F6F4  80 03 00 98 */	lwz r0, 0x98(r3)
/* 8023F6F8  90 01 00 34 */	stw r0, 0x34(r1)
/* 8023F6FC  90 81 00 30 */	stw r4, 0x30(r1)
/* 8023F700  80 83 00 9C */	lwz r4, 0x9c(r3)
/* 8023F704  80 03 00 A0 */	lwz r0, 0xa0(r3)
/* 8023F708  90 01 00 3C */	stw r0, 0x3c(r1)
/* 8023F70C  90 81 00 38 */	stw r4, 0x38(r1)
/* 8023F710  80 83 00 A4 */	lwz r4, 0xa4(r3)
/* 8023F714  80 03 00 A8 */	lwz r0, 0xa8(r3)
/* 8023F718  38 60 00 01 */	li r3, 1
/* 8023F71C  90 01 00 44 */	stw r0, 0x44(r1)
/* 8023F720  90 81 00 40 */	stw r4, 0x40(r1)
/* 8023F724  4B FD B8 C1 */	bl -0x24740
/* 8023F728  38 60 00 00 */	li r3, 0
/* 8023F72C  4B FD B9 8D */	bl -0x24674
/* 8023F730  4B FD BA 05 */	bl -0x245fc
/* 8023F734  38 60 00 01 */	li r3, 1
/* 8023F738  38 80 00 0C */	li r4, 0xc
/* 8023F73C  4B FD BB 61 */	bl -0x244a0
/* 8023F740  38 60 00 01 */	li r3, 1
/* 8023F744  4B F3 2B 65 */	bl -0xcd49c
/* 8023F748  38 60 00 00 */	li r3, 0
/* 8023F74C  38 80 00 FF */	li r4, 0xff
/* 8023F750  38 A0 00 FF */	li r5, 0xff
/* 8023F754  38 C0 00 FF */	li r6, 0xff
/* 8023F758  4B F3 29 F5 */	bl -0xcd60c
/* 8023F75C  38 60 00 00 */	li r3, 0
/* 8023F760  38 80 00 0C */	li r4, 0xc
/* 8023F764  4B F3 27 CD */	bl -0xcd834
/* 8023F768  38 60 00 00 */	li r3, 0
/* 8023F76C  38 80 00 1C */	li r4, 0x1c
/* 8023F770  4B F3 28 11 */	bl -0xcd7f0
/* 8023F774  38 60 00 00 */	li r3, 0
/* 8023F778  38 80 00 0F */	li r4, 0xf
/* 8023F77C  38 A0 00 0F */	li r5, 0xf
/* 8023F780  38 C0 00 0F */	li r6, 0xf
/* 8023F784  38 E0 00 0E */	li r7, 0xe
/* 8023F788  4B F3 25 59 */	bl -0xcdaa8
/* 8023F78C  38 60 00 00 */	li r3, 0
/* 8023F790  38 80 00 07 */	li r4, 7
/* 8023F794  38 A0 00 07 */	li r5, 7
/* 8023F798  38 C0 00 07 */	li r6, 7
/* 8023F79C  38 E0 00 06 */	li r7, 6
/* 8023F7A0  4B F3 25 81 */	bl -0xcda80
/* 8023F7A4  88 E2 9B A4 */	lbz r7, -0x645c(r2)
/* 8023F7A8  38 81 00 10 */	addi r4, r1, 0x10
/* 8023F7AC  88 C2 9B A5 */	lbz r6, -0x645b(r2)
/* 8023F7B0  38 60 00 04 */	li r3, 4
/* 8023F7B4  88 A2 9B A6 */	lbz r5, -0x645a(r2)
/* 8023F7B8  88 02 9B A7 */	lbz r0, -0x6459(r2)
/* 8023F7BC  98 E1 00 10 */	stb r7, 0x10(r1)
/* 8023F7C0  98 C1 00 11 */	stb r6, 0x11(r1)
/* 8023F7C4  98 A1 00 12 */	stb r5, 0x12(r1)
/* 8023F7C8  98 01 00 13 */	stb r0, 0x13(r1)
/* 8023F7CC  4B F3 0C A9 */	bl -0xcf358
/* 8023F7D0  80 6D A2 68 */	lwz r3, -0x5d98(r13)
/* 8023F7D4  3B 41 00 48 */	addi r26, r1, 0x48
/* 8023F7D8  80 0D A2 6C */	lwz r0, -0x5d94(r13)
/* 8023F7DC  3B E0 00 00 */	li r31, 0
/* 8023F7E0  3B C0 00 00 */	li r30, 0
/* 8023F7E4  3B 20 00 00 */	li r25, 0
/* 8023F7E8  7F 83 02 14 */	add r28, r3, r0
/* 8023F7EC  3B 60 00 00 */	li r27, 0
/* 8023F7F0  48 00 00 90 */	b 0x90
/* 8023F7F4  80 7D 00 54 */	lwz r3, 0x54(r29)
/* 8023F7F8  7F 03 C8 2E */	lwzx r24, r3, r25
/* 8023F7FC  7F 03 C3 78 */	mr r3, r24
/* 8023F800  4B FF 0F 19 */	bl -0xf0e8
/* 8023F804  54 63 04 3F */	clrlwi. r3, r3, 0x10
/* 8023F808  40 81 00 40 */	ble 0x40
/* 8023F80C  80 CD A2 6C */	lwz r6, -0x5d94(r13)
/* 8023F810  54 C0 06 FF */	clrlwi. r0, r6, 0x1b
/* 8023F814  41 82 00 0C */	beq 0xc
/* 8023F818  20 00 00 20 */	subfic r0, r0, 0x20
/* 8023F81C  7C C6 02 14 */	add r6, r6, r0
/* 8023F820  1C 03 00 30 */	mulli r0, r3, 0x30
/* 8023F824  80 8D A2 68 */	lwz r4, -0x5d98(r13)
/* 8023F828  7F 03 C3 78 */	mr r3, r24
/* 8023F82C  7C A4 32 14 */	add r5, r4, r6
/* 8023F830  90 BA 00 00 */	stw r5, 0(r26)
/* 8023F834  7C 06 02 14 */	add r0, r6, r0
/* 8023F838  90 0D A2 6C */	stw r0, -0x5d94(r13)
/* 8023F83C  38 81 00 18 */	addi r4, r1, 0x18
/* 8023F840  4B FF 0F 0D */	bl -0xf0f4
/* 8023F844  48 00 00 30 */	b 0x30
/* 8023F848  80 78 00 00 */	lwz r3, 0(r24)
/* 8023F84C  93 7A 00 00 */	stw r27, 0(r26)
/* 8023F850  2C 03 00 00 */	cmpwi r3, 0
/* 8023F854  41 82 00 20 */	beq 0x20
/* 8023F858  81 83 00 00 */	lwz r12, 0(r3)
/* 8023F85C  38 C1 00 18 */	addi r6, r1, 0x18
/* 8023F860  38 80 00 04 */	li r4, 4
/* 8023F864  38 A0 00 00 */	li r5, 0
/* 8023F868  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 8023F86C  7D 89 03 A6 */	mtctr r12
/* 8023F870  4E 80 04 21 */	bctrl
/* 8023F874  3B 39 00 0C */	addi r25, r25, 0xc
/* 8023F878  3B 5A 00 04 */	addi r26, r26, 4
/* 8023F87C  3B DE 00 01 */	addi r30, r30, 1
/* 8023F880  A0 1D 00 2E */	lhz r0, 0x2e(r29)
/* 8023F884  7C 1E 00 00 */	cmpw r30, r0
/* 8023F888  41 80 FF 6C */	blt -0x94
/* 8023F88C  80 6D A2 68 */	lwz r3, -0x5d98(r13)
/* 8023F890  80 0D A2 6C */	lwz r0, -0x5d94(r13)
/* 8023F894  7C 03 02 14 */	add r0, r3, r0
/* 8023F898  7C 9C 00 51 */	subf. r4, r28, r0
/* 8023F89C  41 82 00 0C */	beq 0xc
/* 8023F8A0  7F 83 E3 78 */	mr r3, r28
/* 8023F8A4  4B F6 1D B9 */	bl -0x9e248
/* 8023F8A8  38 60 00 10 */	li r3, 0x10
/* 8023F8AC  4B E2 4B A5 */	bl -0x1db45c
/* 8023F8B0  CB A2 A0 F8 */	lfd f29, -0x5f08(r2)
/* 8023F8B4  3B 21 00 48 */	addi r25, r1, 0x48
/* 8023F8B8  C3 C2 A0 F4 */	lfs f30, -0x5f0c(r2)
/* 8023F8BC  3B C0 00 00 */	li r30, 0
/* 8023F8C0  C3 E2 A0 DC */	lfs f31, -0x5f24(r2)
/* 8023F8C4  3B 40 00 00 */	li r26, 0
/* 8023F8C8  3F 60 43 30 */	lis r27, 0x4330
/* 8023F8CC  3B 80 00 00 */	li r28, 0
/* 8023F8D0  48 00 00 A8 */	b 0xa8
/* 8023F8D4  80 1D 00 54 */	lwz r0, 0x54(r29)
/* 8023F8D8  7C 60 D2 14 */	add r3, r0, r26
/* 8023F8DC  88 03 00 08 */	lbz r0, 8(r3)
/* 8023F8E0  2C 00 00 00 */	cmpwi r0, 0
/* 8023F8E4  40 82 00 88 */	bne 0x88
/* 8023F8E8  88 03 00 09 */	lbz r0, 9(r3)
/* 8023F8EC  38 81 00 0C */	addi r4, r1, 0xc
/* 8023F8F0  88 BD 00 6A */	lbz r5, 0x6a(r29)
/* 8023F8F4  38 60 00 00 */	li r3, 0
/* 8023F8F8  93 61 02 48 */	stw r27, 0x248(r1)
/* 8023F8FC  7C 05 01 D6 */	mullw r0, r5, r0
/* 8023F900  93 81 00 08 */	stw r28, 8(r1)
/* 8023F904  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8023F908  90 01 02 4C */	stw r0, 0x24c(r1)
/* 8023F90C  C8 01 02 48 */	lfd f0, 0x248(r1)
/* 8023F910  EC 00 E8 28 */	fsubs f0, f0, f29
/* 8023F914  EC 1E 00 32 */	fmuls f0, f30, f0
/* 8023F918  EC 1F 00 2A */	fadds f0, f31, f0
/* 8023F91C  FC 00 00 1E */	fctiwz f0, f0
/* 8023F920  D8 01 02 50 */	stfd f0, 0x250(r1)
/* 8023F924  80 01 02 54 */	lwz r0, 0x254(r1)
/* 8023F928  98 01 00 08 */	stb r0, 8(r1)
/* 8023F92C  98 01 00 0B */	stb r0, 0xb(r1)
/* 8023F930  80 01 00 08 */	lwz r0, 8(r1)
/* 8023F934  90 01 00 0C */	stw r0, 0xc(r1)
/* 8023F938  4B F3 25 9D */	bl -0xcda64
/* 8023F93C  80 7D 00 54 */	lwz r3, 0x54(r29)
/* 8023F940  38 80 00 06 */	li r4, 6
/* 8023F944  80 F9 00 00 */	lwz r7, 0(r25)
/* 8023F948  38 A0 00 01 */	li r5, 1
/* 8023F94C  7F 03 D0 2E */	lwzx r24, r3, r26
/* 8023F950  38 C0 00 01 */	li r6, 1
/* 8023F954  7F 03 C3 78 */	mr r3, r24
/* 8023F958  4B FF 0E A5 */	bl -0xf15c
/* 8023F95C  7F 03 C3 78 */	mr r3, r24
/* 8023F960  4B FF 0D B9 */	bl -0xf248
/* 8023F964  54 60 04 3E */	clrlwi r0, r3, 0x10
/* 8023F968  7F FF 02 14 */	add r31, r31, r0
/* 8023F96C  3B 5A 00 0C */	addi r26, r26, 0xc
/* 8023F970  3B 39 00 04 */	addi r25, r25, 4
/* 8023F974  3B DE 00 01 */	addi r30, r30, 1
/* 8023F978  A0 1D 00 2E */	lhz r0, 0x2e(r29)
/* 8023F97C  7C 1E 00 00 */	cmpw r30, r0
/* 8023F980  41 80 FF 54 */	blt -0xac
/* 8023F984  3B 81 00 48 */	addi r28, r1, 0x48
/* 8023F988  3B 00 00 00 */	li r24, 0
/* 8023F98C  3B 60 00 00 */	li r27, 0
/* 8023F990  48 00 00 50 */	b 0x50
/* 8023F994  80 1D 00 54 */	lwz r0, 0x54(r29)
/* 8023F998  7C 60 DA 14 */	add r3, r0, r27
/* 8023F99C  88 03 00 08 */	lbz r0, 8(r3)
/* 8023F9A0  2C 00 00 00 */	cmpwi r0, 0
/* 8023F9A4  41 82 00 30 */	beq 0x30
/* 8023F9A8  83 23 00 00 */	lwz r25, 0(r3)
/* 8023F9AC  38 80 00 04 */	li r4, 4
/* 8023F9B0  80 FC 00 00 */	lwz r7, 0(r28)
/* 8023F9B4  38 A0 00 01 */	li r5, 1
/* 8023F9B8  7F 23 CB 78 */	mr r3, r25
/* 8023F9BC  38 C0 00 01 */	li r6, 1
/* 8023F9C0  4B FF 0E 3D */	bl -0xf1c4
/* 8023F9C4  7F 23 CB 78 */	mr r3, r25
/* 8023F9C8  4B FF 0D 51 */	bl -0xf2b0
/* 8023F9CC  54 60 04 3E */	clrlwi r0, r3, 0x10
/* 8023F9D0  7F FF 02 14 */	add r31, r31, r0
/* 8023F9D4  3B 7B 00 0C */	addi r27, r27, 0xc
/* 8023F9D8  3B 9C 00 04 */	addi r28, r28, 4
/* 8023F9DC  3B 18 00 01 */	addi r24, r24, 1
/* 8023F9E0  A0 1D 00 2E */	lhz r0, 0x2e(r29)
/* 8023F9E4  7C 18 00 00 */	cmpw r24, r0
/* 8023F9E8  41 80 FF AC */	blt -0x54
/* 8023F9EC  E3 E1 02 A8 */	psq_l f31, 680(r1), 0, qr0
/* 8023F9F0  CB E1 02 A0 */	lfd f31, 0x2a0(r1)
/* 8023F9F4  E3 C1 02 98 */	psq_l f30, 664(r1), 0, qr0
/* 8023F9F8  CB C1 02 90 */	lfd f30, 0x290(r1)
/* 8023F9FC  E3 A1 02 88 */	psq_l f29, 648(r1), 0, qr0
/* 8023FA00  39 61 02 80 */	addi r11, r1, 0x280
/* 8023FA04  CB A1 02 80 */	lfd f29, 0x280(r1)
/* 8023FA08  4B DE 1B D9 */	bl -0x21e428
/* 8023FA0C  80 01 02 B4 */	lwz r0, 0x2b4(r1)
/* 8023FA10  7C 08 03 A6 */	mtlr r0
/* 8023FA14  38 21 02 B0 */	addi r1, r1, 0x2b0
/* 8023FA18  4E 80 00 20 */	blr
/* 8023FA1C  94 21 FE A0 */	stwu r1, -0x160(r1)
/* 8023FA20  7C 08 02 A6 */	mflr r0
/* 8023FA24  90 01 01 64 */	stw r0, 0x164(r1)
/* 8023FA28  DB E1 01 50 */	stfd f31, 0x150(r1)
/* 8023FA2C  F3 E1 01 58 */	psq_st f31, 344(r1), 0, qr0
/* 8023FA30  39 61 01 50 */	addi r11, r1, 0x150
/* 8023FA34  4B DE 1B 65 */	bl -0x21e49c
/* 8023FA38  A1 23 00 68 */	lhz r9, 0x68(r3)
/* 8023FA3C  3D 00 43 30 */	lis r8, 0x4330
/* 8023FA40  7C DB 33 78 */	mr r27, r6
/* 8023FA44  91 01 01 10 */	stw r8, 0x110(r1)
/* 8023FA48  55 20 06 F7 */	rlwinm. r0, r9, 0, 0x1b, 0x1b
/* 8023FA4C  7C 79 1B 78 */	mr r25, r3
/* 8023FA50  91 01 01 18 */	stw r8, 0x118(r1)
/* 8023FA54  7C FA 3B 78 */	mr r26, r7
/* 8023FA58  38 C0 00 00 */	li r6, 0
/* 8023FA5C  41 82 00 10 */	beq 0x10
/* 8023FA60  55 20 07 39 */	rlwinm. r0, r9, 0, 0x1c, 0x1c
/* 8023FA64  40 82 00 08 */	bne 0x8
/* 8023FA68  38 C0 00 01 */	li r6, 1
/* 8023FA6C  2C 06 00 00 */	cmpwi r6, 0
/* 8023FA70  41 82 04 80 */	beq 0x480
/* 8023FA74  55 20 07 7B */	rlwinm. r0, r9, 0, 0x1d, 0x1d
/* 8023FA78  A0 0D A3 38 */	lhz r0, -0x5cc8(r13)
/* 8023FA7C  A3 83 00 00 */	lhz r28, 0(r3)
/* 8023FA80  A3 A3 00 02 */	lhz r29, 2(r3)
/* 8023FA84  7C A0 00 38 */	and r0, r5, r0
/* 8023FA88  54 1F FF FE */	rlwinm r31, r0, 0x1f, 0x1f, 0x1f
/* 8023FA8C  41 82 00 0C */	beq 0xc
/* 8023FA90  57 9C 0C 3C */	rlwinm r28, r28, 1, 0x10, 0x1e
/* 8023FA94  57 BD 0C 3C */	rlwinm r29, r29, 1, 0x10, 0x1e
/* 8023FA98  93 81 01 14 */	stw r28, 0x114(r1)
/* 8023FA9C  38 A0 00 00 */	li r5, 0
/* 8023FAA0  C0 03 00 64 */	lfs f0, 0x64(r3)
/* 8023FAA4  38 61 00 A8 */	addi r3, r1, 0xa8
/* 8023FAA8  C0 42 A1 00 */	lfs f2, -0x5f00(r2)
/* 8023FAAC  93 A1 01 1C */	stw r29, 0x11c(r1)
/* 8023FAB0  EF E2 00 32 */	fmuls f31, f2, f0
/* 8023FAB4  C0 22 A0 D4 */	lfs f1, -0x5f2c(r2)
/* 8023FAB8  C8 82 A0 E8 */	lfd f4, -0x5f18(r2)
/* 8023FABC  C8 61 01 10 */	lfd f3, 0x110(r1)
/* 8023FAC0  FC 40 08 90 */	fmr f2, f1
/* 8023FAC4  C8 01 01 18 */	lfd f0, 0x118(r1)
/* 8023FAC8  EC 63 20 28 */	fsubs f3, f3, f4
/* 8023FACC  80 84 00 3C */	lwz r4, 0x3c(r4)
/* 8023FAD0  EC 80 20 28 */	fsubs f4, f0, f4
/* 8023FAD4  4B FF D8 AD */	bl -0x2754
/* 8023FAD8  A0 61 00 DC */	lhz r3, 0xdc(r1)
/* 8023FADC  54 60 07 39 */	rlwinm. r0, r3, 0, 0x1c, 0x1c
/* 8023FAE0  40 82 00 0C */	bne 0xc
/* 8023FAE4  60 60 00 01 */	ori r0, r3, 1
/* 8023FAE8  B0 01 00 DC */	sth r0, 0xdc(r1)
/* 8023FAEC  C0 02 A1 04 */	lfs f0, -0x5efc(r2)
/* 8023FAF0  38 00 00 00 */	li r0, 0
/* 8023FAF4  A0 81 00 DC */	lhz r4, 0xdc(r1)
/* 8023FAF8  38 61 00 A8 */	addi r3, r1, 0xa8
/* 8023FAFC  EC 00 F8 2A */	fadds f0, f0, f31
/* 8023FB00  C0 22 A0 D4 */	lfs f1, -0x5f2c(r2)
/* 8023FB04  60 84 00 48 */	ori r4, r4, 0x48
/* 8023FB08  B0 81 00 DC */	sth r4, 0xdc(r1)
/* 8023FB0C  D0 21 00 C0 */	stfs f1, 0xc0(r1)
/* 8023FB10  D0 01 00 C4 */	stfs f0, 0xc4(r1)
/* 8023FB14  90 01 00 A8 */	stw r0, 0xa8(r1)
/* 8023FB18  4B FF D9 D1 */	bl -0x2630
/* 8023FB1C  2C 1B 00 00 */	cmpwi r27, 0
/* 8023FB20  41 82 00 98 */	beq 0x98
/* 8023FB24  7C 1C 00 D0 */	neg r0, r28
/* 8023FB28  93 A1 01 1C */	stw r29, 0x11c(r1)
/* 8023FB2C  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 8023FB30  C8 42 A0 F8 */	lfd f2, -0x5f08(r2)
/* 8023FB34  90 01 01 14 */	stw r0, 0x114(r1)
/* 8023FB38  38 61 00 A8 */	addi r3, r1, 0xa8
/* 8023FB3C  C8 01 01 18 */	lfd f0, 0x118(r1)
/* 8023FB40  38 81 00 10 */	addi r4, r1, 0x10
/* 8023FB44  C8 21 01 10 */	lfd f1, 0x110(r1)
/* 8023FB48  C8 82 A0 E8 */	lfd f4, -0x5f18(r2)
/* 8023FB4C  93 81 01 14 */	stw r28, 0x114(r1)
/* 8023FB50  EC 21 10 28 */	fsubs f1, f1, f2
/* 8023FB54  C0 A2 A0 DC */	lfs f5, -0x5f24(r2)
/* 8023FB58  EC 40 20 28 */	fsubs f2, f0, f4
/* 8023FB5C  93 A1 01 1C */	stw r29, 0x11c(r1)
/* 8023FB60  C8 61 01 10 */	lfd f3, 0x110(r1)
/* 8023FB64  EC 21 01 72 */	fmuls f1, f1, f5
/* 8023FB68  C8 01 01 18 */	lfd f0, 0x118(r1)
/* 8023FB6C  EC 42 01 72 */	fmuls f2, f2, f5
/* 8023FB70  EC 63 20 28 */	fsubs f3, f3, f4
/* 8023FB74  EC 80 20 28 */	fsubs f4, f0, f4
/* 8023FB78  4B FF E2 5D */	bl -0x1da4
/* 8023FB7C  88 C2 A1 D8 */	lbz r6, -0x5e28(r2)
/* 8023FB80  38 61 00 10 */	addi r3, r1, 0x10
/* 8023FB84  89 42 A1 D9 */	lbz r10, -0x5e27(r2)
/* 8023FB88  38 E1 00 08 */	addi r7, r1, 8
/* 8023FB8C  89 22 A1 DA */	lbz r9, -0x5e26(r2)
/* 8023FB90  38 80 00 01 */	li r4, 1
/* 8023FB94  88 02 A1 DB */	lbz r0, -0x5e25(r2)
/* 8023FB98  38 A0 00 01 */	li r5, 1
/* 8023FB9C  98 C1 00 08 */	stb r6, 8(r1)
/* 8023FBA0  38 C0 00 00 */	li r6, 0
/* 8023FBA4  39 00 00 00 */	li r8, 0
/* 8023FBA8  99 41 00 09 */	stb r10, 9(r1)
/* 8023FBAC  99 21 00 0A */	stb r9, 0xa(r1)
/* 8023FBB0  98 01 00 0B */	stb r0, 0xb(r1)
/* 8023FBB4  4B FD B1 C5 */	bl -0x24e3c
/* 8023FBB8  2C 1F 00 00 */	cmpwi r31, 0
/* 8023FBBC  41 82 00 30 */	beq 0x30
/* 8023FBC0  38 60 00 00 */	li r3, 0
/* 8023FBC4  4B F3 2C 09 */	bl -0xcd3f8
/* 8023FBC8  3F 60 80 38 */	lis r27, 0x8038
/* 8023FBCC  38 00 00 00 */	li r0, 0
/* 8023FBD0  3B 7B 45 20 */	addi r27, r27, 0x4520
/* 8023FBD4  38 60 00 01 */	li r3, 1
/* 8023FBD8  98 1B 00 0C */	stb r0, 0xc(r27)
/* 8023FBDC  4B F3 2C 1D */	bl -0xcd3e4
/* 8023FBE0  38 00 00 01 */	li r0, 1
/* 8023FBE4  98 1B 00 0D */	stb r0, 0xd(r27)
/* 8023FBE8  48 00 00 2C */	b 0x2c
/* 8023FBEC  38 60 00 01 */	li r3, 1
/* 8023FBF0  4B F3 2B DD */	bl -0xcd424
/* 8023FBF4  3F 60 80 38 */	lis r27, 0x8038
/* 8023FBF8  38 00 00 01 */	li r0, 1
/* 8023FBFC  3B 7B 45 20 */	addi r27, r27, 0x4520
/* 8023FC00  38 60 00 00 */	li r3, 0
/* 8023FC04  98 1B 00 0C */	stb r0, 0xc(r27)
/* 8023FC08  4B F3 2B F1 */	bl -0xcd410
/* 8023FC0C  38 00 00 00 */	li r0, 0
/* 8023FC10  98 1B 00 0D */	stb r0, 0xd(r27)
/* 8023FC14  7F 23 CB 78 */	mr r3, r25
/* 8023FC18  4B FF FA 79 */	bl -0x588
/* 8023FC1C  38 61 00 A8 */	addi r3, r1, 0xa8
/* 8023FC20  4B FF DF B9 */	bl -0x2048
/* 8023FC24  C0 23 00 00 */	lfs f1, 0(r3)
/* 8023FC28  C0 03 00 04 */	lfs f0, 4(r3)
/* 8023FC2C  FC 20 08 1E */	fctiwz f1, f1
/* 8023FC30  A0 79 00 68 */	lhz r3, 0x68(r25)
/* 8023FC34  FC 00 00 1E */	fctiwz f0, f0
/* 8023FC38  D8 21 01 20 */	stfd f1, 0x120(r1)
/* 8023FC3C  54 60 07 BD */	rlwinm. r0, r3, 0, 0x1e, 0x1e
/* 8023FC40  D8 01 01 28 */	stfd f0, 0x128(r1)
/* 8023FC44  83 A1 01 24 */	lwz r29, 0x124(r1)
/* 8023FC48  83 81 01 2C */	lwz r28, 0x12c(r1)
/* 8023FC4C  40 82 00 0C */	bne 0xc
/* 8023FC50  54 60 07 7B */	rlwinm. r0, r3, 0, 0x1d, 0x1d
/* 8023FC54  41 82 02 18 */	beq 0x218
/* 8023FC58  38 60 00 01 */	li r3, 1
/* 8023FC5C  4B F3 2B 71 */	bl -0xcd490
/* 8023FC60  3F 60 80 38 */	lis r27, 0x8038
/* 8023FC64  38 00 00 01 */	li r0, 1
/* 8023FC68  3B 7B 45 20 */	addi r27, r27, 0x4520
/* 8023FC6C  38 60 00 00 */	li r3, 0
/* 8023FC70  98 1B 00 0C */	stb r0, 0xc(r27)
/* 8023FC74  4B F3 2B 85 */	bl -0xcd47c
/* 8023FC78  38 00 00 00 */	li r0, 0
/* 8023FC7C  98 1B 00 0D */	stb r0, 0xd(r27)
/* 8023FC80  88 62 9B 18 */	lbz r3, -0x64e8(r2)
/* 8023FC84  80 99 01 0C */	lwz r4, 0x10c(r25)
/* 8023FC88  88 02 9B 19 */	lbz r0, -0x64e7(r2)
/* 8023FC8C  83 C4 00 04 */	lwz r30, 4(r4)
/* 8023FC90  88 C2 9B 1A */	lbz r6, -0x64e6(r2)
/* 8023FC94  88 9E 00 14 */	lbz r4, 0x14(r30)
/* 8023FC98  88 A2 9B 1B */	lbz r5, -0x64e5(r2)
/* 8023FC9C  60 84 00 08 */	ori r4, r4, 8
/* 8023FCA0  98 9E 00 14 */	stb r4, 0x14(r30)
/* 8023FCA4  88 82 9B 1C */	lbz r4, -0x64e4(r2)
/* 8023FCA8  98 7E 00 20 */	stb r3, 0x20(r30)
/* 8023FCAC  88 62 9B 1D */	lbz r3, -0x64e3(r2)
/* 8023FCB0  98 1E 00 21 */	stb r0, 0x21(r30)
/* 8023FCB4  88 02 9B 1E */	lbz r0, -0x64e2(r2)
/* 8023FCB8  98 DE 00 22 */	stb r6, 0x22(r30)
/* 8023FCBC  98 BE 00 23 */	stb r5, 0x23(r30)
/* 8023FCC0  98 9E 00 24 */	stb r4, 0x24(r30)
/* 8023FCC4  98 7E 00 25 */	stb r3, 0x25(r30)
/* 8023FCC8  98 1E 00 26 */	stb r0, 0x26(r30)
/* 8023FCCC  A0 19 00 68 */	lhz r0, 0x68(r25)
/* 8023FCD0  54 1B DF FF */	rlwinm. r27, r0, 0x1b, 0x1f, 0x1f
/* 8023FCD4  40 82 00 14 */	bne 0x14
/* 8023FCD8  88 1E 00 14 */	lbz r0, 0x14(r30)
/* 8023FCDC  60 00 00 03 */	ori r0, r0, 3
/* 8023FCE0  98 1E 00 14 */	stb r0, 0x14(r30)
/* 8023FCE4  48 00 00 10 */	b 0x10
/* 8023FCE8  88 1E 00 14 */	lbz r0, 0x14(r30)
/* 8023FCEC  60 00 00 04 */	ori r0, r0, 4
/* 8023FCF0  98 1E 00 14 */	stb r0, 0x14(r30)
/* 8023FCF4  2C 1B 00 00 */	cmpwi r27, 0
/* 8023FCF8  41 82 00 14 */	beq 0x14
/* 8023FCFC  88 1E 00 14 */	lbz r0, 0x14(r30)
/* 8023FD00  54 00 06 3A */	rlwinm r0, r0, 0, 0x18, 0x1d
/* 8023FD04  98 1E 00 14 */	stb r0, 0x14(r30)
/* 8023FD08  48 00 00 28 */	b 0x28
/* 8023FD0C  88 02 A1 D8 */	lbz r0, -0x5e28(r2)
/* 8023FD10  38 62 A1 D8 */	addi r3, r2, -24104
/* 8023FD14  98 1E 00 15 */	stb r0, 0x15(r30)
/* 8023FD18  88 03 00 01 */	lbz r0, 1(r3)
/* 8023FD1C  98 1E 00 16 */	stb r0, 0x16(r30)
/* 8023FD20  88 03 00 02 */	lbz r0, 2(r3)
/* 8023FD24  98 1E 00 17 */	stb r0, 0x17(r30)
/* 8023FD28  88 03 00 03 */	lbz r0, 3(r3)
/* 8023FD2C  98 1E 00 18 */	stb r0, 0x18(r30)
/* 8023FD30  2C 1F 00 00 */	cmpwi r31, 0
/* 8023FD34  38 E0 00 28 */	li r7, 0x28
/* 8023FD38  41 82 00 08 */	beq 0x8
/* 8023FD3C  38 E0 00 27 */	li r7, 0x27
/* 8023FD40  A0 19 00 68 */	lhz r0, 0x68(r25)
/* 8023FD44  7F C3 F3 78 */	mr r3, r30
/* 8023FD48  57 A4 04 3E */	clrlwi r4, r29, 0x10
/* 8023FD4C  57 85 04 3E */	clrlwi r5, r28, 0x10
/* 8023FD50  54 06 F7 FE */	rlwinm r6, r0, 0x1e, 0x1f, 0x1f
/* 8023FD54  4B FD 4F 21 */	bl -0x2b0e0
/* 8023FD58  38 61 00 40 */	addi r3, r1, 0x40
/* 8023FD5C  38 81 00 A8 */	addi r4, r1, 0xa8
/* 8023FD60  4B FF D6 E9 */	bl -0x2918
/* 8023FD64  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8023FD68  C0 22 A0 D4 */	lfs f1, -0x5f2c(r2)
/* 8023FD6C  C0 02 A0 D0 */	lfs f0, -0x5f30(r2)
/* 8023FD70  2C 00 00 01 */	cmpwi r0, 1
/* 8023FD74  D0 21 00 58 */	stfs f1, 0x58(r1)
/* 8023FD78  D0 01 00 5C */	stfs f0, 0x5c(r1)
/* 8023FD7C  41 82 00 18 */	beq 0x18
/* 8023FD80  A0 61 00 74 */	lhz r3, 0x74(r1)
/* 8023FD84  38 00 00 01 */	li r0, 1
/* 8023FD88  90 01 00 44 */	stw r0, 0x44(r1)
/* 8023FD8C  60 60 00 01 */	ori r0, r3, 1
/* 8023FD90  B0 01 00 74 */	sth r0, 0x74(r1)
/* 8023FD94  38 61 00 40 */	addi r3, r1, 0x40
/* 8023FD98  4B FF D7 51 */	bl -0x28b0
/* 8023FD9C  2C 1B 00 00 */	cmpwi r27, 0
/* 8023FDA0  41 82 00 B8 */	beq 0xb8
/* 8023FDA4  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FDA8  7F E0 00 34 */	cntlzw r0, r31
/* 8023FDAC  88 99 01 1C */	lbz r4, 0x11c(r25)
/* 8023FDB0  54 05 D9 7E */	srwi r5, r0, 5
/* 8023FDB4  98 83 00 30 */	stb r4, 0x30(r3)
/* 8023FDB8  7C 05 00 D0 */	neg r0, r5
/* 8023FDBC  7C 03 2B 78 */	or r3, r0, r5
/* 8023FDC0  80 99 01 10 */	lwz r4, 0x110(r25)
/* 8023FDC4  54 63 0F FE */	srwi r3, r3, 0x1f
/* 8023FDC8  C0 19 01 18 */	lfs f0, 0x118(r25)
/* 8023FDCC  38 00 00 00 */	li r0, 0
/* 8023FDD0  D0 04 00 28 */	stfs f0, 0x28(r4)
/* 8023FDD4  80 99 01 10 */	lwz r4, 0x110(r25)
/* 8023FDD8  98 A4 00 38 */	stb r5, 0x38(r4)
/* 8023FDDC  80 99 01 10 */	lwz r4, 0x110(r25)
/* 8023FDE0  90 64 00 00 */	stw r3, 0(r4)
/* 8023FDE4  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FDE8  90 03 00 08 */	stw r0, 8(r3)
/* 8023FDEC  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FDF0  4B FF 4D 55 */	bl -0xb2ac
/* 8023FDF4  88 19 01 24 */	lbz r0, 0x124(r25)
/* 8023FDF8  2C 00 00 00 */	cmpwi r0, 0
/* 8023FDFC  41 82 00 70 */	beq 0x70
/* 8023FE00  7F C3 F3 78 */	mr r3, r30
/* 8023FE04  57 A4 04 3E */	clrlwi r4, r29, 0x10
/* 8023FE08  57 85 04 3E */	clrlwi r5, r28, 0x10
/* 8023FE0C  38 C0 00 00 */	li r6, 0
/* 8023FE10  38 E0 00 28 */	li r7, 0x28
/* 8023FE14  4B FD 4E 61 */	bl -0x2b1a0
/* 8023FE18  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FE1C  38 00 00 01 */	li r0, 1
/* 8023FE20  88 99 01 24 */	lbz r4, 0x124(r25)
/* 8023FE24  98 83 00 30 */	stb r4, 0x30(r3)
/* 8023FE28  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FE2C  C0 19 01 20 */	lfs f0, 0x120(r25)
/* 8023FE30  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8023FE34  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FE38  98 03 00 38 */	stb r0, 0x38(r3)
/* 8023FE3C  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FE40  90 03 00 00 */	stw r0, 0(r3)
/* 8023FE44  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FE48  90 03 00 08 */	stw r0, 8(r3)
/* 8023FE4C  80 79 01 10 */	lwz r3, 0x110(r25)
/* 8023FE50  4B FF 4C F5 */	bl -0xb30c
/* 8023FE54  48 00 00 18 */	b 0x18
/* 8023FE58  80 79 01 0C */	lwz r3, 0x10c(r25)
/* 8023FE5C  38 00 00 00 */	li r0, 0
/* 8023FE60  90 03 00 08 */	stw r0, 8(r3)
/* 8023FE64  80 79 01 0C */	lwz r3, 0x10c(r25)
/* 8023FE68  4B FF 4C DD */	bl -0xb324
/* 8023FE6C  2C 1A 00 00 */	cmpwi r26, 0
/* 8023FE70  41 82 00 28 */	beq 0x28
/* 8023FE74  88 0D A3 5C */	lbz r0, -0x5ca4(r13)
/* 8023FE78  38 6D A3 5C */	addi r3, r13, -23716
/* 8023FE7C  98 19 00 15 */	stb r0, 0x15(r25)
/* 8023FE80  88 03 00 01 */	lbz r0, 1(r3)
/* 8023FE84  98 19 00 16 */	stb r0, 0x16(r25)
/* 8023FE88  88 03 00 02 */	lbz r0, 2(r3)
/* 8023FE8C  98 19 00 17 */	stb r0, 0x17(r25)
/* 8023FE90  88 03 00 03 */	lbz r0, 3(r3)
/* 8023FE94  98 19 00 18 */	stb r0, 0x18(r25)
/* 8023FE98  88 99 00 05 */	lbz r4, 5(r25)
/* 8023FE9C  7F E0 00 34 */	cntlzw r0, r31
/* 8023FEA0  3C 60 80 26 */	lis r3, 0x8026
/* 8023FEA4  88 D9 00 14 */	lbz r6, 0x14(r25)
/* 8023FEA8  20 A4 00 01 */	subfic r5, r4, 1
/* 8023FEAC  38 84 FF FF */	addi r4, r4, -1
/* 8023FEB0  7C A4 23 78 */	or r4, r5, r4
/* 8023FEB4  54 00 F0 B8 */	rlwinm r0, r0, 0x1e, 2, 0x1c
/* 8023FEB8  38 63 81 B8 */	addi r3, r3, -32328
/* 8023FEBC  54 C5 07 34 */	rlwinm r5, r6, 0, 0x1c, 0x1a
/* 8023FEC0  7C 03 02 14 */	add r0, r3, r0
/* 8023FEC4  54 84 1F 7A */	rlwinm r4, r4, 3, 0x1d, 0x1d
/* 8023FEC8  98 B9 00 14 */	stb r5, 0x14(r25)
/* 8023FECC  7F 23 CB 78 */	mr r3, r25
/* 8023FED0  7C E4 00 2E */	lwzx r7, r4, r0
/* 8023FED4  57 A4 04 3E */	clrlwi r4, r29, 0x10
/* 8023FED8  57 85 04 3E */	clrlwi r5, r28, 0x10
/* 8023FEDC  38 C0 00 00 */	li r6, 0
/* 8023FEE0  4B FD 4D 95 */	bl -0x2b26c
/* 8023FEE4  A0 19 00 68 */	lhz r0, 0x68(r25)
/* 8023FEE8  60 00 00 08 */	ori r0, r0, 8
/* 8023FEEC  B0 19 00 68 */	sth r0, 0x68(r25)
/* 8023FEF0  E3 E1 01 58 */	psq_l f31, 344(r1), 0, qr0
/* 8023FEF4  39 61 01 50 */	addi r11, r1, 0x150
/* 8023FEF8  CB E1 01 50 */	lfd f31, 0x150(r1)
/* 8023FEFC  4B DE 16 E9 */	bl -0x21e918
/* 8023FF00  80 01 01 64 */	lwz r0, 0x164(r1)
/* 8023FF04  7C 08 03 A6 */	mtlr r0
/* 8023FF08  38 21 01 60 */	addi r1, r1, 0x160
/* 8023FF0C  4E 80 00 20 */	blr
/* 8023FF10  80 A3 01 0C */	lwz r5, 0x10c(r3)
/* 8023FF14  90 85 00 04 */	stw r4, 4(r5)
/* 8023FF18  80 63 01 10 */	lwz r3, 0x110(r3)
/* 8023FF1C  90 83 00 04 */	stw r4, 4(r3)
/* 8023FF20  4E 80 00 20 */	blr
/* 8023FF24  3C A0 80 2A */	lis r5, 0x802a
/* 8023FF28  38 80 00 01 */	li r4, 1
/* 8023FF2C  38 00 00 10 */	li r0, 0x10
/* 8023FF30  98 83 00 00 */	stb r4, 0(r3)
/* 8023FF34  38 A5 3F 40 */	addi r5, r5, 0x3f40
/* 8023FF38  90 A3 00 44 */	stw r5, 0x44(r3)
/* 8023FF3C  38 A0 00 00 */	li r5, 0
/* 8023FF40  B0 03 00 02 */	sth r0, 2(r3)
/* 8023FF44  90 A3 00 04 */	stw r5, 4(r3)
/* 8023FF48  90 A3 00 08 */	stw r5, 8(r3)
/* 8023FF4C  90 A3 00 0C */	stw r5, 0xc(r3)
/* 8023FF50  90 A3 00 10 */	stw r5, 0x10(r3)
/* 8023FF54  90 A3 00 14 */	stw r5, 0x14(r3)
/* 8023FF58  90 A3 00 18 */	stw r5, 0x18(r3)
/* 8023FF5C  90 A3 00 1C */	stw r5, 0x1c(r3)
/* 8023FF60  90 A3 00 20 */	stw r5, 0x20(r3)
/* 8023FF64  90 A3 00 24 */	stw r5, 0x24(r3)
/* 8023FF68  90 A3 00 28 */	stw r5, 0x28(r3)
/* 8023FF6C  90 A3 00 2C */	stw r5, 0x2c(r3)
/* 8023FF70  90 A3 00 30 */	stw r5, 0x30(r3)
/* 8023FF74  90 A3 00 34 */	stw r5, 0x34(r3)
/* 8023FF78  90 A3 00 38 */	stw r5, 0x38(r3)
/* 8023FF7C  90 A3 00 3C */	stw r5, 0x3c(r3)
/* 8023FF80  90 A3 00 40 */	stw r5, 0x40(r3)
/* 8023FF84  4E 80 00 20 */	blr
/* 8023FF88  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8023FF8C  7C 08 02 A6 */	mflr r0
/* 8023FF90  90 01 00 24 */	stw r0, 0x24(r1)
/* 8023FF94  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 8023FF98  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8023FF9C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 8023FFA0  7C 7D 1B 78 */	mr r29, r3
/* 8023FFA4  88 03 00 00 */	lbz r0, 0(r3)
/* 8023FFA8  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8023FFAC  41 82 00 80 */	beq 0x80
/* 8023FFB0  88 03 00 00 */	lbz r0, 0(r3)
/* 8023FFB4  7F BF EB 78 */	mr r31, r29
/* 8023FFB8  3B C0 00 00 */	li r30, 0
/* 8023FFBC  54 00 07 FA */	rlwinm r0, r0, 0, 0x1f, 0x1d
/* 8023FFC0  98 03 00 00 */	stb r0, 0(r3)
/* 8023FFC4  80 7F 00 04 */	lwz r3, 4(r31)
/* 8023FFC8  2C 03 00 00 */	cmpwi r3, 0
/* 8023FFCC  41 82 00 20 */	beq 0x20
/* 8023FFD0  80 03 01 14 */	lwz r0, 0x114(r3)
/* 8023FFD4  2C 00 00 00 */	cmpwi r0, 0
/* 8023FFD8  40 82 00 14 */	bne 0x14
/* 8023FFDC  4B FF F1 81 */	bl -0xe80
/* 8023FFE0  88 1D 00 00 */	lbz r0, 0(r29)
/* 8023FFE4  60 00 00 02 */	ori r0, r0, 2
/* 8023FFE8  98 1D 00 00 */	stb r0, 0(r29)
/* 8023FFEC  3B DE 00 01 */	addi r30, r30, 1
/* 8023FFF0  3B FF 00 04 */	addi r31, r31, 4
/* 8023FFF4  2C 1E 00 10 */	cmpwi r30, 0x10
/* 8023FFF8  41 80 FF CC */	blt -0x34
/* 8023FFFC  3B C0 00 00 */	li r30, 0
/* 80240000  80 7D 00 04 */	lwz r3, 4(r29)
/* 80240004  2C 03 00 00 */	cmpwi r3, 0
/* 80240008  41 82 00 14 */	beq 0x14
/* 8024000C  80 03 01 14 */	lwz r0, 0x114(r3)
/* 80240010  2C 00 00 00 */	cmpwi r0, 0
/* 80240014  41 82 00 08 */	beq 0x8
/* 80240018  4B FF F1 45 */	bl -0xebc
/* 8024001C  3B DE 00 01 */	addi r30, r30, 1
/* 80240020  3B BD 00 04 */	addi r29, r29, 4
/* 80240024  2C 1E 00 10 */	cmpwi r30, 0x10
/* 80240028  41 80 FF D8 */	blt -0x28
/* 8024002C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80240030  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80240034  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80240038  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8024003C  7C 08 03 A6 */	mtlr r0
/* 80240040  38 21 00 20 */	addi r1, r1, 0x20
/* 80240044  4E 80 00 20 */	blr
/* 80240048  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 8024004C  7C 08 02 A6 */	mflr r0
/* 80240050  90 01 00 94 */	stw r0, 0x94(r1)
/* 80240054  39 61 00 90 */	addi r11, r1, 0x90
/* 80240058  4B DE 15 29 */	bl -0x21ead8
/* 8024005C  88 03 00 00 */	lbz r0, 0(r3)
/* 80240060  7C 76 1B 78 */	mr r22, r3
/* 80240064  7C 97 23 78 */	mr r23, r4
/* 80240068  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8024006C  41 82 02 5C */	beq 0x25c
/* 80240070  88 03 00 00 */	lbz r0, 0(r3)
/* 80240074  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80240078  40 82 00 08 */	bne 0x8
/* 8024007C  48 00 02 4C */	b 0x24c
/* 80240080  3E A0 80 38 */	lis r21, 0x8038
/* 80240084  38 60 00 01 */	li r3, 1
/* 80240088  3A B5 45 20 */	addi r21, r21, 0x4520
/* 8024008C  8B D5 00 0E */	lbz r30, 0xe(r21)
/* 80240090  4B F3 28 A1 */	bl -0xcd760
/* 80240094  88 E2 9B A4 */	lbz r7, -0x645c(r2)
/* 80240098  3B E0 00 01 */	li r31, 1
/* 8024009C  88 C2 9B A5 */	lbz r6, -0x645b(r2)
/* 802400A0  38 81 00 0C */	addi r4, r1, 0xc
/* 802400A4  88 A2 9B A6 */	lbz r5, -0x645a(r2)
/* 802400A8  38 60 00 04 */	li r3, 4
/* 802400AC  88 02 9B A7 */	lbz r0, -0x6459(r2)
/* 802400B0  9B F5 00 0E */	stb r31, 0xe(r21)
/* 802400B4  98 E1 00 0C */	stb r7, 0xc(r1)
/* 802400B8  98 C1 00 0D */	stb r6, 0xd(r1)
/* 802400BC  98 A1 00 0E */	stb r5, 0xe(r1)
/* 802400C0  98 01 00 0F */	stb r0, 0xf(r1)
/* 802400C4  4B F3 02 D9 */	bl -0xcfd28
/* 802400C8  C0 22 A1 0C */	lfs f1, -0x5ef4(r2)
/* 802400CC  38 81 00 08 */	addi r4, r1, 8
/* 802400D0  C0 42 A1 10 */	lfs f2, -0x5ef0(r2)
/* 802400D4  38 60 00 00 */	li r3, 0
/* 802400D8  88 E2 A1 08 */	lbz r7, -0x5ef8(r2)
/* 802400DC  FC 60 08 90 */	fmr f3, f1
/* 802400E0  88 C2 A1 09 */	lbz r6, -0x5ef7(r2)
/* 802400E4  FC 80 10 90 */	fmr f4, f2
/* 802400E8  88 A2 A1 0A */	lbz r5, -0x5ef6(r2)
/* 802400EC  88 02 A1 0B */	lbz r0, -0x5ef5(r2)
/* 802400F0  98 E1 00 08 */	stb r7, 8(r1)
/* 802400F4  98 C1 00 09 */	stb r6, 9(r1)
/* 802400F8  98 A1 00 0A */	stb r5, 0xa(r1)
/* 802400FC  98 01 00 0B */	stb r0, 0xb(r1)
/* 80240100  4B F3 21 CD */	bl -0xcde34
/* 80240104  7E DD B3 78 */	mr r29, r22
/* 80240108  3B 81 00 10 */	addi r28, r1, 0x10
/* 8024010C  3B 60 FF FF */	li r27, -1
/* 80240110  3B 40 FF FF */	li r26, -1
/* 80240114  3B 20 00 00 */	li r25, 0
/* 80240118  3A A0 00 00 */	li r21, 0
/* 8024011C  83 1D 00 04 */	lwz r24, 4(r29)
/* 80240120  92 BC 00 00 */	stw r21, 0(r28)
/* 80240124  2C 18 00 00 */	cmpwi r24, 0
/* 80240128  41 82 00 D8 */	beq 0xd8
/* 8024012C  A0 98 00 68 */	lhz r4, 0x68(r24)
/* 80240130  38 60 00 00 */	li r3, 0
/* 80240134  54 80 06 F7 */	rlwinm. r0, r4, 0, 0x1b, 0x1b
/* 80240138  41 82 00 10 */	beq 0x10
/* 8024013C  54 80 07 39 */	rlwinm. r0, r4, 0, 0x1c, 0x1c
/* 80240140  40 82 00 08 */	bne 0x8
/* 80240144  38 60 00 01 */	li r3, 1
/* 80240148  2C 03 00 00 */	cmpwi r3, 0
/* 8024014C  41 82 00 B4 */	beq 0xb4
/* 80240150  54 80 07 BD */	rlwinm. r0, r4, 0, 0x1e, 0x1e
/* 80240154  40 82 00 0C */	bne 0xc
/* 80240158  54 80 07 7B */	rlwinm. r0, r4, 0, 0x1d, 0x1d
/* 8024015C  41 82 00 8C */	beq 0x8c
/* 80240160  54 80 07 7B */	rlwinm. r0, r4, 0, 0x1d, 0x1d
/* 80240164  A2 98 00 00 */	lhz r20, 0(r24)
/* 80240168  A2 78 00 02 */	lhz r19, 2(r24)
/* 8024016C  41 82 00 0C */	beq 0xc
/* 80240170  56 94 0C 3C */	rlwinm r20, r20, 1, 0x10, 0x1e
/* 80240174  56 73 0C 3C */	rlwinm r19, r19, 1, 0x10, 0x1e
/* 80240178  2C 14 00 00 */	cmpwi r20, 0
/* 8024017C  41 82 00 0C */	beq 0xc
/* 80240180  2C 13 00 00 */	cmpwi r19, 0
/* 80240184  40 82 00 0C */	bne 0xc
/* 80240188  3A 80 00 00 */	li r20, 0
/* 8024018C  48 00 00 4C */	b 0x4c
/* 80240190  48 00 2F E5 */	bl 0x2fe4
/* 80240194  B2 83 00 00 */	sth r20, 0(r3)
/* 80240198  7C 74 1B 78 */	mr r20, r3
/* 8024019C  B2 63 00 02 */	sth r19, 2(r3)
/* 802401A0  9B E3 00 05 */	stb r31, 5(r3)
/* 802401A4  81 83 00 10 */	lwz r12, 0x10(r3)
/* 802401A8  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 802401AC  7D 89 03 A6 */	mtctr r12
/* 802401B0  4E 80 04 21 */	bctrl
/* 802401B4  A0 74 00 00 */	lhz r3, 0(r20)
/* 802401B8  38 C0 00 00 */	li r6, 0
/* 802401BC  A0 94 00 02 */	lhz r4, 2(r20)
/* 802401C0  38 E0 00 01 */	li r7, 1
/* 802401C4  88 B4 00 05 */	lbz r5, 5(r20)
/* 802401C8  4B F3 04 4D */	bl -0xcfbb4
/* 802401CC  7C 64 1B 78 */	mr r4, r3
/* 802401D0  7E 83 A3 78 */	mr r3, r20
/* 802401D4  48 00 2F C9 */	bl 0x2fc8
/* 802401D8  92 9C 00 00 */	stw r20, 0(r28)
/* 802401DC  7F 03 C3 78 */	mr r3, r24
/* 802401E0  7E 84 A3 78 */	mr r4, r20
/* 802401E4  4B FF FD 2D */	bl -0x2d4
/* 802401E8  2C 1B FF FF */	cmpwi r27, -1
/* 802401EC  40 82 00 08 */	bne 0x8
/* 802401F0  7F 3B CB 78 */	mr r27, r25
/* 802401F4  7C 19 D0 00 */	cmpw r25, r26
/* 802401F8  40 81 00 08 */	ble 0x8
/* 802401FC  7F 3A CB 78 */	mr r26, r25
/* 80240200  3B 39 00 01 */	addi r25, r25, 1
/* 80240204  3B 9C 00 04 */	addi r28, r28, 4
/* 80240208  2C 19 00 10 */	cmpwi r25, 0x10
/* 8024020C  3B BD 00 04 */	addi r29, r29, 4
/* 80240210  41 80 FF 0C */	blt -0xf4
/* 80240214  4B F3 0E FD */	bl -0xcf104
/* 80240218  3A 60 00 00 */	li r19, 0
/* 8024021C  80 76 00 04 */	lwz r3, 4(r22)
/* 80240220  2C 03 00 00 */	cmpwi r3, 0
/* 80240224  41 82 00 58 */	beq 0x58
/* 80240228  A0 A3 00 68 */	lhz r5, 0x68(r3)
/* 8024022C  38 80 00 00 */	li r4, 0
/* 80240230  54 A0 06 F7 */	rlwinm. r0, r5, 0, 0x1b, 0x1b
/* 80240234  41 82 00 10 */	beq 0x10
/* 80240238  54 A0 07 39 */	rlwinm. r0, r5, 0, 0x1c, 0x1c
/* 8024023C  40 82 00 08 */	bne 0x8
/* 80240240  38 80 00 01 */	li r4, 1
/* 80240244  2C 04 00 00 */	cmpwi r4, 0
/* 80240248  41 82 00 34 */	beq 0x34
/* 8024024C  80 AD A3 4C */	lwz r5, -0x5cb4(r13)
/* 80240250  7C 13 D0 50 */	subf r0, r19, r26
/* 80240254  7C 93 D8 50 */	subf r4, r19, r27
/* 80240258  38 C5 FF FF */	addi r6, r5, -1
/* 8024025C  7C 00 00 34 */	cntlzw r0, r0
/* 80240260  7C 85 00 34 */	cntlzw r5, r4
/* 80240264  7E E4 BB 78 */	mr r4, r23
/* 80240268  7C C7 00 34 */	cntlzw r7, r6
/* 8024026C  54 A6 D9 7E */	srwi r6, r5, 5
/* 80240270  54 E5 D9 7E */	srwi r5, r7, 5
/* 80240274  54 07 D9 7E */	srwi r7, r0, 5
/* 80240278  4B FF F7 A5 */	bl -0x85c
/* 8024027C  3A 73 00 01 */	addi r19, r19, 1
/* 80240280  3A D6 00 04 */	addi r22, r22, 4
/* 80240284  2C 13 00 10 */	cmpwi r19, 0x10
/* 80240288  41 80 FF 94 */	blt -0x6c
/* 8024028C  3A 81 00 10 */	addi r20, r1, 0x10
/* 80240290  3A 60 00 00 */	li r19, 0
/* 80240294  80 74 00 00 */	lwz r3, 0(r20)
/* 80240298  2C 03 00 00 */	cmpwi r3, 0
/* 8024029C  41 82 00 08 */	beq 0x8
/* 802402A0  48 00 2C F1 */	bl 0x2cf0
/* 802402A4  3A 73 00 01 */	addi r19, r19, 1
/* 802402A8  3A 94 00 04 */	addi r20, r20, 4
/* 802402AC  2C 13 00 10 */	cmpwi r19, 0x10
/* 802402B0  41 80 FF E4 */	blt -0x1c
/* 802402B4  7F C3 F3 78 */	mr r3, r30
/* 802402B8  4B F3 26 79 */	bl -0xcd988
/* 802402BC  3C 60 80 38 */	lis r3, 0x8038
/* 802402C0  38 63 45 20 */	addi r3, r3, 0x4520
/* 802402C4  9B C3 00 0E */	stb r30, 0xe(r3)
/* 802402C8  39 61 00 90 */	addi r11, r1, 0x90
/* 802402CC  4B DE 13 01 */	bl -0x21ed00
/* 802402D0  80 01 00 94 */	lwz r0, 0x94(r1)
/* 802402D4  7C 08 03 A6 */	mtlr r0
/* 802402D8  38 21 00 90 */	addi r1, r1, 0x90
/* 802402DC  4E 80 00 20 */	blr
/* 802402E0  3D 00 80 38 */	lis r8, 0x8038
/* 802402E4  80 0D 93 B0 */	lwz r0, -0x6c50(r13)
/* 802402E8  39 08 44 80 */	addi r8, r8, 0x4480
/* 802402EC  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 802402F0  38 88 00 30 */	addi r4, r8, 0x30
/* 802402F4  54 07 00 3A */	rlwinm r7, r0, 0, 0, 0x1d
/* 802402F8  38 68 00 48 */	addi r3, r8, 0x48
/* 802402FC  38 C0 FF FF */	li r6, -1
/* 80240300  38 00 00 00 */	li r0, 0
/* 80240304  38 A8 00 00 */	addi r5, r8, 0
/* 80240308  90 ED 93 B0 */	stw r7, -0x6c50(r13)
/* 8024030C  90 CD 93 B4 */	stw r6, -0x6c4c(r13)
/* 80240310  90 0D A3 40 */	stw r0, -0x5cc0(r13)
/* 80240314  90 05 00 08 */	stw r0, 8(r5)
/* 80240318  90 05 00 14 */	stw r0, 0x14(r5)
/* 8024031C  90 05 00 20 */	stw r0, 0x20(r5)
/* 80240320  90 05 00 2C */	stw r0, 0x2c(r5)
/* 80240324  D0 08 00 30 */	stfs f0, 0x30(r8)
/* 80240328  D0 08 00 48 */	stfs f0, 0x48(r8)
/* 8024032C  D0 04 00 04 */	stfs f0, 4(r4)
/* 80240330  D0 03 00 04 */	stfs f0, 4(r3)
/* 80240334  D0 04 00 08 */	stfs f0, 8(r4)
/* 80240338  D0 03 00 08 */	stfs f0, 8(r3)
/* 8024033C  D0 04 00 0C */	stfs f0, 0xc(r4)
/* 80240340  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 80240344  D0 04 00 10 */	stfs f0, 0x10(r4)
/* 80240348  D0 03 00 10 */	stfs f0, 0x10(r3)
/* 8024034C  D0 04 00 14 */	stfs f0, 0x14(r4)
/* 80240350  D0 03 00 14 */	stfs f0, 0x14(r3)
/* 80240354  4E 80 00 20 */	blr
/* 80240358  94 21 FF 70 */	stwu r1, -0x90(r1)
/* 8024035C  7C 08 02 A6 */	mflr r0
/* 80240360  90 01 00 94 */	stw r0, 0x94(r1)
/* 80240364  DB E1 00 80 */	stfd f31, 0x80(r1)
/* 80240368  F3 E1 00 88 */	psq_st f31, 136(r1), 0, qr0
/* 8024036C  DB C1 00 70 */	stfd f30, 0x70(r1)
/* 80240370  F3 C1 00 78 */	psq_st f30, 120(r1), 0, qr0
/* 80240374  39 61 00 70 */	addi r11, r1, 0x70
/* 80240378  4B DE 12 15 */	bl -0x21edec
/* 8024037C  3C 00 43 30 */	lis r0, 0x4330
/* 80240380  7C 76 1B 78 */	mr r22, r3
/* 80240384  3F C0 80 38 */	lis r30, 0x8038
/* 80240388  90 01 00 10 */	stw r0, 0x10(r1)
/* 8024038C  80 6D A2 80 */	lwz r3, -0x5d80(r13)
/* 80240390  7C 98 23 78 */	mr r24, r4
/* 80240394  90 01 00 18 */	stw r0, 0x18(r1)
/* 80240398  7C B9 2B 78 */	mr r25, r5
/* 8024039C  3B DE 44 80 */	addi r30, r30, 0x4480
/* 802403A0  4B FF D8 39 */	bl -0x27c8
/* 802403A4  1F 96 00 0C */	mulli r28, r22, 0xc
/* 802403A8  3B FE 00 00 */	addi r31, r30, 0
/* 802403AC  7C 7D 1B 78 */	mr r29, r3
/* 802403B0  7C 1F E0 2E */	lwzx r0, r31, r28
/* 802403B4  2C 00 00 00 */	cmpwi r0, 0
/* 802403B8  40 82 04 60 */	bne 0x460
/* 802403BC  28 16 00 01 */	cmplwi r22, 1
/* 802403C0  C3 E3 00 00 */	lfs f31, 0(r3)
/* 802403C4  C3 C3 00 04 */	lfs f30, 4(r3)
/* 802403C8  3B 60 00 00 */	li r27, 0
/* 802403CC  3B 40 00 01 */	li r26, 1
/* 802403D0  40 81 00 18 */	ble 0x18
/* 802403D4  2C 16 00 02 */	cmpwi r22, 2
/* 802403D8  41 82 02 00 */	beq 0x200
/* 802403DC  2C 16 00 03 */	cmpwi r22, 3
/* 802403E0  41 82 02 94 */	beq 0x294
/* 802403E4  48 00 03 80 */	b 0x380
/* 802403E8  2C 16 00 00 */	cmpwi r22, 0
/* 802403EC  40 82 00 0C */	bne 0xc
/* 802403F0  C0 62 A1 1C */	lfs f3, -0x5ee4(r2)
/* 802403F4  48 00 00 08 */	b 0x8
/* 802403F8  C0 62 A1 20 */	lfs f3, -0x5ee0(r2)
/* 802403FC  C0 03 00 08 */	lfs f0, 8(r3)
/* 80240400  38 9E 00 30 */	addi r4, r30, 0x30
/* 80240404  A0 AD A3 48 */	lhz r5, -0x5cb8(r13)
/* 80240408  38 DE 00 48 */	addi r6, r30, 0x48
/* 8024040C  EC 20 00 F2 */	fmuls f1, f0, f3
/* 80240410  C8 E2 A1 30 */	lfd f7, -0x5ed0(r2)
/* 80240414  20 A5 02 80 */	subfic r5, r5, 0x280
/* 80240418  A0 0D A3 4A */	lhz r0, -0x5cb6(r13)
/* 8024041C  D0 24 00 08 */	stfs f1, 8(r4)
/* 80240420  FC 40 08 1E */	fctiwz f2, f1
/* 80240424  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 80240428  20 00 02 10 */	subfic r0, r0, 0x210
/* 8024042C  D8 41 00 20 */	stfd f2, 0x20(r1)
/* 80240430  6C A3 80 00 */	xoris r3, r5, 0x8000
/* 80240434  EC 00 00 F2 */	fmuls f0, f0, f3
/* 80240438  D8 41 00 28 */	stfd f2, 0x28(r1)
/* 8024043C  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80240440  81 21 00 24 */	lwz r9, 0x24(r1)
/* 80240444  FC 00 00 1E */	fctiwz f0, f0
/* 80240448  80 A1 00 2C */	lwz r5, 0x2c(r1)
/* 8024044C  C0 22 A1 24 */	lfs f1, -0x5edc(r2)
/* 80240450  D8 01 00 38 */	stfd f0, 0x38(r1)
/* 80240454  54 A8 0F FE */	srwi r8, r5, 0x1f
/* 80240458  54 A5 07 FE */	clrlwi r5, r5, 0x1f
/* 8024045C  7C A7 42 78 */	xor r7, r5, r8
/* 80240460  80 A1 00 3C */	lwz r5, 0x3c(r1)
/* 80240464  7C E8 38 50 */	subf r7, r8, r7
/* 80240468  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 8024046C  7D 09 3A 14 */	add r8, r9, r7
/* 80240470  C0 62 A1 28 */	lfs f3, -0x5ed8(r2)
/* 80240474  54 A7 0F FE */	srwi r7, r5, 0x1f
/* 80240478  54 A5 07 FE */	clrlwi r5, r5, 0x1f
/* 8024047C  7C A5 3A 78 */	xor r5, r5, r7
/* 80240480  6D 08 80 00 */	xoris r8, r8, 0x8000
/* 80240484  7C A7 28 50 */	subf r5, r7, r5
/* 80240488  80 E1 00 34 */	lwz r7, 0x34(r1)
/* 8024048C  91 01 00 14 */	stw r8, 0x14(r1)
/* 80240490  7C A7 2A 14 */	add r5, r7, r5
/* 80240494  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 80240498  C8 41 00 10 */	lfd f2, 0x10(r1)
/* 8024049C  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 802404A0  90 A1 00 1C */	stw r5, 0x1c(r1)
/* 802404A4  EC C2 38 28 */	fsubs f6, f2, f7
/* 802404A8  C8 41 00 18 */	lfd f2, 0x18(r1)
/* 802404AC  90 61 00 14 */	stw r3, 0x14(r1)
/* 802404B0  EC A2 38 28 */	fsubs f5, f2, f7
/* 802404B4  EC 81 30 28 */	fsubs f4, f1, f6
/* 802404B8  90 01 00 1C */	stw r0, 0x1c(r1)
/* 802404BC  C8 41 00 10 */	lfd f2, 0x10(r1)
/* 802404C0  C8 21 00 18 */	lfd f1, 0x18(r1)
/* 802404C4  EC 63 28 28 */	fsubs f3, f3, f5
/* 802404C8  EC 42 38 28 */	fsubs f2, f2, f7
/* 802404CC  EC 21 38 28 */	fsubs f1, f1, f7
/* 802404D0  D0 C4 00 08 */	stfs f6, 8(r4)
/* 802404D4  EC 46 10 28 */	fsubs f2, f6, f2
/* 802404D8  D0 A4 00 0C */	stfs f5, 0xc(r4)
/* 802404DC  EC 25 08 28 */	fsubs f1, f5, f1
/* 802404E0  D0 9E 00 30 */	stfs f4, 0x30(r30)
/* 802404E4  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 802404E8  D0 9E 00 48 */	stfs f4, 0x48(r30)
/* 802404EC  D0 64 00 04 */	stfs f3, 4(r4)
/* 802404F0  D0 66 00 04 */	stfs f3, 4(r6)
/* 802404F4  D0 46 00 08 */	stfs f2, 8(r6)
/* 802404F8  D0 26 00 0C */	stfs f1, 0xc(r6)
/* 802404FC  40 80 00 08 */	bge 0x8
/* 80240500  D0 06 00 08 */	stfs f0, 8(r6)
/* 80240504  38 7E 00 48 */	addi r3, r30, 0x48
/* 80240508  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 8024050C  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 80240510  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80240514  40 80 00 08 */	bge 0x8
/* 80240518  D0 03 00 0C */	stfs f0, 0xc(r3)
/* 8024051C  38 7E 00 48 */	addi r3, r30, 0x48
/* 80240520  38 9E 00 30 */	addi r4, r30, 0x30
/* 80240524  C0 03 00 08 */	lfs f0, 8(r3)
/* 80240528  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 8024052C  FC 00 00 1E */	fctiwz f0, f0
/* 80240530  C3 FE 00 30 */	lfs f31, 0x30(r30)
/* 80240534  FC 20 08 1E */	fctiwz f1, f1
/* 80240538  C3 C4 00 04 */	lfs f30, 4(r4)
/* 8024053C  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 80240540  83 41 00 34 */	lwz r26, 0x34(r1)
/* 80240544  D8 21 00 38 */	stfd f1, 0x38(r1)
/* 80240548  57 40 04 3F */	clrlwi. r0, r26, 0x10
/* 8024054C  83 A1 00 3C */	lwz r29, 0x3c(r1)
/* 80240550  41 82 00 0C */	beq 0xc
/* 80240554  57 A0 04 3F */	clrlwi. r0, r29, 0x10
/* 80240558  40 82 00 0C */	bne 0xc
/* 8024055C  3B 40 00 00 */	li r26, 0
/* 80240560  48 00 00 50 */	b 0x50
/* 80240564  48 00 2C 11 */	bl 0x2c10
/* 80240568  B3 43 00 00 */	sth r26, 0(r3)
/* 8024056C  38 00 00 06 */	li r0, 6
/* 80240570  7C 7A 1B 78 */	mr r26, r3
/* 80240574  B3 A3 00 02 */	sth r29, 2(r3)
/* 80240578  98 03 00 05 */	stb r0, 5(r3)
/* 8024057C  81 83 00 10 */	lwz r12, 0x10(r3)
/* 80240580  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80240584  7D 89 03 A6 */	mtctr r12
/* 80240588  4E 80 04 21 */	bctrl
/* 8024058C  A0 7A 00 00 */	lhz r3, 0(r26)
/* 80240590  38 C0 00 00 */	li r6, 0
/* 80240594  A0 9A 00 02 */	lhz r4, 2(r26)
/* 80240598  38 E0 00 01 */	li r7, 1
/* 8024059C  88 BA 00 05 */	lbz r5, 5(r26)
/* 802405A0  4B F3 00 75 */	bl -0xcff8c
/* 802405A4  7C 64 1B 78 */	mr r4, r3
/* 802405A8  7F 43 D3 78 */	mr r3, r26
/* 802405AC  48 00 2B F1 */	bl 0x2bf0
/* 802405B0  38 7E 00 00 */	addi r3, r30, 0
/* 802405B4  2C 1A 00 00 */	cmpwi r26, 0
/* 802405B8  7F 43 E1 2E */	stwx r26, r3, r28
/* 802405BC  41 82 00 10 */	beq 0x10
/* 802405C0  88 1A 00 14 */	lbz r0, 0x14(r26)
/* 802405C4  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 802405C8  98 1A 00 14 */	stb r0, 0x14(r26)
/* 802405CC  48 00 08 35 */	bl 0x834
/* 802405D0  7C 7A 1B 78 */	mr r26, r3
/* 802405D4  48 00 01 90 */	b 0x190
/* 802405D8  C0 03 00 08 */	lfs f0, 8(r3)
/* 802405DC  C0 23 00 0C */	lfs f1, 0xc(r3)
/* 802405E0  FC 00 00 1E */	fctiwz f0, f0
/* 802405E4  FC 20 08 1E */	fctiwz f1, f1
/* 802405E8  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 802405EC  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 802405F0  D8 21 00 38 */	stfd f1, 0x38(r1)
/* 802405F4  57 A0 04 3F */	clrlwi. r0, r29, 0x10
/* 802405F8  82 E1 00 3C */	lwz r23, 0x3c(r1)
/* 802405FC  41 82 00 0C */	beq 0xc
/* 80240600  56 E0 04 3F */	clrlwi. r0, r23, 0x10
/* 80240604  40 82 00 0C */	bne 0xc
/* 80240608  3B A0 00 00 */	li r29, 0
/* 8024060C  48 00 00 50 */	b 0x50
/* 80240610  48 00 2B 65 */	bl 0x2b64
/* 80240614  B3 A3 00 00 */	sth r29, 0(r3)
/* 80240618  38 00 00 06 */	li r0, 6
/* 8024061C  7C 7D 1B 78 */	mr r29, r3
/* 80240620  B2 E3 00 02 */	sth r23, 2(r3)
/* 80240624  98 03 00 05 */	stb r0, 5(r3)
/* 80240628  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8024062C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80240630  7D 89 03 A6 */	mtctr r12
/* 80240634  4E 80 04 21 */	bctrl
/* 80240638  A0 7D 00 00 */	lhz r3, 0(r29)
/* 8024063C  38 C0 00 00 */	li r6, 0
/* 80240640  A0 9D 00 02 */	lhz r4, 2(r29)
/* 80240644  38 E0 00 01 */	li r7, 1
/* 80240648  88 BD 00 05 */	lbz r5, 5(r29)
/* 8024064C  4B F2 FF C9 */	bl -0xd0038
/* 80240650  7C 64 1B 78 */	mr r4, r3
/* 80240654  7F A3 EB 78 */	mr r3, r29
/* 80240658  48 00 2B 45 */	bl 0x2b44
/* 8024065C  38 7E 00 00 */	addi r3, r30, 0
/* 80240660  7F A3 E1 2E */	stwx r29, r3, r28
/* 80240664  88 1D 00 14 */	lbz r0, 0x14(r29)
/* 80240668  54 00 07 34 */	rlwinm r0, r0, 0, 0x1c, 0x1a
/* 8024066C  98 1D 00 14 */	stb r0, 0x14(r29)
/* 80240670  48 00 00 F4 */	b 0xf4
/* 80240674  48 00 07 99 */	bl 0x798
/* 80240678  2C 03 00 00 */	cmpwi r3, 0
/* 8024067C  3B 60 00 06 */	li r27, 6
/* 80240680  41 82 00 08 */	beq 0x8
/* 80240684  3B 60 00 04 */	li r27, 4
/* 80240688  C0 22 A1 20 */	lfs f1, -0x5ee0(r2)
/* 8024068C  C0 1D 00 08 */	lfs f0, 8(r29)
/* 80240690  C0 5D 00 0C */	lfs f2, 0xc(r29)
/* 80240694  EC 00 00 72 */	fmuls f0, f0, f1
/* 80240698  EC 22 00 72 */	fmuls f1, f2, f1
/* 8024069C  FC 00 00 1E */	fctiwz f0, f0
/* 802406A0  FC 20 08 1E */	fctiwz f1, f1
/* 802406A4  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 802406A8  82 E1 00 34 */	lwz r23, 0x34(r1)
/* 802406AC  D8 21 00 38 */	stfd f1, 0x38(r1)
/* 802406B0  56 E0 04 3F */	clrlwi. r0, r23, 0x10
/* 802406B4  82 C1 00 3C */	lwz r22, 0x3c(r1)
/* 802406B8  41 82 00 0C */	beq 0xc
/* 802406BC  56 C0 04 3F */	clrlwi. r0, r22, 0x10
/* 802406C0  40 82 00 0C */	bne 0xc
/* 802406C4  3B A0 00 00 */	li r29, 0
/* 802406C8  48 00 00 4C */	b 0x4c
/* 802406CC  48 00 2A A9 */	bl 0x2aa8
/* 802406D0  B2 E3 00 00 */	sth r23, 0(r3)
/* 802406D4  7C 7D 1B 78 */	mr r29, r3
/* 802406D8  B2 C3 00 02 */	sth r22, 2(r3)
/* 802406DC  9B 63 00 05 */	stb r27, 5(r3)
/* 802406E0  81 83 00 10 */	lwz r12, 0x10(r3)
/* 802406E4  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 802406E8  7D 89 03 A6 */	mtctr r12
/* 802406EC  4E 80 04 21 */	bctrl
/* 802406F0  A0 7D 00 00 */	lhz r3, 0(r29)
/* 802406F4  38 C0 00 00 */	li r6, 0
/* 802406F8  A0 9D 00 02 */	lhz r4, 2(r29)
/* 802406FC  38 E0 00 01 */	li r7, 1
/* 80240700  88 BD 00 05 */	lbz r5, 5(r29)
/* 80240704  4B F2 FF 11 */	bl -0xd00f0
/* 80240708  7C 64 1B 78 */	mr r4, r3
/* 8024070C  7F A3 EB 78 */	mr r3, r29
/* 80240710  48 00 2A 8D */	bl 0x2a8c
/* 80240714  38 7E 00 00 */	addi r3, r30, 0
/* 80240718  88 82 9B 18 */	lbz r4, -0x64e8(r2)
/* 8024071C  7F A3 E1 2E */	stwx r29, r3, r28
/* 80240720  3B 60 00 01 */	li r27, 1
/* 80240724  88 62 9B 19 */	lbz r3, -0x64e7(r2)
/* 80240728  88 BD 00 14 */	lbz r5, 0x14(r29)
/* 8024072C  88 02 9B 1A */	lbz r0, -0x64e6(r2)
/* 80240730  60 A5 00 08 */	ori r5, r5, 8
/* 80240734  98 BD 00 14 */	stb r5, 0x14(r29)
/* 80240738  88 A2 9B 1B */	lbz r5, -0x64e5(r2)
/* 8024073C  98 9D 00 20 */	stb r4, 0x20(r29)
/* 80240740  88 82 9B 1C */	lbz r4, -0x64e4(r2)
/* 80240744  98 7D 00 21 */	stb r3, 0x21(r29)
/* 80240748  88 62 9B 1D */	lbz r3, -0x64e3(r2)
/* 8024074C  98 1D 00 22 */	stb r0, 0x22(r29)
/* 80240750  88 02 9B 1E */	lbz r0, -0x64e2(r2)
/* 80240754  98 BD 00 23 */	stb r5, 0x23(r29)
/* 80240758  98 9D 00 24 */	stb r4, 0x24(r29)
/* 8024075C  98 7D 00 25 */	stb r3, 0x25(r29)
/* 80240760  98 1D 00 26 */	stb r0, 0x26(r29)
/* 80240764  7C 1F E0 2E */	lwzx r0, r31, r28
/* 80240768  2C 00 00 00 */	cmpwi r0, 0
/* 8024076C  41 82 00 AC */	beq 0xac
/* 80240770  38 1E 00 00 */	addi r0, r30, 0
/* 80240774  2C 18 00 00 */	cmpwi r24, 0
/* 80240778  7C A0 E2 14 */	add r5, r0, r28
/* 8024077C  93 25 00 04 */	stw r25, 4(r5)
/* 80240780  41 82 00 40 */	beq 0x40
/* 80240784  80 85 00 00 */	lwz r4, 0(r5)
/* 80240788  38 00 00 00 */	li r0, 0
/* 8024078C  90 01 00 08 */	stw r0, 8(r1)
/* 80240790  88 64 00 14 */	lbz r3, 0x14(r4)
/* 80240794  88 01 00 08 */	lbz r0, 8(r1)
/* 80240798  60 63 00 02 */	ori r3, r3, 2
/* 8024079C  98 64 00 14 */	stb r3, 0x14(r4)
/* 802407A0  88 81 00 09 */	lbz r4, 9(r1)
/* 802407A4  80 A5 00 00 */	lwz r5, 0(r5)
/* 802407A8  88 61 00 0A */	lbz r3, 0xa(r1)
/* 802407AC  98 05 00 15 */	stb r0, 0x15(r5)
/* 802407B0  88 01 00 0B */	lbz r0, 0xb(r1)
/* 802407B4  98 85 00 16 */	stb r4, 0x16(r5)
/* 802407B8  98 65 00 17 */	stb r3, 0x17(r5)
/* 802407BC  98 05 00 18 */	stb r0, 0x18(r5)
/* 802407C0  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 802407C4  FC 1F 00 40 */	fcmpo cr0, f31, f0
/* 802407C8  40 80 00 08 */	bge 0x8
/* 802407CC  FF E0 00 90 */	fmr f31, f0
/* 802407D0  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 802407D4  FC 1E 00 40 */	fcmpo cr0, f30, f0
/* 802407D8  40 80 00 08 */	bge 0x8
/* 802407DC  FF C0 00 90 */	fmr f30, f0
/* 802407E0  2C 1A 00 00 */	cmpwi r26, 0
/* 802407E4  41 82 00 34 */	beq 0x34
/* 802407E8  FC 20 F8 1E */	fctiwz f1, f31
/* 802407EC  7C 7F E0 2E */	lwzx r3, r31, r28
/* 802407F0  FC 00 F0 1E */	fctiwz f0, f30
/* 802407F4  7F 66 DB 78 */	mr r6, r27
/* 802407F8  D8 21 00 38 */	stfd f1, 0x38(r1)
/* 802407FC  38 E0 FF FF */	li r7, -1
/* 80240800  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 80240804  80 81 00 3C */	lwz r4, 0x3c(r1)
/* 80240808  80 A1 00 34 */	lwz r5, 0x34(r1)
/* 8024080C  54 84 04 3E */	clrlwi r4, r4, 0x10
/* 80240810  54 A5 04 3E */	clrlwi r5, r5, 0x10
/* 80240814  4B FD 44 61 */	bl -0x2bba0
/* 80240818  7C 7F E0 2E */	lwzx r3, r31, r28
/* 8024081C  E3 E1 00 88 */	psq_l f31, 136(r1), 0, qr0
/* 80240820  CB E1 00 80 */	lfd f31, 0x80(r1)
/* 80240824  E3 C1 00 78 */	psq_l f30, 120(r1), 0, qr0
/* 80240828  CB C1 00 70 */	lfd f30, 0x70(r1)
/* 8024082C  39 61 00 70 */	addi r11, r1, 0x70
/* 80240830  4B DE 0D A9 */	bl -0x21f258
/* 80240834  80 01 00 94 */	lwz r0, 0x94(r1)
/* 80240838  7C 08 03 A6 */	mtlr r0
/* 8024083C  38 21 00 90 */	addi r1, r1, 0x90
/* 80240840  4E 80 00 20 */	blr
/* 80240844  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80240848  7C 08 02 A6 */	mflr r0
/* 8024084C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80240850  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80240854  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80240858  3F C0 80 38 */	lis r30, 0x8038
/* 8024085C  3B DE 44 80 */	addi r30, r30, 0x4480
/* 80240860  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80240864  1F A3 00 0C */	mulli r29, r3, 0xc
/* 80240868  7C 7E E8 2E */	lwzx r3, r30, r29
/* 8024086C  2C 03 00 00 */	cmpwi r3, 0
/* 80240870  41 82 00 30 */	beq 0x30
/* 80240874  7F FE EA 14 */	add r31, r30, r29
/* 80240878  80 1F 00 04 */	lwz r0, 4(r31)
/* 8024087C  7C 04 00 40 */	cmplw r4, r0
/* 80240880  40 82 00 20 */	bne 0x20
/* 80240884  48 00 27 0D */	bl 0x270c
/* 80240888  38 00 00 00 */	li r0, 0
/* 8024088C  7C 1E E9 2E */	stwx r0, r30, r29
/* 80240890  38 60 00 01 */	li r3, 1
/* 80240894  90 1F 00 04 */	stw r0, 4(r31)
/* 80240898  90 1F 00 08 */	stw r0, 8(r31)
/* 8024089C  48 00 00 08 */	b 0x8
/* 802408A0  38 60 00 00 */	li r3, 0
/* 802408A4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802408A8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802408AC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802408B0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802408B4  7C 08 03 A6 */	mtlr r0
/* 802408B8  38 21 00 20 */	addi r1, r1, 0x20
/* 802408BC  4E 80 00 20 */	blr
/* 802408C0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802408C4  7C 08 02 A6 */	mflr r0
/* 802408C8  2C 03 00 00 */	cmpwi r3, 0
/* 802408CC  90 01 00 24 */	stw r0, 0x24(r1)
/* 802408D0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802408D4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802408D8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802408DC  7C 9D 23 78 */	mr r29, r4
/* 802408E0  40 82 00 60 */	bne 0x60
/* 802408E4  80 0D 93 B4 */	lwz r0, -0x6c4c(r13)
/* 802408E8  2C 00 00 01 */	cmpwi r0, 1
/* 802408EC  40 82 00 38 */	bne 0x38
/* 802408F0  3F C0 80 38 */	lis r30, 0x8038
/* 802408F4  80 7E 44 80 */	lwz r3, 0x4480(r30)
/* 802408F8  3B FE 44 80 */	addi r31, r30, 0x4480
/* 802408FC  80 1F 00 04 */	lwz r0, 4(r31)
/* 80240900  2C 03 00 00 */	cmpwi r3, 0
/* 80240904  41 82 00 20 */	beq 0x20
/* 80240908  7C 00 00 40 */	cmplw r0, r0
/* 8024090C  40 82 00 18 */	bne 0x18
/* 80240910  48 00 26 81 */	bl 0x2680
/* 80240914  38 00 00 00 */	li r0, 0
/* 80240918  90 1E 44 80 */	stw r0, 0x4480(r30)
/* 8024091C  90 1F 00 04 */	stw r0, 4(r31)
/* 80240920  90 1F 00 08 */	stw r0, 8(r31)
/* 80240924  7F A5 EB 78 */	mr r5, r29
/* 80240928  38 60 00 01 */	li r3, 1
/* 8024092C  38 80 00 00 */	li r4, 0
/* 80240930  4B FF FA 29 */	bl -0x5d8
/* 80240934  38 00 00 00 */	li r0, 0
/* 80240938  90 0D 93 B4 */	stw r0, -0x6c4c(r13)
/* 8024093C  48 00 00 30 */	b 0x30
/* 80240940  2C 03 00 01 */	cmpwi r3, 1
/* 80240944  40 82 00 28 */	bne 0x28
/* 80240948  80 0D 93 B4 */	lwz r0, -0x6c4c(r13)
/* 8024094C  2C 00 00 00 */	cmpwi r0, 0
/* 80240950  41 82 00 1C */	beq 0x1c
/* 80240954  7F A5 EB 78 */	mr r5, r29
/* 80240958  38 60 00 00 */	li r3, 0
/* 8024095C  38 80 00 00 */	li r4, 0
/* 80240960  4B FF F9 F9 */	bl -0x608
/* 80240964  38 00 00 01 */	li r0, 1
/* 80240968  90 0D 93 B4 */	stw r0, -0x6c4c(r13)
/* 8024096C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80240970  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80240974  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80240978  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 8024097C  7C 08 03 A6 */	mtlr r0
/* 80240980  38 21 00 20 */	addi r1, r1, 0x20
/* 80240984  4E 80 00 20 */	blr
/* 80240988  94 21 FE F0 */	stwu r1, -0x110(r1)
/* 8024098C  7C 08 02 A6 */	mflr r0
/* 80240990  90 01 01 14 */	stw r0, 0x114(r1)
/* 80240994  39 61 01 10 */	addi r11, r1, 0x110
/* 80240998  4B DE 0B F5 */	bl -0x21f40c
/* 8024099C  80 0D 93 B4 */	lwz r0, -0x6c4c(r13)
/* 802409A0  2C 00 FF FF */	cmpwi r0, -1
/* 802409A4  41 82 02 BC */	beq 0x2bc
/* 802409A8  2C 00 00 00 */	cmpwi r0, 0
/* 802409AC  38 A0 FF FF */	li r5, -1
/* 802409B0  40 82 00 0C */	bne 0xc
/* 802409B4  38 A0 00 01 */	li r5, 1
/* 802409B8  48 00 00 10 */	b 0x10
/* 802409BC  2C 00 00 01 */	cmpwi r0, 1
/* 802409C0  40 82 00 08 */	bne 0x8
/* 802409C4  38 A0 00 00 */	li r5, 0
/* 802409C8  1F 45 00 0C */	mulli r26, r5, 0xc
/* 802409CC  3C A0 80 38 */	lis r5, 0x8038
/* 802409D0  38 A5 44 80 */	addi r5, r5, 0x4480
/* 802409D4  7F E5 D2 14 */	add r31, r5, r26
/* 802409D8  80 1F 00 04 */	lwz r0, 4(r31)
/* 802409DC  7C 04 00 40 */	cmplw r4, r0
/* 802409E0  40 82 02 80 */	bne 0x280
/* 802409E4  2C 03 00 00 */	cmpwi r3, 0
/* 802409E8  40 82 02 38 */	bne 0x238
/* 802409EC  3E E0 80 38 */	lis r23, 0x8038
/* 802409F0  38 60 00 01 */	li r3, 1
/* 802409F4  3A F7 45 20 */	addi r23, r23, 0x4520
/* 802409F8  8B D7 00 0C */	lbz r30, 0xc(r23)
/* 802409FC  4B F3 1D D1 */	bl -0xce230
/* 80240A00  3A C0 00 01 */	li r22, 1
/* 80240A04  9A D7 00 0C */	stb r22, 0xc(r23)
/* 80240A08  8B B7 00 0D */	lbz r29, 0xd(r23)
/* 80240A0C  38 60 00 01 */	li r3, 1
/* 80240A10  4B F3 1D E9 */	bl -0xce218
/* 80240A14  9A D7 00 0D */	stb r22, 0xd(r23)
/* 80240A18  38 60 00 00 */	li r3, 0
/* 80240A1C  8B 97 00 0E */	lbz r28, 0xe(r23)
/* 80240A20  4B F3 1F 11 */	bl -0xce0f0
/* 80240A24  83 6D A2 80 */	lwz r27, -0x5d80(r13)
/* 80240A28  38 00 00 00 */	li r0, 0
/* 80240A2C  98 17 00 0E */	stb r0, 0xe(r23)
/* 80240A30  38 61 00 78 */	addi r3, r1, 0x78
/* 80240A34  7F 64 DB 78 */	mr r4, r27
/* 80240A38  4B FF CA 11 */	bl -0x35f0
/* 80240A3C  80 01 00 7C */	lwz r0, 0x7c(r1)
/* 80240A40  A0 61 00 AC */	lhz r3, 0xac(r1)
/* 80240A44  2C 00 00 01 */	cmpwi r0, 1
/* 80240A48  60 60 00 40 */	ori r0, r3, 0x40
/* 80240A4C  B0 01 00 AC */	sth r0, 0xac(r1)
/* 80240A50  41 82 00 10 */	beq 0x10
/* 80240A54  60 00 00 01 */	ori r0, r0, 1
/* 80240A58  B0 01 00 AC */	sth r0, 0xac(r1)
/* 80240A5C  92 C1 00 7C */	stw r22, 0x7c(r1)
/* 80240A60  C0 02 A1 38 */	lfs f0, -0x5ec8(r2)
/* 80240A64  3A C0 00 00 */	li r22, 0
/* 80240A68  C0 22 A1 18 */	lfs f1, -0x5ee8(r2)
/* 80240A6C  38 61 00 78 */	addi r3, r1, 0x78
/* 80240A70  92 C1 00 78 */	stw r22, 0x78(r1)
/* 80240A74  D0 21 00 90 */	stfs f1, 0x90(r1)
/* 80240A78  D0 01 00 94 */	stfs f0, 0x94(r1)
/* 80240A7C  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 80240A80  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 80240A84  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 80240A88  D0 01 00 A0 */	stfs f0, 0xa0(r1)
/* 80240A8C  D0 01 00 A4 */	stfs f0, 0xa4(r1)
/* 80240A90  D0 01 00 A8 */	stfs f0, 0xa8(r1)
/* 80240A94  D0 21 00 10 */	stfs f1, 0x10(r1)
/* 80240A98  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 80240A9C  D0 21 00 98 */	stfs f1, 0x98(r1)
/* 80240AA0  D0 21 00 9C */	stfs f1, 0x9c(r1)
/* 80240AA4  4B FF CA 45 */	bl -0x35bc
/* 80240AA8  3F 20 80 38 */	lis r25, 0x8038
/* 80240AAC  C0 A2 A1 18 */	lfs f5, -0x5ee8(r2)
/* 80240AB0  3B 19 44 C8 */	addi r24, r25, 0x44c8
/* 80240AB4  C0 39 44 C8 */	lfs f1, 0x44c8(r25)
/* 80240AB8  C0 58 00 04 */	lfs f2, 4(r24)
/* 80240ABC  C0 78 00 08 */	lfs f3, 8(r24)
/* 80240AC0  C0 98 00 0C */	lfs f4, 0xc(r24)
/* 80240AC4  C0 C2 A1 38 */	lfs f6, -0x5ec8(r2)
/* 80240AC8  48 00 0E 09 */	bl 0xe08
/* 80240ACC  C0 38 00 0C */	lfs f1, 0xc(r24)
/* 80240AD0  4B DE 09 A9 */	bl -0x21f658
/* 80240AD4  C0 38 00 08 */	lfs f1, 8(r24)
/* 80240AD8  7C 77 1B 78 */	mr r23, r3
/* 80240ADC  4B DE 09 9D */	bl -0x21f664
/* 80240AE0  C0 38 00 04 */	lfs f1, 4(r24)
/* 80240AE4  7C 78 1B 78 */	mr r24, r3
/* 80240AE8  4B DE 09 91 */	bl -0x21f670
/* 80240AEC  C0 39 44 C8 */	lfs f1, 0x44c8(r25)
/* 80240AF0  7C 79 1B 78 */	mr r25, r3
/* 80240AF4  4B DE 09 85 */	bl -0x21f67c
/* 80240AF8  7F 24 CB 78 */	mr r4, r25
/* 80240AFC  7F 05 C3 78 */	mr r5, r24
/* 80240B00  7E E6 BB 78 */	mr r6, r23
/* 80240B04  48 00 0E F9 */	bl 0xef8
/* 80240B08  38 60 00 00 */	li r3, 0
/* 80240B0C  38 80 00 00 */	li r4, 0
/* 80240B10  48 00 0F BD */	bl 0xfbc
/* 80240B14  C0 3B 00 08 */	lfs f1, 8(r27)
/* 80240B18  38 61 00 48 */	addi r3, r1, 0x48
/* 80240B1C  C0 5B 00 0C */	lfs f2, 0xc(r27)
/* 80240B20  C0 62 A1 38 */	lfs f3, -0x5ec8(r2)
/* 80240B24  4B F5 99 3D */	bl -0xa66c4
/* 80240B28  48 00 02 D9 */	bl 0x2d8
/* 80240B2C  7C 64 1B 78 */	mr r4, r3
/* 80240B30  38 60 00 01 */	li r3, 1
/* 80240B34  38 A0 00 00 */	li r5, 0
/* 80240B38  4B FD 9A C9 */	bl -0x26538
/* 80240B3C  38 60 00 0C */	li r3, 0xc
/* 80240B40  4B FD B5 D9 */	bl -0x24a28
/* 80240B44  48 00 02 BD */	bl 0x2bc
/* 80240B48  2C 03 00 00 */	cmpwi r3, 0
/* 80240B4C  41 82 00 78 */	beq 0x78
/* 80240B50  3C 60 80 38 */	lis r3, 0x8038
/* 80240B54  38 63 44 80 */	addi r3, r3, 0x4480
/* 80240B58  7E E3 D0 2E */	lwzx r23, r3, r26
/* 80240B5C  9A D7 00 08 */	stb r22, 8(r23)
/* 80240B60  9A D7 00 09 */	stb r22, 9(r23)
/* 80240B64  4B FD 9A 1D */	bl -0x265e4
/* 80240B68  81 97 00 10 */	lwz r12, 0x10(r23)
/* 80240B6C  7C 76 1B 78 */	mr r22, r3
/* 80240B70  7E E3 BB 78 */	mr r3, r23
/* 80240B74  38 81 00 28 */	addi r4, r1, 0x28
/* 80240B78  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80240B7C  7D 89 03 A6 */	mtctr r12
/* 80240B80  4E 80 04 21 */	bctrl
/* 80240B84  7E C4 B3 78 */	mr r4, r22
/* 80240B88  38 61 00 28 */	addi r3, r1, 0x28
/* 80240B8C  4B F3 03 A1 */	bl -0xcfc60
/* 80240B90  89 02 9B A4 */	lbz r8, -0x645c(r2)
/* 80240B94  38 81 00 48 */	addi r4, r1, 0x48
/* 80240B98  88 E2 9B A5 */	lbz r7, -0x645b(r2)
/* 80240B9C  38 A1 00 0C */	addi r5, r1, 0xc
/* 80240BA0  88 C2 9B A6 */	lbz r6, -0x645a(r2)
/* 80240BA4  38 60 00 10 */	li r3, 0x10
/* 80240BA8  88 02 9B A7 */	lbz r0, -0x6459(r2)
/* 80240BAC  99 01 00 0C */	stb r8, 0xc(r1)
/* 80240BB0  98 E1 00 0D */	stb r7, 0xd(r1)
/* 80240BB4  98 C1 00 0E */	stb r6, 0xe(r1)
/* 80240BB8  98 01 00 0F */	stb r0, 0xf(r1)
/* 80240BBC  4B FD B4 9D */	bl -0x24b64
/* 80240BC0  48 00 00 34 */	b 0x34
/* 80240BC4  89 0D A3 5C */	lbz r8, -0x5ca4(r13)
/* 80240BC8  38 81 00 48 */	addi r4, r1, 0x48
/* 80240BCC  88 ED A3 5D */	lbz r7, -0x5ca3(r13)
/* 80240BD0  38 A1 00 08 */	addi r5, r1, 8
/* 80240BD4  88 CD A3 5E */	lbz r6, -0x5ca2(r13)
/* 80240BD8  38 60 00 11 */	li r3, 0x11
/* 80240BDC  88 0D A3 5F */	lbz r0, -0x5ca1(r13)
/* 80240BE0  99 01 00 08 */	stb r8, 8(r1)
/* 80240BE4  98 E1 00 09 */	stb r7, 9(r1)
/* 80240BE8  98 C1 00 0A */	stb r6, 0xa(r1)
/* 80240BEC  98 01 00 0B */	stb r0, 0xb(r1)
/* 80240BF0  4B FD B4 69 */	bl -0x24b98
/* 80240BF4  7F 83 E3 78 */	mr r3, r28
/* 80240BF8  4B F3 1D 39 */	bl -0xce2c8
/* 80240BFC  3F 60 80 38 */	lis r27, 0x8038
/* 80240C00  7F A3 EB 78 */	mr r3, r29
/* 80240C04  3B 7B 45 20 */	addi r27, r27, 0x4520
/* 80240C08  9B 9B 00 0E */	stb r28, 0xe(r27)
/* 80240C0C  4B F3 1B ED */	bl -0xce414
/* 80240C10  9B BB 00 0D */	stb r29, 0xd(r27)
/* 80240C14  7F C3 F3 78 */	mr r3, r30
/* 80240C18  4B F3 1B B5 */	bl -0xce44c
/* 80240C1C  9B DB 00 0C */	stb r30, 0xc(r27)
/* 80240C20  3F 60 80 38 */	lis r27, 0x8038
/* 80240C24  3B 7B 44 80 */	addi r27, r27, 0x4480
/* 80240C28  7C 7B D0 2E */	lwzx r3, r27, r26
/* 80240C2C  2C 03 00 00 */	cmpwi r3, 0
/* 80240C30  41 82 00 1C */	beq 0x1c
/* 80240C34  48 00 23 5D */	bl 0x235c
/* 80240C38  38 00 00 00 */	li r0, 0
/* 80240C3C  7C 1B D1 2E */	stwx r0, r27, r26
/* 80240C40  7C 7B D2 14 */	add r3, r27, r26
/* 80240C44  90 1F 00 04 */	stw r0, 4(r31)
/* 80240C48  90 03 00 08 */	stw r0, 8(r3)
/* 80240C4C  80 6D A3 40 */	lwz r3, -0x5cc0(r13)
/* 80240C50  38 00 FF FF */	li r0, -1
/* 80240C54  90 0D 93 B4 */	stw r0, -0x6c4c(r13)
/* 80240C58  38 03 00 01 */	addi r0, r3, 1
/* 80240C5C  90 0D A3 40 */	stw r0, -0x5cc0(r13)
/* 80240C60  39 61 01 10 */	addi r11, r1, 0x110
/* 80240C64  4B DE 09 75 */	bl -0x21f68c
/* 80240C68  80 01 01 14 */	lwz r0, 0x114(r1)
/* 80240C6C  7C 08 03 A6 */	mtlr r0
/* 80240C70  38 21 01 10 */	addi r1, r1, 0x110
/* 80240C74  4E 80 00 20 */	blr
/* 80240C78  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80240C7C  7C 08 02 A6 */	mflr r0
/* 80240C80  90 01 00 34 */	stw r0, 0x34(r1)
/* 80240C84  3C 00 43 30 */	lis r0, 0x4330
/* 80240C88  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80240C8C  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80240C90  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80240C94  90 01 00 08 */	stw r0, 8(r1)
/* 80240C98  80 6D A2 80 */	lwz r3, -0x5d80(r13)
/* 80240C9C  90 01 00 10 */	stw r0, 0x10(r1)
/* 80240CA0  4B FF CF 39 */	bl -0x30c8
/* 80240CA4  3C A0 80 38 */	lis r5, 0x8038
/* 80240CA8  3F E0 80 38 */	lis r31, 0x8038
/* 80240CAC  38 85 44 B0 */	addi r4, r5, 0x44b0
/* 80240CB0  C0 25 44 B0 */	lfs f1, 0x44b0(r5)
/* 80240CB4  C0 44 00 04 */	lfs f2, 4(r4)
/* 80240CB8  38 9F 44 E0 */	addi r4, r31, 0x44e0
/* 80240CBC  D0 3F 44 E0 */	stfs f1, 0x44e0(r31)
/* 80240CC0  D0 44 00 04 */	stfs f2, 4(r4)
/* 80240CC4  C0 63 00 08 */	lfs f3, 8(r3)
/* 80240CC8  D0 64 00 08 */	stfs f3, 8(r4)
/* 80240CCC  C0 83 00 0C */	lfs f4, 0xc(r3)
/* 80240CD0  D0 84 00 0C */	stfs f4, 0xc(r4)
/* 80240CD4  C0 A3 00 10 */	lfs f5, 0x10(r3)
/* 80240CD8  D0 A4 00 10 */	stfs f5, 0x10(r4)
/* 80240CDC  C0 C3 00 14 */	lfs f6, 0x14(r3)
/* 80240CE0  D0 C4 00 14 */	stfs f6, 0x14(r4)
/* 80240CE4  48 00 0B ED */	bl 0xbec
/* 80240CE8  C0 3F 44 E0 */	lfs f1, 0x44e0(r31)
/* 80240CEC  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 80240CF0  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80240CF4  4C 41 13 82 */	cror 2, 1, 2
/* 80240CF8  40 82 00 08 */	bne 0x8
/* 80240CFC  48 00 00 08 */	b 0x8
/* 80240D00  FC 20 00 90 */	fmr f1, f0
/* 80240D04  4B DE 07 75 */	bl -0x21f88c
/* 80240D08  3C 80 80 38 */	lis r4, 0x8038
/* 80240D0C  C0 02 A1 18 */	lfs f0, -0x5ee8(r2)
/* 80240D10  38 84 44 E0 */	addi r4, r4, 0x44e0
/* 80240D14  7C 7F 1B 78 */	mr r31, r3
/* 80240D18  C0 24 00 04 */	lfs f1, 4(r4)
/* 80240D1C  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80240D20  4C 41 13 82 */	cror 2, 1, 2
/* 80240D24  40 82 00 08 */	bne 0x8
/* 80240D28  48 00 00 08 */	b 0x8
/* 80240D2C  FC 20 00 90 */	fmr f1, f0
/* 80240D30  4B DE 07 49 */	bl -0x21f8b8
/* 80240D34  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80240D38  3C 80 80 38 */	lis r4, 0x8038
/* 80240D3C  38 84 44 E0 */	addi r4, r4, 0x44e0
/* 80240D40  C8 62 A1 40 */	lfd f3, -0x5ec0(r2)
/* 80240D44  C8 01 00 08 */	lfd f0, 8(r1)
/* 80240D48  7C 7E 1B 78 */	mr r30, r3
/* 80240D4C  C0 24 00 08 */	lfs f1, 8(r4)
/* 80240D50  EC 40 18 28 */	fsubs f2, f0, f3
/* 80240D54  C0 02 A1 24 */	lfs f0, -0x5edc(r2)
/* 80240D58  EC 42 08 2A */	fadds f2, f2, f1
/* 80240D5C  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80240D60  40 81 00 14 */	ble 0x14
/* 80240D64  20 1F 02 80 */	subfic r0, r31, 0x280
/* 80240D68  90 01 00 14 */	stw r0, 0x14(r1)
/* 80240D6C  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 80240D70  EC 20 18 28 */	fsubs f1, f0, f3
/* 80240D74  4B DE 07 05 */	bl -0x21f8fc
/* 80240D78  93 C1 00 0C */	stw r30, 0xc(r1)
/* 80240D7C  3C 80 80 38 */	lis r4, 0x8038
/* 80240D80  38 84 44 E0 */	addi r4, r4, 0x44e0
/* 80240D84  C8 62 A1 40 */	lfd f3, -0x5ec0(r2)
/* 80240D88  C8 01 00 08 */	lfd f0, 8(r1)
/* 80240D8C  7C 7D 1B 78 */	mr r29, r3
/* 80240D90  C0 24 00 0C */	lfs f1, 0xc(r4)
/* 80240D94  EC 40 18 28 */	fsubs f2, f0, f3
/* 80240D98  C0 02 A1 28 */	lfs f0, -0x5ed8(r2)
/* 80240D9C  EC 42 08 2A */	fadds f2, f2, f1
/* 80240DA0  FC 02 00 40 */	fcmpo cr0, f2, f0
/* 80240DA4  40 81 00 14 */	ble 0x14
/* 80240DA8  20 1E 02 10 */	subfic r0, r30, 0x210
/* 80240DAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80240DB0  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 80240DB4  EC 20 18 28 */	fsubs f1, f0, f3
/* 80240DB8  4B DE 06 C1 */	bl -0x21f940
/* 80240DBC  7C 66 1B 78 */	mr r6, r3
/* 80240DC0  7F E3 FB 78 */	mr r3, r31
/* 80240DC4  7F C4 F3 78 */	mr r4, r30
/* 80240DC8  7F A5 EB 78 */	mr r5, r29
/* 80240DCC  48 00 0C 31 */	bl 0xc30
/* 80240DD0  38 60 00 00 */	li r3, 0
/* 80240DD4  38 80 00 00 */	li r4, 0
/* 80240DD8  48 00 0C F5 */	bl 0xcf4
/* 80240DDC  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80240DE0  3C 60 80 38 */	lis r3, 0x8038
/* 80240DE4  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80240DE8  38 63 44 E0 */	addi r3, r3, 0x44e0
/* 80240DEC  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80240DF0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80240DF4  7C 08 03 A6 */	mtlr r0
/* 80240DF8  38 21 00 30 */	addi r1, r1, 0x30
/* 80240DFC  4E 80 00 20 */	blr
/* 80240E00  80 0D 93 B0 */	lwz r0, -0x6c50(r13)
/* 80240E04  54 03 F7 FE */	rlwinm r3, r0, 0x1e, 0x1f, 0x1f
/* 80240E08  4E 80 00 20 */	blr
/* 80240E0C  80 0D 93 B0 */	lwz r0, -0x6c50(r13)
/* 80240E10  54 03 EF FE */	rlwinm r3, r0, 0x1d, 0x1f, 0x1f
/* 80240E14  4E 80 00 20 */	blr
/* 80240E18  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80240E1C  7C 08 02 A6 */	mflr r0
/* 80240E20  3C 80 80 38 */	lis r4, 0x8038
/* 80240E24  38 A0 00 04 */	li r5, 4
/* 80240E28  90 01 00 14 */	stw r0, 0x14(r1)
/* 80240E2C  38 84 45 40 */	addi r4, r4, 0x4540
/* 80240E30  38 C0 00 04 */	li r6, 4
/* 80240E34  38 E0 00 03 */	li r7, 3
/* 80240E38  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80240E3C  3F E0 80 38 */	lis r31, 0x8038
/* 80240E40  38 7F 45 00 */	addi r3, r31, 0x4500
/* 80240E44  39 00 00 00 */	li r8, 0
/* 80240E48  39 20 00 00 */	li r9, 0
/* 80240E4C  39 40 00 00 */	li r10, 0
/* 80240E50  4B F2 F9 A9 */	bl -0xd0658
/* 80240E54  C0 22 A1 4C */	lfs f1, -0x5eb4(r2)
/* 80240E58  38 7F 45 00 */	addi r3, r31, 0x4500
/* 80240E5C  38 80 00 01 */	li r4, 1
/* 80240E60  38 A0 00 01 */	li r5, 1
/* 80240E64  FC 40 08 90 */	fmr f2, f1
/* 80240E68  38 C0 00 00 */	li r6, 0
/* 80240E6C  FC 60 08 90 */	fmr f3, f1
/* 80240E70  38 E0 00 00 */	li r7, 0
/* 80240E74  39 00 00 00 */	li r8, 0
/* 80240E78  4B F2 FB D5 */	bl -0xd042c
/* 80240E7C  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 80240E80  54 00 06 F2 */	rlwinm r0, r0, 0, 0x1b, 0x19
/* 80240E84  B0 0D 93 B8 */	sth r0, -0x6c48(r13)
/* 80240E88  4B F3 02 89 */	bl -0xcfd78
/* 80240E8C  48 00 00 29 */	bl 0x28
/* 80240E90  38 00 00 01 */	li r0, 1
/* 80240E94  90 0D 93 BC */	stw r0, -0x6c44(r13)
/* 80240E98  38 60 00 01 */	li r3, 1
/* 80240E9C  4B E1 FC 45 */	bl -0x1e03bc
/* 80240EA0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80240EA4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80240EA8  7C 08 03 A6 */	mtlr r0
/* 80240EAC  38 21 00 10 */	addi r1, r1, 0x10
/* 80240EB0  4E 80 00 20 */	blr
/* 80240EB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80240EB8  7C 08 02 A6 */	mflr r0
/* 80240EBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 80240EC0  80 6D A3 4C */	lwz r3, -0x5cb4(r13)
/* 80240EC4  80 8D A3 50 */	lwz r4, -0x5cb0(r13)
/* 80240EC8  48 00 07 A1 */	bl 0x7a0
/* 80240ECC  4B F2 D4 A1 */	bl -0xd2b60
/* 80240ED0  38 60 00 00 */	li r3, 0
/* 80240ED4  4B F3 23 41 */	bl -0xcdcc0
/* 80240ED8  38 60 00 00 */	li r3, 0
/* 80240EDC  4B F2 E5 05 */	bl -0xd1afc
/* 80240EE0  38 60 00 00 */	li r3, 0
/* 80240EE4  4B F3 26 39 */	bl -0xcd9c8
/* 80240EE8  48 00 00 81 */	bl 0x80
/* 80240EEC  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 80240EF0  54 00 06 B0 */	rlwinm r0, r0, 0, 0x1a, 0x18
/* 80240EF4  B0 0D 93 B8 */	sth r0, -0x6c48(r13)
/* 80240EF8  4B E3 62 C9 */	bl -0x1c9d38
/* 80240EFC  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 80240F00  54 00 06 F7 */	rlwinm. r0, r0, 0, 0x1b, 0x1b
/* 80240F04  41 82 00 0C */	beq 0xc
/* 80240F08  80 6D 93 BC */	lwz r3, -0x6c44(r13)
/* 80240F0C  4B E1 FB D5 */	bl -0x1e042c
/* 80240F10  80 6D A3 60 */	lwz r3, -0x5ca0(r13)
/* 80240F14  81 83 00 00 */	lwz r12, 0(r3)
/* 80240F18  81 8C 00 10 */	lwz r12, 0x10(r12)
/* 80240F1C  7D 89 03 A6 */	mtctr r12
/* 80240F20  4E 80 04 21 */	bctrl
/* 80240F24  88 E3 00 14 */	lbz r7, 0x14(r3)
/* 80240F28  38 8D A3 5C */	addi r4, r13, -23716
/* 80240F2C  88 C3 00 15 */	lbz r6, 0x15(r3)
/* 80240F30  88 A3 00 16 */	lbz r5, 0x16(r3)
/* 80240F34  88 03 00 17 */	lbz r0, 0x17(r3)
/* 80240F38  98 04 00 03 */	stb r0, 3(r4)
/* 80240F3C  98 ED A3 5C */	stb r7, -0x5ca4(r13)
/* 80240F40  98 C4 00 01 */	stb r6, 1(r4)
/* 80240F44  98 A4 00 02 */	stb r5, 2(r4)
/* 80240F48  98 01 00 0B */	stb r0, 0xb(r1)
/* 80240F4C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80240F50  98 E1 00 08 */	stb r7, 8(r1)
/* 80240F54  98 C1 00 09 */	stb r6, 9(r1)
/* 80240F58  98 A1 00 0A */	stb r5, 0xa(r1)
/* 80240F5C  7C 08 03 A6 */	mtlr r0
/* 80240F60  38 21 00 10 */	addi r1, r1, 0x10
/* 80240F64  4E 80 00 20 */	blr
/* 80240F68  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80240F6C  7C 08 02 A6 */	mflr r0
/* 80240F70  90 01 00 14 */	stw r0, 0x14(r1)
/* 80240F74  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 80240F78  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80240F7C  40 82 00 20 */	bne 0x20
/* 80240F80  48 00 00 31 */	bl 0x30
/* 80240F84  48 00 02 45 */	bl 0x244
/* 80240F88  48 00 01 65 */	bl 0x164
/* 80240F8C  48 00 02 B5 */	bl 0x2b4
/* 80240F90  48 00 03 39 */	bl 0x338
/* 80240F94  48 00 03 ED */	bl 0x3ec
/* 80240F98  48 00 05 99 */	bl 0x598
/* 80240F9C  48 00 06 4D */	bl 0x64c
/* 80240FA0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80240FA4  7C 08 03 A6 */	mtlr r0
/* 80240FA8  38 21 00 10 */	addi r1, r1, 0x10
/* 80240FAC  4E 80 00 20 */	blr
/* 80240FB0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80240FB4  7C 08 02 A6 */	mflr r0
/* 80240FB8  38 60 00 00 */	li r3, 0
/* 80240FBC  38 80 00 09 */	li r4, 9
/* 80240FC0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80240FC4  38 A0 00 01 */	li r5, 1
/* 80240FC8  38 C0 00 04 */	li r6, 4
/* 80240FCC  38 E0 00 00 */	li r7, 0
/* 80240FD0  4B F2 CC 99 */	bl -0xd3368
/* 80240FD4  38 60 00 00 */	li r3, 0
/* 80240FD8  38 80 00 0A */	li r4, 0xa
/* 80240FDC  38 A0 00 00 */	li r5, 0
/* 80240FE0  38 C0 00 04 */	li r6, 4
/* 80240FE4  38 E0 00 00 */	li r7, 0
/* 80240FE8  4B F2 CC 81 */	bl -0xd3380
/* 80240FEC  38 60 00 00 */	li r3, 0
/* 80240FF0  38 80 00 0B */	li r4, 0xb
/* 80240FF4  38 A0 00 01 */	li r5, 1
/* 80240FF8  38 C0 00 05 */	li r6, 5
/* 80240FFC  38 E0 00 00 */	li r7, 0
/* 80241000  4B F2 CC 69 */	bl -0xd3398
/* 80241004  38 60 00 00 */	li r3, 0
/* 80241008  38 80 00 0C */	li r4, 0xc
/* 8024100C  38 A0 00 01 */	li r5, 1
/* 80241010  38 C0 00 05 */	li r6, 5
/* 80241014  38 E0 00 00 */	li r7, 0
/* 80241018  4B F2 CC 51 */	bl -0xd33b0
/* 8024101C  38 60 00 00 */	li r3, 0
/* 80241020  38 80 00 0D */	li r4, 0xd
/* 80241024  38 A0 00 01 */	li r5, 1
/* 80241028  38 C0 00 03 */	li r6, 3
/* 8024102C  38 E0 00 07 */	li r7, 7
/* 80241030  4B F2 CC 39 */	bl -0xd33c8
/* 80241034  38 60 00 00 */	li r3, 0
/* 80241038  38 80 00 0E */	li r4, 0xe
/* 8024103C  38 A0 00 01 */	li r5, 1
/* 80241040  38 C0 00 03 */	li r6, 3
/* 80241044  38 E0 00 07 */	li r7, 7
/* 80241048  4B F2 CC 21 */	bl -0xd33e0
/* 8024104C  38 60 00 00 */	li r3, 0
/* 80241050  38 80 00 0F */	li r4, 0xf
/* 80241054  38 A0 00 01 */	li r5, 1
/* 80241058  38 C0 00 03 */	li r6, 3
/* 8024105C  38 E0 00 07 */	li r7, 7
/* 80241060  4B F2 CC 09 */	bl -0xd33f8
/* 80241064  38 60 00 00 */	li r3, 0
/* 80241068  38 80 00 10 */	li r4, 0x10
/* 8024106C  38 A0 00 01 */	li r5, 1
/* 80241070  38 C0 00 03 */	li r6, 3
/* 80241074  38 E0 00 07 */	li r7, 7
/* 80241078  4B F2 CB F1 */	bl -0xd3410
/* 8024107C  38 60 00 00 */	li r3, 0
/* 80241080  38 80 00 11 */	li r4, 0x11
/* 80241084  38 A0 00 01 */	li r5, 1
/* 80241088  38 C0 00 03 */	li r6, 3
/* 8024108C  38 E0 00 07 */	li r7, 7
/* 80241090  4B F2 CB D9 */	bl -0xd3428
/* 80241094  38 60 00 00 */	li r3, 0
/* 80241098  38 80 00 12 */	li r4, 0x12
/* 8024109C  38 A0 00 01 */	li r5, 1
/* 802410A0  38 C0 00 03 */	li r6, 3
/* 802410A4  38 E0 00 07 */	li r7, 7
/* 802410A8  4B F2 CB C1 */	bl -0xd3440
/* 802410AC  38 60 00 00 */	li r3, 0
/* 802410B0  38 80 00 13 */	li r4, 0x13
/* 802410B4  38 A0 00 01 */	li r5, 1
/* 802410B8  38 C0 00 03 */	li r6, 3
/* 802410BC  38 E0 00 07 */	li r7, 7
/* 802410C0  4B F2 CB A9 */	bl -0xd3458
/* 802410C4  38 60 00 00 */	li r3, 0
/* 802410C8  38 80 00 14 */	li r4, 0x14
/* 802410CC  38 A0 00 01 */	li r5, 1
/* 802410D0  38 C0 00 03 */	li r6, 3
/* 802410D4  38 E0 00 07 */	li r7, 7
/* 802410D8  4B F2 CB 91 */	bl -0xd3470
/* 802410DC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802410E0  7C 08 03 A6 */	mtlr r0
/* 802410E4  38 21 00 10 */	addi r1, r1, 0x10
/* 802410E8  4E 80 00 20 */	blr
/* 802410EC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802410F0  7C 08 02 A6 */	mflr r0
/* 802410F4  38 60 00 01 */	li r3, 1
/* 802410F8  90 01 00 24 */	stw r0, 0x24(r1)
/* 802410FC  4B F2 F4 51 */	bl -0xd0bb0
/* 80241100  88 E2 A1 48 */	lbz r7, -0x5eb8(r2)
/* 80241104  38 81 00 18 */	addi r4, r1, 0x18
/* 80241108  88 C2 A1 49 */	lbz r6, -0x5eb7(r2)
/* 8024110C  38 60 00 04 */	li r3, 4
/* 80241110  88 A2 A1 4A */	lbz r5, -0x5eb6(r2)
/* 80241114  88 02 A1 4B */	lbz r0, -0x5eb5(r2)
/* 80241118  98 E1 00 08 */	stb r7, 8(r1)
/* 8024111C  98 C1 00 09 */	stb r6, 9(r1)
/* 80241120  98 A1 00 0A */	stb r5, 0xa(r1)
/* 80241124  98 01 00 0B */	stb r0, 0xb(r1)
/* 80241128  80 01 00 08 */	lwz r0, 8(r1)
/* 8024112C  90 01 00 18 */	stw r0, 0x18(r1)
/* 80241130  4B F2 F2 6D */	bl -0xd0d94
/* 80241134  80 01 00 08 */	lwz r0, 8(r1)
/* 80241138  38 81 00 14 */	addi r4, r1, 0x14
/* 8024113C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241140  38 60 00 05 */	li r3, 5
/* 80241144  4B F2 F2 59 */	bl -0xd0da8
/* 80241148  80 01 00 08 */	lwz r0, 8(r1)
/* 8024114C  38 81 00 10 */	addi r4, r1, 0x10
/* 80241150  90 01 00 10 */	stw r0, 0x10(r1)
/* 80241154  38 60 00 04 */	li r3, 4
/* 80241158  4B F2 F3 1D */	bl -0xd0ce4
/* 8024115C  80 01 00 08 */	lwz r0, 8(r1)
/* 80241160  38 81 00 0C */	addi r4, r1, 0xc
/* 80241164  90 01 00 0C */	stw r0, 0xc(r1)
/* 80241168  38 60 00 05 */	li r3, 5
/* 8024116C  4B F2 F3 09 */	bl -0xd0cf8
/* 80241170  38 60 00 02 */	li r3, 2
/* 80241174  4B F2 E2 45 */	bl -0xd1dbc
/* 80241178  38 60 00 04 */	li r3, 4
/* 8024117C  38 80 00 00 */	li r4, 0
/* 80241180  38 A0 00 00 */	li r5, 0
/* 80241184  38 C0 00 00 */	li r6, 0
/* 80241188  38 E0 00 00 */	li r7, 0
/* 8024118C  39 00 00 02 */	li r8, 2
/* 80241190  39 20 00 02 */	li r9, 2
/* 80241194  4B F2 F3 DD */	bl -0xd0c24
/* 80241198  38 60 00 05 */	li r3, 5
/* 8024119C  38 80 00 00 */	li r4, 0
/* 802411A0  38 A0 00 00 */	li r5, 0
/* 802411A4  38 C0 00 00 */	li r6, 0
/* 802411A8  38 E0 00 00 */	li r7, 0
/* 802411AC  39 00 00 02 */	li r8, 2
/* 802411B0  39 20 00 02 */	li r9, 2
/* 802411B4  4B F2 F3 BD */	bl -0xd0c44
/* 802411B8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802411BC  7C 08 03 A6 */	mtlr r0
/* 802411C0  38 21 00 20 */	addi r1, r1, 0x20
/* 802411C4  4E 80 00 20 */	blr
/* 802411C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 802411CC  7C 08 02 A6 */	mflr r0
/* 802411D0  38 60 00 00 */	li r3, 0
/* 802411D4  90 01 00 14 */	stw r0, 0x14(r1)
/* 802411D8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 802411DC  93 C1 00 08 */	stw r30, 8(r1)
/* 802411E0  4B F3 09 59 */	bl -0xcf6a8
/* 802411E4  3B C0 00 00 */	li r30, 0
/* 802411E8  3F E0 80 26 */	lis r31, 0x8026
/* 802411EC  38 7E 00 01 */	addi r3, r30, 1
/* 802411F0  38 9F 81 F8 */	addi r4, r31, -32264
/* 802411F4  38 A0 00 01 */	li r5, 1
/* 802411F8  4B F3 06 1D */	bl -0xcf9e4
/* 802411FC  3B DE 00 01 */	addi r30, r30, 1
/* 80241200  28 1E 00 03 */	cmplwi r30, 3
/* 80241204  41 80 FF E8 */	blt -0x18
/* 80241208  3B C0 00 00 */	li r30, 0
/* 8024120C  7F C3 F3 78 */	mr r3, r30
/* 80241210  38 80 00 00 */	li r4, 0
/* 80241214  38 A0 00 00 */	li r5, 0
/* 80241218  4B F3 07 51 */	bl -0xcf8b0
/* 8024121C  3B DE 00 01 */	addi r30, r30, 1
/* 80241220  28 1E 00 04 */	cmplwi r30, 4
/* 80241224  41 80 FF E8 */	blt -0x18
/* 80241228  80 01 00 14 */	lwz r0, 0x14(r1)
/* 8024122C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80241230  83 C1 00 08 */	lwz r30, 8(r1)
/* 80241234  7C 08 03 A6 */	mtlr r0
/* 80241238  38 21 00 10 */	addi r1, r1, 0x10
/* 8024123C  4E 80 00 20 */	blr
/* 80241240  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241244  7C 08 02 A6 */	mflr r0
/* 80241248  38 80 00 00 */	li r4, 0
/* 8024124C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241250  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80241254  3F E0 80 38 */	lis r31, 0x8038
/* 80241258  38 7F 45 00 */	addi r3, r31, 0x4500
/* 8024125C  4B F2 FC D1 */	bl -0xd0330
/* 80241260  38 7F 45 00 */	addi r3, r31, 0x4500
/* 80241264  38 80 00 01 */	li r4, 1
/* 80241268  4B F2 FC C5 */	bl -0xd033c
/* 8024126C  38 7F 45 00 */	addi r3, r31, 0x4500
/* 80241270  38 80 00 02 */	li r4, 2
/* 80241274  4B F2 FC B9 */	bl -0xd0348
/* 80241278  38 7F 45 00 */	addi r3, r31, 0x4500
/* 8024127C  38 80 00 03 */	li r4, 3
/* 80241280  4B F2 FC AD */	bl -0xd0354
/* 80241284  38 7F 45 00 */	addi r3, r31, 0x4500
/* 80241288  38 80 00 04 */	li r4, 4
/* 8024128C  4B F2 FC A1 */	bl -0xd0360
/* 80241290  38 7F 45 00 */	addi r3, r31, 0x4500
/* 80241294  38 80 00 05 */	li r4, 5
/* 80241298  4B F2 FC 95 */	bl -0xd036c
/* 8024129C  38 7F 45 00 */	addi r3, r31, 0x4500
/* 802412A0  38 80 00 06 */	li r4, 6
/* 802412A4  4B F2 FC 89 */	bl -0xd0378
/* 802412A8  38 7F 45 00 */	addi r3, r31, 0x4500
/* 802412AC  38 80 00 07 */	li r4, 7
/* 802412B0  4B F2 FC 7D */	bl -0xd0384
/* 802412B4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802412B8  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 802412BC  7C 08 03 A6 */	mtlr r0
/* 802412C0  38 21 00 10 */	addi r1, r1, 0x10
/* 802412C4  4E 80 00 20 */	blr
/* 802412C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802412CC  7C 08 02 A6 */	mflr r0
/* 802412D0  38 60 00 01 */	li r3, 1
/* 802412D4  90 01 00 24 */	stw r0, 0x24(r1)
/* 802412D8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802412DC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 802412E0  93 A1 00 14 */	stw r29, 0x14(r1)
/* 802412E4  4B F2 D2 C1 */	bl -0xd2d40
/* 802412E8  3B A0 00 00 */	li r29, 0
/* 802412EC  3B C0 00 1E */	li r30, 0x1e
/* 802412F0  3F E0 80 26 */	lis r31, 0x8026
/* 802412F4  7F C4 F3 78 */	mr r4, r30
/* 802412F8  38 7F 81 C8 */	addi r3, r31, -32312
/* 802412FC  38 A0 00 00 */	li r5, 0
/* 80241300  4B F3 1F 35 */	bl -0xce0cc
/* 80241304  3B BD 00 01 */	addi r29, r29, 1
/* 80241308  3B DE 00 03 */	addi r30, r30, 3
/* 8024130C  28 1D 00 0A */	cmplwi r29, 0xa
/* 80241310  41 80 FF E4 */	blt -0x1c
/* 80241314  3B A0 00 00 */	li r29, 0
/* 80241318  7F A3 EB 78 */	mr r3, r29
/* 8024131C  38 80 00 01 */	li r4, 1
/* 80241320  38 A0 00 04 */	li r5, 4
/* 80241324  38 C0 00 3C */	li r6, 0x3c
/* 80241328  38 E0 00 00 */	li r7, 0
/* 8024132C  39 00 00 7D */	li r8, 0x7d
/* 80241330  4B F2 D0 4D */	bl -0xd2fb4
/* 80241334  7F A3 EB 78 */	mr r3, r29
/* 80241338  38 80 00 00 */	li r4, 0
/* 8024133C  38 A0 00 00 */	li r5, 0
/* 80241340  38 C0 00 00 */	li r6, 0
/* 80241344  4B F2 FE 3D */	bl -0xd01c4
/* 80241348  7F A3 EB 78 */	mr r3, r29
/* 8024134C  38 80 00 00 */	li r4, 0
/* 80241350  38 A0 00 00 */	li r5, 0
/* 80241354  4B F2 FE A9 */	bl -0xd0158
/* 80241358  3B BD 00 01 */	addi r29, r29, 1
/* 8024135C  28 1D 00 08 */	cmplwi r29, 8
/* 80241360  41 80 FF B8 */	blt -0x48
/* 80241364  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80241368  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 8024136C  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80241370  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80241374  7C 08 03 A6 */	mtlr r0
/* 80241378  38 21 00 20 */	addi r1, r1, 0x20
/* 8024137C  4E 80 00 20 */	blr
/* 80241380  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80241384  7C 08 02 A6 */	mflr r0
/* 80241388  38 60 00 01 */	li r3, 1
/* 8024138C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80241390  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80241394  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80241398  4B F3 0F 11 */	bl -0xcf0f0
/* 8024139C  3B E0 00 00 */	li r31, 0
/* 802413A0  7F E3 FB 78 */	mr r3, r31
/* 802413A4  4B F3 07 B5 */	bl -0xcf84c
/* 802413A8  7F E3 FB 78 */	mr r3, r31
/* 802413AC  38 80 00 FF */	li r4, 0xff
/* 802413B0  38 A0 00 FF */	li r5, 0xff
/* 802413B4  38 C0 00 FF */	li r6, 0xff
/* 802413B8  4B F3 0D 95 */	bl -0xcf26c
/* 802413BC  7F E3 FB 78 */	mr r3, r31
/* 802413C0  38 80 00 0F */	li r4, 0xf
/* 802413C4  38 A0 00 0F */	li r5, 0xf
/* 802413C8  38 C0 00 0F */	li r6, 0xf
/* 802413CC  38 E0 00 0F */	li r7, 0xf
/* 802413D0  4B F3 09 11 */	bl -0xcf6f0
/* 802413D4  7F E3 FB 78 */	mr r3, r31
/* 802413D8  38 80 00 00 */	li r4, 0
/* 802413DC  38 A0 00 00 */	li r5, 0
/* 802413E0  38 C0 00 00 */	li r6, 0
/* 802413E4  38 E0 00 01 */	li r7, 1
/* 802413E8  39 00 00 00 */	li r8, 0
/* 802413EC  4B F3 09 75 */	bl -0xcf68c
/* 802413F0  7F E3 FB 78 */	mr r3, r31
/* 802413F4  38 80 00 07 */	li r4, 7
/* 802413F8  38 A0 00 07 */	li r5, 7
/* 802413FC  38 C0 00 07 */	li r6, 7
/* 80241400  38 E0 00 07 */	li r7, 7
/* 80241404  4B F3 09 1D */	bl -0xcf6e4
/* 80241408  7F E3 FB 78 */	mr r3, r31
/* 8024140C  38 80 00 00 */	li r4, 0
/* 80241410  38 A0 00 00 */	li r5, 0
/* 80241414  38 C0 00 00 */	li r6, 0
/* 80241418  38 E0 00 01 */	li r7, 1
/* 8024141C  39 00 00 00 */	li r8, 0
/* 80241420  4B F3 09 99 */	bl -0xcf668
/* 80241424  7F E3 FB 78 */	mr r3, r31
/* 80241428  38 80 00 00 */	li r4, 0
/* 8024142C  38 A0 00 00 */	li r5, 0
/* 80241430  4B F3 0B A1 */	bl -0xcf460
/* 80241434  3B FF 00 01 */	addi r31, r31, 1
/* 80241438  28 1F 00 10 */	cmplwi r31, 0x10
/* 8024143C  41 80 FF 64 */	blt -0x9c
/* 80241440  88 A2 A1 48 */	lbz r5, -0x5eb8(r2)
/* 80241444  3B C0 00 00 */	li r30, 0
/* 80241448  88 82 A1 49 */	lbz r4, -0x5eb7(r2)
/* 8024144C  88 62 A1 4A */	lbz r3, -0x5eb6(r2)
/* 80241450  88 02 A1 4B */	lbz r0, -0x5eb5(r2)
/* 80241454  98 A1 00 0C */	stb r5, 0xc(r1)
/* 80241458  98 81 00 0D */	stb r4, 0xd(r1)
/* 8024145C  98 61 00 0E */	stb r3, 0xe(r1)
/* 80241460  98 01 00 0F */	stb r0, 0xf(r1)
/* 80241464  98 A1 00 08 */	stb r5, 8(r1)
/* 80241468  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8024146C  98 81 00 09 */	stb r4, 9(r1)
/* 80241470  98 61 00 0A */	stb r3, 0xa(r1)
/* 80241474  98 01 00 0B */	stb r0, 0xb(r1)
/* 80241478  93 E1 00 14 */	stw r31, 0x14(r1)
/* 8024147C  7F C3 F3 78 */	mr r3, r30
/* 80241480  38 81 00 14 */	addi r4, r1, 0x14
/* 80241484  4B F3 0A 51 */	bl -0xcf5b0
/* 80241488  3B DE 00 01 */	addi r30, r30, 1
/* 8024148C  28 1E 00 04 */	cmplwi r30, 4
/* 80241490  41 80 FF E8 */	blt -0x18
/* 80241494  83 E1 00 08 */	lwz r31, 8(r1)
/* 80241498  3B C0 00 00 */	li r30, 0
/* 8024149C  93 E1 00 10 */	stw r31, 0x10(r1)
/* 802414A0  7F C3 F3 78 */	mr r3, r30
/* 802414A4  38 81 00 10 */	addi r4, r1, 0x10
/* 802414A8  4B F3 09 69 */	bl -0xcf698
/* 802414AC  3B DE 00 01 */	addi r30, r30, 1
/* 802414B0  28 1E 00 04 */	cmplwi r30, 4
/* 802414B4  41 80 FF E8 */	blt -0x18
/* 802414B8  38 60 00 00 */	li r3, 0
/* 802414BC  38 80 00 00 */	li r4, 0
/* 802414C0  38 A0 00 01 */	li r5, 1
/* 802414C4  38 C0 00 02 */	li r6, 2
/* 802414C8  38 E0 00 03 */	li r7, 3
/* 802414CC  4B F3 0B 41 */	bl -0xcf4c0
/* 802414D0  38 60 00 01 */	li r3, 1
/* 802414D4  38 80 00 00 */	li r4, 0
/* 802414D8  38 A0 00 00 */	li r5, 0
/* 802414DC  38 C0 00 00 */	li r6, 0
/* 802414E0  38 E0 00 03 */	li r7, 3
/* 802414E4  4B F3 0B 29 */	bl -0xcf4d8
/* 802414E8  38 60 00 02 */	li r3, 2
/* 802414EC  38 80 00 01 */	li r4, 1
/* 802414F0  38 A0 00 01 */	li r5, 1
/* 802414F4  38 C0 00 01 */	li r6, 1
/* 802414F8  38 E0 00 03 */	li r7, 3
/* 802414FC  4B F3 0B 11 */	bl -0xcf4f0
/* 80241500  38 60 00 03 */	li r3, 3
/* 80241504  38 80 00 02 */	li r4, 2
/* 80241508  38 A0 00 02 */	li r5, 2
/* 8024150C  38 C0 00 02 */	li r6, 2
/* 80241510  38 E0 00 03 */	li r7, 3
/* 80241514  4B F3 0A F9 */	bl -0xcf508
/* 80241518  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8024151C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80241520  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80241524  7C 08 03 A6 */	mtlr r0
/* 80241528  38 21 00 20 */	addi r1, r1, 0x20
/* 8024152C  4E 80 00 20 */	blr
/* 80241530  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241534  7C 08 02 A6 */	mflr r0
/* 80241538  38 60 00 01 */	li r3, 1
/* 8024153C  38 80 00 04 */	li r4, 4
/* 80241540  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241544  38 A0 00 05 */	li r5, 5
/* 80241548  38 C0 00 05 */	li r6, 5
/* 8024154C  4B F3 12 31 */	bl -0xcedd0
/* 80241550  38 60 00 07 */	li r3, 7
/* 80241554  38 80 00 00 */	li r4, 0
/* 80241558  38 A0 00 00 */	li r5, 0
/* 8024155C  38 C0 00 07 */	li r6, 7
/* 80241560  38 E0 00 00 */	li r7, 0
/* 80241564  4B F3 0B 25 */	bl -0xcf4dc
/* 80241568  38 60 00 01 */	li r3, 1
/* 8024156C  38 80 00 03 */	li r4, 3
/* 80241570  38 A0 00 01 */	li r5, 1
/* 80241574  4B F3 12 B1 */	bl -0xced50
/* 80241578  C0 42 A1 50 */	lfs f2, -0x5eb0(r2)
/* 8024157C  38 81 00 08 */	addi r4, r1, 8
/* 80241580  88 E2 A1 48 */	lbz r7, -0x5eb8(r2)
/* 80241584  38 60 00 00 */	li r3, 0
/* 80241588  88 C2 A1 49 */	lbz r6, -0x5eb7(r2)
/* 8024158C  FC 80 10 90 */	fmr f4, f2
/* 80241590  88 A2 A1 4A */	lbz r5, -0x5eb6(r2)
/* 80241594  88 02 A1 4B */	lbz r0, -0x5eb5(r2)
/* 80241598  98 E1 00 08 */	stb r7, 8(r1)
/* 8024159C  C0 22 A1 4C */	lfs f1, -0x5eb4(r2)
/* 802415A0  98 C1 00 09 */	stb r6, 9(r1)
/* 802415A4  C0 62 A1 54 */	lfs f3, -0x5eac(r2)
/* 802415A8  98 A1 00 0A */	stb r5, 0xa(r1)
/* 802415AC  98 01 00 0B */	stb r0, 0xb(r1)
/* 802415B0  4B F3 0D 1D */	bl -0xcf2e4
/* 802415B4  38 60 00 00 */	li r3, 0
/* 802415B8  38 80 00 00 */	li r4, 0
/* 802415BC  38 A0 00 00 */	li r5, 0
/* 802415C0  4B F3 10 99 */	bl -0xcef68
/* 802415C4  38 60 00 01 */	li r3, 1
/* 802415C8  4B F3 12 91 */	bl -0xced70
/* 802415CC  38 60 00 00 */	li r3, 0
/* 802415D0  38 80 00 00 */	li r4, 0
/* 802415D4  4B F3 13 89 */	bl -0xcec78
/* 802415D8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 802415DC  7C 08 03 A6 */	mtlr r0
/* 802415E0  38 21 00 10 */	addi r1, r1, 0x10
/* 802415E4  4E 80 00 20 */	blr
/* 802415E8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 802415EC  7C 08 02 A6 */	mflr r0
/* 802415F0  38 60 00 01 */	li r3, 1
/* 802415F4  90 01 00 24 */	stw r0, 0x24(r1)
/* 802415F8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 802415FC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80241600  3F C0 80 38 */	lis r30, 0x8038
/* 80241604  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80241608  3B A0 00 00 */	li r29, 0
/* 8024160C  93 BE 45 20 */	stw r29, 0x4520(r30)
/* 80241610  4B F3 11 BD */	bl -0xcee44
/* 80241614  3B FE 45 20 */	addi r31, r30, 0x4520
/* 80241618  3B C0 00 01 */	li r30, 1
/* 8024161C  9B DF 00 0C */	stb r30, 0xc(r31)
/* 80241620  38 60 00 01 */	li r3, 1
/* 80241624  4B F3 11 D5 */	bl -0xcee2c
/* 80241628  9B DF 00 0D */	stb r30, 0xd(r31)
/* 8024162C  38 60 00 01 */	li r3, 1
/* 80241630  4B F3 13 01 */	bl -0xced00
/* 80241634  9B DF 00 0E */	stb r30, 0xe(r31)
/* 80241638  38 60 00 00 */	li r3, 0
/* 8024163C  38 80 00 00 */	li r4, 0
/* 80241640  4B F3 13 1D */	bl -0xcece4
/* 80241644  9B BF 00 0F */	stb r29, 0xf(r31)
/* 80241648  9B BF 00 10 */	stb r29, 0x10(r31)
/* 8024164C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80241650  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80241654  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80241658  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8024165C  7C 08 03 A6 */	mtlr r0
/* 80241660  38 21 00 20 */	addi r1, r1, 0x20
/* 80241664  4E 80 00 20 */	blr
/* 80241668  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8024166C  7C 08 02 A6 */	mflr r0
/* 80241670  90 01 00 24 */	stw r0, 0x24(r1)
/* 80241674  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80241678  93 C1 00 18 */	stw r30, 0x18(r1)
/* 8024167C  7C 9E 23 78 */	mr r30, r4
/* 80241680  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80241684  7C 7D 1B 78 */	mr r29, r3
/* 80241688  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 8024168C  54 05 06 B5 */	rlwinm. r5, r0, 0, 0x1a, 0x1a
/* 80241690  41 82 00 1C */	beq 0x1c
/* 80241694  80 0D A3 54 */	lwz r0, -0x5cac(r13)
/* 80241698  7C 00 18 00 */	cmpw r0, r3
/* 8024169C  40 82 00 18 */	bne 0x18
/* 802416A0  80 0D A3 58 */	lwz r0, -0x5ca8(r13)
/* 802416A4  7C 00 20 00 */	cmpw r0, r4
/* 802416A8  40 82 00 0C */	bne 0xc
/* 802416AC  2C 05 00 00 */	cmpwi r5, 0
/* 802416B0  40 82 00 28 */	bne 0x28
/* 802416B4  7F A3 EB 78 */	mr r3, r29
/* 802416B8  7F C4 F3 78 */	mr r4, r30
/* 802416BC  4B F3 11 CD */	bl -0xcee34
/* 802416C0  3F E0 80 38 */	lis r31, 0x8038
/* 802416C4  3B FF 45 20 */	addi r31, r31, 0x4520
/* 802416C8  88 7F 00 0C */	lbz r3, 0xc(r31)
/* 802416CC  4B F3 11 01 */	bl -0xcef00
/* 802416D0  88 7F 00 0D */	lbz r3, 0xd(r31)
/* 802416D4  4B F3 11 25 */	bl -0xceedc
/* 802416D8  93 AD A3 54 */	stw r29, -0x5cac(r13)
/* 802416DC  93 CD A3 58 */	stw r30, -0x5ca8(r13)
/* 802416E0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802416E4  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802416E8  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802416EC  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802416F0  7C 08 03 A6 */	mtlr r0
/* 802416F4  38 21 00 20 */	addi r1, r1, 0x20
/* 802416F8  4E 80 00 20 */	blr
/* 802416FC  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80241700  7C 08 02 A6 */	mflr r0
/* 80241704  2C 04 00 00 */	cmpwi r4, 0
/* 80241708  90 01 00 44 */	stw r0, 0x44(r1)
/* 8024170C  41 82 00 10 */	beq 0x10
/* 80241710  2C 04 00 01 */	cmpwi r4, 1
/* 80241714  41 82 00 64 */	beq 0x64
/* 80241718  48 00 00 D4 */	b 0xd4
/* 8024171C  38 00 00 00 */	li r0, 0
/* 80241720  90 01 00 24 */	stw r0, 0x24(r1)
/* 80241724  90 01 00 28 */	stw r0, 0x28(r1)
/* 80241728  90 01 00 2C */	stw r0, 0x2c(r1)
/* 8024172C  90 01 00 30 */	stw r0, 0x30(r1)
/* 80241730  90 01 00 34 */	stw r0, 0x34(r1)
/* 80241734  90 01 00 38 */	stw r0, 0x38(r1)
/* 80241738  90 01 00 3C */	stw r0, 0x3c(r1)
/* 8024173C  C0 03 00 00 */	lfs f0, 0(r3)
/* 80241740  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 80241744  C0 03 00 08 */	lfs f0, 8(r3)
/* 80241748  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 8024174C  C0 03 00 14 */	lfs f0, 0x14(r3)
/* 80241750  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 80241754  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 80241758  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 8024175C  C0 03 00 28 */	lfs f0, 0x28(r3)
/* 80241760  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 80241764  C0 03 00 2C */	lfs f0, 0x2c(r3)
/* 80241768  38 61 00 24 */	addi r3, r1, 0x24
/* 8024176C  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 80241770  48 00 00 8D */	bl 0x8c
/* 80241774  48 00 00 78 */	b 0x78
/* 80241778  3D 40 80 26 */	lis r10, 0x8026
/* 8024177C  85 2A 82 10 */	lwzu r9, -0x7df0(r10)
/* 80241780  91 21 00 08 */	stw r9, 8(r1)
/* 80241784  81 0A 00 04 */	lwz r8, 4(r10)
/* 80241788  80 EA 00 08 */	lwz r7, 8(r10)
/* 8024178C  80 CA 00 0C */	lwz r6, 0xc(r10)
/* 80241790  80 AA 00 10 */	lwz r5, 0x10(r10)
/* 80241794  80 8A 00 14 */	lwz r4, 0x14(r10)
/* 80241798  80 0A 00 18 */	lwz r0, 0x18(r10)
/* 8024179C  91 01 00 0C */	stw r8, 0xc(r1)
/* 802417A0  90 E1 00 10 */	stw r7, 0x10(r1)
/* 802417A4  90 C1 00 14 */	stw r6, 0x14(r1)
/* 802417A8  90 A1 00 18 */	stw r5, 0x18(r1)
/* 802417AC  90 81 00 1C */	stw r4, 0x1c(r1)
/* 802417B0  90 01 00 20 */	stw r0, 0x20(r1)
/* 802417B4  C0 03 00 00 */	lfs f0, 0(r3)
/* 802417B8  D0 01 00 0C */	stfs f0, 0xc(r1)
/* 802417BC  C0 03 00 0C */	lfs f0, 0xc(r3)
/* 802417C0  D0 01 00 10 */	stfs f0, 0x10(r1)
/* 802417C4  C0 03 00 14 */	lfs f0, 0x14(r3)
/* 802417C8  D0 01 00 14 */	stfs f0, 0x14(r1)
/* 802417CC  C0 03 00 1C */	lfs f0, 0x1c(r3)
/* 802417D0  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 802417D4  C0 03 00 28 */	lfs f0, 0x28(r3)
/* 802417D8  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 802417DC  C0 03 00 2C */	lfs f0, 0x2c(r3)
/* 802417E0  38 61 00 08 */	addi r3, r1, 8
/* 802417E4  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 802417E8  48 00 00 15 */	bl 0x14
/* 802417EC  80 01 00 44 */	lwz r0, 0x44(r1)
/* 802417F0  7C 08 03 A6 */	mtlr r0
/* 802417F4  38 21 00 40 */	addi r1, r1, 0x40
/* 802417F8  4E 80 00 20 */	blr
/* 802417FC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80241800  7C 08 02 A6 */	mflr r0
/* 80241804  90 01 00 34 */	stw r0, 0x34(r1)
/* 80241808  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 8024180C  7C 7F 1B 78 */	mr r31, r3
/* 80241810  38 61 00 08 */	addi r3, r1, 8
/* 80241814  4B F3 18 B9 */	bl -0xce748
/* 80241818  3C 60 80 38 */	lis r3, 0x8038
/* 8024181C  80 03 45 20 */	lwz r0, 0x4520(r3)
/* 80241820  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80241824  41 82 00 74 */	beq 0x74
/* 80241828  C0 3F 00 00 */	lfs f1, 0(r31)
/* 8024182C  C0 01 00 08 */	lfs f0, 8(r1)
/* 80241830  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241834  40 82 00 64 */	bne 0x64
/* 80241838  C0 3F 00 04 */	lfs f1, 4(r31)
/* 8024183C  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 80241840  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241844  40 82 00 54 */	bne 0x54
/* 80241848  C0 3F 00 08 */	lfs f1, 8(r31)
/* 8024184C  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 80241850  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241854  40 82 00 44 */	bne 0x44
/* 80241858  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 8024185C  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 80241860  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241864  40 82 00 34 */	bne 0x34
/* 80241868  C0 3F 00 10 */	lfs f1, 0x10(r31)
/* 8024186C  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80241870  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241874  40 82 00 24 */	bne 0x24
/* 80241878  C0 3F 00 14 */	lfs f1, 0x14(r31)
/* 8024187C  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 80241880  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241884  40 82 00 14 */	bne 0x14
/* 80241888  C0 3F 00 18 */	lfs f1, 0x18(r31)
/* 8024188C  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 80241890  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80241894  41 82 00 28 */	beq 0x28
/* 80241898  7F E3 FB 78 */	mr r3, r31
/* 8024189C  4B F3 17 E5 */	bl -0xce81c
/* 802418A0  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 802418A4  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 802418A8  41 82 00 14 */	beq 0x14
/* 802418AC  3C 60 80 38 */	lis r3, 0x8038
/* 802418B0  80 03 45 20 */	lwz r0, 0x4520(r3)
/* 802418B4  60 00 00 01 */	ori r0, r0, 1
/* 802418B8  90 03 45 20 */	stw r0, 0x4520(r3)
/* 802418BC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 802418C0  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 802418C4  7C 08 03 A6 */	mtlr r0
/* 802418C8  38 21 00 30 */	addi r1, r1, 0x30
/* 802418CC  4E 80 00 20 */	blr
/* 802418D0  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 802418D4  7C 08 02 A6 */	mflr r0
/* 802418D8  90 01 00 84 */	stw r0, 0x84(r1)
/* 802418DC  DB E1 00 70 */	stfd f31, 0x70(r1)
/* 802418E0  F3 E1 00 78 */	psq_st f31, 120(r1), 0, qr0
/* 802418E4  DB C1 00 60 */	stfd f30, 0x60(r1)
/* 802418E8  F3 C1 00 68 */	psq_st f30, 104(r1), 0, qr0
/* 802418EC  DB A1 00 50 */	stfd f29, 0x50(r1)
/* 802418F0  F3 A1 00 58 */	psq_st f29, 88(r1), 0, qr0
/* 802418F4  DB 81 00 40 */	stfd f28, 0x40(r1)
/* 802418F8  F3 81 00 48 */	psq_st f28, 72(r1), 0, qr0
/* 802418FC  DB 61 00 30 */	stfd f27, 0x30(r1)
/* 80241900  F3 61 00 38 */	psq_st f27, 56(r1), 0, qr0
/* 80241904  DB 41 00 20 */	stfd f26, 0x20(r1)
/* 80241908  F3 41 00 28 */	psq_st f26, 40(r1), 0, qr0
/* 8024190C  FF 40 08 90 */	fmr f26, f1
/* 80241910  38 61 00 08 */	addi r3, r1, 8
/* 80241914  FF 60 10 90 */	fmr f27, f2
/* 80241918  FF 80 18 90 */	fmr f28, f3
/* 8024191C  FF A0 20 90 */	fmr f29, f4
/* 80241920  FF C0 28 90 */	fmr f30, f5
/* 80241924  FF E0 30 90 */	fmr f31, f6
/* 80241928  4B F3 1A B9 */	bl -0xce548
/* 8024192C  3C 60 80 38 */	lis r3, 0x8038
/* 80241930  80 03 45 20 */	lwz r0, 0x4520(r3)
/* 80241934  54 00 07 BD */	rlwinm. r0, r0, 0, 0x1e, 0x1e
/* 80241938  41 82 00 4C */	beq 0x4c
/* 8024193C  C0 01 00 08 */	lfs f0, 8(r1)
/* 80241940  FC 1A 00 00 */	fcmpu cr0, f26, f0
/* 80241944  40 82 00 40 */	bne 0x40
/* 80241948  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8024194C  FC 1B 00 00 */	fcmpu cr0, f27, f0
/* 80241950  40 82 00 34 */	bne 0x34
/* 80241954  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 80241958  FC 1C 00 00 */	fcmpu cr0, f28, f0
/* 8024195C  40 82 00 28 */	bne 0x28
/* 80241960  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 80241964  FC 1D 00 00 */	fcmpu cr0, f29, f0
/* 80241968  40 82 00 1C */	bne 0x1c
/* 8024196C  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80241970  FC 1E 00 00 */	fcmpu cr0, f30, f0
/* 80241974  40 82 00 10 */	bne 0x10
/* 80241978  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 8024197C  FC 1F 00 00 */	fcmpu cr0, f31, f0
/* 80241980  41 82 00 3C */	beq 0x3c
/* 80241984  FC 20 D0 90 */	fmr f1, f26
/* 80241988  FC 40 D8 90 */	fmr f2, f27
/* 8024198C  FC 60 E0 90 */	fmr f3, f28
/* 80241990  FC 80 E8 90 */	fmr f4, f29
/* 80241994  FC A0 F0 90 */	fmr f5, f30
/* 80241998  FC C0 F8 90 */	fmr f6, f31
/* 8024199C  4B F3 1A 19 */	bl -0xce5e8
/* 802419A0  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 802419A4  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 802419A8  41 82 00 14 */	beq 0x14
/* 802419AC  3C 60 80 38 */	lis r3, 0x8038
/* 802419B0  80 03 45 20 */	lwz r0, 0x4520(r3)
/* 802419B4  60 00 00 02 */	ori r0, r0, 2
/* 802419B8  90 03 45 20 */	stw r0, 0x4520(r3)
/* 802419BC  E3 E1 00 78 */	psq_l f31, 120(r1), 0, qr0
/* 802419C0  CB E1 00 70 */	lfd f31, 0x70(r1)
/* 802419C4  E3 C1 00 68 */	psq_l f30, 104(r1), 0, qr0
/* 802419C8  CB C1 00 60 */	lfd f30, 0x60(r1)
/* 802419CC  E3 A1 00 58 */	psq_l f29, 88(r1), 0, qr0
/* 802419D0  CB A1 00 50 */	lfd f29, 0x50(r1)
/* 802419D4  E3 81 00 48 */	psq_l f28, 72(r1), 0, qr0
/* 802419D8  CB 81 00 40 */	lfd f28, 0x40(r1)
/* 802419DC  E3 61 00 38 */	psq_l f27, 56(r1), 0, qr0
/* 802419E0  CB 61 00 30 */	lfd f27, 0x30(r1)
/* 802419E4  E3 41 00 28 */	psq_l f26, 40(r1), 0, qr0
/* 802419E8  80 01 00 84 */	lwz r0, 0x84(r1)
/* 802419EC  CB 41 00 20 */	lfd f26, 0x20(r1)
/* 802419F0  7C 08 03 A6 */	mtlr r0
/* 802419F4  38 21 00 80 */	addi r1, r1, 0x80
/* 802419F8  4E 80 00 20 */	blr
/* 802419FC  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80241A00  7C 08 02 A6 */	mflr r0
/* 80241A04  90 01 00 34 */	stw r0, 0x34(r1)
/* 80241A08  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 80241A0C  7C DF 33 78 */	mr r31, r6
/* 80241A10  38 C1 00 14 */	addi r6, r1, 0x14
/* 80241A14  93 C1 00 28 */	stw r30, 0x28(r1)
/* 80241A18  7C BE 2B 78 */	mr r30, r5
/* 80241A1C  38 A1 00 10 */	addi r5, r1, 0x10
/* 80241A20  93 A1 00 24 */	stw r29, 0x24(r1)
/* 80241A24  7C 9D 23 78 */	mr r29, r4
/* 80241A28  38 81 00 0C */	addi r4, r1, 0xc
/* 80241A2C  93 81 00 20 */	stw r28, 0x20(r1)
/* 80241A30  7C 7C 1B 78 */	mr r28, r3
/* 80241A34  38 61 00 08 */	addi r3, r1, 8
/* 80241A38  4B F3 1A 61 */	bl -0xce5a0
/* 80241A3C  3C 60 80 38 */	lis r3, 0x8038
/* 80241A40  80 03 45 20 */	lwz r0, 0x4520(r3)
/* 80241A44  54 00 07 7B */	rlwinm. r0, r0, 0, 0x1d, 0x1d
/* 80241A48  41 82 00 34 */	beq 0x34
/* 80241A4C  80 01 00 08 */	lwz r0, 8(r1)
/* 80241A50  7C 1C 00 40 */	cmplw r28, r0
/* 80241A54  40 82 00 28 */	bne 0x28
/* 80241A58  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80241A5C  7C 1D 00 40 */	cmplw r29, r0
/* 80241A60  40 82 00 1C */	bne 0x1c
/* 80241A64  80 01 00 10 */	lwz r0, 0x10(r1)
/* 80241A68  7C 1E 00 40 */	cmplw r30, r0
/* 80241A6C  40 82 00 10 */	bne 0x10
/* 80241A70  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241A74  7C 1F 00 40 */	cmplw r31, r0
/* 80241A78  41 82 00 34 */	beq 0x34
/* 80241A7C  7F 83 E3 78 */	mr r3, r28
/* 80241A80  7F A4 EB 78 */	mr r4, r29
/* 80241A84  7F C5 F3 78 */	mr r5, r30
/* 80241A88  7F E6 FB 78 */	mr r6, r31
/* 80241A8C  4B F3 19 A5 */	bl -0xce65c
/* 80241A90  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 80241A94  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80241A98  41 82 00 14 */	beq 0x14
/* 80241A9C  3C 60 80 38 */	lis r3, 0x8038
/* 80241AA0  80 03 45 20 */	lwz r0, 0x4520(r3)
/* 80241AA4  60 00 00 04 */	ori r0, r0, 4
/* 80241AA8  90 03 45 20 */	stw r0, 0x4520(r3)
/* 80241AAC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80241AB0  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 80241AB4  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 80241AB8  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 80241ABC  83 81 00 20 */	lwz r28, 0x20(r1)
/* 80241AC0  7C 08 03 A6 */	mtlr r0
/* 80241AC4  38 21 00 30 */	addi r1, r1, 0x30
/* 80241AC8  4E 80 00 20 */	blr
/* 80241ACC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241AD0  7C 08 02 A6 */	mflr r0
/* 80241AD4  3C A0 80 38 */	lis r5, 0x8038
/* 80241AD8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241ADC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80241AE0  7C 9F 23 78 */	mr r31, r4
/* 80241AE4  93 C1 00 08 */	stw r30, 8(r1)
/* 80241AE8  7C 7E 1B 78 */	mr r30, r3
/* 80241AEC  80 05 45 20 */	lwz r0, 0x4520(r5)
/* 80241AF0  54 00 07 39 */	rlwinm. r0, r0, 0, 0x1c, 0x1c
/* 80241AF4  41 82 00 20 */	beq 0x20
/* 80241AF8  38 A5 45 20 */	addi r5, r5, 0x4520
/* 80241AFC  80 05 00 04 */	lwz r0, 4(r5)
/* 80241B00  7C 03 00 00 */	cmpw r3, r0
/* 80241B04  40 82 00 10 */	bne 0x10
/* 80241B08  80 05 00 08 */	lwz r0, 8(r5)
/* 80241B0C  7C 04 00 00 */	cmpw r4, r0
/* 80241B10  41 82 00 38 */	beq 0x38
/* 80241B14  7F C3 F3 78 */	mr r3, r30
/* 80241B18  7F E4 FB 78 */	mr r4, r31
/* 80241B1C  4B F3 19 C5 */	bl -0xce63c
/* 80241B20  A0 0D 93 B8 */	lhz r0, -0x6c48(r13)
/* 80241B24  3C 80 80 38 */	lis r4, 0x8038
/* 80241B28  38 64 45 20 */	addi r3, r4, 0x4520
/* 80241B2C  54 00 06 B5 */	rlwinm. r0, r0, 0, 0x1a, 0x1a
/* 80241B30  93 C3 00 04 */	stw r30, 4(r3)
/* 80241B34  93 E3 00 08 */	stw r31, 8(r3)
/* 80241B38  41 82 00 10 */	beq 0x10
/* 80241B3C  80 04 45 20 */	lwz r0, 0x4520(r4)
/* 80241B40  60 00 00 08 */	ori r0, r0, 8
/* 80241B44  90 04 45 20 */	stw r0, 0x4520(r4)
/* 80241B48  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241B4C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80241B50  83 C1 00 08 */	lwz r30, 8(r1)
/* 80241B54  7C 08 03 A6 */	mtlr r0
/* 80241B58  38 21 00 10 */	addi r1, r1, 0x10
/* 80241B5C  4E 80 00 20 */	blr
/* 80241B60  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241B64  7C 08 02 A6 */	mflr r0
/* 80241B68  2C 03 00 00 */	cmpwi r3, 0
/* 80241B6C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241B70  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80241B74  7C 7F 1B 78 */	mr r31, r3
/* 80241B78  41 82 00 10 */	beq 0x10
/* 80241B7C  2C 04 00 00 */	cmpwi r4, 0
/* 80241B80  40 81 00 08 */	ble 0x8
/* 80241B84  4B FE 82 91 */	bl -0x17d70
/* 80241B88  7F E3 FB 78 */	mr r3, r31
/* 80241B8C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80241B90  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241B94  7C 08 03 A6 */	mtlr r0
/* 80241B98  38 21 00 10 */	addi r1, r1, 0x10
/* 80241B9C  4E 80 00 20 */	blr
/* 80241BA0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241BA4  7C 08 02 A6 */	mflr r0
/* 80241BA8  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241BAC  A0 03 00 0C */	lhz r0, 0xc(r3)
/* 80241BB0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80241BB4  41 82 00 28 */	beq 0x28
/* 80241BB8  48 00 02 F5 */	bl 0x2f4
/* 80241BBC  3C 80 80 26 */	lis r4, 0x8026
/* 80241BC0  38 A1 00 08 */	addi r5, r1, 8
/* 80241BC4  38 84 82 30 */	addi r4, r4, -32208
/* 80241BC8  38 84 00 1C */	addi r4, r4, 0x1c
/* 80241BCC  4C C6 31 82 */	crclr 6
/* 80241BD0  4B DD 14 71 */	bl -0x22eb90
/* 80241BD4  80 61 00 08 */	lwz r3, 8(r1)
/* 80241BD8  48 00 00 14 */	b 0x14
/* 80241BDC  38 81 00 0C */	addi r4, r1, 0xc
/* 80241BE0  38 A0 00 04 */	li r5, 4
/* 80241BE4  48 00 00 85 */	bl 0x84
/* 80241BE8  80 61 00 0C */	lwz r3, 0xc(r1)
/* 80241BEC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241BF0  7C 08 03 A6 */	mtlr r0
/* 80241BF4  38 21 00 10 */	addi r1, r1, 0x10
/* 80241BF8  4E 80 00 20 */	blr
/* 80241BFC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241C00  7C 08 02 A6 */	mflr r0
/* 80241C04  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241C08  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80241C0C  7C BF 2B 78 */	mr r31, r5
/* 80241C10  93 C1 00 08 */	stw r30, 8(r1)
/* 80241C14  7C 9E 23 78 */	mr r30, r4
/* 80241C18  A0 03 00 0C */	lhz r0, 0xc(r3)
/* 80241C1C  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80241C20  41 82 00 2C */	beq 0x2c
/* 80241C24  48 00 02 89 */	bl 0x288
/* 80241C28  3C A0 80 26 */	lis r5, 0x8026
/* 80241C2C  7C 66 1B 78 */	mr r6, r3
/* 80241C30  38 A5 82 30 */	addi r5, r5, -32208
/* 80241C34  7F C3 F3 78 */	mr r3, r30
/* 80241C38  7F E4 FB 78 */	mr r4, r31
/* 80241C3C  38 A5 00 56 */	addi r5, r5, 0x56
/* 80241C40  4C C6 31 82 */	crclr 6
/* 80241C44  4B DC FC F5 */	bl -0x23030c
/* 80241C48  48 00 00 08 */	b 0x8
/* 80241C4C  48 00 00 1D */	bl 0x1c
/* 80241C50  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241C54  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80241C58  83 C1 00 08 */	lwz r30, 8(r1)
/* 80241C5C  7C 08 03 A6 */	mtlr r0
/* 80241C60  38 21 00 10 */	addi r1, r1, 0x10
/* 80241C64  4E 80 00 20 */	blr
/* 80241C68  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80241C6C  7C 08 02 A6 */	mflr r0
/* 80241C70  90 01 00 24 */	stw r0, 0x24(r1)
/* 80241C74  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80241C78  7C BF 2B 78 */	mr r31, r5
/* 80241C7C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80241C80  7C 9E 23 78 */	mr r30, r4
/* 80241C84  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80241C88  7C 7D 1B 78 */	mr r29, r3
/* 80241C8C  81 83 00 00 */	lwz r12, 0(r3)
/* 80241C90  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80241C94  7D 89 03 A6 */	mtctr r12
/* 80241C98  4E 80 04 21 */	bctrl
/* 80241C9C  81 9D 00 00 */	lwz r12, 0(r29)
/* 80241CA0  7F A3 EB 78 */	mr r3, r29
/* 80241CA4  7F C4 F3 78 */	mr r4, r30
/* 80241CA8  7F E5 FB 78 */	mr r5, r31
/* 80241CAC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80241CB0  7D 89 03 A6 */	mtctr r12
/* 80241CB4  4E 80 04 21 */	bctrl
/* 80241CB8  80 1D 00 08 */	lwz r0, 8(r29)
/* 80241CBC  7C 00 FA 14 */	add r0, r0, r31
/* 80241CC0  90 1D 00 08 */	stw r0, 8(r29)
/* 80241CC4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80241CC8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80241CCC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80241CD0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80241CD4  7C 08 03 A6 */	mtlr r0
/* 80241CD8  38 21 00 20 */	addi r1, r1, 0x20
/* 80241CDC  4E 80 00 20 */	blr
/* 80241CE0  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80241CE4  7C 08 02 A6 */	mflr r0
/* 80241CE8  90 01 00 24 */	stw r0, 0x24(r1)
/* 80241CEC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80241CF0  7C 7F 1B 78 */	mr r31, r3
/* 80241CF4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80241CF8  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80241CFC  48 00 02 D1 */	bl 0x2d0
/* 80241D00  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 80241D04  3B A0 00 01 */	li r29, 1
/* 80241D08  98 64 00 00 */	stb r3, 0(r4)
/* 80241D0C  48 00 01 5C */	b 0x15c
/* 80241D10  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241D14  7F E3 FB 78 */	mr r3, r31
/* 80241D18  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80241D1C  7D 89 03 A6 */	mtctr r12
/* 80241D20  4E 80 04 21 */	bctrl
/* 80241D24  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241D28  7F E3 FB 78 */	mr r3, r31
/* 80241D2C  38 81 00 0A */	addi r4, r1, 0xa
/* 80241D30  38 A0 00 01 */	li r5, 1
/* 80241D34  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80241D38  7D 89 03 A6 */	mtctr r12
/* 80241D3C  4E 80 04 21 */	bctrl
/* 80241D40  80 9F 00 08 */	lwz r4, 8(r31)
/* 80241D44  7F E3 FB 78 */	mr r3, r31
/* 80241D48  38 04 00 01 */	addi r0, r4, 1
/* 80241D4C  90 1F 00 08 */	stw r0, 8(r31)
/* 80241D50  88 01 00 0A */	lbz r0, 0xa(r1)
/* 80241D54  7C 1E 07 74 */	extsb r30, r0
/* 80241D58  7F C4 F3 78 */	mr r4, r30
/* 80241D5C  48 00 01 B1 */	bl 0x1b0
/* 80241D60  2C 03 00 00 */	cmpwi r3, 0
/* 80241D64  41 82 00 F0 */	beq 0xf0
/* 80241D68  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80241D6C  38 00 00 00 */	li r0, 0
/* 80241D70  7C 03 E9 AE */	stbx r0, r3, r29
/* 80241D74  88 1F 00 1C */	lbz r0, 0x1c(r31)
/* 80241D78  2C 00 00 00 */	cmpwi r0, 0
/* 80241D7C  40 82 01 14 */	bne 0x114
/* 80241D80  2C 1E 00 23 */	cmpwi r30, 0x23
/* 80241D84  40 82 01 0C */	bne 0x10c
/* 80241D88  48 00 00 AC */	b 0xac
/* 80241D8C  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241D90  7F E3 FB 78 */	mr r3, r31
/* 80241D94  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80241D98  7D 89 03 A6 */	mtctr r12
/* 80241D9C  4E 80 04 21 */	bctrl
/* 80241DA0  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241DA4  7F E3 FB 78 */	mr r3, r31
/* 80241DA8  38 81 00 09 */	addi r4, r1, 9
/* 80241DAC  38 A0 00 01 */	li r5, 1
/* 80241DB0  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80241DB4  7D 89 03 A6 */	mtctr r12
/* 80241DB8  4E 80 04 21 */	bctrl
/* 80241DBC  80 9F 00 08 */	lwz r4, 8(r31)
/* 80241DC0  7F E3 FB 78 */	mr r3, r31
/* 80241DC4  38 04 00 01 */	addi r0, r4, 1
/* 80241DC8  90 1F 00 08 */	stw r0, 8(r31)
/* 80241DCC  88 01 00 09 */	lbz r0, 9(r1)
/* 80241DD0  7C 1E 07 74 */	extsb r30, r0
/* 80241DD4  7F C4 F3 78 */	mr r4, r30
/* 80241DD8  48 00 01 C5 */	bl 0x1c4
/* 80241DDC  2C 03 00 00 */	cmpwi r3, 0
/* 80241DE0  41 82 00 44 */	beq 0x44
/* 80241DE4  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241DE8  7F E3 FB 78 */	mr r3, r31
/* 80241DEC  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80241DF0  7D 89 03 A6 */	mtctr r12
/* 80241DF4  4E 80 04 21 */	bctrl
/* 80241DF8  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241DFC  7F E3 FB 78 */	mr r3, r31
/* 80241E00  38 81 00 08 */	addi r4, r1, 8
/* 80241E04  38 A0 00 01 */	li r5, 1
/* 80241E08  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80241E0C  7D 89 03 A6 */	mtctr r12
/* 80241E10  4E 80 04 21 */	bctrl
/* 80241E14  80 7F 00 08 */	lwz r3, 8(r31)
/* 80241E18  38 03 00 01 */	addi r0, r3, 1
/* 80241E1C  90 1F 00 08 */	stw r0, 8(r31)
/* 80241E20  48 00 00 14 */	b 0x14
/* 80241E24  2C 1E 00 0D */	cmpwi r30, 0xd
/* 80241E28  41 82 00 68 */	beq 0x68
/* 80241E2C  2C 1E 00 0A */	cmpwi r30, 0xa
/* 80241E30  41 82 00 60 */	beq 0x60
/* 80241E34  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241E38  7F E3 FB 78 */	mr r3, r31
/* 80241E3C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80241E40  7D 89 03 A6 */	mtctr r12
/* 80241E44  4E 80 04 21 */	bctrl
/* 80241E48  2C 03 00 00 */	cmpwi r3, 0
/* 80241E4C  41 82 FF 40 */	beq -0xc0
/* 80241E50  48 00 00 40 */	b 0x40
/* 80241E54  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80241E58  2C 1E 00 00 */	cmpwi r30, 0
/* 80241E5C  7F C3 E9 AE */	stbx r30, r3, r29
/* 80241E60  3B BD 00 01 */	addi r29, r29, 1
/* 80241E64  41 82 00 2C */	beq 0x2c
/* 80241E68  81 9F 00 00 */	lwz r12, 0(r31)
/* 80241E6C  7F E3 FB 78 */	mr r3, r31
/* 80241E70  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80241E74  7D 89 03 A6 */	mtctr r12
/* 80241E78  4E 80 04 21 */	bctrl
/* 80241E7C  2C 03 00 00 */	cmpwi r3, 0
/* 80241E80  40 82 00 10 */	bne 0x10
/* 80241E84  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 80241E88  7C 1D 00 00 */	cmpw r29, r0
/* 80241E8C  41 80 FE 84 */	blt -0x17c
/* 80241E90  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80241E94  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80241E98  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80241E9C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 80241EA0  7C 08 03 A6 */	mtlr r0
/* 80241EA4  38 21 00 20 */	addi r1, r1, 0x20
/* 80241EA8  4E 80 00 20 */	blr
/* 80241EAC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80241EB0  7C 08 02 A6 */	mflr r0
/* 80241EB4  90 01 00 14 */	stw r0, 0x14(r1)
/* 80241EB8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80241EBC  7C 7F 1B 78 */	mr r31, r3
/* 80241EC0  A0 03 00 0C */	lhz r0, 0xc(r3)
/* 80241EC4  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80241EC8  40 82 00 0C */	bne 0xc
/* 80241ECC  38 60 00 00 */	li r3, 0
/* 80241ED0  48 00 00 28 */	b 0x28
/* 80241ED4  88 03 00 04 */	lbz r0, 4(r3)
/* 80241ED8  2C 00 00 00 */	cmpwi r0, 0
/* 80241EDC  41 82 00 14 */	beq 0x14
/* 80241EE0  38 00 00 00 */	li r0, 0
/* 80241EE4  98 03 00 04 */	stb r0, 4(r3)
/* 80241EE8  80 63 00 10 */	lwz r3, 0x10(r3)
/* 80241EEC  48 00 00 0C */	b 0xc
/* 80241EF0  4B FF FD F1 */	bl -0x210
/* 80241EF4  80 7F 00 10 */	lwz r3, 0x10(r31)
/* 80241EF8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80241EFC  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 80241F00  7C 08 03 A6 */	mtlr r0
/* 80241F04  38 21 00 10 */	addi r1, r1, 0x10
/* 80241F08  4E 80 00 20 */	blr
/* 80241F0C  54 85 06 3E */	clrlwi r5, r4, 0x18
/* 80241F10  38 E0 00 01 */	li r7, 1
/* 80241F14  38 C5 00 F7 */	addi r6, r5, 0xf7
/* 80241F18  39 00 00 01 */	li r8, 1
/* 80241F1C  54 C0 06 3E */	clrlwi r0, r6, 0x18
/* 80241F20  39 20 00 00 */	li r9, 0
/* 80241F24  28 00 00 17 */	cmplwi r0, 0x17
/* 80241F28  41 81 00 20 */	bgt 0x20
/* 80241F2C  38 00 00 01 */	li r0, 1
/* 80241F30  3C A0 00 80 */	lis r5, 0x80
/* 80241F34  7C 06 30 30 */	slw r6, r0, r6
/* 80241F38  38 05 00 13 */	addi r0, r5, 0x13
/* 80241F3C  7C C0 00 39 */	and. r0, r6, r0
/* 80241F40  41 82 00 08 */	beq 0x8
/* 80241F44  39 20 00 01 */	li r9, 1
/* 80241F48  2C 09 00 00 */	cmpwi r9, 0
/* 80241F4C  40 82 00 30 */	bne 0x30
/* 80241F50  88 03 00 1C */	lbz r0, 0x1c(r3)
/* 80241F54  38 60 00 00 */	li r3, 0
/* 80241F58  2C 00 00 00 */	cmpwi r0, 0
/* 80241F5C  40 82 00 14 */	bne 0x14
/* 80241F60  7C 80 07 74 */	extsb r0, r4
/* 80241F64  2C 00 00 23 */	cmpwi r0, 0x23
/* 80241F68  40 82 00 08 */	bne 0x8
/* 80241F6C  38 60 00 01 */	li r3, 1
/* 80241F70  2C 03 00 00 */	cmpwi r3, 0
/* 80241F74  40 82 00 08 */	bne 0x8
/* 80241F78  39 00 00 00 */	li r8, 0
/* 80241F7C  2C 08 00 00 */	cmpwi r8, 0
/* 80241F80  40 82 00 14 */	bne 0x14
/* 80241F84  7C 80 07 74 */	extsb r0, r4
/* 80241F88  2C 00 00 21 */	cmpwi r0, 0x21
/* 80241F8C  41 82 00 08 */	beq 0x8
/* 80241F90  38 E0 00 00 */	li r7, 0
/* 80241F94  7C E3 3B 78 */	mr r3, r7
/* 80241F98  4E 80 00 20 */	blr
/* 80241F9C  54 80 06 3E */	clrlwi r0, r4, 0x18
/* 80241FA0  38 60 00 00 */	li r3, 0
/* 80241FA4  28 00 00 81 */	cmplwi r0, 0x81
/* 80241FA8  41 80 00 0C */	blt 0xc
/* 80241FAC  28 00 00 9F */	cmplwi r0, 0x9f
/* 80241FB0  40 81 00 14 */	ble 0x14
/* 80241FB4  28 00 00 E0 */	cmplwi r0, 0xe0
/* 80241FB8  4D 80 00 20 */	bltlr
/* 80241FBC  28 00 00 FC */	cmplwi r0, 0xfc
/* 80241FC0  4D 81 00 20 */	bgtlr
/* 80241FC4  38 60 00 01 */	li r3, 1
/* 80241FC8  4E 80 00 20 */	blr
/* 80241FCC  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80241FD0  7C 08 02 A6 */	mflr r0
/* 80241FD4  90 01 00 24 */	stw r0, 0x24(r1)
/* 80241FD8  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80241FDC  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80241FE0  7C 7E 1B 78 */	mr r30, r3
/* 80241FE4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 80241FE8  93 81 00 10 */	stw r28, 0x10(r1)
/* 80241FEC  A0 03 00 0C */	lhz r0, 0xc(r3)
/* 80241FF0  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80241FF4  41 82 01 BC */	beq 0x1bc
/* 80241FF8  3B E0 00 00 */	li r31, 0
/* 80241FFC  3B 80 00 01 */	li r28, 1
/* 80242000  3F A0 00 80 */	lis r29, 0x80
/* 80242004  48 00 01 90 */	b 0x190
/* 80242008  81 9E 00 00 */	lwz r12, 0(r30)
/* 8024200C  7F C3 F3 78 */	mr r3, r30
/* 80242010  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80242014  7D 89 03 A6 */	mtctr r12
/* 80242018  4E 80 04 21 */	bctrl
/* 8024201C  81 9E 00 00 */	lwz r12, 0(r30)
/* 80242020  7F C3 F3 78 */	mr r3, r30
/* 80242024  38 81 00 09 */	addi r4, r1, 9
/* 80242028  38 A0 00 01 */	li r5, 1
/* 8024202C  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 80242030  7D 89 03 A6 */	mtctr r12
/* 80242034  4E 80 04 21 */	bctrl
/* 80242038  80 7E 00 08 */	lwz r3, 8(r30)
/* 8024203C  2C 1F 00 00 */	cmpwi r31, 0
/* 80242040  38 03 00 01 */	addi r0, r3, 1
/* 80242044  90 1E 00 08 */	stw r0, 8(r30)
/* 80242048  88 01 00 09 */	lbz r0, 9(r1)
/* 8024204C  7C 03 07 74 */	extsb r3, r0
/* 80242050  41 82 00 A0 */	beq 0xa0
/* 80242054  54 64 06 3E */	clrlwi r4, r3, 0x18
/* 80242058  38 00 00 00 */	li r0, 0
/* 8024205C  28 04 00 81 */	cmplwi r4, 0x81
/* 80242060  41 80 00 0C */	blt 0xc
/* 80242064  28 04 00 9F */	cmplwi r4, 0x9f
/* 80242068  40 81 00 14 */	ble 0x14
/* 8024206C  28 04 00 E0 */	cmplwi r4, 0xe0
/* 80242070  41 80 00 10 */	blt 0x10
/* 80242074  28 04 00 FC */	cmplwi r4, 0xfc
/* 80242078  41 81 00 08 */	bgt 0x8
/* 8024207C  38 00 00 01 */	li r0, 1
/* 80242080  2C 00 00 00 */	cmpwi r0, 0
/* 80242084  41 82 00 44 */	beq 0x44
/* 80242088  81 9E 00 00 */	lwz r12, 0(r30)
/* 8024208C  7F C3 F3 78 */	mr r3, r30
/* 80242090  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 80242094  7D 89 03 A6 */	mtctr r12
/* 80242098  4E 80 04 21 */	bctrl
/* 8024209C  81 9E 00 00 */	lwz r12, 0(r30)
/* 802420A0  7F C3 F3 78 */	mr r3, r30
/* 802420A4  38 81 00 08 */	addi r4, r1, 8
/* 802420A8  38 A0 00 01 */	li r5, 1
/* 802420AC  81 8C 00 0C */	lwz r12, 0xc(r12)
/* 802420B0  7D 89 03 A6 */	mtctr r12
/* 802420B4  4E 80 04 21 */	bctrl
/* 802420B8  80 7E 00 08 */	lwz r3, 8(r30)
/* 802420BC  38 03 00 01 */	addi r0, r3, 1
/* 802420C0  90 1E 00 08 */	stw r0, 8(r30)
/* 802420C4  48 00 00 D0 */	b 0xd0
/* 802420C8  2C 03 00 0D */	cmpwi r3, 0xd
/* 802420CC  38 00 00 00 */	li r0, 0
/* 802420D0  41 82 00 0C */	beq 0xc
/* 802420D4  2C 03 00 0A */	cmpwi r3, 0xa
/* 802420D8  40 82 00 08 */	bne 0x8
/* 802420DC  38 00 00 01 */	li r0, 1
/* 802420E0  2C 00 00 00 */	cmpwi r0, 0
/* 802420E4  41 82 00 B0 */	beq 0xb0
/* 802420E8  3B E0 00 00 */	li r31, 0
/* 802420EC  48 00 00 A8 */	b 0xa8
/* 802420F0  89 1E 00 1C */	lbz r8, 0x1c(r30)
/* 802420F4  2C 08 00 00 */	cmpwi r8, 0
/* 802420F8  40 82 00 0C */	bne 0xc
/* 802420FC  2C 03 00 23 */	cmpwi r3, 0x23
/* 80242100  41 82 00 0C */	beq 0xc
/* 80242104  2C 03 00 21 */	cmpwi r3, 0x21
/* 80242108  40 82 00 0C */	bne 0xc
/* 8024210C  3B E0 00 01 */	li r31, 1
/* 80242110  48 00 00 84 */	b 0x84
/* 80242114  54 64 06 3E */	clrlwi r4, r3, 0x18
/* 80242118  38 A0 00 01 */	li r5, 1
/* 8024211C  38 84 00 F7 */	addi r4, r4, 0xf7
/* 80242120  38 C0 00 01 */	li r6, 1
/* 80242124  54 80 06 3E */	clrlwi r0, r4, 0x18
/* 80242128  38 E0 00 00 */	li r7, 0
/* 8024212C  28 00 00 17 */	cmplwi r0, 0x17
/* 80242130  41 81 00 18 */	bgt 0x18
/* 80242134  7F 84 20 30 */	slw r4, r28, r4
/* 80242138  38 1D 00 13 */	addi r0, r29, 0x13
/* 8024213C  7C 80 00 39 */	and. r0, r4, r0
/* 80242140  41 82 00 08 */	beq 0x8
/* 80242144  38 E0 00 01 */	li r7, 1
/* 80242148  2C 07 00 00 */	cmpwi r7, 0
/* 8024214C  40 82 00 28 */	bne 0x28
/* 80242150  2C 08 00 00 */	cmpwi r8, 0
/* 80242154  38 00 00 00 */	li r0, 0
/* 80242158  40 82 00 10 */	bne 0x10
/* 8024215C  2C 03 00 23 */	cmpwi r3, 0x23
/* 80242160  40 82 00 08 */	bne 0x8
/* 80242164  38 00 00 01 */	li r0, 1
/* 80242168  2C 00 00 00 */	cmpwi r0, 0
/* 8024216C  40 82 00 08 */	bne 0x8
/* 80242170  38 C0 00 00 */	li r6, 0
/* 80242174  2C 06 00 00 */	cmpwi r6, 0
/* 80242178  40 82 00 10 */	bne 0x10
/* 8024217C  2C 03 00 21 */	cmpwi r3, 0x21
/* 80242180  41 82 00 08 */	beq 0x8
/* 80242184  38 A0 00 00 */	li r5, 0
/* 80242188  2C 05 00 00 */	cmpwi r5, 0
/* 8024218C  40 82 00 08 */	bne 0x8
/* 80242190  48 00 00 24 */	b 0x24
/* 80242194  81 9E 00 00 */	lwz r12, 0(r30)
/* 80242198  7F C3 F3 78 */	mr r3, r30
/* 8024219C  81 8C 00 14 */	lwz r12, 0x14(r12)
/* 802421A0  7D 89 03 A6 */	mtctr r12
/* 802421A4  4E 80 04 21 */	bctrl
/* 802421A8  2C 03 00 00 */	cmpwi r3, 0
/* 802421AC  41 82 FE 5C */	beq -0x1a4
/* 802421B0  38 60 00 00 */	li r3, 0
/* 802421B4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 802421B8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 802421BC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 802421C0  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 802421C4  83 81 00 10 */	lwz r28, 0x10(r1)
/* 802421C8  7C 08 03 A6 */	mtlr r0
/* 802421CC  38 21 00 20 */	addi r1, r1, 0x20
/* 802421D0  4E 80 00 20 */	blr
/* 802421D4  3C E0 80 38 */	lis r7, 0x8038
/* 802421D8  3C C0 80 2A */	lis r6, 0x802a
/* 802421DC  39 00 00 00 */	li r8, 0
/* 802421E0  38 00 04 00 */	li r0, 0x400
/* 802421E4  38 E7 45 60 */	addi r7, r7, 0x4560
/* 802421E8  38 C6 3F 50 */	addi r6, r6, 0x3f50
/* 802421EC  99 03 00 04 */	stb r8, 4(r3)
/* 802421F0  B1 03 00 0C */	sth r8, 0xc(r3)
/* 802421F4  91 03 00 08 */	stw r8, 8(r3)
/* 802421F8  91 03 00 18 */	stw r8, 0x18(r3)
/* 802421FC  90 03 00 14 */	stw r0, 0x14(r3)
/* 80242200  90 E3 00 10 */	stw r7, 0x10(r3)
/* 80242204  99 03 00 1C */	stb r8, 0x1c(r3)
/* 80242208  90 C3 00 00 */	stw r6, 0(r3)
/* 8024220C  90 83 00 20 */	stw r4, 0x20(r3)
/* 80242210  90 A3 00 24 */	stw r5, 0x24(r3)
/* 80242214  4E 80 00 20 */	blr
/* 80242218  28 05 00 00 */	cmplwi r5, 0
/* 8024221C  38 E0 00 00 */	li r7, 0
/* 80242220  4C 81 00 20 */	blelr
/* 80242224  54 A0 E8 FF */	rlwinm. r0, r5, 0x1d, 3, 0x1f
/* 80242228  7C 09 03 A6 */	mtctr r0
/* 8024222C  41 82 00 D4 */	beq 0xd4
/* 80242230  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242234  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242238  7C 07 02 14 */	add r0, r7, r0
/* 8024223C  38 E7 00 01 */	addi r7, r7, 1
/* 80242240  7C 06 00 AE */	lbzx r0, r6, r0
/* 80242244  98 04 00 00 */	stb r0, 0(r4)
/* 80242248  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8024224C  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242250  7C 07 02 14 */	add r0, r7, r0
/* 80242254  38 E7 00 01 */	addi r7, r7, 1
/* 80242258  7C 06 00 AE */	lbzx r0, r6, r0
/* 8024225C  98 04 00 01 */	stb r0, 1(r4)
/* 80242260  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242264  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242268  7C 07 02 14 */	add r0, r7, r0
/* 8024226C  38 E7 00 01 */	addi r7, r7, 1
/* 80242270  7C 06 00 AE */	lbzx r0, r6, r0
/* 80242274  98 04 00 02 */	stb r0, 2(r4)
/* 80242278  80 03 00 20 */	lwz r0, 0x20(r3)
/* 8024227C  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242280  7C 07 02 14 */	add r0, r7, r0
/* 80242284  38 E7 00 01 */	addi r7, r7, 1
/* 80242288  7C 06 00 AE */	lbzx r0, r6, r0
/* 8024228C  98 04 00 03 */	stb r0, 3(r4)
/* 80242290  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242294  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242298  7C 07 02 14 */	add r0, r7, r0
/* 8024229C  38 E7 00 01 */	addi r7, r7, 1
/* 802422A0  7C 06 00 AE */	lbzx r0, r6, r0
/* 802422A4  98 04 00 04 */	stb r0, 4(r4)
/* 802422A8  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802422AC  80 C3 00 08 */	lwz r6, 8(r3)
/* 802422B0  7C 07 02 14 */	add r0, r7, r0
/* 802422B4  38 E7 00 01 */	addi r7, r7, 1
/* 802422B8  7C 06 00 AE */	lbzx r0, r6, r0
/* 802422BC  98 04 00 05 */	stb r0, 5(r4)
/* 802422C0  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802422C4  80 C3 00 08 */	lwz r6, 8(r3)
/* 802422C8  7C 07 02 14 */	add r0, r7, r0
/* 802422CC  38 E7 00 01 */	addi r7, r7, 1
/* 802422D0  7C 06 00 AE */	lbzx r0, r6, r0
/* 802422D4  98 04 00 06 */	stb r0, 6(r4)
/* 802422D8  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802422DC  80 C3 00 08 */	lwz r6, 8(r3)
/* 802422E0  7C 07 02 14 */	add r0, r7, r0
/* 802422E4  38 E7 00 01 */	addi r7, r7, 1
/* 802422E8  7C 06 00 AE */	lbzx r0, r6, r0
/* 802422EC  98 04 00 07 */	stb r0, 7(r4)
/* 802422F0  38 84 00 08 */	addi r4, r4, 8
/* 802422F4  42 00 FF 3C */	bdnz -0xc4
/* 802422F8  70 A5 00 07 */	andi. r5, r5, 7
/* 802422FC  4D 82 00 20 */	beqlr
/* 80242300  7C A9 03 A6 */	mtctr r5
/* 80242304  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242308  80 C3 00 08 */	lwz r6, 8(r3)
/* 8024230C  7C 07 02 14 */	add r0, r7, r0
/* 80242310  38 E7 00 01 */	addi r7, r7, 1
/* 80242314  7C 06 00 AE */	lbzx r0, r6, r0
/* 80242318  98 04 00 00 */	stb r0, 0(r4)
/* 8024231C  38 84 00 01 */	addi r4, r4, 1
/* 80242320  42 00 FF E4 */	bdnz -0x1c
/* 80242324  4E 80 00 20 */	blr
/* 80242328  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 8024232C  80 83 00 20 */	lwz r4, 0x20(r3)
/* 80242330  80 03 00 08 */	lwz r0, 8(r3)
/* 80242334  7C A4 02 14 */	add r5, r4, r0
/* 80242338  7C C4 00 AE */	lbzx r6, r4, r0
/* 8024233C  88 85 00 01 */	lbz r4, 1(r5)
/* 80242340  88 65 00 02 */	lbz r3, 2(r5)
/* 80242344  88 05 00 03 */	lbz r0, 3(r5)
/* 80242348  98 C1 00 08 */	stb r6, 8(r1)
/* 8024234C  98 81 00 09 */	stb r4, 9(r1)
/* 80242350  98 61 00 0A */	stb r3, 0xa(r1)
/* 80242354  98 01 00 0B */	stb r0, 0xb(r1)
/* 80242358  80 61 00 08 */	lwz r3, 8(r1)
/* 8024235C  38 21 00 10 */	addi r1, r1, 0x10
/* 80242360  4E 80 00 20 */	blr
/* 80242364  28 05 00 00 */	cmplwi r5, 0
/* 80242368  39 00 00 00 */	li r8, 0
/* 8024236C  4C 81 00 20 */	blelr
/* 80242370  54 A0 E8 FF */	rlwinm. r0, r5, 0x1d, 3, 0x1f
/* 80242374  7C 09 03 A6 */	mtctr r0
/* 80242378  41 82 00 D4 */	beq 0xd4
/* 8024237C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242380  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242384  7C 08 02 14 */	add r0, r8, r0
/* 80242388  88 E4 00 00 */	lbz r7, 0(r4)
/* 8024238C  7C E6 01 AE */	stbx r7, r6, r0
/* 80242390  39 08 00 01 */	addi r8, r8, 1
/* 80242394  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242398  80 C3 00 08 */	lwz r6, 8(r3)
/* 8024239C  7C 08 02 14 */	add r0, r8, r0
/* 802423A0  88 E4 00 01 */	lbz r7, 1(r4)
/* 802423A4  7C E6 01 AE */	stbx r7, r6, r0
/* 802423A8  39 08 00 01 */	addi r8, r8, 1
/* 802423AC  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802423B0  80 C3 00 08 */	lwz r6, 8(r3)
/* 802423B4  7C 08 02 14 */	add r0, r8, r0
/* 802423B8  88 E4 00 02 */	lbz r7, 2(r4)
/* 802423BC  7C E6 01 AE */	stbx r7, r6, r0
/* 802423C0  39 08 00 01 */	addi r8, r8, 1
/* 802423C4  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802423C8  80 C3 00 08 */	lwz r6, 8(r3)
/* 802423CC  7C 08 02 14 */	add r0, r8, r0
/* 802423D0  88 E4 00 03 */	lbz r7, 3(r4)
/* 802423D4  7C E6 01 AE */	stbx r7, r6, r0
/* 802423D8  39 08 00 01 */	addi r8, r8, 1
/* 802423DC  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802423E0  80 C3 00 08 */	lwz r6, 8(r3)
/* 802423E4  7C 08 02 14 */	add r0, r8, r0
/* 802423E8  88 E4 00 04 */	lbz r7, 4(r4)
/* 802423EC  7C E6 01 AE */	stbx r7, r6, r0
/* 802423F0  39 08 00 01 */	addi r8, r8, 1
/* 802423F4  80 03 00 20 */	lwz r0, 0x20(r3)
/* 802423F8  80 C3 00 08 */	lwz r6, 8(r3)
/* 802423FC  7C 08 02 14 */	add r0, r8, r0
/* 80242400  88 E4 00 05 */	lbz r7, 5(r4)
/* 80242404  7C E6 01 AE */	stbx r7, r6, r0
/* 80242408  39 08 00 01 */	addi r8, r8, 1
/* 8024240C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242410  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242414  7C 08 02 14 */	add r0, r8, r0
/* 80242418  88 E4 00 06 */	lbz r7, 6(r4)
/* 8024241C  7C E6 01 AE */	stbx r7, r6, r0
/* 80242420  39 08 00 01 */	addi r8, r8, 1
/* 80242424  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242428  80 C3 00 08 */	lwz r6, 8(r3)
/* 8024242C  7C 08 02 14 */	add r0, r8, r0
/* 80242430  88 E4 00 07 */	lbz r7, 7(r4)
/* 80242434  7C E6 01 AE */	stbx r7, r6, r0
/* 80242438  39 08 00 01 */	addi r8, r8, 1
/* 8024243C  38 84 00 08 */	addi r4, r4, 8
/* 80242440  42 00 FF 3C */	bdnz -0xc4
/* 80242444  70 A5 00 07 */	andi. r5, r5, 7
/* 80242448  4D 82 00 20 */	beqlr
/* 8024244C  7C A9 03 A6 */	mtctr r5
/* 80242450  80 03 00 20 */	lwz r0, 0x20(r3)
/* 80242454  80 C3 00 08 */	lwz r6, 8(r3)
/* 80242458  7C 08 02 14 */	add r0, r8, r0
/* 8024245C  88 E4 00 00 */	lbz r7, 0(r4)
/* 80242460  7C E6 01 AE */	stbx r7, r6, r0
/* 80242464  39 08 00 01 */	addi r8, r8, 1
/* 80242468  38 84 00 01 */	addi r4, r4, 1
/* 8024246C  42 00 FF E4 */	bdnz -0x1c
/* 80242470  4E 80 00 20 */	blr
/* 80242474  80 83 00 08 */	lwz r4, 8(r3)
/* 80242478  80 03 00 24 */	lwz r0, 0x24(r3)
/* 8024247C  7C 80 02 78 */	xor r0, r4, r0
/* 80242480  7C 00 00 34 */	cntlzw r0, r0
/* 80242484  7C 80 00 30 */	slw r0, r4, r0
/* 80242488  54 03 0F FE */	srwi r3, r0, 0x1f
/* 8024248C  4E 80 00 20 */	blr
/* 80242490  4E 80 00 20 */	blr
/* 80242494  4E 80 00 20 */	blr
