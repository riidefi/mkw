#pragma once

#include "AIInfo.hpp"
#include "AISpeed.hpp"

namespace Enemy {

    struct AIRankGroupBase;
    struct AISpeedBase;

    struct AIRank {
        virtual ~AIRank();
        virtual void init();
        virtual void update();

        AIInfo* mpInfo;
        AIRankGroupBase* mpRankGroup;
        AISpeedBase* mpSpeed;
        s32 mId;
        s32 mHumanPlayerInitialRank;
        s32 mHumanPlayerRank;   // The position rank of the human player at the start of the match - 1
        s32 targetRank;
        f32 field_0x1C;
        f32 distanceCompleted;
        f32 field_0x24;
    };

    struct AIRankGroupBase {
        virtual ~AIRankGroupBase();
        virtual void init();
        virtual s32 getGroupKind();
        virtual s32 getType();
        virtual void addMember(AIRank*);
        virtual void initChangeTargetRank();
        virtual void doChangeTargetRank();
        virtual void vf_0x24();
        virtual void vf_0x28();
        virtual void vf_0x2C();
        virtual u32 vf_0x30();
        virtual f32 vf_0x34();
        
        s32 mNumMembers;
        s32 mStartingRank;
        AIRank* mpMembers[3];
        s32 field_0x18;
        f32 field_0x1C;
        f32 field_0x20;
        f32 field_0x24;
        f32 field_0x28;
    };

    struct AIRankGroupBottom: public AIRankGroupBase {
        ~AIRankGroupBottom();
        void init();
        s32 getGroupKind();
        void vf_0x24();
        void vf_0x28();
        void vf_0x2C();
        u32 vf_0x30();
        f32 vf_0x34();
    };

    struct AIRankGroupMiddle: public AIRankGroupBase {
        ~AIRankGroupMiddle();
        void init();
        s32 getGroupKind();
        void initChangeTargetRank();
        void doChangeTargetRank();
        void vf_0x24();
        void vf_0x28();
        void vf_0x2C();
        u32 vf_0x30();
        f32 vf_0x34();
    };

    struct AIRankGroupTop: public AIRankGroupBase {
        ~AIRankGroupTop();
        void init();
        s32 getGroupKind();
        s32 getType();
        void initChangeTargetRank();
        void doChangeTargetRank();
        void vf_0x24();
        void vf_0x28();
        void vf_0x2C();
        u32 vf_0x30();
        f32 vf_0x34();

        s32 mType;

        enum eType {
            EASY = 1,
            NORMAL = 2,
            HARD = 3
        };
    };

}
