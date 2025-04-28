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

void OSInitMessageQueue(OSMessageQueue* mq, OSMessage* msgArray, s32 msgCount);
int OSSendMessage(OSMessageQueue* mq, OSMessage msg, s32 flags);
int OSReceiveMessage(OSMessageQueue* mq, OSMessage* msg, s32 flags);

#ifdef __cplusplus
}
#endif
