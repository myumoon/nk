//=============================================================================
/*!	@file	thread.cpp
	@brief	スレッド関数
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
		THREAD_STATE_START,		//!< 開始
		THREAD_STATE_SUSPEND,	//!< 中断
		THREAD_STATE_WAIT,		//!< 待ち
	};
	
// スレッドデータ
	struct _ThreadData {
		bool						validData;		//!< 有効？
		nk::thread::ThreadHandle	handle;			//!< スレッドハンドル
		ThreadId					id;				//!< スレッドID
		nk::thread::ThreadFunc		func;			//!< 関数
		void*						argument;		//!< スレッド引数
		THREAD_STATE				nowState;		//!< スレッドの状態
		s64							createdTime;	//!< 生成時間
#if defined(_DEBUG)
		char						name[128];		//!< スレッド名
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

	
	// 生成したスレッドを管理
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
		std::vector<_ThreadData*>		m_vecThread;	// 管理スレッド
		_ThreadData						m_dummy;		// 失敗時ダミー
	};

	_ThreadManager*		_threadManager	= NULL;			// スレッド管理
	
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
/*!	@brief	初期化
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
/*!	@brief	終了処理
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

	// メモリ解放
	_GetThreadMng()->Destroy();

	SafeDelete( _threadManager );
}
	
	

//===========================================================================
/*!	@brief	スレッド生成
	@param	func		呼び出し関数
	@param	arg			スレッド関数引数
	@param	priority	優先度
	@param	stackSize	スタックサイズ(デフォルト0)
	@return	true.生成成功	false.生成失敗
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
/*!	@brief	スレッド終了
	@param	handle	終了するスレッドハンドル
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
/*!	@brief	スレッド開始
	@param	handle	開始するスレッドハンドル
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
/*!	@brief	スレッド中断
	@param	handle	中断するスレッドハンドル
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
/*!	@brief	スレッド再開
	@param	handle	再開するスレッドハンドル
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
/*!	@brief		スレッド待ち
	@param		handle	待つスレッド
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
/*!	@brief	ミューテックスの作成
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
/*!	@brief	ミューテックスの作成
	@param	停止するミューテックスのハンドル
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
/*!	@brief	ミューテックスのロック
	@param	handle	ミューテックスハンドル
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
/*!	@brief	ミューテックスのアンロック
	@param	handle	ミューテックスハンドル
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
/*!	@brief		クリティカルセクションの作成
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
/*!	@brief		クリティカルセクションの削除
	@param		handle	削除するクリティカルセクション
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
/*!	@brief		クリティカルセクションをロック
	@param		handle	クリティカルセクションハンドル
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
/*	brief		クリティカルセクションをアンロック
	param		handle	クリティカルセクションハンドル
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
/*	brief	全てのスレッドを停止させる
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
/*	brief	全てのスレッドを再開させる
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
