#pragma once

#include "AIInfo.hpp"
#include "AIControl.hpp"
#include "AISpeed.hpp"
#include "AIItem.hpp"
#include "AITrickHandler.hpp"
#include "AILookAt.hpp"
#include "system/CourseMap.hpp"
#include "system/State.hpp"
#include <rk_types.h>

namespace Enemy {

    struct AIEngine: public System::StateSequencer {
        AIEngine();
        virtual ~AIEngine();
        virtual void onOutOfBounds(const System::MapdataJugemPoint&);
        void endRace();
        void forceRecalculation(s32);

        System::State mStateReady;
        System::State mStateRunCPU;
        System::State mStateRunHuman;
        System::State mStateGhostIdle;
        System::State mStateAfterGoal;  // The racer will keep moving on goal
        System::State mStateStop;       // Used in Battles and Tournaments. The racer will stop moving on goal
        AIInfo* mpAIInfo;
        AIControlBase* mpAIControl;
        AISpeedBase* mpAISpeed;
        AIItemBase* mpItem;
        System::KPadRaceInputState* mInput;
        AITrickHandler* mpTrickHandler;
        AILookAt* mpLookAt;
        s32 field_0x15C;
        bool mbForceRecalculation;
        bool mbForcingRecalculation;
        bool mbDisableForceRecalculation;
        bool mbMatchEnded;
    };

    struct AIEngineKart : public AIEngine {
        AIEngineKart();
        ~AIEngineKart();
    };

    struct AIEngineBike : public AIEngine {
        AIEngineBike();
        ~AIEngineBike();
    };

} // namespace Enemy
