#pragma once

#include <rk_types.h>

namespace Net {

struct ITEMPacket {
  u8 _0[0x8 - 0x0];
};
static_assert(sizeof(ITEMPacket) == 0x8);

class ITEMHandler {
  u8 _000[0x184 - 0x000];
};
static_assert(sizeof(ITEMHandler) == 0x184);

}
