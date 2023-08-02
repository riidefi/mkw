#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct GXFifoObj {
  u8 _00[0x80];
} GXFifoObj;

// PAL: 0x8016b850..0x8016bd54
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

#ifdef __cplusplus
}
#endif
