#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a9528..0x801a9548
UNKNOWN_FUNCTION(SystemCallVector);
// PAL: 0x801a9548..0x801a95a8
UNKNOWN_FUNCTION(__OSInitSystemCall);

#ifdef __cplusplus
}
#endif
