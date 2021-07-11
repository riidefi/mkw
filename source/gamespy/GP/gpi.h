/*
gpi.h
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
// clang-format off
#include "../common/gsCommon.h"
#include "../common/gsAvailable.h"
#include "../common/gsUdpEngine.h"
#include "../hashtable.h"
#include "../darray.h"
#include "../md5.h"
#include "gp.h"
// clang-format on

// Extended message support
#define GPI_NEW_AUTH_NOTIFICATION (1 << 0)
#define GPI_NEW_REVOKE_NOTIFICATION (1 << 1)

// New Status Info support
#define GPI_NEW_STATUS_NOTIFICATION (1 << 2)

// Buddy List + Block List retrieval on login
#define GPI_NEW_LIST_RETRIEVAL_ON_LOGIN (1 << 3)

// Extended SDK features
#define GPI_SDKREV 0x3

// New UDP Layer port
#define GPI_PEER_PORT 6500

// TYPES
///////
// Boolean.
///////////
typedef enum _GPIBool { GPIFalse, GPITrue } GPIBool;

// clang-format off
#include "gpiUtility.h"
#include "gpiCallback.h"
#include "gpiOperation.h"
#include "gpiConnect.h"
#include "gpiBuffer.h"
#include "gpiInfo.h"
#include "gpiProfile.h"
#include "gpiPeer.h"
#include "gpiSearch.h"
#include "gpiBuddy.h"
#include "gpiTransfer.h"
#include "gpiUnique.h"
#include "gpiKeys.h"
// clang-format on

// Connection data.
///////////////////
typedef struct {
  char errorString[GP_ERROR_STRING_LEN]; // 0x00
  GPIBool infoCaching;                   // 0x100
  GPIBool infoCachingBuddyAndBlockOnly;  // 0x104
  GPIBool simulation;                    // 0x108
  GPIBool firewall;                      // 0x10C
  char nick[GP_NICK_LEN];                // 0x110
  char uniquenick[GP_UNIQUENICK_LEN];
  char email[GP_EMAIL_LEN];
  char password[GP_PASSWORD_LEN];
  int sessKey;
  int userid;
  int profileid;
  int partnerID;
  GPICallback callbacks[GPI_NUM_CALLBACKS];
  SOCKET cmSocket;
  int connectState;
  GPIBuffer socketBuffer;
  char* inputBuffer;
  int inputBufferSize;
  GPIBuffer outputBuffer;
  // Replaced by UDP Layer
  // SOCKET peerSocket;
  char mHeader[GS_UDP_MSG_HEADER_LEN];
  unsigned short peerPort;
  int nextOperationID;
  int numSearches;

  GPEnum lastStatusState;
  unsigned int hostIp;
  unsigned int hostPrivateIp;
  unsigned short queryPort;
  unsigned short hostPort;
  unsigned int sessionFlags;

  char richStatus[GP_RICH_STATUS_LEN];
  char gameType[GP_STATUS_BASIC_STR_LEN];
  char gameVariant[GP_STATUS_BASIC_STR_LEN];
  char gameMapName[GP_STATUS_BASIC_STR_LEN];

  // New Status Info extended info Keys
  DArray extendedInfoKeys;

  // Deprecated
  char lastStatusString[GP_STATUS_STRING_LEN];
  char lastLocationString[GP_LOCATION_STRING_LEN];

  GPErrorCode errorCode;
  GPIBool fatalError;
  FILE* diskCache;
  GPIOperation* operationList;
  GPIProfileList profileList;
  GPIPeer* peerList;
  GPICallbackData* callbackList;
  GPICallbackData* lastCallback;
  GPIBuffer updateproBuffer;
  GPIBuffer updateuiBuffer;
  DArray transfers; // matches up to here
  unsigned int nextTransferID;
  int productID;
  int namespaceID;
  char loginTicket[GP_LOGIN_TICKET_LEN];
  GPEnum quietModeFlags;
  gsi_time kaTransmit;
} GPIConnection;

// FUNCTIONS
///////////
GPResult gpiInitialize(GPConnection* connection, int productID, int namespaceID,
                       int partnerID);

void gpiDestroy(GPConnection* connection);

GPResult gpiReset(GPConnection* connection);

GPResult gpiProcessConnectionManager(GPConnection* connection);

GPResult gpiProcess(GPConnection* connection, int blockingOperationID);

GPResult gpiEnable(GPConnection* connection, GPEnum state);

GPResult gpiDisable(GPConnection* connection, GPEnum state);

#ifdef _DEBUG
void gpiReport(GPConnection* connection, void (*report)(const char* output));
#endif
