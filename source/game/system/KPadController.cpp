#include "KPadController.hpp"

#include <game/system/KPadDirector.hpp>


extern "C" {

// Extern function references.
// PAL: 0x80005f34
extern UNKNOWN_FUNCTION(memcpy);
// PAL: 0x80006038
extern UNKNOWN_FUNCTION(memset);
// PAL: 0x8002156c
extern UNKNOWN_FUNCTION(_savegpr_14);
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215b8
extern UNKNOWN_FUNCTION(_restgpr_14);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x801950a0
extern UNKNOWN_FUNCTION(KPADSetFSStickClamp);
// PAL: 0x801950b4
extern UNKNOWN_FUNCTION(KPADSetPosParam);
// PAL: 0x801950d0
extern UNKNOWN_FUNCTION(KPADSetHoriParam);
// PAL: 0x80197380
extern UNKNOWN_FUNCTION(KPADRead);
// PAL: 0x80197da0
extern UNKNOWN_FUNCTION(KPADDisableDPD);
// PAL: 0x80197dbc
extern UNKNOWN_FUNCTION(KPADEnableDPD);
// PAL: 0x8019812c
extern UNKNOWN_FUNCTION(KPADGetUnifiedWpadStatus);
// PAL: 0x801af908
extern UNKNOWN_FUNCTION(PADControlMotor);
// PAL: 0x801bf694
extern UNKNOWN_FUNCTION(FUN_801bf694);
// PAL: 0x801c0990
extern UNKNOWN_FUNCTION(WPADProbe);
// PAL: 0x801c0ca4
extern UNKNOWN_FUNCTION(WPADGetInfoAsync);
// PAL: 0x801c0ec4
extern UNKNOWN_FUNCTION(WPADControlMotor);
// PAL: 0x801c32a4
extern UNKNOWN_FUNCTION(WPADIsDpdEnabled);
// PAL: 0x801cb364
extern UNKNOWN_FUNCTION(unk_801cb364);
// PAL: 0x80213a3c
extern UNKNOWN_FUNCTION(alf_8b7ad3f5);
// PAL: 0x80213ad4
extern UNKNOWN_FUNCTION(alf_239d82da);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x80229ee0
extern UNKNOWN_FUNCTION(__dla__FPv);
// PAL: 0x8051ed14
extern UNKNOWN_FUNCTION(Controller_calc);
// PAL: 0x8051f384
extern UNKNOWN_FUNCTION(unk_8051f384);
// PAL: 0x8051f410
extern UNKNOWN_FUNCTION(unk_8051f410);
// PAL: 0x8051fa7c
extern UNKNOWN_FUNCTION(unk_8051fa7c);
// PAL: 0x8051fbe0
extern UNKNOWN_FUNCTION(unk_8051fbe0);
// PAL: 0x80521198
extern UNKNOWN_FUNCTION(Input_vf_0c);
// PAL: 0x80521acc
extern UNKNOWN_FUNCTION(unk_80521acc);
// PAL: 0x80523a58
extern UNKNOWN_FUNCTION(unk_80523a58);
// PAL: 0x80524628
extern UNKNOWN_FUNCTION(KPadDirector_getPadStatus);
// PAL: 0x80524ac4
extern UNKNOWN_FUNCTION(GhostWriter_construct);
// PAL: 0x80524ca8
extern UNKNOWN_FUNCTION(GhostWriter_reset);
// PAL: 0x80524d20
extern UNKNOWN_FUNCTION(unk_80524d20);
// PAL: 0x80524e74
extern UNKNOWN_FUNCTION(GhostWriter_writeFrame);
// PAL: 0x80525498
extern UNKNOWN_FUNCTION(unk_80525498);
// PAL: 0x80525508
extern UNKNOWN_FUNCTION(unk_80525508);
// PAL: 0x805255bc
extern UNKNOWN_FUNCTION(unk_805255bc);
// PAL: 0x8052564c
extern UNKNOWN_FUNCTION(unk_8052564c);
// PAL: 0x8052570c
extern UNKNOWN_FUNCTION(unk_8052570c);
// PAL: 0x80525974
extern UNKNOWN_FUNCTION(unk_80525974);
// PAL: 0x80525a74
extern UNKNOWN_FUNCTION(unk_80525a74);
// PAL: 0x80745884
extern UNKNOWN_FUNCTION(unk_80745884);
// PAL: 0x807459e4
extern UNKNOWN_FUNCTION(unk_807459e4);
// PAL: 0x80745be4
extern UNKNOWN_FUNCTION(unk_80745be4);
// PAL: 0x80745de4
extern UNKNOWN_FUNCTION(unk_80745de4);// Extern data references.
// PAL: 0x80385fc8
extern UNKNOWN_DATA(spInstance__Q26System8RKSystem);
// PAL: 0x8088fcb0
extern UNKNOWN_DATA(lbl_8088fcb0);
// PAL: 0x8088fcc0
extern UNKNOWN_DATA(ZERO_F__6System);
// PAL: 0x8088fcc4
extern UNKNOWN_DATA(MINUS_ONE_F__6System);
// PAL: 0x8088fcc8
extern UNKNOWN_DATA(SEVEN_F__6System);
// PAL: 0x8088fcd0
extern UNKNOWN_DATA(DIVIDE_BY_SEVEN_F__6System);
// PAL: 0x8088fce0
extern UNKNOWN_DATA(lbl_8088fce0);
// PAL: 0x8088fcf0
extern UNKNOWN_DATA(lbl_8088fcf0);
// PAL: 0x8088fcf4
extern UNKNOWN_DATA(lbl_8088fcf4);
// PAL: 0x8088fd08
extern UNKNOWN_DATA(lbl_8088fd08);
// PAL: 0x808b2d90
extern UNKNOWN_DATA(lbl_808b2d90);
// PAL: 0x808b2dd8
extern UNKNOWN_DATA(lbl_808b2dd8);
// PAL: 0x808b2e00
extern UNKNOWN_DATA(lbl_808b2e00);
// PAL: 0x808b2e48
extern UNKNOWN_DATA(lbl_808b2e48);
// PAL: 0x808b2e90
extern UNKNOWN_DATA(lbl_808b2e90);
// PAL: 0x808b2ed8
extern UNKNOWN_DATA(lbl_808b2ed8);
// PAL: 0x808b2f20
extern UNKNOWN_DATA(lbl_808b2f20);
// PAL: 0x808b2f2c
extern UNKNOWN_DATA(lbl_808b2f2c);
// PAL: 0x808b3078
extern UNKNOWN_DATA(lbl_808b3078);
// PAL: 0x808b30a0
extern UNKNOWN_DATA(lbl_808b30a0);
// PAL: 0x808b30c8
extern UNKNOWN_DATA(lbl_808b30c8);
// PAL: 0x809bd700
extern UNKNOWN_DATA(lbl_809bd700);
// PAL: 0x809bd704
extern UNKNOWN_DATA(lbl_809bd704);
// PAL: 0x809bd70c
extern UNKNOWN_DATA(spInstance__Q26System12KPadDirector);
// PAL: 0x809bd748
extern UNKNOWN_DATA(lbl_809bd748);
}

