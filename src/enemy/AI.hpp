#pragma once

#include "kart/KartObjectProxy.hpp"
#include "system/CourseMap.hpp"
#include <egg/math/eggVector.hpp>

extern bool isTeamsEnabled();
extern bool FUN_80739880();     // Cutscene-related. Always returns `false` in the final game.

namespace Enemy {

    struct AIEngine;

    struct AI: public Kart::KartObjectProxy {
        enum eFlags {
            AI_FLAG_BLOCK_LINE = (1 << 0),
            AI_FLAG_LOOK_BACK_WHILE_BLOCKING_LINE = (1 << 2),
            AI_FLAG_PLAY_WIN_ANIMATION_DURING_CUTSCENE = (1 << 3),
        };

        AI(bool);
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
        void forceRecalculation(bool);
        void handleBump(const EGG::Vector3f&, const AI&);
        bool isOnGround();
        bool isAllWheelsCollision();
        bool isDriftingOnGround();
        bool isHopping();
        bool isAutoDrift();
        bool isInBullet();

        AIEngine* mpEngine;
        EGG::Vector2f mCpuStick;
        u32 mFlags;
        s32 mTeam;
    };

} // namespace Enemy
