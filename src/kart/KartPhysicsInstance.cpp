
#include "KartPhysicsInstance.hpp"

namespace Kart {
void destroyPhysicsInstance(f32 idk) {
  _808b6a08 = idk;
  gKartPhysics = nullptr;
  _809c1994 = 0;
}

KartPhysics* createPhysicsInstance(bool isBike, const KartParam& kartParam, void* unk, s32 tireCount) {
  gKartPhysics = new KartPhysics(isBike);
  f32 idk = gKartPhysics->mpHitboxGroup->initHitboxes(kartParam.bsp->hitboxes, unk, tireCount);
  gKartPhysics->_fc = idk;
  gKartPhysics->mpDynamics->setBspParams(kartParam.bsp->cuboids[0], kartParam.bsp->cuboids[1], false, kartParam.bsp->angVel0Factor);
  return gKartPhysics;
}
}
