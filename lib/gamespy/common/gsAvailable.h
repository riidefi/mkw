#pragma once

#include "gsStringUtil.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GSIStartAvailableCheck GSIStartAvailableCheckA

// the available check contacts a backend server at
// "<gamename>.available.gamespy.com" an app can resolve the hostname itself and
// store the IP here before starting the check
extern char GSIACHostname[64];

// these are possible return types for GSIAvailableCheckThink
typedef enum {
  GSIACWaiting,               // still waiting for a response from the backend
  GSIACAvailable,             // the game's backend services are available
  GSIACUnavailable,           // the game's backend services are unavailable
  GSIACTemporarilyUnavailable // the game's backend services are temporarily
                              // unavailable
} GSIACResult;

// start an available check for a particular game
// return 0 if no error starting up, non-zero if there's an error
void GSIStartAvailableCheckA(const char* gamename);

// let the available check think
// continue to call this while it returns GSIACWaiting
// if it returns GSIACAvailable, use the GameSpy SDKs as normal
// if it returns GSIACUnavailable or GSIACTemporarilyUnavailable, do NOT
// continue to use the GameSpy SDKs.  the backend services are not available
// for the game.  in this case, you can show the user a
// message based on the particular result.
GSIACResult GSIAvailableCheckThink(void);

// this should only be used if the availability check needs to be aborted
// for example, if the player leaves the game's multiplayer area before the
// check completes
void GSICancelAvailableCheck(void);

// internal use only
extern GSIACResult __GSIACResult;
extern char __GSIACGamename[64];

#ifdef __cplusplus
}
#endif
