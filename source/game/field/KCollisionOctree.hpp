#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x807bdc5c..0x807bdd7c
UNKNOWN_FUNCTION(kcl_header_init);
// PAL: 0x807bdd7c..0x807bddbc
UNKNOWN_FUNCTION(unk_807bdd7c);
// PAL: 0x807bddbc..0x807bddfc
UNKNOWN_FUNCTION(unk_807bddbc);
// PAL: 0x807bddfc..0x807bdf54
UNKNOWN_FUNCTION(unk_807bddfc);
// PAL: 0x807c01e4..0x807c0884
UNKNOWN_FUNCTION(unk_807c01e4);
// PAL: 0x807c0884..0x807c0f00
UNKNOWN_FUNCTION(kcl_triangle_collides_two_points);
// PAL: 0x807c0f00..0x807c1514
UNKNOWN_FUNCTION(checkSphere__Q25Field16KCollisionOctreeFlll);
// PAL: 0x807c1514..0x807c1b0c
UNKNOWN_FUNCTION(kcl_triangle_collides_one_point);
// PAL: 0x807c1c8c..0x807c1de8
UNKNOWN_FUNCTION(unk_807c1c8c);
// PAL: 0x807c1de8..0x807c1f80
UNKNOWN_FUNCTION(kcl_find_tri_list_and_prepare_cached);
// PAL: 0x807c1f80..0x807c1fac
UNKNOWN_FUNCTION(unk_807c1f80);
// PAL: 0x807c1fac..0x807c21f4
UNKNOWN_FUNCTION(unk_807c1fac);
// PAL: 0x807c21f4..0x807c2410
UNKNOWN_FUNCTION(unk_807c21f4);
// PAL: 0x807c2410..0x807c243c
UNKNOWN_FUNCTION(kcl_triangle_collides);

#ifdef __cplusplus
}
#endif

#include "KCollision.hpp"

namespace Field {
class KCollisionOctree {
public:
  /* Given the KCL representation of a prism, this function can compute the prism vertex
   positions. Vertex1 is already known, and this function computes vertex2 if enrm is enrm2 and
   vertex 3 if enrm is enrm 1 */
  static EGG::Vector3f getVertex(f32 height, const EGG::Vector3f& vertex1, const EGG::Vector3f& fnrm,
		  const EGG::Vector3f& enrm3, const EGG::Vector3f& enrm);
  // finds block that contains position
  u16* searchBlock(const EGG::Vector3f& pos);

  typedef void (KCollisionOctree::*PrismListVisitor) (u16*);
  void searchMultiBlock(const EGG::Vector3f& pos, f32 radius, PrismListVisitor prismListVisitor);

  // Sets sphere-octree-collision detection parameters
  void prepareCollisionTest(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask);
  void prepareCollisionTestSphere(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, f32 radius);

  void narrowScopeLocal(const EGG::Vector3f&, f32 radius, u32 typeMask);

private:
  void searchMultiBlockRecursiveAll(u8* prismArray, u32 index, PrismListVisitor prismListVisitor, s32, s32, s32, s32, s32, s32);
  void searchMultiBlockRecursive(u8* prismArray, u32 index, PrismListVisitor prismListVisitor);
  bool checkSphere(s32, s32, s32);
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
  // index of prisms near pos (collision candidates). They exist in the same octree leaf block as pos
  u16* prismIndexes;

  u32 triangleCount;
  KCollisionPrism* prisms;
  EGG::Vector3f bboxHigh;
  EGG::Vector3f bboxLow;

  u16 prismCache[0x100];
  u16* prismCacheTop;
  u16* cachedPrismIndexes;
  EGG::Vector3f cachedPos;
  f32 cachedRadius;
};
}
