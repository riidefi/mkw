// credits: kiwi
// https://github.com/kiwi515/ogws/blob/master/include/egg/math/eggMatrix.h

#ifndef EGG_MATH_MATRIX_H
#define EGG_MATH_MATRIX_H

#include "egg/math/eggVector.hpp"
#include "egg/math/eggQuat.hpp"

namespace EGG
{
    struct Matrix33f
    {
        f32& operator()(int i, int j) { return tbl[i][j]; }

        f32 tbl[3][3];
    };

    struct Matrix34f
    {
        Matrix34f() {}
        Matrix34f(f32, f32, f32, f32,
            f32, f32, f32, f32,
            f32, f32, f32, f32);

        void makeZero()
        {
	    for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 4; j++) {
                    tbl[i][j] = 0.0f;
                }
            }
        }

        void inverseToC(Matrix34f& inv) const;
        void makeIdentity();
        void makeQ(const Quatf&);
        void makeS(const Vector3f&);
        void setAxisRotation(const Vector3f &, f32);
        void loadPosMtx(u32);

        f32& operator()(int i, int j) { return tbl[i][j]; }

	friend Vector3f operator*(const Matrix34f& M, const Vector3f& v) {
	    Vector3f out;
	    const float vecX = v.x;
	    const float vecY = v.y;
	    const float vecZ = v.z;
	    out.x = (vecX * M.tbl[0][0]) + (vecY * M.tbl[0][1]) + (vecZ * M.tbl[0][2]);
	    out.y = (vecX * M.tbl[1][0]) + (vecY * M.tbl[1][1]) + (vecZ * M.tbl[1][2]);
	    out.z = (vecX * M.tbl[2][0]) + (vecY * M.tbl[2][1]) + (vecZ * M.tbl[2][2]);
	    return out;
	}

        f32 tbl[3][4];

        static Matrix34f ident;
    };
}

#endif
