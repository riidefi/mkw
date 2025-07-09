#include "NetManager.hpp"

#include "net/MiscPacketHandler.hpp"
#include "net/packets/ROOM.hpp"

#include "host_system/SystemManager.hpp"
#include "system/RaceConfig.hpp"

#include <dwc/common/dwc_error.h>
#include <dwc/common/dwc_init.h>

namespace Net {

void NetManager::scheduleShutdown() { m_shutdownScheduled = true; }

void NetManager::startWWVSSearch(u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  // were online, start search/mm
  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_roomType = ROOM_TYPE_VS_WW;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    // allows the logic in RACEHEADER1Handler_calc() to run
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::startRegionalVSSearch(u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_roomType = ROOM_TYPE_VS_REGIONAL;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::startWWBattleSearch(u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    m_roomType = ROOM_TYPE_BT_WW;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::startRegionalBattleSearch(u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    m_roomType = ROOM_TYPE_BT_REGIONAL;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::joinFriendPublicVS(u32 friendIdx, u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    FriendJoinableStatus status = getFriendJoinableStatus(friendIdx);
    switch (status) {
    case STATUS_WW_VS:
      m_roomType = ROOM_TYPE_JOINING_FRIEND_VS_WW;
      break;
    case STATUS_JOINABLE_REGIONAL_VS:
      m_roomType = ROOM_TYPE_JOINING_FRIEND_VS_REGIONAL;
      break;
    default:
      OSLockMutex(&m_mutex);

      if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
        m_disconnectInfo.type = DISCONNECT_TYPE_CANT_JOIN_FRIEND;
        m_disconnectInfo.code = 0;
      }

      OSUnlockMutex(&m_mutex);
      return;
    }
    initMMInfos();
    m_matchMakingInfos[0].m_hostFriendId = friendIdx;
    m_matchMakingInfos[1].m_hostFriendId = friendIdx;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::joinFriendPublicBT(u32 friendIdx, u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    FriendJoinableStatus status = getFriendJoinableStatus(friendIdx);
    switch (status) {
    case STATUS_WW_BT:
      m_roomType = ROOM_TYPE_JOINING_FRIEND_BT_WW;
      break;
    case STATUS_JOINABLE_REGIONAL_BT:
      m_roomType = ROOM_TYPE_JOINING_FRIEND_BT_REGIONAL;
      break;
    default:
      OSLockMutex(&m_mutex);

      if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
        m_disconnectInfo.type = DISCONNECT_TYPE_CANT_JOIN_FRIEND;
        m_disconnectInfo.code = 0;
      }

      OSUnlockMutex(&m_mutex);
      return;
    }
    initMMInfos();
    m_matchMakingInfos[0].m_hostFriendId = friendIdx;
    m_matchMakingInfos[1].m_hostFriendId = friendIdx;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::joinFriendRoom(u32 friendIdx, u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_matchMakingInfos[0].m_hostFriendId = friendIdx;
    m_matchMakingInfos[1].m_hostFriendId = friendIdx;
    m_roomType = ROOM_TYPE_NONHOST_PRIVATE;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    ROOMHandler::getInstance()->init(ROLE_GUEST);
  }
}

void NetManager::createFriendRoom(u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_roomType = ROOM_TYPE_HOST_PRIVATE;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    ROOMHandler::getInstance()->init(ROLE_HOST);
  }
}

void NetManager::resetRH1andROOM() {
  if (RACEHEADER1Handler::getInstance() != nullptr) {
    RACEHEADER1Handler::getInstance()->reset();
  }
  if (ROOMHandler::getInstance() != nullptr) {
    ROOMHandler::getInstance()->reset();
  }
  m_mmSuspension = MM_SUSPENSION_ERROR;
}

void NetManager::setToMMSuspensionUnk2() {
  if (m_mmSuspension == MM_SUSPENSION_ERROR) {
    return;
  }
  m_mmSuspension = MM_SUSPENSION_UNK2;
}

void NetManager::setToMMSuspensionUnk3() {
  if (m_mmSuspension == MM_SUSPENSION_ERROR) {
    return;
  }
  m_mmSuspension = MM_SUSPENSION_UNK3;
}

void NetManager::setDisconnectInfo(DisconnectType dcType, s32 errorCode) {
  OSLockMutex(&m_mutex);

  if (dcType == DISCONNECT_TYPE_DISK_EJECTED) {
    m_hasEjectedDisk = true;
  } else if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
    m_disconnectInfo.type = dcType;
    m_disconnectInfo.code = errorCode;
    switch (dcType) {
    case DISCONNECT_TYPE_ERROR_CODE:
    case DISCONNECT_TYPE_BAD_MII_NAME:
    case DISCONNECT_TYPE_UNRECOVERABLE_ERROR:
      m_connectionState = CONNECTION_STATE_ERROR;
      break;
    }
  }
  OSUnlockMutex(&m_mutex);
}

DisconnectInfo NetManager::getDisconnectInfo() {
  DisconnectInfo dcInfo;

  OSLockMutex(&m_mutex);

  if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR &&
      m_hasEjectedDisk) {
    dcInfo.type = DISCONNECT_TYPE_DISK_EJECTED;
    dcInfo.code = 0;

  } else {
    dcInfo.type = m_disconnectInfo.type;
    dcInfo.code = m_disconnectInfo.code;
  }
  OSUnlockMutex(&m_mutex);
  return dcInfo;
}

void NetManager::resetDisconnectInfo() {
  m_hasEjectedDisk = false;
  OSLockMutex(&m_mutex);
  if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
    m_disconnectInfo.type = DISCONNECT_TYPE_NONE;
    m_disconnectInfo.code = 0;
  }
  OSUnlockMutex(&m_mutex);
}

