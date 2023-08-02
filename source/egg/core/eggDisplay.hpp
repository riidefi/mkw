#pragma once

#include <rk_types.h>
#include <decomp.h>
#include <nw4r/ut/utColor.hpp>

namespace EGG {

class Display {
public:
  unsigned char mFlag; // 0x04

  Display(unsigned char);

  void copyEFBtoXFB();
  void calcFrequency(void);

  virtual void beginFrame(void);
  virtual void beginRender(void);
  virtual void endRender(void);
  virtual void endFrame(void);
  virtual u32 getTickPerFrame(void);

public:
  unsigned char mMaxRetraces;     // 0x08
  unsigned char mScreenStateFlag; // 0x09
                                  // Source: ogws
  u32 mRetraceCount;              // at 0xC
  u32 mFrameCount;                // at 0x10
  nw4r::ut::Color mClearColor;    // at 0x14
  u32 mClearZ;                    // at 0x20
  s32 mBeginTick;                 // at 0x1C
  s32 mDeltaTick;                 // at 0x20
  f32 mFrequency;                 // at 0x24

public:
  bool hasScreenStateFlag(int idx) { return mScreenStateFlag & 1 << idx; }

  void clearScreenStateFlag(int idx) {
    (*(volatile unsigned char*)(&mScreenStateFlag)) &= ~(1 << idx);
  }

  void setScreenStateFlag(int idx) {
    (*(volatile unsigned char*)(&mScreenStateFlag)) |= (1 << idx);
  }
};

} // namespace EGG
