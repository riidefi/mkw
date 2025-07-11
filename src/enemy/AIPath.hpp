#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_common.h>

namespace Enemy {

    struct AIPathManager;

    struct PointParam {
        virtual ~PointParam();
        virtual bool shouldEnterRouteIfHasMushroom();
        virtual bool shouldUseMushroom();
        virtual bool shouldWheelie();
        virtual bool shouldEndWheelie();
        // Only used in the N64 Bowser's Castle competition,
        // in the ramps before the end of the ramp to ensure
        // the CPU is able to cross it
        virtual bool shouldHaveMinSpeedOf70();
        virtual bool shouldEndDrift();      // MK7 name: `isEndDrift`
        virtual bool shouldForbidDrift();   // MK7 name: `isDisableDrift`
        virtual bool shouldForceDrift();    // MK7 name: `isContinueDrift`
        virtual bool isKinokoK();
        virtual bool vf_0x30();
        virtual bool driftNotForbidden();   // MK7 name: `isAbleToMiniTurbo`
        virtual bool isEflag2() { return false; }
        virtual bool isEflag3() { return false; }
        virtual bool isEflag4() { return false; }

        s32 mParam1;    // From ENPT Settings
        s32 mParam2;    // From ENPT Settings
        s32 mEflags;    // From ENPT Settings
        f32 field_0x10;
    };

    struct DriveInfo {
        EGG::Vector3f field_0x00;
        f32 field_0x0C;
        f32 field_0x10;
        f32 field_0x14;
        f32 field_0x18;
        f32 field_0x1C;
        f32 field_0x20;
        bool mbShouldStartDrift;
        bool mbShouldEndDrift;
        bool mbShouldReleaseMiniturbo;
        u8 field_0x27;
        bool field_0x28;
        u8 field_0x29[3];
    };

    struct AIPathPointInfo {
        AIPathPointInfo();
        virtual ~AIPathPointInfo();

        AIPathManager* mpPathManager;
        s8 mStartingPoint;
        s8 mPointIdxLog[5];  // List of the last 5 enemy points that have been traversed
        s32 field_0x10;
        EGG::Vector3f mTargetTrans;
        f32 field_0x20;
        f32 field_0x24;
        f32 offsetRate;
        f32 field_0x2C;
        s32 mPlayerIdx;
    };

    struct AIPathPoint: public AIPathPointInfo {
        void* mpBattleSearcher;
        EGG::Vector3f field_0x38;
    };

    struct AIPathHandler {
        struct InitArg {
            f32 field_0x00;
            f32 field_0x04;
            f32 field_0x08;
            s32 field_0x0C;
            s32 field_0x10;
            u8 field_0x14;
            bool field_0x15;
        };

        virtual ~AIPathHandler();
        virtual void init(const InitArg&);
        void addOffsetRateAndRecalcTargetTrans(f32);
        // Returns `true` the moment a CPU goes from
        // one CPU point to the next one.
        bool isSwitchingPath();
        
        bool mbIsSwitchingPath;
        PointParam* mpPrevPointParam;
        PointParam* mpCurrPointParam;
        PointParam* mpNextPointParam;
        AIPathPoint* mpPathPoint;
        s32 field_0x18;
        bool field_0x1C;
        bool mbRacalcTargetTrans;
        bool field_0x21;
        bool mbInBullet;
        s32 field_0x24;
        s32 field_0x28;
        s32 field_0x2C;
        f32 field_0x30;
        f32 field_0x34;
        f32 field_0x38;
        f32 field_0x3C;
    };

    struct AIPathManager {
        AIPathManager();
        virtual ~AIPathManager();

        AIPathHandler* mpPlayers[MAX_PLAYER_COUNT];
        u32 mPlayerCount;
    };

    struct GoNextInfo {
        bool field_0x00;
        EGG::Vector3f field_0x04;
        u8 field_0x10;
        u8 field_0x11;
        s32 field_0x14;
        u32 field_0x18;
        bool field_0x1C;
        bool field_0x1D;
        bool mbInBullet;
        s32 mNextSearchMode;
        bool field_0x24;
        f32 field_0x28;

        enum eSearchMode {
            GO_TO_RANDOM_POINT         = 0,
            GO_TO_RANDOM_POINT_2       = 2,
            GO_TO_ITEM_POINT_HIGHEST   = 3,
            GO_TO_ITEM_POINT_LOWEST    = 4,
            GO_TO_FRIEND_POINT_HIGHEST = 5,
            GO_TO_RIVAL_POINT_HIGHEST  = 6,
            GO_TO_FRIEND_POINT_LOWEST  = 7,
            GO_TO_COIN_POINT_HIGHEST   = 8,
            GO_TO_NEAREST_TARGET       = 9,
            GO_TO_FARTHEST_TARGET      = 10
        };
    };

}
