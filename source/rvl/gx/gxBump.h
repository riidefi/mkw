#pragma once

// Credit: kiwi515

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _GXIndTexStageID { GX_IND_TEX_STAGE_0 } GXIndTexStageID;

typedef enum _GXIndTexScale { GX_IND_TEX_SCALE_0 } GXIndTexScale;

typedef enum _GXIndTexMtxID { GX_IND_TEX_MTX_0 } GXIndTexMtxID;

void GXSetIndTexCoordScale(GXIndTexStageID, GXIndTexScale, GXIndTexScale);
void GXSetIndTexMtx(GXIndTexMtxID, const f32*, int);

void GXSetNumIndStages(int);
void GXSetTevDirect(int);

void __GXSetIndirectMask(int);

void GXSetTevSwapMode(int, int, int);

void GXSetTevOrder(int, int, int, int colorChanID);

#ifdef __cplusplus
}
#endif
