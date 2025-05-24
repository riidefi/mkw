#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FILENAME_MAX 256

typedef struct _FILE FILE;

typedef unsigned long __file_handle;

typedef unsigned long fpos_t;

typedef void* __ref_con;
typedef void (*__idle_proc)(void);
typedef int (*__pos_proc)(__file_handle file, fpos_t* position, int mode,
                          __ref_con ref_con);
typedef int (*__io_proc)(__file_handle file, unsigned char* buff, size_t* count,
                         __ref_con ref_con);
typedef int (*__close_proc)(__file_handle file);

typedef struct {
  unsigned int open_mode : 2;
  unsigned int io_mode : 3;
  unsigned int buffer_mode : 2;
  unsigned int file_kind : 3;

  unsigned int binary_io : 1;
} __file_modes;

typedef struct {
  unsigned int io_state : 3;
  unsigned int free_buffer : 1;
  unsigned char eof;
  unsigned char error;
} __file_state;

struct _FILE {
  __file_handle handle;
  __file_modes mode;
  __file_state state;

  unsigned char char_buffer;
  unsigned char char_buffer_overflow;
  unsigned char ungetc_buffer[2];

  unsigned long position;
  unsigned char* buffer;
  unsigned long buffer_size;
  unsigned char* buffer_ptr;
  unsigned long buffer_len;
  unsigned long buffer_alignment;
  unsigned long saved_buffer_len;
  unsigned long buffer_pos;
  __pos_proc position_proc;
  __io_proc read_proc;
  __io_proc write_proc;
  __close_proc close_proc;
  __ref_con ref_con;
};

#define EOF (-1)

#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

typedef char* va_list;

int sprintf(char* str, const char* format, ...);
int snprintf(char* s, size_t n, const char* format, ...);
#ifdef __CWCC__
int vsnprintf(char* s, size_t n, const char* format, va_list arg);
int vprintf(const char* format, va_list arg);
int vsprintf(char* s, const char* format, va_list arg);
#endif

int sscanf(const char* str, const char* format, ...);

FILE* fopen(const char* filename, const char* mode);
int fclose(FILE* stream);
int fseek(FILE* stream, long int offset, int origin);
long int ftell(FILE* stream);
size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
void rewind(FILE* stream);

int remove(const char* pathname);

#ifdef __cplusplus
}
#endif
