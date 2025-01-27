#include "eggProcessMeter.hpp"

#include <rvl/os/osInterrupt.h>
#include <rvl/gx.h>
#include <rvl/gx/gxFifo.h>
#include <rvl/gx/gxGeometry.h>
#include <rvl/mtx/mtx.h>

// Extern function references.
// PAL: 0x800aef60
extern "C" void List_Init__Q24nw4r2utFPQ34nw4r2ut4ListUs();
// PAL: 0x800aef80
extern "C" void List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv();
// PAL: 0x800af180
extern "C" void List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv();
// PAL: 0x8016d39c
extern "C" void GXGetCurrentGXThread();
// PAL: 0x8016dc34
extern "C" void GXClearVtxDesc();
// PAL: 0x8016dc68
extern "C" void GXSetVtxAttrFmt();
// PAL: 0x8016e5a4
extern "C" void GXSetNumTexGens();
// PAL: 0x8016ec88
extern "C" void GXSetDrawSyncCallback();
// PAL: 0x8016f314
extern "C" void GXSetLineWidth();
// PAL: 0x8016f3b8
extern "C" void GXSetCullMode();
// PAL: 0x80170474
extern "C" void GXSetChanMatColor();
// PAL: 0x8017054c
extern "C" void GXSetNumChans();
// PAL: 0x80170570
extern "C" void GXSetChanCtrl();
// PAL: 0x80171b38
extern "C" void GXSetNumIndStages();
// PAL: 0x80171c4c
extern "C" void GXSetTevOp();
// PAL: 0x8017214c
extern "C" void GXSetTevOrder();
// PAL: 0x801722a8
extern "C" void GXSetNumTevStages();
// PAL: 0x8017277c
extern "C" void GXSetBlendMode();
// PAL: 0x801727cc
extern "C" void GXSetColorUpdate();
// PAL: 0x80172824
extern "C" void GXSetZMode();
// PAL: 0x8017301c
extern "C" void GXSetProjection();
// PAL: 0x8017310c
extern "C" void GXLoadPosMtxImm();
// PAL: 0x80173214
extern "C" void GXSetCurrentMtx();
// PAL: 0x801733b4
extern "C" void GXSetViewport();
// PAL: 0x80173430
extern "C" void GXSetScissor();
// PAL: 0x801aab98
extern "C" void OSSetThreadPriority();
// PAL: 0x80238f54
extern "C" void
append__Q23EGG12ProcessMeterFPQ33EGG12ProcessMeter12CpuGpMonitor();
// PAL: 0x80239338
extern "C" void ProcessMeter_draw2();
// PAL: 0x802432e0
extern "C" void __ct__Q23EGG6ThreadFUliiPQ23EGG4Heap();
// PAL: 0x8024341c
extern "C" void __dt__Q23EGG6ThreadFv();

namespace EGG {

// dead-stripped, inlined
ProcessMeter::ProcessBar::ProcessBar(nw4r::ut::Color color, f32 posY,
                                     f32 dimY) {
  mPosX = 0.0f;
  mDimX = 0.0f;
  mStartTick = 0;
  mEndTick = 0;
  mColor = color;
  mPosY = posY;
  mDimY = dimY;
  mFlags = 0;
}

// dead-stripped, inlined
void ProcessMeter::ProcessBar::update(f32 posX) {
  mPosX = posX;

  u32 duration;
  if (mStartTick != 0 && mEndTick != 0) {
    duration = mEndTick - mStartTick;
  } else {
    duration = 0;
  }
  mDimX = static_cast<f32>(duration) / static_cast<f32>(OS_TIMER_CLOCK / 1000);
}

// dead-stripped, inlined
void ProcessMeter::ProcessBar::update(u32 startTickInFrame) {
  f32 posX = static_cast<f32>(startTickInFrame) /
             static_cast<f32>(OS_TIMER_CLOCK / 1000);
  update(posX);
}

// dead-stripped, inlined
ProcessMeter::CpuMonitor::CpuMonitor(nw4r::ut::Color color, f32 posY)
    : mCpuBar(color, posY, 1.0) {}

void ProcessMeter::CpuMonitor::measureBegin() {
  mCpuBar.mStartTick = OSGetTick();
  mCpuBar.mEndTick = 0;
}

void ProcessMeter::CpuMonitor::measureEnd() {
  if (mCpuBar.mStartTick != 0) {
    mCpuBar.mEndTick = OSGetTick();
  }
}

void ProcessMeter::CpuMonitor::show() { mCpuBar.mFlags &= ~ProcessBar::HIDDEN; }

void ProcessMeter::CpuMonitor::hide() { mCpuBar.mFlags |= ProcessBar::HIDDEN; }

void ProcessMeter::CpuGpMonitor::measureBegin() {
  mCpuBar.mStartTick = OSGetTick();
  mCpuBar.mEndTick = 0;

  mNextFuture = NEXT_FUTURE_BEGIN;

  mProcessMeter->setDrawSync(&mBeginFuture);
}

void ProcessMeter::CpuGpMonitor::measureEnd() {
  if (mCpuBar.mStartTick != 0) {
    mCpuBar.mEndTick = OSGetTick();
  }

  mProcessMeter->setDrawSync(&mEndFuture);
}

void ProcessMeter::CpuGpMonitor::show() {
  mCpuBar.mFlags &= ~ProcessBar::HIDDEN;
  mGpBar.mFlags &= ~ProcessBar::HIDDEN;
}

void ProcessMeter::CpuGpMonitor::hide() {
  mCpuBar.mFlags |= ProcessBar::HIDDEN;
  mGpBar.mFlags |= ProcessBar::HIDDEN;
}

} // namespace EGG

