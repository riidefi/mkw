#pragma once

#include <string.h>

#include <rk_types.h>

namespace System {

class Mii {
public:
  void reset() { memset(mBuffer, 0, sizeof(mBuffer)); }

private:
  u8 mBuffer[0x4c];
};

} // namespace System
