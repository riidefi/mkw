#pragma once

#include "gx.h"

#ifdef __cplusplus
extern "C" {
#endif

void GXInitTexObj(GXTexObj* obj, void* image_ptr, u16 width, u16 height,
                  int format, int wrap_s, int wrap_t, int mipmap);

void GXInitTexObjLOD(GXTexObj* obj, int min_filt, int mag_filt, f32 min_lod,
                     f32 max_lod, f32 lod_bias, int bias_clamp, int do_edge_lod,
                     int max_aniso);

void GXLoadTexObj(GXTexObj*, int texMapID);

#ifdef __cplusplus
}
#endif
