//=============================================================================
/*!	@file	window.h

	@brief	ウインドウを管理するクラス

	@author	井手 竜之介
	@date	2011/11/15
	@todo	なし
	@bug	なし
*/
//=============================================================================

#ifndef NK_WINDOW_H
#define NK_WINDOW_H

#include <string>

#include <nk/types.h>

// #include "../math/matrix.h"


namespace nk {
namespace system {

class SystemEventListener;

// ウインドウ更新時コールバック
// typedef void (*WindowCallback)(void*);


//=============================================================================
/*!
                              GLUTウインドウクラス
*/
//=============================================================================
class GLUTWindow {
public:
	GLUTWindow( SystemEventListener* eventListener = NULL );
	virtual ~GLUTWindow();
	
	//! ウインドウ生成
	bool				Create( s32 width = 1024, s32 height = 768, f32 depth = 32, bool fullscreen = false, const char* title = "nk application" );

	//! タイトルをつける
	void				SetTitle( const char* title );
	
	//! アイコンをセット
	void				SetIcon( const char* iconPath );
	
	//! プロジェクション変換行列(右手座標)
	void				SetMatrixPerspectiveFovRH();

	//! 幅・高さ・深度の習得
	//math::Vector		GetScreenParam( void ) const;

	//! ウインドウハンドルを習得
	//NK_WINDOW_HANDLE	GetWindowHandle( void ) const;

	//! ビューポート行列を習得
	//math::Matrix44		GetViewPortMatrix( void ) const;

	//===========================================================================
	/*!	@brief		幅取得
	*/
	//===========================================================================
	s32					GetWidth() const { return m_width; }

	//===========================================================================
	/*!	@brief		高さ取得
	*/
	//===========================================================================
	s32					GetHeight() const { return m_height; }
	
private:
	static void			_DisplayGLUT();
	static void			_DisplayReshape( int width, int height );

	void				DisplayGLUT();
	void				DisplayReshape( int width, int height );
	
private:
	//----------------------メンバ変数-----------------------
	s32							m_width;				//!< 幅
	s32							m_height;				//!< 高さ
	f32							m_depth;				//!< 深度
	bool						m_fullScreen;			//!< フルスクリーン
	SystemEventListener*		m_eventListener;		//!< イベントリスナー
};
	
}	// namespace system
}	// namespace nk



#endif  // NK_WINDOW_H
