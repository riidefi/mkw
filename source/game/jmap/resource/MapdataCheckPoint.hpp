#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataCheckPoint {
  EGG::Vector2f left;  //!< [+0x00] First point of the checkpoint.
  EGG::Vector2f right; //!< [+0x08] Second point of the checkpoint.
  u8 jugemIndex;       //!< [+0x10] Respawn point.
  u8 lapCheck; //!< [+0x11] 0 - start line, 1-254 - key checkpoints, 255 -
               //!< normal
  u8 prevPt;   //!< [+0x12] Last checkpoint. 0xFF -> sequence edge
  u8 nextPt;   //!< [+0x13] Next checkpoint. 0xFF -> sequence edge
};

} // namespace Field
