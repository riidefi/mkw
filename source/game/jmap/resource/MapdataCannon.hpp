#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataCannonPoint {
  EGG::Vector3f position;
  EGG::Vector3f rotation;
  u16 id;
  u16 shootEffect;
};

} // namespace Field
