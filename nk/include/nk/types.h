//=============================================================================
/*!	@file	types.h
	@brief	�^��`
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_TYPES_H
#define NK_TYPES_H


#if defined(WIN32)
	typedef char						s8;
	typedef unsigned char				u8;
	typedef short						s16;
	typedef unsigned short				u16;
	typedef int							s32;
	typedef	unsigned					u32;
	typedef	long long					s64;
	typedef	unsigned long long	 		u64;
	typedef	float						f32;
	typedef	double						f64;

#elif defined(_WIN64)
	typedef char						s8;
	typedef unsigned char				u8;
	typedef short						s16;
	typedef unsigned short				u16;
	typedef int							s32;
	typedef	unsigned					u32;
	typedef	long						s64;
	typedef	unsigned long		 		u64;
	typedef	float						f32;
	typedef	double						f64;
#else
	#error
#endif

#if defined(_WINDOWS)
	#define NK_PROCESS_INSTANCE			HINSTANCE
	#define NK_WINDOW_HANDLE			HWND
#else
	#define NK_PROCESS_INSTANCE			u32
	#define NK_WINDOW_HANDLE			u32
#endif



#endif  // NK_TYPES_H
