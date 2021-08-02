#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OSRoundUp32B(x) (((u32)(x) + 32 - 1) & ~(32 - 1))
#define OSRoundDown32B(x) (((u32)(x)) & ~(32 - 1))

typedef s64 OSTime;
typedef u32 OSTick;

typedef struct OSCalendarTime {
  int sec;
  int min;
  int hour;
  int mday;
  int mon;
  int year;
  int wday;
  int yday;

  int msec;
  int usec;
} OSCalendarTime;

#define OSTicksToSeconds(ticks) ((ticks) / OS_TIMER_CLOCK)
#define OSTicksToMilliseconds(ticks) ((ticks) / (OS_TIMER_CLOCK / 1000))

OSTick OSGetTick(void);
OSTime OSGetTime(void);

OSTime OSCalendarTimeToTicks(OSCalendarTime* td);
void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime* td);

void OSPanic(char* file, int line, char* msg, ...);

#ifdef __cplusplus
}
#endif
