//=============================================================================
/*!	@file	thread.h
	@brief	�X���b�h�֐�
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_THREAD_FUNC_H
#define NK_THREAD_FUNC_H

#include <nk/types.h>

namespace nk {
namespace thread {

//! �X���b�h�֐�
typedef u32 (*ThreadFunc)( void* );

#if defined(_WIN32)
//! �n���h��
typedef u32	ThreadHandle;

//! �~���[�e�b�N�X�n���h��
typedef u32	MutexHandle;

//! �N���e�B�J���Z�N�V�����n���h��
typedef u32	CriticalSectionHandle;
#else
	// TODO
#endif

//===========================================================================
/*!	@brief	�X���b�h������
	@param	none
	@return	none
*/
//===========================================================================
void Initialize();

	
//===========================================================================
/*!	@brief	�X���b�h�I������
	@param	none
	@return	none
*/
//===========================================================================
void Terminate();
	

//===========================================================================
/*!	@brief	�X���b�h����
	@param	func		�Ăяo���֐�
	@param	arg			�X���b�h�֐�����
	@param	priority	�D��x
	@param	stackSize	�X�^�b�N�T�C�Y(�f�t�H���g��0)
	@return	���������X���b�h�̃n���h��
*/
//===========================================================================
#if defined(_DEBUG)
ThreadHandle CreateThread( ThreadFunc func, void* arg, s32 priority = 16, u32 stackSize = 0, const char* name = "" );
#else
ThreadHandle CreateThread( ThreadFunc func, void* arg, s32 priority = 16, u32 stackSize = 0 )
#endif

//===========================================================================
/*!	@brief	�X���b�h�폜
	@param	handle		�폜����X���b�h�̃n���h��
	@return	----
*/
//===========================================================================
void DestroyThread( ThreadHandle handle );


	
//===========================================================================
/*!	@brief	�X���b�h�J�n
	@param	�J�n����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void StartThread( ThreadHandle handle );



//===========================================================================
/*!	@brief	�X���b�h���f
	@param	���f����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void SuspendThread( ThreadHandle handle );


//===========================================================================
/*!	@brief	�X���b�h�ĊJ
	@param	�ĊJ����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void ResumeThread( ThreadHandle handle );

	
//===========================================================================
/*!	@brief	�X���b�h�I���ҋ@
	@param	�҂X���b�h
	@return	----
*/
//===========================================================================
void JoinThread( ThreadHandle handle );



//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̍쐬
	@param	----
	@return	���������~���[�e�b�N�X�̃n���h��
*/
//===========================================================================
MutexHandle CreateMutexObject();



//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̍폜
	@param	handle	�폜����~���[�e�b�N�X�̃n���h��
	@return	----
*/
//===========================================================================
void DeleteMutexObject( MutexHandle handle );


//===========================================================================
/*!	@brief	�~���[�e�b�N�X�����b�N
	@param	handle	���b�N�����݂�~���[�e�b�N�X
	@return	true.���b�N����		false.���s
*/
//===========================================================================
bool LockMutex( MutexHandle handle );


//===========================================================================
/*!	@brief	�~���[�e�b�N�X���A�����b�N
	@param	handle	�A�����b�N�����݂�~���[�e�b�N�X
	@return	true.�A�����b�N����		false.���s
*/
//===========================================================================
bool UnlockMutex( MutexHandle handle );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̍쐬
	@param		----
	@return		----
*/
//===========================================================================
CriticalSectionHandle CreateCriticalSection();


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̍폜
	@param		handle	�폜����N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void DeleteCriticalSection( CriticalSectionHandle handle );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̃��b�N
	@param		�N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void LockCriticalSection( CriticalSectionHandle handle );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̃A�����b�N
	@param		�N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void UnlockCriticalSection( CriticalSectionHandle handle );

//===========================================================================
/*!	@brief	�S�ẴX���b�h���~������
	@param	----
	@return	----
*/
//===========================================================================
void SuspendAllThread();


//===========================================================================
/*!	@brief	�S�ẴX���b�h���ĊJ������
	@param	----
	@return	----
*/
//===========================================================================
void ResumeAllThread();
	
}	// namespace thread
}	// namespace nk





#endif  // NK_THREAD_FUNC_H



#if 0
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#include <vector>

#include <types.h>


#define	HANDLE_LIST_MAX		(128)		//!< �n���h���쐬�ő吔
#define	THREAD_MAX			(32)		//!< �X���b�h��

