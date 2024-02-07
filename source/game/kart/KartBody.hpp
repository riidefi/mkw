
#pragma once

#include "KartPart.hpp"
#include "KartPhysics.hpp"

namespace Kart {
class KartBody : public KartPart {
public:
  KartPhysics* getPhysics() { return mpPhysics; }
  const KartPhysics* getPhysics() const { return mpPhysics; }
private:
  KartPhysics* mpPhysics;
  u8 _84[0x224 - -0x84];
};
}
