#include "DvdArchive.hpp"

// Extern function references.
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(unk_805553b0);

// Symbol: DvdArchive_ct
// PAL: 0x80518cc0..0x80518cf4
MARK_BINARY_BLOB(DvdArchive_ct, 0x80518cc0, 0x80518cf4);
asm UNKNOWN_FUNCTION(DvdArchive_ct) {
  // clang-format off
  nofralloc;
  lis r4, 0;
  li r0, 0;
  addi r4, r4, 0;
  stw r4, 0(r3);
  stw r0, 4(r3);
  stw r0, 8(r3);
  stw r0, 0xc(r3);
  stw r0, 0x10(r3);
  stw r0, 0x14(r3);
  stw r0, 0x18(r3);
  stw r0, 0x1c(r3);
  stw r0, 0x20(r3);
  blr;
  // clang-format on
}

// Symbol: DvdArchive_dt
// PAL: 0x80518cf4..0x80518dcc
MARK_BINARY_BLOB(DvdArchive_dt, 0x80518cf4, 0x80518dcc);
asm UNKNOWN_FUNCTION(DvdArchive_dt) {
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
  beq lbl_80518db0;
  lwz r0, 0x20(r3);
  lis r4, 0;
  addi r4, r4, 0;
  stw r4, 0(r3);
  cmpwi r0, 4;
  bne lbl_80518d38;
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_80518d38:
  lwz r4, 8(r30);
  cmpwi r4, 0;
  beq lbl_80518d68;
  lwz r3, 0x10(r30);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 8(r30);
  stw r0, 0xc(r30);
  stw r0, 0x10(r30);
lbl_80518d68:
  lwz r4, 0x14(r30);
  cmpwi r4, 0;
  beq lbl_80518d98;
  lwz r3, 0x1c(r30);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x14(r30);
  stw r0, 0x18(r30);
  stw r0, 0x1c(r30);
lbl_80518d98:
  cmpwi r31, 0;
  li r0, 0;
  stw r0, 0x20(r30);
  ble lbl_80518db0;
  mr r3, r30;
  bl unk_805553b0;
lbl_80518db0:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DvdArchive_mount
// PAL: 0x80518dcc..0x80518e10
MARK_BINARY_BLOB(DvdArchive_mount, 0x80518dcc, 0x80518e10);
asm UNKNOWN_FUNCTION(DvdArchive_mount) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 4;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r3, 8(r3);
  bl unk_805553b0;
  li r0, 4;
  stw r3, 4(r31);
  stw r0, 0x20(r31);
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  blr;
  // clang-format on
}

// Symbol: DvdArchive_load
// PAL: 0x80518e10..0x80518fa4
MARK_BINARY_BLOB(DvdArchive_load, 0x80518e10, 0x80518fa4);
asm UNKNOWN_FUNCTION(DvdArchive_load) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  cmpwi r6, 0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r30, r3;
  mr r25, r4;
  mr r31, r5;
  mr r26, r6;
  mr r27, r8;
  mr r28, r9;
  beq lbl_80518e48;
  cmpwi r8, 0;
  bne lbl_80518e4c;
lbl_80518e48:
  mr r27, r31;
lbl_80518e4c:
  lwz r0, 0x20(r3);
  cmpwi r0, 0;
  bne lbl_80518ee0;
  cmpwi r6, 0;
  li r29, 0;
  li r6, 1;
  li r0, -8;
  bne lbl_80518e70;
  extsb r0, r7;
lbl_80518e70:
  cmpwi r0, 0;
  bge lbl_80518e7c;
  li r6, 2;
lbl_80518e7c:
  mr r3, r25;
  mr r5, r27;
  addi r9, r30, 0x18;
  li r4, 0;
  li r7, 0;
  li r8, 0;
  bl unk_805553b0;
  lwz r0, 0x18(r30);
  stw r3, 0x14(r30);
  cmpwi r0, 0;
  beq lbl_80518ebc;
  cmpwi r3, 0;
  beq lbl_80518ebc;
  stw r27, 0x1c(r30);
  li r29, 1;
  b lbl_80518ec4;
lbl_80518ebc:
  li r0, 0;
  stw r0, 0x18(r30);
lbl_80518ec4:
  cmpwi r29, 0;
  beq lbl_80518ed8;
  li r0, 2;
  stw r0, 0x20(r30);
  b lbl_80518ee0;
lbl_80518ed8:
  li r0, 0;
  stw r0, 0x20(r30);
