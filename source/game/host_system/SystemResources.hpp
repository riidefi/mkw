#pragma once

#include <rk_types.h>

namespace System {

enum eSystemResource {
  SYS_RES_RFL,
  SYS_RES_HOME_BUTTON,
  SYS_RES_HOME_BUTTON_SE,
  SYS_RES_GLOBE,
  SYS_RES_CHANNEL, // ChRes

  SYS_RES_NUM_MAIN = SYS_RES_CHANNEL
};

namespace Resource {

const char* GetResourcePath(eSystemResource idx);
u32 GetResourceID(eSystemResource idx);

} // namespace Resource

} // namespace System
