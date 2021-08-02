#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80020dd8..0x80020e0c
UNKNOWN_FUNCTION(__register_fragment);
// PAL: 0x80020e0c..0x80020e34
UNKNOWN_FUNCTION(__unregister_fragment);

#ifdef __cplusplus
}
#endif