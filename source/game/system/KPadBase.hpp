#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>


extern "C" {
// PAL: 0x8051e85c..0x8051e89c
UNKNOWN_FUNCTION(reset__Q26System18KPadRaceInputStateFv);
// PAL: 0x8051e89c..0x8051e904
UNKNOWN_FUNCTION(eq__Q26System18KPadRaceInputStateFPQ26System18KPadRaceInputState);
// PAL: 0x8051e904..0x8051e960
UNKNOWN_FUNCTION(reset__Q26System16KPadUIInputStateFv);
// PAL: 0x8051e960..0x8051e9e8
UNKNOWN_FUNCTION(setStickXMirrored__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051e9e8..0x8051ea28
UNKNOWN_FUNCTION(setStickXUnmirrored__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051ea28..0x8051ea60
UNKNOWN_FUNCTION(rawStickToFloat__6SystemFUc);
// PAL: 0x8051ea60..0x8051eaa0
UNKNOWN_FUNCTION(setStickY__Q26System18KPadRaceInputStateFUc);
// PAL: 0x8051eaa0..0x8051eb28
UNKNOWN_FUNCTION(setStickXMirrored__Q26System16KPadUIInputStateFUc);
// PAL: 0x8051eb28..0x8051eb68
UNKNOWN_FUNCTION(setStickY__Q26System16KPadUIInputStateFUc);
// PAL: 0x8051eb68..0x8051eba8
UNKNOWN_FUNCTION(setTrick__Q26System18KPadRaceInputStateFUc);
}


namespace System {

struct KPadRaceInputState {
  virtual ~KPadRaceInputState() {}                // [vt+0x08]

  void reset();

  bool eq(KPadRaceInputState* rhs);

  void setStickXMirrored(u8 x);
  void setStickXUnmirrored(u8 x);
  void setStickY(u8 y);
  void setTrick(u8 trick);

  u16 mButtons;                                   // [this+0x04]
  u16 mButtonsRaw;                                // [this+0x06]
  EGG::Vector2f mStick;                           // [this+0x08]
  u8 mStickXRaw;                                  // [this+0x10]
  u8 mStickYRaw;                                  // [this+0x11]
  u8 mTrick;                                      // [this+0x12]
  u8 mTrickRaw;                                   // [this+0x13]
  u8 _14;
  u8 _15;
  u8 _16;
  u8 _17;
};

static_assert(sizeof(KPadRaceInputState) == 0x18);

struct KPadUIInputState {
  virtual ~KPadUIInputState() {}                  // [vt+0x08]

  void reset();

  void setStickXMirrored(u8 x);
  void setStickY(u8 y);

  u16 mButtons;                                   // [this+0x04]
  u16 mButtonsRaw;                                // [this+0x06]
  EGG::Vector2f mStick;                           // [this+0x08]
  u8 _10[0x08];
  u8 mStickXRaw;                                  // [this+0x18]
  u8 mStickYRaw;                                  // [this+0x19]
  u8 _1a;
  u8 _1b;
  float _1c;
  float _20;
  float _24;
  float _28;
  u8 _2c;
  u8 _2d;
  u8 _2e;
  u8 _2f;
};

static_assert(sizeof(KPadUIInputState) == 0x30);
} // namespace System
