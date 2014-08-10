//=============================================================================
/*!	@file	GLUTWindow.cpp

	@brief	ウインドウを管理するクラス

	@author	井手 竜之介
	@date	2011/11/15
	@todo	なし
	@bug	なし
*/
//=============================================================================


#include <nk/system/window.h>

#include <GL/glut.h>

namespace {
nk::system::GLUTWindow*	s_window	= NULL;
}


namespace nk {
namespace system {


//===========================================================================
/*!	@brief		ディスプレイ関数
	@param		none
	@return		none
*/
//===========================================================================
void GLUTWindow::_DisplayGLUT()
{
	if( s_window ) {
		s_window->DisplayGLUT();
	}

}


//===========================================================================
/*!	@brief		DisplayReshape
	@param		width	幅
	@param		height	高さ
	@return		none
*/
//===========================================================================
void GLUTWindow::_DisplayReshape( int width, int height )
{
	if( s_window ) {
		s_window->DisplayReshape( width, height );
	}
}


	

//===========================================================================
/*!	@brief	コンストラクタ
	@param	none
*/
//===========================================================================
GLUTWindow::GLUTWindow( SystemEventListener* eventListener )
{
	m_eventListener	= eventListener;
	m_width			= 0;
	m_height		= 0;
	m_depth			= 0;
	m_fullScreen	= false;
}


//===========================================================================
/*!	@brief	デストラクタ
	@param	none
*/
//===========================================================================
GLUTWindow::~GLUTWindow()
{
}


//===========================================================================
/*!	@brief		ウインドウ生成
	@param		none
	@return		none
*/
//===========================================================================
bool GLUTWindow::Create( s32 width, s32 height, f32 depth, bool fullscreen, const char* title )
{
	s_window	= this;

	m_width			= width;
	m_height		= height;
	m_depth			= depth;
	m_fullScreen	= fullscreen;

	glutCreateWindow( title );
	glutReshapeWindow( width, height );
	glutDisplayFunc( _DisplayGLUT );
	glutReshapeFunc( _DisplayReshape );
	
	glClearColor( 0.0, 0.0, 0.0, 1.0 );

	return true;
}


//===========================================================================
/*!	@brief		ウインドウコールバック
	@param		none
	@return		none
*/
//===========================================================================
void GLUTWindow::DisplayGLUT()
{
	glClear( GL_COLOR_BUFFER_BIT );
	glFlush();
}


//===========================================================================
/*!	@brief		リサイズコールバック
	@param		width	幅
	@param		height	高さ
	@return		none
*/
//===========================================================================
void GLUTWindow::DisplayReshape( int width, int height )
{
	glutReshapeWindow( GetWidth(), GetHeight() );
}
	
}	// namespace system
}	// namespace nk




