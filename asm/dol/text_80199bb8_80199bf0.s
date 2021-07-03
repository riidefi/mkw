
.include "macros.inc"

.section .text, "ax" # 0x80199BB8 - 0x80199BF0
/* 80199BB8  38 C2 98 C0 */	addi r6, r2, -26432
/* 80199BBC  38 00 00 00 */	li r0, 0
/* 80199BC0  90 C3 00 00 */	stw r6, 0(r3)
/* 80199BC4  90 83 00 04 */	stw r4, 4(r3)
/* 80199BC8  90 A3 00 08 */	stw r5, 8(r3)
/* 80199BCC  90 03 00 0C */	stw r0, 0xc(r3)
/* 80199BD0  4E 80 00 20 */	blr 
/* 80199BD4  38 00 00 00 */	li r0, 0
/* 80199BD8  38 A2 98 C8 */	addi r5, r2, -26424
/* 80199BDC  90 A3 00 00 */	stw r5, 0(r3)
/* 80199BE0  90 83 00 04 */	stw r4, 4(r3)
/* 80199BE4  90 03 00 08 */	stw r0, 8(r3)
/* 80199BE8  90 03 00 0C */	stw r0, 0xc(r3)
/* 80199BEC  4E 80 00 20 */	blr 
