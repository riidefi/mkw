#pragma once

#include <rk_types.h>

namespace EGG {

//! Boyer-moore-horspool SZS encoder
//! @returns compressed size
int encodeSZS(const u8* src, u8* dst, int srcSize);

} // namespace EGG
