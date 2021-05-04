#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataJugemPoint {
  EGG::Vector3f position;
  EGG::Vector3f rotation;
  u16 id;
  s16 range;
};

} // namespace Field
