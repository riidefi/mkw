// credits: kiwi
// https://github.com/kiwi515/ogws/blob/master/include/egg/math/eggMatrix.h

#ifndef EGG_MATH_MATRIX_H
#define EGG_MATH_MATRIX_H

#include "egg/math/eggVector.hpp"
#include "egg/math/eggQuat.hpp"

namespace EGG
{
    struct Matrix33f : public nw4r::math::MTX33
    {
        f32& operator()(int i, int j) { return mtx[i][j]; }
    };

    struct Matrix34f : public nw4r::math::MTX34
    {
        Matrix34f() {}
        Matrix34f(f32, f32, f32, f32,
            f32, f32, f32, f32,
            f32, f32, f32, f32);

        void makeZero()
        {
	    for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 4; j++) {
                    mtx[i][j] = 0.0f;
                }
            }
        }

        void inverseToC(Matrix34f& inv) const;
        void makeIdentity();
        void makeQ(const Quatf&);
        void makeQT(const Quatf&, const Vector3f&);
        void makeS(const Vector3f&);
        void makeR(const Vector3f&);
        void setAxisRotation(const Vector3f &, f32);
	EGG::Vector3f multVector(const EGG::Vector3f&) const;
	// Defined inline and emitted in KartWheelPhysics
	EGG::Vector3f multVector33(const EGG::Vector3f&) const NEVER_INLINE;
        void loadPosMtx(u32);

        f32& operator()(int i, int j) { return mtx[i][j]; }

	friend Vector3f operator*(const Matrix34f& M, const Vector3f& v) {
	    Vector3f out;
	    const float vecX = v.x;
	    const float vecY = v.y;
	    const float vecZ = v.z;
	    out.x = (vecX * M.mtx[0][0]) + (vecY * M.mtx[0][1]) + (vecZ * M.mtx[0][2]);
	    out.y = (vecX * M.mtx[1][0]) + (vecY * M.mtx[1][1]) + (vecZ * M.mtx[1][2]);
	    out.z = (vecX * M.mtx[2][0]) + (vecY * M.mtx[2][1]) + (vecZ * M.mtx[2][2]);
	    return out;
	}

        //f32 tbl[3][4];

        static Matrix34f ident;
    };
inline Vector3f operator*(f32 lhs, const Vector3f& rhs) {return Vector3f(lhs*rhs.x, lhs*rhs.y, lhs*rhs.z);}

class Matrix34f_aligned8 : public Matrix34f {} __attribute__ ((aligned (8)));;
}

#endif
