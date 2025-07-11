#pragma once

#include <rk_types.h>

#include "net/packets/RACEDATA.hpp"
#include "net/packets/EVENT.hpp"

namespace Net {

class MiscPacketHandler {
public:
  MiscPacketHandler();

  void clearAidFromUnkBitfield(u32 aid);

  bool isPlayerLocal(u32 playerId);

  static MiscPacketHandler* getInstance() { return spInstance; }

  static MiscPacketHandler* spInstance;

private:
  u8 _000;
  bool m_unk1;
  u32 m_unkBitfield_4;
  u32 m_unkBitfield_8;
  u32 m_unkBitfield_C;
  u16 m_unk10;
  u16 m_unk12;
  RACEDATAPacket m_sendRACEDATAPackets[2]; // 0x14 - 0x94
  EVENTPacket m_sendEVENTPackets;          // 0x94 - 0x18c
  u8 _18c[0x1c8 - 0x18c];
};
static_assert(sizeof(MiscPacketHandler) == 0x1c8);

} // namespace Net
