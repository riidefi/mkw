/*!
 * @file
 * @brief Abstract allocator interface, an object that can reserve and release
 * blocks of memory.
 */

#pragma once

#include <rk_types.h>
#include <rvl/mem/memAllocator.h>

namespace EGG {

class Heap;

class Allocator : public MEMAllocator {
public: // vt at +0x10
  //! @brief [vt+0x08] Create the default allocator.
  //!
  //! @param[in] heap Heap to use for allocations.
  //! @param[in] align Alignment of blocks to allocate.
  //!
  Allocator(Heap* heap, s32 align);

  //! @brief [vt+0x08] Virtual destructor
  //!
  virtual ~Allocator();

  //! @brief [vt+0x0C] Allocate a block of memory.
  //!
  //! @param[in] size Size of the block to allocate.
  //!
  virtual void* alloc(u32 size);

  //! @brief [vt+0x10] Free a block of memory.
  //!
  //! @param[in] block Block of memory to free.
  //!
  virtual void free(void* block);

  inline MEMAllocator* getHandle() { return static_cast<MEMAllocator*>(this); }

private:
  Heap* mHeap; //!< [+0x14] Heap to use for allocation.
  s32 mAlign;  //!< [+0x18] Alignment of blocks to allocate.
};

} // namespace EGG
