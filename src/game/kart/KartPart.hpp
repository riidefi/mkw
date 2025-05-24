
#pragma once

#include "KartSettings.hpp"

namespace Kart {
class KartPart {
  u8 todo[0x90];

public:
  KartPart(const KartSettings& kartSettings, u32 thing);
};
}
