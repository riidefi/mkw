#pragma once

#include <rk_types.h>

namespace Net {

class RACEDATAPacket {
  u8 _00[0x40 - 0x00];
};
static_assert(sizeof(RACEDATAPacket) == 0x40);

}
