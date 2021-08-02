#include <egg/core/eggHeap.hpp>
#include <egg/core/eggThread.hpp>
#include <egg/eggInternal.hpp>

#include <rvl/os/osMessage.h>

namespace EGG {

nw4r::ut::List Thread::sThreadList;

Thread::Thread(u32 stackSize, int msgCount, int prio, Heap* heap) {
  if (!heap)
    heap = Heap::getCurrentHeap();

  mContainingHeap = heap;
  mStackSize = ROUND_DOWN(stackSize, 32);
  mStackMemory =
      reinterpret_cast<char*>(Heap::alloc(mStackSize, 32, mContainingHeap));
  EGG_ASSERT(mStackMemory, "eggThread.cpp", 70, "mStackMemory");

  mOSThread = Heap::alloc<OSThread>(mContainingHeap, 32);
  EGG_ASSERT(mOSThread, "eggThread.cpp", 80, "mOSThread");

  OSCreateThread(mOSThread, start,
                 this,                      // argument for start
                 mStackMemory + mStackSize, // the created stackBase is the
                                            // very highest value
                 mStackSize, prio, 1);

  mAlloctableHeap = nullptr;
  setCommonMesgQueue(msgCount, mContainingHeap);
}

Thread::Thread(OSThread* osThread, int msgCount)
    : mContainingHeap(nullptr), mOSThread(osThread) {
  mStackSize = (char*)osThread->stack_low - (char*)osThread->stack_high;
  mStackMemory = osThread->stack_high;

  mAlloctableHeap = nullptr;
  setCommonMesgQueue(msgCount, Heap::getCurrentHeap());
}

Thread::~Thread() {
  nw4r::ut::List_Remove(&sThreadList, this);

  if (mContainingHeap != nullptr) {
    if (!OSIsThreadTerminated(mOSThread)) {
      OSDetachThread(mOSThread);
      OSCancelThread(mOSThread);
    }

    Heap::free(mStackMemory, mContainingHeap);
    Heap::free(mOSThread, mContainingHeap);
  }

  Heap::free(mMesgBuffer, nullptr);
}

Thread* Thread::findThread(OSThread* osThread) {
  Thread* iterThread = nullptr;

  while ((iterThread = (Thread*)List_GetNext(&sThreadList, iterThread)))
    if (iterThread->mOSThread == osThread)
      return iterThread;

  return nullptr;
}

void Thread::kandoTestCancelAllThread() {
  Thread* iterThread = nullptr; // r30

  while ((iterThread = (Thread*)List_GetNext(&sThreadList, iterThread))) {
    OSThread* cur = OSGetCurrentThread();
    OSThread* thread = iterThread->mOSThread;
    if (cur != thread)
      OSCancelThread(thread);
  }
}

void Thread::initialize() {
  // offsetof(Thread, nw4r::ut::Node)
  List_Init(&sThreadList, 0x40);
  OSSetSwitchThreadCallback(switchThreadCallback);
}

void Thread::switchThreadCallback(OSThread* from, OSThread* to) {
  // findThread inlined twice
  Thread* fromThread = from ? findThread(from) : nullptr; // r30
  Thread* toThread = to ? findThread(to) : nullptr;       // r31

  if (fromThread != nullptr)
    fromThread->onExit();

  if (toThread != nullptr)
    toThread->onEnter();
}

void Thread::setCommonMesgQueue(int msgCount, EGG::Heap* heap) {
  mMesgCount = msgCount;
  mMesgBuffer = Heap::alloc<OSMessage>(msgCount, heap);
  EGG_ASSERT(mMesgBuffer, "eggThread.cpp", 262, "mMesgBuffer");

  OSInitMessageQueue(&mMesgQueue, mMesgBuffer, mMesgCount);
  List_Append(&sThreadList, this);
}

void* Thread::start(void* eggThread) {
  return reinterpret_cast<Thread*>(eggThread)->run();
}

void* Thread::run() { return nullptr; }

} // namespace EGG
