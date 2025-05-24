/**
 * @file
 * @brief Thread class for extending.
 */

#pragma once

#include <nw4r/ut/utList.hpp>
#include <rk_types.h>
#ifndef RII_CLIENT
#include <rvl/os/osMessage.h>
#include <rvl/os/osThread.h>
#endif

namespace EGG {

class Heap;

//---------------------------------------------------------------------------
//! @brief   Wrapper for OSThread.
//---------------------------------------------------------------------------
class Thread {
public:
  virtual ~Thread(); //!< [vt+0x08] Destroys the EGG Thread, freeing all used
                     //!< memory and canceling the OSThread

  virtual void* run();           //!< [vt+0x0C]
  virtual void onEnter(); /*{}*/ //!< [vt+0x14]
  virtual void onExit(); /*{}*/  //!< [vt+0x10]

  //! @brief   	A constructor.
  //!
  //! @details	Creates an EGG::Thread and OSThread from arguments.
  //!
  //! @param[in]	stackSize:	The size of the stack to create.
  //! @param[in] 	msgCount:	The maximum number of messages the
  //! buffer can hold.
  //! @param[in]	prio:		Priority of the OSThread to create. 0 is
  //! highest priority; 31 is lowest priority.
  //!							The default thread has a
  //! priority of 16.
  //!
  //! @param[in]	heap:		Heap to use for allocations.
  //!
  Thread(u32 stackSize, int msgCount, int prio, Heap* heap);

  //! @brief   	A constructor.
  //!
  //! @details	Creates an EGG::Thread to wrap the provided OSThread.
  //!
  //! @param[in]	osThread: 	OS thread to wrap.
  //! @param[in] 	msgCount:	The maximum number of messages the
  //! buffer can hold.
  //!
  Thread(OSThread* osThread, int msgCount);

private:
  inline Thread(const Thread&) {}

public:
  //! @brief   	Find the (first) EGG::Thread that matches the provided osThread.
  //!
  //! @details	Iterate through the static thread list (sThreadList) to find the
  //! first EGG thread
  //!				that wraps the specified OS thread.
  //!
  //! @param[in]	osThread: 	The OS thread to search for.
  //!
  //! @return 	The found EGG thread.
  //! @retval		NULL: No matching EGG thread was found.
  //!
  static Thread* findThread(OSThread* osThread);

  //! @brief   	Cancel all but the current thread.
  //!
  //! @details	Iterates through registed threads in sThreadList, checking
  //! against
  //!				OSGetCurrentThread(), then calling
  //! OSCancelThread().
  //!
  static void kandoTestCancelAllThread();

  //! @brief   	Initialize EGG Thread.
  //!
  //! @details	Initializes sThreadList and sets the SwitchThreadCallback to
  //!				Thread::switchThreadCallback.
  //!
  static void initialize();

  //! @brief   	The callback for switching threads.
  //!
  //! @details	Finds the associated EGG threads of the two OSThreads, and calls
  //! onExit()
  //!				on the first thread and onEnter() on the next.
  //!
  //! @param[in]	from: 	The last thread running.
  //! @param[in] 	to:		The next thread to run.
  //!
  //! @note		Either threads may be null if there is no thread to run.
  //!				This function handles this accordingly
  //!
  static void switchThreadCallback(OSThread* from, OSThread* to);

  //! @brief   	Configures the message queue.
  //!
  //! @details	- Allocates mMesgBuffer to msgCount * 4
  //!				- Calls OSInitMessageQueue using mMesgQueue and
  //! mMesgBuffer
  //!				- Appends this Thread to sThreadList
  //!
  //! @param[in]	msgCount: 	The maximum number of messages the
  //! buffer can hold.
  //!							The buffer size in bytes
  //! will be msgCount
  //!* 4.
  //!
  void setCommonMesgQueue(int msgCount, Heap* heap);

  //! @brief   	Starts a thread.
  //!
  //! @details	Casts eggThread to EGG::Thread* and calls the virtual run
  //! method.
  //!
  //! @param[in]	eggThread: 	Pointer to an object that inherits
  //! Thread.
  //!
  static void* start(void* eggThread);

  inline OSMessageQueue* getMesgQueue() { return &mMesgQueue; }

  inline OSThread* getOSThread() { return mOSThread; }

  //! When not NULL will override the heap used for allocations.
  inline Heap* getAllocatableHeap() { return mAlloctableHeap; }

  inline void resume() { OSResumeThread(mOSThread); }

  inline int sendMessage(OSMessage message) {
    return OSSendMessage(&mMesgQueue, message, OS_MESSAGE_NOBLOCK);
  }

  inline OSMessage waitMessage(int* success) {
    OSMessage message;
    *success = OSReceiveMessage(&mMesgQueue, &message, OS_MESSAGE_NOBLOCK);
    return message;
  }

  inline OSMessage waitMessageBlock() {
    OSMessage message;
    OSReceiveMessage(&mMesgQueue, &message, OS_MESSAGE_BLOCK);
    return message;
  }

private:
  // List of all registered threads.
  static nw4r::ut::List sThreadList;

  Heap* mContainingHeap; //!< [+0x04] Heap to use for thread-specific
                         //!< allocations (in ctor: create stack and OSThread)
  OSThread* mOSThread;   //!< [+0x08] The OS thread this object wraps. Name
                         //!< confirmed by WS assert.

  OSMessageQueue mMesgQueue; //!< [+0x0C] sizeof=0x20
  OSMessage* mMesgBuffer;    //!< [+0x2C] name confirmed WS assert
  int mMesgCount;            //!< [+0x30]

  char* mStackMemory; //!< [+0x34] The base (*beginning*) of the stack.
  u32 mStackSize;     //!< [+0x38] The size of the stack.

  Heap* mAlloctableHeap; //!< [0+x3C] When not NULL will override the heap used
                         //!< for allocations. (Note: Does not escape the
                         //!< Heap::sAllocatableHeap restriction.)
  nw4r::ut::Node mLink;
};

} // namespace EGG
