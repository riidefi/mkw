/*!
 * @file
 * @brief TODO.
 */

#pragma once

#include <Common/rk_types.h>
#include <EGG/core/eggHeap.hpp>
#include <EGG/core/eggThread.hpp>

namespace EGG {

//! @brief TODO sizeof 0x58
//!
class TaskThread : public Thread {
public:
  typedef void* (*JobRequestProbably)(void*);

  static TaskThread* create(int msgCount, int prio, u32 stackSize, Heap* heap);

  struct TJob {
    JobRequestProbably _00; // called; "isTaskExist" checks this
    void* _04;              // argument?
    void* _08;              // ud?

    JobRequestProbably _0C; // 0C EnterRequest?
    JobRequestProbably _10; // exitRequst?
    JobRequestProbably _14; // set to 0 in ct

    TJob();
    // inlined only. though if inline not sure
    inline void clearFunctions() { _0C = _10 = _14 = 0; }
  };

  unk destroy();
  bool request(JobRequestProbably, void*, void*);
  bool isTaskExist() const;

  // Thread overrides
  ~TaskThread() override;
  void onEnter() override;
  void onExit() override;
  int run() override;

  //! @brief Create a task thread and resume current thread
  //!
  TaskThread(int msgCount, int prio, u32 stackSize);
  TJob* findBlank();

  // starts at 0x40
  TJob* mReceivedJob;  // 48 for receiving msgs
  TJob* mJobArray;     //!< [+0x4C] sppepcial __construct_new_array with TJob.
                       //!< sizeof MessageCount
  u32 mJobCount;       // 50 Number of jobs / messages
  OSMessageQueue* _54; // 54
};

} // namespace EGG
