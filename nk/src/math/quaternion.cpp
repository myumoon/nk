//=============================================================================
/*!	@file	quaternion.cpp
	@brief	�N�I�[�^�j�I��
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================


#include <nk/math/quaternion.h>
#include <nk/nk.h>
#include <nk/math/matrix.h>
#include <nk/math/vector.h>

namespace nk {
namespace math {

//===========================================================================
/*	brief	�R���X�g���N�^
	param	none
*/
//===========================================================================
Quaternion::Quaternion()
{
// 	m_t	= 0.0f;
// 	m_i	= 0.0f;
// 	m_j	= 0.0f;
// 	m_k	= 0.0f;
}


//===========================================================================
/*	brief	�f�X�g���N�^
	param	none
*/
//===========================================================================
Quaternion::~Quaternion()
{
}


//===========================================================================
/*	brief		�P����
	param		none
	return		none
*/
//===========================================================================
Quaternion Quaternion::Identity()
{
	Quaternion	qua;
	qua.m_t = 1.0f;
	qua.m_i = qua.m_j = qua.m_k = 0.0f;

	return qua;
}


//===========================================================================
/*	brief		���K��
	param		none
	return		none
*/
//===========================================================================
void Quaternion::Normalize()
{
	/* �l�����̑傫�����v�Z���� */
	const f32 mag = 1.0f / sqrtf(m_t * m_t + m_i * m_i + m_j * m_j + m_k * m_k);

	NKASSERT( 0.0f < mag, "mag = %f" );

	m_t *= mag;
	m_i *= mag;
	m_j *= mag;
	m_k *= mag;
}


//===========================================================================
/*	brief		�[��
	param		none
	return		none
*/
//===========================================================================
Quaternion Quaternion::Zero()
{
	Quaternion	qua;
	qua.m_t	= 0.0f;
	qua.m_i	= 0.0f;
	qua.m_j	= 0.0f;
	qua.m_k	= 0.0f;

	return qua;
}

	
//===========================================================================
/*	brief		X����]
	param		theta	��]��
	return		none
*/
//===========================================================================
Quaternion Quaternion::RotateX( f32 theta )
{
	const f32	halfTheta = theta * 0.5f;

	Quaternion	qua;
	qua.m_t = cosf( halfTheta );
	qua.m_i = sinf( halfTheta );
	qua.m_j = 0.0f;
	qua.m_k = 0.0f;
	
	return qua;
}


//===========================================================================
/*	brief		Y����]
	param		theta	��]��
	return		none
*/
//===========================================================================
Quaternion Quaternion::RotateY( f32 theta )
{
	const f32	halfTheta = theta * 0.5f;

	Quaternion	qua;
	qua.m_t = cosf(halfTheta);
	qua.m_i = 0.0f;
	qua.m_j = sinf(halfTheta);
	qua.m_k = 0.0f;

	return qua;
}


//===========================================================================
/*	brief		Z����]
	param		theta	��]��
	return		none
*/
//===========================================================================
Quaternion Quaternion::RotateZ( f32 theta )
{
	const f32	halfTheta = theta * 0.5f;

	Quaternion	qua;
	qua.m_t = cosf(halfTheta);
	qua.m_i = 0.0f;
	qua.m_j = 0.0f;
	qua.m_k = sinf(halfTheta);

	return qua;
}


//===========================================================================
/*	brief		�C�ӎ���]
	param		axis	��]��
	param		theta	��]��
	return		none
*/
//===========================================================================
Quaternion Quaternion::RotateAxis( const math::Vec3 &axis, f32 theta )
{
	NKASSERT( 0.0f < fabs(axis.GetNorm() - 1.0f), "invalid axis" );

	const f32	halfTheta = theta * 0.5f;
	const f32	halfSin   = sinf( halfTheta );

	Quaternion	qua;
	qua.m_t = cosf(halfTheta);
	qua.m_i = axis.x * halfSin;
	qua.m_j = axis.y * halfSin;
	qua.m_k = axis.z * halfSin;

	return qua;
}


//===========================================================================
/*	brief		YawPitchRoll
	param		yaw
	param		pitch
	param		roll
	return		none
*/
//===========================================================================
Quaternion Quaternion::YawPitchRoll( f32 yaw, f32 pitch, f32 roll )
{
	// �����̊p��sin cos���v�Z����
	f32 sp, sr, sy;
	f32 cp, cr, cy;
	sp = sinf(pitch * 0.5f); cp = cosf(pitch * 0.5f);
	sr = sinf(roll  * 0.5f); cr = cosf(roll  * 0.5f);
	sy = sinf(yaw   * 0.5f); cy = cosf(yaw   * 0.5f);

	Quaternion	qua;
	qua.m_t = cy * cp * cr + sy * sp * sr;
	qua.m_i = cy * sp * cr + sy * cp * sr;
	qua.m_j =-cy * sp * sr + sy * cp * cp;
	qua.m_k =-sy * sp * cr + cy * cp * sr;

	return qua;
}


