/**
 * @file
 * @brief Disposer.
 */

#pragma once

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

  Heap* mContainHeap; //!< [+0x04] Heap that contains the instance of this
                      //!< disposer.
};

} // namespace EGG
