//=============================================================================
/*!	@file	quaternion.cpp
	@brief	クオータニオン
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
/*	brief	コンストラクタ
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
/*	brief	デストラクタ
	param	none
*/
//===========================================================================
Quaternion::~Quaternion()
{
}


//===========================================================================
/*	brief		単元化
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
/*	brief		正規化
	param		none
	return		none
*/
//===========================================================================
void Quaternion::Normalize()
{
	/* 四元数の大きさを計算する */
	const f32 mag = 1.0f / sqrtf(m_t * m_t + m_i * m_i + m_j * m_j + m_k * m_k);

	NKASSERT( 0.0f < mag, "mag = %f" );

	m_t *= mag;
	m_i *= mag;
	m_j *= mag;
	m_k *= mag;
}


//===========================================================================
/*	brief		ゼロ
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
/*	brief		X軸回転
	param		theta	回転量
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
/*	brief		Y軸回転
	param		theta	回転量
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
/*	brief		Z軸回転
	param		theta	回転量
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
/*	brief		任意軸回転
	param		axis	回転軸
	param		theta	回転量
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
	// 半分の角のsin cosを計算する
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
/*	brief		掛け算
	param		rhs		右辺
	return		結果
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
/*	brief	クォータニオンの内積
	param	q0, q1	: 計算するクォータニオン
	return	内積
*/
//===========================================================================
f32 Quaternion::DotProduct( const Quaternion &q0, const Quaternion &q1 )
{
	return q0.m_t * q1.m_t + q0.m_i * q1.m_i + q0.m_j * q1.m_j + q0.m_k * q1.m_k;
}


//===========================================================================
/*	brief	球面線形補間
	param	q0	: 開始時の姿勢
	param	q1	: 終了時の姿勢
	param	m_t	: 0.0～1.0の間で補間する
	return	補間したクォータニオン
*/
//===========================================================================
Quaternion Quaternion::Slerp( const Quaternion& q0, const Quaternion& q1, f32 m_t )
{
	// 範囲外チェック
	if(m_t <= 0.0f) {
		return q0;
	}
	if(m_t >= 1.0f) {
		return q1;
	}

	// cos計算
	f32 cosOmega = DotProduct( q0, q1 );

	// 負の内積の場合、-q1を用いる
	// 2つの四元数qと-qは同じ回転を表すが、異なる球面線形補間を生成する場合がある
	// 正確な角度を用いて回転するためにqか-qかを選択する
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

	// 補間用のフラクションを計算する
	// 2つの四元数がほとんど全く同じであるかチェックする
	f32 k0, k1;
	if( 1.0f <= cosOmega ) {
		// 非常に近い --- 単純に線形補間を用いる（ゼロ除算を防ぐ）
		k0 = 1.0f - m_t;
		k1 = m_t;
	}
	else {
		// 三角法の等式sin^2(Omega) + cos^2(Omega) = 1を用いて
		// この角度のsinを計算する
		const f32 sinOmega = sqrtf(1.0f - cosOmega * cosOmega);

		/* このsin と cos から角度を計算する */
		const f32 omega = atan2f( sinOmega, cosOmega );

		/* 除算が1回で済むように、分母の逆数を計算する */
		const f32 oneOverSinOmega = 1.0f / sinOmega;

		/* 補間パラメータを計算する */
		k0 = sin((1.0f - m_t) * omega) * oneOverSinOmega;
		k1 = sin(m_t * omega) * oneOverSinOmega;
	}

	// 補間する
	Quaternion result;
	result.m_i = k0 * q0.m_i + k1 * q1i;
	result.m_j = k0 * q0.m_j + k1 * q1j;
	result.m_k = k0 * q0.m_k + k1 * q1k;
	result.m_t = k0 * q0.m_t + k1 * q1t;

	return result;
}



//===========================================================================
/*	brief		行列に変換
	param		none
	return		none
*/
//===========================================================================
Matrix44 Quaternion::ToMatrix() const
{
	f32 m11, m12, m13;	//行列の回転成分
	f32 m21, m22, m23;
	f32 m31, m32, m33;

	/* 共通して用いる副次式を先に計算しておく */
	const f32 t = 2.0f * m_t;
	const f32 i = 2.0f * m_i;
	const f32 j = 2.0f * m_j;
	const f32 k = 2.0f * m_k;

	/* 行列の要素を設定する */
	
	/* i軸成分 */
	m11 = 1.0f - j * m_j - k * m_k;
	m21 = i * m_j + t * m_k;
	m31 = i * m_k - t * m_j; 
	
	/* j軸成分 */
	m12 = i * m_j - t * m_k;
	m22 = 1.0f - i * m_i - k * m_k;
	m32 = j * m_k + t * m_i;
	
	/* k軸成分 */
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
/*	brief		共役
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


