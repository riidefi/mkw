#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80124e80..0x80124ed4
void AXInit();
// PAL: 0x80124ed4..0x80124edc
u32 AXIsInit();

#ifdef __cplusplus
}
#endif
