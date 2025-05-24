#pragma once

// Credit: kiwi515

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _GXIndTexStageID { GX_IND_TEX_STAGE_0 } GXIndTexStageID;

typedef enum _GXIndTexScale { GX_IND_TEX_SCALE_0 } GXIndTexScale;

typedef enum _GXIndTexMtxID { GX_IND_TEX_MTX_0 } GXIndTexMtxID;

// PAL: 0x801717ac..0x80171814
UNKNOWN_FUNCTION(GXSetTevIndirect);
// PAL: 0x80171a6c..0x80171b38
UNKNOWN_FUNCTION(GXSetIndTexOrder);
// PAL: 0x80171ba0..0x80171bf4
UNKNOWN_FUNCTION(GXSetTevIndWarp);
// PAL: 0x80171bf4..0x80171bf8
UNKNOWN_FUNCTION(__GXUpdateBPMask);
// PAL: 0x80171c28..0x80171c4c
UNKNOWN_FUNCTION(__GXFlushTextureState);

// PAL: 0x80171968..0x80171a6c
void GXSetIndTexCoordScale(GXIndTexStageID, GXIndTexScale, GXIndTexScale);
// PAL: 0x80171814..0x80171968
void GXSetIndTexMtx(GXIndTexMtxID, const f32*, int);

// PAL: 0x80171b38..0x80171b58
void GXSetNumIndStages(int);
// PAL: 0x80171b58..0x80171ba0
void GXSetTevDirect(int);

// PAL: 0x80171bf8..0x80171c28
void __GXSetIndirectMask(int);

#ifdef __cplusplus
}
#endif