s32 NetManager::matchMakingElapsedSeconds() {
  s32 time = m_matchMakingInfos[m_currMMInfo].m_MMStartTime;

  // has to do u64 comparison
  if (m_matchMakingInfos[m_currMMInfo].m_MMStartTime == 0) {
    return 0;
  }

  OSTime currTime = OSGetTime();
  return OSTicksToSeconds((s32)currTime - time);
}

void NetManager::resetFriendData(u32 friendIdx) {
  m_friends[friendIdx].statusData.roomId = 0;
  m_friends[friendIdx].statusData.regionId = 0;
  m_friends[friendIdx].statusData.status = 0;
  m_friends[friendIdx].statusData.playerCount = 0;
  m_friends[friendIdx].statusData.currRace = 0;
  m_friends[friendIdx].dwcFriendStatus = 0;
  m_friends[friendIdx].addedBack = true;
}

bool NetManager::isConnectionStateIdleOrInMM() const {
  bool idleOrMM = false;

  switch (getConnectionState()) {
  case CONNECTION_STATE_IDLE:
  case CONNECTION_STATE_IN_MM:
    idleOrMM = true;
    break;
  }

  return idleOrMM;
}

bool NetManager::isTaskThreadIdle() { return !m_taskThread->isTaskExist(); }

bool NetManager::isConnectionStateIdle() const {
  return getConnectionState() == CONNECTION_STATE_IDLE;
}

bool NetManager::hasFoundMatch() const {
  bool inMatch = false;

  bool isMyAidInMatch = (1 << m_matchMakingInfos[m_currMMInfo].m_myAid) &
                        m_matchMakingInfos[m_currMMInfo].m_fullAidBitmap;
  // were in a match if my aid is in the room and we have connected to another
  // console
  if (isMyAidInMatch &&
      m_matchMakingInfos[m_currMMInfo].m_numConnectedConsoles > 1) {
    inMatch = true;
  }
  return inMatch;
}

void NetManager::setConnectionStateIdle() {
  m_connectionState = CONNECTION_STATE_IDLE;
}

void NetManager::setConnectionState(ConnectionState connState) {
  m_connectionState = connState;
}

NetManager::ConnectionState NetManager::getConnectionState() const {
  s32 code;
  DWCErrorType type;
  DWC_GetLastErrorEx(&code, &type);

  ConnectionState connState;

  // 4xxxx and 98xxx are sake erorrs, otherwise set connectionState
  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

  return connState;
}

void NetManager::handleError() {
  s32 code;
  DWCErrorType type;

  if (DWC_GetLastErrorEx(&code, &type)) {
    // this is functionally equal to code = -code; but this was need to match
    // dwc error codes are negative values, but mkw uses positive error codes.
    // we just need to negate code
    code = code - (code << 1);

    if ((code / 10000) == 4 || (code / 1000) == 98) {
      // return early for sake errors
      return;
    }

    DWC_ClearError();

    u32 errorCode; // this variable was needed for matching purposes

    switch (type) {
    case DWC_ERROR_TYPE_1:
    case DWC_ERROR_TYPE_2:

      errorCode = code; // this is used for matching purposes
      OSLockMutex(&m_mutex);
      if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
        m_disconnectInfo.type = DISCONNECT_TYPE_CANT_JOIN_FRIEND;
        // code getting set here is somewhat interesting since errors
        // when joining friends dont bring you to the error code screen in game
        m_disconnectInfo.code = errorCode;
      }
      OSUnlockMutex(&m_mutex);
      break;

    case DWC_ERROR_TYPE_3:
    case DWC_ERROR_TYPE_4:
    case DWC_ERROR_TYPE_5:
    case DWC_ERROR_TYPE_6:
      errorCode = code;
      OSLockMutex(&m_mutex);
      if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
        m_disconnectInfo.type = DISCONNECT_TYPE_ERROR_CODE;
        m_disconnectInfo.code = errorCode;
        m_connectionState = CONNECTION_STATE_ERROR;
      }
      OSUnlockMutex(&m_mutex);
      break;

    case DWC_ERROR_TYPE_7:
      OSLockMutex(&m_mutex);
      if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
        m_disconnectInfo.type = DISCONNECT_TYPE_UNRECOVERABLE_ERROR;
        m_disconnectInfo.code = 0;
        m_connectionState = CONNECTION_STATE_ERROR;
      }
      OSUnlockMutex(&m_mutex);
      break;
    }
  }
}

