#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

void IPCInit(void);
void IPCReInit(void);
u32 IPCReadReg(u32);
void IPCWriteReg(u32, u32);
void* IPCGetBufferHi(void);
void* IPCGetBufferLo(void);
void IPCSetBufferLo(void*);

#ifdef __cplusplus
}
#endif
