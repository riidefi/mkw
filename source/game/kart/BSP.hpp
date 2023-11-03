
#pragma once

#define BSP_HITBOX_COUNT 0x10

namespace Kart {
struct BspHitbox {
  u16 enabled;
  EGG::Vector3f pos;
  f32 radius;
  u16 wallOnly; // only collide with walls
  u16 tireCollisionIndex;
};
static_assert(sizeof(BspHitbox) == 0x18);

class BSP {
public:
  f32 initialYpos;
  BspHitbox hitboxes[BSP_HITBOX_COUNT];
  EGG::Vector3f cuboids[2];
  f32 angVel0Factor;
  u8 _todo[0x25c - 0x1a0];
};
}
