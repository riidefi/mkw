#include "eggXfbManager.hpp"

// Extern function references.
// PAL: 0x8016e654
extern "C" UNKNOWN_FUNCTION(GXFlush);
// PAL: 0x8016fc38
extern "C" UNKNOWN_FUNCTION(GXCopyDisp);
// PAL: 0x801727cc
extern "C" UNKNOWN_FUNCTION(GXSetColorUpdate);
// PAL: 0x801727f8
extern "C" UNKNOWN_FUNCTION(GXSetAlphaUpdate);
// PAL: 0x80172824
extern "C" UNKNOWN_FUNCTION(GXSetZMode);
// PAL: 0x801a65ac
extern "C" UNKNOWN_FUNCTION(OSDisableInterrupts);
// PAL: 0x801a65d4
extern "C" UNKNOWN_FUNCTION(OSRestoreInterrupts);
// PAL: 0x801ba9a4
extern "C" UNKNOWN_FUNCTION(VIFlush);
// PAL: 0x801baab8
extern "C" UNKNOWN_FUNCTION(VISetNextFrameBuffer);
// PAL: 0x801bab24
extern "C" UNKNOWN_FUNCTION(VIGetNextFrameBuffer);

// Symbol: attach__Q23EGG10XfbManagerFPQ23EGG3Xfb
// PAL: 0x80244200..0x80244268
MARK_BINARY_BLOB(attach__Q23EGG10XfbManagerFPQ23EGG3Xfb, 0x80244200,
                 0x80244268);
asm UNKNOWN_FUNCTION(attach__Q23EGG10XfbManagerFPQ23EGG3Xfb) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  li r0, 0;
  beq lbl_80244260;
  lwz r5, 0(r3);
  cmpwi r5, 0;
  bne lbl_8024422c;
  stw r4, 0(r3);
  stw r4, 4(r3);
  stw r4, 8(r4);
  stw r4, 0xc(r4);
  b lbl_8024425c;
lbl_8024422c:
  lwz r5, 0xc(r5);
  stw r4, 8(r5);
  lwz r5, 0(r3);
  lwz r0, 0xc(r5);
  stw r0, 0xc(r4);
  lwz r5, 0(r3);
  stw r4, 0xc(r5);
  lwz r0, 0(r3);
  stw r0, 8(r4);
  lwz r4, 0(r3);
  lwz r0, 8(r4);
  stw r0, 4(r3);
lbl_8024425c:
  li r0, 1;
lbl_80244260:
  mr r3, r0;
  blr;
  // clang-format on
}

// Symbol: copyEFB__Q23EGG10XfbManagerFb
// PAL: 0x80244268..0x802442e8
MARK_BINARY_BLOB(copyEFB__Q23EGG10XfbManagerFb, 0x80244268, 0x802442e8);
asm UNKNOWN_FUNCTION(copyEFB__Q23EGG10XfbManagerFb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_802442ac;
  li r3, 1;
  li r4, 7;
  li r5, 1;
  bl GXSetZMode;
  li r3, 1;
  bl GXSetAlphaUpdate;
  li r3, 1;
  bl GXSetColorUpdate;
lbl_802442ac:
  lwz r3, 4(r30);
  clrlwi r4, r31, 0x18;
  lwz r3, 4(r3);
  bl GXCopyDisp;
  bl GXFlush;
  lwz r3, 4(r30);
  stw r3, 8(r30);
  lwz r0, 8(r3);
  stw r0, 4(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: setNextFrameBuffer__Q23EGG10XfbManagerFv
// PAL: 0x802442e8..0x80244350
MARK_BINARY_BLOB(setNextFrameBuffer__Q23EGG10XfbManagerFv, 0x802442e8,
                 0x80244350);
asm UNKNOWN_FUNCTION(setNextFrameBuffer__Q23EGG10XfbManagerFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r4, 8(r30);
  mr r31, r3;
  cmpwi r4, 0;
  beq lbl_80244330;
  lwz r3, 4(r4);
  bl VISetNextFrameBuffer;
  bl VIFlush;
  lwz r3, 8(r30);
  li r0, 0;
  stw r3, 0xc(r30);
  stw r0, 8(r30);
lbl_80244330:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: postVRetrace__Q23EGG10XfbManagerFv
// PAL: 0x80244350..0x802443ac
MARK_BINARY_BLOB(postVRetrace__Q23EGG10XfbManagerFv, 0x80244350, 0x802443ac);
asm UNKNOWN_FUNCTION(postVRetrace__Q23EGG10XfbManagerFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r4, 0xc(r3);
  cmpwi r4, 0;
  beq lbl_80244394;
  lwz r31, 4(r4);
  bl VIGetNextFrameBuffer;
  cmplw r31, r3;
  bne lbl_80244394;
  lwz r3, 0xc(r30);
  li r0, 0;
  stw r3, 0(r30);
  stw r0, 0xc(r30);
lbl_80244394:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
