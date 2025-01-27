#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80590128..0x80590138
UNKNOWN_FUNCTION(InitList__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590138..0x8059018c
UNKNOWN_FUNCTION(SetupInList__Q24Kart15KartObjectProxyFPQ24Kart12KartAccessor);
// PAL: 0x8059018c..0x805901d0
UNKNOWN_FUNCTION(__ct__Q24Kart15KartObjectProxyFv);
// PAL: 0x805901d0..0x8059020c
UNKNOWN_FUNCTION(setupSingle);
// PAL: 0x8059020c..0x80590224
UNKNOWN_FUNCTION(getPos__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590224..0x80590238
UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysicsHolderPosition);
// PAL: 0x80590238..0x80590264
UNKNOWN_FUNCTION(various_stuff_set_player_position);
// PAL: 0x80590264..0x80590278
UNKNOWN_FUNCTION(PlayerPointers_getMat);
// PAL: 0x80590278..0x80590288
UNKNOWN_FUNCTION(unk_80590278);
// PAL: 0x80590288..0x805902dc
UNKNOWN_FUNCTION(various_stuff_set_player_rotation);
// PAL: 0x805902dc..0x805902ec
UNKNOWN_FUNCTION(PlayerPointers_getWheelCount0);
// PAL: 0x805902ec..0x805902fc
UNKNOWN_FUNCTION(PlayerPointers_getWheelCount1);
// PAL: 0x805902fc..0x8059030c
UNKNOWN_FUNCTION(unk_805902fc);
// PAL: 0x8059030c..0x8059031c
UNKNOWN_FUNCTION(unk_8059030c);
// PAL: 0x8059031c..0x80590338
UNKNOWN_FUNCTION(unk_8059031c);
// PAL: 0x80590338..0x80590350
UNKNOWN_FUNCTION(unk_80590338);
// PAL: 0x80590350..0x80590368
UNKNOWN_FUNCTION(unk_80590350);
// PAL: 0x80590368..0x80590380
UNKNOWN_FUNCTION(unk_80590368);
// PAL: 0x80590380..0x80590390
UNKNOWN_FUNCTION(unk_80590380);
// PAL: 0x80590390..0x805903ac
UNKNOWN_FUNCTION(unk_80590390);
// PAL: 0x805903ac..0x805903bc
UNKNOWN_FUNCTION(kartPhysics__Q24Kart15KartObjectProxyFv);
// PAL: 0x805903bc..0x805903cc
UNKNOWN_FUNCTION(kartPhysics__Q24Kart15KartObjectProxyCFv);
// PAL: 0x805903cc..0x805903e0
UNKNOWN_FUNCTION(kartDynamics__Q24Kart15KartObjectProxyFv);
// PAL: 0x805903e0..0x805903f4
UNKNOWN_FUNCTION(kartDynamics__Q24Kart15KartObjectProxyCFv);
// PAL: 0x805903f4..0x8059041c
UNKNOWN_FUNCTION(KartAccessor_getInput);
// PAL: 0x8059041c..0x80590478
UNKNOWN_FUNCTION(unk_8059041c);
// PAL: 0x80590478..0x80590570
UNKNOWN_FUNCTION(unk_80590478);
// PAL: 0x80590570..0x80590650
UNKNOWN_FUNCTION(unk_80590570);
// PAL: 0x80590650..0x80590664
UNKNOWN_FUNCTION(PlayerPointers_isReal);
// PAL: 0x80590664..0x80590678
UNKNOWN_FUNCTION(PlayerPointers_isCpu);
// PAL: 0x80590678..0x8059068c
UNKNOWN_FUNCTION(PlayerPointers_isGhost);
// PAL: 0x8059068c..0x8059069c
UNKNOWN_FUNCTION(PlayerModel_isMii);
// PAL: 0x8059069c..0x805906a8
UNKNOWN_FUNCTION(kartBody__Q24Kart15KartObjectProxyFv);
// PAL: 0x805906a8..0x805906b4
UNKNOWN_FUNCTION(kartBody__Q24Kart15KartObjectProxyCFv);
// PAL: 0x805906b4..0x805906c8
UNKNOWN_FUNCTION(kartSus__Q24Kart15KartObjectProxyFl);
// PAL: 0x805906c8..0x805906dc
UNKNOWN_FUNCTION(kartSus__Q24Kart15KartObjectProxyCFl);
// PAL: 0x80590704..0x8059071c
UNKNOWN_FUNCTION(PlayerPointers_getWheelPhysicsHolder);
// PAL: 0x8059071c..0x80590734
UNKNOWN_FUNCTION(unk_8059071c);
// PAL: 0x80590734..0x8059074c
UNKNOWN_FUNCTION(PlayerPointers_getWheelPhysics);
// PAL: 0x8059074c..0x80590764
UNKNOWN_FUNCTION(unk_8059074c);
// PAL: 0x80590764..0x80590770
UNKNOWN_FUNCTION(kartPhysicsEngine__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590770..0x8059077c
UNKNOWN_FUNCTION(kartPhysicsEngine__Q24Kart15KartObjectProxyCFv);
// PAL: 0x8059077c..0x80590788
UNKNOWN_FUNCTION(kartMove__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590788..0x80590794
UNKNOWN_FUNCTION(kartMove__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590794..0x805907a0
UNKNOWN_FUNCTION(kartSnd__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907a0..0x805907b0
UNKNOWN_FUNCTION(unk_805907a0);
// PAL: 0x805907b0..0x805907c0
UNKNOWN_FUNCTION(unk_805907b0);
// PAL: 0x805907c0..0x805907cc
UNKNOWN_FUNCTION(kartAccessor_34__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907cc..0x805907d8
UNKNOWN_FUNCTION(maybeShadow__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907d8..0x805907ec
UNKNOWN_FUNCTION(hitboxGroup__Q24Kart15KartObjectProxyFv);
// PAL: 0x805907ec..0x80590800
UNKNOWN_FUNCTION(hitboxGroup__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590800..0x8059081c
UNKNOWN_FUNCTION(wheelHitbox__Q24Kart15KartObjectProxyCFl);
// PAL: 0x8059081c..0x80590834
UNKNOWN_FUNCTION(bodyColInfo__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590834..0x8059084c
UNKNOWN_FUNCTION(wheelColInfo__Q24Kart15KartObjectProxyCFl);
// PAL: 0x8059084c..0x80590858
UNKNOWN_FUNCTION(kartCollide__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590858..0x80590864
UNKNOWN_FUNCTION(kartCollide__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590864..0x80590874
UNKNOWN_FUNCTION(kartParam__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590874..0x80590888
UNKNOWN_FUNCTION(processFloor__Q24Kart11KartCollideFRQ24Kart17KartCollisionInfoRCQ24Kart6HitboxRCQ25Field7ColInfoPUlb);
// PAL: 0x80590888..0x8059089c
UNKNOWN_FUNCTION(bsp__Q24Kart15KartObjectProxyCFv);
// PAL: 0x8059089c..0x805908b4
UNKNOWN_FUNCTION(bspHitboxes__Q24Kart15KartObjectProxyCFv);
// PAL: 0x805908b4..0x805908d4
UNKNOWN_FUNCTION(bspWheel__Q24Kart15KartObjectProxyCFl);
// PAL: 0x805908d4..0x805908e4
UNKNOWN_FUNCTION(unk_805908d4);
// PAL: 0x805908e4..0x805908f4
UNKNOWN_FUNCTION(PlayerPointers_getKartDriverDispParams);
// PAL: 0x805908f4..0x8059090c
UNKNOWN_FUNCTION(unk_805908f4);
// PAL: 0x8059090c..0x8059091c
UNKNOWN_FUNCTION(various_stuff_get_kart_parts_disp_params);
// PAL: 0x8059091c..0x8059092c
UNKNOWN_FUNCTION(various_stuff_get_bike_parts_disp_params);
// PAL: 0x8059092c..0x80590958
UNKNOWN_FUNCTION(unk_8059092c);
// PAL: 0x80590958..0x8059098c
UNKNOWN_FUNCTION(unk_80590958);
// PAL: 0x8059098c..0x805909b8
UNKNOWN_FUNCTION(unk_8059098c);
// PAL: 0x805909b8..0x805909c8
UNKNOWN_FUNCTION(unk_805909b8);
// PAL: 0x805909c8..0x805909f4
UNKNOWN_FUNCTION(unk_805909c8);
// PAL: 0x805909f4..0x80590a04
UNKNOWN_FUNCTION(getHopStickX__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590a04..0x80590a10
UNKNOWN_FUNCTION(getAppliedHopStickX__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590a10..0x80590a28
UNKNOWN_FUNCTION(PlayerPointers_getVehicleType);
// PAL: 0x80590a28..0x80590a40
UNKNOWN_FUNCTION(unk_80590a28);
// PAL: 0x80590a40..0x80590a4c
UNKNOWN_FUNCTION(kartModel__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590a4c..0x80590a5c
UNKNOWN_FUNCTION(unk_80590a4c);
// PAL: 0x80590a5c..0x80590a6c
UNKNOWN_FUNCTION(getPlayerIdx__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590a6c..0x80590a7c
UNKNOWN_FUNCTION(PlayerPointers_isBike);
// PAL: 0x80590a7c..0x80590a8c
UNKNOWN_FUNCTION(PlayerPointers_getVehicle);
// PAL: 0x80590a8c..0x80590a9c
UNKNOWN_FUNCTION(unk_80590a8c);
// PAL: 0x80590a9c..0x80590c44
UNKNOWN_FUNCTION(unk_80590a9c);
// PAL: 0x80590c44..0x80590c6c
UNKNOWN_FUNCTION(PlayerPointers_getPlayerMatCol0);
// PAL: 0x80590c6c..0x80590c94
UNKNOWN_FUNCTION(unk_80590c6c);
// PAL: 0x80590c94..0x80590cbc
UNKNOWN_FUNCTION(PlayerPointers_getBodyFront);
// PAL: 0x80590cbc..0x80590cd0
UNKNOWN_FUNCTION(unk_80590cbc);
// PAL: 0x80590cd0..0x80590ce4
UNKNOWN_FUNCTION(unk_80590cd0);
// PAL: 0x80590ce4..0x80590cf8
UNKNOWN_FUNCTION(PlayerPointers_getMalCol2);
// PAL: 0x80590cf8..0x80590d08
UNKNOWN_FUNCTION(getVehicleSpeed__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590d08..0x80590d20
UNKNOWN_FUNCTION(playerPointers_getSpeed);
// PAL: 0x80590d20..0x80590d2c
UNKNOWN_FUNCTION(kartAction__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590d2c..0x80590d38
UNKNOWN_FUNCTION(kartAction__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590d38..0x80590d5c
UNKNOWN_FUNCTION(unk_80590d38);
// PAL: 0x80590d5c..0x80590d88
UNKNOWN_FUNCTION(unk_80590d5c);
// PAL: 0x80590d88..0x80590d94
UNKNOWN_FUNCTION(unk_80590d88);
// PAL: 0x80590d94..0x80590da4
UNKNOWN_FUNCTION(empty__Q24Kart15KartObjectProxyFs);
// PAL: 0x80590da4..0x80590db4
UNKNOWN_FUNCTION(unk_80590da4);
// PAL: 0x80590db4..0x80590dc0
UNKNOWN_FUNCTION(clearBoost__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590dc0..0x80590dd0
UNKNOWN_FUNCTION(getSpeedRatioCapped__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590dd0..0x80590de0
UNKNOWN_FUNCTION(getSpeedRatio__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590de0..0x80590df8
UNKNOWN_FUNCTION(hasCamera__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590df8..0x80590e04
UNKNOWN_FUNCTION(setCamera__Q24Kart15KartObjectProxyFPQ24Kart10KartCamera);
// PAL: 0x80590e04..0x80590e28
UNKNOWN_FUNCTION(unk_80590e04);
// PAL: 0x80590e28..0x80590e40
UNKNOWN_FUNCTION(unk_80590e28);
// PAL: 0x80590e40..0x80590e58
UNKNOWN_FUNCTION(unk_80590e40);
// PAL: 0x80590e58..0x80590e70
UNKNOWN_FUNCTION(unk_80590e58);
// PAL: 0x80590e70..0x80590e88
UNKNOWN_FUNCTION(unk_80590e70);
// PAL: 0x80590e88..0x80590e8c
UNKNOWN_FUNCTION(empty__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590e8c..0x80590ea4
UNKNOWN_FUNCTION(unk_80590e8c);
// PAL: 0x80590ea4..0x80590ed8
UNKNOWN_FUNCTION(unk_80590ea4);
// PAL: 0x80590ed8..0x80590ef8
UNKNOWN_FUNCTION(unk_80590ed8);
// PAL: 0x80590ef8..0x80590f18
UNKNOWN_FUNCTION(unk_80590ef8);
// PAL: 0x80590f18..0x80590f38
UNKNOWN_FUNCTION(unk_80590f18);
// PAL: 0x80590f38..0x80590f58
UNKNOWN_FUNCTION(unk_80590f38);
// PAL: 0x80590f58..0x80590f70
UNKNOWN_FUNCTION(unk_80590f58);
// PAL: 0x80590f70..0x80590f90
UNKNOWN_FUNCTION(unk_80590f70);
// PAL: 0x80590f90..0x80590f9c
UNKNOWN_FUNCTION(unk_80590f90);
// PAL: 0x80590f9c..0x8059102c
UNKNOWN_FUNCTION(unk_80590f9c);
// PAL: 0x8059102c..0x80591038
UNKNOWN_FUNCTION(unk_8059102c);
// PAL: 0x80591038..0x80591044
UNKNOWN_FUNCTION(unk_80591038);
// PAL: 0x80591044..0x80591050
UNKNOWN_FUNCTION(unk_80591044);
// PAL: 0x80591050..0x80591070
UNKNOWN_FUNCTION(unk_80591050);
// PAL: 0x80591070..0x8059107c
UNKNOWN_FUNCTION(kartAccessor_54__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059107c..0x8059108c
UNKNOWN_FUNCTION(unk_8059107c);
// PAL: 0x8059108c..0x80591098
UNKNOWN_FUNCTION(kartBlink__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591098..0x805910a4
UNKNOWN_FUNCTION(kartBlink__Q24Kart15KartObjectProxyCFv);
// PAL: 0x805910a4..0x805910b0
UNKNOWN_FUNCTION(kartAccessor_5c__Q24Kart15KartObjectProxyFv);
// PAL: 0x805910b0..0x805910c0
UNKNOWN_FUNCTION(getBaseSpeed__Q24Kart15KartObjectProxyFv);
// PAL: 0x805910c0..0x805910cc
UNKNOWN_FUNCTION(kartEnemy__Q24Kart15KartObjectProxyFv);
// PAL: 0x805910cc..0x805910e4
UNKNOWN_FUNCTION(unk_805910cc);
// PAL: 0x805910e4..0x805910fc
UNKNOWN_FUNCTION(unk_805910e4);
// PAL: 0x805910fc..0x80591138
UNKNOWN_FUNCTION(unk_805910fc);
// PAL: 0x80591138..0x80591170
UNKNOWN_FUNCTION(unk_80591138);
// PAL: 0x80591170..0x805911a8
UNKNOWN_FUNCTION(unk_80591170);
// PAL: 0x805911a8..0x805911c0
UNKNOWN_FUNCTION(unk_805911a8);
// PAL: 0x805911c0..0x805911d8
UNKNOWN_FUNCTION(unk_805911c0);
// PAL: 0x805911d8..0x805911e8
UNKNOWN_FUNCTION(getDriftState__Q24Kart15KartObjectProxyFv);
// PAL: 0x805911e8..0x805911f8
UNKNOWN_FUNCTION(getMtCharge__Q24Kart15KartObjectProxyFv);
// PAL: 0x805911f8..0x80591208
UNKNOWN_FUNCTION(getSmtCharge__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591208..0x80591214
UNKNOWN_FUNCTION(getMaxMtCharge__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591214..0x80591220
UNKNOWN_FUNCTION(getMaxSmtCharge__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591220..0x80591264
UNKNOWN_FUNCTION(unk_80591220);
// PAL: 0x80591264..0x80591314
UNKNOWN_FUNCTION(unk_80591264);
// PAL: 0x80591314..0x80591344
UNKNOWN_FUNCTION(unk_80591314);
// PAL: 0x80591344..0x80591378
UNKNOWN_FUNCTION(unk_80591344);
// PAL: 0x80591378..0x805913a8
UNKNOWN_FUNCTION(unk_80591378);
// PAL: 0x805913a8..0x805913fc
UNKNOWN_FUNCTION(unk_805913a8);
// PAL: 0x805913fc..0x80591418
UNKNOWN_FUNCTION(isDrivingIdle__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591418..0x80591428
UNKNOWN_FUNCTION(getBackwardsAllowCounter__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591428..0x80591434
UNKNOWN_FUNCTION(kartAccessor_44__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591434..0x80591440
UNKNOWN_FUNCTION(kartAccessor_48__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591440..0x8059144c
UNKNOWN_FUNCTION(kartNetSender__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059144c..0x80591458
UNKNOWN_FUNCTION(kartNetReceiver__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591458..0x80591468
UNKNOWN_FUNCTION(PlayerPointers_getRacedataFactoryFlags);
// PAL: 0x80591468..0x80591478
UNKNOWN_FUNCTION(unk_80591468);
// PAL: 0x80591478..0x805914bc
UNKNOWN_FUNCTION(setScale__Q24Kart15KartObjectProxyFRCQ23EGG8Vector3f);
// PAL: 0x805914bc..0x805914cc
UNKNOWN_FUNCTION(getScale__Q24Kart15KartObjectProxyFv);
// PAL: 0x805914cc..0x805914e4
UNKNOWN_FUNCTION(unk_805914cc);
// PAL: 0x805914e4..0x805914f4
UNKNOWN_FUNCTION(unk_805914e4);
// PAL: 0x805914f4..0x80591520
UNKNOWN_FUNCTION(inRespawn__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591520..0x8059152c
UNKNOWN_FUNCTION(kartEntity__Q24Kart15KartObjectProxyFv);
// PAL: 0x8059152c..0x80591538
UNKNOWN_FUNCTION(kartAccessor_50__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591538..0x80591608
UNKNOWN_FUNCTION(unk_80591538);
// PAL: 0x80591608..0x80591618
UNKNOWN_FUNCTION(unk_80591608);
// PAL: 0x80591618..0x80591624
UNKNOWN_FUNCTION(kartAccessor_60__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591624..0x80591650
UNKNOWN_FUNCTION(unk_80591624);
// PAL: 0x80591650..0x80591664
UNKNOWN_FUNCTION(isSomeMoveFlagActive__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591664..0x8059170c
UNKNOWN_FUNCTION(PlayerPointers_resetInertia);
// PAL: 0x8059170c..0x80591784
UNKNOWN_FUNCTION(unk_8059170c);
// PAL: 0x80591784..0x805917a0
UNKNOWN_FUNCTION(unk_80591784);
// PAL: 0x805917a0..0x805917b0
UNKNOWN_FUNCTION(PlayerPointers_getOobWipeState);
// PAL: 0x805917b0..0x805917c0
UNKNOWN_FUNCTION(unk_805917b0);
// PAL: 0x805917c0..0x805917f4
UNKNOWN_FUNCTION(unk_805917c0);
// PAL: 0x805917f4..0x80591828
UNKNOWN_FUNCTION(unk_805917f4);
// PAL: 0x80591828..0x8059184c
UNKNOWN_FUNCTION(unk_80591828);
// PAL: 0x8059184c..0x80591898
UNKNOWN_FUNCTION(unk_8059184c);
// PAL: 0x80591898..0x805918bc
UNKNOWN_FUNCTION(unk_80591898);
// PAL: 0x805918bc..0x805918e0
UNKNOWN_FUNCTION(unk_805918bc);
// PAL: 0x805918e0..0x80591904
UNKNOWN_FUNCTION(unk_805918e0);
// PAL: 0x80591904..0x80591914
UNKNOWN_FUNCTION(kartHalfPipe__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591914..0x80591924
UNKNOWN_FUNCTION(kartJump__Q24Kart15KartObjectProxyFv);
// PAL: 0x80591924..0x8059197c
UNKNOWN_FUNCTION(unk_80591924);
// PAL: 0x8059197c..0x80591998
UNKNOWN_FUNCTION(unk_8059197c);
// PAL: 0x80591998..0x805919e8
UNKNOWN_FUNCTION(unk_80591998);
// PAL: 0x805919e8..0x805919f4
UNKNOWN_FUNCTION(unk_805919e8);

#ifdef __cplusplus
}
#endif

#include <nw4r/ut/utList.hpp>

#include "KartSettings.hpp"
#include "KartHitbox.hpp"

namespace Kart {

class KartBody;
class KartPhysics;
class KartDynamics;
class KartSus;
class KartWheel;
class KartPhysicsEngine;
class KartMove;
class KartSnd;
class KartAccessor_34;
class MaybeShadow;
class KartCollide;
class KartModel;
class KartAction;
class KartCamera;
class KartAccessor_54;
class KartBlink;
class KartAccessor_5c;
class KartEnemy;
class KartAccessor_44;
class KartAccessor_48;
class KartNetReceiver;
class KartNetSender;
class BoxColUnit;
class KartAccessor_50;
class KartAccessor_60;
// Used outside of KartAccessor
class KartHalfPipe;
class KartJump;
class KartState;

struct KartAccessor {
  KartSettings* kartSettings;
  KartState* mKartState;
  KartBody* mBody;
  KartSus** mSus;
  KartWheel** mWheels;
  KartModel* mModel;
  KartPhysicsEngine* mPhysicsEngine;
  KartSnd* mSnd;
  MaybeShadow* mMaybeShadow;
  KartCamera* mCamera;
  KartMove* mMove;
  KartAction* mAction;
  KartCollide* mCollide;
  KartAccessor_34* m_34;
  KartEnemy* mEnemy;
  KartNetSender* mSender;
  KartNetReceiver* mReceiver;
  KartAccessor_44* m_44;
  KartAccessor_48* m_48;
  BoxColUnit* mEntity;
  KartAccessor_50* m_50;
  KartAccessor_54* m_54;
  KartBlink* mBlink;
  KartAccessor_5c* m_5c;
  KartAccessor_60* m_60;
};
static_assert(sizeof(KartAccessor) == 0x64);

class KartObjectProxy {
public:
  KartObjectProxy();

  KartPhysics* kartPhysics();
  const KartPhysics* kartPhysics() const;
  KartDynamics* kartDynamics();
  const KartDynamics* kartDynamics() const;
  KartBody* kartBody();
  const KartBody* kartBody() const;
  KartSus* kartSus(s32 idx);
  const KartSus* kartSus(s32 idx) const;
  KartWheel* kartWheel(s32 idx);
  const KartWheel* kartWheel(s32 idx) const;
  KartPhysicsEngine* kartPhysicsEngine();
  const KartPhysicsEngine* kartPhysicsEngine() const;
  KartMove* kartMove();
  const KartMove* kartMove() const;
  KartSnd* kartSnd();
  KartAccessor_34* kartAccessor_34();
  MaybeShadow* maybeShadow();
  HitboxGroup* hitboxGroup();
  const HitboxGroup* hitboxGroup() const;
  const HitboxGroup* wheelHitbox(s32 idx) const;
  const KartCollisionInfo* bodyColInfo() const;
  const KartCollisionInfo* wheelColInfo(s32 idx) const;
  KartCollide* kartCollide();
  const KartCollide* kartCollide() const;

  // dunno why this specifically is inline, but that's what it appears
  KartState* kartState() { return mAccessor->mKartState; }
  const KartState* kartState() const { return mAccessor->mKartState; }

  KartParam* kartParam() const;
  KartStats* kartStats() const;
  BSP* bsp() const;
  BspHitbox* bspHitboxes() const;
  BspWheel* bspWheel(s32 idx) const;

  KartModel* kartModel();
  u8 getPlayerIdx() const;
  KartAction* kartAction();
  const KartAction* kartAction() const;
  bool hasCamera();
  void setCamera(KartCamera* camera);
  void empty();
  KartAccessor_54* kartAccessor_54();
  KartBlink* kartBlink();
  const KartBlink* kartBlink() const;
  KartAccessor_5c* kartAccessor_5c();
  KartEnemy* kartEnemy();
  KartAccessor_44* kartAccessor_44();
  KartAccessor_48* kartAccessor_48();
  KartNetSender* kartNetSender();
  KartNetReceiver* kartNetReceiver();
  BoxColUnit* kartEntity();
  KartAccessor_50* kartAccessor_50();
  KartAccessor_60* kartAccessor_60();
  const KartHalfPipe* kartHalfPipe();
  const KartJump* kartJump();

  const EGG::Vector3f& getPos() const;
  void getBodyForward(EGG::Vector3f& out);
  s32 getHopStickX();
  s32 getAppliedHopStickX();
  f32 getVehicleSpeed();
  void empty(s16 arg);
  void clearBoost();
  f32 getSpeedRatioCapped();
  f32 getSpeedRatio();
  f32 getBaseSpeed();
  s16 getDriftState();
  s16 getMtCharge();
  s16 getSmtCharge();
  s16 getMaxMtCharge();
  s16 getMaxSmtCharge();
  bool isDrivingIdle();
  s16 getBackwardsAllowCounter();
  void setScale(const EGG::Vector3f& scale);
  const EGG::Vector3f& getScale();
  // Tentative name
  bool inRespawn();
  // Unused, and the KartMove flags are not documented
  bool isSomeMoveFlagActive();

  static void InitList();
  static void SetupInList(KartAccessor* accessor);

private:
  inline KartObjectProxy(const KartObjectProxy&) {}
  static nw4r::ut::List sList;
  KartAccessor* mAccessor;
  nw4r::ut::Node mNode;
};

} // namespace Kart
