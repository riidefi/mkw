#include "axfx.h"

#include <rvl/os/osAlloc.h>

AXFXAlloc __AXFXAlloc = __AXFXAllocFunction;
AXFXFree __AXFXFree = __AXFXFreeFunction;

// Symbol: __AXFXAllocFunction
// PAL: 0x8012e52c..0x8012e538
MARK_BINARY_BLOB(__AXFXAllocFunction, 0x8012e52c, 0x8012e538);
asm void* __AXFXAllocFunction(u32) {
  // clang-format off
  nofralloc;
  mr r4, r3;
  lwz r3, __OSCurrentHeap;
  b OSAllocFromHeap;
  // clang-format on
}

// Symbol: __AXFXFreeFunction
// PAL: 0x8012e538..0x8012e544
MARK_BINARY_BLOB(__AXFXFreeFunction, 0x8012e538, 0x8012e544);
asm void __AXFXFreeFunction(void*) {
  // clang-format off
  nofralloc;
  mr r4, r3;
  lwz r3, __OSCurrentHeap;
  b OSFreeToHeap;
  // clang-format on
}

// Symbol: AXFXSetHooks
// PAL: 0x8012e544..0x8012e550
MARK_BINARY_BLOB(AXFXSetHooks, 0x8012e544, 0x8012e550);
asm UNKNOWN_FUNCTION(AXFXSetHooks) {
  // clang-format off
  nofralloc;
  stw r3, __AXFXAlloc;
  stw r4, __AXFXFree;
  blr;
  // clang-format on
}

// Symbol: AXFXGetHooks
// PAL: 0x8012e550..0x8012e564
MARK_BINARY_BLOB(AXFXGetHooks, 0x8012e550, 0x8012e564);
asm UNKNOWN_FUNCTION(AXFXGetHooks) {
  // clang-format off
  nofralloc;
  lwz r0, __AXFXAlloc;
  stw r0, 0(r3);
  lwz r0, __AXFXFree;
  stw r0, 0(r4);
  blr;
  // clang-format on
}
