///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "gsCommon.h"
#include "gsDebug.h"

// This is the platform specific default assert condition handler
extern void _gsDebugAssert(const char* string);

static gsDebugAssertCallback gsDebugAssertHandler = _gsDebugAssert;

//  Call this function to override the default assert handler
//	New function should render message / log message based on string passed
void gsDebugAssertCallbackSet(gsDebugAssertCallback theCallback) {
  if (theCallback)
    gsDebugAssertHandler = theCallback;
  else
    gsDebugAssertHandler = _gsDebugAssert;
}

// This is the default assert condition handler
void gsDebugAssert(const char* szError, const char* szText, const char* szFile,
                   int line) {
  char String[256];
  // format into buffer
  sprintf(&String[0], szError, szText, szFile, line);

  // call plat specific handler
  (*gsDebugAssertHandler)(String);
}

// ****************************************************
// Todo: move to platform specific modules
void _gsDebugAssert(const char* string) { OSHalt(string); }
