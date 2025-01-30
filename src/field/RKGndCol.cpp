#include "RKGndCol.hpp"

#include <math.h>

#include "nw4r/math/mathTypes.hpp"
#include "nw4r/math/mathArithmetic.hpp"

namespace Field {
RKGndCol::RKGndCol(const KCollisionHeader& header) {
  s32 pos_off = header.pos_data_offset;
  this->pos_data = (EGG::Vector3f*) header.pos_data_offset;
  s32 nrm_off = header.nrm_data_offset;
  this->nrm_data = (EGG::Vector3f*) header.nrm_data_offset;
  s32 prism_off = header.prism_data_offset;
  this->prism_data = (KCollisionPrism*) header.prism_data_offset;
  s32 block_off = header.block_data_offset;
  this->block_data = (u8*)header.block_data_offset;

  this->prism_thickness = header.prism_thickness;
  this->area_min_pos = header.area_min_pos;
  this->area_x_width_mask = header.area_x_width_mask;
  this->area_y_width_mask = header.area_y_width_mask;
  this->area_z_width_mask = header.area_z_width_mask;
  this->block_width_shift = header.block_width_shift;
  this->area_x_blocks_shift = header.area_x_blocks_shift;
  this->area_xy_blocks_shift = header.area_xy_blocks_shift;
  this->sphere_radius = header.sphere_radius;
  this->pos_data = (EGG::Vector3f*) ((const u8*)&header + pos_off);
  this->nrm_data = (EGG::Vector3f*) ((const u8*)&header + nrm_off);
  this->prism_data = (KCollisionPrism*) ((const u8*)&header + prism_off);
  this->block_data = (u8*) ((const u8*)&header + block_off);

  this->pos.setZero();
  this->prevPos.setZero();
  this->movement.setZero();
  this->radius = 0.0f;
  this->prismArrayIt = nullptr;
  this->cachedPrismArrayIt = (u16 *)&this->prismCache - 1; // wtf
  this->prisms = this->prism_data + 1;
  this->prismCount = ((s32)this->block_data - (s32)this->prisms) / (s32)sizeof(KCollisionPrism);
  this->computeBbox();
}

struct DummyB { ~DummyB(); };
DummyB::~DummyB() {}

RKGndCol::~RKGndCol() {}

void RKGndCol::computeBbox() {
  this->bboxLow.set(999999.0f);
  this->bboxHigh.set(-999999.0f);

  for (s32 i = 0; i < this->prismCount; i++) {
    KCollisionPrism& prism = this->prisms[i];
    EGG::Vector3f* nrm_data = this->nrm_data;
    EGG::Vector3f& fnrm = nrm_data[prism.fnrm_i];
    EGG::Vector3f& enrm1 = nrm_data[prism.enrm1_i];
    EGG::Vector3f& enrm2 = nrm_data[prism.enrm2_i];
    EGG::Vector3f& enrm3 = nrm_data[prism.enrm3_i];
    EGG::Vector3f& vtx1 = this->pos_data[prism.pos_i];

    EGG::Vector3f vtx3 = getVertex(prism.height, vtx1, fnrm, enrm3, enrm1);
    EGG::Vector3f vtx2 = getVertex(prism.height, vtx1, fnrm, enrm3, enrm2);

    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &vtx1);
    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &vtx3);
    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &vtx2);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &vtx1);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &vtx3);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &vtx2);
  }
}

// https://decomp.me/scratch/byfkO
EGG::Vector3f RKGndCol::getVertex(f32 height, const EGG::Vector3f& vertex1, const EGG::Vector3f& fnrm,
    	const EGG::Vector3f& enrm3, const EGG::Vector3f& enrm) {
  EGG::Vector3f cross;

  VECCrossProduct(fnrm, enrm, cross);

  f32 dp = VEC3Dot(&cross, &enrm3);
  cross *= (height / dp);

  return cross += vertex1;
}

