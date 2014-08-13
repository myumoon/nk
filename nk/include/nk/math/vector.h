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

#include <nk/nk.h>
#include <nk/math/vecutil.inl>
#include <nk/math/math.h>

namespace nk {
namespace math {


class Matrix44;
struct Vec2;
struct Vec3;
struct Vec4;


//=============================================================================
/*!	@brief	2要素のベクトル
*/
//=============================================================================
struct Vec2 {
	
	enum { ELEMEENTS = 2 };
	
	//! 要素
	union {
		struct { f32 x; f32 y; };
		f32	ary[2];
	};

	//! {
	//! コンストラクタ
	Vec2();
	Vec2( f32 x, f32 y );
	Vec2( f32* ary2 );
	Vec2( const Vec2& vec2 );
	Vec2( const Vec3& vec3 );
	Vec2( const Vec4& vec4 );
	//! }
	
	//! デストラクタ
	~Vec2() {}

	
	//===========================================================================
	/*!	@brief		クリア
	*/
	//===========================================================================
	void	Clear()
	{
		VecClear( *this );
	}

	//===========================================================================
	/*!	@brief		ノルムの2乗を返す
	*/
	//===========================================================================
	f32	GetNorm2() const
	{
		return VecGetNorm2( *this );
	}

	//===========================================================================
	/*!	@brief		ノルムを返す
	*/
	//===========================================================================
	f32	GetNorm() const
	{
		return VecGetNorm( *this );
	}

	//===========================================================================
	/*!	@brief		正規化
	*/
	//===========================================================================
	void Normalize()
	{
		VecNorm( *this );
	}

	//===========================================================================
	/*!	@brief		正規化済みのベクトルを返す
	*/
	//===========================================================================
	Vec2 GetNormalized() const
	{
		return VecGetNormalized( *this );
	}

	//===========================================================================
	/*!	@brief		0ベクトルならtrueを返す
	*/
	//===========================================================================
	bool IsZero() const
	{
		return VecIsZero( *this );
	}

	//===========================================================================
	/*!	@brief		符号を逆にする
	*/
	//===========================================================================
	void	Inverse()
	{
		VecInvere( *this );
	}

