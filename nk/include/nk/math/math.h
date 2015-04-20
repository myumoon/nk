//=============================================================================
/*!	@file	math.h
	@brief	���w�֌W�̏���
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_MATH_H
#define NK_MATH_H

#include <math.h>

#include <nk/types.h>


namespace nk {
namespace math {

const f64	PI			= 3.1415926535897932384626433832795;
const f64	QUARTER_PI	= PI * 0.25;
const f64	HALF_PI		= PI * 0.5;
const f64	DOUBLE_PI	= PI * 2.0;
const f64	RADIAN		= PI / 180.0;
const f64	ROOT2		= 1.41421356;


//===========================================================================
/*!	@brief		������Ԃ�
	@param		a		���ׂ鐔��
	@retval		true	���i0�܂ށj
				false	��
*/
//===========================================================================
template <typename T>
inline bool Sign( T a )
{
	if( 0 <= a ) {
		return true;
	}

	return false;
}


//===========================================================================
/*!	@brief		���W�A���l���v�Z
	@param		deg		�p�x
	@return		���W�A��
*/
//===========================================================================
template <typename T>
inline f32 Rad( const T& deg )
{
	return static_cast<f32>(deg / 180.0f * PI);
}



//===========================================================================
/*!	@brief		�p�x���v�Z
	@param		rad		���W�A���p�x
	@return		�x
*/
//===========================================================================
template <typename T>
inline f32 Deg( T rad )
{
	return static_cast<f32>(rad) * 180.0f / PI;
}


//===========================================================================
/*!	@brief	�͈͓��Ɏ��߂�
	@param	num		���肷��l
	@param	min		�ŏ��l
	@param	max		�ő�l
	@return	�͈͓��ɂ܂�߂��l
*/
//===========================================================================
template <typename T>
inline T Clamp( const T& num, const T& min, const T& max )
{
	if( num < min ) {
		return min;
	}
	if( max < num ) {
		return max;
	}

	return num;
}


//===========================================================================
/*!	@brief		�傫�������擾
	@param		rhs
	@param		lhs
	@return		�傫�����̒l
*/
//===========================================================================
template <typename T>
inline T Max( const T& lhs, const T& rhs )
{
	if( lhs < rhs ) {
		return rhs;
	}
	return lhs;
}


//===========================================================================
/*!	@brief		�����������擾
	@param		rhs
	@param		lhs
	@return		----
*/
//===========================================================================
template <typename T>
inline T Min( const T& lhs, const T& rhs )
{
	if( rhs < lhs ) {
		return rhs;
	}
	return lhs;
}


//===========================================================================
/*!	@brief		��Βl���擾
	@param		rhs
	@param		lhs
	@return		----
*/
//===========================================================================
template <typename T>
inline T Abs( const T& value )
{
	if( value < 0 ) {
		return -value;
	}
	return value;
}


//===========================================================================
/*!	@brief		���ϒl���v�Z
	@param		ary
	@param		size	ary�T�C�Y
	@return		----
	@attention	f64 operator[]���K�v�ł�
*/
//===========================================================================
template <typename T>
inline f64 Average( const T& ary, u32 size )
{
	s64	sum	= 0;
	for( u32 i = 0; i < size; ++i ) {
		sum	+= ary[i];
	}
	return sum / size;
}


}	// namespace math
}	// namespace nk


#endif  // NK_MATH_H
