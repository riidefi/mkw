
#pragma once

#include "KartSettings.hpp"
#include "egg/math/eggMatrix.hpp"
#include "egg/math/eggVector.hpp"

namespace Kart {
class KartPart {
  

public:
  KartPart(const KartSettings& kartSettings, u32 thing);
  const EGG::Matrix34f getPose() const { return pose; };

  // TODO : structure is still very wrong
  EGG::Vector3f pos;
  EGG::Matrix34f pose;
  u8 todo[0x90-0x3c];
};
}
