#pragma once

#include <rk_types.h>

namespace Net {

struct SELECTPacket {
  u8 _00[0x38 - 0x00];
};
static_assert(sizeof(SELECTPacket) == 0x38);

class SELECTHandler {
  u8 _000[0x3f8 - 0x000];
};
static_assert(sizeof(SELECTHandler) == 0x3f8);

}
