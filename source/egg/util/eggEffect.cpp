#include "eggEffect.hpp"

extern "C" {
extern UNKNOWN_FUNCTION(strcpy);
// PAL: 0x8001bbdc
extern UNKNOWN_FUNCTION(acos);
// PAL: 0x8001bbe4
extern UNKNOWN_FUNCTION(atan2);
extern UNKNOWN_FUNCTION(unk_80026810);
// PAL: 0x800268e0
extern UNKNOWN_FUNCTION(unk_800268e0);
// PAL: 0x80026da0
extern UNKNOWN_FUNCTION(unk_80026da0);
// PAL: 0x80026db0
extern UNKNOWN_FUNCTION(unk_80026db0);
// PAL: 0x80026dc0
extern UNKNOWN_FUNCTION(unk_80026dc0);
// PAL: 0x80026f30
extern UNKNOWN_FUNCTION(unk_80026f30);
// PAL: 0x80029a60
extern UNKNOWN_FUNCTION(unk_80029a60);
// PAL: 0x80029bb0
extern UNKNOWN_FUNCTION(unk_80029bb0);
// PAL: 0x80029cc0
extern UNKNOWN_FUNCTION(unk_80029cc0);
// PAL: 0x80029cd0
extern UNKNOWN_FUNCTION(unk_80029cd0);
// PAL: 0x80035940
extern UNKNOWN_FUNCTION(unk_80035940);
// PAL: 0x80035df0
extern UNKNOWN_FUNCTION(unk_80035df0);
// PAL: 0x80037560
extern UNKNOWN_FUNCTION(unk_80037560);
// PAL: 0x80037570
extern UNKNOWN_FUNCTION(unk_80037570);
// PAL: 0x80037590
extern UNKNOWN_FUNCTION(unk_80037590);
// PAL: 0x800375c0
extern UNKNOWN_FUNCTION(unk_800375c0);
// PAL: 0x800375f0
extern UNKNOWN_FUNCTION(unk_800375f0);
// PAL: 0x8004bc80
extern UNKNOWN_FUNCTION(unk_8004bc80);
// PAL: 0x8004bcb0
extern UNKNOWN_FUNCTION(unk_8004bcb0);
// PAL: 0x80085940
extern UNKNOWN_FUNCTION(unk_80085940);
// PAL: 0x80199d04
extern UNKNOWN_FUNCTION(PSMTXIdentity);
// PAL: 0x80199d30
extern UNKNOWN_FUNCTION(PSMTXCopy);
// PAL: 0x80199fc8
extern UNKNOWN_FUNCTION(PSMTXInverse);
// PAL: 0x8019a91c
extern UNKNOWN_FUNCTION(PSMTXMultVec);
// PAL: 0x8019ac24
extern UNKNOWN_FUNCTION(PSVECNormalize);
// PAL: 0x80225208
extern UNKNOWN_FUNCTION(unk_80225208);
}

extern float unk_80388ce0, unk_80388ce4, unk_80388ce8, unk_80388cec;

__declspec(section ".ctors") void* eggEffect_ctorEntry = unk_80224340;