// --- EXTERN DECLARATIONS END ---

namespace System {

// .rodata

#ifndef SHIFTABLE
extern f32 ZERO_F;
REL_SYMBOL_AT(ZERO_F, 0x8088fcc0)
extern f32 MINUS_ONE_F;
REL_SYMBOL_AT(MINUS_ONE_F, 0x8088fcc4)
extern f32 SEVEN_F;
REL_SYMBOL_AT(SEVEN_F, 0x8088fcc8)
extern f64 DIVIDE_BY_SEVEN_F;
REL_SYMBOL_AT(DIVIDE_BY_SEVEN_F, 0x8088fcd0)
#else
static const f32 ZERO_F = 0.f;
static const f32 MINUS_ONE_F = 1.f;
static const f32 SEVEN_F = 7.f;
static const f64 DIVIDE_BY_SEVEN_F = reinterpret_cast<f64>(0x433ULL << 52);
#endif

// .data


// .bss


float rawStickToFloat(u8 stick);

void KPadRaceInputState::reset() {
  mButtons = 0;
  mButtonsRaw = 0;
  mStick.y = 0.f;
  mStick.x = 0.f;
  mStickXRaw = 7;
  mStickYRaw = 7;
  mTrick = 0;
  mTrickRaw = 0;
  mFlags._0 = 0;
}

bool KPadRaceInputState::operator==(const KPadRaceInputState& rhs) const {
  if (!mFlags._0 || !rhs.mFlags._0) {
      return false;
  }

  f32 rx = rhs.mStick.x; 
  f32 lx = mStick.x;
  if (lx != rx) {
    return false;
  }

  f32 ry = rhs.mStick.y;
  f32 ly = mStick.y;
  if (ly != ry) {
    return false;
  }

  return mButtons == rhs.mButtons;
}

void KPadUIInputState::reset() {
  mButtons = 0;  
  mButtonsRaw = 0;
  mStick.y = 0.0f;
  mStick.x = 0.0f;
  mStickXRaw = 7;
  mStickYRaw = 7;
  mFlags._0 = 0;
  _1c = -1.f;
  _20 = -1.f;
  _28 = 0.f;
  _24 = 0.f;
  _2c = 0.f;
  mFlags._1 = 0;
}

void KPadRaceInputState::setStickXMirrored(u8 x) {
  mStickXRaw = x;
  mStick.x = KPadDirector::spInstance->mIsMirror ?
              -rawStickToFloat(x) : rawStickToFloat(x);
}

void KPadRaceInputState::setStickXUnmirrored(u8 x) {
  mStickXRaw = x;
  mStick.x = rawStickToFloat(x);
}

float rawStickToFloat(u8 stick) {
  return (stick - 7.f) / 7.f;
}

void KPadRaceInputState::setStickY(u8 y) {
  mStickYRaw = y;
  mStick.y = rawStickToFloat(y);
}

void KPadUIInputState::setStickXMirrored(u8 x) {
  mStickXRaw = x;
  mStick.x = KPadDirector::spInstance->mIsMirror ?
              -rawStickToFloat(x) : rawStickToFloat(x);
}

void KPadUIInputState::setStickY(u8 y) {
  mStickYRaw = y;
  mStick.y = rawStickToFloat(y);
}

void KPadRaceInputState::setTrick(u8 trick) {
  mTrickRaw = trick;
  u8 actualTrick = trick;
  if (KPadDirector::spInstance->mIsMirror) {
    switch (trick) {
    case 3:
      actualTrick = 4;
      break;
    case 4:
      actualTrick = 3;
      break;
    default:
      break;
    }
  }
  mTrick = actualTrick;
}
} // namespace System

