//=============================================================================
/*!	@file	utilityfunc.h
	@brief	汎用処理
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_UTILITYFUNC_H
#define NK_UTILITYFUNC_H

//-------------------------------インクルード-------------------------------
#include <stdlib.h>
#include <stdio.h>

namespace nk {
	

//===========================================================================
/*!	@brief	セーフデリート
	@param	obj : 削除するオブジェクト
	@return	なし
*/
//===========================================================================
template <typename T>
inline void SafeDelete( T*& obj )
{
	delete obj;
	obj = NULL;
}

	
//===========================================================================
/*!	@brief	配列版セーフデリート
	@param	obj : 削除するオブジェクト
	@return	なし
*/
//===========================================================================
template <typename T>
inline void SafeDeleteArray( T*& obj )
{
	delete[] obj;
	obj = NULL;
}

	
//===========================================================================
/*!	@brief	セーフフリー
	@param	obj : 削除するオブジェクト
	@return	なし
*/
//===========================================================================
template <typename T>
inline void SafeFree( T*& obj )
{
	free( obj );
	obj = NULL;
}

	
//===========================================================================
/*!	@brief	オブジェクトの入れ替え
	@param	s1,s2	: 入れ替えるオブジェクト
	@return	なし
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
/*!	@brief		最大習得
	@param		a, b比較するオブジェクト
	@return		最大値
	@note		operator<()が定義されている必要があります
*/
//===========================================================================
template <typename T>
inline T Max( const T& a, const T& b )
{
	return (b < a) ? a : b;
}


//===========================================================================
/*!	@brief		最小習得
	@param		a, b比較するオブジェクト
	@return		最小値
	@note		operator<()が定義されている必要があります
*/
//===========================================================================
template <typename T>
inline T Min( const T& a, const T& b )
{
	return (a < b) ? a : b;
}


//===========================================================================
/*!	@brief		範囲内に丸める
	@param		value		判定するオブジェクト
	@param		min			最小
	@param		max			最大
	@return		丸めた値
	@note		operator<()が定義されている必要があります
*/
//===========================================================================
template <typename T>
inline T Clamp( const T& value, const T& min, const T& max )
{
	return (max < value) ? max : ((value < min) ? min : value);
}

}	// nk

#endif  // NK_UTILITYFUNC_H
