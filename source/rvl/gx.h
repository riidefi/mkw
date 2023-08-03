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
  int tv_mode;       // 0x00
  u16 fb_width;      // 0x04
  u16 efb_height;    // 0x06
  u16 xfb_height;    // 0x08
  u16 vi_x;          // 0x0a
  u16 vi_y;          // 0x0c
  u16 vi_width;      // 0x0e
  u16 vi_height;     // 0x10
  int vi_xfb;        // 0x14
  u8 field;          // 0x18
  u8 aa;             // 0x19
  u8 sample[12][2];  // 0x1a
  u8 vert_filter[7]; // 0x32
} GXRenderModeObj;

void GXFlush(void);

#ifdef __cplusplus
}
#endif
