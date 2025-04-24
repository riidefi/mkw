#pragma once

#include "AI.hpp"
#include "AIPath.hpp"
#include "system/KPadController.hpp"
#include <rk_types.h>

class AI;

namespace Enemy {

    struct AIInfo {
        AI* mpAI;
        System::KPadRaceInputState* mpInput;
        AIPathHandler* mpPathHandler;
        u16 mActions;
        f32 mStickX;
    };

}
