.include "macros.inc"

.section .text, "ax" # { 800f2048..800f38a4 (text) }
/* 800F2048  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F204C  7C 08 02 A6 */	mflr r0
/* 800F2050  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F2054  80 0D 97 50 */	lwz r0, -0x68b0(r13)
/* 800F2058  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F205C  7C 7F 1B 78 */	mr r31, r3
/* 800F2060  2C 00 00 00 */	cmpwi r0, 0
/* 800F2064  40 82 00 18 */	bne 0x18
/* 800F2068  3C 60 80 2F */	lis r3, 0x802f
/* 800F206C  38 63 22 E0 */	addi r3, r3, 0x22e0
/* 800F2070  48 0B 5E 3D */	bl 0xb5e3c
/* 800F2074  38 00 00 01 */	li r0, 1
/* 800F2078  90 0D 97 50 */	stw r0, -0x68b0(r13)
/* 800F207C  3C 60 80 2F */	lis r3, 0x802f
/* 800F2080  38 63 22 E0 */	addi r3, r3, 0x22e0
/* 800F2084  48 0B 5E 61 */	bl 0xb5e60
/* 800F2088  80 7F 00 00 */	lwz r3, 0(r31)
/* 800F208C  4B FF F5 C1 */	bl -0xa40
/* 800F2090  2C 03 00 00 */	cmpwi r3, 0
/* 800F2094  41 82 00 40 */	beq 0x40
/* 800F2098  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800F209C  38 61 00 0C */	addi r3, r1, 0xc
/* 800F20A0  80 84 00 00 */	lwz r4, 0(r4)
/* 800F20A4  80 04 00 00 */	lwz r0, 0(r4)
/* 800F20A8  90 01 00 0C */	stw r0, 0xc(r1)
/* 800F20AC  48 0F B8 8D */	bl 0xfb88c
/* 800F20B0  38 81 00 08 */	addi r4, r1, 8
/* 800F20B4  48 0F B7 79 */	bl 0xfb778
/* 800F20B8  2C 03 00 00 */	cmpwi r3, 0
/* 800F20BC  40 82 00 0C */	bne 0xc
/* 800F20C0  38 00 FF FF */	li r0, -1
/* 800F20C4  48 00 00 08 */	b 0x8
/* 800F20C8  80 01 00 08 */	lwz r0, 8(r1)
/* 800F20CC  90 1F 00 04 */	stw r0, 4(r31)
/* 800F20D0  48 00 00 0C */	b 0xc
/* 800F20D4  38 00 FF FF */	li r0, -1
/* 800F20D8  90 1F 00 04 */	stw r0, 4(r31)
/* 800F20DC  38 00 00 01 */	li r0, 1
/* 800F20E0  3C 60 80 2F */	lis r3, 0x802f
/* 800F20E4  90 1F 00 08 */	stw r0, 8(r31)
/* 800F20E8  38 63 22 E0 */	addi r3, r3, 0x22e0
/* 800F20EC  48 0B 5E D5 */	bl 0xb5ed4
/* 800F20F0  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F20F4  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F20F8  7C 08 03 A6 */	mtlr r0
/* 800F20FC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F2100  4E 80 00 20 */	blr
/* 800F2104  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F2108  7C 08 02 A6 */	mflr r0
/* 800F210C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F2110  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F2114  3F E0 80 2F */	lis r31, 0x802f
/* 800F2118  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F211C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F2120  7C 9D 23 78 */	mr r29, r4
/* 800F2124  93 81 00 10 */	stw r28, 0x10(r1)
/* 800F2128  7C 7C 1B 78 */	mr r28, r3
/* 800F212C  38 60 03 30 */	li r3, 0x330
/* 800F2130  81 9F 21 68 */	lwz r12, 0x2168(r31)
/* 800F2134  7D 89 03 A6 */	mtctr r12
/* 800F2138  4E 80 04 21 */	bctrl
/* 800F213C  2C 03 00 00 */	cmpwi r3, 0
/* 800F2140  7C 7E 1B 78 */	mr r30, r3
/* 800F2144  40 82 00 0C */	bne 0xc
/* 800F2148  38 60 FF FF */	li r3, -1
/* 800F214C  48 00 00 CC */	b 0xcc
/* 800F2150  2C 1C 00 00 */	cmpwi r28, 0
/* 800F2154  40 82 00 0C */	bne 0xc
/* 800F2158  3B E0 00 00 */	li r31, 0
/* 800F215C  48 00 00 30 */	b 0x30
/* 800F2160  7F 83 E3 78 */	mr r3, r28
/* 800F2164  4B F2 F0 F1 */	bl -0xd0f10
/* 800F2168  81 9F 21 68 */	lwz r12, 0x2168(r31)
/* 800F216C  7D 89 03 A6 */	mtctr r12
/* 800F2170  38 63 00 01 */	addi r3, r3, 1
/* 800F2174  4E 80 04 21 */	bctrl
/* 800F2178  2C 03 00 00 */	cmpwi r3, 0
/* 800F217C  7C 7F 1B 78 */	mr r31, r3
/* 800F2180  41 82 00 0C */	beq 0xc
/* 800F2184  7F 84 E3 78 */	mr r4, r28
/* 800F2188  4B F2 0F 99 */	bl -0xdf068
/* 800F218C  2C 1F 00 00 */	cmpwi r31, 0
/* 800F2190  93 FE 00 00 */	stw r31, 0(r30)
/* 800F2194  40 82 00 2C */	bne 0x2c
/* 800F2198  2C 1E 00 00 */	cmpwi r30, 0
/* 800F219C  41 82 00 1C */	beq 0x1c
/* 800F21A0  3C 80 80 2F */	lis r4, 0x802f
/* 800F21A4  7F C3 F3 78 */	mr r3, r30
/* 800F21A8  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F21AC  81 84 00 04 */	lwz r12, 4(r4)
/* 800F21B0  7D 89 03 A6 */	mtctr r12
/* 800F21B4  4E 80 04 21 */	bctrl
/* 800F21B8  38 60 FF FF */	li r3, -1
/* 800F21BC  48 00 00 5C */	b 0x5c
/* 800F21C0  38 00 00 00 */	li r0, 0
/* 800F21C4  3C 80 80 2F */	lis r4, 0x802f
/* 800F21C8  90 1E 00 08 */	stw r0, 8(r30)
/* 800F21CC  38 60 10 00 */	li r3, 0x1000
/* 800F21D0  81 84 21 68 */	lwz r12, 0x2168(r4)
/* 800F21D4  7D 89 03 A6 */	mtctr r12
/* 800F21D8  4E 80 04 21 */	bctrl
/* 800F21DC  7C 66 1B 78 */	mr r6, r3
/* 800F21E0  90 7E 03 28 */	stw r3, 0x328(r30)
/* 800F21E4  3C 80 80 0F */	lis r4, 0x800f
/* 800F21E8  7F C5 F3 78 */	mr r5, r30
/* 800F21EC  38 7E 00 10 */	addi r3, r30, 0x10
/* 800F21F0  38 C6 10 00 */	addi r6, r6, 0x1000
/* 800F21F4  38 84 20 48 */	addi r4, r4, 0x2048
/* 800F21F8  38 E0 10 00 */	li r7, 0x1000
/* 800F21FC  39 00 00 10 */	li r8, 0x10
/* 800F2200  39 20 00 01 */	li r9, 1
/* 800F2204  48 0B 7C 81 */	bl 0xb7c80
/* 800F2208  38 7E 00 10 */	addi r3, r30, 0x10
/* 800F220C  48 0B 83 81 */	bl 0xb8380
/* 800F2210  93 DD 00 00 */	stw r30, 0(r29)
/* 800F2214  38 60 00 00 */	li r3, 0
/* 800F2218  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F221C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F2220  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F2224  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F2228  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F222C  7C 08 03 A6 */	mtlr r0
/* 800F2230  38 21 00 20 */	addi r1, r1, 0x20
/* 800F2234  4E 80 00 20 */	blr
/* 800F2238  94 21 FC D0 */	stwu r1, -0x330(r1)
/* 800F223C  7C 08 02 A6 */	mflr r0
/* 800F2240  38 83 00 0C */	addi r4, r3, 0xc
/* 800F2244  90 01 03 34 */	stw r0, 0x334(r1)
/* 800F2248  38 00 00 64 */	li r0, 0x64
/* 800F224C  38 A1 00 04 */	addi r5, r1, 4
/* 800F2250  93 E1 03 2C */	stw r31, 0x32c(r1)
/* 800F2254  7C 7F 1B 78 */	mr r31, r3
/* 800F2258  7C 09 03 A6 */	mtctr r0
/* 800F225C  80 64 00 04 */	lwz r3, 4(r4)
/* 800F2260  84 04 00 08 */	lwzu r0, 8(r4)
/* 800F2264  90 65 00 04 */	stw r3, 4(r5)
/* 800F2268  94 05 00 08 */	stwu r0, 8(r5)
/* 800F226C  42 00 FF F0 */	bdnz -0x10
/* 800F2270  38 61 00 08 */	addi r3, r1, 8
/* 800F2274  48 0B 7F 61 */	bl 0xb7f60
/* 800F2278  80 61 03 20 */	lwz r3, 0x320(r1)
/* 800F227C  2C 03 00 00 */	cmpwi r3, 0
/* 800F2280  41 82 00 24 */	beq 0x24
/* 800F2284  41 82 00 18 */	beq 0x18
/* 800F2288  3C 80 80 2F */	lis r4, 0x802f
/* 800F228C  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F2290  81 84 00 04 */	lwz r12, 4(r4)
/* 800F2294  7D 89 03 A6 */	mtctr r12
/* 800F2298  4E 80 04 21 */	bctrl
/* 800F229C  38 00 00 00 */	li r0, 0
/* 800F22A0  90 01 03 20 */	stw r0, 0x320(r1)
/* 800F22A4  80 7F 00 00 */	lwz r3, 0(r31)
/* 800F22A8  2C 03 00 00 */	cmpwi r3, 0
/* 800F22AC  41 82 00 18 */	beq 0x18
/* 800F22B0  3C 80 80 2F */	lis r4, 0x802f
/* 800F22B4  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F22B8  81 84 00 04 */	lwz r12, 4(r4)
/* 800F22BC  7D 89 03 A6 */	mtctr r12
/* 800F22C0  4E 80 04 21 */	bctrl
/* 800F22C4  38 00 00 00 */	li r0, 0
/* 800F22C8  2C 1F 00 00 */	cmpwi r31, 0
/* 800F22CC  90 1F 00 00 */	stw r0, 0(r31)
/* 800F22D0  41 82 00 1C */	beq 0x1c
/* 800F22D4  3C 80 80 2F */	lis r4, 0x802f
/* 800F22D8  7F E3 FB 78 */	mr r3, r31
/* 800F22DC  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F22E0  81 84 00 04 */	lwz r12, 4(r4)
/* 800F22E4  7D 89 03 A6 */	mtctr r12
/* 800F22E8  4E 80 04 21 */	bctrl
/* 800F22EC  80 01 03 34 */	lwz r0, 0x334(r1)
/* 800F22F0  83 E1 03 2C */	lwz r31, 0x32c(r1)
/* 800F22F4  7C 08 03 A6 */	mtlr r0
/* 800F22F8  38 21 03 30 */	addi r1, r1, 0x330
/* 800F22FC  4E 80 00 20 */	blr
/* 800F2300  94 21 FC D0 */	stwu r1, -0x330(r1)
/* 800F2304  7C 08 02 A6 */	mflr r0
/* 800F2308  90 01 03 34 */	stw r0, 0x334(r1)
/* 800F230C  93 E1 03 2C */	stw r31, 0x32c(r1)
/* 800F2310  93 C1 03 28 */	stw r30, 0x328(r1)
/* 800F2314  7C 7E 1B 78 */	mr r30, r3
/* 800F2318  80 03 00 08 */	lwz r0, 8(r3)
/* 800F231C  2C 00 00 00 */	cmpwi r0, 0
/* 800F2320  40 82 00 0C */	bne 0xc
/* 800F2324  38 60 00 00 */	li r3, 0
/* 800F2328  48 00 00 B4 */	b 0xb4
/* 800F232C  38 00 00 64 */	li r0, 0x64
/* 800F2330  38 A1 00 04 */	addi r5, r1, 4
/* 800F2334  38 83 00 0C */	addi r4, r3, 0xc
/* 800F2338  83 E3 00 04 */	lwz r31, 4(r3)
/* 800F233C  7C 09 03 A6 */	mtctr r0
/* 800F2340  80 64 00 04 */	lwz r3, 4(r4)
/* 800F2344  84 04 00 08 */	lwzu r0, 8(r4)
/* 800F2348  90 65 00 04 */	stw r3, 4(r5)
/* 800F234C  94 05 00 08 */	stwu r0, 8(r5)
/* 800F2350  42 00 FF F0 */	bdnz -0x10
/* 800F2354  38 61 00 08 */	addi r3, r1, 8
/* 800F2358  48 0B 75 65 */	bl 0xb7564
/* 800F235C  2C 03 00 00 */	cmpwi r3, 0
/* 800F2360  40 82 00 0C */	bne 0xc
/* 800F2364  38 61 00 08 */	addi r3, r1, 8
/* 800F2368  48 0B 7E 6D */	bl 0xb7e6c
/* 800F236C  80 61 03 20 */	lwz r3, 0x320(r1)
/* 800F2370  2C 03 00 00 */	cmpwi r3, 0
/* 800F2374  41 82 00 24 */	beq 0x24
/* 800F2378  41 82 00 18 */	beq 0x18
/* 800F237C  3C 80 80 2F */	lis r4, 0x802f
/* 800F2380  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F2384  81 84 00 04 */	lwz r12, 4(r4)
/* 800F2388  7D 89 03 A6 */	mtctr r12
/* 800F238C  4E 80 04 21 */	bctrl
/* 800F2390  38 00 00 00 */	li r0, 0
/* 800F2394  90 01 03 20 */	stw r0, 0x320(r1)
/* 800F2398  80 7E 00 00 */	lwz r3, 0(r30)
/* 800F239C  2C 03 00 00 */	cmpwi r3, 0
/* 800F23A0  41 82 00 18 */	beq 0x18
/* 800F23A4  3C 80 80 2F */	lis r4, 0x802f
/* 800F23A8  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F23AC  81 84 00 04 */	lwz r12, 4(r4)
/* 800F23B0  7D 89 03 A6 */	mtctr r12
/* 800F23B4  4E 80 04 21 */	bctrl
/* 800F23B8  2C 1E 00 00 */	cmpwi r30, 0
/* 800F23BC  41 82 00 1C */	beq 0x1c
/* 800F23C0  3C 80 80 2F */	lis r4, 0x802f
/* 800F23C4  7F C3 F3 78 */	mr r3, r30
/* 800F23C8  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F23CC  81 84 00 04 */	lwz r12, 4(r4)
/* 800F23D0  7D 89 03 A6 */	mtctr r12
/* 800F23D4  4E 80 04 21 */	bctrl
/* 800F23D8  7F E3 FB 78 */	mr r3, r31
/* 800F23DC  80 01 03 34 */	lwz r0, 0x334(r1)
/* 800F23E0  83 E1 03 2C */	lwz r31, 0x32c(r1)
/* 800F23E4  83 C1 03 28 */	lwz r30, 0x328(r1)
/* 800F23E8  7C 08 03 A6 */	mtlr r0
/* 800F23EC  38 21 03 30 */	addi r1, r1, 0x330
/* 800F23F0  4E 80 00 20 */	blr
/* 800F23F4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F23F8  7C 08 02 A6 */	mflr r0
/* 800F23FC  2C 03 00 00 */	cmpwi r3, 0
/* 800F2400  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F2404  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F2408  93 C1 00 08 */	stw r30, 8(r1)
/* 800F240C  7C 7E 1B 78 */	mr r30, r3
/* 800F2410  40 82 00 0C */	bne 0xc
/* 800F2414  38 60 00 00 */	li r3, 0
/* 800F2418  48 00 00 34 */	b 0x34
/* 800F241C  4B F2 EE 39 */	bl -0xd11c8
/* 800F2420  3C 80 80 2F */	lis r4, 0x802f
/* 800F2424  81 84 21 68 */	lwz r12, 0x2168(r4)
/* 800F2428  7D 89 03 A6 */	mtctr r12
/* 800F242C  38 63 00 01 */	addi r3, r3, 1
/* 800F2430  4E 80 04 21 */	bctrl
/* 800F2434  2C 03 00 00 */	cmpwi r3, 0
/* 800F2438  7C 7F 1B 78 */	mr r31, r3
/* 800F243C  41 82 00 0C */	beq 0xc
/* 800F2440  7F C4 F3 78 */	mr r4, r30
/* 800F2444  4B F2 0C DD */	bl -0xdf324
/* 800F2448  7F E3 FB 78 */	mr r3, r31
/* 800F244C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F2450  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F2454  83 C1 00 08 */	lwz r30, 8(r1)
/* 800F2458  7C 08 03 A6 */	mtlr r0
/* 800F245C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F2460  4E 80 00 20 */	blr
/* 800F2464  3C A0 80 27 */	lis r5, 0x8027
/* 800F2468  7C 67 1B 78 */	mr r7, r3
/* 800F246C  38 A5 11 48 */	addi r5, r5, 0x1148
/* 800F2470  48 00 00 3C */	b 0x3c
/* 800F2474  7C 86 07 75 */	extsb. r6, r4
/* 800F2478  38 00 00 00 */	li r0, 0
/* 800F247C  41 80 00 0C */	blt 0xc
/* 800F2480  2C 06 01 00 */	cmpwi r6, 0x100
/* 800F2484  41 80 00 08 */	blt 0x8
/* 800F2488  38 00 00 01 */	li r0, 1
/* 800F248C  2C 00 00 00 */	cmpwi r0, 0
/* 800F2490  41 82 00 08 */	beq 0x8
/* 800F2494  48 00 00 10 */	b 0x10
/* 800F2498  80 85 00 38 */	lwz r4, 0x38(r5)
/* 800F249C  80 84 00 10 */	lwz r4, 0x10(r4)
/* 800F24A0  7C C4 30 AE */	lbzx r6, r4, r6
/* 800F24A4  98 C3 00 00 */	stb r6, 0(r3)
/* 800F24A8  38 63 00 01 */	addi r3, r3, 1
/* 800F24AC  88 83 00 00 */	lbz r4, 0(r3)
/* 800F24B0  7C 80 07 75 */	extsb. r0, r4
/* 800F24B4  40 82 FF C0 */	bne -0x40
/* 800F24B8  7C E3 3B 78 */	mr r3, r7
/* 800F24BC  4E 80 00 20 */	blr
/* 800F24C0  4E 80 00 20 */	blr
/* 800F24C4  4E 80 00 20 */	blr
/* 800F24C8  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F24CC  7C 08 02 A6 */	mflr r0
/* 800F24D0  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F24D4  48 0B 88 89 */	bl 0xb8888
/* 800F24D8  3C C0 80 00 */	lis r6, 0x8000
/* 800F24DC  3C A0 10 62 */	lis r5, 0x1062
/* 800F24E0  80 06 00 F8 */	lwz r0, 0xf8(r6)
/* 800F24E4  38 C5 4D D3 */	addi r6, r5, 0x4dd3
/* 800F24E8  38 A0 00 00 */	li r5, 0
/* 800F24EC  54 00 F0 BE */	srwi r0, r0, 2
/* 800F24F0  7C 06 00 16 */	mulhwu r0, r6, r0
/* 800F24F4  54 06 D1 BE */	srwi r6, r0, 6
/* 800F24F8  4B F2 F1 F9 */	bl -0xd0e08
/* 800F24FC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F2500  7C 83 23 78 */	mr r3, r4
/* 800F2504  7C 08 03 A6 */	mtlr r0
/* 800F2508  38 21 00 10 */	addi r1, r1, 0x10
/* 800F250C  4E 80 00 20 */	blr
/* 800F2510  3C A0 80 00 */	lis r5, 0x8000
/* 800F2514  3C 80 10 62 */	lis r4, 0x1062
/* 800F2518  80 05 00 F8 */	lwz r0, 0xf8(r5)
/* 800F251C  38 84 4D D3 */	addi r4, r4, 0x4dd3
/* 800F2520  38 C0 00 00 */	li r6, 0
/* 800F2524  54 00 F0 BE */	srwi r0, r0, 2
/* 800F2528  7C 84 00 16 */	mulhwu r4, r4, r0
/* 800F252C  7C 03 31 D6 */	mullw r0, r3, r6
/* 800F2530  54 84 D1 BE */	srwi r4, r4, 6
/* 800F2534  7C A3 20 16 */	mulhwu r5, r3, r4
/* 800F2538  7C C6 21 D6 */	mullw r6, r6, r4
/* 800F253C  7C 83 21 D6 */	mullw r4, r3, r4
/* 800F2540  7C 65 32 14 */	add r3, r5, r6
/* 800F2544  7C 63 02 14 */	add r3, r3, r0
/* 800F2548  48 0B 87 60 */	b 0xb8760
/* 800F254C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F2550  7C 08 02 A6 */	mflr r0
/* 800F2554  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F2558  39 61 00 20 */	addi r11, r1, 0x20
/* 800F255C  4B F2 F0 41 */	bl -0xd0fc0
/* 800F2560  83 E3 00 00 */	lwz r31, 0(r3)
/* 800F2564  3B A0 00 00 */	li r29, 0
/* 800F2568  83 C3 00 04 */	lwz r30, 4(r3)
/* 800F256C  3F 80 80 2F */	lis r28, 0x802f
/* 800F2570  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800F2574  6F A5 80 00 */	xoris r5, r29, 0x8000
/* 800F2578  7C 9D F0 10 */	subfc r4, r29, r30
/* 800F257C  7C 7B 1B 78 */	mr r27, r3
/* 800F2580  7C A5 01 10 */	subfe r5, r5, r0
/* 800F2584  3B 9C 22 F8 */	addi r28, r28, 0x22f8
/* 800F2588  7C A0 01 10 */	subfe r5, r0, r0
/* 800F258C  7C A5 00 D1 */	neg. r5, r5
/* 800F2590  41 82 00 0C */	beq 0xc
/* 800F2594  38 60 00 00 */	li r3, 0
/* 800F2598  48 00 02 04 */	b 0x204
/* 800F259C  3F 40 07 86 */	lis r26, 0x786
/* 800F25A0  7F E3 FB 78 */	mr r3, r31
/* 800F25A4  7F C4 F3 78 */	mr r4, r30
/* 800F25A8  38 A0 00 00 */	li r5, 0
/* 800F25AC  38 DA 1F 80 */	addi r6, r26, 0x1f80
/* 800F25B0  4B F2 F1 41 */	bl -0xd0ec0
/* 800F25B4  38 1A 1F 80 */	addi r0, r26, 0x1f80
/* 800F25B8  3C 60 01 E1 */	lis r3, 0x1e1
/* 800F25BC  7C C4 01 D6 */	mullw r6, r4, r0
/* 800F25C0  54 85 10 3A */	slwi r5, r4, 2
/* 800F25C4  38 E0 00 00 */	li r7, 0
/* 800F25C8  39 03 33 80 */	addi r8, r3, 0x3380
/* 800F25CC  6C E4 80 00 */	xoris r4, r7, 0x8000
/* 800F25D0  39 25 00 46 */	addi r9, r5, 0x46
/* 800F25D4  7C C0 FE 70 */	srawi r0, r6, 0x1f
/* 800F25D8  7F C6 F0 10 */	subfc r30, r6, r30
/* 800F25DC  7F E0 F9 10 */	subfe r31, r0, r31
/* 800F25E0  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800F25E4  7C 68 F0 10 */	subfc r3, r8, r30
/* 800F25E8  7C 84 01 10 */	subfe r4, r4, r0
/* 800F25EC  7C 80 01 10 */	subfe r4, r0, r0
/* 800F25F0  7C 84 00 D1 */	neg. r4, r4
/* 800F25F4  40 82 00 84 */	bne 0x84
/* 800F25F8  3C 60 FE 1F */	lis r3, 0xfe1f
/* 800F25FC  38 A0 FF FF */	li r5, -1
/* 800F2600  38 C3 CC 80 */	addi r6, r3, -13184
/* 800F2604  6C E4 80 00 */	xoris r4, r7, 0x8000
/* 800F2608  7F DE 30 14 */	addc r30, r30, r6
/* 800F260C  39 29 00 01 */	addi r9, r9, 1
/* 800F2610  7F FF 29 14 */	adde r31, r31, r5
/* 800F2614  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800F2618  7C 68 F0 10 */	subfc r3, r8, r30
/* 800F261C  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2620  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2624  7C 84 00 D1 */	neg. r4, r4
/* 800F2628  40 82 00 50 */	bne 0x50
/* 800F262C  7F DE 30 14 */	addc r30, r30, r6
/* 800F2630  3C 60 01 E3 */	lis r3, 0x1e3
/* 800F2634  7F FF 29 14 */	adde r31, r31, r5
/* 800F2638  6C E4 80 00 */	xoris r4, r7, 0x8000
/* 800F263C  38 63 85 00 */	addi r3, r3, -31488
/* 800F2640  39 29 00 01 */	addi r9, r9, 1
/* 800F2644  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800F2648  7C 63 F0 10 */	subfc r3, r3, r30
/* 800F264C  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2650  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2654  7C 84 00 D1 */	neg. r4, r4
/* 800F2658  40 82 00 1C */	bne 0x1c
/* 800F265C  3C 60 FE 1D */	lis r3, 0xfe1d
/* 800F2660  39 29 00 01 */	addi r9, r9, 1
/* 800F2664  38 03 7B 00 */	addi r0, r3, 0x7b00
/* 800F2668  7F DE 00 14 */	addc r30, r30, r0
/* 800F266C  7F FF 29 14 */	adde r31, r31, r5
/* 800F2670  48 00 00 08 */	b 0x8
/* 800F2674  3B A0 00 01 */	li r29, 1
/* 800F2678  3F 40 00 01 */	lis r26, 1
/* 800F267C  91 3C 00 14 */	stw r9, 0x14(r28)
/* 800F2680  7F E3 FB 78 */	mr r3, r31
/* 800F2684  7F C4 F3 78 */	mr r4, r30
/* 800F2688  38 DA 51 80 */	addi r6, r26, 0x5180
/* 800F268C  38 A0 00 00 */	li r5, 0
/* 800F2690  4B F2 F0 61 */	bl -0xd0fa0
/* 800F2694  38 1A 51 80 */	addi r0, r26, 0x5180
/* 800F2698  3C A0 80 28 */	lis r5, 0x8028
/* 800F269C  7C 64 01 D6 */	mullw r3, r4, r0
/* 800F26A0  2C 1D 00 00 */	cmpwi r29, 0
/* 800F26A4  90 9C 00 1C */	stw r4, 0x1c(r28)
/* 800F26A8  38 A5 AD 20 */	addi r5, r5, -21216
/* 800F26AC  7C 60 FE 70 */	srawi r0, r3, 0x1f
/* 800F26B0  7F C3 F0 10 */	subfc r30, r3, r30
/* 800F26B4  7F E0 F9 10 */	subfe r31, r0, r31
/* 800F26B8  41 82 00 0C */	beq 0xc
/* 800F26BC  3C A0 80 28 */	lis r5, 0x8028
/* 800F26C0  38 A5 AC EC */	addi r5, r5, -21268
/* 800F26C4  38 65 00 04 */	addi r3, r5, 4
/* 800F26C8  38 C0 00 01 */	li r6, 1
/* 800F26CC  48 00 00 0C */	b 0xc
/* 800F26D0  38 63 00 04 */	addi r3, r3, 4
/* 800F26D4  38 C6 00 01 */	addi r6, r6, 1
/* 800F26D8  80 03 00 00 */	lwz r0, 0(r3)
/* 800F26DC  7C 00 20 00 */	cmpw r0, r4
/* 800F26E0  41 80 FF F0 */	blt -0x10
/* 800F26E4  38 C6 FF FF */	addi r6, r6, -1
/* 800F26E8  80 1C 00 1C */	lwz r0, 0x1c(r28)
/* 800F26EC  90 DC 00 10 */	stw r6, 0x10(r28)
/* 800F26F0  54 C4 10 3A */	slwi r4, r6, 2
/* 800F26F4  3C 60 00 01 */	lis r3, 1
/* 800F26F8  7C 85 20 2E */	lwzx r4, r5, r4
/* 800F26FC  38 C3 51 80 */	addi r6, r3, 0x5180
/* 800F2700  80 7B 00 00 */	lwz r3, 0(r27)
/* 800F2704  38 A0 00 00 */	li r5, 0
/* 800F2708  7C 04 00 50 */	subf r0, r4, r0
/* 800F270C  80 9B 00 04 */	lwz r4, 4(r27)
/* 800F2710  90 1C 00 0C */	stw r0, 0xc(r28)
/* 800F2714  4B F2 EF DD */	bl -0xd1024
/* 800F2718  3C 60 92 49 */	lis r3, 0x9249
/* 800F271C  39 04 00 04 */	addi r8, r4, 4
/* 800F2720  38 03 24 93 */	addi r0, r3, 0x2493
/* 800F2724  7F C4 F3 78 */	mr r4, r30
/* 800F2728  7C 00 40 96 */	mulhw r0, r0, r8
/* 800F272C  7F E3 FB 78 */	mr r3, r31
/* 800F2730  38 C0 0E 10 */	li r6, 0xe10
/* 800F2734  38 A0 00 00 */	li r5, 0
/* 800F2738  7C 00 42 14 */	add r0, r0, r8
/* 800F273C  7C 00 16 70 */	srawi r0, r0, 2
/* 800F2740  54 07 0F FE */	srwi r7, r0, 0x1f
/* 800F2744  7C 00 3A 14 */	add r0, r0, r7
/* 800F2748  1C 00 00 07 */	mulli r0, r0, 7
/* 800F274C  7C 00 40 50 */	subf r0, r0, r8
/* 800F2750  90 1C 00 18 */	stw r0, 0x18(r28)
/* 800F2754  4B F2 EF 9D */	bl -0xd1064
/* 800F2758  1C 64 0E 10 */	mulli r3, r4, 0xe10
/* 800F275C  90 9C 00 08 */	stw r4, 8(r28)
/* 800F2760  38 C0 00 3C */	li r6, 0x3c
/* 800F2764  38 A0 00 00 */	li r5, 0
/* 800F2768  7C 60 FE 70 */	srawi r0, r3, 0x1f
/* 800F276C  7F C3 F0 10 */	subfc r30, r3, r30
/* 800F2770  7C 60 F9 10 */	subfe r3, r0, r31
/* 800F2774  7F C4 F3 78 */	mr r4, r30
/* 800F2778  4B F2 EF 79 */	bl -0xd1088
/* 800F277C  1C A4 00 3C */	mulli r5, r4, 0x3c
/* 800F2780  38 00 00 00 */	li r0, 0
/* 800F2784  90 9C 00 04 */	stw r4, 4(r28)
/* 800F2788  7F 83 E3 78 */	mr r3, r28
/* 800F278C  7C A4 FE 70 */	srawi r4, r5, 0x1f
/* 800F2790  90 1C 00 20 */	stw r0, 0x20(r28)
/* 800F2794  7C 05 F0 10 */	subfc r0, r5, r30
/* 800F2798  90 1C 00 00 */	stw r0, 0(r28)
/* 800F279C  39 61 00 20 */	addi r11, r1, 0x20
/* 800F27A0  4B F2 EE 49 */	bl -0xd11b8
/* 800F27A4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F27A8  7C 08 03 A6 */	mtlr r0
/* 800F27AC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F27B0  4E 80 00 20 */	blr
/* 800F27B4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F27B8  7C 08 02 A6 */	mflr r0
/* 800F27BC  38 C0 00 00 */	li r6, 0
/* 800F27C0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F27C4  38 00 00 45 */	li r0, 0x45
/* 800F27C8  6C C4 80 00 */	xoris r4, r6, 0x8000
/* 800F27CC  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F27D0  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F27D4  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F27D8  7C 7D 1B 78 */	mr r29, r3
/* 800F27DC  93 81 00 10 */	stw r28, 0x10(r1)
/* 800F27E0  81 03 00 14 */	lwz r8, 0x14(r3)
/* 800F27E4  7D 07 FE 70 */	srawi r7, r8, 0x1f
/* 800F27E8  91 01 00 0C */	stw r8, 0xc(r1)
/* 800F27EC  6C E5 80 00 */	xoris r5, r7, 0x8000
/* 800F27F0  7C 00 40 10 */	subfc r0, r0, r8
/* 800F27F4  7C 84 29 10 */	subfe r4, r4, r5
/* 800F27F8  90 E1 00 08 */	stw r7, 8(r1)
/* 800F27FC  7C 85 29 10 */	subfe r4, r5, r5
/* 800F2800  7C 84 00 D1 */	neg. r4, r4
/* 800F2804  40 82 00 20 */	bne 0x20
/* 800F2808  38 80 00 8B */	li r4, 0x8b
/* 800F280C  6C C0 80 00 */	xoris r0, r6, 0x8000
/* 800F2810  7C 88 20 10 */	subfc r4, r8, r4
/* 800F2814  7C 85 01 10 */	subfe r4, r5, r0
/* 800F2818  7C 80 01 10 */	subfe r4, r0, r0
/* 800F281C  7C 84 00 D1 */	neg. r4, r4
/* 800F2820  41 82 00 10 */	beq 0x10
/* 800F2824  38 80 FF FF */	li r4, -1
/* 800F2828  38 60 FF FF */	li r3, -1
/* 800F282C  48 00 06 7C */	b 0x67c
/* 800F2830  80 03 00 10 */	lwz r0, 0x10(r3)
/* 800F2834  2C 00 00 00 */	cmpwi r0, 0
/* 800F2838  41 80 00 0C */	blt 0xc
/* 800F283C  2C 00 00 0B */	cmpwi r0, 0xb
/* 800F2840  40 81 00 D4 */	ble 0xd4
/* 800F2844  3C 80 2A AB */	lis r4, 0x2aab
/* 800F2848  80 E1 00 0C */	lwz r7, 0xc(r1)
/* 800F284C  38 C4 AA AB */	addi r6, r4, -21845
/* 800F2850  80 A1 00 08 */	lwz r5, 8(r1)
/* 800F2854  7C 06 00 96 */	mulhw r0, r6, r0
/* 800F2858  7C 00 0E 70 */	srawi r0, r0, 1
/* 800F285C  54 04 0F FE */	srwi r4, r0, 0x1f
/* 800F2860  7C 80 22 14 */	add r4, r0, r4
/* 800F2864  7C 80 FE 70 */	srawi r0, r4, 0x1f
/* 800F2868  7C 87 20 14 */	addc r4, r7, r4
/* 800F286C  7C 05 01 14 */	adde r0, r5, r0
/* 800F2870  90 81 00 0C */	stw r4, 0xc(r1)
/* 800F2874  90 01 00 08 */	stw r0, 8(r1)
/* 800F2878  80 A3 00 10 */	lwz r5, 0x10(r3)
/* 800F287C  7C 06 28 96 */	mulhw r0, r6, r5
/* 800F2880  7C 00 0E 70 */	srawi r0, r0, 1
/* 800F2884  54 04 0F FE */	srwi r4, r0, 0x1f
/* 800F2888  7C 00 22 14 */	add r0, r0, r4
/* 800F288C  1C 00 00 0C */	mulli r0, r0, 0xc
/* 800F2890  7C 80 28 51 */	subf. r4, r0, r5
/* 800F2894  90 83 00 10 */	stw r4, 0x10(r3)
/* 800F2898  40 80 00 28 */	bge 0x28
/* 800F289C  38 84 00 0C */	addi r4, r4, 0xc
/* 800F28A0  38 00 FF FF */	li r0, -1
/* 800F28A4  90 83 00 10 */	stw r4, 0x10(r3)
/* 800F28A8  80 81 00 0C */	lwz r4, 0xc(r1)
/* 800F28AC  80 A1 00 08 */	lwz r5, 8(r1)
/* 800F28B0  7C 84 00 14 */	addc r4, r4, r0
/* 800F28B4  7C 05 01 14 */	adde r0, r5, r0
/* 800F28B8  90 81 00 0C */	stw r4, 0xc(r1)
/* 800F28BC  90 01 00 08 */	stw r0, 8(r1)
/* 800F28C0  80 81 00 08 */	lwz r4, 8(r1)
/* 800F28C4  38 C0 00 00 */	li r6, 0
/* 800F28C8  81 01 00 0C */	lwz r8, 0xc(r1)
/* 800F28CC  38 00 00 45 */	li r0, 0x45
/* 800F28D0  6C 85 80 00 */	xoris r5, r4, 0x8000
/* 800F28D4  6C C4 80 00 */	xoris r4, r6, 0x8000
/* 800F28D8  7C 00 40 10 */	subfc r0, r0, r8
/* 800F28DC  7C 84 29 10 */	subfe r4, r4, r5
/* 800F28E0  7C 85 29 10 */	subfe r4, r5, r5
/* 800F28E4  7C 84 00 D1 */	neg. r4, r4
/* 800F28E8  40 82 00 20 */	bne 0x20
/* 800F28EC  38 80 00 8B */	li r4, 0x8b
/* 800F28F0  6C C0 80 00 */	xoris r0, r6, 0x8000
/* 800F28F4  7C 88 20 10 */	subfc r4, r8, r4
/* 800F28F8  7C 85 01 10 */	subfe r4, r5, r0
/* 800F28FC  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2900  7C 84 00 D1 */	neg. r4, r4
/* 800F2904  41 82 00 10 */	beq 0x10
/* 800F2908  38 80 FF FF */	li r4, -1
/* 800F290C  38 60 FF FF */	li r3, -1
/* 800F2910  48 00 05 98 */	b 0x598
/* 800F2914  80 C3 00 10 */	lwz r6, 0x10(r3)
/* 800F2918  55 00 07 BF */	clrlwi. r0, r8, 0x1e
/* 800F291C  3C 80 80 28 */	lis r4, 0x8028
/* 800F2920  54 C0 10 3A */	slwi r0, r6, 2
/* 800F2924  38 84 AD 20 */	addi r4, r4, -21216
/* 800F2928  7C A4 00 2E */	lwzx r5, r4, r0
/* 800F292C  7C A4 FE 70 */	srawi r4, r5, 0x1f
/* 800F2930  40 82 00 1C */	bne 0x1c
/* 800F2934  2C 06 00 01 */	cmpwi r6, 1
/* 800F2938  40 81 00 14 */	ble 0x14
/* 800F293C  38 C0 00 01 */	li r6, 1
/* 800F2940  38 00 00 00 */	li r0, 0
/* 800F2944  7C A5 30 14 */	addc r5, r5, r6
/* 800F2948  7C 84 01 14 */	adde r4, r4, r0
/* 800F294C  81 01 00 0C */	lwz r8, 0xc(r1)
/* 800F2950  38 C0 FF BA */	li r6, -70
/* 800F2954  81 21 00 08 */	lwz r9, 8(r1)
/* 800F2958  3B 80 FF FF */	li r28, -1
/* 800F295C  7F E8 30 14 */	addc r31, r8, r6
/* 800F2960  39 80 01 6D */	li r12, 0x16d
/* 800F2964  7F C9 E1 14 */	adde r30, r9, r28
/* 800F2968  38 00 00 00 */	li r0, 0
/* 800F296C  7D 08 E0 14 */	addc r8, r8, r28
/* 800F2970  38 E0 FF EF */	li r7, -17
/* 800F2974  7D 49 E1 14 */	adde r10, r9, r28
/* 800F2978  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800F297C  55 08 F0 3E */	rotlwi r8, r8, 0x1e
/* 800F2980  6C 06 80 00 */	xoris r6, r0, 0x8000
/* 800F2984  7D 49 16 70 */	srawi r9, r10, 2
/* 800F2988  51 48 F0 02 */	rlwimi r8, r10, 0x1e, 0, 1
/* 800F298C  7D 08 38 14 */	addc r8, r8, r7
/* 800F2990  7C E9 E1 14 */	adde r7, r9, r28
/* 800F2994  1D 5F 01 6D */	mulli r10, r31, 0x16d
/* 800F2998  7D 7F 60 16 */	mulhwu r11, r31, r12
/* 800F299C  7D 0A 40 14 */	addc r8, r10, r8
/* 800F29A0  7D 3E 61 D6 */	mullw r9, r30, r12
/* 800F29A4  7D 2B 4A 14 */	add r9, r11, r9
/* 800F29A8  7C E9 39 14 */	adde r7, r9, r7
/* 800F29AC  7D 48 28 14 */	addc r10, r8, r5
/* 800F29B0  7D 27 21 14 */	adde r9, r7, r4
/* 800F29B4  7C 6B FE 70 */	srawi r11, r3, 0x1f
/* 800F29B8  7C 65 FE 70 */	srawi r5, r3, 0x1f
/* 800F29BC  6D 24 80 00 */	xoris r4, r9, 0x8000
/* 800F29C0  7D 0A 18 14 */	addc r8, r10, r3
/* 800F29C4  7C E9 29 14 */	adde r7, r9, r5
/* 800F29C8  91 01 00 0C */	stw r8, 0xc(r1)
/* 800F29CC  7C A0 50 10 */	subfc r5, r0, r10
/* 800F29D0  7C C6 21 10 */	subfe r6, r6, r4
/* 800F29D4  90 E1 00 08 */	stw r7, 8(r1)
/* 800F29D8  7C C4 21 10 */	subfe r6, r4, r4
/* 800F29DC  7C C6 00 D1 */	neg. r6, r6
/* 800F29E0  40 82 00 3C */	bne 0x3c
/* 800F29E4  6D 64 80 00 */	xoris r4, r11, 0x8000
/* 800F29E8  6C 06 80 00 */	xoris r6, r0, 0x8000
/* 800F29EC  7C A0 18 10 */	subfc r5, r0, r3
/* 800F29F0  7C C6 21 10 */	subfe r6, r6, r4
/* 800F29F4  7C C4 21 10 */	subfe r6, r4, r4
/* 800F29F8  7C C6 00 D1 */	neg. r6, r6
/* 800F29FC  40 82 00 20 */	bne 0x20
/* 800F2A00  6C 05 80 00 */	xoris r5, r0, 0x8000
/* 800F2A04  6C E4 80 00 */	xoris r4, r7, 0x8000
/* 800F2A08  7C 00 40 10 */	subfc r0, r0, r8
/* 800F2A0C  7C A5 21 10 */	subfe r5, r5, r4
/* 800F2A10  7C A4 21 10 */	subfe r5, r4, r4
/* 800F2A14  7C A5 00 D1 */	neg. r5, r5
/* 800F2A18  40 82 00 64 */	bne 0x64
/* 800F2A1C  38 C0 00 00 */	li r6, 0
/* 800F2A20  6D 20 80 00 */	xoris r0, r9, 0x8000
/* 800F2A24  6C C5 80 00 */	xoris r5, r6, 0x8000
/* 800F2A28  7C 86 50 10 */	subfc r4, r6, r10
/* 800F2A2C  7C A5 01 10 */	subfe r5, r5, r0
/* 800F2A30  7C A0 01 10 */	subfe r5, r0, r0
/* 800F2A34  7C A5 00 D1 */	neg. r5, r5
/* 800F2A38  41 82 00 50 */	beq 0x50
/* 800F2A3C  6D 60 80 00 */	xoris r0, r11, 0x8000
/* 800F2A40  6C C4 80 00 */	xoris r4, r6, 0x8000
/* 800F2A44  7C 66 18 10 */	subfc r3, r6, r3
/* 800F2A48  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2A4C  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2A50  7C 84 00 D1 */	neg. r4, r4
/* 800F2A54  41 82 00 34 */	beq 0x34
/* 800F2A58  80 01 00 08 */	lwz r0, 8(r1)
/* 800F2A5C  6C C4 80 00 */	xoris r4, r6, 0x8000
/* 800F2A60  80 61 00 0C */	lwz r3, 0xc(r1)
/* 800F2A64  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 800F2A68  7C 66 18 10 */	subfc r3, r6, r3
/* 800F2A6C  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2A70  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2A74  7C 84 00 D1 */	neg. r4, r4
/* 800F2A78  40 82 00 10 */	bne 0x10
/* 800F2A7C  38 80 FF FF */	li r4, -1
/* 800F2A80  38 60 FF FF */	li r3, -1
/* 800F2A84  48 00 04 24 */	b 0x424
/* 800F2A88  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 800F2A8C  38 80 00 18 */	li r4, 0x18
/* 800F2A90  80 A1 00 08 */	lwz r5, 8(r1)
/* 800F2A94  7C 66 20 16 */	mulhwu r3, r6, r4
/* 800F2A98  7C C0 2B 79 */	or. r0, r6, r5
/* 800F2A9C  7C 05 21 D6 */	mullw r0, r5, r4
/* 800F2AA0  1F E6 00 18 */	mulli r31, r6, 0x18
/* 800F2AA4  7F C3 02 14 */	add r30, r3, r0
/* 800F2AA8  41 82 00 24 */	beq 0x24
/* 800F2AAC  7F C3 F3 78 */	mr r3, r30
/* 800F2AB0  7F E4 FB 78 */	mr r4, r31
/* 800F2AB4  4B F2 EC 3D */	bl -0xd13c4
/* 800F2AB8  68 84 00 18 */	xori r4, r4, 0x18
/* 800F2ABC  7C 80 1B 78 */	or r0, r4, r3
/* 800F2AC0  30 80 FF FF */	addic r4, r0, -1
/* 800F2AC4  7C 04 01 10 */	subfe r0, r4, r0
/* 800F2AC8  48 00 00 08 */	b 0x8
/* 800F2ACC  38 00 00 00 */	li r0, 0
/* 800F2AD0  2C 00 00 00 */	cmpwi r0, 0
/* 800F2AD4  41 82 00 10 */	beq 0x10
/* 800F2AD8  38 80 FF FF */	li r4, -1
/* 800F2ADC  38 60 FF FF */	li r3, -1
/* 800F2AE0  48 00 03 C8 */	b 0x3c8
/* 800F2AE4  81 3D 00 08 */	lwz r9, 8(r29)
/* 800F2AE8  38 A0 00 00 */	li r5, 0
/* 800F2AEC  6F C0 80 00 */	xoris r0, r30, 0x8000
/* 800F2AF0  7D 28 FE 70 */	srawi r8, r9, 0x1f
/* 800F2AF4  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2AF8  7D 23 FE 70 */	srawi r3, r9, 0x1f
/* 800F2AFC  7C FF 48 14 */	addc r7, r31, r9
/* 800F2B00  7C DE 19 14 */	adde r6, r30, r3
/* 800F2B04  90 E1 00 0C */	stw r7, 0xc(r1)
/* 800F2B08  7C 65 F8 10 */	subfc r3, r5, r31
/* 800F2B0C  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2B10  90 C1 00 08 */	stw r6, 8(r1)
/* 800F2B14  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2B18  7C 84 00 D1 */	neg. r4, r4
/* 800F2B1C  40 82 00 3C */	bne 0x3c
/* 800F2B20  6D 00 80 00 */	xoris r0, r8, 0x8000
/* 800F2B24  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2B28  7C 65 48 10 */	subfc r3, r5, r9
/* 800F2B2C  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2B30  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2B34  7C 84 00 D1 */	neg. r4, r4
/* 800F2B38  40 82 00 20 */	bne 0x20
/* 800F2B3C  6C C0 80 00 */	xoris r0, r6, 0x8000
/* 800F2B40  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2B44  7C 65 38 10 */	subfc r3, r5, r7
/* 800F2B48  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2B4C  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2B50  7C 84 00 D1 */	neg. r4, r4
/* 800F2B54  40 82 00 64 */	bne 0x64
/* 800F2B58  38 A0 00 00 */	li r5, 0
/* 800F2B5C  6F C0 80 00 */	xoris r0, r30, 0x8000
/* 800F2B60  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2B64  7C 65 F8 10 */	subfc r3, r5, r31
/* 800F2B68  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2B6C  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2B70  7C 84 00 D1 */	neg. r4, r4
/* 800F2B74  41 82 00 50 */	beq 0x50
/* 800F2B78  6D 00 80 00 */	xoris r0, r8, 0x8000
/* 800F2B7C  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2B80  7C 65 48 10 */	subfc r3, r5, r9
/* 800F2B84  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2B88  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2B8C  7C 84 00 D1 */	neg. r4, r4
/* 800F2B90  41 82 00 34 */	beq 0x34
/* 800F2B94  80 01 00 08 */	lwz r0, 8(r1)
/* 800F2B98  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2B9C  80 61 00 0C */	lwz r3, 0xc(r1)
/* 800F2BA0  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 800F2BA4  7C 65 18 10 */	subfc r3, r5, r3
/* 800F2BA8  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2BAC  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2BB0  7C 84 00 D1 */	neg. r4, r4
/* 800F2BB4  40 82 00 10 */	bne 0x10
/* 800F2BB8  38 80 FF FF */	li r4, -1
/* 800F2BBC  38 60 FF FF */	li r3, -1
/* 800F2BC0  48 00 02 E8 */	b 0x2e8
/* 800F2BC4  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 800F2BC8  38 80 00 3C */	li r4, 0x3c
/* 800F2BCC  80 A1 00 08 */	lwz r5, 8(r1)
/* 800F2BD0  7C 66 20 16 */	mulhwu r3, r6, r4
/* 800F2BD4  7C C0 2B 79 */	or. r0, r6, r5
/* 800F2BD8  7C 05 21 D6 */	mullw r0, r5, r4
/* 800F2BDC  1F E6 00 3C */	mulli r31, r6, 0x3c
/* 800F2BE0  7F C3 02 14 */	add r30, r3, r0
/* 800F2BE4  41 82 00 24 */	beq 0x24
/* 800F2BE8  7F C3 F3 78 */	mr r3, r30
/* 800F2BEC  7F E4 FB 78 */	mr r4, r31
/* 800F2BF0  4B F2 EB 01 */	bl -0xd1500
/* 800F2BF4  68 84 00 3C */	xori r4, r4, 0x3c
/* 800F2BF8  7C 80 1B 78 */	or r0, r4, r3
/* 800F2BFC  30 80 FF FF */	addic r4, r0, -1
/* 800F2C00  7C 04 01 10 */	subfe r0, r4, r0
/* 800F2C04  48 00 00 08 */	b 0x8
/* 800F2C08  38 00 00 00 */	li r0, 0
/* 800F2C0C  2C 00 00 00 */	cmpwi r0, 0
/* 800F2C10  41 82 00 10 */	beq 0x10
/* 800F2C14  38 80 FF FF */	li r4, -1
/* 800F2C18  38 60 FF FF */	li r3, -1
/* 800F2C1C  48 00 02 8C */	b 0x28c
/* 800F2C20  81 3D 00 04 */	lwz r9, 4(r29)
/* 800F2C24  38 A0 00 00 */	li r5, 0
/* 800F2C28  6F C0 80 00 */	xoris r0, r30, 0x8000
/* 800F2C2C  7D 28 FE 70 */	srawi r8, r9, 0x1f
/* 800F2C30  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2C34  7D 23 FE 70 */	srawi r3, r9, 0x1f
/* 800F2C38  7C FF 48 14 */	addc r7, r31, r9
/* 800F2C3C  7C DE 19 14 */	adde r6, r30, r3
/* 800F2C40  90 E1 00 0C */	stw r7, 0xc(r1)
/* 800F2C44  7C 65 F8 10 */	subfc r3, r5, r31
/* 800F2C48  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2C4C  90 C1 00 08 */	stw r6, 8(r1)
/* 800F2C50  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2C54  7C 84 00 D1 */	neg. r4, r4
/* 800F2C58  40 82 00 3C */	bne 0x3c
/* 800F2C5C  6D 00 80 00 */	xoris r0, r8, 0x8000
/* 800F2C60  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2C64  7C 65 48 10 */	subfc r3, r5, r9
/* 800F2C68  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2C6C  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2C70  7C 84 00 D1 */	neg. r4, r4
/* 800F2C74  40 82 00 20 */	bne 0x20
/* 800F2C78  6C C0 80 00 */	xoris r0, r6, 0x8000
/* 800F2C7C  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2C80  7C 65 38 10 */	subfc r3, r5, r7
/* 800F2C84  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2C88  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2C8C  7C 84 00 D1 */	neg. r4, r4
/* 800F2C90  40 82 00 64 */	bne 0x64
/* 800F2C94  38 A0 00 00 */	li r5, 0
/* 800F2C98  6F C0 80 00 */	xoris r0, r30, 0x8000
/* 800F2C9C  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2CA0  7C 65 F8 10 */	subfc r3, r5, r31
/* 800F2CA4  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2CA8  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2CAC  7C 84 00 D1 */	neg. r4, r4
/* 800F2CB0  41 82 00 50 */	beq 0x50
/* 800F2CB4  6D 00 80 00 */	xoris r0, r8, 0x8000
/* 800F2CB8  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2CBC  7C 65 48 10 */	subfc r3, r5, r9
/* 800F2CC0  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2CC4  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2CC8  7C 84 00 D1 */	neg. r4, r4
/* 800F2CCC  41 82 00 34 */	beq 0x34
/* 800F2CD0  80 01 00 08 */	lwz r0, 8(r1)
/* 800F2CD4  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2CD8  80 61 00 0C */	lwz r3, 0xc(r1)
/* 800F2CDC  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 800F2CE0  7C 65 18 10 */	subfc r3, r5, r3
/* 800F2CE4  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2CE8  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2CEC  7C 84 00 D1 */	neg. r4, r4
/* 800F2CF0  40 82 00 10 */	bne 0x10
/* 800F2CF4  38 80 FF FF */	li r4, -1
/* 800F2CF8  38 60 FF FF */	li r3, -1
/* 800F2CFC  48 00 01 AC */	b 0x1ac
/* 800F2D00  80 C1 00 0C */	lwz r6, 0xc(r1)
/* 800F2D04  38 80 00 3C */	li r4, 0x3c
/* 800F2D08  80 A1 00 08 */	lwz r5, 8(r1)
/* 800F2D0C  7C 66 20 16 */	mulhwu r3, r6, r4
/* 800F2D10  7C C0 2B 79 */	or. r0, r6, r5
/* 800F2D14  7C 05 21 D6 */	mullw r0, r5, r4
/* 800F2D18  1F C6 00 3C */	mulli r30, r6, 0x3c
/* 800F2D1C  7F E3 02 14 */	add r31, r3, r0
/* 800F2D20  41 82 00 24 */	beq 0x24
/* 800F2D24  7F E3 FB 78 */	mr r3, r31
/* 800F2D28  7F C4 F3 78 */	mr r4, r30
/* 800F2D2C  4B F2 E9 C5 */	bl -0xd163c
/* 800F2D30  68 84 00 3C */	xori r4, r4, 0x3c
/* 800F2D34  7C 80 1B 78 */	or r0, r4, r3
/* 800F2D38  30 80 FF FF */	addic r4, r0, -1
/* 800F2D3C  7C 04 01 10 */	subfe r0, r4, r0
/* 800F2D40  48 00 00 08 */	b 0x8
/* 800F2D44  38 00 00 00 */	li r0, 0
/* 800F2D48  2C 00 00 00 */	cmpwi r0, 0
/* 800F2D4C  41 82 00 10 */	beq 0x10
/* 800F2D50  38 80 FF FF */	li r4, -1
/* 800F2D54  38 60 FF FF */	li r3, -1
/* 800F2D58  48 00 01 50 */	b 0x150
/* 800F2D5C  81 3D 00 00 */	lwz r9, 0(r29)
/* 800F2D60  38 A0 00 00 */	li r5, 0
/* 800F2D64  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800F2D68  7D 28 FE 70 */	srawi r8, r9, 0x1f
/* 800F2D6C  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2D70  7D 23 FE 70 */	srawi r3, r9, 0x1f
/* 800F2D74  7C FE 48 14 */	addc r7, r30, r9
/* 800F2D78  7C DF 19 14 */	adde r6, r31, r3
/* 800F2D7C  90 E1 00 0C */	stw r7, 0xc(r1)
/* 800F2D80  7C 65 F0 10 */	subfc r3, r5, r30
/* 800F2D84  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2D88  90 C1 00 08 */	stw r6, 8(r1)
/* 800F2D8C  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2D90  7C 84 00 D1 */	neg. r4, r4
/* 800F2D94  40 82 00 3C */	bne 0x3c
/* 800F2D98  6D 00 80 00 */	xoris r0, r8, 0x8000
/* 800F2D9C  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2DA0  7C 65 48 10 */	subfc r3, r5, r9
/* 800F2DA4  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2DA8  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2DAC  7C 84 00 D1 */	neg. r4, r4
/* 800F2DB0  40 82 00 20 */	bne 0x20
/* 800F2DB4  6C C0 80 00 */	xoris r0, r6, 0x8000
/* 800F2DB8  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2DBC  7C 65 38 10 */	subfc r3, r5, r7
/* 800F2DC0  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2DC4  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2DC8  7C 84 00 D1 */	neg. r4, r4
/* 800F2DCC  40 82 00 64 */	bne 0x64
/* 800F2DD0  38 A0 00 00 */	li r5, 0
/* 800F2DD4  6F E0 80 00 */	xoris r0, r31, 0x8000
/* 800F2DD8  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2DDC  7C 65 F0 10 */	subfc r3, r5, r30
/* 800F2DE0  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2DE4  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2DE8  7C 84 00 D1 */	neg. r4, r4
/* 800F2DEC  41 82 00 50 */	beq 0x50
/* 800F2DF0  6D 00 80 00 */	xoris r0, r8, 0x8000
/* 800F2DF4  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2DF8  7C 65 48 10 */	subfc r3, r5, r9
/* 800F2DFC  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2E00  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2E04  7C 84 00 D1 */	neg. r4, r4
/* 800F2E08  41 82 00 34 */	beq 0x34
/* 800F2E0C  80 01 00 08 */	lwz r0, 8(r1)
/* 800F2E10  6C A4 80 00 */	xoris r4, r5, 0x8000
/* 800F2E14  80 61 00 0C */	lwz r3, 0xc(r1)
/* 800F2E18  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 800F2E1C  7C 65 18 10 */	subfc r3, r5, r3
/* 800F2E20  7C 84 01 10 */	subfe r4, r4, r0
/* 800F2E24  7C 80 01 10 */	subfe r4, r0, r0
/* 800F2E28  7C 84 00 D1 */	neg. r4, r4
/* 800F2E2C  40 82 00 10 */	bne 0x10
/* 800F2E30  38 80 FF FF */	li r4, -1
/* 800F2E34  38 60 FF FF */	li r3, -1
/* 800F2E38  48 00 00 70 */	b 0x70
/* 800F2E3C  38 61 00 08 */	addi r3, r1, 8
/* 800F2E40  4B FF F7 0D */	bl -0x8f4
/* 800F2E44  2C 03 00 00 */	cmpwi r3, 0
/* 800F2E48  40 82 00 10 */	bne 0x10
/* 800F2E4C  38 80 FF FF */	li r4, -1
/* 800F2E50  38 60 FF FF */	li r3, -1
/* 800F2E54  48 00 00 54 */	b 0x54
/* 800F2E58  80 83 00 00 */	lwz r4, 0(r3)
/* 800F2E5C  80 03 00 04 */	lwz r0, 4(r3)
/* 800F2E60  90 9D 00 00 */	stw r4, 0(r29)
/* 800F2E64  90 1D 00 04 */	stw r0, 4(r29)
/* 800F2E68  80 83 00 08 */	lwz r4, 8(r3)
/* 800F2E6C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F2E70  90 9D 00 08 */	stw r4, 8(r29)
/* 800F2E74  90 1D 00 0C */	stw r0, 0xc(r29)
/* 800F2E78  80 83 00 10 */	lwz r4, 0x10(r3)
/* 800F2E7C  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F2E80  90 9D 00 10 */	stw r4, 0x10(r29)
/* 800F2E84  90 1D 00 14 */	stw r0, 0x14(r29)
/* 800F2E88  80 83 00 18 */	lwz r4, 0x18(r3)
/* 800F2E8C  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 800F2E90  90 9D 00 18 */	stw r4, 0x18(r29)
/* 800F2E94  90 1D 00 1C */	stw r0, 0x1c(r29)
/* 800F2E98  80 03 00 20 */	lwz r0, 0x20(r3)
/* 800F2E9C  90 1D 00 20 */	stw r0, 0x20(r29)
/* 800F2EA0  80 61 00 08 */	lwz r3, 8(r1)
/* 800F2EA4  80 81 00 0C */	lwz r4, 0xc(r1)
/* 800F2EA8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F2EAC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F2EB0  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F2EB4  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F2EB8  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F2EBC  7C 08 03 A6 */	mtlr r0
/* 800F2EC0  38 21 00 20 */	addi r1, r1, 0x20
/* 800F2EC4  4E 80 00 20 */	blr
/* 800F2EC8  2C 03 00 00 */	cmpwi r3, 0
/* 800F2ECC  38 00 00 01 */	li r0, 1
/* 800F2ED0  41 82 00 08 */	beq 0x8
/* 800F2ED4  54 60 00 7E */	clrlwi r0, r3, 1
/* 800F2ED8  90 0D 84 90 */	stw r0, -0x7b70(r13)
/* 800F2EDC  4E 80 00 20 */	blr
/* 800F2EE0  7C E3 20 51 */	subf. r7, r3, r4
/* 800F2EE4  4D 82 00 20 */	beqlr
/* 800F2EE8  80 AD 84 90 */	lwz r5, -0x7b70(r13)
/* 800F2EEC  3C 80 80 00 */	lis r4, 0x8000
/* 800F2EF0  38 04 FF FF */	addi r0, r4, -1
/* 800F2EF4  54 A4 84 3E */	srwi r4, r5, 0x10
/* 800F2EF8  54 A5 04 3E */	clrlwi r5, r5, 0x10
/* 800F2EFC  1C C4 41 A7 */	mulli r6, r4, 0x41a7
/* 800F2F00  1C A5 41 A7 */	mulli r5, r5, 0x41a7
/* 800F2F04  54 C4 80 5E */	rlwinm r4, r6, 0x10, 1, 0xf
/* 800F2F08  7C A5 22 14 */	add r5, r5, r4
/* 800F2F0C  7C 05 00 40 */	cmplw r5, r0
/* 800F2F10  40 81 00 0C */	ble 0xc
/* 800F2F14  54 A5 00 7E */	clrlwi r5, r5, 1
/* 800F2F18  38 A5 00 01 */	addi r5, r5, 1
/* 800F2F1C  54 C0 8B FE */	srwi r0, r6, 0xf
/* 800F2F20  3C 80 80 00 */	lis r4, 0x8000
/* 800F2F24  7C A5 02 14 */	add r5, r5, r0
/* 800F2F28  38 04 FF FF */	addi r0, r4, -1
/* 800F2F2C  7C 05 00 40 */	cmplw r5, r0
/* 800F2F30  40 81 00 0C */	ble 0xc
/* 800F2F34  54 A5 00 7E */	clrlwi r5, r5, 1
/* 800F2F38  38 A5 00 01 */	addi r5, r5, 1
/* 800F2F3C  7C 05 3B 96 */	divwu r0, r5, r7
/* 800F2F40  90 AD 84 90 */	stw r5, -0x7b70(r13)
/* 800F2F44  7C 00 39 D6 */	mullw r0, r0, r7
/* 800F2F48  7C 00 28 50 */	subf r0, r0, r5
/* 800F2F4C  7C 60 1A 14 */	add r3, r0, r3
/* 800F2F50  4E 80 00 20 */	blr
/* 800F2F54  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F2F58  7C 08 02 A6 */	mflr r0
/* 800F2F5C  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F2F60  39 61 00 30 */	addi r11, r1, 0x30
/* 800F2F64  4B F2 E6 3D */	bl -0xd19c4
/* 800F2F68  2C 07 00 02 */	cmpwi r7, 2
/* 800F2F6C  7C 9C 23 78 */	mr r28, r4
/* 800F2F70  7C DD 33 78 */	mr r29, r6
/* 800F2F74  39 60 00 00 */	li r11, 0
/* 800F2F78  3B C0 00 00 */	li r30, 0
/* 800F2F7C  41 82 00 1C */	beq 0x1c
/* 800F2F80  40 80 00 20 */	bge 0x20
/* 800F2F84  2C 07 00 01 */	cmpwi r7, 1
/* 800F2F88  40 80 00 08 */	bge 0x8
/* 800F2F8C  48 00 00 14 */	b 0x14
/* 800F2F90  39 42 94 C4 */	addi r10, r2, -27452
/* 800F2F94  48 00 00 10 */	b 0x10
/* 800F2F98  39 42 94 C8 */	addi r10, r2, -27448
/* 800F2F9C  48 00 00 08 */	b 0x8
/* 800F2FA0  39 42 94 C0 */	addi r10, r2, -27456
/* 800F2FA4  2C 05 00 00 */	cmpwi r5, 0
/* 800F2FA8  41 81 00 20 */	bgt 0x20
/* 800F2FAC  2C 06 00 00 */	cmpwi r6, 0
/* 800F2FB0  41 82 00 0C */	beq 0xc
/* 800F2FB4  38 00 00 00 */	li r0, 0
/* 800F2FB8  90 06 00 00 */	stw r0, 0(r6)
/* 800F2FBC  38 00 00 00 */	li r0, 0
/* 800F2FC0  98 04 00 00 */	stb r0, 0(r4)
/* 800F2FC4  48 00 02 9C */	b 0x29c
/* 800F2FC8  7C 6C 1B 78 */	mr r12, r3
/* 800F2FCC  38 E1 00 08 */	addi r7, r1, 8
/* 800F2FD0  38 00 00 3F */	li r0, 0x3f
/* 800F2FD4  39 00 00 3E */	li r8, 0x3e
/* 800F2FD8  48 00 01 A0 */	b 0x1a0
/* 800F2FDC  7D 3B 07 74 */	extsb r27, r9
/* 800F2FE0  2C 1B 00 30 */	cmpwi r27, 0x30
/* 800F2FE4  41 80 00 2C */	blt 0x2c
/* 800F2FE8  2C 1B 00 39 */	cmpwi r27, 0x39
/* 800F2FEC  41 81 00 24 */	bgt 0x24
/* 800F2FF0  55 7B F0 02 */	slwi r27, r11, 0x1e
/* 800F2FF4  55 7F 0F FE */	srwi r31, r11, 0x1f
/* 800F2FF8  7F 7F D8 50 */	subf r27, r31, r27
/* 800F2FFC  39 29 00 04 */	addi r9, r9, 4
/* 800F3000  57 7B 10 3E */	rotlwi r27, r27, 2
/* 800F3004  7F 7B FA 14 */	add r27, r27, r31
/* 800F3008  7D 27 D9 AE */	stbx r9, r7, r27
/* 800F300C  48 00 01 04 */	b 0x104
/* 800F3010  7D 3B 07 74 */	extsb r27, r9
/* 800F3014  2C 1B 00 61 */	cmpwi r27, 0x61
/* 800F3018  41 80 00 2C */	blt 0x2c
/* 800F301C  2C 1B 00 7A */	cmpwi r27, 0x7a
/* 800F3020  41 81 00 24 */	bgt 0x24
/* 800F3024  55 7B F0 02 */	slwi r27, r11, 0x1e
/* 800F3028  55 7F 0F FE */	srwi r31, r11, 0x1f
/* 800F302C  7F 7F D8 50 */	subf r27, r31, r27
/* 800F3030  39 29 FF B9 */	addi r9, r9, -71
/* 800F3034  57 7B 10 3E */	rotlwi r27, r27, 2
/* 800F3038  7F 7B FA 14 */	add r27, r27, r31
/* 800F303C  7D 27 D9 AE */	stbx r9, r7, r27
/* 800F3040  48 00 00 D0 */	b 0xd0
/* 800F3044  7D 3B 07 74 */	extsb r27, r9
/* 800F3048  2C 1B 00 41 */	cmpwi r27, 0x41
/* 800F304C  41 80 00 2C */	blt 0x2c
/* 800F3050  2C 1B 00 5A */	cmpwi r27, 0x5a
/* 800F3054  41 81 00 24 */	bgt 0x24
/* 800F3058  55 7B F0 02 */	slwi r27, r11, 0x1e
/* 800F305C  55 7F 0F FE */	srwi r31, r11, 0x1f
/* 800F3060  7F 7F D8 50 */	subf r27, r31, r27
/* 800F3064  39 29 FF BF */	addi r9, r9, -65
/* 800F3068  57 7B 10 3E */	rotlwi r27, r27, 2
/* 800F306C  7F 7B FA 14 */	add r27, r27, r31
/* 800F3070  7D 27 D9 AE */	stbx r9, r7, r27
/* 800F3074  48 00 00 9C */	b 0x9c
/* 800F3078  8B EA 00 00 */	lbz r31, 0(r10)
/* 800F307C  7D 3B 07 74 */	extsb r27, r9
/* 800F3080  7F E9 07 74 */	extsb r9, r31
/* 800F3084  7C 09 D8 00 */	cmpw r9, r27
/* 800F3088  40 82 00 20 */	bne 0x20
/* 800F308C  55 69 F0 02 */	slwi r9, r11, 0x1e
/* 800F3090  55 7B 0F FE */	srwi r27, r11, 0x1f
/* 800F3094  7D 3B 48 50 */	subf r9, r27, r9
/* 800F3098  55 29 10 3E */	rotlwi r9, r9, 2
/* 800F309C  7F 69 DA 14 */	add r27, r9, r27
/* 800F30A0  7D 07 D9 AE */	stbx r8, r7, r27
/* 800F30A4  48 00 00 6C */	b 0x6c
/* 800F30A8  89 2A 00 01 */	lbz r9, 1(r10)
/* 800F30AC  7D 29 07 74 */	extsb r9, r9
/* 800F30B0  7C 09 D8 00 */	cmpw r9, r27
/* 800F30B4  40 82 00 20 */	bne 0x20
/* 800F30B8  55 69 F0 02 */	slwi r9, r11, 0x1e
/* 800F30BC  55 7B 0F FE */	srwi r27, r11, 0x1f
/* 800F30C0  7D 3B 48 50 */	subf r9, r27, r9
/* 800F30C4  55 29 10 3E */	rotlwi r9, r9, 2
/* 800F30C8  7F 69 DA 14 */	add r27, r9, r27
/* 800F30CC  7C 07 D9 AE */	stbx r0, r7, r27
/* 800F30D0  48 00 00 40 */	b 0x40
/* 800F30D4  7C 03 58 AE */	lbzx r0, r3, r11
/* 800F30D8  88 6A 00 02 */	lbz r3, 2(r10)
/* 800F30DC  7C 00 07 74 */	extsb r0, r0
/* 800F30E0  7C 63 07 74 */	extsb r3, r3
/* 800F30E4  7C 03 00 00 */	cmpw r3, r0
/* 800F30E8  41 82 00 B0 */	beq 0xb0
/* 800F30EC  2C 00 00 00 */	cmpwi r0, 0
/* 800F30F0  41 82 00 A8 */	beq 0xa8
/* 800F30F4  2C 06 00 00 */	cmpwi r6, 0
/* 800F30F8  41 82 00 0C */	beq 0xc
/* 800F30FC  38 00 00 00 */	li r0, 0
/* 800F3100  90 06 00 00 */	stw r0, 0(r6)
/* 800F3104  38 00 00 00 */	li r0, 0
/* 800F3108  98 04 00 00 */	stb r0, 0(r4)
/* 800F310C  48 00 01 54 */	b 0x154
/* 800F3110  2C 1B 00 03 */	cmpwi r27, 3
/* 800F3114  40 82 00 5C */	bne 0x5c
/* 800F3118  8B E1 00 08 */	lbz r31, 8(r1)
/* 800F311C  7D 24 F2 14 */	add r9, r4, r30
/* 800F3120  8B 61 00 09 */	lbz r27, 9(r1)
/* 800F3124  7F FF 07 74 */	extsb r31, r31
/* 800F3128  7F 7B 07 74 */	extsb r27, r27
/* 800F312C  57 FF 10 3A */	slwi r31, r31, 2
/* 800F3130  7F 7B 26 70 */	srawi r27, r27, 4
/* 800F3134  7F FB DB 78 */	or r27, r31, r27
/* 800F3138  7F 64 F1 AE */	stbx r27, r4, r30
/* 800F313C  3B DE 00 03 */	addi r30, r30, 3
/* 800F3140  8B 61 00 0A */	lbz r27, 0xa(r1)
/* 800F3144  8B E1 00 09 */	lbz r31, 9(r1)
/* 800F3148  7F 7B 07 74 */	extsb r27, r27
/* 800F314C  57 FF 26 36 */	rlwinm r31, r31, 4, 0x18, 0x1b
/* 800F3150  7F 7B 16 70 */	srawi r27, r27, 2
/* 800F3154  7F FB DB 78 */	or r27, r31, r27
/* 800F3158  9B 69 00 01 */	stb r27, 1(r9)
/* 800F315C  8B E1 00 0A */	lbz r31, 0xa(r1)
/* 800F3160  8B 61 00 0B */	lbz r27, 0xb(r1)
/* 800F3164  57 FF 36 32 */	rlwinm r31, r31, 6, 0x18, 0x19
/* 800F3168  7F FB DB 78 */	or r27, r31, r27
/* 800F316C  9B 69 00 02 */	stb r27, 2(r9)
/* 800F3170  39 6B 00 01 */	addi r11, r11, 1
/* 800F3174  39 8C 00 01 */	addi r12, r12, 1
/* 800F3178  7C 0B 28 00 */	cmpw r11, r5
/* 800F317C  40 80 00 1C */	bge 0x1c
/* 800F3180  89 2C 00 00 */	lbz r9, 0(r12)
/* 800F3184  8B 6A 00 02 */	lbz r27, 2(r10)
/* 800F3188  7D 3F 07 74 */	extsb r31, r9
/* 800F318C  7F 7B 07 74 */	extsb r27, r27
/* 800F3190  7C 1B F8 00 */	cmpw r27, r31
/* 800F3194  40 82 FE 48 */	bne -0x1b8
/* 800F3198  2C 0B 00 00 */	cmpwi r11, 0
/* 800F319C  41 82 00 B8 */	beq 0xb8
/* 800F31A0  55 60 F0 02 */	slwi r0, r11, 0x1e
/* 800F31A4  55 63 0F FE */	srwi r3, r11, 0x1f
/* 800F31A8  7C 03 00 50 */	subf r0, r3, r0
/* 800F31AC  54 00 10 3E */	rotlwi r0, r0, 2
/* 800F31B0  7F E0 1A 15 */	add. r31, r0, r3
/* 800F31B4  41 82 00 A0 */	beq 0xa0
/* 800F31B8  88 8A 00 02 */	lbz r4, 2(r10)
/* 800F31BC  38 61 00 08 */	addi r3, r1, 8
/* 800F31C0  7C 63 FA 14 */	add r3, r3, r31
/* 800F31C4  20 BF 00 04 */	subfic r5, r31, 4
/* 800F31C8  7C 84 07 74 */	extsb r4, r4
/* 800F31CC  4B F1 2E 6D */	bl -0xed194
/* 800F31D0  2C 1F 00 02 */	cmpwi r31, 2
/* 800F31D4  41 80 00 24 */	blt 0x24
/* 800F31D8  88 61 00 08 */	lbz r3, 8(r1)
/* 800F31DC  88 01 00 09 */	lbz r0, 9(r1)
/* 800F31E0  7C 63 07 74 */	extsb r3, r3
/* 800F31E4  7C 00 07 74 */	extsb r0, r0
/* 800F31E8  54 63 10 3A */	slwi r3, r3, 2
/* 800F31EC  7C 00 26 70 */	srawi r0, r0, 4
/* 800F31F0  7C 60 03 78 */	or r0, r3, r0
/* 800F31F4  7C 1C F1 AE */	stbx r0, r28, r30
/* 800F31F8  2C 1F 00 03 */	cmpwi r31, 3
/* 800F31FC  41 80 00 24 */	blt 0x24
/* 800F3200  88 01 00 0A */	lbz r0, 0xa(r1)
/* 800F3204  7C 7C F2 14 */	add r3, r28, r30
/* 800F3208  88 81 00 09 */	lbz r4, 9(r1)
/* 800F320C  7C 00 07 74 */	extsb r0, r0
/* 800F3210  54 84 26 36 */	rlwinm r4, r4, 4, 0x18, 0x1b
/* 800F3214  7C 00 16 70 */	srawi r0, r0, 2
/* 800F3218  7C 80 03 78 */	or r0, r4, r0
/* 800F321C  98 03 00 01 */	stb r0, 1(r3)
/* 800F3220  2C 1F 00 04 */	cmpwi r31, 4
/* 800F3224  41 80 00 1C */	blt 0x1c
/* 800F3228  88 81 00 0A */	lbz r4, 0xa(r1)
/* 800F322C  7C 7C F2 14 */	add r3, r28, r30
/* 800F3230  88 01 00 0B */	lbz r0, 0xb(r1)
/* 800F3234  54 84 36 32 */	rlwinm r4, r4, 6, 0x18, 0x19
/* 800F3238  7C 80 03 78 */	or r0, r4, r0
/* 800F323C  98 03 00 02 */	stb r0, 2(r3)
/* 800F3240  2C 1F 00 03 */	cmpwi r31, 3
/* 800F3244  38 1E 00 01 */	addi r0, r30, 1
/* 800F3248  40 82 00 08 */	bne 0x8
/* 800F324C  38 1E 00 02 */	addi r0, r30, 2
/* 800F3250  7C 1E 03 78 */	mr r30, r0
/* 800F3254  2C 1D 00 00 */	cmpwi r29, 0
/* 800F3258  41 82 00 08 */	beq 0x8
/* 800F325C  93 DD 00 00 */	stw r30, 0(r29)
/* 800F3260  39 61 00 30 */	addi r11, r1, 0x30
/* 800F3264  4B F2 E3 89 */	bl -0xd1c78
/* 800F3268  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F326C  7C 08 03 A6 */	mtlr r0
/* 800F3270  38 21 00 30 */	addi r1, r1, 0x30
/* 800F3274  4E 80 00 20 */	blr
/* 800F3278  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F327C  2C 06 00 02 */	cmpwi r6, 2
/* 800F3280  7C 80 23 78 */	mr r0, r4
/* 800F3284  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F3288  7C BF 2B 78 */	mr r31, r5
/* 800F328C  41 82 00 1C */	beq 0x1c
/* 800F3290  40 80 00 20 */	bge 0x20
/* 800F3294  2C 06 00 01 */	cmpwi r6, 1
/* 800F3298  40 80 00 08 */	bge 0x8
/* 800F329C  48 00 00 14 */	b 0x14
/* 800F32A0  38 C2 94 C4 */	addi r6, r2, -27452
/* 800F32A4  48 00 00 10 */	b 0x10
/* 800F32A8  38 C2 94 C8 */	addi r6, r2, -27448
/* 800F32AC  48 00 00 08 */	b 0x8
/* 800F32B0  38 C2 94 C0 */	addi r6, r2, -27456
/* 800F32B4  39 80 00 00 */	li r12, 0
/* 800F32B8  48 00 00 E0 */	b 0xe0
/* 800F32BC  7C 67 1B 78 */	mr r7, r3
/* 800F32C0  39 41 00 08 */	addi r10, r1, 8
/* 800F32C4  39 20 00 00 */	li r9, 0
/* 800F32C8  48 00 00 18 */	b 0x18
/* 800F32CC  89 07 00 00 */	lbz r8, 0(r7)
/* 800F32D0  39 29 00 01 */	addi r9, r9, 1
/* 800F32D4  38 E7 00 01 */	addi r7, r7, 1
/* 800F32D8  99 0A 00 00 */	stb r8, 0(r10)
/* 800F32DC  39 4A 00 01 */	addi r10, r10, 1
/* 800F32E0  2C 1F 00 03 */	cmpwi r31, 3
/* 800F32E4  39 00 00 03 */	li r8, 3
/* 800F32E8  40 80 00 08 */	bge 0x8
/* 800F32EC  7F E8 FB 78 */	mr r8, r31
/* 800F32F0  7C 09 40 00 */	cmpw r9, r8
/* 800F32F4  41 80 FF D8 */	blt -0x28
/* 800F32F8  2C 09 00 03 */	cmpwi r9, 3
/* 800F32FC  39 41 00 08 */	addi r10, r1, 8
/* 800F3300  7D 4A 4A 14 */	add r10, r10, r9
/* 800F3304  21 09 00 03 */	subfic r8, r9, 3
/* 800F3308  40 80 00 50 */	bge 0x50
/* 800F330C  55 07 E8 FF */	rlwinm. r7, r8, 0x1d, 3, 0x1f
/* 800F3310  7C E9 03 A6 */	mtctr r7
/* 800F3314  41 82 00 34 */	beq 0x34
/* 800F3318  99 8A 00 00 */	stb r12, 0(r10)
/* 800F331C  99 8A 00 01 */	stb r12, 1(r10)
/* 800F3320  99 8A 00 02 */	stb r12, 2(r10)
/* 800F3324  99 8A 00 03 */	stb r12, 3(r10)
/* 800F3328  99 8A 00 04 */	stb r12, 4(r10)
/* 800F332C  99 8A 00 05 */	stb r12, 5(r10)
/* 800F3330  99 8A 00 06 */	stb r12, 6(r10)
/* 800F3334  99 8A 00 07 */	stb r12, 7(r10)
/* 800F3338  39 4A 00 08 */	addi r10, r10, 8
/* 800F333C  42 00 FF DC */	bdnz -0x24
/* 800F3340  71 08 00 07 */	andi. r8, r8, 7
/* 800F3344  41 82 00 14 */	beq 0x14
/* 800F3348  7D 09 03 A6 */	mtctr r8
/* 800F334C  99 8A 00 00 */	stb r12, 0(r10)
/* 800F3350  39 4A 00 01 */	addi r10, r10, 1
/* 800F3354  42 00 FF F8 */	bdnz -0x8
/* 800F3358  89 61 00 08 */	lbz r11, 8(r1)
/* 800F335C  38 63 00 03 */	addi r3, r3, 3
/* 800F3360  89 41 00 09 */	lbz r10, 9(r1)
/* 800F3364  3B FF FF FD */	addi r31, r31, -3
/* 800F3368  7D 67 16 70 */	srawi r7, r11, 2
/* 800F336C  89 01 00 0A */	lbz r8, 0xa(r1)
/* 800F3370  98 E4 00 00 */	stb r7, 0(r4)
/* 800F3374  7D 49 26 70 */	srawi r9, r10, 4
/* 800F3378  51 69 26 B6 */	rlwimi r9, r11, 4, 0x1a, 0x1b
/* 800F337C  55 07 06 BE */	clrlwi r7, r8, 0x1a
/* 800F3380  99 24 00 01 */	stb r9, 1(r4)
/* 800F3384  7D 08 36 70 */	srawi r8, r8, 6
/* 800F3388  51 48 16 BA */	rlwimi r8, r10, 2, 0x1a, 0x1d
/* 800F338C  99 04 00 02 */	stb r8, 2(r4)
/* 800F3390  98 E4 00 03 */	stb r7, 3(r4)
/* 800F3394  38 84 00 04 */	addi r4, r4, 4
/* 800F3398  2C 1F 00 00 */	cmpwi r31, 0
/* 800F339C  41 81 FF 20 */	bgt -0xe0
/* 800F33A0  3C 60 55 55 */	lis r3, 0x5555
/* 800F33A4  7C 88 23 78 */	mr r8, r4
/* 800F33A8  38 63 55 56 */	addi r3, r3, 0x5556
/* 800F33AC  7C E3 28 96 */	mulhw r7, r3, r5
/* 800F33B0  54 E3 0F FE */	srwi r3, r7, 0x1f
/* 800F33B4  7C 67 1A 14 */	add r3, r7, r3
/* 800F33B8  1C 63 00 03 */	mulli r3, r3, 3
/* 800F33BC  7C 63 28 50 */	subf r3, r3, r5
/* 800F33C0  2C 03 00 01 */	cmpwi r3, 1
/* 800F33C4  40 82 00 0C */	bne 0xc
/* 800F33C8  39 04 FF FE */	addi r8, r4, -2
/* 800F33CC  48 00 00 10 */	b 0x10
/* 800F33D0  2C 03 00 02 */	cmpwi r3, 2
/* 800F33D4  40 82 00 08 */	bne 0x8
/* 800F33D8  39 04 FF FF */	addi r8, r4, -1
/* 800F33DC  38 A0 00 00 */	li r5, 0
/* 800F33E0  7C 60 20 50 */	subf r3, r0, r4
/* 800F33E4  98 A4 00 00 */	stb r5, 0(r4)
/* 800F33E8  7C 69 03 A6 */	mtctr r3
/* 800F33EC  7C 04 00 40 */	cmplw r4, r0
/* 800F33F0  40 81 00 88 */	ble 0x88
/* 800F33F4  38 84 FF FF */	addi r4, r4, -1
/* 800F33F8  7C 04 40 40 */	cmplw r4, r8
/* 800F33FC  41 80 00 10 */	blt 0x10
/* 800F3400  88 06 00 02 */	lbz r0, 2(r6)
/* 800F3404  98 04 00 00 */	stb r0, 0(r4)
/* 800F3408  48 00 00 6C */	b 0x6c
/* 800F340C  88 64 00 00 */	lbz r3, 0(r4)
/* 800F3410  7C 60 07 74 */	extsb r0, r3
/* 800F3414  2C 00 00 19 */	cmpwi r0, 0x19
/* 800F3418  41 81 00 10 */	bgt 0x10
/* 800F341C  38 03 00 41 */	addi r0, r3, 0x41
/* 800F3420  98 04 00 00 */	stb r0, 0(r4)
/* 800F3424  48 00 00 50 */	b 0x50
/* 800F3428  2C 00 00 33 */	cmpwi r0, 0x33
/* 800F342C  41 81 00 10 */	bgt 0x10
/* 800F3430  38 03 00 47 */	addi r0, r3, 0x47
/* 800F3434  98 04 00 00 */	stb r0, 0(r4)
/* 800F3438  48 00 00 3C */	b 0x3c
/* 800F343C  2C 00 00 3D */	cmpwi r0, 0x3d
/* 800F3440  41 81 00 10 */	bgt 0x10
/* 800F3444  38 03 FF FC */	addi r0, r3, -4
/* 800F3448  98 04 00 00 */	stb r0, 0(r4)
/* 800F344C  48 00 00 28 */	b 0x28
/* 800F3450  2C 00 00 3E */	cmpwi r0, 0x3e
/* 800F3454  40 82 00 10 */	bne 0x10
/* 800F3458  88 06 00 00 */	lbz r0, 0(r6)
/* 800F345C  98 04 00 00 */	stb r0, 0(r4)
/* 800F3460  48 00 00 14 */	b 0x14
/* 800F3464  2C 00 00 3F */	cmpwi r0, 0x3f
/* 800F3468  40 82 00 0C */	bne 0xc
/* 800F346C  88 06 00 01 */	lbz r0, 1(r6)
/* 800F3470  98 04 00 00 */	stb r0, 0(r4)
/* 800F3474  42 00 FF 80 */	bdnz -0x80
/* 800F3478  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F347C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F3480  4E 80 00 20 */	blr
/* 800F3484  2C 04 00 02 */	cmpwi r4, 2
/* 800F3488  7C 66 1B 78 */	mr r6, r3
/* 800F348C  41 82 00 1C */	beq 0x1c
/* 800F3490  40 80 00 20 */	bge 0x20
/* 800F3494  2C 04 00 01 */	cmpwi r4, 1
/* 800F3498  40 80 00 08 */	bge 0x8
/* 800F349C  48 00 00 14 */	b 0x14
/* 800F34A0  38 A2 94 C4 */	addi r5, r2, -27452
/* 800F34A4  48 00 00 60 */	b 0x60
/* 800F34A8  38 A2 94 C8 */	addi r5, r2, -27448
/* 800F34AC  48 00 00 58 */	b 0x58
/* 800F34B0  38 A2 94 C0 */	addi r5, r2, -27456
/* 800F34B4  48 00 00 50 */	b 0x50
/* 800F34B8  88 05 00 02 */	lbz r0, 2(r5)
/* 800F34BC  7C 84 07 74 */	extsb r4, r4
/* 800F34C0  7C 00 07 74 */	extsb r0, r0
/* 800F34C4  7C 04 00 00 */	cmpw r4, r0
/* 800F34C8  40 82 00 38 */	bne 0x38
/* 800F34CC  7C 66 18 50 */	subf r3, r6, r3
/* 800F34D0  38 83 FF FF */	addi r4, r3, -1
/* 800F34D4  7C 60 16 70 */	srawi r0, r3, 2
/* 800F34D8  7C 60 01 94 */	addze r3, r0
/* 800F34DC  54 85 0F FE */	srwi r5, r4, 0x1f
/* 800F34E0  54 80 F0 02 */	slwi r0, r4, 0x1e
/* 800F34E4  7C 85 00 50 */	subf r4, r5, r0
/* 800F34E8  54 60 10 3A */	slwi r0, r3, 2
/* 800F34EC  54 84 10 3E */	rotlwi r4, r4, 2
/* 800F34F0  7C 84 2A 14 */	add r4, r4, r5
/* 800F34F4  7C 03 00 50 */	subf r0, r3, r0
/* 800F34F8  7C 64 02 14 */	add r3, r4, r0
/* 800F34FC  4E 80 00 20 */	blr
/* 800F3500  38 63 00 01 */	addi r3, r3, 1
/* 800F3504  88 83 00 00 */	lbz r4, 0(r3)
/* 800F3508  7C 80 07 75 */	extsb. r0, r4
/* 800F350C  40 82 FF AC */	bne -0x54
/* 800F3510  7C 06 18 50 */	subf r0, r6, r3
/* 800F3514  7C 00 16 70 */	srawi r0, r0, 2
/* 800F3518  7C 60 01 94 */	addze r3, r0
/* 800F351C  54 60 10 3A */	slwi r0, r3, 2
/* 800F3520  7C 63 00 50 */	subf r3, r3, r0
/* 800F3524  4E 80 00 20 */	blr
/* 800F3528  90 83 00 00 */	stw r4, 0(r3)
/* 800F352C  90 A3 00 04 */	stw r5, 4(r3)
/* 800F3530  90 C3 00 08 */	stw r6, 8(r3)
/* 800F3534  4E 80 00 20 */	blr
/* 800F3538  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F353C  80 C3 00 04 */	lwz r6, 4(r3)
/* 800F3540  2C 06 00 00 */	cmpwi r6, 0
/* 800F3544  41 81 00 0C */	bgt 0xc
/* 800F3548  38 60 00 00 */	li r3, 0
/* 800F354C  48 00 02 F0 */	b 0x2f0
/* 800F3550  80 03 00 08 */	lwz r0, 8(r3)
/* 800F3554  2C 00 00 02 */	cmpwi r0, 2
/* 800F3558  41 82 00 1C */	beq 0x1c
/* 800F355C  40 80 00 20 */	bge 0x20
/* 800F3560  2C 00 00 01 */	cmpwi r0, 1
/* 800F3564  40 80 00 08 */	bge 0x8
/* 800F3568  48 00 00 14 */	b 0x14
/* 800F356C  38 A2 94 C4 */	addi r5, r2, -27452
/* 800F3570  48 00 00 10 */	b 0x10
/* 800F3574  38 A2 94 C8 */	addi r5, r2, -27448
/* 800F3578  48 00 00 08 */	b 0x8
/* 800F357C  38 A2 94 C0 */	addi r5, r2, -27456
/* 800F3580  2C 06 00 03 */	cmpwi r6, 3
/* 800F3584  38 E0 00 03 */	li r7, 3
/* 800F3588  40 80 00 08 */	bge 0x8
/* 800F358C  7C C7 33 78 */	mr r7, r6
/* 800F3590  2C 87 00 00 */	cmpwi cr1, r7, 0
/* 800F3594  81 03 00 00 */	lwz r8, 0(r3)
/* 800F3598  39 20 00 00 */	li r9, 0
/* 800F359C  40 85 00 D0 */	ble cr1, 0xd0
/* 800F35A0  2C 07 00 08 */	cmpwi r7, 8
/* 800F35A4  39 47 FF F8 */	addi r10, r7, -8
/* 800F35A8  40 81 00 90 */	ble 0x90
/* 800F35AC  39 60 00 00 */	li r11, 0
/* 800F35B0  41 84 00 18 */	blt cr1, 0x18
/* 800F35B4  3C C0 80 00 */	lis r6, 0x8000
/* 800F35B8  38 06 FF FE */	addi r0, r6, -2
/* 800F35BC  7C 07 00 00 */	cmpw r7, r0
/* 800F35C0  41 81 00 08 */	bgt 0x8
/* 800F35C4  39 60 00 01 */	li r11, 1
/* 800F35C8  2C 0B 00 00 */	cmpwi r11, 0
/* 800F35CC  41 82 00 6C */	beq 0x6c
/* 800F35D0  38 0A 00 07 */	addi r0, r10, 7
/* 800F35D4  38 C1 00 08 */	addi r6, r1, 8
/* 800F35D8  54 00 E8 FE */	srwi r0, r0, 3
/* 800F35DC  7C 09 03 A6 */	mtctr r0
/* 800F35E0  2C 0A 00 00 */	cmpwi r10, 0
/* 800F35E4  40 81 00 54 */	ble 0x54
/* 800F35E8  7C 08 48 AE */	lbzx r0, r8, r9
/* 800F35EC  7D 48 4A 14 */	add r10, r8, r9
/* 800F35F0  39 29 00 08 */	addi r9, r9, 8
/* 800F35F4  98 06 00 00 */	stb r0, 0(r6)
/* 800F35F8  88 0A 00 01 */	lbz r0, 1(r10)
/* 800F35FC  98 06 00 01 */	stb r0, 1(r6)
/* 800F3600  88 0A 00 02 */	lbz r0, 2(r10)
/* 800F3604  98 06 00 02 */	stb r0, 2(r6)
/* 800F3608  88 0A 00 03 */	lbz r0, 3(r10)
/* 800F360C  98 06 00 03 */	stb r0, 3(r6)
/* 800F3610  88 0A 00 04 */	lbz r0, 4(r10)
/* 800F3614  98 06 00 04 */	stb r0, 4(r6)
/* 800F3618  88 0A 00 05 */	lbz r0, 5(r10)
/* 800F361C  98 06 00 05 */	stb r0, 5(r6)
/* 800F3620  88 0A 00 06 */	lbz r0, 6(r10)
/* 800F3624  98 06 00 06 */	stb r0, 6(r6)
/* 800F3628  88 0A 00 07 */	lbz r0, 7(r10)
/* 800F362C  98 06 00 07 */	stb r0, 7(r6)
/* 800F3630  38 C6 00 08 */	addi r6, r6, 8
/* 800F3634  42 00 FF B4 */	bdnz -0x4c
/* 800F3638  39 41 00 08 */	addi r10, r1, 8
/* 800F363C  7C 09 38 50 */	subf r0, r9, r7
/* 800F3640  7D 4A 4A 14 */	add r10, r10, r9
/* 800F3644  7C C8 4A 14 */	add r6, r8, r9
/* 800F3648  7C 09 03 A6 */	mtctr r0
/* 800F364C  7C 09 38 00 */	cmpw r9, r7
/* 800F3650  40 80 00 1C */	bge 0x1c
/* 800F3654  88 06 00 00 */	lbz r0, 0(r6)
/* 800F3658  39 29 00 01 */	addi r9, r9, 1
/* 800F365C  38 C6 00 01 */	addi r6, r6, 1
/* 800F3660  98 0A 00 00 */	stb r0, 0(r10)
/* 800F3664  39 4A 00 01 */	addi r10, r10, 1
/* 800F3668  42 00 FF EC */	bdnz -0x14
/* 800F366C  2C 09 00 03 */	cmpwi r9, 3
/* 800F3670  39 01 00 08 */	addi r8, r1, 8
/* 800F3674  7D 08 4A 14 */	add r8, r8, r9
/* 800F3678  20 C9 00 03 */	subfic r6, r9, 3
/* 800F367C  38 E0 00 00 */	li r7, 0
/* 800F3680  40 80 00 50 */	bge 0x50
/* 800F3684  54 C0 E8 FF */	rlwinm. r0, r6, 0x1d, 3, 0x1f
/* 800F3688  7C 09 03 A6 */	mtctr r0
/* 800F368C  41 82 00 34 */	beq 0x34
/* 800F3690  98 E8 00 00 */	stb r7, 0(r8)
/* 800F3694  98 E8 00 01 */	stb r7, 1(r8)
/* 800F3698  98 E8 00 02 */	stb r7, 2(r8)
/* 800F369C  98 E8 00 03 */	stb r7, 3(r8)
/* 800F36A0  98 E8 00 04 */	stb r7, 4(r8)
/* 800F36A4  98 E8 00 05 */	stb r7, 5(r8)
/* 800F36A8  98 E8 00 06 */	stb r7, 6(r8)
/* 800F36AC  98 E8 00 07 */	stb r7, 7(r8)
/* 800F36B0  39 08 00 08 */	addi r8, r8, 8
/* 800F36B4  42 00 FF DC */	bdnz -0x24
/* 800F36B8  70 C6 00 07 */	andi. r6, r6, 7
/* 800F36BC  41 82 00 14 */	beq 0x14
/* 800F36C0  7C C9 03 A6 */	mtctr r6
/* 800F36C4  98 E8 00 00 */	stb r7, 0(r8)
/* 800F36C8  39 08 00 01 */	addi r8, r8, 1
/* 800F36CC  42 00 FF F8 */	bdnz -0x8
/* 800F36D0  88 C1 00 08 */	lbz r6, 8(r1)
/* 800F36D4  38 00 00 02 */	li r0, 2
/* 800F36D8  39 00 00 00 */	li r8, 0
/* 800F36DC  7C C6 16 70 */	srawi r6, r6, 2
/* 800F36E0  98 C4 00 00 */	stb r6, 0(r4)
/* 800F36E4  88 C1 00 09 */	lbz r6, 9(r1)
/* 800F36E8  88 E1 00 08 */	lbz r7, 8(r1)
/* 800F36EC  7C C6 26 70 */	srawi r6, r6, 4
/* 800F36F0  50 E6 26 B6 */	rlwimi r6, r7, 4, 0x1a, 0x1b
/* 800F36F4  98 C4 00 01 */	stb r6, 1(r4)
/* 800F36F8  88 C1 00 0A */	lbz r6, 0xa(r1)
/* 800F36FC  88 E1 00 09 */	lbz r7, 9(r1)
/* 800F3700  7C C6 36 70 */	srawi r6, r6, 6
/* 800F3704  50 E6 16 BA */	rlwimi r6, r7, 2, 0x1a, 0x1d
/* 800F3708  98 C4 00 02 */	stb r6, 2(r4)
/* 800F370C  88 C1 00 0A */	lbz r6, 0xa(r1)
/* 800F3710  54 C6 06 BE */	clrlwi r6, r6, 0x1a
/* 800F3714  98 C4 00 03 */	stb r6, 3(r4)
/* 800F3718  80 E3 00 00 */	lwz r7, 0(r3)
/* 800F371C  80 C3 00 04 */	lwz r6, 4(r3)
/* 800F3720  38 E7 00 03 */	addi r7, r7, 3
/* 800F3724  38 C6 FF FD */	addi r6, r6, -3
/* 800F3728  90 E3 00 00 */	stw r7, 0(r3)
/* 800F372C  90 C3 00 04 */	stw r6, 4(r3)
/* 800F3730  7C 09 03 A6 */	mtctr r0
/* 800F3734  7C C4 40 AE */	lbzx r6, r4, r8
/* 800F3738  7C C0 07 74 */	extsb r0, r6
/* 800F373C  2C 00 00 19 */	cmpwi r0, 0x19
/* 800F3740  41 81 00 10 */	bgt 0x10
/* 800F3744  38 06 00 41 */	addi r0, r6, 0x41
/* 800F3748  7C 04 41 AE */	stbx r0, r4, r8
/* 800F374C  48 00 00 50 */	b 0x50
/* 800F3750  2C 00 00 33 */	cmpwi r0, 0x33
/* 800F3754  41 81 00 10 */	bgt 0x10
/* 800F3758  38 06 00 47 */	addi r0, r6, 0x47
/* 800F375C  7C 04 41 AE */	stbx r0, r4, r8
/* 800F3760  48 00 00 3C */	b 0x3c
/* 800F3764  2C 00 00 3D */	cmpwi r0, 0x3d
/* 800F3768  41 81 00 10 */	bgt 0x10
/* 800F376C  38 06 FF FC */	addi r0, r6, -4
/* 800F3770  7C 04 41 AE */	stbx r0, r4, r8
/* 800F3774  48 00 00 28 */	b 0x28
/* 800F3778  2C 00 00 3E */	cmpwi r0, 0x3e
/* 800F377C  40 82 00 10 */	bne 0x10
/* 800F3780  88 05 00 00 */	lbz r0, 0(r5)
/* 800F3784  7C 04 41 AE */	stbx r0, r4, r8
/* 800F3788  48 00 00 14 */	b 0x14
/* 800F378C  2C 00 00 3F */	cmpwi r0, 0x3f
/* 800F3790  40 82 00 0C */	bne 0xc
/* 800F3794  88 05 00 01 */	lbz r0, 1(r5)
/* 800F3798  7C 04 41 AE */	stbx r0, r4, r8
/* 800F379C  39 08 00 01 */	addi r8, r8, 1
/* 800F37A0  7C C4 40 AE */	lbzx r6, r4, r8
/* 800F37A4  7C C0 07 74 */	extsb r0, r6
/* 800F37A8  2C 00 00 19 */	cmpwi r0, 0x19
/* 800F37AC  41 81 00 10 */	bgt 0x10
/* 800F37B0  38 06 00 41 */	addi r0, r6, 0x41
/* 800F37B4  7C 04 41 AE */	stbx r0, r4, r8
/* 800F37B8  48 00 00 50 */	b 0x50
/* 800F37BC  2C 00 00 33 */	cmpwi r0, 0x33
/* 800F37C0  41 81 00 10 */	bgt 0x10
/* 800F37C4  38 06 00 47 */	addi r0, r6, 0x47
/* 800F37C8  7C 04 41 AE */	stbx r0, r4, r8
/* 800F37CC  48 00 00 3C */	b 0x3c
/* 800F37D0  2C 00 00 3D */	cmpwi r0, 0x3d
/* 800F37D4  41 81 00 10 */	bgt 0x10
/* 800F37D8  38 06 FF FC */	addi r0, r6, -4
/* 800F37DC  7C 04 41 AE */	stbx r0, r4, r8
/* 800F37E0  48 00 00 28 */	b 0x28
/* 800F37E4  2C 00 00 3E */	cmpwi r0, 0x3e
/* 800F37E8  40 82 00 10 */	bne 0x10
/* 800F37EC  88 05 00 00 */	lbz r0, 0(r5)
/* 800F37F0  7C 04 41 AE */	stbx r0, r4, r8
/* 800F37F4  48 00 00 14 */	b 0x14
/* 800F37F8  2C 00 00 3F */	cmpwi r0, 0x3f
/* 800F37FC  40 82 00 0C */	bne 0xc
/* 800F3800  88 05 00 01 */	lbz r0, 1(r5)
/* 800F3804  7C 04 41 AE */	stbx r0, r4, r8
/* 800F3808  39 08 00 01 */	addi r8, r8, 1
/* 800F380C  42 00 FF 28 */	bdnz -0xd8
/* 800F3810  80 03 00 04 */	lwz r0, 4(r3)
/* 800F3814  2C 00 00 00 */	cmpwi r0, 0
/* 800F3818  40 80 00 20 */	bge 0x20
/* 800F381C  88 05 00 02 */	lbz r0, 2(r5)
/* 800F3820  98 04 00 03 */	stb r0, 3(r4)
/* 800F3824  80 03 00 04 */	lwz r0, 4(r3)
/* 800F3828  2C 00 FF FE */	cmpwi r0, -2
/* 800F382C  40 82 00 0C */	bne 0xc
/* 800F3830  88 05 00 02 */	lbz r0, 2(r5)
/* 800F3834  98 04 00 02 */	stb r0, 2(r4)
/* 800F3838  38 60 00 01 */	li r3, 1
/* 800F383C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F3840  4E 80 00 20 */	blr
/* 800F3844  3D 00 80 2F */	lis r8, 0x802f
/* 800F3848  38 E8 21 68 */	addi r7, r8, 0x2168
/* 800F384C  90 68 21 68 */	stw r3, 0x2168(r8)
/* 800F3850  90 87 00 04 */	stw r4, 4(r7)
/* 800F3854  90 A7 00 08 */	stw r5, 8(r7)
/* 800F3858  90 C7 00 0C */	stw r6, 0xc(r7)
/* 800F385C  4E 80 00 20 */	blr
/* 800F3860  3C 80 80 2F */	lis r4, 0x802f
/* 800F3864  81 84 21 68 */	lwz r12, 0x2168(r4)
/* 800F3868  7D 89 03 A6 */	mtctr r12
/* 800F386C  4E 80 04 20 */	bctr
/* 800F3870  3C A0 80 2F */	lis r5, 0x802f
/* 800F3874  38 A5 21 68 */	addi r5, r5, 0x2168
/* 800F3878  81 85 00 08 */	lwz r12, 8(r5)
/* 800F387C  7D 89 03 A6 */	mtctr r12
/* 800F3880  4E 80 04 20 */	bctr
/* 800F3884  2C 03 00 00 */	cmpwi r3, 0
/* 800F3888  4D 82 00 20 */	beqlr
/* 800F388C  3C 80 80 2F */	lis r4, 0x802f
/* 800F3890  38 84 21 68 */	addi r4, r4, 0x2168
/* 800F3894  81 84 00 04 */	lwz r12, 4(r4)
/* 800F3898  7D 89 03 A6 */	mtctr r12
/* 800F389C  4E 80 04 20 */	bctr
/* 800F38A0  4E 80 00 20 */	blr
