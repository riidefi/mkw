#include "osReset.h"

#include <string.h>

#include "os.h"
#include "osError.h"
#include "osInterrupt.h"
#include "osThread.h"

// Extern function references.
// PAL: 0x8016322c
extern UNKNOWN_FUNCTION(__DVDGetCoverStatus);
// PAL: 0x80163460
extern UNKNOWN_FUNCTION(__DVDPrepareReset);
// PAL: 0x8019f2d0
extern UNKNOWN_FUNCTION(__OSGetIOSRev);
// PAL: 0x801a0598
extern UNKNOWN_FUNCTION(OSGetAppType);
// PAL: 0x801a1520
extern UNKNOWN_FUNCTION(__OSStopAudioSystem);
// PAL: 0x801a186c
extern UNKNOWN_FUNCTION(LCDisable);
// PAL: 0x801a3888
extern UNKNOWN_FUNCTION(__OSLaunchMenu);
// PAL: 0x801a81b8
extern UNKNOWN_FUNCTION(__OSReboot);
// PAL: 0x801a90b4
extern UNKNOWN_FUNCTION(__OSSyncSram);
// PAL: 0x801a92fc
extern UNKNOWN_FUNCTION(__OSGetRTCFlags);
// PAL: 0x801a9418
extern UNKNOWN_FUNCTION(__OSClearRTCFlags);
// PAL: 0x801a98e8
extern UNKNOWN_FUNCTION(OSDisableScheduler);
// PAL: 0x801a9924
extern UNKNOWN_FUNCTION(OSEnableScheduler);
// PAL: 0x801ab848
extern UNKNOWN_FUNCTION(__OSInitSTM);
// PAL: 0x801ab960
extern UNKNOWN_FUNCTION(__OSShutdownToSBY);
// PAL: 0x801ab9d8
extern UNKNOWN_FUNCTION(__OSHotReset);
// PAL: 0x801abb80
extern UNKNOWN_FUNCTION(__OSUnRegisterStateEvent);
// PAL: 0x801ac274
extern UNKNOWN_FUNCTION(__OSStopPlayRecord);
// PAL: 0x801ac45c
extern UNKNOWN_FUNCTION(__OSWriteStateFlags);
// PAL: 0x801ac540
extern UNKNOWN_FUNCTION(__OSReadStateFlags);
// PAL: 0x801ad800
extern UNKNOWN_FUNCTION(__OSRelaunchTitle);
// PAL: 0x801ae06c
extern UNKNOWN_FUNCTION(__OSReturnToMenul);
// PAL: 0x801b0124
extern UNKNOWN_FUNCTION(__PADDisableRecalibration);
// PAL: 0x801b0180
extern UNKNOWN_FUNCTION(SCInit);
// PAL: 0x801b0220
extern UNKNOWN_FUNCTION(SCCheckStatus);
// PAL: 0x801b1d00
extern UNKNOWN_FUNCTION(SCGetIdleMode);
// PAL: 0x801bcd4c
extern UNKNOWN_FUNCTION(__VISetRGBModeImm);

// Symbol: OSRegisterShutdownFunction
// PAL: 0x801a8238..0x801a82c0
MARK_BINARY_BLOB(OSRegisterShutdownFunction, 0x801a8238, 0x801a82c0);
asm void OSRegisterShutdownFunction(OSShutdownFunctionInfo* info) {
  // clang-format off
  nofralloc;
  lwz r5, -0x62f0(r13);
  b lbl_801a8244;
lbl_801a8240:
  lwz r5, 8(r5);
lbl_801a8244:
  cmpwi r5, 0;
  beq lbl_801a825c;
  lwz r4, 4(r5);
  lwz r0, 4(r3);
  cmplw r4, r0;
  ble lbl_801a8240;
lbl_801a825c:
  cmpwi r5, 0;
  bne lbl_801a8298;
  addi r4, r13, -25328;
  lwz r4, 4(r4);
  cmpwi r4, 0;
  bne lbl_801a827c;
  stw r3, -0x62f0(r13);
  b lbl_801a8280;
lbl_801a827c:
  stw r3, 8(r4);
lbl_801a8280:
  li r0, 0;
  stw r4, 0xc(r3);
  addi r4, r13, -25328;
  stw r0, 8(r3);
  stw r3, 4(r4);
  blr;
lbl_801a8298:
  stw r5, 8(r3);
  lwz r4, 0xc(r5);
  stw r3, 0xc(r5);
  cmpwi r4, 0;
  stw r4, 0xc(r3);
  bne lbl_801a82b8;
  stw r3, -0x62f0(r13);
  blr;
lbl_801a82b8:
  stw r3, 8(r4);
  blr;
  // clang-format on
}

