/*!
 * @file
 * @brief Implementation for the allocator wrapper.
 */

#include <egg/core/eggAllocator.hpp>
#include <egg/core/eggHeap.hpp>

namespace EGG {

Allocator::Allocator(Heap* heap, s32 align) : mHeap(heap), mAlign(align) {
  heap->initAllocator(this, align);
}

Allocator::~Allocator() {}

void* Allocator::alloc(u32 size) { return Heap::alloc(size, mAlign, mHeap); }

void Allocator::free(void* block) { Heap::free(block, mHeap); }

} // namespace EGG
