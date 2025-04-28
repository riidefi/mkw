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

void OSGetFontTexture(void*, u8**, int*, int*, int*);
int OSGetFontWidth(void*, u32*);

#ifdef __cplusplus
}
#endif
