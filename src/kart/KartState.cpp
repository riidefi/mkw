#include <rk_types.h>
#include <decomp.h>

#include "KartState.hpp"

extern EGG::Vector3f lbl_802A4100;

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
}
