#include <rk_types.h>
#include <decomp.h>

#include "KartState.hpp"

#include "KartCollide.hpp"
#include "KartDynamics.hpp"
#include "KartMove.hpp"
#include "KartPhysics.hpp"
#include "KartWheel.hpp"
#include "KartWheelPhysics.hpp"

extern EGG::Vector3f lbl_802A4100;
extern EGG::Vector3f RKSystem_ey;

static inline f32 dotZY(const EGG::Vector3f& a, const EGG::Vector3f& b) {
  EGG::Vector3f zb = b, za = a;
  za.y = 0.0f;
  zb.y = 0.0f;
  return EGG::Vector3f::dot(za, zb);
}

extern "C" void* lbl_1_bss_4218;
extern "C" f32 lbl_1_data_3918[4] = {0.02f, 0.002f, 0.96f, 0.02f};

struct StartBoostEntry {
  f32 threshold;
  s16 count;
  s16 _pad;
};
extern "C" StartBoostEntry lbl_1_data_3928[6] = {
    {0.85f, 0, 0},  {0.88f, 10, 0}, {0.905f, 20, 0},
    {0.925f, 30, 0}, {0.94f, 45, 0}, {0.95f, 70, 0},
};
extern "C" s16 lbl_1_data_3958[6] = {0x00B4, 0x0000, 0x0000, 0x000A, 0x4220, 0x0000};
extern "C" void PlayerSub10_applyStartBoost(void*, s16);
extern "C" {
void fn_1_80068(Kart::KartObjectProxy*, s32, s32, f32);
void* fn_1_803EC(Kart::KartObjectProxy*);
void fn_1_809A8(Kart::KartObjectProxy*, s32);
void fn_1_80C90(Kart::KartObjectProxy*, s32, s32, s32);
s32 fn_1_80DF4(Kart::KartObjectProxy*);
s32 fn_1_80E0C(Kart::KartObjectProxy*);
void fn_1_354D84(void*);
void PlayerZipper_end(const void*, s32);
void PlayerTrick_end(void*);
void PlayerSub10_endTrick(void*);
EGG::Vector3f* playerPointers_getSpeed(Kart::KartObjectProxy*);
s32 PlayerPointers_isBike(Kart::KartObjectProxy*);
s32 Raceinfo_isAtLeastStage(void*, s32);
}

