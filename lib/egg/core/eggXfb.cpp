#include "eggXfb.hpp"
#include <egg/core/eggSystem.hpp>
#include <egg/core/eggVideo.hpp>
#include <rvl/gx.h>

namespace EGG {

Xfb::Xfb(Heap* heap) {
  Video* video = BaseSystem::sSystem->getVideo();
  GXRenderModeObj const* mode = video->getRenderModeObj();
  setDimensions(mode->fb_width, mode->xfb_height);
  size_t sz = calcBufferSize(width, height);
  if (!heap)
    heap = Heap::getCurrentHeap();
  buf = new (heap, 0x20) u8[sz];
  mNext = 0u;
  mPrev = 0u;
}

size_t EGG::Xfb::calcBufferSize(u16 p1, u16 p2) {
  return (p1 + 0xfu & 0xfff0) * p2 * 2;
}

} // namespace EGG
