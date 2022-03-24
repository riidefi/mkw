#pragma once

#include <rk_types.h>
#include <nw4r/math/mathTypes.hpp>

#include "utColor.hpp"
#include "ut_font.hpp"

// Source:
// https://github.com/kiwi515/ogws/blob/master/include/nw4r/ut/ut_CharWriter.h
// Credit: GibHaltmannKill

namespace nw4r {
namespace ut {

class CharWriter {

  struct ColorMapping {
    Color COLOR_0x0;
    Color COLOR_0x4;
  };

  struct VertexColor {
    Color mTopLeft;
    Color mTopRight;
    Color mBottomLeft;
    Color mBottomRight;
  };

  struct TextureFilter {
    int WORD_0x0;
    int WORD_0x4;

    inline bool operator!=(const TextureFilter& other) const {
      return WORD_0x0 != other.WORD_0x0 || WORD_0x4 != other.WORD_0x4;
    }
  };

  struct LoadingTexture {
    s32 s32_0x0;
    u8* PTR_0x4;
    TextureFilter mFilter;

    inline bool operator!=(const LoadingTexture& other) const {
      return s32_0x0 != other.s32_0x0 || PTR_0x4 != other.PTR_0x4 ||
             mFilter != other.mFilter;
    }

    inline void Reset() {
      s32_0x0 = 0xFF;
      PTR_0x4 = 0;
    }
  };

  struct TextColor {
    Color mStart;
    Color mEnd;
  };

  enum GradationMode { GradMode_None, GradMode_Horizontal, GradMode_Vertical };

  static LoadingTexture mLoadingTexture;

  ColorMapping mColorMapping;   // 0x00
  VertexColor mVertexColor;     // 0x08
  TextColor mTextColor;         // 0x18
  GradationMode mGradationMode; // 0x20
  nw4r::math::VEC2 mScale;      // 0x24
  nw4r::math::VEC3 mCursor;     // 0x2c
  TextureFilter mFilter;        // 0x38
  u8 _unk40;                    // 0x40
  u8 _unk41;                    // 0x41
  u8 _unk42;                    // 0x42
  bool mWidthFixedFlag;         // 0x43
  float mFixedWidth;            // 0x44
  Font* mFont;                  // 0x48

public:
  // PAL: 0x800b2b30
  CharWriter();
  // PAL: 0x800b2eb0
  ~CharWriter();

  void SetColorMapping(Color, Color);
  void SetTextColor(Color);

  void UpdateVertexColor();

  float GetFontWidth() const;
  float GetFontHeight() const;

  float GetFontAscent() const;
  float GetFontDescent() const;

  void EnableLinearFilter(bool, bool);

  float Print(u16);

  inline void LoadTexture(const Glyph&); // inlined

  void PrintGlyph(float, float, float, const Glyph&);

  inline float GetFixedWidth() const { return mFixedWidth; }
  inline bool IsWidthFixed() const { return mWidthFixedFlag; }
  inline void SetCursorX(float x) { mCursor.x = x; }
  inline void SetCursorY(float y) { mCursor.y = y; }
  inline void MoveCursorX(float x) { mCursor.x += x; }
  inline void MoveCursorY(float y) { mCursor.y += y; }
  inline float GetCursorX() const { return mCursor.x; }
  inline float GetCursorY() const { return mCursor.y; }

  // PAL: 0x800b2ef0
  void SetupGX();
  static void SetupGXWithColorMapping(Color, Color);
  void SetupGXDefault(); // inlined

  void SetFontSize(float);
  void SetFontSize(float, float);

  inline void SetScale(float d) {
    mScale.x = d;
    mScale.y = d;
  }

  inline void SetScale(float x, float y) {
    mScale.x = x;
    mScale.y = y;
  }

  inline void SetCursor(float x, float y) {
    mCursor.x = x;
    mCursor.y = y;
  }

  inline void SetCursor(float x, float y, float z) {
    mCursor.x = x;
    mCursor.y = y;
    mCursor.z = z;
  }

  inline void ResetColorMapping() { SetColorMapping(Color(0), Color()); }

  inline void SetGradationMode(GradationMode gradationMode) {
    mGradationMode = gradationMode;

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
};

} // namespace ut
} // namespace nw4r
