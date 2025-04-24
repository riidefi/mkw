#pragma once

#include "AIInfo.hpp"
#include "system/State.hpp"
#include <egg/math/eggVector.hpp>

namespace Enemy {

    struct AILookAtNextInfo {
        AI* mpNextPlayer;
        s32 mIsBeingBumped;
    };

    struct struct_101 {
        AIInfo* mpAIInfo;
        s32 field_0x04;
        s32 field_0x08;
        s32 field_0x0C;
        f32 field_0x10;
    };

    struct AILookAt: public System::StateSequencer {
        virtual ~AILookAt();

        System::State mStateRaceStart;
        System::State mStateIdle;
        System::State mStateLookBehindOnBlockLine;
        System::State mStateNearbyPlayer;
        System::State mStateOvertake;
        System::State mStateLookBehind;
        System::State mStateBeingBumped;
        System::State mStateInkApplied;
        System::State mStateDontLookAtCamera;
        System::State mStateLookAtCamera;
        AIInfo* mpAIInfo;
        AILookAtNextInfo* mpNextInfo;
        AI* mpLookAtTarget;
        u32 mTimeUntilStopLookingAtCamera;
        f32 mHeadRotationSpeed;
        s32 mPlayerLookingAtIdx;
        struct_101* field_0x208;
        bool mbIsBeingBumped;
        EGG::Vector3f field_0x210;
    };

    struct AILookAtBattle: public AILookAt {
        ~AILookAtBattle();
    };

    struct AILookAtDemo: public AILookAt {
        ~AILookAtDemo();
    };

    struct AILookAtUnused: public AILookAt {
        ~AILookAtUnused();
    };

}
