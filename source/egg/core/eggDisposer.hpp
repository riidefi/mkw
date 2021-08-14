/**
 * @file
 * @brief Headers for EGG::Disposer.
 */

#pragma once

#include <nw4r/ut/utList.hpp>
#include <rk_types.h>

namespace EGG {

class Heap;

//! @brief Base class for garbage-collected objects.
//!
//! Scene-specific, heap-allocated resources in mkw are typically not explicitly
//! freed. This isn't a memory leak, though: when a Scene transitions, all
//! memory allocated within it is returned in one block. However, in C++, the
//! destructor of an object must be called when its lifetime
//! expires--otherwise, we could leak second-order resources and introduce
//! use-after-free bugs.
//!
//! Disposer solves this issue: when a heap is destroyed,
//! the linked list of dispoers is traversed and each destructor is called
//! in-order.
//!
class Disposer : private NonCopyable {
  friend class Heap;

protected:
  //! @brief Disposer destructor: detach from heap.
  //!
  virtual ~Disposer();

  //! @brief Disposer constructor: attach to heap.
  //! @pre   Lifetime management is assumed if, and only if, the object is
  //! allocated within an EGG::Heap.
  //!
  Disposer();

public:
  //! Describes the lifetime of a derived object.
  enum eLifetime {
    //! This object is not allocated in an EGG::Heap; it acts as a regular C++
    //! object.
    LIFETIME_UNMANAGED,

    //! This object is garbage-collected; its lifetime is tied to its heap.
    LIFETIME_HEAP_GC
  };

  //! @brief Inspect the lifetime of this object.
  inline eLifetime getLifetime() const {
    return mContainHeap != nullptr ? LIFETIME_HEAP_GC : LIFETIME_UNMANAGED;
  }

private:
  // If null, Disposer is no-op.
  Heap* mContainHeap;
  // Otherwise, each Disposer object exists in a linked list owned by
  // mContainHeap.
  nw4r::ut::Node mLink;
};

} // namespace EGG
