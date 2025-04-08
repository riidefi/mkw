#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

// Hardware registers.
volatile u32 HOLLYWOOD_REGS[137] AT_ADDRESS(0xcd000000);

volatile u16 __CPRegs[0x33] AT_ADDRESS(0xcc000000);
volatile u16 __VIRegs[0x3b] AT_ADDRESS(0xcc002000);
volatile u32 __PIRegs[0x0c] AT_ADDRESS(0xcc003000);
volatile u16 __MEMRegs[0x40] AT_ADDRESS(0xcc004000);
volatile u16 __DSPRegs[0x20] AT_ADDRESS(0xcc005000);
volatile u32 __ACRRegs[0x89] AT_ADDRESS(0xcd000000);
volatile u32 __DIRegs[0x10] AT_ADDRESS(0xcc006000);
volatile u32 __SIRegs[0x40] AT_ADDRESS(0xcc006400);
volatile u32 __EXIRegs[0x10] AT_ADDRESS(0xcd006800);
volatile u32 __AIRegs[0x08] AT_ADDRESS(0xcd006c00);

#ifdef __cplusplus
}
#endif
