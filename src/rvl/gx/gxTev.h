#pragma once

#include <rk_types.h>
#include <decomp.h>

#include "gx.h"

// Credit: kiwi515

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _GXTevSwapSel {
  GX_TEV_SWAP_SEL_0,
  GX_TEV_SWAP_SEL_1,
  GX_TEV_SWAP_SEL_2,
  GX_TEV_SWAP_SEL_3,
  GX_TEV_SWAP_SEL_COUNT
} GXTevSwapSel;

typedef enum _GXTevColorChan {

} GXTevColorChan;

typedef enum _GXTevStageID {
  GX_TEV_STAGE_ID_0,
  GX_TEV_STAGE_ID_1,
  GX_TEV_STAGE_ID_2,
  GX_TEV_STAGE_ID_COUNT = 16
} GXTevStageID;

typedef enum _GXTevColorArg {

} GXTevColorArg;

typedef enum _GXTevRegID {
  GX_TEV_REG_ID_0,
  GX_TEV_REG_ID_1,
  GX_TEV_REG_ID_2,
  GX_TEV_REG_ID_3,
} GXTevRegID;

// PAL: 0x80171c4c..0x80171ce0
void GXSetTevOp(GXTevStageID, int tevMode);
// PAL: 0x80171ce0..0x80171d20
void GXSetTevColorIn(GXTevStageID, int a, int b, int c, int d);
// PAL: 0x80171d20..0x80171d60
void GXSetTevAlphaIn(GXTevStageID, int a, int b, int c, int d);
// PAL: 0x80171d60..0x80171db8
void GXSetTevColorOp(GXTevStageID, int, int, int, int, int);
// PAL: 0x80171db8..0x80171e10
void GXSetTevAlphaOp(GXTevStageID, int, int, int, int, int);
// PAL: 0x80171e10..0x80171e70
void GXSetTevColor(GXTevRegID, GXColor);

// PAL: 0x80171ed4..0x80171f30
void GXSetTevKColor(GXTevRegID, GXColor);
// PAL: 0x80171f30..0x80171f80
void GXSetTevKColorSel(GXTevStageID, int);
// PAL: 0x80171f80..0x80171fd0
void GXSetTevKAlphaSel(GXTevStageID, int);

// PAL: 0x8017200c..0x80172088
void GXSetTevSwapModeTable(GXTevSwapSel, int, int, int, int);

// PAL: 0x80172088..0x801720c0
void GXSetAlphaCompare(int, int, int, int, int);
// PAL: 0x801720c0..0x8017214c
void GXSetZTexture(int, int zTexFormat, int);

// PAL: 0x801722a8..0x801722cc
void GXSetNumTevStages(int);

// PAL: 0x80171e70..0x80171ed4
UNKNOWN_FUNCTION(GXSetTevColorS10);
// PAL: 0x80171fd0..0x8017200c
void GXSetTevSwapMode(int, int, int);
// PAL: 0x8017214c..0x801722a8
void GXSetTevOrder(int, int, int, int colorChanID);

#ifdef __cplusplus
}
#endif
