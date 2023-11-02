
#pragma once

#include "rk_types.h"

#include "KartPhysics.hpp"

f32 _808b6a08 = 1.5f;
namespace Kart {
KartPhysics* gKartPhysics;
u16 _809c1994;

void destroyPhysicsInstance(f32);
void createPhysicsInstance();
}
