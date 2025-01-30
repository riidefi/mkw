#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/math/eggVector.hpp>

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
