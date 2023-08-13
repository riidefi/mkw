/*!
 * @file RKSceneManager.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggSceneManager.hpp>

namespace System {

class RKSceneManager : EGG::SceneManager {
public:
    virtual void calc();             // [vt+0x08]
    virtual void draw();             // [vt+0x0c]
    virtual void calcCurrentFader(); // [vt+0x14]
    virtual void doCalcFader();      // [vt+0x24]
    virtual void doDrawFader();      // [vt+0x28]
};
}
