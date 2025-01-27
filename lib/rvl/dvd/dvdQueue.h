#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x801635bc..0x801635c0
UNKNOWN_FUNCTION(__DVDRestartMotor);
// PAL: 0x801635c0..0x801635f8
UNKNOWN_FUNCTION(__DVDClearWaitingQueue);
// PAL: 0x801635f8..0x80163660
UNKNOWN_FUNCTION(__DVDPushWaitingQueue);
// PAL: 0x80163660..0x80163700
UNKNOWN_FUNCTION(__DVDPopWaitingQueue);
// PAL: 0x80163700..0x80163758
UNKNOWN_FUNCTION(__DVDCheckWaitingQueue);
// PAL: 0x80163758..0x801637b8
UNKNOWN_FUNCTION(__DVDGetNextWaitingQueue);
// PAL: 0x801637b8..0x80163818
UNKNOWN_FUNCTION(__DVDDequeueWaitingQueue);

#ifdef __cplusplus
}
#endif
