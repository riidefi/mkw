#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef u8 GXBool;

typedef struct GXFifoObj {
  u8 _00[0x80];
} GXFifoObj;

GXFifoObj* GXInit(void* buf, u32 size);

void GXSetDrawSync(u16 token);

typedef struct GXRenderModeObj {
  int tv_mode;
  u16 fb_width;
  u16 efb_height;
  u16 xfb_height;
  u16 vi_x;
  u16 vi_y;
  u16 vi_width;
  u16 vi_height;
  int vi_xfb;
  u8 field;
  u8 aa;
  u8 sample[12][2];
  u8 vert_filter[7];
} GXRenderModeObj;

f32 GXGetYScaleFactor(u16 efb_height, u16 xfb_height);
u16 GXGetNumXfbLines(u16 efb_height, f32 y_scale_factor);
void GXSetDispCopySrc(u16 left, u16 top, u16 width, u16 height);
void GXSetDispCopyDst(u16 width, u16 height);
u32 GXSetDispCopyYScale(f32 y_scale_factor);

#ifdef __cplusplus
}
#endif
