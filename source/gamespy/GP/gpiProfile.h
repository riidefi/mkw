/*
gpiProfile.h
GameSpy Presence SDK
Dan "Mr. Pants" Schoenblum

Copyright 1999-2007 GameSpy Industries, Inc

devsupport@gamespy.com

***********************************************************************
Please see the GameSpy Presence SDK documentation for more information
**********************************************************************/

#pragma once

// INCLUDES
//////////
#include "gpi.h"

// DEFINES
/////////
#define GPI_SIG_LEN 33

// TYPES
///////
// The status for a buddy profile.
//////////////////////////////////

// New Status Info
typedef struct _GPIBuddyStatusInfo {
  int buddyIndex;             // 0x00
  GPEnum statusState;         // 0x04
  char* richStatus;           // 0x08
  char* gameType;             // 0x0C
  char* gameVariant;          // 0x10
  char* gameMapName;          // 0x14
  unsigned int sessionFlags;  // 0x18
  unsigned int buddyIp;       // 0x1C
  unsigned short buddyPort;   // 0x20
  unsigned int hostIp;        // 0x24
  unsigned int hostPrivateIp; // 0x28
  unsigned short queryPort;   // 0x2C
  unsigned short hostPort;    // 0x2E
  GPEnum quietModeFlags;      // 0x30
  int productId;              // 0x34
  // New Status Info extended info Keys
  DArray extendedInfoKeys; // 0x38
} GPIBuddyStatusInfo;

// Old status
typedef struct {
  int buddyIndex;
  GPEnum status;
  char* statusString;
  char* locationString;
  unsigned int ip;
  unsigned short port;
  GPEnum quietModeFlags;
} GPIBuddyStatus;

// Profile data.
////////////////
typedef struct GPIProfile {
  int profileId;                       // 0x00 0
  int userId;                          // 0x04 4
  GPIBuddyStatus* buddyStatus;         // 0x08 8
  GPIBuddyStatusInfo* buddyStatusInfo; // 0x0C 12
  GPIInfoCache* cache;
  char* authSig;
  int requestCount;
  char* peerSig;
} GPIProfile;

// A list of profiles.
//////////////////////
typedef struct {
  HashTable profileTable;
  int num;
  int numBuddies;
} GPIProfileList;

// FUNCTIONS
///////////
GPIBool gpiInitProfiles(GPConnection* connection);

GPIProfile* gpiProfileListAdd(GPConnection* connection, int id);

GPIBool gpiGetProfile(GPConnection* connection, GPProfile profileid,
                      GPIProfile** pProfile);

GPResult gpiProcessNewProfile(GPConnection* connection, GPIOperation* operation,
                              const char* input);

GPResult gpiNewProfile(GPConnection* connection, const char nick[GP_NICK_LEN],
                       GPEnum replace, GPEnum blocking, GPCallback callback,
                       void* param);

GPResult gpiProcessDeleteProfle(GPConnection* connection,
                                GPIOperation* operation, const char* input);

GPResult gpiDeleteProfile(GPConnection* connection, GPCallback callback,
                          void* param);

void gpiRemoveProfile(GPConnection* connection, GPIProfile* profile);

void gpiRemoveProfileByID(GPConnection* connection, int profileid);

GPResult gpiLoadDiskProfiles(GPConnection* connection);

GPResult gpiSaveDiskProfiles(GPConnection* connection);

GPResult gpiFindProfileByUser(GPConnection* connection, char nick[GP_NICK_LEN],
                              char email[GP_EMAIL_LEN], GPIProfile** profile);

// return false to stop the mapping
typedef GPIBool (*gpiProfileMapFunc)(GPConnection* connection,
                                     GPIProfile* profile, void* data);

GPIBool gpiProfileMap(GPConnection* connection, gpiProfileMapFunc func,
                      void* data);

GPIProfile* gpiFindBuddy(GPConnection* connection, int buddyIndex);

void gpiRemoveBuddyStatus(GPIBuddyStatus* buddyStatus);
void gpiRemoveBuddyStatusInfo(GPIBuddyStatusInfo* buddyStatusInfo);

GPIBool gpiCanFreeProfile(GPIProfile* profile);

void gpiSetInfoCacheFilename(const char filename[FILENAME_MAX + 1]);
