//=============================================================================
/*!	@file	vector.h
	@brief	vector
	@author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#ifndef NK_VECTOR_H
#define NK_VECTOR_H


#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include <nk/nk.h>
#include <nk/math/vecutil.inl>
#include <nk/math/math.h>

namespace nk {
namespace math {


struct Matrix44;
struct Vec2;
struct Vec3;
struct Vec4;


//=============================================================================
/*!	@brief	2�v�f�̃x�N�g��
*/
//=============================================================================
struct Vec2 {
	
	enum { ELEMEENTS = 2 };
	
	//! �v�f
	union {
		struct { f32 x; f32 y; };
		f32	ary[2];
	};

	//! @{
	//! �R���X�g���N�^
	Vec2();
	Vec2( f32 x, f32 y );
	Vec2( f32* ary2 );
	Vec2( const Vec2& vec2 );
	Vec2( const Vec3& vec3 );
	Vec2( const Vec4& vec4 );
	//! @}
	
	//! �f�X�g���N�^
	~Vec2() {}

	
	//===========================================================================
	/*!	@brief		�N���A
	*/
	//===========================================================================
	void	Clear()
	{
		VecClear( *this );
	}

	//===========================================================================
	/*!	@brief		�m������2���Ԃ�
	*/
	//===========================================================================
	f32	GetNorm2() const
	{
		return VecGetNorm2( *this );
	}

	//===========================================================================
	/*!	@brief		�m������Ԃ�
	*/
	//===========================================================================
	f32	GetNorm() const
	{
		return VecGetNorm( *this );
	}

	//===========================================================================
	/*!	@brief		���K��
	*/
	//===========================================================================
	void Normalize()
	{
		VecNorm( *this );
	}

	//===========================================================================
	/*!	@brief		���K���ς݂̃x�N�g����Ԃ�
	*/
	//===========================================================================
	Vec2 GetNormalized() const
	{
		return VecGetNormalized( *this );
	}

	//===========================================================================
	/*!	@brief		0�x�N�g���Ȃ�true��Ԃ�
	*/
	//===========================================================================
	bool IsZero() const
	{
		return VecIsZero( *this );
	}

	//===========================================================================
	/*!	@brief		�������t�ɂ���
	*/
	//===========================================================================
	void	Inverse()
	{
		VecInvere( *this );
	}

