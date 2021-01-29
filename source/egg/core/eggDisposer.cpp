/**
 * @file
 * @brief Disposer implementations.
 */

#include "eggDisposer.hpp"
#include "eggHeap.hpp"

namespace EGG {

Disposer::Disposer() {
  mContainHeap = Heap::findContainHeap(this);

  if (mContainHeap)
    mContainHeap->appendDisposer(this);
}

Disposer::~Disposer() {
  if (mContainHeap)
    mContainHeap->removeDisposer(this);
}

} // namespace EGG
