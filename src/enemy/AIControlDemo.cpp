#include "AI.hpp"
#include "AIControl.hpp"
#include "AIEngine.hpp"
#include "AIItem.hpp"
#include "kart/KartMove.hpp"
#include "kart/KartState.hpp"
#include "system/RaceConfig.hpp"

f32 lbl_1_data_17660 = 1000.0f;

namespace Enemy {

AIControlDemo::AIControlDemo(const AIInfo& info): AIControlBase(info) {
    mTimeUntilStateRun = 0;
    mpProbability = new AIProbabilityDemo();
    mStateInit.setFunctions(this, stateInitStart, stateStart, nullptr);
    mStateRun.setFunctions(this, stateInitRun, stateRun, nullptr);
    mStateEnd.setFunctions(this, stateInitEnd, stateEnd, nullptr);
}

AIControlDemo::~AIControlDemo() {}

void AIControlDemo::init() {
    AIControlBase::init();
    field_0x5C = 0;

    AIProbabilityDemo* probability = static_cast<AIProbabilityDemo*>(mpProbability);
    probability->determineIfCanMiniturbo();
   
    // Ensure that we're currently on a cutscene environment.
    if (FUN_80739880() ||
        System::RaceConfig::spInstance->mRaceScenario.mSettings.mCameraMode == System::RaceConfig::Settings::CAMERA_MODE_GRAND_PRIX_WIN ||
        System::RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode == System::RaceConfig::Settings::GAMEMODE_CREDITS) {
            initAfterManager();
            setNextState(reinterpret_cast<Util::State<AIControlBase>*>(&mStateInit));
    }
    else {
        reset();
    }
}

void AIControlDemo::initAfterManager() {
    AIPathHandler::InitArg initArg;

    AIControlBase::initAfterManager();
    initArg.field_0x10 = 2;
    initArg.field_0x00 = 0.0f;
    initArg.field_0x04 = 0.0f;
    initArg.field_0x08 = lbl_1_data_17660;
    initArg.field_0x0C = 0;
    initArg.field_0x14 = 0;
    initArg.field_0x15 = false;
    mpPathHandler->init(initArg);
}

void AIControlDemo::update() {
    Util::StateSequencer<AIControlBase>* state = this;
    state->update();
}

void AIControlDemo::stateInitStart() {
    mTimeUntilStateRun = mpInfo->mpPathHandler->mpPrevPointParam->mParam1 * 30;
    mpInfo->mpAI->shouldVanishPlayer(true);
}

void AIControlDemo::stateStart() {
    mTimeUntilStateRun--;
    
    if (mTimeUntilStateRun < 0) {
        setNextState(reinterpret_cast<Util::State<AIControlBase>*>(&mStateRun));
    }
}

void AIControlDemo::stateInitRun() {
    if (!mpInfo->mpAI->kartState()->on(Kart::KART_FLAG_HAS_STOPPED)) {
        mpInfo->mpAI->shouldVanishPlayer(false);
    }
}

void AIControlDemo::stateRun() {
    DriveInfo* driveInfo = mpDriveInfo;
    AIInfo* info = mpInfo;
    AI* ai = info->mpAI;
    AIPathHandler* pathHandler = info->mpPathHandler;
    
    driveInfo->field_0x00.z = 0.0f;
    driveInfo->field_0x00.y = 0.0f;
    driveInfo->field_0x00.x = 0.0f;
    driveInfo->field_0x0C = 0.0f;
    driveInfo->field_0x10 = 0.0f;
    driveInfo->field_0x14 = 1.0f;
    driveInfo->field_0x18 = 0.0f;
    driveInfo->field_0x20 = 0.0f;
    driveInfo->mbShouldStartDrift = false;
    driveInfo->mbShouldEndDrift = false;
    driveInfo->mbShouldReleaseMiniturbo = false;
    driveInfo->field_0x27 = 0;
    driveInfo->field_0x28 = false;

    setBasicDriveInfo_(*mpDriveInfo);
    doUpdate_(*mpDriveInfo);
    ai->kartMove()->setSpeed(pathHandler->mpNextPointParam->mParam1);

    if (pathHandler->mpCurrPointParam->isEflag2()) {
        ai->mFlags |= AI::AI_FLAG_PLAY_WIN_ANIMATION_DURING_CUTSCENE;
    }

    if (pathHandler->isSwitchingPath() && pathHandler->mpCurrPointParam->isEflag3()) {
        AIItemBase* item = ai->mpEngine->mpItem;
        item->mbUseItem = true;
        item->mItemThrowDirection = AIItemBase::THROW_FORWARDS;
    }

    if (pathHandler->isSwitchingPath() && pathHandler->mpCurrPointParam->isEflag4()) {
        setNextState(reinterpret_cast<Util::State<AIControlBase>*>(&mStateEnd));
    }
}

void AIControlDemo::stateInitEnd() {
    mpInfo->mpAI->shouldVanishPlayer(true);
}

void AIControlDemo::stateEnd() {}

}
