#pragma once

#include <rk_types.h>

namespace Net {

struct ITEMPacket {
  u8 _0[0x8 - 0x0];
};
static_assert(sizeof(ITEMPacket) == 0x8);

class ITEMHandler {
public:

  static void createStaticInstance();

  static ITEMHandler *getInstance() {
    return spInstance;
  }
private:
  u8 _000[0x184 - 0x000];
  
  static ITEMHandler *spInstance;
};
static_assert(sizeof(ITEMHandler) == 0x184);

}
