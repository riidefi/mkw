#include "RaceManager.hpp"
#include "RaceConfig.hpp"

// .rodata
extern const f32 unused_80890148;
const f32 unused_80890148 = 5 / 3.0 * 1e-5;
extern const f32 unused_8089014c;
const f32 unused_8089014c = 0.001f;
const u32 lbl_80890150[] = {0x00000000};
const u32 lbl_80890154[] = {0xbf800000};
const u32 lbl_80890158[] = {0x3f8ccccd, 0x00000000};
const u32 lbl_80890160[] = {0x3f847ae1, 0x40000000};
const u32 lbl_80890168[] = {0x4156e378, 0xc0000000};
const u32 lbl_80890170[] = {0x43300000, 0x00000000};
const u32 lbl_80890178[] = {0x3f7fffef};
const u32 lbl_8089017c[] = {0x3f800000};
const u32 lbl_80890180[] = {0x42c80000};
const u32 lbl_80890184[] = {0x41880000};
const u32 lbl_80890188[] = {0x378bcf65};
const u32 lbl_8089018c[] = {0x3a83126f};
const u32 lbl_80890190[] = {0xbf19999a};
const u32 lbl_80890194[] = {0x3f19999a};
const u32 lbl_80890198[] = {0x3f733333};
const u32 lbl_8089019c[] = {0xbf733333};
const u32 lbl_808901a0[] = {0x43300000, 0x80000000};
const u32 lbl_808901a8[] = {0x3f7fff58};
const u32 lbl_808901ac[] = {0xbf000000};
const u32 lbl_808901b0[] = {0x3089705f};
const u32 lbl_808901b4[] = {0x476a6000};
const u32 lbl_808901b8[] = {0x447a0000};
const u32 lbl_808901bc[] = {0x3f000000};
const u32 lbl_808901c0[] = {0x3727c5ac};
const u32 lbl_808901c4[] = {0x4e6e6b28, 0x3727c5ac, 0x00060000,
                            0x3f7fff58, 0x00000000, 0x40590000,
                            0x00000000, 0x3f847ae1, 0x40000000};
const u32 lbl_808901e8[] = {0x2f72616e, 0x6b74696d, 0x6547502e, 0x6b727400,
                            0x2f72616e, 0x6b74696d, 0x6547502e, 0x6b727400,
                            0x2f6d696e, 0x6967616d, 0x652e6b6d, 0x67000000};

// .data
#pragma explicit_zero_data on
/*
u32 lbl_808b32b0[] = {0x00000000, 0x00000000, 0x00000000};
void (*jtbl_808b32bc[])() = {
    jump_805321cc, jump_80532220, jump_80532444, jump_80532254,
    jump_80532248, jump_80532444, jump_80532444, jump_805322c8,
    jump_805322c8, jump_805323e0, jump_805323e0,
};

void (*jtbl_808b32e8[])() = {
    jump_80536540, jump_80536540, jump_80536494, jump_80536328, jump_805364a4,
    jump_80536494, jump_80536540, jump_80536540, jump_80536540, jump_80536328,
    jump_80536328, jump_80536450, jump_80536484,
};

void (*jtbl_808b331c[])() = {
    jump_805367f4, jump_805367f4, jump_805367ec, jump_80536618, jump_80536738,
    jump_805367ec, jump_805367f4, jump_805367f4, jump_805367f4, jump_80536618,
    jump_80536618, jump_805367b8, jump_805367e4,
};

u32 lbl_808b3350[] = {0x00000000, 0x00000000, (u32)&unk_80532e3c, 0x00000000};
u32 lbl_808b3360[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053266c, (u32)&unk_805371e8,
                      (u32)&unk_8053724c, (u32)&unk_805372b4};
u32 lbl_808b3378[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053262c, (u32)&unk_805372bc,
                      (u32)&unk_80537320, (u32)&unk_80537388};
u32 lbl_808b3390[] = {0x00000000,         0x00000000,
                      (u32)&unk_805325ac, (u32)&unk_80537390,
                      (u32)&unk_805373f4, (u32)&unk_8053745c};
u32 lbl_808b33a8[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053256c, (u32)&unk_80537464,
                      (u32)&unk_805374c8, (u32)&unk_80537530};
u32 lbl_808b33c0[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053252c, (u32)&unk_80537538,
                      (u32)&unk_8053759c, (u32)&unk_80537604};
u32 lbl_808b33d8[] = {0x00000000, 0x00000000, (u32)&unk_805325ec,
                      0x00000000, 0x00000000, 0x00000000};
u32 lbl_808b33f0[] = {0x00000000,         0x00000000,
                      (u32)&unk_805326ac, (u32)&unk_8053760c,
                      (u32)&unk_80537670, (u32)&unk_805376d8};
u32 lbl_808b3408[] = {0x00000000, 0x00000000, (u32)&unk_805324ec,
                      0x00000000, 0x00000000, 0x00000000};
u32 lbl_808b3420[] = {
    0x00000000,         0x00000000,         (u32)&unk_80536054,
    (u32)&unk_80535de8, (u32)&unk_80535e84, (u32)&unk_805336d8,
    (u32)&unk_80535ef4, (u32)&unk_8053308c, (u32)&unk_80533be8,
    (u32)&unk_80533c34, (u32)&unk_805371a4};
u32 lbl_808b344c[] = {
    0x00000000,         0x00000000,         (u32)&unk_80535f28,
    (u32)&unk_80535de8, (u32)&unk_80535fe4, (u32)&unk_805336d8,
    (u32)&unk_80535ef4, (u32)&unk_8053308c, (u32)&unk_80533be8,
    (u32)&unk_80533c34, (u32)&unk_805371a4};
u32 lbl_808b3478[] = {
    0x00000000,         0x00000000,         (u32)&TimeAttackGamemode_canEndRace,
    (u32)&unk_80535de8, (u32)&unk_80535e84, (u32)&unk_805336d8,
    (u32)&unk_80535ef4, (u32)&unk_8053308c, (u32)&unk_80533be8,
    (u32)&unk_80533c34, (u32)&unk_805371a4};
u32 lbl_808b34a4[] = {0x00000000, 0x00000000, (u32)&RaceinfoPlayer_destroy};
u32 lbl_808b34b0[] = {0x00000000, 0x00000000, (u32)&unk_805376e0,
                      (u32)&unk_80535864, (u32)&unk_80535904};
u32 lbl_808b34c4[] = {0x00000000, 0x00000000, (u32)&unk_80532de0,
                      (u32)&unk_80532d44, (u32)&unk_805336a0};
u32 lbl_808b34d8[] = {0x00000000, 0x00000000, (u32)&unk_805371a8,
                      0x00000000, 0x00000000, 0x00000000};
                      */