// Symbol: Controller_construct
// PAL: 0x8051eba8..0x8051ec94
MARK_BINARY_BLOB(Controller_construct, 0x8051eba8, 0x8051ec94);
asm UNKNOWN_FUNCTION(Controller_construct) {
  #include "asm/8051eba8.s"
}

// Symbol: RaceInputState_destroy
// PAL: 0x8051ec94..0x8051ecd4
MARK_BINARY_BLOB(RaceInputState_destroy, 0x8051ec94, 0x8051ecd4);
asm UNKNOWN_FUNCTION(RaceInputState_destroy) {
  #include "asm/8051ec94.s"
}

// Symbol: UIInputState_destroy
// PAL: 0x8051ecd4..0x8051ed14
MARK_BINARY_BLOB(UIInputState_destroy, 0x8051ecd4, 0x8051ed14);
asm UNKNOWN_FUNCTION(UIInputState_destroy) {
  #include "asm/8051ecd4.s"
}

// Symbol: Controller_calc
// PAL: 0x8051ed14..0x8051f00c
MARK_BINARY_BLOB(Controller_calc, 0x8051ed14, 0x8051f00c);
asm UNKNOWN_FUNCTION(Controller_calc) {
  #include "asm/8051ed14.s"
}

// Symbol: Controller_stopMotorHard
// PAL: 0x8051f00c..0x8051f010
MARK_BINARY_BLOB(Controller_stopMotorHard, 0x8051f00c, 0x8051f010);
asm UNKNOWN_FUNCTION(Controller_stopMotorHard) {
  #include "asm/8051f00c.s"
}

// Symbol: unk_8051f010
// PAL: 0x8051f010..0x8051f074
MARK_BINARY_BLOB(unk_8051f010, 0x8051f010, 0x8051f074);
asm UNKNOWN_FUNCTION(unk_8051f010) {
  #include "asm/8051f010.s"
}

// Symbol: Controller_getBatteryLevelAsync
// PAL: 0x8051f074..0x8051f07c
MARK_BINARY_BLOB(Controller_getBatteryLevelAsync, 0x8051f074, 0x8051f07c);
asm UNKNOWN_FUNCTION(Controller_getBatteryLevelAsync) {
  #include "asm/8051f074.s"
}

// Symbol: unk_8051f07c
// PAL: 0x8051f07c..0x8051f088
MARK_BINARY_BLOB(unk_8051f07c, 0x8051f07c, 0x8051f088);
asm UNKNOWN_FUNCTION(unk_8051f07c) {
  #include "asm/8051f07c.s"
}

// Symbol: WiiController_construct
// PAL: 0x8051f088..0x8051f1ec
MARK_BINARY_BLOB(WiiController_construct, 0x8051f088, 0x8051f1ec);
asm UNKNOWN_FUNCTION(WiiController_construct) {
  #include "asm/8051f088.s"
}

// Symbol: Controller_destroy
// PAL: 0x8051f1ec..0x8051f22c
MARK_BINARY_BLOB(Controller_destroy, 0x8051f1ec, 0x8051f22c);
asm UNKNOWN_FUNCTION(Controller_destroy) {
  #include "asm/8051f1ec.s"
}

// Symbol: unk_8051f22c
// PAL: 0x8051f22c..0x8051f308
MARK_BINARY_BLOB(unk_8051f22c, 0x8051f22c, 0x8051f308);
asm UNKNOWN_FUNCTION(unk_8051f22c) {
  #include "asm/8051f22c.s"
}

// Symbol: unk_8051f308
// PAL: 0x8051f308..0x8051f37c
MARK_BINARY_BLOB(unk_8051f308, 0x8051f308, 0x8051f37c);
asm UNKNOWN_FUNCTION(unk_8051f308) {
  #include "asm/8051f308.s"
}

// Symbol: Controller_setDriftIsAuto
// PAL: 0x8051f37c..0x8051f384
MARK_BINARY_BLOB(Controller_setDriftIsAuto, 0x8051f37c, 0x8051f384);
asm UNKNOWN_FUNCTION(Controller_setDriftIsAuto) {
  #include "asm/8051f37c.s"
}