	//===========================================================================
	/*!	@brief		足し算
	*/
	//===========================================================================
	Vec2	operator+( const Vec2& rhs ) const
	{
		return VecOpAdd( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		引き算
	*/
	//===========================================================================
	Vec2	operator-( const Vec2& rhs ) const
	{
		return VecOpSub( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		掛け算
	*/
	//===========================================================================
	Vec2	operator*( f32 scalar ) const
	{
		return VecOpMul( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		割り算
	*/
	//===========================================================================
	Vec2	operator/( f32 scalar ) const
	{
		return VecOpDiv( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		等しい
	*/
	//===========================================================================
	bool	operator==( const Vec2& rhs ) const
	{
		return VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		等しくない
	*/
	//===========================================================================
	bool	operator!=( const Vec2& rhs ) const
	{
		return !VecEqual( *this, rhs );
	}

};


//=============================================================================
/*!	@brief	3要素のベクトル
*/
//=============================================================================
struct Vec3 {
	
	enum { ELEMEENTS = 3 };
	
	//! 要素
	union {
		struct { f32 x; f32 y; f32 z; };
		f32	ary[3];
	};

	//! {
	//! コンストラクタ
	Vec3();
	Vec3( f32 x, f32 y, f32 z );
	Vec3( f32* ary3 );
	Vec3( const Vec2& vec2 );
	Vec3( const Vec3& vec3 );
	Vec3( const Vec4& vec4 );
	//! }

	//! デストラクタ
	~Vec3() {}

	
	//===========================================================================
	/*!	@brief		クリア
	*/
	//===========================================================================
	void	Clear()
	{
		VecClear( *this );
	}

	//===========================================================================
	/*!	@brief		ノルムの2乗を返す
	*/
	//===========================================================================
	f32	GetNorm2() const
	{
		return VecGetNorm2( *this );
	}

	//===========================================================================
	/*!	@brief		ノルムを返す
	*/
	//===========================================================================
	f32	GetNorm() const
	{
		return VecGetNorm( *this );
	}

	//===========================================================================
	/*!	@brief		正規化
	*/
	//===========================================================================
	void Normalize()
	{
		VecNorm( *this );
	}

	//===========================================================================
	/*!	@brief		正規化済みのベクトルを返す
	*/
	//===========================================================================
	Vec3 GetNormalized() const
	{
		return VecGetNormalized( *this );
	}

	//===========================================================================
	/*!	@brief		0ベクトルならtrueを返す
	*/
	//===========================================================================
	bool IsZero() const
	{
		return VecIsZero( *this );
	}

	//===========================================================================
	/*!	@brief		符号を逆にする
	*/
	//===========================================================================
	void	Inverse()
	{
		VecInvere( *this );
	}

	//===========================================================================
	/*!	@brief		足し算
	*/
	//===========================================================================
	Vec3	operator+( const Vec3& rhs ) const
	{
		return VecOpAdd( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		引き算
	*/
	//===========================================================================
	Vec3	operator-( const Vec3& rhs ) const
	{
		return VecOpSub( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		掛け算
	*/
	//===========================================================================
	Vec3	operator*( f32 scalar ) const
	{
		return VecOpMul( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		割り算
	*/
	//===========================================================================
	Vec3	operator/( f32 scalar ) const
	{
		return VecOpDiv( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		等しい
	*/
	//===========================================================================
	bool	operator==( const Vec3& rhs ) const
	{
		return VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		等しくない
	*/
	//===========================================================================
	bool	operator!=( const Vec3& rhs ) const
	{
		return !VecEqual( *this, rhs );
	}
};


//=============================================================================
/*!	@brief	4要素のベクトル
*/
//=============================================================================
struct Vec4 {

	enum { ELEMEENTS = 4 };
	
	//! 要素
	union {
		struct { f32 x; f32 y; f32 z; f32 w; };
		f32	ary[4];
	};


	//! {
	//! コンストラクタ
	Vec4();
	Vec4( f32 x, f32 y, f32 z, f32 w );
	Vec4( f32* ary4 );
	Vec4( const Vec2& vec2 );
	Vec4( const Vec3& vec3 );
	Vec4( const Vec4& vec4 );
	//! }

	//! デストラクタ
	~Vec4() {}


	//===========================================================================
	/*!	@brief		クリア
	*/
	//===========================================================================
	void	Clear()
	{
		VecClear( *this );
	}

	//===========================================================================
	/*!	@brief		ノルムの2乗を返す
	*/
	//===========================================================================
	f32	GetNorm2() const
	{
		return VecGetNorm2( *this );
	}

	//===========================================================================
	/*!	@brief		ノルムを返す
	*/
	//===========================================================================
	f32	GetNorm() const
	{
		return VecGetNorm( *this );
	}

	//===========================================================================
	/*!	@brief		正規化
	*/
	//===========================================================================
	void Normalize()
	{
		VecNorm( *this );
	}

	//===========================================================================
	/*!	@brief		正規化済みのベクトルを返す
	*/
	//===========================================================================
	Vec4 GetNormalized() const
	{
		return VecGetNormalized( *this );
	}

	//===========================================================================
	/*!	@brief		0ベクトルならtrueを返す
	*/
	//===========================================================================
	bool IsZero() const
	{
		return VecIsZero( *this );
	}

	//===========================================================================
	/*!	@brief		符号を逆にする
	*/
	//===========================================================================
	void	Inverse()
	{
		VecInvere( *this );
	}

	//===========================================================================
	/*!	@brief		足し算
	*/
	//===========================================================================
	Vec4	operator+( const Vec4& rhs ) const
	{
		return VecOpAdd( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		引き算
	*/
	//===========================================================================
	Vec4	operator-( const Vec4& rhs ) const
	{
		return VecOpSub( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		掛け算
	*/
	//===========================================================================
	Vec4	operator*( f32 scalar ) const
	{
		return VecOpMul( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		割り算
	*/
	//===========================================================================
	Vec4	operator/( f32 scalar ) const
	{
		return VecOpDiv( *this, scalar );
	}

	//===========================================================================
	/*!	@brief		等しい
	*/
	//===========================================================================
	bool	operator==( const Vec4& rhs ) const
	{
		return VecEqual( *this, rhs );
	}

	//===========================================================================
	/*!	@brief		等しくない
	*/
	//===========================================================================
	bool	operator!=( const Vec4& rhs ) const
	{
		return !VecEqual( *this, rhs );
	}
};


//===========================================================================
/*!	@brief		なす角
	@param		
	@return		ラジアン
*/
//===========================================================================
//f32		CalcAngle( const Vector& vec1, const Vector& vec2 );

//===========================================================================
/*!	@brief		内積
	@param		none
	@return		none
*/
//===========================================================================
//f32		DotProduct( const Vector& vec1, const Vector& vec2 );

//===========================================================================
/*!	@brief		外積
	@param		none
	@return		none
*/
//===========================================================================
//Vector	CrossProduct( const Vector& vec1, const Vector& vec2 );

//===========================================================================
/*!	@brief		符号が全部一致する場合はtrueを返します
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
                              ベクトルクラス
*/
//=============================================================================
//template<class T = f32>
class Vector {
public:
	//----------------------メンバ変数-----------------------
	union {
		f32	v[4];

		struct {
			f32	x, y, z, w;
		};
	};


	//-----------------------メソッド------------------------

	//!	値のセット
	void SetVector( f32 x, f32 y, f32 z = 0.0f, f32 w = 0.0f );
	void SetVector( const Vector& );	

	//! 0クリア
	void Clear();

	//! 正規化
	void Normalize();

	//! 正規化したベクトルを取得
	Vector GetNormalizeVec( void ) const;

	//! ベクトルを逆にする
	void Inversion();

	//! ノルムを取得
	f32 GetNorm() const;

	//! ノルムの二乗を取得
	f32 GetNorm2() const;

	//! ゼロベクトルかどうかチェック
	bool IsVectorZero( void ) const;

	//! 表示
	void Disp( void ) const { PRINTF("x = %f, y = %f, z = %f, w = %f, norm = %f\n", x, y, z, w, GetNorm()); }

	//! アクセス
	f32& operator[]( std::size_t i ) {
		ASSERT( i < 4, "error" );
		return v[i];
	}
	const f32& operator[]( std::size_t i ) const {
		ASSERT( i < 4, "error" );
		return v[i];
	}

	//! 演算子
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
	
	//-------------コンストラクタ・デストラクタ--------------
	Vector( f32 x = 0.0f, f32 y = 0.0f, f32 z = 0.0f, f32 w = 0.0f );	//!< コンストラクタ
	Vector( const Vector & );											//!< コピーコンストラクタ
	
	//template<class T>
	//Vector( const T& rhs )
	//{
	//	(*this).operator=( rhs );
	//}
	virtual~Vector();															//!< デストラクタ
};


/* ベクトルのなす角 */
f32		CalcVectorAngle( const Vector*, const Vector* );
f32		CalcVectorAngle( const Vector&, const Vector& );

/* ベクトルの内積 */
f32		CalcDotProduct( const Vector*, const Vector* );
f32		CalcDotProduct( const Vector&, const Vector& );

/* ベクトルの外積 */
Vector	CalcCrossProduct( const Vector*, const Vector* );
Vector	CalcCrossProduct( const Vector&, const Vector& );

/* 符号が全部一致するか */
bool	IsSameDirection( const Vector&, const Vector& );

#endif

}	// namespace math
}	// namespace nk


#endif  // NK_VECTOR_H
