#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80192f7c..0x80192fc8
void IPCInit(void);
// PAL: 0x80192fc8..0x80193010
void IPCReInit(void);
// PAL: 0x80193010..0x80193020
u32 IPCReadReg(u32);
// PAL: 0x80193020..0x80193030
void IPCWriteReg(u32, u32);
// PAL: 0x80193030..0x80193038
void* IPCGetBufferHi(void);
// PAL: 0x80193038..0x80193040
void* IPCGetBufferLo(void);
// PAL: 0x80193040..0x80193048
void IPCSetBufferLo(void*);

#ifdef __cplusplus
}
#endif
