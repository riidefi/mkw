
#include "ObjBase.hpp"

namespace GeoObj {
class ObjDrivable : public ObjBase {
public:
  virtual ~ObjDrivable();

  // signatures TBA
  virtual void vfb4() = 0;
  virtual void initCollision();
  virtual void registerBoxColUnit();

  virtual bool checkPointPartial() = 0;
  virtual bool checkPointPartialPush() = 0;
  virtual bool checkPointFull() = 0;
  virtual bool checkPointFullPush() = 0;

  virtual bool checkSpherePartial() = 0;
  virtual bool checkSpherePartialPush() = 0;
  virtual bool checkSphereFull() = 0;
  virtual bool checkSphereFullPush() = 0;

  virtual bool narrowScopeLocal() = 0;

  virtual bool checkPointCachedPartial() = 0;
  virtual bool checkPointCachedPartialPush() = 0;
  virtual bool checkPointCachedFull() = 0;
  virtual bool checkPointCachedFullPush() = 0;

  virtual bool checkSphereCachedPartial() = 0;
  virtual bool checkSphereCachedPartialPush() = 0;
  virtual bool checkSphereCachedFull() = 0;
  virtual bool checkSphereCachedFullPush() = 0;

  virtual void vf104();
  virtual void vf108();
  virtual void vf10c();
  virtual void vf110();
  virtual void vf114();
  virtual void vf118();
  virtual void vf11c();
};
}
