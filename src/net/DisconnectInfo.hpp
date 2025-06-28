#pragma once

#include <rk_types.h>

namespace Net {

// Each value yields a different error screen
enum DisconnectType {
  DISCONNECT_TYPE_NONE = 0x0,
  DISCONNECT_TYPE_ERROR_CODE = 0x1, // standard error code screen
  DISCONNECT_TYPE_BAD_MII_NAME = 0x2,
  DISCONNECT_TYPE_CANT_JOIN_FRIEND = 0x3,    // sends user back to friend roster
  DISCONNECT_TYPE_DISK_EJECTED = 0x4,        // user ejected disk during login
  DISCONNECT_TYPE_UNRECOVERABLE_ERROR = 0x5, // informs user to reboot
};

struct DisconnectInfo {
  DisconnectType type;
  s32 code;

  // reset() 805e3f4c
};

} // namespace Net
