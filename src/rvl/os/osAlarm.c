#include "osAlarm.h"

#include "osException.h"
#include "osInterrupt.h"
#include "osReset.h"

// Extern function references.
// PAL: 0x8012e594
extern void PPCMtdec(u32);
// PAL: 0x80163594
extern int __DVDTestAlarm(const OSAlarm*);
// PAL: 0x801a9e30
extern void __OSReschedule();
// PAL: 0x801aad7c
extern OSTime __OSGetSystemTime();
// PAL: 0x801aade0
extern OSTime __OSTimeToSystemTime(OSTime);

static struct OS_AlarmQueue {
  OSAlarm* head;
  OSAlarm* tail;
} alarmQueue;

static OSShutdownFunctionInfo shutdownFunctionInfo = {
    (u32)OS_Alarm_OnReset,
    0xffffffff,
};

static inline void OS_AlarmSetTimer(OSAlarm* a) {
  OSTime x = a->fire - __OSGetSystemTime();
  if (x < 0)
    PPCMtdec(0);
  else if (x < 0x80000000)
    PPCMtdec((u32)x);
  else
    PPCMtdec(0x7fffffff);
}

// Symbol: __OSInitAlarm
// PAL: 0x801a05b8..0x801a0610
void __OSInitAlarm() {
  if (__OSGetExceptionHandler(8) != OS_Alarm_DecrementerExceptionHandler) {
    alarmQueue.head = alarmQueue.tail = 0;
    __OSSetExceptionHandler(8, OS_Alarm_DecrementerExceptionHandler);
    OSRegisterShutdownFunction(&shutdownFunctionInfo);
  }
}

// Symbol: OSCreateAlarm
// PAL: 0x801a0610..0x801a0620
void OSCreateAlarm(OSAlarm* a) {
  a->handler = NULL;
  a->tag = 0;
}

// Symbol: OS_Alarm_InsertAlarm
// PAL: 0x801a0620..0x801a0870
void OS_Alarm_InsertAlarm(OSAlarm* a, OSTime t, OSAlarmHandler handler) {
  if (0 < a->repeat) {
    OSTime now = __OSGetSystemTime();
    t = a->begin;
    if (a->begin < now)
      t += a->repeat * ((now - a->begin) / a->repeat + 1);
  }
  a->handler = handler;
  a->fire = t;
  OSAlarm* succ;
  OSAlarm* pred;
  for (succ = alarmQueue.head; succ; succ = succ->succ) {
    if (succ->fire <= t)
      continue;
    a->pred = succ->pred;
    succ->pred = a;
    a->succ = succ;
    pred = a->pred;
    if (pred) {
      pred->succ = a;
    } else {
      alarmQueue.head = a;
      OS_AlarmSetTimer(a);
    }
    return;
  }
  a->succ = NULL;
  pred = alarmQueue.tail;
  alarmQueue.tail = a;
  a->pred = pred;
  if (pred) {
    pred->succ = a;
  } else {
    alarmQueue.head = alarmQueue.tail = a;
    OS_AlarmSetTimer(a);
  }
}

// Symbol: OSSetAlarm
// PAL: 0x801a0870..0x801a08e0
void OSSetAlarm(OSAlarm* a, OSTime time, OSAlarmHandler handler) {
  int interrupts = OSDisableInterrupts();
  a->repeat = 0;
  OS_Alarm_InsertAlarm(a, __OSGetSystemTime() + time, handler);
  OSRestoreInterrupts(interrupts);
}

// Symbol: OSSetPeriodicAlarm
// PAL: 0x801a08e0..0x801a0964
void OSSetPeriodicAlarm(OSAlarm* a, OSTime start, OSTime interval,
                        OSAlarmHandler handler) {
  int interrupts = OSDisableInterrupts();
  a->repeat = interval;
  a->begin = __OSTimeToSystemTime(start);
  OS_Alarm_InsertAlarm(a, 0, handler);
  OSRestoreInterrupts(interrupts);
}

