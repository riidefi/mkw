#pragma once

#include <rk_types.h>

namespace Net {

struct USERPacket {
  u8 _00[0xc0 - 0x00];
};
static_assert(sizeof(USERPacket) == 0xc0);

class USERHandler {
  u8 _000[0x9f0 - 0x000];
};
static_assert(sizeof(USERHandler) == 0x9f0);

}
