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
