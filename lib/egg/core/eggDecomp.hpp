#pragma once

#include <rk_types.h>

namespace EGG {

namespace Decomp {

enum CompressionType {
  TYPE_UNKNOWN = 0,
  TYPE_SZS = 1,
  TYPE_ASH = 2,
  TYPE_ASR = 3,
};

// PAL: 0x80218ba4..0x80218c2c
s32 decode(const u8*, u8*);
// PAL: 0x80218c2c..0x80218dc0
s32 decodeSZS(const u8*, u8*);
// PAL: 0x80218dc0..0x80218ff0
s32 decodeASH(const u8*, u8*);
// PAL: 0x80218ff0..0x802198f8
s32 decodeASR(const u8*, u8*);
// PAL: 0x802198f8..0x8021997c
CompressionType checkCompressed(const u8*);
// PAL: 0x8021997c..0x80219a7c
s32 getExpandSize(const u8*);
// PAL: 0x80219a7c..0x80219b84
int getBitsCode(const u8*, int, int);
// PAL: 0x80219b84..0x80219c10
int getBit1c(const u8*, int);
// PAL: 0x80219c10..0x80219d34
void readTree9(const u8*, unsigned short*, unsigned short*, unsigned short*);
// PAL: 0x80219d34..0x80219e68
void readTree12(const u8*, unsigned short*, unsigned short*, unsigned short*);
} // namespace Decomp

} // namespace EGG
