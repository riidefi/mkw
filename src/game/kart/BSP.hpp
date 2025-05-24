
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

struct BspWheel {
  u16 enabled;
  // simple spring-mass-damper suspension
  f32 springStiffness;
  f32 dampingFactor;
  f32 maxTravel;
  EGG::Vector3f centerPos;
  // Wheel X axis rotation (0 in vanilla)
  f32 xRot;
  f32 wheelRadius;
  // bounding sphere used for collision
  f32 colSphereRadius;
  u32 _28;
};
static_assert(sizeof(BspWheel) == 0x2c);

class BSP {
public:
  f32 initialYpos;
  BspHitbox hitboxes[BSP_HITBOX_COUNT];
  EGG::Vector3f cuboids[2];
  f32 angVel0Factor;
  f32 _1a0;
  BspWheel wheels[4];
  u32 _254;
  u32 _258;
};
static_assert(sizeof(BSP) == 0x25c);
}
