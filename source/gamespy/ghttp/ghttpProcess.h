/*
GameSpy GHTTP SDK
Dan "Mr. Pants" Schoenblum
dan@gamespy.com

Copyright 1999-2007 GameSpy Industries, Inc

devsupport@gamespy.com
*/

#pragma once

#include "ghttpConnection.h"
#include "ghttpMain.h"

#ifdef __cplusplus
extern "C" {
#endif

void ghiDoSocketInit(GHIConnection* connection);
void ghiDoHostLookup(GHIConnection* connection);
void ghiDoLookupPending(GHIConnection* connection);
void ghiDoConnecting(GHIConnection* connection);
void ghiDoSecuringSession(GHIConnection* connection);
void ghiDoSendingRequest(GHIConnection* connection);
void ghiDoPosting(GHIConnection* connection);
void ghiDoWaiting(GHIConnection* connection);
void ghiDoReceivingStatus(GHIConnection* connection);
void ghiDoReceivingHeaders(GHIConnection* connection);
void ghiDoReceivingFile(GHIConnection* connection);

#ifdef __cplusplus
}
#endif
