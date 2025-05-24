#pragma once

// Credit: kiwi515

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _GXAttr {
  GX_ATTR_0,
  GX_ATTR_1,
  GX_ATTR_2,
  GX_ATTR_3,
  GX_ATTR_4,
  GX_ATTR_5,
  GX_ATTR_6,
  GX_ATTR_7,
  GX_ATTR_8,

  GX_ATTR_VTX,

  GX_ATTR_VTX_POS = GX_ATTR_VTX,
  GX_ATTR_VTX_NRM,

  GX_ATTR_VTX_CLR,
  GX_ATTR_VTX_CLR_COUNT = 2,

  GX_ATTR_VTX_TEX_COORD = GX_ATTR_VTX_CLR + GX_ATTR_VTX_CLR_COUNT,
  GX_ATTR_VTX_TEX_COORD_COUNT = 8,

  GX_ATTR_14 = 14,
  GX_ATTR_15,
  GX_ATTR_16,
  GX_ATTR_17,
  GX_ATTR_18,
  GX_ATTR_19,
  GX_ATTR_20,

  GX_ATTR_COUNT = GX_ATTR_VTX_TEX_COORD + GX_ATTR_VTX_TEX_COORD_COUNT,
  GX_ATTR_VTX_COUNT = GX_ATTR_COUNT - GX_ATTR_VTX,

  GX_ATTR_INVALID = 0xFF
} GXAttr;

typedef struct _GXVtxDescList {
  GXAttr mAttr; // at 0x0
  int WORD_0x4;
} GXVtxDescList[];

typedef struct _GXVtxAttrFmtList {
  GXAttr mAttr; // at 0x0
  int WORD_0x4;
  int WORD_0x8;
  char BYTE_0xC;
} GXVtxAttrFmtList[];

// PAL: 0x8016d3a4..0x8016d608
void GXSetVtxDesc(GXAttr, int);

// PAL: 0x8016dc34..0x8016dc68
void GXClearVtxDesc(void);

// PAL: 0x8016dc68..0x8016de08
void GXSetVtxAttrFmt(int formatIndex, GXAttr, int, int, int fracValue);

// PAL: 0x8016e32c..0x8016e36c
void GXSetArray(GXAttr, const void*, u8);
// PAL: 0x8016e36c..0x8016e37c
void GXInvalidateVtxCache(void);
// PAL: 0x8016e37c..0x8016e5a4
void GXSetTexCoordGen2(int, int function, int, int, int, int);
// PAL: 0x8016e5a4..0x8016e5c8
void GXSetNumTexGens(int);

// PAL: 0x8016d608..0x8016d814
UNKNOWN_FUNCTION(GXSetVtxDescv);
// PAL: 0x8016d814..0x8016d8c4
UNKNOWN_FUNCTION(__GXSetVCD);
// PAL: 0x8016d8c4..0x8016d9f0
UNKNOWN_FUNCTION(__GXCalculateVLim);
// PAL: 0x8016d9f0..0x8016dba4
UNKNOWN_FUNCTION(GXGetVtxDesc);
// PAL: 0x8016dba4..0x8016dc34
UNKNOWN_FUNCTION(GXGetVtxDescv);
// PAL: 0x8016de08..0x8016dfcc
UNKNOWN_FUNCTION(GXSetVtxAttrFmtv);
// PAL: 0x8016dfcc..0x8016e04c
UNKNOWN_FUNCTION(__GXSetVAT);
// PAL: 0x8016e04c..0x8016e2b8
UNKNOWN_FUNCTION(GXGetVtxAttrFmt);
// PAL: 0x8016e2b8..0x8016e32c
UNKNOWN_FUNCTION(GXGetVtxAttrFmtv);

#ifdef __cplusplus
}
#endif
