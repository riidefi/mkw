#pragma once
#include "KartObjectProxy.hpp"
#include "KartWheelPhysics.hpp"

namespace Kart {
    f32 rateForward = 0.1f;
    f32 wheelColForceFactor = 10.0f;
    f32 wheelHitboxHeight = 100.0f;
    f32 forwardFactor = 0.3f;
    f32 respawnSuspLimit = 1.0f;
    f32 disableSuspForceVerticalXV = 5.0f;
    f32 unk_suspSpeedRate = 0.3f;
enum KartWheelType {
    KART_WHEEL_KART_LEFT,
    KART_WHEEL_KART_RIGHT,
    KART_WHEEL_BIKE,
    };
      
class KartSusPhysics : public KartObjectProxy {
    public:
        virtual ~KartSusPhysics() {}
    
        KartSusPhysics(u32 wheelIdx, KartWheelType wheelType, s32 bspWheelIdx);
        void reset();
        void init();
        void setInitialState();
        void calc(const EGG::Vector3f& forward, const EGG::Vector3f& vehicleMovement);
        void calcCollision(const EGG::Vector3f& gravity, const EGG::Matrix34f& mtx, f32 dt);
    
    private:
    public:
        BspWheel* bspWheel;
        KartWheelPhysics* wheelPhysics;
    private:
        KartWheelType wheelType;
        u32 bspWheelIdx;
        u32 wheelIdx;
        // topmost point of the suspension the wheel can reach
        EGG::Vector3f suspTop;
        // bsp max suspension travel after vehicle scale is applied
        f32 maxTravelScaled;
        bool hasFloorCol;
        s16 _36;
        f32 _38;
        EGG::Vector3f downDir;
    };
    static_assert(sizeof(KartSusPhysics) == 0x48);

}
