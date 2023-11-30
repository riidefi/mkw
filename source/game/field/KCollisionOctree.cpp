#include "KCollisionOctree.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80021450
extern UNKNOWN_FUNCTION(__ptmf_scall);
// PAL: 0x8002156c
extern UNKNOWN_FUNCTION(_savegpr_14);
// PAL: 0x80021578
extern UNKNOWN_FUNCTION(_savegpr_17);
// PAL: 0x8002157c
extern UNKNOWN_FUNCTION(_savegpr_18);
// PAL: 0x80021584
extern UNKNOWN_FUNCTION(_savegpr_20);
// PAL: 0x8002158c
extern UNKNOWN_FUNCTION(_savegpr_22);
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215b8
extern UNKNOWN_FUNCTION(_restgpr_14);
// PAL: 0x800215c4
extern UNKNOWN_FUNCTION(_restgpr_17);
// PAL: 0x800215c8
extern UNKNOWN_FUNCTION(_restgpr_18);
// PAL: 0x800215d0
extern UNKNOWN_FUNCTION(_restgpr_20);
// PAL: 0x800215d8
extern UNKNOWN_FUNCTION(_restgpr_22);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80026050
extern UNKNOWN_FUNCTION(VWarning);
// PAL: 0x80085040
extern UNKNOWN_FUNCTION(FrSqrt);
// PAL: 0x80085580
extern UNKNOWN_FUNCTION(VEC3Maximize);
// PAL: 0x800855c0
extern UNKNOWN_FUNCTION(VEC3Minimize);
// PAL: 0x8051a07c
extern UNKNOWN_FUNCTION(kcl_can_reuse_last_tri_list);
// PAL: 0x807bddfc
extern UNKNOWN_FUNCTION(unk_807bddfc);
// PAL: 0x807bdf54
extern UNKNOWN_FUNCTION(getVertex__Q25Field16KCollisionOctreeFfRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f);
// PAL: 0x807be030
extern UNKNOWN_FUNCTION(searchBlock__Q25Field16KCollisionOctreeFRCQ23EGG8Vector3f);
// PAL: 0x807be3c4
extern UNKNOWN_FUNCTION(applyFunctionForPrismsInBlock__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_vllllll);
// PAL: 0x807bf4c0
extern UNKNOWN_FUNCTION(applyFunctionForPrismsRecurse__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_v);
// PAL: 0x807c0884
extern UNKNOWN_FUNCTION(kcl_triangle_collides_two_points);
// PAL: 0x807c0f00
extern UNKNOWN_FUNCTION(checkSphere__Q25Field16KCollisionOctreeFlll);
// PAL: 0x807c1514
extern UNKNOWN_FUNCTION(kcl_triangle_collides_one_point);
// PAL: 0x807c1fac
extern UNKNOWN_FUNCTION(unk_807c1fac);
// PAL: 0x807c21f4
extern UNKNOWN_FUNCTION(unk_807c21f4);// Extern data references.
// PAL: 0x808b56d0
extern UNKNOWN_DATA(lbl_808b56d0);
// PAL: 0x808b56f4
extern UNKNOWN_DATA(lbl_808b56f4);
// PAL: 0x808d27f8
extern UNKNOWN_DATA(lbl_808d27f8);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
const u32 lbl_808a66d8[] = {
    0x00000000
};
const u32 lbl_808a66dc[] = {
    0x497423f0
};
const u32 lbl_808a66e0[] = {
    0xc97423f0
};
const u32 lbl_808a66e4[] = {
    0x3f800000
};
const u32 lbl_808a66e8[] = {
    0x3c23d70a
};
const u32 lbl_808a66ec[] = {
    0x7f800000, 0x3ca3d70a, 0x00000000, 0x00000000
};

// .data


// .bss


// Symbol: kcl_header_init
// PAL: 0x807bdc5c..0x807bdd7c
MARK_BINARY_BLOB(kcl_header_init, 0x807bdc5c, 0x807bdd7c);
asm UNKNOWN_FUNCTION(kcl_header_init) {
  #include "asm/807bdc5c.s"
}

// Symbol: unk_807bdd7c
// PAL: 0x807bdd7c..0x807bddbc
MARK_BINARY_BLOB(unk_807bdd7c, 0x807bdd7c, 0x807bddbc);
asm UNKNOWN_FUNCTION(unk_807bdd7c) {
  #include "asm/807bdd7c.s"
}

