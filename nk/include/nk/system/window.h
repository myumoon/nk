//=============================================================================
/*!	@file	window.h

	@brief	�E�C���h�E���Ǘ�����N���X

	@author	��� ���V��
	@date	2011/11/15
	@todo	�Ȃ�
	@bug	�Ȃ�
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

// �E�C���h�E�X�V���R�[���o�b�N
// typedef void (*WindowCallback)(void*);


//=============================================================================
/*!
                              GLUT�E�C���h�E�N���X
*/
//=============================================================================
class GLUTWindow {
public:
	GLUTWindow( SystemEventListener* eventListener = NULL );
	virtual ~GLUTWindow();
	
	//! �E�C���h�E����
	bool				Create( s32 width = 1024, s32 height = 768, f32 depth = 32, bool fullscreen = false, const char* title = "nk application" );

	//! �^�C�g��������
	void				SetTitle( const char* title );
	
	//! �A�C�R�����Z�b�g
	void				SetIcon( const char* iconPath );
	
	//! �v���W�F�N�V�����ϊ��s��(�E����W)
	void				SetMatrixPerspectiveFovRH();

	//! ���E�����E�[�x�̏K��
	//math::Vector		GetScreenParam( void ) const;

	//! �E�C���h�E�n���h�����K��
	//NK_WINDOW_HANDLE	GetWindowHandle( void ) const;

	//! �r���[�|�[�g�s����K��
	//math::Matrix44		GetViewPortMatrix( void ) const;

	//===========================================================================
	/*!	@brief		���擾
	*/
	//===========================================================================
	s32					GetWidth() const { return m_width; }

	//===========================================================================
	/*!	@brief		�����擾
	*/
	//===========================================================================
	s32					GetHeight() const { return m_height; }
	
private:
	static void			_DisplayGLUT();
	static void			_DisplayReshape( int width, int height );

	void				DisplayGLUT();
	void				DisplayReshape( int width, int height );
	
private:
	//----------------------�����o�ϐ�-----------------------
	s32							m_width;				//!< ��
	s32							m_height;				//!< ����
	f32							m_depth;				//!< �[�x
	bool						m_fullScreen;			//!< �t���X�N���[��
	SystemEventListener*		m_eventListener;		//!< �C�x���g���X�i�[
};
	
}	// namespace system
}	// namespace nk



#endif  // NK_WINDOW_H
