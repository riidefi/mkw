#include "out.h"

#include <rvl/os/os.h>
#include <rvl/os/osCache.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>

#include "alloc.h"
#include "axAux.h"
#include "cl.h"
#include "spb.h"
#include "vpb.h"

// Extern function references.
// PAL: 0x80123f88
extern UNKNOWN_FUNCTION(AIRegisterDMACallback);
// PAL: 0x80123fcc
extern UNKNOWN_FUNCTION(AIInitDMA);
// PAL: 0x80124048
extern UNKNOWN_FUNCTION(AIStartDMA);
// PAL: 0x8012405c
extern UNKNOWN_FUNCTION(AIGetDMABytesLeft);
// PAL: 0x80127fec
extern UNKNOWN_FUNCTION(__AXGetCurrentProfile);
// PAL: 0x8015d3fc
extern UNKNOWN_FUNCTION(DSPCheckMailToDSP);
// PAL: 0x8015d430
extern UNKNOWN_FUNCTION(DSPSendMailToDSP);
// PAL: 0x8015d444
extern UNKNOWN_FUNCTION(DSPInit);
// PAL: 0x8015d504
extern UNKNOWN_FUNCTION(DSPCheckInit);
// PAL: 0x8015d50c
extern UNKNOWN_FUNCTION(DSPAddTask);
// PAL: 0x8015d57c
extern UNKNOWN_FUNCTION(DSPAssertTask);

typedef struct AXPROFILE {
  char content[56];
} AXPROFILE;

typedef struct DSPTaskInfo {
  char content[80];
} DSPTaskInfo;

// PAL: 0x802f7d20..0x802f81a0
extern s16 __AXOutBuffer[3][192] __attribute__((aligned(32)));
// PAL: 0x802f7a20..0x802f7d20
extern s32 __AXOutSBuffer[192] __attribute__((aligned(32)));

volatile u32 __AXOutFrame;
volatile u32 __AXAiDmaFrame;
volatile u32 __AXOutDspReady;
u32 __AXUserFrameCallback;

// PAL: 0x802f7440..0x802f7480
extern AXPROFILE __AXLocalProfile;

volatile int __AXDSPInitFlag;
volatile int __AXDSPDoneFlag;
volatile u32 __AXDebugSteppingMode;
OSThreadQueue __AXOutThreadQueue;
u32 __AXOutputBufferMode;

// PAL: 0x802f7480..0x802f7a20
extern s16 __AXRmtOutBuffer[4][180] __attribute__((aligned(32)));
s32 __AXRmtBuffLen;
s32 __AXRmtDspPtr;
s32 __AXRmtCpuPtr;
u32 __AXExceedCallback;

extern u16 axDspInitVector;
extern u16 axDspResumeVector;
extern u16 axDspSlave[];
extern u16 axDspSlaveLength;

extern u8 __AXDramImage[64] __attribute__((aligned(32)));
extern DSPTaskInfo __AXDSPTask;

// Symbol: __AXOutNewFrame
// Function signatgure is unknown.
// PAL: 0x80126638..0x80126898
MARK_BINARY_BLOB(__AXOutNewFrame, 0x80126638, 0x80126898);
asm UNKNOWN_FUNCTION(__AXOutNewFrame) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  lis r31, __AXLocalProfile@ha;
  la r31, __AXLocalProfile@l(r31);
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  bl OSGetTime;
  addi r5, r31, 0;
  stw r3, 0(r31);
  stw r4, 4(r5);
  bl AIGetDMABytesLeft;
  srwi r3, r3, 2;
  lwz r0, __AXOutputBufferMode;
  subfic r3, r3, 0x60;
  cmplwi r0, 1;
  mulli r30, r3, 0xed5;
  bne lbl_80126690;
  li r3, 0;
  bl __AXSyncPBs;
  b lbl_80126698;
lbl_80126690:
  li r3, 0x5f50;
  bl __AXSyncPBs;
