// Credits: Melg and CLF, used as reference for names.
// See bottom of file for the licenses
// https://github.com/MelgMKW/Pulsar/blob/main/GameSource/MarioKartWii/RKNet/RKNetController.hpp
// https://github.com/CLF78/OpenPayload/blob/master/payload/game/net/RKNetController.hpp

#pragma once

#include <rk_types.h>

#include "net/DisconnectInfo.hpp"
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
    ROOM_TYPE_JOINING_FRIEND_WW = 0x7,
    ROOM_TYPE_JOINING_FRIEND_REGIONAL = 0x8,
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

  void joinFriendRoom(u32 friendRosterId, u8 localPlayerCount);

  void createFriendRoom(u8 localPlayerCount);

  void resetRH1andROOM();

  void setDisconnectInfo(DisconnectType dcType, s32 errorCode);

  void setToMMSuspensionUnk2();

  void setToMMSuspensionUnk3();

  DisconnectInfo getDisconnectInfo() const;

  void resetDisconnectInfo();

  s32 getLatency();

  void initMMInfos();

  bool isConnectionStateIdleOrInMM() const;

  bool isTaskThreadIdle();

  bool isConnectionStateIdle() const;

  bool hasFoundMatch() const;

  void setConnectionStateIdle();

  void setConnectionState(ConnectionState connState);

  inline ConnectionState getConnectionState() const;

  void* alloc(u32 size, s32 alignment);

  void free(void* block);

  // namesake of the alloc/free functions is the lib they're called by
  static void* SOAlloc(u32 unk, u32 size);

  static void SOFree(u32 unk, void* block);

  static void* DWCAlloc(u32 unk, u32 size, s32 alignment);

  static void DWCFree(u32 unk, void* block);

private:
  struct MatchMakingInfo {
    u64 m_MMStartTime;          // gets set upon match making
    u32 m_numConnectedConsoles; // number of non guest players
    u32 m_playerCount;          // players in room (includes guests)
    u32 m_fullAidBitmap;        // # bits is equal to num consoles, all 1
    u32 m_availableAidBitmap;   // will equal the full bitmap by end of mm
    u32 m_roomId;
    s32 m_hostFriendId; // -1 if host isn't a friend
    u8 m_localPlayerCount;
    u8 m_myAid;
    u8 m_hostAid;
    u8 _23[0x53 - 0x23];      // some kind of localPlayerCount for each aid
    bool m_matchingSuspended; // set when entering mm, cleared shortly after
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
  RACEPacketHolder* m_sendRACEPackets[2][12];
  // points to RACE packets to be recieved, two per aid
  RACEPacketHolder* m_recvRACEPackets[2][12];
  // The RACE packet to be sent, formed from m_sendRACEPackets, one per aid
  PacketHolder<void*>* m_outgoingRACEPacket[12];
  u64 m_timeOfLastSentRACE[12];
  u64 m_timeOfLastRecvRACE[12];
  u64 m_timeBetweenSendingPackets[12]; // time bewteen sent packets per aid
  u64 m_timeBetweenRecvPackets[12];    // time between recieved packets per aid
  u8 m_aidLastSentTo;                  // Aid of last player we sent to
  u8 m_recvRACEPacketBuffer[12][0x2e0];
  u8 _25e1[0x25e4 - 0x25e1];  // padding
  u8 _25e4[0x25ec - 0x25e4];  // Unknown struct
  u8 _25ec[0x2754 - 0x25ec];  // Friend related struct
  bool m_friendStatusChanged; // set when a friend adds back
  bool m_shutdownScheduled;   // set when logging off
  bool m_shouldUpdateFriendStatus;
  bool m_hasEjectedDisk; // triggers a dc screen
  u8 _2759[0x275c - 0x2759];
  s32 m_badWordsNum;         // number of bad words found in the profanity check
  u8 _2760[0x2764 - 0x2760]; // unsure
  s32 m_vr;
  s32 m_br;
  u32 m_lastSendIdx[12]; // idx of m_sendRACEPackets last sent per aid
  // idx of m_recvRACEPackets last recvieved per packet per aid
  u32 m_lastRecvIdx[12][8];
  s32 m_currMMInfo; // Current MM info used
  u8 m_playerIdToAidMapping[12];
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
