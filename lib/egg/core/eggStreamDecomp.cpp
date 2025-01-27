/*!
 * @file
 * @brief Implementations for the EGG streaming decompressor headers.
 */

#include "eggStreamDecomp.hpp"

namespace EGG {

bool LZStreamDecomp::init(void* dst, u32 maxCompressedSize) {
  mpDst = dst;
  mMaxCompressedSize = maxCompressedSize;
  CXInitUncompContextLZ(&mContext, dst);
  return true;
}

bool LZStreamDecomp::decomp(const void* src, u32 len) {
  return CXReadUncompLZ(&mContext, src, len) == CXResultSuccess;
}

u32 LZStreamDecomp::getHeaderSize() { return 32; }

u32 LZStreamDecomp::getUncompressedSize(const void* src) {
  return CXGetUncompressedSize(src);
}

} // namespace EGG
