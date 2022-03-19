#pragma once

#include <game/geo/BoxColUnit.hpp>
#include <egg/core/eggDisposer.hpp>

struct BoxColRightPoint {
  /*
  MKDS:
    u8 leftEndpoint; // left endpoint idx of this segment
    u8 minLeftEndpoint; // from all segments overlapping this x, the left most
                        // left-endpoint idx s16 xPos;
    s16 xPos;
  */
  f32 xPos;
  u8 leftPoint;
  u8 minLeftPoint;
};

struct BoxColLeftPoint {
  /*
  MKDS:
    u8 rightEndpoint; // right endpoint idx of this segment
    u8 colEntryId; // col entry corresponding to this segment
    s16 xPos;
  */
  f32 xPos;
  u8 rightPoint;
  u8 unitID;
};

class BoxColManager : public EGG::Disposer {
public:
  bool isSomeSphereExist(const EGG::Vector3f& pos, u32 flag,
                         float radius) const;

private:
  BoxColRightPoint* mRightPoints;
  BoxColLeftPoint* mLeftPoints;
  BoxColUnit* mpUnitPool;
  BoxColUnit** mppUnits;
  s32 mUnitIDs[256];
  u32 mNumUnits;
  u32 mNextUnitID;
  u32 mNextPlayerID;
  u32 mNextItemID;
  u32 mNextObjectID;
  u32 mNextDrivableID;
  u32 mMaxID;
  u32 _0x43c;
  f32 someX;
  u32 UNK_444;
  f32 someZ;
  f32 someDist;
  u32 someFlag;
};