// Symbol: unk_8051f384
// PAL: 0x8051f384..0x8051f3b4
MARK_BINARY_BLOB(unk_8051f384, 0x8051f384, 0x8051f3b4);
asm UNKNOWN_FUNCTION(unk_8051f384) {
  #include "asm/8051f384.s"
}

// Symbol: unk_8051f3b4
// PAL: 0x8051f3b4..0x8051f3d0
MARK_BINARY_BLOB(unk_8051f3b4, 0x8051f3b4, 0x8051f3d0);
asm UNKNOWN_FUNCTION(unk_8051f3b4) {
  #include "asm/8051f3b4.s"
}

// Symbol: WiiController_getBatteryLevelAsync
// PAL: 0x8051f3d0..0x8051f410
MARK_BINARY_BLOB(WiiController_getBatteryLevelAsync, 0x8051f3d0, 0x8051f410);
asm UNKNOWN_FUNCTION(WiiController_getBatteryLevelAsync) {
  #include "asm/8051f3d0.s"
}

// Symbol: unk_8051f410
// PAL: 0x8051f410..0x8051fa7c
MARK_BINARY_BLOB(unk_8051f410, 0x8051f410, 0x8051fa7c);
asm UNKNOWN_FUNCTION(unk_8051f410) {
  #include "asm/8051f410.s"
}

// Symbol: unk_8051fa7c
// PAL: 0x8051fa7c..0x8051fbe0
MARK_BINARY_BLOB(unk_8051fa7c, 0x8051fa7c, 0x8051fbe0);
asm UNKNOWN_FUNCTION(unk_8051fa7c) {
  #include "asm/8051fa7c.s"
}

// Symbol: unk_8051fbe0
// PAL: 0x8051fbe0..0x8051fc84
MARK_BINARY_BLOB(unk_8051fbe0, 0x8051fbe0, 0x8051fc84);
asm UNKNOWN_FUNCTION(unk_8051fbe0) {
  #include "asm/8051fbe0.s"
}

// Symbol: WiiController_calcInner
// PAL: 0x8051fc84..0x8051ffb8
MARK_BINARY_BLOB(WiiController_calcInner, 0x8051fc84, 0x8051ffb8);
asm UNKNOWN_FUNCTION(WiiController_calcInner) {
  #include "asm/8051fc84.s"
}

// Symbol: WiiController_controlDpd
// PAL: 0x8051ffb8..0x8051ffd0
MARK_BINARY_BLOB(WiiController_controlDpd, 0x8051ffb8, 0x8051ffd0);
asm UNKNOWN_FUNCTION(WiiController_controlDpd) {
  #include "asm/8051ffb8.s"
}

// Symbol: GcController_construct
// PAL: 0x8051ffd0..0x80520118
MARK_BINARY_BLOB(GcController_construct, 0x8051ffd0, 0x80520118);
asm UNKNOWN_FUNCTION(GcController_construct) {
  #include "asm/8051ffd0.s"
}

// Symbol: unk_80520118
// PAL: 0x80520118..0x805201b0
MARK_BINARY_BLOB(unk_80520118, 0x80520118, 0x805201b0);
asm UNKNOWN_FUNCTION(unk_80520118) {
  #include "asm/80520118.s"
}

// Symbol: GcController_calcInner
// PAL: 0x805201b0..0x805206fc
MARK_BINARY_BLOB(GcController_calcInner, 0x805201b0, 0x805206fc);
asm UNKNOWN_FUNCTION(GcController_calcInner) {
  #include "asm/805201b0.s"
}

// Symbol: unk_805206fc
// PAL: 0x805206fc..0x80520730
MARK_BINARY_BLOB(unk_805206fc, 0x805206fc, 0x80520730);
asm UNKNOWN_FUNCTION(unk_805206fc) {
  #include "asm/805206fc.s"
}

// Symbol: GhostController_construct
// PAL: 0x80520730..0x80520924
MARK_BINARY_BLOB(GhostController_construct, 0x80520730, 0x80520924);
asm UNKNOWN_FUNCTION(GhostController_construct) {
  #include "asm/80520730.s"
}

// Symbol: GhostController_destroy
// PAL: 0x80520924..0x80520998
MARK_BINARY_BLOB(GhostController_destroy, 0x80520924, 0x80520998);
asm UNKNOWN_FUNCTION(GhostController_destroy) {
  #include "asm/80520924.s"
}

// Symbol: unk_80520998
// PAL: 0x80520998..0x80520a4c
MARK_BINARY_BLOB(unk_80520998, 0x80520998, 0x80520a4c);
asm UNKNOWN_FUNCTION(unk_80520998) {
  #include "asm/80520998.s"
}

