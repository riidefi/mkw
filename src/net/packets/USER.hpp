#pragma once

#include <rk_types.h>

namespace Net {

struct USERPacket {
  u8 _00[0xc0 - 0x00];
};
static_assert(sizeof(USERPacket) == 0xc0);

class USERHandler {
public:
  void update(); 

  static USERHandler *getInstance() {
    return spInstance;
  }
private:
  u8 _000[0x9f0 - 0x000];

  static USERHandler *spInstance;
};
static_assert(sizeof(USERHandler) == 0x9f0);

}
