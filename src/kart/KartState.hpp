#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <kart/KartObjectProxy.hpp>
#include <system/RKBitField.hpp>
#include <system/RaceConfig.hpp>
#include <system/RaceManager.hpp>

namespace Kart {

enum KartFlags {
  KART_FLAG_HOPPING = 3,
  KART_FLAG_ALL_WHEELS_COLLISION = 15,
  KART_FLAG_STICKY_ROAD = 16,
  KART_FLAG_TOUCHING_GROUND = 18,
  KART_FLAG_AUTO_DRIFT = 19,
  KART_FLAG_LARGE_FLIP_HIT = 25,
  KART_FLAG_IN_BULLET = 28,
  KART_FLAG_JUMPPAD = 30,
  KART_FLAG_CANNON_START = 35,
  KART_FLAG_IN_CANNON = 36,
  KART_FLAG_HALFPIPE_RAMP = 41,
  KART_FLAG_AT_SUSP_LIMIT = 51,
  /// Used for bouncy mushrooms
  KART_FLAG_JUMPPAD_VELY_INCREASE = 55,
  KART_FLAG_REJECT_ROAD = 59,
  KART_FLAG_DRIFTING_ON_GROUND = 61,
  KART_FLAG_HALFPIPE_RAMP_LOCAL = 0x43,
  KART_FLAG_WHEELIE_ROT = 0x44,
  KART_FLAG_SKIP_WHEEL_CALC = 0x45,
  KART_FLAG_DISABLE_Y_SUS_FORCE = 0x56,
  KART_FLAG_HALFPIPE_MIDAIR = 0x57,
  KART_FLAG_COL_INVISIBILITY = 0x59,
  KART_FLAG_IN_A_BULLET = 0x5b,
  KART_FLAG_STH_61 = 0x61,
  KART_FLAG_STH_WALL_COL = 0x63,
  KART_FLAG_STH_KILLER = 0x6a,
  KART_FLAG_CPU = 0x80,
  KART_FLAG_LOCAL = 0x81,
  KART_FLAG_ONLINE_LOCAL = 0x82,
  KART_FLAG_ONLINE_REMOTE = 0x83,
  KART_FLAG_AUTOMATIC_DRIFT = 0x84,
  KART_FLAG_GHOST = 0x86,
  KART_FLAG_SET_SPEED_ZERO = 0x89,
  KART_FLAG_DEMO_LOSS = 0x8b,
};

class KartState {
public:
  KartState(KartSettings* settings);
  virtual ~KartState();
  void init();
  void reset();
  void resetOob();
  void startWipe(int wipeState);
  void resetCollisionFlags();

  bool on(size_t n) const {
    return mFlags.on(n);
  }
  void set(size_t n) { mFlags.set(n); }
  void reset(size_t n) { mFlags.reset(n); }
  u32& field(size_t n) { return mFlags.field(n); }

  void setCannonPointId(s32 id) { mCannonPointId = id; }
  void setBoostRampType(s32 type) { mBoostRampType = type; }
  void setJumpPadType(s32 type) { mJumpPadType = type; }
  void setHalfpipeInvisibilityTimer(s32 timer) { mHalfpipeInvisibilityTimer = timer; }

private:
  RKBitField<160> mFlags;
  KartObjectProxy* mProxy;
  u32 mAirtime;
  u8 _20[0x24 - 0x20];
  f32 _24;
  EGG::Vector3f mUp;
  u8 _34[0x40 - 0x34];
  EGG::Vector3f _40;
  EGG::Vector3f _4c;
  u32 _58;
  u32 _5c;
  u8 _60[0x6c - 0x60];
  u32 mHwgTimer;
  u32 m_70;
  s32 mBoostRampType;
  s32 mJumpPadType;
  f32 _7c;
  u32 mCannonPointId;
  u8 _84[0x86 - 0x84];
  s16 mHalfpipeInvisibilityTimer;
  EGG::Vector2f mStick;
  int mWipeState;
  s16 mWipeFrame;
  u8 _96[0x9c - 0x96];
  f32 mStartBoostCharge;
  s32 mStartBoostIdx;
  u16 _a4;
  u16 _a6;
  EGG::Vector3f m_a8;
  u8 _b4[0xc0 - 0xb4];
};
static_assert(sizeof(KartState) == 0xc0);

} // namespace Kart
