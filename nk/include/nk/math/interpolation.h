//=============================================================================
/*!	@file	interpolation.h
	@brief	補間
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
	@param		prev	直前位置
	@param		x0		位置0
	@param		x1		位置1
	@param		next	次の位置
	@param		t		補間位置(0.0～1.0)
	@return		補間結果
*/
//===========================================================================
f32 InterpolationCatmullRom( f32 prev, f32 begin, f32 end, f32 next, f32 t );


//===========================================================================
/*!	@brief		CatmullRomスプライン曲線
	@param		prev	直前位置
	@param		x0		位置0
	@param		x1		位置1
	@param		next	次の位置
	@param		t		補間位置(0.0～1.0)
	@return		補間結果

	@note		begin-end間を補間します。
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
