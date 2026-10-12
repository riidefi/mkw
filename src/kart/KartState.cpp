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
extern "C" void* lbl_1_bss_4218;
extern "C" s16 lbl_1_data_3958[6] = {0x00B4, 0x0000, 0x0000, 0x000A, 0x4220, 0x0000};
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
  mUp.setZero();
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
  mUp.setZero();
  _40.setZero();
  _58 = 0;
  _5c = 0;
  mHwgTimer = 0;
  m_70 = 0;
  mBoostRampType = -1;
  mJumpPadType = -1;
  _84 = 0;
  mStartBoostCharge = 0.0f;
  mStick.y = 0.0f;
  mStick.x = 0.0f;
  _a4 = 0;
  _4c = m_a8 = lbl_802A4100;
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

void KartState::updateCollisions() {
  using namespace System;
  KartObjectProxy* proxy = mProxy;

  u32 flags0 = proxy->kartState()->field(0);
  s32 var_r28 = (flags0 >> 18) & 1;
  proxy->kartState()->field(0) = flags0 & 0xFFFBE39F;
  bool var_r27 = (flags0 & 0x60) != 0;

  if (mHwgTimer != 0) {
    mHwgTimer -= 1;
    m_70 += 1;
    if (mHwgTimer == 0) {
      m_70 = 0;
      field(3) &= ~0xA;
    }
  }

  s32 var_r25 = 0;
  mUp.z = 0.0f;
  mUp.y = 0.0f;
  mUp.x = 0.0f;
  s32 var_r24 = 0;

  KartCollide* collide = proxy->kartCollide();
  if (collide->someSoftWallTimer > 0) {
    if (collide->someNonSoftWallTimer > 0) {
      if ((collide->suspBottomHeightSoftWall / (f32)collide->someSoftWallTimer) -
              (collide->suspBottomHeightNonSoftWall / (f32)collide->someNonSoftWallTimer) <
          ((f32*)lbl_1_data_3918)[18]) {
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
  while (var_r19 < (s32)proxy->getWheelCount()) {
    KartWheelPhysics* wheel = proxy->kartWheel(var_r19)->getPhysics();
    const KartCollisionInfo* colInfo = &wheel->getKartCollisionInfo();
    if (wheel->hasFloorCollision()) {
      mUp.x += colInfo->floorNrm.x;
      mUp.y += colInfo->floorNrm.y;
      mUp.z += colInfo->floorNrm.z;
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
    proxy->kartState()->field(0) |= 0x800;
    if (var_r23 == (s32)proxy->getWheelCount()) {
      proxy->kartState()->field(0) |= 0x1000;
    }
  }

  HitboxGroup* hg = proxy->kartPhysics()->mpHitboxGroup;
  if (hg->getKartCollisionInfo().flags & 1) {
    proxy->kartState()->field(0) |= 0x400;
    mUp.x += hg->getKartCollisionInfo().floorNrm.x;
    mUp.y += hg->getKartCollisionInfo().floorNrm.y;
    mUp.z += hg->getKartCollisionInfo().floorNrm.z;
    if (var_r25 == 0) {
      var_r25 = (hg->getKartCollisionInfo().flags >> 3) & 1;
    }
    if (proxy->kartState()->field(1) & 0x400) {
      PlayerZipper_end(proxy->kartHalfPipe(), 1);
    }
  }

  s32 var_r24_2 = 0;
  if (var_r24 != 0 && (hg->getKartCollisionInfo().flags & 0x200)) {
    var_r24_2 = 1;
    var_r22++;
    accum.x += hg->getKartCollisionInfo().wallNrm.x;
    accum.y += hg->getKartCollisionInfo().wallNrm.y;
    accum.z += hg->getKartCollisionInfo().wallNrm.z;
  }

  s32 var_r4 = 0;
  if ((hg->getKartCollisionInfo().flags & 0x80) && (mHalfpipeInvisibilityTimer > 0)) {
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

  u32 f = hg->getKartCollisionInfo().flags;
  s32 var_r21 = 0;
  if ((f & 0x42) && var_r4 == 0) {
    if (f & 2) {
      proxy->kartState()->field(0) |= 0x40;
    }
    if (hg->getKartCollisionInfo().flags & 0x40) {
      proxy->kartState()->field(0) |= 0x20;
    }
    if (!var_r27) {
      proxy->kartState()->field(0) |= 0x4000;
      if ((fn_1_80DF4(proxy) == 0x1E) && (fn_1_80E0C(proxy) == 0)) {
        s32 var_r0 = 1;
        s32 var_r7 = 1;
        s32 var_r8 = 1;
        s32 var_r9 = 1;
        s32 var_r10 = 1;
        s32 var_r5;
        u32 f8 = proxy->kartState()->field(2);
        var_r5 = f8 & 0x102;
        if (var_r5 == 0) {
          var_r5 = proxy->kartState()->field(3) & 0x020C6000;
          if (var_r5 == 0) {
            var_r10 = 0;
          }
        }
        if (var_r10 == 0) {
          var_r5 = proxy->kartState()->field(1) & 0x10;
          if (var_r5 == 0) {
            var_r9 = 0;
          }
        }
        if (var_r9 == 0) {
          var_r5 = proxy->kartState()->field(5) & 0x80;
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
          var_r5 = proxy->kartState()->field(3);
          if (!(var_r5 & 0x0A008000)) {
            var_r0 = 0;
          }
        }
        if ((var_r0 == 0) && !(proxy->kartState()->field(5) & 8)) {
          fn_1_809A8(proxy, 1);
          u8 playerIdx = proxy->getPlayerIdx();
          RaceConfig* rc = RaceConfig::spInstance;
          RaceManager* rm = RaceManager::spInstance;
          s32 gameMode = rc->mRaceScenario.mSettings.mGameMode;
          if (gameMode == 3) {
            s32 battleType = rc->mRaceScenario.mSettings.mBattleType;
            if (battleType == 0) {
              ((void (*)(void*, s32))(*(void***)rm->raceMode)[0x38 / 4])(rm->raceMode, playerIdx);
            } else if (battleType == 1) {
              ((void (*)(void*, s32))(*(void***)rm->raceMode)[0x34 / 4])(rm->raceMode, playerIdx);
            }
          } else if (gameMode == 9 || gameMode == 10) {
            s32 battleType = rc->mRaceScenario.mSettings.mBattleType;
            if (battleType == 0) {
              ((void (*)(void*, s32))(*(void***)rm->raceMode)[0x38 / 4])(rm->raceMode, playerIdx);
            } else if (battleType == 1) {
              ((void (*)(void*, s32))(*(void***)rm->raceMode)[0x34 / 4])(rm->raceMode, playerIdx);
            }
          }
          void* r4_6 = proxy->kartSettings()->gpStats;
          if (r4_6 != NULL) {
            *(s32*)((u8*)r4_6 + 0x10) += 1;
          }
        }
      }
    }
    _a4 = 2;
    m_a8.x = hg->getKartCollisionInfo().wallNrm.x;
    m_a8.y = hg->getKartCollisionInfo().wallNrm.y;
    m_a8.z = hg->getKartCollisionInfo().wallNrm.z;
    if (field(3) & 0x20) {
      m_a8.x = _34.x;
      m_a8.y = _34.y;
      m_a8.z = _34.z;
    }
    if (!(*(u32*)((u8*)lbl_1_bss_4218 + 0x28) & 0x20) && (mHwgTimer == 0) &&
        !(proxy->kartCollide()->surfaceFlags & 0x2000) &&
        (hg->getKartCollisionInfo().movement.y > ((f32*)lbl_1_data_3918)[17])) {
      EGG::Vector3f sp20 = hg->getKartCollisionInfo().movement;
      sp20.normalise();
      if ((((sp20.z * RKSystem_ey.z) + ((sp20.x * RKSystem_ey.x) + (sp20.y * RKSystem_ey.y))) > 0.8f) &&
          (((RKSystem_ey.z * hg->getKartCollisionInfo().wallNrm.z) +
            ((RKSystem_ey.x * hg->getKartCollisionInfo().wallNrm.x) + (RKSystem_ey.y * hg->getKartCollisionInfo().wallNrm.y))) >
           ((f32*)lbl_1_data_3918)[18]) &&
          (((sp20.z * hg->getKartCollisionInfo().wallNrm.z) +
            ((sp20.x * hg->getKartCollisionInfo().wallNrm.x) + (0.0f * 0.0f))) < 0.0f ||
           (proxy->kartCollide()->_68 == ((f32*)lbl_1_data_3918)[17]))) {
        hg->getKartCollisionInfo().wallNrm.y = 0.0f;
        hg->getKartCollisionInfo().wallNrm.normalise();
        m_a8.x = hg->getKartCollisionInfo().wallNrm.x;
        m_a8.y = hg->getKartCollisionInfo().wallNrm.y;
        m_a8.z = hg->getKartCollisionInfo().wallNrm.z;
        f32 temp_f5 = hg->getKartCollisionInfo().wallNrm.x;
        f32 temp_f4 = hg->getKartCollisionInfo().wallNrm.z;
        accum.x = temp_f5;
        accum.z = temp_f4;
        accum.y = 0.0f;
        if (EGG::Mathf::sqrt((temp_f4 * temp_f4) + ((temp_f5 * temp_f5) + (0.0f * 0.0f))) < 0.05f) {
          accum.x = sp20.x;
          accum.z = sp20.z;
          accum.y = 0.0f;
        }
        var_r21 = 1;
      }
    }
  }

  if ((hg->getKartCollisionInfo().flags & 4) && (field(1) & 0x200) &&
      !(proxy->kartCollide()->surfaceFlags & 0x10000)) {
    proxy->kartState()->field(2) |= 0x1000;
  }

  if ((var_r22 > 0) || (var_r21 != 0)) {
    field(3) |= 2;
    _34.x = accum.x;
    _34.y = accum.y;
    _34.z = accum.z;
    _34.normalise();
    s32 var_r27_2 = 0;
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
      mHwgTimer = ((s32*)lbl_1_data_3918)[17];
      if (var_r21 != 0) {
        mHwgTimer = ((s32*)lbl_1_data_3918)[17] * 2;
      }
    }
  }

  field(0) &= 0xFFFF7FFF;
  field(1) &= 0xFFFFFFFB;
  _a6 -= 1;
  if (_a6 < 0) {
    _a6 = 0;
  }

  if ((var_r23 > 0) || (hg->getKartCollisionInfo().flags & 1)) {
    mUp.normalise();
    u32 temp_r4_7 = field(3) & 0xFFFFFFBF;
    _4c.x = mUp.x;
    _4c.y = mUp.y;
    _4c.z = mUp.z;
    field(0) |= 0x40000;
    field(3) = temp_r4_7;
    if (!(proxy->kartState()->field(2) & 1)) {
      field(3) = temp_r4_7 & ~0x880;
    }
    if (Raceinfo_isAtLeastStage(RaceManager::spInstance, 2) != 0) {
      if (!(proxy->kartCollide()->surfaceFlags & 0x20) &&
          (proxy->kartCollide()->surfaceFlags & 0x40)) {
        fn_1_80068(proxy, 8, 1, 1.0f);
      }
      if (!(proxy->kartCollide()->surfaceFlags & 0x80) &&
          (proxy->kartCollide()->surfaceFlags & 0x100)) {
        fn_1_80068(proxy, 4, 1, 1.0f);
      }
    }
    if ((proxy->kartState()->field(2) & 0x400) && !(proxy->kartState()->field(3) & 0x800000)) {
      PlayerZipper_end(proxy->kartHalfPipe(), 1);
      if (!(proxy->kartState()->field(1) & 0x10)) {
        proxy->kartState()->field(3) |= 0x80000000;
      }
    }
    if (var_r25 != 0) {
      _a6 = 3;
    }
    if ((s16)_a6 > 0) {
      field(2) |= 0x40000000;
    } else {
      field(2) &= 0xBFFFFFFF;
    }
    if (!(proxy->kartState()->field(1) & 0x40000000)) {
      field(2) &= 0xFFFFF7FF;
    }
    if (var_r28 == 0) {
      proxy->kartState()->field(0) |= 0x200;
      EGG::Vector3f* speed = playerPointers_getSpeed(proxy);
      f32 temp_f31 = (mUp.z * speed->z) + ((mUp.x * speed->x) + (mUp.y * speed->y));
      if (temp_f31 < -22.0f) {
        proxy->kartState()->field(3) |= 0x40000000;
        f32 var_f1 = fabsf(temp_f31 * ((f32*)lbl_1_data_3918)[3]);
        if (1.0f < var_f1) {
          var_f1 = 1.0f;
        }
        fn_1_80068(proxy, 2, 1, var_f1);
      }
      if (!(proxy->kartState()->field(1) & 0x10)) {
        if (temp_f31 < -7.0f) {
          proxy->kartState()->field(3) |= 0x80000000;
        }
        fn_1_803EC(proxy);
        fn_1_354D84(fn_1_803EC(proxy));
        if (mAirtime > 0x3C) {
          fn_1_80068(proxy, 2, 1, 1.0f);
        }
      }
    }
    if ((field(2) & 0x40) && (*(s16*)((u8*)proxy->kartJump() + 0x38) <= 0)) {
      proxy->kartMove();
      PlayerSub10_endTrick(proxy->kartMove());
      proxy->kartDynamics()->_forceUpright = 1;
      PlayerTrick_end(*(void**)((u8*)proxy->kartMove() + 0x258));
    }
    mAirtime = 0;
  } else {
    if (var_r28 != 0) {
      proxy->kartState()->field(0) |= 0x800000;
    }
    u32 temp_r0_7 = mAirtime + 1;
    mAirtime = temp_r0_7;
    if (temp_r0_7 > 0x14) {
      proxy->kartState()->field(0) |= 0x8000;
      if (mAirtime == 0x14) {
        fn_1_80C90(proxy, 5, 0, 1);
      }
      f32 temp_f2 = playerPointers_getSpeed(proxy)->y;
      if ((temp_f2 - _7c) < 0.0f) {
        field(2) |= 4;
      }
      _7c = temp_f2;
    }
  }

  proxy->kartWheelPhysics(0);
  proxy->getPos();
}

KartState::~KartState() {}
}