// Symbol: unk_80222ccc
// PAL: 0x80222ccc..0x80222d50
MARK_BINARY_BLOB(unk_80222ccc, 0x80222ccc, 0x80222d50);
asm UNKNOWN_FUNCTION(unk_80222ccc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x802a;
  stw r0, 0x24(r1);
  li r0, 0;
  addi r6, r6, 0x2dc8;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r6, 0(r3);
  stw r0, 0x28(r3);
  addi r3, r3, 0x74;
  bl unk_80037560;
  mr r4, r30;
  addi r3, r29, 4;
  bl strcpy;
  stw r31, 0x24(r29);
  mr r3, r29;
  lwz r12, 0(r29);
  lwz r12, 0x84(r12);
  mtctr r12;
  bctrl;
  lwz r31, 0x1c(r1);
  mr r3, r29;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80222d50
// PAL: 0x80222d50..0x80222d90
MARK_BINARY_BLOB(unk_80222d50, 0x80222d50, 0x80222d90);
asm UNKNOWN_FUNCTION(unk_80222d50) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_80222d78;
  cmpwi r4, 0;
  ble lbl_80222d78;
  bl __dl__FPv;
lbl_80222d78:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80222d90
// PAL: 0x80222d90..0x80222e60
MARK_BINARY_BLOB(unk_80222d90, 0x80222d90, 0x80222e60);
asm UNKNOWN_FUNCTION(unk_80222d90) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80222dfc;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  cmpwi r3, 0;
  bne lbl_80222dcc;
  li r3, 0;
  b lbl_80222dd0;
lbl_80222dcc:
  lwz r3, 0xc(r3);
lbl_80222dd0:
  cmpwi r3, 1;
  li r0, 0;
  beq lbl_80222de4;
  cmpwi r3, 2;
  bne lbl_80222de8;
lbl_80222de4:
  li r0, 1;
lbl_80222de8:
  cmpwi r0, 0;
  bne lbl_80222dfc;
  addi r3, r31, 0x74;
  addi r4, r13, -24024;
  bl unk_80037570;
lbl_80222dfc:
  addi r3, r31, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  bne lbl_80222e48;
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x84(r12);
  mtctr r12;
  bctrl;
  lwz r3, -0x5dd0(r13);
  addi r4, r31, 4;
  lwz r5, 0x24(r31);
  bl unk_80225208;
  mr r4, r3;
  addi r3, r31, 0x74;
  bl unk_80037590;
  addi r3, r31, 0x74;
  bl unk_800375c0;
  b lbl_80222e4c;
lbl_80222e48:
  li r3, 0;
lbl_80222e4c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80222e60
// PAL: 0x80222e60..0x80222eb0
MARK_BINARY_BLOB(unk_80222e60, 0x80222e60, 0x80222eb0);
asm UNKNOWN_FUNCTION(unk_80222e60) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80222e9c;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  bl unk_80026810;
  addi r3, r31, 0x74;
  addi r4, r13, -24024;
  bl unk_80037570;
lbl_80222e9c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80222eb0
// PAL: 0x80222eb0..0x80222ef4
MARK_BINARY_BLOB(unk_80222eb0, 0x80222eb0, 0x80222ef4);
asm UNKNOWN_FUNCTION(unk_80222eb0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80222ee0;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  bl unk_80026810;
lbl_80222ee0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80222ef4
// PAL: 0x80222ef4..0x80222f50
MARK_BINARY_BLOB(unk_80222ef4, 0x80222ef4, 0x80222f50);
asm UNKNOWN_FUNCTION(unk_80222ef4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80222f3c;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  bl unk_80026810;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  bl unk_800268e0;
  addi r3, r31, 0x74;
  addi r4, r13, -24024;
  bl unk_80037570;
lbl_80222f3c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80222f50
// PAL: 0x80222f50..0x80222fc0
MARK_BINARY_BLOB(unk_80222f50, 0x80222f50, 0x80222fc0);
asm UNKNOWN_FUNCTION(unk_80222f50) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80222fa8;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  cmpwi r31, 0;
  beq lbl_80222f9c;
  lwz r0, 0x50(r3);
  ori r0, r0, 1;
  stw r0, 0x50(r3);
  b lbl_80222fa8;
lbl_80222f9c:
  lwz r0, 0x50(r3);
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x50(r3);
lbl_80222fa8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80222fc0
// PAL: 0x80222fc0..0x80223030
MARK_BINARY_BLOB(unk_80222fc0, 0x80222fc0, 0x80223030);
asm UNKNOWN_FUNCTION(unk_80222fc0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223018;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  cmpwi r31, 0;
  beq lbl_8022300c;
  lwz r0, 0x50(r3);
  ori r0, r0, 2;
  stw r0, 0x50(r3);
  b lbl_80223018;
lbl_8022300c:
  lwz r0, 0x50(r3);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stw r0, 0x50(r3);
lbl_80223018:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80223030
// PAL: 0x80223030..0x802230cc
MARK_BINARY_BLOB(unk_80223030, 0x80223030, 0x802230cc);
asm UNKNOWN_FUNCTION(unk_80223030) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802230b4;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  cmpwi r31, 0;
  beq lbl_8022307c;
  lwz r0, 0x50(r3);
  ori r0, r0, 1;
  stw r0, 0x50(r3);
  b lbl_80223088;
lbl_8022307c:
  lwz r0, 0x50(r3);
  rlwinm r0, r0, 0, 0, 0x1e;
  stw r0, 0x50(r3);
lbl_80223088:
  addi r3, r30, 0x74;
  bl unk_800375f0;
  cmpwi r31, 0;
  beq lbl_802230a8;
  lwz r0, 0x50(r3);
  ori r0, r0, 2;
  stw r0, 0x50(r3);
  b lbl_802230b4;
lbl_802230a8:
  lwz r0, 0x50(r3);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stw r0, 0x50(r3);
lbl_802230b4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_802230cc
// PAL: 0x802230cc..0x8022318c
MARK_BINARY_BLOB(unk_802230cc, 0x802230cc, 0x8022318c);
asm UNKNOWN_FUNCTION(unk_802230cc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r25, r3;
  mr r26, r4;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223178;
  addi r3, r25, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_80223170;
lbl_8022310c:
  addi r3, r25, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_8022316c;
  bl unk_80029cc0;
  clrlwi r28, r3, 0x10;
  li r27, 0;
  b lbl_80223164;
lbl_80223138:
  mr r3, r29;
  clrlwi r4, r27, 0x10;
  bl unk_80029cd0;
  cmpwi r3, 0;
  beq lbl_80223160;
  lwz r12, 0x1c(r3);
  mr r4, r26;
  lwz r12, 0x24(r12);
  mtctr r12;
  bctrl;
lbl_80223160:
  addi r27, r27, 1;
lbl_80223164:
  cmpw r27, r28;
  blt lbl_80223138;
lbl_8022316c:
  addi r30, r30, 1;
lbl_80223170:
  cmpw r30, r31;
  blt lbl_8022310c;
lbl_80223178:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_8022318c
// PAL: 0x8022318c..0x80223220
MARK_BINARY_BLOB(unk_8022318c, 0x8022318c, 0x80223220);
asm UNKNOWN_FUNCTION(unk_8022318c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stfd f31, 0x18(r1);
  fmr f31, f1;
  stw r31, 0x14(r1);
  stw r30, 0x10(r1);
  stw r29, 0xc(r1);
  mr r29, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223200;
  addi r3, r29, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_802231f8;
lbl_802231d8:
  addi r3, r29, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_802231f4;
  stfs f31, 0x28(r3);
lbl_802231f4:
  addi r30, r30, 1;
lbl_802231f8:
  cmpw r30, r31;
  blt lbl_802231d8;
lbl_80223200:
  lwz r0, 0x24(r1);
  lfd f31, 0x18(r1);
  lwz r31, 0x14(r1);
  lwz r30, 0x10(r1);
  lwz r29, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80223220
// PAL: 0x80223220..0x802232b4
MARK_BINARY_BLOB(unk_80223220, 0x80223220, 0x802232b4);
asm UNKNOWN_FUNCTION(unk_80223220) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223294;
  addi r3, r28, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_8022328c;
lbl_8022326c:
  addi r3, r28, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_80223288;
  sth r29, 0x30(r3);
lbl_80223288:
  addi r30, r30, 1;
lbl_8022328c:
  cmpw r30, r31;
  blt lbl_8022326c;
lbl_80223294:
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

// Symbol: unk_802232b4
// PAL: 0x802232b4..0x80223348
MARK_BINARY_BLOB(unk_802232b4, 0x802232b4, 0x80223348);
asm UNKNOWN_FUNCTION(unk_802232b4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223328;
  addi r3, r28, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_80223320;
lbl_80223300:
  addi r3, r28, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_8022331c;
  sth r29, 0x32(r3);
lbl_8022331c:
  addi r30, r30, 1;
lbl_80223320:
  cmpw r30, r31;
  blt lbl_80223300;
lbl_80223328:
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

// Symbol: unk_80223348
// PAL: 0x80223348..0x802233dc
MARK_BINARY_BLOB(unk_80223348, 0x80223348, 0x802233dc);
asm UNKNOWN_FUNCTION(unk_80223348) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stfd f31, 0x18(r1);
  fmr f31, f1;
  stw r31, 0x14(r1);
  stw r30, 0x10(r1);
  stw r29, 0xc(r1);
  mr r29, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802233bc;
  addi r3, r29, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_802233b4;
lbl_80223394:
  addi r3, r29, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_802233b0;
  stfs f31, 0x68(r3);
lbl_802233b0:
  addi r30, r30, 1;
lbl_802233b4:
  cmpw r30, r31;
  blt lbl_80223394;
lbl_802233bc:
  lwz r0, 0x24(r1);
  lfd f31, 0x18(r1);
  lwz r31, 0x14(r1);
  lwz r30, 0x10(r1);
  lwz r29, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_802233dc
// PAL: 0x802233dc..0x80223470
MARK_BINARY_BLOB(unk_802233dc, 0x802233dc, 0x80223470);
asm UNKNOWN_FUNCTION(unk_802233dc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stfd f31, 0x18(r1);
  fmr f31, f1;
  stw r31, 0x14(r1);
  stw r30, 0x10(r1);
  stw r29, 0xc(r1);
  mr r29, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223450;
  addi r3, r29, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_80223448;
lbl_80223428:
  addi r3, r29, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_80223444;
  stfs f31, 0x7c(r3);
lbl_80223444:
  addi r30, r30, 1;
lbl_80223448:
  cmpw r30, r31;
  blt lbl_80223428;
lbl_80223450:
  lwz r0, 0x24(r1);
  lfd f31, 0x18(r1);
  lwz r31, 0x14(r1);
  lwz r30, 0x10(r1);
  lwz r29, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80223470
// PAL: 0x80223470..0x80223528
MARK_BINARY_BLOB(unk_80223470, 0x80223470, 0x80223528);
asm UNKNOWN_FUNCTION(unk_80223470) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stfd f31, 0x20(r1);
  psq_st f31, 40(r1), 0, 0;
  fmr f31, f1;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223504;
  addi r3, r29, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_802234fc;
lbl_802234c0:
  addi r3, r29, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_802234f8;
  lwz r0, 0xb8(r3);
  cmpwi r0, 0;
  beq lbl_802234f8;
  addic. r4, r0, 8;
  beq lbl_802234f8;
  lfs f0, 0x4c(r4);
  fadds f0, f0, f31;
  stfs f0, 0x7c(r3);
lbl_802234f8:
  addi r30, r30, 1;
lbl_802234fc:
  cmpw r30, r31;
  blt lbl_802234c0;
lbl_80223504:
  psq_l f31, 40(r1), 0, 0;
  lwz r0, 0x34(r1);
  lfd f31, 0x20(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_80223528
// PAL: 0x80223528..0x80223620
MARK_BINARY_BLOB(unk_80223528, 0x80223528, 0x80223620);
asm UNKNOWN_FUNCTION(unk_80223528) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stfd f31, 0x90(r1);
  psq_st f31, 152(r1), 0, 0;
  addi r11, r1, 0x90;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223600;
  addi r3, r27, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  lfs f31, unk_80388ce0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_802235f8;
lbl_80223578:
  addi r3, r27, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_802235f4;
  addi r4, r1, 0x18;
  bl unk_80029a60;
  stfs f31, 0x24(r1);
  addi r3, r1, 0x18;
  addi r4, r1, 0x48;
  stfs f31, 0x34(r1);
  stfs f31, 0x44(r1);
  bl PSMTXInverse;
  cmpwi r3, 0;
  beq lbl_802235f4;
  mr r4, r28;
  addi r3, r1, 0x48;
  addi r5, r1, 8;
  bl PSMTXMultVec;
  lfs f1, 0xc(r1);
  bl acos;
  frsp f0, f1;
  stfs f0, 0x84(r29);
  lfs f2, 0x10(r1);
  lfs f1, 8(r1);
  bl atan2;
  frsp f0, f1;
  stfs f0, 0x88(r29);
  stfs f31, 0x8c(r29);
lbl_802235f4:
  addi r30, r30, 1;
lbl_802235f8:
  cmpw r30, r31;
  blt lbl_80223578;
lbl_80223600:
  psq_l f31, 152(r1), 0, 0;
  addi r11, r1, 0x90;
  lfd f31, 0x90(r1);
  bl _restgpr_27;
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: unk_80223620
// PAL: 0x80223620..0x802237d0
MARK_BINARY_BLOB(unk_80223620, 0x80223620, 0x802237d0);
asm UNKNOWN_FUNCTION(unk_80223620) {
  // clang-format off
  nofralloc;
  stwu r1, -0x100(r1);
  mflr r0;
  stw r0, 0x104(r1);
  stfd f31, 0xf0(r1);
  psq_st f31, 248(r1), 0, 0;
  stfd f30, 0xe0(r1);
  psq_st f30, 232(r1), 0, 0;
  stfd f29, 0xd0(r1);
  psq_st f29, 216(r1), 0, 0;
  addi r11, r1, 0xd0;
  bl _savegpr_25;
  mr r25, r3;
  mr r26, r4;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802237a0;
  addi r3, r25, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  lfs f29, unk_80388ce0;
  clrlwi r29, r3, 0x10;
  lfs f30, unk_80388ce4;
  addi r31, r1, 0x14;
  lfs f31, unk_80388ce8;
  li r28, 0;
  b lbl_80223798;
lbl_8022368c:
  addi r3, r25, 0x74;
  bl unk_800375f0;
  clrlwi r4, r28, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  mr r27, r3;
  beq lbl_80223794;
  lwz r0, 0xb8(r3);
  cmpwi r0, 0;
  beq lbl_80223794;
  addic. r30, r0, 8;
  beq lbl_80223794;
  stfs f29, 0x14(r1);
  addi r4, r1, 0x20;
  stfs f30, 0x18(r1);
  stfs f29, 0x1c(r1);
  bl unk_80029a60;
  stfs f29, 0x2c(r1);
  addi r3, r1, 0x80;
  stfs f29, 0x3c(r1);
  stfs f29, 0x4c(r1);
  lfs f2, 0x5c(r30);
  lfs f1, 0x58(r30);
  fmuls f3, f31, f2;
  lfs f0, 0x54(r30);
  fmuls f2, f31, f1;
  fmuls f1, f31, f0;
  bl unk_80085940;
  addi r4, r1, 0x14;
  addi r3, r1, 0x80;
  mr r5, r4;
  bl PSMTXMultVec;
  addi r4, r1, 0x14;
  addi r3, r1, 0x20;
  mr r5, r4;
  bl PSMTXMultVec;
  psq_l f2, 0(r31), 0, 0;
  mr r3, r31;
  psq_l f1, 0(r26), 0, 0;
  mr r4, r31;
  ps_add f0, f2, f1;
  psq_l f2, 8(r31), 1, 0;
  psq_l f1, 8(r26), 1, 0;
  psq_st f0, 0(r31), 0, 0;
  ps_add f0, f2, f1;
  psq_st f0, 8(r31), 1, 0;
  bl PSVECNormalize;
  addi r3, r1, 0x20;
  addi r4, r1, 0x50;
  bl PSMTXInverse;
  cmpwi r3, 0;
  beq lbl_80223794;
  mr r4, r31;
  addi r3, r1, 0x50;
  addi r5, r1, 8;
  bl PSMTXMultVec;
  lfs f1, 0xc(r1);
  bl acos;
  frsp f0, f1;
  stfs f0, 0x84(r27);
  lfs f2, 0x10(r1);
  lfs f1, 8(r1);
  bl atan2;
  frsp f0, f1;
  stfs f0, 0x88(r27);
  stfs f29, 0x8c(r27);
lbl_80223794:
  addi r28, r28, 1;
lbl_80223798:
  cmpw r28, r29;
  blt lbl_8022368c;
lbl_802237a0:
  psq_l f31, 248(r1), 0, 0;
  lfd f31, 0xf0(r1);
  psq_l f30, 232(r1), 0, 0;
  lfd f30, 0xe0(r1);
  psq_l f29, 216(r1), 0, 0;
  addi r11, r1, 0xd0;
  lfd f29, 0xd0(r1);
  bl _restgpr_25;
  lwz r0, 0x104(r1);
  mtlr r0;
  addi r1, r1, 0x100;
  blr;
  // clang-format on
}

// Symbol: unk_802237d0
// PAL: 0x802237d0..0x80223834
MARK_BINARY_BLOB(unk_802237d0, 0x802237d0, 0x80223834);
asm UNKNOWN_FUNCTION(unk_802237d0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_8022381c;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  lfs f0, 0(r31);
  stfs f0, 0x84(r3);
  lfs f0, 4(r31);
  stfs f0, 0x88(r3);
  lfs f0, 8(r31);
  stfs f0, 0x8c(r3);
lbl_8022381c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80223834
// PAL: 0x80223834..0x802238fc
MARK_BINARY_BLOB(unk_80223834, 0x80223834, 0x802238fc);
asm UNKNOWN_FUNCTION(unk_80223834) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r27, 0x1c(r1);
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802238bc;
  addi r3, r27, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  stb r28, 8(r1);
  addi r3, r27, 0x74;
  stb r29, 9(r1);
  stb r30, 0xa(r1);
  stb r31, 0xb(r1);
  bl unk_800375f0;
  lis r4, 0x8022;
  li r5, 1;
  addi r4, r4, 0x38f4;
  li r6, 0;
  bl unk_80026dc0;
  addi r3, r27, 0x74;
  bl unk_800375f0;
  lis r4, 0x8022;
  addi r5, r1, 8;
  addi r4, r4, 0x38d0;
  li r6, 0;
  bl unk_80026dc0;
lbl_802238bc:
  lmw r27, 0x1c(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  lbz r0, 0(r4);
  stb r0, 0x6d(r3);
  lbz r0, 1(r4);
  stb r0, 0x6e(r3);
  lbz r0, 2(r4);
  stb r0, 0x6f(r3);
  lbz r0, 3(r4);
  stb r0, 0x70(r3);
  blr;
  stb r4, 0x6c(r3);
  blr;
  // clang-format on
}

// Symbol: unk_802238fc
// PAL: 0x802238fc..0x802239bc
MARK_BINARY_BLOB(unk_802238fc, 0x802238fc, 0x802239bc);
asm UNKNOWN_FUNCTION(unk_802238fc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r25, r3;
  mr r26, r4;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802239a8;
  addi r3, r25, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_802239a0;
lbl_8022393c:
  addi r3, r25, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_8022399c;
  bl unk_80029cc0;
  clrlwi r28, r3, 0x10;
  li r27, 0;
  b lbl_80223994;
lbl_80223968:
  mr r3, r29;
  clrlwi r4, r27, 0x10;
  bl unk_80029cd0;
  cmpwi r3, 0;
  beq lbl_80223990;
  lwz r12, 0x1c(r3);
  mr r4, r26;
  lwz r12, 0x28(r12);
  mtctr r12;
  bctrl;
lbl_80223990:
  addi r27, r27, 1;
lbl_80223994:
  cmpw r27, r28;
  blt lbl_80223968;
lbl_8022399c:
  addi r30, r30, 1;
lbl_802239a0:
  cmpw r30, r31;
  blt lbl_8022393c;
lbl_802239a8:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_802239bc
// PAL: 0x802239bc..0x80223a30
MARK_BINARY_BLOB(unk_802239bc, 0x802239bc, 0x80223a30);
asm UNKNOWN_FUNCTION(unk_802239bc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223a04;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  lis r4, 0x8022;
  mr r5, r31;
  addi r4, r4, 0x3a1c;
  li r6, 0;
  bl unk_80026dc0;
lbl_80223a04:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lfs f0, 0(r4);
  stfs f0, 0x58(r3);
  lfs f0, 4(r4);
  stfs f0, 0x5c(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80223a30
// PAL: 0x80223a30..0x80223af0
MARK_BINARY_BLOB(unk_80223a30, 0x80223a30, 0x80223af0);
asm UNKNOWN_FUNCTION(unk_80223a30) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r25, r3;
  mr r26, r4;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223adc;
  addi r3, r25, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_80223ad4;
lbl_80223a70:
  addi r3, r25, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80223ad0;
  bl unk_80029cc0;
  clrlwi r28, r3, 0x10;
  li r27, 0;
  b lbl_80223ac8;
lbl_80223a9c:
  mr r3, r29;
  clrlwi r4, r27, 0x10;
  bl unk_80029cd0;
  cmpwi r3, 0;
  beq lbl_80223ac4;
  lwz r12, 0x1c(r3);
  mr r4, r26;
  lwz r12, 0x2c(r12);
  mtctr r12;
  bctrl;
lbl_80223ac4:
  addi r27, r27, 1;
lbl_80223ac8:
  cmpw r27, r28;
  blt lbl_80223a9c;
lbl_80223ad0:
  addi r30, r30, 1;
lbl_80223ad4:
  cmpw r30, r31;
  blt lbl_80223a70;
lbl_80223adc:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_80223af0
// PAL: 0x80223af0..0x80223b6c
MARK_BINARY_BLOB(unk_80223af0, 0x80223af0, 0x80223b6c);
asm UNKNOWN_FUNCTION(unk_80223af0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223b38;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  lis r4, 0x8022;
  mr r5, r31;
  addi r4, r4, 0x3b50;
  li r6, 0;
  bl unk_80026dc0;
lbl_80223b38:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lfs f0, 0(r4);
  stfs f0, 0x60(r3);
  lfs f0, 4(r4);
  stfs f0, 0x64(r3);
  lfs f0, 8(r4);
  stfs f0, 0x68(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80223b6c
// PAL: 0x80223b6c..0x80223c18
MARK_BINARY_BLOB(unk_80223b6c, 0x80223b6c, 0x80223c18);
asm UNKNOWN_FUNCTION(unk_80223b6c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223bf8;
  addi r3, r28, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi r31, r3, 0x10;
  li r30, 0;
  b lbl_80223bf0;
lbl_80223bb8:
  addi r3, r28, 0x74;
  bl unk_800375f0;
  clrlwi r4, r30, 0x10;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_80223bec;
  lfs f0, 0(r29);
  stfs f0, 0x9c(r3);
  lfs f0, 4(r29);
  stfs f0, 0xa0(r3);
  lfs f0, 8(r29);
  stfs f0, 0xa4(r3);
  bl unk_80029bb0;
lbl_80223bec:
  addi r30, r30, 1;
lbl_80223bf0:
  cmpw r30, r31;
  blt lbl_80223bb8;
lbl_80223bf8:
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

// Symbol: unk_80223c18
// PAL: 0x80223c18..0x80223d14
MARK_BINARY_BLOB(unk_80223c18, 0x80223c18, 0x80223d14);
asm UNKNOWN_FUNCTION(unk_80223c18) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lfs f0, unk_80388ce4;
  cmpwi r5, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stfs f0, 8(r1);
  stfs f0, 0xc(r1);
  beq lbl_80223c54;
  lfs f0, 0(r5);
  stfs f0, 8(r1);
  lfs f0, 4(r5);
  stfs f0, 0xc(r1);
  b lbl_80223cd4;
lbl_80223c54:
  lfs f1, 0(r4);
  lfs f0, unk_80388ce0;
  fcmpo cr0, f1, f0;
  ble lbl_80223c68;
  b lbl_80223c6c;
lbl_80223c68:
  fneg f1, f1;
lbl_80223c6c:
  lfs f0, unk_80388cec;
  fcmpo cr0, f1, f0;
  bge lbl_80223c84;
  lfs f0, unk_80388ce0;
  stfs f0, 8(r1);
  b lbl_80223c94;
lbl_80223c84:
  lfs f1, 8(r1);
  lfs f0, 0(r4);
  fdivs f0, f1, f0;
  stfs f0, 8(r1);
lbl_80223c94:
  lfs f1, 4(r4);
  lfs f0, unk_80388ce0;
  fcmpo cr0, f1, f0;
  ble lbl_80223ca8;
  b lbl_80223cac;
lbl_80223ca8:
  fneg f1, f1;
lbl_80223cac:
  lfs f0, unk_80388cec;
  fcmpo cr0, f1, f0;
  bge lbl_80223cc4;
  lfs f0, unk_80388ce0;
  stfs f0, 0xc(r1);
  b lbl_80223cd4;
lbl_80223cc4:
  lfs f1, 0xc(r1);
  lfs f0, 4(r4);
  fdivs f0, f1, f0;
  stfs f0, 0xc(r1);
lbl_80223cd4:
  lwz r12, 0(r31);
  mr r3, r31;
  lwz r12, 0x70(r12);
  mtctr r12;
  bctrl;
  lwz r12, 0(r31);
  mr r3, r31;
  addi r4, r1, 8;
  lwz r12, 0x58(r12);
  mtctr r12;
  bctrl;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80223d14
// PAL: 0x80223d14..0x80223d30
MARK_BINARY_BLOB(unk_80223d14, 0x80223d14, 0x80223d30);
asm UNKNOWN_FUNCTION(unk_80223d14) {
  // clang-format off
  nofralloc;
  lwz r0, 0x28(r3);
  stfs f1, 0x2c(r3);
  ori r0, r0, 4;
  stw r0, 0x28(r3);
  stfs f1, 0x30(r3);
  stfs f1, 0x34(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80223d30
// PAL: 0x80223d30..0x80223d58
MARK_BINARY_BLOB(unk_80223d30, 0x80223d30, 0x80223d58);
asm UNKNOWN_FUNCTION(unk_80223d30) {
  // clang-format off
  nofralloc;
  lwz r0, 0x28(r3);
  lfs f2, 0(r4);
  lfs f1, 4(r4);
  ori r0, r0, 4;
  lfs f0, 8(r4);
  stw r0, 0x28(r3);
  stfs f2, 0x2c(r3);
  stfs f1, 0x30(r3);
  stfs f0, 0x34(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80223d58
// PAL: 0x80223d58..0x80223d80
MARK_BINARY_BLOB(unk_80223d58, 0x80223d58, 0x80223d80);
asm UNKNOWN_FUNCTION(unk_80223d58) {
  // clang-format off
  nofralloc;
  lwz r0, 0x28(r3);
  lfs f2, 0(r4);
  lfs f1, 4(r4);
  ori r0, r0, 1;
  lfs f0, 8(r4);
  stw r0, 0x28(r3);
  stfs f2, 0x38(r3);
  stfs f1, 0x3c(r3);
  stfs f0, 0x40(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80223d80
// PAL: 0x80223d80..0x80223d9c
MARK_BINARY_BLOB(unk_80223d80, 0x80223d80, 0x80223d9c);
asm UNKNOWN_FUNCTION(unk_80223d80) {
  // clang-format off
  nofralloc;
  mr r5, r3;
  mr r3, r4;
  lwz r0, 0x28(r5);
  addi r4, r5, 0x44;
  ori r0, r0, 2;
  stw r0, 0x28(r5);
  b PSMTXCopy;
  // clang-format on
}

// Symbol: unk_80223d9c
// PAL: 0x80223d9c..0x80223f58
MARK_BINARY_BLOB(unk_80223d9c, 0x80223d9c, 0x80223f58);
asm UNKNOWN_FUNCTION(unk_80223d9c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  cntlzw r0, r5;
  stw r31, 0x2c(r1);
  srwi r31, r0, 5;
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  mr r29, r4;
  stw r28, 0x20(r1);
  mr r28, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80223eb0;
  addi r3, r28, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi. r0, r3, 0x10;
  beq lbl_80223eb0;
  addi r3, r28, 0x74;
  bl unk_800375f0;
  li r4, 0;
  bl unk_80026db0;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80223eb0;
  lwz r6, 0xb8(r3);
  cmpwi r6, 0;
  beq lbl_80223eb0;
  cmpwi r29, 0;
  bge lbl_80223e7c;
  li r29, 0;
  b lbl_80223e54;
lbl_80223e24:
  add r6, r4, r5;
  lwzx r5, r4, r5;
  rlwinm r0, r29, 2, 0xe, 0x1d;
  mr r4, r31;
  add r5, r5, r6;
  addi r3, r1, 0x18;
  addi r5, r5, 4;
  add r5, r5, r0;
  lwz r0, 4(r5);
  stw r0, 0x18(r1);
  bl unk_8004bcb0;
  addi r29, r29, 1;
lbl_80223e54:
  lwz r4, 0xb8(r30);
  lwz r3, 4(r4);
  addi r5, r3, 8;
  lwzx r0, r4, r5;
  add r3, r4, r5;
  add r3, r0, r3;
  lhz r0, 4(r3);
  cmpw r29, r0;
  blt lbl_80223e24;
  b lbl_80223f38;
lbl_80223e7c:
  lwz r5, 4(r6);
  rlwinm r0, r29, 2, 0xe, 0x1d;
  mr r4, r31;
  addi r3, r1, 0x14;
  add r6, r5, r6;
  lwzu r5, 8(r6);
  add r5, r5, r6;
  addi r5, r5, 4;
  add r5, r5, r0;
  lwz r0, 4(r5);
  stw r0, 0x14(r1);
  bl unk_8004bcb0;
  b lbl_80223f38;
lbl_80223eb0:
  bl unk_80035940;
  mr r4, r3;
  addi r3, r1, 0x10;
  addi r5, r28, 4;
  li r6, 0;
  bl unk_80035df0;
  cmpwi r29, 0;
  bge lbl_80223f1c;
  li r29, 0;
  b lbl_80223ef8;
lbl_80223ed8:
  addi r3, r1, 0xc;
  addi r4, r1, 0x10;
  clrlwi r5, r29, 0x10;
  bl unk_8004bc80;
  mr r4, r31;
  addi r3, r1, 0xc;
  bl unk_8004bcb0;
  addi r29, r29, 1;
lbl_80223ef8:
  lwz r3, 0x10(r1);
  lwz r0, 4(r3);
  add r3, r0, r3;
  lwzu r0, 8(r3);
  add r3, r0, r3;
  lhz r0, 4(r3);
  cmpw r29, r0;
  blt lbl_80223ed8;
  b lbl_80223f38;
lbl_80223f1c:
  addi r3, r1, 8;
  addi r4, r1, 0x10;
  clrlwi r5, r29, 0x10;
  bl unk_8004bc80;
  mr r4, r31;
  addi r3, r1, 8;
  bl unk_8004bcb0;
lbl_80223f38:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_80223f58
// PAL: 0x80223f58..0x802240b8
MARK_BINARY_BLOB(unk_80223f58, 0x80223f58, 0x802240b8);
asm UNKNOWN_FUNCTION(unk_80223f58) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stw r31, 0x3c(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802240a4;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  cmpwi r3, 0;
  bne lbl_80223f94;
  li r3, 0;
  b lbl_80223f98;
lbl_80223f94:
  lwz r3, 0xc(r3);
lbl_80223f98:
  cmpwi r3, 1;
  li r0, 0;
  beq lbl_80223fac;
  cmpwi r3, 2;
  bne lbl_80223fb0;
lbl_80223fac:
  li r0, 1;
lbl_80223fb0:
  cmpwi r0, 0;
  beq lbl_80224098;
  lwz r0, 0x28(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80223fd4;
  addi r3, r31, 0x44;
  addi r4, r1, 8;
  bl PSMTXCopy;
  b lbl_80223fdc;
lbl_80223fd4:
  addi r3, r1, 8;
  bl PSMTXIdentity;
lbl_80223fdc:
  lwz r0, 0x28(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_80224060;
  lfs f2, 8(r1);
  lfs f4, 0x2c(r31);
  lfs f1, 0x28(r1);
  fmuls f3, f2, f4;
  lfs f0, 0x18(r1);
  fmuls f1, f1, f4;
  fmuls f2, f0, f4;
  stfs f3, 8(r1);
  lfs f0, 0xc(r1);
  stfs f2, 0x18(r1);
  lfs f4, 0x1c(r1);
  stfs f1, 0x28(r1);
  lfs f3, 0x2c(r1);
  lfs f6, 0x30(r31);
  lfs f2, 0x10(r1);
  fmuls f5, f0, f6;
  lfs f1, 0x20(r1);
  fmuls f4, f4, f6;
  lfs f0, 0x30(r1);
  fmuls f3, f3, f6;
  stfs f5, 0xc(r1);
  stfs f4, 0x1c(r1);
  stfs f3, 0x2c(r1);
  lfs f3, 0x34(r31);
  fmuls f2, f2, f3;
  fmuls f1, f1, f3;
  fmuls f0, f0, f3;
  stfs f2, 0x10(r1);
  stfs f1, 0x20(r1);
  stfs f0, 0x30(r1);
lbl_80224060:
  lwz r0, 0x28(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80224084;
  lfs f0, 0x38(r31);
  stfs f0, 0x14(r1);
  lfs f0, 0x3c(r31);
  stfs f0, 0x24(r1);
  lfs f0, 0x40(r31);
  stfs f0, 0x34(r1);
lbl_80224084:
  addi r3, r31, 0x74;
  bl unk_800375f0;
  addi r4, r1, 8;
  bl unk_80026f30;
  b lbl_802240a4;
lbl_80224098:
  addi r3, r31, 0x74;
  addi r4, r13, -24024;
  bl unk_80037570;
lbl_802240a4:
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: unk_802240b8
// PAL: 0x802240b8..0x80224158
MARK_BINARY_BLOB(unk_802240b8, 0x802240b8, 0x80224158);
asm UNKNOWN_FUNCTION(unk_802240b8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80224124;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi. r0, r3, 0x10;
  beq lbl_80224124;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  li r4, 0;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_80224124;
  lwz r0, 0xb8(r3);
  cmpwi r0, 0;
  beq lbl_80224124;
  addic. r3, r0, 8;
  beq lbl_80224124;
  lhz r3, 0xa(r3);
  b lbl_80224144;
lbl_80224124:
  bl unk_80035940;
  mr r4, r3;
  addi r3, r1, 8;
  addi r5, r31, 4;
  li r6, 0;
  bl unk_80035df0;
  lwz r3, 8(r1);
  lhz r3, 0x12(r3);
lbl_80224144:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80224158
// PAL: 0x80224158..0x802241f8
MARK_BINARY_BLOB(unk_80224158, 0x80224158, 0x802241f8);
asm UNKNOWN_FUNCTION(unk_80224158) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_802241c4;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi. r0, r3, 0x10;
  beq lbl_802241c4;
  addi r3, r31, 0x74;
  bl unk_800375f0;
  li r4, 0;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_802241c4;
  lwz r0, 0xb8(r3);
  cmpwi r0, 0;
  beq lbl_802241c4;
  addic. r3, r0, 8;
  beq lbl_802241c4;
  lfs f1, 0x10(r3);
  b lbl_802241e4;
lbl_802241c4:
  bl unk_80035940;
  mr r4, r3;
  addi r3, r1, 8;
  addi r5, r31, 4;
  li r6, 0;
  bl unk_80035df0;
  lwz r3, 8(r1);
  lfs f1, 0x18(r3);
lbl_802241e4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_802241f8
// PAL: 0x802241f8..0x802242dc
MARK_BINARY_BLOB(unk_802241f8, 0x802241f8, 0x802242dc);
asm UNKNOWN_FUNCTION(unk_802241f8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  addi r3, r3, 0x74;
  bl unk_800375c0;
  cmpwi r3, 0;
  beq lbl_80224284;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  bl unk_80026da0;
  clrlwi. r0, r3, 0x10;
  beq lbl_80224284;
  addi r3, r30, 0x74;
  bl unk_800375f0;
  li r4, 0;
  bl unk_80026db0;
  cmpwi r3, 0;
  beq lbl_80224284;
  lwz r5, 0xb8(r3);
  cmpwi r5, 0;
  beq lbl_80224284;
  lbz r3, 0x96(r5);
  li r4, 1;
  lbz r0, 0x97(r5);
  slw r4, r4, r31;
  rlwimi r0, r3, 8, 0x10, 0x17;
  and r3, r4, r0;
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
  b lbl_802242c4;
lbl_80224284:
  bl unk_80035940;
  mr r4, r3;
  addi r3, r1, 8;
  addi r5, r30, 4;
  li r6, 0;
  bl unk_80035df0;
  lwz r5, 8(r1);
  li r0, 1;
  slw r4, r0, r31;
  lbz r3, 0x96(r5);
  lbz r0, 0x97(r5);
  rlwimi r0, r3, 8, 0x10, 0x17;
  and r3, r4, r0;
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
lbl_802242c4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_802242dc
// PAL: 0x802242dc..0x80224340
MARK_BINARY_BLOB(unk_802242dc, 0x802242dc, 0x80224340);
asm UNKNOWN_FUNCTION(unk_802242dc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lfs f1, unk_80388ce4;
  stw r0, 0x14(r1);
  li r0, 0;
  lfs f0, unk_80388ce0;
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r0, 0x28(r3);
  stfs f1, 0x2c(r3);
  stfs f1, 0x30(r3);
  stfs f1, 0x34(r3);
  stfs f0, 0x38(r3);
  stfs f0, 0x3c(r3);
  stfs f0, 0x40(r3);
  addi r3, r3, 0x44;
  bl PSMTXIdentity;
  addi r3, r31, 0x74;
  addi r4, r13, -24024;
  bl unk_80037570;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80224340
// PAL: 0x80224340..0x80224348
MARK_BINARY_BLOB(unk_80224340, 0x80224340, 0x80224348);
asm UNKNOWN_FUNCTION(unk_80224340) {
  // clang-format off
  nofralloc;
  addi r3, r13, -24024;
  b unk_80037560;
  // clang-format on
}
