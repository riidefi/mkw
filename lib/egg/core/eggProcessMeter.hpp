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

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x802386dc..0x80238714
UNKNOWN_FUNCTION(CpuMonitor_measureBegin);
// PAL: 0x80238714..0x80238750
UNKNOWN_FUNCTION(CpuMonitor_measureEnd);
// PAL: 0x80238750..0x80238760
UNKNOWN_FUNCTION(CpuMonitor_show);
// PAL: 0x80238760..0x80238770
UNKNOWN_FUNCTION(CpuMonitor_hide);
// PAL: 0x80238770..0x802387bc
UNKNOWN_FUNCTION(CpuGpMonitor_measureBegin);
// PAL: 0x802387bc..0x80238804
UNKNOWN_FUNCTION(CpuGpMonitor_measureEnd);
// PAL: 0x80238804..0x80238820
UNKNOWN_FUNCTION(CpuGpMonitor_show);
// PAL: 0x80238820..0x8023883c
UNKNOWN_FUNCTION(CpuGpMonitor_hide);
// PAL: 0x8023883c..0x80238a94
UNKNOWN_FUNCTION(__ct__Q23EGG12ProcessMeterFb);
// PAL: 0x80238a94..0x80238d10
UNKNOWN_FUNCTION(measureBeginFrame__Q23EGG12ProcessMeterFv);
// PAL: 0x80238d10..0x80238d20
UNKNOWN_FUNCTION(measureEndFrame__Q23EGG12ProcessMeterFv);
// PAL: 0x80238d20..0x80238d30
UNKNOWN_FUNCTION(measureBeginRender__Q23EGG12ProcessMeterFv);
// PAL: 0x80238d30..0x80238d40
UNKNOWN_FUNCTION(measureEndRender__Q23EGG12ProcessMeterFv);
// PAL: 0x80238d40..0x80238d8c
UNKNOWN_FUNCTION(callbackDrawSync__Q23EGG12ProcessMeterFUs);
// PAL: 0x80238d8c..0x80238e38
UNKNOWN_FUNCTION(ProcessMeter_run);
// PAL: 0x80238e38..0x80238f14
UNKNOWN_FUNCTION(
    setDrawSync__Q23EGG12ProcessMeterFPQ33EGG12ProcessMeter8GpFuture);
// PAL: 0x80238f14..0x80238f3c
UNKNOWN_FUNCTION(setVisible__Q23EGG12ProcessMeterFb);
// PAL: 0x80238f3c..0x80238f48
UNKNOWN_FUNCTION(isVisible__Q23EGG12ProcessMeterFv);
// PAL: 0x80238f48..0x80238fa4
UNKNOWN_FUNCTION(
    append__Q23EGG12ProcessMeterFPQ33EGG12ProcessMeter10CpuMonitor);
// PAL: 0x80238fa4..0x802393e0
UNKNOWN_FUNCTION(ProcessMeter_draw);
// PAL: 0x802393e0..0x80239628
UNKNOWN_FUNCTION(ProcessMeter_drawSetting);
// PAL: 0x80239628..0x80239680
UNKNOWN_FUNCTION(ProcessMeter_destroy);
// PAL: 0x80239680..0x80239688
UNKNOWN_FUNCTION(isVisibleThunk__Q23EGG12ProcessMeterFv);
// PAL: 0x80239688..0x80239690
UNKNOWN_FUNCTION(setVisibleThunk__Q23EGG12ProcessMeterFb);
// PAL: 0x80239690..0x80239698
UNKNOWN_FUNCTION(ProcessMeter_draw_);
// PAL: 0x80239698..0x802396a0
UNKNOWN_FUNCTION(callbackDrawSyncThunk__Q23EGG12ProcessMeterFUs);
// PAL: 0x802396a0..0x802396a8
UNKNOWN_FUNCTION(measureEndRenderThunk__Q23EGG12ProcessMeterFv);
// PAL: 0x802396a8..0x802396b0
UNKNOWN_FUNCTION(measureBeginRenderThunk__Q23EGG12ProcessMeterFv);
// PAL: 0x802396b0..0x802396b8
UNKNOWN_FUNCTION(measureEndFrameThunk__Q23EGG12ProcessMeterFv);
// PAL: 0x802396b8..0x802396c0
UNKNOWN_FUNCTION(measureBeginFrameThunk__Q23EGG12ProcessMeterFv);

#ifdef __cplusplus
}
#endif
