#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

void DBInit(void);
void __DBExceptionDestinationAux(void);
void __DBExceptionDestination(void);
BOOL __DBIsExceptionMarked(u8 exc);
void DBPrintf(const char* msg, ...);

#ifdef __cplusplus
}
#endif
