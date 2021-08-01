/*!
 * @file
 * @brief TODO.
 */

#include <egg/core/eggHeap.hpp>
#include <egg/core/eggTaskThread.hpp>
#include <revolution/dvd.h>
#include <revolution/os/OSFastCast.h>

namespace EGG {

TaskThread* TaskThread::create(int msgCount, int prio, u32 stackSize,
                               Heap* heap) {
  if (heap == nullptr)
    heap = Heap::sCurrentHeap;

  TaskThread* thread = new TaskThread(msgCount, prio, stackSize); // r31
  if (thread == nullptr)
    return nullptr;

  thread->mJobArray = new (heap, 4) TJob[msgCount];
  thread->mJobCount = msgCount;

  if (thread->mJobArray == nullptr) {
    delete thread;

    return nullptr;
  }

  for (int i = 0; i < msgCount; ++i) {
    thread->mJobArray[i]._00 = 0;
    thread->mJobArray[i]._0C = 0;
    thread->mJobArray[i]._10 = 0;
    thread->mJobArray[i]._14 = 0;
  }

  return thread;
}

TaskThread::TJob::TJob() { clearFunctions(); }

unk TaskThread::destroy() {
  if (OSIsThreadTerminated(mOSThread) != TRUE) {
    DVDCancelAll();
    delete[] mJobArray;
    delete this;
  }
}
// ...
bool TaskThread::request(TaskThread::JobRequestProbably req, void* a, void* b) {
  TaskThread::TJob* slot = findBlank();
  if (!slot)
    return false;

  slot->_00 = req;
  slot->_04 = a;
  slot->_08 = b;
  bool res = OSSendMessage(&mMesgQueue, slot, 0);
  if (!res)
    slot->_00 = 0;
  return res;
}
bool TaskThread::isTaskExist() const {
  if (mJobCount > 0) {
    for (int i = 0; i < mJobCount; i++) {
      if (mJobArray[i]._00) // lwzx?
        return true;
    }
  }
  return false;
}
TaskThread::~TaskThread() {}
void TaskThread::onEnter() {
  if (mReceivedJob && mReceivedJob->_0C)
    mReceivedJob->_0C(mReceivedJob->_04);
}
void TaskThread::onExit() {
  if (mReceivedJob && mReceivedJob->_10)
    mReceivedJob->_10(mReceivedJob->_04);
}
int TaskThread::run() {
#ifndef _WIN32
  OSInitFastCast();
#endif
  while (true) {
    OSMessage tmpMsg;
    OSReceiveMessage(&mMesgQueue, &tmpMsg, OS_MESSAGE_BLOCK);
    TJob* taskmsg = (TJob*)tmpMsg;
    mReceivedJob = taskmsg;
    if (mReceivedJob->_00) {
      mReceivedJob->_00(mReceivedJob->_04);
      if (mReceivedJob && mReceivedJob->_14) {
        mReceivedJob->_14(mReceivedJob->_04);
      }
      if (_54)
        OSSendMessage(_54, taskmsg, 0);
    }
    taskmsg->_00 = 0;
    mReceivedJob = 0;
    taskmsg->clearFunctions();
  }
}

TaskThread::TaskThread(int msgCount, int prio, u32 stackSize)
    : Thread(stackSize, msgCount, prio, NULL) {
  // TODO: Why is this needed?
  OSResumeThread(this->mOSThread);
}

TaskThread::TJob* TaskThread::findBlank() {
  if (mJobCount > 0) {
    for (int i = 0; i < mJobCount; i++) {
      if (mJobArray[i]._00) // lwzx?
      {
        TJob* prevJob = &mJobArray[i];
        mJobArray[i]._00 = NULL;
        prevJob->clearFunctions();
        return &mJobArray[i];
      }
    }
  }
  return nullptr;
}

} // namespace EGG