// Symbol: unk_807bddbc
// PAL: 0x807bddbc..0x807bddfc
MARK_BINARY_BLOB(unk_807bddbc, 0x807bddbc, 0x807bddfc);
asm UNKNOWN_FUNCTION(unk_807bddbc) {
  #include "asm/807bddbc.s"
}

// Symbol: unk_807bddfc
// PAL: 0x807bddfc..0x807bdf54
MARK_BINARY_BLOB(unk_807bddfc, 0x807bddfc, 0x807bdf54);
asm UNKNOWN_FUNCTION(unk_807bddfc) {
  #include "asm/807bddfc.s"
}

#ifndef EQUIVALENT
// Symbol: getVertex__Q25Field16KCollisionOctreeFfRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f
// PAL: 0x807bdf54..0x807be030
MARK_BINARY_BLOB(getVertex__Q25Field16KCollisionOctreeFfRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f, 0x807bdf54, 0x807be030);
asm UNKNOWN_FUNCTION(getVertex__Q25Field16KCollisionOctreeFfRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3fRCQ23EGG8Vector3f) {
  #include "asm/807bdf54.s"
}
#else
// https://decomp.me/scratch/byfkO
namespace Field {
EGG::Vector3f KCollisionOctree::getVertex(f32 height, const EGG::Vector3f& vertex1, const EGG::Vector3f& fnrm,
    	const EGG::Vector3f& enrm3, const EGG::Vector3f& enrm) {
  EGG::Vector3f cross;

  VECCrossProduct(fnrm, enrm, cross);

  f32 dp = VEC3Dot(&cross, &enrm3);
  cross *= (height / dp);

  return cross += vertex1;
}
}
#endif

namespace Field {
u16* KCollisionOctree::searchBlock(const EGG::Vector3f& point) {
  // Calculate the x, y, and z offsets of the point from the minimum
  // corner of the tree's bounding box.
  const int x = point.x - this->area_min_pos.x;

  // Check if the point is outside the tree's bounding box in the x, y,
  // or z dimensions. If it is, return 0.
  if ((x & this->area_x_width_mask) != 0) {
    return 0;
  }

  const int y = point.y - this->area_min_pos.y;
  if ((y & this->area_y_width_mask) != 0) {
    return 0;
  }

  const int z = point.z - this->area_min_pos.z;
  if ((z & this->area_z_width_mask) != 0)
  {
    return 0;
  }

  // Initialize the current tree node to the root node of the tree.
  u32 shift = this->block_width_shift;
  u8* curBlock = this->block_data;
  s32 offset;

  // Traverse the tree to find the leaf node containing the input point.
  u32 index = 4 * (((u32)z >> shift) << this->area_xy_blocks_shift
        | ((u32)y >> shift) << this->area_x_blocks_shift
        | (u32)x >> shift);

  while (true) {
    // Get the offset of the current node's child node.
    offset = *(u32*)(curBlock + index);

    // If the offset is negative, the current node is a leaf node.
    if ((offset & 0x80000000) != 0) {
      break;
    }

    // If the offset is non-negative, update the current node to be
    // the child node and continue traversing the tree.
    shift--;
    curBlock += offset;

    index = 4 * ((4 * ((u32)z >> shift)) & 4
        | (2 * ((u32)y >> shift)) & 2
        | (1 * ((u32)x >> shift)) & 1);
  }

  // Return the address of the leaf node containing the input point.
  return reinterpret_cast<u16*>(curBlock + (offset & 0x7FFFFFFF));
}

void KCollisionOctree::searchMultiBlock(const EGG::Vector3f& point, f32 radius, PrismListVisitor prismListVisitor) {
  s32 xmin = ((point.x - radius) - this->area_min_pos.x);
  s32 ymin = ((point.y - radius) - this->area_min_pos.y);
  s32 zmin = ((point.z - radius) - this->area_min_pos.z);

  if (xmin < 0) {
    xmin = 0;
  }
  if (ymin < 0) {
    ymin = 0;
  }
  if (zmin < 0) {
    zmin = 0;
  }

  s32 xmax = ((point.x + radius) - this->area_min_pos.x);
  s32 ymax = ((point.y + radius) - this->area_min_pos.y);
  s32 zmax = ((point.z + radius) - this->area_min_pos.z);

  if (xmax > (s32)~this->area_x_width_mask) {
    xmax = ~this->area_x_width_mask;
  }
  if (ymax > (s32)~this->area_y_width_mask) {
    ymax = ~this->area_y_width_mask;
  }
  if (zmax > (s32)~this->area_z_width_mask) {
    zmax = ~this->area_z_width_mask;
  }

  if (xmin >= xmax || ymin >= ymax || zmin >= zmax) {
    return;
  }

  u8* blockData = this->block_data;
  u32 xminBlock = (u32)xmin >> this->block_width_shift;
  u32 xmaxBlock = (u32)xmax >> this->block_width_shift;
  u32 yminBlock = (u32)ymin >> this->block_width_shift;
  u32 ymaxBlock = (u32)ymax >> this->block_width_shift;
  u32 zminBlock = (u32)zmin >> this->block_width_shift;
  u32 zmaxBlock = (u32)zmax >> this->block_width_shift;

  xmin = xmin << (0x1f - this->block_width_shift);
  ymin = ymin << (0x1f - this->block_width_shift);
  zmin = zmin << (0x1f - this->block_width_shift);
  xmax = xmax << (0x1f - this->block_width_shift);
  ymax = ymax << (0x1f - this->block_width_shift);
  zmax = zmax << (0x1f - this->block_width_shift);

  for (s32 x = xminBlock; x <= xmaxBlock; x++) {
    for (s32 y = yminBlock; y <= ymaxBlock; y++) {
      for (s32 z = zminBlock; z <= zmaxBlock; z++) {

        u32 index = 4 * (z << this->area_xy_blocks_shift
              | y << this->area_x_blocks_shift
              | x);

        this->applyFunctionForPrismsInBlock(blockData, index, prismListVisitor,
            x == xminBlock ? xmin : 0, y == yminBlock ? ymin : 0, z == zminBlock ? zmin : 0,
            x == xmaxBlock ? xmax : -1, y == ymaxBlock ? ymax : -1, z == zmaxBlock ? zmax : -1);
      }
    }
  }
}
}

