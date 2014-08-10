//=============================================================================
/*!	@file	debugfunc.h

	@brief	�f�o�b�O����

	@author	ryunosuke ide
	@date	2014.08.10
*/
//=============================================================================

#ifndef NK_DEBUGFUNC_H
#define NK_DEBUGFUNC_H

#include <stdio.h>

namespace nk {
namespace debug {



//! printf���o�͊֐�
typedef void (*PrintFunc)( const char* text );
	
//! assert���o�͊֐�
typedef void (*AssertFunc)( const char* test, const char* file, int line, const char* text );

	

//===========================================================================
/*!	@brief		�f�o�b�O�v�����g
	@param		fmt		�o�̓t�H�[�}�b�g
*/
//===========================================================================
void Printf( const char* fmt, ... );


//===========================================================================
/*!	@brief		printf�o�͊֐��ݒ�
	@param		func	�o�͊֐�
	@return		none
*/
//===========================================================================
void SetPrintFunc( PrintFunc func );

	
	
//===========================================================================
/*!	@brief		�A�T�[�g���Ăяo������
	@param		
	@return		----
*/
//===========================================================================
void Assert( const char* test, const char* file, int line, const char* fmt, ... );


//===========================================================================
/*!	@brief		�A�T�[�g�o�͊֐��ݒ�
	@param		func	�o�͊֐�
	@return		none
*/
//===========================================================================
void SetAssertFunc( AssertFunc func );


//===========================================================================
/*!	@brief		���[�j���O���Ăяo������
	@param		fmt		�o�̓t�H�[�}�b�g
	@return		----
*/
//===========================================================================
// void Warning( const char* fmt, ... );


//===========================================================================
/*!	@brief		�A�T�[�g�o�͊֐��ݒ�
	@param		func	�o�͊֐�
	@return		none
*/
//===========================================================================
// void SetWarningtFunc( AssertFunc func );


//===========================================================================
/*!	@brief		�A�{�[�g
	@param		none
	@return		none
	@note		�킴�ƃn���O���N�����܂�
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
