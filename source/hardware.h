#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// Hardware registers.
volatile u32 HOLLYWOOD_REGS[137] : 0xcd000000;

volatile u16 __CPRegs[0x33] : 0xcc000000;
volatile u16 __VIRegs[0x3b] : 0xcc002000;
volatile u32 __PIRegs[0x0c] : 0xcc003000;
volatile u16 __MEMRegs[0x40] : 0xcc004000;
volatile u16 __DSPRegs[0x20] : 0xcc005000;
volatile u32 __ACRRegs[0x89] : 0xcd000000;
volatile u32 __DIRegs[0x10] : 0xcc006000;
volatile u32 __SIRegs[0x40] : 0xcc006400;
volatile u32 __EXIRegs[0x10] : 0xcd006800;
volatile u32 __AIRegs[0x08] : 0xcd006c00;

#ifdef __cplusplus
}
#endif
