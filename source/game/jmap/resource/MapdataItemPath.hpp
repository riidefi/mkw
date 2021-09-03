#pragma once

#include <rk_types.h>

namespace Field {

struct MapdataItemPath {
  u8 start; //!< [+0x00]
  u8 size;  //!< [+0x01]

  u8 last[6]; //!< [+0x02]
  u8 next[6]; //!< [+0x08]

private:
  u8 _[2]; //!< [+0x0E] Pad?
};

} // namespace Field
