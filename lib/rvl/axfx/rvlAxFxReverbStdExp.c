#include "rvlAxFxReverbStdExp.h"

#include <string.h>
#include <math.h>

#include <rvl/os/osInterrupt.h>

#include "axfx.h"

const f32 unk_80388580 = 32000.0f;
const f32 unk_80388584 = 0.0f;
const f32 unk_80388588 = 1.0f;
const f32 unk_8038858c = 0.6f;
sdata2_ps_f32 unk_80388590 = {176.0f, -0.0f};
const f32 unk_80388598 = -0.33f;
const f32 unk_8038859c = 0.33f;
sdata2_ps_f32 unk_803885a0 = {-3.0f, 0.0f};
sdata2_ps_f32 unk_803885a8 = {2.5625f, 0.0f};
sdata2_ps_f32 unk_803885b0 = {0.95f, 0.0f};
sdata2_ps_f32 unk_803885b8 = {176.0f, 0.0f};

u32 AXFXReverbStdExp__EarlySizeTable[8] = {163, 317, 479,  641,
                                           797, 967, 1123, 1283};

u32 AXFXReverbStdExp__FilterSizeTable[7][4] = {
    {1789, 1999, 433, 149}, {149, 293, 251, 103},   {947, 1361, 433, 137},
    {1279, 1531, 509, 149}, {1531, 1847, 563, 179}, {1823, 2357, 571, 137},
    {1823, 2357, 571, 179}};
