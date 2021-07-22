#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*NANDCallback)(s32);

typedef struct NANDFileInfo {
  s32 fd;
} NANDFileInfo;

typedef struct NANDStatus {
  u32 uid;
  u16 gid;
  u8 attr;
  u8 perm;
} NANDStatus;

typedef struct NANDCommandBlock {
  void* userData;
} NANDCommandBlock;

typedef struct {
  u32 magic;          // 0x0000
  u32 flag;           // 0x0004
  u16 animSpeed;      // 0x0008
  u8 _unk_0a[22];     // 0x000A
  u16 comment[2][32]; // 0x0020
  u8 banner[24576];   // 0x00a0
  u8 icon[8][4608];   // 0x60a0
} NANDBanner;

s32 NANDInit(void);

s32 NANDCreate(const char*, u8, u8);
s32 NANDCreateDir(const char*, u8, u8);

s32 NANDDelete(const char*);

s32 NANDOpen(const char*, NANDFileInfo*, u8);
s32 NANDOpenAsync(const char*, NANDFileInfo*, u8, NANDCallback,
                  NANDCommandBlock*);

s32 NANDSafeOpen(const char*, NANDFileInfo*, u8, void*, u32);
s32 NANDSafeClose(NANDFileInfo*);
s32 NANDSafeCloseAsync(NANDFileInfo*, NANDCallback, NANDCommandBlock*);

s32 NANDClose(NANDFileInfo*);
s32 NANDCloseAsync(NANDFileInfo*, NANDCallback, NANDCommandBlock*);

s32 NANDRead(NANDFileInfo*, void*, u32);
s32 NANDReadAsync(NANDFileInfo*, void*, u32, NANDCallback);

s32 NANDWrite(NANDFileInfo*, const void*, u32);
s32 NANDWriteAsync(NANDFileInfo*, const void*, u32, NANDCallback);

s32 NANDSeek(NANDFileInfo*, s32, s32);
s32 NANDSeekAsync(NANDFileInfo*, s32, s32, NANDCallback);

s32 NANDMove(const char*, const char*);

s32 NANDGetLength(NANDFileInfo*, u32*);
s32 NANDGetLengthAsync(NANDFileInfo*, u32*, NANDCallback, NANDCommandBlock*);

s32 NANDGetStatus(const char*, NANDStatus*);
s32 NANDSetStatus(const char*, const NANDStatus*);

s32 NANDGetType(const char*, u8*);

void NANDSetUserData(NANDCommandBlock*, void*);
void* NANDGetUserData(const NANDCommandBlock*);

s32 NANDGetCurrentDir(char[64]);
s32 NANDGetHomeDir(char[64]);

void NANDInitBanner(NANDBanner*, u32, const u16*, const u16*);

s32 NANDCheck(u32, u32, u32*);

#ifdef __cplusplus
}
#endif
