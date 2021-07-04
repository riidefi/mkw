
.include "macros.inc"

.section .text, "ax" # 0x800F2048 - 0x800F5A6C
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
/* 800F38A4  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800F38A8  7C 08 02 A6 */	mflr r0
/* 800F38AC  90 01 00 64 */	stw r0, 0x64(r1)
/* 800F38B0  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 800F38B4  93 C1 00 58 */	stw r30, 0x58(r1)
/* 800F38B8  93 A1 00 54 */	stw r29, 0x54(r1)
/* 800F38BC  3F A0 80 2F */	lis r29, 0x802f
/* 800F38C0  3B BD 23 38 */	addi r29, r29, 0x2338
/* 800F38C4  93 81 00 50 */	stw r28, 0x50(r1)
/* 800F38C8  7C 7C 1B 78 */	mr r28, r3
/* 800F38CC  7F 84 E3 78 */	mr r4, r28
/* 800F38D0  38 7D 00 00 */	addi r3, r29, 0
/* 800F38D4  4B F1 F8 4D */	bl -0xe07b4
/* 800F38D8  38 00 FF FF */	li r0, -1
/* 800F38DC  90 1D 00 80 */	stw r0, 0x80(r29)
/* 800F38E0  4B FF EB E1 */	bl -0x1420
/* 800F38E4  8B FD 00 40 */	lbz r31, 0x40(r29)
/* 800F38E8  7F FF 07 75 */	extsb. r31, r31
/* 800F38EC  40 82 00 1C */	bne 0x1c
/* 800F38F0  3C 80 80 28 */	lis r4, 0x8028
/* 800F38F4  7F 85 E3 78 */	mr r5, r28
/* 800F38F8  38 61 00 08 */	addi r3, r1, 8
/* 800F38FC  38 84 AD 58 */	addi r4, r4, -21160
/* 800F3900  4C C6 31 82 */	crclr 6
/* 800F3904  4B F1 E1 29 */	bl -0xe1ed8
/* 800F3908  3B DD 00 80 */	addi r30, r29, 0x80
/* 800F390C  38 00 00 02 */	li r0, 2
/* 800F3910  98 1E 00 05 */	stb r0, 5(r30)
/* 800F3914  38 60 6C FC */	li r3, 0x6cfc
/* 800F3918  48 0F A0 85 */	bl 0xfa084
/* 800F391C  2C 1F 00 00 */	cmpwi r31, 0
/* 800F3920  B0 7E 00 06 */	sth r3, 6(r30)
/* 800F3924  38 61 00 08 */	addi r3, r1, 8
/* 800F3928  41 82 00 08 */	beq 0x8
/* 800F392C  38 7D 00 40 */	addi r3, r29, 0x40
/* 800F3930  4B FF DB B5 */	bl -0x244c
/* 800F3934  3C 03 00 01 */	addis r0, r3, 1
/* 800F3938  38 9D 00 80 */	addi r4, r29, 0x80
/* 800F393C  28 00 FF FF */	cmplwi r0, 0xffff
/* 800F3940  90 64 00 08 */	stw r3, 8(r4)
/* 800F3944  40 82 00 3C */	bne 0x3c
/* 800F3948  2C 1F 00 00 */	cmpwi r31, 0
/* 800F394C  38 61 00 08 */	addi r3, r1, 8
/* 800F3950  41 82 00 08 */	beq 0x8
/* 800F3954  38 7D 00 40 */	addi r3, r29, 0x40
/* 800F3958  4B FF DC F5 */	bl -0x230c
/* 800F395C  2C 03 00 00 */	cmpwi r3, 0
/* 800F3960  40 82 00 0C */	bne 0xc
/* 800F3964  38 00 00 00 */	li r0, 0
/* 800F3968  48 00 00 1C */	b 0x1c
/* 800F396C  80 83 00 0C */	lwz r4, 0xc(r3)
/* 800F3970  38 7D 00 80 */	addi r3, r29, 0x80
/* 800F3974  80 84 00 00 */	lwz r4, 0(r4)
/* 800F3978  80 04 00 00 */	lwz r0, 0(r4)
/* 800F397C  90 03 00 08 */	stw r0, 8(r3)
/* 800F3980  38 00 00 01 */	li r0, 1
/* 800F3984  2C 00 00 00 */	cmpwi r0, 0
/* 800F3988  41 82 00 78 */	beq 0x78
/* 800F398C  38 60 00 02 */	li r3, 2
/* 800F3990  38 80 00 02 */	li r4, 2
/* 800F3994  38 A0 00 11 */	li r5, 0x11
/* 800F3998  4B FF D7 F5 */	bl -0x280c
/* 800F399C  2C 03 FF FF */	cmpwi r3, -1
/* 800F39A0  90 7D 00 80 */	stw r3, 0x80(r29)
/* 800F39A4  41 82 00 5C */	beq 0x5c
/* 800F39A8  3B DD 00 80 */	addi r30, r29, 0x80
/* 800F39AC  38 00 00 09 */	li r0, 9
/* 800F39B0  98 1E 00 0C */	stb r0, 0xc(r30)
/* 800F39B4  7F 83 E3 78 */	mr r3, r28
/* 800F39B8  4B F2 D8 9D */	bl -0xd2764
/* 800F39BC  7C 7F 1B 78 */	mr r31, r3
/* 800F39C0  7F 84 E3 78 */	mr r4, r28
/* 800F39C4  38 7E 00 11 */	addi r3, r30, 0x11
/* 800F39C8  38 BF 00 01 */	addi r5, r31, 1
/* 800F39CC  4B F1 25 69 */	bl -0xeda98
/* 800F39D0  38 BF 00 06 */	addi r5, r31, 6
/* 800F39D4  80 7D 00 80 */	lwz r3, 0x80(r29)
/* 800F39D8  90 BE 00 4C */	stw r5, 0x4c(r30)
/* 800F39DC  38 9E 00 0C */	addi r4, r30, 0xc
/* 800F39E0  38 FE 00 04 */	addi r7, r30, 4
/* 800F39E4  38 C0 00 00 */	li r6, 0
/* 800F39E8  39 00 00 08 */	li r8, 8
/* 800F39EC  4B FF D9 E9 */	bl -0x2618
/* 800F39F0  4B FF EA D9 */	bl -0x1528
/* 800F39F4  38 00 00 00 */	li r0, 0
/* 800F39F8  90 7E 00 50 */	stw r3, 0x50(r30)
/* 800F39FC  90 1E 00 54 */	stw r0, 0x54(r30)
/* 800F3A00  80 01 00 64 */	lwz r0, 0x64(r1)
/* 800F3A04  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 800F3A08  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 800F3A0C  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 800F3A10  83 81 00 50 */	lwz r28, 0x50(r1)
/* 800F3A14  7C 08 03 A6 */	mtlr r0
/* 800F3A18  38 21 00 60 */	addi r1, r1, 0x60
/* 800F3A1C  4E 80 00 20 */	blr 
/* 800F3A20  54 2B 06 FE */	clrlwi r11, r1, 0x1b
/* 800F3A24  7C 2C 0B 78 */	mr r12, r1
/* 800F3A28  21 6B FF 60 */	subfic r11, r11, -160
/* 800F3A2C  7C 21 59 6E */	stwux r1, r1, r11
/* 800F3A30  7C 08 02 A6 */	mflr r0
/* 800F3A34  90 0C 00 04 */	stw r0, 4(r12)
/* 800F3A38  38 00 00 08 */	li r0, 8
/* 800F3A3C  93 EC FF FC */	stw r31, -4(r12)
/* 800F3A40  3F E0 80 2F */	lis r31, 0x802f
/* 800F3A44  80 7F 23 B8 */	lwz r3, 0x23b8(r31)
/* 800F3A48  90 01 00 20 */	stw r0, 0x20(r1)
/* 800F3A4C  2C 03 FF FF */	cmpwi r3, -1
/* 800F3A50  40 82 00 14 */	bne 0x14
/* 800F3A54  38 00 00 01 */	li r0, 1
/* 800F3A58  38 60 00 01 */	li r3, 1
/* 800F3A5C  90 0D 97 58 */	stw r0, -0x68a8(r13)
/* 800F3A60  48 00 01 80 */	b 0x180
/* 800F3A64  4B FF E2 39 */	bl -0x1dc8
/* 800F3A68  2C 03 00 00 */	cmpwi r3, 0
/* 800F3A6C  41 82 01 00 */	beq 0x100
/* 800F3A70  80 7F 23 B8 */	lwz r3, 0x23b8(r31)
/* 800F3A74  38 81 00 40 */	addi r4, r1, 0x40
/* 800F3A78  38 E1 00 28 */	addi r7, r1, 0x28
/* 800F3A7C  39 01 00 20 */	addi r8, r1, 0x20
/* 800F3A80  38 A0 00 40 */	li r5, 0x40
/* 800F3A84  38 C0 00 00 */	li r6, 0
/* 800F3A88  4B FF D8 B9 */	bl -0x2748
/* 800F3A8C  2C 03 00 07 */	cmpwi r3, 7
/* 800F3A90  40 80 00 0C */	bge 0xc
/* 800F3A94  38 A0 00 01 */	li r5, 1
/* 800F3A98  48 00 00 88 */	b 0x88
/* 800F3A9C  3B FF 23 B8 */	addi r31, r31, 0x23b8
/* 800F3AA0  38 61 00 2C */	addi r3, r1, 0x2c
/* 800F3AA4  38 9F 00 08 */	addi r4, r31, 8
/* 800F3AA8  38 A0 00 04 */	li r5, 4
/* 800F3AAC  4B F1 B8 69 */	bl -0xe4798
/* 800F3AB0  2C 03 00 00 */	cmpwi r3, 0
/* 800F3AB4  41 82 00 0C */	beq 0xc
/* 800F3AB8  38 A0 00 01 */	li r5, 1
/* 800F3ABC  48 00 00 64 */	b 0x64
/* 800F3AC0  A0 61 00 2A */	lhz r3, 0x2a(r1)
/* 800F3AC4  A0 1F 00 06 */	lhz r0, 6(r31)
/* 800F3AC8  7C 03 00 40 */	cmplw r3, r0
/* 800F3ACC  41 82 00 0C */	beq 0xc
/* 800F3AD0  38 A0 00 01 */	li r5, 1
/* 800F3AD4  48 00 00 4C */	b 0x4c
/* 800F3AD8  38 61 00 40 */	addi r3, r1, 0x40
/* 800F3ADC  38 8D 84 98 */	addi r4, r13, -31592
/* 800F3AE0  38 A0 00 03 */	li r5, 3
/* 800F3AE4  4B F1 B8 31 */	bl -0xe47d0
/* 800F3AE8  2C 03 00 00 */	cmpwi r3, 0
/* 800F3AEC  41 82 00 0C */	beq 0xc
/* 800F3AF0  38 A0 00 01 */	li r5, 1
/* 800F3AF4  48 00 00 2C */	b 0x2c
/* 800F3AF8  88 01 00 44 */	lbz r0, 0x44(r1)
/* 800F3AFC  38 A0 00 00 */	li r5, 0
/* 800F3B00  88 61 00 45 */	lbz r3, 0x45(r1)
/* 800F3B04  54 06 82 1E */	rlwinm r6, r0, 0x10, 8, 0xf
/* 800F3B08  88 81 00 43 */	lbz r4, 0x43(r1)
/* 800F3B0C  88 01 00 46 */	lbz r0, 0x46(r1)
/* 800F3B10  54 63 44 2E */	rlwinm r3, r3, 8, 0x10, 0x17
/* 800F3B14  50 86 C0 0E */	rlwimi r6, r4, 0x18, 0, 7
/* 800F3B18  7C C6 1B 78 */	or r6, r6, r3
/* 800F3B1C  7C DF 03 78 */	or r31, r6, r0
/* 800F3B20  2C 05 00 00 */	cmpwi r5, 0
/* 800F3B24  40 82 00 48 */	bne 0x48
/* 800F3B28  3C 60 80 2F */	lis r3, 0x802f
/* 800F3B2C  80 63 23 B8 */	lwz r3, 0x23b8(r3)
/* 800F3B30  4B FF D6 95 */	bl -0x296c
/* 800F3B34  57 E0 07 FF */	clrlwi. r0, r31, 0x1f
/* 800F3B38  41 82 00 10 */	beq 0x10
/* 800F3B3C  38 00 00 02 */	li r0, 2
/* 800F3B40  90 0D 97 58 */	stw r0, -0x68a8(r13)
/* 800F3B44  48 00 00 20 */	b 0x20
/* 800F3B48  57 E0 07 BD */	rlwinm. r0, r31, 0, 0x1e, 0x1e
/* 800F3B4C  41 82 00 10 */	beq 0x10
/* 800F3B50  38 00 00 03 */	li r0, 3
/* 800F3B54  90 0D 97 58 */	stw r0, -0x68a8(r13)
/* 800F3B58  48 00 00 0C */	b 0xc
/* 800F3B5C  38 00 00 01 */	li r0, 1
/* 800F3B60  90 0D 97 58 */	stw r0, -0x68a8(r13)
/* 800F3B64  7C 03 03 78 */	mr r3, r0
/* 800F3B68  48 00 00 78 */	b 0x78
/* 800F3B6C  4B FF E9 5D */	bl -0x16a4
/* 800F3B70  3C A0 80 2F */	lis r5, 0x802f
/* 800F3B74  3B E5 23 B8 */	addi r31, r5, 0x23b8
/* 800F3B78  80 9F 00 50 */	lwz r4, 0x50(r31)
/* 800F3B7C  38 04 07 D0 */	addi r0, r4, 0x7d0
/* 800F3B80  7C 03 00 40 */	cmplw r3, r0
/* 800F3B84  40 81 00 58 */	ble 0x58
/* 800F3B88  80 1F 00 54 */	lwz r0, 0x54(r31)
/* 800F3B8C  2C 00 00 01 */	cmpwi r0, 1
/* 800F3B90  40 82 00 1C */	bne 0x1c
/* 800F3B94  80 65 23 B8 */	lwz r3, 0x23b8(r5)
/* 800F3B98  4B FF D6 2D */	bl -0x29d4
/* 800F3B9C  38 00 00 01 */	li r0, 1
/* 800F3BA0  38 60 00 01 */	li r3, 1
/* 800F3BA4  90 0D 97 58 */	stw r0, -0x68a8(r13)
/* 800F3BA8  48 00 00 38 */	b 0x38
/* 800F3BAC  80 65 23 B8 */	lwz r3, 0x23b8(r5)
/* 800F3BB0  38 9F 00 0C */	addi r4, r31, 0xc
/* 800F3BB4  80 BF 00 4C */	lwz r5, 0x4c(r31)
/* 800F3BB8  38 FF 00 04 */	addi r7, r31, 4
/* 800F3BBC  38 C0 00 00 */	li r6, 0
/* 800F3BC0  39 00 00 08 */	li r8, 8
/* 800F3BC4  4B FF D8 11 */	bl -0x27f0
/* 800F3BC8  4B FF E9 01 */	bl -0x1700
/* 800F3BCC  80 9F 00 54 */	lwz r4, 0x54(r31)
/* 800F3BD0  90 7F 00 50 */	stw r3, 0x50(r31)
/* 800F3BD4  38 04 00 01 */	addi r0, r4, 1
/* 800F3BD8  90 1F 00 54 */	stw r0, 0x54(r31)
/* 800F3BDC  38 60 00 00 */	li r3, 0
/* 800F3BE0  81 41 00 00 */	lwz r10, 0(r1)
/* 800F3BE4  80 0A 00 04 */	lwz r0, 4(r10)
/* 800F3BE8  83 EA FF FC */	lwz r31, -4(r10)
/* 800F3BEC  7C 08 03 A6 */	mtlr r0
/* 800F3BF0  7D 41 53 78 */	mr r1, r10
/* 800F3BF4  4E 80 00 20 */	blr 
/* 800F3BF8  3C 60 80 2F */	lis r3, 0x802f
/* 800F3BFC  38 63 24 10 */	addi r3, r3, 0x2410
/* 800F3C00  38 63 00 10 */	addi r3, r3, 0x10
/* 800F3C04  4B FF E3 F0 */	b -0x1c10
/* 800F3C08  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F3C0C  7C 08 02 A6 */	mflr r0
/* 800F3C10  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F3C14  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F3C18  3F E0 80 2F */	lis r31, 0x802f
/* 800F3C1C  3B FF 24 10 */	addi r31, r31, 0x2410
/* 800F3C20  48 00 00 0C */	b 0xc
/* 800F3C24  38 60 00 64 */	li r3, 0x64
/* 800F3C28  4B FF E8 E9 */	bl -0x1718
/* 800F3C2C  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F3C30  2C 00 00 00 */	cmpwi r0, 0
/* 800F3C34  40 82 FF F0 */	bne -0x10
/* 800F3C38  7F E3 FB 78 */	mr r3, r31
/* 800F3C3C  4B FF E3 1D */	bl -0x1ce4
/* 800F3C40  28 03 00 01 */	cmplwi r3, 1
/* 800F3C44  40 82 00 84 */	bne 0x84
/* 800F3C48  80 1F 00 04 */	lwz r0, 4(r31)
/* 800F3C4C  2C 00 00 00 */	cmpwi r0, 0
/* 800F3C50  40 82 00 20 */	bne 0x20
/* 800F3C54  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F3C58  4B FF E3 91 */	bl -0x1c70
/* 800F3C5C  3C 60 80 0F */	lis r3, 0x800f
/* 800F3C60  38 63 3B F8 */	addi r3, r3, 0x3bf8
/* 800F3C64  4B F1 87 CD */	bl -0xe7834
/* 800F3C68  38 00 00 01 */	li r0, 1
/* 800F3C6C  90 1F 00 04 */	stw r0, 4(r31)
/* 800F3C70  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F3C74  4B FF E3 79 */	bl -0x1c88
/* 800F3C78  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F3C7C  4B FF E3 75 */	bl -0x1c8c
/* 800F3C80  48 00 00 0C */	b 0xc
/* 800F3C84  38 60 00 64 */	li r3, 0x64
/* 800F3C88  4B FF E8 89 */	bl -0x1778
/* 800F3C8C  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F3C90  2C 00 00 00 */	cmpwi r0, 0
/* 800F3C94  40 82 FF F0 */	bne -0x10
/* 800F3C98  38 60 00 04 */	li r3, 4
/* 800F3C9C  38 80 00 0A */	li r4, 0xa
/* 800F3CA0  38 A0 00 00 */	li r5, 0
/* 800F3CA4  4B FF B6 D5 */	bl -0x492c
/* 800F3CA8  90 7F 00 28 */	stw r3, 0x28(r31)
/* 800F3CAC  48 01 F6 DD */	bl 0x1f6dc
/* 800F3CB0  38 00 00 01 */	li r0, 1
/* 800F3CB4  90 1F 00 08 */	stw r0, 8(r31)
/* 800F3CB8  48 00 00 44 */	b 0x44
/* 800F3CBC  48 00 00 0C */	b 0xc
/* 800F3CC0  38 60 00 64 */	li r3, 0x64
/* 800F3CC4  4B FF E8 4D */	bl -0x17b4
/* 800F3CC8  80 1F 00 04 */	lwz r0, 4(r31)
/* 800F3CCC  2C 00 00 00 */	cmpwi r0, 0
/* 800F3CD0  41 82 FF F0 */	beq -0x10
/* 800F3CD4  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F3CD8  4B FF E3 15 */	bl -0x1cec
/* 800F3CDC  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F3CE0  4B FF E3 11 */	bl -0x1cf0
/* 800F3CE4  48 00 00 0C */	b 0xc
/* 800F3CE8  38 60 00 64 */	li r3, 0x64
/* 800F3CEC  4B FF E8 25 */	bl -0x17dc
/* 800F3CF0  80 1F 00 08 */	lwz r0, 8(r31)
/* 800F3CF4  2C 00 00 00 */	cmpwi r0, 0
/* 800F3CF8  41 82 FF F0 */	beq -0x10
/* 800F3CFC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F3D00  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F3D04  7C 08 03 A6 */	mtlr r0
/* 800F3D08  38 21 00 10 */	addi r1, r1, 0x10
/* 800F3D0C  4E 80 00 20 */	blr 
/* 800F3D10  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F3D14  7C 08 02 A6 */	mflr r0
/* 800F3D18  2C 03 00 00 */	cmpwi r3, 0
/* 800F3D1C  38 80 00 00 */	li r4, 0
/* 800F3D20  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F3D24  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F3D28  7C 7F 1B 78 */	mr r31, r3
/* 800F3D2C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F3D30  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F3D34  3F A0 80 2F */	lis r29, 0x802f
/* 800F3D38  3B BD 24 10 */	addi r29, r29, 0x2410
/* 800F3D3C  93 81 00 10 */	stw r28, 0x10(r1)
/* 800F3D40  40 82 00 0C */	bne 0xc
/* 800F3D44  38 60 00 04 */	li r3, 4
/* 800F3D48  48 00 01 C4 */	b 0x1c4
/* 800F3D4C  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F3D50  2C 00 00 00 */	cmpwi r0, 0
/* 800F3D54  41 82 00 20 */	beq 0x20
/* 800F3D58  81 83 00 34 */	lwz r12, 0x34(r3)
/* 800F3D5C  2C 0C 00 00 */	cmpwi r12, 0
/* 800F3D60  41 82 00 14 */	beq 0x14
/* 800F3D64  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800F3D68  7D 89 03 A6 */	mtctr r12
/* 800F3D6C  4E 80 04 21 */	bctrl 
/* 800F3D70  7C 64 1B 78 */	mr r4, r3
/* 800F3D74  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800F3D78  2C 00 00 00 */	cmpwi r0, 0
/* 800F3D7C  40 82 00 B4 */	bne 0xb4
/* 800F3D80  2C 04 00 01 */	cmpwi r4, 1
/* 800F3D84  40 82 00 AC */	bne 0xac
/* 800F3D88  80 1F 00 04 */	lwz r0, 4(r31)
/* 800F3D8C  2C 00 00 00 */	cmpwi r0, 0
/* 800F3D90  41 82 01 78 */	beq 0x178
/* 800F3D94  4B FF E7 35 */	bl -0x18cc
/* 800F3D98  80 9F 00 08 */	lwz r4, 8(r31)
/* 800F3D9C  80 1F 00 04 */	lwz r0, 4(r31)
/* 800F3DA0  7C 64 18 50 */	subf r3, r4, r3
/* 800F3DA4  7C 03 00 40 */	cmplw r3, r0
/* 800F3DA8  40 81 01 60 */	ble 0x160
/* 800F3DAC  3F C0 80 2F */	lis r30, 0x802f
/* 800F3DB0  3B DE 24 10 */	addi r30, r30, 0x2410
/* 800F3DB4  38 7E 00 10 */	addi r3, r30, 0x10
/* 800F3DB8  4B FF E2 35 */	bl -0x1dcc
/* 800F3DBC  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800F3DC0  2C 00 00 00 */	cmpwi r0, 0
/* 800F3DC4  41 82 00 30 */	beq 0x30
/* 800F3DC8  80 1F 00 18 */	lwz r0, 0x18(r31)
/* 800F3DCC  2C 00 00 00 */	cmpwi r0, 0
/* 800F3DD0  40 82 00 24 */	bne 0x24
/* 800F3DD4  81 9F 00 2C */	lwz r12, 0x2c(r31)
/* 800F3DD8  38 00 00 01 */	li r0, 1
/* 800F3DDC  90 1F 00 18 */	stw r0, 0x18(r31)
/* 800F3DE0  2C 0C 00 00 */	cmpwi r12, 0
/* 800F3DE4  41 82 00 10 */	beq 0x10
/* 800F3DE8  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800F3DEC  7D 89 03 A6 */	mtctr r12
/* 800F3DF0  4E 80 04 21 */	bctrl 
/* 800F3DF4  38 7E 00 10 */	addi r3, r30, 0x10
/* 800F3DF8  4B FF E1 F9 */	bl -0x1e08
/* 800F3DFC  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 800F3E00  2C 00 00 00 */	cmpwi r0, 0
/* 800F3E04  41 82 01 04 */	beq 0x104
/* 800F3E08  81 9F 00 28 */	lwz r12, 0x28(r31)
/* 800F3E0C  38 00 00 00 */	li r0, 0
/* 800F3E10  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800F3E14  2C 0C 00 00 */	cmpwi r12, 0
/* 800F3E18  41 82 00 F0 */	beq 0xf0
/* 800F3E1C  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800F3E20  38 80 00 03 */	li r4, 3
/* 800F3E24  7D 89 03 A6 */	mtctr r12
/* 800F3E28  4E 80 04 21 */	bctrl 
/* 800F3E2C  48 00 00 DC */	b 0xdc
/* 800F3E30  2C 04 00 01 */	cmpwi r4, 1
/* 800F3E34  41 82 00 D4 */	beq 0xd4
/* 800F3E38  80 1F 00 14 */	lwz r0, 0x14(r31)
/* 800F3E3C  3B 80 00 01 */	li r28, 1
/* 800F3E40  2C 00 00 00 */	cmpwi r0, 0
/* 800F3E44  41 82 00 38 */	beq 0x38
/* 800F3E48  80 1F 00 1C */	lwz r0, 0x1c(r31)
/* 800F3E4C  2C 00 00 00 */	cmpwi r0, 0
/* 800F3E50  41 82 00 24 */	beq 0x24
/* 800F3E54  81 9F 00 28 */	lwz r12, 0x28(r31)
/* 800F3E58  38 00 00 00 */	li r0, 0
/* 800F3E5C  90 1F 00 1C */	stw r0, 0x1c(r31)
/* 800F3E60  2C 0C 00 00 */	cmpwi r12, 0
/* 800F3E64  41 82 00 10 */	beq 0x10
/* 800F3E68  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800F3E6C  7D 89 03 A6 */	mtctr r12
/* 800F3E70  4E 80 04 21 */	bctrl 
/* 800F3E74  38 00 00 00 */	li r0, 0
/* 800F3E78  90 1F 00 14 */	stw r0, 0x14(r31)
/* 800F3E7C  81 9F 00 30 */	lwz r12, 0x30(r31)
/* 800F3E80  2C 0C 00 00 */	cmpwi r12, 0
/* 800F3E84  41 82 00 14 */	beq 0x14
/* 800F3E88  80 7F 00 20 */	lwz r3, 0x20(r31)
/* 800F3E8C  7D 89 03 A6 */	mtctr r12
/* 800F3E90  4E 80 04 21 */	bctrl 
/* 800F3E94  7C 7C 1B 78 */	mr r28, r3
/* 800F3E98  2C 1C 00 00 */	cmpwi r28, 0
/* 800F3E9C  41 82 00 6C */	beq 0x6c
/* 800F3EA0  38 7D 00 10 */	addi r3, r29, 0x10
/* 800F3EA4  4B FF E1 49 */	bl -0x1eb8
/* 800F3EA8  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 800F3EAC  4B FF B5 FD */	bl -0x4a04
/* 800F3EB0  7C 7E 1B 78 */	mr r30, r3
/* 800F3EB4  3B 80 00 00 */	li r28, 0
/* 800F3EB8  48 00 00 38 */	b 0x38
/* 800F3EBC  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 800F3EC0  7F 84 E3 78 */	mr r4, r28
/* 800F3EC4  4B FF B5 ED */	bl -0x4a14
/* 800F3EC8  80 03 00 00 */	lwz r0, 0(r3)
/* 800F3ECC  7C 00 F8 40 */	cmplw r0, r31
/* 800F3ED0  40 82 00 1C */	bne 0x1c
/* 800F3ED4  80 7D 00 28 */	lwz r3, 0x28(r29)
/* 800F3ED8  7F 84 E3 78 */	mr r4, r28
/* 800F3EDC  4B FF B8 A9 */	bl -0x4758
/* 800F3EE0  7F E3 FB 78 */	mr r3, r31
/* 800F3EE4  4B FF F9 A1 */	bl -0x660
/* 800F3EE8  48 00 00 10 */	b 0x10
/* 800F3EEC  3B 9C 00 01 */	addi r28, r28, 1
/* 800F3EF0  7C 1C F0 00 */	cmpw r28, r30
/* 800F3EF4  41 80 FF C8 */	blt -0x38
/* 800F3EF8  38 7D 00 10 */	addi r3, r29, 0x10
/* 800F3EFC  4B FF E0 F5 */	bl -0x1f0c
/* 800F3F00  38 60 00 04 */	li r3, 4
/* 800F3F04  48 00 00 08 */	b 0x8
/* 800F3F08  38 60 00 01 */	li r3, 1
/* 800F3F0C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F3F10  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F3F14  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F3F18  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F3F1C  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F3F20  7C 08 03 A6 */	mtlr r0
/* 800F3F24  38 21 00 20 */	addi r1, r1, 0x20
/* 800F3F28  4E 80 00 20 */	blr 
/* 800F3F2C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F3F30  7C 08 02 A6 */	mflr r0
/* 800F3F34  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F3F38  39 61 00 20 */	addi r11, r1, 0x20
/* 800F3F3C  4B F2 D6 65 */	bl -0xd299c
/* 800F3F40  3F C0 80 2F */	lis r30, 0x802f
/* 800F3F44  7C 7B 1B 78 */	mr r27, r3
/* 800F3F48  3B DE 24 10 */	addi r30, r30, 0x2410
/* 800F3F4C  3B 80 00 01 */	li r28, 1
/* 800F3F50  80 1E 00 08 */	lwz r0, 8(r30)
/* 800F3F54  2C 00 00 00 */	cmpwi r0, 0
/* 800F3F58  41 82 00 B4 */	beq 0xb4
/* 800F3F5C  38 7E 00 10 */	addi r3, r30, 0x10
/* 800F3F60  4B FF E0 8D */	bl -0x1f74
/* 800F3F64  4B FF E5 65 */	bl -0x1a9c
/* 800F3F68  7C 7F 1B 78 */	mr r31, r3
/* 800F3F6C  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 800F3F70  4B FF B5 39 */	bl -0x4ac8
/* 800F3F74  2C 03 00 00 */	cmpwi r3, 0
/* 800F3F78  40 81 00 08 */	ble 0x8
/* 800F3F7C  3B 80 00 00 */	li r28, 0
/* 800F3F80  3B A3 FF FF */	addi r29, r3, -1
/* 800F3F84  48 00 00 40 */	b 0x40
/* 800F3F88  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 800F3F8C  7F A4 EB 78 */	mr r4, r29
/* 800F3F90  4B FF B5 21 */	bl -0x4ae0
/* 800F3F94  80 63 00 00 */	lwz r3, 0(r3)
/* 800F3F98  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F3F9C  2C 00 00 00 */	cmpwi r0, 0
/* 800F3FA0  41 82 00 08 */	beq 0x8
/* 800F3FA4  4B FF FD 6D */	bl -0x294
/* 800F3FA8  2C 1B 00 00 */	cmpwi r27, 0
/* 800F3FAC  41 82 00 14 */	beq 0x14
/* 800F3FB0  4B FF E5 19 */	bl -0x1ae8
/* 800F3FB4  7C 1F 18 50 */	subf r0, r31, r3
/* 800F3FB8  7C 00 D8 40 */	cmplw r0, r27
/* 800F3FBC  41 81 00 10 */	bgt 0x10
/* 800F3FC0  3B BD FF FF */	addi r29, r29, -1
/* 800F3FC4  2C 1D 00 00 */	cmpwi r29, 0
/* 800F3FC8  40 80 FF C0 */	bge -0x40
/* 800F3FCC  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 800F3FD0  2C 00 00 00 */	cmpwi r0, 0
/* 800F3FD4  41 82 00 30 */	beq 0x30
/* 800F3FD8  2C 1C 00 00 */	cmpwi r28, 0
/* 800F3FDC  41 82 00 28 */	beq 0x28
/* 800F3FE0  48 01 F3 F9 */	bl 0x1f3f8
/* 800F3FE4  80 7E 00 28 */	lwz r3, 0x28(r30)
/* 800F3FE8  2C 03 00 00 */	cmpwi r3, 0
/* 800F3FEC  41 82 00 10 */	beq 0x10
/* 800F3FF0  4B FF B4 25 */	bl -0x4bdc
/* 800F3FF4  38 00 00 00 */	li r0, 0
/* 800F3FF8  90 1E 00 28 */	stw r0, 0x28(r30)
/* 800F3FFC  38 00 00 00 */	li r0, 0
/* 800F4000  90 1E 00 0C */	stw r0, 0xc(r30)
/* 800F4004  38 7E 00 10 */	addi r3, r30, 0x10
/* 800F4008  4B FF DF E9 */	bl -0x2018
/* 800F400C  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4010  4B F2 D5 DD */	bl -0xd2a24
/* 800F4014  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4018  7C 08 03 A6 */	mtlr r0
/* 800F401C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4020  4E 80 00 20 */	blr 
/* 800F4024  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4028  7C 08 02 A6 */	mflr r0
/* 800F402C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F4030  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4034  4B F2 D5 6D */	bl -0xd2a94
/* 800F4038  3C 60 80 2F */	lis r3, 0x802f
/* 800F403C  3B 83 24 10 */	addi r28, r3, 0x2410
/* 800F4040  80 1C 00 08 */	lwz r0, 8(r28)
/* 800F4044  2C 00 00 00 */	cmpwi r0, 0
/* 800F4048  41 82 00 B4 */	beq 0xb4
/* 800F404C  38 7C 00 10 */	addi r3, r28, 0x10
/* 800F4050  4B FF DF 9D */	bl -0x2064
/* 800F4054  7F 83 E3 78 */	mr r3, r28
/* 800F4058  4B FF DF 49 */	bl -0x20b8
/* 800F405C  2C 03 00 00 */	cmpwi r3, 0
/* 800F4060  41 82 00 10 */	beq 0x10
/* 800F4064  38 7C 00 10 */	addi r3, r28, 0x10
/* 800F4068  4B FF DF 89 */	bl -0x2078
/* 800F406C  48 00 00 90 */	b 0x90
/* 800F4070  3B C0 00 01 */	li r30, 1
/* 800F4074  80 7C 00 28 */	lwz r3, 0x28(r28)
/* 800F4078  93 DC 00 0C */	stw r30, 0xc(r28)
/* 800F407C  4B FF B4 2D */	bl -0x4bd4
/* 800F4080  2C 03 00 00 */	cmpwi r3, 0
/* 800F4084  7C 7F 1B 78 */	mr r31, r3
/* 800F4088  3B 60 00 00 */	li r27, 0
/* 800F408C  40 81 00 68 */	ble 0x68
/* 800F4090  48 00 00 5C */	b 0x5c
/* 800F4094  80 7C 00 28 */	lwz r3, 0x28(r28)
/* 800F4098  7F 64 DB 78 */	mr r4, r27
/* 800F409C  4B FF B4 15 */	bl -0x4bec
/* 800F40A0  83 A3 00 00 */	lwz r29, 0(r3)
/* 800F40A4  38 7C 00 10 */	addi r3, r28, 0x10
/* 800F40A8  4B FF DF 45 */	bl -0x20bc
/* 800F40AC  80 1D 00 14 */	lwz r0, 0x14(r29)
/* 800F40B0  2C 00 00 00 */	cmpwi r0, 0
/* 800F40B4  41 82 00 2C */	beq 0x2c
/* 800F40B8  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 800F40BC  2C 00 00 00 */	cmpwi r0, 0
/* 800F40C0  40 82 00 20 */	bne 0x20
/* 800F40C4  93 DD 00 18 */	stw r30, 0x18(r29)
/* 800F40C8  81 9D 00 2C */	lwz r12, 0x2c(r29)
/* 800F40CC  2C 0C 00 00 */	cmpwi r12, 0
/* 800F40D0  41 82 00 10 */	beq 0x10
/* 800F40D4  80 7D 00 20 */	lwz r3, 0x20(r29)
/* 800F40D8  7D 89 03 A6 */	mtctr r12
/* 800F40DC  4E 80 04 21 */	bctrl 
/* 800F40E0  38 7C 00 10 */	addi r3, r28, 0x10
/* 800F40E4  4B FF DF 0D */	bl -0x20f4
/* 800F40E8  3B 7B 00 01 */	addi r27, r27, 1
/* 800F40EC  7C 1B F8 00 */	cmpw r27, r31
/* 800F40F0  41 80 FF A4 */	blt -0x5c
/* 800F40F4  38 7C 00 10 */	addi r3, r28, 0x10
/* 800F40F8  4B FF DE F9 */	bl -0x2108
/* 800F40FC  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4100  4B F2 D4 ED */	bl -0xd2b14
/* 800F4104  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4108  7C 08 03 A6 */	mtlr r0
/* 800F410C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4110  4E 80 00 20 */	blr 
/* 800F4114  3C 60 80 2F */	lis r3, 0x802f
/* 800F4118  38 63 24 10 */	addi r3, r3, 0x2410
/* 800F411C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F4120  2C 00 00 00 */	cmpwi r0, 0
/* 800F4124  41 82 00 0C */	beq 0xc
/* 800F4128  38 60 00 01 */	li r3, 1
/* 800F412C  4E 80 00 20 */	blr 
/* 800F4130  80 03 00 00 */	lwz r0, 0(r3)
/* 800F4134  38 60 00 00 */	li r3, 0
/* 800F4138  2C 00 00 00 */	cmpwi r0, 0
/* 800F413C  4C 82 00 20 */	bnelr 
/* 800F4140  38 60 00 02 */	li r3, 2
/* 800F4144  4E 80 00 20 */	blr 
/* 800F4148  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F414C  7C 08 02 A6 */	mflr r0
/* 800F4150  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F4154  38 00 00 01 */	li r0, 1
/* 800F4158  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F415C  3F E0 80 2F */	lis r31, 0x802f
/* 800F4160  3B FF 24 10 */	addi r31, r31, 0x2410
/* 800F4164  90 61 00 08 */	stw r3, 8(r1)
/* 800F4168  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800F416C  80 61 00 08 */	lwz r3, 8(r1)
/* 800F4170  90 03 00 10 */	stw r0, 0x10(r3)
/* 800F4174  80 61 00 08 */	lwz r3, 8(r1)
/* 800F4178  90 03 00 14 */	stw r0, 0x14(r3)
/* 800F417C  80 61 00 08 */	lwz r3, 8(r1)
/* 800F4180  90 83 00 04 */	stw r4, 4(r3)
/* 800F4184  4B FF E3 45 */	bl -0x1cbc
/* 800F4188  80 81 00 08 */	lwz r4, 8(r1)
/* 800F418C  90 64 00 08 */	stw r3, 8(r4)
/* 800F4190  80 61 00 08 */	lwz r3, 8(r1)
/* 800F4194  81 83 00 24 */	lwz r12, 0x24(r3)
/* 800F4198  2C 0C 00 00 */	cmpwi r12, 0
/* 800F419C  41 82 00 10 */	beq 0x10
/* 800F41A0  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800F41A4  7D 89 03 A6 */	mtctr r12
/* 800F41A8  4E 80 04 21 */	bctrl 
/* 800F41AC  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F41B0  4B FF DE 3D */	bl -0x21c4
/* 800F41B4  80 7F 00 28 */	lwz r3, 0x28(r31)
/* 800F41B8  38 81 00 08 */	addi r4, r1, 8
/* 800F41BC  4B FF B3 25 */	bl -0x4cdc
/* 800F41C0  38 7F 00 10 */	addi r3, r31, 0x10
/* 800F41C4  4B FF DE 2D */	bl -0x21d4
/* 800F41C8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F41CC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F41D0  7C 08 03 A6 */	mtlr r0
/* 800F41D4  38 21 00 20 */	addi r1, r1, 0x20
/* 800F41D8  4E 80 00 20 */	blr 
/* 800F41DC  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F41E0  7C 08 02 A6 */	mflr r0
/* 800F41E4  38 60 00 38 */	li r3, 0x38
/* 800F41E8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F41EC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F41F0  4B FF F6 71 */	bl -0x990
/* 800F41F4  2C 03 00 00 */	cmpwi r3, 0
/* 800F41F8  7C 7F 1B 78 */	mr r31, r3
/* 800F41FC  40 82 00 0C */	bne 0xc
/* 800F4200  38 60 00 00 */	li r3, 0
/* 800F4204  48 00 00 1C */	b 0x1c
/* 800F4208  38 80 00 00 */	li r4, 0
/* 800F420C  38 A0 00 38 */	li r5, 0x38
/* 800F4210  4B F1 1E 29 */	bl -0xee1d8
/* 800F4214  38 00 00 01 */	li r0, 1
/* 800F4218  7F E3 FB 78 */	mr r3, r31
/* 800F421C  90 1F 00 0C */	stw r0, 0xc(r31)
/* 800F4220  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F4224  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F4228  7C 08 03 A6 */	mtlr r0
/* 800F422C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F4230  4E 80 00 20 */	blr 
/* 800F4234  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4238  7C 08 02 A6 */	mflr r0
/* 800F423C  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F4240  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4244  4B F2 D3 59 */	bl -0xd2ca8
/* 800F4248  7C 7A 1B 78 */	mr r26, r3
/* 800F424C  7C 9B 23 78 */	mr r27, r4
/* 800F4250  7C BC 2B 78 */	mr r28, r5
/* 800F4254  7C DD 33 78 */	mr r29, r6
/* 800F4258  7C FE 3B 78 */	mr r30, r7
/* 800F425C  38 60 00 34 */	li r3, 0x34
/* 800F4260  4B FF F6 01 */	bl -0xa00
/* 800F4264  2C 03 00 00 */	cmpwi r3, 0
/* 800F4268  7C 7F 1B 78 */	mr r31, r3
/* 800F426C  40 82 00 0C */	bne 0xc
/* 800F4270  38 60 00 00 */	li r3, 0
/* 800F4274  48 00 00 A0 */	b 0xa0
/* 800F4278  93 A3 00 00 */	stw r29, 0(r3)
/* 800F427C  38 00 00 00 */	li r0, 0
/* 800F4280  90 03 00 04 */	stw r0, 4(r3)
/* 800F4284  93 43 00 08 */	stw r26, 8(r3)
/* 800F4288  93 63 00 0C */	stw r27, 0xc(r3)
/* 800F428C  93 83 00 10 */	stw r28, 0x10(r3)
/* 800F4290  90 03 00 1C */	stw r0, 0x1c(r3)
/* 800F4294  90 03 00 14 */	stw r0, 0x14(r3)
/* 800F4298  90 03 00 18 */	stw r0, 0x18(r3)
/* 800F429C  93 C3 00 20 */	stw r30, 0x20(r3)
/* 800F42A0  90 03 00 2C */	stw r0, 0x2c(r3)
/* 800F42A4  90 03 00 30 */	stw r0, 0x30(r3)
/* 800F42A8  4B FF FF 35 */	bl -0xcc
/* 800F42AC  2C 03 00 00 */	cmpwi r3, 0
/* 800F42B0  40 82 00 14 */	bne 0x14
/* 800F42B4  7F E3 FB 78 */	mr r3, r31
/* 800F42B8  4B FF F5 CD */	bl -0xa34
/* 800F42BC  38 60 00 00 */	li r3, 0
/* 800F42C0  48 00 00 54 */	b 0x54
/* 800F42C4  3C A0 80 0F */	lis r5, 0x800f
/* 800F42C8  3C E0 80 0F */	lis r7, 0x800f
/* 800F42CC  38 A5 45 04 */	addi r5, r5, 0x4504
/* 800F42D0  3C 80 80 0F */	lis r4, 0x800f
/* 800F42D4  90 A3 00 28 */	stw r5, 0x28(r3)
/* 800F42D8  38 E7 44 00 */	addi r7, r7, 0x4400
/* 800F42DC  3C C0 80 0F */	lis r6, 0x800f
/* 800F42E0  3C A0 80 0F */	lis r5, 0x800f
/* 800F42E4  90 E3 00 24 */	stw r7, 0x24(r3)
/* 800F42E8  38 84 43 C4 */	addi r4, r4, 0x43c4
/* 800F42EC  38 C6 45 24 */	addi r6, r6, 0x4524
/* 800F42F0  38 A5 44 B0 */	addi r5, r5, 0x44b0
/* 800F42F4  90 83 00 34 */	stw r4, 0x34(r3)
/* 800F42F8  38 80 00 00 */	li r4, 0
/* 800F42FC  90 C3 00 30 */	stw r6, 0x30(r3)
/* 800F4300  90 A3 00 2C */	stw r5, 0x2c(r3)
/* 800F4304  93 E3 00 20 */	stw r31, 0x20(r3)
/* 800F4308  90 7F 00 24 */	stw r3, 0x24(r31)
/* 800F430C  4B FF FE 3D */	bl -0x1c4
/* 800F4310  7F E3 FB 78 */	mr r3, r31
/* 800F4314  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4318  4B F2 D2 D1 */	bl -0xd2d30
/* 800F431C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4320  7C 08 03 A6 */	mtlr r0
/* 800F4324  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4328  4E 80 00 20 */	blr 
/* 800F432C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4330  7C 08 02 A6 */	mflr r0
/* 800F4334  2C 04 00 00 */	cmpwi r4, 0
/* 800F4338  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F433C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F4340  3B E0 00 01 */	li r31, 1
/* 800F4344  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F4348  7C FE 3B 78 */	mr r30, r7
/* 800F434C  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F4350  7C DD 33 78 */	mr r29, r6
/* 800F4354  93 81 00 10 */	stw r28, 0x10(r1)
/* 800F4358  7C BC 2B 78 */	mr r28, r5
/* 800F435C  90 87 00 2C */	stw r4, 0x2c(r7)
/* 800F4360  93 E7 00 30 */	stw r31, 0x30(r7)
/* 800F4364  90 A7 00 18 */	stw r5, 0x18(r7)
/* 800F4368  40 82 00 38 */	bne 0x38
/* 800F436C  48 00 1E 21 */	bl 0x1e20
/* 800F4370  2C 03 00 00 */	cmpwi r3, 0
/* 800F4374  90 7E 00 14 */	stw r3, 0x14(r30)
/* 800F4378  40 82 00 0C */	bne 0xc
/* 800F437C  93 FE 00 2C */	stw r31, 0x2c(r30)
/* 800F4380  48 00 00 20 */	b 0x20
/* 800F4384  7F 84 E3 78 */	mr r4, r28
/* 800F4388  7F A5 EB 78 */	mr r5, r29
/* 800F438C  48 00 1E B9 */	bl 0x1eb8
/* 800F4390  2C 03 00 00 */	cmpwi r3, 0
/* 800F4394  40 82 00 0C */	bne 0xc
/* 800F4398  38 00 00 07 */	li r0, 7
/* 800F439C  90 1E 00 2C */	stw r0, 0x2c(r30)
/* 800F43A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F43A4  38 60 00 00 */	li r3, 0
/* 800F43A8  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F43AC  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F43B0  83 81 00 10 */	lwz r28, 0x10(r1)
/* 800F43B4  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F43B8  7C 08 03 A6 */	mtlr r0
/* 800F43BC  38 21 00 20 */	addi r1, r1, 0x20
/* 800F43C0  4E 80 00 20 */	blr 
/* 800F43C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F43C8  7C 08 02 A6 */	mflr r0
/* 800F43CC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F43D0  80 03 00 30 */	lwz r0, 0x30(r3)
/* 800F43D4  2C 00 00 00 */	cmpwi r0, 0
/* 800F43D8  41 82 00 0C */	beq 0xc
/* 800F43DC  38 60 00 04 */	li r3, 4
/* 800F43E0  48 00 00 10 */	b 0x10
/* 800F43E4  80 63 00 28 */	lwz r3, 0x28(r3)
/* 800F43E8  48 01 F4 39 */	bl 0x1f438
/* 800F43EC  38 60 00 01 */	li r3, 1
/* 800F43F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F43F4  7C 08 03 A6 */	mtlr r0
/* 800F43F8  38 21 00 10 */	addi r1, r1, 0x10
/* 800F43FC  4E 80 00 20 */	blr 
/* 800F4400  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4404  7C 08 02 A6 */	mflr r0
/* 800F4408  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F440C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F4410  7C 7F 1B 78 */	mr r31, r3
/* 800F4414  48 01 F5 0D */	bl 0x1f50c
/* 800F4418  2C 03 00 00 */	cmpwi r3, 0
/* 800F441C  90 7F 00 1C */	stw r3, 0x1c(r31)
/* 800F4420  40 82 00 14 */	bne 0x14
/* 800F4424  38 00 00 01 */	li r0, 1
/* 800F4428  90 1F 00 30 */	stw r0, 0x30(r31)
/* 800F442C  90 1F 00 2C */	stw r0, 0x2c(r31)
/* 800F4430  48 00 00 6C */	b 0x6c
/* 800F4434  38 80 00 00 */	li r4, 0
/* 800F4438  48 01 F4 ED */	bl 0x1f4ec
/* 800F443C  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800F4440  80 9F 00 10 */	lwz r4, 0x10(r31)
/* 800F4444  48 01 F5 69 */	bl 0x1f568
/* 800F4448  81 9F 00 04 */	lwz r12, 4(r31)
/* 800F444C  2C 0C 00 00 */	cmpwi r12, 0
/* 800F4450  41 82 00 14 */	beq 0x14
/* 800F4454  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800F4458  80 9F 00 20 */	lwz r4, 0x20(r31)
/* 800F445C  7D 89 03 A6 */	mtctr r12
/* 800F4460  4E 80 04 21 */	bctrl 
/* 800F4464  3C 60 80 0F */	lis r3, 0x800f
/* 800F4468  38 A0 00 00 */	li r5, 0
/* 800F446C  38 63 43 2C */	addi r3, r3, 0x432c
/* 800F4470  38 C0 00 00 */	li r6, 0
/* 800F4474  90 61 00 08 */	stw r3, 8(r1)
/* 800F4478  39 00 00 00 */	li r8, 0
/* 800F447C  39 20 00 00 */	li r9, 0
/* 800F4480  39 40 00 00 */	li r10, 0
/* 800F4484  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F4488  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F448C  80 9F 00 0C */	lwz r4, 0xc(r31)
/* 800F4490  80 FF 00 1C */	lwz r7, 0x1c(r31)
/* 800F4494  48 01 EF A1 */	bl 0x1efa0
/* 800F4498  90 7F 00 28 */	stw r3, 0x28(r31)
/* 800F449C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F44A0  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F44A4  7C 08 03 A6 */	mtlr r0
/* 800F44A8  38 21 00 20 */	addi r1, r1, 0x20
/* 800F44AC  4E 80 00 20 */	blr 
/* 800F44B0  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F44B4  7C 08 02 A6 */	mflr r0
/* 800F44B8  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F44BC  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F44C0  7C 7F 1B 78 */	mr r31, r3
/* 800F44C4  80 03 00 30 */	lwz r0, 0x30(r3)
/* 800F44C8  2C 00 00 00 */	cmpwi r0, 0
/* 800F44CC  40 82 00 24 */	bne 0x24
/* 800F44D0  80 63 00 28 */	lwz r3, 0x28(r3)
/* 800F44D4  2C 03 00 00 */	cmpwi r3, 0
/* 800F44D8  41 80 00 08 */	blt 0x8
/* 800F44DC  48 01 F3 7D */	bl 0x1f37c
/* 800F44E0  38 60 00 12 */	li r3, 0x12
/* 800F44E4  38 00 00 01 */	li r0, 1
/* 800F44E8  90 7F 00 2C */	stw r3, 0x2c(r31)
/* 800F44EC  90 1F 00 30 */	stw r0, 0x30(r31)
/* 800F44F0  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F44F4  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F44F8  7C 08 03 A6 */	mtlr r0
/* 800F44FC  38 21 00 10 */	addi r1, r1, 0x10
/* 800F4500  4E 80 00 20 */	blr 
/* 800F4504  7C 66 1B 78 */	mr r6, r3
/* 800F4508  80 63 00 2C */	lwz r3, 0x2c(r3)
/* 800F450C  81 86 00 00 */	lwz r12, 0(r6)
/* 800F4510  80 86 00 10 */	lwz r4, 0x10(r6)
/* 800F4514  80 A6 00 14 */	lwz r5, 0x14(r6)
/* 800F4518  80 C6 00 20 */	lwz r6, 0x20(r6)
/* 800F451C  7D 89 03 A6 */	mtctr r12
/* 800F4520  4E 80 04 20 */	bctr 
/* 800F4524  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F4528  7C 08 02 A6 */	mflr r0
/* 800F452C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F4530  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F4534  7C 7F 1B 78 */	mr r31, r3
/* 800F4538  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F453C  2C 00 00 00 */	cmpwi r0, 0
/* 800F4540  41 82 00 0C */	beq 0xc
/* 800F4544  7C 03 03 78 */	mr r3, r0
/* 800F4548  48 00 1D B9 */	bl 0x1db8
/* 800F454C  80 7F 00 18 */	lwz r3, 0x18(r31)
/* 800F4550  2C 03 00 00 */	cmpwi r3, 0
/* 800F4554  41 82 00 08 */	beq 0x8
/* 800F4558  4B FF F3 2D */	bl -0xcd4
/* 800F455C  80 7F 00 1C */	lwz r3, 0x1c(r31)
/* 800F4560  2C 03 00 00 */	cmpwi r3, 0
/* 800F4564  41 82 00 08 */	beq 0x8
/* 800F4568  48 01 F3 CD */	bl 0x1f3cc
/* 800F456C  7F E3 FB 78 */	mr r3, r31
/* 800F4570  4B FF F3 15 */	bl -0xcec
/* 800F4574  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F4578  38 60 00 01 */	li r3, 1
/* 800F457C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F4580  7C 08 03 A6 */	mtlr r0
/* 800F4584  38 21 00 10 */	addi r1, r1, 0x10
/* 800F4588  4E 80 00 20 */	blr 
/* 800F458C  2C 05 00 00 */	cmpwi r5, 0
/* 800F4590  40 82 00 14 */	bne 0x14
/* 800F4594  38 00 00 3F */	li r0, 0x3f
/* 800F4598  38 60 00 00 */	li r3, 0
/* 800F459C  B0 04 00 00 */	sth r0, 0(r4)
/* 800F45A0  4E 80 00 20 */	blr 
/* 800F45A4  88 E3 00 00 */	lbz r7, 0(r3)
/* 800F45A8  28 07 00 7F */	cmplwi r7, 0x7f
/* 800F45AC  41 81 00 14 */	bgt 0x14
/* 800F45B0  7C E0 07 74 */	extsb r0, r7
/* 800F45B4  38 60 00 01 */	li r3, 1
/* 800F45B8  B0 04 00 00 */	sth r0, 0(r4)
/* 800F45BC  4E 80 00 20 */	blr 
/* 800F45C0  54 E0 06 34 */	rlwinm r0, r7, 0, 0x18, 0x1a
/* 800F45C4  2C 00 00 C0 */	cmpwi r0, 0xc0
/* 800F45C8  40 82 00 44 */	bne 0x44
/* 800F45CC  2C 05 00 02 */	cmpwi r5, 2
/* 800F45D0  40 80 00 14 */	bge 0x14
/* 800F45D4  38 00 00 3F */	li r0, 0x3f
/* 800F45D8  38 60 00 00 */	li r3, 0
/* 800F45DC  B0 04 00 00 */	sth r0, 0(r4)
/* 800F45E0  4E 80 00 20 */	blr 
/* 800F45E4  88 A3 00 01 */	lbz r5, 1(r3)
/* 800F45E8  54 A0 06 32 */	rlwinm r0, r5, 0, 0x18, 0x19
/* 800F45EC  2C 00 00 80 */	cmpwi r0, 0x80
/* 800F45F0  40 82 00 80 */	bne 0x80
/* 800F45F4  54 E3 35 72 */	rlwinm r3, r7, 6, 0x15, 0x19
/* 800F45F8  54 A0 06 BE */	clrlwi r0, r5, 0x1a
/* 800F45FC  7C 03 02 14 */	add r0, r3, r0
/* 800F4600  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4604  38 60 00 02 */	li r3, 2
/* 800F4608  4E 80 00 20 */	blr 
/* 800F460C  54 E0 06 36 */	rlwinm r0, r7, 0, 0x18, 0x1b
/* 800F4610  2C 00 00 E0 */	cmpwi r0, 0xe0
/* 800F4614  40 82 00 5C */	bne 0x5c
/* 800F4618  2C 05 00 03 */	cmpwi r5, 3
/* 800F461C  40 80 00 14 */	bge 0x14
/* 800F4620  38 00 00 3F */	li r0, 0x3f
/* 800F4624  38 60 00 00 */	li r3, 0
/* 800F4628  B0 04 00 00 */	sth r0, 0(r4)
/* 800F462C  4E 80 00 20 */	blr 
/* 800F4630  88 A3 00 01 */	lbz r5, 1(r3)
/* 800F4634  54 A0 06 32 */	rlwinm r0, r5, 0, 0x18, 0x19
/* 800F4638  2C 00 00 80 */	cmpwi r0, 0x80
/* 800F463C  40 82 00 34 */	bne 0x34
/* 800F4640  88 63 00 02 */	lbz r3, 2(r3)
/* 800F4644  54 60 06 32 */	rlwinm r0, r3, 0, 0x18, 0x19
/* 800F4648  2C 00 00 80 */	cmpwi r0, 0x80
/* 800F464C  40 82 00 24 */	bne 0x24
/* 800F4650  54 66 06 BE */	clrlwi r6, r3, 0x1a
/* 800F4654  54 E0 64 26 */	rlwinm r0, r7, 0xc, 0x10, 0x13
/* 800F4658  54 A5 35 32 */	rlwinm r5, r5, 6, 0x14, 0x19
/* 800F465C  38 60 00 03 */	li r3, 3
/* 800F4660  7C 06 02 14 */	add r0, r6, r0
/* 800F4664  7C 05 02 14 */	add r0, r5, r0
/* 800F4668  B0 04 00 00 */	sth r0, 0(r4)
/* 800F466C  4E 80 00 20 */	blr 
/* 800F4670  38 00 00 3F */	li r0, 0x3f
/* 800F4674  38 60 00 01 */	li r3, 1
/* 800F4678  B0 04 00 00 */	sth r0, 0(r4)
/* 800F467C  4E 80 00 20 */	blr 
/* 800F4680  28 03 00 7F */	cmplwi r3, 0x7f
/* 800F4684  41 81 00 10 */	bgt 0x10
/* 800F4688  98 64 00 00 */	stb r3, 0(r4)
/* 800F468C  38 60 00 01 */	li r3, 1
/* 800F4690  4E 80 00 20 */	blr 
/* 800F4694  28 03 07 FF */	cmplwi r3, 0x7ff
/* 800F4698  41 81 00 24 */	bgt 0x24
/* 800F469C  54 65 D5 BE */	rlwinm r5, r3, 0x1a, 0x16, 0x1f
/* 800F46A0  54 60 06 BE */	clrlwi r0, r3, 0x1a
/* 800F46A4  60 A5 00 C0 */	ori r5, r5, 0xc0
/* 800F46A8  38 60 00 02 */	li r3, 2
/* 800F46AC  60 00 00 80 */	ori r0, r0, 0x80
/* 800F46B0  98 A4 00 00 */	stb r5, 0(r4)
/* 800F46B4  98 04 00 01 */	stb r0, 1(r4)
/* 800F46B8  4E 80 00 20 */	blr 
/* 800F46BC  54 66 A7 3E */	rlwinm r6, r3, 0x14, 0x1c, 0x1f
/* 800F46C0  54 65 D6 BE */	rlwinm r5, r3, 0x1a, 0x1a, 0x1f
/* 800F46C4  54 60 06 BE */	clrlwi r0, r3, 0x1a
/* 800F46C8  38 60 00 03 */	li r3, 3
/* 800F46CC  60 C6 00 E0 */	ori r6, r6, 0xe0
/* 800F46D0  60 A5 00 80 */	ori r5, r5, 0x80
/* 800F46D4  60 00 00 80 */	ori r0, r0, 0x80
/* 800F46D8  98 C4 00 00 */	stb r6, 0(r4)
/* 800F46DC  98 A4 00 01 */	stb r5, 1(r4)
/* 800F46E0  98 04 00 02 */	stb r0, 2(r4)
/* 800F46E4  4E 80 00 20 */	blr 
/* 800F46E8  2C 03 00 00 */	cmpwi r3, 0
/* 800F46EC  38 A0 00 00 */	li r5, 0
/* 800F46F0  40 82 00 70 */	bne 0x70
/* 800F46F4  38 60 00 00 */	li r3, 0
/* 800F46F8  4E 80 00 20 */	blr 
/* 800F46FC  48 00 00 64 */	b 0x64
/* 800F4700  54 80 06 34 */	rlwinm r0, r4, 0, 0x18, 0x1a
/* 800F4704  2C 00 00 C0 */	cmpwi r0, 0xc0
/* 800F4708  40 82 00 1C */	bne 0x1c
/* 800F470C  88 03 00 01 */	lbz r0, 1(r3)
/* 800F4710  54 00 06 32 */	rlwinm r0, r0, 0, 0x18, 0x19
/* 800F4714  2C 00 00 80 */	cmpwi r0, 0x80
/* 800F4718  40 82 00 0C */	bne 0xc
/* 800F471C  38 63 00 02 */	addi r3, r3, 2
/* 800F4720  48 00 00 3C */	b 0x3c
/* 800F4724  54 80 06 36 */	rlwinm r0, r4, 0, 0x18, 0x1b
/* 800F4728  2C 00 00 E0 */	cmpwi r0, 0xe0
/* 800F472C  40 82 00 2C */	bne 0x2c
/* 800F4730  88 03 00 01 */	lbz r0, 1(r3)
/* 800F4734  54 00 06 32 */	rlwinm r0, r0, 0, 0x18, 0x19
/* 800F4738  2C 00 00 80 */	cmpwi r0, 0x80
/* 800F473C  40 82 00 1C */	bne 0x1c
/* 800F4740  88 03 00 02 */	lbz r0, 2(r3)
/* 800F4744  54 00 06 32 */	rlwinm r0, r0, 0, 0x18, 0x19
/* 800F4748  2C 00 00 80 */	cmpwi r0, 0x80
/* 800F474C  40 82 00 0C */	bne 0xc
/* 800F4750  38 63 00 03 */	addi r3, r3, 3
/* 800F4754  48 00 00 08 */	b 0x8
/* 800F4758  38 63 00 01 */	addi r3, r3, 1
/* 800F475C  38 A5 00 01 */	addi r5, r5, 1
/* 800F4760  88 83 00 00 */	lbz r4, 0(r3)
/* 800F4764  7C 80 07 75 */	extsb. r0, r4
/* 800F4768  40 82 FF 98 */	bne -0x68
/* 800F476C  7C A3 2B 78 */	mr r3, r5
/* 800F4770  4E 80 00 20 */	blr 
/* 800F4774  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F4778  7C 08 02 A6 */	mflr r0
/* 800F477C  2C 03 00 00 */	cmpwi r3, 0
/* 800F4780  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F4784  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F4788  93 C1 00 08 */	stw r30, 8(r1)
/* 800F478C  7C 7E 1B 78 */	mr r30, r3
/* 800F4790  40 82 00 0C */	bne 0xc
/* 800F4794  38 60 00 00 */	li r3, 0
/* 800F4798  48 00 00 34 */	b 0x34
/* 800F479C  4B FF FF 4D */	bl -0xb4
/* 800F47A0  38 03 00 01 */	addi r0, r3, 1
/* 800F47A4  54 03 08 3C */	slwi r3, r0, 1
/* 800F47A8  4B FF F0 B9 */	bl -0xf48
/* 800F47AC  7C 7F 1B 78 */	mr r31, r3
/* 800F47B0  7F C3 F3 78 */	mr r3, r30
/* 800F47B4  4B F2 CA A1 */	bl -0xd3560
/* 800F47B8  7C 65 1B 78 */	mr r5, r3
/* 800F47BC  7F C3 F3 78 */	mr r3, r30
/* 800F47C0  7F E4 FB 78 */	mr r4, r31
/* 800F47C4  48 00 00 21 */	bl 0x20
/* 800F47C8  7F E3 FB 78 */	mr r3, r31
/* 800F47CC  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F47D0  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F47D4  83 C1 00 08 */	lwz r30, 8(r1)
/* 800F47D8  7C 08 03 A6 */	mtlr r0
/* 800F47DC  38 21 00 10 */	addi r1, r1, 0x10
/* 800F47E0  4E 80 00 20 */	blr 
/* 800F47E4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F47E8  7C 08 02 A6 */	mflr r0
/* 800F47EC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F47F0  39 61 00 20 */	addi r11, r1, 0x20
/* 800F47F4  4B F2 CD A9 */	bl -0xd3258
/* 800F47F8  2C 03 00 00 */	cmpwi r3, 0
/* 800F47FC  7C 9A 23 78 */	mr r26, r4
/* 800F4800  7C 7D 1B 78 */	mr r29, r3
/* 800F4804  7C BB 2B 78 */	mr r27, r5
/* 800F4808  3B E0 00 00 */	li r31, 0
/* 800F480C  7F 5C D3 78 */	mr r28, r26
/* 800F4810  3B C0 00 00 */	li r30, 0
/* 800F4814  40 82 00 50 */	bne 0x50
/* 800F4818  38 00 00 00 */	li r0, 0
/* 800F481C  38 60 00 01 */	li r3, 1
/* 800F4820  B0 04 00 00 */	sth r0, 0(r4)
/* 800F4824  48 00 00 60 */	b 0x60
/* 800F4828  48 00 00 3C */	b 0x3c
/* 800F482C  7F A3 EB 78 */	mr r3, r29
/* 800F4830  7F 84 E3 78 */	mr r4, r28
/* 800F4834  7C BE D8 50 */	subf r5, r30, r27
/* 800F4838  4B FF FD 55 */	bl -0x2ac
/* 800F483C  2C 03 00 00 */	cmpwi r3, 0
/* 800F4840  40 82 00 14 */	bne 0x14
/* 800F4844  38 00 00 00 */	li r0, 0
/* 800F4848  38 60 00 00 */	li r3, 0
/* 800F484C  B0 1A 00 00 */	sth r0, 0(r26)
/* 800F4850  48 00 00 34 */	b 0x34
/* 800F4854  7F DE 1A 14 */	add r30, r30, r3
/* 800F4858  7F BD 1A 14 */	add r29, r29, r3
/* 800F485C  3B FF 00 01 */	addi r31, r31, 1
/* 800F4860  3B 9C 00 02 */	addi r28, r28, 2
/* 800F4864  88 1D 00 00 */	lbz r0, 0(r29)
/* 800F4868  2C 00 00 00 */	cmpwi r0, 0
/* 800F486C  41 82 00 0C */	beq 0xc
/* 800F4870  7C 1B F0 00 */	cmpw r27, r30
/* 800F4874  41 81 FF B8 */	bgt -0x48
/* 800F4878  38 00 00 00 */	li r0, 0
/* 800F487C  38 7F 00 01 */	addi r3, r31, 1
/* 800F4880  B0 1C 00 00 */	sth r0, 0(r28)
/* 800F4884  39 61 00 20 */	addi r11, r1, 0x20
/* 800F4888  4B F2 CD 61 */	bl -0xd32a0
/* 800F488C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4890  7C 08 03 A6 */	mtlr r0
/* 800F4894  38 21 00 20 */	addi r1, r1, 0x20
/* 800F4898  4E 80 00 20 */	blr 
/* 800F489C  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800F48A0  4B FF AB 74 */	b -0x548c
/* 800F48A4  38 A0 00 10 */	li r5, 0x10
/* 800F48A8  4B F1 AA 6C */	b -0xe5594
/* 800F48AC  38 A0 00 10 */	li r5, 0x10
/* 800F48B0  38 63 00 10 */	addi r3, r3, 0x10
/* 800F48B4  38 84 00 10 */	addi r4, r4, 0x10
/* 800F48B8  4B F1 AA 5C */	b -0xe55a4
/* 800F48BC  80 A3 00 00 */	lwz r5, 0(r3)
/* 800F48C0  80 04 00 00 */	lwz r0, 0(r4)
/* 800F48C4  7C 05 00 40 */	cmplw r5, r0
/* 800F48C8  41 82 00 0C */	beq 0xc
/* 800F48CC  38 60 00 01 */	li r3, 1
/* 800F48D0  4E 80 00 20 */	blr 
/* 800F48D4  A0 A3 00 04 */	lhz r5, 4(r3)
/* 800F48D8  A0 04 00 04 */	lhz r0, 4(r4)
/* 800F48DC  7C 65 00 50 */	subf r3, r5, r0
/* 800F48E0  7C 00 28 50 */	subf r0, r0, r5
/* 800F48E4  7C 60 03 78 */	or r0, r3, r0
/* 800F48E8  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800F48EC  4E 80 00 20 */	blr 
/* 800F48F0  80 A3 00 08 */	lwz r5, 8(r3)
/* 800F48F4  80 04 00 08 */	lwz r0, 8(r4)
/* 800F48F8  7C 65 00 50 */	subf r3, r5, r0
/* 800F48FC  7C 00 28 50 */	subf r0, r0, r5
/* 800F4900  7C 60 03 78 */	or r0, r3, r0
/* 800F4904  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800F4908  4E 80 00 20 */	blr 
/* 800F490C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F4910  7C 08 02 A6 */	mflr r0
/* 800F4914  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F4918  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F491C  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F4920  93 A1 00 14 */	stw r29, 0x14(r1)
/* 800F4924  3F A0 80 2F */	lis r29, 0x802f
/* 800F4928  3B BD 24 40 */	addi r29, r29, 0x2440
/* 800F492C  81 9D 00 24 */	lwz r12, 0x24(r29)
/* 800F4930  2C 0C 00 00 */	cmpwi r12, 0
/* 800F4934  41 82 00 14 */	beq 0x14
/* 800F4938  80 9D 00 2C */	lwz r4, 0x2c(r29)
/* 800F493C  38 60 00 03 */	li r3, 3
/* 800F4940  7D 89 03 A6 */	mtctr r12
/* 800F4944  4E 80 04 21 */	bctrl 
/* 800F4948  80 7D 00 08 */	lwz r3, 8(r29)
/* 800F494C  4B FF AB 5D */	bl -0x54a4
/* 800F4950  7C 7F 1B 78 */	mr r31, r3
/* 800F4954  3B C0 00 00 */	li r30, 0
/* 800F4958  48 00 00 30 */	b 0x30
/* 800F495C  80 7D 00 08 */	lwz r3, 8(r29)
/* 800F4960  7F C4 F3 78 */	mr r4, r30
/* 800F4964  4B FF AB 4D */	bl -0x54b4
/* 800F4968  81 83 00 34 */	lwz r12, 0x34(r3)
/* 800F496C  2C 0C 00 00 */	cmpwi r12, 0
/* 800F4970  41 82 00 14 */	beq 0x14
/* 800F4974  80 83 00 38 */	lwz r4, 0x38(r3)
/* 800F4978  38 60 00 03 */	li r3, 3
/* 800F497C  7D 89 03 A6 */	mtctr r12
/* 800F4980  4E 80 04 21 */	bctrl 
/* 800F4984  3B DE 00 01 */	addi r30, r30, 1
/* 800F4988  7C 1E F8 00 */	cmpw r30, r31
/* 800F498C  41 80 FF D0 */	blt -0x30
/* 800F4990  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F4994  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F4998  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F499C  83 A1 00 14 */	lwz r29, 0x14(r1)
/* 800F49A0  7C 08 03 A6 */	mtlr r0
/* 800F49A4  38 21 00 20 */	addi r1, r1, 0x20
/* 800F49A8  4E 80 00 20 */	blr 
/* 800F49AC  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800F49B0  7C 08 02 A6 */	mflr r0
/* 800F49B4  90 01 00 54 */	stw r0, 0x54(r1)
/* 800F49B8  39 61 00 50 */	addi r11, r1, 0x50
/* 800F49BC  4B F2 CB DD */	bl -0xd3424
/* 800F49C0  38 04 FF FE */	addi r0, r4, -2
/* 800F49C4  3F 80 80 2F */	lis r28, 0x802f
/* 800F49C8  28 00 00 01 */	cmplwi r0, 1
/* 800F49CC  7C 79 1B 78 */	mr r25, r3
/* 800F49D0  3B 9C 24 40 */	addi r28, r28, 0x2440
/* 800F49D4  41 81 00 0C */	bgt 0xc
/* 800F49D8  3B 40 00 02 */	li r26, 2
/* 800F49DC  48 00 00 14 */	b 0x14
/* 800F49E0  2C 04 00 04 */	cmpwi r4, 4
/* 800F49E4  40 82 00 08 */	bne 0x8
/* 800F49E8  38 80 00 03 */	li r4, 3
/* 800F49EC  7C 9A 23 78 */	mr r26, r4
/* 800F49F0  7F 23 CB 78 */	mr r3, r25
/* 800F49F4  48 01 62 D1 */	bl 0x162d0
/* 800F49F8  7C 7D 1B 78 */	mr r29, r3
/* 800F49FC  7F 23 CB 78 */	mr r3, r25
/* 800F4A00  48 01 62 BD */	bl 0x162bc
/* 800F4A04  57 A4 04 3E */	clrlwi r4, r29, 0x10
/* 800F4A08  38 A1 00 14 */	addi r5, r1, 0x14
/* 800F4A0C  48 01 9F B5 */	bl 0x19fb4
/* 800F4A10  80 7C 00 08 */	lwz r3, 8(r28)
/* 800F4A14  4B FF AA 95 */	bl -0x556c
/* 800F4A18  7C 7D 1B 78 */	mr r29, r3
/* 800F4A1C  3B 60 00 00 */	li r27, 0
/* 800F4A20  48 00 00 50 */	b 0x50
/* 800F4A24  80 7C 00 08 */	lwz r3, 8(r28)
/* 800F4A28  7F 64 DB 78 */	mr r4, r27
/* 800F4A2C  4B FF AA 85 */	bl -0x557c
/* 800F4A30  80 03 00 24 */	lwz r0, 0x24(r3)
/* 800F4A34  7C 7E 1B 78 */	mr r30, r3
/* 800F4A38  2C 00 00 00 */	cmpwi r0, 0
/* 800F4A3C  41 82 00 30 */	beq 0x30
/* 800F4A40  7F 23 CB 78 */	mr r3, r25
/* 800F4A44  48 01 62 81 */	bl 0x16280
/* 800F4A48  7C 7F 1B 78 */	mr r31, r3
/* 800F4A4C  7F 23 CB 78 */	mr r3, r25
/* 800F4A50  48 01 62 6D */	bl 0x1626c
/* 800F4A54  81 9E 00 24 */	lwz r12, 0x24(r30)
/* 800F4A58  7F 45 D3 78 */	mr r5, r26
/* 800F4A5C  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 800F4A60  80 DE 00 38 */	lwz r6, 0x38(r30)
/* 800F4A64  7D 89 03 A6 */	mtctr r12
/* 800F4A68  4E 80 04 21 */	bctrl 
/* 800F4A6C  3B 7B 00 01 */	addi r27, r27, 1
/* 800F4A70  7C 1B E8 00 */	cmpw r27, r29
/* 800F4A74  41 80 FF B0 */	blt -0x50
/* 800F4A78  80 1C 00 14 */	lwz r0, 0x14(r28)
/* 800F4A7C  2C 00 00 00 */	cmpwi r0, 0
/* 800F4A80  41 82 00 30 */	beq 0x30
/* 800F4A84  7F 23 CB 78 */	mr r3, r25
/* 800F4A88  48 01 62 3D */	bl 0x1623c
/* 800F4A8C  7C 7F 1B 78 */	mr r31, r3
/* 800F4A90  7F 23 CB 78 */	mr r3, r25
/* 800F4A94  48 01 62 29 */	bl 0x16228
/* 800F4A98  81 9C 00 14 */	lwz r12, 0x14(r28)
/* 800F4A9C  7F 45 D3 78 */	mr r5, r26
/* 800F4AA0  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 800F4AA4  80 DC 00 2C */	lwz r6, 0x2c(r28)
/* 800F4AA8  7D 89 03 A6 */	mtctr r12
/* 800F4AAC  4E 80 04 21 */	bctrl 
/* 800F4AB0  3C A0 80 0F */	lis r5, 0x800f
/* 800F4AB4  93 21 00 10 */	stw r25, 0x10(r1)
/* 800F4AB8  80 7C 00 04 */	lwz r3, 4(r28)
/* 800F4ABC  38 81 00 08 */	addi r4, r1, 8
/* 800F4AC0  38 A5 48 F0 */	addi r5, r5, 0x48f0
/* 800F4AC4  38 C0 00 00 */	li r6, 0
/* 800F4AC8  38 E0 00 00 */	li r7, 0
/* 800F4ACC  4B FF AF 25 */	bl -0x50dc
/* 800F4AD0  2C 03 FF FF */	cmpwi r3, -1
/* 800F4AD4  7C 64 1B 78 */	mr r4, r3
/* 800F4AD8  41 82 00 0C */	beq 0xc
/* 800F4ADC  80 7C 00 04 */	lwz r3, 4(r28)
/* 800F4AE0  4B FF AD 51 */	bl -0x52b0
/* 800F4AE4  39 61 00 50 */	addi r11, r1, 0x50
/* 800F4AE8  4B F2 CA FD */	bl -0xd3504
/* 800F4AEC  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800F4AF0  7C 08 03 A6 */	mtlr r0
/* 800F4AF4  38 21 00 50 */	addi r1, r1, 0x50
/* 800F4AF8  4E 80 00 20 */	blr 
/* 800F4AFC  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800F4B00  7C 08 02 A6 */	mflr r0
/* 800F4B04  90 01 00 64 */	stw r0, 0x64(r1)
/* 800F4B08  39 61 00 60 */	addi r11, r1, 0x60
/* 800F4B0C  4B F2 CA 85 */	bl -0xd357c
/* 800F4B10  2C 04 00 02 */	cmpwi r4, 2
/* 800F4B14  3F 40 80 2F */	lis r26, 0x802f
/* 800F4B18  7C 7E 1B 78 */	mr r30, r3
/* 800F4B1C  7C 97 23 78 */	mr r23, r4
/* 800F4B20  3B 5A 24 40 */	addi r26, r26, 0x2440
/* 800F4B24  41 82 00 34 */	beq 0x34
/* 800F4B28  40 80 00 10 */	bge 0x10
/* 800F4B2C  2C 04 00 00 */	cmpwi r4, 0
/* 800F4B30  41 82 00 38 */	beq 0x38
/* 800F4B34  48 00 00 3C */	b 0x3c
/* 800F4B38  2C 04 00 07 */	cmpwi r4, 7
/* 800F4B3C  41 82 00 14 */	beq 0x14
/* 800F4B40  40 80 00 30 */	bge 0x30
/* 800F4B44  2C 04 00 06 */	cmpwi r4, 6
/* 800F4B48  40 80 00 18 */	bge 0x18
/* 800F4B4C  48 00 00 24 */	b 0x24
/* 800F4B50  3B E0 00 07 */	li r31, 7
/* 800F4B54  48 00 00 20 */	b 0x20
/* 800F4B58  3B E0 00 02 */	li r31, 2
/* 800F4B5C  48 00 00 18 */	b 0x18
/* 800F4B60  3B E0 00 06 */	li r31, 6
/* 800F4B64  48 00 00 10 */	b 0x10
/* 800F4B68  3B E0 00 00 */	li r31, 0
/* 800F4B6C  48 00 00 08 */	b 0x8
/* 800F4B70  3B E0 00 0D */	li r31, 0xd
/* 800F4B74  2C 04 00 02 */	cmpwi r4, 2
/* 800F4B78  40 82 00 70 */	bne 0x70
/* 800F4B7C  7F C3 F3 78 */	mr r3, r30
/* 800F4B80  48 01 61 3D */	bl 0x1613c
/* 800F4B84  90 61 00 14 */	stw r3, 0x14(r1)
/* 800F4B88  7F C3 F3 78 */	mr r3, r30
/* 800F4B8C  48 01 61 39 */	bl 0x16138
/* 800F4B90  B0 61 00 18 */	sth r3, 0x18(r1)
/* 800F4B94  3C A0 80 0F */	lis r5, 0x800f
/* 800F4B98  80 7A 00 04 */	lwz r3, 4(r26)
/* 800F4B9C  38 81 00 14 */	addi r4, r1, 0x14
/* 800F4BA0  38 A5 48 BC */	addi r5, r5, 0x48bc
/* 800F4BA4  38 C0 00 00 */	li r6, 0
/* 800F4BA8  38 E0 00 00 */	li r7, 0
/* 800F4BAC  4B FF AE 45 */	bl -0x51bc
/* 800F4BB0  2C 03 FF FF */	cmpwi r3, -1
/* 800F4BB4  7C 79 1B 78 */	mr r25, r3
/* 800F4BB8  41 82 00 30 */	beq 0x30
/* 800F4BBC  7F C3 F3 78 */	mr r3, r30
/* 800F4BC0  48 01 61 05 */	bl 0x16104
/* 800F4BC4  7C 7B 1B 78 */	mr r27, r3
/* 800F4BC8  7F C3 F3 78 */	mr r3, r30
/* 800F4BCC  48 01 60 F1 */	bl 0x160f0
/* 800F4BD0  57 64 04 3E */	clrlwi r4, r27, 0x10
/* 800F4BD4  38 A1 00 20 */	addi r5, r1, 0x20
/* 800F4BD8  48 01 9D E9 */	bl 0x19de8
/* 800F4BDC  80 7A 00 04 */	lwz r3, 4(r26)
/* 800F4BE0  7F 24 CB 78 */	mr r4, r25
/* 800F4BE4  4B FF AC 4D */	bl -0x53b4
/* 800F4BE8  80 7A 00 08 */	lwz r3, 8(r26)
/* 800F4BEC  4B FF A8 BD */	bl -0x5744
/* 800F4BF0  7C 7B 1B 78 */	mr r27, r3
/* 800F4BF4  3B 20 00 00 */	li r25, 0
/* 800F4BF8  3F A0 80 0F */	lis r29, 0x800f
/* 800F4BFC  48 00 00 AC */	b 0xac
/* 800F4C00  80 7A 00 08 */	lwz r3, 8(r26)
/* 800F4C04  7F 24 CB 78 */	mr r4, r25
/* 800F4C08  4B FF A8 A9 */	bl -0x5758
/* 800F4C0C  7C 7C 1B 78 */	mr r28, r3
/* 800F4C10  7F C3 F3 78 */	mr r3, r30
/* 800F4C14  48 01 60 A9 */	bl 0x160a8
/* 800F4C18  90 61 00 08 */	stw r3, 8(r1)
/* 800F4C1C  7F C3 F3 78 */	mr r3, r30
/* 800F4C20  48 01 60 A5 */	bl 0x160a4
/* 800F4C24  B0 61 00 0C */	sth r3, 0xc(r1)
/* 800F4C28  38 81 00 08 */	addi r4, r1, 8
/* 800F4C2C  38 BD 48 BC */	addi r5, r29, 0x48bc
/* 800F4C30  38 C0 00 00 */	li r6, 0
/* 800F4C34  80 7C 00 20 */	lwz r3, 0x20(r28)
/* 800F4C38  38 E0 00 00 */	li r7, 0
/* 800F4C3C  4B FF AD B5 */	bl -0x524c
/* 800F4C40  2C 03 FF FF */	cmpwi r3, -1
/* 800F4C44  7C 78 1B 78 */	mr r24, r3
/* 800F4C48  41 82 00 5C */	beq 0x5c
/* 800F4C4C  80 1C 00 2C */	lwz r0, 0x2c(r28)
/* 800F4C50  2C 00 00 00 */	cmpwi r0, 0
/* 800F4C54  41 82 00 40 */	beq 0x40
/* 800F4C58  38 17 FF FE */	addi r0, r23, -2
/* 800F4C5C  7F C3 F3 78 */	mr r3, r30
/* 800F4C60  7C 00 00 34 */	cntlzw r0, r0
/* 800F4C64  54 1B D9 7E */	srwi r27, r0, 5
/* 800F4C68  48 01 60 5D */	bl 0x1605c
/* 800F4C6C  7C 7D 1B 78 */	mr r29, r3
/* 800F4C70  7F C3 F3 78 */	mr r3, r30
/* 800F4C74  48 01 60 49 */	bl 0x16048
/* 800F4C78  81 9C 00 2C */	lwz r12, 0x2c(r28)
/* 800F4C7C  7F E5 FB 78 */	mr r5, r31
/* 800F4C80  7F 66 DB 78 */	mr r6, r27
/* 800F4C84  57 A4 04 3E */	clrlwi r4, r29, 0x10
/* 800F4C88  80 FC 00 38 */	lwz r7, 0x38(r28)
/* 800F4C8C  7D 89 03 A6 */	mtctr r12
/* 800F4C90  4E 80 04 21 */	bctrl 
/* 800F4C94  80 7C 00 20 */	lwz r3, 0x20(r28)
/* 800F4C98  7F 04 C3 78 */	mr r4, r24
/* 800F4C9C  4B FF AB 95 */	bl -0x546c
/* 800F4CA0  48 00 00 70 */	b 0x70
/* 800F4CA4  3B 39 00 01 */	addi r25, r25, 1
/* 800F4CA8  7C 19 D8 00 */	cmpw r25, r27
/* 800F4CAC  41 80 FF 54 */	blt -0xac
/* 800F4CB0  80 1A 00 30 */	lwz r0, 0x30(r26)
/* 800F4CB4  2C 00 00 00 */	cmpwi r0, 0
/* 800F4CB8  40 81 00 58 */	ble 0x58
/* 800F4CBC  80 1A 00 10 */	lwz r0, 0x10(r26)
/* 800F4CC0  2C 00 00 00 */	cmpwi r0, 0
/* 800F4CC4  41 82 00 40 */	beq 0x40
/* 800F4CC8  38 17 FF FE */	addi r0, r23, -2
/* 800F4CCC  7F C3 F3 78 */	mr r3, r30
/* 800F4CD0  7C 00 00 34 */	cntlzw r0, r0
/* 800F4CD4  54 1B D9 7E */	srwi r27, r0, 5
/* 800F4CD8  48 01 5F ED */	bl 0x15fec
/* 800F4CDC  7C 7D 1B 78 */	mr r29, r3
/* 800F4CE0  7F C3 F3 78 */	mr r3, r30
/* 800F4CE4  48 01 5F D9 */	bl 0x15fd8
/* 800F4CE8  81 9A 00 10 */	lwz r12, 0x10(r26)
/* 800F4CEC  7F E5 FB 78 */	mr r5, r31
/* 800F4CF0  7F 66 DB 78 */	mr r6, r27
/* 800F4CF4  57 A4 04 3E */	clrlwi r4, r29, 0x10
/* 800F4CF8  80 FA 00 2C */	lwz r7, 0x2c(r26)
/* 800F4CFC  7D 89 03 A6 */	mtctr r12
/* 800F4D00  4E 80 04 21 */	bctrl 
/* 800F4D04  80 7A 00 30 */	lwz r3, 0x30(r26)
/* 800F4D08  38 03 FF FF */	addi r0, r3, -1
/* 800F4D0C  90 1A 00 30 */	stw r0, 0x30(r26)
/* 800F4D10  39 61 00 60 */	addi r11, r1, 0x60
/* 800F4D14  4B F2 C8 C9 */	bl -0xd3738
/* 800F4D18  80 01 00 64 */	lwz r0, 0x64(r1)
/* 800F4D1C  7C 08 03 A6 */	mtlr r0
/* 800F4D20  38 21 00 60 */	addi r1, r1, 0x60
/* 800F4D24  4E 80 00 20 */	blr 
/* 800F4D28  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800F4D2C  7C 08 02 A6 */	mflr r0
/* 800F4D30  90 01 00 44 */	stw r0, 0x44(r1)
/* 800F4D34  39 61 00 40 */	addi r11, r1, 0x40
/* 800F4D38  4B F2 C8 65 */	bl -0xd379c
/* 800F4D3C  3F A0 80 2F */	lis r29, 0x802f
/* 800F4D40  7C 7A 1B 78 */	mr r26, r3
/* 800F4D44  7C 9B 23 78 */	mr r27, r4
/* 800F4D48  3B BD 24 40 */	addi r29, r29, 0x2440
/* 800F4D4C  48 01 5F 79 */	bl 0x15f78
/* 800F4D50  7C 7E 1B 78 */	mr r30, r3
/* 800F4D54  7F 43 D3 78 */	mr r3, r26
/* 800F4D58  48 01 5F 65 */	bl 0x15f64
/* 800F4D5C  57 C4 04 3E */	clrlwi r4, r30, 0x10
/* 800F4D60  38 A1 00 08 */	addi r5, r1, 8
/* 800F4D64  48 01 9C 5D */	bl 0x19c5c
/* 800F4D68  80 7D 00 08 */	lwz r3, 8(r29)
/* 800F4D6C  4B FF A7 3D */	bl -0x58c4
/* 800F4D70  7C 7F 1B 78 */	mr r31, r3
/* 800F4D74  3B 80 00 00 */	li r28, 0
/* 800F4D78  48 00 00 54 */	b 0x54
/* 800F4D7C  80 7D 00 08 */	lwz r3, 8(r29)
/* 800F4D80  7F 84 E3 78 */	mr r4, r28
/* 800F4D84  4B FF A7 2D */	bl -0x58d4
/* 800F4D88  80 03 00 30 */	lwz r0, 0x30(r3)
/* 800F4D8C  7C 7E 1B 78 */	mr r30, r3
/* 800F4D90  2C 00 00 00 */	cmpwi r0, 0
/* 800F4D94  41 82 00 34 */	beq 0x34
/* 800F4D98  7F 43 D3 78 */	mr r3, r26
/* 800F4D9C  48 01 5F 29 */	bl 0x15f28
/* 800F4DA0  7C 7F 1B 78 */	mr r31, r3
/* 800F4DA4  7F 43 D3 78 */	mr r3, r26
/* 800F4DA8  48 01 5F 15 */	bl 0x15f14
/* 800F4DAC  81 9E 00 30 */	lwz r12, 0x30(r30)
/* 800F4DB0  7F 65 DB 78 */	mr r5, r27
/* 800F4DB4  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 800F4DB8  80 DE 00 38 */	lwz r6, 0x38(r30)
/* 800F4DBC  7D 89 03 A6 */	mtctr r12
/* 800F4DC0  4E 80 04 21 */	bctrl 
/* 800F4DC4  48 00 00 48 */	b 0x48
/* 800F4DC8  3B 9C 00 01 */	addi r28, r28, 1
/* 800F4DCC  7C 1C F8 00 */	cmpw r28, r31
/* 800F4DD0  41 80 FF AC */	blt -0x54
/* 800F4DD4  80 1D 00 18 */	lwz r0, 0x18(r29)
/* 800F4DD8  2C 00 00 00 */	cmpwi r0, 0
/* 800F4DDC  41 82 00 30 */	beq 0x30
/* 800F4DE0  7F 43 D3 78 */	mr r3, r26
/* 800F4DE4  48 01 5E E1 */	bl 0x15ee0
/* 800F4DE8  7C 7F 1B 78 */	mr r31, r3
/* 800F4DEC  7F 43 D3 78 */	mr r3, r26
/* 800F4DF0  48 01 5E CD */	bl 0x15ecc
/* 800F4DF4  81 9D 00 18 */	lwz r12, 0x18(r29)
/* 800F4DF8  7F 65 DB 78 */	mr r5, r27
/* 800F4DFC  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 800F4E00  80 DD 00 2C */	lwz r6, 0x2c(r29)
/* 800F4E04  7D 89 03 A6 */	mtctr r12
/* 800F4E08  4E 80 04 21 */	bctrl 
/* 800F4E0C  39 61 00 40 */	addi r11, r1, 0x40
/* 800F4E10  4B F2 C7 D9 */	bl -0xd3828
/* 800F4E14  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800F4E18  7C 08 03 A6 */	mtlr r0
/* 800F4E1C  38 21 00 40 */	addi r1, r1, 0x40
/* 800F4E20  4E 80 00 20 */	blr 
/* 800F4E24  94 21 FF 80 */	stwu r1, -0x80(r1)
/* 800F4E28  7C 08 02 A6 */	mflr r0
/* 800F4E2C  90 01 00 84 */	stw r0, 0x84(r1)
/* 800F4E30  39 61 00 80 */	addi r11, r1, 0x80
/* 800F4E34  4B F2 C7 65 */	bl -0xd389c
/* 800F4E38  3F A0 80 2F */	lis r29, 0x802f
/* 800F4E3C  7C 79 1B 78 */	mr r25, r3
/* 800F4E40  7C 9A 23 78 */	mr r26, r4
/* 800F4E44  7C BB 2B 78 */	mr r27, r5
/* 800F4E48  7C DC 33 78 */	mr r28, r6
/* 800F4E4C  3B BD 24 40 */	addi r29, r29, 0x2440
/* 800F4E50  48 01 5E 75 */	bl 0x15e74
/* 800F4E54  7C 7E 1B 78 */	mr r30, r3
/* 800F4E58  7F 23 CB 78 */	mr r3, r25
/* 800F4E5C  48 01 5E 61 */	bl 0x15e60
/* 800F4E60  57 C4 04 3E */	clrlwi r4, r30, 0x10
/* 800F4E64  38 A1 00 08 */	addi r5, r1, 8
/* 800F4E68  48 01 9B 59 */	bl 0x19b58
/* 800F4E6C  2C 1B 00 10 */	cmpwi r27, 0x10
/* 800F4E70  41 80 00 8C */	blt 0x8c
/* 800F4E74  7F 44 D3 78 */	mr r4, r26
/* 800F4E78  38 61 00 30 */	addi r3, r1, 0x30
/* 800F4E7C  38 A0 00 10 */	li r5, 0x10
/* 800F4E80  4B F1 10 B5 */	bl -0xeef4c
/* 800F4E84  3C A0 80 0F */	lis r5, 0x800f
/* 800F4E88  80 7D 00 08 */	lwz r3, 8(r29)
/* 800F4E8C  38 81 00 20 */	addi r4, r1, 0x20
/* 800F4E90  38 C0 00 00 */	li r6, 0
/* 800F4E94  38 A5 48 AC */	addi r5, r5, 0x48ac
/* 800F4E98  38 E0 00 00 */	li r7, 0
/* 800F4E9C  4B FF AB 55 */	bl -0x54ac
/* 800F4EA0  2C 03 FF FF */	cmpwi r3, -1
/* 800F4EA4  7C 64 1B 78 */	mr r4, r3
/* 800F4EA8  41 82 00 54 */	beq 0x54
/* 800F4EAC  80 7D 00 08 */	lwz r3, 8(r29)
/* 800F4EB0  4B FF A6 01 */	bl -0x5a00
/* 800F4EB4  80 03 00 28 */	lwz r0, 0x28(r3)
/* 800F4EB8  7C 7E 1B 78 */	mr r30, r3
/* 800F4EBC  2C 00 00 00 */	cmpwi r0, 0
/* 800F4EC0  41 82 00 3C */	beq 0x3c
/* 800F4EC4  7F 23 CB 78 */	mr r3, r25
/* 800F4EC8  48 01 5D FD */	bl 0x15dfc
/* 800F4ECC  7C 7F 1B 78 */	mr r31, r3
/* 800F4ED0  7F 23 CB 78 */	mr r3, r25
/* 800F4ED4  48 01 5D E9 */	bl 0x15de8
/* 800F4ED8  81 9E 00 28 */	lwz r12, 0x28(r30)
/* 800F4EDC  7F 87 E3 78 */	mr r7, r28
/* 800F4EE0  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 800F4EE4  38 BA 00 10 */	addi r5, r26, 0x10
/* 800F4EE8  38 DB FF F0 */	addi r6, r27, -16
/* 800F4EEC  81 1E 00 38 */	lwz r8, 0x38(r30)
/* 800F4EF0  7D 89 03 A6 */	mtctr r12
/* 800F4EF4  4E 80 04 21 */	bctrl 
/* 800F4EF8  48 00 00 44 */	b 0x44
/* 800F4EFC  80 1D 00 1C */	lwz r0, 0x1c(r29)
/* 800F4F00  2C 00 00 00 */	cmpwi r0, 0
/* 800F4F04  41 82 00 38 */	beq 0x38
/* 800F4F08  7F 23 CB 78 */	mr r3, r25
/* 800F4F0C  48 01 5D B9 */	bl 0x15db8
/* 800F4F10  7C 7F 1B 78 */	mr r31, r3
/* 800F4F14  7F 23 CB 78 */	mr r3, r25
/* 800F4F18  48 01 5D A5 */	bl 0x15da4
/* 800F4F1C  81 9D 00 1C */	lwz r12, 0x1c(r29)
/* 800F4F20  7F 45 D3 78 */	mr r5, r26
/* 800F4F24  7F 66 DB 78 */	mr r6, r27
/* 800F4F28  7F 87 E3 78 */	mr r7, r28
/* 800F4F2C  57 E4 04 3E */	clrlwi r4, r31, 0x10
/* 800F4F30  81 1D 00 2C */	lwz r8, 0x2c(r29)
/* 800F4F34  7D 89 03 A6 */	mtctr r12
/* 800F4F38  4E 80 04 21 */	bctrl 
/* 800F4F3C  39 61 00 80 */	addi r11, r1, 0x80
/* 800F4F40  4B F2 C6 A5 */	bl -0xd395c
/* 800F4F44  80 01 00 84 */	lwz r0, 0x84(r1)
/* 800F4F48  7C 08 03 A6 */	mtlr r0
/* 800F4F4C  38 21 00 80 */	addi r1, r1, 0x80
/* 800F4F50  4E 80 00 20 */	blr 
/* 800F4F54  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 800F4F58  7C 08 02 A6 */	mflr r0
/* 800F4F5C  90 01 00 44 */	stw r0, 0x44(r1)
/* 800F4F60  39 61 00 40 */	addi r11, r1, 0x40
/* 800F4F64  4B F2 C6 3D */	bl -0xd39c4
/* 800F4F68  3F E0 80 2F */	lis r31, 0x802f
/* 800F4F6C  7C 9B 23 78 */	mr r27, r4
/* 800F4F70  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F4F74  7C BC 2B 78 */	mr r28, r5
/* 800F4F78  80 1F 00 28 */	lwz r0, 0x28(r31)
/* 800F4F7C  7C DD 33 78 */	mr r29, r6
/* 800F4F80  7C FE 3B 78 */	mr r30, r7
/* 800F4F84  2C 00 00 00 */	cmpwi r0, 0
/* 800F4F88  41 82 00 44 */	beq 0x44
/* 800F4F8C  7F 63 DB 78 */	mr r3, r27
/* 800F4F90  7F 84 E3 78 */	mr r4, r28
/* 800F4F94  38 A1 00 08 */	addi r5, r1, 8
/* 800F4F98  48 01 9A 29 */	bl 0x19a28
/* 800F4F9C  81 9F 00 28 */	lwz r12, 0x28(r31)
/* 800F4FA0  7F 63 DB 78 */	mr r3, r27
/* 800F4FA4  7F 84 E3 78 */	mr r4, r28
/* 800F4FA8  7F A5 EB 78 */	mr r5, r29
/* 800F4FAC  7F C6 F3 78 */	mr r6, r30
/* 800F4FB0  80 FF 00 2C */	lwz r7, 0x2c(r31)
/* 800F4FB4  7D 89 03 A6 */	mtctr r12
/* 800F4FB8  4E 80 04 21 */	bctrl 
/* 800F4FBC  7C 03 00 D0 */	neg r0, r3
/* 800F4FC0  7C 00 1B 78 */	or r0, r0, r3
/* 800F4FC4  54 03 0F FE */	srwi r3, r0, 0x1f
/* 800F4FC8  48 00 00 08 */	b 0x8
/* 800F4FCC  38 60 00 00 */	li r3, 0
/* 800F4FD0  39 61 00 40 */	addi r11, r1, 0x40
/* 800F4FD4  4B F2 C6 19 */	bl -0xd39e8
/* 800F4FD8  80 01 00 44 */	lwz r0, 0x44(r1)
/* 800F4FDC  7C 08 03 A6 */	mtlr r0
/* 800F4FE0  38 21 00 40 */	addi r1, r1, 0x40
/* 800F4FE4  4E 80 00 20 */	blr 
/* 800F4FE8  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 800F4FEC  7C 08 02 A6 */	mflr r0
/* 800F4FF0  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 800F4FF4  39 61 00 A0 */	addi r11, r1, 0xa0
/* 800F4FF8  4B F2 C5 A1 */	bl -0xd3a60
/* 800F4FFC  7C BA 2B 78 */	mr r26, r5
/* 800F5000  3F E0 80 2F */	lis r31, 0x802f
/* 800F5004  7C DB 33 78 */	mr r27, r6
/* 800F5008  7C 99 23 78 */	mr r25, r4
/* 800F500C  7C FC 3B 78 */	mr r28, r7
/* 800F5010  7D 1D 43 78 */	mr r29, r8
/* 800F5014  7D 3E 4B 78 */	mr r30, r9
/* 800F5018  7F 43 D3 78 */	mr r3, r26
/* 800F501C  7F 64 DB 78 */	mr r4, r27
/* 800F5020  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F5024  38 A1 00 24 */	addi r5, r1, 0x24
/* 800F5028  48 01 99 99 */	bl 0x19998
/* 800F502C  2C 1E 00 10 */	cmpwi r30, 0x10
/* 800F5030  41 80 00 90 */	blt 0x90
/* 800F5034  7F A4 EB 78 */	mr r4, r29
/* 800F5038  38 61 00 3C */	addi r3, r1, 0x3c
/* 800F503C  38 A0 00 10 */	li r5, 0x10
/* 800F5040  4B F1 0E F5 */	bl -0xef10c
/* 800F5044  93 41 00 18 */	stw r26, 0x18(r1)
/* 800F5048  38 81 00 18 */	addi r4, r1, 0x18
/* 800F504C  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5050  B3 61 00 1C */	sth r27, 0x1c(r1)
/* 800F5054  93 21 00 20 */	stw r25, 0x20(r1)
/* 800F5058  4B FF A4 89 */	bl -0x5b78
/* 800F505C  3C A0 80 0F */	lis r5, 0x800f
/* 800F5060  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F5064  38 81 00 3C */	addi r4, r1, 0x3c
/* 800F5068  38 C0 00 00 */	li r6, 0
/* 800F506C  38 A5 48 A4 */	addi r5, r5, 0x48a4
/* 800F5070  38 E0 00 00 */	li r7, 0
/* 800F5074  4B FF A9 7D */	bl -0x5684
/* 800F5078  2C 03 FF FF */	cmpwi r3, -1
/* 800F507C  41 82 00 44 */	beq 0x44
/* 800F5080  3C 60 80 0F */	lis r3, 0x800f
/* 800F5084  3C E0 80 0F */	lis r7, 0x800f
/* 800F5088  3C C0 80 0F */	lis r6, 0x800f
/* 800F508C  3C A0 80 0F */	lis r5, 0x800f
/* 800F5090  38 63 49 AC */	addi r3, r3, 0x49ac
/* 800F5094  38 E7 4A FC */	addi r7, r7, 0x4afc
/* 800F5098  38 C6 4D 28 */	addi r6, r6, 0x4d28
/* 800F509C  38 A5 4E 24 */	addi r5, r5, 0x4e24
/* 800F50A0  90 61 00 10 */	stw r3, 0x10(r1)
/* 800F50A4  38 81 00 08 */	addi r4, r1, 8
/* 800F50A8  80 61 00 20 */	lwz r3, 0x20(r1)
/* 800F50AC  90 E1 00 08 */	stw r7, 8(r1)
/* 800F50B0  90 C1 00 14 */	stw r6, 0x14(r1)
/* 800F50B4  90 A1 00 0C */	stw r5, 0xc(r1)
/* 800F50B8  48 01 58 FD */	bl 0x158fc
/* 800F50BC  48 00 00 70 */	b 0x70
/* 800F50C0  80 1F 00 20 */	lwz r0, 0x20(r31)
/* 800F50C4  2C 00 00 00 */	cmpwi r0, 0
/* 800F50C8  41 82 00 3C */	beq 0x3c
/* 800F50CC  7F 43 D3 78 */	mr r3, r26
/* 800F50D0  7F 64 DB 78 */	mr r4, r27
/* 800F50D4  38 A1 00 24 */	addi r5, r1, 0x24
/* 800F50D8  48 01 98 E9 */	bl 0x198e8
/* 800F50DC  81 9F 00 20 */	lwz r12, 0x20(r31)
/* 800F50E0  7F 43 D3 78 */	mr r3, r26
/* 800F50E4  7F 64 DB 78 */	mr r4, r27
/* 800F50E8  7F 85 E3 78 */	mr r5, r28
/* 800F50EC  7F A6 EB 78 */	mr r6, r29
/* 800F50F0  7F C7 F3 78 */	mr r7, r30
/* 800F50F4  81 1F 00 2C */	lwz r8, 0x2c(r31)
/* 800F50F8  7D 89 03 A6 */	mtctr r12
/* 800F50FC  4E 80 04 21 */	bctrl 
/* 800F5100  48 00 00 2C */	b 0x2c
/* 800F5104  7F 23 CB 78 */	mr r3, r25
/* 800F5108  38 80 00 00 */	li r4, 0
/* 800F510C  38 A0 00 00 */	li r5, 0
/* 800F5110  48 01 58 A9 */	bl 0x158a8
/* 800F5114  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5118  4B FF A3 91 */	bl -0x5c70
/* 800F511C  7C 64 1B 78 */	mr r4, r3
/* 800F5120  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5124  38 84 FF FF */	addi r4, r4, -1
/* 800F5128  4B FF A6 5D */	bl -0x59a4
/* 800F512C  39 61 00 A0 */	addi r11, r1, 0xa0
/* 800F5130  4B F2 C4 B5 */	bl -0xd3b4c
/* 800F5134  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 800F5138  7C 08 03 A6 */	mtlr r0
/* 800F513C  38 21 00 A0 */	addi r1, r1, 0xa0
/* 800F5140  4E 80 00 20 */	blr 
/* 800F5144  3C 60 80 2F */	lis r3, 0x802f
/* 800F5148  38 63 24 40 */	addi r3, r3, 0x2440
/* 800F514C  80 63 00 0C */	lwz r3, 0xc(r3)
/* 800F5150  4E 80 00 20 */	blr 
/* 800F5154  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 800F5158  7C 08 02 A6 */	mflr r0
/* 800F515C  2C 04 00 00 */	cmpwi r4, 0
/* 800F5160  90 01 00 34 */	stw r0, 0x34(r1)
/* 800F5164  81 61 00 38 */	lwz r11, 0x38(r1)
/* 800F5168  93 E1 00 2C */	stw r31, 0x2c(r1)
/* 800F516C  80 01 00 3C */	lwz r0, 0x3c(r1)
/* 800F5170  93 C1 00 28 */	stw r30, 0x28(r1)
/* 800F5174  3B C0 05 DC */	li r30, 0x5dc
/* 800F5178  93 A1 00 24 */	stw r29, 0x24(r1)
/* 800F517C  3F A0 80 2F */	lis r29, 0x802f
/* 800F5180  3B BD 24 40 */	addi r29, r29, 0x2440
/* 800F5184  93 81 00 20 */	stw r28, 0x20(r1)
/* 800F5188  83 81 00 40 */	lwz r28, 0x40(r1)
/* 800F518C  41 82 00 08 */	beq 0x8
/* 800F5190  7C 9E 23 78 */	mr r30, r4
/* 800F5194  2C 05 00 00 */	cmpwi r5, 0
/* 800F5198  3B E0 05 B4 */	li r31, 0x5b4
/* 800F519C  41 82 00 08 */	beq 0x8
/* 800F51A0  7C BF 2B 78 */	mr r31, r5
/* 800F51A4  90 DD 00 24 */	stw r6, 0x24(r29)
/* 800F51A8  7C 64 1B 78 */	mr r4, r3
/* 800F51AC  38 A1 00 08 */	addi r5, r1, 8
/* 800F51B0  38 60 00 00 */	li r3, 0
/* 800F51B4  91 7D 00 28 */	stw r11, 0x28(r29)
/* 800F51B8  90 FD 00 10 */	stw r7, 0x10(r29)
/* 800F51BC  91 1D 00 14 */	stw r8, 0x14(r29)
/* 800F51C0  91 3D 00 18 */	stw r9, 0x18(r29)
/* 800F51C4  91 5D 00 1C */	stw r10, 0x1c(r29)
/* 800F51C8  90 1D 00 20 */	stw r0, 0x20(r29)
/* 800F51CC  48 01 97 F5 */	bl 0x197f4
/* 800F51D0  3C E0 80 0F */	lis r7, 0x800f
/* 800F51D4  7F A3 EB 78 */	mr r3, r29
/* 800F51D8  7F E5 FB 78 */	mr r5, r31
/* 800F51DC  7F C6 F3 78 */	mr r6, r30
/* 800F51E0  38 81 00 08 */	addi r4, r1, 8
/* 800F51E4  38 E7 49 0C */	addi r7, r7, 0x490c
/* 800F51E8  48 01 57 31 */	bl 0x15730
/* 800F51EC  2C 03 00 00 */	cmpwi r3, 0
/* 800F51F0  41 82 00 0C */	beq 0xc
/* 800F51F4  38 60 00 03 */	li r3, 3
/* 800F51F8  48 00 00 B0 */	b 0xb0
/* 800F51FC  38 60 00 0C */	li r3, 0xc
/* 800F5200  38 80 00 01 */	li r4, 1
/* 800F5204  38 A0 00 00 */	li r5, 0
/* 800F5208  4B FF A1 71 */	bl -0x5e90
/* 800F520C  2C 03 00 00 */	cmpwi r3, 0
/* 800F5210  90 7D 00 04 */	stw r3, 4(r29)
/* 800F5214  40 82 00 0C */	bne 0xc
/* 800F5218  38 60 00 01 */	li r3, 1
/* 800F521C  48 00 00 8C */	b 0x8c
/* 800F5220  3C A0 80 0F */	lis r5, 0x800f
/* 800F5224  38 60 00 3C */	li r3, 0x3c
/* 800F5228  38 A5 48 9C */	addi r5, r5, 0x489c
/* 800F522C  38 80 00 01 */	li r4, 1
/* 800F5230  4B FF A1 49 */	bl -0x5eb8
/* 800F5234  2C 03 00 00 */	cmpwi r3, 0
/* 800F5238  90 7D 00 08 */	stw r3, 8(r29)
/* 800F523C  40 82 00 0C */	bne 0xc
/* 800F5240  38 60 00 01 */	li r3, 1
/* 800F5244  48 00 00 64 */	b 0x64
/* 800F5248  3C 80 80 0F */	lis r4, 0x800f
/* 800F524C  80 7D 00 00 */	lwz r3, 0(r29)
/* 800F5250  38 84 4F 54 */	addi r4, r4, 0x4f54
/* 800F5254  48 01 5A A9 */	bl 0x15aa8
/* 800F5258  3C 80 80 0F */	lis r4, 0x800f
/* 800F525C  80 7D 00 00 */	lwz r3, 0(r29)
/* 800F5260  38 84 4F E8 */	addi r4, r4, 0x4fe8
/* 800F5264  48 01 57 4D */	bl 0x1574c
/* 800F5268  80 7D 00 00 */	lwz r3, 0(r29)
/* 800F526C  48 01 5A 61 */	bl 0x15a60
/* 800F5270  90 7D 00 34 */	stw r3, 0x34(r29)
/* 800F5274  80 7D 00 00 */	lwz r3, 0(r29)
/* 800F5278  48 01 5A 5D */	bl 0x15a5c
/* 800F527C  38 80 00 00 */	li r4, 0
/* 800F5280  38 00 00 01 */	li r0, 1
/* 800F5284  2C 1C 00 00 */	cmpwi r28, 0
/* 800F5288  B0 7D 00 38 */	sth r3, 0x38(r29)
/* 800F528C  90 9D 00 30 */	stw r4, 0x30(r29)
/* 800F5290  90 1D 00 0C */	stw r0, 0xc(r29)
/* 800F5294  41 82 00 0C */	beq 0xc
/* 800F5298  93 9D 00 2C */	stw r28, 0x2c(r29)
/* 800F529C  48 00 00 08 */	b 0x8
/* 800F52A0  90 9D 00 2C */	stw r4, 0x2c(r29)
/* 800F52A4  38 60 00 00 */	li r3, 0
/* 800F52A8  80 01 00 34 */	lwz r0, 0x34(r1)
/* 800F52AC  83 E1 00 2C */	lwz r31, 0x2c(r1)
/* 800F52B0  83 C1 00 28 */	lwz r30, 0x28(r1)
/* 800F52B4  83 A1 00 24 */	lwz r29, 0x24(r1)
/* 800F52B8  83 81 00 20 */	lwz r28, 0x20(r1)
/* 800F52BC  7C 08 03 A6 */	mtlr r0
/* 800F52C0  38 21 00 30 */	addi r1, r1, 0x30
/* 800F52C4  4E 80 00 20 */	blr 
/* 800F52C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F52CC  7C 08 02 A6 */	mflr r0
/* 800F52D0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F52D4  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F52D8  3F E0 80 2F */	lis r31, 0x802f
/* 800F52DC  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F52E0  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F52E4  93 C1 00 18 */	stw r30, 0x18(r1)
/* 800F52E8  7C BE 2B 78 */	mr r30, r5
/* 800F52EC  2C 00 00 00 */	cmpwi r0, 0
/* 800F52F0  40 82 00 14 */	bne 0x14
/* 800F52F4  38 00 00 03 */	li r0, 3
/* 800F52F8  38 60 00 0B */	li r3, 0xb
/* 800F52FC  90 05 00 00 */	stw r0, 0(r5)
/* 800F5300  48 00 00 5C */	b 0x5c
/* 800F5304  90 61 00 08 */	stw r3, 8(r1)
/* 800F5308  3C A0 80 0F */	lis r5, 0x800f
/* 800F530C  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5310  38 A5 48 BC */	addi r5, r5, 0x48bc
/* 800F5314  B0 81 00 0C */	sth r4, 0xc(r1)
/* 800F5318  38 81 00 08 */	addi r4, r1, 8
/* 800F531C  38 C0 00 00 */	li r6, 0
/* 800F5320  38 E0 00 00 */	li r7, 0
/* 800F5324  4B FF A6 CD */	bl -0x5934
/* 800F5328  2C 03 FF FF */	cmpwi r3, -1
/* 800F532C  7C 64 1B 78 */	mr r4, r3
/* 800F5330  40 82 00 14 */	bne 0x14
/* 800F5334  38 00 00 03 */	li r0, 3
/* 800F5338  38 60 00 00 */	li r3, 0
/* 800F533C  90 1E 00 00 */	stw r0, 0(r30)
/* 800F5340  48 00 00 1C */	b 0x1c
/* 800F5344  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5348  4B FF A1 69 */	bl -0x5e98
/* 800F534C  80 63 00 08 */	lwz r3, 8(r3)
/* 800F5350  48 01 59 39 */	bl 0x15938
/* 800F5354  90 7E 00 00 */	stw r3, 0(r30)
/* 800F5358  38 60 00 00 */	li r3, 0
/* 800F535C  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F5360  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F5364  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 800F5368  7C 08 03 A6 */	mtlr r0
/* 800F536C  38 21 00 20 */	addi r1, r1, 0x20
/* 800F5370  4E 80 00 20 */	blr 
/* 800F5374  94 21 FF 60 */	stwu r1, -0xa0(r1)
/* 800F5378  7C 08 02 A6 */	mflr r0
/* 800F537C  90 01 00 A4 */	stw r0, 0xa4(r1)
/* 800F5380  39 61 00 A0 */	addi r11, r1, 0xa0
/* 800F5384  4B F2 C2 1D */	bl -0xd3de4
/* 800F5388  3F C0 80 2F */	lis r30, 0x802f
/* 800F538C  7C 7B 1B 78 */	mr r27, r3
/* 800F5390  3B DE 24 40 */	addi r30, r30, 0x2440
/* 800F5394  7C 9C 23 78 */	mr r28, r4
/* 800F5398  80 1E 00 0C */	lwz r0, 0xc(r30)
/* 800F539C  7C BD 2B 78 */	mr r29, r5
/* 800F53A0  7C DF 33 78 */	mr r31, r6
/* 800F53A4  2C 00 00 00 */	cmpwi r0, 0
/* 800F53A8  40 82 00 0C */	bne 0xc
/* 800F53AC  38 60 00 03 */	li r3, 3
/* 800F53B0  48 00 01 B8 */	b 0x1b8
/* 800F53B4  2C 03 00 00 */	cmpwi r3, 0
/* 800F53B8  41 82 00 0C */	beq 0xc
/* 800F53BC  2C 04 00 00 */	cmpwi r4, 0
/* 800F53C0  40 82 00 0C */	bne 0xc
/* 800F53C4  38 60 00 0A */	li r3, 0xa
/* 800F53C8  48 00 01 A0 */	b 0x1a0
/* 800F53CC  90 61 00 20 */	stw r3, 0x20(r1)
/* 800F53D0  3C A0 80 0F */	lis r5, 0x800f
/* 800F53D4  80 7E 00 04 */	lwz r3, 4(r30)
/* 800F53D8  38 A5 48 BC */	addi r5, r5, 0x48bc
/* 800F53DC  B0 81 00 24 */	sth r4, 0x24(r1)
/* 800F53E0  38 81 00 20 */	addi r4, r1, 0x20
/* 800F53E4  38 C0 00 00 */	li r6, 0
/* 800F53E8  38 E0 00 00 */	li r7, 0
/* 800F53EC  4B FF A6 05 */	bl -0x59fc
/* 800F53F0  2C 03 FF FF */	cmpwi r3, -1
/* 800F53F4  7C 64 1B 78 */	mr r4, r3
/* 800F53F8  41 82 00 80 */	beq 0x80
/* 800F53FC  80 7E 00 04 */	lwz r3, 4(r30)
/* 800F5400  4B FF A0 B1 */	bl -0x5f50
/* 800F5404  7C 7F 1B 78 */	mr r31, r3
/* 800F5408  80 63 00 08 */	lwz r3, 8(r3)
/* 800F540C  48 01 58 7D */	bl 0x1587c
/* 800F5410  2C 03 00 01 */	cmpwi r3, 1
/* 800F5414  40 82 00 0C */	bne 0xc
/* 800F5418  38 60 00 05 */	li r3, 5
/* 800F541C  48 00 01 4C */	b 0x14c
/* 800F5420  2C 03 00 00 */	cmpwi r3, 0
/* 800F5424  40 82 01 40 */	bne 0x140
/* 800F5428  7F A4 EB 78 */	mr r4, r29
/* 800F542C  38 61 00 44 */	addi r3, r1, 0x44
/* 800F5430  38 A0 00 10 */	li r5, 0x10
/* 800F5434  4B F1 0B 01 */	bl -0xef500
/* 800F5438  3C A0 80 0F */	lis r5, 0x800f
/* 800F543C  80 7E 00 08 */	lwz r3, 8(r30)
/* 800F5440  38 81 00 44 */	addi r4, r1, 0x44
/* 800F5444  38 C0 00 00 */	li r6, 0
/* 800F5448  38 A5 48 A4 */	addi r5, r5, 0x48a4
/* 800F544C  38 E0 00 00 */	li r7, 0
/* 800F5450  4B FF A5 A1 */	bl -0x5a60
/* 800F5454  2C 03 FF FF */	cmpwi r3, -1
/* 800F5458  7C 64 1B 78 */	mr r4, r3
/* 800F545C  41 82 01 08 */	beq 0x108
/* 800F5460  80 7E 00 08 */	lwz r3, 8(r30)
/* 800F5464  4B FF A0 4D */	bl -0x5fb4
/* 800F5468  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800F546C  7F E4 FB 78 */	mr r4, r31
/* 800F5470  4B FF A0 71 */	bl -0x5f90
/* 800F5474  48 00 00 F0 */	b 0xf0
/* 800F5478  7F 63 DB 78 */	mr r3, r27
/* 800F547C  7F 84 E3 78 */	mr r4, r28
/* 800F5480  38 A1 00 2C */	addi r5, r1, 0x2c
/* 800F5484  48 01 95 3D */	bl 0x1953c
/* 800F5488  3C 60 80 0F */	lis r3, 0x800f
/* 800F548C  3C 80 80 0F */	lis r4, 0x800f
/* 800F5490  3C E0 80 0F */	lis r7, 0x800f
/* 800F5494  3D 60 80 0F */	lis r11, 0x800f
/* 800F5498  38 63 49 AC */	addi r3, r3, 0x49ac
/* 800F549C  38 84 4A FC */	addi r4, r4, 0x4afc
/* 800F54A0  38 E7 4D 28 */	addi r7, r7, 0x4d28
/* 800F54A4  39 6B 4E 24 */	addi r11, r11, 0x4e24
/* 800F54A8  90 61 00 18 */	stw r3, 0x18(r1)
/* 800F54AC  7F A6 EB 78 */	mr r6, r29
/* 800F54B0  80 7E 00 00 */	lwz r3, 0(r30)
/* 800F54B4  7F E8 FB 78 */	mr r8, r31
/* 800F54B8  90 81 00 10 */	stw r4, 0x10(r1)
/* 800F54BC  38 81 00 28 */	addi r4, r1, 0x28
/* 800F54C0  38 A1 00 2C */	addi r5, r1, 0x2c
/* 800F54C4  39 21 00 10 */	addi r9, r1, 0x10
/* 800F54C8  90 E1 00 1C */	stw r7, 0x1c(r1)
/* 800F54CC  38 E0 00 10 */	li r7, 0x10
/* 800F54D0  39 40 00 00 */	li r10, 0
/* 800F54D4  91 61 00 14 */	stw r11, 0x14(r1)
/* 800F54D8  48 01 54 E5 */	bl 0x154e4
/* 800F54DC  80 7E 00 04 */	lwz r3, 4(r30)
/* 800F54E0  38 81 00 20 */	addi r4, r1, 0x20
/* 800F54E4  4B FF 9F FD */	bl -0x6004
/* 800F54E8  7F A4 EB 78 */	mr r4, r29
/* 800F54EC  38 61 00 44 */	addi r3, r1, 0x44
/* 800F54F0  38 A0 00 10 */	li r5, 0x10
/* 800F54F4  4B F1 0A 41 */	bl -0xef5c0
/* 800F54F8  3C A0 80 0F */	lis r5, 0x800f
/* 800F54FC  80 7E 00 08 */	lwz r3, 8(r30)
/* 800F5500  38 81 00 44 */	addi r4, r1, 0x44
/* 800F5504  38 C0 00 00 */	li r6, 0
/* 800F5508  38 A5 48 A4 */	addi r5, r5, 0x48a4
/* 800F550C  38 E0 00 00 */	li r7, 0
/* 800F5510  4B FF A4 E1 */	bl -0x5b20
/* 800F5514  2C 03 FF FF */	cmpwi r3, -1
/* 800F5518  7C 7F 1B 78 */	mr r31, r3
/* 800F551C  41 82 00 3C */	beq 0x3c
/* 800F5520  80 7E 00 04 */	lwz r3, 4(r30)
/* 800F5524  4B FF 9F 85 */	bl -0x607c
/* 800F5528  7C 64 1B 78 */	mr r4, r3
/* 800F552C  80 7E 00 04 */	lwz r3, 4(r30)
/* 800F5530  38 84 FF FF */	addi r4, r4, -1
/* 800F5534  4B FF 9F 7D */	bl -0x6084
/* 800F5538  90 61 00 08 */	stw r3, 8(r1)
/* 800F553C  7F E4 FB 78 */	mr r4, r31
/* 800F5540  80 7E 00 08 */	lwz r3, 8(r30)
/* 800F5544  4B FF 9F 6D */	bl -0x6094
/* 800F5548  80 63 00 20 */	lwz r3, 0x20(r3)
/* 800F554C  38 81 00 08 */	addi r4, r1, 8
/* 800F5550  4B FF 9F 91 */	bl -0x6070
/* 800F5554  48 00 00 10 */	b 0x10
/* 800F5558  80 7E 00 30 */	lwz r3, 0x30(r30)
/* 800F555C  38 03 00 01 */	addi r0, r3, 1
/* 800F5560  90 1E 00 30 */	stw r0, 0x30(r30)
/* 800F5564  38 60 00 00 */	li r3, 0
/* 800F5568  39 61 00 A0 */	addi r11, r1, 0xa0
/* 800F556C  4B F2 C0 81 */	bl -0xd3f80
/* 800F5570  80 01 00 A4 */	lwz r0, 0xa4(r1)
/* 800F5574  7C 08 03 A6 */	mtlr r0
/* 800F5578  38 21 00 A0 */	addi r1, r1, 0xa0
/* 800F557C  4E 80 00 20 */	blr 
/* 800F5580  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800F5584  7C 08 02 A6 */	mflr r0
/* 800F5588  90 01 00 54 */	stw r0, 0x54(r1)
/* 800F558C  39 61 00 50 */	addi r11, r1, 0x50
/* 800F5590  4B F2 C0 05 */	bl -0xd3ffc
/* 800F5594  3F E0 80 2F */	lis r31, 0x802f
/* 800F5598  7C 78 1B 78 */	mr r24, r3
/* 800F559C  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F55A0  7C 9D 23 78 */	mr r29, r4
/* 800F55A4  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F55A8  7C B9 2B 78 */	mr r25, r5
/* 800F55AC  7C DA 33 78 */	mr r26, r6
/* 800F55B0  7C FB 3B 78 */	mr r27, r7
/* 800F55B4  2C 00 00 00 */	cmpwi r0, 0
/* 800F55B8  7D 1C 43 78 */	mr r28, r8
/* 800F55BC  40 82 00 0C */	bne 0xc
/* 800F55C0  38 60 00 03 */	li r3, 3
/* 800F55C4  48 00 00 E8 */	b 0xe8
/* 800F55C8  88 05 00 00 */	lbz r0, 0(r5)
/* 800F55CC  7F 7E DB 78 */	mr r30, r27
/* 800F55D0  7C 00 07 75 */	extsb. r0, r0
/* 800F55D4  41 82 00 08 */	beq 0x8
/* 800F55D8  3B C7 00 10 */	addi r30, r7, 0x10
/* 800F55DC  90 61 00 08 */	stw r3, 8(r1)
/* 800F55E0  3C A0 80 0F */	lis r5, 0x800f
/* 800F55E4  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F55E8  38 A5 48 BC */	addi r5, r5, 0x48bc
/* 800F55EC  B0 81 00 0C */	sth r4, 0xc(r1)
/* 800F55F0  38 81 00 08 */	addi r4, r1, 8
/* 800F55F4  38 C0 00 00 */	li r6, 0
/* 800F55F8  38 E0 00 00 */	li r7, 0
/* 800F55FC  4B FF A3 F5 */	bl -0x5c0c
/* 800F5600  2C 03 FF FF */	cmpwi r3, -1
/* 800F5604  7C 64 1B 78 */	mr r4, r3
/* 800F5608  40 82 00 1C */	bne 0x1c
/* 800F560C  7F 03 C3 78 */	mr r3, r24
/* 800F5610  7F A4 EB 78 */	mr r4, r29
/* 800F5614  38 A1 00 14 */	addi r5, r1, 0x14
/* 800F5618  48 01 93 A9 */	bl 0x193a8
/* 800F561C  38 60 00 04 */	li r3, 4
/* 800F5620  48 00 00 8C */	b 0x8c
/* 800F5624  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5628  4B FF 9E 89 */	bl -0x6178
/* 800F562C  7C 7F 1B 78 */	mr r31, r3
/* 800F5630  80 63 00 08 */	lwz r3, 8(r3)
/* 800F5634  48 01 56 A9 */	bl 0x156a8
/* 800F5638  7C 1E 18 00 */	cmpw r30, r3
/* 800F563C  40 81 00 14 */	ble 0x14
/* 800F5640  2C 1C 00 00 */	cmpwi r28, 0
/* 800F5644  41 82 00 0C */	beq 0xc
/* 800F5648  38 60 00 0C */	li r3, 0xc
/* 800F564C  48 00 00 60 */	b 0x60
/* 800F5650  7F C3 F3 78 */	mr r3, r30
/* 800F5654  4B FF E2 0D */	bl -0x1df4
/* 800F5658  7C 7D 1B 78 */	mr r29, r3
/* 800F565C  7F 24 CB 78 */	mr r4, r25
/* 800F5660  38 A0 00 10 */	li r5, 0x10
/* 800F5664  4B F1 08 D1 */	bl -0xef730
/* 800F5668  7F 44 D3 78 */	mr r4, r26
/* 800F566C  7F 65 DB 78 */	mr r5, r27
/* 800F5670  38 7D 00 10 */	addi r3, r29, 0x10
/* 800F5674  4B F1 08 C1 */	bl -0xef740
/* 800F5678  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F567C  7F A4 EB 78 */	mr r4, r29
/* 800F5680  7F C5 F3 78 */	mr r5, r30
/* 800F5684  7F 86 E3 78 */	mr r6, r28
/* 800F5688  48 01 54 DD */	bl 0x154dc
/* 800F568C  7C 7F 1B 78 */	mr r31, r3
/* 800F5690  7F A3 EB 78 */	mr r3, r29
/* 800F5694  4B FF E1 F1 */	bl -0x1e10
/* 800F5698  2C 1F 00 00 */	cmpwi r31, 0
/* 800F569C  41 82 00 0C */	beq 0xc
/* 800F56A0  38 60 00 08 */	li r3, 8
/* 800F56A4  48 00 00 08 */	b 0x8
/* 800F56A8  38 60 00 00 */	li r3, 0
/* 800F56AC  39 61 00 50 */	addi r11, r1, 0x50
/* 800F56B0  4B F2 BF 31 */	bl -0xd40d0
/* 800F56B4  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800F56B8  7C 08 03 A6 */	mtlr r0
/* 800F56BC  38 21 00 50 */	addi r1, r1, 0x50
/* 800F56C0  4E 80 00 20 */	blr 
/* 800F56C4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F56C8  7C 08 02 A6 */	mflr r0
/* 800F56CC  3C 60 80 2F */	lis r3, 0x802f
/* 800F56D0  38 63 24 40 */	addi r3, r3, 0x2440
/* 800F56D4  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F56D8  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F56DC  2C 00 00 00 */	cmpwi r0, 0
/* 800F56E0  40 82 00 0C */	bne 0xc
/* 800F56E4  38 60 00 03 */	li r3, 3
/* 800F56E8  48 00 00 10 */	b 0x10
/* 800F56EC  80 63 00 00 */	lwz r3, 0(r3)
/* 800F56F0  48 01 52 75 */	bl 0x15274
/* 800F56F4  38 60 00 00 */	li r3, 0
/* 800F56F8  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F56FC  7C 08 03 A6 */	mtlr r0
/* 800F5700  38 21 00 10 */	addi r1, r1, 0x10
/* 800F5704  4E 80 00 20 */	blr 
/* 800F5708  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F570C  7C 08 02 A6 */	mflr r0
/* 800F5710  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F5714  93 E1 00 0C */	stw r31, 0xc(r1)
/* 800F5718  3F E0 80 2F */	lis r31, 0x802f
/* 800F571C  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F5720  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F5724  2C 00 00 00 */	cmpwi r0, 0
/* 800F5728  40 82 00 0C */	bne 0xc
/* 800F572C  38 60 00 03 */	li r3, 3
/* 800F5730  48 00 00 28 */	b 0x28
/* 800F5734  80 7F 00 00 */	lwz r3, 0(r31)
/* 800F5738  48 01 51 E9 */	bl 0x151e8
/* 800F573C  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F5740  4B FF 9C D5 */	bl -0x632c
/* 800F5744  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5748  4B FF 9C CD */	bl -0x6334
/* 800F574C  38 00 00 00 */	li r0, 0
/* 800F5750  38 60 00 00 */	li r3, 0
/* 800F5754  90 1F 00 0C */	stw r0, 0xc(r31)
/* 800F5758  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F575C  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 800F5760  7C 08 03 A6 */	mtlr r0
/* 800F5764  38 21 00 10 */	addi r1, r1, 0x10
/* 800F5768  4E 80 00 20 */	blr 
/* 800F576C  3C 60 80 2F */	lis r3, 0x802f
/* 800F5770  38 63 24 40 */	addi r3, r3, 0x2440
/* 800F5774  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F5778  2C 00 00 00 */	cmpwi r0, 0
/* 800F577C  41 82 00 0C */	beq 0xc
/* 800F5780  A0 63 00 38 */	lhz r3, 0x38(r3)
/* 800F5784  4E 80 00 20 */	blr 
/* 800F5788  38 60 00 00 */	li r3, 0
/* 800F578C  4E 80 00 20 */	blr 
/* 800F5790  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 800F5794  7C 08 02 A6 */	mflr r0
/* 800F5798  90 01 00 64 */	stw r0, 0x64(r1)
/* 800F579C  93 E1 00 5C */	stw r31, 0x5c(r1)
/* 800F57A0  3F E0 80 2F */	lis r31, 0x802f
/* 800F57A4  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F57A8  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F57AC  93 C1 00 58 */	stw r30, 0x58(r1)
/* 800F57B0  7D 5E 53 78 */	mr r30, r10
/* 800F57B4  2C 00 00 00 */	cmpwi r0, 0
/* 800F57B8  93 A1 00 54 */	stw r29, 0x54(r1)
/* 800F57BC  7C 9D 23 78 */	mr r29, r4
/* 800F57C0  40 82 00 0C */	bne 0xc
/* 800F57C4  38 60 00 03 */	li r3, 3
/* 800F57C8  48 00 00 98 */	b 0x98
/* 800F57CC  88 03 00 00 */	lbz r0, 0(r3)
/* 800F57D0  7C 00 07 75 */	extsb. r0, r0
/* 800F57D4  40 82 00 0C */	bne 0xc
/* 800F57D8  38 60 00 0A */	li r3, 0xa
/* 800F57DC  48 00 00 84 */	b 0x84
/* 800F57E0  88 04 00 00 */	lbz r0, 0(r4)
/* 800F57E4  7C 00 07 75 */	extsb. r0, r0
/* 800F57E8  40 82 00 0C */	bne 0xc
/* 800F57EC  38 60 00 0A */	li r3, 0xa
/* 800F57F0  48 00 00 70 */	b 0x70
/* 800F57F4  90 A1 00 3C */	stw r5, 0x3c(r1)
/* 800F57F8  7C 64 1B 78 */	mr r4, r3
/* 800F57FC  38 61 00 08 */	addi r3, r1, 8
/* 800F5800  38 A0 00 10 */	li r5, 0x10
/* 800F5804  90 E1 00 2C */	stw r7, 0x2c(r1)
/* 800F5808  90 C1 00 34 */	stw r6, 0x34(r1)
/* 800F580C  91 01 00 38 */	stw r8, 0x38(r1)
/* 800F5810  91 21 00 30 */	stw r9, 0x30(r1)
/* 800F5814  4B F1 07 21 */	bl -0xef8e0
/* 800F5818  7F A4 EB 78 */	mr r4, r29
/* 800F581C  38 61 00 18 */	addi r3, r1, 0x18
/* 800F5820  38 A0 00 10 */	li r5, 0x10
/* 800F5824  4B F1 07 11 */	bl -0xef8f0
/* 800F5828  38 60 00 04 */	li r3, 4
/* 800F582C  38 80 00 01 */	li r4, 1
/* 800F5830  38 A0 00 00 */	li r5, 0
/* 800F5834  4B FF 9B 45 */	bl -0x64bc
/* 800F5838  2C 03 00 00 */	cmpwi r3, 0
/* 800F583C  90 61 00 28 */	stw r3, 0x28(r1)
/* 800F5840  40 82 00 0C */	bne 0xc
/* 800F5844  38 60 00 01 */	li r3, 1
/* 800F5848  48 00 00 18 */	b 0x18
/* 800F584C  93 C1 00 40 */	stw r30, 0x40(r1)
/* 800F5850  38 81 00 08 */	addi r4, r1, 8
/* 800F5854  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F5858  4B FF 9C 89 */	bl -0x6378
/* 800F585C  38 60 00 00 */	li r3, 0
/* 800F5860  80 01 00 64 */	lwz r0, 0x64(r1)
/* 800F5864  83 E1 00 5C */	lwz r31, 0x5c(r1)
/* 800F5868  83 C1 00 58 */	lwz r30, 0x58(r1)
/* 800F586C  83 A1 00 54 */	lwz r29, 0x54(r1)
/* 800F5870  7C 08 03 A6 */	mtlr r0
/* 800F5874  38 21 00 60 */	addi r1, r1, 0x60
/* 800F5878  4E 80 00 20 */	blr 
/* 800F587C  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 800F5880  7C 08 02 A6 */	mflr r0
/* 800F5884  90 01 00 54 */	stw r0, 0x54(r1)
/* 800F5888  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 800F588C  3F E0 80 2F */	lis r31, 0x802f
/* 800F5890  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F5894  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F5898  2C 00 00 00 */	cmpwi r0, 0
/* 800F589C  40 82 00 0C */	bne 0xc
/* 800F58A0  38 60 00 03 */	li r3, 3
/* 800F58A4  48 00 00 64 */	b 0x64
/* 800F58A8  2C 03 00 00 */	cmpwi r3, 0
/* 800F58AC  41 82 00 10 */	beq 0x10
/* 800F58B0  88 03 00 00 */	lbz r0, 0(r3)
/* 800F58B4  7C 00 07 75 */	extsb. r0, r0
/* 800F58B8  40 82 00 0C */	bne 0xc
/* 800F58BC  38 60 00 0A */	li r3, 0xa
/* 800F58C0  48 00 00 48 */	b 0x48
/* 800F58C4  7C 64 1B 78 */	mr r4, r3
/* 800F58C8  38 61 00 18 */	addi r3, r1, 0x18
/* 800F58CC  38 A0 00 10 */	li r5, 0x10
/* 800F58D0  4B F1 06 65 */	bl -0xef99c
/* 800F58D4  3C A0 80 0F */	lis r5, 0x800f
/* 800F58D8  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F58DC  38 81 00 08 */	addi r4, r1, 8
/* 800F58E0  38 C0 00 00 */	li r6, 0
/* 800F58E4  38 A5 48 AC */	addi r5, r5, 0x48ac
/* 800F58E8  38 E0 00 00 */	li r7, 0
/* 800F58EC  4B FF A1 05 */	bl -0x5efc
/* 800F58F0  2C 03 FF FF */	cmpwi r3, -1
/* 800F58F4  7C 64 1B 78 */	mr r4, r3
/* 800F58F8  41 82 00 0C */	beq 0xc
/* 800F58FC  80 7F 00 08 */	lwz r3, 8(r31)
/* 800F5900  4B FF 9F 31 */	bl -0x60d0
/* 800F5904  38 60 00 00 */	li r3, 0
/* 800F5908  80 01 00 54 */	lwz r0, 0x54(r1)
/* 800F590C  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 800F5910  7C 08 03 A6 */	mtlr r0
/* 800F5914  38 21 00 50 */	addi r1, r1, 0x50
/* 800F5918  4E 80 00 20 */	blr 
/* 800F591C  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800F5920  7C 08 02 A6 */	mflr r0
/* 800F5924  3C 60 80 2F */	lis r3, 0x802f
/* 800F5928  38 63 24 40 */	addi r3, r3, 0x2440
/* 800F592C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800F5930  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F5934  2C 00 00 00 */	cmpwi r0, 0
/* 800F5938  40 82 00 0C */	bne 0xc
/* 800F593C  38 60 00 01 */	li r3, 1
/* 800F5940  48 00 00 14 */	b 0x14
/* 800F5944  80 63 00 08 */	lwz r3, 8(r3)
/* 800F5948  4B FF 9B 61 */	bl -0x64a0
/* 800F594C  7C 60 00 34 */	cntlzw r0, r3
/* 800F5950  54 03 D9 7E */	srwi r3, r0, 5
/* 800F5954  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800F5958  7C 08 03 A6 */	mtlr r0
/* 800F595C  38 21 00 10 */	addi r1, r1, 0x10
/* 800F5960  4E 80 00 20 */	blr 
/* 800F5964  3C 60 80 2F */	lis r3, 0x802f
/* 800F5968  38 63 24 40 */	addi r3, r3, 0x2440
/* 800F596C  80 03 00 0C */	lwz r0, 0xc(r3)
/* 800F5970  2C 00 00 00 */	cmpwi r0, 0
/* 800F5974  40 82 00 0C */	bne 0xc
/* 800F5978  38 60 00 01 */	li r3, 1
/* 800F597C  4E 80 00 20 */	blr 
/* 800F5980  80 03 00 14 */	lwz r0, 0x14(r3)
/* 800F5984  2C 00 00 00 */	cmpwi r0, 0
/* 800F5988  40 82 00 4C */	bne 0x4c
/* 800F598C  80 03 00 20 */	lwz r0, 0x20(r3)
/* 800F5990  2C 00 00 00 */	cmpwi r0, 0
/* 800F5994  40 82 00 40 */	bne 0x40
/* 800F5998  80 03 00 10 */	lwz r0, 0x10(r3)
/* 800F599C  2C 00 00 00 */	cmpwi r0, 0
/* 800F59A0  40 82 00 34 */	bne 0x34
/* 800F59A4  80 03 00 24 */	lwz r0, 0x24(r3)
/* 800F59A8  2C 00 00 00 */	cmpwi r0, 0
/* 800F59AC  40 82 00 28 */	bne 0x28
/* 800F59B0  80 03 00 18 */	lwz r0, 0x18(r3)
/* 800F59B4  2C 00 00 00 */	cmpwi r0, 0
/* 800F59B8  40 82 00 1C */	bne 0x1c
/* 800F59BC  80 03 00 1C */	lwz r0, 0x1c(r3)
/* 800F59C0  2C 00 00 00 */	cmpwi r0, 0
/* 800F59C4  40 82 00 10 */	bne 0x10
/* 800F59C8  80 03 00 28 */	lwz r0, 0x28(r3)
/* 800F59CC  2C 00 00 00 */	cmpwi r0, 0
/* 800F59D0  41 82 00 0C */	beq 0xc
/* 800F59D4  38 60 00 00 */	li r3, 0
/* 800F59D8  4E 80 00 20 */	blr 
/* 800F59DC  38 60 00 01 */	li r3, 1
/* 800F59E0  4E 80 00 20 */	blr 
/* 800F59E4  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800F59E8  7C 08 02 A6 */	mflr r0
/* 800F59EC  90 01 00 24 */	stw r0, 0x24(r1)
/* 800F59F0  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 800F59F4  3F E0 80 2F */	lis r31, 0x802f
/* 800F59F8  3B FF 24 40 */	addi r31, r31, 0x2440
/* 800F59FC  80 1F 00 0C */	lwz r0, 0xc(r31)
/* 800F5A00  2C 00 00 00 */	cmpwi r0, 0
/* 800F5A04  40 82 00 0C */	bne 0xc
/* 800F5A08  38 60 00 00 */	li r3, 0
/* 800F5A0C  48 00 00 4C */	b 0x4c
/* 800F5A10  90 61 00 08 */	stw r3, 8(r1)
/* 800F5A14  3C A0 80 0F */	lis r5, 0x800f
/* 800F5A18  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5A1C  38 A5 48 BC */	addi r5, r5, 0x48bc
/* 800F5A20  B0 81 00 0C */	sth r4, 0xc(r1)
/* 800F5A24  38 81 00 08 */	addi r4, r1, 8
/* 800F5A28  38 C0 00 00 */	li r6, 0
/* 800F5A2C  38 E0 00 00 */	li r7, 0
/* 800F5A30  4B FF 9F C1 */	bl -0x6040
/* 800F5A34  2C 03 FF FF */	cmpwi r3, -1
/* 800F5A38  7C 64 1B 78 */	mr r4, r3
/* 800F5A3C  41 82 00 18 */	beq 0x18
/* 800F5A40  80 7F 00 04 */	lwz r3, 4(r31)
/* 800F5A44  4B FF 9A 6D */	bl -0x6594
/* 800F5A48  80 63 00 08 */	lwz r3, 8(r3)
/* 800F5A4C  48 01 52 99 */	bl 0x15298
/* 800F5A50  48 00 00 08 */	b 0x8
/* 800F5A54  38 60 00 00 */	li r3, 0
/* 800F5A58  80 01 00 24 */	lwz r0, 0x24(r1)
/* 800F5A5C  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 800F5A60  7C 08 03 A6 */	mtlr r0
/* 800F5A64  38 21 00 20 */	addi r1, r1, 0x20
/* 800F5A68  4E 80 00 20 */	blr 
