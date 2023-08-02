#pragma once

#include <rk_types.h>
#include <egg/core/eggHeap.hpp>

namespace EGG {

class Xfb {
public:
  Xfb(Heap*);
  static size_t calcBufferSize(u16, u16);

private:
  u16 width;
  u16 height;
  u8* buf;
  u32 _unk08;
  u32 _unk0c;

private:
  inline void setDimensions(u16 w, u16 h) {
    width = w;
    height = h;
  }
};

} // namespace EGG
