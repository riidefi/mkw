#pragma once

#include <rk_types.h>
namespace nw4r {
namespace math {

  static inline u16 ps_f32_to_u16(register f32 in) {
    f32 a;
    register f32* ptr = &a;
    register u16 r;
    
    asm
    {
#ifdef __CWCC__
psq_st in, 0(ptr), 1, 3
lhz r, 0(ptr)
#endif
  }
  return r;
}

static inline void fast_f32_to_u16(register f32* in,
                                   volatile register u16* out) {
  *out = ps_f32_to_u16(*in);
}

static inline f32 ps_u16_to_f32(register u16* in) {
  register f32 r;
#ifdef __CWCC__
  asm { psq_l r, 0(in), 1, 3 }
#endif
  return r;
}

static inline void fast_u16_to_f32(register u16* in,
                                   volatile register f32* out) {
  *out = ps_u16_to_f32(in);
}

inline u16 f32_to_u16(f32 in) {
  u16 out;
  fast_f32_to_u16(&in, &out);
  return out;
}

inline f32 u16_to_f32(u16 in) {
  f32 out;
  fast_u16_to_f32(&in, &out);
  return out;
}

inline f32 FAbs(register f32 x) {
  register f32 ret;
#ifdef __CWCC__
  asm { fabs ret, x }
#endif
  return ret;
}

} // namespace math
} // namespace nw4r
