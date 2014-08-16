//=============================================================================
/*!	@file	matrix.cpp
	@brief	�s��
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#include <nk/math/matrix.h>
#include <nk/nk.h>
#include <nk/math/vector.h>

namespace nk {
namespace math {


//===========================================================================
/*	brief	�R���X�g���N�^
	param	none
*/
//===========================================================================
Matrix44::Matrix44()
{
	//Clear();
}


//===========================================================================
/*	brief	�R���X�g���N�^
	param	�v�f
*/
//===========================================================================
Matrix44::Matrix44(
	f32	m00, f32 m10, f32 m20, f32 m30,
	f32	m01, f32 m11, f32 m21, f32 m31,
	f32	m02, f32 m12, f32 m22, f32 m32,
	f32	m03, f32 m13, f32 m23, f32 m33
)
{
	this->m00	= m00;
	this->m10	= m10;
	this->m20	= m20;
	this->m30	= m30;
	this->m01	= m01;
	this->m11	= m11;
	this->m21	= m21;
	this->m31	= m31;
	this->m02	= m02;
	this->m12	= m12;
	this->m22	= m22;
	this->m32	= m32;
	this->m03	= m03;
	this->m13	= m13;
	this->m23	= m23;
	this->m33	= m33;
}

//===========================================================================
/*	brief	�R���X�g���N�^
	param	none
*/
//===========================================================================
Matrix44::Matrix44( const f32* m16 )
{
	for( s32 i = 0; i < 16; ++i ) {
		ary16[i]	= m16[i];
	}
}

//===========================================================================
/*	brief	�f�X�g���N�^
	param	none
*/
//===========================================================================
Matrix44::~Matrix44()
{
}


//===========================================================================
/*	brief		�N���A
	param		none
	return		none
*/
//===========================================================================
void Matrix44::Clear()
{
	for(s32 i = 0; i < 16; i++) {
		ary16[i] = 0;
	}
}


//===========================================================================
/*	brief		�t�s��ɕϊ�
	param		none
	return		none
*/
//===========================================================================
void Matrix44::Inverse()
{
	Matrix44	work( *this );

	Matrix44	inv	= Identity();

	// �|���o���@
	s32 i = 0, j = 0, k = 0;
	for( i = 0; i < 4; ++i ) {
		f32	buf	= 1.0f / work[i * 4 + i];
		
		for( j = 0; j < 4; ++j ) {
			work[i * 4 + j]	*= buf;
			inv[i * 4 + j]	*= buf;
		}
		for( j = 0; j < 4; ++j ) {
			if( i != j ) {
				buf	= work[j * 4 + i];
				for( k = 0; k < 4; ++k ) {
					work[j * 4 + k]	-= work[i * 4 + k] * buf;
					inv[j * 4 + k]	-= inv[i * 4 + k] * buf;
				}
			}
		}
	}

	*this	= inv;
}


//===========================================================================
/*	brief		�s�Ɨ�����ւ�
	param		none
	return		none
*/
//===========================================================================
void Matrix44::Transpose()
{
	Matrix44	swap;

	for( s32 i = 0; i < 4; ++i ) {
		for( s32 j = 0; j < 4; ++j ) {
			swap[j * 4 + i] = ary16[i * 4 + j];
		}
	}

	*this	= swap;
}


