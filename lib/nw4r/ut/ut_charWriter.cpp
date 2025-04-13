#include "ut_charWriter.hpp"

#include <decomp.h>

#include <rvl/gx/gxAttr.h>
#include <rvl/gx/gxBump.h>
#include <rvl/gx/gxGeometry.h>
#include <rvl/gx/gxLight.h>
#include <rvl/gx/gxPixel.h>
#include <rvl/gx/gxTev.h>
#include <rvl/gx/gxTexture.h>
#include <rvl/gx/gxVert.h>

// Source:
// https://github.com/kiwi515/ogws/blob/master/src/nw4r/ut/ut_CharWriter.cpp
// Credit: kiwi515
// Credit: GibHaltmannKill

namespace {
inline void SetupGXCommon() {
  static const nw4r::ut::Color fog = 0;

  GXSetFog(0, 0.0f, 0.0f, 0.0f, 0.0f, fog);
  GXSetTevSwapModeTable(GX_TEV_SWAP_SEL_0, 0, 1, 2, 3);
  GXSetZTexture(0, 17, 0);
  GXSetNumChans(1);
  GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
  GXSetChanCtrl(5, 0, 0, 0, 0, 0, 2);
  GXSetNumTexGens(1);
  GXSetTexCoordGen2(0, 1, 4, 60, 0, 125);
  GXSetNumIndStages(0);
  GXSetBlendMode(1, 4, 5, 15);
}
} // namespace

