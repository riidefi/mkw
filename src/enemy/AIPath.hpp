#pragma once

#include <rk_types.h>

namespace Enemy {

    struct PointParam {
        virtual ~PointParam();

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
