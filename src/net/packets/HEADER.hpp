#pragma once

#include <rk_types.h>

namespace Net {

struct HEADERPacket {
  u8 _00[0x10 - 0x00];
};
static_assert(sizeof(HEADERPacket) == 0x10);

} // namespace Net