namespace nw4r {
namespace ut {

CharWriter::LoadingTexture CharWriter::mLoadingTexture;

// TODO
CharWriter::CharWriter() {}

// PAL: 0x800b2eb0
CharWriter::~CharWriter() {}

inline void CharWriter::SetColorMapping(Color color1, Color color2) {
  mColorMapping.COLOR_0x0 = color1;
  mColorMapping.COLOR_0x4 = color2;
}

inline void CharWriter::SetTextColor(Color color) {
  mTextColor.mStart = color;
  UpdateVertexColor();
}

inline void CharWriter::SetupGXDefault() {
  SetupGXCommon();
  GXSetNumTevStages(1);
  GXSetTevDirect(0);
  GXSetTevSwapMode(GX_TEV_STAGE_ID_0, 0, 0);
  GXSetTevOrder(GX_TEV_STAGE_ID_0, 0, 0, 4);
  GXSetTevOp(GX_TEV_STAGE_ID_0, 0);
  GXSetVtxAttrFmt(0, GX_ATTR_VTX, 1, 4, 0);
  GXSetVtxAttrFmt(0, GX_ATTR_VTX_CLR, 1, 5, 0);
  GXSetVtxAttrFmt(0, GX_ATTR_VTX_TEX_COORD, 1, 2, 0xf);
  GXClearVtxDesc();
  GXSetVtxDesc(GX_ATTR_VTX, 1);
  GXSetVtxDesc(GX_ATTR_VTX_CLR, 1);
  GXSetVtxDesc(GX_ATTR_VTX_TEX_COORD, 1);
}

void CharWriter::SetupGX() {
  mLoadingTexture.Reset();
  if ((u32)mColorMapping.COLOR_0x0 != 0 ||
      (u32)mColorMapping.COLOR_0x4 != 0xFFFFFFFF) {
    SetupGXWithColorMapping(mColorMapping.COLOR_0x0, mColorMapping.COLOR_0x4);
  } else if (mFont) {
    switch (mFont->GetTextureFormat()) {
    case 0:
    case 1:
      SetupGXCommon();
      GXSetNumTevStages(1);
      GXSetTevDirect(0);
      GXSetTevSwapMode(GX_TEV_STAGE_ID_0, 0, 0);
      GXSetTevOrder(GX_TEV_STAGE_ID_0, 0, 0, 4);
      GXSetTevColorIn(GX_TEV_STAGE_ID_0, 0xf, 0xf, 0xf, 10);
      GXSetTevAlphaIn(GX_TEV_STAGE_ID_0, 7, 4, 5, 7);
      GXSetTevColorOp(GX_TEV_STAGE_ID_0, 0, 0, 0, 1, 0);
      GXSetTevAlphaOp(GX_TEV_STAGE_ID_0, 0, 0, 0, 1, 0);
      GXSetVtxAttrFmt(0, GX_ATTR_VTX, 1, 4, 0);
      GXSetVtxAttrFmt(0, GX_ATTR_VTX_CLR, 1, 5, 0);
      GXSetVtxAttrFmt(0, GX_ATTR_VTX_TEX_COORD, 1, 2, 0xf);
      GXClearVtxDesc();
      GXSetVtxDesc(GX_ATTR_VTX, 1);
      GXSetVtxDesc(GX_ATTR_VTX_CLR, 1);
      GXSetVtxDesc(GX_ATTR_VTX_TEX_COORD, 1);
      break;
    case 2:
    case 3:
      SetupGXDefault();
      break;
    case 4:
    case 5:
    case 6:
      SetupGXDefault();
      break;
    default:
      SetupGXDefault();
      break;
    }
  } else {
    SetupGXDefault();
  }
}

void CharWriter::SetFontSize(float width, float height) {
  SetScale(width / mFont->GetWidth(), height / mFont->GetHeight());
}

void CharWriter::SetFontSize(float height) {
  const float scale = height / mFont->GetHeight();
  SetScale(scale);
}

float CharWriter::GetFontWidth() const { return mScale.x * mFont->GetWidth(); }

float CharWriter::GetFontHeight() const {
  return mScale.y * mFont->GetHeight();
}

float CharWriter::GetFontAscent() const {
  return mScale.y * mFont->GetAscent();
}

float CharWriter::GetFontDescent() const {
  return mScale.y * mFont->GetDescent();
}

void CharWriter::EnableLinearFilter(bool b1, bool b2) {
  mFilter.WORD_0x0 = b1 != false;
  mFilter.WORD_0x4 = b2 != false;
}

float CharWriter::Print(u16 ch) {
  Glyph glyph; // at 0x8

  mFont->GetGlyph(&glyph, ch);

  float xOfs;
  float ret;

  if (mWidthFixedFlag) {
    ret = mFixedWidth;
    xOfs = (ret - glyph.BYTE_0x6 * mScale.x) / 2 + (glyph.BYTE_0x4 * mScale.x);
  } else {
    ret = glyph.BYTE_0x6 * mScale.x;
    xOfs = glyph.BYTE_0x4 * mScale.x;
  }

  PrintGlyph(mCursor.x + xOfs, mCursor.y, mCursor.z, glyph);
  mCursor.x += ret;

  return ret;
}

inline void CharWriter::LoadTexture(const Glyph& glyph) {
  GXTexObj texObj;
  LoadingTexture loadingTexture;

  loadingTexture.s32_0x0 = 0;
  loadingTexture.PTR_0x4 = glyph.PTR_0x0; // r0
  loadingTexture.mFilter = mFilter;

  if (loadingTexture != mLoadingTexture) {
    GXInitTexObj(&texObj, glyph.PTR_0x0, glyph.SHORT_0xC, glyph.SHORT_0xE,
                 glyph.WORD_0x8, 0, 0, 0);
    GXInitTexObjLOD(&texObj, mFilter.WORD_0x0, mFilter.WORD_0x4, 0, 0, 0, 0.0f,
                    0.0f, 0.0f);
    GXLoadTexObj(&texObj, 0);
    mLoadingTexture = loadingTexture;
  }
}

void CharWriter::PrintGlyph(float x, float y, float z, const Glyph& glyph) {
  u32 left;
  u32 top;
  u32 right;
  u32 bottom;

  u16 normLeft;
  u16 normTop;
  u16 normRight;
  u16 normBottom;

  float x2;
  float y2;

  x2 = x + (glyph.cellWidth * mScale.x);
  y2 = y + (glyph.cellHeight * mScale.y);

  left = glyph.SHORT_0x10;
  normLeft = 0x8000 * left / glyph.SHORT_0xC;

  top = glyph.SHORT_0x12;
  normTop = 0x8000 * top / glyph.SHORT_0xE;

  right = left + glyph.cellWidth;
  normRight = 0x8000 * right / glyph.SHORT_0xC;

  bottom = top + glyph.cellHeight;
  normBottom = 0x8000 * bottom / glyph.SHORT_0xE;

  LoadTexture(glyph);

  GXBegin(0x80, 0, 4);

  GXPosition3f32(x, y, z);
  GXColor1u32(mVertexColor.mTopLeft);
  GXTexCoord2u16(normLeft, normTop);

  GXPosition3f32(x2, y, z);
  GXColor1u32(mVertexColor.mTopRight);
  GXTexCoord2u16(normRight, normTop);

  GXPosition3f32(x2, y2, z);
  GXColor1u32(mVertexColor.mBottomRight);
  GXTexCoord2u16(normRight, normBottom);

  GXPosition3f32(x, y2, z);
  GXColor1u32(mVertexColor.mBottomLeft);
  GXTexCoord2u16(normLeft, normBottom);

  GXEnd();
}

void CharWriter::UpdateVertexColor() {
  mVertexColor.mTopLeft = mTextColor.mStart;
  mVertexColor.mTopRight = (mGradationMode != GradMode_Horizontal)
                               ? mTextColor.mStart
                               : mTextColor.mEnd;
  mVertexColor.mBottomLeft = (mGradationMode != GradMode_Vertical)
                                 ? mTextColor.mStart
                                 : mTextColor.mEnd;
  mVertexColor.mBottomRight =
      (mGradationMode == GradMode_None) ? mTextColor.mStart : mTextColor.mEnd;

  mVertexColor.mTopLeft.mChannels.a =
      (mVertexColor.mTopLeft.mChannels.a * _unk42) / 0xFF,
  mVertexColor.mTopRight.mChannels.a =
      (mVertexColor.mTopRight.mChannels.a * _unk42) / 0xFF;
  mVertexColor.mBottomLeft.mChannels.a =
      (mVertexColor.mBottomLeft.mChannels.a * _unk42) / 0xFF;
  mVertexColor.mBottomRight.mChannels.a =
      (mVertexColor.mBottomRight.mChannels.a * _unk42) / 0xFF;
}

void CharWriter::SetupGXWithColorMapping(Color color1, Color color2) {
  SetupGXCommon();
  GXSetNumTevStages(2);
  GXSetTevDirect(0);
  GXSetTevDirect(1);
  GXSetTevSwapMode(GX_TEV_STAGE_ID_0, 0, 0);
  GXSetTevSwapMode(GX_TEV_STAGE_ID_1, 0, 0);
  GXSetTevOrder(GX_TEV_STAGE_ID_0, 0, 0, 0xFF);
  GXSetTevColor(GX_TEV_REG_ID_1, color1);
  GXSetTevColor(GX_TEV_REG_ID_2, color2);
  GXSetTevColorIn(GX_TEV_STAGE_ID_0, 2, 4, 8, 0xf);
  GXSetTevAlphaIn(GX_TEV_STAGE_ID_0, 1, 2, 4, 7);
  GXSetTevColorOp(GX_TEV_STAGE_ID_0, 0, 0, 0, 1, 0);
  GXSetTevAlphaOp(GX_TEV_STAGE_ID_0, 0, 0, 0, 1, 0);
  GXSetTevOrder(GX_TEV_STAGE_ID_1, 0xff, 0xff, 4);
  GXSetTevColorIn(GX_TEV_STAGE_ID_1, 0xf, 0, 10, 0xf);
  GXSetTevAlphaIn(GX_TEV_STAGE_ID_1, 7, 0, 5, 7);
  GXSetTevColorOp(GX_TEV_STAGE_ID_1, 0, 0, 0, 1, 0);
  GXSetTevAlphaOp(GX_TEV_STAGE_ID_1, 0, 0, 0, 1, 0);
  GXSetVtxAttrFmt(0, GX_ATTR_VTX, 1, 4, 0);
  GXSetVtxAttrFmt(0, GX_ATTR_VTX_CLR, 1, 5, 0);
  GXSetVtxAttrFmt(0, GX_ATTR_VTX_TEX_COORD, 1, 2, 0xf);
  GXClearVtxDesc();
  GXSetVtxDesc(GX_ATTR_VTX, 1);
  GXSetVtxDesc(GX_ATTR_VTX_CLR, 1);
  GXSetVtxDesc(GX_ATTR_VTX_TEX_COORD, 1);
}

} // namespace ut
} // namespace nw4r