u16* RKGndCol::searchBlock(const EGG::Vector3f& point) {
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

void RKGndCol::searchMultiBlock(const EGG::Vector3f& point, f32 radius, PrismListVisitor prismListVisitor) {
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

        this->searchMultiBlockRecursiveAll(blockData, index, prismListVisitor,
            x == xminBlock ? xmin : 0, y == yminBlock ? ymin : 0, z == zminBlock ? zmin : 0,
            x == xmaxBlock ? xmax : -1, y == ymaxBlock ? ymax : -1, z == zmaxBlock ? zmax : -1);
      }
    }
  }
}

// searchMultiBlockRecursiveAll: nonmatching: https://decomp.me/scratch/5gxb6
// searchMultiBlockRecursive: regswap+inswap: https://decomp.me/scratch/5gxb6
#define MIN_EDGE_CHILD(x) (x & 0x80000000) == 0 ? x : -1
#define MAX_EDGE_CHILD(x) (x & 0x80000000) == 0 ? x : -1

void RKGndCol::searchMultiBlockRecursiveAll(u8* prismArray, u32 index, PrismListVisitor prismListVisitor,
        s32 xmin, s32 ymin, s32 zmin, s32 xmax, s32 ymax, s32 zmax) {
  if ((xmin | ymin | zmin) == 0 && (xmax & ymax & zmax) == 0xffffffff) {
    searchMultiBlockRecursive(prismArray, index, prismListVisitor);
  }

  /*if (xmin == 0xffffffff || ymin == 0xffffffff || zmin == 0xffffffff || xmax == 0 || ymax == 0 || zmax == 0) {
    return;
  }*/

  else if (xmin != 0xffffffff && ymin != 0xffffffff && zmin != 0xffffffff && xmax != 0 && ymax != 0 && zmax != 0) {
  s32 offset = *(u32*)(prismArray + index);
  if ((offset & 0x80000000) != 0) {
    (this->*prismListVisitor)(reinterpret_cast<u16*>(prismArray + (offset & 0x7FFFFFFF)));
    return;
  } else {
    u8* curBlock = prismArray + offset;

    s32 nextxmin = xmin << 1;
    s32 nextymin = ymin << 1;
    s32 nextzmin = zmin << 1;
    s32 nextxmax = xmax << 1;
    s32 nextymax = ymax << 1;
    s32 nextzmax = zmax << 1;

    s32 nextxminedge = MIN_EDGE_CHILD(nextxmin);
    s32 nextyminedge = MIN_EDGE_CHILD(nextymin);
    s32 nextzminedge = MIN_EDGE_CHILD(nextzmin);

    s32 nextxmaxedge = MAX_EDGE_CHILD(nextxmax);
    s32 nextymaxedge = MAX_EDGE_CHILD(nextymax);
    s32 nextzmaxedge = MAX_EDGE_CHILD(nextzmax);

    searchMultiBlockRecursiveAll(curBlock, 4*0, prismListVisitor, nextxminedge, nextyminedge, nextzminedge, nextxmaxedge, nextymaxedge, nextzmaxedge);
    searchMultiBlockRecursiveAll(curBlock, 4*1, prismListVisitor, nextxmin, nextyminedge, nextzminedge, nextxmax, nextymaxedge, nextzmaxedge);
    searchMultiBlockRecursiveAll(curBlock, 4*2, prismListVisitor, nextxminedge, nextymin, nextzminedge, nextymaxedge, nextymax, nextzmaxedge);
    searchMultiBlockRecursiveAll(curBlock, 4*3, prismListVisitor, nextxmin, nextymin, nextzminedge, nextxmax, nextymax, nextzmaxedge);
    searchMultiBlockRecursiveAll(curBlock, 4*4, prismListVisitor, nextxminedge, nextyminedge, nextzmin, nextymaxedge, nextymaxedge, nextzmax);
    searchMultiBlockRecursiveAll(curBlock, 4*5, prismListVisitor, nextxmin, nextyminedge, nextzmin, nextxmax, nextymaxedge, nextzmax);
    searchMultiBlockRecursiveAll(curBlock, 4*6, prismListVisitor, nextxminedge, nextymin, nextzmin, nextymaxedge, nextymax, nextzmax);
    searchMultiBlockRecursiveAll(curBlock, 4*7, prismListVisitor, nextxmin, nextymin, nextzmin, nextxmax, nextymax, nextzmax);
  }
  }
}

