#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8000f360..0x8000f41c
UNKNOWN_FUNCTION(__copy_longs_aligned);
// PAL: 0x8000f41c..0x8000f4c4
UNKNOWN_FUNCTION(__copy_longs_rev_aligned);
// PAL: 0x8000f4c4..0x8000f584
UNKNOWN_FUNCTION(__copy_longs_unaligned);
// PAL: 0x8000f584..0x8000f630
UNKNOWN_FUNCTION(__copy_longs_rev_unaligned);

#ifdef __cplusplus
}
#endif
