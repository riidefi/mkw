
#pragma once

#include <rk_types.h>

namespace GeoObj {

/// has its update function called each frame
#define GEOOBJ_KIND_UPDATE 1
/// has its update function called each frame
#define GEOOBJ_KIND_DEBUG_DRAW 2
#define GEOOBJ_KIND_4 4

class ObjBase {
public:
  // signatures TBA
  virtual ~ObjBase();
  virtual void setup();
  /// Use GX for custom drawing on the screen
  virtual void drawDebug();
  /// calculates model position
  virtual void calc();
  virtual void vf18();
  /// updates model matrices
  virtual void update();
  virtual void init() = 0;

  virtual void getId();
  virtual void getName();
  virtual u32 getKindFlags();
  virtual void getOrigin();
  virtual void getResources();
  virtual void getModelName();
  virtual void getLowModelName();
  virtual void getShadowModelName();

  virtual void loadGraphics();
  virtual void loadResources();
  virtual void loadResources2(); // overload?
  virtual void loadShadowModel();
  virtual void initSoundActor();
  virtual void initRenderGroup();
  virtual void loadAnims();
  virtual void loadCollision() = 0;
  virtual void loadRoute();
  virtual void initModels();

  virtual void updateModelMatrix();
  virtual void updateShadow();
  virtual void updateCollision() = 0;
  virtual void updateModelScale();
  virtual void updateShadowScale();

  virtual void vf80();
  virtual void vf84();
  virtual void vf88();
  virtual void vf8c();

  virtual void disableCollision();
  virtual void enableCollision();

  virtual void getDrawInfo();
  virtual void getPosition();
  virtual void calcCollision();
  virtual void isLodDisabled();
  virtual void vfa8();
  virtual void vfac();
  virtual void getDrawType();
 
  u8 _4[0xa4 - 0x4];
  u32 managerIdx;
};
}
