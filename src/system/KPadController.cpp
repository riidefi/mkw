#include "KPadController.hpp"

#include <system/KPadDirector.hpp>

namespace System {
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
