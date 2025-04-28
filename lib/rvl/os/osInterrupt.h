#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "osContext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*__OSInterruptHandler)(s16 interrupt, OSContext* context);

int OSDisableInterrupts(void);
int OSEnableInterrupts(void);
int OSRestoreInterrupts(int level);
__OSInterruptHandler __OSSetInterruptHandler(s16 interrupt,
                                             __OSInterruptHandler handler);
__OSInterruptHandler __OSGetInterruptHandler(s16 interrupt);
void __OSInterruptInit(void);
u32 __OSMaskInterrupts(u32);
u32 __OSUnmaskInterrupts(u32);
void __OSDispatchInterrupt(u8 exception, OSContext* context);

extern volatile OSTime __OSLastInterruptTime;
extern volatile s16 __OSLastInterrupt;
extern volatile u32 __OSLastInterruptSrr0;

#ifdef __cplusplus
}
#endif
