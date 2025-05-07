#pragma once

#include "AIRank.hpp"
#include "AIPath.hpp"
#include "AIProbability.hpp"
#include "system/CourseMap.hpp"
#include "util/State.hpp"

namespace Enemy {

    struct AIControlBase: public Util::StateSequencer<AIControlBase> {
        AIControlBase();
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

        AIInfo* mpInfo;
        AIPathHandler* mpPathHandler;
        void* mpStuck;
        AIProbabilityBase* mpProbability;
        u8 field_0x44[28];
    };

}
