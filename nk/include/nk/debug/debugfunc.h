//=============================================================================
/*!	@file	debugfunc.h
	@brief	デバッグ処理
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_DEBUGFUNC_H
#define NK_DEBUGFUNC_H

#include <stdio.h>

namespace nk {
namespace debug {



//! printf時出力関数
typedef void (*PrintFunc)( const char* text );
	
//! assert時出力関数
typedef void (*AssertFunc)( const char* test, const char* file, int line, const char* text );

	

//===========================================================================
/*!	@brief		デバッグプリント
	@param		fmt		出力フォーマット
*/
//===========================================================================
void Printf( const char* fmt, ... );


//===========================================================================
/*!	@brief		printf出力関数設定
	@param		func	出力関数
	@return		none
*/
//===========================================================================
void SetPrintFunc( PrintFunc func );

	
	
//===========================================================================
/*!	@brief		アサート時呼び出し処理
	@param		
	@return		----
*/
//===========================================================================
void Assert( const char* test, const char* file, int line, const char* fmt, ... );


//===========================================================================
/*!	@brief		アサート出力関数設定
	@param		func	出力関数
	@return		none
*/
//===========================================================================
void SetAssertFunc( AssertFunc func );


//===========================================================================
/*!	@brief		ワーニング時呼び出し処理
	@param		fmt		出力フォーマット
	@return		----
*/
//===========================================================================
// void Warning( const char* fmt, ... );


//===========================================================================
/*!	@brief		アサート出力関数設定
	@param		func	出力関数
	@return		none
*/
//===========================================================================
// void SetWarningtFunc( AssertFunc func );


//===========================================================================
/*!	@brief		アボート
	@param		none
	@return		none
	@note		わざとハングを起こします
*/
//===========================================================================
inline void Abort()
{
	int*	a	= NULL;
	*a			= 0;
}
	
}	// namespace debug
}	// namespace nk




#endif  // NK_DEBUGFUNC_H
