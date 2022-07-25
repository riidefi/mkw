#include "dsp.h"

#include <rvl/os/os.h>
#include <rvl/os/osInterrupt.h>

#include "dspPrintf.h"
#include "dspTask.h"

static u32 unk_80386608;

// Symbol: DSPCheckMailToDSP
// PAL: 0x8015d3fc..0x8015d40c
MARK_BINARY_BLOB(DSPCheckMailToDSP, 0x8015d3fc, 0x8015d40c);
asm UNKNOWN_FUNCTION(DSPCheckMailToDSP) {
  // clang-format off
  nofralloc;
  lis r3, 0xcc00;
  lhz r0, 0x5000(r3);
  rlwinm r3, r0, 0x11, 0x1f, 0x1f;
  blr;
  // clang-format on
}

// Symbol: DSPCheckMailFromDSP
// PAL: 0x8015d40c..0x8015d41c
MARK_BINARY_BLOB(DSPCheckMailFromDSP, 0x8015d40c, 0x8015d41c);
asm UNKNOWN_FUNCTION(DSPCheckMailFromDSP) {
  // clang-format off
  nofralloc;
  lis r3, 0xcc00;
  lhz r0, 0x5004(r3);
  rlwinm r3, r0, 0x11, 0x1f, 0x1f;
  blr;
  // clang-format on
}

// Symbol: DSPReadMailFromDSP
// PAL: 0x8015d41c..0x8015d430
MARK_BINARY_BLOB(DSPReadMailFromDSP, 0x8015d41c, 0x8015d430);
asm UNKNOWN_FUNCTION(DSPReadMailFromDSP) {
  // clang-format off
  nofralloc;
  lis r3, 0xcc00;
  lhz r0, 0x5004(r3);
  lhz r3, 0x5006(r3);
  rlwimi r3, r0, 0x10, 0, 0xf;
  blr;
  // clang-format on
}

// Symbol: DSPSendMailToDSP
// PAL: 0x8015d430..0x8015d444
MARK_BINARY_BLOB(DSPSendMailToDSP, 0x8015d430, 0x8015d444);
asm UNKNOWN_FUNCTION(DSPSendMailToDSP) {
  // clang-format off
  nofralloc;
  lis r4, 0xcc00;
  srwi r0, r3, 0x10;
  sth r0, 0x5000(r4);
  sth r3, 0x5002(r4);
  blr;
  // clang-format on
}

// Symbol: DSPInit
// PAL: 0x8015d444..0x8015d504
MARK_BINARY_BLOB(DSPInit, 0x8015d444, 0x8015d504);
asm UNKNOWN_FUNCTION(DSPInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8029;
  stw r0, 0x14(r1);
  addi r5, r5, -32672;
  addi r3, r5, 0x48;
  stw r31, 0xc(r1);
  addi r4, r5, 0x68;
  addi r5, r5, 0x74;
  crclr 6;
  bl __DSP_debug_printf;
  lwz r0, unk_80386608;
  cmpwi r0, 1;
  beq lbl_8015d4f0;
  lwz r3, -0x7350(r13);
  bl OSRegisterVersion;
  bl OSDisableInterrupts;
  lis r4, 0x8016;
  mr r31, r3;
  addi r4, r4, -10616;
  li r3, 7;
  bl __OSSetInterruptHandler;
  lis r3, 0x100;
  bl __OSUnmaskInterrupts;
  lis r7, 0xcc00;
  li r3, -169;
  lhz r6, 0x500a(r7);
  li r5, -173;
  li r4, 0;
  li r0, 1;
  and r3, r6, r3;
  ori r3, r3, 0x800;
  sth r3, 0x500a(r7);
  mr r3, r31;
  lhz r6, 0x500a(r7);
  and r5, r6, r5;
  sth r5, 0x500a(r7);
  stw r4, unk_80386618;
  stw r4, unk_80386624;
  stw r4, unk_8038661c;
  stw r4, unk_80386620;
  stw r0, unk_80386608;
  bl OSRestoreInterrupts;
lbl_8015d4f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DSPCheckInit
// PAL: 0x8015d504..0x8015d50c
MARK_BINARY_BLOB(DSPCheckInit, 0x8015d504, 0x8015d50c);
asm UNKNOWN_FUNCTION(DSPCheckInit) {
  // clang-format off
  nofralloc;
  lwz r3, unk_80386608;
  blr;
  // clang-format on
}

// Symbol: DSPAddTask
// PAL: 0x8015d50c..0x8015d57c
MARK_BINARY_BLOB(DSPAddTask, 0x8015d50c, 0x8015d57c);
asm UNKNOWN_FUNCTION(DSPAddTask) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  mr r31, r3;
  mr r3, r30;
  bl __DSP_insert_task;
  li r3, 0;
  li r0, 1;
  stw r3, 0(r30);
  mr r3, r31;
  stw r0, 8(r30);
  bl OSRestoreInterrupts;
  lwz r0, unk_80386620;
  cmplw r30, r0;
  bne lbl_8015d560;
  mr r3, r30;
  bl __DSP_boot_task;
lbl_8015d560:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DSPAssertTask
// PAL: 0x8015d57c..0x8015d638
MARK_BINARY_BLOB(DSPAssertTask, 0x8015d57c, 0x8015d638);
asm UNKNOWN_FUNCTION(DSPAssertTask) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r5, unk_80386624;
  mr r31, r3;
  cmplw r5, r30;
  bne lbl_8015d5c0;
  li r0, 1;
  stw r30, unk_80386614;
  stw r0, unk_80386610;
  bl OSRestoreInterrupts;
  mr r3, r30;
  b lbl_8015d620;
lbl_8015d5c0:
  lwz r4, 4(r30);
  lwz r0, 4(r5);
  cmplw r4, r0;
  bge lbl_8015d618;
  li r0, 1;
  stw r30, unk_80386614;
  stw r0, unk_80386610;
  lwz r0, 0(r5);
  cmplwi r0, 1;
  bne lbl_8015d608;
  bl OSDisableInterrupts;
  lis r5, 0xcc00;
  li r0, -169;
  lhz r4, 0x500a(r5);
  and r0, r4, r0;
  ori r0, r0, 2;
  sth r0, 0x500a(r5);
  bl OSRestoreInterrupts;
lbl_8015d608:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  b lbl_8015d620;
lbl_8015d618:
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_8015d620:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
