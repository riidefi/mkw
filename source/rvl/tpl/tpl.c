#include "tpl.h"

#include <rvl/gx/gxTexture.h>
#include <rvl/os/os.h>

void TPLBind(TPLPalette* pal) {
  u16 i;

  if (pal->version != 2142000)
    OSPanic("TPL.c", 0x19, "invalid version number for texture palette");

  pal->descriptorArray =
      (TPLDescriptor*)(((u32)(pal->descriptorArray)) + ((u32)pal));

  for (i = 0; i < pal->numDescriptors; i++) {
    if (pal->descriptorArray[i].textureHeader) {
      pal->descriptorArray[i].textureHeader =
          (TPLHeader*)(((u32)(pal->descriptorArray[i].textureHeader)) +
                       ((u32)pal));

      if (!(pal->descriptorArray[i].textureHeader->unpacked)) {
        pal->descriptorArray[i].textureHeader->data =
            (void*)((u32)(pal->descriptorArray[i].textureHeader->data) +
                    (u32)pal);
        pal->descriptorArray[i].textureHeader->unpacked = 1;
      }
    }

    if (pal->descriptorArray[i].CLUTHeader) {
      pal->descriptorArray[i].CLUTHeader =
          (TPLClutHeader*)((u32)(pal->descriptorArray[i].CLUTHeader) +
                           (u32)pal);

      if (!(pal->descriptorArray[i].CLUTHeader->unpacked)) {
        pal->descriptorArray[i].CLUTHeader->data =
            (void*)((u32)(pal->descriptorArray[i].CLUTHeader->data) + (u32)pal);
        pal->descriptorArray[i].CLUTHeader->unpacked = 1;
      }
    }
  }
}

TPLDescriptor* TPLGet(TPLPalette* pal, u32 id) {
  id %= pal->numDescriptors;
  return &pal->descriptorArray[id];
}

void TPLGetGXTexObjFromPalette(TPLPalette* pal, GXTexObj* to, u32 id) {
  TPLDescriptor* tdp = TPLGet(pal, id);
  int mipMap;

  if (tdp->textureHeader->minLOD == tdp->textureHeader->maxLOD)
    mipMap = 0;
  else
    mipMap = 1;

  GXInitTexObj(to, tdp->textureHeader->data, tdp->textureHeader->width,
               tdp->textureHeader->height, tdp->textureHeader->format,
               tdp->textureHeader->wrapS, tdp->textureHeader->wrapT, mipMap);

  GXInitTexObjLOD(to, tdp->textureHeader->minFilter,
                  tdp->textureHeader->magFilter, tdp->textureHeader->minLOD,
                  tdp->textureHeader->maxLOD, tdp->textureHeader->LODBias, 0,
                  tdp->textureHeader->edgeLODEnable, 0);
}