// Symbol: unk_80520a4c
// PAL: 0x80520a4c..0x80520a60
MARK_BINARY_BLOB(unk_80520a4c, 0x80520a4c, 0x80520a60);
asm UNKNOWN_FUNCTION(unk_80520a4c) {
  #include "asm/80520a4c.s"
}

// Symbol: unk_80520a60
// PAL: 0x80520a60..0x80520b18
MARK_BINARY_BLOB(unk_80520a60, 0x80520a60, 0x80520b18);
asm UNKNOWN_FUNCTION(unk_80520a60) {
  #include "asm/80520a60.s"
}

// Symbol: unk_80520b18
// PAL: 0x80520b18..0x80520b9c
MARK_BINARY_BLOB(unk_80520b18, 0x80520b18, 0x80520b9c);
asm UNKNOWN_FUNCTION(unk_80520b18) {
  #include "asm/80520b18.s"
}

// Symbol: GhostController_calcInner
// PAL: 0x80520b9c..0x80520d4c
MARK_BINARY_BLOB(GhostController_calcInner, 0x80520b9c, 0x80520d4c);
asm UNKNOWN_FUNCTION(GhostController_calcInner) {
  #include "asm/80520b9c.s"
}

// Symbol: DirectionButtonsStream_readFrame
// PAL: 0x80520d4c..0x80520eb4
MARK_BINARY_BLOB(DirectionButtonsStream_readFrame, 0x80520d4c, 0x80520eb4);
asm UNKNOWN_FUNCTION(DirectionButtonsStream_readFrame) {
  #include "asm/80520d4c.s"
}

// Symbol: DirectionButtonsStream_getSequenceSize
// PAL: 0x80520eb4..0x80520ebc
MARK_BINARY_BLOB(DirectionButtonsStream_getSequenceSize, 0x80520eb4, 0x80520ebc);
asm UNKNOWN_FUNCTION(DirectionButtonsStream_getSequenceSize) {
  #include "asm/80520eb4.s"
}

// Symbol: Input_vf_20
// PAL: 0x80520ebc..0x80520f2c
MARK_BINARY_BLOB(Input_vf_20, 0x80520ebc, 0x80520f2c);
asm UNKNOWN_FUNCTION(Input_vf_20) {
  #include "asm/80520ebc.s"
}

// Symbol: unk_80520f2c
// PAL: 0x80520f2c..0x80520f64
MARK_BINARY_BLOB(unk_80520f2c, 0x80520f2c, 0x80520f64);
asm UNKNOWN_FUNCTION(unk_80520f2c) {
  #include "asm/80520f2c.s"
}

// Symbol: KartInput_construct
// PAL: 0x80520f64..0x80521110
MARK_BINARY_BLOB(KartInput_construct, 0x80520f64, 0x80521110);
asm UNKNOWN_FUNCTION(KartInput_construct) {
  #include "asm/80520f64.s"
}

// Symbol: Input_vf_10
// PAL: 0x80521110..0x80521198
MARK_BINARY_BLOB(Input_vf_10, 0x80521110, 0x80521198);
asm UNKNOWN_FUNCTION(Input_vf_10) {
  #include "asm/80521110.s"
}

// Symbol: Input_vf_0c
// PAL: 0x80521198..0x80521554
MARK_BINARY_BLOB(Input_vf_0c, 0x80521198, 0x80521554);
asm UNKNOWN_FUNCTION(Input_vf_0c) {
  #include "asm/80521198.s"
}

// Symbol: KartInput_setController
// PAL: 0x80521554..0x805215d4
MARK_BINARY_BLOB(KartInput_setController, 0x80521554, 0x805215d4);
asm UNKNOWN_FUNCTION(KartInput_setController) {
  #include "asm/80521554.s"
}

// Symbol: GhostPadProxy_start
// PAL: 0x805215d4..0x80521688
MARK_BINARY_BLOB(GhostPadProxy_start, 0x805215d4, 0x80521688);
asm UNKNOWN_FUNCTION(GhostPadProxy_start) {
  #include "asm/805215d4.s"
}

// Symbol: GhostPadProxy_end
// PAL: 0x80521688..0x80521768
MARK_BINARY_BLOB(GhostPadProxy_end, 0x80521688, 0x80521768);
asm UNKNOWN_FUNCTION(GhostPadProxy_end) {
  #include "asm/80521688.s"
}

// Symbol: PlayerInput_calc
// PAL: 0x80521768..0x80521844
MARK_BINARY_BLOB(PlayerInput_calc, 0x80521768, 0x80521844);
asm UNKNOWN_FUNCTION(PlayerInput_calc) {
  #include "asm/80521768.s"
}

// Symbol: PlayerKartInput_setGhostController
// PAL: 0x80521844..0x80521930
MARK_BINARY_BLOB(PlayerKartInput_setGhostController, 0x80521844, 0x80521930);
asm UNKNOWN_FUNCTION(PlayerKartInput_setGhostController) {
  #include "asm/80521844.s"
}

