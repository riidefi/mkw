///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "ghttpCommon.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
GHTTPBool ghttpSetRequestEncryptionEngine(GHTTPRequest request,
                                          GHTTPEncryptionEngine engine) {
  GHIConnection* connection = ghiRequestToConnection(request);
  if (!connection)
    return GHTTPFalse;

  // Translate default into the actual engine name
  // We don't want to set the engine value to "default" because
  //   we'd lose the ability to determine the engine name in other places
  if (engine == GHTTPEncryptionEngine_Default) {
    engine = GHTTPEncryptionEngine_RevoEx;
  }

  // If the same engine has previously been set then we're done
  if (connection->encryptor.mEngine == engine)
    return GHTTPTrue;

  // If a different engine has previously been set then we're screwed
  if (connection->encryptor.mInterface != NULL &&
      connection->encryptor.mEngine != engine) {
    return GHTTPFalse;
  }

  // If the URL is HTTPS but the engine is specific as NONE then we can't
  // connect
  if ((engine == GHTTPEncryptionEngine_None) &&
      (strncmp(connection->URL, "https://", 8) == 0))
    return GHTTPFalse;

  // Initialize the engine
  connection->encryptor.mEngine = engine;

  if (engine == GHTTPEncryptionEngine_None) {
    connection->encryptor.mInterface = NULL;
    return GHTTPTrue; // this is the default, just return
  } else {
    // 02OCT07 BED: Design was changed to only allow one engine at a time
    //              Assert that the specified engine is the one supported
    if (engine != GHTTPEncryptionEngine_Default) {
      GS_ASSERT(engine == GHTTPEncryptionEngine_RevoEx);
    }

    connection->encryptor.mInterface = NULL;
    connection->encryptor.mInitFunc = ghiEncryptorSslInitFunc;
    connection->encryptor.mStartFunc = ghiEncryptorSslStartFunc;
    connection->encryptor.mCleanupFunc = ghiEncryptorSslCleanupFunc;
    connection->encryptor.mEncryptFunc = ghiEncryptorSslEncryptFunc;
    connection->encryptor.mDecryptFunc = ghiEncryptorSslDecryptFunc;
    connection->encryptor.mInitialized = GHTTPFalse;
    connection->encryptor.mSessionStarted = GHTTPFalse;
    connection->encryptor.mSessionEstablished = GHTTPFalse;
    connection->encryptor.mEncryptOnBuffer = GHTTPTrue;
    connection->encryptor.mEncryptOnSend = GHTTPFalse;
    connection->encryptor.mLibSendsHandshakeMessages = GHTTPFalse;
    return GHTTPTrue;
  }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// *********************  REVOEX SSL ENCRYPTION ENGINE  ******************** //
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <rvl/ssl.h>

typedef struct gsRevoExInterface {
  int mId;
  int mClientCertId;
  int mRootCAId;
  GHTTPBool mConnected; // means "connected to socket", not "connected to remote
                        // machine"
} gsRevoExInterface;

// Init the engine
GHIEncryptionResult ghiEncryptorSslInitFunc(struct GHIConnection* connection,
                                            struct GHIEncryptor* theEncryptor) {
  int i = 0;
  gsRevoExInterface* sslInterface = NULL;

  // There is only one place where this function should be called,
  //  and it should check if the engine has been initialized
  GS_ASSERT(theEncryptor->mInitialized == GHTTPFalse);
  GS_ASSERT(theEncryptor->mInterface == NULL);

  // allocate the interface (need one per connection)
  theEncryptor->mInterface = gsimalloc(sizeof(gsRevoExInterface));
  if (theEncryptor->mInterface == NULL) {
    // memory allocation failed
    gsDebugFormat(
        GSIDebugCat_HTTP, GSIDebugType_Memory, GSIDebugLevel_WarmError,
        "Failed to allocate SSL interface (out of memory: %d bytes)\r\n",
        sizeof(gsRevoExInterface));
    return GHIEncryptionResult_Error;
  }
  memset(theEncryptor->mInterface, 0, sizeof(gsRevoExInterface));
  sslInterface = (gsRevoExInterface*)theEncryptor->mInterface;

  {
    int verifyOption = 0;
    int rcode = 0;

    // verifyOption = SSL_VERIFY_COMMON_NAME | SSL_VERIFY_ROOT_CA |
    //               SSL_VERIFY_DATE | SSL_VERIFY_CHAIN |
    //               SSL_VERIFY_SUBJECT_ALT_NAME;
    verifyOption = 0xb;

    // todo serverAddress, is this used for certificate name?
    sslInterface->mId = SSLNew(verifyOption, connection->serverAddress);

    rcode = SSLSetBuiltinRootCA(sslInterface->mId, 1);
    if (rcode != SSL_ENONE) {
      SSLShutdown(sslInterface->mId);
      return GHIEncryptionResult_Error;
    }

    rcode = SSLSetBuiltinClientCert(sslInterface->mId, 0);
    if (rcode != SSL_ENONE) {
      SSLShutdown(sslInterface->mId);
      return GHIEncryptionResult_Error;
    }
  }

  theEncryptor->mInitialized = GHTTPTrue;
  theEncryptor->mSessionStarted = GHTTPFalse;
  theEncryptor->mSessionEstablished = GHTTPFalse;
  // theEncryptor->mUseSSLConnect = GHTTPTrue;
  theEncryptor->mEncryptOnBuffer = GHTTPFalse;
  theEncryptor->mEncryptOnSend = GHTTPTrue;
  theEncryptor->mLibSendsHandshakeMessages = GHTTPTrue;

  gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                "GameSpy SSL (RevoEx engine) initialized\r\n");

  return GHIEncryptionResult_Success;
}

