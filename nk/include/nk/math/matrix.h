//=============================================================================
/*!	@file	matrix.h
	@brief	行列
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
	//! コンストラクタ
	//! @attention	ゼロクリアはしていません
	//! 			必要に応じて#GetIdentity
	Matrix44();	
	Matrix44(
		f32	m00, f32 m10, f32 m20, f32 m30,
		f32	m01, f32 m11, f32 m21, f32 m31,
		f32	m02, f32 m12, f32 m22, f32 m32,
		f32	m03, f32 m13, f32 m23, f32 m33
	);
	Matrix44( const f32* a16 );
	
	//! デストラクタ
	~Matrix44();
	//! @}


	//===========================================================================
	/*!	@brief		要素をクリア
	*/
	//===========================================================================
	void	Clear();

	//===========================================================================
	/*!	@brief		平行移動成分を取得
	*/
	//===========================================================================
	Vec3	GetTrans() const;

	//===========================================================================
	/*!	@brief		逆行列に変換
	*/
	//===========================================================================
	void	Inverse();

	//===========================================================================
	/*!	@brief		行と列の入れ替え
	*/
	//===========================================================================
	void	Transpose();

	//! @{
	//===========================================================================
	/*!	@brief		演算子のオーバーロード	
	*/
	//===========================================================================
	//Matrix44		operator+( const Matrix44& ) const;
	Matrix44		operator*( const Matrix44& ) const;
	void			operator*=( const Matrix44& );
	const Matrix44&	operator=( const Matrix44& );
	//! @}

	//===========================================================================
	/*!	@brief		添字アクセス
	*/
	//===========================================================================
	const f32&	operator[]( std::size_t i ) const
	{
		return ary16[i];
	}

	//===========================================================================
	/*!	@brief		添字アクセス
	*/
	//===========================================================================
	f32&	operator[]( std::size_t i )
	{
		return ary16[i];
	}


	//! @{
	//===========================================================================
	/*!	@brief		行列を生成
	*/
	//===========================================================================
	//! ゼロクリアされた行列
	static Matrix44 Zero();
	
	//! 単位行列
	static Matrix44	Identity();
		
	//! 平行移動行列
	static Matrix44	Translation( const Vec2& vec2 );
	static Matrix44	Translation( const Vec3& vec3 );

	//! 拡大行列
	static Matrix44	Scale( const Vec2& vec2 );
	static Matrix44	Scale( const Vec3& vec3 );
	static Matrix44	Scale( f32 rate );

	//! X軸回転行列
	static Matrix44	RotateX( f32 theta );
	
	//! Y軸回転行列
	static Matrix44	RotateY( f32 theta );
	
	//! Z軸回転行列
	static Matrix44	RotateZ( f32 theta );
	
	//! 任意軸回転行列
	static Matrix44	RotateAxis( const Vec3& axis, f32 theta );

	//! テクスチャ空間に直す行列
	//! @todo	未確認
	//!			場所を変える
	static Matrix44	PerspectiveToTextureSpace( f32 screenW, f32 screenH );

	//! 射影行列
	//! @todo	未確認
	//!			場所を変える
	//static Matrix44	PerspectiveFieldOfView();
	//! @}
	
	// デバッグ表示
	void Disp();
};




/* 射影行列を生成 */
//Matrix44	CreatePerspectiveFieldOfView( f64 field_of_vision, f64 aspect_ratio, f64 near, f64 far );
//Matrix44	CreatePerspectiveFieldOfView();


/* 射影空間からテクスチャ空間に変換した行列を生成 */
//Matrix44	CreatePerspectiveToTextureSpace( f32 screenW, f32 screenH );

	
}	// namespace math
}	// namespace nk




#endif  // NK_MATRIX_H

#if 0

const s32 MATRIX_ROW = 4;			// 行
const s32 MATRIX_COL = 4;			// 列
const s32 MATRIX_MAX = MATRIX_ROW * MATRIX_COL;

//---------------------------------前方宣言---------------------------------
class Vector;

//----------------------------------共用体----------------------------------
/*! 行列を格納する型 */
union MatrixAry {
	f32 ary16[16];
	f32 ary44[4][4];
};



//=============================================================================
/*!
                     4x4行列クラス
*/
//=============================================================================
class Matrix44 {
public:

