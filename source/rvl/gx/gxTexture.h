#pragma once

#include <rk_types.h>
#include <decomp.h>

#include "gx.h"

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80170614..0x80170738
UNKNOWN_FUNCTION(GXGetTexBufferSize);
// PAL: 0x80170738..0x801707f8
UNKNOWN_FUNCTION(__GetImageTileCount);
// PAL: 0x801707f8..0x80170a04
void GXInitTexObj(GXTexObj* obj, void* image_ptr, u16 width, u16 height,
                  int format, int wrap_s, int wrap_t, int mipmap);
// PAL: 0x80170a04..0x80170a4c
UNKNOWN_FUNCTION(GXInitTexObjCI);
// PAL: 0x80170a4c..0x80170b50
void GXInitTexObjLOD(GXTexObj* obj, int min_filt, int mag_filt, f32 min_lod,
                     f32 max_lod, f32 lod_bias, int bias_clamp, int do_edge_lod,
                     int max_aniso);
// PAL: 0x80170b50..0x80170b64
UNKNOWN_FUNCTION(GXInitTexObjWrapMode);
// PAL: 0x80170b64..0x80170b6c
UNKNOWN_FUNCTION(GXInitTexObjTlut);
// PAL: 0x80170b6c..0x80170b94
UNKNOWN_FUNCTION(GXInitTexObjFilter);
// PAL: 0x80170b94..0x80170be8
UNKNOWN_FUNCTION(GXInitTexObjLODBias);
// PAL: 0x80170be8..0x80170bf0
UNKNOWN_FUNCTION(GXInitTexObjUserData);
// PAL: 0x80170bf0..0x80170bf8
UNKNOWN_FUNCTION(GXGetTexObjUserData);
// PAL: 0x80170bf8..0x80170c5c
UNKNOWN_FUNCTION(GXGetTexObjAll);
// PAL: 0x80170c5c..0x80170c68
UNKNOWN_FUNCTION(GXGetTexObjData);
// PAL: 0x80170c68..0x80170c7c
UNKNOWN_FUNCTION(GXGetTexObjWidth);
// PAL: 0x80170c7c..0x80170c90
UNKNOWN_FUNCTION(GXGetTexObjHeight);
// PAL: 0x80170c90..0x80170c98
UNKNOWN_FUNCTION(GXGetTexObjFmt);
// PAL: 0x80170c98..0x80170ca4
UNKNOWN_FUNCTION(GXGetTexObjWrapS);
// PAL: 0x80170ca4..0x80170cb0
UNKNOWN_FUNCTION(GXGetTexObjWrapT);
// PAL: 0x80170cb0..0x80170cbc
UNKNOWN_FUNCTION(GXGetTexObjMipMap);
// PAL: 0x80170cbc..0x80170da0
UNKNOWN_FUNCTION(GXGetTexObjLODAll);
// PAL: 0x80170da0..0x80170db4
UNKNOWN_FUNCTION(GXGetTexObjMinFilt);
// PAL: 0x80170db4..0x80170dc0
UNKNOWN_FUNCTION(GXGetTexObjMagFilt);
// PAL: 0x80170dc0..0x80170dc8
UNKNOWN_FUNCTION(GXGetTexObjTlut);
// PAL: 0x80170dc8..0x80170f2c
UNKNOWN_FUNCTION(GXLoadTexObjPreLoaded);
// PAL: 0x80170f2c..0x80170f80
void GXLoadTexObj(GXTexObj*, int texMapID);
// PAL: 0x80170f80..0x80170fa8
UNKNOWN_FUNCTION(GXInitTlutObj);
// PAL: 0x80170fa8..0x8017103c
UNKNOWN_FUNCTION(GXLoadTlut);
// PAL: 0x8017103c..0x801710f0
UNKNOWN_FUNCTION(GXInitTexCacheRegion);
// PAL: 0x801710f0..0x80171110
UNKNOWN_FUNCTION(GXInitTlutRegion);
// PAL: 0x80171110..0x80171158
UNKNOWN_FUNCTION(GXInvalidateTexAll);
// PAL: 0x80171158..0x8017116c
UNKNOWN_FUNCTION(GXSetTexRegionCallback);
// PAL: 0x8017116c..0x80171180
UNKNOWN_FUNCTION(GXSetTlutRegionCallback);
// PAL: 0x80171180..0x801711fc
UNKNOWN_FUNCTION(GXSetTexCoordScaleManually);
// PAL: 0x801711fc..0x80171260
UNKNOWN_FUNCTION(GXSetTexCoordBias);
// PAL: 0x80171260..0x801712f0
UNKNOWN_FUNCTION(__SetSURegs);
// PAL: 0x801712f0..0x80171458
UNKNOWN_FUNCTION(__GXSetSUTexRegs);
// PAL: 0x80171458..0x801717ac
UNKNOWN_FUNCTION(__GXSetTmemConfig);

#ifdef __cplusplus
}
#endif
