#pragma once

// this maybe should go in NetManager

namespace Net {

enum FriendStatus {
  FRIEND_STATUS_IDLE = 0x0, // Is this any different than ONLINE?
  FRIEND_STATUS_ONLINE = 0x2,
  FRIEND_STATUS_OPEN_ROOM = 0x3, // or hosting
  FRIEND_STATUS_PLAYING_WITH_FRIENDS = 0x4,
  FRIEND_STATUS_PUBLIC_VS = 0x5,
  FRIEND_STATUS_PUBLIC_BT = 0x8,
  FRIEND_STATUS_FROOM_VS_HOST = 0xB,
  FRIEND_STATUS_FROOM_BATTLE_HOST = 0xC,
  FRIEND_STATUS_FROOM_VS_NON_HOST = 0xD,
  FRIEND_STATUS_FROOM_BATTLE_NON_HOST = 0xE,
};

// The enums here are a little confusing and deserve some explanation
// Whereas FriendStatus only makes a destinction between public and private
// rooms, FriendJoinableStatus goes a bit further in whether you can join the
// public room or not.
enum FriendJoinableStatus {
  STATUS_NONE = 0x0,
  STATUS_OFFLINE = 0x1,
  STATUS_ONLINE = 0x2,
  STATUS_OPEN_ROOM = 0x3,
  STATUS_PLAYING_WITH_FRIEND = 0x4,
  STATUS_WW_VS = 0x5,
  STATUS_JOINABLE_REGIONAL_VS = 0x6,
  STATUS_UNJOINABLE_REGIONAL_VS = 0x7,
  STATUS_WW_BT = 0x8,
  STATUS_JOINABLE_REGIONAL_BT = 0x9,
  STATUS_UNJOINABLE_REGIONAL_BT = 0xA,
  STATUS_HOSTING_GP = 0xB,
  STATUS_HOSTING_BT = 0xC,
  STATUS_PLAYING_WITH_FRIENDS_RACE_COUNT = 0xD,
  STATUS_PLAYING_WITH_FRIEND_BATTLE_COUNT = 0xE,
};

struct StatusData {
  u32 roomId; // note to self, this is the one used 80659680, not to be confused
              // with a similar field in matchMakingInfo
  s8 regionId;
  u8 status; // FriendStatus
  u8 playerCount;
  u8 currRace;
};
static_assert(sizeof(StatusData) == 0x8);

struct FriendInfo {
  StatusData statusData;
  u8 dwcFriendStatus; // Updated in NetManager::updateStatusDatas
  bool addedBack;
  u8 _a[0xc - 0xa];
};
static_assert(sizeof(FriendInfo) == 0xc);

} // namespace Net
