#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* OSMessage;

typedef struct OSMessageQueue {
  char _[0x20];
} OSMessageQueue;

#define OS_MESSAGE_NOBLOCK 0
#define OS_MESSAGE_BLOCK 1

// PAL: 0x801a72fc..0x801a735c
void OSInitMessageQueue(OSMessageQueue* mq, OSMessage* msgArray, s32 msgCount);
// PAL: 0x801a735c..0x801a7424
int OSSendMessage(OSMessageQueue* mq, OSMessage msg, s32 flags);
// PAL: 0x801a7424..0x801a7500
int OSReceiveMessage(OSMessageQueue* mq, OSMessage* msg, s32 flags);
// PAL: 0x801a7500..0x801a75d0
UNKNOWN_FUNCTION(OSJamMessage);

#ifdef __cplusplus
}
#endif
