#include <egg/core/eggProcessMeter.hpp>

#include <rvl/gx/gxFifo.h>
#include <rvl/os/osThread.h>

namespace EGG {

ProcessMeter::ProcessBar::ProcessBar(nw4r::ut::Color color, f32 posY, f32 dimY) {
  mPosX = 0.0f;
  mDimX = 0.0f;
  mStartTick = 0;
  mEndTick = 0;
  mColor = color;
  mPosY = posY;
  mDimY = dimY;
  mFlags = 0;
}

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

void ProcessMeter::ProcessBar::update(u32 startTickInFrame) {
  f32 posX = static_cast<f32>(startTickInFrame) / static_cast<f32>(OS_TIMER_CLOCK / 1000);
  update(posX);
}

ProcessMeter::CpuMonitor::CpuMonitor(nw4r::ut::Color color, f32 posY) : mCpuBar(color, posY, 1.0) {}

void ProcessMeter::CpuMonitor::measureBegin() {
  mCpuBar.mStartTick = OSGetTick();
  mCpuBar.mEndTick = 0;
}

void ProcessMeter::CpuMonitor::measureEnd() {
  if (mCpuBar.mStartTick != 0) {
    mCpuBar.mEndTick = OSGetTick();
  }
}

void ProcessMeter::CpuMonitor::show() {
  mCpuBar.mFlags &= ~ProcessBar::HIDDEN;
}

void ProcessMeter::CpuMonitor::hide() {
  mCpuBar.mFlags |= ProcessBar::HIDDEN;
}

ProcessMeter::GpFuture::GpFuture(CpuGpMonitor *cpuGpMonitor) : mCpuGpMonitor(cpuGpMonitor) {}

ProcessMeter::CpuGpMonitor::CpuGpMonitor(nw4r::ut::Color cpuColor, nw4r::ut::Color gpColor, f32 cpuPosY, f32 gpPosY) : CpuMonitor(cpuColor, cpuPosY), mGpBar(gpColor, gpPosY, 1.0), mNextFuture(CpuGpMonitor::NEXT_FUTURE_NONE), mBeginFuture(this), mEndFuture(this) {}

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

// TODO ProcessMeter::ProcessMeter(bool showGp);

void ProcessMeter::measureBeginFrame() {
  if (mBgBar.mStartTick != 0) {
    mBgBar.mEndTick = OSGetTick();
  }
  mBgBar.update(0.0f);

  ProcessBar *bar = nullptr;
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

void ProcessMeter::measureEndFrame() {
  mCpuMonitor.measureEnd();
}

void ProcessMeter::measureBeginRender() {
  mCpuGpMonitor.measureBegin();
}

void ProcessMeter::measureEndRender() {
  mCpuGpMonitor.measureEnd();
}

void ProcessMeter::callbackDrawSync(u16 token) {
  if (mHeadGpFuture->mToken == token) {
    u32 tick = OSGetTick();
    OSSendMessage(getMesgQueue(), reinterpret_cast<void *>(tick), OS_MESSAGE_NOBLOCK);
  }
}

void *ProcessMeter::run() {
  while (true) {
    OSMessage message;
    OSReceiveMessage(getMesgQueue(), &message, OS_MESSAGE_BLOCK);
    u32 tick = reinterpret_cast<u32>(message);

    int interrupts = OSDisableInterrupts();

    GpFuture *next = mHeadGpFuture->mNext;
    if (next != nullptr) {
      if (next->mNext != nullptr) {
        GXEnableBreakPt(next->mNext->mWritePtr);
      } else {
        GXDisableBreakPt();
      }
    }

    CpuGpMonitor *cpuGpMonitor = mHeadGpFuture->mCpuGpMonitor;
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

void ProcessMeter::setDrawSync(GpFuture *nextGpFuture) {
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
    void *readPtr;
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

bool ProcessMeter::isVisible() {
  return mFlags & VISIBLE;
}

void ProcessMeter::append(CpuMonitor *cpuMonitor) {
  List_Append(&mBarList, &cpuMonitor->mCpuBar);
}

void ProcessMeter::append(CpuGpMonitor *cpuGpMonitor) {
  List_Append(&mBarList, &cpuGpMonitor->mCpuBar);
  List_Append(&mBarList, &cpuGpMonitor->mGpBar);
  cpuGpMonitor->mProcessMeter = this;
}

void draw(f32 width, f32 height, u32 tickPerFrame) {
  // TODO
}

void draw() {
  // TODO
}

void drawSetting(f32 width, f32 height, f32 unk) {
  //GXSetViewport(0.0f, 0.0f, width, height, 0.0, 1.0);
  //GXSetScissor(0, 0, width, height);
}

ProcessMeter::~ProcessMeter() {}

} // namespace EGG
