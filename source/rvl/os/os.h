#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif


#define OSRoundUp32B(x)       (((u32)(x) + 32 - 1) & ~(32 - 1))
#define OSRoundDown32B(x)     (((u32)(x)) & ~(32 - 1))

typedef s64 OSTime;
typedef u32 OSTick;

typedef struct OSCalendarTime
{
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

#define OSTicksToCycles( ticks )        (((ticks) * ((OS_CORE_CLOCK * 2) / OS_TIMER_CLOCK)) / 2)
#define OSTicksToSeconds( ticks )       ((ticks) / OS_TIMER_CLOCK)
#define OSTicksToMilliseconds( ticks )  ((ticks) / (OS_TIMER_CLOCK / 1000))
#define OSTicksToMicroseconds( ticks )  (((ticks) * 8) / (OS_TIMER_CLOCK / 125000))
#define OSTicksToNanoseconds( ticks )   (((ticks) * 8000) / (OS_TIMER_CLOCK / 125000))
#define OSSecondsToTicks( sec )         ((sec)  * OS_TIMER_CLOCK)
#define OSMillisecondsToTicks( msec )   ((msec) * (OS_TIMER_CLOCK / 1000))
#define OSMicrosecondsToTicks( usec )   (((usec) * (OS_TIMER_CLOCK / 125000)) / 8)
#define OSNanosecondsToTicks( nsec )    (((nsec) * (OS_TIMER_CLOCK / 125000)) / 8000)

OSTick  OSGetTick( void );
OSTime  OSGetTime( void );

OSTime OSCalendarTimeToTicks( OSCalendarTime* td );
void   OSTicksToCalendarTime( OSTime ticks, OSCalendarTime* td );

int    OSDisableInterrupts ( void );
int    OSEnableInterrupts  ( void );
int    OSRestoreInterrupts ( int level );


#ifdef __cplusplus
}
#endif
