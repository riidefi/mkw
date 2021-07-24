#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int DWC_GetLastError(int* errorCode);
int DWC_GetLastErrorEx(int* errorCode, int* errorType);
void DWC_ClearError();

#ifdef __cplusplus
}
#endif
