#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "KCollision.hpp"

namespace Field {
class RKGndCol {
public:
  RKGndCol(const KCollisionHeader& header);
  ~RKGndCol();
  void computeBbox();
  /* Given the KCL representation of a prism, this function can compute the prism vertex
   positions. Vertex1 is already known, and this function computes vertex2 if enrm is enrm2 and
   vertex 3 if enrm is enrm 1 */
  static EGG::Vector3f getVertex(f32 height, const EGG::Vector3f& vertex1, const EGG::Vector3f& fnrm,
		  const EGG::Vector3f& enrm3, const EGG::Vector3f& enrm) __attribute__((never_inline));
  // finds block that contains position
  u16* searchBlock(const EGG::Vector3f& pos);

  typedef void (RKGndCol::*PrismListVisitor) (u16*);
  void searchMultiBlock(const EGG::Vector3f& pos, f32 radius, PrismListVisitor prismListVisitor);

  // Perform lookup and set sphere-octree-collision detection parameters
  void lookupPoint(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask);
  void lookupSphere(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, f32 radius);
  void lookupPointCached(const EGG::Vector3f& p1, const EGG::Vector3f& p2, u32 typeMask);
  void lookupSphereCached(const EGG::Vector3f& p1, const EGG::Vector3f& p2, u32 typeMask, f32 radius);

  // Perform prism-sphere/point collision check on looked up prisms
  bool checkPointCollision(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
  bool checkSphereCollision(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);

  void narrowScopeLocal(const EGG::Vector3f&, f32 radius, u32 typeMask, u32 unused);

  f32 getPrismThickness() const { return this->prism_thickness; }
  u16 getPrismCache(u32 i) const { return this->prismCache[i]; }
  bool cacheEmpty() const { return this->prismCache[0] == 0; }
  const EGG::Vector3f& getBboxLow() const { return this->bboxLow; }
  const EGG::Vector3f& getBboxHigh() const { return this->bboxHigh; }

private:
  inline bool prismCacheNotEmpty() const { return prismCache != prismCacheTop; }
  void searchMultiBlockRecursiveAll(u8* prismArray, u32 index, PrismListVisitor prismListVisitor, s32, s32, s32, s32, s32, s32);
  void searchMultiBlockRecursive(u8* prismArray, u32 index, PrismListVisitor prismListVisitor);
  bool checkSphereSingle(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
  bool checkSphere(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
  bool checkSphereMovement(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
  bool checkPointMovement(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
  bool checkPoint(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut);
  void narrowPolygon_EachBlock(u16* prismArray);

  EGG::Vector3f* pos_data;
  EGG::Vector3f* nrm_data;
  KCollisionPrism* prism_data;
  u8* block_data;
  f32 prism_thickness;
  EGG::Vector3f area_min_pos;
  u32 area_x_width_mask;
  u32 area_y_width_mask;
  u32 area_z_width_mask;
  u32 block_width_shift;
  u32 area_x_blocks_shift;
  u32 area_xy_blocks_shift;
  f32 sphere_radius;

  // --- Sphere-octree collision detection parameters
  EGG::Vector3f pos;
  // I think this is for support of directional collision checking (wall is only one way solid)
  // Pretty much a collision is triggered only when the movement vector has an acute angle with the prism face normal
  EGG::Vector3f prevPos;
  EGG::Vector3f movement; // pos - prevPos
  f32 radius;
  // This mask can be used to only count collision with certain KCL attribute base types. The n-th bit in this mask signifies if KCL of base type n will count towards collision
  u32 typeMask;
  // Iterator for the array of prisms to be checked by e.g. checkSphere. It gets set after searchBlock/searchMultiBlock lookup
  u16* prismArrayIt;

  s32 prismCount;
  KCollisionPrism* prisms;
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;

  // prismCache is the list of prisms that are verified that are colliding by e.g. checkSphere (so not really a cache tbh)
  u16 prismCache[0x100];
  // Pointer to the end of prismCache
  u16* prismCacheTop;
  // Cached lookup result (prismArrayIt)
  u16* cachedPrismArrayIt;
  // Cached query parameters (used in checks if cache should be used)
  EGG::Vector3f cachedPos;
  f32 cachedRadius;
};
}
