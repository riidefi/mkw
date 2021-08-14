/**
 * @file
 * @brief Disposer implementations.
 */

#include "eggDisposer.hpp"
#include "eggHeap.hpp"

namespace EGG {

Disposer::Disposer() {
  mContainHeap = Heap::findContainHeap(this);

  if (mContainHeap != nullptr)
    mContainHeap->appendDisposer(this);
}

Disposer::~Disposer() {
  if (mContainHeap != nullptr)
    mContainHeap->removeDisposer(this);
}

} // namespace EGG
