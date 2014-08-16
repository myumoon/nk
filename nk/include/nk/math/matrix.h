//=============================================================================
/*!	@file	matrix.h
	@brief	�s��
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================


#ifndef NK_MATRIX_H
#define NK_MATRIX_H

#include <math.h>
#include <iostream>

#include <nk/types.h>


namespace nk {
namespace math {

struct Vec2;
struct Vec3;
struct Vec4;

//=============================================================================
/*!	@brief	
*/
//=============================================================================
struct Matrix44 {

	union {
// 		struct {
// 			f32	m00, m01, m02, m03;
// 			f32	m10, m11, m12, m13;
// 			f32	m20, m21, m22, m23;
// 			f32	m30, m31, m32, m33;
// 		};
		struct {
			f32	m00, m10, m20, m30;
			f32	m01, m11, m21, m31;
			f32	m02, m12, m22, m32;
			f32	m03, m13, m23, m33;
		};
		f32	ary44[4][4];
		f32	ary16[16];
	};

	//! @{
	//! �R���X�g���N�^
	//! @attention	�[���N���A�͂��Ă��܂���
	//! 			�K�v�ɉ�����#GetIdentity
	Matrix44();	
	Matrix44(
		f32	m00, f32 m10, f32 m20, f32 m30,
		f32	m01, f32 m11, f32 m21, f32 m31,
		f32	m02, f32 m12, f32 m22, f32 m32,
		f32	m03, f32 m13, f32 m23, f32 m33
	);
	Matrix44( const f32* a16 );
	
	//! �f�X�g���N�^
	~Matrix44();
	//! @}


	//===========================================================================
	/*!	@brief		�v�f���N���A
	*/
	//===========================================================================
	void	Clear();

	//===========================================================================
	/*!	@brief		���s�ړ��������擾
	*/
	//===========================================================================
	Vec3	GetTrans() const;

	//===========================================================================
	/*!	@brief		�t�s��ɕϊ�
	*/
	//===========================================================================
	void	Inverse();

	//===========================================================================
	/*!	@brief		�s�Ɨ�̓���ւ�
	*/
	//===========================================================================
	void	Transpose();

	//! @{
	//===========================================================================
	/*!	@brief		���Z�q�̃I�[�o�[���[�h	
	*/
	//===========================================================================
	//Matrix44		operator+( const Matrix44& ) const;
	Matrix44		operator*( const Matrix44& ) const;
	void			operator*=( const Matrix44& );
	const Matrix44&	operator=( const Matrix44& );
	//! @}

	//===========================================================================
	/*!	@brief		�Y���A�N�Z�X
	*/
	//===========================================================================
	const f32&	operator[]( std::size_t i ) const
	{
		return ary16[i];
	}

	//===========================================================================
	/*!	@brief		�Y���A�N�Z�X
	*/
	//===========================================================================
	f32&	operator[]( std::size_t i )
	{
		return ary16[i];
	}


	//! @{
	//===========================================================================
	/*!	@brief		�s��𐶐�
	*/
	//===========================================================================
	//! �[���N���A���ꂽ�s��
	static Matrix44 Zero();
	
	//! �P�ʍs��
	static Matrix44	Identity();
		
	//! ���s�ړ��s��
	static Matrix44	Translation( const Vec2& vec2 );
	static Matrix44	Translation( const Vec3& vec3 );

	//! �g��s��
	static Matrix44	Scale( const Vec2& vec2 );
	static Matrix44	Scale( const Vec3& vec3 );
	static Matrix44	Scale( f32 rate );

	//! X����]�s��
	static Matrix44	RotateX( f32 theta );
	
	//! Y����]�s��
	static Matrix44	RotateY( f32 theta );
	
	//! Z����]�s��
	static Matrix44	RotateZ( f32 theta );
	
	//! �C�ӎ���]�s��
	static Matrix44	RotateAxis( const Vec3& axis, f32 theta );

	//! �e�N�X�`����Ԃɒ����s��
	//! @todo	���m�F
	//!			�ꏊ��ς���
	static Matrix44	PerspectiveToTextureSpace( f32 screenW, f32 screenH );

	//! �ˉe�s��
	//! @todo	���m�F
	//!			�ꏊ��ς���
	//static Matrix44	PerspectiveFieldOfView();
	//! @}
	
	// �f�o�b�O�\��
	void Disp();
};




/* �ˉe�s��𐶐� */
//Matrix44	CreatePerspectiveFieldOfView( f64 field_of_vision, f64 aspect_ratio, f64 near, f64 far );
//Matrix44	CreatePerspectiveFieldOfView();


/* �ˉe��Ԃ���e�N�X�`����Ԃɕϊ������s��𐶐� */
//Matrix44	CreatePerspectiveToTextureSpace( f32 screenW, f32 screenH );

	
}	// namespace math
}	// namespace nk




#endif  // NK_MATRIX_H

#if 0

