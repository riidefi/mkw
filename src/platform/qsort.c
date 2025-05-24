#include "stdlib.h"

#include <decomp.h>

// Symbol: qsort
// PAL: 0x80011b00..0x80011c70
MARK_BINARY_BLOB(qsort, 0x80011b00, 0x80011c70);
asm void qsort(void* base, size_t nitems, size_t size,
               int (*compar)(const void*, const void*)) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  cmplwi r4, 2;
  stw r0, 0x44(r1);
  stmw r19, 0xc(r1);
  mr r27, r3;
  mr r28, r5;
  mr r29, r6;
  blt lbl_80011c5c;
  srwi r7, r4, 1;
  slwi r0, r5, 1;
  addi r31, r7, 1;
  addi r6, r4, -1;
  addi r7, r31, -1;
  mr r30, r4;
  mullw r4, r5, r7;
  subf r25, r0, r5;
  mullw r0, r5, r6;
  add r23, r3, r4;
  mullw r26, r31, r5;
  add r22, r3, r0;
lbl_80011b54:
  cmplwi r31, 1;
  ble lbl_80011b6c;
  subf r26, r28, r26;
  subf r23, r28, r23;
  addi r31, r31, -1;
  b lbl_80011ba8;
lbl_80011b6c:
  addi r3, r22, -1;
  addi r4, r23, -1;
  addi r5, r28, 1;
  b lbl_80011b90;
lbl_80011b7c:
  lbz r6, 1(r4);
  lbz r0, 1(r3);
  stbu r0, 1(r4);
  extsb r6, r6;
  stbu r6, 1(r3);
lbl_80011b90:
  addic. r5, r5, -1;
  bne lbl_80011b7c;
  addi r30, r30, -1;
  cmplwi r30, 1;
  beq lbl_80011c5c;
  subf r22, r28, r22;
lbl_80011ba8:
  add r0, r26, r25;
  mr r24, r31;
  add r20, r27, r0;
  b lbl_80011c4c;
lbl_80011bb8:
  slwi r24, r24, 1;
  mr r21, r20;
  addi r0, r24, -1;
  mullw r0, r28, r0;
  cmplw r24, r30;
  add r20, r27, r0;
  bge lbl_80011bfc;
  add r19, r20, r28;
  mr r12, r29;
  mr r3, r20;
  mr r4, r19;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bge lbl_80011bfc;
  mr r20, r19;
  addi r24, r24, 1;
lbl_80011bfc:
  mr r12, r29;
  mr r3, r21;
  mr r4, r20;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bge lbl_80011b54;
  addi r3, r20, -1;
  addi r4, r21, -1;
  addi r5, r28, 1;
  b lbl_80011c44;
lbl_80011c28:
  lbz r6, 1(r4);
  lbz r0, 1(r3);
  stb r0, 1(r4);
  extsb r6, r6;
  addi r4, r4, 1;
  stb r6, 1(r3);
  addi r3, r3, 1;
lbl_80011c44:
  addic. r5, r5, -1;
  bne lbl_80011c28;
lbl_80011c4c:
  slwi r0, r24, 1;
  cmplw r0, r30;
  ble lbl_80011bb8;
  b lbl_80011b54;
lbl_80011c5c:
  lmw r19, 0xc(r1);
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}
