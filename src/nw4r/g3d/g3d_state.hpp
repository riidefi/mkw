// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/nw4r/g3d/g3d_state.h
// Decompiled by kiwi515.

#pragma once

#include <rvl/gx.h>

namespace nw4r {
namespace g3d {
namespace G3DState {

// PAL: 0x80064440
GXRenderModeObj& GetRenderModeObj();
void SetRenderModeObj(const GXRenderModeObj&);

} // namespace G3DState
} // namespace g3d
} // namespace nw4r
