#pragma once

#include <rk_types.h>
#include <rvl/nand/nand.h>
#include <rvl/os/os.h>
#include <rvl/os/osThread.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

int NandUtil_safeOpen(const char* a1, NANDFileInfo* a2, u8 a3, void* a4,
                      u32 a5);
int NandUtil_open(const char* a1, NANDFileInfo* a2, u8 a3);
int NandUtil_safeClose(NANDFileInfo* a1);
int NandUtil_close(NANDFileInfo* a1);
int NandUtil_getLength(NANDFileInfo* a1, u32* a2);
int NandUtil_createDir(const char* a1, u8 a2);
int NandUtil_create(const char* a1, u8 a2);
int NandUtil_delete(const char* a1);
int NandUtil_setStatus(const char* a1, const NANDStatus* a2);
int NandUtil_getStatus(const char* a1, NANDStatus* a2);
void unk_8052bd38(void* first);

#ifdef __cplusplus
}
#endif
