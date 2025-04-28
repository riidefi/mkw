#pragma once

#include <decomp.h>
#include <rk_types.h>

#include "os.h"
#include "osContext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm*, OSContext*);

struct OSAlarm {
  OSAlarmHandler handler;
  u32 tag;
  OSTime fire;
  OSAlarm* pred;
  OSAlarm* succ;
  OSTime repeat;
  OSTime begin;
  void* data;
};

void __OSInitAlarm();
void OSCreateAlarm(OSAlarm*);
void OS_Alarm_InsertAlarm(OSAlarm*, OSTime, OSAlarmHandler);
void OSSetAlarm(OSAlarm*, OSTime, OSAlarmHandler);
void OSSetPeriodicAlarm(OSAlarm*, OSTime, OSTime, OSAlarmHandler);
void OSCancelAlarm(OSAlarm*);
void OS_Alarm_DecrementerExceptionCallback(u8 exception, OSContext* context);
void OS_Alarm_DecrementerExceptionHandler(u8 exception, OSContext* context);
void OSSetAlarmTag(OSAlarm*, u32);
int OS_Alarm_OnReset(int, u32);
void OSSetAlarmUserData(OSAlarm*, void*);
void* OSGetAlarmUserData(OSAlarm*);

#ifdef __cplusplus
}
#endif
