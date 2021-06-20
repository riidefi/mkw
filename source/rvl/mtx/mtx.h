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

// PAL: 0x80199d04
void PSMTXIdentity(Mtx);
// PAL: 0x80199d30
void PSMTXCopy(const Mtx, Mtx);

void PSMTXRotAxisRad(Mtx, const Vec*, f32);

#ifdef __cplusplus
}
#endif
