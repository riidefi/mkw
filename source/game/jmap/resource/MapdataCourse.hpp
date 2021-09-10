#pragma once

#include <rk_types.h>

namespace Field {

struct MapdataCourse {
  u32 magic;       // 00
  u32 fileSize;    // 04
  u16 numSections; // 08
  u16 headerSize;  // 0A
  u32 revision;    // 0C
  // Section offsets start here. 10
  s32 offsets[];
};

} // namespace Field
