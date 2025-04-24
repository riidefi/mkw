#pragma once

#include "AIEngine.hpp"
#include "kart/KartObjectProxy.hpp"
#include <egg/math/eggVector.hpp>

namespace Enemy {

    struct AI : public Kart::KartObjectProxy {
        enum eFlags {
            AI_FLAG_BLOCK_LINE = (1 << 0),
            AI_FLAG_LOOK_BACK_WHILE_BLOCKING_LINE = (1 << 2),
            AI_FLAG_PLAY_WIN_ANIMATION_DURING_CUTSCENE = (1 << 3),
        };

        AI(s32);
        virtual ~AI();
        void init();
        void update();
        const EGG::Vector2f& getStick() const;  
        bool isCPU();
        bool isRealLocal();
        bool isRealLocalAndCPU();
        bool isAICPU();
        bool isGhost();
        bool isSameTeam(const AI&);
        void endRace();
        void onOutOfBounds(const System::MapdataJugemPoint&);
        void forceRecalculation(s32);
        bool fn_1_216018();
        bool isAllWheelsCollision();
        bool isOnGround();
        bool isDriftingOnGround();
        bool isHopping();
        bool isAutoDrift();
        bool isInBullet();

        AIEngine* mpEngine;
        EGG::Vector2f mStick;
        u32 mFlags;
        u32 mTeam;
    };

} // namespace Enemy
