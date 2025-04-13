#include "eggDecomp.hpp"

#include <decomp.h>

#define getSZSExpandSize(src)                                                  \
  ((src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7])

#define getASExpandSize(src) ((src[5] << 16) | (src[6] << 8) | src[7])

namespace EGG {
namespace Decomp {

long long unk_80386de8 = 0;
int unk_80386df0 = 0;
int unk_80386df4 = 0;
int unk_80386df8 = 0;
int unk_80386dfc = 0;
int unk_80386e00 = 0;
int unk_80386e04 = 0;
int unk_80386e08 = 0;

s32 decode(const u8* src, u8* dst) {
  switch (checkCompressed(src)) {
  case TYPE_SZS:
    return decodeSZS(src, dst);
  case TYPE_ASH:
    return decodeASH(src, dst);
  case TYPE_ASR:
    return decodeASR(src, dst);
  default:
    return -1;
  }
}

s32 decodeSZS(const u8* src, u8* dst) {

  long expandSize = getSZSExpandSize(src);
  long srcIdx = 0x10;
  u8 code = 0;

  u8 byte;

  for (long destIdx = 0; destIdx < expandSize; code >>= 1) {
    if (!code) {
      code = 0x80;
      byte = src[srcIdx++];
    }

    // Direct copy (code bit = 1)
    if (byte & code) {
      dst[destIdx++] = src[srcIdx++];
    }
    // RLE compressed data (code bit = 0)
    else {
      // Lower nibble of byte1 + byte2
      long distToDest = (src[srcIdx] << 8) | src[srcIdx + 1];
      srcIdx += sizeof(u8) * 2;
      long runSrcIdx = destIdx - (distToDest & 0xfff);

      // Upper nibble of byte 1
      long runLen = ((distToDest >> 12) == 0) ? src[srcIdx++] + 0x12
                                              : (distToDest >> 12) + 2;

      for (; runLen > 0; runLen--, destIdx++, runSrcIdx++) {
        dst[destIdx] = dst[runSrcIdx - 1];
      }
    }

    // Prepare next code bit
  }

  return expandSize;
}

// s32 decodeASH(const u8*, u8*) 

// s32 decodeASR(const u8*, u8*) 

CompressionType checkCompressed(const u8* src) {
  if ((src[0] == 'Y') && (src[1] == 'a') && (src[2] == 'z'))
    return TYPE_SZS;
  if ((src[0] == 'A') && (src[1] == 'S') && (src[2] == 'H'))
    return TYPE_ASH;
  if ((src[0] == 'A') && (src[1] == 'S') && (src[2] == 'R'))
    return TYPE_ASR;

  return TYPE_UNKNOWN;
}

s32 getExpandSize(const u8* src) {
  switch (checkCompressed(src)) {
  case TYPE_SZS:
    return getSZSExpandSize(src);
  case TYPE_ASH:
    return getASExpandSize(src);
  case TYPE_ASR:
    return getASExpandSize(src);
  default:
    return -1;
  }
}

// int getBitsCode(const u8*, int, int) 

// int getBit1c(const u8*, int) 

// void readTree9(const u8*, unsigned short*, unsigned short*, unsigned short*)

// void readTree12(const u8*, unsigned short*, unsigned short*, unsigned short*) 

} // namespace Decomp
} // namespace EGG
