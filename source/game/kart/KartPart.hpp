
#pragma once

namespace Kart {
class KartSettings;
class KartPart {
  u8 todo[0x90];

public:
  KartPart(const KartSettings& kartSettings, u32 thing);
};
}
