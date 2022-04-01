#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "osContext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*__OSInterruptHandler)(s16 interrupt, OSContext* context);

// PAL: 0x801a65ac..0x801a65c0
int OSDisableInterrupts(void);
// PAL: 0x801a65c0..0x801a65d4
int OSEnableInterrupts(void);
// PAL: 0x801a65d4..0x801a65f8
int OSRestoreInterrupts(int level);
// PAL: 0x801a65f8..0x801a660c
__OSInterruptHandler __OSSetInterruptHandler(s16 interrupt,
                                             __OSInterruptHandler handler);
// PAL: 0x801a660c..0x801a661c
__OSInterruptHandler __OSGetInterruptHandler(s16 interrupt);
// PAL: 0x801a661c..0x801a66e0
void __OSInterruptInit(void);
// PAL: 0x801a693c..0x801a69bc
u32 __OSMaskInterrupts(u32);
// PAL: 0x801a69bc..0x801a6a3c
u32 __OSUnmaskInterrupts(u32);
// PAL: 0x801a6a3c..0x801a6ce0
void __OSDispatchInterrupt(u8 exception, OSContext* context);

extern volatile OSTime __OSLastInterruptTime;
extern volatile s16 __OSLastInterrupt;
extern volatile u32 __OSLastInterruptSrr0;

#ifdef __cplusplus
}
#endif
