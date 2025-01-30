#include "KartObjectProxy.hpp"
#include <stddef.h>

#include <kart/KartMove.hpp>
#include <kart/KartBody.hpp>
#include <kart/KartDynamics.hpp>
#include <kart/KartWheel.hpp>
#include <kart/KartWheelPhysics.hpp>

nw4r::ut::List Kart::KartObjectProxy::sList;
extern u32 bss_809c190c;
u32 bss_809c190c;

namespace Kart {

void KartObjectProxy::InitList() {
  List_Init(&sList, offsetof(KartObjectProxy, mNode));
}

void KartObjectProxy::SetupInList(KartAccessor* accessor) {
  KartObjectProxy* component = nullptr;
  while ((component = (KartObjectProxy*)List_GetNext(&sList, component))) {
    component->mAccessor = accessor;
  }
}

KartObjectProxy::KartObjectProxy() : mAccessor(nullptr) {
  List_Append(&sList, this);
}

const EGG::Vector3f& KartObjectProxy::getPos() const { return kartDynamics()->pos; }

KartPhysics* KartObjectProxy::kartPhysics() { return mAccessor->mBody->getPhysics(); }

const KartPhysics* KartObjectProxy::kartPhysics() const { return mAccessor->mBody->getPhysics(); }

KartDynamics* KartObjectProxy::kartDynamics() { return mAccessor->mBody->getPhysics()->mpDynamics; }

const KartDynamics* KartObjectProxy::kartDynamics() const { return mAccessor->mBody->getPhysics()->mpDynamics; }

KartBody* KartObjectProxy::kartBody() { return mAccessor->mBody; }

const KartBody* KartObjectProxy::kartBody() const { return mAccessor->mBody; }

KartSus* KartObjectProxy::kartSus(s32 idx) { return mAccessor->mSus[idx]; }

const KartSus* KartObjectProxy::kartSus(s32 idx) const {
  return mAccessor->mSus[idx];
}

KartWheel* KartObjectProxy::kartWheel(s32 idx) { return mAccessor->mWheels[idx]; }

const KartWheel* KartObjectProxy::kartWheel(s32 idx) const {
  return mAccessor->mWheels[idx];
}

KartPhysicsEngine* KartObjectProxy::kartPhysicsEngine() { return mAccessor->mPhysicsEngine; }

const KartPhysicsEngine* KartObjectProxy::kartPhysicsEngine() const { return mAccessor->mPhysicsEngine; }

KartMove* KartObjectProxy::kartMove() { return mAccessor->mMove; }

const KartMove* KartObjectProxy::kartMove() const { return mAccessor->mMove; }

KartSnd* KartObjectProxy::kartSnd() { return mAccessor->mSnd; }

KartAccessor_34* KartObjectProxy::kartAccessor_34() { return mAccessor->m_34; }

MaybeShadow* KartObjectProxy::maybeShadow() { return mAccessor->mMaybeShadow; }

HitboxGroup* KartObjectProxy::hitboxGroup() { return kartBody()->getPhysics()->mpHitboxGroup; }

const HitboxGroup* KartObjectProxy::hitboxGroup() const { return kartBody()->getPhysics()->mpHitboxGroup; }

const HitboxGroup* KartObjectProxy::wheelHitbox(s32 wheelIdx) const { return kartWheel(wheelIdx)->getPhysics()->getHitbox(); }

const KartCollisionInfo* KartObjectProxy::bodyColInfo() const { return &hitboxGroup()->getKartCollisionInfo(); }

const KartCollisionInfo* KartObjectProxy::wheelColInfo(s32 idx) const { return &kartWheel(idx)->getPhysics()->getKartCollisionInfo(); }

KartCollide* KartObjectProxy::kartCollide() { return mAccessor->mCollide; }

const KartCollide* KartObjectProxy::kartCollide() const {
  return mAccessor->mCollide;
}

KartParam* KartObjectProxy::kartParam() const { return mAccessor->kartSettings->kartParam; }
KartStats* KartObjectProxy::kartStats() const { return mAccessor->kartSettings->kartParam->stats; }
BSP* KartObjectProxy::bsp() const { return mAccessor->kartSettings->kartParam->bsp; }
BspHitbox* KartObjectProxy::bspHitboxes() const { return mAccessor->kartSettings->kartParam->bsp->hitboxes; }
BspWheel* KartObjectProxy::bspWheel(s32 idx) const { return &mAccessor->kartSettings->kartParam->bsp->wheels[idx]; }

s32 KartObjectProxy::getHopStickX() { return kartMove()->hopStickX(); }

s32 KartObjectProxy::getAppliedHopStickX() {
  return kartMove()->getAppliedHopStickX();
}

KartModel* KartObjectProxy::kartModel() { return mAccessor->mModel; }

f32 KartObjectProxy::getVehicleSpeed() { return kartMove()->speed(); }

KartAction* KartObjectProxy::kartAction() { return mAccessor->mAction; }

const KartAction* KartObjectProxy::kartAction() const {
  return mAccessor->mAction;
}

void KartObjectProxy::empty(s16 arg) { kartMove()->empty(arg); }

void KartObjectProxy::clearBoost() { kartMove()->clearBoost(); }

f32 KartObjectProxy::getSpeedRatioCapped() {
  return kartMove()->speedRatioCapped();
}

f32 KartObjectProxy::getSpeedRatio() { return kartMove()->speedRatio(); }

bool KartObjectProxy::hasCamera() { return mAccessor->mCamera; }

void KartObjectProxy::setCamera(KartCamera* camera) {
  mAccessor->mCamera = camera;
}

void KartObjectProxy::empty() {}

KartAccessor_54* KartObjectProxy::kartAccessor_54() { return mAccessor->m_54; }

KartBlink* KartObjectProxy::kartBlink() { return mAccessor->mBlink; }

const KartBlink* KartObjectProxy::kartBlink() const {
  return mAccessor->mBlink;
}

KartAccessor_5c* KartObjectProxy::kartAccessor_5c() { return mAccessor->m_5c; }

f32 KartObjectProxy::getBaseSpeed() { return kartMove()->baseSpeed(); }

KartEnemy* KartObjectProxy::kartEnemy() { return mAccessor->mEnemy; }

s16 KartObjectProxy::getDriftState() { return kartMove()->driftState(); }

s16 KartObjectProxy::getMtCharge() { return kartMove()->mtCharge(); }

s16 KartObjectProxy::getSmtCharge() { return kartMove()->smtCharge(); }

s16 KartObjectProxy::getMaxMtCharge() { return kartMove()->getMaxMtCharge(); }

s16 KartObjectProxy::getMaxSmtCharge() { return kartMove()->getMaxSmtCharge(); }

bool KartObjectProxy::isDrivingIdle() {
  return kartMove()->drivingDirection() == KartMove::DRIVING_DIRECTION_IDLE;
}

s16 KartObjectProxy::getBackwardsAllowCounter() {
  return kartMove()->backwardsAllowCounter();
}

KartAccessor_44* KartObjectProxy::kartAccessor_44() { return mAccessor->m_44; }

KartAccessor_48* KartObjectProxy::kartAccessor_48() { return mAccessor->m_48; }

KartNetSender* KartObjectProxy::kartNetSender() { return mAccessor->mSender; }

KartNetReceiver* KartObjectProxy::kartNetReceiver() {
  return mAccessor->mReceiver;
}

void KartObjectProxy::setScale(const EGG::Vector3f& scale) {
  kartMove()->setScale(scale);
}

const EGG::Vector3f& KartObjectProxy::getScale() { return kartMove()->scale(); }

bool KartObjectProxy::inRespawn() {
  return kartMove()->respawnTimer() > 0 || kartMove()->someTimer() > 0;
}

BoxColUnit* KartObjectProxy::kartEntity() { return mAccessor->mEntity; }

KartAccessor_50* KartObjectProxy::kartAccessor_50() { return mAccessor->m_50; }

KartAccessor_60* KartObjectProxy::kartAccessor_60() { return mAccessor->m_60; }

bool KartObjectProxy::isSomeMoveFlagActive() {
  return kartMove()->flags() & 1 << 2;
}

const KartHalfPipe* KartObjectProxy::kartHalfPipe() {
  return kartMove()->kartHalfPipe();
}

const KartJump* KartObjectProxy::kartJump() { return kartMove()->kartJump(); }

} // namespace Kart
