/*!
 * @file
 * @brief TODO.
 */

#include <egg/core/eggHeap.hpp>
#include <egg/core/eggTaskThread.hpp>

#include <rvl/dvd/dvd.h>

namespace EGG {

TaskThread* TaskThread::create(int jobCount, int prio, u32 stackSize,
                               Heap* heap) {
  if (heap == nullptr) {
    heap = Heap::getCurrentHeap();
  }

  TaskThread* thread =
      new (heap, 4) TaskThread(jobCount, prio, stackSize); // r31
  if (thread == nullptr) {
    return nullptr;
  }

  thread->mCurrentJob = nullptr;
  thread->mJobs = new (heap, 4) TJob[jobCount];
  thread->mJobCount = jobCount;

  if (thread->mJobs == nullptr) {
    delete thread;

    return nullptr;
  }

  for (int i = 0; i < jobCount; ++i) {
    thread->mJobs[i].mMainFunction = nullptr;
    thread->mJobs[i].clearFunctions();
  }

  return thread;
}

TaskThread::TJob::TJob()
    : mEnterFunction(nullptr), mExitFunction(nullptr),
      mCallbackFunction(nullptr) {}

void TaskThread::destroy() {
  if (OSIsThreadTerminated(getOSThread()) != 1) {
    DVDCancelAll();
    delete[] mJobs;
    delete this;
  }
}

bool TaskThread::request(TaskThread::TFunction mainFunction, void* arg,
                         void* taskEndMessage) {
  TaskThread::TJob* slot = findBlank();
  if (!slot) {
    return false;
  }

  slot->mMainFunction = mainFunction;
  slot->mArg = arg;
  slot->mTaskEndMessage = taskEndMessage;

  bool res = sendMessage(slot);
  if (!res) {
    slot->mMainFunction = nullptr;
  }
  return res;
}

bool TaskThread::isTaskExist() const {
  for (int i = 0; i < mJobCount; i++) {
    if (mJobs[i].mMainFunction) {
      return true;
    }
  }

  return false;
}

TaskThread::~TaskThread() {}

void TaskThread::onEnter() {
  if (mCurrentJob && mCurrentJob->mEnterFunction) {
    mCurrentJob->mEnterFunction(mCurrentJob->mArg);
  }
}

void TaskThread::onExit() {
  if (mCurrentJob && mCurrentJob->mExitFunction) {
    mCurrentJob->mExitFunction(mCurrentJob->mArg);
  }
}

void* TaskThread::run() {
  OSInitFastCast();

  while (true) {
    TJob* currentJob = (TJob*)waitMessageBlock();
    mCurrentJob = currentJob;
    if (mCurrentJob->mMainFunction) {
      mCurrentJob->mMainFunction(mCurrentJob->mArg);

      if (mCurrentJob && mCurrentJob->mCallbackFunction) {
        mCurrentJob->mCallbackFunction(mCurrentJob->mArg);
      }

      if (mTaskEndMessageQueue)
        OSSendMessage(mTaskEndMessageQueue, currentJob->mTaskEndMessage,
                      OS_MESSAGE_NOBLOCK);
    }

    currentJob->mMainFunction = nullptr;
    mCurrentJob = nullptr;
    currentJob->clearFunctions();
  }
}

TaskThread::TaskThread(int msgCount, int prio, u32 stackSize)
    : Thread(stackSize, msgCount, prio, nullptr),
      mTaskEndMessageQueue(nullptr) {
  // TODO: Why is this needed?
  resume();
}

TaskThread::TJob* TaskThread::findBlank() {
  for (int i = 0; i < mJobCount; i++) {
    if (!mJobs[i].mMainFunction) {
      mJobs[i].clearFunctions();
      return &mJobs[i];
    }
  }

  return nullptr;
}

} // namespace EGG
