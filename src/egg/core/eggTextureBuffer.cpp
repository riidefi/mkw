#include "eggTextureBuffer.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(unk_80214bd0);
extern UNKNOWN_FUNCTION(unk_8021805c);
extern UNKNOWN_FUNCTION(unk_80218178);
extern UNKNOWN_FUNCTION(__nw__FUl);
extern UNKNOWN_FUNCTION(__nwa__FUlPQ23EGG4Heapi);
}

// Symbol: unk_80242f1c
// PAL: 0x80242f1c..0x80242f90
MARK_BINARY_BLOB(unk_80242f1c, 0x80242f1c, 0x80242f90);
asm UNKNOWN_FUNCTION(unk_80242f1c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl unk_80214bd0;
  lbz r0, -0x5ca4(r13);
  addi r6, r13, -23716;
  stb r0, 0x15(r31);
  li r4, 0;
  lbz r0, 0x14(r31);
  li r3, 1;
  lbz r5, 1(r6);
  stb r5, 0x16(r31);
  ori r0, r0, 0x10;
  lbz r5, 2(r6);
  stb r5, 0x17(r31);
  lbz r5, 3(r6);
  stb r5, 0x18(r31);
  stb r4, 6(r31);
  stb r4, 7(r31);
  stb r3, 8(r31);
  stb r3, 9(r31);
  stb r0, 0x14(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80242f90
// PAL: 0x80242f90..0x80243080
MARK_BINARY_BLOB(unk_80242f90, 0x80242f90, 0x80243080);
asm UNKNOWN_FUNCTION(unk_80242f90) {
  // clang-format off
  nofralloc;
  lwz r6, 0x34(r3);
  li r0, 0;
  stw r0, 0x2c(r3);
  cmpwi r6, 0;
  beq lbl_8024301c;
  lwz r0, 0x2c(r6);
  cmpwi r0, 0;
  bne lbl_8024301c;
  lwz r5, 0x28(r3);
  lwz r4, 0x28(r6);
  lbz r0, 4(r3);
  add r4, r5, r4;
  stw r4, 0x28(r3);
  lwz r4, 0xc(r3);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  lwz r5, 0x28(r6);
  subf r4, r5, r4;
  stw r4, 0xc(r3);
  stb r0, 4(r3);
  lwz r4, -0x5c94(r13);
  lwz r5, 0x34(r6);
  cmpwi r4, 0;
  beq lbl_80242ff0;
  stw r6, 0x30(r4);
lbl_80242ff0:
  lwz r4, -0x5c94(r13);
  li r0, 0;
  stw r4, 0x34(r6);
  cmpwi r5, 0;
  stw r0, 0x30(r6);
  stw r6, -0x5c94(r13);
  stw r5, 0x34(r3);
  beq lbl_80243018;
  stw r3, 0x30(r5);
  b lbl_8024301c;
lbl_80243018:
  stw r3, -0x5c98(r13);
lbl_8024301c:
  lwz r5, 0x30(r3);
  cmpwi r5, 0;
  beqlr;
  lwz r0, 0x2c(r5);
  cmpwi r0, 0;
  bnelr;
  lwz r4, 0x28(r3);
  lwz r0, 0x28(r5);
  add r0, r4, r0;
  stw r0, 0x28(r3);
  lwz r4, -0x5c94(r13);
  lwz r6, 0x30(r5);
  cmpwi r4, 0;
  beq lbl_80243058;
  stw r5, 0x30(r4);
lbl_80243058:
  lwz r4, -0x5c94(r13);
  li r0, 0;
  stw r4, 0x34(r5);
  cmpwi r6, 0;
  stw r0, 0x30(r5);
  stw r5, -0x5c94(r13);
  stw r6, 0x30(r3);
  beqlr;
  stw r3, 0x34(r6);
  blr;
  // clang-format on
}

// Symbol: unk_80243080
// PAL: 0x80243080..0x80243174
MARK_BINARY_BLOB(unk_80243080, 0x80243080, 0x80243174);
asm UNKNOWN_FUNCTION(unk_80243080) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r26, r3;
  bne lbl_802430a0;
  lwz r4, -0x5d60(r13);
lbl_802430a0:
  stw r3, -0x5c8c(r13);
  mr r3, r26;
  li r5, 0x20;
  bl __nwa__FUlPQ23EGG4Heapi;
  li r30, 0;
  lis r28, 0x8038;
  lis r31, 0x802a;
  stw r3, -0x5c90(r13);
  addi r28, r28, 0x4960;
  li r27, 0;
  stw r30, -0x5c94(r13);
  addi r31, r31, 0x3fa8;
lbl_802430d0:
  li r3, 0x38;
  bl __nw__FUl;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_802430fc;
  bl unk_8021805c;
  stw r31, 0x10(r29);
  stw r30, 0x28(r29);
  stw r30, 0x2c(r29);
  stw r30, 0x30(r29);
  stw r30, 0x34(r29);
lbl_802430fc:
  lwz r3, -0x5c94(r13);
  stw r29, 0(r28);
  cmpwi r3, 0;
  beq lbl_80243110;
  stw r29, 0x30(r3);
lbl_80243110:
  lwz r0, -0x5c94(r13);
  addi r27, r27, 1;
  stw r0, 0x34(r29);
  cmpwi r27, 0x80;
  addi r28, r28, 4;
  stw r30, 0x30(r29);
  stw r29, -0x5c94(r13);
  blt lbl_802430d0;
  bl unk_80243174;
  stw r3, -0x5c98(r13);
  li r0, 0;
  stw r0, 0x2c(r3);
  lwz r3, -0x5c98(r13);
  stw r26, 0x28(r3);
  lwz r3, -0x5c98(r13);
  lwz r0, -0x5c90(r13);
  stw r0, 0xc(r3);
  lbz r0, 4(r3);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stb r0, 4(r3);
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80243174
// PAL: 0x80243174..0x8024319c
MARK_BINARY_BLOB(unk_80243174, 0x80243174, 0x8024319c);
asm UNKNOWN_FUNCTION(unk_80243174) {
  // clang-format off
  nofralloc;
  lwz r3, -0x5c94(r13);
  lwz r4, 0x34(r3);
  stw r4, -0x5c94(r13);
  cmpwi r4, 0;
  beq lbl_80243190;
  li r0, 0;
  stw r0, 0x30(r4);
lbl_80243190:
  li r0, 0;
  stw r0, 0x34(r3);
  blr;
  // clang-format on
}

// Symbol: unk_8024319c
// PAL: 0x8024319c..0x80243284
MARK_BINARY_BLOB(unk_8024319c, 0x8024319c, 0x80243284);
asm UNKNOWN_FUNCTION(unk_8024319c) {
  // clang-format off
  nofralloc;
  clrlwi r0, r4, 0x1b;
  lwz r5, -0x5c98(r13);
  subfic r0, r0, 0x20;
  add r7, r4, r0;
  b lbl_80243278;
lbl_802431b0:
  lwz r0, 0x2c(r5);
  cmpwi r0, 0;
  bne lbl_80243274;
  lwz r0, 0x28(r5);
  cmplw r0, r7;
  blt lbl_80243274;
  li r0, 1;
  stw r0, 0x2c(r3);
  lbz r0, 4(r3);
  stw r7, 0x28(r3);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  lwz r6, 0xc(r5);
  stw r6, 0xc(r3);
  stb r0, 4(r3);
  stw r5, 0x30(r3);
  lwz r4, 0x34(r5);
  stw r4, 0x34(r3);
  cmpwi r4, 0;
  beq lbl_80243204;
  stw r3, 0x30(r4);
  b lbl_80243208;
lbl_80243204:
  stw r3, -0x5c98(r13);
lbl_80243208:
  lwz r0, 0x28(r5);
  subf. r0, r7, r0;
  stw r0, 0x28(r5);
  bne lbl_80243258;
  lwz r4, 0x30(r5);
  cmpwi r4, 0;
  beq lbl_80243228;
  stw r3, 0x34(r4);
lbl_80243228:
  lwz r0, 0x30(r5);
  stw r0, 0x30(r3);
  lwz r3, -0x5c94(r13);
  cmpwi r3, 0;
  beq lbl_80243240;
  stw r5, 0x30(r3);
lbl_80243240:
  lwz r3, -0x5c94(r13);
  li r0, 0;
  stw r3, 0x34(r5);
  stw r0, 0x30(r5);
  stw r5, -0x5c94(r13);
  blr;
lbl_80243258:
  add r0, r6, r7;
  stw r0, 0xc(r5);
  lbz r0, 4(r5);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stb r0, 4(r5);
  stw r3, 0x34(r5);
  blr;
lbl_80243274:
  lwz r5, 0x30(r5);
lbl_80243278:
  cmpwi r5, 0;
  bne lbl_802431b0;
  blr;
  // clang-format on
}

// Symbol: unk_80243284
// PAL: 0x80243284..0x802432e0
MARK_BINARY_BLOB(unk_80243284, 0x80243284, 0x802432e0);
asm UNKNOWN_FUNCTION(unk_80243284) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_802432c4;
  beq lbl_802432b4;
  li r4, 0;
  bl unk_80218178;
lbl_802432b4:
  cmpwi r31, 0;
  ble lbl_802432c4;
  mr r3, r30;
  bl __dl__FPv;
lbl_802432c4:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
