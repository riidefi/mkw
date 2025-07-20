#pragma once

#include "AIRank.hpp"
#include "AIPath.hpp"
#include "AIProbability.hpp"
#include "system/CourseMap.hpp"
#include "util/State.hpp"

namespace Enemy {

    // This struct tracks the current airtime of a CPU
    // and it also starts a small countdown everytime the CPU
    // lands on the ground after being airborne for 20 frames.
    // While this runs in the background during matches, the game
    // doesn't seem to use it for anything.
    struct AIAirtimeTracker {
        inline AIAirtimeTracker(const AIInfo&);
        virtual ~AIAirtimeTracker();
        virtual void init(s32);
        virtual void update();
        bool isCurrentGroundStartTimerZero();

        AIInfo* mpInfo;
        s32 mInitialGroundStartTimer;   // Initial countdown time set when landing.
        s32 mAirtime;
        s32 mCurrentGroundStartTimer;   // Current countdown time.
    };

    // This struct manages the probability of a CPU avoiding the POW block,
    // and is also in charge of avoiding it when said probability passes.
    struct AIPowAvoider {
        inline AIPowAvoider(const AIInfo&);
        virtual ~AIPowAvoider();
        virtual void init();
        virtual void update();
        inline bool isSameTeam(s32);

        AIInfo* mpInfo;
        s32 mAvoidChance;   // How likely the CPU is going to avoid the POW block.
    };

    struct AIControlBase: public Util::StateSequencer<AIControlBase> {
        AIControlBase(const AIInfo&);
        virtual ~AIControlBase();
        virtual void init();
        virtual void update();
        virtual void onRaceStart();
        virtual void initAfterManager();
        virtual void setStartDashTypeToKart();
        virtual void onOutOfBoundsInner(const System::MapdataJugemPoint&);
        virtual void onForceRecalculation(const EGG::Vector3f&);
        virtual void onPlayerGoal();
        virtual void onCpuGoal();
        virtual AIRank* getAIRank();
        virtual void* getAIBlockLine();
        virtual AIProbabilityBase* getAIProbability();
        virtual void vf_0x48();
        virtual void setBattleType();
        virtual void setAIRankTopOfPlayer();
        virtual void setDoNotSelectBackward();
        virtual void isAllStopAfterGoal();
        virtual void doUpdate_(const DriveInfo&);
        virtual void setBasicDriveInfo_(const DriveInfo&);

        AIInfo* mpInfo;
        AIPathHandler* mpPathHandler;
        void* mpStuck;
        AIProbabilityBase* mpProbability;
        void* mpAutoSteer;
        void* mpDriftDrive;
        DriveInfo* mpDriveInfo;
        AIAirtimeTracker* mpAirtimeTracker;
        AIPowAvoider* mpPowAvoider;
        s32 field_0x5C;
    };

    struct AIControlDemo: public AIControlBase {
        AIControlDemo(const AIInfo&);
        ~AIControlDemo();
        void init();
        void update();
        void initAfterManager();
        virtual void stateInitStart();
        virtual void stateStart();
        virtual void stateInitRun();
        virtual void stateRun();
        virtual void stateInitEnd();
        virtual void stateEnd();

        Util::State<AIControlDemo> mStateInit;
        Util::State<AIControlDemo> mStateRun;
        Util::State<AIControlDemo> mStateEnd;
        s32 mTimeUntilStateRun;
    };

}
