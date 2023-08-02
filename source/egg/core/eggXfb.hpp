#pragma once

#include <rk_types.h>

#include <decomp.h>

namespace EGG {

class Xfb {
static int calcXfbSize(int, int);
};

}

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80244160..0x802441ec
UNKNOWN_FUNCTION(__ct__Q23EGG3XfbFPQ23EGG4Heap);
// PAL: 0x802441ec..0x80244200
UNKNOWN_FUNCTION(calcXfbSize__Q23EGG3XfbFii);

#ifdef __cplusplus
}
#endif