// Symbol: __OSCallShutdownFunctions
// PAL: 0x801a82c0..0x801a8370
MARK_BINARY_BLOB(__OSCallShutdownFunctions, 0x801a82c0, 0x801a8370);
asm UNKNOWN_FUNCTION(__OSCallShutdownFunctions) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  li r3, 0;
  lwz r31, -0x62f0(r13);
  b lbl_801a8330;
lbl_801a82f4:
  cmpwi r30, 0;
  beq lbl_801a8308;
  lwz r0, 4(r31);
  cmplw r3, r0;
  bne lbl_801a8338;
lbl_801a8308:
  lwz r12, 0(r31);
  mr r3, r28;
  mr r4, r29;
  mtctr r12;
  bctrl;
  cntlzw r0, r3;
  lwz r3, 4(r31);
  srwi r0, r0, 5;
  lwz r31, 8(r31);
  or r30, r30, r0;
lbl_801a8330:
  cmpwi r31, 0;
  bne lbl_801a82f4;
lbl_801a8338:
  bl __OSSyncSram;
  cntlzw r0, r3;
  lwz r31, 0x1c(r1);
  srwi r0, r0, 5;
  or r30, r30, r0;
  cntlzw r0, r30;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  srwi r3, r0, 5;
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSShutdownDevices
// PAL: 0x801a8370..0x801a8500
MARK_BINARY_BLOB(__OSShutdownDevices, 0x801a8370, 0x801a8500);
asm UNKNOWN_FUNCTION(__OSShutdownDevices) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 5;
  mr r27, r3;
  bge lbl_801a839c;
  cmpwi r3, 0;
  beq lbl_801a83a4;
  b lbl_801a83ac;
lbl_801a839c:
  cmpwi r3, 7;
  bge lbl_801a83ac;
lbl_801a83a4:
  li r28, 0;
  b lbl_801a83b0;
lbl_801a83ac:
  li r28, 1;
lbl_801a83b0:
  bl __OSStopAudioSystem;
  cmpwi r28, 0;
  bne lbl_801a83c8;
  li r3, 1;
  bl __PADDisableRecalibration;
  mr r29, r3;
lbl_801a83c8:
  lwz r30, -0x62f0(r13);
  li r3, 0;
  li r31, 0;
  b lbl_801a8414;
lbl_801a83d8:
  cmpwi r31, 0;
  beq lbl_801a83ec;
  lwz r0, 4(r30);
  cmplw r3, r0;
  bne lbl_801a841c;
lbl_801a83ec:
  lwz r12, 0(r30);
  mr r4, r27;
  li r3, 0;
  mtctr r12;
  bctrl;
  cntlzw r0, r3;
  lwz r3, 4(r30);
  srwi r0, r0, 5;
  lwz r30, 8(r30);
  or r31, r31, r0;
lbl_801a8414:
  cmpwi r30, 0;
  bne lbl_801a83d8;
lbl_801a841c:
  bl __OSSyncSram;
  cntlzw r0, r3;
  srwi r0, r0, 5;
  or. r31, r31, r0;
  bne lbl_801a83c8;
lbl_801a8430:
  bl __OSSyncSram;
  cmpwi r3, 0;
  beq lbl_801a8430;
  bl OSDisableInterrupts;
  lwz r31, -0x62f0(r13);
  li r3, 0;
  li r30, 0;
  b lbl_801a848c;
lbl_801a8450:
  cmpwi r30, 0;
  beq lbl_801a8464;
  lwz r0, 4(r31);
  cmplw r3, r0;
  bne lbl_801a8494;
lbl_801a8464:
  lwz r12, 0(r31);
  mr r4, r27;
  li r3, 1;
  mtctr r12;
  bctrl;
  cntlzw r0, r3;
  lwz r3, 4(r31);
  srwi r0, r0, 5;
  lwz r31, 8(r31);
  or r30, r30, r0;
lbl_801a848c:
  cmpwi r31, 0;
  bne lbl_801a8450;
