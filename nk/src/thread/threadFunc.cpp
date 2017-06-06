//=============================================================================
/*!	@file	thread.cpp
	@brief	�X���b�h�֐�
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#include <nk/thread/threadFunc.h>

#include <vector>

#if defined(_WIN32)
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#endif

#include <nk/nk.h>


namespace nk {
namespace thread {

namespace {

#if defined(_WIN32)
	typedef DWORD	ThreadId;
#else
	typedef u32		ThreadId;
#endif
	
	enum THREAD_STATE {
		THREAD_STATE_START,		//!< �J�n
		THREAD_STATE_SUSPEND,	//!< ���f
		THREAD_STATE_WAIT,		//!< �҂�
	};
	
// �X���b�h�f�[�^
	struct _ThreadData {
		bool						validData;		//!< �L���H
		nk::thread::ThreadHandle	handle;			//!< �X���b�h�n���h��
		ThreadId					id;				//!< �X���b�hID
		nk::thread::ThreadFunc		func;			//!< �֐�
		void*						argument;		//!< �X���b�h����
		THREAD_STATE				nowState;		//!< �X���b�h�̏��
		s64							createdTime;	//!< ��������
#if defined(_DEBUG)
		char						name[128];		//!< �X���b�h��
#endif

		_ThreadData()
		{
			this->validData		= false;
			this->handle		= 0;
			this->id			= 0;
			this->createdTime	= 0;
#if defined(_DEBUG)
			memset( name, 0, sizeof(name) );
#endif
		}

		~_ThreadData()
		{
#if defined(_DEBUG)
			printf("DeleteThread : name = %s\n", name);
#endif
		}

		bool Initialized( void ) const
		{
			return this->validData == true;
		}

		bool operator ==( nk::thread::ThreadHandle handle )
		{
			if( this->handle == handle ) {
				return true;
			}
			return false;
		}
	};

	
	// ���������X���b�h���Ǘ�
	class _ThreadManager {
	public:
		_ThreadManager()
		{
			m_vecThread.reserve( 256 );
		}

		void Add( _ThreadData* data )
		{
			data->validData	= data->handle != 0;
			m_vecThread.push_back( data );
		}

		_ThreadData& GetDataByHandle( nk::thread::ThreadHandle handle )
		{
			std::vector<_ThreadData*>::iterator	itr	= m_vecThread.begin();
			std::vector<_ThreadData*>::iterator	end	= m_vecThread.end();
			for( ; itr != end; ++itr ) {
				if( (*itr)->handle == handle ) {
					return *(*itr);
				}
			}

			return m_dummy;
		}


		_ThreadData& GetDataByIndex( u32 idx )
		{
			NKASSERT( idx < m_vecThread.size(), "index over." );
			return *m_vecThread[idx];
		}

		u32 GetSize() const
		{
			return m_vecThread.size();
		}
		

		void Remove( nk::thread::ThreadHandle handle )
		{
			std::vector<_ThreadData*>::iterator	itr	= m_vecThread.begin();
			std::vector<_ThreadData*>::iterator	end	= m_vecThread.end();
			for( ; itr != end; ++itr ) {
				if( (*itr)->handle == handle ) {
					nk::SafeDelete( *itr );
					break;
				}
			}
			m_vecThread.erase( itr );
		}

		void Destroy( void )
		{
			std::vector<_ThreadData*>::iterator	itr	= m_vecThread.begin();
			std::vector<_ThreadData*>::iterator	end	= m_vecThread.end();
			for( ; itr != end; ++itr ) {
				nk::SafeDelete( *itr );
			}
		}
		
	private:
		std::vector<_ThreadData*>		m_vecThread;	// �Ǘ��X���b�h
		_ThreadData						m_dummy;		// ���s���_�~�[
	};

	_ThreadManager*		_threadManager	= NULL;			// �X���b�h�Ǘ�
	
}	// unnamed



namespace {

_ThreadManager* _GetThreadMng( void )
{
	NKASSERT( _threadManager != NULL, "thread not initialized.\n" );
	
	return _threadManager;
}


#if defined(_WIN32)
u32 __stdcall _ThreadCallback( void* param )
{
	_ThreadData*	threadData	= static_cast<_ThreadData*>( param );
	(*threadData->func)( threadData->argument );
	
	_GetThreadMng()->Remove( threadData->handle );

	return 0;
}
	
#else
s32 _ThreadCallback( void* param )
{
	nk::ThreadData*	threadData	= static_cast<nk::ThreadData*>( param );
	(*threadData->func)( threadData->argument );

	_GetThreadMng()->Remove( threadData->handle );

	return 0;
}
#endif


}	// unnamed



namespace nk {
namespace thread {


//===========================================================================
/*!	@brief	������
	@param	----
	@return	----
*/
//===========================================================================
void Initialize( void )
{
	if( _threadManager == NULL ) {
		_threadManager	= new _ThreadManager();
	}
}



