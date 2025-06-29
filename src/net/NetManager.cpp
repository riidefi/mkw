#include "NetManager.hpp"

#include "net/packets/ROOM.hpp"

#include <dwc/common/dwc_error.h>

namespace Net {

void NetManager::scheduleShutdown() { m_shutdownScheduled = true; }

void NetManager::startWWVSSearch(u8 localPlayerCount) {
  DisconnectInfo dcInfo;
  s32 code;
  
  // we just care about the ec
  DWC_GetLastErrorEx(&code, reinterpret_cast<u32*>(&dcInfo.type));

  ConnectionState connState;

  // check for 4xxxx and 98xxx (sake errors)
  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

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
  DisconnectInfo dcInfo;
  s32 code;
  DWC_GetLastErrorEx(&code, reinterpret_cast<u32*>(&dcInfo.type));

  ConnectionState connState;

  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_roomType = ROOM_TYPE_VS_REGIONAL;
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::startWWBattleSearch(u8 localPlayerCount) {
  DisconnectInfo dcInfo;
  s32 code;
  DWC_GetLastErrorEx(&code, reinterpret_cast<u32*>(&dcInfo.type));

  ConnectionState connState;

  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    m_roomType = ROOM_TYPE_BT_WW;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::startRegionalBattleSearch(u8 localPlayerCount) {
  DisconnectInfo dcInfo;
  s32 code;
  DWC_GetLastErrorEx(&code, reinterpret_cast<u32*>(&dcInfo.type));

  ConnectionState connState;

  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

  if (connState == CONNECTION_STATE_IDLE) {
    initMMInfos();
    m_matchMakingInfos[0].m_localPlayerCount = localPlayerCount;
    m_matchMakingInfos[1].m_localPlayerCount = localPlayerCount;
    m_roomType = ROOM_TYPE_BT_REGIONAL;
    RACEHEADER1Handler::getInstance()->setPrepared();
  }
}

void NetManager::joinFriendRoom(u32 friendRosterId, u8 localPlayerCount) {
  u32 type;
  s32 code;
  DWC_GetLastErrorEx(&code, &type);

  ConnectionState connState;

  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

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
  u32 type;
  s32 code;
  DWC_GetLastErrorEx(&code, &type);

  ConnectionState connState;

  if ((code / 10000) == 4 || (code / 1000) == 98) {
    connState = CONNECTION_STATE_SAKE_ERROR;
  } else {
    connState = m_connectionState;
  }

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
    if (static_cast<u32>(dcType - 1) <= DISCONNECT_TYPE_ERROR_CODE ||
        dcType == DISCONNECT_TYPE_UNRECOVERABLE_ERROR) {
      m_connectionState = CONNECTION_STATE_ERROR;
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

s32 NetManager::getTimeDiff() {

  u32 time = (s32)(m_matchMakingInfos[m_currMMInfo].m_timeOfMatchMaking);
  if (m_matchMakingInfos[m_currMMInfo].m_timeOfMatchMaking == 0) {
    return 0;
  } else {
    OSTime currTime = OSGetTime();
    return ((s32)currTime - time) / (__OSBusClock / 4);
  }
}

} // namespace Net