//===========================================================================
/*	brief	*���Z�q�̃I�[�o�[���[�h
	param	mat	: �|����s��
	return	����
*/
//===========================================================================
Matrix44 Matrix44::operator*( const Matrix44& rhs ) const
{
	Matrix44 ans;
	ans.Clear();


	#define MAT1 this->ary44
	#define MAT2 rhs.ary44

	ans.ary44[0][0]	=	MAT1[0][0] * MAT2[0][0] + MAT1[1][0] * MAT2[0][1] + MAT1[2][0] * MAT2[0][2] + MAT1[3][0] * MAT2[0][3];
	ans.ary44[0][1]	=	MAT1[0][1] * MAT2[0][0] + MAT1[1][1] * MAT2[0][1] + MAT1[2][1] * MAT2[0][2] + MAT1[3][1] * MAT2[0][3];
	ans.ary44[0][2]	=	MAT1[0][2] * MAT2[0][0] + MAT1[1][2] * MAT2[0][1] + MAT1[2][2] * MAT2[0][2] + MAT1[3][2] * MAT2[0][3];
	ans.ary44[0][3]	=	MAT1[0][3] * MAT2[0][0] + MAT1[1][3] * MAT2[0][1] + MAT1[2][3] * MAT2[0][2] + MAT1[3][3] * MAT2[0][3];

	ans.ary44[1][0]	=	MAT1[0][0] * MAT2[1][0] + MAT1[1][0] * MAT2[1][1] + MAT1[2][0] * MAT2[1][2] + MAT1[3][0] * MAT2[1][3];
	ans.ary44[1][1]	=	MAT1[0][1] * MAT2[1][0] + MAT1[1][1] * MAT2[1][1] + MAT1[2][1] * MAT2[1][2] + MAT1[3][1] * MAT2[1][3];
	ans.ary44[1][2]	=	MAT1[0][2] * MAT2[1][0] + MAT1[1][2] * MAT2[1][1] + MAT1[2][2] * MAT2[1][2] + MAT1[3][2] * MAT2[1][3];
	ans.ary44[1][3]	=	MAT1[0][3] * MAT2[1][0] + MAT1[1][3] * MAT2[1][1] + MAT1[2][3] * MAT2[1][2] + MAT1[3][3] * MAT2[1][3];
																								 
	ans.ary44[2][0]	=	MAT1[0][0] * MAT2[2][0] + MAT1[1][0] * MAT2[2][1] + MAT1[2][0] * MAT2[2][2] + MAT1[3][0] * MAT2[2][3];
	ans.ary44[2][1]	=	MAT1[0][1] * MAT2[2][0] + MAT1[1][1] * MAT2[2][1] + MAT1[2][1] * MAT2[2][2] + MAT1[3][1] * MAT2[2][3];
	ans.ary44[2][2]	=	MAT1[0][2] * MAT2[2][0] + MAT1[1][2] * MAT2[2][1] + MAT1[2][2] * MAT2[2][2] + MAT1[3][2] * MAT2[2][3];
	ans.ary44[2][3]	=	MAT1[0][3] * MAT2[2][0] + MAT1[1][3] * MAT2[2][1] + MAT1[2][3] * MAT2[2][2] + MAT1[3][3] * MAT2[2][3];
																								 
	ans.ary44[3][0]	=	MAT1[0][0] * MAT2[3][0] + MAT1[1][0] * MAT2[3][1] + MAT1[2][0] * MAT2[3][2] + MAT1[3][0] * MAT2[3][3];
	ans.ary44[3][1]	=	MAT1[0][1] * MAT2[3][0] + MAT1[1][1] * MAT2[3][1] + MAT1[2][1] * MAT2[3][2] + MAT1[3][1] * MAT2[3][3];
	ans.ary44[3][2]	=	MAT1[0][2] * MAT2[3][0] + MAT1[1][2] * MAT2[3][1] + MAT1[2][2] * MAT2[3][2] + MAT1[3][2] * MAT2[3][3];
	ans.ary44[3][3]	=	MAT1[0][3] * MAT2[3][0] + MAT1[1][3] * MAT2[3][1] + MAT1[2][3] * MAT2[3][2] + MAT1[3][3] * MAT2[3][3];

	#undef MAT1
	#undef MAT2

	return ans;
}



