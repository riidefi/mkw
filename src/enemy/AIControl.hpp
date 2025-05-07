#pragma once

#include "util/State.hpp"

namespace Enemy {

    struct AIControlBase: public Util::StateSequencer<AIControlBase> {
        AIInfo* mpInfo;
        AIPathHandler* mpPathHandler;
        u8 field_0x40[32];
    };

}
