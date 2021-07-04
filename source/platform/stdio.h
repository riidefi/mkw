#pragma once

#include <rk_types.h>

typedef struct _FILE FILE;

typedef unsigned long __file_handle;

typedef unsigned long fpos_t;

typedef void * __ref_con;
typedef void (* __idle_proc)  (void);
typedef int  (* __pos_proc)   (__file_handle file, fpos_t * position, int mode, __ref_con ref_con);     /*- mm 970708 -*/
typedef int  (* __io_proc)    (__file_handle file, unsigned char * buff, size_t * count, __ref_con ref_con);
typedef int	 (* __close_proc) (__file_handle file);

typedef struct
{
	unsigned int	open_mode	: 2;
	unsigned int	io_mode		: 3;
	unsigned int	buffer_mode	: 2;
	unsigned int	file_kind	: 3;			/*- mm 980708 -*/
	
	unsigned int	binary_io	: 1;
} __file_modes;

typedef struct
{
	unsigned int	io_state	: 3;
	unsigned int	free_buffer	: 1;
	unsigned char	eof;
	unsigned char	error;
} __file_state;

#define __ungetc_buffer_size 2

struct _FILE
{
	__file_handle		handle;
	__file_modes		mode;
	__file_state		state;
	
	#if _MSL_OS_DISK_FILE_SUPPORT
		unsigned char	is_dynamically_allocated;			/*- mm 981007 -*/
	#endif /* _MSL_OS_DISK_FILE_SUPPORT */
	
	unsigned char		char_buffer;
	unsigned char		char_buffer_overflow;
	unsigned char		ungetc_buffer[__ungetc_buffer_size];
	
	#if _MSL_WIDE_CHAR
		wchar_t			ungetwc_buffer[__ungetc_buffer_size];
	#endif /* _MSL_WIDE_CHAR */
	
	unsigned long		position;
	unsigned char *		buffer;
	unsigned long		buffer_size;
	unsigned char *		buffer_ptr;
	unsigned long		buffer_len;
	unsigned long		buffer_alignment;
	unsigned long		saved_buffer_len;
	unsigned long		buffer_pos;
	__pos_proc			position_proc;
	__io_proc			read_proc;
	__io_proc			write_proc;
	__close_proc		close_proc;
	__ref_con			ref_con;
	
	#if _MSL_OS_DISK_FILE_SUPPORT
		struct _FILE *	next_file_struct;					/*- mm 981007 -*/
	#endif /* _MSL_OS_DISK_FILE_SUPPORT */
};

int sprintf ( char * str, const char * format, ... );

int sscanf(const char *str, const char *format, ...);
