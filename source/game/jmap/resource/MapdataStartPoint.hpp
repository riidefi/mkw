#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataStartPoint {
  EGG::Vector3f position; // 00
  EGG::Vector3f rotation; // 0c
                          // --- Pre Revision 1830: End of structure
  s16 playerIndex;        // 18
  u16 _;                  // 1a - 1c
};

} // namespace Field
