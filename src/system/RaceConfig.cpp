#include "RaceConfig.hpp"

#pragma legacy_struct_alignment off

namespace System {
extern const f32 ZERO_FLOAT;
extern const CourseId COURSE_ORDER[8][4];
extern const u8 VS_POINT_DISTRIBUTION[12][12];
extern const s32 RANK_SCORES[5];
extern const u16 SCORES[4];
extern const s32 lbl_808900e8[15];
extern const char lbl_80890124[][0x12];

const f32 ZERO_FLOAT = 0;
const CourseId COURSE_ORDER[8][4] = {
    {LUIGI_CIRCUIT, MOO_MOO_MEADOWS, MUSHROOM_GORGE, TOADS_FACTORY},
    {MARIO_CIRCUIT, COCONUT_MALL, DK_SUMMIT, WARIOS_GOLD_MINE},
    {DAISY_CIRCUIT, KOOPA_CAPE, MAPLE_TREEWAY, GRUMBLE_VOLCANO},
    {DRY_DRY_RUINS, MOONVIEW_HIGHWAY, BOWSERS_CASTLE, RAINBOW_ROAD},
    {GCN_PEACH_BEACH, DS_YOSHI_FALLS, SNES_GHOST_VALLEY_2, N64_MARIO_RACEWAY},
    {N64_SHERBET_LAND, GBA_SHY_GUY_BEACH, DS_DELFINO_SQUARE,
     GCN_WALUIGI_STADIUM},
    {DS_DESERT_HILLS, GBA_BOWSER_CASTLE_3, N64_DKS_JUNGLE_PARKWAY,
     GCN_MARIO_CIRCUIT},
    {SNES_MARIO_CIRCUIT_3, DS_PEACH_GARDENS, GCN_DK_MOUNTAIN,
     N64_BOWSERS_CASTLE}};

const u8 __attribute__((force_export))
VS_POINT_DISTRIBUTION[12][12] = {{15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 9, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 9, 5, 2, 1, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 10, 6, 3, 1, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 10, 7, 5, 3, 1, 0, 0, 0, 0, 0, 0},
                                 {15, 11, 8, 6, 4, 2, 1, 0, 0, 0, 0, 0},
                                 {15, 11, 8, 6, 4, 3, 2, 1, 0, 0, 0, 0},
                                 {15, 12, 10, 8, 6, 4, 3, 2, 1, 0, 0, 0},
                                 {15, 12, 10, 8, 6, 5, 4, 3, 2, 1, 0, 0},
                                 {15, 12, 10, 8, 7, 6, 5, 4, 3, 2, 1, 0}};

const s32 RANK_SCORES[] = {1000, 700, 400, 200, 0};
const u16 SCORES[] = {60, 52, 40, 20};

// bss
RaceConfig* RaceConfig::spInstance;

extern "C" void getCompetitionWrapper(void*, CompetitionWrapper*);

RaceConfig::Player::Player()
    : _04(0), mLocalPlayerNum(-1), mPlayerInputIdx(-1),
      mVehicleId(STANDARD_KART_M), mCharacterId(MARIO),
      mPlayerType(TYPE_REAL_LOCAL), mMii(7), mControllerId(-1), _d4(8),
      mRating(), _ec(_ec & ~0x80) {}

void RaceConfig::Player::appendParamFile(RaceConfig* raceConfig) {
  raceConfig->append(mVehicleId, InitScene::spInstance->mHeapCollection
                                     .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mCharacterId, InitScene::spInstance->mHeapCollection
                                       .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mPlayerType, InitScene::spInstance->mHeapCollection
                                      .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mTeam, InitScene::spInstance->mHeapCollection
                                .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
}

s32 RaceConfig::Player::computeGpRank() const {
  s8 weightedRankScore = 5;
  for (u8 i = 0; i < sizeof(RANK_SCORES) / 4; i++) {
    if (mGpRankScore >= RANK_SCORES[i]) {
      weightedRankScore = i;
      break;
    }
  }

  s8 weightedScore = 4;
  for (u8 i = 0; i < sizeof(SCORES) / 2; i++) {
    if (mGpScore >= SCORES[i]) {
      weightedScore = i;
      break;
    }
  }

  if (weightedRankScore + weightedScore >= 8) {
    return 7;
  }

  return weightedRankScore + weightedScore;
}

RaceConfig::Scenario::Scenario(RawGhostFile* ghost)
    : mPlayerCount(0), mHudCount(0), mPlayers() {
  mSettings.mCourseId = GCN_MARIO_CIRCUIT;
  mSettings.mGameMode = Settings::GAMEMODE_GRAND_PRIX;
  mSettings.mCameraMode = Settings::CAMERA_MODE_GAMEPLAY_NO_INTRO;
  mSettings.mCupId = MUSHROOM_CUP;

  // seems dubious
  memset(&this->mCompetitionSettings, 0, sizeof(CompetitionSettings));

  mGhost = ghost;
}

RaceConfig::Player::~Player() {}

BattleTeam RaceConfig::Scenario::computeWinningTeam() {
  u16 results[] = {0, 0};

  for (u8 i = 0; i < RaceConfig::spInstance->mRaceScenario.mPlayerCount; i++) {
    const BattleTeam team = mPlayers[i].getTeam();
    results[team] += mPlayers[i].mPreviousScore;
  }

  return (results[0] < results[1]) ? BATTLE_TEAM_BLUE : BATTLE_TEAM_RED;
}

BattleTeam RaceConfig::Player::getTeam() { return mTeam; }

const RaceConfig::Player& RaceConfig::Scenario::getPlayer(u8 idx) const {
  return mPlayers[idx];
}

const u8 RaceConfig::getRacePlayerCount() {
  return RaceConfig::spInstance->mRaceScenario.mPlayerCount;
}

#pragma legacy_struct_alignment on
inline void as_scenarios(RaceConfig::Scenario& s1, RaceConfig::Scenario& s2) {
  s1 = s2;
}

void RaceConfig::init() {
  Player* player;
  mMenuScenario.mSettings.mCourseId = GCN_MARIO_CIRCUIT;
  mMenuScenario.mSettings.mGameMode = Settings::GAMEMODE_GRAND_PRIX;
  mMenuScenario.mSettings.mCameraMode = Settings::CAMERA_MODE_GAMEPLAY_NO_INTRO;
  mMenuScenario.mSettings.mCupId = MUSHROOM_CUP;
  mMenuScenario.mSettings.mEngineClass = 2;
  mMenuScenario.mSettings.mCpuMode = 1;
  mMenuScenario.mSettings.mModeFlags =
      (Settings::ModeFlags)(mMenuScenario.mSettings.mModeFlags & 0xfffffff8);

  for (u8 i = 0; i < MAX_PLAYER_COUNT; i++) {
    player = &mMenuScenario.getPlayer(i);
    player->mCharacterId = MARIO;
    player->mVehicleId = STANDARD_KART_M;
    player->mPlayerType = i != 0 ? Player::TYPE_CPU : Player::TYPE_REAL_LOCAL;
    player->mTeam = BATTLE_TEAM_NONE;
  }

  clear();
  mMenuScenario.appendParamFile(this);
  read(InitScene::spInstance->mHeapCollection
           .mpHeaps[HeapCollection::HEAP_ID_MEM2]); // ParamFile base function
  mMenuScenario.initRace(&mRaceScenario);
  as_scenarios(mRaceScenario, mMenuScenario);
  // mRaceScenario = mMenuScenario;
}

void RaceConfig::Player::setCharacter(CharacterId character) {
  mCharacterId = character;
}

RaceConfig::Player& RaceConfig::Scenario::getPlayer(u8 idx) {
  return mPlayers[idx];
}

void RaceConfig::Player::setVehicle(VehicleId vehicle) { mVehicleId = vehicle; }

void RaceConfig::Player::setPlayerType(Type playerType) {
  mPlayerType = playerType;
}

void RaceConfig::clear() {
  mMenuScenario.clear();
  mAwardsScenario.clear();
}

void RaceConfig::Player::reset(s8 pos) {
  mPreviousScore = 0;
  mGpRankScore = 0;
  mPrevFinishPos = pos;
  this->_e0 = pos;
}

void RaceConfig::Player::setPrevFinishPos(s8 pos) { mPrevFinishPos = pos; }

void RaceConfig::Player::setUnkPos(s8 pos) { this->_e0 = pos; }

void RaceConfig::Scenario::clear() {
  mSettings.mItemMode = 0;
  mSettings.mCpuMode = 1;
  mSettings.mLapCount = 3;
  mSettings.mEngineClass = 1;
  mSettings.mModeFlags =
      (Settings::ModeFlags)(mSettings.mModeFlags & 0xFFFFFFF8);

  for (u8 i = 0; i < 12; i++) {
    getPlayer(i).reset(i + 1);
  }

  mSettings.mRaceNumber = 0;
  mSettings.mLapCount = 3;
}

// 3 blr padding
void empty1() {}
void empty2() {}
void empty3() {}

u8 RaceConfig::Scenario::update() {
  if (mSettings.mRaceNumber < 100) {
    mSettings.mRaceNumber++;
  } else {
    mSettings.mRaceNumber = 0;
  }

  for (u8 i = 0; i < 12; i++) {
    Player& player = getPlayer(i);
    player.mPrevFinishPos = player.mFinishPos;
    player.mPreviousScore = player.mGpScore;
  }

  return mSettings.mRaceNumber;
}

s16 RaceConfig::updateRating(u8 playerIdx) {
  const u8 playerCount = RaceConfig::getRacePlayerCount();
  f32 totalPoints = ZERO_FLOAT;

  for (u8 i = 0; i < playerCount; i++) {
    if (playerIdx == i) {
      continue;
    }

    Player& player = RaceConfig::spInstance->mRaceScenario.getPlayer(playerIdx);
    totalPoints += player.mRating.calcNegPoints(
        RaceConfig::spInstance->mRaceScenario.getPlayer(i).mRating);
  }
  return totalPoints;
}


RaceConfig::Settings::CameraMode RaceConfig::Scenario::getCameraMode() {
  return mSettings.mCameraMode;
}

const RaceConfig::Player::Type RaceConfig::Player::getPlayerType() const {
  return mPlayerType;
}

bool RaceConfig::Scenario::initGhost(u8 playerIdx, s8 playerInputIdx) {
  bool ret = false;
  if (mGhost->isValid()) {
    GhostFile ghost;
    ghost.read(*mGhost);

    if (ghost.mCourseId == mSettings.mCourseId) {
      if (playerInputIdx >= 0) {
        KPadDirector::spInstance->setGhostController(
            playerInputIdx, (u16*)ghost.mInputs, ghost.mDriftIsAuto);
      }

      mPlayers[playerIdx].mCharacterId = (CharacterId)ghost.mCharacterId;
      mPlayers[playerIdx].mVehicleId = (VehicleId)ghost.mVehicleId;
      mPlayers[playerIdx].mPlayerInputIdx = playerInputIdx;
      mPlayers[playerIdx].mControllerId = ghost.mControllerId;
      ret = true;
    }
  }

  return ret;
}

void RaceConfig::Scenario::resetPlayers() {
  for (u8 i = 0; i < 12; i++) {
    Player& player = getPlayer(i);
    player.mLocalPlayerNum = -1;
    player.mPlayerInputIdx = -1;
  }

  for (u8 i = 0; i < 4; i++) {
    mSettings.mHudPlayerIds[i] = -1;
  }
}

void RaceConfig::Scenario::initPlayers(u8 playerCount) {
  u32 gamemode = mSettings.mGameMode;
  if (isOnline((Settings::GameMode)gamemode)) {
    return;
  }
  for (u8 i = 0; i < playerCount; i++) {
    Player& player = getPlayer(i);
    player.mPreviousScore = 0;
    player.mPrevFinishPos = playerCount - i;
    player._e0 = playerCount - i;
  }
}
}


#ifdef NON_MATCHING
namespace System {
void RaceConfig::Scenario::initControllers(u8 controllerCount) {
  Controller* controller;
  s32 controllerId;
  u8 localPlayerNum = 0;
  u8 playerInputIdx = 0;

  mSettings.mHudPlayerIds[0] = -1;
  mSettings.mHudPlayerIds[1] = -1;
  mSettings.mHudPlayerIds[2] = -1;
  mSettings.mHudPlayerIds[3] = -1;

  for (s32 i = 0; i < MAX_PLAYER_COUNT; i++) {
    switch (mPlayers[i].getPlayerType()) {
    case Player::TYPE_REAL_LOCAL:
      mPlayers[i].mLocalPlayerNum = localPlayerNum;
      mPlayers[i].mPlayerInputIdx = playerInputIdx;
      controller =
          KPadDirector::spInstance->playerInputs[playerInputIdx].controller;
      if (controller == nullptr) {
        controllerId = -1;
      } else {
        controllerId = controller->getControllerId();
      }
      mPlayers[i].mControllerId = controllerId;
      if (mSettings.mHudPlayerIds[localPlayerNum] == -1) {
        mSettings.mHudPlayerIds[localPlayerNum] = i;
      }
      localPlayerNum++;
      playerInputIdx++;
      break;
    case Player::TYPE_GHOST:
      if (initGhost(i, playerInputIdx)) {
        playerInputIdx++;
      } else {
        mPlayers[i].mPlayerType = Player::TYPE_NONE;
        mPlayers[i].mControllerId = -1;
      }
      break;
    case Player::TYPE_CPU:
      mPlayers[i].mControllerId = -1;
    }
  }

  // For spectating?
  for (s32 i = 0; i < MAX_PLAYER_COUNT; i++) {
    if (mPlayers[i].mPlayerType != Player::TYPE_NONE &&
        mPlayers[i].mLocalPlayerNum == -1) {
      s32 hudIdx = localPlayerNum;
      mPlayers[i].mLocalPlayerNum = localPlayerNum;
      localPlayerNum++;
      mSettings.mHudPlayerIds[hudIdx] = i;
      if (localPlayerNum >= controllerCount)
        break;
    }
  }
}
} // namespace System
#endif

namespace System {

void RaceConfig::Scenario::computePlayerCounts(u8& playerCount, u8& hudCount,
                                               u8& localPlayerCount) {
  u8 playerCount_ = 0;
  u8 hudCount_ = 0;
  u8 localPlayerCount_ = 0;

  for (u8 i = 0; i < 12; i++) {
    const Player::Type playerType = mPlayers[i].getPlayerType();

    // Check if player exists
    if (playerType == Player::TYPE_NONE) {
      continue;
    }
    playerCount_++;

    // Check if player is local
    if (playerType != Player::TYPE_REAL_LOCAL) {
      continue;
    }

    // Increment HUD count
    if (hudCount_ < 4) {
      hudCount_++;
    }

    localPlayerCount_++;
  }

  // Correct HUD counts
  if (hudCount_ == 0) {
    hudCount_ = 1;
  }
  if (hudCount_ == 3) {
    hudCount_ = 4;
  }

  // Set title screen HUD count
  const Settings::CameraMode cameraMode = mSettings.mCameraMode;
  if (cameraMode == Settings::CAMERA_MODE_TITLE_ONE_PLAYER) {
    hudCount_ = 1;
  } else if (cameraMode == Settings::CAMERA_MODE_TITLE_TWO_PLAYER) {
    hudCount_ = 2;
  } else if (cameraMode == Settings::CAMERA_MODE_TITLE_FOUR_PLAYER) {
    hudCount_ = 4;
  }

  // Cap player count on awards
  if (mSettings.mGameMode == Settings::GAMEMODE_AWARDS) {
    if (cameraMode == Settings::CAMERA_MODE_GRAND_PRIX_WIN) {
      // Cap player count on GP win
      if (3 < playerCount_) {
        playerCount_ = 3;
      }
    } else if (6 < playerCount_) {
      playerCount_ = 6;
    }
  }

  playerCount = playerCount_;
  hudCount = hudCount_;
  localPlayerCount = localPlayerCount_;
}

void RaceConfig::Scenario::initRng() {
  u32 seed;
  u32 mask;
  u32 mask1;
  u32 mask2;
  u32 mask3;
  u32 gamemode = mSettings.mGameMode;

  switch ((Settings::GameMode)gamemode) {
  case Settings::GAMEMODE_TIME_TRIAL:
  case Settings::GAMEMODE_MISSION_TOURNAMENT:
  case Settings::GAMEMODE_GHOST_RACE:
    mSettings.mSeed1 = 0x74a1b095;
    seed = OSGetTick();
    mask = (seed >> 27) & 0xFFFF;
    mask |= (seed >> 3) & 0x1FFF0000;
    mSettings.mSeed2 = mask;
    return;
  }

  if (mSettings.mModeFlags & Settings::MODE_FLAG_COMPETITION) {
    mSettings.mSeed1 = 0x92bc7d03;
    seed = OSGetTick();
    mask = ((seed >> 27) & 0xFFFF);
    mask |= ((seed >> 3) & 0x1fff0000);
    mSettings.mSeed2 = mask;
    return;
  }

  if (mSettings.mCameraMode == Settings::CAMERA_MODE_REPLAY) {
    return;
  }
  if (isOnline((Settings::GameMode)gamemode)) {
    return;
  }

  seed = OSGetTick();
  mask = (seed >> 7) & 0xff000000;
  mask1 = (seed >> 20) & 0xff;
  mask2 = (seed >> 20) & 0x00ff0000;
  mask3 = (seed >> 7) & 0xff00;

  mSettings.mSeed1 = (seed >> 8) | (seed << 24);
  mSettings.mSeed2 = mask1 | mask2 | mask | mask3;
}

const s32 lbl_808900e8[15] = {-1, -1, -1, 5, 6, 8,         9,      11,
                              -1, -1, -1, 1, 2, 0xc030005, 0x40000};

extern void* lbl_809c2144;

void RaceConfig::Scenario::initCompetitionSettings() {
  CompetitionSettings settings; // 0x28-0x98
  memset(&settings, 0, sizeof(CompetitionSettings));
  CompetitionWrapper wrapper; // 0x8-0x24
  wrapper.isValid = false;
  wrapper.fileRaw = (u32) nullptr;
  // lbl_809c2144 is ptrNwc24Manager
  getCompetitionWrapper(lbl_809c2144, &wrapper);
  RawCompetitionFile* file = wrapper.fileRaw;

  // TODO: enum of competition type
  if (!((s32)file->competitionType != 0 && (s32)file->competitionType != 1)) {
    // there might have been a debug log here or something?/
    return;
  } else {
    settings.field1_0x2 = lbl_808900e8[file->competitionType];
    settings.courseId = file->courseId;
    settings.engineClass = file->engineClass;
    settings.controllerRestriction = file->controllerRestriction;
    settings.field7_0x30[0] = file->score;
    settings.field7_0x30[1] = file->score;
    settings.field7_0x30[2] = file->score;
    settings.field7_0x30[3] = file->score;
    settings.field7_0x30[4] = file->score;
    settings.field7_0x30[5] = file->score;
    settings.cameraAngle = file->cameraAngle;
    settings.minimapObject = file->minimapObject;
    settings.field10_0x4c = file->field13_0x20;
    settings.field11_0x4e = file->field14_0x22;
    settings.cannonFlag = file->cannonFlag;
    settings.cpuCount = file->getSize();

    settings.cpuCombosFromWrapper(wrapper);

#ifdef __CWCC__
    __memcpy(&mCompetitionSettings, &settings, sizeof(settings));
#else
    memcpy(&mCompetitionSettings, &settings, sizeof(settings));
#endif
  }
}

void RaceConfig::Scenario::initRace(Scenario* scenario) {
  u8 playerCount = 0;
  u8 hudCount = 0;
  u8 localPlayerCount = 0;

  if (mSettings.mModeFlags & Settings::MODE_FLAG_COMPETITION) {
    initCompetitionSettings();
  }

  copyPrevPositions();

  for (u8 i = 0; i < 12; i++) {
    Player& player = getPlayer(i);
    player.mLocalPlayerNum = -1;
    player.mPlayerInputIdx = -1;
  }

  for (u8 i = 0; i < 4; i++) {
    mSettings.mHudPlayerIds[i] = -1;
  }

  computePlayerCounts(playerCount, hudCount, localPlayerCount);

  u8 hudCount_ = hudCount;
  if (mSettings.mCameraMode == Settings::CAMERA_MODE_GAMEPLAY_INTRO) {
    hudCount = 1;
  }

  if (mSettings.mRaceNumber == 0) {
    u8 playerCount_ = playerCount;
    u32 gamemode = mSettings.mGameMode;
    if (!isOnline((Settings::GameMode)gamemode)) {
      for (u8 i = 0; i < playerCount_; i++) {
        Player& player = getPlayer(i);
        player.mPreviousScore = 0;
        player.setPrevFinishPos(playerCount_ - i);
        player.setUnkPos(playerCount_ - i);
      }
    }
  }

  initControllers(hudCount);
  postInitControllers(scenario);
  initRng();

  mPlayerCount = playerCount;
  mHudCount = hudCount;
  mHudCount2 = hudCount_;
  mLocalPlayerCount = localPlayerCount;
}

#pragma dont_reuse_strings on
RaceConfig* RaceConfig::createInstance() {
  if (!spInstance) {
    spInstance = new RaceConfig();
  }

  return spInstance;
}

void RaceConfig::destroyInstance() {
  if (spInstance) {
    delete spInstance;
  }

  spInstance = nullptr;
}

RaceConfig::~RaceConfig() {}

RaceConfig::Scenario::~Scenario() {}

RaceConfig::RaceConfig()
    : ParameterFile("/boot/menuset.prm", 0), mRaceScenario(&mGhosts[0]),
      mMenuScenario(&mGhosts[1]), mAwardsScenario(nullptr) {
  RawGhostFile* it = mGhosts;
  do {
    it->reset();
    it++;
  } while (it < mGhosts + ARRAY_SIZE(mGhosts));
}

#pragma legacy_struct_alignment on
void RaceConfig::initRace() {
  mMenuScenario.initRace(&mRaceScenario);
  mRaceScenario = mMenuScenario;
}

RaceConfig::Scenario&
RaceConfig::Scenario::copy(const RaceConfig::Scenario& other) {
  mPlayerCount = other.mPlayerCount;
  mHudCount = other.mHudCount;
  mLocalPlayerCount = other.mLocalPlayerCount;
  mHudCount2 = other.mHudCount2;

  RaceConfig::Player* thisPlayer = mPlayers;
  const RaceConfig::Player* otherPlayer = other.mPlayers;
  RaceConfig::Player* end = mPlayers + MAX_PLAYER_COUNT;
  do {
    *thisPlayer = *otherPlayer;
    thisPlayer++;
    otherPlayer++;
  } while (thisPlayer < end);

  mSettings = other.mSettings;
#ifdef __CWCC__
  __memcpy(&mCompetitionSettings, &other.mCompetitionSettings,
           sizeof(CompetitionSettings));
#else
  memcpy(&mCompetitionSettings, &other.mCompetitionSettings,
         sizeof(CompetitionSettings));
#endif
  mGhost = other.mGhost;
  return *this;
}

} // namespace System

// Requires some inline-related pragma to be implemented correctly
// Scratch link: https://decomp.me/scratch/4L7ac
#ifdef EQUIVALENT
namespace System {

void RaceConfig::initAwards() {
  initRace();
  mAwardsScenario = mRaceScenario;

  for (u8 i = 0; i < 12; i++) {
    mMenuScenario.getPlayer(i)->setPlayerType(PLAYER_TYPE_NONE);
    mMenuScenario.getPlayer(i)->setPrevFinishPos(i + 1);
    mMenuScenario.getPlayer(i)->setUnkPos(i + 1);
  }

  bool isGpWin = mMenuScenario.getGameType() == GAMETYPE_GRAND_PRIX_WIN;
  bool isLoss = mMenuScenario.getGameType() == GAMETYPE_LOSS;
  bool isTeamMode = mMenuScenario.isTeamMode();

  if (isGpWin) {
    for (u8 i = 1; i <= 3; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType == PLAYER_TYPE_NONE) {
          continue;
        }

        u8 idx = i - 1;
        copy(i, j, idx);
        break;
      }
    }
  } else if (isTeamMode) {
    BattleTeam winningTeam = mRaceScenario.computeWinningTeam();
    BattleTeam winningTeam_ = (BattleTeam)(winningTeam == 0);
    for (u8 i = 0; i < getRacePlayerCount(); i++) {
      PlayerType playerType = mRaceScenario.getPlayer(i)->getPlayerType();
      if (playerType == PLAYER_TYPE_REAL_LOCAL) {
        BattleTeam playerTeam = mRaceScenario.getPlayer(i)->getTeam();
        if (winningTeam == playerTeam) {
          winningTeam_ = winningTeam;
          break;
        }
      }
    }

    u8 idx = 0;
    for (u8 i = 1; i <= 12; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType == PLAYER_TYPE_REAL_LOCAL) {
          BattleTeam playerTeam = mRaceScenario.getPlayer(j)->getTeam();
          if (winningTeam_ != playerTeam) {
            continue;
          }

          copy(idx + 1, j, idx);
          idx++;
        }
      }
    }

    for (u8 i = 1; i <= 12; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType == PLAYER_TYPE_NONE) {
          continue;
        }

        playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType != PLAYER_TYPE_REAL_LOCAL) {
          BattleTeam playerTeam = mRaceScenario.getPlayer(j)->getTeam();
          if (winningTeam_ != playerTeam) {
            continue;
          }

          copy(idx + 1, j, idx);
          idx++;
        }
      }
    }
  } else if (isLoss) {
    u8 idx = 0;
    for (u8 i = 1; i <= 12; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType != PLAYER_TYPE_REAL_LOCAL) {
          continue;
        }

        copy(idx + 1, j, idx);
        idx++;
      }
    }
  } else {
    copy(1, 0, 0);
  }

  initRace();
}

} // namespace System
#endif

