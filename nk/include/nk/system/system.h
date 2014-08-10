//=============================================================================
/*!	@file	system.h

	@brief	�Q�[���V�X�e��

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
	

//! �A�v���P�[�V�����������p�����[�^
struct InitParam {
	s32			argc;						//!<	�v���O��������
	char**		argv;						//!<	�v���O��������
	s32			screenWidth;				//!<	�X�N���[������
	s32			screenHeight;				//!<	�X�N���[���c��
	s32			frameRate;					//!<	�t���[�����[�g
	bool		fullScreen;					//!<	�t���X�N���[��
	char		strApplicationName[128];	//!<	�A�v���P�[�V������

	//! �R���X�g���N�^
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

	//! �R���X�g���N�^
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
/*!	@brief	�Q�[���V�X�e��
*/
//=============================================================================
class System {
public:
	
	
public:
	//! �R���X�g���N�^
	System( const InitParam& param, SystemEventListener* eventlistener = NULL );

	//! �f�X�g���N�^
	virtual ~System();
	
	//===========================================================================
	/*!	@brief		�Q�[���C�x���g���X�i�[�ݒ�
	*/
	//===========================================================================
	void	SetSystemEventListener( SystemEventListener* eventlistener );

	//===========================================================================
	/*!	@brief		������
	*/
	//===========================================================================
	bool	Initialize();

	//===========================================================================
	/*!	@brief		���s
	*/
	//===========================================================================
	void	Run();

	//===========================================================================
	/*!	@brief		�I������
	*/
	//===========================================================================
	void	Terminate();

private:
	static void				DisplayGLUT();
	static void				DisplayReshape( int width, int height );

private:
	InitParam				m_initParam;				//!< �������p�����[�^
	SystemEventListener*	m_systemEventListener;		//!< ���X�i�[
	GLUTWindow*				m_window;					//!< �E�C���h�E

private:
	System();	//!< �g�p�s��
};

}	// namespace system
}	// namespace nk




#endif  // NK_SYSTEM_H
