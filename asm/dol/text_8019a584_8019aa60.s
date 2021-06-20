
.include "macros.inc"

.section .text, "ax" # 0x8019A584 - 0x8019AA60
/* 8019A584  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 8019A588  7C 08 02 A6 */	mflr r0
/* 8019A58C  C0 24 00 00 */	lfs f1, 0(r4)
/* 8019A590  90 01 00 44 */	stw r0, 0x44(r1)
/* 8019A594  C0 06 00 00 */	lfs f0, 0(r6)
/* 8019A598  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 8019A59C  7C BF 2B 78 */	mr r31, r5
/* 8019A5A0  EC 81 00 28 */	fsubs f4, f1, f0
/* 8019A5A4  C0 64 00 04 */	lfs f3, 4(r4)
/* 8019A5A8  93 C1 00 38 */	stw r30, 0x38(r1)
/* 8019A5AC  7C 9E 23 78 */	mr r30, r4
/* 8019A5B0  C0 46 00 04 */	lfs f2, 4(r6)
/* 8019A5B4  93 A1 00 34 */	stw r29, 0x34(r1)
/* 8019A5B8  EC 43 10 28 */	fsubs f2, f3, f2
/* 8019A5BC  C0 24 00 08 */	lfs f1, 8(r4)
/* 8019A5C0  C0 06 00 08 */	lfs f0, 8(r6)
/* 8019A5C4  7C 7D 1B 78 */	mr r29, r3
/* 8019A5C8  38 61 00 20 */	addi r3, r1, 0x20
/* 8019A5CC  D0 81 00 20 */	stfs f4, 0x20(r1)
/* 8019A5D0  EC 01 00 28 */	fsubs f0, f1, f0
/* 8019A5D4  D0 41 00 24 */	stfs f2, 0x24(r1)
/* 8019A5D8  7C 64 1B 78 */	mr r4, r3
/* 8019A5DC  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 8019A5E0  48 00 06 45 */	bl 0x644
/* 8019A5E4  7F E3 FB 78 */	mr r3, r31
/* 8019A5E8  38 81 00 20 */	addi r4, r1, 0x20
/* 8019A5EC  38 A1 00 14 */	addi r5, r1, 0x14
/* 8019A5F0  48 00 06 DD */	bl 0x6dc
/* 8019A5F4  38 61 00 14 */	addi r3, r1, 0x14
/* 8019A5F8  7C 64 1B 78 */	mr r4, r3
/* 8019A5FC  48 00 06 29 */	bl 0x628
/* 8019A600  38 61 00 20 */	addi r3, r1, 0x20
/* 8019A604  38 81 00 14 */	addi r4, r1, 0x14
/* 8019A608  38 A1 00 08 */	addi r5, r1, 8
/* 8019A60C  48 00 06 C1 */	bl 0x6c0
/* 8019A610  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 8019A614  C0 9E 00 00 */	lfs f4, 0(r30)
/* 8019A618  D0 1D 00 00 */	stfs f0, 0(r29)
/* 8019A61C  C0 7E 00 04 */	lfs f3, 4(r30)
/* 8019A620  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 8019A624  C0 BE 00 08 */	lfs f5, 8(r30)
/* 8019A628  D0 1D 00 04 */	stfs f0, 4(r29)
/* 8019A62C  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 8019A630  D0 1D 00 08 */	stfs f0, 8(r29)
/* 8019A634  C0 21 00 14 */	lfs f1, 0x14(r1)
/* 8019A638  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 8019A63C  EC 24 00 72 */	fmuls f1, f4, f1
/* 8019A640  C0 41 00 1C */	lfs f2, 0x1c(r1)
/* 8019A644  EC 03 00 32 */	fmuls f0, f3, f0
/* 8019A648  EC 45 00 B2 */	fmuls f2, f5, f2
/* 8019A64C  EC 01 00 2A */	fadds f0, f1, f0
/* 8019A650  EC 02 00 2A */	fadds f0, f2, f0
/* 8019A654  FC 00 00 50 */	fneg f0, f0
/* 8019A658  D0 1D 00 0C */	stfs f0, 0xc(r29)
/* 8019A65C  C0 01 00 08 */	lfs f0, 8(r1)
/* 8019A660  D0 1D 00 10 */	stfs f0, 0x10(r29)
/* 8019A664  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8019A668  D0 1D 00 14 */	stfs f0, 0x14(r29)
/* 8019A66C  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 8019A670  D0 1D 00 18 */	stfs f0, 0x18(r29)
/* 8019A674  C0 21 00 08 */	lfs f1, 8(r1)
/* 8019A678  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 8019A67C  C0 41 00 10 */	lfs f2, 0x10(r1)
/* 8019A680  EC 24 00 72 */	fmuls f1, f4, f1
/* 8019A684  EC 03 00 32 */	fmuls f0, f3, f0
/* 8019A688  EC 45 00 B2 */	fmuls f2, f5, f2
/* 8019A68C  EC 01 00 2A */	fadds f0, f1, f0
/* 8019A690  EC 02 00 2A */	fadds f0, f2, f0
/* 8019A694  FC 00 00 50 */	fneg f0, f0
/* 8019A698  D0 1D 00 1C */	stfs f0, 0x1c(r29)
/* 8019A69C  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 8019A6A0  D0 1D 00 20 */	stfs f0, 0x20(r29)
/* 8019A6A4  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 8019A6A8  D0 1D 00 24 */	stfs f0, 0x24(r29)
/* 8019A6AC  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 8019A6B0  D0 1D 00 28 */	stfs f0, 0x28(r29)
/* 8019A6B4  C0 21 00 20 */	lfs f1, 0x20(r1)
/* 8019A6B8  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 8019A6BC  C0 41 00 28 */	lfs f2, 0x28(r1)
/* 8019A6C0  EC 24 00 72 */	fmuls f1, f4, f1
/* 8019A6C4  EC 03 00 32 */	fmuls f0, f3, f0
/* 8019A6C8  EC 45 00 B2 */	fmuls f2, f5, f2
/* 8019A6CC  EC 01 00 2A */	fadds f0, f1, f0
/* 8019A6D0  EC 02 00 2A */	fadds f0, f2, f0
/* 8019A6D4  FC 00 00 50 */	fneg f0, f0
/* 8019A6D8  D0 1D 00 2C */	stfs f0, 0x2c(r29)
/* 8019A6DC  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 8019A6E0  83 C1 00 38 */	lwz r30, 0x38(r1)
/* 8019A6E4  83 A1 00 34 */	lwz r29, 0x34(r1)
/* 8019A6E8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 8019A6EC  7C 08 03 A6 */	mtlr r0
/* 8019A6F0  38 21 00 40 */	addi r1, r1, 0x40
/* 8019A6F4  4E 80 00 20 */	blr 
/* 8019A6F8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8019A6FC  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 8019A700  F3 E1 00 18 */	psq_st f31, 24(r1), 0, qr0
/* 8019A704  EC 04 18 28 */	fsubs f0, f4, f3
/* 8019A708  C1 42 98 D4 */	lfs f10, -0x672c(r2)
/* 8019A70C  C1 82 98 D0 */	lfs f12, -0x6730(r2)
/* 8019A710  ED 21 10 28 */	fsubs f9, f1, f2
/* 8019A714  C1 62 98 E0 */	lfs f11, -0x6720(r2)
/* 8019A718  EC 64 18 2A */	fadds f3, f4, f3
/* 8019A71C  ED AC 00 24 */	fdivs f13, f12, f0
/* 8019A720  C0 02 98 E4 */	lfs f0, -0x671c(r2)
/* 8019A724  C3 E1 00 28 */	lfs f31, 0x28(r1)
/* 8019A728  D0 03 00 28 */	stfs f0, 0x28(r3)
/* 8019A72C  D1 43 00 04 */	stfs f10, 4(r3)
/* 8019A730  D1 43 00 0C */	stfs f10, 0xc(r3)
/* 8019A734  EC 8B 01 72 */	fmuls f4, f11, f5
/* 8019A738  D1 43 00 10 */	stfs f10, 0x10(r3)
/* 8019A73C  EC 01 10 2A */	fadds f0, f1, f2
/* 8019A740  EC 2D 00 F2 */	fmuls f1, f13, f3
/* 8019A744  D1 43 00 1C */	stfs f10, 0x1c(r3)
/* 8019A748  EC AC 48 24 */	fdivs f5, f12, f9
/* 8019A74C  D1 43 00 20 */	stfs f10, 0x20(r3)
/* 8019A750  D1 43 00 24 */	stfs f10, 0x24(r3)
/* 8019A754  D1 43 00 2C */	stfs f10, 0x2c(r3)
/* 8019A758  EC 46 00 72 */	fmuls f2, f6, f1
/* 8019A75C  EC 05 00 32 */	fmuls f0, f5, f0
/* 8019A760  EC 64 03 72 */	fmuls f3, f4, f13
/* 8019A764  EC 24 01 72 */	fmuls f1, f4, f5
/* 8019A768  EC 07 00 32 */	fmuls f0, f7, f0
/* 8019A76C  EC 66 00 F2 */	fmuls f3, f6, f3
/* 8019A770  EC 42 40 28 */	fsubs f2, f2, f8
/* 8019A774  EC 27 00 72 */	fmuls f1, f7, f1
/* 8019A778  EC 00 F8 28 */	fsubs f0, f0, f31
/* 8019A77C  D0 63 00 00 */	stfs f3, 0(r3)
/* 8019A780  D0 43 00 08 */	stfs f2, 8(r3)
/* 8019A784  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8019A788  D0 03 00 18 */	stfs f0, 0x18(r3)
/* 8019A78C  E3 E1 00 18 */	psq_l f31, 24(r1), 0, qr0
/* 8019A790  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 8019A794  38 21 00 20 */	addi r1, r1, 0x20
/* 8019A798  4E 80 00 20 */	blr 
/* 8019A79C  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 8019A7A0  7C 08 02 A6 */	mflr r0
/* 8019A7A4  90 01 00 64 */	stw r0, 0x64(r1)
/* 8019A7A8  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 8019A7AC  F3 E1 00 58 */	psq_st f31, 88(r1), 0, qr0
/* 8019A7B0  DB C1 00 40 */	stfd f30, 0x40(r1)
/* 8019A7B4  F3 C1 00 48 */	psq_st f30, 72(r1), 0, qr0
/* 8019A7B8  DB A1 00 30 */	stfd f29, 0x30(r1)
/* 8019A7BC  F3 A1 00 38 */	psq_st f29, 56(r1), 0, qr0
/* 8019A7C0  DB 81 00 20 */	stfd f28, 0x20(r1)
/* 8019A7C4  F3 81 00 28 */	psq_st f28, 40(r1), 0, qr0
/* 8019A7C8  DB 61 00 10 */	stfd f27, 0x10(r1)
/* 8019A7CC  F3 61 00 18 */	psq_st f27, 24(r1), 0, qr0
/* 8019A7D0  FF 60 10 90 */	fmr f27, f2
/* 8019A7D4  C0 E2 98 D8 */	lfs f7, -0x6728(r2)
/* 8019A7D8  FF 80 18 90 */	fmr f28, f3
/* 8019A7DC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 8019A7E0  FF A0 20 90 */	fmr f29, f4
/* 8019A7E4  EC 27 00 72 */	fmuls f1, f7, f1
/* 8019A7E8  C0 02 98 E8 */	lfs f0, -0x6718(r2)
/* 8019A7EC  FF C0 28 90 */	fmr f30, f5
/* 8019A7F0  FF E0 30 90 */	fmr f31, f6
/* 8019A7F4  7C 7F 1B 78 */	mr r31, r3
/* 8019A7F8  EC 20 00 72 */	fmuls f1, f0, f1
/* 8019A7FC  4B E8 13 69 */	bl -0x17ec98
/* 8019A800  FC A0 08 18 */	frsp f5, f1
/* 8019A804  C0 62 98 D4 */	lfs f3, -0x672c(r2)
/* 8019A808  C0 82 98 D0 */	lfs f4, -0x6730(r2)
/* 8019A80C  FC 20 F8 50 */	fneg f1, f31
/* 8019A810  C0 02 98 E4 */	lfs f0, -0x671c(r2)
/* 8019A814  FC 40 F0 50 */	fneg f2, f30
/* 8019A818  EC 84 28 24 */	fdivs f4, f4, f5
/* 8019A81C  D0 3F 00 18 */	stfs f1, 0x18(r31)
/* 8019A820  D0 1F 00 28 */	stfs f0, 0x28(r31)
/* 8019A824  D0 7F 00 04 */	stfs f3, 4(r31)
/* 8019A828  D0 5F 00 08 */	stfs f2, 8(r31)
/* 8019A82C  D0 7F 00 0C */	stfs f3, 0xc(r31)
/* 8019A830  EC 24 D8 24 */	fdivs f1, f4, f27
/* 8019A834  D0 7F 00 10 */	stfs f3, 0x10(r31)
/* 8019A838  D0 7F 00 1C */	stfs f3, 0x1c(r31)
/* 8019A83C  D0 7F 00 20 */	stfs f3, 0x20(r31)
/* 8019A840  D0 7F 00 24 */	stfs f3, 0x24(r31)
/* 8019A844  D0 7F 00 2C */	stfs f3, 0x2c(r31)
/* 8019A848  EC 3C 00 72 */	fmuls f1, f28, f1
/* 8019A84C  EC 04 07 72 */	fmuls f0, f4, f29
/* 8019A850  D0 3F 00 00 */	stfs f1, 0(r31)
/* 8019A854  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 8019A858  E3 E1 00 58 */	psq_l f31, 88(r1), 0, qr0
/* 8019A85C  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 8019A860  E3 C1 00 48 */	psq_l f30, 72(r1), 0, qr0
/* 8019A864  CB C1 00 40 */	lfd f30, 0x40(r1)
/* 8019A868  E3 A1 00 38 */	psq_l f29, 56(r1), 0, qr0
/* 8019A86C  CB A1 00 30 */	lfd f29, 0x30(r1)
/* 8019A870  E3 81 00 28 */	psq_l f28, 40(r1), 0, qr0
/* 8019A874  CB 81 00 20 */	lfd f28, 0x20(r1)
/* 8019A878  E3 61 00 18 */	psq_l f27, 24(r1), 0, qr0
/* 8019A87C  CB 61 00 10 */	lfd f27, 0x10(r1)
/* 8019A880  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8019A884  80 01 00 64 */	lwz r0, 0x64(r1)
/* 8019A888  7C 08 03 A6 */	mtlr r0
/* 8019A88C  38 21 00 60 */	addi r1, r1, 0x60
/* 8019A890  4E 80 00 20 */	blr 
/* 8019A894  ED 64 18 28 */	fsubs f11, f4, f3
/* 8019A898  C1 22 98 D4 */	lfs f9, -0x672c(r2)
/* 8019A89C  C1 42 98 D0 */	lfs f10, -0x6730(r2)
/* 8019A8A0  EC 01 10 28 */	fsubs f0, f1, f2
/* 8019A8A4  EC 64 18 2A */	fadds f3, f4, f3
/* 8019A8A8  C0 82 98 E0 */	lfs f4, -0x6720(r2)
/* 8019A8AC  ED 8A 58 24 */	fdivs f12, f10, f11
/* 8019A8B0  D1 23 00 04 */	stfs f9, 4(r3)
/* 8019A8B4  D1 23 00 08 */	stfs f9, 8(r3)
/* 8019A8B8  D1 23 00 10 */	stfs f9, 0x10(r3)
/* 8019A8BC  D1 23 00 18 */	stfs f9, 0x18(r3)
/* 8019A8C0  D1 23 00 20 */	stfs f9, 0x20(r3)
/* 8019A8C4  ED 6A 00 24 */	fdivs f11, f10, f0
/* 8019A8C8  D1 23 00 24 */	stfs f9, 0x24(r3)
/* 8019A8CC  D1 23 00 28 */	stfs f9, 0x28(r3)
/* 8019A8D0  D1 43 00 2C */	stfs f10, 0x2c(r3)
/* 8019A8D4  EC 01 10 2A */	fadds f0, f1, f2
/* 8019A8D8  FC 20 18 50 */	fneg f1, f3
/* 8019A8DC  EC 64 03 32 */	fmuls f3, f4, f12
/* 8019A8E0  FC 00 00 50 */	fneg f0, f0
/* 8019A8E4  EC 4C 00 72 */	fmuls f2, f12, f1
/* 8019A8E8  EC 24 02 F2 */	fmuls f1, f4, f11
/* 8019A8EC  EC 0B 00 32 */	fmuls f0, f11, f0
/* 8019A8F0  EC 45 00 B2 */	fmuls f2, f5, f2
/* 8019A8F4  EC 63 01 72 */	fmuls f3, f3, f5
/* 8019A8F8  EC 06 00 32 */	fmuls f0, f6, f0
/* 8019A8FC  EC 47 10 2A */	fadds f2, f7, f2
/* 8019A900  EC 21 01 B2 */	fmuls f1, f1, f6
/* 8019A904  D0 63 00 00 */	stfs f3, 0(r3)
/* 8019A908  EC 08 00 2A */	fadds f0, f8, f0
/* 8019A90C  D0 43 00 0C */	stfs f2, 0xc(r3)
/* 8019A910  D0 23 00 14 */	stfs f1, 0x14(r3)
/* 8019A914  D0 03 00 1C */	stfs f0, 0x1c(r3)
/* 8019A918  4E 80 00 20 */	blr 
/* 8019A91C  E0 04 00 00 */	psq_l f0, 0(r4), 0, qr0
/* 8019A920  E0 43 00 00 */	psq_l f2, 0(r3), 0, qr0
/* 8019A924  E0 24 80 08 */	psq_l f1, 8(r4), 1, qr0
/* 8019A928  10 82 00 32 */	ps_mul f4, f2, f0
/* 8019A92C  E0 63 00 08 */	psq_l f3, 8(r3), 0, qr0
/* 8019A930  10 A3 20 7A */	ps_madd f5, f3, f1, f4
/* 8019A934  E1 03 00 10 */	psq_l f8, 16(r3), 0, qr0
/* 8019A938  10 C5 29 94 */	ps_sum0 f6, f5, f6, f5
/* 8019A93C  E1 23 00 18 */	psq_l f9, 24(r3), 0, qr0
/* 8019A940  11 48 00 32 */	ps_mul f10, f8, f0
/* 8019A944  F0 C5 80 00 */	psq_st f6, 0(r5), 1, qr0
/* 8019A948  11 69 50 7A */	ps_madd f11, f9, f1, f10
/* 8019A94C  E0 43 00 20 */	psq_l f2, 32(r3), 0, qr0
/* 8019A950  11 8B 5B 14 */	ps_sum0 f12, f11, f12, f11
/* 8019A954  E0 63 00 28 */	psq_l f3, 40(r3), 0, qr0
/* 8019A958  10 82 00 32 */	ps_mul f4, f2, f0
/* 8019A95C  F1 85 80 04 */	psq_st f12, 4(r5), 1, qr0
/* 8019A960  10 A3 20 7A */	ps_madd f5, f3, f1, f4
/* 8019A964  10 C5 29 94 */	ps_sum0 f6, f5, f6, f5
/* 8019A968  F0 C5 80 08 */	psq_st f6, 8(r5), 1, qr0
/* 8019A96C  4E 80 00 20 */	blr 
/* 8019A970  E0 03 00 00 */	psq_l f0, 0(r3), 0, qr0
/* 8019A974  E0 C4 00 00 */	psq_l f6, 0(r4), 0, qr0
/* 8019A978  E0 43 00 10 */	psq_l f2, 16(r3), 0, qr0
/* 8019A97C  11 00 01 B2 */	ps_mul f8, f0, f6
/* 8019A980  E0 83 00 20 */	psq_l f4, 32(r3), 0, qr0
/* 8019A984  11 42 01 B2 */	ps_mul f10, f2, f6
/* 8019A988  E0 E4 80 08 */	psq_l f7, 8(r4), 1, qr0
/* 8019A98C  11 84 01 B2 */	ps_mul f12, f4, f6
/* 8019A990  E0 63 00 18 */	psq_l f3, 24(r3), 0, qr0
/* 8019A994  11 08 42 14 */	ps_sum0 f8, f8, f8, f8
/* 8019A998  E0 A3 00 28 */	psq_l f5, 40(r3), 0, qr0
/* 8019A99C  11 4A 52 94 */	ps_sum0 f10, f10, f10, f10
/* 8019A9A0  E0 23 00 08 */	psq_l f1, 8(r3), 0, qr0
/* 8019A9A4  11 8C 63 14 */	ps_sum0 f12, f12, f12, f12
/* 8019A9A8  11 21 41 FA */	ps_madd f9, f1, f7, f8
/* 8019A9AC  F1 25 80 00 */	psq_st f9, 0(r5), 1, qr0
/* 8019A9B0  11 63 51 FA */	ps_madd f11, f3, f7, f10
/* 8019A9B4  F1 65 80 04 */	psq_st f11, 4(r5), 1, qr0
/* 8019A9B8  11 A5 61 FA */	ps_madd f13, f5, f7, f12
/* 8019A9BC  F1 A5 80 08 */	psq_st f13, 8(r5), 1, qr0
/* 8019A9C0  4E 80 00 20 */	blr 
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