MARK_FLOW_CHECK(0x807bf4c0);
void RKGndCol::searchMultiBlockRecursive(u8* prismArray, u32 index, PrismListVisitor prismListVisitor) {
  u32* nextBlock = (u32*)(prismArray + index);
  if ((*nextBlock & 0x80000000) != 0) {
    (this->*prismListVisitor)(reinterpret_cast<u16*>(prismArray + (*nextBlock & 0x7FFFFFFF)));
  } else {
    u8* curBlock = prismArray + *nextBlock;
    searchMultiBlockRecursive(curBlock, 4*0, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*1, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*2, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*3, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*4, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*5, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*6, prismListVisitor);
    searchMultiBlockRecursive(curBlock, 4*7, prismListVisitor);
  }
}

// https://decomp.me/scratch/l1qiN
static inline f32 cornerLenSq(const EGG::Vector3f& v1, const EGG::Vector3f& v2, f32 cos, f32 edge_dist, f32 other_dist) {
  f32 w1 = (cos * edge_dist - other_dist) / (cos * cos - 1.0f);
  f32 w2 = edge_dist - w1 * cos;

  EGG::Vector3f sth;
  sth.y = v1.y * w1 + v2.y * w2;
  sth.x = v1.x * w1 + v2.x * w2;
  sth.z = v1.z * w1 + v2.z * w2;

  return sth.lenSq();
}

bool isPositive(f32 x) { return x>= 0; }

