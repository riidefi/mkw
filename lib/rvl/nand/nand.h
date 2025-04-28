#pragma once

#include <rk_types.h>
#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

struct NANDCommandBlock;
struct NANDCB_UNK;

typedef void (*NANDCallback)(s32);
typedef void (*NANDAsyncCallback)(s32, struct NANDCommandBlock*);
typedef void (*NANDCBAsyncCallback)(s32, struct NANDCB_UNK*, u32);

typedef struct NANDFileInfo {
  s32 fd;
  u32 WORD_0x4;

  volatile char BUF_0x8[0x40];

  volatile char BUF_0x48[0x40];

  char BYTE_0x88;
  char BYTE_0x89;
  char BYTE_0x8a;
} NANDFileInfo;

struct NANDCB_UNK {
  char UNK_0x0[0x8];
  u32 WORD_0x8;
  NANDCBAsyncCallback CALLBACK_0xC;
  u32 WORD_0x10;
  char UNK_0x14[0x156];
  char BYTE_0x16A;
};

typedef struct NANDStatus {
  u32 uid;
  u16 gid;
  u8 attr;
  u8 perm;
} NANDStatus;

typedef struct NANDCommandBlock {
  void* userData;
  char _unk04[0x144];
  struct NANDCB_UNK* PTR_0x144;
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
s32 NANDReadAsync(NANDFileInfo*, void*, u32, NANDAsyncCallback, void*);

s32 NANDWrite(NANDFileInfo*, const void*, u32);
s32 NANDWriteAsync(NANDFileInfo*, const void*, u32, NANDAsyncCallback, void*);

s32 NANDSeek(NANDFileInfo*, u32, s32);
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

u32 nandGetHomeDir();

#ifdef __cplusplus
}
#endif