lbl_801a8494:
  bl __OSSyncSram;
  bl LCDisable;
  cmpwi r28, 0;
  bne lbl_801a84ac;
  mr r3, r29;
  bl __PADDisableRecalibration;
lbl_801a84ac:
  lis r3, 0x8000;
  lwz r3, 0xdc(r3);
  b lbl_801a84e0;
lbl_801a84b8:
  lhz r0, 0x2c8(r3);
  lwz r30, 0x2fc(r3);
  cmpwi r0, 4;
  beq lbl_801a84d8;
  bge lbl_801a84dc;
  cmpwi r0, 1;
  beq lbl_801a84d8;
  b lbl_801a84dc;
lbl_801a84d8:
  bl OSCancelThread;
lbl_801a84dc:
  mr r3, r30;
lbl_801a84e0:
  cmpwi r3, 0;
  bne lbl_801a84b8;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __OSGetDiscState
// PAL: 0x801a8500..0x801a856c
MARK_BINARY_BLOB(__OSGetDiscState, 0x801a8500, 0x801a856c);
asm UNKNOWN_FUNCTION(__OSGetDiscState) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  bl __DVDGetCoverStatus;
  cmplwi r3, 2;
  beq lbl_801a8528;
  li r3, 3;
  b lbl_801a8558;
lbl_801a8528:
  cmplwi r31, 1;
  bne lbl_801a8554;
  addi r3, r1, 8;
  bl __OSGetRTCFlags;
  cmpwi r3, 0;
  beq lbl_801a8554;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  bne lbl_801a8554;
  li r3, 1;
  b lbl_801a8558;
lbl_801a8554:
  li r3, 2;
lbl_801a8558:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSShutdownSystem
// PAL: 0x801a856c..0x801a8688
MARK_BINARY_BLOB(OSShutdownSystem, 0x801a856c, 0x801a8688);
asm UNKNOWN_FUNCTION(OSShutdownSystem) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  li r4, 0;
  li r5, 2;
  stw r0, 0x44(r1);
  addi r3, r1, 8;
  stw r31, 0x3c(r1);
  bl memset;
  bl SCInit;
lbl_801a8590:
  bl SCCheckStatus;
  cmplwi r3, 1;
  beq lbl_801a8590;
  addi r3, r1, 8;
  bl SCGetIdleMode;
  bl __OSStopPlayRecord;
  bl __OSUnRegisterStateEvent;
  bl __DVDPrepareReset;
  addi r3, r1, 0x18;
  bl __OSReadStateFlags;
  lbz r31, 0x1e(r1);
  bl __DVDGetCoverStatus;
  cmplwi r3, 2;
  beq lbl_801a85d0;
  li r3, 3;
  b lbl_801a8600;
lbl_801a85d0:
  cmplwi r31, 1;
  bne lbl_801a85fc;
  addi r3, r1, 0xc;
  bl __OSGetRTCFlags;
  cmpwi r3, 0;
  beq lbl_801a85fc;
  lwz r0, 0xc(r1);
  cmpwi r0, 0;
  bne lbl_801a85fc;
  li r3, 1;
  b lbl_801a8600;
lbl_801a85fc:
  li r3, 2;
lbl_801a8600:
  lbz r0, 8(r1);
  stb r3, 0x1e(r1);
  cmplwi r0, 1;
  bne lbl_801a861c;
  li r0, 5;
  stb r0, 0x1d(r1);
  b lbl_801a8624;
lbl_801a861c:
  li r0, 1;
  stb r0, 0x1d(r1);
lbl_801a8624:
  bl __OSClearRTCFlags;
  addi r3, r1, 0x18;
  bl __OSWriteStateFlags;
  addi r3, r1, 0x10;
  bl __OSGetIOSRev;
  lbz r0, 8(r1);
  cmplwi r0, 1;
  bne lbl_801a8664;
  li r0, 1;
  stw r0, -0x62f4(r13);
  bl OSDisableScheduler;
  li r3, 5;
  bl __OSShutdownDevices;
  bl OSEnableScheduler;
  bl __OSLaunchMenu;
  b lbl_801a8674;
lbl_801a8664:
  bl OSDisableScheduler;
  li r3, 2;
  bl __OSShutdownDevices;
  bl __OSShutdownToSBY;
