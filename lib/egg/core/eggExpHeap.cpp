/*!
 * @file
 * @brief EGG wraper for expanded heaps implementation.
 */

#include <egg/core/eggExpHeap.hpp>
#include <nw4r/ut/utInlines.hpp>
#include <rvl/mem/expHeap.h>

inline void* operator new(unsigned long, void* p) { return p; }

namespace EGG {

enum {
  EXP_HEAP_BASE_SIZE = 56, // (sizeof(ExpHeap) - sizeof(...)),
  EXP_HEAP_ALIGN = 4
};

ExpHeap::~ExpHeap() {
  // Recursively free all memory
  Heap::dispose();

  // Destroy the wrapped MEM heap
  MEMDestroyExpHeap(mHeapHandle);
}

#ifdef NONMATCHING
ExpHeap* ExpHeap::create(void* block, u32 size, u16 attr) {
  ExpHeap* createdHeap = nullptr; // r30

  u32 heapEnd = nw4r::ut::RoundDown((u32)block + size, EXP_HEAP_ALIGN); // r3
  u32 heapStart = nw4r::ut::RoundUp((u32)block, EXP_HEAP_ALIGN);        // r27

  // Enforce requirement for 56 byte ExpHeap object + minimum 4 bytes in heap.
  if (heapStart > heapEnd ||
      heapEnd - heapStart < EXP_HEAP_BASE_SIZE + EXP_HEAP_ALIGN) {
    createdHeap = nullptr;
  } else {
    // We reserve 56 bytes in the heap.
    MEMHeapHandle hnd = MEMCreateExpHeapEx(
        reinterpret_cast<void*>(heapStart + EXP_HEAP_BASE_SIZE),
        heapEnd - heapStart - EXP_HEAP_BASE_SIZE, attr); // r28

    if (hnd) {
      Heap* contain =
          Heap::findContainHeap(reinterpret_cast<void*>(heapStart)); // r31

      createdHeap = new (reinterpret_cast<void*>(heapStart)) ExpHeap(hnd);

      createdHeap->mParentBlock = block;
      createdHeap->mParentHeap = contain;
    }
  }

  return createdHeap;
}
#else
extern "C" void __ct__Q23EGG4HeapFP12MEMiHeapHead();
extern "C" void findContainHeap__Q23EGG4HeapFPCv();

// clang-format off
asm ExpHeap* ExpHeap::create(void* block, u32 size, u16 attr) {
    nofralloc

/* 80226A1C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80226A20  7C 08 02 A6 */	mflr r0
/* 80226A24  7C 83 22 14 */	add r4, r3, r4
/* 80226A28  90 01 00 24 */	stw r0, 0x24(r1)
/* 80226A2C  38 03 00 03 */	addi r0, r3, 3
/* 80226A30  BF 61 00 0C */	stmw r27, 0xc(r1)
/* 80226A34  7C 7D 1B 78 */	mr r29, r3
/* 80226A38  54 83 00 3A */	rlwinm r3, r4, 0, 0, 0x1d
/* 80226A3C  54 1B 00 3A */	rlwinm r27, r0, 0, 0, 0x1d
/* 80226A40  7C 1B 18 40 */	cmplw r27, r3
/* 80226A44  3B C0 00 00 */	li r30, 0
/* 80226A48  41 81 00 10 */	bgt loc_80226A58
/* 80226A4C  7C 9B 18 50 */	subf r4, r27, r3
/* 80226A50  28 04 00 3C */	cmplwi r4, 0x3c
/* 80226A54  40 80 00 0C */	bge loc_80226A60
loc_80226A58:
/* 80226A58  38 60 00 00 */	li r3, 0
/* 80226A5C  48 00 00 58 */	b loc_80226AB4
loc_80226A60:
/* 80226A60  38 7B 00 38 */	addi r3, r27, 0x38
/* 80226A64  38 84 FF C8 */	addi r4, r4, -56
/* 80226A68  4B F7 22 41 */	bl MEMCreateExpHeapEx
/* 80226A6C  2C 03 00 00 */	cmpwi r3, 0
/* 80226A70  7C 7C 1B 78 */	mr r28, r3
/* 80226A74  41 82 00 3C */	beq loc_80226AB0
/* 80226A78  7F 63 DB 78 */	mr r3, r27
/* 80226A7C  48 00 30 61 */	bl findContainHeap__Q23EGG4HeapFPCv
/* 80226A80  2C 1B 00 00 */	cmpwi r27, 0
/* 80226A84  7C 7F 1B 78 */	mr r31, r3
/* 80226A88  41 82 00 1C */	beq loc_80226AA4
/* 80226A8C  7F 63 DB 78 */	mr r3, r27
/* 80226A90  7F 84 E3 78 */	mr r4, r28
/* 80226A94  48 00 2C 55 */	bl __ct__Q23EGG4HeapFP12MEMiHeapHead
/* 80226A98  3C 60 80 2A */	lis r3, 0x802a
/* 80226A9C  38 63 2F F8 */	addi r3, r3, 0x2ff8
/* 80226AA0  90 7B 00 00 */	stw r3, 0(r27)
loc_80226AA4:
/* 80226AA4  93 BB 00 14 */	stw r29, 0x14(r27)
/* 80226AA8  7F 7E DB 78 */	mr r30, r27
/* 80226AAC  93 FB 00 18 */	stw r31, 0x18(r27)
loc_80226AB0:
/* 80226AB0  7F C3 F3 78 */	mr r3, r30
loc_80226AB4:
/* 80226AB4  BB 61 00 0C */	lmw r27, 0xc(r1)
/* 80226AB8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80226ABC  7C 08 03 A6 */	mtlr r0
/* 80226AC0  38 21 00 20 */	addi r1, r1, 0x20
/* 80226AC4  4E 80 00 20 */	blr
}
// clang-format on
#endif

ExpHeap* ExpHeap::create(u32 size, Heap* heap, u16 attr) {
  ExpHeap* newHeap = nullptr;

  if (heap == nullptr)
    heap = Heap::sCurrentHeap;
  if (size == -1)
    size = heap->getAllocatableSize(4);

  void* block = heap->alloc(size, 4);
  if (block) {
    newHeap = ExpHeap::create(block, size, attr);

    if (newHeap)
      newHeap->mParentHeap = heap;
    else
      heap->free(block);
  }

  return newHeap;
}

void ExpHeap::destroy() {
  Heap* parentHeap = findParentHeap();

  (*this).~ExpHeap();

  if (parentHeap)
    parentHeap->free(this);
}
extern "C" void OSPanic(const char* file, u32 line, const char* msg, ...);
void* ExpHeap::alloc(u32 size, s32 align) {
  if ((mFlag & HEAP_FLAG_LOCKED) != 0)
    OSPanic("eggExpHeap.cpp", 174, "DAME DAME\n");

  return MEMAllocFromExpHeapEx(mHeapHandle, size, align);
}

void ExpHeap::free(void* block) { MEMFreeToExpHeap(mHeapHandle, block); }

u32 ExpHeap::resizeForMBlock(void* memBlock, u32 size) {
  return MEMResizeForMBlockExpHeap(mHeapHandle, memBlock, size);
}

u32 ExpHeap::getTotalFreeSize() {
  return MEMGetTotalFreeSizeForExpHeap(mHeapHandle);
}

u32 ExpHeap::getAllocatableSize(s32 align) {
  return MEMGetAllocatableSizeForExpHeapEx(mHeapHandle, align);
}

u16 ExpHeap::setGroupID(u16 groupID) {
  return MEMSetGroupIDForExpHeap(mHeapHandle, groupID);
}

void ExpHeap::addGroupSize(void* block, MEMHeapHandle heap, u32 userParam) {
  u16 grpID = MEMGetGroupIDForMBlockExpHeap(block);
  // below may return
  ((GroupSizeRecord*)userParam)
      ->addSize(grpID, MEMGetSizeForMBlockExpHeap(block));
}

void ExpHeap::calcGroupSize(GroupSizeRecord* record) {
  record->reset();
  MEMVisitAllocatedForExpHeap(mHeapHandle, addGroupSize, (u32)record);
}

u32 ExpHeap::adjust() {
  u32 adjustedSize = MEMAdjustExpHeap(mHeapHandle) + 56;

  if (adjustedSize > 56 && mParentHeap) {
    mParentHeap->resizeForMBlock(mParentBlock, adjustedSize);
    return adjustedSize;
  }

  return nullptr;
}

void ExpHeap::initAllocator(Allocator* allocator, s32 align) {
  MEMInitAllocatorForExpHeap((MEMAllocator*)allocator, mHeapHandle, align);
}

ExpHeap::GroupSizeRecord::GroupSizeRecord() { reset(); }

void ExpHeap::GroupSizeRecord::reset() {
  u32* iterEntry = &entries[0];
  for (int i = 0; i < 256; i++) {
    *iterEntry = 0;
    iterEntry++;
  }
}

void ExpHeap::GroupSizeRecord::addSize(u16 groupID, u32 size) {
  entries[groupID] += size;
}

namespace {
void free_all_visitor(void* block, MEMHeapHandle heap, u32 userParam) {
  MEMFreeToExpHeap(heap, block);
}
} // namespace

void ExpHeap::freeAll() {
  Heap::dispose();

  MEMVisitAllocatedForExpHeap(mHeapHandle, &free_all_visitor, 0);
}

Heap::eHeapKind ExpHeap::getHeapKind() const {
  return Heap::HEAP_KIND_EXPANDED;
}

} // namespace EGG
