#pragma once

#include <rk_types.h>

#include "rvl/mtx/mtx.h"

namespace nw4r {
namespace math {

struct _VEC2 {
  f32 x;
  f32 y;
};

struct _VEC3 {
  f32 x;
  f32 y;
  f32 z;
};

struct __MTX33 {
  f32 _00, _01, _02;
  f32 _10, _11, _12;
  f32 _20, _21, _22;
};

struct _MTX33 {
  union {
    struct __MTX33 e;
    f32 arr[9];
    f32 mtx[3][3];
  };
};

struct __MTX34 {
  f32 _00, _01, _02, _03;
  f32 _10, _11, _12, _13;
  f32 _20, _21, _22, _23;
};

struct _MTX34 {
  union {
    struct __MTX34 e;
    f32 arr[12];
    f32 mtx[3][4];
  };
};

struct _MTX44 {
  f32 arr[16];
};

// forward decls
struct VEC2;
struct VEC3;
struct MTX34;
struct MTX44;

struct VEC3 : public _VEC3 {
public:
  VEC3() {}

  operator f32*() { return &x; }
  operator const f32*() const { return &x; }

  operator Vec*() { return (Vec*)&x; }
  operator const Vec*() const { return (const Vec*)&x; }

  bool operator==(const VEC3& o) const {
    return x == o.x && y == o.y && z == o.z;
  }
  bool operator!=(const VEC3& o) const {
    return x != o.x || y != o.y || z != o.z;
  }
};

struct VEC2 : public _VEC2 {
  bool operator==(const VEC3& o) const { return x == o.x && y == o.y; }
  bool operator!=(const VEC3& o) const { return x != o.x || y != o.y; }
};

class MTX33 : public _MTX33 {
public:
  MTX33() {}
  MTX33(const f32* p);
  MTX33(const MTX34& rhs);
  MTX33(f32 x00, f32 x01, f32 x02, f32 x10, f32 x11, f32 x12, f32 x20, f32 x21,
        f32 x22) {
    e._00 = x00;
    e._01 = x01;
    e._02 = x02;
    e._10 = x10;
    e._11 = x11;
    e._12 = x12;
    e._20 = x20;
    e._21 = x21;
    e._22 = x22;
  }

  operator f32*() { return &e._00; }
  operator const f32*() const { return &e._00; }
};

struct MTX34 : public _MTX34 {
public:
  typedef f32 (*MtxPtr)[4];
  typedef const f32 (*ConstMtxPtr)[4];

public:
  MTX34() {}

  operator f32*() { return &e._00; }
  operator const f32*() const { return &e._00; }

  operator MtxPtr() { return (MtxPtr)&e._00; }
  operator ConstMtxPtr() const { return (ConstMtxPtr)&e._00; }
};

struct MTX44 : public _MTX44 {
public:
  typedef f32 (*Mtx44Ptr)[4];
  typedef const f32 (*ConstMtx44Ptr)[4];

public:
  MTX44() {}

  operator f32*() { return &arr[0]; }
  operator const f32*() const { return &arr[0]; }

  operator Mtx44Ptr() { return (Mtx44Ptr)&arr[0]; }
  operator ConstMtx44Ptr() const { return (ConstMtx44Ptr)&arr[0]; }
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
// PAL: 0x80085900
MTX34* MTX34RotAxisFIdx(MTX34*, const VEC3*, f32);

} // namespace math
} // namespace nw4r
