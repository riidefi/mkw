#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GXDrawDoneCallback)(void);

void GXSetMisc(u32 token, u32 val);
void GXFlush(void);
void GXResetWriteGatherPipe(void);

void GXAbortFrame(void);

void GXDrawDone(void);
void GXPixModeSync(void);

GXDrawDoneCallback GXSetDrawDoneCallback(GXDrawDoneCallback);
void GXSetDrawDone();

#ifdef __cplusplus
}
#endif
