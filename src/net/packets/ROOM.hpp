#pragma once

#include <rk_types.h>

namespace Net {
  
enum RoomRole {
  ROLE_HOST = 0x0,
  ROLE_GUEST = 0x1,
};

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
public:
  void init(RoomRole role);

  void reset();

  static ROOMHandler *getInstance() {
    return spInstance;
  }
private:
  u8 _00[0x80 - 0x00];

  static ROOMHandler *spInstance;
};
static_assert(sizeof(ROOMHandler) == 0x80);

}
