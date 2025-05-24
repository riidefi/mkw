
#pragma once

#include "rk_types.h"

#include "KartParam.hpp"
#include "KartPhysics.hpp"

f32 _808b6a08 = 1.5f;
namespace Kart {
KartPhysics* gKartPhysics;
u16 _809c1994;

void destroyPhysicsInstance(f32);
KartPhysics* createPhysicsInstance(bool isBike, const KartParam& stats, void* unk, s32 tireCount);
}
