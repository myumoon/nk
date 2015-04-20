//=============================================================================
/*!	@file	window.h
	@brief	ウインドウ管理
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#include <nk/system/window.h>

// #include <windows.h>
#include <GL/glut.h>
#include <GL/glfw.h>




namespace {
}


namespace nk {
namespace system {


	

//===========================================================================
/*!	@brief	コンストラクタ
	@param	none
*/
//===========================================================================
GLUTWindow::GLUTWindow()
{
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
bool GLUTWindow::Create( s32 width, s32 height, s32 depth, s32 stencil, bool fullscreen, const char* title )
{
	const int windowMode	= fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW;
	
	if( !glfwOpenWindow( width, height, 8, 8, 8, 8, depth, stencil, windowMode ) ) {
		return false;
	}
	
	glfwSetWindowTitle( title );
	
	m_width			= width;
	m_height		= height;
	m_depth			= depth;
	m_stencil		= stencil;
	m_fullScreen	= fullscreen;

	return true;
}


	
}	// namespace system
}	// namespace nk