const s32 MATRIX_ROW = 4;			// �s
const s32 MATRIX_COL = 4;			// ��
const s32 MATRIX_MAX = MATRIX_ROW * MATRIX_COL;

//---------------------------------�O���錾---------------------------------
class Vector;

//----------------------------------���p��----------------------------------
/*! �s����i�[����^ */
union MatrixAry {
	f32 ary16[16];
	f32 ary44[4][4];
};



//=============================================================================
/*!
                     4x4�s��N���X
*/
//=============================================================================
class Matrix44 {
public:

	//	�R���X�g���N�^�E�f�X�g���N�^
	//---------------------------------------
	Matrix44();
	Matrix44(
		f32, f32, f32, f32, 
		f32, f32, f32, f32, 
		f32, f32, f32, f32, 
		f32, f32, f32, f32
	);
			Matrix44( f32* );							// 16�v�f������f32�z����R�s�[
			Matrix44( const Matrix44 & );				// �R�s�[�R���X�g���N�^
	virtual~Matrix44();								// �f�X�g���N�^


	//	�f�[�^�̃Z�b�g
	//---------------------------------------
	void Clear();				// 0�Ŗ��߂�
	void SetMatrix( f32 * );

	//	�v�f�̃Z�b�g
	//---------------------------------------
	void SetElement( s32 row, s32 col, f32 num );

	//	X���������擾
	//---------------------------------------
	Vector GetXAxis() const;

	//	Y���������擾
	//---------------------------------------
	Vector GetYAxis() const;

	//	Z���������擾
	//---------------------------------------
	Vector GetZAxis() const;

	//	���s�ړ��������擾
	//---------------------------------------
	Vector GetParallel() const;

	//	�ϊ�
	//---------------------------------------
	void	InitIdentityMatrix( void ) { Identity(); }	// �P�ʍs��(�폜�\��)
	void	Identity( void );							// �P�ʍs��
	void	InverseMatrix() { Inverse(); }				// �t�s��(�폜�\��)
	void	Inverse( void );							// �t�s��
	Vector	ApplyMatrixXYZ( const Matrix44& m1, const Vector& v );

	//	���s�ړ��������N���A
	//---------------------------------------
	void	ClearMoveComponent();

	//	�s�Ɨ�̓���ւ�
	//---------------------------------------
	void	Transpose();	


	//	GL�ɍs����Z�b�g
	//---------------------------------------
	void		SetGL( const Matrix44 *model );
	friend void SetGL( const Matrix44 *_view, const Matrix44 *_model );


	//	�f�[�^�̎擾	
	//---------------------------------------
	MatrixAry	GetMatrix() const { return matrix; }


	//	���Z�q�̃I�[�o�[���[�h	
	//---------------------------------------
	Matrix44	operator +	(const Matrix44 &	) const;	//!< �s��{�s��
	Vector		operator *	(const Vector &		) const;	//!< �s�񂘃x�N�g��
	Matrix44	operator *	(const Matrix44 &	) const;	//!< �s�񂘍s��
	void		operator *=	(const Matrix44 &	);			//!< �s�񂘍s��
	Matrix44&	operator =	(const Matrix44 &	);			//!< ���

	//! �A�N�Z�X
	f32	operator[]( std::size_t i ) const {
		return matrix.ary16[i];
	}

	//	�\��
	//---------------------------------------
	void Disp();

private:
	MatrixAry		matrix;					// 4*4�s��
};







//-----------------------------------------------
//	�ϊ��s��
//-----------------------------------------------
/* ���s�ړ� */
Matrix44	Translation( f32 x, f32 y, f32 z );
Matrix44	Translation( const Vector& xyz );

/* �g�� */
Matrix44	Expansion( f32 x, f32 y, f32 z );

/* �ϓ��Ɋg�� */
Matrix44	Expansion( f32 rate );

/* X����] */
Matrix44	RotateX( f32 theta );

/* Y����] */
Matrix44	RotateY( f32 theta );

/* Z����] */
Matrix44	RotateZ( f32 theta );

/* �C�ӂ̎��ŉ�]����ϊ��s���Ԃ� */
Matrix44	RotateAxis( f32 theta, const Vector *axis );
Matrix44	RotateAxis( f32 theta, const Vector& axis );

/* GL�ɍs����Z�b�g */
void		SetGL( const Matrix44*, const Matrix44* );

/* �ˉe�s��𐶐� */
Matrix44	CreatePerspectiveFieldOfView( f64 field_of_vision, f64 aspect_ratio, f64 near, f64 far );
Matrix44	CreatePerspectiveFieldOfView();


/* �ˉe��Ԃ���e�N�X�`����Ԃɕϊ������s��𐶐� */
Matrix44	CreatePerspectiveToTextureSpace( f32 screenW, f32 screenH );

//! �s���z��(16�v�f��f32�z��)�ɃR�s�[
void		CopyMatrix44ToArray( f32*, const Matrix44& );
void		CopyMatrix44ToArray( f64*, const Matrix44& );

}	// namespace math
}	// namespace nk

#endif
