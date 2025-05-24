#include "eggAsyncDisplay.hpp"

#include <egg/core/eggVideo.hpp>
#include <rvl/os/osAlarm.h>
#include <rvl/os/osInterrupt.h>
#include <rvl/os/osThread.h>
#include <rvl/vi.h>
#include <rvl/gx/gxAttr.h>
#include <rvl/gx/gxDraw.h>
#include <rvl/gx/gxFrameBuf.h>
#include <rvl/gx/gxGeometry.h>
#include <rvl/gx/gxLight.h>
#include <rvl/gx/gxMisc.h>
#include <rvl/gx/gxPixel.h>
#include <rvl/gx/gxTexture.h>
#include <rvl/gx/gxTev.h>
#include <rvl/gx/gxTransform.h>
#include <rvl/mtx/mtx.h>

// extern function references.
// PAL: 0x801b9138
extern "C" UNKNOWN_FUNCTION(VISetPostRetraceCallback);
// PAL: 0x80219e68
extern "C" UNKNOWN_FUNCTION(__ct__Q23EGG7DisplayFUc);
// PAL: 0x80219fb4
extern "C" UNKNOWN_FUNCTION(endRender__Q23EGG7DisplayFv);
// PAL: 0x8021a06c
extern "C" UNKNOWN_FUNCTION(calcFrequency__Q23EGG7DisplayFv);
// PAL: 0x8023040c
extern "C" UNKNOWN_FUNCTION(loadPosMtx__Q23EGG9Matrix34fFUl);
// PAL: 0x80243e70
extern "C" UNKNOWN_FUNCTION(getTickPerVRetrace__Q23EGG5VideoFUl);
// PAL: 0x80243ed0
extern "C" UNKNOWN_FUNCTION(getTickPerVRetrace__Q23EGG5VideoFv);
// PAL: 0x802442e8
extern "C" UNKNOWN_FUNCTION(setNextFrameBuffer__Q23EGG10XfbManagerFv);
// PAL: 0x80244350
extern "C" UNKNOWN_FUNCTION(postVRetrace__Q23EGG10XfbManagerFv);

extern "C" void copyEFBtoXFB__Q23EGG7DisplayFv();

// Symbol: PostRetraceCallback
// PAL: 0x8020fcd4..0x8020fcdc
MARK_BINARY_BLOB(PostRetraceCallback, 0x8020fcd4, 0x8020fcdc);
asm UNKNOWN_FUNCTION(PostRetraceCallback) {
  // clang-format off
  nofralloc;
  lwz r3, -0x5e70(r13);
  b postVRetrace__Q23EGG12AsyncDisplayFv;
  // clang-format on
}