// Symbol: __ct__Q23EGG12ProcessMeterFb
// PAL: 0x8023883c..0x80238a94
MARK_BINARY_BLOB(__ct__Q23EGG12ProcessMeterFb, 0x8023883c, 0x80238a94);
asm UNKNOWN_FUNCTION(__ct__Q23EGG12ProcessMeterFb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_18;
  mr r31, r4;
  mr r30, r3;
  li r4, 0x1000;
  li r5, 4;
  li r6, 0;
  li r7, 0;
  bl __ct__Q23EGG6ThreadFUliiPQ23EGG4Heap;
  lis r5, 0x802a;
  lfs f2, -0x5ffc(r2);
  addi r5, r5, 0x3ce0;
  lfs f1, -0x5ff8(r2);
  lfs f0, -0x6000(r2);
  lis r3, 0xcccd;
  addi r0, r3, -13057;
  addi r4, r5, 0x18;
  stw r4, 0x48(r30);
  addi r3, r30, 0x60;
  li r4, 0x20;
  stw r5, 0(r30);
  stw r0, 0x4c(r30);
  stfs f2, 0x50(r30);
  stfs f2, 0x54(r30);
  stfs f1, 0x58(r30);
  stfs f0, 0x5c(r30);
  bl List_Init__Q24nw4r2utFPQ34nw4r2ut4ListUs;
  lis r4, 0xff50;
  lis r6, 0x50ff;
  addi r0, r4, 0x50ff;
  stw r0, 0x10(r1);
  lis r3, 0x5051;
  addi r6, r6, 0x50ff;
  lfs f2, -0x6018(r2);
  addi r3, r3, -1;
  li r0, 0;
  stw r6, 8(r1);
  lfs f1, -0x6000(r2);
  addi r5, r30, 0xc8;
  stw r3, 0xc(r1);
  li r6, 0x32c8;
  lis r22, 0x802a;
  lbz r23, 0x10(r1);
  stw r6, 0x14(r1);
  addi r22, r22, 0x3d60;
  lis r11, 0x802a;
  lbz r24, 0x11(r1);
  lbz r18, 0x14(r1);
  li r6, 0x14;
  lbz r19, 0x15(r1);
  addi r11, r11, 0x3d48;
  stw r22, 0xc8(r30);
  addi r4, r30, 0x9c;
  lbz r20, 0x16(r1);
  mr r3, r30;
  lbz r21, 0x17(r1);
  lbz r25, 0x12(r1);
  lbz r26, 0x13(r1);
  lbz r27, 8(r1);
  lbz r28, 9(r1);
  lbz r29, 0xa(r1);
  lbz r12, 0xb(r1);
  lbz r10, 0xc(r1);
  lbz r9, 0xd(r1);
  lbz r8, 0xe(r1);
  lbz r7, 0xf(r1);
  lfs f0, -0x5ff4(r2);
  stfs f2, 0x74(r30);
  stfs f2, 0x78(r30);
  stw r0, 0x7c(r30);
  stw r0, 0x80(r30);
  stb r18, 0x84(r30);
  stb r19, 0x85(r30);
  stb r20, 0x86(r30);
  stb r21, 0x87(r30);
  stfs f2, 0x88(r30);
  stfs f1, 0x8c(r30);
  stb r0, 0x90(r30);
  stw r22, 0x9c(r30);
  stfs f2, 0xa0(r30);
  stfs f2, 0xa4(r30);
  stw r0, 0xa8(r30);
  stw r0, 0xac(r30);
  stb r23, 0xb0(r30);
  stb r24, 0xb1(r30);
  stb r25, 0xb2(r30);
  stb r26, 0xb3(r30);
  stfs f2, 0xb4(r30);
  stfs f1, 0xb8(r30);
  stb r0, 0xbc(r30);
  stfs f2, 0xcc(r30);
  stfs f2, 0xd0(r30);
  stw r0, 0xd4(r30);
  stw r0, 0xd8(r30);
  stb r27, 0xdc(r30);
  stb r28, 0xdd(r30);
  stb r29, 0xde(r30);
  stb r12, 0xdf(r30);
  stfs f1, 0xe0(r30);
  stfs f1, 0xe4(r30);
  stb r0, 0xe8(r30);
  stw r11, 0xc8(r30);
  stfs f2, 0xf4(r30);
  stfs f2, 0xf8(r30);
  stw r0, 0xfc(r30);
  stw r0, 0x100(r30);
  stb r10, 0x104(r30);
  stb r9, 0x105(r30);
  stb r8, 0x106(r30);
  stb r7, 0x107(r30);
  stfs f0, 0x108(r30);
  stfs f1, 0x10c(r30);
  stb r0, 0x110(r30);
  sth r0, 0x11c(r30);
  stw r5, 0x130(r30);
  stw r5, 0x140(r30);
  stw r6, 0x144(r30);
  stb r0, 0x152(r30);
  stw r0, 0x6c(r30);
  stw r0, 0x70(r30);
  bl append__Q23EGG12ProcessMeterFPQ33EGG12ProcessMeter10CpuMonitor;
  mr r3, r30;
  addi r4, r30, 0xc8;
  bl append__Q23EGG12ProcessMeterFPQ33EGG12ProcessMeter12CpuGpMonitor;
  lbz r0, 0x152(r30);
  cmpwi r31, 0;
  ori r0, r0, 1;
  stb r0, 0x152(r30);
  beq lbl_80238a58;
  lis r3, 0x8023;
  addi r3, r3, 0x4a04;
  bl GXSetDrawSyncCallback;
lbl_80238a58:
  bl GXGetCurrentGXThread;
  mr r4, r3;
  lwz r3, 8(r30);
  lwz r4, 0x2d0(r4);
  addi r4, r4, -1;
  bl OSSetThreadPriority;
  lwz r3, 8(r30);
  bl OSResumeThread;
  addi r11, r1, 0x50;
  mr r3, r30;
  bl _restgpr_18;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: measureBeginFrame__Q23EGG12ProcessMeterFv
// PAL: 0x80238a94..0x80238d10
MARK_BINARY_BLOB(measureBeginFrame__Q23EGG12ProcessMeterFv, 0x80238a94,
                 0x80238d10);
asm UNKNOWN_FUNCTION(measureBeginFrame__Q23EGG12ProcessMeterFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stfd f31, 0x70(r1);
  psq_st f31, 120(r1), 0, 0;
  stfd f30, 0x60(r1);
  psq_st f30, 104(r1), 0, 0;
  stfd f29, 0x50(r1);
  psq_st f29, 88(r1), 0, 0;
  stfd f28, 0x40(r1);
  psq_st f28, 72(r1), 0, 0;
  stfd f27, 0x30(r1);
  psq_st f27, 56(r1), 0, 0;
  lis r4, 0x4330;
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  mr r30, r3;
  stw r29, 0x24(r1);
  stw r28, 0x20(r1);
  lwz r0, 0x7c(r3);
  stw r4, 8(r1);
  cmpwi r0, 0;
  stw r4, 0x10(r1);
  beq lbl_80238afc;
  bl OSGetTick;
  stw r3, 0x80(r30);
lbl_80238afc:
  lfs f0, -0x6018(r2);
  stfs f0, 0x74(r30);
  fcmpo cr0, f0, f0;
  lwz r31, 0x7c(r30);
  bge lbl_80238b14;
  stfs f0, 0x74(r30);
lbl_80238b14:
  lwz r0, 0x7c(r30);
  cmpwi r0, 0;
  beq lbl_80238b34;
  lwz r3, 0x80(r30);
  cmpwi r3, 0;
  beq lbl_80238b34;
  subf r5, r0, r3;
  b lbl_80238b38;
lbl_80238b34:
  li r5, 0;
lbl_80238b38:
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r3, r3, 0x4dd3;
  stw r5, 0xc(r1);
  srwi r0, r0, 2;
  lfd f3, -0x6008(r2);
  mulhwu r0, r3, r0;
  lfd f1, 8(r1);
  lfs f0, -0x6018(r2);
  fsubs f2, f1, f3;
  srwi r0, r0, 6;
  stw r0, 0x14(r1);
  lfd f1, 0x10(r1);
  fsubs f1, f1, f3;
  fdivs f1, f2, f1;
  stfs f1, 0x78(r30);
  fcmpo cr0, f1, f0;
  mfcr r0;
  rlwinm. r0, r0, 2, 0x1f, 0x1f;
  cmpwi r0, 0;
  lfs f31, -0x6018(r2);
  lis r3, 0x1062;
  lfd f27, -0x6010(r2);
  addi r28, r3, 0x4dd3;
  fmr f29, f31;
  lfd f28, -0x6008(r2);
  fmr f30, f31;
  li r4, 0;
  lis r29, 0x8000;
  b lbl_80238c84;
lbl_80238bb4:
  lwz r0, 0xf8(r29);
  lwz r5, 8(r3);
  srwi r0, r0, 2;
  mulhwu r0, r28, r0;
  subf r5, r31, r5;
  xoris r5, r5, 0x8000;
  stw r5, 0xc(r1);
  lfd f0, 8(r1);
  srwi r0, r0, 6;
  stw r0, 0x14(r1);
  fsubs f1, f0, f27;
  lfd f0, 0x10(r1);
  fsubs f0, f0, f28;
  fdivs f0, f1, f0;
  stfs f0, 0(r3);
  fcmpo cr0, f0, f29;
  bge lbl_80238bfc;
  stfs f29, 0(r3);
lbl_80238bfc:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80238c1c;
  lwz r5, 0xc(r3);
  cmpwi r5, 0;
  beq lbl_80238c1c;
  subf r5, r0, r5;
  b lbl_80238c20;
lbl_80238c1c:
  li r5, 0;
lbl_80238c20:
  lwz r0, 0xf8(r29);
  stw r5, 0xc(r1);
  srwi r0, r0, 2;
  mulhwu r0, r28, r0;
  lfd f0, 8(r1);
  fsubs f1, f0, f28;
  srwi r0, r0, 6;
  stw r0, 0x14(r1);
  lfd f0, 0x10(r1);
  fsubs f0, f0, f28;
  fdivs f0, f1, f0;
  stfs f0, 4(r3);
  fcmpo cr0, f0, f30;
  ble lbl_80238c68;
  lfs f1, 0x14(r3);
  lfs f0, 0x18(r3);
  fadds f0, f1, f0;
  b lbl_80238c6c;
lbl_80238c68:
  fmr f0, f30;
lbl_80238c6c:
  lbz r0, 0x1c(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_80238c84;
  fcmpo cr0, f0, f31;
  ble lbl_80238c84;
  fmr f31, f0;
lbl_80238c84:
  addi r3, r30, 0x60;
  bl List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv;
  cmpwi r3, 0;
  mr r4, r3;
  bne lbl_80238bb4;
  lfs f0, -0x6000(r2);
  fadds f0, f0, f31;
  stfs f0, 0x148(r30);
  bl OSGetTick;
  stw r3, 0x7c(r30);
  li r0, 0;
  addi r3, r30, 0x9c;
  stw r0, 0x80(r30);
  lwz r12, 0x9c(r30);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  psq_l f31, 120(r1), 0, 0;
  lfd f31, 0x70(r1);
  psq_l f30, 104(r1), 0, 0;
  lfd f30, 0x60(r1);
  psq_l f29, 88(r1), 0, 0;
  lfd f29, 0x50(r1);
  psq_l f28, 72(r1), 0, 0;
  lfd f28, 0x40(r1);
  psq_l f27, 56(r1), 0, 0;
  lfd f27, 0x30(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r0, 0x84(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

namespace EGG {

// void ProcessMeter::measureBeginFrame() {
//   if (mBgBar.mStartTick != 0) {
//     mBgBar.mEndTick = OSGetTick();
//   }
//   mBgBar.update(0.0f);

//   ProcessBar* bar = nullptr;
//   f32 maxY = 0.0f;
//   while ((bar = (ProcessBar*)List_GetNext(&mBarList, bar))) {
//     bar->update(bar->mStartTick - mBgBar.mStartTick);

//     f32 barMaxY;
//     if (bar->mDimX > 0.0f) {
//       barMaxY = bar->mPosY + bar->mDimY;
//     } else {
//       barMaxY = 0.0f;
//     }
//     if (!(bar->mFlags & ProcessBar::HIDDEN) && barMaxY > maxY) {
//       maxY = barMaxY;
//     }
//   }

//   mBgBarDimY = 1.0f + maxY;

//   mBgBar.mStartTick = OSGetTick();
//   mBgBar.mEndTick = 0;

//   mCpuMonitor.measureBegin();
// }

void ProcessMeter::measureEndFrame() { mCpuMonitor.measureEnd(); }

void ProcessMeter::measureBeginRender() { mCpuGpMonitor.measureBegin(); }

void ProcessMeter::measureEndRender() { mCpuGpMonitor.measureEnd(); }

void ProcessMeter::callbackDrawSync(u16 token) {
  if (mHeadGpFuture->mToken == token) {
    u32 tick = OSGetTick();
    OSSendMessage(getMesgQueue(), reinterpret_cast<void*>(tick),
                  OS_MESSAGE_NOBLOCK);
  }
}

void* ProcessMeter::run() {
  while (true) {
    OSMessage message;
    OSReceiveMessage(getMesgQueue(), &message, OS_MESSAGE_BLOCK);
    u32 tick = reinterpret_cast<u32>(message);

    int interrupts = OSDisableInterrupts();

    GpFuture* next = mHeadGpFuture->mNext;
    if (next != nullptr) {
      if (next->mNext != nullptr) {
        GXEnableBreakPt(next->mNext->mWritePtr);
      } else {
        GXDisableBreakPt();
      }
    }

    CpuGpMonitor* cpuGpMonitor = mHeadGpFuture->mCpuGpMonitor;
    mHeadGpFuture = mHeadGpFuture->mNext;

    OSRestoreInterrupts(interrupts);

    switch (cpuGpMonitor->mNextFuture) {
    case CpuGpMonitor::NEXT_FUTURE_BEGIN:
      cpuGpMonitor->mGpBar.mStartTick = tick;
      cpuGpMonitor->mNextFuture = CpuGpMonitor::NEXT_FUTURE_END;
      break;
    case CpuGpMonitor::NEXT_FUTURE_END:
      cpuGpMonitor->mGpBar.mEndTick = tick;
      cpuGpMonitor->mNextFuture = CpuGpMonitor::NEXT_FUTURE_NONE;
      break;
    }
  }
}

void ProcessMeter::setDrawSync(GpFuture* nextGpFuture) {
  int interrupts = OSDisableInterrupts();

  mToken += 1;
  if (mToken > 0xdfff) {
    mToken = 0xd000;
  }

  nextGpFuture->mToken = mToken;
  nextGpFuture->mNext = nullptr;

  if (mHeadGpFuture != nullptr) {
    GXFifoObj fifo;
    GXGetGPFifo(&fifo);
    void* readPtr;
    GXGetFifoPtrs(&fifo, &readPtr, &nextGpFuture->mWritePtr);
    if (mHeadGpFuture->mNext == nullptr) {
      GXEnableBreakPt(nextGpFuture->mWritePtr);
    }

    mTailGpFuture->mNext = nextGpFuture;
    mTailGpFuture = nextGpFuture;
  } else {
    mHeadGpFuture = nextGpFuture;
    mTailGpFuture = nextGpFuture;
  }

  GXSetDrawSync(mToken);

  OSRestoreInterrupts(interrupts);
}

void ProcessMeter::setVisible(bool visible) {
  if (visible) {
    mFlags |= VISIBLE;
  } else {
    mFlags &= ~VISIBLE;
  }
}

bool ProcessMeter::isVisible() { return mFlags & VISIBLE; }

void ProcessMeter::append(CpuMonitor* cpuMonitor) {
  List_Append(&mBarList, &cpuMonitor->mCpuBar);
}

void ProcessMeter::append(CpuGpMonitor* cpuGpMonitor) {
  List_Append(&mBarList, &cpuGpMonitor->mCpuBar);
  List_Append(&mBarList, &cpuGpMonitor->mGpBar);
  cpuGpMonitor->mProcessMeter = this;
}

} // namespace EGG

// Symbol: ProcessMeter_draw
MARK_BINARY_BLOB(ProcessMeter_draw, 0x80238fa4, 0x80239338);
asm UNKNOWN_FUNCTION(ProcessMeter_draw) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stfd f31, 0x90(r1);
  psq_st f31, 152(r1), 0, 0;
  stfd f30, 0x80(r1);
  psq_st f30, 136(r1), 0, 0;
  stfd f29, 0x70(r1);
  psq_st f29, 120(r1), 0, 0;
  stfd f28, 0x60(r1);
  psq_st f28, 104(r1), 0, 0;
  stfd f27, 0x50(r1);
  psq_st f27, 88(r1), 0, 0;
  addi r11, r1, 0x50;
  bl _savegpr_27;
  lbz r0, 0x152(r3);
  mr r28, r3;
  clrlwi. r0, r0, 0x1f;
  beq lbl_802392f8;
  lis r6, 0x8000;
  lis r5, 0x4330;
  lwz r7, 0xf8(r6);
  lis r6, 0x431c;
  addi r8, r6, -8573;
  lbz r0, 0x153(r3);
  srwi r6, r7, 2;
  slwi r7, r4, 3;
  mulhwu r4, r8, r6;
  stw r0, 0x34(r1);
  lfd f5, -0x6008(r2);
  stw r5, 0x30(r1);
  lfs f3, -0x5ff0(r2);
  lfd f0, 0x30(r1);
  srwi r0, r4, 0xf;
  stw r5, 0x28(r1);
  divwu r0, r7, r0;
  fsubs f0, f0, f5;
  stw r0, 0x2c(r1);
  lfd f4, 0x28(r1);
  fsubs f4, f4, f5;
  fdivs f27, f4, f3;
  fmuls f3, f27, f0;
  bl ProcessMeter_drawSetting;
  lbz r7, 0x84(r28);
  addi r4, r1, 0x10;
  lbz r6, 0x85(r28);
  li r3, 4;
  lbz r5, 0x86(r28);
  lbz r0, 0x87(r28);
  lfs f31, 0x148(r28);
  stb r7, 0x1c(r1);
  stb r6, 0x1d(r1);
  stb r5, 0x1e(r1);
  stb r0, 0x1f(r1);
  stb r7, 0x10(r1);
  stb r6, 0x11(r1);
  stb r5, 0x12(r1);
  stb r0, 0x13(r1);
  bl GXSetChanMatColor;
  lfs f29, 0x78(r28);
  lfs f0, -0x6018(r2);
  lfs f30, 0x74(r28);
  fcmpo cr0, f29, f0;
  ble lbl_802390f4;
  fcmpo cr0, f31, f0;
  ble lbl_802390f4;
  li r3, 0x80;
  li r4, 0;
  li r5, 4;
  bl GXBegin;
  lis r3, 0xcc01;
  lfs f0, -0x5fec(r2);
  stfs f30, -0x8000(r3);
  fadds f2, f30, f29;
  lfs f1, -0x5fec(r2);
  fadds f0, f0, f31;
  stfs f1, -0x8000(r3);
  stfs f2, -0x8000(r3);
  lfs f1, -0x5fec(r2);
  stfs f1, -0x8000(r3);
  stfs f2, -0x8000(r3);
  stfs f0, -0x8000(r3);
  stfs f30, -0x8000(r3);
  stfs f0, -0x8000(r3);
lbl_802390f4:
  lfs f28, -0x6018(r2);
  addi r31, r1, 0x18;
  lfs f29, 0x78(r28);
  addi r30, r1, 0x14;
  li r29, 0;
  lis r27, 0xcc01;
  b lbl_802391f8;
lbl_80239110:
  li r3, 0x14;
  li r4, 0;
  bl GXSetLineWidth;
  lbz r7, 0x84(r28);
  mr r4, r31;
  lbz r6, 0x85(r28);
  li r3, 4;
  lbz r5, 0x86(r28);
  lbz r0, 0x87(r28);
  stb r7, 0x24(r1);
  stb r6, 0x25(r1);
  stb r5, 0x26(r1);
  stb r0, 0x27(r1);
  stb r7, 0x18(r1);
  stb r6, 0x19(r1);
  stb r5, 0x1a(r1);
  stb r0, 0x1b(r1);
  bl GXSetChanMatColor;
  lfs f31, 0x148(r28);
  li r3, 0xa8;
  li r4, 0;
  li r5, 2;
  bl GXBegin;
  stfs f28, -0x8000(r27);
  li r3, 0xc;
  lfs f0, -0x5fec(r2);
  li r4, 0;
  stfs f0, -0x8000(r27);
  stfs f28, -0x8000(r27);
  stfs f31, -0x8000(r27);
  bl GXSetLineWidth;
  lbz r7, 0x4c(r28);
  mr r4, r30;
  lbz r6, 0x4d(r28);
  li r3, 4;
  lbz r5, 0x4e(r28);
  lbz r0, 0x4f(r28);
  stb r7, 0x20(r1);
  stb r6, 0x21(r1);
  stb r5, 0x22(r1);
  stb r0, 0x23(r1);
  stb r7, 0x14(r1);
  stb r6, 0x15(r1);
  stb r5, 0x16(r1);
  stb r0, 0x17(r1);
  bl GXSetChanMatColor;
  lfs f31, 0x148(r28);
  li r3, 0xa8;
  li r4, 0;
  li r5, 2;
  bl GXBegin;
  stfs f28, -0x8000(r27);
  addi r29, r29, 1;
  lfs f0, -0x5fec(r2);
  stfs f0, -0x8000(r27);
  stfs f28, -0x8000(r27);
  fadds f28, f28, f27;
  stfs f31, -0x8000(r27);
lbl_802391f8:
  fcmpo cr0, f28, f29;
  mfcr r0;
  rlwinm. r0, r0, 1, 0x1f, 0x1f;
  beq lbl_80239214;
  lwz r0, 0x144(r28);
  cmplw r29, r0;
  blt lbl_80239110;
lbl_80239214:
  lbz r0, 0x152(r28);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8023922c;
  lbz r0, 0x153(r28);
  cmpw r29, r0;
  ble lbl_80239110;
lbl_8023922c:
  lfs f31, -0x6018(r2);
  addi r27, r1, 8;
  li r30, 0;
  lis r29, 0xcc01;
  b lbl_802392e0;
lbl_80239240:
  lbz r0, 0x1c(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_802392e0;
  lbz r7, 0x10(r3);
  mr r4, r27;
  lbz r6, 0x11(r3);
  lbz r5, 0x12(r3);
  lbz r0, 0x13(r3);
  lfs f30, 0x18(r3);
  lfs f29, 0x14(r3);
  li r3, 4;
  stb r7, 0xc(r1);
  stb r6, 0xd(r1);
  stb r5, 0xe(r1);
  stb r0, 0xf(r1);
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  bl GXSetChanMatColor;
  lfs f27, 4(r30);
  lfs f28, 0(r30);
  fcmpo cr0, f27, f31;
  ble lbl_802392e0;
  fcmpo cr0, f30, f31;
  ble lbl_802392e0;
  li r3, 0x80;
  li r4, 0;
  li r5, 4;
  bl GXBegin;
  stfs f28, -0x8000(r29);
  fadds f1, f28, f27;
  fadds f0, f29, f30;
  stfs f29, -0x8000(r29);
  stfs f1, -0x8000(r29);
  stfs f29, -0x8000(r29);
  stfs f1, -0x8000(r29);
  stfs f0, -0x8000(r29);
  stfs f28, -0x8000(r29);
  stfs f0, -0x8000(r29);
lbl_802392e0:
  mr r4, r30;
  addi r3, r28, 0x60;
  bl List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80239240;
lbl_802392f8:
  psq_l f31, 152(r1), 0, 0;
  lfd f31, 0x90(r1);
  psq_l f30, 136(r1), 0, 0;
  lfd f30, 0x80(r1);
  psq_l f29, 120(r1), 0, 0;
  lfd f29, 0x70(r1);
  psq_l f28, 104(r1), 0, 0;
  lfd f28, 0x60(r1);
  psq_l f27, 88(r1), 0, 0;
  addi r11, r1, 0x50;
  lfd f27, 0x50(r1);
  bl _restgpr_27;
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_draw2
MARK_BINARY_BLOB(ProcessMeter_draw2, 0x80239338, 0x802393e0);
asm UNKNOWN_FUNCTION(ProcessMeter_draw2) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r31, 0(r3);
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  lwz r12, 4(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  lhz r6, 4(r31);
  lis r5, 0x4330;
  stw r6, 0xc(r1);
  mr r4, r3;
  lhz r0, 6(r31);
  mr r3, r30;
  stw r5, 8(r1);
  lfd f2, -0x6008(r2);
  lfd f0, 8(r1);
  stw r0, 0x14(r1);
  fsubs f1, f0, f2;
  stw r5, 0x10(r1);
  lfd f0, 0x10(r1);
  fsubs f2, f0, f2;
  bl ProcessMeter_draw;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_drawSetting
// PAL: 0x802393e0..0x80239628
MARK_BINARY_BLOB(ProcessMeter_drawSetting, 0x802393e0, 0x80239628);
asm UNKNOWN_FUNCTION(ProcessMeter_drawSetting) {
  // clang-format off
  nofralloc;
  stwu r1, -0x110(r1);
  mflr r0;
  stw r0, 0x114(r1);
  stfd f31, 0x100(r1);
  psq_st f31, 264(r1), 0, 0;
  stfd f30, 0xf0(r1);
  psq_st f30, 248(r1), 0, 0;
  stfd f29, 0xe0(r1);
  psq_st f29, 232(r1), 0, 0;
  fmr f29, f1;
  fmr f30, f2;
  lfs f1, -0x6018(r2);
  stw r31, 0xdc(r1);
  fmr f31, f3;
  fmr f2, f1;
  stw r30, 0xd8(r1);
  fmr f3, f29;
  lfs f6, -0x6000(r2);
  fmr f4, f30;
  mr r30, r3;
  fmr f5, f1;
  bl GXSetViewport;
  fmr f1, f30;
  bl __cvt_fp2unsigned;
  fmr f1, f29;
  mr r31, r3;
  bl __cvt_fp2unsigned;
  mr r5, r3;
  mr r6, r31;
  li r3, 0;
  li r4, 0;
  bl GXSetScissor;
  lfs f1, -0x6000(r2);
  addi r3, r1, 0x98;
  lfs f2, -0x6018(r2);
  fmr f4, f1;
  fmr f3, f2;
  fmr f5, f2;
  fmr f6, f1;
  bl C_MTXOrtho;
  addi r3, r1, 0x98;
  li r4, 1;
  bl GXSetProjection;
  lfs f1, 0x50(r30);
  addi r3, r1, 8;
  lfs f2, -0x5fe8(r2);
  lfs f0, 0x54(r30);
  fdivs f1, f1, f2;
  lfs f3, -0x6018(r2);
  fdivs f2, f0, f2;
  bl PSMTXTrans;
  lfs f1, 0x58(r30);
  addi r3, r1, 0x38;
  lfs f2, -0x5fe8(r2);
  lfs f0, 0x5c(r30);
  fdivs f1, f1, f2;
  lfs f3, -0x6018(r2);
  fdivs f2, f0, f2;
  bl PSMTXScale;
  addi r3, r1, 8;
  addi r4, r1, 0x38;
  addi r5, r1, 0x68;
  bl PSMTXConcat;
  lbz r0, 0x152(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8023950c;
  lfs f0, 0x78(r30);
  fcmpo cr0, f0, f31;
  bge lbl_8023950c;
  lfs f2, -0x6000(r2);
  addi r3, r1, 0x38;
  fdivs f1, f2, f31;
  fmr f3, f2;
  bl PSMTXScale;
  b lbl_80239524;
lbl_8023950c:
  lfs f2, -0x6000(r2);
  addi r3, r1, 0x38;
  lfs f0, 0x78(r30);
  fmr f3, f2;
  fdivs f1, f2, f0;
  bl PSMTXScale;
lbl_80239524:
  addi r3, r1, 0x68;
  addi r4, r1, 0x38;
  mr r5, r3;
  bl PSMTXConcat;
  addi r3, r1, 0x68;
  li r4, 0;
  bl GXLoadPosMtxImm;
  li r3, 0;
  bl GXSetCurrentMtx;
  li r3, 4;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  li r9, 2;
  bl GXSetChanCtrl;
  li r3, 1;
  bl GXSetNumChans;
  li r3, 0;
  bl GXSetNumIndStages;
  li r3, 0;
  bl GXSetNumTexGens;
  li r3, 0;
  li r4, 0xff;
  li r5, 0xff;
  li r6, 4;
  bl GXSetTevOrder;
  li r3, 0;
  li r4, 4;
  bl GXSetTevOp;
  li r3, 1;
  bl GXSetNumTevStages;
  li r3, 0;
  bl GXSetCullMode;
  li r3, 2;
  li r4, 1;
  li r5, 0;
  li r6, 3;
  bl GXSetBlendMode;
  li r3, 1;
  bl GXSetColorUpdate;
  bl GXClearVtxDesc;
  li r3, 0;
  li r4, 9;
  li r5, 0;
  li r6, 4;
  li r7, 0;
  bl GXSetVtxAttrFmt;
  li r3, 0;
  li r4, 7;
  li r5, 0;
  bl GXSetZMode;
  psq_l f31, 264(r1), 0, 0;
  lfd f31, 0x100(r1);
  psq_l f30, 248(r1), 0, 0;
  lfd f30, 0xf0(r1);
  psq_l f29, 232(r1), 0, 0;
  lfd f29, 0xe0(r1);
  lwz r31, 0xdc(r1);
  lwz r0, 0x114(r1);
  lwz r30, 0xd8(r1);
  mtlr r0;
  addi r1, r1, 0x110;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_destroy
// PAL: 0x80239628..0x80239680
MARK_BINARY_BLOB(ProcessMeter_destroy, 0x80239628, 0x80239680);
asm UNKNOWN_FUNCTION(ProcessMeter_destroy) {
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
  beq lbl_80239664;
  li r4, 0;
  bl __dt__Q23EGG6ThreadFv;
  cmpwi r31, 0;
  ble lbl_80239664;
  mr r3, r30;
  bl __dl__FPv;
lbl_80239664:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: isVisibleThunk__Q23EGG12ProcessMeterFv
// PAL: 0x80239680..0x80239688
MARK_BINARY_BLOB(isVisibleThunk__Q23EGG12ProcessMeterFv, 0x80239680,
                 0x80239688);
asm UNKNOWN_FUNCTION(isVisibleThunk__Q23EGG12ProcessMeterFv) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b isVisible__Q23EGG12ProcessMeterFv;
  // clang-format on
}

// Symbol: setVisibleThunk__Q23EGG12ProcessMeterFb
// PAL: 0x80239688..0x80239690
MARK_BINARY_BLOB(setVisibleThunk__Q23EGG12ProcessMeterFb, 0x80239688,
                 0x80239690);
asm UNKNOWN_FUNCTION(setVisibleThunk__Q23EGG12ProcessMeterFb) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b setVisible__Q23EGG12ProcessMeterFb;
  // clang-format on
}

// Symbol: ProcessMeter_draw_
// PAL: 0x80239690..0x80239698
MARK_BINARY_BLOB(ProcessMeter_draw_, 0x80239690, 0x80239698);
asm UNKNOWN_FUNCTION(ProcessMeter_draw_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_draw2;
  // clang-format on
}

// Symbol: callbackDrawSyncThunk__Q23EGG12ProcessMeterFUs
// PAL: 0x80239698..0x802396a0
MARK_BINARY_BLOB(callbackDrawSyncThunk__Q23EGG12ProcessMeterFUs, 0x80239698,
                 0x802396a0);
asm UNKNOWN_FUNCTION(callbackDrawSyncThunk__Q23EGG12ProcessMeterFUs) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b callbackDrawSync__Q23EGG12ProcessMeterFUs;
  // clang-format on
}

// Symbol: measureEndRenderThunk__Q23EGG12ProcessMeterFv
// PAL: 0x802396a0..0x802396a8
MARK_BINARY_BLOB(measureEndRenderThunk__Q23EGG12ProcessMeterFv, 0x802396a0,
                 0x802396a8);
asm UNKNOWN_FUNCTION(measureEndRenderThunk__Q23EGG12ProcessMeterFv) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b measureEndRender__Q23EGG12ProcessMeterFv;
  // clang-format on
}

// Symbol: measureBeginRenderThunk__Q23EGG12ProcessMeterFv
// PAL: 0x802396a8..0x802396b0
MARK_BINARY_BLOB(measureBeginRenderThunk__Q23EGG12ProcessMeterFv, 0x802396a8,
                 0x802396b0);
asm UNKNOWN_FUNCTION(measureBeginRenderThunk__Q23EGG12ProcessMeterFv) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b measureBeginRender__Q23EGG12ProcessMeterFv;
  // clang-format on
}

// Symbol: measureEndFrameThunk__Q23EGG12ProcessMeterFv
// PAL: 0x802396b0..0x802396b8
MARK_BINARY_BLOB(measureEndFrameThunk__Q23EGG12ProcessMeterFv, 0x802396b0,
                 0x802396b8);
asm UNKNOWN_FUNCTION(measureEndFrameThunk__Q23EGG12ProcessMeterFv) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b measureEndFrame__Q23EGG12ProcessMeterFv;
  // clang-format on
}

// Symbol: measureBeginFrameThunk__Q23EGG12ProcessMeterFv
// PAL: 0x802396b8..0x802396c0
MARK_BINARY_BLOB(measureBeginFrameThunk__Q23EGG12ProcessMeterFv, 0x802396b8,
                 0x802396c0);
asm UNKNOWN_FUNCTION(measureBeginFrameThunk__Q23EGG12ProcessMeterFv) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b measureBeginFrame__Q23EGG12ProcessMeterFv;
  // clang-format on
}
