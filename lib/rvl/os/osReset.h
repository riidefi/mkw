#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef BOOL (*OSShutdownFunction)(BOOL final, u32 event);

typedef enum {
  OS_SD_EVENT_SHUTDOWN = 2,
  OS_SD_EVENT_RESTART = 4,
  OS_SD_EVENT_RETURN_TO_MENU = 5,
  OS_SD_EVENT_LAUNCH_APP = 6,
} OSShutdownEvent;

typedef struct OSShutdownFunctionInfo {
  u32 func;
  u32 priority;
  u32 succ;
  u32 prev;
} OSShutdownFunctionInfo;

typedef struct OSShutdownFunctionQueue {
  OSShutdownFunctionInfo *head;
  OSShutdownFunctionInfo *tail;
} OSShutdownFunctionQueue;

void OSReturnToMenu(void);
void OSRegisterShutdownFunction(OSShutdownFunctionInfo *info);
void __OSShutdownDevices(OSShutdownEvent event);
void __OSGetDiscState(u8 *out);
void OSShutdownSystem(void);
BOOL __OSCallShutdownFunctions(BOOL final, u32 event);
void __OSReturnToMenuForError(void);
void __OSHotResetForError(void);
u32 OSGetResetCode(void);
void OSResetSystem(BOOL arg0, u32 arg1, BOOL arg2);

#define OSIsRestart() ((OSGetResetCode() & 0x80000000) ? TRUE : FALSE)

#ifdef __cplusplus
}
#endif
