
#pragma once

#include "KartPart.hpp"

namespace Kart {
class KartWheelPhysics;
class KartWheel : public KartPart {
public:
  inline const KartWheelPhysics* getPhysics() const { return wheelPhysics; }
  inline KartWheelPhysics* getPhysics() { return wheelPhysics; }
private:
  // for kart the x coordinate is mirrored for the left wheels
  u32 xMirrored;
  u32 bspWheelIdx;
  KartWheelPhysics* wheelPhysics;
  // TODO more
};
}
