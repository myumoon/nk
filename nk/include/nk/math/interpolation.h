//=============================================================================
/*!	@file	interpolation.h
	@brief	���
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_INTERPOLATION_H
#define NK_INTERPOLATION_H

#include <nk/types.h>


namespace nk {
namespace math {

struct Vec2;
struct Vec3;
struct Vec4;

//===========================================================================
/*!	@brief		CatmullRom
	@param		prev	���O�ʒu
	@param		x0		�ʒu0
	@param		x1		�ʒu1
	@param		next	���̈ʒu
	@param		t		��Ԉʒu(0.0�`1.0)
	@return		��Ԍ���
*/
//===========================================================================
f32 InterpolationCatmullRom( f32 prev, f32 begin, f32 end, f32 next, f32 t );


//===========================================================================
/*!	@brief		CatmullRom�X�v���C���Ȑ�
	@param		prev	���O�ʒu
	@param		x0		�ʒu0
	@param		x1		�ʒu1
	@param		next	���̈ʒu
	@param		t		��Ԉʒu(0.0�`1.0)
	@return		��Ԍ���

	@note		begin-end�Ԃ��Ԃ��܂��B
*/
//===========================================================================
Vector	InterpolationCatmullRom(
	const nk::math::Vec3&	prev,
	const nk::math::Vec3&	begin,
	const nk::math::Vec3&	end,
	const nk::math::Vec3&	next,
	f32						t
);

	
}	// namespace math
}	// namespace nk





#endif  // NK_INTERPOLATION_H
