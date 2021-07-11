#pragma once

#include <rvl/gx/gx.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  u16 numEntries;
  u8 unpacked;
  u8 pad8;
  int format;
  void* data;
} TPLClutHeader;

typedef struct {
  u16 height;
  u16 width;
  u32 format;
  void* data;
  int wrapS;
  int wrapT;
  int minFilter;
  int magFilter;
  float LODBias;
  u8 edgeLODEnable;
  u8 minLOD;
  u8 maxLOD;
  u8 unpacked;
} TPLHeader;

typedef struct {
  TPLHeader* textureHeader;
  TPLClutHeader* CLUTHeader;
} TPLDescriptor;

typedef struct {
  u32 version;
  u32 numDescriptors;
  TPLDescriptor* descriptorArray;
} TPLPalette;

void TPLBind(TPLPalette*);
TPLDescriptor* TPLGet(TPLPalette*, u32);

void TPLGetGXTexObjFromPalette(TPLPalette*, GXTexObj*, u32);
void TPLGetGXTexObjFromPaletteCI(TPLPalette*, GXTexObj*, GXTlutObj*, int, u32);

#ifdef __cplusplus
}
#endif
