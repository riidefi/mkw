#pragma once

#include "AI.hpp"
#include "AIPath.hpp"
#include "system/KPadController.hpp"

namespace Enemy {

    class AI;

    struct AIInfo {
        AI* mpAI;
        System::KPadRaceInputState* mpInput;
        AIPathHandler* mpPathHandler;
        u16 mActions;
        f32 mStickX;
    };

}