#pragma suppress_warnings on // goto warning spam
bool RKGndCol::checkSphereSingle(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut) {
  f32 radius = this->radius;
  EGG::Vector3f* nrm_data = this->nrm_data;
  bool cacheNotEmpty = prismCacheNotEmpty();
  if (prismArrayIt == nullptr) return false;

  while (*++prismArrayIt != nullptr) {
    // skip if in cache
    if (cacheNotEmpty) {
      u16* prismCacheIt = prismCacheTop;
      while (--prismCacheIt >= prismCache) {
        if (*prismArrayIt == *prismCacheIt) break;
      }
      if (prismCacheIt >= prismCache) continue;
    }

    // 807c0fe4 - 807c14b0
    KCollisionPrism& prism = this->prism_data[*prismArrayIt];
    EGG::Vector3f& vertex = this->pos_data[prism.pos_i];
    EGG::Vector3f relPos = this->pos - vertex;
    EGG::Vector3f& enrm1 = nrm_data[prism.enrm1_i];

    f32 enrm1dist = EGG::Vector3f::dot(relPos, enrm1);
    if (enrm1dist >= radius) continue;

    EGG::Vector3f& enrm2 = nrm_data[prism.enrm2_i];
    f32 enrm2dist = EGG::Vector3f::dot(relPos, enrm2);
    if (enrm2dist >= radius) continue;

    EGG::Vector3f& enrm3 = nrm_data[prism.enrm3_i];
    f32 enrm3dist = EGG::Vector3f::dot(relPos, enrm3) - prism.height;
    if (enrm3dist >= radius) continue;

    EGG::Vector3f& fnrm = nrm_data[prism.fnrm_i];
    f32 dist = radius - EGG::Vector3f::dot(relPos, fnrm);
    if (dist <= 0.0f) continue;

    if (!(dist <= this->prism_thickness) || this->prism_thickness + radius <= dist) {
      continue;
    }

    if ((KCL_ATTRIBUTE_TYPE_BIT(prism.attribute) & this->typeMask) == 0) continue;

    f32 sqDist;
    f32 radiusSq = radius * radius;
    f32 cornerDistSq;
    f32 cos;
    if (enrm1dist > enrm2dist) {
      if (enrm1dist > enrm3dist) {
        goto m1154;
      } else {
        goto m122c;
      }
    } else {
      if (enrm2dist > enrm3dist) {
        goto m11c0;
      } else {
        goto m122c;
      }
    }
m1154:
    if (enrm1dist <= 0) goto collisionTrue;
    if (enrm2dist > enrm3dist) {
      cos = EGG::Vector3f::dot(enrm1, enrm2);
      if (cos * enrm1dist > enrm2dist) goto edge1;
      else goto corner1;
    } else {
      cos = EGG::Vector3f::dot(enrm1, enrm3);
      if (cos * enrm1dist > enrm3dist) goto edge1;
      else goto corner2;
    }
m11c0:
    if (enrm2dist <= 0) goto collisionTrue;
    if (enrm3dist > enrm1dist) {
      cos = EGG::Vector3f::dot(enrm2, enrm3);
      if (cos * enrm2dist > enrm3dist) goto edge2;
      else goto corner3;
    } else {
      cos = EGG::Vector3f::dot(enrm2, enrm1);
      if (cos * enrm2dist > enrm1dist) goto edge2;
      else goto corner1;
    }
m122c:
    if (enrm3dist <= 0) goto collisionTrue;
    if (enrm1dist > enrm2dist) {
      cos = EGG::Vector3f::dot(enrm3, enrm1);
      if (cos * enrm3dist > enrm1dist) goto edge3;
      else goto corner2;
    } else {
      cos = EGG::Vector3f::dot(enrm3, enrm2);
      if (cos * enrm3dist > enrm2dist) goto edge3;
      else goto corner3;
    }
edge1:
    sqDist = radiusSq - enrm1dist * enrm1dist;
    goto distCheck;
edge2:
    sqDist = radiusSq - enrm2dist * enrm2dist;
    goto distCheck;
edge3:
    sqDist = radiusSq - enrm3dist * enrm3dist;
    goto distCheck;

corner1:
    cornerDistSq = cornerLenSq(enrm1, enrm2, cos, enrm1dist, enrm2dist);
    goto cornerDistCheck;
corner2:
    cornerDistSq = cornerLenSq(enrm2, enrm3, cos, enrm2dist, enrm3dist);
    goto cornerDistCheck;
corner3:
    cornerDistSq = cornerLenSq(enrm3, enrm1, cos, enrm3dist, enrm1dist);
    goto cornerDistCheck;

cornerDistCheck:
    sqDist = radiusSq - cornerDistSq;
    if (sqDist <= 0) continue;
distCheck:
    if (sqDist < dist*dist || isPositive(sqDist)) continue;
    f32 someDist = nw4r::math::FSqrt(sqDist);
    if (someDist - dist <= 0) continue;

collisionTrue:
    return true;
  }

  prismArrayIt = nullptr;
  return false;
}
#pragma suppress_warnings off

void RKGndCol::lookupPoint(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask) {
  this->prismArrayIt = searchBlock(pos);
  this->pos = pos;
  this->prevPos = prevPos;
  VEC3Sub(&this->movement, &pos, &prevPos);
  //this->movement = pos - prevPos; can't inline VEC3Sub in an operator without messing the stack
  this->typeMask = typeMask;
}

void RKGndCol::lookupSphere(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, f32 radius) {
  f32 radiusClamped = radius;
  if (radius > this->sphere_radius) {
    radiusClamped = this->sphere_radius;
  }
  this->prismArrayIt = searchBlock(pos);
  this->pos = pos;
  this->prevPos = prevPos;
  VEC3Sub(&this->movement, &pos, &prevPos);
  //this->movement = pos - prevPos; can't inline VEC3Sub in an operator without messing the stack
  this->radius = radiusClamped;
  this->typeMask = typeMask;
}

