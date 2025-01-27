#include "dvdMain.h"

#include <string.h>

#include <rvl/os/os.h>
#include <rvl/os/osAlarm.h>
#include <rvl/os/osCache.h>
#include <rvl/os/osError.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "dvdBroadway.h"
#include "dvdError.h"
#include "dvdFatal.h"
#include "dvdFs.h"
#include "dvdQueue.h"
#include "dvdUtils.h"

// Extern function references.
// PAL: 0x801671d0
extern UNKNOWN_FUNCTION(ESP_InitLib);
// PAL: 0x80167224
extern UNKNOWN_FUNCTION(ESP_CloseLib);
// PAL: 0x8016765c
extern UNKNOWN_FUNCTION(ESP_DiGetTicketView);
// PAL: 0x80167700
extern UNKNOWN_FUNCTION(ESP_DiGetTmd);
// PAL: 0x801aad7c
extern UNKNOWN_FUNCTION(__OSGetSystemTime);

// Symbol: dvd_StampCommand
// PAL: 0x8015e964..0x8015ea18
MARK_BINARY_BLOB(dvd_StampCommand, 0x8015e964, 0x8015ea18);
asm UNKNOWN_FUNCTION(dvd_StampCommand) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015e9a0;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015e9a0:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r4, r0, 0x14;
  lwz r0, -0x65a0(r13);
  mulli r3, r3, 0x14;
  add r4, r30, r4;
  stw r27, 0x1c(r4);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r28, 0x20(r3);
  add r3, r30, r0;
  stw r29, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: dvd_defaultOptionalCommandChecker
// PAL: 0x8015ea18..0x8015ea1c
MARK_BINARY_BLOB(dvd_defaultOptionalCommandChecker, 0x8015ea18, 0x8015ea1c);
asm UNKNOWN_FUNCTION(dvd_defaultOptionalCommandChecker) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: DVDInit
// PAL: 0x8015ea1c..0x8015eb70
MARK_BINARY_BLOB(DVDInit, 0x8015ea1c, 0x8015eb70);
asm UNKNOWN_FUNCTION(DVDInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lwz r0, -0x6560(r13);
  cmpwi r0, 0;
  bne lbl_8015eb58;
  lwz r3, -0x7338(r13);
  bl OSRegisterVersion;
  li r0, 1;
  stw r0, -0x6560(r13);
  bl DVDLowInit;
  lwz r0, -0x63a8(r13);
  cmpwi r0, 0;
  bne lbl_8015eab8;
  lis r3, 0x8000;
  lbz r0, 0x3187(r3);
  cmplwi r0, 0x80;
  bne lbl_8015eab8;
  bl ESP_InitLib;
  cmpwi r3, 0;
  bne lbl_8015ea88;
  lis r4, 0x8034;
  li r3, 0;
  addi r4, r4, -6784;
  bl ESP_DiGetTicketView;
lbl_8015ea88:
  cmpwi r3, 0;
  bne lbl_8015ea9c;
  li r3, 0;
  addi r4, r13, -25920;
  bl ESP_DiGetTmd;
lbl_8015ea9c:
  cmpwi r3, 0;
  bne lbl_8015eab4;
  lis r3, 0x8034;
  addi r4, r13, -25920;
  addi r3, r3, -6528;
  bl ESP_DiGetTmd;
lbl_8015eab4:
  bl ESP_CloseLib;
lbl_8015eab8:
  bl __DVDFSInit;
  bl __DVDClearWaitingQueue;
  lis r0, 0x8000;
  li r3, 0;
  stw r3, -0x6530(r13);
  addi r3, r13, -26064;
  stw r0, -0x6518(r13);
  stw r0, -0x6514(r13);
  bl OSInitThreadQueue;
  bl DVDLowUnmaskStatusInterrupts;
  bl DVDLowMaskCoverInterrupt;
  lwz r3, -0x6518(r13);
  lwz r3, 0x20(r3);
  addis r0, r3, 0x1ae0;
  cmplwi r0, 0x7c22;
  beq lbl_8015eb0c;
  addis r0, r3, 0xf2eb;
  cmplwi r0, 0xea5e;
  beq lbl_8015eb0c;
  li r0, 1;
  stw r0, -0x6580(r13);
lbl_8015eb0c:
  lis r31, 0x8034;
  li r4, 0;
  addi r3, r31, 0x33c0;
  li r5, 0x80;
  bl memset;
  lis r30, 0x8000;
  addi r3, r31, 0x33c0;
  mr r4, r30;
  li r5, 4;
  bl memcpy;
  lbz r4, 6(r30);
  addi r5, r31, 0x33c0;
  li r0, 0;
  li r3, 1;
  stb r4, 4(r5);
  lbz r4, 7(r30);
  stb r4, 5(r5);
  stw r0, -0x6564(r13);
  bl DVDSetAutoFatalMessaging;
lbl_8015eb58:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_stateReadingFST
// PAL: 0x8015eb70..0x8015ece8
MARK_BINARY_BLOB(dvd_stateReadingFST, 0x8015eb70, 0x8015ece8);
asm UNKNOWN_FUNCTION(dvd_stateReadingFST) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8016;
  lis r3, 0x8034;
  stw r0, 0x24(r1);
  addi r5, r5, -5264;
  addi r3, r3, 0x3080;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lwz r4, -0x6518(r13);
  stw r5, -0x650c(r13);
  lwz r0, 8(r3);
  lwz r3, 0x3c(r4);
  cmplw r3, r0;
  bge lbl_8015ebcc;
  lis r5, 0x8029;
  addi r3, r13, -29484;
  addi r5, r5, -31792;
  li r4, 0x43b;
  crclr 6;
  bl OSPanic;
lbl_8015ebcc:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lwz r3, -0x6564(r13);
  lis r6, 0x8034;
  addi r6, r6, 0x3080;
  lwz r0, -0x6564(r13);
  nor r3, r3, r3;
  lwz r5, 8(r6);
  rlwinm r4, r3, 0, 0x1e, 0x1e;
  lwz r3, 4(r6);
  slw r4, r5, r4;
  addi r4, r4, 0x1f;
  srw r29, r3, r0;
  rlwinm r28, r4, 0, 0, 0x1a;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015ec20;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015ec20:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r4, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r5, 1;
  mulli r3, r3, 0x14;
  add r4, r30, r4;
  stw r5, 0x1c(r4);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r29, 0x20(r3);
  add r3, r30, r0;
  stw r28, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, -0x6564(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x3080;
  lis r6, 0x8016;
  nor r0, r0, r0;
  lwz r3, 8(r4);
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  lwz r7, -0x6518(r13);
  slw r3, r3, r0;
  lwz r5, 4(r4);
  addi r4, r3, 0x1f;
  lwz r0, -0x6564(r13);
  lwz r3, 0x38(r7);
  rlwinm r4, r4, 0, 0, 0x1a;
  srw r5, r5, r0;
  addi r6, r6, -4888;
  bl DVDLowRead;
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

// Symbol: cbForStateReadingFST
// PAL: 0x8015ece8..0x8015ee70
MARK_BINARY_BLOB(cbForStateReadingFST, 0x8015ece8, 0x8015ee70);
asm UNKNOWN_FUNCTION(cbForStateReadingFST) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8015ed20;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r30, 0x78(r4);
  b lbl_8015ed38;
lbl_8015ed20:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r30, 0x14(r4);
lbl_8015ed38:
  bl OSRestoreInterrupts;
  cmplwi r30, 0x10;
  bne lbl_8015ed5c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015ee54;
lbl_8015ed5c:
  cmplwi r30, 0x20;
  bne lbl_8015ed7c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015ee54;
lbl_8015ed7c:
  clrlwi. r0, r30, 0x1f;
  beq lbl_8015edc4;
  li r30, 0;
  stw r30, -0x6588(r13);
  bl __DVDFSInit;
  lis r3, 0x8034;
  lwz r4, -0x6510(r13);
  addi r3, r3, 0x30a0;
  stw r3, -0x6510(r13);
  stw r30, 0xc(r4);
  lwz r12, 0x28(r4);
  cmpwi r12, 0;
  beq lbl_8015edbc;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8015edbc:
  bl stateReady;
  b lbl_8015ee54;
lbl_8015edc4:
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015ede0;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015ede0:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x27;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_8015ee54:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  b __DVDPrintFatalMessage;
  // clang-format on
}

// Symbol: dvd_cbForStateError
// PAL: 0x8015ee70..0x8015ef94
MARK_BINARY_BLOB(dvd_cbForStateError, 0x8015ee70, 0x8015ef94);
asm UNKNOWN_FUNCTION(dvd_cbForStateError) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __DVDGetAutoFatalMessaging;
  cmpwi r3, 0;
  beq lbl_8015eeb8;
  lis r31, 0x8034;
  addi r3, r31, 0x30d0;
  bl OSCreateAlarm;
  lis r7, 0x8016;
  addi r3, r31, 0x30d0;
  addi r7, r7, -4500;
  li r6, 1;
  li r5, 0;
  bl OSSetAlarm;
  b lbl_8015ef6c;
lbl_8015eeb8:
  lwz r3, -0x6510(r13);
  li r0, -1;
  cmplwi r31, 0x10;
  stw r0, 0xc(r3);
  bne lbl_8015eee4;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015ef6c;
lbl_8015eee4:
  cmplwi r31, 0x20;
  bne lbl_8015ef04;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015ef6c;
lbl_8015ef04:
  lis r3, 0x8034;
  lwz r31, -0x6510(r13);
  addi r3, r3, 0x30a0;
  li r0, 1;
  stw r0, -0x6594(r13);
  stw r3, -0x6510(r13);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_8015ef38;
  mr r4, r31;
  li r3, -1;
  mtctr r12;
  bctrl;
lbl_8015ef38:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_8015ef68;
  lwz r12, -0x6520(r13);
  li r0, 0;
  stw r0, -0x6590(r13);
  cmpwi r12, 0;
  beq lbl_8015ef68;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8015ef68:
  bl stateReady;
lbl_8015ef6c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, -4496;
  li r4, 0;
  b DVDLowStopMotor;
  // clang-format on
}

