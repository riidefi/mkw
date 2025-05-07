#pragma once

#include <rk_types.h>

namespace Enemy {

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
        virtual bool shouldEndDrift();      // Real name: `isEndDrift`
        virtual bool shouldForbidDrift();   // Real name: `isDisableDrift`
        virtual bool shouldForceDrift();    // Real name: `isContinueDrift`
        virtual bool isKinokoK();
        virtual bool vf_0x30();
        virtual bool driftNotForbidden();   // Real name: `isAbleToMiniTurbo`
        virtual bool isEflag2();
        virtual bool isEflag3();
        virtual bool isEflag4();

        u32 mParam1;    // From ENPT Settings
        u32 mParam2;    // From ENPT Settings
        u32 mEflags;    // From ENPT Settings
        f32 field_0x10;
    };

    struct AIPathPoint {
        u8 field_0x00[0x44];
    };

    struct AIPathHandler {
        virtual ~AIPathHandler();
        void addOffsetRateAndRecalcTargetTrans(f32);
        bool isSwitchingPath();
        
        bool mbIsSwitchingPath;
        PointParam* field_0x08;
        PointParam* field_0x0C;
        PointParam* field_0x10;
        AIPathPoint* field_0x14;
        s32 field_0x18;
        bool field_0x1C;
        bool field_0x20;
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

}
