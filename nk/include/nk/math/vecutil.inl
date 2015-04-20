//=============================================================================
/*!	@file	vecutil.h
	@brief	ベクトル関係の共通処理
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_VECUTIL_H
#define NK_VECUTIL_H

#include <math.h>
#include <nk/nk.h>

namespace nk {
namespace math {


// コピー
template<typename T, typename U>
inline void VecCopy( T& to, const U& from )
{
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		if( i < U::ELEMEENTS ) {
			to.ary[i]	= from.ary[i];
		}
		else {
			to.ary[i]	= 0.0f;
		}		
	}
}

// クリア
template<typename T>
inline void VecClear( T& vec )
{
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		vec.ary[i]	= 0.0f;
	}
}

// ノルムを返す
template<typename T>
inline f32 VecGetNorm2( const T& vec )
{
	f32	norm2	= 0.0f;
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		norm2	+= vec.ary[i] * vec.ary[i];
	}
	return norm2;
}

// ノルムを返す
template<typename T>
inline f32 VecGetNorm( const T& vec )
{
	return sqrt( VecGetNorm2( vec ) );
}

// 正規化
template<typename T>
inline void VecNorm( T& vec )
{
	const f32	norm	= VecGetNorm( vec );

	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		vec.ary[i]	/= norm;
	}
}

// 正規化済みのベクトルを返す
template<typename T>
inline T VecGetNormalized( const T& vec )
{
	T	nomalized	= vec;
	VecNorm( nomalized );
	return nomalized;
}

// 0ベクトルならtrueを返す
template<typename T>
inline bool VecIsZero( const T& vec )
{
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		if( vec.ary[i] != 0.0f ) {
			return false;
		}
	}
	return true;
}

// 符号を逆にする
template<typename T>
inline void VecInvere( T& vec )
{
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		vec.ary[i] *= -1.0f;
	}
}

// vec1 + vec2
template<typename T, typename U>
inline T VecOpAdd( const T& vec1, const U& vec2 )
{
	T	result( vec1 );
	for( s32 i = 0; (i < T::ELEMEENTS) && (i < U::ELEMEENTS); ++i ) {
		result.ary[i]	+= vec2.ary[i];
	}
	return result;
}

// vec1 - vec2
template<typename T, typename U>
inline T VecOpSub( const T& vec1, const U& vec2 )
{
	T	result( vec1 );
	for( s32 i = 0; (i < T::ELEMEENTS) && (i < U::ELEMEENTS); ++i ) {
		result.ary[i]	-= vec2.ary[i];
	}
	return result;
}

// vec * scalar
template<typename T, typename U>
inline T VecOpMul( const T& vec, const U& scalar )
{
	T	result( vec );
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		result.ary[i]	*= scalar;
	}
	return result;
}

// vec / scalar
template<typename T, typename U>
inline T VecOpDiv( const T& vec, const U& scalar )
{
	T	result( vec );
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		result.ary[i]	/= scalar;
	}
	return result;
}

// equal
template<typename T>
inline bool VecEqual( const T& vec1, const T& vec2 )
{
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		if( vec1.ary[i] != vec2.ary[i] ) {
			return false;
		}
	}
	return true;
}

// 内積
template<typename T>
inline f32 VecDotProduct( const T& vec1, const T& vec2 )
{
	f32	sum	= 0.0f;
	for( s32 i = 0; i < T::ELEMEENTS; ++i ) {
		sum	+= vec1.ary[i] * vec2.ary[i];
	}
	return sum;
}

	
}	// namespace math
}	// namespace nk




#endif  // NK_VECUTIL_H
