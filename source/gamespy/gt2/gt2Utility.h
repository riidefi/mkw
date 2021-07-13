/*
GameSpy GT2 SDK
Dan "Mr. Pants" Schoenblum
dan@gamespy.com

Copyright 2002 GameSpy Industries, Inc

devsupport@gamespy.com
*/

#pragma once

#include "gt2Main.h"

void gti2MessageCheck(const GT2Byte** message, int* len);

#ifdef RECV_LOG
void gti2LogMessage(unsigned int fromIP, unsigned short fromPort,
                    unsigned int toIP, unsigned short toPort,
                    const GT2Byte* message, int len);
#endif