// Symbol: unk_80521930
// PAL: 0x80521930..0x805219ac
MARK_BINARY_BLOB(unk_80521930, 0x80521930, 0x805219ac);
asm UNKNOWN_FUNCTION(unk_80521930) {
  #include "asm/80521930.s"
}

// Symbol: unk_805219ac
// PAL: 0x805219ac..0x80521a34
MARK_BINARY_BLOB(unk_805219ac, 0x805219ac, 0x80521a34);
asm UNKNOWN_FUNCTION(unk_805219ac) {
  #include "asm/805219ac.s"
}

// Symbol: unk_80521a34
// PAL: 0x80521a34..0x80521acc
MARK_BINARY_BLOB(unk_80521a34, 0x80521a34, 0x80521acc);
asm UNKNOWN_FUNCTION(unk_80521a34) {
  #include "asm/80521a34.s"
}

// Symbol: unk_80521acc
// PAL: 0x80521acc..0x80521d84
MARK_BINARY_BLOB(unk_80521acc, 0x80521acc, 0x80521d84);
asm UNKNOWN_FUNCTION(unk_80521acc) {
  #include "asm/80521acc.s"
}

// Symbol: unk_80521d84
// PAL: 0x80521d84..0x80521d8c
MARK_BINARY_BLOB(unk_80521d84, 0x80521d84, 0x80521d8c);
asm UNKNOWN_FUNCTION(unk_80521d84) {
  #include "asm/80521d84.s"
}

// Symbol: unk_80521d8c
// PAL: 0x80521d8c..0x80521e48
MARK_BINARY_BLOB(unk_80521d8c, 0x80521d8c, 0x80521e48);
asm UNKNOWN_FUNCTION(unk_80521d8c) {
  #include "asm/80521d8c.s"
}

// Symbol: unk_80521e48
// PAL: 0x80521e48..0x80521ed0
MARK_BINARY_BLOB(unk_80521e48, 0x80521e48, 0x80521ed0);
asm UNKNOWN_FUNCTION(unk_80521e48) {
  #include "asm/80521e48.s"
}

// Symbol: unk_80521ed0
// PAL: 0x80521ed0..0x80521f8c
MARK_BINARY_BLOB(unk_80521ed0, 0x80521ed0, 0x80521f8c);
asm UNKNOWN_FUNCTION(unk_80521ed0) {
  #include "asm/80521ed0.s"
}

// Symbol: unk_80521f8c
// PAL: 0x80521f8c..0x80522014
MARK_BINARY_BLOB(unk_80521f8c, 0x80521f8c, 0x80522014);
asm UNKNOWN_FUNCTION(unk_80521f8c) {
  #include "asm/80521f8c.s"
}

// Symbol: unk_80522014
// PAL: 0x80522014..0x80522078
MARK_BINARY_BLOB(unk_80522014, 0x80522014, 0x80522078);
asm UNKNOWN_FUNCTION(unk_80522014) {
  #include "asm/80522014.s"
}

// Symbol: unk_80522078
// PAL: 0x80522078..0x8052208c
MARK_BINARY_BLOB(unk_80522078, 0x80522078, 0x8052208c);
asm UNKNOWN_FUNCTION(unk_80522078) {
  #include "asm/80522078.s"
}

// Symbol: Controller_startMotor
// PAL: 0x8052208c..0x80522090
MARK_BINARY_BLOB(Controller_startMotor, 0x8052208c, 0x80522090);
asm UNKNOWN_FUNCTION(Controller_startMotor) {
  #include "asm/8052208c.s"
}

// Symbol: unk_80522090
// PAL: 0x80522090..0x805220a4
MARK_BINARY_BLOB(unk_80522090, 0x80522090, 0x805220a4);
asm UNKNOWN_FUNCTION(unk_80522090) {
  #include "asm/80522090.s"
}

// Symbol: Controller_stopMotor
// PAL: 0x805220a4..0x805220a8
MARK_BINARY_BLOB(Controller_stopMotor, 0x805220a4, 0x805220a8);
asm UNKNOWN_FUNCTION(Controller_stopMotor) {
  #include "asm/805220a4.s"
}

// Symbol: unk_805220a8
// PAL: 0x805220a8..0x805220bc
MARK_BINARY_BLOB(unk_805220a8, 0x805220a8, 0x805220bc);
asm UNKNOWN_FUNCTION(unk_805220a8) {
  #include "asm/805220a8.s"
}

// Symbol: PlayerKartInput_construct
// PAL: 0x805220bc..0x805222b4
MARK_BINARY_BLOB(PlayerKartInput_construct, 0x805220bc, 0x805222b4);
asm UNKNOWN_FUNCTION(PlayerKartInput_construct) {
  #include "asm/805220bc.s"
}

// Symbol: KartInput_destroy
// PAL: 0x805222b4..0x805222f4
MARK_BINARY_BLOB(KartInput_destroy, 0x805222b4, 0x805222f4);
asm UNKNOWN_FUNCTION(KartInput_destroy) {
  #include "asm/805222b4.s"
}

