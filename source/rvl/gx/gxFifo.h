#pragma once

#include <rvl/gx.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

void GXGetGPStatus(u8* overhi, u8* underlow, u8* readIdle, u8* cmdIdle,
                   u8* brkpt);

int GXGetGPFifo(GXFifoObj* fifo);

void GXGetFifoPtrs(const GXFifoObj* fifo, void** readPtr, void** writePtr);

void GXEnableBreakPt(void* breakPtr);
void GXDisableBreakPt(void);

// PAL: 0x8016c668..0x8016c7c8
UNKNOWN_FUNCTION(GXCPInterruptHandler);
// PAL: 0x8016c7c8..0x8016c854
UNKNOWN_FUNCTION(GXInitFifoBase);
// PAL: 0x8016c854..0x8016c94c
UNKNOWN_FUNCTION(CPGPLinkCheck);
// PAL: 0x8016c94c..0x8016cb2c
UNKNOWN_FUNCTION(GXSetCPUFifo);
// PAL: 0x8016cb2c..0x8016cdbc
UNKNOWN_FUNCTION(GXSetGPFifo);
// PAL: 0x8016cdbc..0x8016cebc
UNKNOWN_FUNCTION(__GXSaveFifo);
// PAL: 0x8016cebc..0x8016cec4
UNKNOWN_FUNCTION(__GXIsGPFifoReady);
// PAL: 0x8016cf10..0x8016cfa0
UNKNOWN_FUNCTION(GXGetCPUFifo);
// PAL: 0x8016d044..0x8016d04c
UNKNOWN_FUNCTION(GXGetFifoCount);
// PAL: 0x8016d04c..0x8016d054
UNKNOWN_FUNCTION(GXGetFifoWrap);
// PAL: 0x8016d054..0x8016d098
UNKNOWN_FUNCTION(GXSetBreakPtCallback);
// PAL: 0x8016d180..0x8016d1fc
UNKNOWN_FUNCTION(__GXFifoInit);
// PAL: 0x8016d1fc..0x8016d39c
UNKNOWN_FUNCTION(__GXCleanGPFifo);
// PAL: 0x8016d39c..0x8016d3a4
UNKNOWN_FUNCTION(GXGetCurrentGXThread);

#ifdef __cplusplus
}
#endif
