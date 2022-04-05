#include "__ppc_eabi_init.h"

#include <decomp.h>

// Extern function references.
// PAL: 0x8019f1a8
extern void __OSFPRInit(void);
// PAL: 0x801a04a0
extern void __OSPSInit(void);
// PAL: 0x801a1ae4
extern void __OSCacheInit(void);

// Symbol: __init_hardware
// PAL: 0x80006348..0x8000636c
__declspec(section ".init") asm void __init_hardware() {
  // clang-format off
  nofralloc;
  mfmsr r0;
  ori r0, r0, 0x2000;
  mtmsr r0;
  mflr r31;
  bl __OSPSInit;
  bl __OSFPRInit;
  bl __OSCacheInit;
  mtlr r31;
  blr;
  // clang-format on
}

// Symbol: __flush_cache
// PAL: 0x8000636c..0x800063a0
MARK_BINARY_BLOB(__flush_cache, 0x8000636c, 0x800063a0);
__declspec(section ".init") asm void __flush_cache() {
  // clang-format off
  nofralloc;
  lis r5, 0xffff;
  ori r5, r5, 0xfff1;
  and r5, r5, r3;
  subf r3, r5, r3;
  add r4, r4, r3;
lbl_80006380:
  dcbst 0, r5;
  sync;
  icbi 0, r5;
  addic r5, r5, 8;
  addic. r4, r4, -8;
  bge lbl_80006380;
  isync;
  blr;
  // clang-format on
}
