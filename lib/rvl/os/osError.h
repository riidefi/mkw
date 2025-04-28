#pragma once

#include <decomp.h>
#include <rk_types.h>

#include <stdio.h>

#include "osContext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*OSErrorHandler)(s16 error, OSContext* context, ...);

void OSReport(const char* msg, ...);
void OSVReport(const char* msg, va_list arg);
void OSPanic(const char* file, int line, const char* msg, ...);
OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler);
void __OSUnhandledException(u8, OSContext*, u32, u32);

void PackArgs();

extern u32 _unk_80385aa8;

#ifdef __cplusplus
}
#endif