void RKGndCol::lookupPointCached(const EGG::Vector3f& p1, const EGG::Vector3f& p2, u32 typeMask) {
  EGG::Vector3f c1 = p1;
  EGG::Vector3f c2 = this->cachedPos;
  bool cacheMiss = EGG::isSphereContainedInOther(c1, 0.01f, c2, this->cachedRadius) == false;
  if (cacheMiss) {
    lookupPoint(p1, p2, typeMask);
  } else {
    this->pos = p1;
    this->prevPos = p2;
    VEC3Sub(&this->movement, &p1, &p2);
    this->radius = 0.01f;
    this->typeMask = typeMask;

    this->prismArrayIt = this->cachedPrismArrayIt;
  }
}

void RKGndCol::lookupSphereCached(const EGG::Vector3f& p1, const EGG::Vector3f& p2, u32 typeMask, f32 radius) {
  f32 r = radius;
  EGG::Vector3f c1 = p1;
  EGG::Vector3f c2 = this->cachedPos;
  bool cacheMiss = EGG::isSphereContainedInOther(c1, radius, c2, this->cachedRadius) == false;
  if (cacheMiss) {
    if (r > this->sphere_radius)
      r = this->sphere_radius;
    lookupSphere(p1, p2, typeMask, r);
  } else {
    this->pos = p1;
    this->prevPos = p2;
    VEC3Sub(&this->movement, &p1, &p2);
    this->radius = radius;
    this->typeMask = typeMask;

    this->prismArrayIt = this->cachedPrismArrayIt;
  }

}

bool RKGndCol::checkPointCollision(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut) {
  return isfinite(this->prevPos.y)                          ?
	 checkPointMovement(distOut, fnrmOut, attributeOut) :
         checkPoint        (distOut, fnrmOut, attributeOut);
}

bool RKGndCol::checkPointMovement(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut) {
  f32 radius = 0.01f;
  EGG::Vector3f* nrm_data = this->nrm_data;
  bool cacheNotEmpty = prismCacheNotEmpty();
  if (prismArrayIt == nullptr) return false;

  while (*++prismArrayIt != nullptr) {
    KCollisionPrism& prism = this->prism_data[*prismArrayIt];
    EGG::Vector3f& vertex = this->pos_data[prism.pos_i];
    EGG::Vector3f relPos;
    nw4r::math::VEC3Sub(&relPos, &this->pos, &vertex);
    EGG::Vector3f& enrm1 = nrm_data[prism.enrm1_i];

    f32 enrm1dist = nw4r::math::VEC3Dot(&relPos, &enrm1);
    if (enrm1dist >= 0.01f) continue;

    EGG::Vector3f& enrm2 = nrm_data[prism.enrm2_i];
    f32 enrm2dist = nw4r::math::VEC3Dot(&relPos, &enrm2);
    if (enrm2dist >= 0.01f) continue;

    EGG::Vector3f& enrm3 = nrm_data[prism.enrm3_i];
    f32 enrm3dist = nw4r::math::VEC3Dot(&relPos, &enrm3) - prism.height;
    if (enrm3dist >= 0.01f) continue;

    EGG::Vector3f fnrm = nrm_data[prism.fnrm_i];
    f32 dist = 0.01f - nw4r::math::VEC3Dot(&relPos, &fnrm);
    if (dist <= 0.0f) continue;

    if (this->prism_thickness <= dist && this->prism_thickness + 0.02f <= dist) {
      continue;
    }

    if ((KCL_ATTRIBUTE_TYPE_BIT(prism.attribute) & this->typeMask) == 0) continue;

    if ((KCL_ATTRIBUTE_TYPE_BIT(prism.attribute) & KCL_TYPE_DIRECTIONAL) != 0 && nw4r::math::VEC3Dot(&this->movement, &fnrm) > 0.0f) continue;

    if (distOut != nullptr) {
      *distOut = dist;
    }
    if (fnrmOut != nullptr) {
      *fnrmOut = fnrm;
    }
    if (attributeOut != nullptr) {
      *attributeOut = prism.attribute;
    }
    return true;
  }
  this->prismArrayIt = nullptr;
  return false;
}

