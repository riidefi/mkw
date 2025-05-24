/*
GameSpy GHTTP SDK
Dan "Mr. Pants" Schoenblum
dan@gamespy.com

Copyright 1999-2007 GameSpy Industries, Inc

devsupport@gamespy.com
*/

#include "ghttpCommon.h"

// Disable compiler warnings for issues that are unavoidable.
/////////////////////////////////////////////////////////////
#if defined(_MSC_VER) // DevStudio
// Level4, "conditional expression is constant".
// Occurs with use of the MS provided macro FD_SET
#pragma warning(disable : 4127)
#endif // _MSC_VER

// Proxy server.
////////////////
char* ghiProxyAddress;
unsigned short ghiProxyPort;

// Throttle settings.
/////////////////////
int ghiThrottleBufferSize = 125;
gsi_time ghiThrottleTimeDelay = 250;

// Number of connections
/////////////////////
extern int ghiNumConnections;

// Creates the ghttp lock.
//////////////////////////
void ghiCreateLock(void) {}

// Frees the ghttp lock.
////////////////////////
void ghiFreeLock(void) {}

// Locks the ghttp lock.
////////////////////////
void ghiLock(void) {}

// Unlocks the ghttp lock.
//////////////////////////
void ghiUnlock(void) {}

// Reads encrypted data from decodeBuffer
// Appends decrypted data to recvBuffer
// Returns GHTTPFalse if there was a fatal error
////////////////////////////////////////////////
GHTTPBool ghiDecryptReceivedData(struct GHIConnection* connection) {
  // Decrypt data from decodeBuffer to recvBuffer
  GHIEncryptionResult aResult = GHIEncryptionResult_None;

  // data to be decrypted
  char* aReadPos = NULL;
  char* aWritePos = NULL;
  int aReadLen = 0;
  int aWriteLen = 0;

  do {
    // Call the decryption func
    do {
      aReadPos = connection->decodeBuffer.data + connection->decodeBuffer.pos;
      aReadLen = connection->decodeBuffer.len - connection->decodeBuffer.pos;
      aWritePos = connection->recvBuffer.data + connection->recvBuffer.len;
      aWriteLen =
          connection->recvBuffer.size -
          connection->recvBuffer.len; // the amount of room in recvbuffer

      aResult = (connection->encryptor.mDecryptFunc)(
          connection, &connection->encryptor, aReadPos, &aReadLen, aWritePos,
          &aWriteLen);
      if (aResult == GHIEncryptionResult_BufferTooSmall) {
        // Make some more room
        if (GHTTPFalse == ghiResizeBuffer(&connection->recvBuffer,
                                          connection->recvBuffer.sizeIncrement))
          return GHTTPFalse; // error
      } else if (aResult == GHIEncryptionResult_Error) {
        return GHTTPFalse;
      }
    } while (aResult == GHIEncryptionResult_BufferTooSmall && aWriteLen == 0);

    // Adjust GHIBuffer sizes so they account for transfered data
    if (aReadLen > connection->decodeBuffer.len) {
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_HotError,
                    "ghiDecryptReceivedData read past the end of "
                    "connection->decodeBuffer! (%d\\%d bytes)\r\n",
                    aReadLen, connection->decodeBuffer.len);
      return GHTTPFalse;
    }

    connection->decodeBuffer.pos += aReadLen;
    connection->recvBuffer.len += aWriteLen;

  } while (aWriteLen > 0);

  // Discard data from the decodedBuffer in chunks
  if (connection->decodeBuffer.pos > 0xFF) {
    int bytesToKeep =
        connection->decodeBuffer.len - connection->decodeBuffer.pos;
    if (bytesToKeep == 0)
      ghiResetBuffer(&connection->decodeBuffer);
    else {
      memmove(connection->decodeBuffer.data,
              connection->decodeBuffer.data + connection->decodeBuffer.pos,
              (size_t)bytesToKeep);
      connection->decodeBuffer.pos = 0;
      connection->decodeBuffer.len = bytesToKeep;
    }
  }

  return GHTTPTrue;
}