// Symbol: PlayerKartInput_destroy
// PAL: 0x805222f4..0x80522358
MARK_BINARY_BLOB(PlayerKartInput_destroy, 0x805222f4, 0x80522358);
asm UNKNOWN_FUNCTION(PlayerKartInput_destroy) {
  #include "asm/805222f4.s"
}

// Symbol: unk_80522358
// PAL: 0x80522358..0x80522364
MARK_BINARY_BLOB(unk_80522358, 0x80522358, 0x80522364);
asm UNKNOWN_FUNCTION(unk_80522358) {
  #include "asm/80522358.s"
}

// Symbol: unk_80522364
// PAL: 0x80522364..0x80522494
MARK_BINARY_BLOB(unk_80522364, 0x80522364, 0x80522494);
asm UNKNOWN_FUNCTION(unk_80522364) {
  #include "asm/80522364.s"
}

// Symbol: Controller_getChan
// PAL: 0x80522494..0x8052249c
MARK_BINARY_BLOB(Controller_getChan, 0x80522494, 0x8052249c);
asm UNKNOWN_FUNCTION(Controller_getChan) {
  #include "asm/80522494.s"
}

// Symbol: unk_8052249c
// PAL: 0x8052249c..0x8052250c
MARK_BINARY_BLOB(unk_8052249c, 0x8052249c, 0x8052250c);
asm UNKNOWN_FUNCTION(unk_8052249c) {
  #include "asm/8052249c.s"
}

// Symbol: unk_8052250c
// PAL: 0x8052250c..0x805225a4
MARK_BINARY_BLOB(unk_8052250c, 0x8052250c, 0x805225a4);
asm UNKNOWN_FUNCTION(unk_8052250c) {
  #include "asm/8052250c.s"
}

// Symbol: unk_805225a4
// PAL: 0x805225a4..0x80522690
MARK_BINARY_BLOB(unk_805225a4, 0x805225a4, 0x80522690);
asm UNKNOWN_FUNCTION(unk_805225a4) {
  #include "asm/805225a4.s"
}

// Symbol: unk_80522690
// PAL: 0x80522690..0x805226f4
MARK_BINARY_BLOB(unk_80522690, 0x80522690, 0x805226f4);
asm UNKNOWN_FUNCTION(unk_80522690) {
  #include "asm/80522690.s"
}

// Symbol: Input_setInputState
// PAL: 0x805226f4..0x805226f8
MARK_BINARY_BLOB(Input_setInputState, 0x805226f4, 0x805226f8);
asm UNKNOWN_FUNCTION(Input_setInputState) {
  #include "asm/805226f4.s"
}

// Symbol: unk_805226f8
// PAL: 0x805226f8..0x80522700
MARK_BINARY_BLOB(unk_805226f8, 0x805226f8, 0x80522700);
asm UNKNOWN_FUNCTION(unk_805226f8) {
  #include "asm/805226f8.s"
}

// Symbol: unk_80522700
// PAL: 0x80522700..0x80522708
MARK_BINARY_BLOB(unk_80522700, 0x80522700, 0x80522708);
asm UNKNOWN_FUNCTION(unk_80522700) {
  #include "asm/80522700.s"
}

// Symbol: PlayerKartInput_reset
// PAL: 0x80522708..0x8052279c
MARK_BINARY_BLOB(PlayerKartInput_reset, 0x80522708, 0x8052279c);
asm UNKNOWN_FUNCTION(PlayerKartInput_reset) {
  #include "asm/80522708.s"
}

// Symbol: AiKartInput_destroy
// PAL: 0x8052279c..0x805227dc
MARK_BINARY_BLOB(AiKartInput_destroy, 0x8052279c, 0x805227dc);
asm UNKNOWN_FUNCTION(AiKartInput_destroy) {
  #include "asm/8052279c.s"
}

// Symbol: unk_805227dc
// PAL: 0x805227dc..0x8052281c
MARK_BINARY_BLOB(unk_805227dc, 0x805227dc, 0x8052281c);
asm UNKNOWN_FUNCTION(unk_805227dc) {
  #include "asm/805227dc.s"
}

// Symbol: Controller_isDpdEnabled
// PAL: 0x8052281c..0x80522824
MARK_BINARY_BLOB(Controller_isDpdEnabled, 0x8052281c, 0x80522824);
asm UNKNOWN_FUNCTION(Controller_isDpdEnabled) {
  #include "asm/8052281c.s"
}

// Symbol: Controller_controlDpd
// PAL: 0x80522824..0x80522828
MARK_BINARY_BLOB(Controller_controlDpd, 0x80522824, 0x80522828);
asm UNKNOWN_FUNCTION(Controller_controlDpd) {
  #include "asm/80522824.s"
}

// Symbol: GhostController_setDriftIsAuto
// PAL: 0x80522828..0x8052282c
MARK_BINARY_BLOB(GhostController_setDriftIsAuto, 0x80522828, 0x8052282c);
asm UNKNOWN_FUNCTION(GhostController_setDriftIsAuto) {
  #include "asm/80522828.s"
}

