#pragma once

#include <rk_types.h>
#include <decomp.h>
#include <egg/core/eggDisplay.hpp>
#include <nw4r/ut/utColor.hpp>
#include <rvl/os/osThread.h>

// Source:
// https://github.com/doldecomp/ogws/blob/master/include/egg/core/eggAsyncDisplay.h
namespace EGG {
struct AsyncDisplay : Display {
  AsyncDisplay(u8);
  void startSyncNTSC(u8);
  void syncTick();
  void clearEFB(u16, u16, u16, u16, u16, u16, nw4r::ut::Color);

  virtual void beginFrame();
  virtual void beginRender();
  virtual void endRender();
  virtual u32 getTickPerFrame();

  char UNK_0x28[0x30];
  OSThreadQueue mThreadQueue; // at 0x58
  s32 WORD_0x60;
  f32 FLOAT_0x64;
  u32 WORD_0x68;
  u32 WORD_0x6C;
  u8 BYTE_0x70;
  char UNK_0x71[3];
  u32 WORD_0x74;
  u32 WORD_0x78;
  s32 OSTICK_0x7C;
  s32 OSTICK_0x80;
  u32 WORD_0x84;
};
} // namespace EGG

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8020fcd4..0x8020fcdc
UNKNOWN_FUNCTION(PostRetraceCallback);
// PAL: 0x8020fcdc..0x8020fd10
UNKNOWN_FUNCTION(DrawDoneCallback);
// PAL: 0x8020fd10..0x8020fd18
UNKNOWN_FUNCTION(AlarmHandler_0);
// PAL: 0x8020fd18..0x8020fd8c
UNKNOWN_FUNCTION(__ct__Q23EGG12AsyncDisplayFUc);
// PAL: 0x8020fd8c..0x8020fe24
UNKNOWN_FUNCTION(startSyncNTSC__Q23EGG12AsyncDisplayFUc);
// PAL: 0x8020fe24..0x8020ff98
UNKNOWN_FUNCTION(beginFrame__Q23EGG12AsyncDisplayFv);
// PAL: 0x8020ff98..0x8020ff9c
UNKNOWN_FUNCTION(beginRender__Q23EGG12AsyncDisplayFv);
// PAL: 0x8020ff9c..0x80210024
UNKNOWN_FUNCTION(endRender__Q23EGG12AsyncDisplayFv);
// PAL: 0x80210024..0x8021008c
UNKNOWN_FUNCTION(postVRetrace__Q23EGG12AsyncDisplayFv);
// PAL: 0x8021008c..0x802100a0
UNKNOWN_FUNCTION(alarmHandler__Q23EGG12AsyncDisplayFv);
// PAL: 0x802100a0..0x80210124
UNKNOWN_FUNCTION(clearEFB__Q23EGG12AsyncDisplayFv);
// PAL: 0x80210124..0x8021013c
UNKNOWN_FUNCTION(getTickPerFrame__Q23EGG12AsyncDisplayFv);
// PAL: 0x8021013c..0x802104ec
UNKNOWN_FUNCTION(clearEFB__Q23EGG12AsyncDisplayFUsUsUsUsUsUsQ34nw4r2ut5Color);

#ifdef __cplusplus
}
#endif