//===========================================================================
/*!	@brief	*=���Z�q�̃I�[�o�[���[�h
	@param	mat	: �|�����킹��s��
	@return	
*/
//===========================================================================
void Matrix44::operator*=( const Matrix44 &rhs )
{
	Matrix44 temp(*this);

	this->ary44[0][0]	=	temp.ary44[0][0] * rhs.ary44[0][0] + temp.ary44[1][0] * rhs.ary44[0][1] + temp.ary44[2][0] * rhs.ary44[0][2] + temp.ary44[3][0] * rhs.ary44[0][3];
	this->ary44[0][1]	=	temp.ary44[0][1] * rhs.ary44[0][0] + temp.ary44[1][1] * rhs.ary44[0][1] + temp.ary44[2][1] * rhs.ary44[0][2] + temp.ary44[3][1] * rhs.ary44[0][3];
	this->ary44[0][2]	=	temp.ary44[0][2] * rhs.ary44[0][0] + temp.ary44[1][2] * rhs.ary44[0][1] + temp.ary44[2][2] * rhs.ary44[0][2] + temp.ary44[3][2] * rhs.ary44[0][3];
	this->ary44[0][3]	=	temp.ary44[0][3] * rhs.ary44[0][0] + temp.ary44[1][3] * rhs.ary44[0][1] + temp.ary44[2][3] * rhs.ary44[0][2] + temp.ary44[3][3] * rhs.ary44[0][3];

	this->ary44[1][0]	=	temp.ary44[0][0] * rhs.ary44[1][0] + temp.ary44[1][0] * rhs.ary44[1][1] + temp.ary44[2][0] * rhs.ary44[1][2] + temp.ary44[3][0] * rhs.ary44[1][3];
	this->ary44[1][1]	=	temp.ary44[0][1] * rhs.ary44[1][0] + temp.ary44[1][1] * rhs.ary44[1][1] + temp.ary44[2][1] * rhs.ary44[1][2] + temp.ary44[3][1] * rhs.ary44[1][3];
	this->ary44[1][2]	=	temp.ary44[0][2] * rhs.ary44[1][0] + temp.ary44[1][2] * rhs.ary44[1][1] + temp.ary44[2][2] * rhs.ary44[1][2] + temp.ary44[3][2] * rhs.ary44[1][3];
	this->ary44[1][3]	=	temp.ary44[0][3] * rhs.ary44[1][0] + temp.ary44[1][3] * rhs.ary44[1][1] + temp.ary44[2][3] * rhs.ary44[1][2] + temp.ary44[3][3] * rhs.ary44[1][3];
																		 
	this->ary44[2][0]	=	temp.ary44[0][0] * rhs.ary44[2][0] + temp.ary44[1][0] * rhs.ary44[2][1] + temp.ary44[2][0] * rhs.ary44[2][2] + temp.ary44[3][0] * rhs.ary44[2][3];
	this->ary44[2][1]	=	temp.ary44[0][1] * rhs.ary44[2][0] + temp.ary44[1][1] * rhs.ary44[2][1] + temp.ary44[2][1] * rhs.ary44[2][2] + temp.ary44[3][1] * rhs.ary44[2][3];
	this->ary44[2][2]	=	temp.ary44[0][2] * rhs.ary44[2][0] + temp.ary44[1][2] * rhs.ary44[2][1] + temp.ary44[2][2] * rhs.ary44[2][2] + temp.ary44[3][2] * rhs.ary44[2][3];
	this->ary44[2][3]	=	temp.ary44[0][3] * rhs.ary44[2][0] + temp.ary44[1][3] * rhs.ary44[2][1] + temp.ary44[2][3] * rhs.ary44[2][2] + temp.ary44[3][3] * rhs.ary44[2][3];
																		 
	this->ary44[3][0]	=	temp.ary44[0][0] * rhs.ary44[3][0] + temp.ary44[1][0] * rhs.ary44[3][1] + temp.ary44[2][0] * rhs.ary44[3][2] + temp.ary44[3][0] * rhs.ary44[3][3];
	this->ary44[3][1]	=	temp.ary44[0][1] * rhs.ary44[3][0] + temp.ary44[1][1] * rhs.ary44[3][1] + temp.ary44[2][1] * rhs.ary44[3][2] + temp.ary44[3][1] * rhs.ary44[3][3];
	this->ary44[3][2]	=	temp.ary44[0][2] * rhs.ary44[3][0] + temp.ary44[1][2] * rhs.ary44[3][1] + temp.ary44[2][2] * rhs.ary44[3][2] + temp.ary44[3][2] * rhs.ary44[3][3];
	this->ary44[3][3]	=	temp.ary44[0][3] * rhs.ary44[3][0] + temp.ary44[1][3] * rhs.ary44[3][1] + temp.ary44[2][3] * rhs.ary44[3][2] + temp.ary44[3][3] * rhs.ary44[3][3];

}




//===========================================================================
/*!	@brief	=���Z�q�I�[�o�[���[�h
	@param	mat	: ������s���s��
	@return	*this
*/
//===========================================================================
const Matrix44& Matrix44::operator=( const Matrix44& rhs )
{
	for(s32 i = 0; i < 16; i++) {
		ary16[i] = rhs.ary16[i];
	}

	return *this;
}



