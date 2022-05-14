#pragma once

#include <decomp.h>
#include <rk_types.h>

#include <stdio.h>

#include "osContext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*OSErrorHandler)(s16 error, OSContext* context, ...);

// PAL: 0x801a25d0..0x801a265c
void OSReport(const char* msg, ...);
// PAL: 0x801a265c..0x801a2660
void OSVReport(const char* msg, va_list arg);
// PAL: 0x801a2660..0x801a278c
void OSPanic(const char* file, int line, const char* msg, ...);
// PAL: 0x801a278c..0x801a2a14
OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler);
// PAL: 0x801a2a14..0x801a2e84
void __OSUnhandledException(u8, OSContext*, u32, u32);

void PackArgs();

extern u32 _unk_80385aa8;

#ifdef __cplusplus
}
#endif
