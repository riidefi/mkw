#include "MiscPacketHandler.hpp"

#include "net/NetManager.hpp"

#include "net/packets/EVENT.hpp"
#include "net/packets/ITEM.hpp"

namespace Net {

void MiscPacketHandler::clearAidFromUnkBitfield(u32 aid) {
  m_unkBitfield_4 &= ~(1 << aid);
}

MiscPacketHandler::MiscPacketHandler()
    : _000(0), m_unk1(false), m_unkBitfield_4(0), m_unkBitfield_8(0),
      m_unkBitfield_C(0), m_unk10(0), m_unk12(3000) {
  EVENTHandler::createStaticInstance();
  ITEMHandler::createStaticInstance();
}

bool MiscPacketHandler::isPlayerLocal(u32 playerId) {
  bool isPlayerIdLocal = false;
  if (playerId == NetManager::getInstance()->getLocalPlayerId(0) ||
      playerId == NetManager::getInstance()->getLocalPlayerId(1)) {
    isPlayerIdLocal = true;
  }
  return isPlayerIdLocal;
}

} // namespace Net
