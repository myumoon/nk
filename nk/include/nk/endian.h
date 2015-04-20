//=============================================================================
/*!	@file	endian.h
	@brief	エンディアン
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_ENDIAN_H
#define NK_ENDIAN_H


namespace nk {


enum ENDIAN_TYPE {
	BIG_ENDIAN,		//!< ビッグエンディアン
	LITTLE_ENDIAN,	//!< リトルエンディアン
	
	UNKNOWN_ENDIAN,	//!< エラー
};


//===========================================================================
/*!	@brief		エンディアン処理初期化
*/
//===========================================================================
void		InitializeEndian();

//===========================================================================
/*!	@brief		エンディアンタイプを取得
*/
//===========================================================================
ENDIAN_TYPE	GetEndian();
	
}	// namespace nk


#endif  // NK_ENDIAN_H