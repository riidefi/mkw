#include "eggCompress.hpp"

// Symbol: Comp_encodeSZS
// PAL: 0x802156ac..0x8021587c
MARK_BINARY_BLOB(Comp_encodeSZS, 0x802156ac, 0x8021587c);
asm UNKNOWN_FUNCTION(Comp_encodeSZS) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  srawi r6, r5, 0x10;
  li r10, 0x59;
  stw r0, 0x44(r1);
  srawi r0, r5, 8;
  li r9, 0x61;
  li r8, 0x7a;
  stmw r24, 0x20(r1);
  li r31, 0;
  li r7, 0x31;
  mr r24, r3;
  mr r25, r4;
  mr r26, r5;
  li r30, 0;
  li r27, 0x80;
  li r29, 0x10;
  li r28, 0x11;
  stb r10, 0(r4);
  stb r9, 1(r4);
  stb r8, 2(r4);
  stb r7, 3(r4);
  stb r31, 4(r4);
  stb r6, 5(r4);
  stb r0, 6(r4);
  stb r5, 7(r4);
  stb r31, 0x10(r4);
  b lbl_8021585c;
lbl_8021571c:
  mr r3, r24;
  mr r4, r30;
  mr r5, r26;
  addi r6, r1, 0x14;
  addi r7, r1, 0x10;
  bl unk_8021587c;
  lwz r0, 0x10(r1);
  cmpwi r0, 2;
  ble lbl_80215828;
  mr r3, r24;
  mr r5, r26;
  addi r4, r30, 1;
  addi r6, r1, 0xc;
  addi r7, r1, 8;
  bl unk_8021587c;
  lwz r3, 0x10(r1);
  lwz r0, 8(r1);
  addi r3, r3, 1;
  cmpw r3, r0;
  bge lbl_802157b0;
  lbzx r3, r25, r29;
  lbzx r0, r24, r30;
  addi r30, r30, 1;
  or r3, r3, r27;
  stbx r3, r25, r29;
  rlwinm. r27, r27, 0x1f, 0x19, 0x1f;
  stbx r0, r25, r28;
  addi r28, r28, 1;
  bne lbl_802157a0;
  stbx r31, r25, r28;
  mr r29, r28;
  li r27, 0x80;
  addi r28, r28, 1;
lbl_802157a0:
  lwz r3, 8(r1);
  lwz r0, 0xc(r1);
  stw r3, 0x10(r1);
  stw r0, 0x14(r1);
lbl_802157b0:
  lwz r0, 0x14(r1);
  lwz r4, 0x10(r1);
  subf r3, r0, r30;
  addi r3, r3, -1;
  cmpwi r4, 0x12;
  stw r3, 0x14(r1);
  bge lbl_802157f8;
  addi r0, r4, -2;
  add r4, r25, r28;
  slwi r0, r0, 0xc;
  or r0, r3, r0;
  stw r0, 0x14(r1);
  srawi r0, r0, 8;
  stbx r0, r25, r28;
  addi r28, r28, 2;
  lwz r0, 0x14(r1);
  stb r0, 1(r4);
  b lbl_8021581c;
lbl_802157f8:
  srawi r0, r3, 8;
  stbx r0, r25, r28;
  add r4, r25, r28;
  addi r28, r28, 3;
  lwz r0, 0x14(r1);
  stb r0, 1(r4);
  lwz r3, 0x10(r1);
  addi r0, r3, -18;
  stb r0, 2(r4);
lbl_8021581c:
  lwz r0, 0x10(r1);
  add r30, r30, r0;
  b lbl_80215844;
lbl_80215828:
  lbzx r3, r25, r29;
  lbzx r0, r24, r30;
  addi r30, r30, 1;
  or r3, r3, r27;
  stbx r3, r25, r29;
  stbx r0, r25, r28;
  addi r28, r28, 1;
lbl_80215844:
  rlwinm. r27, r27, 0x1f, 0x19, 0x1f;
  bne lbl_8021585c;
  stbx r31, r25, r28;
  mr r29, r28;
  li r27, 0x80;
  addi r28, r28, 1;
