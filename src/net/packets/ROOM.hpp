#pragma once

#include <rk_types.h>

namespace Net {

// Credits: https://wiki.tockdom.com/wiki/Network_Protocol/ROOM
#pragma options align=packed
struct ROOMPacket {
  // Message Type:
  // 1: Starting room
  // 2: Adding another as a friend
  // 3: Someone joined room
  // 4: Chat
  u8 messageType;
  
  // These are parameters, but its use depends on the message type.
  u16 _1;
  u8 _3;
};
#pragma options align=reset
static_assert(sizeof(ROOMPacket) == 0x4);

class ROOMHandler {
  u8 _00[0x80 - 0x00];
};
static_assert(sizeof(ROOMHandler) == 0x80);

}
