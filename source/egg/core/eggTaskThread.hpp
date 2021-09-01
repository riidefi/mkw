/*!
 * @file
 * @brief TODO.
 */

#pragma once

#include <egg/core/eggHeap.hpp>
#include <egg/core/eggThread.hpp>

#include <rk_types.h>

namespace EGG {

class TaskThread : public Thread {
public:
  typedef void (*TFunction)(void*);

  static TaskThread* create(int msgCount, int prio, u32 stackSize, Heap* heap);

  struct TJob {
    TFunction mMainFunction;
    void* mArg;
    void* mTaskEndMessage;
    TFunction mEnterFunction;
    TFunction mExitFunction;
    TFunction mCallbackFunction;

    TJob();

    inline void clearFunctions() {
      mMainFunction = nullptr;
      mEnterFunction = nullptr;
      mExitFunction = nullptr;
      mCallbackFunction = nullptr;
    }
  };

  void destroy();
  bool request(TFunction mainFunction, void* arg, void* _08);
  bool isTaskExist() const;

  // Thread overrides
  ~TaskThread() override;
  void onEnter() override;
  void onExit() override;
  void* run() override;

  //! @brief Create a task thread and resume current thread
  //!
  TaskThread(int msgCount, int prio, u32 stackSize);
  TJob* findBlank();

  TJob* mCurrentJob;
  TJob* mJobs;
  s32 mJobCount;
  OSMessageQueue* mTaskEndMessageQueue;
};

} // namespace EGG
