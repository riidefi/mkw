#pragma once

#include <Common/rk_types.h>

namespace Field {

struct MapdataCheckPath {
  u8 start; //!< [+0x00]
  u8 size;  //!< [+0x01]

  u8 last[6]; //!< [+0x02]
  u8 next[6]; //!< [+0x08]
};

} // namespace Field