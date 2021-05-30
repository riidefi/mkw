#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#ifndef RII_CLIENT
struct OSThread {
  char _00[0x304];
  char* stack_high; // 304
  char* stack_low;  // 308
  char _30c[0x318 - 0x30c];
};

typedef void* OSMessage;

struct OSMessageQueue {
  char _[0x20];
};

typedef struct {
  char _[0x18];
} OSMutex;

void OSInitMutex(OSMutex*);
void OSLockMutex(OSMutex*);
void OSUnlockMutex(OSMutex*);

int OSCreateThread(OSThread* thread, void* (*callable)(void*), void* user_data,
                   void* stack, u32 stack_size, s32 prio, u16 flag);

void OSCancelThread(OSThread* thread);
void OSDetachThread(OSThread* thread);
int OSIsThreadTerminated(OSThread* thread);
OSThread* OSGetCurrentThread();

typedef void (*OSSwitchFunction)(OSThread*, OSThread*);
OSSwitchFunction OSSetSwitchThreadCallback(OSSwitchFunction callable);

void OSInitMessageQueue(OSMessageQueue* queue, OSMessage* buffer, s32 capacity);

#endif
#ifdef __cplusplus
}
#endif