lbl_80518ee0:
  lwz r3, 0x20(r30);
  addi r0, r3, -2;
  cntlzw r0, r0;
  rlwinm. r0, r0, 0x1b, 5, 0x1f;
  beq lbl_80518f90;
  cmpwi r26, 0;
  beq lbl_80518f44;
  mr r3, r30;
  mr r4, r25;
  mr r5, r31;
  mr r6, r28;
  bl SArchive_decompress;
  lwz r4, 0x14(r30);
  cmpwi r4, 0;
  beq lbl_80518f74;
  lwz r3, 0x1c(r30);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x14(r30);
  stw r0, 0x18(r30);
  stw r0, 0x1c(r30);
  b lbl_80518f74;
lbl_80518f44:
  lwz r6, 0x14(r30);
  li r3, 0;
  lwz r5, 0x18(r30);
  li r0, 3;
  lwz r4, 0x1c(r30);
  stw r6, 8(r30);
  stw r5, 0xc(r30);
  stw r4, 0x10(r30);
  stw r3, 0x14(r30);
  stw r3, 0x18(r30);
  stw r3, 0x1c(r30);
  stw r0, 0x20(r30);
lbl_80518f74:
  lwz r3, 8(r30);
  mr r4, r31;
  li r5, 4;
  bl unk_805553b0;
  li r0, 4;
  stw r3, 4(r30);
  stw r0, 0x20(r30);
lbl_80518f90:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: SArchive_load
// PAL: 0x80518fa4..0x80518fbc
MARK_BINARY_BLOB(SArchive_load, 0x80518fa4, 0x80518fbc);
asm UNKNOWN_FUNCTION(SArchive_load) {
  // clang-format off
  nofralloc;
  mr r5, r6;
  li r6, 0;
  li r7, -8;
  li r8, 0;
  li r9, 0;
  b DvdArchive_load;
  // clang-format on
}