	//===========================================================================
	/*!	@brief		�����Z
	*/
	//===========================================================================
	Vec2	operator+( const Vec2& rhs ) const
	{
		return VecOpAdd( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�����Z
	*/
	//===========================================================================
	Vec2	operator-( const Vec2& rhs ) const
	{
		return VecOpSub( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�|���Z
	*/
	//===========================================================================
	Vec2	operator*( f32 scalar ) const
	{
		return VecOpMul( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		����Z
	*/
	//===========================================================================
	Vec2	operator/( f32 scalar ) const
	{
		return VecOpDiv( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		������
	*/
	//===========================================================================
	bool	operator==( const Vec2& rhs ) const
	{
		return VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�������Ȃ�
	*/
	//===========================================================================
	bool	operator!=( const Vec2& rhs ) const
	{
		return !VecEqual( *this, rhs );
	}


	//===========================================================================
	/*!	@brief		X���x�N�g�����擾
		@param		none
		@return		Vec2(1.0f, 0.0f)
	*/
	//===========================================================================
	static Vec2 AxisX()
	{
		return Vec2( 1.0f, 0.0f );
	}

	//===========================================================================
	/*!	@brief		Y���x�N�g�����擾
		@param		none
		@return		Vec2(0.0f, 1.0f)
	*/
	//===========================================================================
	static Vec2 AxisY()
	{
		return Vec2( 0.0f, 1.0f);
	}

	//===========================================================================
	/*!	@brief		������ɕϊ�
	*/
	//===========================================================================
	std::string ToStr() const
	{
		std::stringstream	str;
		str	<< "(" << x << "," << y << ")";
		return str.str();
	}
};


//=============================================================================
/*!	@brief	3�v�f�̃x�N�g��
*/
//=============================================================================
struct Vec3 {
	
	enum { ELEMEENTS = 3 };
	
	//! �v�f
	union {
		struct { f32 x; f32 y; f32 z; };
		f32	ary[3];
	};

	//! @{
	//! �R���X�g���N�^
	Vec3();
	Vec3( f32 x, f32 y, f32 z );
	Vec3( f32* ary3 );
	Vec3( const Vec2& vec2 );
	Vec3( const Vec3& vec3 );
	Vec3( const Vec4& vec4 );
	//! @}

	//! �f�X�g���N�^
	~Vec3() {}

	
	//===========================================================================
	/*!	@brief		�N���A
	*/
	//===========================================================================
	void	Clear()
	{
		VecClear( *this );
	}

	//===========================================================================
	/*!	@brief		�m������2���Ԃ�
	*/
	//===========================================================================
	f32	GetNorm2() const
	{
		return VecGetNorm2( *this );
	}

	//===========================================================================
	/*!	@brief		�m������Ԃ�
	*/
	//===========================================================================
	f32	GetNorm() const
	{
		return VecGetNorm( *this );
	}

	//===========================================================================
	/*!	@brief		���K��
	*/
	//===========================================================================
	void Normalize()
	{
		VecNorm( *this );
	}

	//===========================================================================
	/*!	@brief		���K���ς݂̃x�N�g����Ԃ�
	*/
	//===========================================================================
	Vec3 GetNormalized() const
	{
		return VecGetNormalized( *this );
	}

	//===========================================================================
	/*!	@brief		0�x�N�g���Ȃ�true��Ԃ�
	*/
	//===========================================================================
	bool IsZero() const
	{
		return VecIsZero( *this );
	}

	//===========================================================================
	/*!	@brief		�������t�ɂ���
	*/
	//===========================================================================
	void	Inverse()
	{
		VecInvere( *this );
	}

	//===========================================================================
	/*!	@brief		�����Z
	*/
	//===========================================================================
	Vec3	operator+( const Vec3& rhs ) const
	{
		return VecOpAdd( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�����Z
	*/
	//===========================================================================
	Vec3	operator-( const Vec3& rhs ) const
	{
		return VecOpSub( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�|���Z
	*/
	//===========================================================================
	Vec3	operator*( f32 scalar ) const
	{
		return VecOpMul( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		�|���Z
	*/
	//===========================================================================
	Vec3	operator*( const Matrix44& rhs ) const;

	//===========================================================================
	/*!	@brief		����Z
	*/
	//===========================================================================
	Vec3	operator/( f32 scalar ) const
	{
		return VecOpDiv( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		������
	*/
	//===========================================================================
	bool	operator==( const Vec3& rhs ) const
	{
		return VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�������Ȃ�
	*/
	//===========================================================================
	bool	operator!=( const Vec3& rhs ) const
	{
		return !VecEqual( *this, rhs );
	}


	//===========================================================================
	/*!	@brief		X���x�N�g�����擾
		@param		none
		@return		Vec3(1.0f, 0.0f, 0.0f)
	*/
	//===========================================================================
	static Vec3 AxisX()
	{
		return Vec3( 1.0f, 0.0f, 0.0f );
	}

	//===========================================================================
	/*!	@brief		Y���x�N�g�����擾
		@param		none
		@return		Vec3(0.0f, 1.0f, 0.0f)
	*/
	//===========================================================================
	static Vec3 AxisY()
	{
		return Vec3( 0.0f, 1.0f, 0.0f );
	}


	//===========================================================================
	/*!	@brief		Z���x�N�g�����擾
		@param		none
		@return		Vec3(0.0f, 0.0f, 1.0f)
	*/
	//===========================================================================
	static Vec3 AxisZ()
	{
		return Vec3( 0.0f, 0.0f, 1.0f );
	}

	//===========================================================================
	/*!	@brief		������ɕϊ�
	*/
	//===========================================================================
	std::string ToStr() const
	{
		std::stringstream	str;
		str	<< "(" << x << "," << y << "," << z << ")";
		return str.str();
	}
};


//=============================================================================
/*!	@brief	4�v�f�̃x�N�g��
*/
//=============================================================================
struct Vec4 {

	enum { ELEMEENTS = 4 };
	
	//! �v�f
	union {
		struct { f32 x; f32 y; f32 z; f32 w; };
		f32	ary[4];
	};


	//! @{
	//! �R���X�g���N�^
	Vec4();
	Vec4( f32 x, f32 y, f32 z, f32 w );
	Vec4( f32* ary4 );
	Vec4( const Vec2& vec2 );
	Vec4( const Vec3& vec3 );
	Vec4( const Vec4& vec4 );
	//! @}

	//! �f�X�g���N�^
	~Vec4() {}


	//===========================================================================
	/*!	@brief		�N���A
	*/
	//===========================================================================
	void	Clear()
	{
		VecClear( *this );
	}

	//===========================================================================
	/*!	@brief		�m������2���Ԃ�
	*/
	//===========================================================================
	f32	GetNorm2() const
	{
		return VecGetNorm2( *this );
	}

	//===========================================================================
	/*!	@brief		�m������Ԃ�
	*/
	//===========================================================================
	f32	GetNorm() const
	{
		return VecGetNorm( *this );
	}

	//===========================================================================
	/*!	@brief		���K��
	*/
	//===========================================================================
	void Normalize()
	{
		VecNorm( *this );
	}

	//===========================================================================
	/*!	@brief		���K���ς݂̃x�N�g����Ԃ�
	*/
	//===========================================================================
	Vec4 GetNormalized() const
	{
		return VecGetNormalized( *this );
	}

	//===========================================================================
	/*!	@brief		0�x�N�g���Ȃ�true��Ԃ�
	*/
	//===========================================================================
	bool IsZero() const
	{
		return VecIsZero( *this );
	}

	//===========================================================================
	/*!	@brief		�������t�ɂ���
	*/
	//===========================================================================
	void	Inverse()
	{
		VecInvere( *this );
	}

	//===========================================================================
	/*!	@brief		�����Z
	*/
	//===========================================================================
	Vec4	operator+( const Vec4& rhs ) const
	{
		return VecOpAdd( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�����Z
	*/
	//===========================================================================
	Vec4	operator-( const Vec4& rhs ) const
	{
		return VecOpSub( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�|���Z
	*/
	//===========================================================================
	Vec4	operator*( f32 scalar ) const
	{
		return VecOpMul( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		�|���Z
	*/
	//===========================================================================
	Vec4	operator*( const Matrix44& rhs ) const;


	//===========================================================================
	/*!	@brief		����Z
	*/
	//===========================================================================
	Vec4	operator/( f32 scalar ) const
	{
		return VecOpDiv( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		������
	*/
	//===========================================================================
	bool	operator==( const Vec4& rhs ) const
	{
		return VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		�������Ȃ�
	*/
	//===========================================================================
	bool	operator!=( const Vec4& rhs ) const
	{
		return !VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		X���x�N�g�����擾
		@param		none
		@return		Vec4(1.0f, 0.0f, 0.0f, 0.0f)
	*/
	//===========================================================================
	static Vec4 AxisX()
	{
		return Vec4( 1.0f, 0.0f, 0.0f, 0.0f );
	}

	//===========================================================================
	/*!	@brief		Y���x�N�g�����擾
		@param		none
		@return		Vec4(0.0f, 1.0f, 0.0f, 0.0f)
	*/
	//===========================================================================
	static Vec4 AxisY()
	{
		return Vec4( 0.0f, 1.0f, 0.0f, 0.0f );
	}


	//===========================================================================
	/*!	@brief		Z���x�N�g�����擾
		@param		none
		@return		Vec4(0.0f, 0.0f, 1.0f, 0.0f)
	*/
	//===========================================================================
	static Vec4 AxisZ()
	{
		return Vec4( 0.0f, 0.0f, 1.0f, 0.0f );
	}


	//===========================================================================
	/*!	@brief		W���x�N�g�����擾
		@param		none
		@return		Vec4(0.0f, 0.0f, 1.0f, 0.0f)
	*/
	//===========================================================================
	static Vec4 AxisW()
	{
		return Vec4( 0.0f, 0.0f, 0.0f, 1.0f );
	}

	
	//===========================================================================
	/*!	@brief		������ɕϊ�
	*/
	//===========================================================================
	std::string ToStr() const
	{
		std::stringstream	str;
		str	<< "(" << x << "," << y << "," << z << "," << w << ")";
		return str.str();
	}
};


//===========================================================================
/*!	@brief		�x�N�g���̂Ȃ��p�����W�A���Ŏ擾
	@param		begin	�J�n�ʒu
	@param		end		�I���ʒu
	@return		���W�A��
	@attention	�ǂ��炩�̃x�N�g�����[���x�N�g���̏ꍇ
					- Debug�r���h���̓A�T�[�V�����Ɉ���������܂�
					- Release�ł�
*/
//===========================================================================
f32 CalcAngle( const Vec3& begin, const Vec2& end );

//===========================================================================
/*!	@brief		���ς��v�Z
	@param		vec1,vec2	�v�Z���s���x�N�g��
	@return		����
*/
//===========================================================================
template<typename T>
inline f32 DotProduct( const T& vec1, const T& vec2 )
{
	return VecDotProduct( vec1, vec2 );
}

//===========================================================================
/*!	@brief		�O�ς��v�Z
	@param		vec1,vec2	�v�Z���s���x�N�g��
	@return		�O��
*/
//===========================================================================
Vec3 CrossProduct( const Vec3& vec1, const Vec3& vec2 );

//===========================================================================
/*!	@brief		�������S����v����ꍇ��true��Ԃ��܂�
	@param		none
	@return		none
*/
//===========================================================================
template<typename T>
inline bool IsSameDirection( const T& vec1, const T& vec2 )
{
	if( Sign(vec1.x) != Sign(vec2.x) ) {
		return false;
	}
	if( Sign(vec1.y) != Sign(vec2.y) ) {
		return false;
	}
	if( Sign(vec1.z) != Sign(vec2.z) ) {
		return false;
	}
	
	return true;
}




#if 0
//=============================================================================
/*!
                              �x�N�g���N���X
*/
//=============================================================================
//template<class T = f32>
class Vector {
public:
	//----------------------�����o�ϐ�-----------------------
	union {
		f32	v[4];

		struct {
			f32	x, y, z, w;
		};
	};


	//-----------------------���\�b�h------------------------

	//!	�l�̃Z�b�g
	void SetVector( f32 x, f32 y, f32 z = 0.0f, f32 w = 0.0f );
	void SetVector( const Vector& );	

	//! 0�N���A
	void Clear();

	//! ���K��
	void Normalize();

	//! ���K�������x�N�g�����擾
	Vector GetNormalizeVec( void ) const;

	//! �x�N�g�����t�ɂ���
	void Inversion();

	//! �m�������擾
	f32 GetNorm() const;

	//! �m�����̓����擾
	f32 GetNorm2() const;

	//! �[���x�N�g�����ǂ����`�F�b�N
	bool IsVectorZero( void ) const;

	//! �\��
	void Disp( void ) const { PRINTF("x = %f, y = %f, z = %f, w = %f, norm = %f\n", x, y, z, w, GetNorm()); }

	//! �A�N�Z�X
	f32& operator[]( std::size_t i ) {
		ASSERT( i < 4, "error" );
		return v[i];
	}
	const f32& operator[]( std::size_t i ) const {
		ASSERT( i < 4, "error" );
		return v[i];
	}

	//! ���Z�q
	//template<class T>
	const Vector& operator=( const Vector& rhs )
	{
		for( std::size_t i = 0; i < 4; ++i ) {
			v[i]	= rhs[i];
		}
		return *this;
	}
#if defined(NK_USE_EXP_OPERATOR)
	Exp<Vector, OpPlus, Vector>			operator+( const Vector& rhs	) const;
	Exp<Vector, OpMinus, Vector>		operator-( const Vector& rhs	) const;
	Exp<Vector, OpMul, ExpScalar<f32> >	operator*( f32 rhs				) const;
//	Exp<Vector, OpDiv, Vector>		operator /	( f32 rhs ) const;
#else
	Vector  							operator+( const Vector &vec ) const;
	Vector  							operator-( const Vector &vec ) const;
	Vector  							operator*( f32 scalar		) const;
#endif
	
	Vector  							operator/( f32 scalar		) const;

	
	Vector&								operator+=( const Vector &vec	);
	Vector& 							operator+=( f32 a				);
	Vector  							operator-( void					) const;
	Vector& 							operator-=( const Vector &vec	);
	Vector& 							operator-=( f32 a				);
	Vector& 							operator*=( f32 scalar			);
	Vector  							operator*( const Matrix44&		) const;
	Vector&								operator/=( f32 scalar			);
	bool								operator==( const Vector &vec	) const;
	bool								operator!=( const Vector &vec	) const;

		
	//-------------�R���X�g���N�^�E�f�X�g���N�^--------------
	Vector( f32 x = 0.0f, f32 y = 0.0f, f32 z = 0.0f, f32 w = 0.0f );	//!< �R���X�g���N�^
	Vector( const Vector & );											//!< �R�s�[�R���X�g���N�^
	
	//template<class T>
	//Vector( const T& rhs )
	//{
	//	(*this).operator=( rhs );
	//}
	virtual~Vector();															//!< �f�X�g���N�^
};


/* �x�N�g���̂Ȃ��p */
f32		CalcVectorAngle( const Vector*, const Vector* );
f32		CalcVectorAngle( const Vector&, const Vector& );

/* �x�N�g���̓��� */
f32		CalcDotProduct( const Vector*, const Vector* );
f32		CalcDotProduct( const Vector&, const Vector& );

/* �x�N�g���̊O�� */
Vector	CalcCrossProduct( const Vector*, const Vector* );
Vector	CalcCrossProduct( const Vector&, const Vector& );

/* �������S����v���邩 */
bool	IsSameDirection( const Vector&, const Vector& );

#endif

}	// namespace math
}	// namespace nk


#endif  // NK_VECTOR_H