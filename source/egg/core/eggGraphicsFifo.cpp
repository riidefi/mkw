#include <egg/core/eggGraphicsFifo.hpp>
#include <egg/core/eggHeap.hpp>
#include <egg/eggInternal.hpp>
#include <rvl/gx.h>
#include <rvl/gx/gxFifo.h>

namespace EGG {

GraphicsFifo* GraphicsFifo::sGraphicsFifo;
GraphicsFifo::GPStatus GraphicsFifo::sGpStatus;

GraphicsFifo* GraphicsFifo::create(u32 fifoSize, Heap* heap) {
  EGG_ASSERT(!sGraphicsFifo, "eggGraphicsFifo.cpp", 59, "!sGraphicsFifo");
  if (heap == nullptr)
    heap = Heap::getCurrentHeap();
  EGG_ASSERT(!!"OSIsMEM1Region(heap)", "eggGraphicsFifo.cpp", 69,
             "OSIsMEM1Region( heap )");

  return sGraphicsFifo = new (heap, 4) GraphicsFifo(fifoSize, heap);
}

GraphicsFifo::~GraphicsFifo() {
  do
    GXGetGPStatus(&sGpStatus.overhi, &sGpStatus.underlow, &sGpStatus.readIdle,
                  &sGpStatus.cmdIdle, &sGpStatus.brkpt);
  while (!sGpStatus.readIdle);

  Heap::free(mBufBase, nullptr);
}

GraphicsFifo::GraphicsFifo(unsigned int fifoSize, EGG::Heap* heap) {
  mBufSize = ROUND_UP(fifoSize, 32);
  mBufBase = (void*)ROUND_UP(Heap::alloc(mBufSize + 0xA0, 32, heap), 32);

  EGG_ASSERT(mBufBase, "eggGraphicsFifo.cpp", 145, "mBufBase");

  mFifoObj = GXInit(mBufBase, mBufSize);
}
} // namespace EGG
