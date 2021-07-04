#pragma once

#ifndef MSL_CTYPE_H
#define MSL_CTYPE_H

#include "rk_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define _COMPONENT_NAME_LEN  8

#if !_MSL_C_LOCALE_ONLY
struct _loc_ctype_cmpt
{

#if !_MSL_C_LOCALE_ONLY
	char   CmptName[_COMPONENT_NAME_LEN];
	const unsigned short * ctype_map_ptr;
	const unsigned char * upper_map_ptr;
	const unsigned char * lower_map_ptr;
#if _MSL_WIDE_CHAR
#if _MSL_C99
	const unsigned short * wctype_map_ptr;
	const wchar_t *       wupper_map_ptr;
	const wchar_t *       wlower_map_ptr;
#endif /* _MSL_C99 */
	__decode_mbyte  decode_mb;
	__encode_mbyte  encode_wc;
#endif	/* _MSL_WIDE_CHAR */
#endif	/* !_MSL_C_LOCALE_ONLY */					
	};

#elif _MSL_WIDE_CHAR && _MSL_C_LOCALE_ONLY

	struct _loc_ctype_cmpt
	{
	__decode_mbyte  decode_mb;
	__encode_mbyte  encode_wc;
	
	};

#endif

#define _LOCALE_NAME_LEN    48
struct __locale													/*- mm 011205 -*/
{
	struct __locale *   		next_locale;					/*- mm 011205 -*/
	char               			locale_name[_LOCALE_NAME_LEN];
	struct _loc_coll_cmpt * 	coll_cmpt_ptr; 
	struct _loc_ctype_cmpt *	ctype_cmpt_ptr; 
	struct _loc_mon_cmpt *  	mon_cmpt_ptr; 
	struct _loc_num_cmpt *  	num_cmpt_ptr; 
	struct _loc_time_cmpt * 	time_cmpt_ptr;
}; 

extern struct __locale _current_locale;

#ifndef _MSL_LOCALDATA
#define _MSL_LOCALDATA(_a) _a
#endif

#if !_MSL_C_LOCALE_ONLY	
		#define __msl_cmap_size 256
	#else
		#define __msl_cmap_size 128
	#endif	

#if _MSL_C_LOCALE_ONLY
	#define _MSL_CMAP_ACCESS __ctype_mapC
	#define _MSL_CLOWER_ACCESS __lower_mapC
	#define _MSL_CUPPER_ACCESS __upper_mapC
#else
	#define _MSL_CMAP_ACCESS _MSL_LOCALDATA(_current_locale).ctype_cmpt_ptr->ctype_map_ptr
	#define _MSL_CLOWER_ACCESS _MSL_LOCALDATA(_current_locale).ctype_cmpt_ptr->lower_map_ptr
	#define _MSL_CUPPER_ACCESS _MSL_LOCALDATA(_current_locale).ctype_cmpt_ptr->upper_map_ptr
#endif

#define __msl_alpha		0x0001
#define __msl_blank		0x0002
#define __msl_cntrl		0x0004
#define __msl_digit		0x0008
#define __msl_graph		0x0010
#define __msl_lower		0x0020
#define __msl_print		0x0040
#define __msl_punct		0x0080
#define __msl_space		0x0100
#define __msl_upper		0x0200
#define __msl_xdigit	0x0400

#define __msl_alnum		(__msl_alpha | __msl_digit)

	inline
	int isalnum(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_alnum); }
	inline
	int isalpha(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_alpha); }
#if _MSL_C99						/*- mm 030226 -*/
	inline
	int isblank(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_blank); }
#endif   /* _MSL_C99 */				/*- mm 030226 -*/
	inline
	int iscntrl(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_cntrl); }
	inline
	int isdigit(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_digit); }
	inline
	int isgraph(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_graph); }
	inline
	int islower(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_lower); }
	inline
	int isprint(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_print); }
	inline
	int ispunct(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_punct); }
	inline
	int isspace(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_space); }
	inline
	int isupper(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_upper); }
	inline
	int isxdigit(int c) 	{ return ((c < 0) || (c >= __msl_cmap_size)) ? 0 :  (int) (_MSL_CMAP_ACCESS[c] & __msl_xdigit); }
	inline int tolower(int c) { return ((c < 0) || (c >= __msl_cmap_size)) ? c : (int) (_MSL_CLOWER_ACCESS[c]); }
	inline int toupper(int c) { return ((c < 0) || (c >= __msl_cmap_size)) ? c : (int) (_MSL_CUPPER_ACCESS[c]); }

#ifdef __cplusplus
} // extern "C"
#endif

#endif // MSL_CTYPE_H