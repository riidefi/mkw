#pragma once

#include "AIInfo.hpp"
#include "AIControl.hpp"
#include "AISpeed.hpp"
#include "AIItem.hpp"
#include "AITrickHandler.hpp"
#include "AILookAt.hpp"
#include "system/CourseMap.hpp"
#include "util/State.hpp"

namespace Enemy {

    struct AI;

    struct AIEngine: public Util::StateSequencer<AIEngine> {
        AIEngine(const AI&);
        virtual ~AIEngine();
        virtual void init();
        virtual void update(const System::MapdataEnemyPathAccessor*);
        virtual void onOutOfBounds(const System::MapdataJugemPoint&);
        void endRace();
        void forceRecalculation(bool);

        Util::State<AIEngine> mStateReady;
        Util::State<AIEngine> mStateRunCPU;
        Util::State<AIEngine> mStateRunHuman;
        Util::State<AIEngine> mStateGhostIdle;
        Util::State<AIEngine> mStateAfterGoal;  // The racer will keep moving on goal
        Util::State<AIEngine> mStateStop;       // Used in Battles and Tournaments. The racer will stop moving on goal
        AIInfo* mpInfo;
        AIControlBase* mpControl;
        AISpeedBase* mpSpeed;
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

    struct AIEngineKart: public AIEngine {
        AIEngineKart(const AI&);
        ~AIEngineKart();
    };

    struct AIEngineBike: public AIEngine {
        AIEngineBike(const AI&);
        ~AIEngineBike();
    };

} // namespace Enemy
