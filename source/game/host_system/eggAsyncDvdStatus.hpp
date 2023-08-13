/*!
 * @file eggAsyncDvdStatus.hpp
 * @brief 
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

namespace EGG {

class AsyncDvdStatus {
public:
    static AsyncDvdStatus* sInstance;

    void halt();
    void printError();

    u8 _00[0x51];
    u8 _51;
};
}
