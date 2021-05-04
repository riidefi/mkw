#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataGeoObj {
  u16 id; // 00 object id
  u16 _;  // 02 pad?

  // TODO: generic TRS type (note: computed in order SRT)

  EGG::Vector3f translation; // 04
  EGG::Vector3f rotation;    // 10
  EGG::Vector3f scale;       // 1c

  s16 pathId;       // 28
  u16 settings[8];  // 2a
  u16 presenceFlag; // 3a
};

} // namespace Field
