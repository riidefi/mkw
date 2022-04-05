#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*AXFXAlloc)(u32);
typedef void (*AXFXFree)(void*);

extern AXFXAlloc __AXFXAlloc;
extern AXFXFree __AXFXFree;

// PAL: 0x8012e52c..0x8012e538
void* __AXFXAllocFunction(u32);
// PAL: 0x8012e538..0x8012e544
void __AXFXFreeFunction(void*);
// PAL: 0x8012e544..0x8012e550
UNKNOWN_FUNCTION(AXFXSetHooks);
// PAL: 0x8012e550..0x8012e564
UNKNOWN_FUNCTION(AXFXGetHooks);

#ifdef __cplusplus
}
#endif
