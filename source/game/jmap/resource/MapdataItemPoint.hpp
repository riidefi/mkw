#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataItemPoint {
  EGG::Vector3f position; // 00
  f32 deviation;          // 0C
  u16 parameters[2];      // 10 todo
};

} // namespace Field
