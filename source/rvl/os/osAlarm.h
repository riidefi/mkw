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

// PAL: 0x801a05b8..0x801a0610
void __OSInitAlarm();
// PAL: 0x801a0610..0x801a0620
void OSCreateAlarm(OSAlarm*);
// PAL: 0x801a0620..0x801a0870
void OS_Alarm_InsertAlarm(OSAlarm*, OSTime, OSAlarmHandler);
// PAL: 0x801a0870..0x801a08e0
void OSSetAlarm(OSAlarm*, OSTime, OSAlarmHandler);
// PAL: 0x801a08e0..0x801a0964
void OSSetPeriodicAlarm(OSAlarm*, OSTime, OSTime, OSAlarmHandler);
// PAL: 0x801a0964..0x801a0a7c
void OSCancelAlarm(OSAlarm*);
// PAL: 0x801a0a7c..0x801a0ca8
void OS_Alarm_DecrementerExceptionCallback(u8 exception, OSContext* context);
// PAL: 0x801a0ca8..0x801a0cf8
void OS_Alarm_DecrementerExceptionHandler(u8 exception, OSContext* context);
// PAL: 0x801a0cf8..0x801a0d00
void OSSetAlarmTag(OSAlarm*, u32);
// PAL: 0x801a0d00..0x801a0d8c
int OS_Alarm_OnReset(int, u32);
// PAL: 0x801a0d8c..0x801a0d94
void OSSetAlarmUserData(OSAlarm*, void*);
// PAL: 0x801a0d94..0x801a0d9c
void* OSGetAlarmUserData(OSAlarm*);

#ifdef __cplusplus
}
#endif
