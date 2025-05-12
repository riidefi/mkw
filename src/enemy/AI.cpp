#include "AI.hpp"
#include "kart/KartInput.hpp"
#include "kart/KartState.hpp"
#include "system/RaceConfig.hpp"
#include "system/CourseMap.hpp"
#include <egg/core/eggHeap.hpp>

namespace Enemy {

AI::AI(bool isBike) {
    mpEngine = nullptr;
    mFlags = 0;
    mTeam = -1;

    switch (isBike) {
        case false:
            mpEngine = new AIEngineKart(*this);
            break;

        case true:
            mpEngine = new AIEngineBike(*this);
            break;
    }
}

AI::~AI() {
    delete mpEngine;
    mpEngine = nullptr;
}

void AI::init() {
    mCpuStick.y = 0.0f;
    mCpuStick.x = 0.0f;
    mFlags = 0;

    if (isTeamsEnabled()) {
        s32 team = System::RaceConfig::spInstance->mRaceScenario.getPlayerTeam(getPlayerIdx());

        if (team == System::BATTLE_TEAM_RED) {
            mTeam = System::BATTLE_TEAM_RED;
        }
        else if (team == System::BATTLE_TEAM_BLUE) {
            mTeam = System::BATTLE_TEAM_BLUE;
        }
    }

    mpEngine->init();
}

void AI::update() {
    mFlags = 0;

    /**
     * Avoid updating the AI engine if there are no CPU points in the course.
     *
     * This has the side effect of making the characters not look at other racers
     * due to `AILookAt` not being updated.

     * This is also the reason why Miis won't look at the camera when finishing some
     * competitions / tournaments, as said functionality is controlled by `AILookAt` as well.
     * This function is also not called when playing online matches, so characters won't look 
     * at other racers there either, plus Miis won't look at the camera during Live View.
     * 
     * Characters are still able to look at course objects, though, since in those cases
     * it's the object's code the one that requests characters to look at them.
     */
    System::MapdataEnemyPathAccessor* enemyPathAccessor = System::CourseMap::instance()->getEnemyPathAccessor();
    s32 updateEngine = false;
    if (enemyPathAccessor != nullptr && enemyPathAccessor->size() != 0) {
        updateEngine = true;
    }

    if (updateEngine) {
        mpEngine->update(enemyPathAccessor);
    }
}

const EGG::Vector2f& AI::getStick() const {
    if (isCpu()) {
        return mCpuStick;
    }
    
    return getInput().currentInputState.mStick;
}

bool AI::isCPU() {
    return System::RaceConfig::spInstance->mRaceScenario.getPlayerType(getPlayerIdx()) == System::RaceConfig::Player::TYPE_CPU;
}

bool AI::isRealLocal() {
    return System::RaceConfig::spInstance->mRaceScenario.getPlayerType(getPlayerIdx()) == System::RaceConfig::Player::TYPE_REAL_LOCAL;
}

bool AI::isRealLocalAndCPU() {
    if (System::RaceConfig::spInstance->mRaceScenario.getPlayerType(getPlayerIdx()) == System::RaceConfig::Player::TYPE_REAL_LOCAL) {
        if (isCpu()) {
            return true;
        }
    }
    
    return false;
}

bool AI::isAICPU() {
    return isCpu();
}

bool AI::isGhost() {
    return System::RaceConfig::spInstance->mRaceScenario.getPlayerType(getPlayerIdx()) == System::RaceConfig::Player::TYPE_GHOST;
}

bool AI::isSameTeam(const AI& other) {
    if (mTeam < 0) {
        return false;
    }

    return mTeam == other.mTeam;
}

void AI::endRace() {
    mpEngine->endRace();
}

void AI::onOutOfBounds(const System::MapdataJugemPoint& respawnPoint) {
    mpEngine->onOutOfBounds(respawnPoint);
}

void AI::forceRecalculation(bool activateForceRecalculation) {
    mpEngine->forceRecalculation(activateForceRecalculation);
}

void AI::handleBump(const EGG::Vector3f& bumpDirection, const AI& other) {
    EGG::Vector3f bodyForward;
    f32 alignment;
    f32 alignmentSign;
    f32 alignmentFactor;

    // [alignmentMin, alignmentMax, offsetRateMin, offsetRateMax]
    static f32 alignmentParameters[] = {
        5.0f, 15.0f, -500.0f, -650.0f
    };
    f32* alignmentParametersPtr = alignmentParameters;
    
    if (isCpu()) {
        getBodyForward(bodyForward);
        alignment = bodyForward.x * bumpDirection.x + bodyForward.y * bumpDirection.y + bodyForward.z * bumpDirection.z;
        if (alignment > 0.0f) {
            alignmentSign = 1.0f;  // Bump is from the front
        }
        else {
            alignmentSign = -1.0f; // Bump is from the back
        }
        
        alignmentFactor = (fabsf(alignment) - alignmentParametersPtr[0]) / (alignmentParametersPtr[1] - alignmentParametersPtr[0]);
        if (alignmentFactor > 1.0f) {
            alignmentFactor = 1.0f;
        }
        else if (alignmentFactor < 0.0f) {
            alignmentFactor = 0.0f;
        }
        
        f32 offsetRate = alignmentParametersPtr[2] + (alignmentFactor * (alignmentParametersPtr[3] - alignmentParametersPtr[2]));
        mpEngine->mpControl->mpPathHandler->addOffsetRateAndRecalcTargetTrans(offsetRate * alignmentSign);
    }

    mpEngine->mpLookAt->registerBump(bumpDirection, other);
}

bool Enemy::AI::isOnGround() {
    return kartState()->on(Kart::KART_FLAG_TOUCHING_GROUND);
}

bool Enemy::AI::isAllWheelsCollision() {
    return kartState()->on(Kart::KART_FLAG_ALL_WHEELS_COLLISION);
}

bool Enemy::AI::isDriftingOnGround() {
    return kartState()->on(Kart::KART_FLAG_DRIFTING_ON_GROUND);
}

bool Enemy::AI::isHopping() {
    return kartState()->on(Kart::KART_FLAG_HOPPING);
}

bool Enemy::AI::isAutoDrift() {
    return kartState()->on(Kart::KART_FLAG_AUTO_DRIFT);
}

bool Enemy::AI::isInBullet() {
    return kartState()->on(Kart::KART_FLAG_IN_BULLET);
}

}
