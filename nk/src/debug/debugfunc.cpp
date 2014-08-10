//=============================================================================
/*!	@file	debugfunc.cpp

	@brief	デバッグ処理

	@author	ryunosuke ide
	@date	2014.08.10
*/
//=============================================================================

#include <nk/debug/debugfunc.h>
#include <stdarg.h>

#if defined(_WIN32)
#include <windows.h>
#endif

namespace {
	
void _DefaultPrint( const char* text )
{
#if defined(WIN32)
	OutputDebugStringA( text );
#endif
}

void _DefaultAssert( const char* test, const char* file, int line, const char* text )
{
	nk::debug::Printf("---- assert ----\n");
	nk::debug::Printf("test : %s\n", test);
	nk::debug::Printf("%s\n", text);
	nk::debug::Printf("%s(%d)\n", file, line);
	nk::debug::Printf("----------------\n");

	nk::debug::Abort();
	
}

void _DefaultWarning( const char* text )
{
	(void)text;
}
	
}


namespace {
	nk::debug::PrintFunc	s_printFunc		= _DefaultPrint;	// 出力関数
	nk::debug::AssertFunc	s_assertFunc	= _DefaultAssert;	// アサート関数
}


namespace nk {
namespace debug {



//===========================================================================
/*!	@brief		デバッグプリント
	@param		fmt		出力フォーマット
*/
//===========================================================================
void Printf( const char* fmt, ... )
{
#if defined(WIN32)
	char debugOutBuff[512]	= { 0 };
	
	va_list argPtr;
	va_start( argPtr, fmt );


	if( !vsprintf_s( debugOutBuff, sizeof(debugOutBuff), fmt, argPtr ) ) {
		return;
	}

	(*s_printFunc)( debugOutBuff );

    va_end( argPtr );
#endif
}


//===========================================================================
/*!	@brief		printf出力関数設定
	@param		func	出力関数
	@return		none
*/
//===========================================================================
void SetPrintFunc( PrintFunc func )
{
	s_printFunc	= func;
}

	
	
//===========================================================================
/*!	@brief		アサート時呼び出し処理
	@param		
	@return		----
*/
//===========================================================================
void Assert( const char* test, const char* file, int line, const char* fmt, ... )
{
#if defined(WIN32)
	char debugOutBuff[512]	= { 0 };
	
	va_list argPtr;
	va_start( argPtr, fmt );


	if( !vsprintf_s( debugOutBuff, sizeof(debugOutBuff), fmt, argPtr ) ) {
		return;
	}

	(*s_assertFunc)( test, file, line, debugOutBuff );

    va_end( argPtr );
#endif
}


//===========================================================================
/*!	@brief		アサート出力関数設定
	@param		func	出力関数
	@return		none
*/
//===========================================================================
void SetAssertFunc( AssertFunc func )
{
	s_assertFunc	= func;
}


//===========================================================================
/*!	@brief		ワーニング時呼び出し処理
	@param		fmt		出力フォーマット
	@return		----
*/
//===========================================================================
// void Warning( const char* fmt, ... )
// {
// }


//===========================================================================
/*!	@brief		アサート出力関数設定
	@param		func	出力関数
	@return		none
*/
//===========================================================================
// void SetWarningtFunc( AssertFunc func )
// {
// }


}	// namespace debug
}	// namespace nk




