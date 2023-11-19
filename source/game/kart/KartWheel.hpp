
#pragma once

#include "KartPart.hpp"

namespace Kart {
class KartWheelPhysics;
class KartWheel : public KartPart {
public:
  inline KartWheelPhysics* getWheelPhysics() { return wheelPhysics; }
private:
  // for kart the x coordinate is mirrored for the left wheels
  u32 xMirrored;
  u32 bspWheelIdx;
  KartWheelPhysics* wheelPhysics;
  // TODO more
};
}
