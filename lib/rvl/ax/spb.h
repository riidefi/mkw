#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXSPB {
  char unknown[120];
} AXSPB;

AXSPB* __AXGetStudio();
void __AXSPBInit();

#ifdef __cplusplus
}
#endif
