//=============================================================================
/*!	@file	system.h

	@brief	ゲームシステム

	@author	ryunosuke ide
	@date	2014.08.10
*/
//=============================================================================

#ifndef NK_SYSTEM_H
#define NK_SYSTEM_H

#include <stdlib.h>
#include <string.h>
#include <nk/types.h>
#include <nk/macros.h>

namespace nk {
namespace system {

class SystemEventListener;
class GLUTWindow;
	

//! アプリケーション初期化パラメータ
struct InitParam {
	s32			argc;						//!<	プログラム引数
	char**		argv;						//!<	プログラム引数
	s32			screenWidth;				//!<	スクリーン横幅
	s32			screenHeight;				//!<	スクリーン縦幅
	s32			frameRate;					//!<	フレームレート
	bool		fullScreen;					//!<	フルスクリーン
	char		strApplicationName[128];	//!<	アプリケーション名

	//! コンストラクタ
	InitParam()
	{
		this->argc				= 0;
		this->argv				= NULL;
		this->screenWidth		= 1024;
		this->screenHeight		= 768;
		this->frameRate			= 60;
		this->fullScreen		= false;
		strcpy( this->strApplicationName, "nk application" );
	}

	//! コンストラクタ
	InitParam( s32 argc, char** argv, s32 screenWidth, s32 screenHeight, s32 frameRate, bool fullScreen, const char* appName )
	{
		this->argc				= argc;
		this->argv				= argv;
		this->screenWidth		= screenWidth;
		this->screenHeight		= screenHeight;
		this->frameRate			= frameRate;
		this->fullScreen		= fullScreen;
		strncpy( this->strApplicationName, appName, NKARRAY_SIZE(this->strApplicationName) );
	}
};

//=============================================================================
/*!	@brief	ゲームシステム
*/
//=============================================================================
class System {
public:
	
	
public:
	//! コンストラクタ
	System( const InitParam& param, SystemEventListener* eventlistener = NULL );

	//! デストラクタ
	virtual ~System();
	
	//===========================================================================
	/*!	@brief		ゲームイベントリスナー設定
	*/
	//===========================================================================
	void	SetSystemEventListener( SystemEventListener* eventlistener );

	//===========================================================================
	/*!	@brief		初期化
	*/
	//===========================================================================
	bool	Initialize();

	//===========================================================================
	/*!	@brief		実行
	*/
	//===========================================================================
	void	Run();

	//===========================================================================
	/*!	@brief		終了処理
	*/
	//===========================================================================
	void	Terminate();

private:
	static void				DisplayGLUT();
	static void				DisplayReshape( int width, int height );

private:
	InitParam				m_initParam;				//!< 初期化パラメータ
	SystemEventListener*	m_systemEventListener;		//!< リスナー
	GLUTWindow*				m_window;					//!< ウインドウ

private:
	System();	//!< 使用不可
};

}	// namespace system
}	// namespace nk




#endif  // NK_SYSTEM_H