// Symbol: applyFunctionForPrismsInBlock__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_vllllll
// PAL: 0x807be3c4..0x807bf4c0
MARK_BINARY_BLOB(applyFunctionForPrismsInBlock__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_vllllll, 0x807be3c4, 0x807bf4c0);
asm UNKNOWN_FUNCTION(applyFunctionForPrismsInBlock__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_vllllll) {
  #include "asm/807be3c4.s"
}

#ifndef EQUIVALENT
// Symbol: applyFunctionForPrismsRecurse__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_v
// PAL: 0x807bf4c0..0x807c01e4
MARK_BINARY_BLOB(applyFunctionForPrismsRecurse__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_v, 0x807bf4c0, 0x807c01e4);
asm UNKNOWN_FUNCTION(applyFunctionForPrismsRecurse__Q25Field16KCollisionOctreeFPUcUlMQ25Field16KCollisionOctreeFPCvPvPUs_v) {
  #include "asm/807bf4c0.s"
}
#else
namespace Field {
// MARK_FLOW_CHECK(0x807bf4c0); Takes too long to flow-check
// regswap: https://decomp.me/scratch/o1f1W
void KCollisionOctree::applyFunctionForPrismsRecurse(u8* prismArray, const u32 index, PrismListVisitor prismListVisitor) {
  s32 offset = *(u32*)(prismArray + index);
  if ((offset & 0x80000000) != 0) {
    (this->*prismListVisitor)(reinterpret_cast<u16*>(prismArray + (offset & 0x7FFFFFFF)));
  } else {
    u8* curBlock = prismArray + offset;
    applyFunctionForPrismsRecurse(curBlock, 4*0, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*1, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*2, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*3, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*4, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*5, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*6, prismListVisitor);
    applyFunctionForPrismsRecurse(curBlock, 4*7, prismListVisitor);
  }
}
}
#endif

// Symbol: unk_807c01e4
// PAL: 0x807c01e4..0x807c0884
MARK_BINARY_BLOB(unk_807c01e4, 0x807c01e4, 0x807c0884);
asm UNKNOWN_FUNCTION(unk_807c01e4) {
  #include "asm/807c01e4.s"
}

// Symbol: kcl_triangle_collides_two_points
// PAL: 0x807c0884..0x807c0f00
MARK_BINARY_BLOB(kcl_triangle_collides_two_points, 0x807c0884, 0x807c0f00);
asm UNKNOWN_FUNCTION(kcl_triangle_collides_two_points) {
  #include "asm/807c0884.s"
}

// Symbol: checkSphere__Q25Field16KCollisionOctreeFlll
// PAL: 0x807c0f00..0x807c1514
MARK_BINARY_BLOB(checkSphere__Q25Field16KCollisionOctreeFlll, 0x807c0f00, 0x807c1514);
asm UNKNOWN_FUNCTION(checkSphere__Q25Field16KCollisionOctreeFlll) {
  #include "asm/807c0f00.s"
}

