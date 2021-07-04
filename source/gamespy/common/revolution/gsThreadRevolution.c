///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "../gsCommon.h"
 
#include <stdbool.h>

// Begin of Threading for Revolution    
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
gsi_u32 gsiInterlockedIncrement(gsi_u32 * value)
{
	int enabled = OSDisableInterrupts();

	gsi_u32 ret = ++(*value);
	OSRestoreInterrupts(enabled);

	// return "ret" rather than "value" here b/c
	// value may be modified by another thread 
	// before we can return it
	return ret;
}

gsi_u32 gsiInterlockedDecrement(gsi_u32 * value)
{
	int state = OSDisableInterrupts();
	gsi_u32 ret = --(*value);
	OSRestoreInterrupts(state);

	// return "ret" rather than "value" here b/c
	// value may be modified by another thread 
	// before we can return it
	return ret;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int gsiStartThread(GSThreadFunc aThreadFunc, gsi_u32 theStackSize, void *arg, GSIThreadID* theThreadIdOut)
{
	char *aStackBase;
	if(theStackSize % 32 != 0)
	{
		OSRoundUp32B(theStackSize);
	}

	theThreadIdOut->mStack = gsimalloc(theStackSize);
	aStackBase = (char *)theThreadIdOut->mStack;
	aStackBase += theStackSize;
	
	OSCreateThread(&theThreadIdOut->mThread, aThreadFunc, arg, (void *)aStackBase, 
				   theStackSize, 16, 0x0001u);

	OSResumeThread(&theThreadIdOut->mThread);

	return 0;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiCancelThread(GSIThreadID theThreadID)
{
	OSCancelThread(&theThreadID.mThread);
	if(theThreadID.mStack)
	{
		gsifree(theThreadID.mStack);
		theThreadID.mStack = NULL;
	}
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiCleanupThread(GSIThreadID theThreadID)
{

	if (!OSIsThreadTerminated(&theThreadID.mThread))
		OSCancelThread(&theThreadID.mThread);
	if(theThreadID.mStack)
	{
		gsifree(theThreadID.mStack);
		theThreadID.mStack = NULL;
	}
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
gsi_u32 gsiHasThreadShutdown(GSIThreadID theThreadID)
{
	int shutdown = OSIsThreadTerminated(&theThreadID.mThread);

	if(shutdown == true)
		return 1;
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiInitializeCriticalSection(GSICriticalSection *theCrit)
{
	OSInitMutex(theCrit);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiEnterCriticalSection(GSICriticalSection *theCrit)
{
	OSLockMutex(theCrit);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiLeaveCriticalSection(GSICriticalSection *theCrit)
{
	OSUnlockMutex(theCrit);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiDeleteCriticalSection(GSICriticalSection *theCrit)
{
	GSI_UNUSED(theCrit);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/*
GSISemaphoreID gsiCreateSemaphore(gsi_i32 theInitialCount, gsi_i32 theMaxCount, char* theName)
{
	GSISemaphoreID semaphore;

	OSInitSemaphore(&semaphore, theInitialCount);

	GSI_UNUSED(theName);
	GSI_UNUSED(theMaxCount);
	
	return semaphore;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
gsi_u32 gsiWaitForSemaphore(GSISemaphoreID theSemaphore, gsi_u32 theTimeoutMs)
{
	gsi_u32 retval = (unsigned int)OSWaitSemaphore(&theSemaphore);
	GSI_UNUSED(theTimeoutMs);
	return retval;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiReleaseSemaphore(GSISemaphoreID theSemaphore, gsi_i32 theReleaseCount)
{
	OSSignalSemaphore(&theSemaphore);
	GSI_UNUSED(theReleaseCount);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiCloseSemaphore(GSISemaphoreID theSemaphore)
{
	GSI_UNUSED(theSemaphore);
}
*/


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiExitThread(GSIThreadID theThreadID)
{
	GSI_UNUSED(theThreadID);
}



// End of Threading for Revolution 
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////