#include "g3d_scnrfl.hpp"

// Extern function references.
extern "C" {
// PAL: 0x80005f34
extern UNKNOWN_FUNCTION(memcpy);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80063ee0
extern UNKNOWN_FUNCTION(unk_80063ee0);
// PAL: 0x80064040
extern UNKNOWN_FUNCTION(unk_80064040);
// PAL: 0x80064450
extern UNKNOWN_FUNCTION(Invalidate__Q34nw4r3g3d8G3DStateFUl);
// PAL: 0x8006d790
extern UNKNOWN_FUNCTION(unk_8006d790);
// PAL: 0x8006d7b0
extern UNKNOWN_FUNCTION(unk_8006d7b0);
// PAL: 0x8006d8a0
extern UNKNOWN_FUNCTION(unk_8006d8a0);
// PAL: 0x8006dc80
extern UNKNOWN_FUNCTION(unk_8006dc80);
// PAL: 0x8006e0b0
extern UNKNOWN_FUNCTION(unk_8006e0b0);
// PAL: 0x800c05b0
extern UNKNOWN_FUNCTION(RFLiGetExpressionNum);
// PAL: 0x800c0690
extern UNKNOWN_FUNCTION(RFLInitCharModel);
// PAL: 0x800c0a70
extern UNKNOWN_FUNCTION(RFLSetMtx);
// PAL: 0x800c0ac0
extern UNKNOWN_FUNCTION(RFLSetExpression);
// PAL: 0x800c0b20
extern UNKNOWN_FUNCTION(RFLLoadDrawSetting);
// PAL: 0x800c0e10
extern UNKNOWN_FUNCTION(RFLDrawOpa);
// PAL: 0x800c0e20
extern UNKNOWN_FUNCTION(RFLDrawXlu);
// PAL: 0x80199b98
extern UNKNOWN_FUNCTION(MEMAllocFromAllocator);

extern double unk_80389130;
extern float unk_8038912c, unk_80389128;
extern float unk_80389138;
}

// Symbol: unk_802443ac
// PAL: 0x802443ac..0x802443c8
MARK_BINARY_BLOB(unk_802443ac, 0x802443ac, 0x802443c8);
asm UNKNOWN_FUNCTION(unk_802443ac) {
  // clang-format off
  nofralloc;
  cmplwi r4, 0x7f;
  ble lbl_802443c0;
  li r0, -1;
  stb r0, 0xf0(r3);
  blr;
lbl_802443c0:
  stb r4, 0xf0(r3);
  blr;
  // clang-format on
}

// Symbol: unk_802443c8
// PAL: 0x802443c8..0x802443e4
MARK_BINARY_BLOB(unk_802443c8, 0x802443c8, 0x802443e4);
asm UNKNOWN_FUNCTION(unk_802443c8) {
  // clang-format off
  nofralloc;
  cmplwi r4, 0x7f;
  ble lbl_802443dc;
  li r0, -1;
  stb r0, 0xf1(r3);
  blr;
lbl_802443dc:
  stb r4, 0xf1(r3);
  blr;
  // clang-format on
}

