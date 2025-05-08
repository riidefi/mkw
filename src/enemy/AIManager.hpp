#pragma once

#include "AIInfo.hpp"
#include "AIRank.hpp"
#include "AISpeed.hpp"
#include <egg/core/eggDisposer.hpp>
#include <rk_common.h>

namespace Enemy {

    class AIManagerEx {
        public:
            virtual ~AIManagerEx();
    };

    class AIManager: public AIManagerEx, public EGG::Disposer {
        public:
            static AIManager* createInstance();
            static void destroyInstance();
            static inline AIManager* getInstance() { return spInstance; }
            u32 getRandU32(u32);
            f32 getRandF32(f32);
            inline AIRankManager* getRankManager() { return mpRankManager; }

        private:
            AIManager();
            virtual ~AIManager();

            static AIManager* spInstance;

            s32 mPlayerCount;
            s32 mEngineClass;
            s32 mCpuMode;
            bool mbIsTimeTrials;
            AI* mpCpuPlayers[MAX_PLAYER_COUNT];
            AI* mpRealPlayers[MAX_PLAYER_COUNT];
            AIRankManager* mpRankManager;
    };

}