// Symbol: OSCancelAlarm
// PAL: 0x801a0964..0x801a0a7c
void OSCancelAlarm(OSAlarm* a) {
  int interrupts = OSDisableInterrupts();
  if (!a->handler) {
    OSRestoreInterrupts(interrupts);
    return;
  }
  OSAlarm* succ = a->succ;
  if (!succ)
    alarmQueue.tail = a->pred;
  else
    succ->pred = a->pred;
  if (a->pred)
    a->pred->succ = succ;
  else {
    alarmQueue.head = succ;
    if (succ)
      OS_AlarmSetTimer(succ);
  }
  a->handler = NULL;
  OSRestoreInterrupts(interrupts);
}

// Symbol: OS_Alarm_DecrementerExceptionCallback
// PAL: 0x801a0a7c..0x801a0ca8
void OS_Alarm_DecrementerExceptionCallback(u8, OSContext* context) {
  OSTime now = __OSGetSystemTime();
  OSAlarm* a = alarmQueue.head;
  if (!a)
    OSLoadContext(context);
  if (now < a->fire) {
    OS_AlarmSetTimer(a);
    OSLoadContext(context);
  }
  OSAlarm* succ = a->succ;
  alarmQueue.head = succ;
  if (!succ)
    alarmQueue.tail = NULL;
  else
    succ->pred = NULL;
  OSAlarmHandler handler = a->handler;
  a->handler = NULL;
  if (0 < a->repeat)
    OS_Alarm_InsertAlarm(a, 0, handler);
  if (alarmQueue.head)
    OS_AlarmSetTimer(alarmQueue.head);
  OSDisableScheduler();
  OSContext exceptionCtx;
  OSClearContext(&exceptionCtx);
  OSSetCurrentContext(&exceptionCtx);
  handler(a, context);
  OSClearContext(&exceptionCtx);
  OSSetCurrentContext(context);
  OSEnableScheduler();
  __OSReschedule();
  OSLoadContext(context);
}

// Symbol: OS_Alarm_DecrementerExceptionHandler
// PAL: 0x801a0ca8..0x801a0cf8
asm void OS_Alarm_DecrementerExceptionHandler(u8 exception,
                                              register OSContext* context) {
  nofralloc;
  stw r0, 0(r4);
  stw r1, 4(r4);
  stw r2, 8(r4);
  stmw r6, 0x18(context);
  mfspr r0, 0x391;
  stw r0, 0x1a8(context);
  mfspr r0, 0x392;
  stw r0, 0x1ac(context);
  mfspr r0, 0x393;
  stw r0, 0x1b0(context);
  mfspr r0, 0x394;
  stw r0, 0x1b4(context);
  mfspr r0, 0x395;
  stw r0, 0x1b8(context);
  mfspr r0, 0x396;
  stw r0, 0x1bc(context);
  mfspr r0, 0x397;
  stw r0, 0x1c0(context);
  stwu r1, -8(r1);
  b OS_Alarm_DecrementerExceptionCallback;
}

// Symbol: OSSetAlarmTag
// PAL: 0x801a0cf8..0x801a0d00
void OSSetAlarmTag(OSAlarm* a, u32 tag) { a->tag = tag; }

// Symbol: OS_Alarm_OnReset
// PAL: 0x801a0d00..0x801a0d8c
int OS_Alarm_OnReset(int arg1, u32 arg2) {
  if (arg1) {
    OSAlarm* a;
    OSAlarm* succ;
    for (a = alarmQueue.head, succ = a ? a->succ : NULL; a;
         a = succ, succ = a ? a->succ : NULL) {
      if (!__DVDTestAlarm(a))
        OSCancelAlarm(a);
    }
  }
  return 1;
}

// Symbol: OSSetAlarmUserData
// PAL: 0x801a0d8c..0x801a0d94
void OSSetAlarmUserData(OSAlarm* a, void* data) { a->data = data; }

// Symbol: OSGetAlarmUserData
// PAL: 0x801a0d94..0x801a0d9c
void* OSGetAlarmUserData(OSAlarm* a) { return a->data; }
