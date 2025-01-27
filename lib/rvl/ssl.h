#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum SSLError {
  SSL_ENONE = 0,
  SSL_EFAILED = -1,
  SSL_EWANT_READ = -2,
  SSL_EWANT_WRITE = -3,
  SSL_ESYSCALL = -5,
  SSL_EZERO_RETURN = -6,
  SSL_EWANT_CONNECT = -7,
  SSL_ESSLID = -8,
  SSL_EVERIFY_COMMON_NAME = -9,
  SSL_EVERIFY_ROOT_CA = -10,
  SSL_EVERIFY_CHAIN = -11,
  SSL_EVERIFY_DATE = -12,
  SSL_EGET_SERVER_CERT = -13
};

int SSLNew(u32, const char*);
int SSLConnect(int, int);
int SSLDoHandshake(int);
int SSLDoHandshakeEx(int, char*, size_t);
int SSLRead(int, char*, size_t);
int SSLWrite(int, const char*, size_t);
int SSLShutdown(int);
int SSLSetClientCert(int, const char*, size_t, const char*, size_t);
int SSLSetClientCertDefault(int);
int SSLRemoveClientCert(int);
int SSLSetRootCA(int, const char*, size_t);
int SSLSetRootCADefault(int);
int SSLSetBuiltinRootCA(int, int);
int SSLSetBuiltinClientCert(int, int);

#ifdef __cplusplus
}
#endif // __cplusplus
