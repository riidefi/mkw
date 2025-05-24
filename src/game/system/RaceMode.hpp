#pragma once

#include <rk_types.h>

namespace System {
class RaceManager;

struct RaceMode {
    virtual u32 canEndRace();
    RaceManager* raceManager;
};

class KrtFile;

struct RaceModeGrandPrix: public RaceMode {
    KrtFile* krtFile[1];

    u32 canEndRace();
    RaceModeGrandPrix(RaceManager* raceManager_);
};
}
