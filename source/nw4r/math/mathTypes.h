#pragma once

#include <rk_types.h>

namespace nw4r {
namespace math {

struct _VEC3 {
  f32 x;
  f32 y;
  f32 z;
};

struct _MTX33 {
  union {
    struct {
      f32 _00, _01, _02;
      f32 _10, _11, _12;
      f32 _20, _21, _22;
    };
    f32 arr[9];
    f32 mtx[3][3];
  };
};

struct _MTX34 {
  union {
    struct {
      f32 _00, _01, _02, _03;
      f32 _10, _11, _12, _13;
      f32 _20, _21, _22, _23;
    };
    f32 arr[12];
    f32 mtx[3][4];
  };
};

struct _MTX44 {
  f32 arr[16];
};

// forward decls
struct VEC3;
struct MTX34;
struct MTX44;

struct VEC3 : public _VEC3 {
public:
  VEC3() {}

  operator f32*() { return &x; }
  operator const f32*() const { return &x; }
};

class MTX33 : public _MTX33 {
public:
  MTX33() {}
  MTX33(const f32* p);
  MTX33(const MTX34& rhs);
  MTX33(f32 x00, f32 x01, f32 x02, f32 x10, f32 x11, f32 x12, f32 x20, f32 x21,
        f32 x22) {
    _00 = x00;
    _01 = x01;
    _02 = x02;
    _10 = x10;
    _11 = x11;
    _12 = x12;
    _20 = x20;
    _21 = x21;
    _22 = x22;
  }

  operator f32*() { return &_00; }
  operator const f32*() const { return &_00; }
};

// PAL: 0x80085600
MTX33* MTX33Identity(MTX33*);
// PAL: 0x80085630
MTX33* MTX34ToMTX33(MTX33*, const MTX34*);
// PAL: 0x80085670
u32 MTX34InvTranspose(MTX33*, const MTX34*);
// PAL: 0x80085740
MTX34* MTX34Zero(MTX34*);
// PAL: 0x80085760
MTX34* MTX34Mult(MTX34*, const MTX34*, f32);
// PAL: 0x800857b0
MTX34* MTX34Scale(MTX34*, const MTX34*, const VEC3*);
// PAL: 0x80085810
MTX34* MTX34Trans(MTX34*, const MTX34*, const VEC3*);
// PAL: 0x80085880
MTX34* MTX34MAdd(MTX34*, f32, const MTX34*, const MTX34*);

} // namespace math
} // namespace nw4r
