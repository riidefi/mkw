#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  f32 x, y, z;
} Vec;

typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];

void PSMTXRotAxisRad(Mtx m, const Vec* axis, f32 rad);

#ifdef __cplusplus
}
#endif
