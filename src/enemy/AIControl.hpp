#pragma once

#include "AIRank.hpp"
#include "AIPath.hpp"
#include "AIProbability.hpp"
#include "system/CourseMap.hpp"
#include "util/State.hpp"

namespace Enemy {

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
        void* field_0x154;
        void* mpPowAvoider;
        s32 field_0x5C;
    };

    struct AIControlDemo: public AIControlBase {
        AIControlDemo(const AIInfo&);
        ~AIControlDemo();
        void init();
        void update();
        void initAfterManager();
        void stateInitStart();
        void stateStart();
        void stateInitRun();
        void stateRun();
        void stateInitEnd();
        void stateEnd();

        Util::State<AIControlDemo> mStateInit;
        Util::State<AIControlDemo> mStateRun;
        Util::State<AIControlDemo> mStateEnd;
        s32 mTimeUntilStateRun;
    };

}
