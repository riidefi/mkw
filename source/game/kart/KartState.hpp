#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <game/kart/KartObjectProxy.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x805943b4..0x8059455c
UNKNOWN_FUNCTION(PlayerSub1c_construct);
// PAL: 0x8059455c..0x80594594
UNKNOWN_FUNCTION(unk_8059455c);
// PAL: 0x80594594..0x80594634
UNKNOWN_FUNCTION(reset__Q24Kart9KartStateFv);
// PAL: 0x80594634..0x80594644
UNKNOWN_FUNCTION(resetOob__Q24Kart9KartStateFv);
// PAL: 0x80594644..0x805946f4
UNKNOWN_FUNCTION(unk_80594644);
// PAL: 0x805946f4..0x80594704
UNKNOWN_FUNCTION(PlayerSub1c_startOobWipe);
// PAL: 0x80594704..0x8059474c
UNKNOWN_FUNCTION(unk_80594704);
// PAL: 0x8059474c..0x8059487c
UNKNOWN_FUNCTION(PlayerSub1c_updateCollisionsAndMore);
// PAL: 0x8059487c..0x80594bd4
UNKNOWN_FUNCTION(PlayerSub1c_updateFromInput);
// PAL: 0x80594bd4..0x805958ec
UNKNOWN_FUNCTION(PlayerSub1c_updateCollisions);
// PAL: 0x805958ec..0x805958f0
UNKNOWN_FUNCTION(unk_805958ec);
// PAL: 0x805958f0..0x80595918
UNKNOWN_FUNCTION(unk_805958f0);
// PAL: 0x80595918..0x805959d4
UNKNOWN_FUNCTION(PlayerSub1c_updateStartBoostCharge);
// PAL: 0x805959d4..0x80595af8
UNKNOWN_FUNCTION(PlayerSub1c_computeStartBoost);
// PAL: 0x80595af8..0x80595c5c
UNKNOWN_FUNCTION(PlayerSub1c_applyStartBoost);
// PAL: 0x80595c5c..0x80595ca4
UNKNOWN_FUNCTION(unk_80595c5c);
// PAL: 0x80595ca4..0x80595cb4
UNKNOWN_FUNCTION(unk_80595ca4);
// PAL: 0x80595cb4..0x80595cc4
UNKNOWN_FUNCTION(unk_80595cb4);
// PAL: 0x80595cc4..0x80595d04
UNKNOWN_FUNCTION(PlayerSub1c_destroy);

#ifdef __cplusplus
}
#endif

namespace Kart {

namespace KartFlags {

// We never reference this enum directly, we only reference the values
enum _KartFlags {};

} // namespace KartFlags

class KartState {
public:
  void init();
  void reset();
  void resetOob();
  void startWipe(int wipeState);
  void resetCollisionFlags();

private:
  u8 _00[0x04 - 0x00];
  RKBitField<160> mFlags;
  KartObjectProxy* mProxy;
  u32 mAirtime;
  u8 _20[0x24 - 0x20];
  f32 m_24;
  EGG::Vector3f mTop;
  u8 _34[0x40 - 0x34];
  EGG::Vector3f _40;
  EGG::Vector3f m_4c;
  u32 _58;
  u32 _5c;
  u8 _60[0x6c - 0x60];
  u32 mHwgTimer;
  u32 m_70;
  s32 mBoostRampType;
  s32 mJumpPadType;
  u8 _7c[0x84 - 0x7c];
  u16 m_84;
  EGG::Vector2f mStick;
  int mWipeState;
  s16 mWipeFrame;
  u8 _96[0x9c - 0x96];
  f32 mStartBoostCharge;
  u8 _a0[0xa4 - 0xa0];
  u16 m_a4;
  u16 m_a6;
  EGG::Vector3f m_a8;
  u8 _b4[0xc0 - 0xb4];
};
static_assert(sizeof(KartState) == 0xc0);

} // namespace Kart