void* NetManager::alloc(u32 size, s32 alignment) {
  void* block = nullptr;
  if (size != 0) {
    OSLockMutex(&m_mutex);
    block = m_heap->alloc(size, alignment);
    OSUnlockMutex(&m_mutex);
  }
  return block;
}

void NetManager::free(void* block) {
  if (block != nullptr) {
    OSLockMutex(&m_mutex);
    m_heap->free(block);
    OSUnlockMutex(&m_mutex);
  }
}

void* NetManager::SOAlloc(u32 unk, u32 size) {
  void* block = nullptr;
  NetManager* netManager = spInstance;
  if (size != 0) {
    OSLockMutex(&netManager->m_mutex);
    block = netManager->m_heap->alloc(size, 0x20);
    OSUnlockMutex(&netManager->m_mutex);
  }
  return block;
}

void NetManager::SOFree(u32 unk, void* block) {
  NetManager* netManager = spInstance;
  if (block != nullptr) {
    OSLockMutex(&netManager->m_mutex);
    netManager->m_heap->free(block);
    OSUnlockMutex(&netManager->m_mutex);
  }
}

void* NetManager::DWCAlloc(u32 unk, u32 size, s32 alignment) {
  void* block = nullptr;
  NetManager* netManager = spInstance;
  if (size != 0) {
    OSLockMutex(&netManager->m_mutex);
    block = netManager->m_heap->alloc(size, alignment);
    OSUnlockMutex(&netManager->m_mutex);
  }
  return block;
}

void NetManager::DWCFree(u32 unk, void* block) {
  NetManager* netManager = spInstance;
  if (block != nullptr) {
    OSLockMutex(&netManager->m_mutex);
    netManager->m_heap->free(block);
    OSUnlockMutex(&netManager->m_mutex);
  }
}

void NetManager::updateDWCServersAsyncCallback(u32 r3, u32 r4,
                                               NetManager* netManager) {
  if (r3 != 0)
    return;
  if (r4 == 0)
    return;
  netManager->m_friendStatusChanged = true;
}

void NetManager::DWCSetBuddyFriendCallback(u32 r3, NetManager* netManager) {
  netManager->m_friendStatusChanged = true;
}

void NetManager::initMMInfos() {
  for (u32 i = 0; i < 2; i++) {
    m_matchMakingInfos[i].m_MMStartTime = 0;
    m_matchMakingInfos[i].m_numConnectedConsoles = 0;
    m_matchMakingInfos[i].m_playerCount = 0;
    m_matchMakingInfos[i].m_fullAidBitmap = 0;
    m_matchMakingInfos[i].m_directConnectedAidBitmap = 0;
    m_matchMakingInfos[i].m_roomId = 0;
    m_matchMakingInfos[i].m_hostFriendId = -1;
    m_matchMakingInfos[i].m_myAid = -1;
    m_matchMakingInfos[i].m_hostAid = -1;
    m_matchMakingInfos[i].m_matchingSuspended = false;
    for (u32 j = 0; j < MAX_PLAYER_COUNT; j++) {
      memset(&m_matchMakingInfos[i].m_localPlayerCounts[j], 0, 4);
    }
  }
}

void NetManager::resetFriends() {
  for (u32 i = 0; i < MAX_FRIEND_COUNT; i++)
    resetFriendData(i);
}

void NetManager::resetPlayerIdToAidMap() {
  for (u32 i = 0; i < MAX_PLAYER_COUNT; i++)
    m_playerIdToAidMapping[i] = -1;
}

