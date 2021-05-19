
#include <EGG/WiiSportsAssert.hpp>
#include <EGG/core/eggColorFader.hpp>
#include <revolution/gx.h>
#include <revolution/mtx.h>
#include <revolution/os.h>

#include <EGG/WiiSportsAssert.hpp>

namespace EGG {

ColorFader::ColorFader(f32 leftX, f32 bottomY, f32 width, f32 height,
                       nw4r::ut::Color color, Fader::EStatus status) {
  mFrameCount = 20;
  mFlag = FLAG_8;
  mFrame = 0;
  // This line is useless due to the call to setColor() below
  mColor = nw4r::ut::Color::WHITE;
  mLeftX = leftX;
  mBottomY = bottomY;
  mRightX = leftX + width;
  mTopY = bottomY + height;
  setColor(color);
  setStatus(status);
  mFlag |= FLAG_2;
}

// Wii sports function. This is the correct placement.
// Not linked in MKW.
void ColorFader::setFrame(u16 frame) {
  WiiSportsAssert(frame, "eggColorFader.cpp", 63, "frame != 0");
  mFrame = frame;
}

void ColorFader::setColor(nw4r::ut::Color color) {
  mColor.Set(color.r, color.g, color.b, mColor.a);
}

void ColorFader::setStatus(Fader::EStatus status) {
  if (status == ESTATUS_OPAQUE) {
    mStatus = ESTATUS_OPAQUE;
    mColor.a = 0xFF;
  } else if (status == ESTATUS_HIDDEN) {
    mStatus = ESTATUS_HIDDEN;
    mColor.a = 0;
  }
}

bool ColorFader::fadeIn() {
  bool doFadeIn = mStatus == ESTATUS_OPAQUE;
  if (doFadeIn) {
    mStatus = ESTATUS_FADE_IN;
    mFrame = 0;
  }

  return doFadeIn;
}

bool ColorFader::fadeOut() {
  const bool doFadeOut = mStatus == ESTATUS_HIDDEN;
  if (doFadeOut) {
    mStatus = ESTATUS_FADE_OUT;
    mFrame = 0;
  }

  return doFadeOut;
}

int ColorFader::calc() {
  int result = 0;
  switch (mStatus) {
  case ESTATUS_HIDDEN:
    mColor.a = 0;
    break;
  case ESTATUS_OPAQUE:
    mColor.a = 0xFF;
    break;
  case ESTATUS_FADE_IN: {
    u16 curFrame = mFrame;
    u16 maxFrame = mFrameCount;
    mFrame++; // Advance the current frame!
    // If our current frame has completed the FADE_IN
    if (curFrame > maxFrame) {
      mStatus = ESTATUS_HIDDEN;
      curFrame = maxFrame;
      // ??? TODO
      result = (mFlag & FLAG_1) != 0;
    }
    // set the alpha to opaque - how much progression made
    mColor.a = 0xFF - 0xFF * ((u32)curFrame / mFrameCount);
    break;
  }
  case ESTATUS_FADE_OUT: {
    u16 curFrame = mFrame;
    u16 maxFrame = mFrameCount;
    // If the animation is completed.
    if (curFrame > maxFrame) {
      if (curFrame > maxFrame + 1) {
        mStatus = ESTATUS_OPAQUE;
        result = (mFlag & FLAG_4) != 0;
      }
      curFrame = maxFrame = mFrameCount;
    }
    // Set the alpha to HIDDEN (0) + amount of progress made.
    mColor.a = 0xFF * ((u32)curFrame / maxFrame);
    break;
  }
  }
  return result;
}

void ColorFader::draw() {
  Mtx44 projectionMtx;
  Mtx positionMtx;

  // If the quad is fully transparent, don't draw it!
  if (mColor.a == 0)
    return;

  // Setup the projection matrix
  MTXOrtho(projectionMtx, mTopY, mBottomY, mLeftX, mRightX, 0, 1);
  GXSetProjection(projectionMtx, GX_ORTHOGRAPHIC);

  // Set the viewport
  GXSetViewport(mLeftX, mTopY, mRightX - mLeftX, mBottomY - mTopY, 1, 0);

  // Set scissoring
  GXSetScissor((u32)mLeftX, (u32)mTopY, (u32)(mRightX - mLeftX),
               (u32)(mBottomY - mTopY));

  // Set the position matrix
  MTXIdentity(positionMtx);
  GXLoadPosMtxImm(positionMtx, 0);
  GXSetCurrentMtx(0);

  // Set up for rendering f32 POS-only QUADS
  GXClearVtxDesc();
  GXInvalidateVtxCache();
  GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
  GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);

  // Set material channels
  GXSetNumChans(1);
  GXSetChanMatColor(GX_COLOR0A0, mColor);
  GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE,
                GX_AF_NONE);

  // Disable texture and indirect
  GXSetNumTexGens(0);
  GXSetNumIndStages(0);
  __GXSetIndirectMask(0);

  // Setup TEV
  GXSetNumTevStages(1);
  GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
  GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);

  // Setup blending
  if (mColor.a != 0xFF)
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA,
                   GX_LO_SET); // translucency
  else                         // If fully opaque, no need to blend
    GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_SET);

  // Color/Alpha Update
  GXSetColorUpdate(GX_TRUE);
  GXSetAlphaUpdate(GX_TRUE);

  // Disable Z comparison
  GXSetZMode(0, GX_NEVER, 0);
  GXSetCullMode(GX_CULL_BACK);

  GXBegin(GX_QUADS, GX_VTXFMT0, 4);
  {
    GXPosition3f32(mLeftX, mTopY, 0.0f);     // top left
    GXPosition3f32(mRightX, mTopY, 0.0f);    // top right
    GXPosition3f32(mRightX, mBottomY, 0.0f); // bottom right
    GXPosition3f32(mLeftX, mBottomY, 0.0f);  // bottom left
  }
  GXEnd();
}

ColorFader::~ColorFader() {}

} // namespace EGG