//===========================================================================
/*!	@brief	�I������
	@param	----
	@return	----
*/
//===========================================================================
void Terminate( void )
{
	for( u32 i = 0; i < _GetThreadMng()->GetSize(); ++i ) {
		_ThreadData&	thread	= _GetThreadMng()->GetDataByIndex( i );
#if defined(_WIN32)
		::CloseHandle( static_cast<HANDLE>(thread.handle) );
#else
#endif		
	}

	// ���������
	_GetThreadMng()->Destroy();

	SafeDelete( _threadManager );
}
	
	

//===========================================================================
/*!	@brief	�X���b�h����
	@param	func		�Ăяo���֐�
	@param	arg			�X���b�h�֐�����
	@param	priority	�D��x
	@param	stackSize	�X�^�b�N�T�C�Y(�f�t�H���g0)
	@return	true.��������	false.�������s
*/
//===========================================================================
#if defined(_DEBUG)
ThreadHandle CreateThread( ThreadFunc func, void* arg, s32 priority, u32 stackSize, const char* name )
#else
ThreadHandle CreateThread( ThreadFunc func, void* arg, s32 priority, u32 stackSize )
#endif
{
	_ThreadData	*threadData	= new _ThreadData();

	threadData->nowState	= THREAD_STATE_SUSPEND;
	threadData->func		= func;
	threadData->argument 	= arg;
	threadData->createdTime	= GetTimeMillSec();

#if defined(_DEBUG)
	strcpy_s( threadData->name, name );
	printf("CreateThread : name = %s\n", name);
#endif


#if defined(_WIN32)
	threadData->handle	= static_cast<ThreadHandle>(_beginthreadex(
		NULL,
        stackSize,
		_ThreadCallback,
        threadData,
        CREATE_SUSPENDED,
        (u32*)&threadData->id
	);
	//threadData->handle		= ::OpenThread( SYNCHRONIZE | STANDARD_RIGHTS_REQUIRED | THREAD_SUSPEND_RESUME | THREAD_SET_INFORMATION, TRUE, threadData->id );
#else
	// TODO
#endif
	
    if( threadData->handle == 0 ) {
        PRINTF("error : create thread\n");
        return false;
    }

#if defined(_WIN32)
	::SetThreadPriority( static_cast<HANDLE>(threadData->handle), priority );
#else
	// TODO
#endif

	_GetThreadMng()->Add( threadData );
	
	
	return threadData->handle;
}


//===========================================================================
/*!	@brief	�X���b�h�I��
	@param	handle	�I������X���b�h�n���h��
	@return	----
*/
//===========================================================================
void DestroyThread( ThreadHandle handle )
{
	_ThreadData&	thread	= _GetThreadMng()->GetDataByHandle( handle );
	NKASSERT( thread.validData == true, "invalid thread." );


#if defined(_WIN32)
	::CloseHandle( static_cast<HANDLE>(thread.handle) );
#else
	// TODO
#endif

	_GetThreadMng()->Remove( handle );

}


//===========================================================================
/*!	@brief	�X���b�h�J�n
	@param	handle	�J�n����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void StartThread( ThreadHandle handle )
{
	_ThreadData&	thread	= _GetThreadMng()->GetDataByHandle( handle );
	NKASSERT( thread.validData == true, "invalid thread." );
	
	thread.nowState		= THREAD_STATE_START;
	thread.createdTime	= GetTimeMillSec();

#if defined(_WIN32)
	::ResumeThread( static_cast<HANDLE>(handle) );
#else
	// TODO
#endif

}



//===========================================================================
/*!	@brief	�X���b�h���f
	@param	handle	���f����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void SuspendThread( ThreadHandle handle )
{
	_ThreadData&	thread	= _GetThreadMng()->GetDataByHandle( handle );
	NKASSERT( thread.validData == true, "invalid thread." );

	thread.nowState		= THREAD_STATE_SUSPEND;
	
#if defined(_WIN32)
	const s64	THREAD_LIFE_TIME	= 5;
	const s64	nowTime				= GetTimeMillSec();
	if( nowTime < thread.createdTime + THREAD_LIFE_TIME ) {
		nk::SleepThread( thread.createdTime + THREAD_LIFE_TIME - nowTime );
	}
	::SuspendThread( static_cast<HANDLE>(thread.handle) );
#else
	// TODO
#endif
	
	
}


//===========================================================================
/*!	@brief	�X���b�h�ĊJ
	@param	handle	�ĊJ����X���b�h�n���h��
	@return	----
*/
//===========================================================================
void ResumeThread( ThreadHandle handle )
{
	_ThreadData&	thread	= _GetThreadMng()->GetDataByHandle( handle );
	NKASSERT( thread.validData == true, "invalid thread." );

	thread.nowState		= THREAD_STATE_START;
	
#if defined(_WIN32)
	::ResumeThread( static_cast<HANDLE>(thread.handle) );
#else
	// TODO
#endif
	

}



//===========================================================================
/*!	@brief		�X���b�h�҂�
	@param		handle	�҂X���b�h
	@return		----
*/
//===========================================================================
void JoinThread( ThreadHandle handle )
{
	_ThreadData&	thread	= _GetThreadMng()->GetDataByHandle( handle );
	NKASSERT( thread.validData == true, "invalid thread." );

#if defined(_WIN32)
	::WaitForSingleObject( static_cast<HANDLE>(thread.handle), INFINITE );
#else
	// TODO
#endif
}


	
//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̍쐬
	@param	----
	@return	----
*/
//===========================================================================
MutexHandle CreateMutexObject( void )
{
	MutexHandle	retMutex;

#if defined(_WIN32)
    retMutex	= ::static_cast<MutexHandle>(CreateMutex( NULL, FALSE, "Mutex" ));
	//retMutex	= ::CreateMutex( NULL, TRUE, "Mutex" );
	NULL_ASSERT( retMutex );
#else
	// TODO
#endif

	
	return retMutex;
}



//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̍쐬
	@param	��~����~���[�e�b�N�X�̃n���h��
	@return	----
*/
//===========================================================================
void DeleteMutexObject( MutexHandle handle )
{
#if defined(_WIN32)	
	NULL_ASSERT( handle );

	::CloseHandle( static_cast<HANDLE>(handle) );
	
#else
	// TODO
#endif
	
}



//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̃��b�N
	@param	handle	�~���[�e�b�N�X�n���h��
	@return	----
*/
//===========================================================================
bool LockMutex( MutexHandle handle )
{
#if defined(_WIN32)
	DWORD	result	= ::WaitForSingleObject( static_cast<HANDLE>(handle), INFINITE );

	if( result == WAIT_FAILED ) {
		return false;
	}

#else
	// TODO
#endif
	
	return true;
}


//===========================================================================
/*!	@brief	�~���[�e�b�N�X�̃A�����b�N
	@param	handle	�~���[�e�b�N�X�n���h��
	@return	----
*/
//===========================================================================
bool UnlockMutex( MutexHandle handle )
{
	
#if defined(_WIN32)
	BOOL	result	= ::ReleaseMutex( static_cast<HANDLE>(handle) );
	if( result == 0 ) {
		return false;
	}

#else
	// TODO
#endif
	
	return true;
}


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̍쐬
	@param		----
	@return		----
*/
//===========================================================================
CriticalSectionHandle CreateCriticalSection( void )
{
#if defined(_WIN32)
	//::InitializeCriticalSection();
	LPCRITICAL_SECTION	retHandle	= new CRITICAL_SECTION;
	::InitializeCriticalSection( retHandle );
	
	return static_cast<CriticalSectionHandle>(retHandle);
#else
	#error
#endif
}



//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V�����̍폜
	@param		handle	�폜����N���e�B�J���Z�N�V����
	@return		----
*/
//===========================================================================
void DeleteCriticalSection( CriticalSectionHandle handle )
{
#if defined(_WIN32)
	::DeleteCriticalSection( static_cast<LPCRITICAL_SECTION>(handle) );
	SafeDelete( static_cast<LPCRITICAL_SECTION>(handle) );
	
#else
	#error
#endif
}


//===========================================================================
/*!	@brief		�N���e�B�J���Z�N�V���������b�N
	@param		handle	�N���e�B�J���Z�N�V�����n���h��
	@return		----
*/
//===========================================================================
void LockCriticalSection( CriticalSectionHandle handle )
{
#if defined(_WIN32)
	::EnterCriticalSection( static_cast<LPCRITICAL_SECTION>(handle) );
#else
	#error
#endif
}


//===========================================================================
/*	brief		�N���e�B�J���Z�N�V�������A�����b�N
	param		handle	�N���e�B�J���Z�N�V�����n���h��
	return		----
*/
//===========================================================================
void UnlockCriticalSection( CriticalSectionHandle handle )
{
#if defined(_WIN32)
	::LeaveCriticalSection( static_cast<LPCRITICAL_SECTION>(handle) );
#else
	#error
#endif
}


//===========================================================================
/*	brief	�S�ẴX���b�h���~������
	param	----
	return	----
*/
//===========================================================================
void SuspendAllThread()
{
	for( u32 i = 0; i < _GetThreadMng()->GetSize(); ++i ) {
		_ThreadData&	thread	= _GetThreadMng()->GetDataByIndex( i );

		if( thread.nowState != THREAD_STATE_SUSPEND ) {
			thread.nowState	= THREAD_STATE_SUSPEND;
			
#if defined(_WIN32)
			::SuspendThread( static_cast<HANDLE>(thread.handle) );
#else
			// TODO
#endif
		}
	}

}


//===========================================================================
/*	brief	�S�ẴX���b�h���ĊJ������
	param	----
	return	----
*/
//===========================================================================
void ResumeAllThread()
{
	for( u32 i = 0; i < _GetThreadMng()->GetSize(); ++i ) {
		_ThreadData&	thread	= _GetThreadMng()->GetDataByIndex( i );

		if( thread.nowState != THREAD_STATE_START ) {
			thread.nowState		= THREAD_STATE_START;
			
#if defined(_WIN32)
			::ResumeThread( static_cast<HANDLE>(thread.handle) );
#else
			// TODO
#endif
		}
	}
	
}

}	// namespace thread
}	// namespace nk
