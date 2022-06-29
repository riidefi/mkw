#pragma once

#include <rk_types.h>

struct RaceConfigPlayer {
    u8 _00[0x08 - 0x00];
    u32 vehicleId;
    u32 characterId;
    u32 type;
    u8 _14[0xd0 - 0x14];
    s32 controllerId;
    u8 _d4[0xf0 - 0xd4];
};

struct RaceConfigScenario {
    u8 _000[0x004 - 0x000];
    u8 playerCount;
    u8 _005[0x008 - 0x005];
    RaceConfigPlayer players[12];
    // ...
};

struct RaceConfig {
    static RaceConfig* spInstance;
    u8 _0000[0x0020 - 0x0000];
    RaceConfigScenario raceScenario;
    // ...
};