	//	コンストラクタ・デストラクタ
	//---------------------------------------
	Matrix44();
	Matrix44(
		f32, f32, f32, f32, 
		f32, f32, f32, f32, 
		f32, f32, f32, f32, 
		f32, f32, f32, f32
	);
			Matrix44( f32* );							// 16個要素があるf32配列をコピー
			Matrix44( const Matrix44 & );				// コピーコンストラクタ
	virtual~Matrix44();								// デストラクタ


	//	データのセット
	//---------------------------------------
	void Clear();				// 0で埋める
	void SetMatrix( f32 * );

	//	要素のセット
	//---------------------------------------
	void SetElement( s32 row, s32 col, f32 num );

	//	X軸成分を取得
	//---------------------------------------
	Vector GetXAxis() const;

	//	Y軸成分を取得
	//---------------------------------------
	Vector GetYAxis() const;

	//	Z軸成分を取得
	//---------------------------------------
	Vector GetZAxis() const;

	//	平行移動成分を取得
	//---------------------------------------
	Vector GetParallel() const;

	//	変換
	//---------------------------------------
	void	InitIdentityMatrix( void ) { Identity(); }	// 単位行列(削除予定)
	void	Identity( void );							// 単位行列
	void	InverseMatrix() { Inverse(); }				// 逆行列(削除予定)
	void	Inverse( void );							// 逆行列
	Vector	ApplyMatrixXYZ( const Matrix44& m1, const Vector& v );

	//	平行移動成分をクリア
	//---------------------------------------
	void	ClearMoveComponent();

	//	行と列の入れ替え
	//---------------------------------------
	void	Transpose();	


	//	GLに行列をセット
	//---------------------------------------
	void		SetGL( const Matrix44 *model );
	friend void SetGL( const Matrix44 *_view, const Matrix44 *_model );


	//	データの取得	
	//---------------------------------------
	MatrixAry	GetMatrix() const { return matrix; }


	//	演算子のオーバーロード	
	//---------------------------------------
	Matrix44	operator +	(const Matrix44 &	) const;	//!< 行列＋行列
	Vector		operator *	(const Vector &		) const;	//!< 行列ｘベクトル
	Matrix44	operator *	(const Matrix44 &	) const;	//!< 行列ｘ行列
	void		operator *=	(const Matrix44 &	);			//!< 行列ｘ行列
	Matrix44&	operator =	(const Matrix44 &	);			//!< 代入

	//! アクセス
	f32	operator[]( std::size_t i ) const {
		return matrix.ary16[i];
	}

	//	表示
	//---------------------------------------
	void Disp();

private:
	MatrixAry		matrix;					// 4*4行列
};







//-----------------------------------------------
//	変換行列
//-----------------------------------------------
/* 平行移動 */
Matrix44	Translation( f32 x, f32 y, f32 z );
Matrix44	Translation( const Vector& xyz );

/* 拡大 */
Matrix44	Expansion( f32 x, f32 y, f32 z );

/* 均等に拡大 */
Matrix44	Expansion( f32 rate );

/* X軸回転 */
Matrix44	RotateX( f32 theta );

/* Y軸回転 */
Matrix44	RotateY( f32 theta );

/* Z軸回転 */
Matrix44	RotateZ( f32 theta );

/* 任意の軸で回転する変換行列を返す */
Matrix44	RotateAxis( f32 theta, const Vector *axis );
Matrix44	RotateAxis( f32 theta, const Vector& axis );

/* GLに行列をセット */
void		SetGL( const Matrix44*, const Matrix44* );

/* 射影行列を生成 */
Matrix44	CreatePerspectiveFieldOfView( f64 field_of_vision, f64 aspect_ratio, f64 near, f64 far );
Matrix44	CreatePerspectiveFieldOfView();


/* 射影空間からテクスチャ空間に変換した行列を生成 */
Matrix44	CreatePerspectiveToTextureSpace( f32 screenW, f32 screenH );

//! 行列を配列(16要素のf32配列)にコピー
void		CopyMatrix44ToArray( f32*, const Matrix44& );
void		CopyMatrix44ToArray( f64*, const Matrix44& );

}	// namespace math
}	// namespace nk

#endif
