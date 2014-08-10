//=============================================================================
/*!	@file	system.cpp

	@brief	�Q�[���V�X�e��

	@author	ryunosuke ide
	@date	2014.08.10
*/
//=============================================================================


#include <nk/system/system.h>

#include <GL/glut.h>

#include <nk/nk.h>
#include <nk/system/window.h>



namespace nk {
namespace system {


	

//===========================================================================
/*!	@brief	�R���X�g���N�^
	@param	----
*/
//===========================================================================
System::System( const InitParam& param, SystemEventListener* eventlistener )
{
	m_initParam				= param;
	m_systemEventListener	= eventlistener;
}


//===========================================================================
/*!	@brief	�f�X�g���N�^
	@param	----
*/
//===========================================================================
System::~System()
{
	SafeDelete( m_window );
}


//===========================================================================
/*!	@brief		������
	@param		none
	@return		none
*/
//===========================================================================
bool System::Initialize()
{
	glutInit( &m_initParam.argc, m_initParam.argv );

	m_window		= new GLUTWindow( m_systemEventListener );
	m_window->Create( m_initParam.screenWidth, m_initParam.screenHeight, 32, m_initParam.fullScreen, m_initParam.strApplicationName );
	
	return true;
}


//===========================================================================
/*!	@brief		���s
	@param		none
	@return		none
*/
//===========================================================================
void System::Run()
{
	glutMainLoop();
}


//===========================================================================
/*!	@brief		�I��
	@param		none
	@return		none
*/
//===========================================================================
void System::Terminate()
{
}

	
}	// namespace system
}	// namespace nk
