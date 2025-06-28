#pragma once

#include "net/packets/PacketHolder.hpp"
#include "net/packets/HEADER.hpp"
#include "net/packets/RACEHEADER1.hpp"
#include "net/packets/RACEHEADER2.hpp"
#include "net/packets/SELECT.hpp"
#include "net/packets/RACEDATA.hpp"
#include "net/packets/USER.hpp"
#include "net/packets/ITEM.hpp"
#include "net/packets/EVENT.hpp"

#include <rk_types.h>

namespace Net {

class RACEPacketHolder {
private:
  // Maybe this is an array?
  PacketHolder<HEADERPacket> *m_headerPacket;
  PacketHolder<RACEHEADER1Packet> *m_raceHeader1Packet;
  PacketHolder<RACEHEADER2Packet> *m_raceHeader2Packet;
  PacketHolder<SELECTPacket> *m_selectPacket;
  PacketHolder<RACEDATAPacket> *m_raceDataPacket;
  PacketHolder<USERPacket> *m_userPacket;
  PacketHolder<ITEMPacket> *m_itemPacket;
  PacketHolder<EVENTPacket> *m_eventPacket;

  // 0x8065a3dc
  RACEPacketHolder();
  // 0x8065a474
  ~RACEPacketHolder();
};
static_assert(sizeof(RACEPacketHolder) == 0x20);

}
