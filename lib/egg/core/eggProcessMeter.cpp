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

namespace EGG {

void ProcessMeter::measureBeginFrame() {
  if (mBgBar.mStartTick != 0) {
    mBgBar.mEndTick = OSGetTick();
  }
  mBgBar.update(0.0f);

  ProcessBar* bar = nullptr;
  f32 maxY = 0.0f;
  while ((bar = (ProcessBar*)List_GetNext(&mBarList, bar))) {
    bar->update(bar->mStartTick - mBgBar.mStartTick);

    f32 barMaxY;
    if (bar->mDimX > 0.0f) {
      barMaxY = bar->mPosY + bar->mDimY;
    } else {
      barMaxY = 0.0f;
    }
    if (!(bar->mFlags & ProcessBar::HIDDEN) && barMaxY > maxY) {
      maxY = barMaxY;
    }
  }

  mBgBarDimY = 1.0f + maxY;

  mBgBar.mStartTick = OSGetTick();
  mBgBar.mEndTick = 0;

  mCpuMonitor.measureBegin();
}

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
