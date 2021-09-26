#pragma once

#include <rk_types.h>

#include "osContext.h"
#include "osThread.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*__OSExceptionHandler)(u8 exception, OSContext* context);

__OSExceptionHandler __OSGetExceptionHandler(u8 exception);

// PAL: 0x801a0388
__OSExceptionHandler __OSSetExceptionHandler(u8 exception,
                                             __OSExceptionHandler handler);

#ifdef __cplusplus
}
#endif
