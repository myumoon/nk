//=============================================================================
/*!	@file	macros.h
	@brief	汎用マクロ
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_MACROS_H
#define NK_MACROS_H

// #include <stdlib.h>
// #include <stdio.h>
#include <nk/debug/debugfunc.h>

//! 左ビットシフト
#define NKBITSHIFT_L(a)				(1 << (a))

//! 右ビットシフト
#define NKBITSHIFT_R(a)				(1 >> (a))

//! 配列サイズ
#define NKARRAY_SIZE(ary)			(sizeof(ary) / sizeof(ary[0]))


#if !defined(_RELEASE)

	//! printf
	#define	NKPRINTF(fmt, ...)								nk::debug::Printf(fmt, __VA_ARGS__)
	
	//! アサート	
	#define NKASSERT(test, fmt, ...)						if(!(test)) { nk::debug::Assert( #test, __FILE__, __LINE__, fmt, __VA_ARGS__ ); }

	//! インデックスアサート
	//! idxが(0 <= idx < max)の範囲外であればプログラムを停止します
	#define NKASSERT_INDEX(idx, max, fmt, ...)				NKASSERT( (0 <= (idx)) && ((idx) < (max)), fmt, __VA_ARGS__ )

	//! 範囲アサート
	//! valueが(first <= value <= last)の範囲外であればプログラムを停止します
	#define NKASSERT_RANGE(value, first, last, fmt, ...)	NKASSERT( ((first) <= (value)) && ((value) <= (last)), fmt, __VA_ARGS__ )

	//! NULLアサート
	#define NKASSERT_NULL(var)								NKASSERT( (var), "null assert : " #var )

	//! ワーニング
	//#define NKWARNING(test, fmt, ...)						if(!(test)) { nk::debug::Warning( #test, fmt, __FILE__, __LINE__, __VA_ARGS__ ); }

#else
	#define NKPRINTF(...)									((void)0)
	#define NKABORT(...)									((void)0)
	#define NKASSERT(...)									((void)0)
	#define NKASSERT_INDEX(...)								((void)0)
	#define NKASSERT_RANGE(...)								((void)0)
	#define NKASSERT_NULL(...)								((void)0)
	//#define NKWARNING(...)									((void)0)
#endif


#endif  // NK_MACROS_H
