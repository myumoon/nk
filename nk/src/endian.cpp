//=============================================================================
/*!	@file	endian.h
	@brief	�G���f�B�A��
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================


#include <nk/endian.h>


namespace {
	nk::ENDIAN_TYPE		g_endianType	= nk::UNKNOWN_ENDIAN;
}	// unnamed


namespace nk {

//===========================================================================
/*!	@brief		������
	@param		----
	@return		----
*/
//===========================================================================
void InitializeEndian( void )
{
#if defined(__LITTLE_ENDIAN__)
	g_endianType	= LITTLE_ENDIAN;
#elif defined(__BIG_ENDIAN__)
	g_endianType	= BIG_ENDIAN;
#else
	int i = 1;
	if( *(char*)&i ) {
		g_endianType	= LITTLE_ENDIAN;
	}
	else {
		g_endianType	= BIG_ENDIAN;
	}
#endif
}


//===========================================================================
/*!	@brief		�G���f�B�A�����擾
	@param		----
	@return		ENDIAN_TYPE
*/
//===========================================================================
ENDIAN_TYPE	GetEndian( void )
{
	
	return g_endianType;
}
	
}	// namespace nk