// Destroy the engine
GHIEncryptionResult
ghiEncryptorSslCleanupFunc(struct GHIConnection* connection,
                           struct GHIEncryptor* theEncryptor) {
  if (theEncryptor != NULL) {
    gsRevoExInterface* sslInterface =
        (gsRevoExInterface*)theEncryptor->mInterface;
    if (sslInterface != NULL) {
      SSLShutdown(sslInterface->mId);
      gsifree(sslInterface);
      theEncryptor->mInterface = NULL;
    }
    theEncryptor->mInitialized = GHTTPFalse;
    theEncryptor->mSessionStarted = GHTTPFalse;
    theEncryptor->mSessionEstablished = GHTTPFalse;
  }

  gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                "GameSpy SSL (RevoEx) engine cleanup called\r\n");

  GSI_UNUSED(connection);

  return GHIEncryptionResult_Success;
}

GHIEncryptionResult
ghiEncryptorSslStartFunc(struct GHIConnection* connection,
                         struct GHIEncryptor* theEncryptor) {
  gsRevoExInterface* sslInterface =
      (gsRevoExInterface*)theEncryptor->mInterface;
  int result = 0;

  GS_ASSERT(theEncryptor->mSessionStarted == GHTTPFalse);

  // Call this only AFTER the socket has been connected to the remote server
  if (!sslInterface->mConnected) {
    result = SSLConnect(sslInterface->mId, connection->socket);
    if (result != SSL_ENONE) {
      switch (result) {
      case SSL_EFAILED:
        gsDebugFormat(
            GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
            "GameSpy SSL (RevoEx) SSLConnect failed (SSL_EFAILED)\r\n");
        break;
      case SSL_ESSLID:
        gsDebugFormat(
            GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
            "GameSpy SSL (RevoEx) SSLConnect failed (SSL_ESSLID)\r\n");
        break;
      default:
        gsDebugFormat(
            GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
            "GameSpy SSL (RevoEx) SSLConnect failed (Unhandled Error)\r\n");
        break;
      }
      return GHIEncryptionResult_Error;
    }
    sslInterface->mConnected = GHTTPTrue;
  }

  GS_ASSERT(sslInterface->mConnected == GHTTPTrue);

  // begin securing the session
  result = SSLDoHandshake(sslInterface->mId);
  if (result != SSL_ENONE) {
    // Check for EWOULDBLOCK conditions
    if (result == SSL_EWANT_READ || result == SSL_EWANT_WRITE)
      return GHIEncryptionResult_Success;

    switch (result) {
    case SSL_EFAILED:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_EFAILED)\r\n");
      break;
    case SSL_ESSLID:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_ESSLID)\r\n");
      break;
    case SSL_ESYSCALL:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_ESYSCALL)\r\n");
      break;
    case SSL_EZERO_RETURN:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_EZERO_RETURN)\r\n");
      break;
    case SSL_EWANT_CONNECT:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_EWANT_CONNECT)\r\n");
      break;
    case SSL_EVERIFY_COMMON_NAME:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLDoHandshake failed "
                    "(SSL_EVERIFY_COMMON_NAME)\r\n");
      break;
    case SSL_EVERIFY_CHAIN:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_EVERIFY_CHAIN)\r\n");
      break;
    case SSL_EVERIFY_ROOT_CA:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLDoHandshake failed "
                    "(SSL_EVERIFY_ROOT_CA)\r\n");
      break;
    case SSL_EVERIFY_DATE:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (SSL_EVERIFY_DATE)\r\n");
      break;
    default:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLDoHandshake failed (Unhandled Error)\r\n");
      break;
    }
    return GHIEncryptionResult_Error;
  }

  // Success
  theEncryptor->mSessionStarted = GHTTPTrue;
  theEncryptor->mSessionEstablished = GHTTPTrue;
  return GHIEncryptionResult_Success;
}

