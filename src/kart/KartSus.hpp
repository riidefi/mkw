#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80598b08..0x80598b50
UNKNOWN_FUNCTION(KartSus_ct);
// PAL: 0x80598b50..0x80598b60
UNKNOWN_FUNCTION(unk_80598b50);
// PAL: 0x80598b60..0x80598bd4
UNKNOWN_FUNCTION(KartSus_init);
// PAL: 0x80598bd4..0x80598bdc
UNKNOWN_FUNCTION(KartSus_initPhysics);
// PAL: 0x80598bdc..0x80598be4
UNKNOWN_FUNCTION(unk_80598bdc);
// PAL: 0x80598be4..0x80598bec
UNKNOWN_FUNCTION(tire0_set_initial_physics_values);
// PAL: 0x80598bec..0x80598fe8
UNKNOWN_FUNCTION(unk_80598bec);
// PAL: 0x80598fe8..0x80598ff8
UNKNOWN_FUNCTION(unk_80598fe8);
// PAL: 0x80598ff8..0x80599124
UNKNOWN_FUNCTION(unk_80598ff8);
// PAL: 0x80599124..0x80599134
UNKNOWN_FUNCTION(unk_80599124);
// PAL: 0x80599134..0x8059938c
UNKNOWN_FUNCTION(unk_80599134);
// PAL: 0x8059938c..0x805993cc
UNKNOWN_FUNCTION(unk_8059938c);
// PAL: 0x805993cc..0x8059940c
UNKNOWN_FUNCTION(unk_805993cc);

#ifdef __cplusplus
}
#endif

#include "KartPart.hpp"

namespace Kart {
class KartSus {

};
}