lbl_801a8674:
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: OSRestart
// PAL: 0x801a8688..0x801a8758
MARK_BINARY_BLOB(OSRestart, 0x801a8688, 0x801a8758);
asm UNKNOWN_FUNCTION(OSRestart) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl OSGetAppType;
  mr r31, r3;
  bl __OSStopPlayRecord;
  bl __OSUnRegisterStateEvent;
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x81;
  bne lbl_801a86d4;
  bl OSDisableScheduler;
  li r3, 4;
  bl __OSShutdownDevices;
  bl OSEnableScheduler;
  bl __OSRelaunchTitle;
  b lbl_801a86f8;
lbl_801a86d4:
  cmplwi r0, 0x80;
  bne lbl_801a86f8;
  bl OSDisableScheduler;
  li r3, 4;
  bl __OSShutdownDevices;
  bl OSEnableScheduler;
  lwz r4, -0x62f8(r13);
  mr r3, r30;
  bl __OSReboot;
lbl_801a86f8:
  bl OSDisableScheduler;
  li r3, 1;
  bl __OSShutdownDevices;
  lwz r0, -0x63a4(r13);
  cmpwi r0, 0;
  bne lbl_801a871c;
  lwz r0, -0x6334(r13);
  cmpwi r0, 0;
  beq lbl_801a8720;
lbl_801a871c:
  bl __OSInitSTM;
lbl_801a8720:
  bl __OSHotReset;
  lis r3, 0x8029;
  lis r5, 0x8029;
  addi r3, r3, 0x668;
  li r4, 0x3d0;
  addi r5, r5, 0x674;
  crclr 6;
  bl OSPanic;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSReturnToMenu
// PAL: 0x801a8758..0x801a8858
MARK_BINARY_BLOB(__OSReturnToMenu, 0x801a8758, 0x801a8858);
asm UNKNOWN_FUNCTION(__OSReturnToMenu) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  stw r31, 0x3c(r1);
  stw r30, 0x38(r1);
  mr r30, r3;
  bl __OSStopPlayRecord;
  bl __OSUnRegisterStateEvent;
  bl __DVDPrepareReset;
  addi r3, r1, 0x10;
  bl __OSReadStateFlags;
  lbz r31, 0x16(r1);
  bl __DVDGetCoverStatus;
  cmplwi r3, 2;
  beq lbl_801a879c;
  li r3, 3;
  b lbl_801a87cc;
lbl_801a879c:
  cmplwi r31, 1;
  bne lbl_801a87c8;
  addi r3, r1, 8;
  bl __OSGetRTCFlags;
  cmpwi r3, 0;
  beq lbl_801a87c8;
  lwz r0, 8(r1);
  cmpwi r0, 0;
  bne lbl_801a87c8;
  li r3, 1;
  b lbl_801a87cc;
lbl_801a87c8:
  li r3, 2;
lbl_801a87cc:
  li r0, 3;
  stb r3, 0x16(r1);
  stb r0, 0x15(r1);
  stb r30, 0x17(r1);
  bl __OSClearRTCFlags;
  addi r3, r1, 0x10;
  bl __OSWriteStateFlags;
  bl OSDisableScheduler;
  li r3, 5;
  bl __OSShutdownDevices;
  bl OSEnableScheduler;
  bl __OSLaunchMenu;
  bl OSDisableScheduler;
  bl __VISetRGBModeImm;
  lwz r0, -0x63a4(r13);
  cmpwi r0, 0;
  bne lbl_801a881c;
  lwz r0, -0x6334(r13);
  cmpwi r0, 0;
  beq lbl_801a8820;
lbl_801a881c:
  bl __OSInitSTM;
