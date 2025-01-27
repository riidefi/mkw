#pragma once

#include <rk_types.h>
#include <egg/core/eggHeap.hpp>

namespace EGG {

class Xfb {
public:
  Xfb(Heap*);
  static size_t calcBufferSize(u16, u16);

  u16 getWidth() const { return width; }
  u16 getHeight() const { return height; }

  u8* getBuffer() const { return buf; }

  Xfb* getPrev() const { return mPrev; }
  void setPrev(Xfb* xfb) { mPrev = xfb; }

  Xfb* getNext() const { return mNext; }
  void setNext(Xfb* xfb) { mNext = xfb; }

private:
  u16 width;
  u16 height;
  u8* buf;
  Xfb* mPrev;
  Xfb* mNext;

private:
  inline void setDimensions(u16 w, u16 h) {
    width = w;
    height = h;
  }
};

} // namespace EGG
