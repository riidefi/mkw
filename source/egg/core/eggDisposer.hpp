/**
 * @file
 * @brief Base class for garbage-collected objects.
 */

#pragma once

#include <nw4r/ut/utList.hpp>

namespace EGG {

class Heap;

//---------------------------------------------------------------------------
//! @brief   Interface for objects that can be destroyed.
//!
//! @details Has a virtual table (with virtual destructor) and pointer to
//!          containing heap.
//---------------------------------------------------------------------------
class Disposer {
public:
  //! @brief Disposer destructor. If a containing heap is set, unregister self
  //! from its children.
  //!
  virtual ~Disposer();

  //! @brief Disposer constructor. If a containing heap is set, register self to
  //! its children.
  //!
  Disposer();

private:
  inline Disposer(const Disposer&) {}

private:
  Heap* mContainHeap; //!< [+0x04] Heap that contains the instance of this
                      //!< disposer.

public:
  nw4r::ut::Node mLink;
};

} // namespace EGG
