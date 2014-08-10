//=============================================================================
/*!	@file	system.cpp

	@brief	ゲームシステム

	@author	ryunosuke ide
	@date	2014.08.10
*/
//=============================================================================


#include <nk/system/system.h>

// #include <windows.h>
#include <GL/glut.h>
#include <GL/glfw.h>





#include <nk/nk.h>
#include <nk/system/window.h>
#include <nk/system/gameCoreInterface.h>



namespace nk {
namespace system {


	

//===========================================================================
/*!	@brief	コンストラクタ
	@param	----
*/
//===========================================================================
System::System( const InitParam& param, GameCoreInterface* gameCore )
{
	m_initParam				= param;
	m_gameCoreInterface		= gameCore;
}


//===========================================================================
/*!	@brief	デストラクタ
	@param	----
*/
//===========================================================================
System::~System()
{
	SafeDelete( m_window );
}


//===========================================================================
/*!	@brief		初期化
	@param		none
	@return		none
*/
//===========================================================================
bool System::Initialize()
{
	glfwInit();

	m_window		= new GLUTWindow();
	m_window->Create(
		m_initParam.screenWidth,
		m_initParam.screenHeight,
		m_initParam.screenDepth,
		m_initParam.screenStencil,
		m_initParam.fullScreen,
		m_initParam.strApplicationName
	);
	
	return true;
}


//===========================================================================
/*!	@brief		実行
	@param		none
	@return		none
*/
//===========================================================================
void System::Run()
{
	int running = GL_TRUE;

	glEnable(GL_DEPTH_TEST);
	
	while( running ) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if( m_gameCoreInterface ) {
			m_gameCoreInterface->Update();
		}
		
		//描画
		glBegin(GL_POLYGON);
		glColor3d(1.0, 0.0, 0.0);
		glVertex2d(-0.9, -0.9);
		glColor3d(0.0, 1.0, 0.0);
		glVertex2d(0.9, -0.9);
		glColor3d(0.0, 0.0, 1.0);
		glVertex2d(0.9, 0.9);
		glColor3d(1.0, 1.0, 0.0);
		glVertex2d(-0.9, 0.9);
		glEnd();
		
		//ダブルバッファリングのバッファの交換
		glfwSwapBuffers();
		
		//ESCキーかXボタンで終了
		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
	}
}


//===========================================================================
/*!	@brief		終了
	@param		none
	@return		none
*/
//===========================================================================
void System::Terminate()
{
	glfwTerminate();
}

	
}	// namespace system
}	// namespace nk
