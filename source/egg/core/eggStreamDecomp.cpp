/*!
 * @file
 * @brief Implementations for the EGG streaming decompressor headers.
 */

#include "eggStreamDecomp.hpp"

namespace EGG {

bool LZStreamDecomp::initialize(void* dst, unk arg3) {
  mpDst = dst;
  _08 = arg3;
  CXInitUncompContextLZ(&mContext, dst);
  return true;
}

bool LZStreamDecomp::process(const void* src, u32 len) {
  return CXReadUncompLZ(&mContext, src, len) == CXResultSuccess;
}

u32 LZStreamDecomp::getDataOffset() { return 32; }

u32 LZStreamDecomp::getExpandSize(const void* src) {
  return CXGetUncompressedSize(src);
}

} // namespace EGG