// Symbol: DrawDoneCallback
// PAL: 0x8020fcdc..0x8020fd10
MARK_BINARY_BLOB(DrawDoneCallback, 0x8020fcdc, 0x8020fd10);
asm UNKNOWN_FUNCTION(DrawDoneCallback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  bl setNextFrameBuffer__Q23EGG10XfbManagerFv;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AlarmHandler_0
// PAL: 0x8020fd10..0x8020fd18
MARK_BINARY_BLOB(AlarmHandler_0, 0x8020fd10, 0x8020fd18);
asm UNKNOWN_FUNCTION(AlarmHandler_0) {
  // clang-format off
  nofralloc;
  lwz r3, -0x5e70(r13);
  b alarmHandler__Q23EGG12AsyncDisplayFv;
  // clang-format on
}

// Symbol: __ct__Q23EGG12AsyncDisplayFUc
// PAL: 0x8020fd18..0x8020fd8c
MARK_BINARY_BLOB(__ct__Q23EGG12AsyncDisplayFUc, 0x8020fd18, 0x8020fd8c);
asm UNKNOWN_FUNCTION(__ct__Q23EGG12AsyncDisplayFUc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q23EGG7DisplayFUc;
  lfs f0, -0x6580(r2);
  lis r3, 0x802a;
  li r4, 0;
  li r0, 1;
  addi r3, r3, 0x26e0;
  stw r3, 4(r31);
  addi r3, r31, 0x58;
  stw r4, 0x60(r31);
  stfs f0, 0x64(r31);
  stw r4, 0x68(r31);
  stw r4, 0x6c(r31);
  stb r0, 0x70(r31);
  stw r31, -0x5e70(r13);
  bl OSInitThreadQueue;
  lis r3, 0x8021;
  addi r3, r3, -812;
  bl VISetPostRetraceCallback;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: startSyncNTSC__Q23EGG12AsyncDisplayFUc
// PAL: 0x8020fd8c..0x8020fe24
MARK_BINARY_BLOB(startSyncNTSC__Q23EGG12AsyncDisplayFUc, 0x8020fd8c,
                 0x8020fe24);
asm UNKNOWN_FUNCTION(startSyncNTSC__Q23EGG12AsyncDisplayFUc) {
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
  lwz r0, 0x60(r29);
  mr r31, r3;
  cmpwi r0, 0;
  bne lbl_8020fe00;
  li r0, 1;
  stb r30, 0x70(r29);
  li r3, 0;
  stw r0, 0x60(r29);
  bl getTickPerVRetrace__Q23EGG5VideoFUl;
  stw r3, 0x74(r29);
  bl getTickPerVRetrace__Q23EGG5VideoFv;
  stw r3, 0x78(r29);
  lis r9, 0x8021;
  lwz r8, 0x74(r29);
  addi r3, r29, 0x28;
  addi r9, r9, -752;
  li r6, 0;
  li r5, 0;
  li r7, 0;
  bl OSSetPeriodicAlarm;
lbl_8020fe00:
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: beginFrame__Q23EGG12AsyncDisplayFv
// PAL: 0x8020fe24..0x8020ff98
MARK_BINARY_BLOB(beginFrame__Q23EGG12AsyncDisplayFv, 0x8020fe24, 0x8020ff98);
asm UNKNOWN_FUNCTION(beginFrame__Q23EGG12AsyncDisplayFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  lwz r4, 0x68(r3);
  lwz r0, 0x6c(r3);
  subf r30, r4, r0;
lbl_8020fe48:
  addi r3, r31, 0x58;
  bl OSSleepThread;
  lbz r0, 8(r31);
  addi r30, r30, 1;
  cmplw r30, r0;
  blt lbl_8020fe48;
  lwz r0, 0x6c(r31);
  mr r3, r31;
  stw r0, 0x68(r31);
  bl calcFrequency__Q23EGG7DisplayFv;
  lwz r0, 0x60(r31);
  cmpwi r0, 1;
  bne lbl_8020ff08;
  lwz r3, 0x74(r31);
  lbz r0, 0x70(r31);
  lwz r30, 0x78(r31);
  mullw r0, r3, r0;
  b lbl_8020fe94;
lbl_8020fe90:
  add r30, r30, r0;
lbl_8020fe94:
  cmpw r30, r0;
  blt lbl_8020fe90;
  bl OSGetTick;
  lwz r0, 0x80(r31);
  lwz r4, 0x74(r31);
  subf r3, r0, r3;
  stw r3, 0x7c(r31);
  subf r0, r4, r30;
  subf. r3, r3, r0;
  bge lbl_8020fec0;
  add r3, r3, r4;
lbl_8020fec0:
  lis r0, 0x4330;
  xoris r3, r3, 0x8000;
  stw r3, 0xc(r1);
  lfd f1, -0x6578(r2);
  stw r0, 8(r1);
  lfd f2, -0x6570(r2);
  lfd f0, 8(r1);
  stw r4, 0x14(r1);
  fsubs f3, f0, f1;
  lfs f0, -0x6580(r2);
  stw r0, 0x10(r1);
  lfd f1, 0x10(r1);
  fsubs f1, f1, f2;
  fdivs f1, f3, f1;
  stfs f1, 0x64(r31);
  fcmpo cr0, f1, f0;
  ble lbl_8020ff08;
  stfs f0, 0x64(r31);
lbl_8020ff08:
  lbz r0, 9(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8020ff74;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lbz r0, 4(r3);
  mr r30, r3;
  clrlwi r0, r0, 0x1f;
  cntlzw r0, r0;
  srwi r3, r0, 5;
  bl VISetBlack;
  lbz r0, 4(r30);
  clrlwi. r0, r0, 0x1f;
  bne lbl_8020ff5c;
  lbz r0, 4(r30);
  ori r0, r0, 1;
  stb r0, 4(r30);
  b lbl_8020ff68;
lbl_8020ff5c:
  lbz r0, 4(r30);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 4(r30);
lbl_8020ff68:
  lbz r0, 9(r31);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 9(r31);
lbl_8020ff74:
  lwz r3, 0x10(r31);
  addi r0, r3, 1;
  stw r0, 0x10(r31);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

namespace EGG {

void AsyncDisplay::beginRender() { GXDraw(); }

} // namespace EGG

// Symbol: endRender__Q23EGG12AsyncDisplayFv
// PAL: 0x8020ff9c..0x80210024
MARK_BINARY_BLOB(endRender__Q23EGG12AsyncDisplayFv, 0x8020ff9c, 0x80210024);
asm UNKNOWN_FUNCTION(endRender__Q23EGG12AsyncDisplayFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  lwz r5, 4(r3);
  li r4, 0;
  lwz r0, 0xc(r3);
  cmplw r5, r0;
  beq lbl_8020ffe8;
  lwz r0, 0(r3);
  cmplw r5, r0;
  beq lbl_8020ffe8;
  li r4, 1;
lbl_8020ffe8:
  cmpwi r4, 0;
  beq lbl_80210008;
  mr r3, r31;
  bl copyEFBtoXFB__Q23EGG7DisplayFv;
  lis r3, 0x8021;
  addi r3, r3, -804;
  bl GXSetDrawDoneCallback;
  b lbl_80210010;
lbl_80210008:
  mr r3, r31;
  bl clearEFB__Q23EGG12AsyncDisplayFv;
lbl_80210010:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: postVRetrace__Q23EGG12AsyncDisplayFv
// PAL: 0x80210024..0x8021008c
MARK_BINARY_BLOB(postVRetrace__Q23EGG12AsyncDisplayFv, 0x80210024, 0x8021008c);
asm UNKNOWN_FUNCTION(postVRetrace__Q23EGG12AsyncDisplayFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  bl postVRetrace__Q23EGG10XfbManagerFv;
  bl OSGetTick;
  lwz r0, 0x60(r31);
  stw r3, 0x80(r31);
  cmpwi r0, 0;
  bne lbl_80210078;
  lwz r4, 0x6c(r31);
  addi r3, r31, 0x58;
  addi r0, r4, 1;
  stw r0, 0x6c(r31);
  bl OSWakeupThread;
lbl_80210078:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: alarmHandler__Q23EGG12AsyncDisplayFv
// PAL: 0x8021008c..0x802100a0
MARK_BINARY_BLOB(alarmHandler__Q23EGG12AsyncDisplayFv, 0x8021008c, 0x802100a0);
asm UNKNOWN_FUNCTION(alarmHandler__Q23EGG12AsyncDisplayFv) {
  // clang-format off
  nofralloc;
  lwz r4, 0x6c(r3);
  addi r0, r4, 1;
  stw r0, 0x6c(r3);
  addi r3, r3, 0x58;
  b OSWakeupThread;
  // clang-format on
}

// Symbol: clearEFB__Q23EGG12AsyncDisplayFv
// PAL: 0x802100a0..0x80210124
MARK_BINARY_BLOB(clearEFB__Q23EGG12AsyncDisplayFv, 0x802100a0, 0x80210124);
asm UNKNOWN_FUNCTION(clearEFB__Q23EGG12AsyncDisplayFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r4, 0(r3);
  mr r3, r31;
  lbz r0, 0x14(r31);
  addi r10, r1, 8;
  stb r0, 8(r1);
  li r6, 0;
  li r7, 0;
  lbz r0, 0x15(r31);
  stb r0, 9(r1);
  lbz r0, 0x16(r31);
  stb r0, 0xa(r1);
  lbz r0, 0x17(r31);
  stb r0, 0xb(r1);
  lhz r5, 6(r4);
  lhz r4, 4(r4);
  mr r9, r5;
  mr r8, r4;
  bl clearEFB__Q23EGG12AsyncDisplayFUsUsUsUsUsUsQ34nw4r2ut5Color;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

namespace EGG {

u32 AsyncDisplay::getTickPerFrame() {
  if (WORD_0x60 == 1) {
    return Video::getTickPerVRetrace(VI_NTSC);
  }

  return Video::getTickPerVRetrace();
}

} // namespace EGG

// Symbol: clearEFB__Q23EGG12AsyncDisplayFUsUsUsUsUsUsQ34nw4r2ut5Color
// PAL: 0x8021013c..0x802104ec
MARK_BINARY_BLOB(clearEFB__Q23EGG12AsyncDisplayFUsUsUsUsUsUsQ34nw4r2ut5Color,
                 0x8021013c, 0x802104ec);
asm UNKNOWN_FUNCTION(
    clearEFB__Q23EGG12AsyncDisplayFUsUsUsUsUsUsQ34nw4r2ut5Color) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  addi r11, r1, 0x80;
  bl _savegpr_24;
  lis r0, 0x4330;
  lis r31, 0x8038;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  mr r28, r8;
  mr r29, r9;
  mr r30, r10;
  stw r0, 0x50(r1);
  lis r5, 0x802a;
  mr r24, r4;
  addi r3, r31, 0x32e8;
  addi r4, r5, 0x26a0;
  stw r0, 0x58(r1);
  li r5, 4;
  li r6, 4;
  li r7, 0x16;
  li r8, 1;
  li r9, 1;
  li r10, 0;
  bl GXInitTexObj;
  lfs f1, -0x6568(r2);
  addi r3, r31, 0x32e8;
  li r4, 0;
  li r5, 0;
  fmr f2, f1;
  li r6, 0;
  fmr f3, f1;
  li r7, 0;
  li r8, 0;
  bl GXInitTexObjLOD;
  stw r25, 0x54(r1);
  addi r3, r1, 0x10;
  lfs f1, -0x6568(r2);
  stw r24, 0x5c(r1);
  lfd f4, -0x6570(r2);
  fmr f3, f1;
  lfd f2, 0x50(r1);
  fmr f5, f1;
  lfd f0, 0x58(r1);
  fsubs f2, f2, f4;
  lfs f6, -0x6580(r2);
  fsubs f4, f0, f4;
  bl C_MTXOrtho;
  addi r3, r1, 0x10;
  li r4, 1;
  bl GXSetProjection;
  stw r24, 0x54(r1);
  lfs f1, -0x6568(r2);
  stw r25, 0x5c(r1);
  lfd f4, -0x6570(r2);
  fmr f2, f1;
  lfd f3, 0x50(r1);
  fmr f5, f1;
  lfd f0, 0x58(r1);
  fsubs f3, f3, f4;
  lfs f6, -0x6580(r2);
  fsubs f4, f0, f4;
  bl GXSetViewport;
  mr r5, r24;
  mr r6, r25;
  li r3, 0;
  li r4, 0;
  bl GXSetScissor;
  lis r3, 0x8038;
  li r4, 0;
  addi r3, r3, 0x4370;
  bl loadPosMtx__Q23EGG9Matrix34fFUl;
  li r3, 0;
  bl GXSetCurrentMtx;
  bl GXClearVtxDesc;
  li r3, 9;
  li r4, 1;
  bl GXSetVtxDesc;
  li r3, 0xd;
  li r4, 1;
  bl GXSetVtxDesc;
  li r3, 0;
  li r4, 9;
  li r5, 0;
  li r6, 2;
  li r7, 0;
  bl GXSetVtxAttrFmt;
  li r3, 0;
  li r4, 0xd;
  li r5, 1;
  li r6, 0;
  li r7, 0;
  bl GXSetVtxAttrFmt;
  li r3, 0;
  bl GXSetNumChans;
  li r3, 4;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  li r9, 2;
  bl GXSetChanCtrl;
  li r3, 5;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  li r9, 2;
  bl GXSetChanCtrl;
  li r3, 1;
  bl GXSetNumTexGens;
  li r3, 0;
  li r4, 1;
  li r5, 4;
  li r6, 0x3c;
  li r7, 0;
  li r8, 0x7d;
  bl GXSetTexCoordGen2;
  addi r3, r31, 0x32e8;
  li r4, 0;
  bl GXLoadTexObj;
  li r3, 1;
  bl GXSetNumTevStages;
  lbz r7, 0(r30);
  addi r4, r1, 8;
  lbz r6, 1(r30);
  li r3, 1;
  lbz r5, 2(r30);
  lbz r0, 3(r30);
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  bl GXSetTevColor;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  li r6, 0xff;
  bl GXSetTevOrder;
  li r3, 0;
  li r4, 0xf;
  li r5, 0xf;
  li r6, 0xf;
  li r7, 2;
  bl GXSetTevColorIn;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  li r8, 0;
  bl GXSetTevColorOp;
  li r3, 0;
  li r4, 7;
  li r5, 7;
  li r6, 7;
  li r7, 1;
  bl GXSetTevAlphaIn;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  li r8, 0;
  bl GXSetTevAlphaOp;
  li r3, 7;
  li r4, 0;
  li r5, 1;
  li r6, 7;
  li r7, 0;
  bl GXSetAlphaCompare;
  li r3, 2;
  li r4, 0x16;
  li r5, 0;
  bl GXSetZTexture;
  li r3, 0;
  bl GXSetZCompLoc;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  li r6, 5;
  bl GXSetBlendMode;
  li r3, 1;
  bl GXSetAlphaUpdate;
  lbz r4, 3(r30);
  li r3, 1;
  bl GXSetDstAlpha;
  li r3, 1;
  li r4, 7;
  li r5, 1;
  bl GXSetZMode;
  li r3, 2;
  bl GXSetCullMode;
  li r3, 0x80;
  li r4, 0;
  li r5, 4;
  bl GXBegin;
  lis r8, 0xcc01;
  li r7, 0;
  sth r26, -0x8000(r8);
  add r3, r26, r28;
  li r6, 1;
  add r0, r27, r29;
  sth r27, -0x8000(r8);
  li r4, 0x16;
  li r5, 0;
  stb r7, -0x8000(r8);
  stb r7, -0x8000(r8);
  sth r3, -0x8000(r8);
  sth r27, -0x8000(r8);
  stb r6, -0x8000(r8);
  stb r7, -0x8000(r8);
  sth r3, -0x8000(r8);
  li r3, 0;
  sth r0, -0x8000(r8);
  stb r6, -0x8000(r8);
  stb r6, -0x8000(r8);
  sth r26, -0x8000(r8);
  sth r0, -0x8000(r8);
  stb r7, -0x8000(r8);
  stb r6, -0x8000(r8);
  bl GXSetZTexture;
  li r3, 1;
  bl GXSetZCompLoc;
  lbz r4, 3(r30);
  li r3, 0;
  bl GXSetDstAlpha;
  addi r11, r1, 0x80;
  bl _restgpr_24;
  lwz r0, 0x84(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}