// Symbol: unk_802443e4
// PAL: 0x802443e4..0x80244420
MARK_BINARY_BLOB(unk_802443e4, 0x802443e4, 0x80244420);
asm UNKNOWN_FUNCTION(unk_802443e4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lbz r0, 0xf3(r3);
  extsb. r0, r0;
  beq lbl_8024440c;
  addi r3, r3, 0x110;
  bl RFLSetExpression;
  li r3, 1;
  b lbl_80244410;
lbl_8024440c:
  li r3, 0;
lbl_80244410:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80244420
// PAL: 0x80244420..0x802444b0
MARK_BINARY_BLOB(unk_80244420, 0x80244420, 0x802444b0);
asm UNKNOWN_FUNCTION(unk_80244420) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl unk_80244504;
  lwz r7, 0x100(r28);
  mr r4, r29;
  lwz r8, 0xe8(r28);
  mr r5, r31;
  lwz r9, 0xec(r28);
  mr r6, r30;
  addi r3, r28, 0x110;
  bl RFLInitCharModel;
  cmpwi r3, 0;
  stw r3, 0x104(r28);
  beq lbl_80244484;
  li r3, 0;
  b lbl_80244490;
lbl_80244484:
  li r0, 1;
  stb r0, 0xf3(r28);
  li r3, 1;
lbl_80244490:
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

// Symbol: unk_802444b0
// PAL: 0x802444b0..0x80244504
MARK_BINARY_BLOB(unk_802444b0, 0x802444b0, 0x80244504);
asm UNKNOWN_FUNCTION(unk_802444b0) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl unk_80244504;
  mr r4, r31;
  addi r3, r30, 0x110;
  li r5, 0x88;
  bl memcpy;
  li r0, 1;
  stb r0, 0xf3(r30);
  li r3, 1;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80244504
// PAL: 0x80244504..0x8024451c
MARK_BINARY_BLOB(unk_80244504, 0x80244504, 0x8024451c);
asm UNKNOWN_FUNCTION(unk_80244504) {
  // clang-format off
  nofralloc;
  lbz r0, 0xf3(r3);
  extsb. r0, r0;
  beqlr;
  li r0, 0;
  stb r0, 0xf3(r3);
  blr;
  // clang-format on
}

// Symbol: unk_8024451c
// PAL: 0x8024451c..0x802445ec
MARK_BINARY_BLOB(unk_8024451c, 0x8024451c, 0x802445ec);
asm UNKNOWN_FUNCTION(unk_8024451c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  cmpwi r8, 0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  li r30, 0;
  beq lbl_8024455c;
  mr r3, r27;
  mr r4, r28;
  bl RFLiGetExpressionNum;
  b lbl_80244560;
lbl_8024455c:
  li r3, 0;
lbl_80244560:
  addi r0, r29, 0x1b7;
  cmpwi r26, 0;
  rlwinm r31, r0, 0, 0, 0x1a;
  add r3, r31, r3;
  addi r0, r3, 0x1f;
  rlwinm r4, r0, 0, 0, 0x1a;
  beq lbl_80244580;
  stw r4, 0(r26);
lbl_80244580:
  cmpwi r25, 0;
  beq lbl_802445d4;
  mr r3, r25;
  bl MEMAllocFromAllocator;
  cmpwi r3, 0;
  bne lbl_802445a0;
  li r3, 0;
  b lbl_802445d8;
lbl_802445a0:
  mr r30, r3;
  beq lbl_802445d4;
  cmpwi r29, 0;
  mr r4, r25;
  add r5, r3, r31;
  beq lbl_802445c0;
  addi r6, r3, 0x198;
  b lbl_802445c4;
lbl_802445c0:
  li r6, 0;
lbl_802445c4:
  mr r7, r27;
  mr r8, r28;
  bl unk_80244c0c;
  mr r30, r3;
lbl_802445d4:
  mr r3, r30;
lbl_802445d8:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_802445ec
// PAL: 0x802445ec..0x80244920
MARK_BINARY_BLOB(unk_802445ec, 0x802445ec, 0x80244920);
asm UNKNOWN_FUNCTION(unk_802445ec) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  cmplwi r4, 9;
  stw r0, 0x54(r1);
  mr r0, r5;
  stw r31, 0x4c(r1);
  mr r31, r6;
  stw r30, 0x48(r1);
  mr r30, r3;
  stw r5, 8(r1);
  bge lbl_80244638;
  addi r6, r4, -1;
  li r7, 1;
  lwz r5, 0xcc(r3);
  slw r6, r7, r6;
  and. r5, r6, r5;
  beq lbl_80244638;
  li r5, 1;
  b lbl_8024463c;
lbl_80244638:
  li r5, 0;
lbl_8024463c:
  cmpwi r5, 0;
  bne lbl_80244908;
  cmplwi r4, 5;
  beq lbl_80244670;
  cmplwi r4, 1;
  beq lbl_80244694;
  cmplwi r4, 4;
  beq lbl_80244784;
  cmplwi r4, 6;
  beq lbl_80244880;
  cmplwi r4, 7;
  beq lbl_802448bc;
  b lbl_802448f8;
lbl_80244670:
  lwz r12, 0(r31);
  mr r3, r31;
  mr r4, r30;
  li r5, 1;
  lwz r12, 0xc(r12);
  li r6, 1;
  mtctr r12;
  bctrl;
  b lbl_80244908;
lbl_80244694:
  lwz r5, 0xd4(r3);
  cmpwi r5, 0;
  beq lbl_802446dc;
  lhz r4, 0xda(r3);
  clrlwi. r4, r4, 0x1f;
  beq lbl_802446dc;
  lbz r3, 0xd8(r3);
  clrlwi. r3, r3, 0x1f;
  beq lbl_802446dc;
  mr r3, r5;
  mr r5, r30;
  lwz r12, 0(r3);
  mr r6, r0;
  mr r7, r31;
  li r4, 1;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
lbl_802446dc:
  lwz r12, 0(r30);
  mr r3, r30;
  mr r4, r31;
  addi r5, r1, 8;
  lwz r12, 0x30(r12);
  mtctr r12;
  bctrl;
  lwz r3, 0xd4(r30);
  lwz r6, 8(r1);
  cmpwi r3, 0;
  beq lbl_8024473c;
  lhz r0, 0xda(r30);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8024473c;
  lbz r0, 0xd8(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8024473c;
  lwz r12, 0(r3);
  mr r5, r30;
  mr r7, r31;
  li r4, 2;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
lbl_8024473c:
  lwz r3, 0xd4(r30);
  lwz r6, 8(r1);
  cmpwi r3, 0;
  beq lbl_80244908;
  lhz r0, 0xda(r30);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80244908;
  lbz r0, 0xd8(r30);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_80244908;
  lwz r12, 0(r3);
  mr r5, r30;
  mr r7, r31;
  li r4, 4;
  lwz r12, 0xc(r12);
  mtctr r12;
  bctrl;
  b lbl_80244908;
lbl_80244784:
  lwz r5, 0xd4(r3);
  cmpwi r5, 0;
  beq lbl_802447cc;
  lhz r4, 0xda(r3);
  rlwinm. r4, r4, 0, 0x1d, 0x1d;
  beq lbl_802447cc;
  lbz r3, 0xd8(r3);
  clrlwi. r3, r3, 0x1f;
  beq lbl_802447cc;
  mr r3, r5;
  mr r5, r30;
  lwz r12, 0(r3);
  mr r6, r0;
  mr r7, r31;
  li r4, 1;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
lbl_802447cc:
  mr r3, r30;
  mr r4, r31;
  bl unk_8006d790;
  lwz r3, 0xd4(r30);
  lwz r6, 8(r1);
  cmpwi r3, 0;
  beq lbl_8024481c;
  lhz r0, 0xda(r30);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8024481c;
  lbz r0, 0xd8(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8024481c;
  lwz r12, 0(r3);
  mr r5, r30;
  mr r7, r31;
  li r4, 2;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
lbl_8024481c:
  mr r3, r30;
  addi r5, r1, 0x10;
  li r4, 2;
  bl unk_8006dc80;
  addi r3, r30, 0x110;
  addi r4, r1, 0x10;
  bl RFLSetMtx;
  lwz r3, 0xd4(r30);
  lwz r6, 8(r1);
  cmpwi r3, 0;
  beq lbl_80244908;
  lhz r0, 0xda(r30);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_80244908;
  lbz r0, 0xd8(r30);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_80244908;
  lwz r12, 0(r3);
  mr r5, r30;
  mr r7, r31;
  li r4, 4;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  b lbl_80244908;
lbl_80244880:
  lbz r0, 0xf3(r3);
  extsb. r0, r0;
  beq lbl_80244908;
  lwz r0, 0x108(r3);
  cmpwi r0, 0;
  bne lbl_802448ac;
  mr r3, r30;
  bl unk_80244a94;
  addi r3, r30, 0x110;
  bl RFLDrawOpa;
  b lbl_80244908;
lbl_802448ac:
  mr r3, r30;
  li r4, 1;
  bl unk_80244920;
  b lbl_80244908;
lbl_802448bc:
  lbz r0, 0xf3(r3);
  extsb. r0, r0;
  beq lbl_80244908;
  lwz r0, 0x108(r3);
  cmpwi r0, 0;
  bne lbl_802448e8;
  mr r3, r30;
  bl unk_80244a94;
  addi r3, r30, 0x110;
  bl RFLDrawXlu;
  b lbl_80244908;
lbl_802448e8:
  mr r3, r30;
  li r4, 0;
  bl unk_80244920;
  b lbl_80244908;
lbl_802448f8:
  mr r3, r30;
  mr r5, r0;
  mr r6, r31;
  bl unk_8006e0b0;
lbl_80244908:
  lwz r0, 0x54(r1);
  lwz r31, 0x4c(r1);
  lwz r30, 0x48(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: unk_80244920
// PAL: 0x80244920..0x80244a94
MARK_BINARY_BLOB(unk_80244920, 0x80244920, 0x80244a94);
asm UNKNOWN_FUNCTION(unk_80244920) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  lis r0, 0x4330;
  stw r31, 0x5c(r1);
  mr r31, r4;
  stw r30, 0x58(r1);
  mr r30, r3;
  lbz r3, 0xf1(r3);
  stw r0, 0x20(r1);
  extsb r3, r3;
  stw r0, 0x28(r1);
  bl unk_80063ee0;
  lbz r3, 0xf0(r30);
  addi r4, r1, 0x18;
  addi r5, r1, 0x14;
  addi r6, r1, 0x10;
  extsb r3, r3;
  bl unk_80064040;
  lbz r4, 0x10(r1);
  li r3, 0x4ff;
  lbz r0, 0xf4(r30);
  lbz r8, 0x11(r1);
  mullw r9, r4, r0;
  lbz r7, 0xf5(r30);
  lbz r6, 0x12(r1);
  lbz r5, 0xf6(r30);
  lbz r4, 0x13(r1);
  lbz r0, 0xf7(r30);
  mullw r7, r8, r7;
  xoris r8, r9, 0x8000;
  stw r8, 0x24(r1);
  lfd f6, unk_80389130;
  lfd f0, 0x20(r1);
  lfs f5, unk_8038912c;
  mullw r5, r6, r5;
  xoris r6, r7, 0x8000;
  fsubs f1, f0, f6;
  stw r6, 0x2c(r1);
  lfs f4, unk_80389128;
  lfd f0, 0x28(r1);
  mullw r0, r4, r0;
  xoris r4, r5, 0x8000;
  fsubs f2, f0, f6;
  stw r4, 0x24(r1);
  fmuls f3, f5, f1;
  lfd f0, 0x20(r1);
  xoris r0, r0, 0x8000;
  fsubs f1, f0, f6;
  stw r0, 0x2c(r1);
  fmuls f2, f5, f2;
  fadds f3, f4, f3;
  lfd f0, 0x28(r1);
  fmuls f1, f5, f1;
  fadds f2, f4, f2;
  fsubs f0, f0, f6;
  fadds f1, f4, f1;
  fctiwz f3, f3;
  fmuls f0, f5, f0;
  fctiwz f2, f2;
  stfd f3, 0x30(r1);
  fctiwz f1, f1;
  fadds f0, f4, f0;
  stfd f2, 0x38(r1);
  lwz r6, 0x34(r1);
  stfd f1, 0x40(r1);
  fctiwz f0, f0;
  lwz r5, 0x3c(r1);
  lwz r4, 0x44(r1);
  stfd f0, 0x48(r1);
  lwz r0, 0x4c(r1);
  stb r6, 0xc(r1);
  stb r5, 0xd(r1);
  stb r4, 0xe(r1);
  stb r0, 0xf(r1);
  bl Invalidate__Q34nw4r3g3d8G3DStateFUl;
  lwz r0, 0xc(r1);
  mr r3, r30;
  stw r0, 8(r1);
  mr r8, r31;
  addi r4, r30, 0x110;
  addi r7, r1, 8;
  lwz r12, 0x108(r30);
  lwz r5, 0x18(r1);
  lwz r6, 0x14(r1);
  mtctr r12;
  bctrl;
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: unk_80244a94
// PAL: 0x80244a94..0x80244c0c
MARK_BINARY_BLOB(unk_80244a94, 0x80244a94, 0x80244c0c);
asm UNKNOWN_FUNCTION(unk_80244a94) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  lis r0, 0x4330;
  stw r31, 0x6c(r1);
  mr r31, r3;
  lbz r3, 0xf1(r3);
  stw r0, 0x30(r1);
  extsb r3, r3;
  stw r0, 0x38(r1);
  bl unk_80063ee0;
  lbz r3, 0xf0(r31);
  addi r4, r1, 0x10;
  addi r5, r1, 0xc;
  addi r6, r1, 8;
  extsb r3, r3;
  bl unk_80064040;
  lbz r4, 0xf0(r31);
  li r3, 0x4ff;
  lwz r0, 0x10(r1);
  extsb r4, r4;
  stw r0, 0x1c(r1);
  srwi r0, r4, 0x1f;
  lbz r4, 8(r1);
  xori r0, r0, 1;
  stb r0, 0x18(r1);
  lfd f3, unk_80389130;
  lwz r0, 0xf8(r31);
  stw r0, 0x20(r1);
  lfs f2, unk_8038912c;
  lwz r0, 0xfc(r31);
  stw r0, 0x24(r1);
  lfs f1, unk_80389128;
  lbz r0, 0xf2(r31);
  stb r0, 0x2c(r1);
  lbz r6, 9(r1);
  lbz r0, 0xf4(r31);
  lbz r5, 0xa(r1);
  mullw r0, r4, r0;
  lbz r4, 0xb(r1);
  xoris r0, r0, 0x8000;
  stw r0, 0x34(r1);
  lfd f0, 0x30(r1);
  fsubs f0, f0, f3;
  fmuls f0, f2, f0;
  fadds f0, f1, f0;
  fctiwz f0, f0;
  stfd f0, 0x40(r1);
  lwz r0, 0x44(r1);
  stb r0, 0x28(r1);
  lbz r0, 0xf5(r31);
  mullw r0, r6, r0;
  xoris r0, r0, 0x8000;
  stw r0, 0x3c(r1);
  lfd f0, 0x38(r1);
  fsubs f0, f0, f3;
  fmuls f0, f2, f0;
  fadds f0, f1, f0;
  fctiwz f0, f0;
  stfd f0, 0x48(r1);
  lwz r0, 0x4c(r1);
  stb r0, 0x29(r1);
  lbz r0, 0xf6(r31);
  mullw r0, r5, r0;
  xoris r0, r0, 0x8000;
  stw r0, 0x34(r1);
  lfd f0, 0x30(r1);
  fsubs f0, f0, f3;
  fmuls f0, f2, f0;
  fadds f0, f1, f0;
  fctiwz f0, f0;
  stfd f0, 0x50(r1);
  lwz r0, 0x54(r1);
  stb r0, 0x2a(r1);
  lbz r0, 0xf7(r31);
  mullw r0, r4, r0;
  xoris r0, r0, 0x8000;
  stw r0, 0x3c(r1);
  lfd f0, 0x38(r1);
  fsubs f0, f0, f3;
  fmuls f0, f2, f0;
  fadds f0, f1, f0;
  fctiwz f0, f0;
  stfd f0, 0x58(r1);
  lwz r0, 0x5c(r1);
  stb r0, 0x2b(r1);
  bl Invalidate__Q34nw4r3g3d8G3DStateFUl;
  addi r3, r1, 0x18;
  bl RFLLoadDrawSetting;
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: unk_80244c0c
// PAL: 0x80244c0c..0x80244cc8
MARK_BINARY_BLOB(unk_80244c0c, 0x80244c0c, 0x80244cc8);
asm UNKNOWN_FUNCTION(unk_80244c0c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  mr r31, r8;
  bl unk_8006d7b0;
  lfs f0, unk_80389138;
  lis r9, 0x802a;
  li r6, 0;
  li r4, 0x40;
  li r8, -1;
  li r7, 1;
  addi r9, r9, 0x4008;
  li r5, 2;
  li r0, 0xff;
  stfs f0, 0xdc(r27);
  addi r11, r1, 0x20;
  mr r3, r27;
  stfs f0, 0xe0(r27);
  stfs f0, 0xe4(r27);
  stw r9, 0(r27);
  stw r30, 0xe8(r27);
  stw r31, 0xec(r27);
  stb r8, 0xf0(r27);
  stb r8, 0xf1(r27);
  stb r7, 0xf2(r27);
  stb r6, 0xf3(r27);
  stw r5, 0xf8(r27);
  stw r7, 0xfc(r27);
  stw r28, 0x100(r27);
  stw r6, 0x104(r27);
  stw r6, 0x108(r27);
  stw r29, 0x10c(r27);
  stb r4, 0xf6(r27);
  stb r4, 0xf5(r27);
  stb r4, 0xf4(r27);
  stb r0, 0xf7(r27);
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: unk_80244cc8
// PAL: 0x80244cc8..0x80244d30
MARK_BINARY_BLOB(unk_80244cc8, 0x80244cc8, 0x80244d30);
asm UNKNOWN_FUNCTION(unk_80244cc8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_80244d18;
  lbz r0, 0xf3(r3);
  lis r4, 0x802a;
  addi r4, r4, 0x4008;
  stw r4, 0(r3);
  extsb. r0, r0;
  beq lbl_80244d04;
  li r0, 0;
  stb r0, 0xf3(r3);
lbl_80244d04:
  cmpwi r3, 0;
  beq lbl_80244d18;
  mr r3, r31;
  li r4, 0;
  bl unk_8006d8a0;
lbl_80244d18:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80244d30
// PAL: 0x80244d30..0x80244d3c
MARK_BINARY_BLOB(unk_80244d30, 0x80244d30, 0x80244d3c);
asm UNKNOWN_FUNCTION(unk_80244d30) {
  // clang-format off
  nofralloc;
  lis r3, 0x8026;
  addi r3, r3, -31392;
  blr;
  // clang-format on
}

// Symbol: unk_80244d3c
// PAL: 0x80244d3c..0x80244dd4
MARK_BINARY_BLOB(unk_80244d3c, 0x80244d3c, 0x80244dd4);
asm UNKNOWN_FUNCTION(unk_80244d3c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  addi r3, r3, 4;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lis r3, 0x8026;
  lwz r0, 0(r4);
  addi r3, r3, -31392;
  cmplw r0, r3;
  bne lbl_80244d88;
  li r3, 1;
  blr;
lbl_80244d88:
  lis r3, 0x8024;
  lwz r0, 0(r4);
  addi r3, r3, 0x7f80;
  cmplw r0, r3;
  bne lbl_80244da4;
  li r3, 1;
  blr;
lbl_80244da4:
  lis r3, 0x8024;
  addi r3, r3, 0x7f70;
  cmplw r0, r3;
  bne lbl_80244dbc;
  li r3, 1;
  blr;
lbl_80244dbc:
  lis r3, 0x8024;
  addi r3, r3, 0x76c8;
  subf r0, r0, r3;
  cntlzw r0, r0;
  srwi r3, r0, 5;
  blr;
  // clang-format on
}
