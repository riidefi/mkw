#include "pad.h"

#include <math.h>

static const PADClampRegion PADClampRegionV1 = {
    30, 180, 15, 72, 47, 15, 59, 37, 62, 50,
};

static const PADClampRegion PADClampRegionV2 = {
    0, 180, 0, 87, 62, 0, 74, 52, 80, 68,
};

// Clamps a Vec2 into a circle with bounds min <= len(vec) <= r
void PAD_ClampCircle(s8* outX, s8* outY, s8 r, s8 min) {
  int x = *outX;
  int y = *outY;
  int mag;
  int len;
  if (-min < x && x < min) {
    x = 0;
  } else if (0 < x) {
    x -= min;
  } else {
    x += min;
  }
  if (-min < y && y < min) {
    y = 0;
  } else if (0 < y) {
    y -= min;
  } else {
    y += min;
  }
  mag = x * x + y * y;
  if (r * r < mag) {
    len = (int)sqrtf(mag);
    x = (x * r) / len;
    y = (y * r) / len;
  }
  *outX = (s8)x;
  *outY = (s8)y;
}

// Clamps a value to min <= value <= max.
static inline void PAD_ClampTrigger(u8* out, u8 min, u8 max) {
  if (*out <= min) {
    *out = 0;
  } else {
    if (max < *out) {
      *out = max;
    }
    *out -= min;
  }
}

// PADClampCircle clamps stick, substick and both triggers.
void PADClampCircle(PADStatus* status) {
  int i;
  for (i = 0; i < 4; i++, status++) {
    if (status->err != 0) {
      continue;
    }
    PAD_ClampCircle(&status->stickX, &status->stickY, 56, 15);
    PAD_ClampCircle(&status->substickX, &status->substickY, 44, 15);
    PAD_ClampTrigger(&status->triggerL, 30, 180);
    PAD_ClampTrigger(&status->triggerR, 30, 180);
  }
}

// PADClampCircle2 clamps circles of all controllers.
void PADClampCircle2(PADStatus* status, u32 type) {
  const PADClampRegion* region;
  int i;
  for (i = 0; i < 4; i++, status++) {
    if (status->err != 0) {
      continue;
    }
    if (type == 2) {
      region = &PADClampRegionV1;
    } else {
      region = &PADClampRegionV2;
    }
    PAD_ClampCircle(&status->stickX, &status->stickY, region->stickRad,
                    region->stickMin);
    PAD_ClampCircle(&status->substickX, &status->substickY, region->substickRad,
                    region->substickMin);
  }
}
