#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x800bbb80..0x800bbba0
UNKNOWN_FUNCTION(RFLGetWorkSize);
// PAL: 0x800bbba0..0x800bbf08
UNKNOWN_FUNCTION(RFLInitResAsync);

#ifdef __cplusplus
}
#endif