namespace nk {

typedef u32 (*THREAD_FUNC)( void* );

#if defined(_WIN32)	// windows
//! �X���b�h�֐�

//! �X���b�h�n���h��
typedef HANDLE				THREAD_HANDLE;

//! �~���[�e�b�N�X�n���h��
typedef HANDLE				MUTEX_HANDLE;

//! 
typedef LPCRITICAL_SECTION	CRITICAL_SECTION_HANDLE;

//! �C�x���g�n���h��
//typedef HANDLE			EVENT_HANDLE;

//! �X���b�hID
typedef DWORD				THREAD_ID;

#else	// SDL

//! �X���b�h�n���h��
typedef u32					THREAD_HANDLE;

//! �~���[�e�b�N�X�n���h��
typedef u32					MUTEX_HANDLE;

//! �N���e�B�J���Z�N�V�����n���h��
typedef void*				CRITICAL_SECTION_HANDLE;	// �R���p�C���G���[�ł�͂�

//! �X���b�hID
typedef u32					THREAD_ID;
	
#endif







//===========================================================================
/*!	@brief	�X���b�h������
	@param	----
	@return	----
*/
//===========================================================================
void Initialize( void );


	
//===========================================================================
/*!	@brief	�X���b�h�I������
	@param	----
	@return	----
*/
//===========================================================================
void Terminate( void );
	

//===========================================================================
/*!	@brief	�X���b�h����
	@param	func		�Ăяo���֐�
	@param	arg			�X���b�h�֐�����
	@param	priority	�D��x
	@param	stackSize	�X�^�b�N�T�C�Y(�f�t�H���g��0)
	@return	���������X���b�h�̃n���h��
*/
//===========================================================================
THREAD_HANDLE	CreateThread( THREAD_FUNC func, void* arg, s32 priority = THREAD_PRIORITY_NORMAL, u32 stackSize = 0, const char* name = "" );
	

//===========================================================================
/*!	@brief	�X���b�h�폜
	@param	handle		�폜����X���b�h�̃n���h��
	@return	----
*/
//===========================================================================
void			DestroyThread( THREAD_HANDLE handle );


	
//===========================================================================
/*!	@brief	�X���b�h�J�n
	@param	�J�n����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void			StartThread( THREAD_HANDLE handle );



//===========================================================================
/*!	@brief	�X���b�h���f
	@param	���f����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void			SuspendThread( THREAD_HANDLE handle );


//===========================================================================
/*!	@brief	�X���b�h�ĊJ
	@param	�ĊJ����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void			ResumeThread( THREAD_HANDLE handle );

	
//===========================================================================
/*!	@brief	�X���b�h�I���ҋ@
	@param	�҂X���b�h
	@return	----
*/
//===========================================================================
void			JoinThread( THREAD_HANDLE handle );



//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̍쐬
	@param	----
	@return	���������~���[�e�b�N�X�̃n���h��
*/
//===========================================================================
MUTEX_HANDLE	CreateMutexObject( void );



//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̍폜
	@param	handle	�폜����~���[�e�b�N�X�̃n���h��
	@return	----
*/
//===========================================================================
void			DeleteMutexObject( MUTEX_HANDLE handle );


//===========================================================================
/*!	@brief	�~���[�e�b�N�X�����b�N
	@param	handle	���b�N�����݂�~���[�e�b�N�X
	@return	true.���b�N����		false.���s
*/
//===========================================================================
bool			LockMutex( MUTEX_HANDLE handle );


//===========================================================================
/*!	@brief	�~���[�e�b�N�X���A�����b�N
	@param	handle	�A�����b�N�����݂�~���[�e�b�N�X
	@return	true.�A�����b�N����		false.���s
*/
//===========================================================================
bool			UnlockMutex( MUTEX_HANDLE handle );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̍쐬
	@param		----
	@return		----
*/
//===========================================================================
CRITICAL_SECTION_HANDLE	CreateCriticalSection( void );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̍폜
	@param		handle	�폜����N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void			DeleteCriticalSection( CRITICAL_SECTION_HANDLE handle );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̃��b�N
	@param		�N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void			LockCriticalSection( CRITICAL_SECTION_HANDLE handle );


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̃A�����b�N
	@param		�N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void			UnlockCriticalSection( CRITICAL_SECTION_HANDLE handle );

//===========================================================================
/*!	@brief	�S�ẴX���b�h���~������
	@param	----
	@return	----
*/
//===========================================================================
void			SuspendAllThread( void );



//===========================================================================
/*!	@brief	�S�ẴX���b�h���ȑO�̏�Ԃɖ߂�
	@param	----
	@return	----
*/
//===========================================================================
void			ReturnAllThread( void );


//===========================================================================
/*!	@brief	�S�ẴX���b�h���ĊJ������
	@param	----
	@return	----
*/
//===========================================================================
void			ResumeAllThread( void );



#endif  // __THREAD_FUNC_H__