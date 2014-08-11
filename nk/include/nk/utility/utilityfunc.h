//=============================================================================
/*!	@file	utilityfunc.h
	@brief	�ėp����
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_UTILITYFUNC_H
#define NK_UTILITYFUNC_H

//-------------------------------�C���N���[�h-------------------------------
#include <stdlib.h>
#include <stdio.h>

namespace nk {
	

//===========================================================================
/*!	@brief	�Z�[�t�f���[�g
	@param	obj : �폜����I�u�W�F�N�g
	@return	�Ȃ�
*/
//===========================================================================
template <typename T>
inline void SafeDelete( T*& obj )
{
	delete obj;
	obj = NULL;
}

	
//===========================================================================
/*!	@brief	�z��ŃZ�[�t�f���[�g
	@param	obj : �폜����I�u�W�F�N�g
	@return	�Ȃ�
*/
//===========================================================================
template <typename T>
inline void SafeDeleteArray( T*& obj )
{
	delete[] obj;
	obj = NULL;
}

	
//===========================================================================
/*!	@brief	�Z�[�t�t���[
	@param	obj : �폜����I�u�W�F�N�g
	@return	�Ȃ�
*/
//===========================================================================
template <typename T>
inline void SafeFree( T*& obj )
{
	free( obj );
	obj = NULL;
}

	
//===========================================================================
/*!	@brief	�I�u�W�F�N�g�̓���ւ�
	@param	s1,s2	: ����ւ���I�u�W�F�N�g
	@return	�Ȃ�
*/
//===========================================================================
template <typename T>
inline void Swap( T& s1, T& s2 )
{
	T temp = s1;
	s1 = s2;
	s2 = temp;
}


//===========================================================================
/*!	@brief		�ő�K��
	@param		a, b��r����I�u�W�F�N�g
	@return		�ő�l
	@note		operator<()����`����Ă���K�v������܂�
*/
//===========================================================================
template <typename T>
inline T Max( const T& a, const T& b )
{
	return (b < a) ? a : b;
}


//===========================================================================
/*!	@brief		�ŏ��K��
	@param		a, b��r����I�u�W�F�N�g
	@return		�ŏ��l
	@note		operator<()����`����Ă���K�v������܂�
*/
//===========================================================================
template <typename T>
inline T Min( const T& a, const T& b )
{
	return (a < b) ? a : b;
}


//===========================================================================
/*!	@brief		�͈͓��Ɋۂ߂�
	@param		value		���肷��I�u�W�F�N�g
	@param		min			�ŏ�
	@param		max			�ő�
	@return		�ۂ߂��l
	@note		operator<()����`����Ă���K�v������܂�
*/
//===========================================================================
template <typename T>
inline T Clamp( const T& value, const T& min, const T& max )
{
	return (max < value) ? max : ((value < min) ? min : value);
}

}	// nk

#endif  // NK_UTILITYFUNC_H