namespace System {

bool RaceConfig::Scenario::isTeamMode() {
  return mSettings.mModeFlags >> 1 & 1;
}

u8 RaceConfig::Player::getUnkPos() { return this->_e0; }

CharacterId RaceConfig::Player::getCharacter() { return mCharacterId; }

VehicleId RaceConfig::Player::getVehicle() { return mVehicleId; }

#pragma legacy_struct_alignment on
void RaceConfig::Player::setMii(const Mii& mii) { mMii = mii; }
#pragma legacy_struct_alignment off

Mii& RaceConfig::Player::getMii() { return mMii; }

u8 RaceConfig::update() { return mMenuScenario.update(); }

void RaceConfig::Scenario::appendParamFile(RaceConfig* raceConfig) {
  raceConfig->append(mSettings.mCourseId,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mSettings.mEngineClass,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mSettings.mGameMode,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mPlayerCount, InitScene::spInstance->mHeapCollection
                                       .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mLocalPlayerCount,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);

  // Couldn't have just done getPlayer(i)?
  Player* player = mPlayers;
  for (s8 _ = 0; _ < (s8)ARRAY_SIZE(mPlayers); _++) {
    player->appendParamFile(raceConfig);
    player++;
  }

  raceConfig->append(mSettings.mModeFlags, nullptr);
}

// This is so stupid, Nintendo just HAD to use r0
s32 RaceConfig::getLocalPlayerCount(u8 playerIdx) {
  return (s8)(u8)mRaceScenario.mPlayers[playerIdx].mLocalPlayerNum;
}

void RaceConfig::setGhost(RawGhostFile* ghost) {
  if (mRaceScenario.mGhost == mMenuScenario.mGhost) {
    if (mRaceScenario.mGhost == &mGhosts[0]) {
      mMenuScenario.mGhost = &mGhosts[1];
    } else if (mRaceScenario.mGhost == &mGhosts[1]) {
      mMenuScenario.mGhost = &mGhosts[0];
    }
  }
  memcpy(mMenuScenario.mGhost, ghost, 0x2800);
}

s8 RaceConfig::getHudPlayerId(u8 playerIdx) {
  return (u8)mRaceScenario.mSettings.mHudPlayerIds[playerIdx];
}

void RaceConfig::loadNextCourse() {
  if (mRaceScenario.mSettings.mGameMode != Settings::GAMEMODE_GRAND_PRIX) {
    return;
  }

  u8 raceNumber = mRaceScenario.mSettings.mRaceNumber;
  if (raceNumber >= 3) {
    return;
  }

  ResourceManager::spInstance.nonvol->preloadCourseAsync(
      COURSE_ORDER[mRaceScenario.mSettings.mCupId][raceNumber + 1]);
}

bool RaceConfig::isLiveView(u8 hudPlayerIdx) {
  Settings::CameraMode cameraMode = mRaceScenario.mSettings.mCameraMode;
  if (cameraMode > (Settings::CameraMode)1 &&
      cameraMode < (Settings::CameraMode)5) {
    return true;
  }

  if (cameraMode == Settings::CAMERA_MODE_REPLAY) {
    return true;
  }

  s32 playerId = mRaceScenario.mSettings.mHudPlayerIds[hudPlayerIdx];
  if (playerId >= 0) {
    Player::Type playerType = mRaceScenario.mPlayers[(u8)playerId].mPlayerType;
    if (playerType != Player::TYPE_REAL_LOCAL &&
        playerType != Player::TYPE_GHOST) {
      return true;
    }
  }

  return false;
}

bool RaceConfig::isTimeAttackReplay() {
  const Settings::GameMode gameMode = mRaceScenario.mSettings.mGameMode;

  return ((gameMode == Settings::GAMEMODE_TIME_TRIAL ||
           gameMode == Settings::GAMEMODE_GHOST_RACE) &&
          spInstance->mRaceScenario.mPlayerCount != 0 &&
          spInstance->mRaceScenario.mPlayers[0].mPlayerType ==
              Player::TYPE_GHOST)
             ? true
             : false;
}

void ParameterFile::emptySub3() {}
void ParameterFile::emptySub2() {}
void ParameterFile::emptySub1() {}
s32 ParameterFile::emptySub0() { return 0; }

} // namespace System
