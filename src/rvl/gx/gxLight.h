#pragma once

// Credit: kiwi515

#include <rk_types.h>
#include <decomp.h>

#include "gx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GXLightObj {
  char UNK_0x0[64];
} GXLightObj;

typedef enum _GXLightID { _GXLightID_dummy } GXLightID;

typedef enum _GXSpotFn { GX_SPOT_FN_0 } GXSpotFn;

typedef enum _GXDistAttnFn { GX_DIST_ATTN_FN_0 } GXDistAttnFn;

// PAL: 0x80170314..0x80170320
void GXInitLightColor(GXLightObj*, GXColor*);
// PAL: 0x80170198..0x801701a8
void GXInitLightPos(GXLightObj*, float, float, float);
// PAL: 0x801701c4..0x801701e0
void GXInitLightDir(GXLightObj*, float, float, float);
// PAL: 0x80170208..0x80170314
void GXInitSpecularDir(GXLightObj*, float, float, float);
// PAL: 0x8016ff40..0x801700c8
void GXInitLightSpot(GXLightObj*, float, GXSpotFn);
// PAL: 0x8016ff20..0x8016ff30
void GXInitLightAttnA(GXLightObj*, float, float, float);
// PAL: 0x801700c8..0x80170198
void GXInitLightDistAttn(GXLightObj*, float, float, GXDistAttnFn);
// PAL: 0x8016ff30..0x8016ff40
void GXInitLightAttnK(GXLightObj*, float, float, float);
// PAL: 0x8016ff04..0x8016ff20
void GXInitLightAttn(GXLightObj*, float, float, float, float, float, float);
// PAL: 0x801701a8..0x801701c4
void GXGetLightPos(const GXLightObj*, float*, float*, float*);
// PAL: 0x801701e0..0x80170208
void GXGetLightDir(const GXLightObj*, float*, float*, float*);

// PAL: 0x8017039c..0x80170474
void GXSetChanAmbColor(int, GXColor);
// PAL: 0x80170474..0x8017054c
void GXSetChanMatColor(int, GXColor);
// PAL: 0x8017054c..0x80170570
void GXSetNumChans(int nChans);
// PAL: 0x80170570..0x80170614
void GXSetChanCtrl(int, int, int, int, int, int, int);

// PAL: 0x80170320..0x8017039c
UNKNOWN_FUNCTION(GXLoadLightObjImm);

#ifdef __cplusplus
}
#endif
