#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80005f34
void* memcpy(void*, const void*, u32);
// PAL: 0x80006038
void* memset(void*, s32, u32);

#ifdef __cplusplus
} // extern "C"
#endif
