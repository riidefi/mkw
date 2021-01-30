#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct GXFifoObj;

void GXGetGPStatus(u8* overhi, u8* underlow, u8* readIdle, u8* cmdIdle,
                   u8* brkpt);
GXFifoObj* GXInit(void* buf, u32 size);

struct GXRenderModeObj {
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
};

#ifdef __cplusplus
}
#endif