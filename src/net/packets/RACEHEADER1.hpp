#pragma once

#include <rk_types.h>

namespace Net {

struct RACEHEADER1Packet {
  u8 _00[0x28 - 0x00];
};
static_assert(sizeof(RACEHEADER1Packet) == 0x28);

class RACEHEADER1Handler {
  u8 _000[0x260 - 0x000];
};
static_assert(sizeof(RACEHEADER1Handler) == 0x260);

}
