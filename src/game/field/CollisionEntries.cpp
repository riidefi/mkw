#include "CollisionEntries.hpp"
#include "KCollision.hpp"

#include <float.h>

extern "C" const u32 _unused2;
const u32 _unused2 = 0;

namespace Field {
CollisionEntry collisionEntries[64];
s32 collisionEntryCount;
CollisionEntry* closestCollisionEntry;
u32* typeMaskPtr;

bool findClosestCollisionEntry(u32* typeMask, u32 type) {
  CollisionEntry* entryIt ;
  CollisionEntry* closest;
  closest = closestCollisionEntry = nullptr;
  f32 minDist = -FLT_MIN;
  entryIt = collisionEntries;
    
  for (s32 i = 0; i < collisionEntryCount;  i++) {
    u32 typeMask = entryIt[i].typeMask;
    typeMask &= type;
    if (typeMask != 0) {
      bool candidate;
      if (entryIt[i].dist > minDist) {
        minDist = entryIt[i].dist;
        candidate = true;
      } else {
        candidate = false;
      }
      if (candidate) {
        closest = &entryIt[i];
        closestCollisionEntry = &entryIt[i];
      }
    }
  }

  return closestCollisionEntry != nullptr;
}

bool findClosestCollisionEntry(u32* typeMask, u32 type, u32 attribute) {
  CollisionEntry* closest = nullptr;
  closestCollisionEntry = nullptr;
  f32 minDist = -FLT_MIN;

  for (s32 i = 0; i < collisionEntryCount; i++) {
    CollisionEntry* entryIt = &collisionEntries[i];
    if ((entryIt->typeMask & type) != 0) {
      if ((attribute & KCL_ATTRIBUTE_TYPE_BIT(entryIt->attribute)) != 0) {
        bool candidate;
        if (entryIt->dist > minDist) {
          minDist = entryIt->dist;
          candidate = true;
        } else {
          candidate = false;
        }
        if (candidate) {
          closest = entryIt;
          closestCollisionEntry = entryIt;
        }
      }
    }
  }

  return closestCollisionEntry != nullptr;
}

void resetCollisionEntries(u32* typeMask) {
  *typeMask = 0;
  collisionEntryCount = 0;
  closestCollisionEntry = nullptr;
  typeMaskPtr = typeMask;
}

void pushCollisionEntry(f32 dist, u32* typeMask, u32 kclTypeBit, u16 attribute) {
  *typeMask |= kclTypeBit;
  if (collisionEntryCount >= COL_ENTRY_COUNT) {
    collisionEntryCount = COL_ENTRY_COUNT - 1;
  }
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount];
  colEntry.typeMask = kclTypeBit;
  colEntry.attribute = attribute;
  colEntry.dist = dist;
  collisionEntryCount++;
}

// if it matches, it matches
void setCurrentColAttributeField(u32* typeMask, u32 value, u16 shift, u16 mask) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(colEntry.attribute & ~mask) | (u16)(((u16)value) << (shift));
}

void setCurrentColBlightIdx(u32* typeMask, u32 value) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(colEntry.attribute & ~0x700) | (u16)(((u16)value) << 8);
}

void setCurrentColVariant(u32* typeMask, u32 value) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(colEntry.attribute & ~0xe0) | (u16)(((u16)value) << 5);
}

void setCurrentColWheelDepth(u32* typeMask, u32 value) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(colEntry.attribute & ~0x1800) | (u16)(((u16)value) << 0xb);
}

void setCurrentColTrickable(u32* typeMask, u32 value) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(colEntry.attribute & ~0x2000) | (u16)(((u16)value) << 0xd);
}

void setCurrentColRejectRoad(u32* typeMask, u32 value) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(colEntry.attribute & ~0x4000) | (u16)(((u16)value) << 0xe);
}

void setCurrentColSoftWall(u32* typeMask, u32 value) {
  CollisionEntry& colEntry = collisionEntries[collisionEntryCount - 1];
  colEntry.attribute = (u16)(((u16)value) << 0xf) | (u16)(colEntry.attribute & ~0x8000);
}
}
