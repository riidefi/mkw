
#pragma once

#include "rk_types.h"

#include "egg/math/eggVector.hpp"

namespace Field {
struct KCollisionHeader {
  u32 pos_data_offset;
  u32 nrm_data_offset;
  u32 prism_data_offset;
  u32 block_data_offset;
  f32 prism_thickness;
  EGG::Vector3f area_min_pos;
  u32 area_x_width_mask;
  u32 area_y_width_mask;
  u32 area_z_width_mask;
  u32 block_width_shift;
  u32 area_x_blocks_shift;
  u32 area_xy_blocks_shift;
  f32 sphere_radius;
};

struct KCollisionPrism {
  // inlined after KCollisionOctree ctor I think ~KCollisionPrism() {}

  f32 height;
  u16 pos_i;
  u16 fnrm_i;
  u16 enrm1_i;
  u16 enrm2_i;
  u16 enrm3_i;
  u16 attribute;
};

#define KCL_ATTRIBUTE_TYPE(x) ((x) & 0x3f)
#define KCL_TYPE_BIT(x) (1 << (x))
#define KCL_ATTRIBUTE_TYPE_BIT(x) KCL_TYPE_BIT(KCL_ATTRIBUTE_TYPE(x))
}
