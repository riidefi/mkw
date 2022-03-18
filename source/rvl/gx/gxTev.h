#pragma once

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

void GXSetTevOp(GXTevStageID, int tevMode);
void GXSetTevColorIn(GXTevStageID, int a, int b, int c, int d);
void GXSetTevAlphaIn(GXTevStageID, int a, int b, int c, int d);
void GXSetTevColorOp(GXTevStageID, int, int, int, int, int);
void GXSetTevAlphaOp(GXTevStageID, int, int, int, int, int);
void GXSetTevColor(GXTevRegID, GXColor);

void GXSetTevKColor(GXTevRegID, GXColor);
void GXSetTevKColorSel(GXTevStageID, int);
void GXSetTevKAlphaSel(GXTevStageID, int);

void GXSetTevSwapModeTable(GXTevSwapSel, int, int, int, int);

void GXSetAlphaCompare(int, int, int, int, int);
void GXSetZTexture(int, int zTexFormat, int);

void GXSetNumTevStages(int);

#ifdef __cplusplus
}
#endif
