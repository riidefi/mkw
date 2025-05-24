#pragma once

#include <rk_types.h>

#define COL_ENTRY_COUNT 64

namespace Field {
bool findClosestCollisionEntry(u32* typeMask, u32 type);
bool findClosestCollisionEntry(u32* typeMask, u32 type, u16 attribute);
void resetCollisionEntries(u32* typeMask);
void pushCollisionEntry(f32 dist, u32* typeMask, u32 kclAttributeBit, u16 attribute);
void setCurrentColAttributeField(u32* typeMask, u32 value, u16 shift, u16 mask);
void setCurrentColBlightIdx(u32* typeMask, u32 value);
void setCurrentColVariant(u32* typeMask, u32 value);
void setCurrentColWheelDepth(u32* typeMask, u32 value);
void setCurrentColTrickable(u32* typeMask, u32 value);
void setCurrentColRejectRoad(u32* typeMask, u32 value);
void setCurrentColSoftWall(u32* typeMask, u32 value);

inline bool lookupCollisionEntry(u32* typeMask, u32 type) {
  if ((*typeMask & type) != 0) return findClosestCollisionEntry(typeMask, type);
  return false;
}

struct CollisionEntry {
  u32 typeMask;
  u16 attribute;
  f32 dist;
};

extern CollisionEntry collisionEntries[COL_ENTRY_COUNT];
extern s32 collisionEntryCount;
extern CollisionEntry* closestCollisionEntry;
extern u32* typeMaskPtr;
}
