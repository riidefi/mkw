#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

int DWC_GetLastError(int* errorCode);
s32 DWC_GetLastErrorEx(s32* errorCode, u32* errorType);
void DWC_ClearError();

#ifdef __cplusplus
}
#endif