bool RKGndCol::checkPoint(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut) {
  f32 radius = 0.01f;
  EGG::Vector3f* nrm_data = this->nrm_data;
  bool cacheNotEmpty = prismCacheNotEmpty();
  if (prismArrayIt == nullptr) return false;

  while (*++prismArrayIt != nullptr) {
    KCollisionPrism& prism = this->prism_data[*prismArrayIt];
    EGG::Vector3f& vertex = this->pos_data[prism.pos_i];
    EGG::Vector3f relPos;
    nw4r::math::VEC3Sub(&relPos, &this->pos, &vertex);
        EGG::Vector3f& enrm1 = nrm_data[prism.enrm1_i];

    f32 enrm1dist = nw4r::math::VEC3Dot(&relPos, &enrm1);
    if (enrm1dist >= 0.01f) continue;

    EGG::Vector3f& enrm2 = nrm_data[prism.enrm2_i];
    f32 enrm2dist = nw4r::math::VEC3Dot(&relPos, &enrm2);
    if (enrm2dist >= 0.01f) continue;

    EGG::Vector3f& enrm3 = nrm_data[prism.enrm3_i];
    f32 enrm3dist = nw4r::math::VEC3Dot(&relPos, &enrm3) - prism.height;
    if (enrm3dist >= 0.01f) continue;

    EGG::Vector3f fnrm = nrm_data[prism.fnrm_i];
    f32 dist = 0.01f - nw4r::math::VEC3Dot(&relPos, &fnrm);
    if (dist <= 0.0f) continue;

    if (this->prism_thickness <= dist && this->prism_thickness + 0.02f <= dist) {
      continue;
    }

    if ((KCL_ATTRIBUTE_TYPE_BIT(prism.attribute) & this->typeMask) == 0) continue;

    if (distOut != nullptr) {
      *distOut = dist;
    }
    if (fnrmOut != nullptr) {
      *fnrmOut = fnrm;
    }
    if (attributeOut != nullptr) {
      *attributeOut = prism.attribute;
    }
    return true;
  }
  this->prismArrayIt = nullptr;
  return false;
}

bool RKGndCol::checkSphereCollision(f32* distOut, EGG::Vector3f* fnrmOut, u16* attributeOut) {
  return isfinite(this->prevPos.y)                          ?
	 checkSphereMovement(distOut, fnrmOut, attributeOut) :
         checkSphere        (distOut, fnrmOut, attributeOut);
}

#define ARRAY_END(X) (&X + 1)
void RKGndCol::narrowPolygon_EachBlock(u16* prismArray) {
  this->prismArrayIt = prismArray;

  u16* prismCacheIt = prismCacheTop;
  while (checkSphereSingle(nullptr, nullptr, nullptr)) {
    // Add colliding prism to cache
    prismCacheIt = prismCacheTop;
    *prismCacheIt = *this->prismArrayIt;
    prismCacheTop = prismCacheIt + 1;
    if (prismCacheIt + 1 >= (u16*)ARRAY_END(prismCache)) {
      prismCacheTop--;
      return;
    }
  }
}

void RKGndCol::narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 typeMask, u32 unused) {
  this->prismCacheTop = this->prismCache;
  this->pos = pos;
  this->radius = radius;
  this->typeMask = typeMask;
  this->cachedPos = pos;
  this->cachedRadius = radius;

  if (radius > this->sphere_radius) {
    this->searchMultiBlock(pos, radius, &RKGndCol::narrowPolygon_EachBlock);
  } else {
    this->narrowPolygon_EachBlock(searchBlock(pos));
  }
  *this->prismCacheTop = nullptr;
}
}
