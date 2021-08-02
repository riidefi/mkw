#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* buffer, s32 capacity);

#ifdef __cplusplus
}
#endif
