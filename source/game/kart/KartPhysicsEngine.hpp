
#pragma once

#include "egg/math/eggVector.hpp"
#include "KartObjectProxy.hpp"

namespace Kart {
extern f32 sinkDepthFactor;

class KartPhysicsEngine : public KartObjectProxy {
public:
  void registerSuspLimits(const EGG::Vector3f& travelVector);

  inline f32 getYScale() const { return yScale; }
private:
  u8 _0[0x60 - 0xc];
  f32 yScale;
  u8 _64[0x9c - 0x64];
};
}