// Symbol: unk_8052282c
// PAL: 0x8052282c..0x80522834
MARK_BINARY_BLOB(unk_8052282c, 0x8052282c, 0x80522834);
asm UNKNOWN_FUNCTION(unk_8052282c) {
  #include "asm/8052282c.s"
}

// Symbol: unk_80522834
// PAL: 0x80522834..0x80522840
MARK_BINARY_BLOB(unk_80522834, 0x80522834, 0x80522840);
asm UNKNOWN_FUNCTION(unk_80522834) {
  #include "asm/80522834.s"
}

// Symbol: GcController_stopMotorHard
// PAL: 0x80522840..0x8052284c
MARK_BINARY_BLOB(GcController_stopMotorHard, 0x80522840, 0x8052284c);
asm UNKNOWN_FUNCTION(GcController_stopMotorHard) {
  #include "asm/80522840.s"
}

// Symbol: GcController_stopMotor
// PAL: 0x8052284c..0x80522858
MARK_BINARY_BLOB(GcController_stopMotor, 0x8052284c, 0x80522858);
asm UNKNOWN_FUNCTION(GcController_stopMotor) {
  #include "asm/8052284c.s"
}

// Symbol: GcController_startMotor
// PAL: 0x80522858..0x80522864
MARK_BINARY_BLOB(GcController_startMotor, 0x80522858, 0x80522864);
asm UNKNOWN_FUNCTION(GcController_startMotor) {
  #include "asm/80522858.s"
}

// Symbol: GcController_getChan
// PAL: 0x80522864..0x8052286c
MARK_BINARY_BLOB(GcController_getChan, 0x80522864, 0x8052286c);
asm UNKNOWN_FUNCTION(GcController_getChan) {
  #include "asm/80522864.s"
}

// Symbol: unk_8052286c
// PAL: 0x8052286c..0x80522874
MARK_BINARY_BLOB(unk_8052286c, 0x8052286c, 0x80522874);
asm UNKNOWN_FUNCTION(unk_8052286c) {
  #include "asm/8052286c.s"
}

// Symbol: GcController_destroy
// PAL: 0x80522874..0x805228b4
MARK_BINARY_BLOB(GcController_destroy, 0x80522874, 0x805228b4);
asm UNKNOWN_FUNCTION(GcController_destroy) {
  #include "asm/80522874.s"
}

// Symbol: WiiController_stopMotorHard
// PAL: 0x805228b4..0x805228c4
MARK_BINARY_BLOB(WiiController_stopMotorHard, 0x805228b4, 0x805228c4);
asm UNKNOWN_FUNCTION(WiiController_stopMotorHard) {
  #include "asm/805228b4.s"
}

// Symbol: WiiController_stopMotor
// PAL: 0x805228c4..0x805228d0
MARK_BINARY_BLOB(WiiController_stopMotor, 0x805228c4, 0x805228d0);
asm UNKNOWN_FUNCTION(WiiController_stopMotor) {
  #include "asm/805228c4.s"
}

// Symbol: WiiController_startMotor
// PAL: 0x805228d0..0x805228dc
MARK_BINARY_BLOB(WiiController_startMotor, 0x805228d0, 0x805228dc);
asm UNKNOWN_FUNCTION(WiiController_startMotor) {
  #include "asm/805228d0.s"
}

// Symbol: unk_805228dc
// PAL: 0x805228dc..0x805228f4
MARK_BINARY_BLOB(unk_805228dc, 0x805228dc, 0x805228f4);
asm UNKNOWN_FUNCTION(unk_805228dc) {
  #include "asm/805228dc.s"
}

// Symbol: WiiController_isDpdEnabled
// PAL: 0x805228f4..0x80522924
MARK_BINARY_BLOB(WiiController_isDpdEnabled, 0x805228f4, 0x80522924);
asm UNKNOWN_FUNCTION(WiiController_isDpdEnabled) {
  #include "asm/805228f4.s"
}

// Symbol: WiiController_getChan
// PAL: 0x80522924..0x8052292c
MARK_BINARY_BLOB(WiiController_getChan, 0x80522924, 0x8052292c);
asm UNKNOWN_FUNCTION(WiiController_getChan) {
  #include "asm/80522924.s"
}

// Symbol: unk_8052292c
// PAL: 0x8052292c..0x80522934
MARK_BINARY_BLOB(unk_8052292c, 0x8052292c, 0x80522934);
asm UNKNOWN_FUNCTION(unk_8052292c) {
  #include "asm/8052292c.s"
}

// Symbol: WiiController_destroy
// PAL: 0x80522934..0x80522974
MARK_BINARY_BLOB(WiiController_destroy, 0x80522934, 0x80522974);
asm UNKNOWN_FUNCTION(WiiController_destroy) {
  #include "asm/80522934.s"
}