lbl_8021585c:
  cmpw r30, r26;
  blt lbl_8021571c;
  mr r3, r28;
  lmw r24, 0x20(r1);
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: unk_8021587c
// PAL: 0x8021587c..0x802159b8
MARK_BINARY_BLOB(unk_8021587c, 0x8021587c, 0x802159b8);
asm UNKNOWN_FUNCTION(unk_8021587c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  subf r8, r4, r5;
  srwi r5, r4, 0x1f;
  stw r0, 0x34(r1);
  li r0, 0x1000;
  subfc r0, r4, r0;
  cmpwi r8, 0x111;
  stmw r23, 0xc(r1);
  li r0, 0;
  subfe r5, r0, r5;
  mr r26, r3;
  addi r0, r4, -4096;
  mr r27, r4;
  mr r28, r6;
  mr r29, r7;
  and r31, r0, r5;
  li r30, 3;
  li r25, 0x111;
  bgt lbl_802158d0;
  mr r25, r8;
lbl_802158d0:
  cmpwi r25, 3;
  bge lbl_802158e8;
  li r0, 0;
  stw r0, 0(r7);
  stw r0, 0(r6);
  b lbl_802159a4;
lbl_802158e8:
  add r24, r3, r4;
  b lbl_80215954;
lbl_802158f0:
  add r6, r26, r31;
  add r5, r30, r3;
  subf r0, r30, r25;
  add r4, r24, r30;
  add r6, r6, r5;
  mtctr r0;
  cmpw r30, r25;
  bge lbl_80215930;
lbl_80215910:
  lbz r5, 0(r6);
  lbz r0, 0(r4);
  cmplw r5, r0;
  bne lbl_80215930;
  addi r6, r6, 1;
  addi r30, r30, 1;
  addi r4, r4, 1;
  bdnz lbl_80215910;
lbl_80215930:
  cmpw r30, r25;
  bne lbl_80215948;
  add r0, r31, r3;
  stw r0, 0(r28);
  stw r25, 0(r29);
  b lbl_802159a4;
lbl_80215948:
  add r23, r31, r3;
  addi r30, r30, 1;
  addi r31, r23, 1;
lbl_80215954:
  cmpw r31, r27;
  bge lbl_80215980;
  add r0, r27, r30;
  mr r3, r24;
  mr r4, r30;
  add r5, r26, r31;
  subf r6, r31, r0;
  bl unk_802159b8;
  subf r0, r31, r27;
  cmpw r3, r0;
  blt lbl_802158f0;
lbl_80215980:
  li r0, 3;
  stw r23, 0(r28);
  subfc r0, r30, r0;
  srwi r4, r30, 0x1f;
  li r3, 0;
  addi r0, r30, -1;
  subfe r3, r3, r4;
  and r0, r0, r3;
  stw r0, 0(r29);
lbl_802159a4:
  lmw r23, 0xc(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_802159b8
// PAL: 0x802159b8..0x80215aa8
MARK_BINARY_BLOB(unk_802159b8, 0x802159b8, 0x80215aa8);
asm UNKNOWN_FUNCTION(unk_802159b8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpw r4, r6;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  ble lbl_802159ec;
  mr r3, r6;
  b lbl_80215a8c;
lbl_802159ec:
  bl unk_80215aa8;
  add r4, r30, r29;
  lis r3, 0x8038;
  lbz r6, -1(r4);
  addi r8, r30, -1;
  addi r5, r3, 0x3510;
lbl_80215a04:
  lbzx r0, r31, r8;
  cmplw r6, r0;
  beq lbl_80215a20;
  rlwinm r0, r0, 1, 0x17, 0x1e;
  lhzx r0, r5, r0;
  add r8, r8, r0;
  b lbl_80215a04;
lbl_80215a20:
  addi r8, r8, -1;
  addi r9, r30, -2;
  b lbl_80215a4c;
lbl_80215a2c:
  rlwinm r0, r7, 1, 0x17, 0x1e;
  subf r3, r9, r30;
  lhzx r0, r5, r0;
  cmpw r3, r0;
  ble lbl_80215a44;
  mr r0, r3;
lbl_80215a44:
  add r8, r8, r0;
  b lbl_80215a04;
lbl_80215a4c:
  addi r0, r9, 1;
  add r4, r29, r9;
  add r3, r31, r8;
  mtctr r0;
  cmpwi r9, 0;
  blt lbl_80215a88;
lbl_80215a64:
  lbz r7, 0(r3);
  lbz r0, 0(r4);
  cmplw r7, r0;
  bne lbl_80215a2c;
  addi r8, r8, -1;
  addi r3, r3, -1;
  addi r9, r9, -1;
  addi r4, r4, -1;
  bdnz lbl_80215a64;
lbl_80215a88:
  addi r3, r8, 1;
lbl_80215a8c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80215aa8
// PAL: 0x80215aa8..0x80215cbc
MARK_BINARY_BLOB(unk_80215aa8, 0x80215aa8, 0x80215cbc);
asm UNKNOWN_FUNCTION(unk_80215aa8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  lis r5, 0x8038;
  li r0, 8;
  stw r31, 0x1c(r1);
  addi r5, r5, 0x3510;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mtctr r0;
lbl_80215ac8:
  sth r4, 0(r5);
  sth r4, 2(r5);
  sth r4, 4(r5);
  sth r4, 6(r5);
  sth r4, 8(r5);
  sth r4, 0xa(r5);
  sth r4, 0xc(r5);
  sth r4, 0xe(r5);
  sth r4, 0x10(r5);
  sth r4, 0x12(r5);
  sth r4, 0x14(r5);
  sth r4, 0x16(r5);
  sth r4, 0x18(r5);
  sth r4, 0x1a(r5);
  sth r4, 0x1c(r5);
  sth r4, 0x1e(r5);
  sth r4, 0x20(r5);
  sth r4, 0x22(r5);
  sth r4, 0x24(r5);
  sth r4, 0x26(r5);
  sth r4, 0x28(r5);
  sth r4, 0x2a(r5);
  sth r4, 0x2c(r5);
  sth r4, 0x2e(r5);
  sth r4, 0x30(r5);
  sth r4, 0x32(r5);
  sth r4, 0x34(r5);
  sth r4, 0x36(r5);
  sth r4, 0x38(r5);
  sth r4, 0x3a(r5);
  sth r4, 0x3c(r5);
  sth r4, 0x3e(r5);
  addi r5, r5, 0x40;
  bdnz lbl_80215ac8;
  cmpwi cr1, r4, 0;
  li r7, 0;
  ble cr1, lbl_80215ca8;
  cmpwi r4, 8;
  addi r6, r4, -8;
  ble lbl_80215c6c;
  li r8, 0;
  blt cr1, lbl_80215b84;
  lis r5, 0x8000;
  addi r0, r5, -2;
  cmpw r4, r0;
  bgt lbl_80215b84;
  li r8, 1;
lbl_80215b84:
  cmpwi r8, 0;
  beq lbl_80215c6c;
  addi r0, r6, 7;
  lis r5, 0x8038;
  srwi r0, r0, 3;
  addi r5, r5, 0x3510;
  mtctr r0;
  cmpwi r6, 0;
  ble lbl_80215c6c;
lbl_80215ba8:
  lbzx r9, r3, r7;
  add r6, r3, r7;
  subf r11, r7, r4;
  lbz r8, 1(r6);
  slwi r9, r9, 1;
  subfic r10, r7, -2;
  addi r11, r11, -1;
  addi r0, r7, 2;
  sthx r11, r5, r9;
  subf r9, r0, r4;
  lbz r0, 2(r6);
  slwi r8, r8, 1;
  add r10, r10, r4;
  sthx r10, r5, r8;
  lbz r8, 3(r6);
  slwi r10, r0, 1;
  addi r11, r9, -1;
  addi r0, r7, 3;
  subf r9, r0, r4;
  sthx r11, r5, r10;
  lbz r12, 4(r6);
  slwi r30, r8, 1;
  addi r0, r7, 4;
  addi r29, r9, -1;
  subf r31, r0, r4;
  lbz r10, 5(r6);
  addi r0, r7, 5;
  lbz r8, 6(r6);
  subf r11, r0, r4;
  sthx r29, r5, r30;
  addi r0, r7, 6;
  slwi r12, r12, 1;
  subf r9, r0, r4;
  lbz r0, 7(r6);
  addi r6, r7, 7;
  addi r31, r31, -1;
  subf r6, r6, r4;
  sthx r31, r5, r12;
  slwi r10, r10, 1;
  addi r11, r11, -1;
  sthx r11, r5, r10;
  slwi r8, r8, 1;
  addi r9, r9, -1;
  slwi r0, r0, 1;
  sthx r9, r5, r8;
  addi r6, r6, -1;
  addi r7, r7, 8;
  sthx r6, r5, r0;
  bdnz lbl_80215ba8;
lbl_80215c6c:
  lis r5, 0x8038;
  subf r0, r7, r4;
  addi r5, r5, 0x3510;
  add r3, r3, r7;
  mtctr r0;
  cmpw r7, r4;
  bge lbl_80215ca8;
lbl_80215c88:
  lbz r0, 0(r3);
  subf r6, r7, r4;
  addi r6, r6, -1;
  addi r7, r7, 1;
  slwi r0, r0, 1;
  addi r3, r3, 1;
  sthx r6, r5, r0;
  bdnz lbl_80215c88;
lbl_80215ca8:
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
