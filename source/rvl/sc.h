#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SCAspectRatio {
  SC_ASPECT_RATIO_4x3,
  SC_ASPECT_RATIO_16x9
} SCAspectRatio;

u8 SCGetProgressiveMode();
u8 SCGetEuRgb60Mode();
u8 SCGetAspectRatio();

#ifdef __cplusplus
}
#endif
