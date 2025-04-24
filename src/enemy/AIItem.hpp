#pragma once

#include "AIInfo.hpp"
#include "system/State.hpp"

namespace Enemy {

    struct AIItemBase: public System::StateSequencer {
        virtual ~AIItemBase();

        System::State mStateIdle;
        System::State mStateStock;
        System::State mStateThrowDefault;
        System::State mStateKinoko;
        System::State mStateThrowFront;
        System::State mStateThrowBack;
        System::State mStateHold;
        System::State mStateGoal;
        AIInfo* mpAIInfo;
        s32 mItemHoldState;
        bool mbUseItem;
        bool mbIsTimeToHold;
        bool mbImmediatlyThrowItemBackwards;
        s32 mItemThrowDirection;

        enum eItemHoldState {
            NO_ITEM = 0,
            HAS_ITEM = 1,
            THROW_ITEM = 2
        };
    
        enum eItemThrowDirection {
            DEFAULT = 0,
            THROW_FORWARDS = 1,
            THROW_BACKWARDS = 2
        };
    };

    struct AIItemRace: public AIItemBase {
        ~AIItemRace();

        u32 mDelayTimeBeforeUsingItem;
        bool mbIsGoal;
    };
    
}
