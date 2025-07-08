#pragma once

#include <rk_types.h>

namespace Net {

struct SELECTPacket {
  u8 _00[0x28 - 0x00];
  u8 m_playerIdToAidMapping[12];
  u8 _34[0x38 - 0x34];
};
static_assert(sizeof(SELECTPacket) == 0x38);

class SELECTHandler {
public:
  const u8 *getPlayerIdToAidMapping() const;

  static SELECTHandler *getInstance() {
    return spInstance;
  }

private:
  u8 _000[0x008 - 0x000];
  SELECTPacket m_sendPacket;
  SELECTPacket m_recvPackets[12];
  u8 _2e0[0x3f8 - 0x2e0];

  static SELECTHandler *spInstance;
};
static_assert(sizeof(SELECTHandler) == 0x3f8);

}
