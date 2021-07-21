.include "macros.inc"

.section .text, "ax" # { 800f164c..800f1f58 (text) }
/* 800F164C  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F1650  7C 08 02 A6 */	mflr r0
/* 800F1654  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F1658  39 61 00 30 */	addi r11, r1, 0x30
/* 800F165C  4B F2 FF 35 */	bl -0xd00cc
/* 800F1660  7C 7B 1B 78 */	mr r27, r3
/* 800F1664  38 6D 84 88 */	addi r3, r13, -31608
/* 800F1668  4B F2 FB ED */	bl -0xd0414
/* 800F166C  7C 65 1B 78 */	mr r5, r3
/* 800F1670  7F 64 DB 78 */	mr r4, r27
/* 800F1674  38 6D 84 88 */	addi r3, r13, -31608
/* 800F1678  4B F2 1D 41 */	bl -0xde2c0
/* 800F167C  2C 03 00 00 */	cmpwi r3, 0
/* 800F1680  40 82 01 28 */	bne 0x128
/* 800F1684  80 0D 97 48 */	lwz r0, -0x68b8(r13)
/* 800F1688  2C 00 00 00 */	cmpwi r0, 0
/* 800F168C  41 82 01 14 */	beq 0x114
/* 800F1690  3C 60 80 2F */	lis r3, 0x802f
/* 800F1694  3A E0 00 00 */	li r23, 0
/* 800F1698  3B 20 00 00 */	li r25, 0
/* 800F169C  3B 03 21 68 */	addi r24, r3, 0x2168
/* 800F16A0  80 6D 97 48 */	lwz r3, -0x68b8(r13)
/* 800F16A4  7C 03 C8 2E */	lwzx r0, r3, r25
/* 800F16A8  2C 00 00 00 */	cmpwi r0, 0
/* 800F16AC  41 82 00 A0 */	beq 0xa0
/* 800F16B0  3B 60 00 00 */	li r27, 0
/* 800F16B4  3B 40 00 00 */	li r26, 0
/* 800F16B8  48 00 00 20 */	b 0x20
/* 800F16BC  2C 03 00 00 */	cmpwi r3, 0
/* 800F16C0  41 82 00 10 */	beq 0x10
/* 800F16C4  81 98 00 04 */	lwz r12, 4(r24)
/* 800F16C8  7D 89 03 A6 */	mtctr r12
/* 800F16CC  4E 80 04 21 */	bctrl
/* 800F16D0  3B 5A 00 04 */	addi r26, r26, 4
/* 800F16D4  3B 7B 00 01 */	addi r27, r27, 1
/* 800F16D8  80 0D 97 48 */	lwz r0, -0x68b8(r13)
/* 800F16DC  7C 79 00 2E */	lwzx r3, r25, r0
/* 800F16E0  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800F16E4  7C 64 D0 2E */	lwzx r3, r4, r26
/* 800F16E8  2C 03 00 00 */	cmpwi r3, 0
/* 800F16EC  40 82 FF D0 */	bne -0x30
/* 800F16F0  57 60 10 3A */	slwi r0, r27, 2
/* 800F16F4  7C 64 00 2E */	lwzx r3, r4, r0
/* 800F16F8  2C 03 00 00 */	cmpwi r3, 0
/* 800F16FC  41 82 00 10 */	beq 0x10
/* 800F1700  81 98 00 04 */	lwz r12, 4(r24)
/* 800F1704  7D 89 03 A6 */	mtctr r12
/* 800F1708  4E 80 04 21 */	bctrl
/* 800F170C  80 6D 97 48 */	lwz r3, -0x68b8(r13)
/* 800F1710  7C 63 C8 2E */	lwzx r3, r3, r25
/* 800F1714  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800F1718  2C 03 00 00 */	cmpwi r3, 0
/* 800F171C  41 82 00 10 */	beq 0x10
/* 800F1720  81 98 00 04 */	lwz r12, 4(r24)
/* 800F1724  7D 89 03 A6 */	mtctr r12
/* 800F1728  4E 80 04 21 */	bctrl
/* 800F172C  80 6D 97 48 */	lwz r3, -0x68b8(r13)
/* 800F1730  7C 63 C8 2E */	lwzx r3, r3, r25
/* 800F1734  80 63 00 10 */	lwz r3, 0x10(r3)
/* 800F1738  2C 03 00 00 */	cmpwi r3, 0
/* 800F173C  41 82 00 10 */	beq 0x10
/* 800F1740  81 98 00 04 */	lwz r12, 4(r24)
/* 800F1744  7D 89 03 A6 */	mtctr r12
/* 800F1748  4E 80 04 21 */	bctrl
/* 800F174C  80 6D 97 48 */	lwz r3, -0x68b8(r13)
/* 800F1750  7C 63 C8 2E */	lwzx r3, r3, r25
/* 800F1754  2C 03 00 00 */	cmpwi r3, 0
/* 800F1758  41 82 00 10 */	beq 0x10
/* 800F175C  81 98 00 04 */	lwz r12, 4(r24)
/* 800F1760  7D 89 03 A6 */	mtctr r12
/* 800F1764  4E 80 04 21 */	bctrl
/* 800F1768  3A F7 00 01 */	addi r23, r23, 1
/* 800F176C  3B 39 00 04 */	addi r25, r25, 4
/* 800F1770  28 17 00 1F */	cmplwi r23, 0x1f
/* 800F1774  41 80 FF 2C */	blt -0xd4
/* 800F1778  80 6D 97 48 */	lwz r3, -0x68b8(r13)
/* 800F177C  2C 03 00 00 */	cmpwi r3, 0
/* 800F1780  41 82 00 18 */	beq 0x18
/* 800F1784  3C 80 80 2F */	lis r4, 0x802f
/* 800F1788  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F178C  81 84 00 04 */	lwz r12, 4(r4)
/* 800F1790  7D 89 03 A6 */	mtctr r12
/* 800F1794  4E 80 04 21 */	bctrl
/* 800F1798  38 00 00 00 */	li r0, 0
/* 800F179C  90 0D 97 48 */	stw r0, -0x68b8(r13)
/* 800F17A0  38 60 00 00 */	li r3, 0
/* 800F17A4  48 00 04 0C */	b 0x40c
/* 800F17A8  80 0D 97 48 */	lwz r0, -0x68b8(r13)
/* 800F17AC  2C 00 00 00 */	cmpwi r0, 0
/* 800F17B0  40 82 00 28 */	bne 0x28
/* 800F17B4  3C 80 80 2F */	lis r4, 0x802f
/* 800F17B8  38 60 00 7C */	li r3, 0x7c
/* 800F17BC  81 84 21 68 */	lwz r12, 0x2168(r4)
/* 800F17C0  7D 89 03 A6 */	mtctr r12
/* 800F17C4  4E 80 04 21 */	bctrl
/* 800F17C8  90 6D 97 48 */	stw r3, -0x68b8(r13)
/* 800F17CC  38 80 00 00 */	li r4, 0
/* 800F17D0  38 A0 00 7C */	li r5, 0x7c
/* 800F17D4  4B F1 48 65 */	bl -0xeb79c
/* 800F17D8  7F 63 DB 78 */	mr r3, r27
/* 800F17DC  4B F2 FA 79 */	bl -0xd0588
/* 800F17E0  2C 03 00 00 */	cmpwi r3, 0
/* 800F17E4  3B 80 00 00 */	li r28, 0
/* 800F17E8  38 80 00 00 */	li r4, 0
/* 800F17EC  41 82 01 20 */	beq 0x120
/* 800F17F0  28 03 00 08 */	cmplwi r3, 8
/* 800F17F4  38 A3 FF F8 */	addi r5, r3, -8
/* 800F17F8  40 81 00 E0 */	ble 0xe0
/* 800F17FC  38 05 00 07 */	addi r0, r5, 7
/* 800F1800  54 00 E8 FE */	srwi r0, r0, 3
/* 800F1804  7C 09 03 A6 */	mtctr r0
/* 800F1808  28 05 00 00 */	cmplwi r5, 0
/* 800F180C  40 81 00 CC */	ble 0xcc
/* 800F1810  7E FB 22 14 */	add r23, r27, r4
/* 800F1814  7C 1B 20 AE */	lbzx r0, r27, r4
/* 800F1818  8B 37 00 01 */	lbz r25, 1(r23)
/* 800F181C  3B 44 00 01 */	addi r26, r4, 1
/* 800F1820  8B F7 00 02 */	lbz r31, 2(r23)
/* 800F1824  7C 05 07 74 */	extsb r5, r0
/* 800F1828  54 80 16 FA */	rlwinm r0, r4, 2, 0x1b, 0x1d
/* 800F182C  3B C4 00 02 */	addi r30, r4, 2
/* 800F1830  7C B8 00 30 */	slw r24, r5, r0
/* 800F1834  8B B7 00 03 */	lbz r29, 3(r23)
/* 800F1838  39 84 00 03 */	addi r12, r4, 3
/* 800F183C  89 77 00 04 */	lbz r11, 4(r23)
/* 800F1840  39 44 00 04 */	addi r10, r4, 4
/* 800F1844  89 37 00 05 */	lbz r9, 5(r23)
/* 800F1848  39 04 00 05 */	addi r8, r4, 5
/* 800F184C  88 F7 00 06 */	lbz r7, 6(r23)
/* 800F1850  38 C4 00 06 */	addi r6, r4, 6
/* 800F1854  38 04 00 07 */	addi r0, r4, 7
/* 800F1858  88 B7 00 07 */	lbz r5, 7(r23)
/* 800F185C  7F 39 07 74 */	extsb r25, r25
/* 800F1860  57 5A 16 FA */	rlwinm r26, r26, 2, 0x1b, 0x1d
/* 800F1864  7F 9C C2 14 */	add r28, r28, r24
/* 800F1868  7F 3A D0 30 */	slw r26, r25, r26
/* 800F186C  7F FF 07 74 */	extsb r31, r31
/* 800F1870  57 DE 16 FA */	rlwinm r30, r30, 2, 0x1b, 0x1d
/* 800F1874  7F BD 07 74 */	extsb r29, r29
/* 800F1878  55 8C 16 FA */	rlwinm r12, r12, 2, 0x1b, 0x1d
/* 800F187C  7F 9C D2 14 */	add r28, r28, r26
/* 800F1880  7F FE F0 30 */	slw r30, r31, r30
/* 800F1884  7D 6B 07 74 */	extsb r11, r11
/* 800F1888  55 4A 16 FA */	rlwinm r10, r10, 2, 0x1b, 0x1d
/* 800F188C  7F AC 60 30 */	slw r12, r29, r12
/* 800F1890  7F 9C F2 14 */	add r28, r28, r30
/* 800F1894  7D 29 07 74 */	extsb r9, r9
/* 800F1898  55 08 16 FA */	rlwinm r8, r8, 2, 0x1b, 0x1d
/* 800F189C  7D 6A 50 30 */	slw r10, r11, r10
/* 800F18A0  7F 9C 62 14 */	add r28, r28, r12
/* 800F18A4  7C E7 07 74 */	extsb r7, r7
/* 800F18A8  54 C6 16 FA */	rlwinm r6, r6, 2, 0x1b, 0x1d
/* 800F18AC  7D 28 40 30 */	slw r8, r9, r8
/* 800F18B0  7F 9C 52 14 */	add r28, r28, r10
/* 800F18B4  7C A5 07 74 */	extsb r5, r5
/* 800F18B8  54 00 16 FA */	rlwinm r0, r0, 2, 0x1b, 0x1d
/* 800F18BC  7C E6 30 30 */	slw r6, r7, r6
/* 800F18C0  7F 9C 42 14 */	add r28, r28, r8
/* 800F18C4  38 84 00 08 */	addi r4, r4, 8
/* 800F18C8  7F 9C 32 14 */	add r28, r28, r6
/* 800F18CC  7C A0 00 30 */	slw r0, r5, r0
/* 800F18D0  7F 9C 02 14 */	add r28, r28, r0
/* 800F18D4  42 00 FF 3C */	bdnz -0xc4
/* 800F18D8  7C 04 18 50 */	subf r0, r4, r3
/* 800F18DC  7C BB 22 14 */	add r5, r27, r4
/* 800F18E0  7C 09 03 A6 */	mtctr r0
/* 800F18E4  7C 04 18 40 */	cmplw r4, r3
/* 800F18E8  40 80 00 24 */	bge 0x24
/* 800F18EC  88 65 00 00 */	lbz r3, 0(r5)
/* 800F18F0  54 80 16 FA */	rlwinm r0, r4, 2, 0x1b, 0x1d
/* 800F18F4  38 84 00 01 */	addi r4, r4, 1
/* 800F18F8  38 A5 00 01 */	addi r5, r5, 1
/* 800F18FC  7C 63 07 74 */	extsb r3, r3
/* 800F1900  7C 60 00 30 */	slw r0, r3, r0
/* 800F1904  7F 9C 02 14 */	add r28, r28, r0
/* 800F1908  42 00 FF E4 */	bdnz -0x1c
/* 800F190C  3C 60 08 42 */	lis r3, 0x842
/* 800F1910  83 CD 97 48 */	lwz r30, -0x68b8(r13)
/* 800F1914  3B E3 10 85 */	addi r31, r3, 0x1085
/* 800F1918  3B A0 00 00 */	li r29, 0
/* 800F191C  7C 7F E0 16 */	mulhwu r3, r31, r28
/* 800F1920  7C 03 E0 50 */	subf r0, r3, r28
/* 800F1924  54 00 F8 7E */	srwi r0, r0, 1
/* 800F1928  7C 00 1A 14 */	add r0, r0, r3
/* 800F192C  54 00 E1 3E */	srwi r0, r0, 4
/* 800F1930  1C 00 00 1F */	mulli r0, r0, 0x1f
/* 800F1934  7F 80 E0 50 */	subf r28, r0, r28
/* 800F1938  7C 1D E9 D6 */	mullw r0, r29, r29
/* 800F193C  7C 9C 02 14 */	add r4, r28, r0
/* 800F1940  7C 7F 20 16 */	mulhwu r3, r31, r4
/* 800F1944  7C 03 20 50 */	subf r0, r3, r4
/* 800F1948  54 00 F8 7E */	srwi r0, r0, 1
/* 800F194C  7C 00 1A 14 */	add r0, r0, r3
/* 800F1950  54 00 E1 3E */	srwi r0, r0, 4
/* 800F1954  1C 00 00 1F */	mulli r0, r0, 0x1f
/* 800F1958  7C 00 20 50 */	subf r0, r0, r4
/* 800F195C  54 00 10 3A */	slwi r0, r0, 2
/* 800F1960  7E FE 00 2E */	lwzx r23, r30, r0
/* 800F1964  2C 17 00 00 */	cmpwi r23, 0
/* 800F1968  41 82 00 20 */	beq 0x20
/* 800F196C  80 77 00 10 */	lwz r3, 0x10(r23)
/* 800F1970  7F 64 DB 78 */	mr r4, r27
/* 800F1974  4B F2 19 29 */	bl -0xde6d8
/* 800F1978  2C 03 00 00 */	cmpwi r3, 0
/* 800F197C  40 82 00 0C */	bne 0xc
/* 800F1980  7E E3 BB 78 */	mr r3, r23
/* 800F1984  48 00 02 2C */	b 0x22c
/* 800F1988  3B BD 00 01 */	addi r29, r29, 1
/* 800F198C  28 1D 00 0F */	cmplwi r29, 0xf
/* 800F1990  41 80 FF A8 */	blt -0x58
/* 800F1994  57 80 10 3A */	slwi r0, r28, 2
/* 800F1998  7C 1E 00 2E */	lwzx r0, r30, r0
/* 800F199C  2C 00 00 00 */	cmpwi r0, 0
/* 800F19A0  41 82 00 B0 */	beq 0xb0
/* 800F19A4  3C 60 08 42 */	lis r3, 0x842
/* 800F19A8  38 00 00 07 */	li r0, 7
/* 800F19AC  38 63 10 85 */	addi r3, r3, 0x1085
/* 800F19B0  38 C0 00 01 */	li r6, 1
/* 800F19B4  7C 09 03 A6 */	mtctr r0
/* 800F19B8  7C 06 31 D6 */	mullw r0, r6, r6
/* 800F19BC  7C BC 02 14 */	add r5, r28, r0
/* 800F19C0  7C 83 28 16 */	mulhwu r4, r3, r5
/* 800F19C4  7C 04 28 50 */	subf r0, r4, r5
/* 800F19C8  54 00 F8 7E */	srwi r0, r0, 1
/* 800F19CC  7C 00 22 14 */	add r0, r0, r4
/* 800F19D0  54 00 E1 3E */	srwi r0, r0, 4
/* 800F19D4  1C 00 00 1F */	mulli r0, r0, 0x1f
/* 800F19D8  7C 80 28 50 */	subf r4, r0, r5
/* 800F19DC  54 80 10 3A */	slwi r0, r4, 2
/* 800F19E0  7C 1E 00 2E */	lwzx r0, r30, r0
/* 800F19E4  2C 00 00 00 */	cmpwi r0, 0
/* 800F19E8  40 82 00 0C */	bne 0xc
/* 800F19EC  7C 9C 23 78 */	mr r28, r4
/* 800F19F0  48 00 00 4C */	b 0x4c
/* 800F19F4  38 C6 00 01 */	addi r6, r6, 1
/* 800F19F8  7C 06 31 D6 */	mullw r0, r6, r6
/* 800F19FC  7C BC 02 14 */	add r5, r28, r0
/* 800F1A00  7C 83 28 16 */	mulhwu r4, r3, r5
/* 800F1A04  7C 04 28 50 */	subf r0, r4, r5
/* 800F1A08  54 00 F8 7E */	srwi r0, r0, 1
/* 800F1A0C  7C 00 22 14 */	add r0, r0, r4
/* 800F1A10  54 00 E1 3E */	srwi r0, r0, 4
/* 800F1A14  1C 00 00 1F */	mulli r0, r0, 0x1f
/* 800F1A18  7C 80 28 50 */	subf r4, r0, r5
/* 800F1A1C  54 80 10 3A */	slwi r0, r4, 2
/* 800F1A20  7C 1E 00 2E */	lwzx r0, r30, r0
/* 800F1A24  2C 00 00 00 */	cmpwi r0, 0
/* 800F1A28  40 82 00 0C */	bne 0xc
/* 800F1A2C  7C 9C 23 78 */	mr r28, r4
/* 800F1A30  48 00 00 0C */	b 0xc
/* 800F1A34  38 C6 00 01 */	addi r6, r6, 1
/* 800F1A38  42 00 FF 80 */	bdnz -0x80
/* 800F1A3C  28 06 00 0F */	cmplwi r6, 0xf
/* 800F1A40  40 82 00 10 */	bne 0x10
/* 800F1A44  7F 63 DB 78 */	mr r3, r27
/* 800F1A48  48 0F C4 B9 */	bl 0xfc4b8
/* 800F1A4C  48 00 01 64 */	b 0x164
/* 800F1A50  7F 63 DB 78 */	mr r3, r27
/* 800F1A54  48 0F C4 AD */	bl 0xfc4ac
/* 800F1A58  2C 03 00 00 */	cmpwi r3, 0
/* 800F1A5C  7C 7D 1B 78 */	mr r29, r3
/* 800F1A60  40 82 00 0C */	bne 0xc
/* 800F1A64  38 60 00 00 */	li r3, 0
/* 800F1A68  48 00 01 48 */	b 0x148
/* 800F1A6C  3C 80 80 2F */	lis r4, 0x802f
/* 800F1A70  38 60 00 14 */	li r3, 0x14
/* 800F1A74  81 84 21 68 */	lwz r12, 0x2168(r4)
/* 800F1A78  7D 89 03 A6 */	mtctr r12
/* 800F1A7C  4E 80 04 21 */	bctrl
/* 800F1A80  80 CD 97 48 */	lwz r6, -0x68b8(r13)
/* 800F1A84  57 9E 10 3A */	slwi r30, r28, 2
/* 800F1A88  38 A0 00 00 */	li r5, 0
/* 800F1A8C  7C 66 F1 2E */	stwx r3, r6, r30
/* 800F1A90  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800F1A94  48 00 00 0C */	b 0xc
/* 800F1A98  38 63 00 04 */	addi r3, r3, 4
/* 800F1A9C  38 A5 00 01 */	addi r5, r5, 1
/* 800F1AA0  80 03 00 00 */	lwz r0, 0(r3)
/* 800F1AA4  2C 00 00 00 */	cmpwi r0, 0
/* 800F1AA8  40 82 FF F0 */	bne -0x10
/* 800F1AAC  7C 66 F0 2E */	lwzx r3, r6, r30
/* 800F1AB0  38 80 00 02 */	li r4, 2
/* 800F1AB4  38 05 00 01 */	addi r0, r5, 1
/* 800F1AB8  38 A0 00 00 */	li r5, 0
/* 800F1ABC  B0 83 00 08 */	sth r4, 8(r3)
/* 800F1AC0  54 03 10 3A */	slwi r3, r0, 2
/* 800F1AC4  3F 80 80 2F */	lis r28, 0x802f
/* 800F1AC8  A8 1D 00 0A */	lha r0, 0xa(r29)
/* 800F1ACC  7C 86 F0 2E */	lwzx r4, r6, r30
/* 800F1AD0  B0 04 00 0A */	sth r0, 0xa(r4)
/* 800F1AD4  7C 86 F0 2E */	lwzx r4, r6, r30
/* 800F1AD8  90 A4 00 00 */	stw r5, 0(r4)
/* 800F1ADC  7C 86 F0 2E */	lwzx r4, r6, r30
/* 800F1AE0  90 A4 00 04 */	stw r5, 4(r4)
/* 800F1AE4  81 9C 21 68 */	lwz r12, 0x2168(r28)
/* 800F1AE8  7D 89 03 A6 */	mtctr r12
/* 800F1AEC  4E 80 04 21 */	bctrl
/* 800F1AF0  80 8D 97 48 */	lwz r4, -0x68b8(r13)
/* 800F1AF4  3A E0 00 00 */	li r23, 0
/* 800F1AF8  3B 00 00 00 */	li r24, 0
/* 800F1AFC  7C 84 F0 2E */	lwzx r4, r4, r30
/* 800F1B00  90 64 00 0C */	stw r3, 0xc(r4)
/* 800F1B04  48 00 00 48 */	b 0x48
/* 800F1B08  81 9C 21 68 */	lwz r12, 0x2168(r28)
/* 800F1B0C  A8 7D 00 0A */	lha r3, 0xa(r29)
/* 800F1B10  7D 89 03 A6 */	mtctr r12
/* 800F1B14  4E 80 04 21 */	bctrl
/* 800F1B18  80 0D 97 48 */	lwz r0, -0x68b8(r13)
/* 800F1B1C  7C 9E 00 2E */	lwzx r4, r30, r0
/* 800F1B20  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800F1B24  7C 64 C1 2E */	stwx r3, r4, r24
/* 800F1B28  7C 9E 00 2E */	lwzx r4, r30, r0
/* 800F1B2C  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800F1B30  80 A4 00 0C */	lwz r5, 0xc(r4)
/* 800F1B34  7C 83 C0 2E */	lwzx r4, r3, r24
/* 800F1B38  7C 65 C0 2E */	lwzx r3, r5, r24
/* 800F1B3C  A8 BD 00 0A */	lha r5, 0xa(r29)
/* 800F1B40  4B F1 43 F5 */	bl -0xebc0c
/* 800F1B44  3B 18 00 04 */	addi r24, r24, 4
/* 800F1B48  3A F7 00 01 */	addi r23, r23, 1
/* 800F1B4C  80 7D 00 0C */	lwz r3, 0xc(r29)
/* 800F1B50  7C 03 C0 2E */	lwzx r0, r3, r24
/* 800F1B54  2C 00 00 00 */	cmpwi r0, 0
/* 800F1B58  40 82 FF B0 */	bne -0x50
/* 800F1B5C  80 8D 97 48 */	lwz r4, -0x68b8(r13)
/* 800F1B60  56 E0 10 3A */	slwi r0, r23, 2
/* 800F1B64  38 A0 00 00 */	li r5, 0
/* 800F1B68  7F 63 DB 78 */	mr r3, r27
/* 800F1B6C  7C 84 F0 2E */	lwzx r4, r4, r30
/* 800F1B70  80 84 00 0C */	lwz r4, 0xc(r4)
/* 800F1B74  7C A4 01 2E */	stwx r5, r4, r0
/* 800F1B78  4B F2 F6 DD */	bl -0xd0924
/* 800F1B7C  3C 80 80 2F */	lis r4, 0x802f
/* 800F1B80  81 84 21 68 */	lwz r12, 0x2168(r4)
/* 800F1B84  7D 89 03 A6 */	mtctr r12
/* 800F1B88  38 63 00 01 */	addi r3, r3, 1
/* 800F1B8C  4E 80 04 21 */	bctrl
/* 800F1B90  80 CD 97 48 */	lwz r6, -0x68b8(r13)
/* 800F1B94  7F 64 DB 78 */	mr r4, r27
/* 800F1B98  7C A6 F0 2E */	lwzx r5, r6, r30
/* 800F1B9C  90 65 00 10 */	stw r3, 0x10(r5)
/* 800F1BA0  7C 66 F0 2E */	lwzx r3, r6, r30
/* 800F1BA4  80 63 00 10 */	lwz r3, 0x10(r3)
/* 800F1BA8  4B F2 15 79 */	bl -0xdea88
/* 800F1BAC  7F A3 EB 78 */	mr r3, r29
/* 800F1BB0  39 61 00 30 */	addi r11, r1, 0x30
/* 800F1BB4  4B F2 FA 29 */	bl -0xd05d8
/* 800F1BB8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F1BBC  7C 08 03 A6 */	mtlr r0
/* 800F1BC0  38 21 00 30 */	addi r1, r1, 0x30
/* 800F1BC4  4E 80 00 20 */	blr
/* 800F1BC8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F1BCC  7C 08 02 A6 */	mflr r0
/* 800F1BD0  38 A0 00 00 */	li r5, 0
/* 800F1BD4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F1BD8  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F1BDC  7C 9F 23 78 */	mr r31, r4
/* 800F1BE0  38 80 00 03 */	li r4, 3
/* 800F1BE4  93 C1 00 08 */	stw r30, 8(r1)
/* 800F1BE8  7C 7E 1B 78 */	mr r30, r3
/* 800F1BEC  4C C6 31 82 */	crclr 6
/* 800F1BF0  48 0F B8 FD */	bl 0xfb8fc
/* 800F1BF4  2C 1F 00 00 */	cmpwi r31, 0
/* 800F1BF8  60 65 00 04 */	ori r5, r3, 4
/* 800F1BFC  41 82 00 08 */	beq 0x8
/* 800F1C00  54 65 07 B8 */	rlwinm r5, r3, 0, 0x1e, 0x1c
/* 800F1C04  7F C3 F3 78 */	mr r3, r30
/* 800F1C08  38 80 00 04 */	li r4, 4
/* 800F1C0C  4C C6 31 82 */	crclr 6
/* 800F1C10  48 0F B8 DD */	bl 0xfb8dc
/* 800F1C14  2C 03 00 00 */	cmpwi r3, 0
/* 800F1C18  40 82 00 0C */	bne 0xc
/* 800F1C1C  38 60 00 01 */	li r3, 1
/* 800F1C20  48 00 00 08 */	b 0x8
/* 800F1C24  38 60 00 00 */	li r3, 0
/* 800F1C28  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F1C2C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F1C30  83 C1 00 08 */	lwz r30, 8(r1)
/* 800F1C34  7C 08 03 A6 */	mtlr r0
/* 800F1C38  38 21 00 10 */	addi r1, r1, 0x10
/* 800F1C3C  4E 80 00 20 */	blr
/* 800F1C40  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F1C44  7C 08 02 A6 */	mflr r0
/* 800F1C48  38 A0 10 02 */	li r5, 0x1002
/* 800F1C4C  38 E0 00 04 */	li r7, 4
/* 800F1C50  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F1C54  38 C1 00 08 */	addi r6, r1, 8
/* 800F1C58  90 81 00 08 */	stw r4, 8(r1)
/* 800F1C5C  3C 80 00 01 */	lis r4, 1
/* 800F1C60  38 84 FF FF */	addi r4, r4, -1
/* 800F1C64  48 0F C7 25 */	bl 0xfc724
/* 800F1C68  2C 03 00 00 */	cmpwi r3, 0
/* 800F1C6C  41 80 00 08 */	blt 0x8
/* 800F1C70  48 00 00 0C */	b 0xc
/* 800F1C74  90 6D 97 54 */	stw r3, -0x68ac(r13)
/* 800F1C78  38 60 FF FF */	li r3, -1
/* 800F1C7C  20 83 FF FF */	subfic r4, r3, -1
/* 800F1C80  38 03 00 01 */	addi r0, r3, 1
/* 800F1C84  7C 80 03 78 */	or r0, r4, r0
/* 800F1C88  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800F1C8C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F1C90  7C 08 03 A6 */	mtlr r0
/* 800F1C94  38 21 00 10 */	addi r1, r1, 0x10
/* 800F1C98  4E 80 00 20 */	blr
/* 800F1C9C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F1CA0  7C 08 02 A6 */	mflr r0
/* 800F1CA4  38 A0 00 00 */	li r5, 0
/* 800F1CA8  38 C0 00 00 */	li r6, 0
/* 800F1CAC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F1CB0  38 00 00 00 */	li r0, 0
/* 800F1CB4  38 81 00 08 */	addi r4, r1, 8
/* 800F1CB8  90 01 00 08 */	stw r0, 8(r1)
/* 800F1CBC  4B FF F8 69 */	bl -0x798
/* 800F1CC0  2C 03 00 01 */	cmpwi r3, 1
/* 800F1CC4  40 82 00 0C */	bne 0xc
/* 800F1CC8  80 61 00 08 */	lwz r3, 8(r1)
/* 800F1CCC  48 00 00 08 */	b 0x8
/* 800F1CD0  38 60 00 00 */	li r3, 0
/* 800F1CD4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F1CD8  7C 08 03 A6 */	mtlr r0
/* 800F1CDC  38 21 00 10 */	addi r1, r1, 0x10
/* 800F1CE0  4E 80 00 20 */	blr
/* 800F1CE4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F1CE8  7C 08 02 A6 */	mflr r0
/* 800F1CEC  38 80 00 00 */	li r4, 0
/* 800F1CF0  38 C0 00 00 */	li r6, 0
/* 800F1CF4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F1CF8  38 00 00 00 */	li r0, 0
/* 800F1CFC  38 A1 00 08 */	addi r5, r1, 8
/* 800F1D00  90 01 00 08 */	stw r0, 8(r1)
/* 800F1D04  4B FF F8 21 */	bl -0x7e0
/* 800F1D08  2C 03 00 01 */	cmpwi r3, 1
/* 800F1D0C  40 82 00 0C */	bne 0xc
/* 800F1D10  80 61 00 08 */	lwz r3, 8(r1)
/* 800F1D14  48 00 00 08 */	b 0x8
/* 800F1D18  38 60 00 00 */	li r3, 0
/* 800F1D1C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F1D20  7C 08 03 A6 */	mtlr r0
/* 800F1D24  38 21 00 10 */	addi r1, r1, 0x10
/* 800F1D28  4E 80 00 20 */	blr
/* 800F1D2C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F1D30  7C 08 02 A6 */	mflr r0
/* 800F1D34  38 60 00 00 */	li r3, 0
/* 800F1D38  38 A0 40 02 */	li r5, 0x4002
/* 800F1D3C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F1D40  38 00 00 04 */	li r0, 4
/* 800F1D44  38 C1 00 10 */	addi r6, r1, 0x10
/* 800F1D48  38 E1 00 0C */	addi r7, r1, 0xc
/* 800F1D4C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F1D50  3F E0 80 2F */	lis r31, 0x802f
/* 800F1D54  3B FF 21 68 */	addi r31, r31, 0x2168
/* 800F1D58  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F1D5C  3F C0 00 01 */	lis r30, 1
/* 800F1D60  38 9E FF FE */	addi r4, r30, -2
/* 800F1D64  90 01 00 0C */	stw r0, 0xc(r1)
/* 800F1D68  48 0F C7 25 */	bl 0xfc724
/* 800F1D6C  80 01 00 10 */	lwz r0, 0x10(r1)
/* 800F1D70  38 7F 00 60 */	addi r3, r31, 0x60
/* 800F1D74  38 80 00 BE */	li r4, 0xbe
/* 800F1D78  1C A0 00 0C */	mulli r5, r0, 0xc
/* 800F1D7C  4B F1 42 BD */	bl -0xebd44
/* 800F1D80  80 01 00 10 */	lwz r0, 0x10(r1)
/* 800F1D84  38 9E FF FE */	addi r4, r30, -2
/* 800F1D88  38 DF 00 60 */	addi r6, r31, 0x60
/* 800F1D8C  38 E1 00 08 */	addi r7, r1, 8
/* 800F1D90  1C 00 00 0C */	mulli r0, r0, 0xc
/* 800F1D94  38 60 00 00 */	li r3, 0
/* 800F1D98  38 A0 40 03 */	li r5, 0x4003
/* 800F1D9C  90 01 00 08 */	stw r0, 8(r1)
/* 800F1DA0  48 0F C6 ED */	bl 0xfc6ec
/* 800F1DA4  80 E1 00 10 */	lwz r7, 0x10(r1)
/* 800F1DA8  3C 80 80 28 */	lis r4, 0x8028
/* 800F1DAC  38 84 AC E0 */	addi r4, r4, -21280
/* 800F1DB0  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F1DB4  38 AD 97 4C */	addi r5, r13, -26804
/* 800F1DB8  38 00 00 02 */	li r0, 2
/* 800F1DBC  90 9F 00 10 */	stw r4, 0x10(r31)
/* 800F1DC0  2C 87 00 00 */	cmpwi cr1, r7, 0
/* 800F1DC4  38 80 00 00 */	li r4, 0
/* 800F1DC8  90 A3 00 04 */	stw r5, 4(r3)
/* 800F1DCC  B0 03 00 08 */	sth r0, 8(r3)
/* 800F1DD0  B0 E3 00 0A */	sth r7, 0xa(r3)
/* 800F1DD4  40 85 00 DC */	ble cr1, 0xdc
/* 800F1DD8  2C 07 00 08 */	cmpwi r7, 8
/* 800F1DDC  38 A7 FF F8 */	addi r5, r7, -8
/* 800F1DE0  40 81 00 90 */	ble 0x90
/* 800F1DE4  38 C0 00 00 */	li r6, 0
/* 800F1DE8  41 84 00 18 */	blt cr1, 0x18
/* 800F1DEC  3C 60 80 00 */	lis r3, 0x8000
/* 800F1DF0  38 03 FF FE */	addi r0, r3, -2
/* 800F1DF4  7C 07 00 00 */	cmpw r7, r0
/* 800F1DF8  41 81 00 08 */	bgt 0x8
/* 800F1DFC  38 C0 00 01 */	li r6, 1
/* 800F1E00  2C 06 00 00 */	cmpwi r6, 0
/* 800F1E04  41 82 00 6C */	beq 0x6c
/* 800F1E08  38 05 00 07 */	addi r0, r5, 7
/* 800F1E0C  39 1F 00 60 */	addi r8, r31, 0x60
/* 800F1E10  54 00 E8 FE */	srwi r0, r0, 3
/* 800F1E14  39 3F 00 20 */	addi r9, r31, 0x20
/* 800F1E18  7C 09 03 A6 */	mtctr r0
/* 800F1E1C  2C 05 00 00 */	cmpwi r5, 0
/* 800F1E20  40 81 00 50 */	ble 0x50
/* 800F1E24  91 09 00 00 */	stw r8, 0(r9)
/* 800F1E28  38 68 00 0C */	addi r3, r8, 0xc
/* 800F1E2C  38 08 00 18 */	addi r0, r8, 0x18
/* 800F1E30  38 E8 00 24 */	addi r7, r8, 0x24
/* 800F1E34  90 69 00 04 */	stw r3, 4(r9)
/* 800F1E38  38 C8 00 30 */	addi r6, r8, 0x30
/* 800F1E3C  38 A8 00 3C */	addi r5, r8, 0x3c
/* 800F1E40  38 68 00 48 */	addi r3, r8, 0x48
/* 800F1E44  90 09 00 08 */	stw r0, 8(r9)
/* 800F1E48  38 08 00 54 */	addi r0, r8, 0x54
/* 800F1E4C  39 08 00 60 */	addi r8, r8, 0x60
/* 800F1E50  38 84 00 08 */	addi r4, r4, 8
/* 800F1E54  90 E9 00 0C */	stw r7, 0xc(r9)
/* 800F1E58  90 C9 00 10 */	stw r6, 0x10(r9)
/* 800F1E5C  90 A9 00 14 */	stw r5, 0x14(r9)
/* 800F1E60  90 69 00 18 */	stw r3, 0x18(r9)
/* 800F1E64  90 09 00 1C */	stw r0, 0x1c(r9)
/* 800F1E68  39 29 00 20 */	addi r9, r9, 0x20
/* 800F1E6C  42 00 FF B8 */	bdnz -0x48
/* 800F1E70  81 01 00 10 */	lwz r8, 0x10(r1)
/* 800F1E74  1C E4 00 0C */	mulli r7, r4, 0xc
/* 800F1E78  38 DF 00 60 */	addi r6, r31, 0x60
/* 800F1E7C  54 85 10 3A */	slwi r5, r4, 2
/* 800F1E80  38 7F 00 20 */	addi r3, r31, 0x20
/* 800F1E84  7C 04 40 50 */	subf r0, r4, r8
/* 800F1E88  7C C6 3A 14 */	add r6, r6, r7
/* 800F1E8C  7C 63 2A 14 */	add r3, r3, r5
/* 800F1E90  7C 09 03 A6 */	mtctr r0
/* 800F1E94  7C 04 40 00 */	cmpw r4, r8
/* 800F1E98  40 80 00 18 */	bge 0x18
/* 800F1E9C  90 C3 00 00 */	stw r6, 0(r3)
/* 800F1EA0  38 C6 00 0C */	addi r6, r6, 0xc
/* 800F1EA4  38 63 00 04 */	addi r3, r3, 4
/* 800F1EA8  38 84 00 01 */	addi r4, r4, 1
/* 800F1EAC  42 00 FF F0 */	bdnz -0x10
/* 800F1EB0  54 80 10 3A */	slwi r0, r4, 2
/* 800F1EB4  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F1EB8  38 BF 00 20 */	addi r5, r31, 0x20
/* 800F1EBC  38 80 00 00 */	li r4, 0
/* 800F1EC0  7C 85 01 2E */	stwx r4, r5, r0
/* 800F1EC4  90 A3 00 0C */	stw r5, 0xc(r3)
/* 800F1EC8  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F1ECC  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F1ED0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F1ED4  7C 08 03 A6 */	mtlr r0
/* 800F1ED8  38 21 00 20 */	addi r1, r1, 0x20
/* 800F1EDC  4E 80 00 20 */	blr
/* 800F1EE0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F1EE4  7C 08 02 A6 */	mflr r0
/* 800F1EE8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F1EEC  80 63 00 00 */	lwz r3, 0(r3)
/* 800F1EF0  48 0F BA 9D */	bl 0xfba9c
/* 800F1EF4  54 60 46 3E */	srwi r0, r3, 0x18
/* 800F1EF8  54 63 86 3E */	rlwinm r3, r3, 0x10, 0x18, 0x1f
/* 800F1EFC  2C 00 00 0A */	cmpwi r0, 0xa
/* 800F1F00  40 82 00 0C */	bne 0xc
/* 800F1F04  38 60 00 01 */	li r3, 1
/* 800F1F08  48 00 00 40 */	b 0x40
/* 800F1F0C  2C 00 00 AC */	cmpwi r0, 0xac
/* 800F1F10  40 82 00 1C */	bne 0x1c
/* 800F1F14  2C 03 00 10 */	cmpwi r3, 0x10
/* 800F1F18  41 80 00 14 */	blt 0x14
/* 800F1F1C  2C 03 00 1F */	cmpwi r3, 0x1f
/* 800F1F20  41 81 00 0C */	bgt 0xc
/* 800F1F24  38 60 00 01 */	li r3, 1
/* 800F1F28  48 00 00 20 */	b 0x20
/* 800F1F2C  2C 00 00 C0 */	cmpwi r0, 0xc0
/* 800F1F30  40 82 00 14 */	bne 0x14
/* 800F1F34  2C 03 00 A8 */	cmpwi r3, 0xa8
/* 800F1F38  40 82 00 0C */	bne 0xc
/* 800F1F3C  38 60 00 01 */	li r3, 1
/* 800F1F40  48 00 00 08 */	b 0x8
/* 800F1F44  38 60 00 00 */	li r3, 0
/* 800F1F48  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F1F4C  7C 08 03 A6 */	mtlr r0
/* 800F1F50  38 21 00 10 */	addi r1, r1, 0x10
/* 800F1F54  4E 80 00 20 */	blr
