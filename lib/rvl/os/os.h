#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OSRoundUp32B(x) (((u32)(x) + 32 - 1) & ~(32 - 1))
#define OSRoundDown32B(x) (((u32)(x)) & ~(32 - 1))

#ifdef __CWCC__
static inline void OSInitFastCast(void) {
  asm {
    li r3, 4
    oris r3, r3, 4
    mtspr 0x392, r3
    li r3, 5
    oris r3, r3, 5
    mtspr 0x393, r3
    li r3, 6
    oris r3, r3, 6
    mtspr 0x394, r3
    li r3, 7
    oris r3, r3, 7
    mtspr 0x395, r3
  }
}
#endif

void OSRegisterVersion(const char* version);

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

#ifdef __cplusplus
}
#endif
