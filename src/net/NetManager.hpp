#pragma once

// Credits: Melg and CLF, used as reference for names.
// See bottom of file for the licenses
// https://github.com/MelgMKW/Pulsar/blob/main/GameSource/MarioKartWii/RKNet/RKNetController.hpp
// https://github.com/CLF78/OpenPayload/blob/master/payload/game/net/RKNetController.hpp

#include <rk_types.h>
#include <decomp.h>

#include "net/DisconnectInfo.hpp"
#include "net/FriendInfo.hpp"
#include "net/packets/RACEPacketHolder.hpp"

#include <egg/core/eggExpHeap.hpp>
#include <egg/core/eggTaskThread.hpp>

namespace Net {

class NetManager {
public:
  enum ConnectionState {
    CONNECTION_STATE_SHUTDOWN = 0x0, // offline
    CONNECTION_STATE_BEGIN_LOGIN = 0x1,
    CONNECTION_STATE_CHECK_PROFANITY = 0x2,
    CONNECTION_STATE_SOMETHING_GP_FRIENDS =
        0x3,                             // Friend related, needs better name
    CONNECTION_STATE_SYNC_FRIENDS = 0x4, // checks if a friend has added back
    CONNECTION_STATE_IDLE = 0x5,         // online but not doing anything
    CONNECTION_STATE_IN_MM = 0x6,        // searching or in a room
    CONNECTION_STATE_ERROR = 0x7,        // non SAKE errors
    CONNECTION_STATE_SAKE_ERROR = 0x8,   // set when the EC is 4xxxx or 98xxx
  };

  enum RoomType {
    ROOM_TYPE_NONE = 0x0,
    ROOM_TYPE_VS_WW = 0x1,
    ROOM_TYPE_VS_REGIONAL = 0x2,
    ROOM_TYPE_BT_WW = 0x3,
    ROOM_TYPE_BT_REGIONAL = 0x4,
    ROOM_TYPE_HOST_PRIVATE = 0x5,
    ROOM_TYPE_NONHOST_PRIVATE = 0x6,
    ROOM_TYPE_JOINING_FRIEND_VS_WW = 0x7,
    ROOM_TYPE_JOINING_FRIEND_VS_REGIONAL = 0x8,
    ROOM_TYPE_JOINING_FRIEND_BT_WW = 0x9,
    ROOM_TYPE_JOINING_FRIEND_BT_REGIONAL = 0xA,
  };

  // Certainly suspending MM related, but unsure about last two values
  enum UnkMMSuspension {
    MM_SUSPENSION_NONE = 0x0,
    MM_SUSPENSION_ERROR = 0x1, // triggers a dc
    MM_SUSPENSION_UNK2 = 0x2,  // set when matchingSuspended is true
    MM_SUSPENSION_UNK3 = 0x3,  // set when matchingSuspended is false
  };

  void scheduleShutdown();

  void startWWVSSearch(u8 localPlayerCount);

  void startRegionalVSSearch(u8 localPlayerCount);

  void startWWBattleSearch(u8 localPlayerCount);

  void startRegionalBattleSearch(u8 localPlayerCount);

  void joinFriendPublicVS(u32 friendIdx, u8 localPlayerCount);

  void joinFriendPublicBT(u32 friendIdx, u8 localPlayerCount);

  void joinFriendRoom(u32 friendIdx, u8 localPlayerCount);

  void createFriendRoom(u8 localPlayerCount);

  void resetRH1andROOM();

  void setDisconnectInfo(DisconnectType dcType, s32 errorCode);

  void setToMMSuspensionUnk2();

  void setToMMSuspensionUnk3();

  DisconnectInfo getDisconnectInfo();

  void resetDisconnectInfo();

  s32 matchMakingElapsedSeconds();

  void resetFriendData(u32 friendIdx);

  bool isConnectionStateIdleOrInMM() const;

  bool isTaskThreadIdle();

  bool isConnectionStateIdle() const;

  bool hasFoundMatch() const;

  void setConnectionStateIdle();

  void setConnectionState(ConnectionState connState);

  ConnectionState getConnectionState() const;

  void handleError();

  void* alloc(u32 size, s32 alignment);

  void free(void* block);

  // namesake of the alloc/free functions is the lib they're called by
  static void* SOAlloc(u32 unk, u32 size);

  static void SOFree(u32 unk, void* block);

  static void* DWCAlloc(u32 unk, u32 size, s32 alignment);

  static void DWCFree(u32 unk, void* block);

  static void setFriendStatusUpdatingCallback2(u32 r3, u32 r4,
                                               NetManager* netManager);

  static void setFriendStatusUpdatingCallback(u32 r3, NetManager* netManager);

  void initMMInfos();

  void resetFriends();

  void updateAidMapping();

  void resetPidToAidMap();

  inline s32 getLocalId(u32 hudId) const;

  inline u32 myAidIdx() const;

  inline bool myAidInRoom() const;

  s32 getLocalPlayerId(u32 hudId) const;