// Receive some data.
/////////////////////
#ifdef NON_MATCHING
GHIRecvResult ghiDoReceive(GHIConnection* connection, char buffer[],
                           int* bufferLen) {
  int rcode;
  int socketError;
  int len;

  // How much to try and receive.
  ///////////////////////////////
  len = (*bufferLen - 1);

  // Are we throttled?
  ////////////////////
  if (connection->throttle) {
    unsigned long now;

    // Don't receive too often.
    ///////////////////////////
    now = current_time();
    if (now < (connection->lastThrottleRecv + ghiThrottleTimeDelay))
      return GHINoData;

    // Update the receive time.
    ///////////////////////////
    connection->lastThrottleRecv = (unsigned int)now;

    // Don't receive too much.
    //////////////////////////
    len = min(len, ghiThrottleBufferSize);
  }

  // Receive some data.
  /////////////////////
  if (connection->encryptor.mEngine != GHTTPEncryptionEngine_None &&
      connection->encryptor.mSessionEstablished == GHTTPTrue &&
      connection->encryptor.mEncryptOnSend == GHTTPTrue) {
    GHIEncryptionResult result;
    int recvLength = len;

    result = ghiEncryptorSslDecryptRecv(connection, &connection->encryptor,
                                        buffer, &recvLength);
    if (result == GHIEncryptionResult_Success)
      rcode = recvLength;
    else
      rcode = -1; // signal termination of connection
  } else {
    rcode = recv(connection->socket, buffer, len, 0);
  }

  // There was an error.
  //////////////////////
  if (gsiSocketIsError(rcode)) {
    // Get the error code.
    //////////////////////
    socketError = GOAGetLastError(connection->socket);

    // Check for a closed connection.
    /////////////////////////////////
    if (socketError == WSAENOTCONN) {
      connection->connectionClosed = GHTTPTrue;
      return GHIConnClosed;
    }

    // Check for nothing waiting.
    /////////////////////////////
    if ((socketError == WSAEWOULDBLOCK) || (socketError == WSAEINPROGRESS) ||
        (socketError == WSAETIMEDOUT))
      return GHINoData;

    // There was a real error.
    //////////////////////////
    connection->completed = GHTTPTrue;
    connection->result = GHTTPSocketFailed;
    connection->socketError = socketError;
    connection->connectionClosed = GHTTPTrue;

    return GHIError;
  }

  // The connection was closed.
  /////////////////////////////
  if (rcode == 0) {
    connection->connectionClosed = GHTTPTrue;
    return GHIConnClosed;
  }

  // Cap the buffer.
  //////////////////
  buffer[rcode] = '\0';
  *bufferLen = rcode;

  // gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Network,
  // GSIDebugLevel_RawDump,
  //               "Received %d bytes\n", rcode);

  // Notify app.
  //////////////
  return GHIRecvData;
}
#else
asm GHIRecvResult ghiDoReceive(GHIConnection* connection, char buffer[],
                               int* bufferLen) {
  nofralloc;
  stwu r1, -32(r1);
  mflr r0;
  stw r0, 36(r1);
  stw r31, 28(r1);
  mr r31, r3;
  stw r30, 24(r1);
  stw r29, 20(r1);
  mr r29, r5;
  stw r28, 16(r1);
  mr r28, r4;
  lwz r0, 344(r3);
  lwz r3, 0(r5);
  cmpwi r0, 0x0;
  addi r30, r3, -0x1;
  beq loc6;
loc1:
  bl current_time;
  lwz r4, 348(r31);
  lwz r0, -30244(r13);
  add r0, r4, r0;
  cmplw r3, r0;
  bge loc3;
loc2:
  li r3, 0x1;
  b loc25;
loc3:
  stw r3, 348(r31);
  lwz r0, -30248(r13);
  cmpw r30, r0;
  bge loc5;
loc4:
  mr r0, r30;
loc5:
  mr r30, r0;
loc6:
  lwz r0, 404(r31);
  cmpwi r0, 0x0;
  beq loc14;
loc7:
  lwz r0, 416(r31);
  cmpwi r0, 0x1;
  bne loc14;
loc8:
  lwz r0, 424(r31);
  cmpwi r0, 0x1;
  bne loc14;
loc9:
  stw r30, 8(r1);
  mr r3, r31;
  mr r5, r28;
  addi r4, r31, 0x190;
  addi r6, r1, 0x8;
  bl ghiEncryptorSslDecryptRecv;
  cmpwi r3, 0x1;
  bne loc13;
loc10:
  lwz r4, 8(r1);
  cmpwi r4, -0x1;
  bne loc22;
loc11:
  li r3, 0x1;
  b loc25;
loc12:
  // ??????????????????????????????
  b loc22;
loc13:
  li r5, 0x1;
  li r4, 0x5;
  li r0, 0x0;
  stw r5, 288(r31);
  li r3, 0x3;
  stw r4, 60(r31);
  stw r0, 80(r31);
  stw r5, 340(r31);
  b loc25;
loc14:
  lwz r3, 76(r31);
  mr r4, r28;
  mr r5, r30;
  li r6, 0x0;
  bl recv;
  cmpwi r3, -0x1;
  mr r4, r3;
  bne loc22;
loc15:
  lwz r3, 76(r31);
  bl GOAGetLastError;
  cmpwi r3, -0x38;
  bne loc17;
loc16:
  li r0, 0x1;
  li r3, 0x2;
  stw r0, 340(r31);
  b loc25;
loc17:
  cmpwi r3, -0x6;
  beq loc20;
loc18:
  cmpwi r3, -0x1a;
  beq loc20;
loc19:
  cmpwi r3, -0x4c;
  bne loc21;
loc20:
  li r3, 0x1;
  b loc25;
loc21:
  li r4, 0x1;
  li r0, 0x5;
  stw r3, 80(r31);
  li r3, 0x3;
  stw r4, 288(r31);
  stw r0, 60(r31);
  stw r4, 340(r31);
  b loc25;
loc22:
  cmpwi r4, 0x0;
  bne loc24;
loc23:
  li r0, 0x1;
  li r3, 0x2;
  stw r0, 340(r31);
  b loc25;
loc24:
  li r0, 0x0;
  li r3, 0x0;
  stbx r0, r28, r4;
  stw r4, 0(r29);
loc25:
  lwz r0, 36(r1);
  lwz r31, 28(r1);
  lwz r30, 24(r1);
  lwz r29, 20(r1);
  lwz r28, 16(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}
#endif

asm int ghiDoSend(struct GHIConnection* connection, const char* buffer,
                  int len) {
  stwu r1, -32(r1);
  mflr r0;
  cmpwi r4, 0x0;
  mr r6, r5;
  stw r0, 36(r1);
  stw r31, 28(r1);
  stw r30, 24(r1);
  mr r30, r3;
  beq loc2;
loc1:
  cmpwi r5, 0x0;
  bne loc3;
loc2:
  li r3, 0x0;
  b loc20;
loc3:
  lwz r0, 404(r3);
  cmpwi r0, 0x0;
  beq loc11;
loc4:
  lwz r0, 416(r3);
  cmpwi r0, 0x1;
  bne loc11;
loc5:
  lwz r0, 424(r3);
  cmpwi r0, 0x1;
  bne loc11;
loc6:
  li r31, 0x0;
  mr r5, r4;
  stw r31, 8(r1);
  addi r4, r3, 0x190;
  addi r7, r1, 0x8;
  bl ghiEncryptorSslEncryptSend;
  cmpwi r3, 0x1;
  bne loc10;
loc7:
  lwz r3, 8(r1);
  cmpwi r3, -0x1;
  bne loc17;
loc8:
  li r3, -0x2;
  b loc20;
loc9:
  b loc17;
loc10:
  li r3, 0x1;
  li r0, 0x5;
  stw r3, 288(r30);
  li r3, -0x1;
  stw r0, 60(r30);
  stw r31, 80(r30);
  b loc20;
loc11:
  lwz r3, 76(r3);
  mr r5, r6;
  li r6, 0x0;
  bl send;
  cmpwi r3, -0x1;
  bne loc17;
loc12:
  lwz r3, 76(r30);
  bl GOAGetLastError;
  cmpwi r3, -0x6;
  beq loc15;
loc13:
  cmpwi r3, -0x1a;
  beq loc15;
loc14:
  cmpwi r3, -0x4c;
  bne loc16;
loc15:
  li r3, 0x0;
  b loc20;
loc16:
  li r4, 0x1;
  li r0, 0x5;
  stw r3, 80(r30);
  li r3, -0x1;
  stw r4, 288(r30);
  stw r0, 60(r30);
  b loc20;
loc17:
  lwz r0, 16(r30);
  cmpwi r0, 0x6;
  bne loc20;
loc18:
  lwz r0, 380(r30);
  cmpwi r0, 0x0;
  bne loc20;
loc19:
  lwz r0, 364(r30);
  add r0, r0, r3;
  stw r0, 364(r30);
loc20:
  lwz r0, 36(r1);
  lwz r31, 28(r1);
  lwz r30, 24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
}

// Re-enable previously disabled compiler warnings
///////////////////////////////////////////////////
#if defined(_MSC_VER)
#pragma warning(default : 4127)
#endif // _MSC_VER
