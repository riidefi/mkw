#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801317e8..0x80131800
UNKNOWN_FUNCTION(BTUInterruptHandler);
// PAL: 0x80131800..0x801318dc
UNKNOWN_FUNCTION(BTA_Init);
// PAL: 0x801318dc..0x80131910
UNKNOWN_FUNCTION(BTA_CleanUp);
// PAL: 0x80131910..0x80131940
UNKNOWN_FUNCTION(bta_usb_close_evt);

#ifdef __cplusplus
}
#endif
