#include "BoxColUnit.hpp"

BoxColUnit::BoxColUnit()
    : position(nullptr), radius(0.0f), range(0.0f), flags(0),
      userData(nullptr) {}
BoxColUnit::~BoxColUnit() {}

void BoxColUnit::set(const EGG::Vector3f* pos, u32 flags, void* userData,
                     float radius, float thickness) {
  const f32 bouding_radius = radius + thickness;

  this->position = pos;
  this->radius = radius;
  this->range = bouding_radius;
  this->flags = flags | BOXCOL_FLAG_STATIC;
  this->userData = userData;
  this->xMax = pos->x + bouding_radius;
  this->xMin = pos->x - bouding_radius;
}

void BoxColUnit::makeDynamic() { this->flags &= ~BOXCOL_FLAG_STATIC; }

void BoxColUnit::resizeSphere(float radius, float thickness) {
  this->radius = radius;
  this->range = radius + thickness;
  this->flags |= BOXCOL_FLAG_CHANGE_SIZE;
}
