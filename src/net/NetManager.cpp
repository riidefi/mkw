#include "NetManager.hpp"

#include "net/packets/ROOM.hpp"

#include <dwc/common/dwc_error.h>

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

void NetManager::joinFriendRoom(u32 friendRosterId, u8 localPlayerCount) {
  ConnectionState connState = getConnectionState();

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_matchMakingInfos[0].m_hostFriendId = friendRosterId;
    m_matchMakingInfos[1].m_hostFriendId = friendRosterId;
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

DisconnectInfo NetManager::getDisconnectInfo() const {
  DisconnectInfo dcInfo;

  OSLockMutex(const_cast<OSMutex*>(&m_mutex));

  if (m_disconnectInfo.type != DISCONNECT_TYPE_UNRECOVERABLE_ERROR &&
      m_hasEjectedDisk) {
    dcInfo.type = DISCONNECT_TYPE_DISK_EJECTED;
    dcInfo.code = 0;

  } else {
    dcInfo.type = m_disconnectInfo.type;
    dcInfo.code = m_disconnectInfo.code;
  }
  OSUnlockMutex(const_cast<OSMutex*>(&m_mutex));
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
  u32 type;
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

} // namespace Net
