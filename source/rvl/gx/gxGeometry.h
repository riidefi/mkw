#pragma once

// Credit: kiwi515

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void GXBegin(int, int formatIndex, int);
static void GXEnd(void) {}

#ifdef __cplusplus
}
#endif
