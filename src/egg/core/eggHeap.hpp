/**
 * @file
 * @brief Base Heap class.
 */

#pragma once

#ifndef HEAP_PRIVATE
#define HEAP_PRIVATE protected
#endif

#include <egg/core/eggDisposer.hpp>
#include <nw4r/ut/utList.hpp>
#include <rk_types.h>
#include <rvl/os/osThread.h>
#include <rvl/mem/memAllocator.h>
#include <egg/core/eggThread.hpp>

namespace EGG {

class ExpHeap;
class Allocator;

struct HeapAllocArg {
  int userArg; // 00
  u32 size;    // 04
  int align;   // 08
  Heap* heap;  // 0C heap to allocate in

  inline HeapAllocArg() : userArg(0), size(0), align(0), heap(nullptr) {}
};
typedef void (*HeapAllocCallback)(HeapAllocArg& arg);

struct HeapErrorArg {
  const char* msg;
  void* userdata;

  inline HeapErrorArg() {}
};

typedef void (*ErrorCallback)(void*);

//! @brief   Base Heap class
//!
//! @details EGG::Heap is not concrete and only acts as an interface for actual
//! implementations.
//!
class Heap : public Disposer {
public:
  //! @brief Types of heaps that can be created
  //!
  enum eHeapKind {
    HEAP_KIND_NONE = 0, //!< [0] Unconfirmed!
    HEAP_KIND_EXPANDED, //!< [1] Expanded heap.
    HEAP_KIND_FRAME,    //!< [2] Frame heap. Doesn't exist in MKW's EGG.
    HEAP_KIND_UNIT      //!< [3] Unit heap.
  };

  inline bool isExpHeap() { return getHeapKind() == HEAP_KIND_EXPANDED; }
  inline Heap* getParentHeap() { return mParentHeap; }
  inline void* getStartAddress() { return this; }

  virtual ~Heap();

  //! @brief [vt+0x0C] Get the type of heap the current heap is.
  //!
  //! @returns The eHeapKing of the heap.
  //!
  virtual eHeapKind getHeapKind() const = 0;

  virtual void initAllocator(Allocator* allocator, s32 align) = 0; // [vt+0x10]
  virtual void* alloc(u32 size, s32 align) = 0;                    // [vt+0x14]
  virtual void free(void* block) = 0;                              // [vt+0x18]
  virtual void destroy() = 0;                                      // [vt+0x1C]
  virtual u32 resizeForMBlock(void* block, u32 size) = 0;          // [vt+0x20]
  virtual u32 getAllocatableSize(s32 align) = 0;                   // [vt+0x24]
  virtual u32 adjust() = 0;                                        // [vt+0x28]

  HEAP_PRIVATE :
      //! @brief   	Static linked-list of heaps.
      //!
      //! @details	When a heap is created, it is appended to this list.
      //!				When it is deleted, it is removed.
      //!
      static nw4r::ut::List sHeapList;

  //! @brief   	Root heap mutex.
  //!
  static OSMutex sRootMutex;

  //! @brief When the heap passed to alloc is NULL, use this instead.
  static Heap* sCurrentHeap;

  //! @brief Whether or not the static list of heaps has been initialized.
  //! @see   initialize
  static int sIsHeapListInitialized;

  //! @brief	When non NULL, this heap MUST be used for heap allocations.
  //!			This will restrict rather than redirect allocations.
  static Heap* sAllocatableHeap;
  static ErrorCallback sErrorCallback;     //!< TODO
  static HeapAllocCallback sAllocCallback; //!< TODO
  static void* sErrorCallbackArg;          //!< TODO
  static void* sAllocCallbackArg;          //!< TODO
  static class Thread* sAllocatableThread; //!< TODO
public:
  //! @brief [+0x10] argument of heap constructor. Name confirmed by WS assert.
  MEMHeapHandle mHeapHandle;
  //! @brief [+0x14] set to 0 in heap ctor. treeki -- void* parentHeapMBlock
  void* mParentBlock;
  //! @brief [+0x18] name from findParentHeap()
  Heap* mParentHeap;
  //! @brief [+0x1C] Values of HeapFlag
  enum HeapFlag {
    // tstDisableAllocation, enableAllocation, disableAllocation
    // setBit__Q23EGG12TBitFlag<Us>FUc
    HEAP_FLAG_LOCKED = (1 << 0)
  };
  u16 mFlag;
  // 2b implicit pad?

  //! @details List of child disposers.
  //! When Heap::dispose() is called, ~Disposer() will be called for all
  //! children.
  nw4r::ut::Node mNode;     //!< [+0x20]
  nw4r::ut::List mChildren; //!< [+0x28] sizeof=0xC

  const char* mName; //!< [+0x034] set to "NoName" in ctor

public:
  //! @brief   	Must be called before heaps are created. Prepares static heap
  //! members.
  //!
  //! @details	Initializes the static heap data for heap creation.
  //!
  //! @post
  //!	- sHeapList is initialized.
  //!	- sRootMutex is initialized.
  //!	- sIsHeapListInitialized is true.
  //!
  //!
  static void initialize();

