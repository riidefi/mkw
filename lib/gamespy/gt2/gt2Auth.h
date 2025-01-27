/*
GameSpy GT2 SDK
Dan "Mr. Pants" Schoenblum
dan@gamespy.com

Copyright 2002 GameSpy Industries, Inc

devsupport@gamespy.com
*/

#pragma once

#define GTI2_CHALLENGE_LEN 32
#define GTI2_RESPONSE_LEN 32

#ifdef __cplusplus
extern "C" {
#endif

GT2Byte* gti2GetChallenge(GT2Byte* buffer);

GT2Byte* gti2GetResponse(GT2Byte* buffer, const GT2Byte* challenge);

GT2Bool gti2CheckResponse(const GT2Byte* response1, const GT2Byte* response2);

#ifdef __cplusplus
}
#endif