// Encrypt and send some data
GHIEncryptionResult
ghiEncryptorSslEncryptSend(struct GHIConnection* connection,
                           struct GHIEncryptor* theEncryptor,
                           const char* thePlainTextBuffer,
                           int thePlainTextLength, int* theBytesSentOut) {
  gsRevoExInterface* sslInterface =
      (gsRevoExInterface*)theEncryptor->mInterface;
  int result = 0;

  result = SSLWrite(sslInterface->mId, thePlainTextBuffer, thePlainTextLength);
  if (result == SSL_EWANT_WRITE) {
    // signal socket error, GetLastError will return EWOULDBLOCK or EINPROGRESS
    *theBytesSentOut = -1;
  } else if (result < 0) {
    switch (result) {
    case SSL_EFAILED:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLWrite failed (SSL_EFAILED)\r\n");
      break;
    case SSL_ESSLID:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLWrite failed (SSL_ESSLID)\r\n");
      break;
    case SSL_EWANT_READ:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLWrite failed (SSL_EWANT_READ)\r\n");
      break;
    case SSL_ESYSCALL:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLWrite failed (SSL_ESYSCALL)\r\n");
      break;
    case SSL_EWANT_CONNECT:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLWrite failed (SSL_EWANT_CONNECT)\r\n");
      break;
    default:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLWrite failed (Unhandled Error)\r\n");
      break;
    }
    return GHIEncryptionResult_Error;
  } else {
    GS_ASSERT(result > 0);
    *theBytesSentOut = result;
  }
  GSI_UNUSED(connection);
  return GHIEncryptionResult_Success;
}

// Receive and decrypt some data
GHIEncryptionResult
ghiEncryptorSslDecryptRecv(struct GHIConnection* connection,
                           struct GHIEncryptor* theEncryptor,
                           char* theDecryptedBuffer, int* theDecryptedLength) {
  gsRevoExInterface* sslInterface =
      (gsRevoExInterface*)theEncryptor->mInterface;
  int result = 0;

  result = SSLRead(sslInterface->mId, theDecryptedBuffer, *theDecryptedLength);
  if (result == SSL_EZERO_RETURN) {
    // receive 0 is not fatal
    *theDecryptedLength = 0;
  } else if (result == SSL_EWANT_READ) {
    // signal socket error, GetLastError will return EWOULDBLOCK or EINPROGRESS
    *theDecryptedLength = -1;
  } else if (result < 0) {
    // Fatal errors
    switch (result) {
    case SSL_EFAILED:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLRead failed (SSL_EFAILED)\r\n");
      break;
    case SSL_ESSLID:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLRead failed (SSL_ESSLID)\r\n");
      break;
    case SSL_EWANT_WRITE:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLRead failed (SSL_EWANT_WRITE)\r\n");
      break;
    case SSL_ESYSCALL:
      gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
                    "GameSpy SSL (RevoEx) SSLRead failed (SSL_ESYSCALL)\r\n");
      break;
    case SSL_EWANT_CONNECT:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLRead failed (SSL_EWANT_CONNECT)\r\n");
      break;
    default:
      gsDebugFormat(
          GSIDebugCat_HTTP, GSIDebugType_Misc, GSIDebugLevel_Debug,
          "GameSpy SSL (RevoEx) SSLRead failed (Unhandled Error)\r\n");
      break;
    }
    return GHIEncryptionResult_Error;
  } else {
    GS_ASSERT(result > 0);
    *theDecryptedLength = result;
  }
  GSI_UNUSED(connection);
  return GHIEncryptionResult_Success;
}

GHIEncryptionResult ghiEncryptorSslEncryptFunc(
    struct GHIConnection* connection, struct GHIEncryptor* theEncryptor,
    const char* thePlainTextBuffer, int thePlainTextLength,
    char* theEncryptedBuffer, int* theEncryptedLength) {
  GS_FAIL(); // Should never call this for RevoEx SSL!  It uses encrypt on send

  GSI_UNUSED(connection);
  GSI_UNUSED(theEncryptor);
  GSI_UNUSED(thePlainTextBuffer);
  GSI_UNUSED(thePlainTextLength);
  GSI_UNUSED(theEncryptedBuffer);
  GSI_UNUSED(theEncryptedLength);

  return GHIEncryptionResult_Error;
}

GHIEncryptionResult ghiEncryptorSslDecryptFunc(
    struct GHIConnection* connection, struct GHIEncryptor* theEncryptor,
    const char* theEncryptedBuffer, int* theEncryptedLength,
    char* theDecryptedBuffer, int* theDecryptedLength) {
  GS_FAIL(); // Should never call this for RevoEx SSL!  It uses decrypt on recv

  GSI_UNUSED(connection);
  GSI_UNUSED(theEncryptor);
  GSI_UNUSED(theEncryptedBuffer);
  GSI_UNUSED(theEncryptedLength);
  GSI_UNUSED(theDecryptedBuffer);
  GSI_UNUSED(theDecryptedLength);

  return GHIEncryptionResult_Error;
}