lbl_80126698:
  bl __AXPrintStudio;
  bl __AXGetCommandListAddress;
  lis r4, 0xbabe;
  mr r29, r3;
  addi r3, r4, 0x80;
  bl DSPSendMailToDSP;
lbl_801266b0:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_801266b0;
  mr r3, r29;
  bl DSPSendMailToDSP;
lbl_801266c4:
  bl DSPCheckMailToDSP;
  cmpwi r3, 0;
  bne lbl_801266c4;
  bl __AXServiceCallbackStack;
  bl OSGetTime;
  addi r29, r31, 0;
  stw r4, 0xc(r29);
  stw r3, 8(r29);
  bl __AXProcessAux;
  bl OSGetTime;
  stw r4, 0x14(r29);
  stw r3, 0x10(r29);
  bl OSGetTime;
  lwz r12, __AXUserFrameCallback;
  stw r4, 0x1c(r29);
  cmpwi r12, 0;
  stw r3, 0x18(r29);
  beq lbl_80126714;
  mtctr r12;
  bctrl;
lbl_80126714:
  bl OSGetTime;
  lwz r7, __AXRmtDspPtr;
  addi r8, r31, 0;
  addi r5, r31, 0x40;
  lwz r0, __AXRmtBuffLen;
  slwi r6, r7, 1;
  addi r7, r7, 0x12;
  add r6, r5, r6;
  stw r4, 0x24(r8);
  addi r5, r6, 0x168;
  cmpw r7, r0;
  addi r4, r6, 0x2d0;
  addi r0, r6, 0x438;
  stw r3, 0x20(r8);
  stw r6, 8(r1);
  stw r5, 0xc(r1);
  stw r4, 0x10(r1);
  stw r0, 0x14(r1);
  blt lbl_80126764;
  li r7, 0;
lbl_80126764:
  lwz r4, __AXRmtCpuPtr;
  lwz r3, __AXRmtDspPtr;
  cmpw r4, r3;
  blt lbl_80126784;
  addi r0, r3, 0x12;
  cmpw r4, r0;
  bge lbl_80126784;
  stw r7, __AXRmtCpuPtr;
lbl_80126784:
  lwz r0, __AXOutFrame;
  addi r29, r31, 0x8e0;
  stw r7, __AXRmtDspPtr;
  addi r3, r31, 0x5e0;
  mulli r0, r0, 0x180;
  addi r5, r1, 8;
  add r4, r29, r0;
  bl __AXNextFrame;
  lwz r3, __AXOutFrame;
  lwz r0, __AXOutputBufferMode;
  addi r3, r3, 1;
  cmplwi r0, 1;
  stw r3, __AXOutFrame;
  bne lbl_801267e0;
  lis r3, 0xaaab;
  lwz r4, __AXOutFrame;
  addi r0, r3, -21845;
  mulhwu r0, r0, r4;
  srwi r0, r0, 1;
  mulli r0, r0, 3;
  subf r0, r0, r4;
  stw r0, __AXOutFrame;
  b lbl_80126800;
lbl_801267e0:
  lwz r0, __AXOutFrame;
  li r4, 0x180;
  clrlwi r0, r0, 0x1f;
  stw r0, __AXOutFrame;
  lwz r0, __AXOutFrame;
  mulli r0, r0, 0x180;
  add r3, r29, r0;
  bl AIInitDMA;
lbl_80126800:
  bl OSGetTime;
  addi r29, r31, 0;
  stw r4, 0x2c(r29);
  stw r3, 0x28(r29);
  bl __AXGetNumVoices;
  stw r3, 0x30(r29);
  bl __AXGetCurrentProfile;
  cmpwi r3, 0;
  beq lbl_80126878;
  li r0, 7;
  mtctr r0;
