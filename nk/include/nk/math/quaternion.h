//=============================================================================
/*!	@file	quaternion.h
	@brief	�N�I�[�^�j�I��
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================


#ifndef NK_QUATERNION_H
#define NK_QUATERNION_H

#include <nk/types.h>


namespace nk {
namespace math {
	
struct Matrix44;
struct Vec3;
struct Vec4;
	
//=============================================================================
/*!	@brief		�N�H�[�^�j�I��
	@caution	�R���X�g���N�^���ŏ������͍s���܂���B
				�K�v�ɉ����� #Zero, #Identity ���̃N�H�[�^�j�I�������֐����Ăяo���Ă��������B
*/
//=============================================================================
class Quaternion {
public:
	
	
public:
	//! @{
	//! �R���X�g���N�^
	Quaternion();
	
	//! �f�X�g���N�^
	~Quaternion();
	//! @}
	
	//===========================================================================
	/*!	@brief		���K��
	*/
	//===========================================================================
	void			Normalize();

	//===========================================================================
	/*!	@brief		����
	*/
	//===========================================================================
	void			Conjugate();

	//===========================================================================
	/*!	@brief		�|���Z
	*/
	//===========================================================================
	Quaternion		operator*( const Quaternion& qua ) const;
	
	//===========================================================================
	/*!	@brief		�s��ɕϊ�
	*/
	//===========================================================================
	Matrix44		ToMatrix() const;

	//! @defgroup QuatanionInitializer Quatanion inititlizer
	//! @{
	//===========================================================================
	/*!	@brief		�[��
	*/
	//===========================================================================
	static Quaternion	Zero();
		
	//===========================================================================
	/*!	@brief		�P�ʌ�
	*/
	//===========================================================================
	static Quaternion	Identity();
	
	//===========================================================================
	/*!	@brief		X����]
	*/
	//===========================================================================
	static Quaternion	RotateX( f32 theta );

	//===========================================================================
	/*!	@brief		Y����]
	*/
	//===========================================================================
	static Quaternion	RotateY( f32 theta );

	//===========================================================================
	/*!	@brief		Z����]
	*/
	//===========================================================================
	static Quaternion	RotateZ( f32 theta );

	//===========================================================================
	/*!	@brief		Yaw Pitch Roll(Y,X,Z)
	*/
	//===========================================================================
	static Quaternion	YawPitchRoll( f32 yaw, f32 pitch, f32 roll );

	//===========================================================================
	/*!	@brief		�C�ӎ���]
	*/
	//===========================================================================
	static Quaternion	RotateAxis( const math::Vec3& axis, f32 theta );
	//! @}

	//===========================================================================
	/*!	@brief		����
		@param		qua1, qua2	�|�����킹��N�H�[�^�j�I��
		@return		none
	*/
	//===========================================================================
	static f32			DotProduct( const Quaternion &q0, const Quaternion &q1 );
	
	//===========================================================================
	/*!	@brief		���ʐ��`���
		@param		begin	�J�n
		@param		end		�I��
		@param		t		0.0-1.0
		@return		����
	*/
	//===========================================================================
	Quaternion Slerp( const Quaternion& begin, const Quaternion& end, f32 t );
	
private:
	f32		m_t;
	f32		m_i;
	f32		m_j;
	f32		m_k;
};


}	// namespace math
}	// namespace nk

#endif NK_QUATERNION_H