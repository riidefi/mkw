#pragma once

// Credit: kiwi515

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

void GXBegin(int, int formatIndex, int);
#define GXEnd() (void)0

#ifdef __cplusplus
}
#endif