lbl_8012682c:
  lbz r0, 0(r29);
  stb r0, 0(r3);
  lbz r0, 1(r29);
  stb r0, 1(r3);
  lbz r0, 2(r29);
  stb r0, 2(r3);
  lbz r0, 3(r29);
  stb r0, 3(r3);
  lbz r0, 4(r29);
  stb r0, 4(r3);
  lbz r0, 5(r29);
  stb r0, 5(r3);
  lbz r0, 6(r29);
  stb r0, 6(r3);
  lbz r0, 7(r29);
  addi r29, r29, 8;
  stb r0, 7(r3);
  addi r3, r3, 8;
  bdnz lbl_8012682c;
lbl_80126878:
  mr r3, r30;
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: __AXOutAiCallback
// PAL: 0x80126898..0x80126948
MARK_BINARY_BLOB(__AXOutAiCallback, 0x80126898, 0x80126948);
asm UNKNOWN_FUNCTION(__AXOutAiCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, __AXDSPDoneFlag;
  cmpwi r0, 1;
  beq lbl_80126938;
  lwz r0, __AXOutDspReady;
  cmplwi r0, 1;
  bne lbl_801268cc;
  li r0, 0;
  stw r0, __AXOutDspReady;
  bl __AXOutNewFrame;
  b lbl_801268e0;
lbl_801268cc:
  li r0, 2;
  lis r3, 0x8030;
  stw r0, __AXOutDspReady;
  addi r3, r3, -32352;
  bl DSPAssertTask;
lbl_801268e0:
  lwz r0, __AXOutputBufferMode;
  cmplwi r0, 1;
  bne lbl_80126938;
  lwz r0, __AXAiDmaFrame;
  lis r3, __AXOutBuffer@ha;
  la r3, __AXOutBuffer@l(r3);
  li r4, 0x180;
  mulli r0, r0, 0x180;
  add r3, r3, r0;
  bl AIInitDMA;
  lwz r4, __AXAiDmaFrame;
  lis r3, 0xaaab;
  addi r3, r3, -21845;
  lwz r0, __AXOutFrame;
  addi r4, r4, 1;
  mulhwu r3, r3, r4;
  srwi r3, r3, 1;
  mulli r3, r3, 3;
  subf r4, r3, r4;
  cmplw r4, r0;
  beq lbl_80126938;
  stw r4, __AXAiDmaFrame;
lbl_80126938:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __AXDSPInitCallback
// PAL: 0x80126948..0x80126954
MARK_BINARY_BLOB(__AXDSPInitCallback, 0x80126948, 0x80126954);
asm UNKNOWN_FUNCTION(__AXDSPInitCallback) {
  // clang-format off
  nofralloc;
  li r0, 1;
  stw r0, __AXDSPInitFlag;
  blr;
  // clang-format on
}

// Symbol: __AXDSPResumeCallback
// PAL: 0x80126954..0x801269a8
MARK_BINARY_BLOB(__AXDSPResumeCallback, 0x80126954, 0x801269a8);
asm UNKNOWN_FUNCTION(__AXDSPResumeCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, __AXOutDspReady;
  cmplwi r0, 2;
  bne lbl_80126990;
  li r0, 0;
  stw r0, __AXOutDspReady;
  bl __AXOutNewFrame;
  lwz r12, __AXExceedCallback;
  cmpwi r12, 0;
  beq lbl_80126998;
  mtctr r12;
  bctrl;
  b lbl_80126998;
lbl_80126990:
  li r0, 1;
  stw r0, __AXOutDspReady;
lbl_80126998:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __AXDSPDoneCallback
// PAL: 0x801269a8..0x801269b8
MARK_BINARY_BLOB(__AXDSPDoneCallback, 0x801269a8, 0x801269b8);
asm UNKNOWN_FUNCTION(__AXDSPDoneCallback) {
  // clang-format off
  nofralloc;
  li r0, 1;
  la r3, __AXOutThreadQueue;
  stw r0, __AXDSPDoneFlag;
  b OSWakeupThread;
  // clang-format on
}

// Symbol: __AXDSPRequestCallback
// PAL: 0x801269b8..0x801269bc
MARK_BINARY_BLOB(__AXDSPRequestCallback, 0x801269b8, 0x801269bc);
asm UNKNOWN_FUNCTION(__AXDSPRequestCallback) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: __AXOutInitDSP
// PAL: 0x801269bc..0x80126aac
MARK_BINARY_BLOB(__AXOutInitDSP, 0x801269bc, 0x80126aac);
asm UNKNOWN_FUNCTION(__AXOutInitDSP) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r11, 0x8030;
  lis r7, 0x8012;
  stw r0, 0x24(r1);
  lis r6, 0x8012;
  lis r5, 0x8012;
  lis r4, 0x8012;
  stw r31, 0x1c(r1);
  li r12, 0;
  addi r11, r11, -32256;
  addi r7, r7, 0x6948;
  stw r30, 0x18(r1);
  lis r30, 0x8030;
  addi r30, r30, -32352; // 80307e60
  addi r6, r6, 0x6954;
  stw r29, 0x14(r1);
  lis r29, 0x8028; // 80280e70
  addi r29, r29, -2016;
  addi r5, r5, 0x69a8;
  lhz r31, axDspSlaveLength;
  addi r4, r4, 0x69b8;
  lhz r8, axDspInitVector;
  li r10, 0x40;
  lhz r0, axDspResumeVector;
  li r9, 0xcd2;
  stw r12, 4(r30);
  la r3, __AXOutThreadQueue;
  stw r12, __AXDSPInitFlag;
  stw r29, 0xc(r30);
  stw r31, 0x10(r30);
  stw r12, 0x14(r30);
  stw r11, 0x18(r30);
  stw r10, 0x1c(r30);
  stw r9, 0x20(r30);
  sth r8, 0x24(r30);
  sth r0, 0x26(r30);
  stw r7, 0x28(r30);
  stw r6, 0x2c(r30);
  stw r5, 0x30(r30);
  stw r4, 0x34(r30);
  stw r12, __AXDSPDoneFlag;
  bl OSInitThreadQueue;
  bl DSPCheckInit;
  cmpwi r3, 0;
  bne lbl_80126a78;
  bl DSPInit;
lbl_80126a78:
  lis r3, 0x8030;
  addi r3, r3, -32352;
  bl DSPAddTask;
lbl_80126a84:
  lwz r0, __AXDSPInitFlag;
  cmpwi r0, 0;
  beq lbl_80126a84;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __AXOutInit
// PAL: 0x80126aac..0x80126ca4
MARK_BINARY_BLOB(__AXOutInit, 0x80126aac, 0x80126ca4);
asm UNKNOWN_FUNCTION(__AXOutInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r4, 0;
  stw r0, 0x24(r1);
  li r0, 0x20;
  stw r31, 0x1c(r1);
  lis r31, __AXLocalProfile@ha;
  la r31, __AXLocalProfile@l(r31);
  stw r4, __AXOutFrame;
  addi r5, r31, 0x8e0;
  stw r4, __AXAiDmaFrame;
  stw r3, __AXOutputBufferMode;
  stw r4, __AXDebugSteppingMode;
  mtctr r0;
lbl_80126ae4:
  stw r4, 0(r5);
  stw r4, 4(r5);
  stw r4, 8(r5);
  stw r4, 0xc(r5);
  stw r4, 0x10(r5);
  stw r4, 0x14(r5);
  stw r4, 0x18(r5);
  stw r4, 0x1c(r5);
  stw r4, 0x20(r5);
  addi r5, r5, 0x24;
  bdnz lbl_80126ae4;
  addi r3, r31, 0x8e0;
  li r4, 0x480;
  bl DCFlushRange;
  li r0, 0x18;
  addi r4, r31, 0x5e0;
  li r3, 0;
  mtctr r0;
lbl_80126b2c:
  stw r3, 0(r4);
  stw r3, 4(r4);
  stw r3, 8(r4);
  stw r3, 0xc(r4);
  stw r3, 0x10(r4);
  stw r3, 0x14(r4);
  stw r3, 0x18(r4);
  stw r3, 0x1c(r4);
  addi r4, r4, 0x20;
  bdnz lbl_80126b2c;
  addi r3, r31, 0x5e0;
  li r4, 0x300;
  bl DCFlushRange;
  li r0, 0x24;
  addi r4, r31, 0x40;
  li r3, 0;
  mtctr r0;
lbl_80126b70:
  stw r3, 0(r4);
  stw r3, 4(r4);
  stw r3, 8(r4);
  stw r3, 0xc(r4);
  stw r3, 0x10(r4);
  stw r3, 0x14(r4);
  stw r3, 0x18(r4);
  stw r3, 0x1c(r4);
  stw r3, 0x20(r4);
  stw r3, 0x24(r4);
  addi r4, r4, 0x28;
  bdnz lbl_80126b70;
  addi r3, r31, 0x40;
  li r4, 0x5a0;
  bl DCFlushRange;
  bl __AXOutInitDSP;
  lis r3, 0x8012;
  addi r3, r3, 0x6898;
  bl AIRegisterDMACallback;
  lwz r0, __AXOutputBufferMode;
  addi r8, r31, 0x40;
  li r4, 0x12;
  li r3, 0xb4;
  addi r7, r8, 0x168;
  addi r6, r8, 0x2d0;
  addi r5, r8, 0x438;
  cmplwi r0, 1;
  stw r8, 8(r1);
  stw r7, 0xc(r1);
  stw r6, 0x10(r1);
  stw r5, 0x14(r1);
  stw r4, __AXRmtCpuPtr;
  stw r4, __AXRmtDspPtr;
  stw r3, __AXRmtBuffLen;
  bne lbl_80126c14;
  addi r4, r31, 0x8e0;
  addi r3, r31, 0x5e0;
  addi r4, r4, 0x300;
  addi r5, r1, 8;
  bl __AXNextFrame;
  b lbl_80126c28;
lbl_80126c14:
  addi r4, r31, 0x8e0;
  addi r3, r31, 0x5e0;
  addi r4, r4, 0x180;
  addi r5, r1, 8;
  bl __AXNextFrame;
lbl_80126c28:
  lwz r0, __AXOutputBufferMode;
  li r4, 1;
  li r3, 0;
  stw r4, __AXOutDspReady;
  cmplwi r0, 1;
  stw r3, __AXUserFrameCallback;
  bne lbl_80126c6c;
  lwz r3, __AXAiDmaFrame;
  addi r0, r31, 0x8e0;
  li r4, 0x180;
  mulli r3, r3, 0x180;
  add r3, r0, r3;
  bl AIInitDMA;
  lwz r3, __AXAiDmaFrame;
  addi r0, r3, 1;
  stw r0, __AXAiDmaFrame;
  b lbl_80126c84;
lbl_80126c6c:
  lwz r3, __AXOutFrame;
  addi r0, r31, 0x8e0;
  li r4, 0x180;
  mulli r3, r3, 0x180;
  add r3, r0, r3;
  bl AIInitDMA;
lbl_80126c84:
  bl AIStartDMA;
  li r0, 0;
  stw r0, __AXExceedCallback;
  lwz r31, 0x1c(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: AXRegisterCallback
// PAL: 0x80126ca4..0x80126ce8
MARK_BINARY_BLOB(AXRegisterCallback, 0x80126ca4, 0x80126ce8);
asm UNKNOWN_FUNCTION(AXRegisterCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r31, __AXUserFrameCallback;
  bl OSDisableInterrupts;
  stw r30, __AXUserFrameCallback;
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

// Symbol: AXRmtGetSamplesLeft
// PAL: 0x80126ce8..0x80126d14
MARK_BINARY_BLOB(AXRmtGetSamplesLeft, 0x80126ce8, 0x80126d14);
asm UNKNOWN_FUNCTION(AXRmtGetSamplesLeft) {
  // clang-format off
  nofralloc;
  lwz r3, __AXRmtDspPtr;
  addic. r3, r3, -36;
  bge lbl_80126cfc;
  lwz r0, __AXRmtBuffLen;
  add r3, r3, r0;
lbl_80126cfc:
  lwz r0, __AXRmtCpuPtr;
  subf. r3, r0, r3;
  bgelr;
  lwz r0, __AXRmtBuffLen;
  add r3, r3, r0;
  blr;
  // clang-format on
}

// Symbol: AXRmtGetSamples
// PAL: 0x80126d14..0x80126dd8
MARK_BINARY_BLOB(AXRmtGetSamples, 0x80126d14, 0x80126dd8);
asm UNKNOWN_FUNCTION(AXRmtGetSamples) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r6, __AXRmtDspPtr;
  addic. r31, r6, -36;
  bge lbl_80126d38;
  lwz r0, __AXRmtBuffLen;
  add r31, r31, r0;
lbl_80126d38:
  lwz r0, __AXRmtCpuPtr;
  subf. r31, r0, r31;
  bge lbl_80126d4c;
  lwz r0, __AXRmtBuffLen;
  add r31, r31, r0;
lbl_80126d4c:
  cmpw r5, r31;
  ble lbl_80126d58;
  b lbl_80126d5c;
lbl_80126d58:
  mr r31, r5;
lbl_80126d5c:
  mulli r0, r3, 0x168;
  lis r5, __AXRmtOutBuffer@ha;
  lwz r7, __AXRmtCpuPtr;
  la r5, __AXRmtOutBuffer@l(r5);
  add r5, r5, r0;
  mtctr r31;
  cmpwi r31, 0;
  ble lbl_80126da4;
lbl_80126d7c:
  slwi r6, r7, 1;
  addi r7, r7, 1;
  lhax r0, r6, r5;
  sth r0, 0(r4);
  addi r4, r4, 2;
  lwz r0, __AXRmtBuffLen;
  cmpw r7, r0;
  blt lbl_80126da0;
  li r7, 0;
lbl_80126da0:
  bdnz lbl_80126d7c;
lbl_80126da4:
  mulli r5, r3, 0x168;
  lwz r0, __AXRmtBuffLen;
  lis r3, 0x802f;
  slwi r4, r0, 1;
  addi r3, r3, 0x7480;
  add r3, r3, r5;
  bl DCInvalidateRange;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXRmtAdvancePtr
// PAL: 0x80126dd8..0x80126e30
MARK_BINARY_BLOB(AXRmtAdvancePtr, 0x80126dd8, 0x80126e30);
asm UNKNOWN_FUNCTION(AXRmtAdvancePtr) {
  // clang-format off
  nofralloc;
  lwz r4, __AXRmtDspPtr;
  addic. r4, r4, -36;
  bge lbl_80126dec;
  lwz r0, __AXRmtBuffLen;
  add r4, r4, r0;
lbl_80126dec:
  lwz r0, __AXRmtCpuPtr;
  subf. r4, r0, r4;
  bge lbl_80126e00;
  lwz r0, __AXRmtBuffLen;
  add r4, r4, r0;
lbl_80126e00:
  cmpw r3, r4;
  ble lbl_80126e0c;
  mr r3, r4;
lbl_80126e0c:
  lwz r0, __AXRmtCpuPtr;
  lwz r4, __AXRmtBuffLen;
  add r0, r0, r3;
  cmpw r0, r4;
  stw r0, __AXRmtCpuPtr;
  bltlr;
  subf r0, r4, r0;
  stw r0, __AXRmtCpuPtr;
  blr;
  // clang-format on
}
