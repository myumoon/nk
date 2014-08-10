//=============================================================================
/*!	@file	GLUTWindow.cpp

	@brief	�E�C���h�E���Ǘ�����N���X

	@author	��� ���V��
	@date	2011/11/15
	@todo	�Ȃ�
	@bug	�Ȃ�
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
/*!	@brief		�f�B�X�v���C�֐�
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
	@param		width	��
	@param		height	����
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
/*!	@brief	�R���X�g���N�^
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
/*!	@brief	�f�X�g���N�^
	@param	none
*/
//===========================================================================
GLUTWindow::~GLUTWindow()
{
}


//===========================================================================
/*!	@brief		�E�C���h�E����
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
/*!	@brief		�E�C���h�E�R�[���o�b�N
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
/*!	@brief		���T�C�Y�R�[���o�b�N
	@param		width	��
	@param		height	����
	@return		none
*/
//===========================================================================
void GLUTWindow::DisplayReshape( int width, int height )
{
	glutReshapeWindow( GetWidth(), GetHeight() );
}
	
}	// namespace system
}	// namespace nk




