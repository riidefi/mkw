/*!
 * @file
 * @brief EGG wraper for expanded heaps header.
 */

#pragma once

#include <egg/core/eggHeap.hpp>
#include <rk_types.h>

namespace EGG {

class ExpHeap : public Heap {
public:
  struct GroupSizeRecord {
    u32 entries[256];

    GroupSizeRecord();
    void reset();
    void addSize(u16 groupID, u32 size);
  };

  ExpHeap(MEMHeapHandle heapHandle) : Heap(heapHandle) {}

  virtual ~ExpHeap() override;

  //! @brief Create an EGG ExpHeap and wrapped MEM ExpHeap in a certain region.
  //!
  //! @param[in] block Start of memory block to create.
  //! @param[in] size Size of the new heap to create. Must be at least 60 bytes.
  //! @param[in] attr MEM ExpHeap option flags.
  //!
  //! @returns The created ExpHeap
  //!
  static ExpHeap* create(void* block, u32 size, u16 attr) NEVER_INLINE;

  //! @brief Create a new ExpHeap as a child of an existing heap.
  //!
  //! @param[in] size Size of the new heap to create. If -1, the maximum
  //! alloctable size will be used.
  //! @param[in] heap Parent heap to use. If NULL, default heap will be used.
  //! @param[in] attr MEM ExpHeap option flags.
  //
  static ExpHeap* create(u32 size, Heap* heap, u16 attr);

  //! @brief There's no evidence of this macro/inline function existing, but it
  //! makes future work a lot cleaner.
  static inline ExpHeap* Make(void* start, u32 size, char* name) {
    ExpHeap* made = ExpHeap::create(start, size, 0);
    made->mName = name;
    return made;
  }
  //! @brief There's no evidence of this macro/inline function existing, but it
  //! makes future work a lot cleaner.
  static inline ExpHeap* MakeChild(u32 size, Heap* parent, char* name) {
    ExpHeap* made = ExpHeap::create(size, parent, 0);
    made->mName = name;
    return made;
  }

  //! @brief Destroy the current heap and free itself from its parent if it has
  //! one.
  //!
  void destroy() override;

  //! @brief Allocate a block of memory in the heap.
  //!
  //! @param[in] size  Size of the block of memory.
  //! @param[in] align Alignment of memory block.
  //!
  //! @pre _1 must not have the last bit set.
  //!		 If set, `OSPanic("eggExpHeap.cpp", 174, "DAME DAME\n");`
  //!
  void* alloc(u32 size, s32 align) override;

  //! @brief Free a block of memory in the heap.
  //!
  //! @param[in] block Block of memory in the heap.
  //!
  void free(void* block) override;

  //! @brief Resize allocated memory block.
  //!
  //! @param[in] block Allocated memory block to resize.
  //! @param[in] size  New size for memory block.
  //!
  //! @returns New size of memory block.
  //!			 - When expanding, may be greater than the size of the
  //! requested size.
  //!			 - When reducing, may be the original block size.
  //!			 - When unsuccessful, 0.
  //!
  u32 resizeForMBlock(void* block, u32 size) override;

  u32 getTotalFreeSize();

  u32 getAllocatableSize(s32 align) override;

  u16 setGroupID(u16 groupID);

  u32 adjust() override;

  void initAllocator(Allocator* allocator, s32 align) override;

  static void addGroupSize(void* block, MEMHeapHandle heap, u32 userParam);

  void calcGroupSize(GroupSizeRecord* record);

  void freeAll();

  //! @brief Returns the heap kind.
  //!
  //! @returns HEAP_KIND_EXPANDED
  //!
  eHeapKind getHeapKind() const override;
};

} // namespace EGG
