#pragma once

#include <geo/BoxColUnit.hpp>
#include <geo/ObjDrivable.hpp>
#include <egg/core/eggDisposer.hpp>

extern "C" const float flt_808A47EC;
// extern const float flt_808A47EC;

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

/**
 * An efficient container data structure for quick spatial accessing of game objects and collision checking.
 *
 * Internally it is a 1D quadtree. Each object in this structure is called a "box unit" and is characterized
 * by its center position and halfwidth. Every collidable object in the game has its bounding box computed so
 * that it can be quickly checked for collision with other units, without proceding to more expensive operations
 * (such as octree collision checking in the case of courses/KCL objects).
 * The quadtree partitions the space based on the object's Z coordinate and width into 4 quadrants
 * (hence quadtree). The object's "left point" is point.z-radius and its 
 * right point point.z+radius. For each node, the 4 children's left and right points have a specific behavior 
 * when compared to their parent's (< and <, < and >, > and <, > and >). Hence when checking for a collision of
 * a box, we can iterate the quadtree so that we avoid iterating box units that have right point > the queried
 * box's left point and left point < the queried box's right point.
 *
 * Additionally it contains iterators for iterating different types of box units
 */
class BoxColManager : public EGG::Disposer {
public:
  static BoxColManager* spInstance;

  bool isSphereInSpatialCache(const EGG::Vector3f& pos, float radius, u32 flag) const;
  void initIterators(const EGG::Vector3f& pos, f32 radius, u32 boxColFlag);
  void resetIterators();
  GeoObj::ObjDrivable* nextDrivable();

private:
  // right point of each box unit in the pool
  BoxColRightPoint* mRightPoints;
  // left point of each box unit in the pool
  BoxColLeftPoint* mLeftPoints;
  // flat array of all units
  BoxColUnit* mpUnitPool;
  // pointer array of colliding units after a bounding box search query
  BoxColUnit** mppUnits;
  s32 mUnitIDs[256];
  // total number of units
  u32 mNumUnits;
  // iterators used when iterating 
  u32 mNextUnitID;
  u32 mNextPlayerID;
  u32 mNextItemID;
  u32 mNextObjectID;
  u32 mNextDrivableID;
  // number of results of the last box query
  u32 mMaxID;
  u32 _0x43c;
  f32 someX;
  u32 UNK_444;
  f32 someZ;
  f32 someDist;
  u32 someFlag;
};
