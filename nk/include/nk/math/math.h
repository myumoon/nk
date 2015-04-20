//=============================================================================
/*!	@file	math.h
	@brief	数学関係の処理
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
/*!	@brief		符号を返す
	@param		a		調べる数字
	@retval		true	正（0含む）
				false	負
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
/*!	@brief		ラジアン値を計算
	@param		deg		角度
	@return		ラジアン
*/
//===========================================================================
template <typename T>
inline f32 Rad( const T& deg )
{
	return static_cast<f32>(deg / 180.0f * PI);
}



//===========================================================================
/*!	@brief		角度を計算
	@param		rad		ラジアン角度
	@return		度
*/
//===========================================================================
template <typename T>
inline f32 Deg( T rad )
{
	return static_cast<f32>(rad) * 180.0f / PI;
}


//===========================================================================
/*!	@brief	範囲内に収める
	@param	num		判定する値
	@param	min		最小値
	@param	max		最大値
	@return	範囲内にまるめた値
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
/*!	@brief		大きい方を取得
	@param		rhs
	@param		lhs
	@return		大きい方の値
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
/*!	@brief		小さい方を取得
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
/*!	@brief		絶対値を取得
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
/*!	@brief		平均値を計算
	@param		ary
	@param		size	aryサイズ
	@return		----
	@attention	f64 operator[]が必要です
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
