#pragma once

#include <rk_types.h>

#include "os.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*__OSExceptionHandler)(u8 exception, OSContext* context);

// PAL: 0x801a0388
__OSExceptionHandler __OSSetExceptionHandler(u8 exception,
                                             __OSExceptionHandler handler);

#ifdef __cplusplus
}
#endif
