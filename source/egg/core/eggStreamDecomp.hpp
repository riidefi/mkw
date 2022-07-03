/*!
 * @file
 * @brief Wrappers for the CX streaming decompressors.
 * @remarks While NSMBW's StreamDecomp had all CX decompressors and SZS
 decompression linked, MKW only links the LZ decompressor.
 */

#pragma once

#include <rk_types.h>
#include <rvl/cx/cxLz.h>

namespace EGG {

//! @brief Interface for streamed decompression
//!
class StreamDecomp {
public:
  virtual bool init(void* dst, u32 maxCompressedSize);
  virtual bool decomp(const void* src, u32 len);
  virtual u32 getHeaderSize();
  virtual u32 getUncompressedSize(const void* src);
  void foo();
};

class LZStreamDecomp : public StreamDecomp {
public:
  bool init(void* dst, u32 maxCompressedSize) override;
  bool decomp(const void* src, u32 len) override;
  u32 getHeaderSize() override;
  u32 getUncompressedSize(const void* src) override;

private:
  void* mpDst; //!< [+0x04] Pointer to the decompressed destination buffer.
  u32 mMaxCompressedSize; //!< [+0x08] Not used by the LZ decompressor.
  CXUncompContextLZ
      mContext; //!< [+0x0C] CX streaming LZ decompression context.
};

} // namespace EGG
