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

#ifdef __cplusplus
}
#endif
