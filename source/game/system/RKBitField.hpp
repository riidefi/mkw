
#pragma once

#define NBITS32 32

#include "rk_types.h"

template <size_t N>
class RKBitField {
public:
    RKBitField() {
        for (int i = 0; i < sizeof(mFields) / sizeof(mFields[0]); ++i) {
            mFields[i] = 0;
        }
    }

    bool on(size_t n) const {
        return mFields[n / NBITS32] & (1 << (n % NBITS32));
    }

    void set(size_t n) { mFields[n / NBITS32] |= (1 << (n % NBITS32)); }
    void reset(size_t n) { mFields[n / NBITS32] &= ~(1 << (n % NBITS32)); }
    u32& field(size_t n) { return mFields[n]; }

private:
    u32 mFields[(((u32)(N) + 32 - 1) & ~( 32 - 1)) / NBITS32];
};
