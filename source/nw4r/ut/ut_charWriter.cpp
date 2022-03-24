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

// Symbol: __ct__Q34nw4r2ut10CharWriterFv
// PAL: 0x800b2b30..0x800b2eb0
MARK_BINARY_BLOB(__ct__Q34nw4r2ut10CharWriterFv, 0x800b2b30, 0x800b2eb0);
asm CharWriter::CharWriter() {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  li r6, -1;
  lis r5, mLoadingTexture@ha;
  lfs f0, 0.0f;
  stw r31, 0x2c(r1);
  li r0, 0xff;
  addi r4, r5, mLoadingTexture@l;
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  li r29, 0;
  stw r28, 0x20(r1);
  addi r28, r3, 0x18;
  stw r6, 0(r3);
  stw r29, 8(r1);
  stw r6, 0xc(r1);
  lbz r30, 8(r1);
  stw r6, 4(r3);
  lbz r31, 9(r1);
  stw r6, 8(r3);
  lbz r12, 0xa(r1);
  stw r6, 0xc(r3);
  lbz r11, 0xb(r1);
  stw r6, 0x10(r3);
  lbz r10, 0xc(r1);
  stw r6, 0x14(r3);
  lbz r9, 0xd(r1);
  stw r6, 0x18(r3);
  lbz r8, 0xe(r1);
  stw r6, 0x1c(r3);
  lbz r7, 0xf(r1);
  stb r0, 0x42(r3);
  stb r29, 0x43(r3);
  stfs f0, 0x44(r3);
  stw r29, 0x48(r3);
  stw r0, mLoadingTexture@l(r5);
  stw r29, 4(r4);
  lbz r6, 0x18(r3);
  lbz r5, 0x19(r3);
  lbz r4, 0x1a(r3);
  lbz r0, 0x1b(r3);
  stb r30, 0(r3);
  stb r31, 1(r3);
  stb r12, 2(r3);
  stb r11, 3(r3);
  stb r10, 4(r3);
  stb r9, 5(r3);
  stb r8, 6(r3);
  stb r7, 7(r3);
  stw r29, 0x20(r3);
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r0, 0xb(r3);
  lbz r0, 0(r28);
  stb r0, 0xc(r3);
  lwz r0, 0x20(r3);
  lbz r4, 1(r28);
  stb r4, 0xd(r3);
  cmpwi r0, 2;
  lbz r0, 2(r28);
  stb r0, 0xe(r3);
  lbz r0, 3(r28);
  stb r0, 0xf(r3);
  beq lbl_800b2c38;
  addi r5, r3, 0x18;
  b lbl_800b2c3c;
lbl_800b2c38:
  addi r5, r3, 0x1c;
lbl_800b2c3c:
  lbz r0, 0(r5);
  stb r0, 0x10(r3);
  lwz r0, 0x20(r3);
  lbz r4, 1(r5);
  stb r4, 0x11(r3);
  cmpwi r0, 0;
  lbz r0, 2(r5);
  stb r0, 0x12(r3);
  lbz r0, 3(r5);
  stb r0, 0x13(r3);
  bne lbl_800b2c70;
  addi r6, r3, 0x18;
  b lbl_800b2c74;
lbl_800b2c70:
  addi r6, r3, 0x1c;
lbl_800b2c74:
  lbz r0, 0(r6);
  lis r5, 0x8081;
  stb r0, 0x14(r3);
  addi r12, r5, -32639;
  lwz r0, 0x20(r3);
  li r4, -1;
  lbz r5, 1(r6);
  stb r5, 0x15(r3);
  cmpwi r0, 1;
  lbz r5, 0xb(r3);
  lbz r0, 2(r6);
  stb r0, 0x16(r3);
  lbz r11, 0x42(r3);
  lbz r0, 0xf(r3);
  stw r4, 0x10(r1);
  mullw r10, r5, r11;
  lbz r31, 3(r6);
  lbz r5, 0x11(r1);
  lbz r4, 0x12(r1);
  lbz r7, 0x13(r3);
  mullw r9, r0, r11;
  stb r5, 0x19(r3);
  lbz r6, 0x10(r1);
  stb r5, 9(r3);
  lbz r0, 0x13(r1);
  mulhw r5, r12, r10;
  stb r4, 0x1a(r3);
  stb r4, 0xa(r3);
  mullw r8, r7, r11;
  stb r6, 0x18(r3);
  add r5, r5, r10;
  stb r6, 8(r3);
  srawi r5, r5, 7;
  stb r0, 0x1b(r3);
  mulhw r4, r12, r9;
  stb r0, 0xb(r3);
  mulhw r5, r12, r8;
  add r4, r4, r9;
  srawi r6, r4, 7;
  add r5, r5, r8;
  srwi r8, r6, 0x1f;
  mullw r7, r31, r11;
  add r8, r6, r8;
  stb r8, 0xf(r3);
  srawi r5, r5, 7;
  srwi r6, r5, 0x1f;
  mulhw r4, r12, r7;
  add r5, r5, r6;
  stb r5, 0x13(r3);
  add r0, r4, r7;
  srawi r0, r0, 7;
  srwi r4, r0, 0x1f;
  add r0, r0, r4;
  stb r0, 0x17(r3);
  beq lbl_800b2d58;
  addi r5, r3, 0x18;
  b lbl_800b2d5c;
lbl_800b2d58:
  addi r5, r3, 0x1c;
lbl_800b2d5c:
  lbz r0, 0(r5);
  stb r0, 0xc(r3);
  lwz r0, 0x20(r3);
  lbz r4, 1(r5);
  stb r4, 0xd(r3);
  cmpwi r0, 2;
  lbz r0, 2(r5);
  stb r0, 0xe(r3);
  lbz r0, 3(r5);
  stb r0, 0xf(r3);
  beq lbl_800b2d90;
  addi r5, r3, 0x18;
  b lbl_800b2d94;
lbl_800b2d90:
  addi r5, r3, 0x1c;
lbl_800b2d94:
  lbz r0, 0(r5);
  stb r0, 0x10(r3);
  lwz r0, 0x20(r3);
  lbz r4, 1(r5);
  stb r4, 0x11(r3);
  cmpwi r0, 0;
  lbz r0, 2(r5);
  stb r0, 0x12(r3);
  lbz r0, 3(r5);
  stb r0, 0x13(r3);
  bne lbl_800b2dc8;
  addi r7, r3, 0x18;
  b lbl_800b2dcc;
lbl_800b2dc8:
  addi r7, r3, 0x1c;
lbl_800b2dcc:
  lbz r0, 0(r7);
  lis r4, 0x8081;
  stb r0, 0x14(r3);
  addi r10, r4, -32639;
  lbz r4, 0xb(r3);
  li r0, 1;
  lbz r5, 1(r7);
  stb r5, 0x15(r3);
  lbz r8, 0x42(r3);
  lbz r5, 2(r7);
  stb r5, 0x16(r3);
  mullw r6, r4, r8;
  lbz r5, 0xf(r3);
  lbz r9, 3(r7);
  lbz r4, 0x13(r3);
  lfs f0, 0.0f;
  mullw r7, r5, r8;
  lfs f1, 1.0f;
  stw r0, 0x38(r3);
  stw r0, 0x3c(r3);
  mullw r5, r4, r8;
  stfs f1, 0x24(r3);
  stfs f1, 0x28(r3);
  mullw r4, r9, r8;
  stfs f0, 0x2c(r3);
  stfs f0, 0x30(r3);
  stfs f0, 0x34(r3);
  mulhw r8, r10, r6;
  mulhw r0, r10, r7;
  add r6, r8, r6;
  srawi r8, r6, 7;
  mulhw r6, r10, r5;
  srwi r9, r8, 0x1f;
  add r0, r0, r7;
  add r7, r8, r9;
  stb r7, 0xb(r3);
  srawi r7, r0, 7;
  add r5, r6, r5;
  srwi r6, r7, 0x1f;
  mulhw r0, r10, r4;
  add r6, r7, r6;
  stb r6, 0xf(r3);
  srawi r5, r5, 7;
  srwi r6, r5, 0x1f;
  add r0, r0, r4;
  srawi r0, r0, 7;
  add r5, r5, r6;
  srwi r4, r0, 0x1f;
  stb r5, 0x13(r3);
  add r0, r0, r4;
  stb r0, 0x17(r3);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

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
