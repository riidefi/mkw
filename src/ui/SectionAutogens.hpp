#pragma once

#include <decomp.h>

#include <rk_types.h>
#include <host_system/RKScene.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8062c3a4..0x80630094
void Section_addPages(void* pSection, int sectionId);
// PAL: 0x80630094..0x80631588
void Section_addActivePages(void* pSection, int sectionId);
// PAL: 0x80631588..0x80631734
RKSceneID Section_getSceneId(s32);
// PAL: 0x80631734..0x80631a58
UNKNOWN_FUNCTION(Section_getResourceName);
// PAL: 0x80631a58..0x80631af8
UNKNOWN_FUNCTION(Section_hasBackModel);
// PAL: 0x80631af8..0x80631bf0
UNKNOWN_FUNCTION(SectionId_hasDriver);
// PAL: 0x80631bf0..0x80631c00
UNKNOWN_FUNCTION(SectionManager_getPageName);
// PAL: 0x80631c00..0x80631c10
UNKNOWN_FUNCTION(SectionManager_getSectionName);
// PAL: 0x80631c10..0x80631c68
UNKNOWN_FUNCTION(unk_80631c10);
// PAL: 0x80631c68..0x80631ef8
UNKNOWN_FUNCTION(unk_80631c68);
// PAL: 0x80632080..0x806321b4
UNKNOWN_FUNCTION(unk_80632080);
// PAL: 0x806321b4..0x8063240c
s32 Section_getSoundTrigger(s32);

#ifdef __cplusplus
}
#endif