#pragma explicit_zero_data off

// .bss
u8 spInstance__Q26System11RaceManager[8];


namespace System {
KrtFile** RaceManager::getKrtFile() {
    KrtFile** files;

    if (RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode != RaceConfig::Settings::GAMEMODE_GRAND_PRIX) {
        return nullptr;
    }
    else {
        RaceModeGrandPrix* raceModeGP = (RaceModeGrandPrix*) raceMode;
        files = raceModeGP->krtFile;
        return (files[0] != nullptr) ? files : nullptr;
    }
}
}

// needs KartObjectManager definitions
#ifdef WIP_DECOMP
namespace System {
void RaceManagerPlayer::updateGpRankScore() {
    s32 raceStarRankScore = 0;
    s32 krtTime = 0;
    KrtFile** krtFile = nullptr;
    
    // Get ranktimeGP.krt
    krtFile = RaceManager::spInstance->getKrtFile();

    if ((krtFile == nullptr) || (RaceConfig::spInstance->mRaceScenario.getPlayer(idx).getPlayerType() != RaceConfig::Player::TYPE_REAL_LOCAL)) {
        unk34 = 7;
    }
    else {
        // Get course time limit from ranktimeGP
        s32 engineClass = RaceConfig::spInstance->mRaceScenario.mSettings.getEngineClass();
        s32 courseId = RaceConfig::spInstance->mRaceScenario.mSettings.getCourseId();
        krtTime = (*krtFile != nullptr) ? (*krtFile)->entries[courseId][RaceConfig::spInstance->mRaceScenario.mSettings.getEngineClass()] : 0;

        // Calculate time bonus
        // s32 raceStarRankScore = 0;
         raceStarRankScore += 1000.0f * (krtTime - frameCounter) / krtTime;
        // Calculate time bonus corresponding to the time spent in 1st place
        s32 firstPlaceTimeBonus = framesInFirstPlace * 150 / krtTime;
        // Add time bonus
        raceStarRankScore += firstPlaceTimeBonus;

        // Add bonus for successfull rocket start
        if (Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->startBoostSuccessful) {
            raceStarRankScore += 25;
        }
        
        u16 miniturbos = Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->miniturbos;
        raceStarRankScore += (miniturbos * 2);
        
        u16 hitOthersWithItemsCount = Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->raceStats->hitOthersWithItemsCount;
        raceStarRankScore += (hitOthersWithItemsCount * 5);
        
        raceStarRankScore -= (Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->offroad / 3);
        
        u16 numWallCollision = Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->numWallCollision;
        raceStarRankScore -= (numWallCollision * 20);
        
        u16 numObjectCollision = Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->numObjectCollision;
        raceStarRankScore -= (numObjectCollision * 30);
        
        u16 outOfBounds = Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->outOfBounds;
        raceStarRankScore -= (outOfBounds * 70);

        s8 playerInputIdx = RaceConfig::spInstance->mRaceScenario.getPlayer(idx).getPlayerInputIdx();
        
        // Add bonus for playing using the Wii Wheel
        if (playerInputIdx != -1) {
            Controller* controller = InputManager::spInstance->playerInputs[(u8) playerInputIdx].raceController;

            u32 controllerType = (controller != nullptr) ? controller->getType() : CONTROLLER_TYPE_UNKNOWN;
            if (controllerType == CONTROLLER_TYPE_WII_WHEEL) {
                raceStarRankScore += 10;
            }
        }

        // Add bonus for using Automatic drift
        if (playerInputIdx != -1) {
            Controller* controller = InputManager::spInstance->playerInputs[(u8) playerInputIdx].raceController;

            bool usingAutomaticDrift = (controller != nullptr) ? controller->driftIsAuto : false;
            if (usingAutomaticDrift) {
                raceStarRankScore += 25;
            }
        }

        // Add unknown bonus
        u16 field_0x18 = Kart::KartObjectManager::spInstance->getObject(idx)->mAccessor->settings->gpStats->field_0x18;
        raceStarRankScore += field_0x18;

        // Clamp the start rank score
        if (raceStarRankScore < -50) {
            raceStarRankScore = -50;
        }
        if (raceStarRankScore > 250) {
            raceStarRankScore = 250;
        }

        // Save the new star rank score
        RaceConfig::spInstance->mMenuScenario.getPlayer(idx).mGpStarRankScore += (s16) raceStarRankScore;
    }
}
}
#endif
