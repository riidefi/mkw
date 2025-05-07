#pragma once

#include "AIInfo.hpp"
#include "AIRank.hpp"

namespace Enemy {

    struct AIParamSpeed {
        f32 mSpeedAdvantage;
        f32 mSpeedBias;
        f32 mBaseSpeed;
    };

    struct AISpeedBase {
        virtual ~AISpeedBase();
        virtual void init();
        virtual void update();
        virtual void updateAfterGoal();
        virtual f32 vf_0x18();

        AIInfo* mpInfo;
        AIParamSpeed* mpParamSpeed;
        f32 field_0x0C;
        f32 mRankManagerSpeedAdvantage;
    };

    struct AISpeedBattle: public AISpeedBase {
        ~AISpeedBattle();
        void init();
        void update();
    };

    struct AISpeedBossRace: public AISpeedBase {
        ~AISpeedBossRace();
        void init();
        void update();

        AIRank* mpRank;
        AIRank* mpHumanPlayerRank;
    };

    struct AISpeedDemo: public AISpeedBase {
        ~AISpeedDemo();
        void init();
        void update();
    };

    struct AISpeedRace: public AISpeedBase {
        ~AISpeedRace();
        void init();
        void update();
        void updateAfterGoal();

        AIRank* mpRank;
        f32 field_0x18;
        f32 field_0x1C;
        f32 field_0x20;
        f32 field_0x24;
        f32 field_0x28;
    };

}
