#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a81b8..0x801a8224
UNKNOWN_FUNCTION(__OSReboot);
// PAL: 0x801a8224..0x801a8238
UNKNOWN_FUNCTION(OSGetSaveRegion);

#ifdef __cplusplus
}
#endif
