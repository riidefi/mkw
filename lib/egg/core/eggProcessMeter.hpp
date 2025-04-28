#pragma once

#include <egg/core/eggThread.hpp>

#include <nw4r/ut/utColor.hpp>

namespace EGG {

class PerformanceView {
public:
  virtual void measureBeginFrame() = 0;

  virtual void measureEndFrame() = 0;

  virtual void measureBeginRender() = 0;

  virtual void measureEndRender() = 0;

  virtual void callbackDrawSync(u16 token) = 0;

  virtual void unused() = 0;

  virtual void draw() = 0;

  virtual void setVisible(bool visible) = 0;

  virtual bool isVisible() = 0;
};

class ProcessMeter : public Thread, public PerformanceView {
private:
  class ProcessBar {
  public:
    enum Flags {
      HIDDEN = 1,
    };

    ProcessBar(nw4r::ut::Color color, f32 posY, f32 dimY);

    void update(f32 posX);

    void update(u32 startTickInFrame);

    f32 mPosX;
    f32 mDimX;
    u32 mStartTick;
    u32 mEndTick;
    nw4r::ut::Color mColor;
    f32 mPosY;
    f32 mDimY;
    u8 mFlags;
    nw4r::ut::Node mNode;
  };

  class CpuMonitor {
  public:
    CpuMonitor(nw4r::ut::Color color, f32 posY);

    virtual void show();

    virtual void hide();

    virtual void measureBegin();

    virtual void measureEnd();

    ProcessBar mCpuBar;
  };

  class CpuGpMonitor;

  class GpFuture {
  public:
    GpFuture(CpuGpMonitor* cpuGpMonitor);

    void* mWritePtr;
    u16 mToken;
    GpFuture* mNext;
    CpuGpMonitor* mCpuGpMonitor;
  };

  class CpuGpMonitor : public CpuMonitor {
  public:
    enum NextFuture {
      NEXT_FUTURE_NONE = 0,
      NEXT_FUTURE_BEGIN = 1,
      NEXT_FUTURE_END = 2,
    };

    CpuGpMonitor(nw4r::ut::Color cpuColor, nw4r::ut::Color gpColor, f32 cpuPosY,
                 f32 gpPosY);

    void show() override;

    void hide() override;

    void measureBegin() override;

    void measureEnd() override;

    ProcessBar mGpBar;
    u16 mNextFuture;
    ProcessMeter* mProcessMeter;
    GpFuture mBeginFuture;
    GpFuture mEndFuture;
  };

public:
  enum Flags {
    VISIBLE = 1,
  };

  ProcessMeter(bool showGp);

  ~ProcessMeter() override;

  void setVisible(bool visible) override;

  void* run() override;

  void measureBeginFrame() override;

  void measureEndFrame() override;

  void measureBeginRender() override;

  void measureEndRender() override;

  void callbackDrawSync(u16 token) override;

  void unused() override;

  void draw() override;

  bool isVisible() override;

  void setDrawSync(GpFuture* nextGpFuture);

  void append(CpuMonitor* cpuMonitor);

  void append(CpuGpMonitor* cpuGpMonitor);

  void draw(f32 width, f32 height, u32 tickPerFrame);

  void drawSetting(f32 width, f32 height, f32 unk);

private:
  nw4r::ut::Color _4c;
  f32 _50;
  f32 _54;
  f32 _58;
  f32 _5c;
  nw4r::ut::List mBarList;
  GpFuture* mHeadGpFuture;
  GpFuture* mTailGpFuture;
  ProcessBar mBgBar;
  CpuMonitor mCpuMonitor;
  CpuGpMonitor mCpuGpMonitor;
  u32 _144;
  f32 mBgBarDimY;
  u32 _14c; // TODO check type
  u16 mToken;
  u8 mFlags;
};

} // namespace EGG
