#pragma once

#include <rvl/gx/gx.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  u16 numEntries;
  u8 unpacked;
  u8 _;
  int format;
  void* data;
} TPLClutHeader;

typedef struct {
  u16 height;
  u16 width;
  u32 format;
  void* data;
  int wrap_s;
  int wrap_t;
  int filter_min;
  int filter_mag;
  float lod_bias;
  u8 edge_lod_enabled;
  u8 lod_min;
  u8 lod_max;
  u8 unpacked;
} TPLHeader;

typedef struct {
  TPLHeader* header;
  TPLClutHeader* clut_header;
} TPLDescriptor;

typedef struct {
  u32 version;
  u32 num_descriptors;
  TPLDescriptor* descriptors;
} TPLPalette;

void TPLBind(TPLPalette*);
TPLDescriptor* TPLGet(TPLPalette*, u32);

void TPLGetGXTexObjFromPalette(TPLPalette*, GXTexObj*, u32);
void TPLGetGXTexObjFromPaletteCI(TPLPalette*, GXTexObj*, GXTlutObj*, int, u32);

#ifdef __cplusplus
}
#endif
