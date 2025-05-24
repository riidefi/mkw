
#pragma once

#include "KartPart.hpp"
#include "KartPhysics.hpp"

namespace Kart {
class KartBody : public KartPart {
public:
  void requireSinkDepth(f32 sinkDepth);

  KartPhysics* getPhysics() { return mpPhysics; }
  const KartPhysics* getPhysics() const { return mpPhysics; }
  f32 getSinkDepth() const { return sinkDepth; }
private:
  KartPhysics* mpPhysics;
  f32 _94;
  f32 _98;
  f32 sinkDepth;
  u8 _90[0x224 - -0xa0];
};
}
