#pragma once

#include <rk_types.h>

namespace Net {

struct EVENTPacket {
  u8 _00[0xf8 - 0x00];
};
static_assert(sizeof(EVENTPacket) == 0xf8);

class EVENTHandler {
public:
  static void createStaticInstance();

  static EVENTHandler* getInstance() { return spInstance; }

private:
  u8 _0000[0x2b88 - 0x0000];

  static EVENTHandler* spInstance;
};
static_assert(sizeof(EVENTHandler) == 0x2b88);

} // namespace Net