//https://decomp.me/scratch/7prZZ
namespace Kart {
extern bool isPlayerOnlineLocal;
extern bool isPlayerOnlineRemote;

MARK_FLOW_CHECK(0x805943b4);
KartState::KartState(KartSettings* settings) {
  using namespace System;

  mAirtime = 0;
  _24 = 0.0f;
  mCannonPointId = 0;
  mStartBoostIdx = 0;
  mTop.setZero();
  mProxy = new KartObjectProxy;

  RaceConfig::Player::Type playerType = RaceConfig::spInstance->mRaceScenario.mPlayers[settings->playerIdx].mPlayerType;
  switch (playerType) {
  case RaceConfig::Player::TYPE_REAL_LOCAL:
    set(KART_FLAG_LOCAL);
    break;
  case RaceConfig::Player::TYPE_CPU:
    set(KART_FLAG_CPU);
    break;
  case RaceConfig::Player::TYPE_GHOST:
    set(KART_FLAG_GHOST);
    break;
  }

  if (isPlayerOnlineLocal) {
    set(KART_FLAG_ONLINE_LOCAL);
  } else if (isPlayerOnlineRemote) {
    set(KART_FLAG_ONLINE_REMOTE);
  }

  KPadController* controller = RaceManager::spInstance->players[settings->playerIdx]->kpadPlayer->mController;
  bool isAuto;
  if (!controller) {
    isAuto = false;
  } else {
    isAuto = controller->mDriftIsAuto;
  }

  if (isAuto) {
    set(KART_FLAG_AUTOMATIC_DRIFT);
  }

  if (RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode == RaceConfig::Settings::GAMEMODE_AWARDS &&
      RaceConfig::spInstance->mRaceScenario.mSettings.mCameraMode == RaceConfig::Settings::CAMERA_MODE_LOSS) {
    set(KART_FLAG_SET_SPEED_ZERO);
    set(KART_FLAG_DEMO_LOSS);
  }
}

void KartState::init() {
  reset();
  mWipeState = -1;
  mWipeFrame = -1;
}

void KartState::reset() {
  mFlags.field(3) = 0;
  mFlags.field(2) = 0;
  mFlags.field(1) = 0;
  mFlags.field(0) = 0;
  mAirtime = 0;
  _24 = 0.0f;
  mTop.setZero();
  _40.setZero();
  _58 = 0;
  _5c = 0;
  mHwgTimer = 0;
  _70 = 0;
  mBoostRampType = -1;
  mJumpPadType = -1;
  _84 = 0;
  mStartBoostCharge = 0.0f;
  mStick.y = 0.0f;
  mStick.x = 0.0f;
  _a4 = 0;
  _4c = _a8 = lbl_802A4100;
  _a6 = 0;
}

void KartState::resetOob() {
  mWipeState = -1;
  mWipeFrame = -1;
}

void KartState::updateWipe() {
  if (mWipeState == -1) {
    return;
  }
  mWipeFrame++;
  f32 ratio = (f32)mWipeFrame / (f32)lbl_1_data_3958[mWipeState];
  _98 = ratio;
  if (1.0f < ratio) {
    _98 = 1.0f;
  }
  if (mWipeFrame > lbl_1_data_3958[mWipeState]) {
    mWipeState = -1;
  }
}

void KartState::startWipe(int wipeState) {
  mWipeState = wipeState;
  mWipeFrame = 0;
}

void KartState::resetCollisionFlags() {
  field(0) &= 0xFE7F9C78;
  field(1) &= 0xFFFFEFFF;
  field(2) &= 0x3FBFEFFF;
  mStick.y = 0.0f;
  mStick.x = 0.0f;
}

void KartState::empty() {}

void KartState::resetGroundFlags() {
  field(1) &= 0xF7F7FDFF;
  field(2) &= 0xFFFFFBF7;
}

void KartState::setCollisionFlag() {
  field(4) |= 0x20;
}

void KartState::clearCollisionFlag() {
  field(4) &= ~0x20;
}

void KartState::applyStartBoost(s32 idx) {
  PlayerSub10_applyStartBoost(mProxy->kartMove(), lbl_1_data_3928[idx].count);
}

void KartState::calcStartBoost() {
  if (on(104)) {
    f32 delta = lbl_1_data_3918[0] - lbl_1_data_3918[1];
    delta *= mStartBoostCharge;
    mStartBoostCharge += lbl_1_data_3918[0] - delta;
  } else {
    mStartBoostCharge *= lbl_1_data_3918[2];
  }

  if (0.0f > mStartBoostCharge) {
    mStartBoostCharge = 0.0f;
  } else if (1.0f < mStartBoostCharge) {
    mStartBoostCharge = 1.0f;
  }

  *(f32*)((u8*)mProxy->kartMove() + 0x224) = mStartBoostCharge * 10.0f;
}

// nonmatching (98.69%): colouring/playerIdx/gameMode/vtable/flags-accessor blocks
// match retail; the dotZY helper uses named locals (not zeroY) to fix the temp-copy
// order. See SUBAGENT_FIELD_NOTES_updateCollisions.md.
struct __KMVT {
  virtual void f0(u8);
  virtual void f1(u8);
  virtual void f2(u8);
  virtual void f3(u8);
  virtual void f4(u8);
  virtual void f5(u8);
  virtual void f6(u8);
  virtual void f7(u8);
  virtual void f8(u8);
  virtual void f9(u8);
  virtual void f10(u8);
  virtual void f11(u8);
  virtual void f12(u8);
  virtual void f13(u8);
  virtual void f14(u8);
};

void KartState::updateCollisions() {
  using namespace System;
  bool var_r28;
  bool var_r27;
  f32* const p3 = lbl_1_data_3918 + 3;
  f32* const pe = p3 - 3;
  KartObjectProxy* proxy = mProxy;
  KartObjectProxy** pproxy = &proxy;
  HitboxGroup** hgp;
  s32 var_r27_2;

  u32 flags0 = (*pproxy)->kartStateReload()->field(0);
  var_r28 = (flags0 & 0x40000) != 0;
  var_r27 = (flags0 & 0x60) != 0;
  (*pproxy)->kartState()->field(0) &= 0xFFFBE39F;
  KartObjectProxy* proxyF = proxy;

  if (mHwgTimer != 0) {
    mHwgTimer -= 1;
    _70 += 1;
    if (mHwgTimer == 0) {
      _70 = 0;
      field(3) &= ~0xA;
    }
  }

  s32 var_r25 = 0;
  mTop.z = 0.0f;
  mTop.y = 0.0f;
  mTop.x = 0.0f;
  s32 var_r24 = 0;

  KartCollide* collide = proxyF->kartCollide();
  KartCollide** pcollide = &collide;
  if ((*pcollide)->someSoftWallTimer > 0) {
    if ((*pcollide)->someNonSoftWallTimer > 0) {
      f32 softTimer = (f32)(*pcollide)->someSoftWallTimer;
      f32 softRatio = (*pcollide)->suspBottomHeightSoftWall;
      f32 nonSoftRatio = (*pcollide)->suspBottomHeightNonSoftWall;
      f32 nonSoftTimer = (f32)(*pcollide)->someNonSoftWallTimer;
      if ((softRatio / softTimer) - (nonSoftRatio / nonSoftTimer) < pe[18]) {
        var_r24 = 1;
      } else {
        field(3) &= 0xFFFFFFEF;
      }
    } else {
      var_r24 = 1;
    }
  }

  s32 var_r23 = 0;
  EGG::Vector3f accum;
  accum.z = 0.0f;
  s32 var_r22 = 0;
  s32 var_r19 = 0;
  accum.y = 0.0f;
  accum.x = 0.0f;
  while (var_r19 < (s32)proxyF->getWheelCount()) {
    KartWheelPhysics* wheel = proxyF->kartWheel(var_r19)->getPhysics();
    const KartCollisionInfo* colInfo = &wheel->getKartCollisionInfo();
    if (wheel->hasFloorCollision()) {
      mTop.x += colInfo->floorNrm.x;
      mTop.y += colInfo->floorNrm.y;
      mTop.z += colInfo->floorNrm.z;
      if (var_r25 == 0) {
        var_r25 = (colInfo->flags >> 3) & 1;
      }
      var_r23++;
    }
    if (var_r24 != 0 && (colInfo->flags & 0x200)) {
      var_r22++;
      accum.x += colInfo->softWallNrm.x;
      accum.y += colInfo->softWallNrm.y;
      accum.z += colInfo->softWallNrm.z;
    }
    var_r19++;
  }

  if (var_r23 > 0) {
    proxyF->kartState()->field(0) |= 0x800;
    if (var_r23 == (s32)proxyF->getWheelCount()) {
      proxyF->kartState()->field(0) |= 0x1000;
    }
  }

  hgp = &proxyF->kartPhysics()->mpHitboxGroup;
  KartCollisionInfo& ci = (*hgp)->getKartCollisionInfo();
  if (ci.flags & 1) {
    proxyF->kartState()->field(0) |= 0x400;
    mTop.x += ci.floorNrm.x;
    mTop.y += ci.floorNrm.y;
    mTop.z += ci.floorNrm.z;
    if (var_r25 == 0) {
      var_r25 = (ci.flags >> 3) & 1;
    }
    if (proxyF->kartState()->field(1) & 0x400) {
      PlayerZipper_end(proxyF->kartHalfPipe(), 1);
    }
  }

  s32 var_r24_2 = 0;
  if (var_r24 != 0 && (ci.flags & 0x200)) {
    var_r24_2 = 1;
    var_r22++;
    accum.x += ci.wallNrm.x;
    accum.y += ci.wallNrm.y;
    accum.z += ci.wallNrm.z;
  }

  s32 var_r4 = 0;
  if ((ci.flags & 0x80) && (mHalfpipeInvisibilityTimer > 0)) {
    var_r4 = 1;
  }
  mHalfpipeInvisibilityTimer -= 1;
  if (mHalfpipeInvisibilityTimer < 0) {
    mHalfpipeInvisibilityTimer = 0;
  }
  _a4 -= 1;
  if (_a4 < 0) {
    _a4 = 0;
  }

  u32 f = ci.flags;
  s32 var_r21 = 0;
  if ((f & 0x42) && var_r4 == 0) {
    if (f & 2) {
      proxyF->kartState()->field(0) |= 0x40;
    }
    if (ci.flags & 0x40) {
      proxyF->kartState()->field(0) |= 0x20;
    }
    if (!var_r27) {
      proxyF->kartState()->field(0) |= 0x4000;
      if ((fn_1_80DF4(proxy) == 0x1E) && (fn_1_80E0C(proxy) == 0)) {
        s32 var_r0 = 1;
        s32 var_r7 = 1;
        s32 var_r8 = 1;
        s32 var_r9 = 1;
        s32 var_r10 = 1;
        s32 var_r5;
        u32 f8 = proxyF->kartState()->field(1);
        var_r5 = f8 & 0x102;
        if (var_r5 == 0) {
          var_r5 = proxyF->kartState()->field(2) & 0x020C6000;
          if (var_r5 == 0) {
            var_r10 = 0;
          }
        }
        if (var_r10 == 0) {
          var_r5 = proxyF->kartState()->field(0) & 0x10;
          if (var_r5 == 0) {
            var_r9 = 0;
          }
        }
        if (var_r9 == 0) {
          var_r5 = proxyF->kartState()->field(4) & 0x80;
          if (var_r5 == 0) {
            var_r8 = 0;
          }
        }
        if (var_r8 == 0) {
          var_r5 = 0x80000019;
          if (!(f8 & 0x80000019)) {
            var_r7 = 0;
          }
        }
        if (var_r7 == 0) {
          var_r5 = proxyF->kartState()->field(2);
          if (!(var_r5 & 0x0A008000)) {
            var_r0 = 0;
          }
        }
        if ((var_r0 == 0) && !(proxyF->kartState()->field(4) & 8)) {
          fn_1_809A8(proxy, 1);
          u8 playerIdx = proxyF->getPlayerIdx();
          RaceManager* rm = RaceManager::spInstance;
          RaceConfig* rc = RaceConfig::spInstance;
          s32 gameMode = rc->mRaceScenario.mSettings.mGameMode;
          if (gameMode == 3) {
            s32 battleType = rc->mRaceScenario.mSettings.mBattleType;
            if (battleType == 0) {
              ((__KMVT*)rm->raceMode)->f12((u8)playerIdx);
            } else if (battleType == 1) {
              ((__KMVT*)rm->raceMode)->f11((u8)playerIdx);
            }
          } else if (!(gameMode != 9 && gameMode != 10)) {
            s32 battleType = rc->mRaceScenario.mSettings.mBattleType;
            if (battleType == 0) {
              ((__KMVT*)rm->raceMode)->f12((u8)playerIdx);
            } else if (battleType == 1) {
              ((__KMVT*)rm->raceMode)->f11((u8)playerIdx);
            }
          }
          void* r4_6 = proxyF->kartSettings()->gpStats;
          if (r4_6 != NULL) {
            *(s32*)((u8*)r4_6 + 0x10) += 1;
          }
        }
      }
    }
    _a4 = 2;
    _a8.x = ci.wallNrm.x;
    _a8.y = ci.wallNrm.y;
    _a8.z = ci.wallNrm.z;
    if (field(3) & 0x20) {
      _a8.x = _34.x;
      _a8.y = _34.y;
      _a8.z = _34.z;
    }
    if (!(*(u32*)((u8*)lbl_1_bss_4218 + 0x28) & 0x20) && (mHwgTimer == 0) &&
        !(proxyF->kartCollide()->surfaceFlags & 0x2000) &&
        (ci.movement.y > 1.0f)) {
      EGG::Vector3f sp20 = ci.movement;
      sp20.normalise();
      if ((((sp20.z * RKSystem_ey.z) + ((sp20.x * RKSystem_ey.x) + (sp20.y * RKSystem_ey.y))) > 0.8f) &&
          (((RKSystem_ey.z * ci.wallNrm.z) +
            ((RKSystem_ey.x * ci.wallNrm.x) + (RKSystem_ey.y * ci.wallNrm.y))) >
           0.85f) &&
          ((dotZY(ci.wallNrm, sp20) < 0.0f) ||
           (proxyF->kartCollide()->_68 >= 1.0f))) {
        ci.wallNrm.y = 0.0f;
        ci.wallNrm.normalise();
        _a8.x = ci.wallNrm.x;
        _a8.y = ci.wallNrm.y;
        _a8.z = ci.wallNrm.z;
        f32 temp_f5 = ci.wallNrm.x;
        f32 temp_f4 = ci.wallNrm.z;
        accum.x = temp_f5;
        accum.z = temp_f4;
        accum.y = 0.0f;
        if (EGG::Mathf::sqrt((temp_f4 * temp_f4) + ((temp_f5 * temp_f5) + (accum.y * accum.y))) < 0.05f) {
          accum.x = sp20.x;
          accum.z = sp20.z;
          accum.y = 0.0f;
        }
        var_r21 = 1;
      }
    }
  }

  if ((ci.flags & 4) && (field(1) & 0x200) &&
      !(proxyF->kartCollide()->surfaceFlags & 0x10000)) {
    proxyF->kartState()->field(1) |= 0x1000;
  }

  if ((var_r22 > 0) || (var_r21 != 0)) {
    field(3) |= 2;
    _34.x = accum.x;
    _34.y = accum.y;
    _34.z = accum.z;
    _34.normalise();
    var_r27_2 = 0;
    if ((var_r22 > 0) && (PlayerPointers_isBike(proxy) == 1)) {
      var_r27_2 = 1;
    }
    if ((var_r22 > 0) && !(field(0) & 0x80000)) {
      field(3) |= 0x10;
    }
    if (var_r21 != 0) {
      field(3) |= 0x20;
    }
    if ((var_r24_2 != 0) || (var_r21 != 0) || (var_r27_2 != 0)) {
      field(3) |= 8;
      s32 hwg = *((s32*)(pe + 17));
      mHwgTimer = hwg;
      if (var_r21 != 0) {
        mHwgTimer = hwg * 2;
      }
    }
  }

  field(0) &= 0xFFFF7FFF;
  field(1) &= 0xFFFFFFFB;
  _a6 -= 1;
  if (_a6 < 0) {
    _a6 = 0;
  }

  if ((var_r23 > 0) || (ci.flags & 1)) {
    mTop.normalise();
    u32 f0 = field(0) | 0x40000;
    u32 f3 = field(3) & 0xFFFFFFBF;
    _4c.x = mTop.x;
    _4c.y = mTop.y;
    _4c.z = mTop.z;
    field(0) = f0;
    field(3) = f3;
    if (!(proxyF->kartState()->field(1) & 1)) {
      field(3) = f3 & ~0x880;
    }
    if (Raceinfo_isAtLeastStage(RaceManager::spInstance, 2) != 0) {
      if (!(proxyF->kartCollide()->surfaceFlags & 0x20) &&
          (proxyF->kartCollide()->surfaceFlags & 0x40)) {
        fn_1_80068(proxy, 8, 1, 1.0f);
      }
      if (!(proxyF->kartCollide()->surfaceFlags & 0x80) &&
          (proxyF->kartCollide()->surfaceFlags & 0x100)) {
        fn_1_80068(proxy, 4, 1, 1.0f);
      }
    }
    if ((proxyF->kartState()->field(1) & 0x400) && !(proxyF->kartState()->field(2) & 0x800000)) {
      PlayerZipper_end(proxyF->kartHalfPipe(), 1);
      if (!(proxyF->kartState()->field(0) & 0x10)) {
        proxyF->kartStateReload()->field(2) |= 0x80000000;
      }
    }
    if (var_r25 != 0) {
      _a6 = 3;
    }
    if ((s16)_a6 > 0) {
      field(1) |= 0x40000000;
    } else {
      field(1) &= 0xBFFFFFFF;
    }
    if (!(proxyF->kartState()->field(0) & 0x40000000)) {
      field(1) &= 0xFFFFF7FF;
    }
    if (var_r28 == 0) {
      proxyF->kartState()->field(0) |= 0x200;
      EGG::Vector3f* speed = playerPointers_getSpeed(proxy);
      f32 temp_f31 = (mTop.z * speed->z) + ((mTop.x * speed->x) + (mTop.y * speed->y));
      if (temp_f31 < -22.0f) {
        proxyF->kartState()->field(2) |= 0x40000000;
        f32 var_f1 = fabsf(temp_f31 * pe[3]);
        if (1.0f < var_f1) {
          var_f1 = 1.0f;
        }
        fn_1_80068(proxy, 2, 1, var_f1);
      }
      if (!(proxyF->kartState()->field(0) & 0x10)) {
        if (temp_f31 < -7.0f) {
          proxyF->kartStateReload()->field(2) |= 0x80000000;
        }
        fn_1_354D84(fn_1_803EC(proxy));
        if (mAirtime > 0x3C) {
          fn_1_80068(proxy, 2, 1, 1.0f);
        }
      }
    }
    if ((field(1) & 0x40) && (*(s16*)((u8*)proxyF->kartJump() + 0x38) <= 0)) {
      PlayerSub10_endTrick(proxyF->kartMove());
      KartDynamics* kdyn = proxyF->kartDynamics();
      kdyn->_forceUpright = 1;
      PlayerTrick_end(*(void**)((u8*)proxyF->kartMove() + 0x258));
    }
    mAirtime = 0;
  } else {
    if (var_r28 != 0) {
      proxyF->kartState()->field(0) |= 0x800000;
    }
    u32 temp_r0_7 = mAirtime + 1;
    mAirtime = temp_r0_7;
    if (temp_r0_7 > 0x14) {
      proxyF->kartState()->field(0) |= 0x8000;
      if (mAirtime == 0x14) {
        fn_1_80C90(proxy, 5, 0, 1);
      }
      f32 temp_f2 = playerPointers_getSpeed(proxy)->y;
      if ((temp_f2 - _7c) < 0.0f) {
        field(1) |= 4;
      }
      _7c = temp_f2;
    }
  }

  proxyF->kartWheelPhysics(0);
  proxyF->getPos();
}

KartState::~KartState() {}
}