//=============================================================================
/*!	@file	macros.h
	@brief	�ėp�}�N��
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

//! ���r�b�g�V�t�g
#define NKBITSHIFT_L(a)				(1 << (a))

//! �E�r�b�g�V�t�g
#define NKBITSHIFT_R(a)				(1 >> (a))

//! �z��T�C�Y
#define NKARRAY_SIZE(ary)			(sizeof(ary) / sizeof(ary[0]))


#if !defined(_RELEASE)

	//! printf
	#define	NKPRINTF(fmt, ...)								nk::debug::Printf(fmt, __VA_ARGS__)
	
	//! �A�T�[�g	
	#define NKASSERT(test, fmt, ...)						if(!(test)) { nk::debug::Assert( #test, __FILE__, __LINE__, fmt, __VA_ARGS__ ); }

	//! �C���f�b�N�X�A�T�[�g
	//! idx��(0 <= idx < max)�͈̔͊O�ł���΃v���O�������~���܂�
	#define NKASSERT_INDEX(idx, max, fmt, ...)				NKASSERT( (0 <= (idx)) && ((idx) < (max)), fmt, __VA_ARGS__ )

	//! �͈̓A�T�[�g
	//! value��(first <= value <= last)�͈̔͊O�ł���΃v���O�������~���܂�
	#define NKASSERT_RANGE(value, first, last, fmt, ...)	NKASSERT( ((first) <= (value)) && ((value) <= (last)), fmt, __VA_ARGS__ )

	//! NULL�A�T�[�g
	#define NKASSERT_NULL(var)								NKASSERT( (var), "null assert : " #var )

	//! ���[�j���O
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