// Symbol: SArchive_load2
// PAL: 0x80518fbc..0x80519040
MARK_BINARY_BLOB(SArchive_load2, 0x80518fbc, 0x80519040);
asm UNKNOWN_FUNCTION(SArchive_load2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r7, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r6;
  stw r30, 8(r1);
  mr r30, r3;
  stw r4, 0x14(r3);
  stw r5, 0x18(r3);
  beq lbl_8051900c;
  lis r4, 0;
  mr r5, r31;
  addi r4, r4, 0;
  li r6, 0;
  bl SArchive_decompress;
  li r0, 0;
  stw r0, 0x14(r30);
  stw r0, 0x18(r30);
  stw r0, 0x1c(r30);
lbl_8051900c:
  lwz r3, 8(r30);
  mr r4, r31;
  li r5, 4;
  bl unk_805553b0;
  li r0, 4;
  stw r3, 4(r30);
  stw r0, 0x20(r30);
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80519040
// PAL: 0x80519040..0x805190e8
MARK_BINARY_BLOB(unk_80519040, 0x80519040, 0x805190e8);
asm UNKNOWN_FUNCTION(unk_80519040) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r7;
  stw r29, 0x14(r1);
  mr r29, r6;
  stw r28, 0x10(r1);
  mr r28, r5;
  addi r5, r1, 8;
  bl unk_80519420;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_805190c4;
  lwz r12, 0(r28);
  mr r3, r28;
  extsb r5, r30;
  lwz r4, 8(r1);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r5, 8(r1);
  mr r30, r3;
  mr r4, r31;
  bl unk_805553b0;
  cmpwi r30, 0;
  mr r31, r30;
  beq lbl_805190c4;
  cmpwi r29, 0;
  beq lbl_805190c4;
  lwz r0, 8(r1);
  stw r0, 0(r29);
lbl_805190c4:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_805190e8
// PAL: 0x805190e8..0x805190f0
MARK_BINARY_BLOB(unk_805190e8, 0x805190e8, 0x805190f0);
asm UNKNOWN_FUNCTION(unk_805190e8) {
  // clang-format off
  nofralloc;
  mr r3, r5;
  b unk_805553b0;
  // clang-format on
}

// Symbol: SArchive_ripFile
// PAL: 0x805190f0..0x805191a4
MARK_BINARY_BLOB(SArchive_ripFile, 0x805190f0, 0x805191a4);
asm UNKNOWN_FUNCTION(SArchive_ripFile) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  extsb. r0, r6;
  li r6, 1;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  bge lbl_80519124;
  li r6, 2;
lbl_80519124:
  mr r3, r4;
  mr r5, r30;
  addi r9, r29, 0x18;
  li r4, 0;
  li r7, 0;
  li r8, 0;
  bl unk_805553b0;
  lwz r0, 0x18(r29);
  stw r3, 0x14(r29);
  cmpwi r0, 0;
  beq lbl_80519164;
  cmpwi r3, 0;
  beq lbl_80519164;
  stw r30, 0x1c(r29);
  li r31, 1;
  b lbl_8051916c;
lbl_80519164:
  li r0, 0;
  stw r0, 0x18(r29);
lbl_8051916c:
  cmpwi r31, 0;
  beq lbl_80519180;
  li r0, 2;
  stw r0, 0x20(r29);
  b lbl_80519188;
lbl_80519180:
  li r0, 0;
  stw r0, 0x20(r29);
lbl_80519188:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_805191a4
// PAL: 0x805191a4..0x80519240
MARK_BINARY_BLOB(unk_805191a4, 0x805191a4, 0x80519240);
asm UNKNOWN_FUNCTION(unk_805191a4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  extsb. r0, r6;
  li r6, 1;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  bge lbl_805191d8;
  li r6, 2;
lbl_805191d8:
  mr r3, r4;
  mr r5, r30;
  addi r9, r29, 0x18;
  li r4, 0;
  li r7, 0;
  li r8, 0;
  bl unk_805553b0;
  lwz r0, 0x18(r29);
  stw r3, 0x14(r29);
  cmpwi r0, 0;
  beq lbl_80519218;
  cmpwi r3, 0;
  beq lbl_80519218;
  stw r30, 0x1c(r29);
  li r31, 1;
  b lbl_80519220;
lbl_80519218:
  li r0, 0;
  stw r0, 0x18(r29);
lbl_80519220:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: SArchive_destroyBuffers
// PAL: 0x80519240..0x805192cc
MARK_BINARY_BLOB(SArchive_destroyBuffers, 0x80519240, 0x805192cc);
asm UNKNOWN_FUNCTION(SArchive_destroyBuffers) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r4, 8(r3);
  cmpwi r4, 0;
  beq lbl_80519284;
  lwz r3, 0x10(r3);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 8(r31);
  stw r0, 0xc(r31);
  stw r0, 0x10(r31);
lbl_80519284:
  lwz r4, 0x14(r31);
  cmpwi r4, 0;
  beq lbl_805192b4;
  lwz r3, 0x1c(r31);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x14(r31);
  stw r0, 0x18(r31);
  stw r0, 0x1c(r31);
lbl_805192b4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  blr;
  // clang-format on
}

// Symbol: DvdArchive_unmount
// PAL: 0x805192cc..0x80519370
MARK_BINARY_BLOB(DvdArchive_unmount, 0x805192cc, 0x80519370);
asm UNKNOWN_FUNCTION(DvdArchive_unmount) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r0, 0x20(r3);
  cmpwi r0, 4;
  bne lbl_805192f4;
  lwz r3, 4(r3);
  bl unk_805553b0;
lbl_805192f4:
  lwz r4, 8(r31);
  cmpwi r4, 0;
  beq lbl_80519324;
  lwz r3, 0x10(r31);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 8(r31);
  stw r0, 0xc(r31);
  stw r0, 0x10(r31);
lbl_80519324:
  lwz r4, 0x14(r31);
  cmpwi r4, 0;
  beq lbl_80519354;
  lwz r3, 0x1c(r31);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x14(r31);
  stw r0, 0x18(r31);
  stw r0, 0x1c(r31);
lbl_80519354:
  li r0, 0;
  stw r0, 0x20(r31);
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80519370
// PAL: 0x80519370..0x805193c8
MARK_BINARY_BLOB(unk_80519370, 0x80519370, 0x805193c8);
asm UNKNOWN_FUNCTION(unk_80519370) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r4, 8(r3);
  cmpwi r4, 0;
  beq lbl_805193b4;
  lwz r3, 0x10(r3);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 8(r31);
  stw r0, 0xc(r31);
  stw r0, 0x10(r31);
lbl_805193b4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_805193c8
// PAL: 0x805193c8..0x80519420
MARK_BINARY_BLOB(unk_805193c8, 0x805193c8, 0x80519420);
asm UNKNOWN_FUNCTION(unk_805193c8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r4, 0x14(r3);
  cmpwi r4, 0;
  beq lbl_8051940c;
  lwz r3, 0x1c(r3);
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x14(r31);
  stw r0, 0x18(r31);
  stw r0, 0x1c(r31);
lbl_8051940c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80519420
// PAL: 0x80519420..0x80519508
MARK_BINARY_BLOB(unk_80519420, 0x80519420, 0x80519508);
asm UNKNOWN_FUNCTION(unk_80519420) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  stw r31, 0x11c(r1);
  mr r31, r5;
  stw r30, 0x118(r1);
  mr r30, r3;
  lwz r0, 0x20(r3);
  cmpwi r0, 4;
  beq lbl_80519450;
  li r3, 0;
  b lbl_805194f0;
lbl_80519450:
  lbz r0, 0(r4);
  cmpwi r0, 0x2f;
  bne lbl_80519480;
  lis r5, 0;
  mr r6, r4;
  addi r5, r5, 0;
  addi r3, r1, 0x10;
  addi r5, r5, 0xc;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
  b lbl_805194a0;
lbl_80519480:
  lis r5, 0;
  mr r6, r4;
  addi r5, r5, 0;
  addi r3, r1, 0x10;
  addi r5, r5, 0xf;
  li r4, 0x100;
  crclr 6;
  bl unk_805553b0;
lbl_805194a0:
  li r0, 0;
  stb r0, 0x10f(r1);
  addi r4, r1, 0x10;
  stw r0, 8(r1);
  stw r0, 0xc(r1);
  lwz r3, 4(r30);
  bl unk_805553b0;
  cmpwi r3, -1;
  mr r4, r3;
  li r3, 0;
  beq lbl_805194f0;
  lwz r3, 4(r30);
  addi r5, r1, 8;
  bl unk_805553b0;
  cmpwi r3, 0;
  beq lbl_805194f0;
  cmpwi r31, 0;
  beq lbl_805194f0;
  lwz r0, 0xc(r1);
  stw r0, 0(r31);
lbl_805194f0:
  lwz r0, 0x124(r1);
  lwz r31, 0x11c(r1);
  lwz r30, 0x118(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: SArchive_decompress
// PAL: 0x80519508..0x805195a4
MARK_BINARY_BLOB(SArchive_decompress, 0x80519508, 0x805195a4);
asm UNKNOWN_FUNCTION(SArchive_decompress) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r3, 0x14(r3);
  bl unk_805553b0;
  lwz r12, 0(r29);
  mr r31, r3;
  mr r3, r29;
  li r5, 0x20;
  lwz r12, 0x14(r12);
  mr r4, r31;
  mtctr r12;
  bctrl;
  mr r30, r3;
  lwz r3, 0x14(r28);
  mr r4, r30;
  bl unk_805553b0;
  stw r31, 0xc(r28);
  mr r3, r30;
  mr r4, r31;
  stw r30, 8(r28);
  stw r29, 0x10(r28);
  bl unk_805553b0;
  li r0, 3;
  stw r0, 0x20(r28);
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_805195a4
// PAL: 0x805195a4..0x805195d8
MARK_BINARY_BLOB(unk_805195a4, 0x805195a4, 0x805195d8);
asm UNKNOWN_FUNCTION(unk_805195a4) {
  // clang-format off
  nofralloc;
  lwz r7, 0x14(r3);
  li r4, 0;
  lwz r6, 0x18(r3);
  li r0, 3;
  lwz r5, 0x1c(r3);
  stw r7, 8(r3);
  stw r6, 0xc(r3);
  stw r5, 0x10(r3);
  stw r4, 0x14(r3);
  stw r4, 0x18(r3);
  stw r4, 0x1c(r3);
  stw r0, 0x20(r3);
  blr;
  // clang-format on
}

// Symbol: SArchive_loadOther
// PAL: 0x805195d8..0x80519670
MARK_BINARY_BLOB(SArchive_loadOther, 0x805195d8, 0x80519670);
asm UNKNOWN_FUNCTION(SArchive_loadOther) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lwz r6, 0x20(r4);
  stw r0, 0x14(r1);
  addi r0, r6, -2;
  stw r31, 0xc(r1);
  cntlzw r0, r0;
  rlwinm. r0, r0, 0x1b, 5, 0x1f;
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_80519650;
  lwz r4, 0x14(r4);
  li r0, 2;
  stw r4, 0x14(r3);
  li r4, 0;
  li r6, 0;
  stw r0, 0x20(r3);
  bl SArchive_decompress;
  lwz r3, 8(r30);
  mr r4, r31;
  li r5, 4;
  bl unk_805553b0;
  li r0, 0;
  li r4, 4;
  stw r3, 4(r30);
  stw r4, 0x20(r30);
  stw r0, 0x14(r30);
  stw r0, 0x18(r30);
  b lbl_80519658;
lbl_80519650:
  li r0, 0;
  stw r0, 0x20(r3);
lbl_80519658:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
