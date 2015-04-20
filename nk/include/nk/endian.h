//=============================================================================
/*!	@file	endian.h
	@brief	�G���f�B�A��
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_ENDIAN_H
#define NK_ENDIAN_H


namespace nk {


enum ENDIAN_TYPE {
	BIG_ENDIAN,		//!< �r�b�O�G���f�B�A��
	LITTLE_ENDIAN,	//!< ���g���G���f�B�A��
	
	UNKNOWN_ENDIAN,	//!< �G���[
};


//===========================================================================
/*!	@brief		�G���f�B�A������������
*/
//===========================================================================
void		InitializeEndian();

//===========================================================================
/*!	@brief		�G���f�B�A���^�C�v���擾
*/
//===========================================================================
ENDIAN_TYPE	GetEndian();
	
}	// namespace nk


#endif  // NK_ENDIAN_H