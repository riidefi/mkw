#include "bte_logmsg.h"

#include <stdio.h>
#include <rvl/os/osError.h>

// Symbol: LogMsg
// PAL: 0x80131684..0x80131740
MARK_BINARY_BLOB(LogMsg, 0x80131684, 0x80131740);
asm UNKNOWN_FUNCTION(LogMsg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stw r31, 0x7c(r1);
  stw r30, 0x78(r1);
  bne cr1, lbl_801316bc;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_801316bc:
  addi r11, r1, 0x88;
  addi r0, r1, 8;
  lis r12, 0x200;
  stw r4, 0xc(r1);
  addi r30, r1, 0x68;
  lis r31, 0x8033;
  stw r3, 8(r1);
  addi r3, r31, 0x4540;
  stw r5, 0x10(r1);
  mr r5, r30;
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  stw r12, 0x68(r1);
  stw r11, 0x6c(r1);
  stw r0, 0x70(r1);
  bl vsprintf;
  addi r3, r31, 0x4540;
  addi r4, r13, -29616;
  mr r5, r3;
  crclr 6;
  bl sprintf;
  addi r3, r31, 0x4540;
  crclr 6;
  bl OSReport;
  lwz r0, 0x84(r1);
  lwz r31, 0x7c(r1);
  lwz r30, 0x78(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: LogMsg_0
// PAL: 0x80131740..0x80131758
MARK_BINARY_BLOB(LogMsg_0, 0x80131740, 0x80131758);
asm UNKNOWN_FUNCTION(LogMsg_0) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}

// Symbol: LogMsg_1
// PAL: 0x80131758..0x80131770
MARK_BINARY_BLOB(LogMsg_1, 0x80131758, 0x80131770);
asm UNKNOWN_FUNCTION(LogMsg_1) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}

// Symbol: LogMsg_2
// PAL: 0x80131770..0x80131788
MARK_BINARY_BLOB(LogMsg_2, 0x80131770, 0x80131788);
asm UNKNOWN_FUNCTION(LogMsg_2) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}

// Symbol: LogMsg_3
// PAL: 0x80131788..0x801317a0
MARK_BINARY_BLOB(LogMsg_3, 0x80131788, 0x801317a0);
asm UNKNOWN_FUNCTION(LogMsg_3) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}

// Symbol: LogMsg_4
// PAL: 0x801317a0..0x801317b8
MARK_BINARY_BLOB(LogMsg_4, 0x801317a0, 0x801317b8);
asm UNKNOWN_FUNCTION(LogMsg_4) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}

// Symbol: LogMsg_5
// PAL: 0x801317b8..0x801317d0
MARK_BINARY_BLOB(LogMsg_5, 0x801317b8, 0x801317d0);
asm UNKNOWN_FUNCTION(LogMsg_5) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}

// Symbol: LogMsg_6
// PAL: 0x801317d0..0x801317e8
MARK_BINARY_BLOB(LogMsg_6, 0x801317d0, 0x801317e8);
asm UNKNOWN_FUNCTION(LogMsg_6) {
  // clang-format off
  nofralloc;
  lbz r0, -0x6620(r13);
  cmpwi r0, 0;
  bnelr;
  crclr 6;
  b LogMsg;
  blr;
  // clang-format on
}
