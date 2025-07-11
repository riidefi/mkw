#include "SELECT.hpp"

namespace Net {

const u8* SELECTHandler::getPlayerIdToAidMapping() const {
  return m_sendPacket.m_playerIdToAidMapping;
}

} // namespace Net
