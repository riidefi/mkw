#include "AI.hpp"
#include "AIEngine.hpp"
#include "AIManager.hpp"
#include "AITrickHandler.hpp"
#include "AIProbability.hpp"
#include "AIControl.hpp"
#include "kart/KartState.hpp"

namespace Enemy {

struct_121::struct_121(s32 arg0) {
    field_0x00 = arg0;
}

struct_121::~struct_121() {}

void struct_121::vf_0x0C() {}

void struct_121::vf_0x10() {}

void AITrickHandler::avoidPow() {
    mpInfo->mpInput->setTrick(System::KPadRaceInputState::UP_TRICK);
}

bool AITrickHandler::isStartingAirborne() {
    Kart::KartState* state = mpInfo->mpAI->kartState();

    if (state->on(Kart::KART_FLAG_AIR_START) && !state->on(Kart::KART_FLAG_JUMPPAD) && !state->on(Kart::KART_FLAG_HIT_ITEM_OR_OBJ)) {
        return true;
    }
    
    return false;
}

bool AITrickHandler::shouldTrick() {
    AIProbabilityBase* probability = mpInfo->mpAI->mpEngine->mpControl->getAIProbability();

    if (isStartingAirborne() && probability->getTrick()) {
        return true;
    }
    
    return false;
}

AITrickHandler::AITrickHandler(AIInfo* info): mpInfo(info) {}

AITrickHandler::~AITrickHandler() {}

void AITrickHandler::vf_0x0C() {}

void AITrickHandler::calc() {
    update();
}

void AITrickHandler::disableWheelie() {}

void AITrickHandler::update() {
    if (shouldTrick()) {
        System::KPadRaceInputState* input = mpInfo->mpInput;
        
        const int kartTricks[2] = {
            System::KPadRaceInputState::UP_TRICK,
            System::KPadRaceInputState::DOWN_TRICK
        };
        
        int rand = AIManager::getInstance()->getRandU32(ARRAY_COUNT(kartTricks));
        input->setTrick(kartTricks[rand]);
    }
}

AITrickHandlerBike::AITrickHandlerBike(AIInfo* info): AITrickHandler(info) {}

AITrickHandlerBike::~AITrickHandlerBike() {}

void AITrickHandlerBike::vf_0x0C() {}

void AITrickHandlerBike::calc() {
    update();
    calcWheelie();
}

void AITrickHandlerBike::disableWheelie() {
    mbPerformWheelie = false;
}

void AITrickHandlerBike::calcWheelie() {
    AIProbabilityBase* probability = mpInfo->mpAI->mpEngine->mpControl->getAIProbability();
    AIPathHandler* pathHandler = mpInfo->mpPathHandler;

    if (pathHandler->isSwitchingPath()) {
        bool disableWheelie = false;

        AIRankManager* rankManager = AIManager::getInstance()->getRankManager();
        if (rankManager != nullptr) {
            if (rankManager->isStateSpeedAdvantage()) {
                disableWheelie = true;
            }
        }

        System::KPadRaceInputState* input = mpInfo->mpInput;

        if (pathHandler->field_0x0C->shouldWheelie() && probability->getWheelie() && !disableWheelie) {
            mbPerformWheelie = true;
        }

        if (pathHandler->field_0x0C->shouldEndWheelie()) {
            mbPerformWheelie = false;
            input->setTrick(System::KPadRaceInputState::DOWN_TRICK);
        }

        if (mbPerformWheelie) {
            input->setTrick(System::KPadRaceInputState::UP_TRICK);
        }
    }
}

void AITrickHandlerBike::update() {
    if (shouldTrick()) {
        System::KPadRaceInputState* input = mpInfo->mpInput;
        
        const int bikeTricks[4] = {
            System::KPadRaceInputState::UP_TRICK,
            System::KPadRaceInputState::DOWN_TRICK,
            System::KPadRaceInputState::LEFT_TRICK,
            System::KPadRaceInputState::RIGHT_TRICK,
        };
        
        int rand = AIManager::getInstance()->getRandU32(ARRAY_COUNT(bikeTricks));
        input->setTrick(bikeTricks[rand]);
    }
}

AITrickHandlerBikeUnused::AITrickHandlerBikeUnused(AIInfo* info): AITrickHandlerBike(info) {}

AITrickHandlerBikeUnused::~AITrickHandlerBikeUnused() {}

void AITrickHandlerBikeUnused::update() {
    if (shouldTrick()) {
        System::KPadRaceInputState* input = mpInfo->mpInput;

        input->setTrick(System::KPadRaceInputState::UP_TRICK);
    }
}

}
