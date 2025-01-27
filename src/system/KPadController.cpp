#include "KPadController.hpp"

#include <system/KPadDirector.hpp>


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
// PAL: 0x801bf694
extern UNKNOWN_FUNCTION(FUN_801bf694);
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
// PAL: 0x80523a58
extern UNKNOWN_FUNCTION(getControllerType__Q26System12KPadDirectorFQ26System14eControlSource);
// PAL: 0x80524628
extern UNKNOWN_FUNCTION(getPadStatus__Q26System12KPadDirectorFUcP9PADStatus);
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
static const f64 DIVIDE_BY_SEVEN_F = 4503599627370496.0;
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
  mIsValid = 0;
}

bool KPadRaceInputState::operator==(const KPadRaceInputState& rhs) const {
  if (!mIsValid || !rhs.mIsValid) {
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
  mFlags_0 = 0;
  mPointerPos.x = -1.f;
  mPointerPos.y = -1.f;
  mPointerHorizontal.y = 0.f;
  mPointerHorizontal.x = 0.f;
  mPointerDist = 0.f;
  mFlags_1 = 0;
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

// Symbol: __ct__Q26System14KPadControllerFv
// PAL: 0x8051eba8..0x8051ec94
MARK_BINARY_BLOB(__ct__Q26System14KPadControllerFv, 0x8051eba8, 0x8051ec94);
asm UNKNOWN_FUNCTION(__ct__Q26System14KPadControllerFv) {
  #include "asm/8051eba8.s"
}

// Symbol: __dt__Q26System18KPadRaceInputStateFv
// PAL: 0x8051ec94..0x8051ecd4
MARK_BINARY_BLOB(__dt__Q26System18KPadRaceInputStateFv, 0x8051ec94, 0x8051ecd4);
asm UNKNOWN_FUNCTION(__dt__Q26System18KPadRaceInputStateFv) {
  #include "asm/8051ec94.s"
}

// Symbol: __dt__Q26System16KPadUIInputStateFv
// PAL: 0x8051ecd4..0x8051ed14
MARK_BINARY_BLOB(__dt__Q26System16KPadUIInputStateFv, 0x8051ecd4, 0x8051ed14);
asm UNKNOWN_FUNCTION(__dt__Q26System16KPadUIInputStateFv) {
  #include "asm/8051ecd4.s"
}

// Symbol: calc__Q26System14KPadControllerFv
// PAL: 0x8051ed14..0x8051f00c
MARK_BINARY_BLOB(calc__Q26System14KPadControllerFv, 0x8051ed14, 0x8051f00c);
asm UNKNOWN_FUNCTION(calc__Q26System14KPadControllerFv) {
  #include "asm/8051ed14.s"
}

// Symbol: stopMotorHard__Q26System14KPadControllerFv
// PAL: 0x8051f00c..0x8051f010
MARK_BINARY_BLOB(stopMotorHard__Q26System14KPadControllerFv, 0x8051f00c, 0x8051f010);
asm UNKNOWN_FUNCTION(stopMotorHard__Q26System14KPadControllerFv) {
  #include "asm/8051f00c.s"
}

// Symbol: updateBatteryStatus__Q26System14KPadControllerFv
// PAL: 0x8051f010..0x8051f074
MARK_BINARY_BLOB(updateBatteryStatus__Q26System14KPadControllerFv, 0x8051f010, 0x8051f074);
asm UNKNOWN_FUNCTION(updateBatteryStatus__Q26System14KPadControllerFv) {
  #include "asm/8051f010.s"
}

// Symbol: getBatteryLevelAsync__Q26System14KPadControllerFv
// PAL: 0x8051f074..0x8051f07c
MARK_BINARY_BLOB(getBatteryLevelAsync__Q26System14KPadControllerFv, 0x8051f074, 0x8051f07c);
asm UNKNOWN_FUNCTION(getBatteryLevelAsync__Q26System14KPadControllerFv) {
  #include "asm/8051f074.s"
}

// Symbol: vf_3c__Q26System14KPadControllerFv
// PAL: 0x8051f07c..0x8051f088
MARK_BINARY_BLOB(vf_3c__Q26System14KPadControllerFv, 0x8051f07c, 0x8051f088);
asm UNKNOWN_FUNCTION(vf_3c__Q26System14KPadControllerFv) {
  #include "asm/8051f07c.s"
}

// Symbol: __ct__Q26System17KPadWiiControllerFv
// PAL: 0x8051f088..0x8051f1ec
MARK_BINARY_BLOB(__ct__Q26System17KPadWiiControllerFv, 0x8051f088, 0x8051f1ec);
asm UNKNOWN_FUNCTION(__ct__Q26System17KPadWiiControllerFv) {
  #include "asm/8051f088.s"
}

// Symbol: __dt__Q26System14KPadControllerFv
// PAL: 0x8051f1ec..0x8051f22c
MARK_BINARY_BLOB(__dt__Q26System14KPadControllerFv, 0x8051f1ec, 0x8051f22c);
asm UNKNOWN_FUNCTION(__dt__Q26System14KPadControllerFv) {
  #include "asm/8051f1ec.s"
}

// Symbol: reset__Q26System17KPadWiiControllerFb
// PAL: 0x8051f22c..0x8051f308
MARK_BINARY_BLOB(reset__Q26System17KPadWiiControllerFb, 0x8051f22c, 0x8051f308);
asm UNKNOWN_FUNCTION(reset__Q26System17KPadWiiControllerFb) {
  #include "asm/8051f22c.s"
}

// Symbol: reset__Q26System14KPadControllerFb
// PAL: 0x8051f308..0x8051f37c
MARK_BINARY_BLOB(reset__Q26System14KPadControllerFb, 0x8051f308, 0x8051f37c);
asm UNKNOWN_FUNCTION(reset__Q26System14KPadControllerFb) {
  #include "asm/8051f308.s"
}

// Symbol: setDriftIsAuto__Q26System14KPadControllerFb
// PAL: 0x8051f37c..0x8051f384
MARK_BINARY_BLOB(setDriftIsAuto__Q26System14KPadControllerFb, 0x8051f37c, 0x8051f384);
asm UNKNOWN_FUNCTION(setDriftIsAuto__Q26System14KPadControllerFb) {
  #include "asm/8051f37c.s"
}

// Symbol: updateBatteryCallback__Q26System17KPadWiiControllerFii
// PAL: 0x8051f384..0x8051f3b4
MARK_BINARY_BLOB(updateBatteryCallback__Q26System17KPadWiiControllerFii, 0x8051f384, 0x8051f3b4);
asm UNKNOWN_FUNCTION(updateBatteryCallback__Q26System17KPadWiiControllerFii) {
  #include "asm/8051f384.s"
}

// Symbol: updateBattery__Q26System17KPadWiiControllerFi
// PAL: 0x8051f3b4..0x8051f3d0
MARK_BINARY_BLOB(updateBattery__Q26System17KPadWiiControllerFi, 0x8051f3b4, 0x8051f3d0);
asm UNKNOWN_FUNCTION(updateBattery__Q26System17KPadWiiControllerFi) {
  #include "asm/8051f3b4.s"
}

// Symbol: getBatteryLevelAsync__Q26System17KPadWiiControllerFv
// PAL: 0x8051f3d0..0x8051f410
MARK_BINARY_BLOB(getBatteryLevelAsync__Q26System17KPadWiiControllerFv, 0x8051f3d0, 0x8051f410);
asm UNKNOWN_FUNCTION(getBatteryLevelAsync__Q26System17KPadWiiControllerFv) {
  #include "asm/8051f3d0.s"
}

// Symbol: calcClassic__Q26System17KPadWiiControllerFP21KPADUnifiedWpadStatusPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState
// PAL: 0x8051f410..0x8051fa7c
MARK_BINARY_BLOB(calcClassic__Q26System17KPadWiiControllerFP21KPADUnifiedWpadStatusPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState, 0x8051f410, 0x8051fa7c);
asm UNKNOWN_FUNCTION(calcClassic__Q26System17KPadWiiControllerFP21KPADUnifiedWpadStatusPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState) {
  #include "asm/8051f410.s"
}

// Symbol: raceToUIInputFreestyle__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState
// PAL: 0x8051fa7c..0x8051fbe0
MARK_BINARY_BLOB(raceToUIInputFreestyle__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState, 0x8051fa7c, 0x8051fbe0);
asm UNKNOWN_FUNCTION(raceToUIInputFreestyle__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState) {
  #include "asm/8051fa7c.s"
}

// Symbol: raceToUIInputCore__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState
// PAL: 0x8051fbe0..0x8051fc84
MARK_BINARY_BLOB(raceToUIInputCore__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState, 0x8051fbe0, 0x8051fc84);
asm UNKNOWN_FUNCTION(raceToUIInputCore__Q26System17KPadWiiControllerFPQ26System16KPadUIInputStatePQ26System18KPadRaceInputState) {
  #include "asm/8051fbe0.s"
}

// Symbol: calcInner__Q26System17KPadWiiControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState
// PAL: 0x8051fc84..0x8051ffb8
MARK_BINARY_BLOB(calcInner__Q26System17KPadWiiControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState, 0x8051fc84, 0x8051ffb8);
asm UNKNOWN_FUNCTION(calcInner__Q26System17KPadWiiControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState) {
  #include "asm/8051fc84.s"
}

// Symbol: setDpdEnabled__Q26System17KPadWiiControllerFb
// PAL: 0x8051ffb8..0x8051ffd0
MARK_BINARY_BLOB(setDpdEnabled__Q26System17KPadWiiControllerFb, 0x8051ffb8, 0x8051ffd0);
asm UNKNOWN_FUNCTION(setDpdEnabled__Q26System17KPadWiiControllerFb) {
  #include "asm/8051ffb8.s"
}

// Symbol: __ct__Q26System16KPadGCControllerFv
// PAL: 0x8051ffd0..0x80520118
MARK_BINARY_BLOB(__ct__Q26System16KPadGCControllerFv, 0x8051ffd0, 0x80520118);
asm UNKNOWN_FUNCTION(__ct__Q26System16KPadGCControllerFv) {
  #include "asm/8051ffd0.s"
}

// Symbol: reset__Q26System16KPadGCControllerFb
// PAL: 0x80520118..0x805201b0
MARK_BINARY_BLOB(reset__Q26System16KPadGCControllerFb, 0x80520118, 0x805201b0);
asm UNKNOWN_FUNCTION(reset__Q26System16KPadGCControllerFb) {
  #include "asm/80520118.s"
}

// Symbol: calcInner__Q26System16KPadGCControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState
// PAL: 0x805201b0..0x805206fc
MARK_BINARY_BLOB(calcInner__Q26System16KPadGCControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState, 0x805201b0, 0x805206fc);
asm UNKNOWN_FUNCTION(calcInner__Q26System16KPadGCControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState) {
  #include "asm/805201b0.s"
}

// Symbol: isRumbleEnabled__Q26System16KPadGCControllerFv
// PAL: 0x805206fc..0x80520730
MARK_BINARY_BLOB(isRumbleEnabled__Q26System16KPadGCControllerFv, 0x805206fc, 0x80520730);
asm UNKNOWN_FUNCTION(isRumbleEnabled__Q26System16KPadGCControllerFv) {
  #include "asm/805206fc.s"
}

// Symbol: __ct__Q26System19KPadGhostControllerFv
// PAL: 0x80520730..0x80520924
MARK_BINARY_BLOB(__ct__Q26System19KPadGhostControllerFv, 0x80520730, 0x80520924);
asm UNKNOWN_FUNCTION(__ct__Q26System19KPadGhostControllerFv) {
  #include "asm/80520730.s"
}

// Symbol: __dt__Q26System19KPadGhostControllerFv
// PAL: 0x80520924..0x80520998
MARK_BINARY_BLOB(__dt__Q26System19KPadGhostControllerFv, 0x80520924, 0x80520998);
asm UNKNOWN_FUNCTION(__dt__Q26System19KPadGhostControllerFv) {
  #include "asm/80520924.s"
}

// Symbol: reset__Q26System19KPadGhostControllerFb
// PAL: 0x80520998..0x80520a4c
MARK_BINARY_BLOB(reset__Q26System19KPadGhostControllerFb, 0x80520998, 0x80520a4c);
asm UNKNOWN_FUNCTION(reset__Q26System19KPadGhostControllerFb) {
  #include "asm/80520998.s"
}

// Symbol: hasGhostBuffer__Q26System19KPadGhostControllerFv
// PAL: 0x80520a4c..0x80520a60
MARK_BINARY_BLOB(hasGhostBuffer__Q26System19KPadGhostControllerFv, 0x80520a4c, 0x80520a60);
asm UNKNOWN_FUNCTION(hasGhostBuffer__Q26System19KPadGhostControllerFv) {
  #include "asm/80520a4c.s"
}

// Symbol: getStreamSize__Q26System19KPadGhostControllerFv
// PAL: 0x80520a60..0x80520b18
MARK_BINARY_BLOB(getStreamSize__Q26System19KPadGhostControllerFv, 0x80520a60, 0x80520b18);
asm UNKNOWN_FUNCTION(getStreamSize__Q26System19KPadGhostControllerFv) {
  #include "asm/80520a60.s"
}

// Symbol: readGhostBuffer__Q26System19KPadGhostControllerFPUsb
// PAL: 0x80520b18..0x80520b9c
MARK_BINARY_BLOB(readGhostBuffer__Q26System19KPadGhostControllerFPUsb, 0x80520b18, 0x80520b9c);
asm UNKNOWN_FUNCTION(readGhostBuffer__Q26System19KPadGhostControllerFPUsb) {
  #include "asm/80520b18.s"
}

// Symbol: calcInner__Q26System19KPadGhostControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState
// PAL: 0x80520b9c..0x80520d4c
MARK_BINARY_BLOB(calcInner__Q26System19KPadGhostControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState, 0x80520b9c, 0x80520d4c);
asm UNKNOWN_FUNCTION(calcInner__Q26System19KPadGhostControllerFPQ26System18KPadRaceInputStatePQ26System16KPadUIInputState) {
  #include "asm/80520b9c.s"
}

// Symbol: readFrame__Q26System26KPadDirectionButtonsStreamFv
// PAL: 0x80520d4c..0x80520eb4
MARK_BINARY_BLOB(readFrame__Q26System26KPadDirectionButtonsStreamFv, 0x80520d4c, 0x80520eb4);
asm UNKNOWN_FUNCTION(readFrame__Q26System26KPadDirectionButtonsStreamFv) {
  #include "asm/80520d4c.s"
}

// Symbol: getSequenceSize__Q26System26KPadDirectionButtonsStreamFv
// PAL: 0x80520eb4..0x80520ebc
MARK_BINARY_BLOB(getSequenceSize__Q26System26KPadDirectionButtonsStreamFv, 0x80520eb4, 0x80520ebc);
asm UNKNOWN_FUNCTION(getSequenceSize__Q26System26KPadDirectionButtonsStreamFv) {
  #include "asm/80520eb4.s"
}

// Symbol: initRumbleManagers__Q26System4KPadFv
// PAL: 0x80520ebc..0x80520f2c
MARK_BINARY_BLOB(initRumbleManagers__Q26System4KPadFv, 0x80520ebc, 0x80520f2c);
asm UNKNOWN_FUNCTION(initRumbleManagers__Q26System4KPadFv) {
  #include "asm/80520ebc.s"
}

// Symbol: setDriftIsAuto__Q26System4KPadFUs
// PAL: 0x80520f2c..0x80520f64
MARK_BINARY_BLOB(setDriftIsAuto__Q26System4KPadFUs, 0x80520f2c, 0x80520f64);
asm UNKNOWN_FUNCTION(setDriftIsAuto__Q26System4KPadFUs) {
  #include "asm/80520f2c.s"
}

// Symbol: __ct__Q26System4KPadFv
// PAL: 0x80520f64..0x80521110
MARK_BINARY_BLOB(__ct__Q26System4KPadFv, 0x80520f64, 0x80521110);
asm UNKNOWN_FUNCTION(__ct__Q26System4KPadFv) {
  #include "asm/80520f64.s"
}

// Symbol: reset__Q26System4KPadFv
// PAL: 0x80521110..0x80521198
MARK_BINARY_BLOB(reset__Q26System4KPadFv, 0x80521110, 0x80521198);
asm UNKNOWN_FUNCTION(reset__Q26System4KPadFv) {
  #include "asm/80521110.s"
}

// Symbol: calc__Q26System4KPadFb
// PAL: 0x80521198..0x80521554
MARK_BINARY_BLOB(calc__Q26System4KPadFb, 0x80521198, 0x80521554);
asm UNKNOWN_FUNCTION(calc__Q26System4KPadFb) {
  #include "asm/80521198.s"
}

// Symbol: setController__Q26System4KPadFPQ26System14KPadControllerPQ26System14KPadController
// PAL: 0x80521554..0x805215d4
MARK_BINARY_BLOB(setController__Q26System4KPadFPQ26System14KPadControllerPQ26System14KPadController, 0x80521554, 0x805215d4);
asm UNKNOWN_FUNCTION(setController__Q26System4KPadFPQ26System14KPadControllerPQ26System14KPadController) {
  #include "asm/80521554.s"
}

// Symbol: startGhostProxy__Q26System10KPadPlayerFv
// PAL: 0x805215d4..0x80521688
MARK_BINARY_BLOB(startGhostProxy__Q26System10KPadPlayerFv, 0x805215d4, 0x80521688);
asm UNKNOWN_FUNCTION(startGhostProxy__Q26System10KPadPlayerFv) {
  #include "asm/805215d4.s"
}

// Symbol: endGhostProxy__Q26System10KPadPlayerFv
// PAL: 0x80521688..0x80521768
MARK_BINARY_BLOB(endGhostProxy__Q26System10KPadPlayerFv, 0x80521688, 0x80521768);
asm UNKNOWN_FUNCTION(endGhostProxy__Q26System10KPadPlayerFv) {
  #include "asm/80521688.s"
}

// Symbol: calc__Q26System10KPadPlayerFb
// PAL: 0x80521768..0x80521844
MARK_BINARY_BLOB(calc__Q26System10KPadPlayerFb, 0x80521768, 0x80521844);
asm UNKNOWN_FUNCTION(calc__Q26System10KPadPlayerFb) {
  #include "asm/80521768.s"
}

// Symbol: setGhostController__Q26System10KPadPlayerFPQ26System14KPadControllerPQ26System14KPadControllerb
// PAL: 0x80521844..0x80521930
MARK_BINARY_BLOB(setGhostController__Q26System10KPadPlayerFPQ26System14KPadControllerPQ26System14KPadControllerb, 0x80521844, 0x80521930);
asm UNKNOWN_FUNCTION(setGhostController__Q26System10KPadPlayerFPQ26System14KPadControllerPQ26System14KPadControllerb) {
  #include "asm/80521844.s"
}

// Symbol: unk_80521930
// PAL: 0x80521930..0x805219ac
MARK_BINARY_BLOB(unk_80521930, 0x80521930, 0x805219ac);
asm UNKNOWN_FUNCTION(unk_80521930) {
  #include "asm/80521930.s"
}

// Symbol: setInputState__Q26System6KPadAIFPQ26System18KPadRaceInputState
// PAL: 0x805219ac..0x80521a34
MARK_BINARY_BLOB(setInputState__Q26System6KPadAIFPQ26System18KPadRaceInputState, 0x805219ac, 0x80521a34);
asm UNKNOWN_FUNCTION(setInputState__Q26System6KPadAIFPQ26System18KPadRaceInputState) {
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

// Symbol: isRumbleEnabled__Q26System14KPadControllerFv
// PAL: 0x80521d84..0x80521d8c
MARK_BINARY_BLOB(isRumbleEnabled__Q26System14KPadControllerFv, 0x80521d84, 0x80521d8c);
asm UNKNOWN_FUNCTION(isRumbleEnabled__Q26System14KPadControllerFv) {
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

// Symbol: startMotor__Q26System4KPadFv
// PAL: 0x80522078..0x8052208c
MARK_BINARY_BLOB(startMotor__Q26System4KPadFv, 0x80522078, 0x8052208c);
asm UNKNOWN_FUNCTION(startMotor__Q26System4KPadFv) {
  #include "asm/80522078.s"
}

// Symbol: startMotor__Q26System14KPadControllerFv
// PAL: 0x8052208c..0x80522090
MARK_BINARY_BLOB(startMotor__Q26System14KPadControllerFv, 0x8052208c, 0x80522090);
asm UNKNOWN_FUNCTION(startMotor__Q26System14KPadControllerFv) {
  #include "asm/8052208c.s"
}

// Symbol: stopMotor__Q26System4KPadFv
// PAL: 0x80522090..0x805220a4
MARK_BINARY_BLOB(stopMotor__Q26System4KPadFv, 0x80522090, 0x805220a4);
asm UNKNOWN_FUNCTION(stopMotor__Q26System4KPadFv) {
  #include "asm/80522090.s"
}

// Symbol: stopMotor__Q26System14KPadControllerFv
// PAL: 0x805220a4..0x805220a8
MARK_BINARY_BLOB(stopMotor__Q26System14KPadControllerFv, 0x805220a4, 0x805220a8);
asm UNKNOWN_FUNCTION(stopMotor__Q26System14KPadControllerFv) {
  #include "asm/805220a4.s"
}

// Symbol: stopMotorHard__Q26System4KPadFv
// PAL: 0x805220a8..0x805220bc
MARK_BINARY_BLOB(stopMotorHard__Q26System4KPadFv, 0x805220a8, 0x805220bc);
asm UNKNOWN_FUNCTION(stopMotorHard__Q26System4KPadFv) {
  #include "asm/805220a8.s"
}

// Symbol: __ct__Q26System10KPadPlayerFv
// PAL: 0x805220bc..0x805222b4
MARK_BINARY_BLOB(__ct__Q26System10KPadPlayerFv, 0x805220bc, 0x805222b4);
asm UNKNOWN_FUNCTION(__ct__Q26System10KPadPlayerFv) {
  #include "asm/805220bc.s"
}

// Symbol: __dt__Q26System4KPadFv
// PAL: 0x805222b4..0x805222f4
MARK_BINARY_BLOB(__dt__Q26System4KPadFv, 0x805222b4, 0x805222f4);
asm UNKNOWN_FUNCTION(__dt__Q26System4KPadFv) {
  #include "asm/805222b4.s"
}

// Symbol: __dt__Q26System10KPadPlayerFv
// PAL: 0x805222f4..0x80522358
MARK_BINARY_BLOB(__dt__Q26System10KPadPlayerFv, 0x805222f4, 0x80522358);
asm UNKNOWN_FUNCTION(__dt__Q26System10KPadPlayerFv) {
  #include "asm/805222f4.s"
}

// Symbol: unk_80522358
// PAL: 0x80522358..0x80522364
MARK_BINARY_BLOB(unk_80522358, 0x80522358, 0x80522364);
asm UNKNOWN_FUNCTION(unk_80522358) {
  #include "asm/80522358.s"
}

// Symbol: init__Q26System18KPadControllerInfoFPQ26System14KPadController
// PAL: 0x80522364..0x80522494
MARK_BINARY_BLOB(init__Q26System18KPadControllerInfoFPQ26System14KPadController, 0x80522364, 0x80522494);
asm UNKNOWN_FUNCTION(init__Q26System18KPadControllerInfoFPQ26System14KPadController) {
  #include "asm/80522364.s"
}

// Symbol: getChan__Q26System14KPadControllerFv
// PAL: 0x80522494..0x8052249c
MARK_BINARY_BLOB(getChan__Q26System14KPadControllerFv, 0x80522494, 0x8052249c);
asm UNKNOWN_FUNCTION(getChan__Q26System14KPadControllerFv) {
  #include "asm/80522494.s"
}

// Symbol: getDevAddr__Q36System18KPadControllerInfo4AddrFi
// PAL: 0x8052249c..0x8052250c
MARK_BINARY_BLOB(getDevAddr__Q36System18KPadControllerInfo4AddrFi, 0x8052249c, 0x8052250c);
asm UNKNOWN_FUNCTION(getDevAddr__Q36System18KPadControllerInfo4AddrFi) {
  #include "asm/8052249c.s"
}

// Symbol: __eq__Q36System18KPadControllerInfo4AddrCFRCQ36System18KPadControllerInfo4Addr
// PAL: 0x8052250c..0x805225a4
MARK_BINARY_BLOB(__eq__Q36System18KPadControllerInfo4AddrCFRCQ36System18KPadControllerInfo4Addr, 0x8052250c, 0x805225a4);
asm UNKNOWN_FUNCTION(__eq__Q36System18KPadControllerInfo4AddrCFRCQ36System18KPadControllerInfo4Addr) {
  #include "asm/8052250c.s"
}

// Symbol: __eq__Q26System18KPadControllerInfoCFRCQ26System18KPadControllerInfo
// PAL: 0x805225a4..0x80522690
MARK_BINARY_BLOB(__eq__Q26System18KPadControllerInfoCFRCQ26System18KPadControllerInfo, 0x805225a4, 0x80522690);
asm UNKNOWN_FUNCTION(__eq__Q26System18KPadControllerInfoCFRCQ26System18KPadControllerInfo) {
  #include "asm/805225a4.s"
}

// Symbol: unk_80522690
// PAL: 0x80522690..0x805226f4
MARK_BINARY_BLOB(unk_80522690, 0x80522690, 0x805226f4);
asm UNKNOWN_FUNCTION(unk_80522690) {
  #include "asm/80522690.s"
}

// Symbol: setInputState__Q26System4KPadFPQ26System18KPadRaceInputState
// PAL: 0x805226f4..0x805226f8
MARK_BINARY_BLOB(setInputState__Q26System4KPadFPQ26System18KPadRaceInputState, 0x805226f4, 0x805226f8);
asm UNKNOWN_FUNCTION(setInputState__Q26System4KPadFPQ26System18KPadRaceInputState) {
  #include "asm/805226f4.s"
}

// Symbol: getRecordedBufferSize__Q26System10KPadPlayerFv
// PAL: 0x805226f8..0x80522700
MARK_BINARY_BLOB(getRecordedBufferSize__Q26System10KPadPlayerFv, 0x805226f8, 0x80522700);
asm UNKNOWN_FUNCTION(getRecordedBufferSize__Q26System10KPadPlayerFv) {
  #include "asm/805226f8.s"
}

// Symbol: getRecordedBuffer__Q26System10KPadPlayerFv
// PAL: 0x80522700..0x80522708
MARK_BINARY_BLOB(getRecordedBuffer__Q26System10KPadPlayerFv, 0x80522700, 0x80522708);
asm UNKNOWN_FUNCTION(getRecordedBuffer__Q26System10KPadPlayerFv) {
  #include "asm/80522700.s"
}

// Symbol: reset__Q26System10KPadPlayerFv
// PAL: 0x80522708..0x8052279c
MARK_BINARY_BLOB(reset__Q26System10KPadPlayerFv, 0x80522708, 0x8052279c);
asm UNKNOWN_FUNCTION(reset__Q26System10KPadPlayerFv) {
  #include "asm/80522708.s"
}

// Symbol: __dt__Q26System6KPadAIFv
// PAL: 0x8052279c..0x805227dc
MARK_BINARY_BLOB(__dt__Q26System6KPadAIFv, 0x8052279c, 0x805227dc);
asm UNKNOWN_FUNCTION(__dt__Q26System6KPadAIFv) {
  #include "asm/8052279c.s"
}

// Symbol: __dt__Q26System16KPadAIControllerFv
// PAL: 0x805227dc..0x8052281c
MARK_BINARY_BLOB(__dt__Q26System16KPadAIControllerFv, 0x805227dc, 0x8052281c);
asm UNKNOWN_FUNCTION(__dt__Q26System16KPadAIControllerFv) {
  #include "asm/805227dc.s"
}

// Symbol: isDpdEnabled__Q26System14KPadControllerFv
// PAL: 0x8052281c..0x80522824
MARK_BINARY_BLOB(isDpdEnabled__Q26System14KPadControllerFv, 0x8052281c, 0x80522824);
asm UNKNOWN_FUNCTION(isDpdEnabled__Q26System14KPadControllerFv) {
  #include "asm/8052281c.s"
}

// Symbol: setDpdEnabled__Q26System14KPadControllerFb
// PAL: 0x80522824..0x80522828
MARK_BINARY_BLOB(setDpdEnabled__Q26System14KPadControllerFb, 0x80522824, 0x80522828);
asm UNKNOWN_FUNCTION(setDpdEnabled__Q26System14KPadControllerFb) {
  #include "asm/80522824.s"
}

// Symbol: setDriftIsAuto__Q26System19KPadGhostControllerFb
// PAL: 0x80522828..0x8052282c
MARK_BINARY_BLOB(setDriftIsAuto__Q26System19KPadGhostControllerFb, 0x80522828, 0x8052282c);
asm UNKNOWN_FUNCTION(setDriftIsAuto__Q26System19KPadGhostControllerFb) {
  #include "asm/80522828.s"
}

// Symbol: getControlSource__Q26System19KPadGhostControllerFv
// PAL: 0x8052282c..0x80522834
MARK_BINARY_BLOB(getControlSource__Q26System19KPadGhostControllerFv, 0x8052282c, 0x80522834);
asm UNKNOWN_FUNCTION(getControlSource__Q26System19KPadGhostControllerFv) {
  #include "asm/8052282c.s"
}

// Symbol: getStreamSize__Q26System14KPadControllerFv
// PAL: 0x80522834..0x80522840
MARK_BINARY_BLOB(getStreamSize__Q26System14KPadControllerFv, 0x80522834, 0x80522840);
asm UNKNOWN_FUNCTION(getStreamSize__Q26System14KPadControllerFv) {
  #include "asm/80522834.s"
}

// Symbol: stopMotorHard__Q26System16KPadGCControllerFv
// PAL: 0x80522840..0x8052284c
MARK_BINARY_BLOB(stopMotorHard__Q26System16KPadGCControllerFv, 0x80522840, 0x8052284c);
asm UNKNOWN_FUNCTION(stopMotorHard__Q26System16KPadGCControllerFv) {
  #include "asm/80522840.s"
}

// Symbol: stopMotor__Q26System16KPadGCControllerFv
// PAL: 0x8052284c..0x80522858
MARK_BINARY_BLOB(stopMotor__Q26System16KPadGCControllerFv, 0x8052284c, 0x80522858);
asm UNKNOWN_FUNCTION(stopMotor__Q26System16KPadGCControllerFv) {
  #include "asm/8052284c.s"
}

// Symbol: startMotor__Q26System16KPadGCControllerFv
// PAL: 0x80522858..0x80522864
MARK_BINARY_BLOB(startMotor__Q26System16KPadGCControllerFv, 0x80522858, 0x80522864);
asm UNKNOWN_FUNCTION(startMotor__Q26System16KPadGCControllerFv) {
  #include "asm/80522858.s"
}

// Symbol: getChan__Q26System16KPadGCControllerFv
// PAL: 0x80522864..0x8052286c
MARK_BINARY_BLOB(getChan__Q26System16KPadGCControllerFv, 0x80522864, 0x8052286c);
asm UNKNOWN_FUNCTION(getChan__Q26System16KPadGCControllerFv) {
  #include "asm/80522864.s"
}

// Symbol: getControlSource__Q26System16KPadGCControllerFv
// PAL: 0x8052286c..0x80522874
MARK_BINARY_BLOB(getControlSource__Q26System16KPadGCControllerFv, 0x8052286c, 0x80522874);
asm UNKNOWN_FUNCTION(getControlSource__Q26System16KPadGCControllerFv) {
  #include "asm/8052286c.s"
}

// Symbol: __dt__Q26System16KPadGCControllerFv
// PAL: 0x80522874..0x805228b4
MARK_BINARY_BLOB(__dt__Q26System16KPadGCControllerFv, 0x80522874, 0x805228b4);
asm UNKNOWN_FUNCTION(__dt__Q26System16KPadGCControllerFv) {
  #include "asm/80522874.s"
}

// Symbol: stopMotorHard__Q26System17KPadWiiControllerFv
// PAL: 0x805228b4..0x805228c4
MARK_BINARY_BLOB(stopMotorHard__Q26System17KPadWiiControllerFv, 0x805228b4, 0x805228c4);
asm UNKNOWN_FUNCTION(stopMotorHard__Q26System17KPadWiiControllerFv) {
  #include "asm/805228b4.s"
}

// Symbol: stopMotor__Q26System17KPadWiiControllerFv
// PAL: 0x805228c4..0x805228d0
MARK_BINARY_BLOB(stopMotor__Q26System17KPadWiiControllerFv, 0x805228c4, 0x805228d0);
asm UNKNOWN_FUNCTION(stopMotor__Q26System17KPadWiiControllerFv) {
  #include "asm/805228c4.s"
}

// Symbol: startMotor__Q26System17KPadWiiControllerFv
// PAL: 0x805228d0..0x805228dc
MARK_BINARY_BLOB(startMotor__Q26System17KPadWiiControllerFv, 0x805228d0, 0x805228dc);
asm UNKNOWN_FUNCTION(startMotor__Q26System17KPadWiiControllerFv) {
  #include "asm/805228d0.s"
}

// Symbol: isRumbleEnabled__Q26System17KPadWiiControllerFv
// PAL: 0x805228dc..0x805228f4
MARK_BINARY_BLOB(isRumbleEnabled__Q26System17KPadWiiControllerFv, 0x805228dc, 0x805228f4);
asm UNKNOWN_FUNCTION(isRumbleEnabled__Q26System17KPadWiiControllerFv) {
  #include "asm/805228dc.s"
}

// Symbol: isDpdEnabled__Q26System17KPadWiiControllerFv
// PAL: 0x805228f4..0x80522924
MARK_BINARY_BLOB(isDpdEnabled__Q26System17KPadWiiControllerFv, 0x805228f4, 0x80522924);
asm UNKNOWN_FUNCTION(isDpdEnabled__Q26System17KPadWiiControllerFv) {
  #include "asm/805228f4.s"
}

// Symbol: getChan__Q26System17KPadWiiControllerFv
// PAL: 0x80522924..0x8052292c
MARK_BINARY_BLOB(getChan__Q26System17KPadWiiControllerFv, 0x80522924, 0x8052292c);
asm UNKNOWN_FUNCTION(getChan__Q26System17KPadWiiControllerFv) {
  #include "asm/80522924.s"
}

// Symbol: getControlSource__Q26System17KPadWiiControllerFv
// PAL: 0x8052292c..0x80522934
MARK_BINARY_BLOB(getControlSource__Q26System17KPadWiiControllerFv, 0x8052292c, 0x80522934);
asm UNKNOWN_FUNCTION(getControlSource__Q26System17KPadWiiControllerFv) {
  #include "asm/8052292c.s"
}

// Symbol: __dt__Q26System17KPadWiiControllerFv
// PAL: 0x80522934..0x80522974
MARK_BINARY_BLOB(__dt__Q26System17KPadWiiControllerFv, 0x80522934, 0x80522974);
asm UNKNOWN_FUNCTION(__dt__Q26System17KPadWiiControllerFv) {
  #include "asm/80522934.s"
}

// Symbol: writeFrame__Q26System26KPadDirectionButtonsStreamFUc
// PAL: 0x80522974..0x80522ae8
MARK_BINARY_BLOB(writeFrame__Q26System26KPadDirectionButtonsStreamFUc, 0x80522974, 0x80522ae8);
asm UNKNOWN_FUNCTION(writeFrame__Q26System26KPadDirectionButtonsStreamFUc) {
  #include "asm/80522974.s"
}

// Symbol: writeFrame__Q26System18KPadTrickButtonsStreamFUc
// PAL: 0x80522ae8..0x80522c5c
MARK_BINARY_BLOB(writeFrame__Q26System18KPadTrickButtonsStreamFUc, 0x80522ae8, 0x80522c5c);
asm UNKNOWN_FUNCTION(writeFrame__Q26System18KPadTrickButtonsStreamFUc) {
  #include "asm/80522ae8.s"
}

// Symbol: readFrame__Q26System18KPadTrickButtonsStreamFv
// PAL: 0x80522c5c..0x80522dc4
MARK_BINARY_BLOB(readFrame__Q26System18KPadTrickButtonsStreamFv, 0x80522c5c, 0x80522dc4);
asm UNKNOWN_FUNCTION(readFrame__Q26System18KPadTrickButtonsStreamFv) {
  #include "asm/80522c5c.s"
}

// Symbol: getSequenceSize__Q26System18KPadTrickButtonsStreamFv
// PAL: 0x80522dc4..0x80522dcc
MARK_BINARY_BLOB(getSequenceSize__Q26System18KPadTrickButtonsStreamFv, 0x80522dc4, 0x80522dcc);
asm UNKNOWN_FUNCTION(getSequenceSize__Q26System18KPadTrickButtonsStreamFv) {
  #include "asm/80522dc4.s"
}

// Symbol: writeFrame__Q26System17KPadFaceButtonsStreamFUc
// PAL: 0x80522dcc..0x80522f40
MARK_BINARY_BLOB(writeFrame__Q26System17KPadFaceButtonsStreamFUc, 0x80522dcc, 0x80522f40);
asm UNKNOWN_FUNCTION(writeFrame__Q26System17KPadFaceButtonsStreamFUc) {
  #include "asm/80522dcc.s"
}

// Symbol: readFrame__Q26System17KPadFaceButtonsStreamFv
// PAL: 0x80522f40..0x805230a8
MARK_BINARY_BLOB(readFrame__Q26System17KPadFaceButtonsStreamFv, 0x80522f40, 0x805230a8);
asm UNKNOWN_FUNCTION(readFrame__Q26System17KPadFaceButtonsStreamFv) {
  #include "asm/80522f40.s"
}

// Symbol: getSequenceSize__Q26System17KPadFaceButtonsStreamFv
// PAL: 0x805230a8..0x805230b0
MARK_BINARY_BLOB(getSequenceSize__Q26System17KPadFaceButtonsStreamFv, 0x805230a8, 0x805230b0);
asm UNKNOWN_FUNCTION(getSequenceSize__Q26System17KPadFaceButtonsStreamFv) {
  #include "asm/805230a8.s"
}

// Symbol: __sinit__KPadController_cpp
// PAL: 0x805230b0..0x805230e0
MARK_BINARY_BLOB(__sinit__KPadController_cpp, 0x805230b0, 0x805230e0);
asm UNKNOWN_FUNCTION(__sinit__KPadController_cpp) {
  #include "asm/805230b0.s"
}
