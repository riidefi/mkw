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

// PAL: 0x801a6d30..0x801a6d34
void OSNotifyLink(OSModuleInfo*);
// PAL: 0x801a6d34..0x801a6d38
void OSNotifyPreLink(OSModuleInfo*);
// PAL: 0x801a6d38..0x801a6d3c
void OSNotifyPostLink(OSModuleHeader*, OSModuleHeader*);
// PAL: 0x801a6d3c..0x801a6ffc
int Relocate(OSModuleHeader*, OSModuleHeader*);
// PAL: 0x801a6ffc..0x801a72dc
int Link(OSModuleInfo* info, void* bss, int fixed);
// PAL: 0x801a72dc..0x801a72e4
int OSLink(OSModuleInfo* info, void* bss);
// PAL: 0x801a72e4..0x801a72fc
void __OSModuleInit(void);

#ifdef __cplusplus
}
#endif
