#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSModuleInfo OSModuleInfo;

typedef struct OSModuleLink {
  OSModuleInfo* succ;
  OSModuleInfo* pred;
} OSModuleLink;

typedef struct OSModuleQueue {
  OSModuleInfo* head;
  OSModuleInfo* tail;
} OSModuleQueue;

struct OSModuleInfo {
  u32 id;
  OSModuleLink head;
  u32 sections;
  u32 sectionInfoOffset;
  u32 nameOffset;
  u32 nameLen;
  u32 version;
};

typedef struct OSModuleHeader {
  OSModuleInfo info;
  u32 bssSize;
  u32 relOffset;
  u32 impOffset;
  u32 impSize;
  u8 prologSection;
  u8 epilogSection;
  u8 unresolvedSection;
  u8 bssSection;
  u32 prolog;
  u32 epilog;
  u32 unresolved;
  u32 align;
  u32 bssAlign;
  u32 fixSize;
} OSModuleHeader;

void OSNotifyLink(OSModuleInfo*);
void OSNotifyPreLink(OSModuleInfo*);
void OSNotifyPostLink(OSModuleHeader*, OSModuleHeader*);
int Relocate(OSModuleHeader*, OSModuleHeader*);
int Link(OSModuleInfo* info, void* bss, int fixed);
int OSLink(OSModuleInfo* info, void* bss);
void __OSModuleInit(void);

#ifdef __cplusplus
}
#endif