void NetManager::updateAidMapping() {
  m_disconnectedPlayerIds = 0;
  m_disconnectedAids = 0;

  if (RACEHEADER1Handler::getInstance()) {
    const u8* RH1AidMapping =
        RACEHEADER1Handler::getInstance()->getPlayerIdToAidMapping();
    for (u32 i = 0; i < MAX_PLAYER_COUNT; i++)
      m_playerIdToAidMapping[i] = RH1AidMapping[i];
  } else if (SELECTHandler::getInstance()) {
    const u8* selectAidMapping =
        SELECTHandler::getInstance()->getPlayerIdToAidMapping();
    for (u32 i = 0; i < MAX_PLAYER_COUNT; i++)
      m_playerIdToAidMapping[i] = selectAidMapping[i];
  } else {
    resetPlayerIdToAidMap();
  }
}

s32 NetManager::getLocalId(u32 hudId) const {
  u8 myAid = m_matchMakingInfos[m_currMMInfo].m_myAid;
  s32 count = -1;
  for (s32 i = 0; i < MAX_PLAYER_COUNT; i++) {
    if (m_playerIdToAidMapping[i] == myAid) {
      count++;
      if (count == hudId)
        return i;
    }
  }
  return -1;
}

bool NetManager::myAidInRoom() const {
  u32 fullMap = m_matchMakingInfos[m_currMMInfo].m_fullAidBitmap;
  u8 myAid = m_matchMakingInfos[m_currMMInfo].m_myAid;
  return (1 << myAid & fullMap);
}

s32 NetManager::getLocalPlayerId(u32 hudId) const {
  if (MiscPacketHandler::spInstance) {
    System::RaceConfig::Player* players =
        System::RaceConfig::spInstance->mRaceScenario.mPlayers;
    s32 count = 0;
    // this currently just exists to prevent regswaps
    u8 playerId = 0;
    // loop thru player ids, check if player[i] is local
    for (s32 i = 0; i < MAX_PLAYER_COUNT; i++) {

      if (players[playerId].mPlayerType ==
          System::RaceConfig::Player::TYPE_REAL_LOCAL) {

        // there can be at most two local players for online and the guest's
        // player id will be higher than player 1's.
        if (count == hudId) {
          return i;
        }
        count++;
      }
      playerId++;
    }

    return -1;
  }

  if (myAidInRoom()) {
    return getLocalId(hudId);
  }
  return -1;
}

// https://decomp.me/scratch/l8u6Q
FriendJoinableStatus NetManager::getFriendJoinableStatus(u32 friendIdx) const {
  if (!m_friends[friendIdx].addedBack ||
      m_friends[friendIdx].dwcFriendStatus == 0) {
    return STATUS_OFFLINE;
  }

  FriendStatus friendStatus =
      static_cast<FriendStatus>(m_friends[friendIdx].statusData.status);
  s8 regionId;

  // if the friend isn't online but not doing anything
  if (friendStatus != FRIEND_STATUS_IDLE) {
    switch (friendStatus) {

    // maybe the following two cases are an inlined function? its quite
    // repetitive
    case FRIEND_STATUS_PUBLIC_VS:
      if (m_disconnectPenalty != 0) {
        // if im penalized for dc-ing too much show my status as online for
        // others
        return STATUS_ONLINE;
      }

      regionId = m_friends[friendIdx].statusData.regionId;

      if (regionId != -1) {
        // i have the same region as my friend, so i can join their regional
        // room
        if (regionId ==
            static_cast<s32>(System::SystemManager::sInstance->mMatchingArea)) {
          return STATUS_JOINABLE_REGIONAL_VS;
        }
        // otherwise i cant
        return STATUS_UNJOINABLE_REGIONAL_VS;
      }
      return STATUS_WW_VS;

    case FRIEND_STATUS_PUBLIC_BT:
      if (m_disconnectPenalty != 0) {
        return STATUS_ONLINE;
      }

      regionId = m_friends[friendIdx].statusData.regionId;

      if (regionId != -1) {
        if (regionId ==
            static_cast<s32>(System::SystemManager::sInstance->mMatchingArea)) {
          return STATUS_JOINABLE_REGIONAL_BT;
        }
        return STATUS_UNJOINABLE_REGIONAL_BT;
      }
      return STATUS_WW_BT;

    // just return the friendStatus for all other cases
    case FRIEND_STATUS_FROOM_VS_HOST:
    case FRIEND_STATUS_FROOM_BATTLE_HOST:
    case FRIEND_STATUS_FROOM_VS_NON_HOST:
    case FRIEND_STATUS_FROOM_BATTLE_NON_HOST:
    case FRIEND_STATUS_ONLINE:
    case FRIEND_STATUS_OPEN_ROOM:
    case FRIEND_STATUS_PLAYING_WITH_FRIENDS:
      return static_cast<FriendJoinableStatus>(friendStatus);
      break;
    default:
      return static_cast<FriendJoinableStatus>(friendStatus);
    }
  }
  return STATUS_ONLINE;
}

} // namespace Net
