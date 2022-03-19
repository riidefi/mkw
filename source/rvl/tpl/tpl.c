#include "tpl.h"

#include <rvl/gx/gxTexture.h>
#include <rvl/os/osError.h>

void TPLBind(TPLPalette* pal) {
  if (pal->version != 2142000)
    OSPanic("TPL.c", 0x19, "invalid version number for texture palette");

  pal->descriptors = (TPLDescriptor*)(((u32)(pal->descriptors)) + ((u32)pal));

  for (u16 i = 0; i < pal->num_descriptors; i++) {
    if (pal->descriptors[i].header) {
      pal->descriptors[i].header =
          (TPLHeader*)(((u32)(pal->descriptors[i].header)) + ((u32)pal));
      if (!(pal->descriptors[i].header->unpacked)) {
        pal->descriptors[i].header->data =
            (void*)((u32)(pal->descriptors[i].header->data) + (u32)pal);
        pal->descriptors[i].header->unpacked = 1;
      }
    }
    if (pal->descriptors[i].clut_header) {
      pal->descriptors[i].clut_header =
          (TPLClutHeader*)((u32)(pal->descriptors[i].clut_header) + (u32)pal);
      if (!(pal->descriptors[i].clut_header->unpacked)) {
        pal->descriptors[i].clut_header->data =
            (void*)((u32)(pal->descriptors[i].clut_header->data) + (u32)pal);
        pal->descriptors[i].clut_header->unpacked = 1;
      }
    }
  }
}

TPLDescriptor* TPLGet(TPLPalette* pal, u32 id) {
  return &pal->descriptors[id % pal->num_descriptors];
}

void TPLGetGXTexObjFromPalette(TPLPalette* pal, GXTexObj* to, u32 id) {
  TPLDescriptor* desc = TPLGet(pal, id);
  int mipMap = desc->header->lod_min == desc->header->lod_max ? 0 : 1;
  GXInitTexObj(to, desc->header->data, desc->header->width,
               desc->header->height, desc->header->format, desc->header->wrap_s,
               desc->header->wrap_t, mipMap);
  GXInitTexObjLOD(to, desc->header->filter_min, desc->header->filter_mag,
                  desc->header->lod_min, desc->header->lod_max,
                  desc->header->lod_bias, 0, desc->header->edge_lod_enabled, 0);
}
