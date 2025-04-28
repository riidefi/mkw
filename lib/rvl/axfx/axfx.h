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

void* __AXFXAllocFunction(u32);
void __AXFXFreeFunction(void*);

#ifdef __cplusplus
}
#endif