// Symbol: dvd_cbForStoreErrorCode2
// PAL: 0x8015ef94..0x8015efd0
MARK_BINARY_BLOB(dvd_cbForStoreErrorCode2, 0x8015ef94, 0x8015efd0);
asm UNKNOWN_FUNCTION(dvd_cbForStoreErrorCode2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0;
  stw r0, 0x14(r1);
  bl DVDLowSetSpinupFlag;
  lis r3, 0x8016;
  addi r3, r3, -4496;
  bl DVDLowReset;
  li r0, 0;
  stw r0, -0x652c(r13);
  stw r0, -0x658c(r13);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8015efd0
// PAL: 0x8015efd0..0x8015f0c4
MARK_BINARY_BLOB(unk_8015efd0, 0x8015efd0, 0x8015f0c4);
asm UNKNOWN_FUNCTION(unk_8015efd0) {
  // clang-format off
  nofralloc;
  addis r0, r3, 0xfffe;
  cmplwi r0, 0x400;
  bne lbl_8015efe8;
  stw r3, -0x6528(r13);
  li r3, 1;
  blr;
lbl_8015efe8:
  clrlwi r4, r3, 8;
  addis r0, r4, 0xfffa;
  cmplwi r0, 0x2800;
  beq lbl_8015f01c;
  addis r0, r4, 0xfffe;
  cmplwi r0, 0x3a00;
  beq lbl_8015f01c;
  addis r3, r4, 0xfffb;
  cmplwi r3, 0x3000;
  beq lbl_8015f01c;
  addis r0, r4, 0xfff5;
  cmplwi r0, 0x5a01;
  bne lbl_8015f024;
lbl_8015f01c:
  li r3, 0;
  blr;
lbl_8015f024:
  cmplwi r3, 0x2000;
  bne lbl_8015f058;
  lwz r3, -0x6510(r13);
  lwz r0, 8(r3);
  cmplwi r0, 0x25;
  beq lbl_8015f050;
  lis r3, 0x8016;
  lwz r0, -0x650c(r13);
  addi r3, r3, 0xf10;
  cmplw r0, r3;
  bne lbl_8015f058;
lbl_8015f050:
  li r3, 0;
  blr;
lbl_8015f058:
  lwz r3, -0x6588(r13);
  addi r0, r3, 1;
  stw r0, -0x6588(r13);
  lwz r0, -0x6588(r13);
  cmpwi r0, 2;
  bne lbl_8015f094;
  lwz r0, -0x6528(r13);
  cmplw r4, r0;
  bne lbl_8015f088;
  stw r4, -0x6528(r13);
  li r3, 1;
  blr;
lbl_8015f088:
  stw r4, -0x6528(r13);
  li r3, 2;
  blr;
lbl_8015f094:
  addis r0, r4, 0xfffd;
  stw r4, -0x6528(r13);
  cmplwi r0, 0x1100;
  beq lbl_8015f0b4;
  lwz r3, -0x6510(r13);
  lwz r0, 8(r3);
  cmplwi r0, 5;
  bne lbl_8015f0bc;
lbl_8015f0b4:
  li r3, 2;
  blr;
lbl_8015f0bc:
  li r3, 3;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStoreErrorCode3
// PAL: 0x8015f0c4..0x8015f188
MARK_BINARY_BLOB(dvd_cbForStoreErrorCode3, 0x8015f0c4, 0x8015f188);
asm UNKNOWN_FUNCTION(dvd_cbForStoreErrorCode3) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015f0f4;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015f0f4:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x10;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, -1728;
  li r4, 0;
  bl DVDLowStopMotor;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateGettingError
// PAL: 0x8015f188..0x8015f68c
MARK_BINARY_BLOB(dvd_cbForStateGettingError, 0x8015f188, 0x8015f68c);
asm UNKNOWN_FUNCTION(dvd_cbForStateGettingError) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8015f1c8;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r28, 0x78(r4);
  b lbl_8015f1e0;
lbl_8015f1c8:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r28, 0x14(r4);
lbl_8015f1e0:
  bl OSRestoreInterrupts;
  cmplwi r28, 0x10;
  bne lbl_8015f204;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015f66c;
lbl_8015f204:
  cmplwi r28, 0x20;
  bne lbl_8015f224;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015f66c;
lbl_8015f224:
  rlwinm. r0, r28, 0, 0x1e, 0x1e;
  beq lbl_8015f244;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_8015f66c;
lbl_8015f244:
  bl DVDLowGetImmBufferReg;
  mr r29, r3;
  rlwinm r28, r3, 0, 0, 7;
  bl unk_8015efd0;
  cmplwi r3, 1;
  mr r30, r3;
  bne lbl_8015f274;
  lis r4, 0x8016;
  mr r3, r29;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_8015f66c;
lbl_8015f274:
  addi r0, r3, -2;
  cmplwi r0, 1;
  bgt lbl_8015f288;
  li r5, 0;
  b lbl_8015f2ec;
lbl_8015f288:
  addis r0, r28, 0xff00;
  cmplwi r0, 0;
  bne lbl_8015f29c;
  li r5, 4;
  b lbl_8015f2ec;
lbl_8015f29c:
  addis r0, r28, 0xfe00;
  cmplwi r0, 0;
  bne lbl_8015f2b0;
  li r5, 6;
  b lbl_8015f2ec;
lbl_8015f2b0:
  addis r0, r28, 0xfd00;
  cmplwi r0, 0;
  bne lbl_8015f2c4;
  li r5, 3;
  b lbl_8015f2ec;
lbl_8015f2c4:
  cmpwi r28, 0;
  bne lbl_8015f2e8;
  addis r0, r29, 0xfffb;
  cmplwi r0, 0x3000;
  bne lbl_8015f2e0;
  li r5, 1;
  b lbl_8015f2ec;
lbl_8015f2e0:
  li r5, 5;
  b lbl_8015f2ec;
lbl_8015f2e8:
  li r5, 5;
lbl_8015f2ec:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_8015f360;
  lis r3, 0x8034;
  lwz r31, -0x6510(r13);
  addi r3, r3, 0x30a0;
  li r4, 0;
  stw r5, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_8015f338;
  mr r4, r31;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_8015f338:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_8015f354;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8015f354:
  bl stateReady;
  li r0, 1;
  b lbl_8015f364;
lbl_8015f360:
  li r0, 0;
lbl_8015f364:
  cmpwi r0, 0;
  bne lbl_8015f66c;
  cmplwi r30, 2;
  bne lbl_8015f388;
  lis r4, 0x8016;
  mr r3, r29;
  addi r4, r4, -3900;
  bl __DVDStoreErrorCode;
  b lbl_8015f66c;
lbl_8015f388:
  cmplwi r30, 3;
  bne lbl_8015f458;
  clrlwi r3, r29, 8;
  addis r0, r3, 0xfffd;
  cmplwi r0, 0x1100;
  bne lbl_8015f444;
  lwz r3, -0x6510(r13);
  lwz r29, 0x10(r3);
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015f3c4;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015f3c4:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 2;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r29, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r3, -0x6510(r13);
  lis r4, 0x8016;
  addi r4, r4, -2420;
  lwz r3, 0x10(r3);
  bl DVDLowSeek;
  b lbl_8015f66c;
lbl_8015f444:
  lwz r12, -0x650c(r13);
  lwz r3, -0x6510(r13);
  mtctr r12;
  bctrl;
  b lbl_8015f66c;
lbl_8015f458:
  addis r0, r28, 0xff00;
  cmplwi r0, 0;
  bne lbl_8015f4e4;
  lwz r4, -0x6510(r13);
  li r0, 5;
  li r3, 1;
  stw r0, 0xc(r4);
  lwz r0, -0x6578(r13);
  stw r3, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_8015f66c;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_8015f66c;
  lis r30, 0x8034;
  stw r3, -0x6578(r13);
  addi r3, r30, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r30, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_8015f66c;
lbl_8015f4e4:
  addis r0, r28, 0xfe00;
  cmplwi r0, 0;
  bne lbl_8015f504;
  lwz r3, -0x6510(r13);
  li r0, 3;
  stw r0, 0xc(r3);
  bl dvd_stateCoverClosed;
  b lbl_8015f66c;
lbl_8015f504:
  addis r0, r28, 0xfd00;
  cmplwi r0, 0;
  bne lbl_8015f590;
  lwz r4, -0x6510(r13);
  li r0, 4;
  li r3, 1;
  stw r0, 0xc(r4);
  lwz r0, -0x6578(r13);
  stw r3, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_8015f66c;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_8015f66c;
  lis r30, 0x8034;
  stw r3, -0x6578(r13);
  addi r3, r30, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r30, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_8015f66c;
lbl_8015f590:
  cmpwi r28, 0;
  bne lbl_8015f658;
  addis r0, r29, 0xfffb;
  cmplwi r0, 0x3000;
  bne lbl_8015f640;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015f5c0;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015f5c0:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x10;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x7bc;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_8015f66c;
lbl_8015f640:
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_8015f66c;
lbl_8015f658:
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
lbl_8015f66c:
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

// Symbol: dvd_cbForUnrecoveredError
// PAL: 0x8015f68c..0x8015f86c
MARK_BINARY_BLOB(dvd_cbForUnrecoveredError, 0x8015f68c, 0x8015f86c);
asm UNKNOWN_FUNCTION(dvd_cbForUnrecoveredError) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8015f6c4;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r30, 0x78(r4);
  b lbl_8015f6dc;
lbl_8015f6c4:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r30, 0x14(r4);
lbl_8015f6dc:
  bl OSRestoreInterrupts;
  cmplwi r30, 0x10;
  bne lbl_8015f700;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015f854;
lbl_8015f700:
  cmplwi r30, 0x20;
  bne lbl_8015f720;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015f854;
lbl_8015f720:
  clrlwi. r0, r30, 0x1f;
  beq lbl_8015f7c4;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015f744;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015f744:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x10;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, -1728;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_8015f854;
lbl_8015f7c4:
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_8015f7e0;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015f7e0:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x27;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r3, 0x8016;
  addi r3, r3, -1940;
  bl DVDLowRequestError;
lbl_8015f854:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForUnrecoveredErrorRetry
// PAL: 0x8015f86c..0x8015f940
MARK_BINARY_BLOB(dvd_cbForUnrecoveredErrorRetry, 0x8015f86c, 0x8015f940);
asm UNKNOWN_FUNCTION(dvd_cbForUnrecoveredErrorRetry) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8015f8a0;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_8015f8b8;
lbl_8015f8a0:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r31, 0x14(r4);
lbl_8015f8b8:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_8015f8dc;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015f92c;
lbl_8015f8dc:
  cmplwi r31, 0x20;
  bne lbl_8015f8fc;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015f92c;
lbl_8015f8fc:
  rlwinm. r0, r31, 0, 0x1e, 0x1e;
  beq lbl_8015f91c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_8015f92c;
lbl_8015f91c:
  bl DVDLowGetImmBufferReg;
  lis r4, 0x8016;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
lbl_8015f92c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateGoToRetry
// PAL: 0x8015f940..0x8015fb80
MARK_BINARY_BLOB(dvd_cbForStateGoToRetry, 0x8015f940, 0x8015fb80);
asm UNKNOWN_FUNCTION(dvd_cbForStateGoToRetry) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8015f974;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_8015f98c;
lbl_8015f974:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r31, 0x14(r4);
lbl_8015f98c:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_8015f9b0;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015fb6c;
lbl_8015f9b0:
  cmplwi r31, 0x20;
  bne lbl_8015f9d0;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8015fb6c;
lbl_8015f9d0:
  rlwinm. r0, r31, 0, 0x1e, 0x1e;
  beq lbl_8015f9f0;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_8015fb6c;
lbl_8015f9f0:
  li r0, 0;
  stw r0, -0x6588(r13);
  lwz r0, -0x651c(r13);
  cmplwi r0, 4;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 5;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xd;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x21;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x22;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x29;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x2a;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xf;
  beq lbl_8015fa64;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x25;
  bne lbl_8015fa6c;
lbl_8015fa64:
  li r0, 1;
  stw r0, -0x652c(r13);
lbl_8015fa6c:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_8015fae4;
  lis r3, 0x8034;
  lwz r31, -0x6510(r13);
  addi r3, r3, 0x30a0;
  li r0, 2;
  stw r0, -0x658c(r13);
  li r4, 0;
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_8015fabc;
  mr r4, r31;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_8015fabc:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_8015fad8;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8015fad8:
  bl stateReady;
  li r0, 1;
  b lbl_8015fae8;
lbl_8015fae4:
  li r0, 0;
lbl_8015fae8:
  cmpwi r0, 0;
  bne lbl_8015fb6c;
  lwz r4, -0x6510(r13);
  li r0, 0xb;
  li r3, 1;
  stw r0, 0xc(r4);
  lwz r0, -0x6578(r13);
  stw r3, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_8015fb6c;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_8015fb6c;
  lis r31, 0x8034;
  stw r3, -0x6578(r13);
  addi r3, r31, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r31, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
lbl_8015fb6c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_stateCheckID
// PAL: 0x8015fb80..0x8015feb8
MARK_BINARY_BLOB(dvd_stateCheckID, 0x8015fb80, 0x8015feb8);
asm UNKNOWN_FUNCTION(dvd_stateCheckID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8034;
  addi r30, r30, -6784;
  stw r29, 0x14(r1);
  lwz r0, -0x651c(r13);
  cmpwi r0, 3;
  beq lbl_8015fbb0;
  b lbl_8015fd3c;
lbl_8015fbb0:
  li r31, 0;
  lwz r4, -0x6510(r13);
  stw r31, -0x656c(r13);
  addi r3, r30, 0x4bc0;
  lwz r4, 0x24(r4);
  bl DVDCompareDiskID;
  cmpwi r3, 0;
  beq lbl_8015fca4;
  lwz r3, -0x6514(r13);
  addi r4, r30, 0x4bc0;
  li r5, 0x20;
  bl memcpy;
  lwz r5, -0x6510(r13);
  li r0, 1;
  addi r3, r30, 0x4b00;
  li r4, 0x20;
  stw r0, 0xc(r5);
  bl DCInvalidateRange;
  stw r31, -0x6588(r13);
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r29, r3;
  cmplwi r0, 5;
  blt lbl_8015fc1c;
  stw r31, -0x65a0(r13);
lbl_8015fc1c:
  lwz r0, -0x65a0(r13);
  lis r31, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r31, r31, 0x33c0;
  mulli r6, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r7, 0x21;
  lis r5, 1;
  mulli r3, r3, 0x14;
  li r4, 0x20;
  add r6, r31, r6;
  stw r7, 0x1c(r6);
  add r3, r31, r3;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r31, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r31, r5;
  stw r3, 0x2c(r4);
  mr r3, r29;
  bl OSRestoreInterrupts;
  lis r6, 0x8016;
  addi r3, r30, 0x4be0;
  addi r6, r6, -328;
  li r4, 0x20;
  lis r5, 1;
  bl DVDLowUnencryptedRead;
  b lbl_8015fe9c;
lbl_8015fca4:
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r29, r3;
  cmplwi r0, 5;
  blt lbl_8015fcbc;
  stw r31, -0x65a0(r13);
lbl_8015fcbc:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x10;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r29;
  bl OSRestoreInterrupts;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x7bc;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_8015fe9c;
lbl_8015fd3c:
  lwz r4, -0x6514(r13);
  addi r3, r30, 0x4bc0;
  li r5, 0x20;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_8015fdf0;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r29, r3;
  cmplwi r0, 5;
  blt lbl_8015fd70;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_8015fd70:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x10;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r29;
  bl OSRestoreInterrupts;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x7bc;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_8015fe9c;
lbl_8015fdf0:
  li r31, 0;
  li r3, 0;
  stw r31, -0x6588(r13);
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r29, r3;
  cmplwi r0, 5;
  blt lbl_8015fe18;
  stw r31, -0x65a0(r13);
lbl_8015fe18:
  lwz r0, -0x65a0(r13);
  lis r31, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r31, r31, 0x33c0;
  mulli r6, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r7, 0x21;
  lis r5, 1;
  mulli r3, r3, 0x14;
  li r4, 0x20;
  add r6, r31, r6;
  stw r7, 0x1c(r6);
  add r3, r31, r3;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r31, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r31, r5;
  stw r3, 0x2c(r4);
  mr r3, r29;
  bl OSRestoreInterrupts;
  lis r6, 0x8016;
  addi r3, r30, 0x4be0;
  addi r6, r6, -328;
  li r4, 0x20;
  lis r5, 1;
  bl DVDLowUnencryptedRead;
lbl_8015fe9c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateReadingTOC
// PAL: 0x8015feb8..0x80160058
MARK_BINARY_BLOB(dvd_cbForStateReadingTOC, 0x8015feb8, 0x80160058);
asm UNKNOWN_FUNCTION(dvd_cbForStateReadingTOC) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8015fef4;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r29, 0x78(r4);
  b lbl_8015ff10;
lbl_8015fef4:
  lwz r4, -0x65a0(r13);
  lis r5, 0x8034;
  addi r5, r5, 0x33c0;
  addi r0, r4, -1;
  mulli r0, r0, 0x14;
  add r4, r5, r0;
  stw r29, 0x28(r4);
lbl_8015ff10:
  bl OSRestoreInterrupts;
  cmplwi r29, 0x10;
  bne lbl_8015ff34;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8016003c;
lbl_8015ff34:
  cmplwi r29, 0x20;
  bne lbl_8015ff54;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_8016003c;
lbl_8015ff54:
  clrlwi. r0, r29, 0x1f;
  beq lbl_80160020;
  lis r4, 0x8034;
  li r29, 0;
  addi r4, r4, 0x3160;
  stw r29, -0x6588(r13);
  li r3, 0;
  stw r4, -0x654c(r13);
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r30, r3;
  cmplwi r0, 5;
  blt lbl_8015ff90;
  stw r29, -0x65a0(r13);
lbl_8015ff90:
  lwz r0, -0x65a0(r13);
  lis r31, 0x8034;
  lwz r3, -0x65a0(r13);
  lis r29, 1;
  mulli r4, r0, 0x14;
  addi r31, r31, 0x33c0;
  lwz r0, -0x65a0(r13);
  li r6, 0x21;
  addi r5, r29, 8;
  mulli r3, r3, 0x14;
  add r4, r31, r4;
  stw r6, 0x1c(r4);
  add r3, r31, r3;
  li r4, 0x20;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r31, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r31, r5;
  stw r3, 0x2c(r4);
  mr r3, r30;
  bl OSRestoreInterrupts;
  lis r3, 0x8034;
  lis r6, 0x8016;
  addi r5, r29, 8;
  li r4, 0x20;
  addi r3, r3, 0x3180;
  addi r6, r6, 0x58;
  bl DVDLowUnencryptedRead;
  b lbl_8016003c;
lbl_80160020:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_8016003c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateReadingPartitionInfo
// PAL: 0x80160058..0x801604d0
MARK_BINARY_BLOB(dvd_cbForStateReadingPartitionInfo, 0x80160058, 0x801604d0);
asm UNKNOWN_FUNCTION(dvd_cbForStateReadingPartitionInfo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8034;
  addi r31, r31, -6784;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_801600a0;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r28, 0x78(r4);
  b lbl_801600bc;
lbl_801600a0:
  lwz r4, -0x65a0(r13);
  lis r5, 0x8034;
  addi r5, r5, 0x33c0;
  addi r0, r4, -1;
  mulli r0, r0, 0x14;
  add r4, r5, r0;
  stw r28, 0x28(r4);
lbl_801600bc:
  bl OSRestoreInterrupts;
  cmplwi r28, 0x10;
  bne lbl_801600e0;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_801604b0;
lbl_801600e0:
  cmplwi r28, 0x20;
  bne lbl_80160100;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_801604b0;
lbl_80160100:
  clrlwi. r0, r28, 0x1f;
  beq lbl_80160494;
  li r0, 0;
  addi r6, r31, 0x4c00;
  stw r0, -0x6588(r13);
  lis r5, 0x8000;
  stw r6, -0x6550(r13);
  stw r0, -0x6554(r13);
  lwz r0, 0x3198(r5);
  cmpwi r0, 0;
  beq lbl_80160148;
  stw r6, -0x6554(r13);
  lwz r0, 0x3194(r5);
  stw r0, 4(r6);
  lwz r0, 0x3198(r5);
  lwz r3, -0x6554(r13);
  stw r0, 0(r3);
  b lbl_80160184;
lbl_80160148:
  lwz r3, -0x654c(r13);
  li r7, 0;
  b lbl_80160174;
lbl_80160154:
  lwz r4, 4(r6);
  lwz r0, 0x3194(r5);
  cmplw r4, r0;
  bne lbl_80160168;
  stw r6, -0x6554(r13);
lbl_80160168:
  addi r6, r6, 8;
  addi r7, r7, 1;
  stw r6, -0x6550(r13);
lbl_80160174:
  lwz r0, 0(r3);
  extsh r4, r7;
  cmplw r4, r0;
  blt lbl_80160154;
lbl_80160184:
  lwz r0, -0x6554(r13);
  cmpwi r0, 0;
  beq lbl_80160398;
  lwz r0, -0x651c(r13);
  cmpwi r0, 3;
  beq lbl_801601a0;
  b lbl_8016029c;
lbl_801601a0:
  li r29, 0;
  li r3, 0;
  stw r29, -0x6588(r13);
  bl DVDLowClearCoverInterrupt;
  lwz r3, -0x6554(r13);
  lwz r28, 0(r3);
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r30, r3;
  cmplwi r0, 5;
  blt lbl_801601d0;
  stw r29, -0x65a0(r13);
lbl_801601d0:
  lwz r0, -0x65a0(r13);
  lis r29, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r29, r29, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x22;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r29, r5;
  stw r6, 0x1c(r5);
  add r3, r29, r3;
  mulli r0, r0, 0x14;
  stw r28, 0x20(r3);
  add r3, r29, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r29, r5;
  stw r3, 0x2c(r4);
  mr r3, r30;
  bl OSRestoreInterrupts;
  lis r3, 0x8000;
  lbz r0, 0x3187(r3);
  cmplwi r0, 0x80;
  bne lbl_80160274;
  lwz r3, -0x6554(r13);
  lis r9, 0x8016;
  lwz r5, -0x6540(r13);
  addi r4, r31, 0;
  lwz r3, 0(r3);
  addi r6, r31, 0x100;
  addi r9, r9, 0x4d0;
  li r7, 0;
  li r8, 0;
  bl DVDLowOpenPartitionWithTmdAndTicketView;
  b lbl_801604b0;
lbl_80160274:
  lwz r3, -0x6554(r13);
  lis r8, 0x8016;
  addi r7, r31, 0x100;
  li r4, 0;
  lwz r3, 0(r3);
  addi r8, r8, 0x4d0;
  li r5, 0;
  li r6, 0;
  bl DVDLowOpenPartition;
  b lbl_801604b0;
lbl_8016029c:
  li r29, 0;
  li r3, 0;
  stw r29, -0x6588(r13);
  bl DVDLowClearCoverInterrupt;
  lwz r3, -0x6554(r13);
  lwz r28, 0(r3);
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r30, r3;
  cmplwi r0, 5;
  blt lbl_801602cc;
  stw r29, -0x65a0(r13);
lbl_801602cc:
  lwz r0, -0x65a0(r13);
  lis r29, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r29, r29, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x22;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r29, r5;
  stw r6, 0x1c(r5);
  add r3, r29, r3;
  mulli r0, r0, 0x14;
  stw r28, 0x20(r3);
  add r3, r29, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r29, r5;
  stw r3, 0x2c(r4);
  mr r3, r30;
  bl OSRestoreInterrupts;
  lis r3, 0x8000;
  lbz r0, 0x3187(r3);
  cmplwi r0, 0x80;
  bne lbl_80160370;
  lwz r3, -0x6554(r13);
  lis r9, 0x8016;
  lwz r5, -0x6540(r13);
  addi r4, r31, 0;
  lwz r3, 0(r3);
  addi r6, r31, 0x100;
  addi r9, r9, 0x658;
  li r7, 0;
  li r8, 0;
  bl DVDLowOpenPartitionWithTmdAndTicketView;
  b lbl_801604b0;
lbl_80160370:
  lwz r3, -0x6554(r13);
  lis r8, 0x8016;
  addi r7, r31, 0x100;
  li r4, 0;
  lwz r3, 0(r3);
  addi r8, r8, 0x658;
  li r5, 0;
  li r6, 0;
  bl DVDLowOpenPartition;
  b lbl_801604b0;
lbl_80160398:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_8016040c;
  lwz r28, -0x6510(r13);
  addi r3, r31, 0x4b20;
  li r0, 1;
  li r4, 0;
  stw r0, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r28);
  lwz r12, 0x28(r28);
  cmpwi r12, 0;
  beq lbl_801603e4;
  mr r4, r28;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_801603e4:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_80160400;
  mr r4, r28;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80160400:
  bl stateReady;
  li r0, 1;
  b lbl_80160410;
lbl_8016040c:
  li r0, 0;
lbl_80160410:
  cmpwi r0, 0;
  bne lbl_801604b0;
  lwz r4, -0x6510(r13);
  li r0, 6;
  li r3, 1;
  stw r0, 0xc(r4);
  lwz r0, -0x6578(r13);
  stw r3, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_801604b0;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_801604b0;
  stw r3, -0x6578(r13);
  addi r3, r31, 0x4b80;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r31, 0x4b80;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_801604b0;
lbl_80160494:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_801604b0:
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

// Symbol: dvd_cbForStateOpenPartition
// PAL: 0x801604d0..0x80160658
MARK_BINARY_BLOB(dvd_cbForStateOpenPartition, 0x801604d0, 0x80160658);
asm UNKNOWN_FUNCTION(dvd_cbForStateOpenPartition) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_80160508;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r30, 0x78(r4);
  b lbl_80160524;
lbl_80160508:
  lwz r4, -0x65a0(r13);
  lis r5, 0x8034;
  addi r5, r5, 0x33c0;
  addi r0, r4, -1;
  mulli r0, r0, 0x14;
  add r4, r5, r0;
  stw r30, 0x28(r4);
lbl_80160524:
  bl OSRestoreInterrupts;
  cmplwi r30, 0x10;
  bne lbl_80160548;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160640;
lbl_80160548:
  cmplwi r30, 0x20;
  bne lbl_80160568;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160640;
lbl_80160568:
  clrlwi. r0, r30, 0x1f;
  beq lbl_80160624;
  li r30, 0;
  li r3, 0;
  stw r30, -0x6588(r13);
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80160598;
  stw r30, -0x65a0(r13);
lbl_80160598:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r6, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r7, 1;
  li r5, 0x108;
  mulli r3, r3, 0x14;
  li r4, 0x20;
  add r6, r30, r6;
  stw r7, 0x1c(r6);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r3, 0x8034;
  lis r6, 0x8016;
  addi r3, r3, 0x3080;
  li r4, 0x20;
  addi r6, r6, 0x984;
  li r5, 0x108;
  bl DVDLowRead;
  b lbl_80160640;
lbl_80160624:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_80160640:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateOpenPartition2
// PAL: 0x80160658..0x801607bc
MARK_BINARY_BLOB(dvd_cbForStateOpenPartition2, 0x80160658, 0x801607bc);
asm UNKNOWN_FUNCTION(dvd_cbForStateOpenPartition2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_8016068c;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_801606a4;
lbl_8016068c:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r31, 0x14(r4);
lbl_801606a4:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_801606c8;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_801607a8;
lbl_801606c8:
  cmplwi r31, 0x20;
  bne lbl_801606e8;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_801607a8;
lbl_801606e8:
  clrlwi. r0, r31, 0x1f;
  beq lbl_8016078c;
  li r4, 0;
  stw r4, -0x6588(r13);
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80160768;
  lis r3, 0x8034;
  lwz r31, -0x6510(r13);
  addi r3, r3, 0x30a0;
  stw r4, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_80160740;
  mr r4, r31;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80160740:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_8016075c;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8016075c:
  bl stateReady;
  li r0, 1;
  b lbl_8016076c;
lbl_80160768:
  li r0, 0;
lbl_8016076c:
  cmpwi r0, 0;
  bne lbl_801607a8;
  lwz r3, -0x6510(r13);
  li r0, 1;
  stw r0, 0xc(r3);
  lwz r3, -0x6510(r13);
  bl stateBusy;
  b lbl_801607a8;
lbl_8016078c:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_801607a8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateCheckID1
// PAL: 0x801607bc..0x80160984
MARK_BINARY_BLOB(dvd_cbForStateCheckID1, 0x801607bc, 0x80160984);
asm UNKNOWN_FUNCTION(dvd_cbForStateCheckID1) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_801607f0;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_80160808;
lbl_801607f0:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r31, 0x14(r4);
lbl_80160808:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_8016082c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160970;
lbl_8016082c:
  cmplwi r31, 0x20;
  bne lbl_8016084c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160970;
lbl_8016084c:
  rlwinm. r0, r31, 0, 0x1e, 0x1e;
  beq lbl_8016086c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_80160970;
lbl_8016086c:
  li r4, 0;
  stw r4, -0x6588(r13);
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_801608e8;
  lis r3, 0x8034;
  lwz r31, -0x6510(r13);
  addi r3, r3, 0x30a0;
  li r0, 1;
  stw r0, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_801608c0;
  mr r4, r31;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_801608c0:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_801608dc;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_801608dc:
  bl stateReady;
  li r0, 1;
  b lbl_801608ec;
lbl_801608e8:
  li r0, 0;
lbl_801608ec:
  cmpwi r0, 0;
  bne lbl_80160970;
  lwz r4, -0x6510(r13);
  li r0, 6;
  li r3, 1;
  stw r0, 0xc(r4);
  lwz r0, -0x6578(r13);
  stw r3, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_80160970;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_80160970;
  lis r31, 0x8034;
  stw r3, -0x6578(r13);
  addi r3, r31, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r31, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
lbl_80160970:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateCheckID2
// PAL: 0x80160984..0x80160b18
MARK_BINARY_BLOB(dvd_cbForStateCheckID2, 0x80160984, 0x80160b18);
asm UNKNOWN_FUNCTION(dvd_cbForStateCheckID2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_801609b8;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_801609d4;
lbl_801609b8:
  lwz r4, -0x65a0(r13);
  lis r5, 0x8034;
  addi r5, r5, 0x33c0;
  addi r0, r4, -1;
  mulli r0, r0, 0x14;
  add r4, r5, r0;
  stw r31, 0x28(r4);
lbl_801609d4:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_801609f8;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160b04;
lbl_801609f8:
  cmplwi r31, 0x20;
  bne lbl_80160a18;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160b04;
lbl_80160a18:
  clrlwi. r0, r31, 0x1f;
  beq lbl_80160ae8;
  lis r5, 0x8016;
  li r0, 0;
  addi r5, r5, -5264;
  lis r3, 0x8034;
  stw r0, -0x6588(r13);
  addi r3, r3, 0x3080;
  lwz r4, -0x6518(r13);
  stw r5, -0x650c(r13);
  lwz r0, 8(r3);
  lwz r3, 0x3c(r4);
  cmplw r3, r0;
  bge lbl_80160a68;
  lis r5, 0x8029;
  addi r3, r13, -29484;
  addi r5, r5, -31792;
  li r4, 0x43b;
  crclr 6;
  bl OSPanic;
lbl_80160a68:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lwz r6, -0x6564(r13);
  lis r31, 0x8034;
  addi r31, r31, 0x3080;
  lwz r0, -0x6564(r13);
  lwz r4, 8(r31);
  li r3, 1;
  nor r0, r0, r0;
  lwz r7, 4(r31);
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  slw r5, r4, r0;
  srw r4, r7, r6;
  addi r0, r5, 0x1f;
  rlwinm r5, r0, 0, 0, 0x1a;
  bl dvd_StampCommand;
  lwz r0, -0x6564(r13);
  lis r6, 0x8016;
  lwz r3, 8(r31);
  addi r6, r6, -4888;
  nor r0, r0, r0;
  lwz r7, -0x6518(r13);
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  lwz r5, 4(r31);
  slw r3, r3, r0;
  lwz r0, -0x6564(r13);
  addi r4, r3, 0x1f;
  lwz r3, 0x38(r7);
  rlwinm r4, r4, 0, 0, 0x1a;
  srw r5, r5, r0;
  bl DVDLowRead;
  b lbl_80160b04;
lbl_80160ae8:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_80160b04:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_stateCoverClosed
// PAL: 0x80160b18..0x80160bdc
MARK_BINARY_BLOB(dvd_stateCoverClosed, 0x80160b18, 0x80160bdc);
asm UNKNOWN_FUNCTION(dvd_stateCoverClosed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 1;
  stw r0, 0x14(r1);
  lwz r0, -0x651c(r13);
  stw r3, -0x6530(r13);
  cmplwi r0, 0x2a;
  bgt lbl_80160bb0;
  lis r3, 0x8029;
  slwi r0, r0, 2;
  addi r3, r3, -31740;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  bl __DVDClearWaitingQueue;
  lis r3, 0x8034;
  lwz r4, -0x6510(r13);
  addi r3, r3, 0x30a0;
  stw r3, -0x6510(r13);
  lwz r12, 0x28(r4);
  cmpwi r12, 0;
  beq lbl_80160b7c;
  li r3, -4;
  mtctr r12;
  bctrl;
lbl_80160b7c:
  bl stateReady;
  b lbl_80160bcc;
  li r0, 0;
  stw r0, -0x6530(r13);
  lwz r3, -0x6510(r13);
  li r0, 1;
  stw r0, 0xc(r3);
  lwz r3, -0x6510(r13);
  bl stateBusy;
  b lbl_80160bcc;
  lwz r0, -0x63a8(r13);
  cmpwi r0, 0;
  bne lbl_80160bcc;
lbl_80160bb0:
  li r0, 0;
  li r3, 1;
  stw r0, -0x6530(r13);
  bl DVDLowSetSpinupFlag;
  lis r3, 0x8016;
  addi r3, r3, 0xe2c;
  bl DVDLowReset;
lbl_80160bcc:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_ResetAlarmHandler
// PAL: 0x80160bdc..0x80160e2c
MARK_BINARY_BLOB(dvd_ResetAlarmHandler, 0x80160bdc, 0x80160e2c);
asm UNKNOWN_FUNCTION(dvd_ResetAlarmHandler) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8000;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lhz r0, 0x30e6(r3);
  cmplwi r0, 0x8003;
  bne lbl_80160cac;
  lis r4, 0x8016;
  li r3, 0;
  addi r4, r4, 0xf10;
  stw r4, -0x650c(r13);
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80160c30;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_80160c30:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x25;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r4, 0x8016;
  lis r3, 2;
  addi r4, r4, 0xfd8;
  bl DVDLowSetMaximumRotation;
  b lbl_80160e14;
lbl_80160cac:
  lis r3, 0x8034;
  li r4, 0x20;
  addi r3, r3, 0x3140;
  bl DCInvalidateRange;
  lwz r0, -0x651c(r13);
  lis r3, 0x8016;
  addi r3, r3, 0x1218;
  cmplwi r0, 0x28;
  stw r3, -0x650c(r13);
  bne lbl_80160d70;
  li r4, 0;
  stw r4, -0x6588(r13);
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80160d4c;
  lis r3, 0x8034;
  lwz r30, -0x6510(r13);
  addi r3, r3, 0x30a0;
  stw r4, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r30);
  lwz r12, 0x28(r30);
  cmpwi r12, 0;
  beq lbl_80160d24;
  mr r4, r30;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80160d24:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_80160d40;
  mr r4, r30;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80160d40:
  bl stateReady;
  li r0, 1;
  b lbl_80160d50;
lbl_80160d4c:
  li r0, 0;
lbl_80160d50:
  cmpwi r0, 0;
  bne lbl_80160e14;
  lwz r3, -0x6510(r13);
  li r0, 1;
  stw r0, 0xc(r3);
  lwz r3, -0x6510(r13);
  bl stateBusy;
  b lbl_80160e14;
lbl_80160d70:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80160d94;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_80160d94:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r6, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r7, 5;
  li r5, 0;
  mulli r3, r3, 0x14;
  li r4, 0x20;
  add r6, r30, r6;
  stw r7, 0x1c(r6);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r3, 0x8034;
  lis r4, 0x8016;
  addi r3, r3, 0x3140;
  addi r4, r4, 0x1390;
  bl DVDLowReadDiskID;
lbl_80160e14:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateReset
// PAL: 0x80160e2c..0x80160f10
MARK_BINARY_BLOB(dvd_cbForStateReset, 0x80160e2c, 0x80160f10);
asm UNKNOWN_FUNCTION(dvd_cbForStateReset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 0x10;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bne lbl_80160e5c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160efc;
lbl_80160e5c:
  cmplwi r3, 0x20;
  bne lbl_80160e7c;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80160efc;
lbl_80160e7c:
  clrlwi. r0, r3, 0x1f;
  beq lbl_80160ee0;
  bl __OSGetSystemTime;
  li r0, 0;
  stw r4, -0x6534(r13);
  lis r31, 0x8034;
  stw r3, -0x6538(r13);
  addi r3, r31, 0x31a0;
  stw r0, -0x652c(r13);
  stw r0, -0x658c(r13);
  bl OSCreateAlarm;
  lis r4, 0x8000;
  lis r7, 0x8016;
  lwz r0, 0xf8(r4);
  lis r3, 0x1062;
  addi r4, r3, 0x4dd3;
  addi r7, r7, 0xbdc;
  srwi r0, r0, 2;
  addi r3, r31, 0x31a0;
  mulhwu r0, r4, r0;
  li r5, 0;
  srwi r0, r0, 6;
  mulli r6, r0, 0x64;
  bl OSSetAlarm;
  b lbl_80160efc;
lbl_80160ee0:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_80160efc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_stateDownRotation
// PAL: 0x80160f10..0x80160fd8
MARK_BINARY_BLOB(dvd_stateDownRotation, 0x80160f10, 0x80160fd8);
asm UNKNOWN_FUNCTION(dvd_stateDownRotation) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80160f48;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_80160f48:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x25;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r30, r5;
  stw r6, 0x1c(r5);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r4, 0x8016;
  lis r3, 2;
  addi r4, r4, 0xfd8;
  bl DVDLowSetMaximumRotation;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateDownRotation
// PAL: 0x80160fd8..0x80161218
MARK_BINARY_BLOB(dvd_cbForStateDownRotation, 0x80160fd8, 0x80161218);
asm UNKNOWN_FUNCTION(dvd_cbForStateDownRotation) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_80161010;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r30, 0x78(r4);
  b lbl_8016102c;
lbl_80161010:
  lwz r4, -0x65a0(r13);
  lis r5, 0x8034;
  addi r5, r5, 0x33c0;
  addi r0, r4, -1;
  mulli r0, r0, 0x14;
  add r4, r5, r0;
  stw r30, 0x28(r4);
lbl_8016102c:
  bl OSRestoreInterrupts;
  cmplwi r30, 0x10;
  bne lbl_80161050;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80161200;
lbl_80161050:
  cmplwi r30, 0x20;
  bne lbl_80161070;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80161200;
lbl_80161070:
  clrlwi. r0, r30, 0x1f;
  beq lbl_801611e4;
  lis r3, 0x8034;
  li r4, 0x20;
  addi r3, r3, 0x3140;
  bl DCInvalidateRange;
  lwz r0, -0x651c(r13);
  lis r3, 0x8016;
  addi r3, r3, 0x1218;
  cmplwi r0, 0x28;
  stw r3, -0x650c(r13);
  bne lbl_8016113c;
  li r4, 0;
  stw r4, -0x6588(r13);
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80161118;
  lis r3, 0x8034;
  lwz r30, -0x6510(r13);
  addi r3, r3, 0x30a0;
  stw r4, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r30);
  lwz r12, 0x28(r30);
  cmpwi r12, 0;
  beq lbl_801610f0;
  mr r4, r30;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_801610f0:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_8016110c;
  mr r4, r30;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8016110c:
  bl stateReady;
  li r0, 1;
  b lbl_8016111c;
lbl_80161118:
  li r0, 0;
lbl_8016111c:
  cmpwi r0, 0;
  bne lbl_80161200;
  lwz r3, -0x6510(r13);
  li r0, 1;
  stw r0, 0xc(r3);
  lwz r3, -0x6510(r13);
  bl stateBusy;
  b lbl_80161200;
lbl_8016113c:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80161160;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_80161160:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r6, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r7, 5;
  li r5, 0;
  mulli r3, r3, 0x14;
  li r4, 0x20;
  add r6, r30, r6;
  stw r7, 0x1c(r6);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r3, 0x8034;
  lis r4, 0x8016;
  addi r3, r3, 0x3140;
  addi r4, r4, 0x1390;
  bl DVDLowReadDiskID;
  b lbl_80161200;
lbl_801611e4:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_80161200:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_stateCoverClosed_CMD
// PAL: 0x80161218..0x80161390
MARK_BINARY_BLOB(dvd_stateCoverClosed_CMD, 0x80161218, 0x80161390);
asm UNKNOWN_FUNCTION(dvd_stateCoverClosed_CMD) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x28;
  bne lbl_801612d4;
  li r4, 0;
  stw r4, -0x6588(r13);
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_801612b0;
  lis r3, 0x8034;
  lwz r30, -0x6510(r13);
  addi r3, r3, 0x30a0;
  stw r4, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r30);
  lwz r12, 0x28(r30);
  cmpwi r12, 0;
  beq lbl_80161288;
  mr r4, r30;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80161288:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_801612a4;
  mr r4, r30;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_801612a4:
  bl stateReady;
  li r0, 1;
  b lbl_801612b4;
lbl_801612b0:
  li r0, 0;
lbl_801612b4:
  cmpwi r0, 0;
  bne lbl_80161378;
  lwz r3, -0x6510(r13);
  li r0, 1;
  stw r0, 0xc(r3);
  lwz r3, -0x6510(r13);
  bl stateBusy;
  b lbl_80161378;
lbl_801612d4:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_801612f8;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_801612f8:
  lwz r0, -0x65a0(r13);
  lis r30, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r30, r30, 0x33c0;
  mulli r6, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r7, 5;
  li r5, 0;
  mulli r3, r3, 0x14;
  li r4, 0x20;
  add r6, r30, r6;
  stw r7, 0x1c(r6);
  add r3, r30, r3;
  mulli r0, r0, 0x14;
  stw r5, 0x20(r3);
  add r3, r30, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r30, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lis r3, 0x8034;
  lis r4, 0x8016;
  addi r3, r3, 0x3140;
  addi r4, r4, 0x1390;
  bl DVDLowReadDiskID;
lbl_80161378:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateCoverClosed
// PAL: 0x80161390..0x80161468
MARK_BINARY_BLOB(dvd_cbForStateCoverClosed, 0x80161390, 0x80161468);
asm UNKNOWN_FUNCTION(dvd_cbForStateCoverClosed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_801613c4;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_801613dc;
lbl_801613c4:
  lwz r0, -0x65a0(r13);
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  mulli r0, r0, 0x14;
  add r4, r4, r0;
  stw r31, 0x14(r4);
lbl_801613dc:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_80161400;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80161454;
lbl_80161400:
  cmplwi r31, 0x20;
  bne lbl_80161420;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_80161454;
lbl_80161420:
  clrlwi. r0, r31, 0x1f;
  beq lbl_80161438;
  li r0, 0;
  stw r0, -0x6588(r13);
  bl dvd_stateCheckID;
  b lbl_80161454;
lbl_80161438:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_80161454:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForPrepareCoverRegister
// PAL: 0x80161468..0x80161614
MARK_BINARY_BLOB(dvd_cbForPrepareCoverRegister, 0x80161468, 0x80161614);
asm UNKNOWN_FUNCTION(dvd_cbForPrepareCoverRegister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r31, -0x6568(r13);
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  beq lbl_80161510;
  bl DVDLowGetCoverRegister;
  clrlwi. r0, r3, 0x1f;
  bne lbl_801615dc;
  lis r3, 0x8034;
  addi r3, r3, 0x3100;
  bl OSCancelAlarm;
  stw r31, -0x6574(r13);
  stw r31, -0x6574(r13);
  lwz r0, -0x651c(r13);
  cmplwi r0, 3;
  bne lbl_801614c0;
  li r0, 1;
  stw r0, -0x656c(r13);
lbl_801614c0:
  lwz r0, -0x6530(r13);
  cmplwi r0, 2;
  bne lbl_801614e4;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_801615dc;
  li r0, 0xc;
  stw r0, 0xc(r3);
  b lbl_801615dc;
lbl_801614e4:
  bl DVDLowMaskCoverInterrupt;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_80161504;
  li r0, 3;
  stw r0, 0xc(r3);
  bl dvd_stateCoverClosed;
  b lbl_801615dc;
lbl_80161504:
  li r0, 7;
  stw r0, -0x658c(r13);
  b lbl_801615dc;
lbl_80161510:
  bl DVDLowGetCoverRegister;
  clrlwi. r0, r3, 0x1f;
  beq lbl_80161554;
  lwz r0, -0x6530(r13);
  li r3, 1;
  stw r31, -0x6578(r13);
  cmplwi r0, 2;
  stw r3, -0x6574(r13);
  bne lbl_80161544;
  lwz r3, -0x6510(r13);
  li r0, 0xc;
  stw r0, 0xc(r3);
  b lbl_801615dc;
lbl_80161544:
  lwz r3, -0x6510(r13);
  li r0, 5;
  stw r0, 0xc(r3);
  b lbl_801615dc;
lbl_80161554:
  bl DVDLowGetCoverRegister;
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_801615dc;
  lis r3, 0x8034;
  addi r3, r3, 0x3100;
  bl OSCancelAlarm;
  stw r31, -0x6578(r13);
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  stw r31, -0x6574(r13);
  lwz r0, -0x651c(r13);
  cmplwi r0, 3;
  bne lbl_80161590;
  li r0, 1;
  stw r0, -0x656c(r13);
lbl_80161590:
  lwz r0, -0x6530(r13);
  cmplwi r0, 2;
  bne lbl_801615b4;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_801615dc;
  li r0, 0xc;
  stw r0, 0xc(r3);
  b lbl_801615dc;
lbl_801615b4:
  bl DVDLowMaskCoverInterrupt;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_801615d4;
  li r0, 3;
  stw r0, 0xc(r3);
  bl dvd_stateCoverClosed;
  b lbl_801615dc;
lbl_801615d4:
  li r0, 7;
  stw r0, -0x658c(r13);
lbl_801615dc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  lwz r0, -0x6568(r13);
  cmpwi r0, 0;
  bnelr;
  li r0, 1;
  lis r3, 0x8016;
  stw r0, -0x6568(r13);
  addi r3, r3, 0x1468;
  b DVDLowPrepareCoverRegister;
  blr;
  // clang-format on
}

// Symbol: stateReady
// PAL: 0x80161614..0x8016193c
MARK_BINARY_BLOB(stateReady, 0x80161614, 0x8016193c);
asm UNKNOWN_FUNCTION(stateReady) {
  // clang-format off
  nofralloc;
lbl_80161614:
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl __DVDCheckWaitingQueue;
  cmpwi r3, 0;
  bne lbl_8016163c;
  li r0, 0;
  stw r0, -0x6510(r13);
  b lbl_80161928;
lbl_8016163c:
  lwz r0, -0x659c(r13);
  cmpwi r0, 0;
  beq lbl_8016165c;
  li r3, 1;
  li r0, 0;
  stw r3, -0x6598(r13);
  stw r0, -0x6510(r13);
  b lbl_80161928;
lbl_8016165c:
  bl __DVDPopWaitingQueue;
  lwz r0, -0x6594(r13);
  stw r3, -0x6510(r13);
  cmpwi r0, 0;
  beq lbl_801616a8;
  li r0, -1;
  lis r5, 0x8034;
  stw r0, 0xc(r3);
  addi r5, r5, 0x30a0;
  lwz r4, -0x6510(r13);
  stw r5, -0x6510(r13);
  lwz r12, 0x28(r4);
  cmpwi r12, 0;
  beq lbl_801616a0;
  li r3, -1;
  mtctr r12;
  bctrl;
lbl_801616a0:
  bl lbl_80161614;
  b lbl_80161928;
lbl_801616a8:
  lwz r0, 8(r3);
  stw r0, -0x651c(r13);
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x20;
  beq lbl_801616d4;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xe;
  beq lbl_801616d4;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x23;
  bne lbl_801616dc;
lbl_801616d4:
  li r0, 0;
  stw r0, -0x658c(r13);
lbl_801616dc:
  lwz r0, -0x658c(r13);
  cmpwi r0, 0;
  beq lbl_801618c4;
  lwz r0, -0x658c(r13);
  cmpwi r0, 4;
  beq lbl_8016181c;
  bge lbl_80161710;
  cmpwi r0, 2;
  beq lbl_80161724;
  bge lbl_801617a0;
  cmpwi r0, 1;
  bge lbl_80161898;
  b lbl_801618b8;
lbl_80161710:
  cmpwi r0, 8;
  bge lbl_801618b8;
  cmpwi r0, 6;
  bge lbl_80161898;
  b lbl_801618a8;
lbl_80161724:
  li r0, 0xb;
  li r4, 1;
  stw r0, 0xc(r3);
  lwz r0, -0x6578(r13);
  stw r4, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_801618b8;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_801618b8;
  lis r31, 0x8034;
  stw r4, -0x6578(r13);
  addi r3, r31, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r31, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_801618b8;
lbl_801617a0:
  li r0, 4;
  li r4, 1;
  stw r0, 0xc(r3);
  lwz r0, -0x6578(r13);
  stw r4, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_801618b8;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_801618b8;
  lis r31, 0x8034;
  stw r4, -0x6578(r13);
  addi r3, r31, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r31, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_801618b8;
lbl_8016181c:
  li r0, 5;
  li r4, 1;
  stw r0, 0xc(r3);
  lwz r0, -0x6578(r13);
  stw r4, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_801618b8;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_801618b8;
  lis r31, 0x8034;
  stw r4, -0x6578(r13);
  addi r3, r31, 0x3100;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r31, 0x3100;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_801618b8;
lbl_80161898:
  li r0, 3;
  stw r0, 0xc(r3);
  bl dvd_stateCoverClosed;
  b lbl_801618b8;
lbl_801618a8:
  lis r4, 0x8016;
  lwz r3, -0x6524(r13);
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
lbl_801618b8:
  li r0, 0;
  stw r0, -0x658c(r13);
  b lbl_80161928;
lbl_801618c4:
  lwz r0, -0x6530(r13);
  cmpwi r0, 1;
  beq lbl_80161924;
  bge lbl_801618e0;
  cmpwi r0, 0;
  bge lbl_80161910;
  b lbl_80161924;
lbl_801618e0:
  cmpwi r0, 3;
  bge lbl_80161924;
  lwz r0, -0x6570(r13);
  cmpwi r0, 0;
  beq lbl_80161900;
  li r0, 0xc;
  stw r0, 0xc(r3);
  b lbl_80161928;
lbl_80161900:
  li r0, 3;
  stw r0, 0xc(r3);
  bl dvd_stateCoverClosed;
  b lbl_80161928;
lbl_80161910:
  li r0, 1;
  stw r0, 0xc(r3);
  lwz r3, -0x6510(r13);
  bl stateBusy;
  b lbl_80161928;
lbl_80161924:
  bl dvd_stateCoverClosed;
lbl_80161928:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: stateBusy
// PAL: 0x8016193c..0x80161eec
MARK_BINARY_BLOB(stateBusy, 0x8016193c, 0x80161eec);
asm UNKNOWN_FUNCTION(stateBusy) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  lis r4, 0x8016;
  mr r29, r3;
  addi r4, r4, 0x193c;
  stw r4, -0x650c(r13);
  lwz r30, 8(r3);
  cmplwi r30, 0x2a;
  bgt lbl_80161a08;
  lis r4, 0x8029;
  slwi r0, r30, 2;
  addi r4, r4, -31396;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  lwz r26, 0x14(r3);
  lwz r27, 0x10(r3);
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_801619a8;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_801619a8:
  lwz r0, -0x65a0(r13);
  lis r28, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r28, r28, 0x33c0;
  mulli r4, r0, 0x14;
  lwz r0, -0x65a0(r13);
  mulli r3, r3, 0x14;
  add r4, r28, r4;
  stw r30, 0x1c(r4);
  add r3, r28, r3;
  mulli r0, r0, 0x14;
  stw r27, 0x20(r3);
  add r3, r28, r0;
  stw r26, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r28, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
lbl_80161a08:
  lwz r0, 8(r29);
  cmplwi r0, 0x2a;
  bgt lbl_80161ebc;
  lis r3, 0x8029;
  slwi r0, r0, 2;
  addi r3, r3, -31568;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  li r0, 0x20;
  lis r4, 0x8016;
  stw r0, 0x1c(r29);
  addi r4, r4, 0x1eec;
  lwz r3, 0x18(r29);
  bl DVDLowReadDiskID;
  b lbl_80161ed4;
  lwz r0, 0x14(r29);
  cmpwi r0, 0;
  bne lbl_80161a94;
  lis r3, 0x8034;
  lwz r4, -0x6510(r13);
  addi r3, r3, 0x30a0;
  li r0, 0;
  stw r3, -0x6510(r13);
  stw r0, 0xc(r4);
  lwz r12, 0x28(r4);
  cmpwi r12, 0;
  beq lbl_80161a8c;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80161a8c:
  bl stateReady;
  b lbl_80161ed4;
lbl_80161a94:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lwz r4, 0x20(r29);
  lis r0, 8;
  lwz r3, 0x14(r29);
  subf r30, r4, r3;
  cmplw r30, r0;
  ble lbl_80161ab8;
  lis r30, 8;
lbl_80161ab8:
  lwz r0, 0x20(r29);
  lwz r3, 0x10(r29);
  srwi r0, r0, 2;
  stw r30, 0x1c(r29);
  lwz r26, 8(r29);
  add r27, r3, r0;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80161aec;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_80161aec:
  lwz r0, -0x65a0(r13);
  lis r28, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r28, r28, 0x33c0;
  mulli r4, r0, 0x14;
  lwz r0, -0x65a0(r13);
  mulli r3, r3, 0x14;
  add r4, r28, r4;
  stw r26, 0x1c(r4);
  add r3, r28, r3;
  mulli r0, r0, 0x14;
  stw r27, 0x20(r3);
  add r3, r28, r0;
  stw r30, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r28, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r3, 0x20(r29);
  lis r6, 0x8016;
  lwz r7, 0x18(r29);
  addi r6, r6, 0x1eec;
  srwi r0, r3, 2;
  lwz r5, 0x10(r29);
  lwz r4, 0x1c(r29);
  add r3, r7, r3;
  add r5, r5, r0;
  bl DVDLowRead;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r4, 0x8016;
  lwz r3, 0x10(r29);
  addi r4, r4, 0x1eec;
  bl DVDLowSeek;
  b lbl_80161ed4;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x1eec;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_80161ed4;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x1eec;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r5, 0x8016;
  lwz r3, 0x10(r29);
  lwz r4, 0x14(r29);
  addi r5, r5, 0x1eec;
  bl DVDLowAudioBufferConfig;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  li r0, 0x20;
  lis r4, 0x8016;
  stw r0, 0x1c(r29);
  addi r4, r4, 0x1eec;
  lwz r3, 0x18(r29);
  bl DVDLowInquiry;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x1eec;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_80161ed4;
  li r3, 1;
  bl DVDLowSetSpinupFlag;
  lis r3, 0x8016;
  addi r3, r3, 0x1eec;
  bl DVDLowReset;
  b lbl_80161ed4;
  lwz r0, 0x14(r29);
  cmpwi r0, 0;
  bne lbl_80161c84;
  lis r3, 0x8034;
  lwz r4, -0x6510(r13);
  addi r3, r3, 0x30a0;
  li r0, 0;
  stw r3, -0x6510(r13);
  stw r0, 0xc(r4);
  lwz r12, 0x28(r4);
  cmpwi r12, 0;
  beq lbl_80161c7c;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80161c7c:
  bl stateReady;
  b lbl_80161ed4;
lbl_80161c84:
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lwz r4, 0x20(r29);
  lis r0, 8;
  lwz r3, 0x14(r29);
  subf r30, r4, r3;
  cmplw r30, r0;
  ble lbl_80161ca8;
  lis r30, 8;
lbl_80161ca8:
  lwz r0, 0x20(r29);
  lwz r3, 0x10(r29);
  srwi r0, r0, 2;
  stw r30, 0x1c(r29);
  lwz r26, 8(r29);
  add r27, r3, r0;
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r31, r3;
  cmplwi r0, 5;
  blt lbl_80161cdc;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_80161cdc:
  lwz r0, -0x65a0(r13);
  lis r28, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r28, r28, 0x33c0;
  mulli r4, r0, 0x14;
  lwz r0, -0x65a0(r13);
  mulli r3, r3, 0x14;
  add r4, r28, r4;
  stw r26, 0x1c(r4);
  add r3, r28, r3;
  mulli r0, r0, 0x14;
  stw r27, 0x20(r3);
  add r3, r28, r0;
  stw r30, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r28, r5;
  stw r3, 0x2c(r4);
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r3, 0x20(r29);
  lis r6, 0x8016;
  lwz r7, 0x18(r29);
  addi r6, r6, 0x1eec;
  srwi r0, r3, 2;
  lwz r5, 0x10(r29);
  lwz r4, 0x1c(r29);
  add r3, r7, r3;
  add r5, r5, r0;
  bl DVDLowUnencryptedRead;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r8, 0x8016;
  lwz r3, 0x10(r29);
  lwz r7, 0x18(r29);
  addi r8, r8, 0x1eec;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  bl DVDLowOpenPartition;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r3, 0x8016;
  addi r3, r3, 0x1eec;
  bl DVDLowClosePartition;
  b lbl_80161ed4;
  lis r3, 0x8016;
  addi r3, r3, 0x1eec;
  bl DVDLowPrepareCoverRegister;
  b lbl_80161ed4;
  lis r3, 0x8016;
  addi r3, r3, 0x1eec;
  bl DVDLowPrepareCoverRegister;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r4, 0x8016;
  lis r3, 2;
  addi r4, r4, 0x1eec;
  bl DVDLowSetMaximumRotation;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lis r3, 0x8034;
  li r0, 0x20;
  addi r3, r3, 0x3140;
  lis r4, 0x8016;
  stw r3, 0x18(r29);
  addi r4, r4, 0x1eec;
  stw r0, 0x1c(r29);
  bl DVDLowReadDiskID;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lwz r10, 0x18(r29);
  lwz r0, 0x3a0(r10);
  cmpwi r0, 0;
  bne lbl_80161e54;
  lwz r0, 0x4dc0(r10);
  cmpwi r0, 0;
  bne lbl_80161e54;
  lis r6, 0x8016;
  lwz r3, 0x10(r29);
  addi r4, r10, 0x3a0;
  addi r5, r10, 0x4dc0;
  addi r6, r6, 0x1eec;
  bl DVDLowGetNoDiscBufferSizes;
  b lbl_80161ed4;
lbl_80161e54:
  lis r3, 0x8016;
  mr r4, r10;
  addi r3, r3, 0x1eec;
  addi r5, r10, 0x3a0;
  stw r3, 8(r1);
  addi r6, r10, 0x3c0;
  addi r7, r10, 0x4dc0;
  addi r8, r10, 0x4de0;
  lwz r3, 0x10(r29);
  addi r9, r10, 0x5de0;
  addi r10, r10, 0x5e00;
  bl DVDLowGetNoDiscOpenPartitionParams;
  b lbl_80161ed4;
  li r3, 0;
  bl DVDLowClearCoverInterrupt;
  lwz r8, 0x18(r29);
  lis r9, 0x8016;
  lwz r3, 0x10(r29);
  addi r9, r9, 0x1eec;
  lwz r5, 0x3a0(r8);
  addi r4, r8, 0x2c0;
  lwz r7, 0x4dc0(r8);
  addi r6, r8, 0x3c0;
  addi r8, r8, 0x4de0;
  bl DVDLowOpenPartitionWithTmdAndTicketView;
  b lbl_80161ed4;
lbl_80161ebc:
  lwz r12, -0x7330(r13);
  lis r4, 0x8016;
  mr r3, r29;
  addi r4, r4, 0x1eec;
  mtctr r12;
  bctrl;
lbl_80161ed4:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: dvd_cbForStateBusy
// PAL: 0x80161eec..0x801628cc
MARK_BINARY_BLOB(dvd_cbForStateBusy, 0x80161eec, 0x801628cc);
asm UNKNOWN_FUNCTION(dvd_cbForStateBusy) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  lis r30, 0x8034;
  addi r30, r30, -6784;
  stw r29, 0x14(r1);
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  cmpwi r0, 0;
  bne lbl_80161f30;
  lis r4, 0x8034;
  addi r4, r4, 0x33c0;
  stw r31, 0x78(r4);
  b lbl_80161f4c;
lbl_80161f30:
  lwz r4, -0x65a0(r13);
  lis r5, 0x8034;
  addi r5, r5, 0x33c0;
  addi r0, r4, -1;
  mulli r0, r0, 0x14;
  add r4, r5, r0;
  stw r31, 0x28(r4);
lbl_80161f4c:
  bl OSRestoreInterrupts;
  cmplwi r31, 0x10;
  bne lbl_80161f70;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4568;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_801628b0;
lbl_80161f70:
  cmplwi r31, 0x20;
  bne lbl_80161f90;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4569;
  addi r4, r4, -4204;
  bl __DVDStoreErrorCode;
  b lbl_801628b0;
lbl_80161f90:
  lwz r0, -0x651c(r13);
  cmplwi r0, 3;
  beq lbl_80161fa8;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xf;
  bne lbl_801620ec;
lbl_80161fa8:
  rlwinm. r0, r31, 0, 0x1e, 0x1e;
  beq lbl_80161fc8;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_801628b0;
lbl_80161fc8:
  li r0, 0;
  stw r0, -0x6588(r13);
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xf;
  bne lbl_80161fe4;
  li r0, 1;
  stw r0, -0x652c(r13);
lbl_80161fe4:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80162058;
  lwz r29, -0x6510(r13);
  addi r3, r30, 0x4b20;
  li r0, 7;
  li r4, 0;
  stw r0, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r29);
  lwz r12, 0x28(r29);
  cmpwi r12, 0;
  beq lbl_80162030;
  mr r4, r29;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80162030:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_8016204c;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8016204c:
  bl stateReady;
  li r0, 1;
  b lbl_8016205c;
lbl_80162058:
  li r0, 0;
lbl_8016205c:
  cmpwi r0, 0;
  bne lbl_801628b0;
  lwz r0, -0x6530(r13);
  cmplwi r0, 2;
  beq lbl_801628b0;
  lwz r4, -0x6510(r13);
  li r0, 7;
  li r3, 1;
  stw r0, 0xc(r4);
  lwz r0, -0x6578(r13);
  stw r3, -0x6530(r13);
  cmpwi r0, 0;
  bne lbl_801628b0;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_801628b0;
  stw r3, -0x6578(r13);
  addi r3, r30, 0x4b80;
  bl OSCreateAlarm;
  bl OSGetTick;
  lis r5, 0x8000;
  lis r4, 0x1062;
  lwz r0, 0xf8(r5);
  lis r9, 0x8016;
  mr r6, r3;
  addi r4, r4, 0x4dd3;
  srwi r0, r0, 2;
  addi r3, r30, 0x4b80;
  mulhwu r0, r4, r0;
  addi r9, r9, 0x15f0;
  li r5, 0;
  li r7, 0;
  srwi r0, r0, 6;
  mulli r8, r0, 0x64;
  bl OSSetPeriodicAlarm;
  b lbl_801628b0;
lbl_801620ec:
  lwz r4, -0x651c(r13);
  cmplwi r4, 1;
  beq lbl_80162118;
  cmplwi r4, 4;
  beq lbl_80162118;
  cmplwi r4, 5;
  beq lbl_80162118;
  cmplwi r4, 0x21;
  beq lbl_80162118;
  cmplwi r4, 0xe;
  bne lbl_80162120;
lbl_80162118:
  li r0, 1;
  b lbl_80162138;
lbl_80162120:
  lwz r0, -0x7324(r13);
  cmplw r4, r0;
  bne lbl_80162134;
  li r0, 1;
  b lbl_80162138;
lbl_80162134:
  li r0, 0;
lbl_80162138:
  cmpwi r0, 0;
  beq lbl_80162168;
  andi. r0, r31, 9;
  beq lbl_80162154;
  lwz r3, -0x6510(r13);
  lwz r4, 0x1c(r3);
  b lbl_80162158;
lbl_80162154:
  li r4, 0;
lbl_80162158:
  lwz r3, -0x6510(r13);
  lwz r0, 0x20(r3);
  add r0, r0, r4;
  stw r0, 0x20(r3);
lbl_80162168:
  lwz r0, -0x657c(r13);
  cmpwi r0, 0;
  beq lbl_801621d4;
  lwz r31, -0x6510(r13);
  li r4, 0;
  addi r3, r30, 0x4b20;
  stw r4, -0x657c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_801621b0;
  mr r4, r31;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_801621b0:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_801621cc;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_801621cc:
  bl stateReady;
  b lbl_801628b0;
lbl_801621d4:
  clrlwi. r0, r31, 0x1f;
  beq lbl_80162770;
  li r29, 0;
  stw r29, -0x6588(r13);
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x10;
  bne lbl_8016224c;
  lwz r3, -0x6510(r13);
  lwz r0, 0x10(r3);
  cmpwi r0, 0;
  beq lbl_8016220c;
  li r0, 2;
  stw r0, -0x6530(r13);
  b lbl_80162214;
lbl_8016220c:
  li r0, 1;
  stw r0, -0x6530(r13);
lbl_80162214:
  lwz r31, -0x6510(r13);
  addi r3, r30, 0x4b20;
  li r0, 0;
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_80162244;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162244:
  bl stateReady;
  b lbl_801628b0;
lbl_8016224c:
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x20;
  bne lbl_801622a0;
  bl __OSGetSystemTime;
  lwz r31, -0x6510(r13);
  addi r0, r30, 0x4b20;
  stw r4, -0x6534(r13);
  stw r3, -0x6538(r13);
  stw r29, -0x652c(r13);
  stw r29, -0x658c(r13);
  stw r0, -0x6510(r13);
  stw r29, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_80162298;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162298:
  bl stateReady;
  b lbl_801628b0;
lbl_801622a0:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_8016230c;
  lwz r31, -0x6510(r13);
  addi r3, r30, 0x4b20;
  stw r29, -0x658c(r13);
  li r0, 0xa;
  stw r29, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_801622e4;
  mr r4, r31;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_801622e4:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_80162300;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162300:
  bl stateReady;
  li r0, 1;
  b lbl_80162310;
lbl_8016230c:
  li r0, 0;
lbl_80162310:
  cmpwi r0, 0;
  bne lbl_801628b0;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x26;
  bne lbl_801623d4;
  bl DVDLowGetCoverRegister;
  mr r31, r3;
  bl __OSGetSystemTime;
  lis r6, 0x8000;
  lis r5, 0x1062;
  lwz r6, 0xf8(r6);
  addi r7, r5, 0x4dd3;
  lwz r8, -0x6538(r13);
  li r0, 0;
  srwi r5, r6, 2;
  lwz r9, -0x6534(r13);
  mulhwu r6, r7, r5;
  subfc r4, r9, r4;
  xoris r5, r0, 0x8000;
  subfe r0, r8, r3;
  xoris r0, r0, 0x8000;
  srwi r3, r6, 6;
  mulli r3, r3, 0x64;
  subfc r3, r3, r4;
  subfe r5, r5, r0;
  subfe r5, r0, r0;
  neg. r5, r5;
  beq lbl_80162388;
  li r3, 0;
  b lbl_8016239c;
lbl_80162388:
  clrlwi. r0, r31, 0x1f;
  beq lbl_80162398;
  li r3, 1;
  b lbl_8016239c;
lbl_80162398:
  li r3, 2;
lbl_8016239c:
  lwz r31, -0x6510(r13);
  addi r4, r30, 0x4b20;
  li r0, 0;
  stw r4, -0x6510(r13);
  stw r0, 0xc(r31);
  stw r3, 0x10(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_801623cc;
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_801623cc:
  bl stateReady;
  b lbl_801628b0;
lbl_801623d4:
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x24;
  bne lbl_8016244c;
  bl DVDLowGetCoverRegister;
  rlwinm. r0, r3, 0x1e, 0x1f, 0x1f;
  bne lbl_801623f4;
  clrlwi. r0, r3, 0x1f;
  beq lbl_801623fc;
lbl_801623f4:
  li r3, 0;
  b lbl_80162414;
lbl_801623fc:
  lwz r0, -0x658c(r13);
  cmpwi r0, 0;
  beq lbl_80162410;
  li r3, 0;
  b lbl_80162414;
lbl_80162410:
  li r3, 1;
lbl_80162414:
  lwz r31, -0x6510(r13);
  addi r4, r30, 0x4b20;
  li r0, 0;
  stw r4, -0x6510(r13);
  stw r0, 0xc(r31);
  stw r3, 0x10(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_80162444;
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_80162444:
  bl stateReady;
  b lbl_801628b0;
lbl_8016244c:
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x28;
  bne lbl_80162564;
  lwz r4, -0x6510(r13);
  addi r3, r30, 0x4bc0;
  lwz r4, 0x24(r4);
  bl DVDCompareDiskID;
  cmpwi r3, 0;
  beq lbl_801624c8;
  lwz r3, -0x6514(r13);
  addi r4, r30, 0x4bc0;
  li r5, 0x20;
  bl memcpy;
  lwz r31, -0x6510(r13);
  addi r4, r30, 0x4b20;
  li r3, 0;
  li r0, 1;
  stw r4, -0x6510(r13);
  stw r3, 0xc(r31);
  stw r0, 0x10(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_801624b8;
  mr r4, r31;
  li r3, 1;
  mtctr r12;
  bctrl;
lbl_801624b8:
  li r0, 0;
  stw r0, -0x6588(r13);
  bl stateReady;
  b lbl_801628b0;
lbl_801624c8:
  bl OSDisableInterrupts;
  lwz r0, -0x65a0(r13);
  mr r30, r3;
  cmplwi r0, 5;
  blt lbl_801624e4;
  li r0, 0;
  stw r0, -0x65a0(r13);
lbl_801624e4:
  lwz r0, -0x65a0(r13);
  lis r31, 0x8034;
  lwz r3, -0x65a0(r13);
  addi r31, r31, 0x33c0;
  mulli r5, r0, 0x14;
  lwz r0, -0x65a0(r13);
  li r6, 0x10;
  li r4, 0;
  mulli r3, r3, 0x14;
  add r5, r31, r5;
  stw r6, 0x1c(r5);
  add r3, r31, r3;
  mulli r0, r0, 0x14;
  stw r4, 0x20(r3);
  add r3, r31, r0;
  stw r4, 0x24(r3);
  bl OSGetTick;
  lwz r0, -0x65a0(r13);
  lwz r4, -0x65a0(r13);
  mulli r5, r0, 0x14;
  addi r0, r4, 1;
  stw r0, -0x65a0(r13);
  add r4, r31, r5;
  stw r3, 0x2c(r4);
  mr r3, r30;
  bl OSRestoreInterrupts;
  lis r5, 0x8016;
  li r3, 0;
  addi r5, r5, 0x7bc;
  li r4, 0;
  bl DVDLowStopMotor;
  b lbl_801628b0;
lbl_80162564:
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x29;
  bne lbl_801625c0;
  lwz r3, -0x6510(r13);
  lwz r4, 0x18(r3);
  lwz r0, 0x5de0(r4);
  cmpwi r0, 0;
  bne lbl_8016258c;
  bl stateBusy;
  b lbl_801628b0;
lbl_8016258c:
  addi r4, r30, 0x4b20;
  li r0, 0;
  stw r4, -0x6510(r13);
  stw r0, 0xc(r3);
  lwz r12, 0x28(r3);
  cmpwi r12, 0;
  beq lbl_801625b8;
  mr r4, r3;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_801625b8:
  bl stateReady;
  b lbl_801628b0;
lbl_801625c0:
  lwz r4, -0x651c(r13);
  cmplwi r4, 1;
  beq lbl_801625ec;
  cmplwi r4, 4;
  beq lbl_801625ec;
  cmplwi r4, 5;
  beq lbl_801625ec;
  cmplwi r4, 0x21;
  beq lbl_801625ec;
  cmplwi r4, 0xe;
  bne lbl_801625f4;
lbl_801625ec:
  li r0, 1;
  b lbl_8016260c;
lbl_801625f4:
  lwz r0, -0x7324(r13);
  cmplw r4, r0;
  bne lbl_80162608;
  li r0, 1;
  b lbl_8016260c;
lbl_80162608:
  li r0, 0;
lbl_8016260c:
  cmpwi r0, 0;
  beq lbl_80162664;
  lwz r3, -0x6510(r13);
  lwz r4, 0x20(r3);
  lwz r0, 0x14(r3);
  cmplw r4, r0;
  beq lbl_80162630;
  bl stateBusy;
  b lbl_801628b0;
lbl_80162630:
  addi r4, r30, 0x4b20;
  li r0, 0;
  stw r4, -0x6510(r13);
  stw r0, 0xc(r3);
  lwz r12, 0x28(r3);
  cmpwi r12, 0;
  beq lbl_8016265c;
  mr r4, r3;
  lwz r3, 0x20(r3);
  mtctr r12;
  bctrl;
lbl_8016265c:
  bl stateReady;
  b lbl_801628b0;
lbl_80162664:
  lwz r4, -0x651c(r13);
  cmplwi r4, 9;
  beq lbl_80162688;
  cmplwi r4, 0xa;
  beq lbl_80162688;
  cmplwi r4, 0xb;
  beq lbl_80162688;
  cmplwi r4, 0xc;
  bne lbl_80162690;
lbl_80162688:
  li r0, 1;
  b lbl_801626d4;
lbl_80162690:
  lis r3, 0x8029;
  lwzu r0, -0x79f8(r3);
  cmplw r4, r0;
  bne lbl_801626a8;
  li r0, 1;
  b lbl_801626d4;
lbl_801626a8:
  lwz r0, 4(r3);
  cmplw r4, r0;
  bne lbl_801626bc;
  li r0, 1;
  b lbl_801626d4;
lbl_801626bc:
  lwz r0, 8(r3);
  cmplw r4, r0;
  bne lbl_801626d0;
  li r0, 1;
  b lbl_801626d4;
lbl_801626d0:
  li r0, 0;
lbl_801626d4:
  cmpwi r0, 0;
  beq lbl_80162738;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xb;
  beq lbl_801626f4;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xa;
  bne lbl_80162700;
lbl_801626f4:
  bl DVDLowGetImmBufferReg;
  slwi r3, r3, 2;
  b lbl_80162704;
lbl_80162700:
  bl DVDLowGetImmBufferReg;
lbl_80162704:
  lwz r31, -0x6510(r13);
  addi r4, r30, 0x4b20;
  li r0, 0;
  stw r4, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_80162730;
  mr r4, r31;
  mtctr r12;
  bctrl;
lbl_80162730:
  bl stateReady;
  b lbl_801628b0;
lbl_80162738:
  lwz r31, -0x6510(r13);
  addi r3, r30, 0x4b20;
  li r0, 0;
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_80162768;
  mr r4, r31;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162768:
  bl stateReady;
  b lbl_801628b0;
lbl_80162770:
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xe;
  bne lbl_80162794;
  lis r3, 0x123;
  lis r4, 0x8016;
  addi r3, r3, 0x4567;
  addi r4, r4, -4224;
  bl __DVDStoreErrorCode;
  b lbl_801628b0;
lbl_80162794:
  lwz r0, -0x651c(r13);
  cmplwi r0, 1;
  beq lbl_801627d0;
  lwz r0, -0x651c(r13);
  cmplwi r0, 4;
  beq lbl_801627d0;
  lwz r0, -0x651c(r13);
  cmplwi r0, 5;
  beq lbl_801627d0;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0x21;
  beq lbl_801627d0;
  lwz r0, -0x651c(r13);
  cmplwi r0, 0xe;
  bne lbl_80162894;
lbl_801627d0:
  lwz r29, -0x6510(r13);
  lwz r3, 0x20(r29);
  lwz r0, 0x14(r29);
  cmplw r3, r0;
  bne lbl_80162894;
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80162850;
  li r4, 0;
  addi r3, r30, 0x4b20;
  stw r4, -0x658c(r13);
  li r0, 0xa;
  stw r4, -0x6590(r13);
  stw r3, -0x6510(r13);
  stw r0, 0xc(r29);
  lwz r12, 0x28(r29);
  cmpwi r12, 0;
  beq lbl_80162828;
  mr r4, r29;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80162828:
  lwz r12, -0x6520(r13);
  cmpwi r12, 0;
  beq lbl_80162844;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162844:
  bl stateReady;
  li r0, 1;
  b lbl_80162854;
lbl_80162850:
  li r0, 0;
lbl_80162854:
  cmpwi r0, 0;
  bne lbl_801628b0;
  lwz r31, -0x6510(r13);
  addi r3, r30, 0x4b20;
  li r0, 0;
  stw r3, -0x6510(r13);
  stw r0, 0xc(r31);
  lwz r12, 0x28(r31);
  cmpwi r12, 0;
  beq lbl_8016288c;
  mr r4, r31;
  lwz r3, 0x20(r31);
  mtctr r12;
  bctrl;
lbl_8016288c:
  bl stateReady;
  b lbl_801628b0;
lbl_80162894:
  li r3, 0x27;
  li r4, 0;
  li r5, 0;
  bl dvd_StampCommand;
  lis r3, 0x8016;
  addi r3, r3, -3704;
  bl DVDLowRequestError;
lbl_801628b0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DVDReadAbsAsyncPrio
// PAL: 0x801628cc..0x801629b0
MARK_BINARY_BLOB(DVDReadAbsAsyncPrio, 0x801628cc, 0x801629b0);
asm UNKNOWN_FUNCTION(DVDReadAbsAsyncPrio) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r9, 1;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  mr r31, r8;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r9, 8(r3);
  stw r4, 0x18(r3);
  stw r5, 0x14(r3);
  stw r6, 0x10(r3);
  stw r0, 0x20(r3);
  stw r7, 0x28(r3);
  lwz r0, -0x7334(r13);
  cmpwi r0, 0;
  beq lbl_8016294c;
  cmplwi r9, 1;
  beq lbl_80162940;
  cmplwi r9, 4;
  beq lbl_80162940;
  cmplwi r9, 5;
  beq lbl_80162940;
  cmplwi r9, 0x21;
  beq lbl_80162940;
  cmplwi r9, 0xe;
  bne lbl_8016294c;
lbl_80162940:
  lwz r3, 0x18(r3);
  lwz r4, 0x14(r29);
  bl DCInvalidateRange;
lbl_8016294c:
  bl OSDisableInterrupts;
  li r0, 2;
  mr r30, r3;
  stw r0, 0xc(r29);
  mr r3, r31;
  mr r4, r29;
  bl __DVDPushWaitingQueue;
  lwz r0, -0x6510(r13);
  mr r31, r3;
  cmpwi r0, 0;
  bne lbl_80162988;
  lwz r0, -0x659c(r13);
  cmpwi r0, 0;
  bne lbl_80162988;
  bl stateReady;
lbl_80162988:
  mr r3, r30;
  bl OSRestoreInterrupts;
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

// Symbol: DVDInquiryAsync
// PAL: 0x801629b0..0x80162a88
MARK_BINARY_BLOB(DVDInquiryAsync, 0x801629b0, 0x80162a88);
asm UNKNOWN_FUNCTION(DVDInquiryAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r7, 0xe;
  li r6, 0x20;
  stw r0, 0x14(r1);
  li r0, 0;
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  stw r7, 8(r3);
  stw r4, 0x18(r3);
  stw r6, 0x14(r3);
  stw r0, 0x20(r3);
  stw r5, 0x28(r3);
  lwz r0, -0x7334(r13);
  cmpwi r0, 0;
  beq lbl_80162a28;
  cmplwi r7, 1;
  beq lbl_80162a1c;
  cmplwi r7, 4;
  beq lbl_80162a1c;
  cmplwi r7, 5;
  beq lbl_80162a1c;
  cmplwi r7, 0x21;
  beq lbl_80162a1c;
  cmplwi r7, 0xe;
  bne lbl_80162a28;
lbl_80162a1c:
  lwz r3, 0x18(r3);
  lwz r4, 0x14(r31);
  bl DCInvalidateRange;
lbl_80162a28:
  bl OSDisableInterrupts;
  li r0, 2;
  mr r30, r3;
  stw r0, 0xc(r31);
  mr r4, r31;
  li r3, 2;
  bl __DVDPushWaitingQueue;
  lwz r0, -0x6510(r13);
  mr r31, r3;
  cmpwi r0, 0;
  bne lbl_80162a64;
  lwz r0, -0x659c(r13);
  cmpwi r0, 0;
  bne lbl_80162a64;
  bl stateReady;
lbl_80162a64:
  mr r3, r30;
  bl OSRestoreInterrupts;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDGetCommandBlockStatus
// PAL: 0x80162a88..0x80162b50
MARK_BINARY_BLOB(DVDGetCommandBlockStatus, 0x80162a88, 0x80162b50);
asm UNKNOWN_FUNCTION(DVDGetCommandBlockStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  lwz r0, 0xc(r29);
  mr r30, r3;
  cmpwi r0, 3;
  bne lbl_80162ac0;
  li r31, 1;
  b lbl_80162b28;
lbl_80162ac0:
  lwz r0, 0xc(r29);
  cmpwi r0, 5;
  bne lbl_80162ad4;
  li r31, 4;
  b lbl_80162b28;
lbl_80162ad4:
  lis r31, 0x8034;
  lwz r0, -0x6510(r13);
  addi r31, r31, 0x31d0;
  cmplw r0, r31;
  bne lbl_80162b24;
  bl __DVDGetNextWaitingQueue;
  cmpwi r3, 0;
  beq lbl_80162b0c;
  cmplw r29, r3;
  bne lbl_80162b04;
  li r31, 1;
  b lbl_80162b28;
lbl_80162b04:
  lwz r31, 0xc(r29);
  b lbl_80162b28;
lbl_80162b0c:
  cmplw r29, r31;
  bne lbl_80162b1c;
  li r31, 0;
  b lbl_80162b28;
lbl_80162b1c:
  lwz r31, 0xc(r29);
  b lbl_80162b28;
lbl_80162b24:
  lwz r31, 0xc(r29);
lbl_80162b28:
  mr r3, r30;
  bl OSRestoreInterrupts;
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

// Symbol: DVDGetDriveStatus
// PAL: 0x80162b50..0x80162bec
MARK_BINARY_BLOB(DVDGetDriveStatus, 0x80162b50, 0x80162bec);
asm UNKNOWN_FUNCTION(DVDGetDriveStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl OSDisableInterrupts;
  lwz r0, -0x6594(r13);
  mr r31, r3;
  cmpwi r0, 0;
  beq lbl_80162b80;
  li r30, -1;
  b lbl_80162bc8;
lbl_80162b80:
  lwz r0, -0x6598(r13);
  cmpwi r0, 0;
  beq lbl_80162b94;
  li r30, 8;
  b lbl_80162bc8;
lbl_80162b94:
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  bne lbl_80162ba8;
  li r30, 0;
  b lbl_80162bc8;
lbl_80162ba8:
  lis r4, 0x8034;
  addi r4, r4, 0x30a0;
  cmplw r3, r4;
  bne lbl_80162bc0;
  li r3, 0;
  b lbl_80162bc4;
lbl_80162bc0:
  bl DVDGetCommandBlockStatus;
lbl_80162bc4:
  mr r30, r3;
lbl_80162bc8:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDSetAutoInvalidation
// PAL: 0x80162bec..0x80162bfc
MARK_BINARY_BLOB(DVDSetAutoInvalidation, 0x80162bec, 0x80162bfc);
asm UNKNOWN_FUNCTION(DVDSetAutoInvalidation) {
  // clang-format off
  nofralloc;
  mr r0, r3;
  lwz r3, -0x7334(r13);
  stw r0, -0x7334(r13);
  blr;
  // clang-format on
}

// Symbol: DVDPause
// PAL: 0x80162bfc..0x80162c38
MARK_BINARY_BLOB(DVDPause, 0x80162bfc, 0x80162c38);
asm UNKNOWN_FUNCTION(DVDPause) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl OSDisableInterrupts;
  lwz r0, -0x6510(r13);
  li r4, 1;
  stw r4, -0x659c(r13);
  cmpwi r0, 0;
  bne lbl_80162c24;
  stw r4, -0x6598(r13);
lbl_80162c24:
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDResume
// PAL: 0x80162c38..0x80162c88
MARK_BINARY_BLOB(DVDResume, 0x80162c38, 0x80162c88);
asm UNKNOWN_FUNCTION(DVDResume) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl OSDisableInterrupts;
  li r4, 0;
  mr r31, r3;
  stw r4, -0x659c(r13);
  lwz r0, -0x6598(r13);
  cmpwi r0, 0;
  beq lbl_80162c6c;
  stw r4, -0x6598(r13);
  bl stateReady;
lbl_80162c6c:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: DVDCancelAsync
// PAL: 0x80162c88..0x80162fec
MARK_BINARY_BLOB(DVDCancelAsync, 0x80162c88, 0x80162fec);
asm UNKNOWN_FUNCTION(DVDCancelAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  lwz r4, 0xc(r29);
  mr r31, r3;
  addi r0, r4, 1;
  cmplwi r0, 0xd;
  bgt lbl_80162fc4;
  lis r4, 0x8029;
  slwi r0, r0, 2;
  addi r4, r4, -31040;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  cmpwi r30, 0;
  beq lbl_80162fc4;
  mr r12, r30;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_80162fc4;
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80162d10;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80162fd0;
lbl_80162d10:
  li r0, 1;
  stw r30, -0x6520(r13);
  stw r0, -0x6590(r13);
  lwz r0, 8(r29);
  cmplwi r0, 4;
  beq lbl_80162d50;
  cmplwi r0, 0x21;
  beq lbl_80162d50;
  cmplwi r0, 0x22;
  beq lbl_80162d50;
  cmplwi r0, 0x29;
  beq lbl_80162d50;
  cmplwi r0, 0x2a;
  beq lbl_80162d50;
  cmplwi r0, 1;
  bne lbl_80162fc4;
lbl_80162d50:
  li r0, 1;
  stw r0, -0x657c(r13);
  b lbl_80162fc4;
  mr r3, r29;
  bl __DVDDequeueWaitingQueue;
  lwz r12, 0x28(r29);
  li r0, 0xa;
  stw r0, 0xc(r29);
  cmpwi r12, 0;
  beq lbl_80162d88;
  mr r4, r29;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80162d88:
  cmpwi r30, 0;
  beq lbl_80162fc4;
  mr r12, r30;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_80162fc4;
  lwz r0, 8(r29);
  cmplwi r0, 0x2a;
  bgt lbl_80162e4c;
  lis r3, 0x8029;
  slwi r0, r0, 2;
  addi r3, r3, -31212;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  cmpwi r30, 0;
  beq lbl_80162fc4;
  mr r12, r30;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
  b lbl_80162fc4;
  lwz r0, -0x63a8(r13);
  cmpwi r0, 0;
  beq lbl_80162e4c;
  lis r3, 0x8034;
  li r0, 0xa;
  addi r3, r3, 0x30a0;
  stw r3, -0x6510(r13);
  lwz r12, 0x28(r29);
  stw r0, 0xc(r29);
  cmpwi r12, 0;
  beq lbl_80162e28;
  mr r4, r29;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80162e28:
  cmpwi r30, 0;
  beq lbl_80162e44;
  mr r12, r30;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162e44:
  bl stateReady;
  b lbl_80162fc4;
lbl_80162e4c:
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80162e68;
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80162fd0;
lbl_80162e68:
  li r0, 1;
  stw r30, -0x6520(r13);
  stw r0, -0x6590(r13);
  b lbl_80162fc4;
  lwz r0, -0x6574(r13);
  cmpwi r0, 0;
  bne lbl_80162e9c;
  lwz r0, -0x6578(r13);
  cmpwi r0, 0;
  bne lbl_80162e9c;
  bl OSRestoreInterrupts;
  li r3, 0;
  b lbl_80162fd0;
lbl_80162e9c:
  lwz r0, -0x6578(r13);
  cmpwi r0, 0;
  beq lbl_80162ebc;
  lis r3, 0x8034;
  addi r3, r3, 0x3100;
  bl OSCancelAlarm;
  li r0, 0;
  stw r0, -0x6578(r13);
lbl_80162ebc:
  lwz r0, 0xc(r29);
  cmpwi r0, 4;
  bne lbl_80162ed0;
  li r0, 3;
  stw r0, -0x658c(r13);
lbl_80162ed0:
  lwz r0, 0xc(r29);
  cmpwi r0, 5;
  bne lbl_80162ee4;
  li r0, 4;
  stw r0, -0x658c(r13);
lbl_80162ee4:
  lwz r0, 0xc(r29);
  cmpwi r0, 6;
  bne lbl_80162ef8;
  li r0, 1;
  stw r0, -0x658c(r13);
lbl_80162ef8:
  lwz r0, 0xc(r29);
  cmpwi r0, 0xb;
  bne lbl_80162f0c;
  li r0, 2;
  stw r0, -0x658c(r13);
lbl_80162f0c:
  lwz r0, 0xc(r29);
  cmpwi r0, 7;
  bne lbl_80162f20;
  li r0, 7;
  stw r0, -0x658c(r13);
lbl_80162f20:
  lis r3, 0x8034;
  li r0, 0xa;
  addi r3, r3, 0x30a0;
  stw r3, -0x6510(r13);
  lwz r12, 0x28(r29);
  stw r0, 0xc(r29);
  cmpwi r12, 0;
  beq lbl_80162f50;
  mr r4, r29;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80162f50:
  cmpwi r30, 0;
  beq lbl_80162f6c;
  mr r12, r30;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162f6c:
  bl stateReady;
  b lbl_80162fc4;
  lis r3, 0x8034;
  li r0, 0xa;
  addi r3, r3, 0x30a0;
  stw r3, -0x6510(r13);
  lwz r12, 0x28(r29);
  stw r0, 0xc(r29);
  cmpwi r12, 0;
  beq lbl_80162fa4;
  mr r4, r29;
  li r3, -3;
  mtctr r12;
  bctrl;
lbl_80162fa4:
  cmpwi r30, 0;
  beq lbl_80162fc0;
  mr r12, r30;
  mr r4, r29;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_80162fc0:
  bl stateReady;
lbl_80162fc4:
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 1;
lbl_80162fd0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: DVDCancel
// PAL: 0x80162fec..0x801630d0
MARK_BINARY_BLOB(DVDCancel, 0x80162fec, 0x801630d0);
asm UNKNOWN_FUNCTION(DVDCancel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8016;
  stw r0, 0x14(r1);
  addi r4, r4, 0x30c8;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl DVDCancelAsync;
  cmpwi r3, 0;
  bne lbl_80163020;
  li r3, -1;
  b lbl_801630b0;
lbl_80163020:
  bl OSDisableInterrupts;
  mr r31, r3;
lbl_80163028:
  lwz r0, 0xc(r30);
  cmpwi r0, 0;
  beq lbl_801630a4;
  cmpwi r0, -1;
  beq lbl_801630a4;
  cmpwi r0, 0xa;
  beq lbl_801630a4;
  cmpwi r0, 3;
  bne lbl_80163098;
  lwz r0, 8(r30);
  cmplwi r0, 4;
  beq lbl_801630a4;
  cmplwi r0, 5;
  beq lbl_801630a4;
  cmplwi r0, 0xd;
  beq lbl_801630a4;
  cmplwi r0, 0x21;
  beq lbl_801630a4;
  cmplwi r0, 0x22;
  beq lbl_801630a4;
  cmplwi r0, 0x29;
  beq lbl_801630a4;
  cmplwi r0, 0x2a;
  beq lbl_801630a4;
  cmplwi r0, 0xf;
  beq lbl_801630a4;
  cmplwi r0, 0x25;
  beq lbl_801630a4;
lbl_80163098:
  addi r3, r13, -26064;
  bl OSSleepThread;
  b lbl_80163028;
lbl_801630a4:
  mr r3, r31;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_801630b0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  addi r3, r13, -26064;
  b OSWakeupThread;
  // clang-format on
}

// Symbol: DVDCancelAll
// PAL: 0x801630d0..0x8016321c
MARK_BINARY_BLOB(DVDCancelAll, 0x801630d0, 0x8016321c);
asm UNKNOWN_FUNCTION(DVDCancelAll) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  bl OSDisableInterrupts;
  li r0, 0;
  mr r28, r3;
  stw r0, -0x6584(r13);
  bl OSDisableInterrupts;
  mr r29, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x6510(r13);
  li r4, 1;
  stw r4, -0x659c(r13);
  cmpwi r0, 0;
  bne lbl_80163120;
  stw r4, -0x6598(r13);
lbl_80163120:
  bl OSRestoreInterrupts;
  b lbl_80163130;
lbl_80163128:
  li r4, 0;
  bl DVDCancelAsync;
lbl_80163130:
  bl __DVDPopWaitingQueue;
  cmpwi r3, 0;
  bne lbl_80163128;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_8016315c;
  lis r4, 0x8016;
  addi r4, r4, 0x320c;
  bl DVDCancelAsync;
  mr r30, r3;
  b lbl_8016317c;
lbl_8016315c:
  lis r0, 0x8016;
  li r30, 1;
  addic. r0, r0, 0x320c;
  beq lbl_8016317c;
  li r0, 1;
  addi r3, r13, -26064;
  stw r0, -0x6584(r13);
  bl OSWakeupThread;
lbl_8016317c:
  bl OSDisableInterrupts;
  li r4, 0;
  mr r31, r3;
  stw r4, -0x659c(r13);
  lwz r0, -0x6598(r13);
  cmpwi r0, 0;
  beq lbl_801631a0;
  stw r4, -0x6598(r13);
  bl stateReady;
lbl_801631a0:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r29;
  bl OSRestoreInterrupts;
  cmpwi r30, 0;
  bne lbl_801631c8;
  mr r3, r28;
  bl OSRestoreInterrupts;
  li r3, -1;
  b lbl_801631ec;
lbl_801631c8:
  lwz r0, -0x6584(r13);
  cmpwi r0, 0;
  bne lbl_801631e0;
  addi r3, r13, -26064;
  bl OSSleepThread;
  b lbl_801631c8;
lbl_801631e0:
  mr r3, r28;
  bl OSRestoreInterrupts;
  li r3, 0;
lbl_801631ec:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  li r0, 1;
  addi r3, r13, -26064;
  stw r0, -0x6584(r13);
  b OSWakeupThread;
  // clang-format on
}

// Symbol: DVDGetCurrentDiskID
// PAL: 0x8016321c..0x80163224
MARK_BINARY_BLOB(DVDGetCurrentDiskID, 0x8016321c, 0x80163224);
asm UNKNOWN_FUNCTION(DVDGetCurrentDiskID) {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  blr;
  // clang-format on
}

// Symbol: __BS2DVDLowCallback
// PAL: 0x80163224..0x8016322c
MARK_BINARY_BLOB(__BS2DVDLowCallback, 0x80163224, 0x8016322c);
asm UNKNOWN_FUNCTION(__BS2DVDLowCallback) {
  // clang-format off
  nofralloc;
  stw r3, -0x655c(r13);
  blr;
  // clang-format on
}

// Symbol: __DVDGetCoverStatus
// PAL: 0x8016322c..0x801632f4
MARK_BINARY_BLOB(__DVDGetCoverStatus, 0x8016322c, 0x801632f4);
asm UNKNOWN_FUNCTION(__DVDGetCoverStatus) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8016;
  stw r0, 0x14(r1);
  li r0, 0;
  addi r3, r3, 0x3224;
  stw r31, 0xc(r1);
  stw r0, -0x655c(r13);
  bl DVDLowPrepareCoverRegister;
lbl_80163250:
  lwz r0, -0x655c(r13);
  cmpwi r0, 0;
  beq lbl_80163250;
  lwz r0, -0x655c(r13);
  clrlwi. r0, r0, 0x1f;
  bne lbl_80163270;
  li r3, 0;
  b lbl_801632e0;
lbl_80163270:
  bl DVDLowGetCoverRegister;
  mr r31, r3;
  bl __OSGetSystemTime;
  lis r6, 0x8000;
  lis r5, 0x1062;
  lwz r6, 0xf8(r6);
  addi r7, r5, 0x4dd3;
  lwz r8, -0x6538(r13);
  li r0, 0;
  srwi r5, r6, 2;
  lwz r9, -0x6534(r13);
  mulhwu r6, r7, r5;
  subfc r4, r9, r4;
  xoris r5, r0, 0x8000;
  subfe r0, r8, r3;
  xoris r0, r0, 0x8000;
  srwi r3, r6, 6;
  mulli r3, r3, 0x64;
  subfc r3, r3, r4;
  subfe r5, r5, r0;
  subfe r5, r0, r0;
  neg. r5, r5;
  beq lbl_801632d4;
  li r3, 0;
  b lbl_801632e0;
lbl_801632d4:
  clrlwi r0, r31, 0x1f;
  neg r3, r0;
  addi r3, r3, 2;
lbl_801632e0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDResetWithNoSpinup
// PAL: 0x801632f4..0x80163338
MARK_BINARY_BLOB(__DVDResetWithNoSpinup, 0x801632f4, 0x80163338);
asm UNKNOWN_FUNCTION(__DVDResetWithNoSpinup) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0;
  stw r0, 0x14(r1);
  li r0, 0;
  stw r0, -0x655c(r13);
  bl DVDLowSetSpinupFlag;
  lis r3, 0x8016;
  addi r3, r3, 0x3224;
  bl DVDLowReset;
lbl_8016331c:
  lwz r0, -0x655c(r13);
  cmpwi r0, 0;
  beq lbl_8016331c;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DVDPrepareResetAsync
// PAL: 0x80163338..0x80163460
MARK_BINARY_BLOB(__DVDPrepareResetAsync, 0x80163338, 0x80163460);
asm UNKNOWN_FUNCTION(__DVDPrepareResetAsync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  bl OSDisableInterrupts;
  mr r29, r3;
  bl __DVDClearWaitingQueue;
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_80163374;
  stw r31, -0x6520(r13);
  b lbl_80163430;
lbl_80163374:
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_80163388;
  li r0, 0;
  stw r0, 0x28(r3);
lbl_80163388:
  bl OSDisableInterrupts;
  mr r30, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x6510(r13);
  li r4, 1;
  stw r4, -0x659c(r13);
  cmpwi r0, 0;
  bne lbl_801633ac;
  stw r4, -0x6598(r13);
lbl_801633ac:
  bl OSRestoreInterrupts;
  b lbl_801633bc;
lbl_801633b4:
  li r4, 0;
  bl DVDCancelAsync;
lbl_801633bc:
  bl __DVDPopWaitingQueue;
  cmpwi r3, 0;
  bne lbl_801633b4;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_801633e0;
  mr r4, r31;
  bl DVDCancelAsync;
  b lbl_801633fc;
lbl_801633e0:
  cmpwi r31, 0;
  beq lbl_801633fc;
  mr r12, r31;
  li r3, 0;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_801633fc:
  bl OSDisableInterrupts;
  li r4, 0;
  mr r31, r3;
  stw r4, -0x659c(r13);
  lwz r0, -0x6598(r13);
  cmpwi r0, 0;
  beq lbl_80163420;
  stw r4, -0x6598(r13);
  bl stateReady;
lbl_80163420:
  mr r3, r31;
  bl OSRestoreInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
lbl_80163430:
  mr r3, r29;
  bl OSRestoreInterrupts;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  li r0, 1;
  stw r0, -0x6558(r13);
  blr;
  // clang-format on
}

// Symbol: __DVDPrepareReset
// PAL: 0x80163460..0x80163594
MARK_BINARY_BLOB(__DVDPrepareReset, 0x80163460, 0x80163594);
asm UNKNOWN_FUNCTION(__DVDPrepareReset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  bl OSDisableInterrupts;
  li r31, 0;
  stw r31, -0x6558(r13);
  bl OSDisableInterrupts;
  mr r29, r3;
  bl __DVDClearWaitingQueue;
  lwz r0, -0x6590(r13);
  cmpwi r0, 0;
  beq lbl_801634ac;
  lis r3, 0x8016;
  addi r3, r3, 0x3454;
  stw r3, -0x6520(r13);
  b lbl_80163560;
lbl_801634ac:
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_801634bc;
  stw r31, 0x28(r3);
lbl_801634bc:
  bl OSDisableInterrupts;
  mr r31, r3;
  bl OSDisableInterrupts;
  lwz r0, -0x6510(r13);
  li r4, 1;
  stw r4, -0x659c(r13);
  cmpwi r0, 0;
  bne lbl_801634e0;
  stw r4, -0x6598(r13);
lbl_801634e0:
  bl OSRestoreInterrupts;
  b lbl_801634f0;
lbl_801634e8:
  li r4, 0;
  bl DVDCancelAsync;
lbl_801634f0:
  bl __DVDPopWaitingQueue;
  cmpwi r3, 0;
  bne lbl_801634e8;
  lwz r3, -0x6510(r13);
  cmpwi r3, 0;
  beq lbl_80163518;
  lis r4, 0x8016;
  addi r4, r4, 0x3454;
  bl DVDCancelAsync;
  b lbl_8016352c;
lbl_80163518:
  lis r0, 0x8016;
  addic. r0, r0, 0x3454;
  beq lbl_8016352c;
  li r0, 1;
  stw r0, -0x6558(r13);
lbl_8016352c:
  bl OSDisableInterrupts;
  li r4, 0;
  mr r30, r3;
  stw r4, -0x659c(r13);
  lwz r0, -0x6598(r13);
  cmpwi r0, 0;
  beq lbl_80163550;
  stw r4, -0x6598(r13);
  bl stateReady;
lbl_80163550:
  mr r3, r30;
  bl OSRestoreInterrupts;
  mr r3, r31;
  bl OSRestoreInterrupts;
lbl_80163560:
  mr r3, r29;
  bl OSRestoreInterrupts;
  bl OSEnableInterrupts;
lbl_8016356c:
  lwz r0, -0x6558(r13);
  cmpwi r0, 1;
  bne lbl_8016356c;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __DVDTestAlarm
// PAL: 0x80163594..0x801635b4
MARK_BINARY_BLOB(__DVDTestAlarm, 0x80163594, 0x801635b4);
asm UNKNOWN_FUNCTION(__DVDTestAlarm) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  addi r4, r4, 0x31a0;
  cmplw r3, r4;
  bne lbl_801635ac;
  li r3, 1;
  blr;
lbl_801635ac:
  b __DVDLowTestAlarm;
  blr;
  // clang-format on
}

// Symbol: __DVDStopMotorAsync
// PAL: 0x801635b4..0x801635bc
MARK_BINARY_BLOB(__DVDStopMotorAsync, 0x801635b4, 0x801635bc);
asm UNKNOWN_FUNCTION(__DVDStopMotorAsync) {
  // clang-format off
  nofralloc;
  li r3, 1;
  blr;
  // clang-format on
}
