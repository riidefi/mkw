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
class IStreamDecomp {
public:
  virtual bool initialize(void* dst, unk arg3) = 0;
  virtual bool process(const void* src, u32 len) = 0;
  virtual u32 getDataOffset() = 0;
  virtual u32 getExpandSize(const void* src) = 0;
};

class LZStreamDecomp : public IStreamDecomp {
public:
  bool initialize(void* dst, unk arg3) override;
  bool process(const void* src, u32 len) override;
  u32 getDataOffset() override;
  u32 getExpandSize(const void* src) override;

private:
  void* mpDst; //!< [+0x04] Pointer to the decompressed destination buffer.
  unk _08;     //!< [+0x08] Second argument of constructor -- unused.
  CXUncompContextLZ
      mContext; //!< [+0x0C] CX streaming LZ decompression context.
};

} // namespace EGG