#include "dspTask.h"

#include <rvl/os/osContext.h>

#include "dsp.h"
#include "dspPrintf.h"

u32 unk_80386624;
u32 unk_80386620;
u32 unk_8038661c;
u32 unk_80386618;
u32 unk_80386614;
u32 unk_80386610;

// Symbol: __DSPHandler
// PAL: 0x8015d688..0x8015dabc
MARK_BINARY_BLOB(__DSPHandler, 0x8015d688, 0x8015dabc);
asm UNKNOWN_FUNCTION(__DSPHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2e0(r1);
  mflr r0;
  lis r6, 0xcc00;
  stw r0, 0x2e4(r1);
  li r0, -41;
  addi r3, r1, 8;
  stw r31, 0x2dc(r1);
  mr r31, r4;
  lhz r5, 0x500a(r6);
  and r0, r5, r0;
  ori r0, r0, 0x80;
  sth r0, 0x500a(r6);
  bl OSClearContext;
  addi r3, r1, 8;
  bl OSSetCurrentContext;
lbl_8015d6c4:
  bl DSPCheckMailFromDSP;
  cmpwi r3, 0;
  beq lbl_8015d6c4;
  bl DSPReadMailFromDSP;
  lwz r5, unk_80386624;
  lwz r0, 8(r5);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8015d6f8;
  addis r0, r3, 0x232f;
  cmplwi r0, 2;
  bne lbl_8015d6f8;
  lis r3, 0xdcd1;
  addi r3, r3, 3;
lbl_8015d6f8:
  lis r4, 0xdcd1;
  addi r0, r4, 2;
  cmpw r3, r0;
  beq lbl_8015d778;
  bge lbl_8015d71c;
  cmpw r3, r4;
  beq lbl_8015d730;
  bge lbl_8015d754;
  b lbl_8015da98;
lbl_8015d71c:
  addi r0, r4, 4;
  cmpw r3, r0;
  beq lbl_8015da80;
  bge lbl_8015da98;
  b lbl_8015d8e0;
lbl_8015d730:
  li r0, 1;
  stw r0, 0(r5);
  lwz r3, unk_80386624;
  lwz r12, 0x28(r3);
  cmpwi r12, 0;
  beq lbl_8015da98;
  mtctr r12;
  bctrl;
  b lbl_8015da98;
lbl_8015d754:
  li r0, 1;
  stw r0, 0(r5);
  lwz r3, unk_80386624;
  lwz r12, 0x2c(r3);
  cmpwi r12, 0;
  beq lbl_8015da98;
  mtctr r12;
  bctrl;
  b lbl_8015da98;
lbl_8015d778:
  lwz r0, unk_80386610;
  cmpwi r0, 0;
  beq lbl_8015d818;
  lwz r0, unk_80386614;
  cmplw r5, r0;
  bne lbl_8015d7d0;
  lis r3, 0xcdd1;
  addi r3, r3, 3;
  bl DSPSendMailToDSP;
lbl_8015d79c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d79c;
  li r0, 0;
  lwz r3, unk_80386624;
  stw r0, unk_80386614;
  stw r0, unk_80386610;
  lwz r12, 0x2c(r3);
  cmpwi r12, 0;
  beq lbl_8015da98;
  mtctr r12;
  bctrl;
  b lbl_8015da98;
lbl_8015d7d0:
  lis r3, 0xcdd1;
  addi r3, r3, 1;
  bl DSPSendMailToDSP;
lbl_8015d7dc:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d7dc;
  lwz r3, unk_80386624;
  lwz r4, unk_80386614;
  bl __DSP_exec_task;
  lwz r3, unk_80386624;
  li r4, 2;
  li r0, 0;
  stw r4, 0(r3);
  lwz r3, unk_80386614;
  stw r0, unk_80386610;
  stw r3, unk_80386624;
  stw r0, unk_80386614;
  b lbl_8015da98;
lbl_8015d818:
  lwz r0, 0x38(r5);
  cmpwi r0, 0;
  bne lbl_8015d8a0;
  lwz r0, unk_80386620;
  cmplw r5, r0;
  bne lbl_8015d864;
  lis r3, 0xcdd1;
  addi r3, r3, 3;
  bl DSPSendMailToDSP;
lbl_8015d83c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d83c;
  lwz r3, unk_80386624;
  lwz r12, 0x2c(r3);
  cmpwi r12, 0;
  beq lbl_8015da98;
  mtctr r12;
  bctrl;
  b lbl_8015da98;
lbl_8015d864:
  lis r3, 0xcdd1;
  addi r3, r3, 1;
  bl DSPSendMailToDSP;
lbl_8015d870:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d870;
  lwz r3, unk_80386624;
  lwz r4, unk_80386620;
  bl __DSP_exec_task;
  lwz r3, unk_80386624;
  li r0, 2;
  stw r0, 0(r3);
  lwz r0, unk_80386620;
  stw r0, unk_80386624;
  b lbl_8015da98;
lbl_8015d8a0:
  lis r3, 0xcdd1;
  addi r3, r3, 1;
  bl DSPSendMailToDSP;
lbl_8015d8ac:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d8ac;
  lwz r3, unk_80386624;
  lwz r4, 0x38(r3);
  bl __DSP_exec_task;
  lwz r3, unk_80386624;
  li r0, 2;
  stw r0, 0(r3);
  lwz r3, unk_80386624;
  lwz r0, 0x38(r3);
  stw r0, unk_80386624;
  b lbl_8015da98;
lbl_8015d8e0:
  lwz r0, unk_80386610;
  cmpwi r0, 0;
  beq lbl_8015d960;
  lwz r0, unk_80386614;
  cmplw r5, r0;
  beq lbl_8015d954;
  lwz r12, 0x30(r5);
  cmpwi r12, 0;
  beq lbl_8015d910;
  mr r3, r5;
  mtctr r12;
  bctrl;
lbl_8015d910:
  lis r3, 0xcdd1;
  addi r3, r3, 1;
  bl DSPSendMailToDSP;
lbl_8015d91c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d91c;
  lwz r4, unk_80386614;
  li r3, 0;
  bl __DSP_exec_task;
  lwz r3, unk_80386624;
  bl __DSP_remove_task;
  lwz r3, unk_80386614;
  li r0, 0;
  stw r0, unk_80386610;
  stw r3, unk_80386624;
  stw r0, unk_80386614;
  b lbl_8015da98;
lbl_8015d954:
  li r0, 0;
  stw r0, unk_80386614;
  stw r0, unk_80386610;
lbl_8015d960:
  lwz r0, 0x38(r5);
  cmpwi r0, 0;
  bne lbl_8015da1c;
  lwz r0, unk_80386620;
  cmplw r5, r0;
  bne lbl_8015d9c0;
  lwz r12, 0x30(r5);
  cmpwi r12, 0;
  beq lbl_8015d990;
  mr r3, r5;
  mtctr r12;
  bctrl;
lbl_8015d990:
  lis r3, 0xcdd1;
  addi r3, r3, 2;
  bl DSPSendMailToDSP;
lbl_8015d99c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d99c;
  lwz r3, unk_80386624;
  li r0, 3;
  stw r0, 0(r3);
  lwz r3, unk_80386624;
  bl __DSP_remove_task;
  b lbl_8015da98;
lbl_8015d9c0:
  lwz r12, 0x30(r5);
  cmpwi r12, 0;
  beq lbl_8015d9d8;
  mr r3, r5;
  mtctr r12;
  bctrl;
lbl_8015d9d8:
  lis r3, 0xcdd1;
  addi r3, r3, 1;
  bl DSPSendMailToDSP;
lbl_8015d9e4:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015d9e4;
  lwz r4, unk_80386624;
  li r0, 3;
  li r3, 0;
  stw r0, 0(r4);
  lwz r4, unk_80386620;
  bl __DSP_exec_task;
  lwz r0, unk_80386620;
  lwz r3, unk_8038661c;
  stw r0, unk_80386624;
  bl __DSP_remove_task;
  b lbl_8015da98;
lbl_8015da1c:
  lwz r12, 0x30(r5);
  cmpwi r12, 0;
  beq lbl_8015da34;
  mr r3, r5;
  mtctr r12;
  bctrl;
lbl_8015da34:
  lis r3, 0xcdd1;
  addi r3, r3, 1;
  bl DSPSendMailToDSP;
lbl_8015da40:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015da40;
  lwz r4, unk_80386624;
  li r0, 3;
  li r3, 0;
  stw r0, 0(r4);
  lwz r4, unk_80386624;
  lwz r4, 0x38(r4);
  bl __DSP_exec_task;
  lwz r3, unk_80386624;
  lwz r3, 0x38(r3);
  stw r3, unk_80386624;
  lwz r3, 0x3c(r3);
  bl __DSP_remove_task;
  b lbl_8015da98;
lbl_8015da80:
  lwz r12, 0x34(r5);
  cmpwi r12, 0;
  beq lbl_8015da98;
  mr r3, r5;
  mtctr r12;
  bctrl;
lbl_8015da98:
  addi r3, r1, 8;
  bl OSClearContext;
  mr r3, r31;
  bl OSSetCurrentContext;
  lwz r0, 0x2e4(r1);
  lwz r31, 0x2dc(r1);
  mtlr r0;
  addi r1, r1, 0x2e0;
  blr;
  // clang-format on
}

