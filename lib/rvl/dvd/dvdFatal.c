#include "dvdFatal.h"

#include <rvl/os/osFatal.h>
#include <rvl/os/osFont.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/gx/gx.h>

// Extern function references.
// PAL: 0x801b1d0c
extern UNKNOWN_FUNCTION(SCGetLanguage);
// PAL: 0x801b24c8
extern UNKNOWN_FUNCTION(SCGetProductGameRegion);

static const GXColor color = {0xff, 0xff, 0xff, 0x00};

// Symbol: __DVDShowFatalMessage
// PAL: 0x80164294..0x80164364
MARK_BINARY_BLOB(__DVDShowFatalMessage, 0x80164294, 0x80164364);
asm UNKNOWN_FUNCTION(__DVDShowFatalMessage) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  lbz r5, color.r;
  lbz r4, color.g;
  lbz r3, color.b;
  lbz r0, color.a;
  stb r5, 0x10(r1);
  stb r4, 0x11(r1);
  stb r3, 0x12(r1);
  stb r0, 0x13(r1);
  bl SCGetLanguage;
  clrlwi. r0, r3, 0x18;
  bne lbl_801642e4;
  li r3, 1;
  bl OSSetFontEncode;
  b lbl_801642ec;
lbl_801642e4:
  li r3, 0;
  bl OSSetFontEncode;
lbl_801642ec:
  bl SCGetProductGameRegion;
  extsb r0, r3;
  cmpwi r0, 2;
  beq lbl_80164308;
  lis r30, 0x8025;
  addi r30, r30, -12848;
  b lbl_80164310;
lbl_80164308:
  lis r30, 0x8025;
  addi r30, r30, -12820;
lbl_80164310:
  bl SCGetLanguage;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 6;
  ble lbl_80164328;
  lwz r5, 4(r30);
  b lbl_80164334;
lbl_80164328:
  bl SCGetLanguage;
  rlwinm r0, r3, 2, 0x16, 0x1d;
  lwzx r5, r30, r0;
lbl_80164334:
  lwz r0, 0x10(r1);
  addi r3, r1, 0xc;
  stw r31, 8(r1);
  addi r4, r1, 8;
  stw r0, 0xc(r1);
  bl OSFatal;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DVDSetAutoFatalMessaging
// PAL: 0x80164364..0x801643c0
MARK_BINARY_BLOB(DVDSetAutoFatalMessaging, 0x80164364, 0x801643c0);
asm UNKNOWN_FUNCTION(DVDSetAutoFatalMessaging) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r5, -0x64f8(r13);
  cmpwi r31, 0;
  li r4, 0;
  neg r0, r5;
  or r0, r0, r5;
  srwi r31, r0, 0x1f;
  beq lbl_801643a0;
  lis r4, 0x8016;
  addi r4, r4, 0x4294;
lbl_801643a0:
  stw r4, -0x64f8(r13);
  bl OSRestoreInterrupts;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDGetAutoFatalMessaging
// PAL: 0x801643c0..0x801643d4
MARK_BINARY_BLOB(__DVDGetAutoFatalMessaging, 0x801643c0, 0x801643d4);
asm UNKNOWN_FUNCTION(__DVDGetAutoFatalMessaging) {
  // clang-format off
  nofralloc;
  lwz r3, -0x64f8(r13);
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
  blr;
  // clang-format on
}

// Symbol: __DVDPrintFatalMessage
// PAL: 0x801643d4..0x801643ec
MARK_BINARY_BLOB(__DVDPrintFatalMessage, 0x801643d4, 0x801643ec);
asm UNKNOWN_FUNCTION(__DVDPrintFatalMessage) {
  // clang-format off
  nofralloc;
  lwz r12, -0x64f8(r13);
  cmpwi r12, 0;
  beqlr;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}
