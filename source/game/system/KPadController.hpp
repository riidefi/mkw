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
// PAL: 0x8051eba8..0x8051ec94
UNKNOWN_FUNCTION(Controller_construct);
// PAL: 0x8051ec94..0x8051ecd4
UNKNOWN_FUNCTION(RaceInputState_destroy);
// PAL: 0x8051ecd4..0x8051ed14
UNKNOWN_FUNCTION(UIInputState_destroy);
// PAL: 0x8051ed14..0x8051f00c
UNKNOWN_FUNCTION(Controller_calc);
// PAL: 0x8051f00c..0x8051f010
UNKNOWN_FUNCTION(Controller_stopMotorHard);
// PAL: 0x8051f010..0x8051f074
UNKNOWN_FUNCTION(unk_8051f010);
// PAL: 0x8051f074..0x8051f07c
UNKNOWN_FUNCTION(Controller_getBatteryLevelAsync);
// PAL: 0x8051f07c..0x8051f088
UNKNOWN_FUNCTION(unk_8051f07c);
// PAL: 0x8051f088..0x8051f1ec
UNKNOWN_FUNCTION(WiiController_construct);
// PAL: 0x8051f1ec..0x8051f22c
UNKNOWN_FUNCTION(Controller_destroy);
// PAL: 0x8051f22c..0x8051f308
UNKNOWN_FUNCTION(unk_8051f22c);
// PAL: 0x8051f308..0x8051f37c
UNKNOWN_FUNCTION(unk_8051f308);
// PAL: 0x8051f37c..0x8051f384
UNKNOWN_FUNCTION(Controller_setDriftIsAuto);
// PAL: 0x8051f384..0x8051f3b4
UNKNOWN_FUNCTION(unk_8051f384);
// PAL: 0x8051f3b4..0x8051f3d0
UNKNOWN_FUNCTION(unk_8051f3b4);
// PAL: 0x8051f3d0..0x8051f410
UNKNOWN_FUNCTION(WiiController_getBatteryLevelAsync);
// PAL: 0x8051f410..0x8051fa7c
UNKNOWN_FUNCTION(unk_8051f410);
// PAL: 0x8051fa7c..0x8051fbe0
UNKNOWN_FUNCTION(unk_8051fa7c);
// PAL: 0x8051fbe0..0x8051fc84
UNKNOWN_FUNCTION(unk_8051fbe0);
// PAL: 0x8051fc84..0x8051ffb8
UNKNOWN_FUNCTION(WiiController_calcInner);
// PAL: 0x8051ffb8..0x8051ffd0
UNKNOWN_FUNCTION(WiiController_controlDpd);
// PAL: 0x8051ffd0..0x80520118
UNKNOWN_FUNCTION(GcController_construct);
// PAL: 0x80520118..0x805201b0
UNKNOWN_FUNCTION(unk_80520118);
// PAL: 0x805201b0..0x805206fc
UNKNOWN_FUNCTION(GcController_calcInner);
// PAL: 0x805206fc..0x80520730
UNKNOWN_FUNCTION(unk_805206fc);
// PAL: 0x80520730..0x80520924
UNKNOWN_FUNCTION(GhostController_construct);
// PAL: 0x80520924..0x80520998
UNKNOWN_FUNCTION(GhostController_destroy);
// PAL: 0x80520998..0x80520a4c
UNKNOWN_FUNCTION(unk_80520998);
// PAL: 0x80520a4c..0x80520a60
UNKNOWN_FUNCTION(unk_80520a4c);
// PAL: 0x80520a60..0x80520b18
UNKNOWN_FUNCTION(unk_80520a60);
// PAL: 0x80520b18..0x80520b9c
UNKNOWN_FUNCTION(unk_80520b18);
// PAL: 0x80520b9c..0x80520d4c
UNKNOWN_FUNCTION(GhostController_calcInner);
// PAL: 0x80520d4c..0x80520eb4
UNKNOWN_FUNCTION(DirectionButtonsStream_readFrame);
// PAL: 0x80520eb4..0x80520ebc
UNKNOWN_FUNCTION(DirectionButtonsStream_getSequenceSize);
// PAL: 0x80520ebc..0x80520f2c
UNKNOWN_FUNCTION(Input_vf_20);
// PAL: 0x80520f2c..0x80520f64
UNKNOWN_FUNCTION(unk_80520f2c);
// PAL: 0x80520f64..0x80521110
UNKNOWN_FUNCTION(KartInput_construct);
// PAL: 0x80521110..0x80521198
UNKNOWN_FUNCTION(Input_vf_10);
// PAL: 0x80521198..0x80521554
UNKNOWN_FUNCTION(Input_vf_0c);
// PAL: 0x80521554..0x805215d4
UNKNOWN_FUNCTION(KartInput_setController);
// PAL: 0x805215d4..0x80521688
UNKNOWN_FUNCTION(GhostPadProxy_start);
// PAL: 0x80521688..0x80521768
UNKNOWN_FUNCTION(GhostPadProxy_end);
// PAL: 0x80521768..0x80521844
UNKNOWN_FUNCTION(PlayerInput_calc);
// PAL: 0x80521844..0x80521930
UNKNOWN_FUNCTION(PlayerKartInput_setGhostController);
// PAL: 0x80521930..0x805219ac
UNKNOWN_FUNCTION(unk_80521930);
// PAL: 0x805219ac..0x80521a34
UNKNOWN_FUNCTION(unk_805219ac);
// PAL: 0x80521a34..0x80521acc
UNKNOWN_FUNCTION(unk_80521a34);
// PAL: 0x80521acc..0x80521d84
UNKNOWN_FUNCTION(unk_80521acc);
// PAL: 0x80521d84..0x80521d8c
UNKNOWN_FUNCTION(unk_80521d84);
// PAL: 0x80521d8c..0x80521e48
UNKNOWN_FUNCTION(unk_80521d8c);
// PAL: 0x80521e48..0x80521ed0
UNKNOWN_FUNCTION(unk_80521e48);
// PAL: 0x80521ed0..0x80521f8c
UNKNOWN_FUNCTION(unk_80521ed0);
// PAL: 0x80521f8c..0x80522014
UNKNOWN_FUNCTION(unk_80521f8c);
// PAL: 0x80522014..0x80522078
UNKNOWN_FUNCTION(unk_80522014);
// PAL: 0x80522078..0x8052208c
UNKNOWN_FUNCTION(unk_80522078);
// PAL: 0x8052208c..0x80522090
UNKNOWN_FUNCTION(Controller_startMotor);
// PAL: 0x80522090..0x805220a4
UNKNOWN_FUNCTION(unk_80522090);
// PAL: 0x805220a4..0x805220a8
UNKNOWN_FUNCTION(Controller_stopMotor);
// PAL: 0x805220a8..0x805220bc
UNKNOWN_FUNCTION(unk_805220a8);
// PAL: 0x805220bc..0x805222b4
UNKNOWN_FUNCTION(PlayerKartInput_construct);
// PAL: 0x805222b4..0x805222f4
UNKNOWN_FUNCTION(KartInput_destroy);
// PAL: 0x805222f4..0x80522358
UNKNOWN_FUNCTION(PlayerKartInput_destroy);
// PAL: 0x80522358..0x80522364
UNKNOWN_FUNCTION(unk_80522358);
// PAL: 0x80522364..0x80522494
UNKNOWN_FUNCTION(unk_80522364);
// PAL: 0x80522494..0x8052249c
UNKNOWN_FUNCTION(Controller_getChan);
// PAL: 0x8052249c..0x8052250c
UNKNOWN_FUNCTION(unk_8052249c);
// PAL: 0x8052250c..0x805225a4
UNKNOWN_FUNCTION(unk_8052250c);
// PAL: 0x805225a4..0x80522690
UNKNOWN_FUNCTION(unk_805225a4);
// PAL: 0x80522690..0x805226f4
UNKNOWN_FUNCTION(unk_80522690);
// PAL: 0x805226f4..0x805226f8
UNKNOWN_FUNCTION(Input_setInputState);
// PAL: 0x805226f8..0x80522700
UNKNOWN_FUNCTION(unk_805226f8);
// PAL: 0x80522700..0x80522708
UNKNOWN_FUNCTION(unk_80522700);
// PAL: 0x80522708..0x8052279c
UNKNOWN_FUNCTION(PlayerKartInput_reset);
// PAL: 0x8052279c..0x805227dc
UNKNOWN_FUNCTION(AiKartInput_destroy);
// PAL: 0x805227dc..0x8052281c
UNKNOWN_FUNCTION(unk_805227dc);
// PAL: 0x8052281c..0x80522824
UNKNOWN_FUNCTION(Controller_isDpdEnabled);
// PAL: 0x80522824..0x80522828
UNKNOWN_FUNCTION(Controller_controlDpd);
// PAL: 0x80522828..0x8052282c
UNKNOWN_FUNCTION(GhostController_setDriftIsAuto);
// PAL: 0x8052282c..0x80522834
UNKNOWN_FUNCTION(unk_8052282c);
// PAL: 0x80522834..0x80522840
UNKNOWN_FUNCTION(unk_80522834);
// PAL: 0x80522840..0x8052284c
UNKNOWN_FUNCTION(GcController_stopMotorHard);
// PAL: 0x8052284c..0x80522858
UNKNOWN_FUNCTION(GcController_stopMotor);
// PAL: 0x80522858..0x80522864
UNKNOWN_FUNCTION(GcController_startMotor);
// PAL: 0x80522864..0x8052286c
UNKNOWN_FUNCTION(GcController_getChan);
// PAL: 0x8052286c..0x80522874
UNKNOWN_FUNCTION(unk_8052286c);
// PAL: 0x80522874..0x805228b4
UNKNOWN_FUNCTION(GcController_destroy);
// PAL: 0x805228b4..0x805228c4
UNKNOWN_FUNCTION(WiiController_stopMotorHard);
// PAL: 0x805228c4..0x805228d0
UNKNOWN_FUNCTION(WiiController_stopMotor);
// PAL: 0x805228d0..0x805228dc
UNKNOWN_FUNCTION(WiiController_startMotor);
// PAL: 0x805228dc..0x805228f4
UNKNOWN_FUNCTION(unk_805228dc);
// PAL: 0x805228f4..0x80522924
UNKNOWN_FUNCTION(WiiController_isDpdEnabled);
// PAL: 0x80522924..0x8052292c
UNKNOWN_FUNCTION(WiiController_getChan);
// PAL: 0x8052292c..0x80522934
UNKNOWN_FUNCTION(unk_8052292c);
// PAL: 0x80522934..0x80522974
UNKNOWN_FUNCTION(WiiController_destroy);
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
  struct {
    u8 _0: 1;
    u8 _1: 1;
    u8 _2: 1;
    u8 _3: 1;
    u8 _4: 1;
    u8 _5: 1;
    u8 _6: 1;
    u8 _7: 1;
  } mFlags;                                       // [this+0x14]
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
  float _24; // _24 and _28 potentially a vector?
  float _28;
  float _2c;
  struct {
    volatile u8 _0: 1; // volatile feels like a hack...
    u8 _1: 1;
    u8 _2: 1;
    u8 _3: 1;
    u8 _4: 1;
    u8 _5: 1;
    u8 _6: 1;
    u8 _7: 1;
  } mFlags;                                       // [this+0x30]
  u8 _31;
  u8 _32;
  u8 _33;
};

static_assert(sizeof(KPadUIInputState) == 0x34);
} // namespace System
