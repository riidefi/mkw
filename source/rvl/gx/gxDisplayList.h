#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80172e00..0x80172eb4
UNKNOWN_FUNCTION(GXBeginDisplayList);
// PAL: 0x80172eb4..0x80172f64
UNKNOWN_FUNCTION(GXEndDisplayList);
// PAL: 0x80172f64..0x80172fd8
UNKNOWN_FUNCTION(GXCallDisplayList);

#ifdef __cplusplus
}
#endif