  //! @brief   	Heap constructor.
  //!
  //! @details	Creates a Heap wrapper around the supplied MEM heap.
  //!				- Calls down to the parent Disposer constructor
  //! before setting values.
  //!				- Parent members _14, _18, _1C are zeroed; mName
  //! is set to "NoName".
  //!				- ut::List at _28 initialized.
  //!				- This heap is added to the global heap list
  //!(sHeapList).
  //!
  //! @param[in]	heapHandle: MEM heap handle to create EGG::Heap wrapper
  //! around.
  //!
  //! @pre 		initialize() has been called. (WS asserts
  //! sHeapInitialized)
  //!
  //! @return 	this
  //!
  Heap(MEMiHeapHead* heapHandle);

private:
  inline Heap(const Heap&) {}

public:
  //! @brief   	Allocate a block of memory in a heap.
  //!
  //! @details	TODO
  //!
  //! @param[in]	size: 	Size of the block in bytes.
  //! @param[in]  align:	Alignment of block to create.
  //! @param[in]	heap:	Heap to allocate block in.
  //!
  //! @return 	The address of the allocated block.
  //! @retval		NULL: The allocation failed.
  //!
  static void* alloc(u32 size, int align, Heap* heap);

  template <typename T> static T* alloc(u32 count, Heap* heap, int align = 4) {
    return reinterpret_cast<T*>(alloc(count * sizeof(T), align, heap));
  }
  template <typename T> static T* alloc(Heap* heap, int align = 4) {
    return reinterpret_cast<T*>(alloc(sizeof(T), align, heap));
  }

  //! @brief   	Returns the Disposer's parent heap.
  //!
  //! @details	Initializes the static heap data for heap creation.
  //!
  //! @pre		mHeapHandle != NULL. (WS assert)
  //!
  Heap* findParentHeap();

  //! @brief   	Scan global heap list for heap containing specified memory
  //! block.
  //!
  //! @details	First runs MEMFindContainHeap() to determine if it is in a MEM
  //! heap.
  //!				If this check passes, it will iterate through
  //! sHeapList, checking if 				the heap in each
  //! iteration's _10 matches the MEM heap found before.
  //!
  //! @param[in]	memBlock: Memory block to look scan for container.
  //!
  //! @pre 		sHeapList is intialized. (sIsHeapListInitialized)
  //!
  //! @return 	The Heap that contains the memory block.
  //! @retval		nullptr: The memory block is not contained in any heap
  //!
  static Heap* findContainHeap(const void* memBlock);

  //! @brief   	Free a block of memory from a heap.
  //!
  //! @details	Safely calls heap virtual free function on a memory block.
  //! Memory contained in a non EGG heap cannot be used.
  //!
  //! @param[in]	memBlock Block of memory to free.
  //! @param[in]  heap     Heap of memBlock to use for free. If NULL, it will be
  //! rederived.
  //!
  //! @pre 		If no heap is provided, the global heap list must be
  //! initialized.
  //!
  static void free(void* memBlock, Heap* heap);

  //! @brief   	Destroy all child heaps.
  //!
  //! @details	Calls destructor on first heap in child heap list until there
  //! are no children.
  //!
  void dispose();

  static void dumpAll();

  //! @brief   	Let this heap become the current heap.
  //!
  //! @details	Sets the static Heap sCurrentHeap to this.
  //!
  //! @pre 		sRootMutex is intialized.
  //!
  //! @return 	The previous current heap.
  //!
  Heap* becomeCurrentHeap();

public:
  bool hasFlag(u8 idx) volatile { return mFlag & 1 << idx; }

  void clearFlag(u8 idx) volatile { mFlag &= ~(1 << idx); }

  void setFlag(u8 idx) volatile { mFlag |= (1 << idx); }

  //! @brief Enables the heap's allocation.
  //!
  //! @return Whether or not the heap's allocation was disabled.
  //!
  bool enableAllocation() {
    bool b = hasFlag(0);
    if (b)
      clearFlag(0);
    return b;
  }

  //! @brief Disables the heap's allocation.
  //!
  void disableAllocation() {
    setFlag(0);
  }

  static void* addOffset(void* begin, u32 size) {
    return reinterpret_cast<char*>(begin) + size;
  }

  inline void appendDisposer(Disposer* disposer) {
    nw4r::ut::List_Append(&mChildren, disposer);
  }
  inline void removeDisposer(Disposer* disposer) {
    nw4r::ut::List_Remove(&mChildren, disposer);
  }

  inline MEMiHeapHead* getHeapHandle() { return mHeapHandle; }

  static inline Heap* getCurrentHeap() { return sCurrentHeap; }

  inline int getArenaEnd() {
#ifdef RII_CLIENT
    return 0;
#else
    return (int)mHeapHandle->arena_end;
#endif
  }
};

} // namespace EGG

void* operator new(size_t size);
// __nwa(ulong, ulong)
void* operator new[](size_t size, u32 align);
// __nw(ulong, EGG::Heap *, int)
void* operator new(size_t size, EGG::Heap* heap, int align);
// __nwa(ulong)
void* operator new[](size_t size);
// __nwa(ulong, int)
void* operator new[](size_t size, int align);
// __nwa(ulong, EGG::Heap *, int)
void* operator new[](size_t size, EGG::Heap* heap, int align);
// __dl(void *)
void operator delete(void* p);
// __dla(void *)
void operator delete[](void*);

#undef HEAP_PRIVATE
