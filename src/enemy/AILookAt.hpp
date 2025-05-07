#pragma once

#include "AIInfo.hpp"
#include "util/State.hpp"
#include <egg/math/eggVector.hpp>

namespace Enemy {

    struct AILookAtNextInfo {
        AI* mpNextPlayer;
        s32 mIsBeingBumped;
    };

    struct struct_101 {
        AIInfo* mpInfo;
        s32 field_0x04;
        s32 field_0x08;
        s32 field_0x0C;
        f32 field_0x10;
    };

    struct AILookAt: public Util::StateSequencer<AILookAt> {
        virtual ~AILookAt();
        void registerBump(const EGG::Vector3f&, const AI&);

        Util::State<AILookAt> mStateRaceStart;
        Util::State<AILookAt> mStateIdle;
        Util::State<AILookAt> mStateLookBehindOnBlockLine;
        Util::State<AILookAt> mStateNearbyPlayer;
        Util::State<AILookAt> mStateOvertake;
        Util::State<AILookAt> mStateLookBehind;
        Util::State<AILookAt> mStateBeingBumped;
        Util::State<AILookAt> mStateInkApplied;
        Util::State<AILookAt> mStateDontLookAtCamera;
        Util::State<AILookAt> mStateLookAtCamera;
        AIInfo* mpInfo;
        AILookAtNextInfo* mpNextInfo;
        AI* mpLookAtTarget;
        u32 mTimeUntilStopLookingAtCamera;
        f32 mHeadRotationSpeed;
        s32 mPlayerLookingAtIdx;
        struct_101* field_0x208;
        bool mbIsBeingBumped;
        EGG::Vector3f bumpDirection;
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
