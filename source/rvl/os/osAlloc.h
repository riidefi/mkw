#pragma once

#include <rk_types.h>

#include "decomp.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801a0d9c..0x801a0e48
UNKNOWN_FUNCTION(DLInsert);
// PAL: 0x801a0e48..0x801a0f40
UNKNOWN_FUNCTION(OSAllocFromHeap);
// PAL: 0x801a0f40..0x801a0fb8
UNKNOWN_FUNCTION(OSFreeToHeap);
// PAL: 0x801a0fb8..0x801a0fc8
UNKNOWN_FUNCTION(set_CurrHeap);
// PAL: 0x801a0fc8..0x801a1038
UNKNOWN_FUNCTION(OSInitAlloc);
// PAL: 0x801a1038..0x801a10a4
UNKNOWN_FUNCTION(OSCreateHeap);

#ifdef __cplusplus
}
#endif