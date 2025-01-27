#pragma once

#include <rk_types.h>

#include "rvl/mtx/mtx.h"

#include "nw4r/math/config.h"

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
  typedef VEC3 self_type;
  typedef f32  value_type;

  VEC3() {}
  VEC3(const f32* p) { x = p[0]; y = p[1]; z = p[2]; }
  VEC3(f32 fx, f32 fy, f32 fz) { x = fx; y = fy; z = fz; }
  VEC3(const _VEC3& v) { x = v.x; y = v.y; z = v.z; }
  VEC3(const Vec& v) { x = v.x; y = v.y; z = v.z; }

  operator f32*() { return &x; }
  operator const f32*() const { return &x; }

  operator Vec*() { return (Vec*)&x; }
  operator const Vec*() const { return (const Vec*)&x; }

  self_type& operator+=(const self_type& rhs);
  self_type& operator-=(const self_type& rhs);
  self_type& operator*=(f32 f);
  self_type& operator/=(f32 f) { return operator*=(1.f / f); }

  self_type operator+() const { return *this; }
  self_type operator-() const { return self_type(-x, -y, -z); }

  // The optimal implementation of binary operators depends on whether the return value is optimized.
  self_type operator+(const self_type& rhs) const;
  self_type operator-(const self_type& rhs) const;
  self_type operator*(f32 f) const;
  self_type operator/(f32 f) const { f32 r = 1.f / f; return operator*(r); }

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

inline VEC3* VEC3Add(register VEC3* pOut, const register VEC3* p1, const register VEC3* p2)
{
#if defined(NW4R_MATH_BROADWAY)
    register f32 a, b, c;
    asm
    {
        psq_l a, 0(p1), 0, 0;
        psq_l b, 0(p2), 0, 0;
        ps_add c, a, b;
        psq_st c, 0(pOut), 0, 0;

        psq_l a, 8(p1), 1, 0;
        psq_l b, 8(p2), 1, 0;
        ps_add c, a, b;
        psq_st c, 8(pOut), 1, 0;
    }
#else
    pOut->x = p1->x + p2->x;
    pOut->y = p1->y + p2->y;
    pOut->z = p1->z + p2->z;
#endif
    return pOut;
}

inline VEC3* VEC3Sub(register VEC3* pOut, const register VEC3* p1, const register VEC3* p2)
{
#if defined(NW4R_MATH_BROADWAY)
    register f32 a, b, c;
    asm
    {
        psq_l a, 0(p1), 0, 0;
        psq_l b, 0(p2), 0, 0;
        ps_sub c, a, b;
        psq_st c, 0(pOut), 0, 0;

        psq_l a, 8(p1), 1, 0;
        psq_l b, 8(p2), 1, 0;
        ps_sub c, a, b;
        psq_st c, 8(pOut), 1, 0;
    }
#else
    pOut->x = p1->x - p2->x;
    pOut->y = p1->y - p2->y;
    pOut->z = p1->z - p2->z;
#endif
    return pOut;
}

inline VEC3* VEC3Scale(register VEC3* pOut, const register VEC3* p, register f32 scale)
{
#if defined(NW4R_MATH_BROADWAY)
    register f32 a, b;
    asm
    {
        psq_l    a, 0(p), 0, 0;
        ps_muls0 b, a, scale;
        psq_st   b, 0(pOut), 0, 0;

        psq_l    a, 8(p), 1, 0;
        ps_muls0 b, a, scale;
        psq_st   b, 8(pOut), 1, 0;
    }
#else
    pOut->x = p->x * scale;
    pOut->y = p->y * scale;
    pOut->z = p->z * scale;
#endif
    return pOut;
}

inline f32 VEC3Dot(const register VEC3* p1, const register VEC3* p2)
{
#if defined(NW4R_MATH_BROADWAY)
    register f32 _v1, _v2, _v3, _v4, _v5;
    asm
    {
        psq_l   _v2, 4(p1), 0, 0;
        psq_l   _v3, 4(p2), 0, 0;
        ps_mul  _v2, _v2, _v3;

        psq_l   _v5, 0(p1), 1, 0;
        psq_l   _v4, 0(p2), 1, 0;

        ps_madd _v3, _v5, _v4, _v2;
        ps_sum0 _v1, _v3, _v2, _v2;
    }
    return _v1;
#else
    return p1->x * p2->x + p1->y * p2->y + p1->z * p2->z;
#endif
}

inline f32 VEC3LenSq(const register VEC3* p)
{
#if defined(NW4R_MATH_BROADWAY)
    register f32 vxy, vzz, sqmag;

    asm
    {
        // load X | Y
        psq_l       vxy, 0(p), 0, 0
        // XX | YY
        ps_mul      vxy, vxy, vxy
        // load Z | Z
        lfs         vzz, 8(p)
        // XX + ZZ | YY + ZZ
        ps_madd     sqmag, vzz, vzz, vxy
        ps_sum0     sqmag, sqmag, vxy, vxy
    }

    return sqmag;
#else
    return p->x * p->x + p->y * p->y + p->z * p->z;
#endif
}

#if defined(NW4R_MATH_BROADWAY)
#define NW4R_VECCROSS      PSVECCrossProduct
#define NW4R_VECMAG        PSVECMag
#define NW4R_VECNORMALIZE  PSVECNormalize
#define NW4R_VECSQDIST     PSVECSquareDistance
#else
#define NW4R_VECCROSS      C_VECCrossProduct
#define NW4R_VECMAG        C_VECMag
#define NW4R_VECNORMALIZE  C_VECNormalize
#define NW4R_VECSQDIST     C_VECSquareDistance
#endif

inline VEC3* VEC3Cross(VEC3* pOut, const VEC3* p1, const VEC3* p2) { NW4R_VECCROSS(*p1, *p2, *pOut); return pOut; }

VEC3* VEC3Maximize(VEC3* pOut, const VEC3* p1, const VEC3* p2);
VEC3* VEC3Minimize(VEC3* pOut, const VEC3* p1, const VEC3* p2);

inline VEC3& VEC3::operator+=(const VEC3& rhs) { (void)VEC3Add(this, this, &rhs); return *this; }
inline VEC3& VEC3::operator-=(const VEC3& rhs) { (void)VEC3Sub(this, this, &rhs); return *this; }
inline VEC3& VEC3::operator*=(f32 f) { (void)VEC3Scale(this, this, f); return *this; }
inline VEC3 VEC3::operator+(const VEC3& rhs) const { VEC3 tmp; (void)VEC3Add(&tmp, this, &rhs); return tmp; }
inline VEC3 VEC3::operator-(const VEC3& rhs) const { VEC3 tmp; (void)VEC3Sub(&tmp, this, &rhs); return tmp; }

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

// PAL: 0x80085b80
MTX44* MTX44Copy(MTX44*, MTX44*);

inline VEC3*
VEC3Transform(VEC3* pOut, const MTX34* pM, const VEC3* pV) { PSMTXMultVec(*pM, *pV, *pOut); return pOut; }
inline VEC3*
VEC3TransformSR(VEC3* pOut, const MTX34* pM, const VEC3* pV) { MTXMultVecSR(*pM, *pV, *pOut); return pOut; }

VEC3* VEC3TransformNormal(VEC3* pOut, const MTX34* pM, const VEC3* pV);

} // namespace math
} // namespace nw4r
