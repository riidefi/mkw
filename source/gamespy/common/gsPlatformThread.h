///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "gsPlatform.h"

#include <rvl/os/osMutex.h>
#include <rvl/os/osSemaphore.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Thread types
typedef OSMutex GSICriticalSection;
typedef OSSemaphore GSISemaphoreID;
typedef struct {
  OSThread mThread;
  void* mStack;
} GSIThreadID;
typedef void* (*GSThreadFunc)(void* arg);

#define GSI_INFINITE (gsi_u32)(-1)

gsi_u32 gsiInterlockedIncrement(gsi_u32* num);
gsi_u32 gsiInterlockedDecrement(gsi_u32* num);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int gsiStartThread(GSThreadFunc aThreadFunc, gsi_u32 theStackSize, void* arg,
                   GSIThreadID* theThreadIdOut);
void gsiCancelThread(GSIThreadID theThreadID);
void gsiExitThread(GSIThreadID theThreadID);
void gsiCleanupThread(GSIThreadID theThreadID);

// Thread Synchronization - Startup/Shutdown
gsi_u32 gsiHasThreadShutdown(GSIThreadID theThreadID);

// Thread Synchronization - Critical Section
void gsiInitializeCriticalSection(GSICriticalSection* theCrit);
void gsiEnterCriticalSection(GSICriticalSection* theCrit);
void gsiLeaveCriticalSection(GSICriticalSection* theCrit);
void gsiDeleteCriticalSection(GSICriticalSection* theCrit);

// Thread Synchronization - Semaphore
GSISemaphoreID gsiCreateSemaphore(gsi_i32 theInitialCount, gsi_i32 theMaxCount,
                                  char* theName);
gsi_u32 gsiWaitForSemaphore(GSISemaphoreID theSemaphore, gsi_u32 theTimeoutMs);
void gsiReleaseSemaphore(GSISemaphoreID theSemaphore, gsi_i32 theReleaseCount);
void gsiCloseSemaphore(GSISemaphoreID theSemaphore);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