// Symbol: kcl_triangle_collides_one_point
// PAL: 0x807c1514..0x807c1b0c
MARK_BINARY_BLOB(kcl_triangle_collides_one_point, 0x807c1514, 0x807c1b0c);
asm UNKNOWN_FUNCTION(kcl_triangle_collides_one_point) {
  #include "asm/807c1514.s"
}

namespace Field {
void KCollisionOctree::prepareCollisionTest(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask) {
  this->prismIndexes = searchBlock(pos);
  this->pos = pos;
  this->prevPos = prevPos;
  VEC3Sub(&this->movement, &pos, &prevPos);
  //this->movement = pos - prevPos; can't inline VEC3Sub in an operator without messing the stack
  this->typeMask = typeMask;
}

void KCollisionOctree::prepareCollisionTestSphere(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, f32 radius) {
  f32 radiusClamped = radius;
  if (radius > this->sphere_radius) {
    radiusClamped = this->sphere_radius;
  }
  this->prismIndexes = searchBlock(pos);
  this->pos = pos;
  this->prevPos = prevPos;
  VEC3Sub(&this->movement, &pos, &prevPos);
  //this->movement = pos - prevPos; can't inline VEC3Sub in an operator without messing the stack
  this->radius = radiusClamped;
  this->typeMask = typeMask;
}
}

// Symbol: unk_807c1c8c
// PAL: 0x807c1c8c..0x807c1de8
MARK_BINARY_BLOB(unk_807c1c8c, 0x807c1c8c, 0x807c1de8);
asm UNKNOWN_FUNCTION(unk_807c1c8c) {
  #include "asm/807c1c8c.s"
}

// Symbol: kcl_find_tri_list_and_prepare_cached
// PAL: 0x807c1de8..0x807c1f80
MARK_BINARY_BLOB(kcl_find_tri_list_and_prepare_cached, 0x807c1de8, 0x807c1f80);
asm UNKNOWN_FUNCTION(kcl_find_tri_list_and_prepare_cached) {
  #include "asm/807c1de8.s"
}

// Symbol: unk_807c1f80
// PAL: 0x807c1f80..0x807c1fac
MARK_BINARY_BLOB(unk_807c1f80, 0x807c1f80, 0x807c1fac);
asm UNKNOWN_FUNCTION(unk_807c1f80) {
  #include "asm/807c1f80.s"
}

// Symbol: unk_807c1fac
// PAL: 0x807c1fac..0x807c21f4
MARK_BINARY_BLOB(unk_807c1fac, 0x807c1fac, 0x807c21f4);
asm UNKNOWN_FUNCTION(unk_807c1fac) {
  #include "asm/807c1fac.s"
}

// Symbol: unk_807c21f4
// PAL: 0x807c21f4..0x807c2410
MARK_BINARY_BLOB(unk_807c21f4, 0x807c21f4, 0x807c2410);
asm UNKNOWN_FUNCTION(unk_807c21f4) {
  #include "asm/807c21f4.s"
}

// Symbol: kcl_triangle_collides
// PAL: 0x807c2410..0x807c243c
MARK_BINARY_BLOB(kcl_triangle_collides, 0x807c2410, 0x807c243c);
asm UNKNOWN_FUNCTION(kcl_triangle_collides) {
  #include "asm/807c2410.s"
}

#define ARRAY_END(X) (&X + 1)
namespace Field {
void KCollisionOctree::narrowPolygon_EachBlock(u16* prismArray) {
  this->prismIndexes = prismArray;

  u16* prismIt = prismCacheTop;
  while (checkSphere(0, 0, 0)) {
    prismIt = prismCacheTop;
    *prismIt = *this->prismIndexes;
    prismCacheTop = prismIt + 1;
    if (prismIt + 1 >= (u16*)ARRAY_END(prismCache)) {
      prismCacheTop--;
      return;
    }
  }
}

void KCollisionOctree::narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 typeMask) {
  this->prismCacheTop = this->prismCache;
  this->pos = pos;
  this->radius = radius;
  this->typeMask = typeMask;
  this->cachedPos = pos;
  this->cachedRadius = radius;

  if (radius > this->sphere_radius) {
     this->searchMultiBlock(pos, radius, KCollisionOctree::narrowPolygon_EachBlock);
  } else {
     this->narrowPolygon_EachBlock(searchBlock(pos));
  }
  *this->prismCacheTop = nullptr;
}
}