//===========================================================================
/*	brief		�|���Z
	param		rhs		�E��
	return		����
*/
//===========================================================================
Quaternion Quaternion::operator*( const Quaternion& rhs ) const
{
	Quaternion qua;

	qua.m_t = m_t * rhs.m_t - m_i * rhs.m_i - m_j * rhs.m_j - m_k * rhs.m_k;
	qua.m_i = m_t * rhs.m_i + m_i * rhs.m_t + m_j * rhs.m_k - m_k * rhs.m_j;
	qua.m_j = m_t * rhs.m_j + m_j * rhs.m_t + m_k * rhs.m_i - m_k * rhs.m_k;
	qua.m_k = m_t * rhs.m_k + m_k * rhs.m_t + m_i * rhs.m_j - m_k * rhs.m_i;

	return qua;
}


//===========================================================================
/*	brief	�N�H�[�^�j�I���̓���
	param	q0, q1	: �v�Z����N�H�[�^�j�I��
	return	����
*/
//===========================================================================
f32 Quaternion::DotProduct( const Quaternion &q0, const Quaternion &q1 )
{
	return q0.m_t * q1.m_t + q0.m_i * q1.m_i + q0.m_j * q1.m_j + q0.m_k * q1.m_k;
}


//===========================================================================
/*	brief	���ʐ��`���
	param	q0	: �J�n���̎p��
	param	q1	: �I�����̎p��
	param	m_t	: 0.0�`1.0�̊Ԃŕ�Ԃ���
	return	��Ԃ����N�H�[�^�j�I��
*/
//===========================================================================
Quaternion Quaternion::Slerp( const Quaternion& q0, const Quaternion& q1, f32 m_t )
{
	// �͈͊O�`�F�b�N
	if(m_t <= 0.0f) {
		return q0;
	}
	if(m_t >= 1.0f) {
		return q1;
	}

	// cos�v�Z
	f32 cosOmega = DotProduct( q0, q1 );

	// ���̓��ς̏ꍇ�A-q1��p����
	// 2�̎l����q��-q�͓�����]��\�����A�قȂ鋅�ʐ��`��Ԃ𐶐�����ꍇ������
	// ���m�Ȋp�x��p���ĉ�]���邽�߂�q��-q����I������
	f32 q1t = q1.m_t;
	f32 q1i = q1.m_i;
	f32 q1j = q1.m_j;
	f32 q1k = q1.m_k;
	if( cosOmega < 0.0f ) {
		q1t			= -q1t;
		q1i			= -q1i;
		q1j			= -q1j;
		q1k			= -q1k;
		cosOmega	= -cosOmega;
	}

	// ��ԗp�̃t���N�V�������v�Z����
	// 2�̎l�������قƂ�ǑS�������ł��邩�`�F�b�N����
	f32 k0, k1;
	if( 1.0f <= cosOmega ) {
		// ���ɋ߂� --- �P���ɐ��`��Ԃ�p����i�[�����Z��h���j
		k0 = 1.0f - m_t;
		k1 = m_t;
	}
	else {
		// �O�p�@�̓���sin^2(Omega) + cos^2(Omega) = 1��p����
		// ���̊p�x��sin���v�Z����
		const f32 sinOmega = sqrtf(1.0f - cosOmega * cosOmega);

		/* ����sin �� cos ����p�x���v�Z���� */
		const f32 omega = atan2f( sinOmega, cosOmega );

		/* ���Z��1��ōςނ悤�ɁA����̋t�����v�Z���� */
		const f32 oneOverSinOmega = 1.0f / sinOmega;

		/* ��ԃp�����[�^���v�Z���� */
		k0 = sin((1.0f - m_t) * omega) * oneOverSinOmega;
		k1 = sin(m_t * omega) * oneOverSinOmega;
	}

	// ��Ԃ���
	Quaternion result;
	result.m_i = k0 * q0.m_i + k1 * q1i;
	result.m_j = k0 * q0.m_j + k1 * q1j;
	result.m_k = k0 * q0.m_k + k1 * q1k;
	result.m_t = k0 * q0.m_t + k1 * q1t;

	return result;
}



//===========================================================================
/*	brief		�s��ɕϊ�
	param		none
	return		none
*/
//===========================================================================
Matrix44 Quaternion::ToMatrix() const
{
	f32 m11, m12, m13;	//�s��̉�]����
	f32 m21, m22, m23;
	f32 m31, m32, m33;

	/* ���ʂ��ėp���镛�������Ɍv�Z���Ă��� */
	const f32 t = 2.0f * m_t;
	const f32 i = 2.0f * m_i;
	const f32 j = 2.0f * m_j;
	const f32 k = 2.0f * m_k;

	/* �s��̗v�f��ݒ肷�� */
	
	/* i������ */
	m11 = 1.0f - j * m_j - k * m_k;
	m21 = i * m_j + t * m_k;
	m31 = i * m_k - t * m_j; 
	
	/* j������ */
	m12 = i * m_j - t * m_k;
	m22 = 1.0f - i * m_i - k * m_k;
	m32 = j * m_k + t * m_i;
	
	/* k������ */
	m13 = i * m_k + t * m_j;
	m23 = j * m_k - t * m_i; 
	m33 = 1.0f - i * m_i - j * m_j;

	Matrix44 retMat(
		m11,	m21,	m31,	0.0f,
		m12,	m22,	m32,	0.0f,
		m13,	m23,	m33,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f
	);

	return retMat;
}


//===========================================================================
/*	brief		����
	param		none
	return		none
*/
//===========================================================================
void Quaternion::Conjugate()
{
	m_t = m_t;

	m_i	= -m_t;
	m_j	= -m_j;
	m_k	= -m_k;
}

}	// namespace math
}	// namespace nk