lbl_801a8820:
  bl __OSHotReset;
  lis r3, 0x8029;
  lis r5, 0x8029;
  addi r3, r3, 0x668;
  li r4, 0x3d0;
  addi r5, r5, 0x674;
  crclr 6;
  bl OSPanic;
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  lwz r30, 0x38(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: OSReturnToMenu
// PAL: 0x801a8858..0x801a8898
MARK_BINARY_BLOB(OSReturnToMenu, 0x801a8858, 0x801a8898);
asm UNKNOWN_FUNCTION(OSReturnToMenu) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0;
  stw r0, 0x14(r1);
  bl __OSReturnToMenu;
  lis r3, 0x8029;
  lis r5, 0x8029;
  addi r3, r3, 0x668;
  li r4, 0x345;
  addi r5, r5, 0x6a0;
  crclr 6;
  bl OSPanic;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSReturnToSetting
// PAL: 0x801a8898..0x801a8954
MARK_BINARY_BLOB(OSReturnToSetting, 0x801a8898, 0x801a8954);
asm UNKNOWN_FUNCTION(OSReturnToSetting) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmplwi r3, 7;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8029;
  addi r31, r31, 0x668;
  bgt lbl_801a8908;
  lis r4, 0x8029;
  slwi r0, r3, 2;
  addi r4, r4, 0x820;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  addi r31, r31, 0xa0;
  b lbl_801a892c;
  addi r31, r31, 0xc0;
  b lbl_801a892c;
  addi r31, r31, 0xdc;
  b lbl_801a892c;
  addi r31, r31, 0xf4;
  b lbl_801a892c;
  addi r31, r31, 0x124;
  b lbl_801a892c;
  addi r31, r31, 0x144;
  b lbl_801a892c;
  addi r31, r31, 0x16c;
  b lbl_801a892c;
lbl_801a8908:
  mr r4, r3;
  addi r3, r31, 0x188;
  crclr 6;
  bl OSReport;
  addi r3, r31, 0;
  li r4, 0x391;
  addi r5, r13, -28968;
  crclr 6;
  bl OSPanic;
lbl_801a892c:
  mr r4, r31;
  li r3, 1;
  li r5, 0;
  crclr 6;
  bl __OSReturnToMenul;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSReturnToMenuForError
// PAL: 0x801a8954..0x801a89f8
MARK_BINARY_BLOB(__OSReturnToMenuForError, 0x801a8954, 0x801a89f8);
asm UNKNOWN_FUNCTION(__OSReturnToMenuForError) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r3, r1, 8;
  stw r31, 0x2c(r1);
  lis r31, 0x8029;
  addi r31, r31, 0x668;
  bl __OSReadStateFlags;
  li r3, 2;
  li r0, 3;
  stb r3, 0xe(r1);
  stb r0, 0xd(r1);
  bl __OSClearRTCFlags;
  addi r3, r1, 8;
  bl __OSWriteStateFlags;
  bl __OSLaunchMenu;
  bl OSDisableScheduler;
  bl __VISetRGBModeImm;
  lwz r0, -0x63a4(r13);
  cmpwi r0, 0;
  bne lbl_801a89b4;
  lwz r0, -0x6334(r13);
  cmpwi r0, 0;
  beq lbl_801a89b8;
lbl_801a89b4:
  bl __OSInitSTM;
lbl_801a89b8:
  bl __OSHotReset;
  addi r3, r31, 0;
  addi r5, r31, 0xc;
  li r4, 0x3d0;
  crclr 6;
  bl OSPanic;
  addi r3, r31, 0;
  addi r5, r31, 0x1d8;
  li r4, 0x3b8;
  crclr 6;
  bl OSPanic;
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: __OSHotResetForError
// PAL: 0x801a89f8..0x801a8a50
MARK_BINARY_BLOB(__OSHotResetForError, 0x801a89f8, 0x801a8a50);
asm UNKNOWN_FUNCTION(__OSHotResetForError) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, -0x63a4(r13);
  cmpwi r0, 0;
  bne lbl_801a8a1c;
  lwz r0, -0x6334(r13);
  cmpwi r0, 0;
  beq lbl_801a8a20;
lbl_801a8a1c:
  bl __OSInitSTM;
lbl_801a8a20:
  bl __OSHotReset;
  lis r3, 0x8029;
  lis r5, 0x8029;
  addi r3, r3, 0x668;
  li r4, 0x3d0;
  addi r5, r5, 0x674;
  crclr 6;
  bl OSPanic;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: OSGetResetCode
// PAL: 0x801a8a50..0x801a8a80
MARK_BINARY_BLOB(OSGetResetCode, 0x801a8a50, 0x801a8a80);
asm UNKNOWN_FUNCTION(OSGetResetCode) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  lwz r0, 0x7080(r3);
  cmpwi r0, 0;
  beq lbl_801a8a70;
  addi r3, r3, 0x7080;
  lwz r0, 4(r3);
  oris r3, r0, 0x8000;
  blr;
lbl_801a8a70:
  lis r3, 0xcc00;
  lwz r0, 0x3024(r3);
  srwi r3, r0, 3;
  blr;
  // clang-format on
}
