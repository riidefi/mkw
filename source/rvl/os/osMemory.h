#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a72fc..0x801a735c
UNKNOWN_FUNCTION(OSInitMessageQueue);
// PAL: 0x801a735c..0x801a7424
UNKNOWN_FUNCTION(OSSendMessage);
// PAL: 0x801a7424..0x801a7500
UNKNOWN_FUNCTION(OSReceiveMessage);
// PAL: 0x801a7500..0x801a75d0
UNKNOWN_FUNCTION(OSJamMessage);

#ifdef __cplusplus
}
#endif