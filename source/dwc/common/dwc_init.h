#pragma once

#include <dwc/common/dwc_memfunc.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  DWC_SVR_DEV,
  DWC_SVR_RELEASE,
  DWC_SVR_PROHIBITED // test
} DWC_AuthServer;
//! @brief Initialize the DWC library.
//!
//! @param[in] authSvr TODO...
int DWC_Init(DWC_AuthServer authSvr, const char* gameName, u32 gameCode,
             DWCAllocEx allocator, DWCFreeEx freeer);
void DWC_Shutdown();
u32 DWCi_GetGamecode();
#ifdef __cplusplus
}
#endif
