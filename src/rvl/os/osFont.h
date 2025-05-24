#pragma once

#include <rk_types.h>
#include <decomp.h>

// Credit: GibHaltmannKill

#ifdef __cplusplus
extern "C" {
#endif

enum { OS_ENCODE_CP1252, OS_ENCODE_SJIS };

typedef u16 OSFontEncoding;
typedef u16 OSFontChar;

struct OSFontHeader {
  char UNK_0x0[0x8]; // 0x0
  u16 ascent;        // 0x8
  u16 descent;       // 0xa

  u16 charWidth; // 0xc

  u16 linefeed; // 0xe

  u16 cellWidth;  // 0x10
  u16 cellHeight; // 0x12

  u32 UNK_0x14;
  u32 UNK_0x18;
  u16 UNK_0x1A;

  u16 SHORT_0x1E;
  u16 SHORT_0x20;
};

// PAL: 0x801a56dc..0x801a5810
UNKNOWN_FUNCTION(GetFontCode);
// PAL: 0x801a5810..0x801a59b4
UNKNOWN_FUNCTION(Decode);
// PAL: 0x801a59b4..0x801a5a34
UNKNOWN_FUNCTION(OSSetFontEncode);
// PAL: 0x801a5a34..0x801a5d34
UNKNOWN_FUNCTION(ReadFont);
// PAL: 0x801a5d34..0x801a5e5c
UNKNOWN_FUNCTION(OSLoadFont);
// PAL: 0x801a5e5c..0x801a5f58
UNKNOWN_FUNCTION(ParseStringS);
// PAL: 0x801a5f58..0x801a6114
UNKNOWN_FUNCTION(ParseStringW);
// PAL: 0x801a6114..0x801a63a4
UNKNOWN_FUNCTION(OSGetFontTexel);
// PAL: 0x801a63a4..0x801a64f4
void OSGetFontTexture(void*, u8**, int*, int*, int*);
// PAL: 0x801a64f4..0x801a65ac
int OSGetFontWidth(void*, u32*);

#ifdef __cplusplus
}
#endif