//===========================================================================
/*!	@brief	�s����R���\�[���ɕ\��
	@param	�Ȃ�
	@return	�Ȃ�
*/
//===========================================================================
void Matrix44::Disp()
{
	NKPRINTF("Matrix44 ( %p )\n", this);

	for( s32 i = 0; i < 4; ++i ) {
		for( s32 j = 0; j < 4; ++j ) {
			NKPRINTF("%f ", ary44[i][j]);
		}
		NKPRINTF("\n");
	}

}


//===========================================================================
/*	brief		�[���N���A���ꂽ�s����擾
	param		none
	return		�[���N���A���ꂽ�s��
*/
//===========================================================================
Matrix44 Matrix44::Zero()
{
	Matrix44	mat;
	mat.Clear();
	
	return mat;
}

//===========================================================================
/*	brief	�P�ʍs����擾
	param	none
	return	�P�ʍs��
*/
//===========================================================================
Matrix44 Matrix44::Identity()
{
	Matrix44	mat(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return mat;
}

//===========================================================================
/*	brief	�g��s��𐶐�
	param	x,y,z:�e���ɑ΂��Ă̊g�嗦
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::Scale( const Vec3& vec3 )
{
	Matrix44 mat(
		vec3.x, 0,      0,      0,
		0,      vec3.y, 0,      0,
		0,      0,      vec3.z, 0,
		0,      0,      0,      1
	);

	return mat;
}


//===========================================================================
/*	brief	�g��s��𐶐�
	param	rate	: �g�嗦
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::Scale( f32 rate )
{

	return Scale( Vec3( rate, rate, rate ) );
}



//===========================================================================
/*	brief	X����]�s��𐶐�
	param	theta	��]�p�x(���W�A���p)
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::RotateX( f32 theta )
{
	const f32 cos_theta = cos(theta);
	const f32 sin_theta = sin(theta);
	
	Matrix44 mat(
		1.0f,    0.0f,        0.0f,       0.0f,
		0.0f,    cos_theta,   sin_theta,  0.0f,
		0.0f,    -sin_theta,  cos_theta,  0.0f,
		0.0f,    0.0f,        0.0f,       1.0f
	);

	return mat;
}



//===========================================================================
/*	brief	Y����]�s��𐶐�
	param	theta	��]�p�x(���W�A���p)
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::RotateY( f32 theta )
{
	const f32 cos_theta = cos(theta);
	const f32 sin_theta = sin(theta);

	Matrix44 mat(
		cos_theta,  0,      -sin_theta, 0,
		0,          1,      0,          0,
		sin_theta,  0,      cos_theta,  0,
		0,          0,      0,          1
	);

	return mat;
}


//===========================================================================
/*	brief	Z����]�s��𐶐�
	param	theta	��]�p�x(���W�A���p)
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::RotateZ( f32 theta )
{
	const f32 cos_theta = cos(theta);
	const f32 sin_theta = sin(theta);

	Matrix44 mat(
		cos_theta,  sin_theta,  0,      0,
		-sin_theta, cos_theta,  0,      0,
		0,          0,          1,      0,
		0,          0,          0,      1
	);

	return mat;
}


//===========================================================================
/*	brief	�C�ӂ̎��ɑ΂����]�s��𐶐�
	param	axis	��]��
	param	theta	��]�p�x(���W�A���p)
	
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::RotateAxis( const Vec3& axis, f32 theta )
{
	const f32 cos_theta = cos(theta), sin_theta = sin(theta);
	const f32 cos1		= 1.0f - cos_theta;		// (1 - cos��)
	const f32 px		= axis.x;
	const f32 py		= axis.y;
	const f32 pz		= axis.z;

	Matrix44 mat(
		cos1 * px * px + cos_theta,      cos1 * px * py - pz * sin_theta, cos1 * pz * px + py * sin_theta, 0.0f,
		cos1 * px * py + pz * sin_theta, cos1 * py * py + cos_theta,      cos1 * py * pz - px * sin_theta, 0.0f,
		cos1 * pz * px - py * sin_theta, cos1 * py * pz + px * sin_theta, cos1 * pz * pz + cos_theta,      0.0f,
		0.0f,                            0.0f,                            0.0f,                            1.0f
	);

	return mat;
}




//===========================================================================
/*	brief	���s�ړ��s��𐶐�
	param	trans	�ړ���
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::Translation( const Vec2& trans )
{
	Matrix44 mat(
		1.0f,    0.0f,    0.0f,    0.0f,
		0.0f,    1.0f,    0.0f,    0.0f,
		0.0f,    0.0f,    1.0f,    0.0f,
		trans.x, trans.y, 0.0f,    1.0f
	);

	return mat;
}



//===========================================================================
/*	brief	���s�ړ��s��𐶐�
	param	trans	�ړ���
	return	���������s��
*/
//===========================================================================
Matrix44 Matrix44::Translation( const Vec3& trans )
{
	Matrix44 mat(
		1.0f,    0.0f,    0.0f,    0.0f,
		0.0f,    1.0f,    0.0f,    0.0f,
		0.0f,    0.0f,    1.0f,    0.0f,
		trans.x, trans.y, trans.z, 1.0f
	);
	
	return mat;
}



#if 0

//===========================================================================
/*	brief	�ˉe�s��𐶐�
	param	fieldOfVision	������p�x
	param	aspectRatio		�E�C���h�E�̃A�X�y�N�g��(w/h)
	param	nearDistance	�ŏ�������
	param	farDistance		�ő������
	return	���������s��
*/
//===========================================================================
Matrix44 CreatePerspectiveFieldOfView(f64 fieldOfVision, f64 aspectRatio, f64 nearDistance, f64 farDistance)
{
	Matrix44 result;
	result.Clear();
	f64 rad = Rad(fieldOfVision);
	f64 y_scale = 1.0 / tan(rad * 0.5);			// 1/tan(x) == cos(x)
	f64 x_scale = y_scale / aspectRatio;	

	result.SetElement(0, 0, static_cast<f32>(x_scale));
	result.SetElement(1, 1, static_cast<f32>(y_scale));
	
	result.SetElement(2, 2, static_cast<f32>(farDistance / (nearDistance - farDistance)));
	//result.SetElement(2, 2, static_cast<f32>(farDistance / (farDistance - nearDistance)));	// ASURA��

	// ������t�ɂ���ƃE�C���h�E��(0,0)����Ɖ��ŕς��
	result.SetElement(2, 3, -1.0f);	
	//result.SetElement(2, 3, 1.0f);	
	
	result.SetElement(3, 2, static_cast<f32>((nearDistance * farDistance) / (nearDistance - farDistance)));
	//result.SetElement(3, 2, static_cast<f32>((-nearDistance * farDistance) / (farDistance - nearDistance)));

	//�����ˉe�ϊ��s�񐶐�
	// http://www.xxxxx13.com/gles2_ViewProjection.html
	//
	//void HelperFunc::MatrixPerspectiveFovLH(MATRIX2 *p, f32 radian, f32 aspect, f32 zmin, f32 zmax){
	//f32 ys=cot(radian / 2);
	//f32 xs=ys / aspect;
	//
	//f32 w22=zmax / (zmax - zmin);
	//f32 w32=-zmin * zmax / (zmax - zmin);
	//
	//p->m[0][0] = xs; p->m[0][1] = 0.0f; p->m[0][2] = 0.0f; p->m[0][3] = 0.0f;
	//p->m[1][0] = 0.0f; p->m[1][1] = ys; p->m[1][2] = 0.0f; p->m[1][3] = 0.0f;
	//p->m[2][0] = 0.0f; p->m[2][1] = 0.0f; p->m[2][2] = w22; p->m[2][3] = 1.0f;
	//p->m[3][0] = 0.0f; p->m[3][1] = 0.0f; p->m[3][2] = w32; p->m[3][3] = 0.0f;
	//}
	return result;
}
#endif
//===========================================================================
/*	brief	�e�N�X�`����Ԃɒ����s����K��
	param	screenW	: ��
	param	screenH	: ����
	return	���������s��
*/
//===========================================================================
Matrix44 CreatePerspectiveToTextureSpace( f32 screenW, f32 screenH )
{
	const f32 offsetX = 0.5f + ( 0.5f / screenW );
	const f32 offsetY = 0.5f + ( 0.5f / screenH );

	math::Matrix44 scaleBias(
		0.5f,       0.0f,       0.0f,       offsetX,
		0.0f,       0.5f,       0.0f,       offsetY,
		0.0f,       0.0f,       1.0f,       0.0f,
		offsetX,    offsetY,    0.0f,       1.0f
		);

	return scaleBias;
}


}	// namespace math
}	// namespace nk


