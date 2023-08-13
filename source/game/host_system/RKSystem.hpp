/*!
 * @file RKSystem.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggAsyncDisplay.hpp>
#include <egg/core/eggSystem.hpp>
#include <game/host_system/RKSceneManager.hpp>

namespace System {

class RKSystem : EGG::BaseSystem {
public:
    static RKSystem* sInstance;

    u8 _24[0x28];
    EGG::AsyncDisplay* mAsyncDisplay;
    u32 _50;
    RKSceneManager* mSceneMgr;
};
}
