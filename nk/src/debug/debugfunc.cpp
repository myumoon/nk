//=============================================================================
/*!	@file	debugfunc.cpp

	@brief	�f�o�b�O����

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
	nk::debug::PrintFunc	s_printFunc		= _DefaultPrint;	// �o�͊֐�
	nk::debug::AssertFunc	s_assertFunc	= _DefaultAssert;	// �A�T�[�g�֐�
}


namespace nk {
namespace debug {



//===========================================================================
/*!	@brief		�f�o�b�O�v�����g
	@param		fmt		�o�̓t�H�[�}�b�g
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
/*!	@brief		printf�o�͊֐��ݒ�
	@param		func	�o�͊֐�
	@return		none
*/
//===========================================================================
void SetPrintFunc( PrintFunc func )
{
	s_printFunc	= func;
}

	
	
//===========================================================================
/*!	@brief		�A�T�[�g���Ăяo������
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
/*!	@brief		�A�T�[�g�o�͊֐��ݒ�
	@param		func	�o�͊֐�
	@return		none
*/
//===========================================================================
void SetAssertFunc( AssertFunc func )
{
	s_assertFunc	= func;
}


//===========================================================================
/*!	@brief		���[�j���O���Ăяo������
	@param		fmt		�o�̓t�H�[�}�b�g
	@return		----
*/
//===========================================================================
// void Warning( const char* fmt, ... )
// {
// }


//===========================================================================
/*!	@brief		�A�T�[�g�o�͊֐��ݒ�
	@param		func	�o�͊֐�
	@return		none
*/
//===========================================================================
// void SetWarningtFunc( AssertFunc func )
// {
// }


}	// namespace debug
}	// namespace nk