  FriendJoinableStatus getFriendJoinableStatus(u32 friendIdx) const;

  static NetManager* getInstance() { return spInstance; }
  // reason this exists is since the local player count must be in the highest
  // byte to be passed off to DWC functions
  struct LocalPlayerCountDWC {
    u8 localPlayerCount;
    u8 _1[0x4 - 0x1];
  };
  static_assert(sizeof(LocalPlayerCountDWC) == 0x4);

  struct MatchMakingInfo {
    u64 m_MMStartTime;          // gets set upon match making 0x0
    u32 m_numConnectedConsoles; // number of non guest players 0x8
    u32 m_playerCount;          // players in room (includes guests) 0xC
    u32 m_fullAidBitmap;        // # bits is equal to num consoles, all 1 0x10
    u32 m_directConnectedAidBitmap; // Aids I'm connected to. It will fill up to
                                    // equal m_fullAidBitmap by the end of MM as
                                    // I connect to other users. 0x14
    u32 m_roomId;                   // Also known as groupId by DWC 0x18
    s32 m_hostFriendId;             // -1 if host isn't a friend. 0x1C
    u8 m_localPlayerCount;          // 0x20
    u8 m_myAid;                     // 0x21
    u8 m_hostAid;                   // value returned by DWC_GetServerAid() 0x22
    LocalPlayerCountDWC m_localPlayerCounts[MAX_PLAYER_COUNT]; // 0x23
    bool
        m_matchingSuspended; // set when entering mm, cleared shortly after 0x53
    u8 _54[0x58 - 0x54];
  };
  static_assert(sizeof(MatchMakingInfo) == 0x58);

  // Two vtables
  void* m_vtable1; // offset 0xc is NetManager's dtor
  void* m_vtable2; // unk dtor at 0xc, also present in FriendManager vtable
  OSMutex m_mutex;
  EGG::ExpHeap* m_heap;
  EGG::TaskThread* m_taskThread; // runs the mainLoop
  ConnectionState m_connectionState;
  DisconnectInfo m_disconnectInfo;
  u8 _0034[0x0038 - 0x0034]; // padding?
  MatchMakingInfo m_matchMakingInfos[2];
  RoomType m_roomType;
  UnkMMSuspension m_mmSuspension;
  // points to RACE packets to be sent, two per aid
  RACEPacketHolder* m_sendRACEPackets[2][MAX_PLAYER_COUNT];
  // points to RACE packets to be recieved, two per aid
  RACEPacketHolder* m_recvRACEPackets[2][MAX_PLAYER_COUNT];
  // The RACE packet to be sent, formed from m_sendRACEPackets, one per aid
  PacketHolder<void*>* m_outgoingRACEPacket[MAX_PLAYER_COUNT];
  u64 m_timeOfLastSentRACE[MAX_PLAYER_COUNT];
  u64 m_timeOfLastRecvRACE[MAX_PLAYER_COUNT];
  u64 m_timeBetweenSendingPackets[MAX_PLAYER_COUNT]; // time bewteen sent
                                                     // packets per aid
  u64 m_timeBetweenRecvPackets[MAX_PLAYER_COUNT];    // time between recieved
                                                     // packets per aid
  u8 m_aidLastSentTo; // Aid of last player we sent to
  u8 m_recvRACEPacketBuffer[MAX_PLAYER_COUNT][0x2e0];
  u8 _25e1[0x25e4 - 0x25e1]; // padding
  StatusData m_myStatusData;
  FriendInfo m_friends[MAX_FRIEND_COUNT];
  bool m_friendStatusChanged;      // set when a friend adds back 0x2753
  bool m_shutdownScheduled;        // set when logging off // 0x2755
  bool m_shouldUpdateFriendStatus; // 0x2756
  bool m_hasEjectedDisk;           // triggers a dc screen 0x2757
  u8 _2759[0x275c - 0x2759];
  s32 m_badWordsNum; // number of bad words found in the profanity check
  s32 m_disconnectPenalty;
  s32 m_vr;
  s32 m_br;
  u32 m_lastSendIdx[MAX_PLAYER_COUNT]; // idx of m_sendRACEPackets last sent per
                                       // aid
  // idx of m_recvRACEPackets last recvieved per packet per aid
  u32 m_lastRecvIdx[MAX_PLAYER_COUNT][8];
  s32 m_currMMInfo; // Current MM info used
  u8 m_playerIdToAidMapping[MAX_PLAYER_COUNT];
  u32 m_disconnectedAids;      // disconnected if 1 << aid is 1
  u32 m_disconnectedPlayerIds; // disconnected if 1 << pid is 1
  u8 _2934[0x295c - 0x2934];   // elo based MM struct
  u8 _295c[0x29c8 - 0x295c];   // some timers

  static NetManager* spInstance;
};
static_assert(sizeof(NetManager) == 0x29c8);
} // namespace Net

// MIT License

// Copyright (c) 2023 MelgMKW

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// MIT License

// Copyright (c) 2024 CLF78

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