// Symbol: __DSP_exec_task
// PAL: 0x8015dabc..0x8015dc60
MARK_BINARY_BLOB(__DSP_exec_task, 0x8015dabc, 0x8015dc60);
asm UNKNOWN_FUNCTION(__DSP_exec_task) {
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
  beq lbl_8015db20;
  lwz r3, 0x18(r3);
  bl DSPSendMailToDSP;
lbl_8015dae8:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dae8;
  lwz r3, 0x1c(r30);
  bl DSPSendMailToDSP;
lbl_8015dafc:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dafc;
  lwz r3, 0x20(r30);
  bl DSPSendMailToDSP;
lbl_8015db10:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db10;
  b lbl_8015db5c;
lbl_8015db20:
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015db28:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db28;
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015db3c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db3c;
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015db50:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db50;
lbl_8015db5c:
  lwz r3, 0xc(r31);
  bl DSPSendMailToDSP;
lbl_8015db64:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db64;
  lwz r3, 0x10(r31);
  bl DSPSendMailToDSP;
lbl_8015db78:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db78;
  lwz r3, 0x14(r31);
  bl DSPSendMailToDSP;
lbl_8015db8c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015db8c;
  lwz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_8015dbf8;
  lhz r3, 0x24(r31);
  bl DSPSendMailToDSP;
lbl_8015dbac:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dbac;
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015dbc0:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dbc0;
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015dbd4:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dbd4;
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015dbe8:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dbe8;
  b lbl_8015dc48;
lbl_8015dbf8:
  lhz r3, 0x26(r31);
  bl DSPSendMailToDSP;
lbl_8015dc00:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dc00;
  lwz r3, 0x18(r31);
  bl DSPSendMailToDSP;
lbl_8015dc14:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dc14;
  lwz r3, 0x1c(r31);
  bl DSPSendMailToDSP;
lbl_8015dc28:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dc28;
  lwz r3, 0x20(r31);
  bl DSPSendMailToDSP;
lbl_8015dc3c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dc3c;
lbl_8015dc48:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DSP_boot_task
// PAL: 0x8015dc60..0x8015ddec
MARK_BINARY_BLOB(__DSP_boot_task, 0x8015dc60, 0x8015ddec);
asm UNKNOWN_FUNCTION(__DSP_boot_task) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8029;
  addi r31, r31, -32544;
  stw r30, 0x18(r1);
  mr r30, r3;
lbl_8015dc80:
  bl DSPCheckMailFromDSP;
  cmpwi r3, 0;
  beq lbl_8015dc80;
  bl DSPReadMailFromDSP;
  stw r3, 8(r1);
  lis r3, 0x80f4;
  addi r3, r3, -24575;
  bl DSPSendMailToDSP;
lbl_8015dca0:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dca0;
  lwz r3, 0xc(r30);
  bl DSPSendMailToDSP;
lbl_8015dcb4:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dcb4;
  lis r3, 0x80f4;
  addi r3, r3, -16382;
  bl DSPSendMailToDSP;
lbl_8015dccc:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dccc;
  lwz r0, 0x14(r30);
  clrlwi r3, r0, 0x10;
  bl DSPSendMailToDSP;
lbl_8015dce4:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dce4;
  lis r3, 0x80f4;
  addi r3, r3, -24574;
  bl DSPSendMailToDSP;
lbl_8015dcfc:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dcfc;
  lwz r3, 0x10(r30);
  bl DSPSendMailToDSP;
lbl_8015dd10:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dd10;
  lis r3, 0x80f4;
  addi r3, r3, -20478;
  bl DSPSendMailToDSP;
lbl_8015dd28:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dd28;
  li r3, 0;
  bl DSPSendMailToDSP;
lbl_8015dd3c:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dd3c;
  lis r3, 0x80f4;
  addi r3, r3, -12287;
  bl DSPSendMailToDSP;
lbl_8015dd54:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dd54;
  lhz r3, 0x24(r30);
  bl DSPSendMailToDSP;
lbl_8015dd68:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_8015dd68;
  mr r4, r30;
  addi r3, r31, 0;
  crclr 6;
  bl __DSP_debug_printf;
  lwz r4, 0xc(r30);
  addi r3, r31, 0x20;
  crclr 6;
  bl __DSP_debug_printf;
  lwz r4, 0x14(r30);
  addi r3, r31, 0x50;
  crclr 6;
  bl __DSP_debug_printf;
  lwz r4, 0x10(r30);
  addi r3, r31, 0x80;
  crclr 6;
  bl __DSP_debug_printf;
  lwz r4, 0x1c(r30);
  addi r3, r31, 0xb0;
  crclr 6;
  bl __DSP_debug_printf;
  lhz r4, 0x24(r30);
  addi r3, r31, 0xe0;
  crclr 6;
  bl __DSP_debug_printf;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __DSP_insert_task
// PAL: 0x8015ddec..0x8015de88
MARK_BINARY_BLOB(__DSP_insert_task, 0x8015ddec, 0x8015de88);
asm UNKNOWN_FUNCTION(__DSP_insert_task) {
  // clang-format off
  nofralloc;
  lwz r5, unk_80386620;
  cmpwi r5, 0;
  bne lbl_8015de58;
  stw r3, unk_80386624;
  li r0, 0;
  stw r3, unk_8038661c;
  stw r3, unk_80386620;
  stw r0, 0x3c(r3);
  stw r0, 0x38(r3);
  blr;
  b lbl_8015de58;
lbl_8015de18:
  lwz r4, 4(r3);
  lwz r0, 4(r5);
  cmplw r4, r0;
  bge lbl_8015de54;
  lwz r0, 0x3c(r5);
  stw r0, 0x3c(r3);
  stw r3, 0x3c(r5);
  lwz r4, 0x3c(r3);
  stw r5, 0x38(r3);
  cmpwi r4, 0;
  bne lbl_8015de4c;
  stw r3, unk_80386620;
  b lbl_8015de60;
lbl_8015de4c:
  stw r3, 0x38(r4);
  b lbl_8015de60;
lbl_8015de54:
  lwz r5, 0x38(r5);
lbl_8015de58:
  cmpwi r5, 0;
  bne lbl_8015de18;
lbl_8015de60:
  cmpwi r5, 0;
  bnelr;
  lwz r4, unk_8038661c;
  li r0, 0;
  stw r3, 0x38(r4);
  stw r0, 0x38(r3);
  lwz r0, unk_8038661c;
  stw r0, 0x3c(r3);
  stw r3, unk_8038661c;
  blr;
  // clang-format on
}

// Symbol: __DSP_remove_task
// PAL: 0x8015de88..0x8015df1c
MARK_BINARY_BLOB(__DSP_remove_task, 0x8015de88, 0x8015df1c);
asm UNKNOWN_FUNCTION(__DSP_remove_task) {
  // clang-format off
  nofralloc;
  li r4, 0;
  li r0, 3;
  stw r4, 8(r3);
  stw r0, 0(r3);
  lwz r0, unk_80386620;
  cmplw r0, r3;
  bne lbl_8015ded0;
  lwz r0, 0x38(r3);
  cmpwi r0, 0;
  beq lbl_8015dec0;
  stw r0, unk_80386620;
  lwz r3, 0x38(r3);
  stw r4, 0x3c(r3);
  blr;
lbl_8015dec0:
  stw r4, unk_80386624;
  stw r4, unk_8038661c;
  stw r4, unk_80386620;
  blr;
lbl_8015ded0:
  lwz r0, unk_8038661c;
  cmplw r0, r3;
  bne lbl_8015def8;
  lwz r0, 0x3c(r3);
  stw r0, unk_8038661c;
  lwz r3, 0x3c(r3);
  stw r4, 0x38(r3);
  lwz r0, unk_80386620;
  stw r0, unk_80386624;
  blr;
lbl_8015def8:
  lwz r0, 0x38(r3);
  stw r0, unk_80386624;
  lwz r0, 0x38(r3);
  lwz r4, 0x3c(r3);
  stw r0, 0x38(r4);
  lwz r0, 0x3c(r3);
  lwz r3, 0x38(r3);
  stw r0, 0x3c(r3);
  blr;
  // clang-format on
}
