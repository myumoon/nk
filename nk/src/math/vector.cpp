//=============================================================================
/*	file	vector.cpp
	brief	vector
	author	ryunosuke ide
	
	Copyright (c) 2014 Ryunosuke Ide
	Released under the MIT license
	http://opensource.org/licenses/mit-license.php
*/
//=============================================================================

#include <nk/math/vector.h>

#include <math.h>
#include <float.h>

#include <nk/math/vecutil.inl>


namespace {
}


namespace nk {
namespace math {



//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec2::Vec2()
{
	x	= 0.0f;
	y	= 0.0f;
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec2::Vec2( f32 x, f32 y )
{
	this->x	= x;
	this->y	= y;
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec2::Vec2( f32* ary2 )
{
	x	= ary2[0];
	y	= ary2[1];
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec2::Vec2( const Vec2& vec2 )
{
	VecCopy( *this, vec2 );
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec2::Vec2( const Vec3& vec3 )
{
	VecCopy( *this, vec3 );
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec2::Vec2( const Vec4& vec4 )
{
	VecCopy( *this, vec4 );
}














//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec3::Vec3()
{
	x	= 0.0f;
	y	= 0.0f;
	z	= 0.0f;
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec3::Vec3( f32 x, f32 y, f32 z )
{
	this->x	= x;
	this->y	= y;
	this->z	= z;
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec3::Vec3( f32* ary3 )
{
	x	= ary3[0];
	y	= ary3[1];
	z	= ary3[2];
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec3::Vec3( const Vec2& vec2 )
{
	VecCopy( *this, vec2 );
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec3::Vec3( const Vec3& vec3 )
{
	VecCopy( *this, vec3 );
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec3::Vec3( const Vec4& vec4 )
{
	VecCopy( *this, vec4 );
}


//===========================================================================
/*	brief	ベクトルの外積を計算
	param	vec1,vec2:ベクトル
	return	２ベクトルに垂直でノルムが|vec1||vec2|sinθのベクトル
	note	ノルムは計算しない
*/
//===========================================================================
Vec3 CrossProduct( const Vec3& vec1, const Vec3& vec2 )
{
	NKASSERT( !vec1.IsZero(), "vec1 is zero vector" );
	NKASSERT( !vec2.IsZero(), "vec2 is zero vector" );
	
	Vec3	vec1_cpy( vec1 );
	Vec3	vec2_cpy( vec2 );
	
	
	// 外積の計算
	// (y1*z2-z1y2, z1*x2-x1*z2, x1*y2-y1*x2)
	// ノルムは |v1||v2|sinθ
	// 向きは座標系により異なる
	Vec3	closs;
	closs.x	= vec1_cpy.y * vec2_cpy.z - vec1_cpy.z * vec2_cpy.y;
	closs.y	= vec1_cpy.z * vec2_cpy.x - vec1_cpy.x * vec2_cpy.z;
	closs.z	= vec1_cpy.x * vec2_cpy.y - vec1_cpy.y * vec2_cpy.x;

	return closs;
}


//===========================================================================
/*	brief	ベクトルのなす角を計算
	param	vec1,vec2:計算するベクトル
	return	なす角
*/
//===========================================================================
f32 CalcAngle( const Vec3& begin, const Vec2& end )
{
	NKASSERT( !begin.IsZero(),	"vec1 is zero vector" );
	NKASSERT( !end.IsZero(),		"vec2 is zero vector" );
	
	const Vec3 n_begin		= begin.GetNormalized();
	const Vec3 n_end		= end.GetNormalized();

	// cosθ = a・b / |a||b|
	//-----------------------------------------------
	const f32	angle = DotProduct( n_begin, n_end ) / 1.0f;

	return acos(angle);
}







//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec4::Vec4()
{
	x	= 0.0f;
	y	= 0.0f;
	z	= 0.0f;
	w	= 0.0f;
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec4::Vec4( f32 x, f32 y, f32 z, f32 w )
{
	this->x	= x;
	this->y	= y;
	this->z	= z;
	this->w	= w;
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec4::Vec4( f32* ary4 )
{
	x	= ary4[0];
	y	= ary4[1];
	z	= ary4[2];
	w	= ary4[3];
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec4::Vec4( const Vec2& vec2 )
{
	VecCopy( *this, vec2 );
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec4::Vec4( const Vec3& vec3 )
{
	VecCopy( *this, vec3 );
}


//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vec4::Vec4( const Vec4& vec4 )
{
	VecCopy( *this, vec4 );
}











#if 0

//===========================================================================
/*	brief	コンストラクタ
*/
//===========================================================================
Vector::Vector(f32 vx, f32 vy, f32 vz, f32 vw)
{
	x = vx;
	y = vy;
	z = vz;
	w = vw;
}

//===========================================================================
/*	brief	コンストラクタ
	param	vec:初期化するベクトル
*/
//===========================================================================
Vector::Vector(const Vector &vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}




//===========================================================================
/*	brief	デストラクタ
	param	
*/
//===========================================================================
Vector::~Vector()
{

}



//===========================================================================
/*	brief	0クリア
	param	なし
	return	なし
*/
//===========================================================================
void Vector::Clear()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;

}


//===========================================================================
/*	brief	値をセット
	param	vx,vy,vz:セットする値
	return	なし
*/
//===========================================================================
void Vector::SetVector(f32 vx, f32 vy, f32 vz, f32 vw)
{
	x = vx;
	y = vy;
	z = vz;
	w = vw;
}


//===========================================================================
/*	brief	ベクトルをセット
	param	v:セットするベクトル
	return	なし
*/
//===========================================================================
void Vector::SetVector(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}


//===========================================================================
/*	brief	正規化
	param	なし
	return	なし
*/
//===========================================================================
void Vector::Normalize()
{
	
	if( IsVectorZero() ) {
		return;
	}

	const f32	norm	= GetNorm();	// ベクトルの大きさを求める

	x /= norm;
	y /= norm;
	z /= norm;
	w = 0.0f;
}



//===========================================================================
/*	brief	したベクトルを取得
	param	なし
	return	なし
*/
//===========================================================================
Vector Vector::GetNormalizeVec( void ) const
{
	
	if( IsVectorZero() ) {
		return Vector();
	}

	Vector	calcVec	= *this;
	const f32	norm	= calcVec.GetNorm();

	calcVec.x /= norm;
	calcVec.y /= norm;
	calcVec.z /= norm;
	calcVec.w = 0.0f;

	return calcVec;
}


//===========================================================================
/*	brief	ノルムを取得
	param	なし
	return	ノルム
*/
//===========================================================================
f32 Vector::GetNorm() const
{

	return sqrt(x * x + y * y + z * z);
}


//===========================================================================
/*	brief	ノルムの2乗を取得
	param	なし
	return	ノルムの2乗
*/
//===========================================================================
f32 Vector::GetNorm2() const
{

	return x * x + y * y + z * z;
}



//===========================================================================
/*	brief	ベクトルの符号を逆にする
	param	なし
	return	なし
*/
//===========================================================================
void Vector::Inversion()
{
	x *= -1.0f;
	y *= -1.0f;
	z *= -1.0f;
	w *= -1.0f;
}


//===========================================================================
/*	brief	ゼロベクトルかどうかを判断
	param	
	return	
*/
//===========================================================================
bool Vector::IsVectorZero( void ) const
{
	const f32	errorRange	= 0.000000f;	// 誤差
	
	return	((-errorRange <= x) && (x <= errorRange)) &&
			((-errorRange <= y) && (y <= errorRange)) &&
			((-errorRange <= z) && (z <= errorRange)) &&
			((-errorRange <= w) && (w <= errorRange));
}

#if defined(NK_USE_EXP_OPERATOR)
//===========================================================================
/*	brief	+演算子のオーバーロード
	param	rhs		ベクトル
	return	演算
*/
//===========================================================================
Exp<Vector, OpPlus, Vector> Vector::operator+( const Vector& rhs ) const
{
	return Exp<Vector, OpPlus, Vector>( *this, rhs );
}


//===========================================================================
/*	brief	-演算子のオーバーロード
	param	rhs		ベクトル
	return	演算
*/
//===========================================================================
Exp<Vector, OpMinus, Vector> Vector::operator-( const Vector& rhs ) const
{
	return Exp<Vector, OpMinus, Vector>( *this, rhs );
}


//===========================================================================
/*	brief	*演算子のオーバーロード
	param	rhs		スカラー値
	return	演算
*/
//===========================================================================
Exp<Vector, OpMul, ExpScalar<f32> > Vector::operator*( f32 rhs ) const
{
	return Exp<Vector, OpMul, ExpScalar<f32> >( *this, ExpScalar<f32>(rhs) );
}
	
//===========================================================================
/*	brief	+演算子のオーバーロード
	param	vec:足すベクトル
	return	足した結果
*/
//===========================================================================
//Vector Vector::operator +(const Vector &vec) const
//{
//	return Vector(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
//}
#endif

#if !defined(NK_USE_EXP_OPERATOR)
	
//===========================================================================
/*	brief	+演算子のオーバーロード
	param	vec:足すベクトル
	return	足した結果
*/
//===========================================================================
Vector Vector::operator +(const Vector &vec) const
{
	return Vector(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}
#endif
	
//===========================================================================
/*	brief	+=演算子のオーバーロード
	param	vec:加えるベクトル
	return	足した結果
*/
//===========================================================================
Vector& Vector::operator +=(const Vector &vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;

	return (*this);
}



//===========================================================================
/*	brief	+=演算子のオーバーロード
	param	a:足す値
	return	足した結果
*/
//===========================================================================
Vector& Vector::operator +=(f32 a)
{
	x += a;
	y += a;
	z += a;
	w += a;

	return *this;
}



//===========================================================================
/*	brief	単項-演算子のオーバーロード
	param	なし
	return	結果
*/
//===========================================================================
Vector Vector::operator -() const
{
	return Vector(-x, -y, -z, -w);


}


#if !defined(NK_USE_EXP_OPERATOR)
//===========================================================================
/*	brief	-演算子のオーバーロード
	param	vec:引くベクトル
	return	引いた結果
*/
//===========================================================================
Vector Vector::operator -(const Vector &vec) const
{
	return ( Vector(x - vec.x, y - vec.y, z - vec.z, w - vec.w) );
}


//===========================================================================
/*	brief	*演算子のオーバーロード
	param	num:掛ける値
	return	掛けた結果
*/
//===========================================================================
Vector Vector::operator *(f32 num) const
{
	return Vector(x * num, y * num, z * num, w * num);
}
#endif



//===========================================================================
/*	brief	-=演算子のオーバーロード
	param	vec:引くベクトル
	return	引いた結果
*/
//===========================================================================
Vector& Vector::operator -=(const Vector &vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;

	return (*this);
}



//===========================================================================
/*	brief	-=演算子のオーバーロード
	param	a:引く値
	return	引いた結果
*/
//===========================================================================
Vector& Vector::operator -=(f32 a)
{
	x -= a;
	y -= a;
	z -= a;
	w -= a;

	return *this;
}



//===========================================================================
/*	brief	*=演算子のオーバーロード
	param	num:掛ける値
	return	掛けた結果
*/
//===========================================================================
Vector &Vector::operator *=(f32 num)
{
	x *= num;
	y *= num;
	z *= num;
	w *= num;

	return *this;
}


//===========================================================================
/*	brief	/演算子のオーバーロード
	param	scalar:割る値
	return	割った結果
*/
//===========================================================================
Vector Vector::operator /(f32 scalar) const
{

	return Vector(x / scalar, y / scalar, z / scalar, w / scalar);
}


//===========================================================================
/*	brief	/=演算子のオーバーロード
	param	scalar:割る値
	return	割った結果
*/
//===========================================================================
Vector &Vector::operator /=(f32 scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;

	return *this;
}


//===========================================================================
/*	brief	ベクトルの比較
	param	vec:比較するベクトル
	return	true:一致	false:不一致
	note	FLT_EPSILONの誤差は一致とする
*/
//===========================================================================
bool Vector::operator ==(const Vector &vec) const
{

	return (x - FLT_EPSILON < vec.x && vec.x < x + FLT_EPSILON) && (y - FLT_EPSILON < vec.y && vec.y < y + FLT_EPSILON) && (z - FLT_EPSILON < vec.z && vec.z < z + FLT_EPSILON);
}


//===========================================================================
/*	brief	ベクトルの比較
	param	vec:比較するベクトル
	return	true:一致	false:不一致
	note	FLT_EPSILONの誤差は許容範囲
*/
//===========================================================================
bool Vector::operator !=(const Vector &vec) const
{
	
	//return !((x - FLT_EPSILON < vec.x && vec.x < x + FLT_EPSILON) && (y - FLT_EPSILON < vec.y && vec.y < y + FLT_EPSILON) && (z - FLT_EPSILON < vec.z && vec.z < z + FLT_EPSILON));
	return (this->operator==( vec ) == false);
}


//===========================================================================
/*	brief	内積を計算
	param	vec1,vec2:ベクトル
	return	結果
*/
//===========================================================================
f32 CalcDotProduct(const Vector *vec1, const Vector *vec2)
{

	return vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
}


//===========================================================================
/*	brief	内積を計算
	param	vec1,vec2:ベクトル
	return	結果
*/
//===========================================================================
f32 CalcDotProduct(const Vector& vec1, const Vector& vec2)
{

	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}



//===========================================================================
/*	brief	ベクトルの外積を計算
	param	vec1,vec2:ベクトル
	return	２ベクトルに垂直でノルムが|vec1||vec2|sinθのベクトル
	\note	ノルムは計算しない
*/
//===========================================================================
Vector CalcCrossProduct(const Vector *vec1, const Vector *vec2)
{
	Vector vec1_cpy(*vec1);
	Vector vec2_cpy(*vec2);
	Vector closs_product;		// 外積


	/* 零ベクトルの場合 */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		closs_product.SetVector(0.0, 0.0, 0.0);
		return closs_product;
	}



	//			外積の計算
	//	(y1*z2-z1y2, z1*x2-x1*z2, x1*y2-y1*x2)
	//	ノルムは |v1||v2|sinθ
	//	向きは座標系により異なる
	closs_product.x = vec1_cpy.y * vec2_cpy.z - vec1_cpy.z * vec2_cpy.y;
	closs_product.y = vec1_cpy.z * vec2_cpy.x - vec1_cpy.x * vec2_cpy.z;
	closs_product.z = vec1_cpy.x * vec2_cpy.y - vec1_cpy.y * vec2_cpy.x;

	//closs_product.CalcNorm();


	return closs_product;
}




//===========================================================================
/*	brief	ベクトルの外積を計算
	param	vec1,vec2:ベクトル
	return	２ベクトルに垂直でノルムが|vec1||vec2|sinθのベクトル
	\note	ノルムは計算しない
*/
//===========================================================================
Vector CalcCrossProduct(const Vector& vec1, const Vector& vec2)
{
	Vector vec1_cpy(vec1);
	Vector vec2_cpy(vec2);
	Vector closs_product;		// 外積


	/* 零ベクトルの場合 */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		closs_product.SetVector(0.0, 0.0, 0.0);
		return closs_product;
	}



	//			外積の計算
	//	(y1*z2-z1y2, z1*x2-x1*z2, x1*y2-y1*x2)
	//	ノルムは |v1||v2|sinθ
	//	向きは座標系により異なる
	closs_product.x = vec1_cpy.y * vec2_cpy.z - vec1_cpy.z * vec2_cpy.y;
	closs_product.y = vec1_cpy.z * vec2_cpy.x - vec1_cpy.x * vec2_cpy.z;
	closs_product.z = vec1_cpy.x * vec2_cpy.y - vec1_cpy.y * vec2_cpy.x;

	//closs_product.CalcNorm();

	return closs_product;
}



//===========================================================================
/*	brief	なす角を計算
	param	vec1,vec2:計算を行うベクトル
	return	なす角
*/
//===========================================================================
f32 CalcVectorAngle(const Vector *vec1, const Vector *vec2)
{
	f32 angle;
	Vector vec1_cpy(*vec1);
	Vector vec2_cpy(*vec2);


	/* 零ベクトルの場合 */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		return 0.0f;
	}


	vec1_cpy.Normalize();
	vec2_cpy.Normalize();

	//	cosθ = a・b / |a||b|
	//-----------------------------------------------
	angle = CalcDotProduct(&vec1_cpy, &vec2_cpy) / (vec1_cpy.GetNorm() * vec2_cpy.GetNorm());


	return acos(angle);
}




//===========================================================================
/*	brief	ベクトルのなす角を計算
	param	vec1,vec2:計算するベクトル
	return	なす角
*/
//===========================================================================
f32 CalcVectorAngle(const Vector& vec1, const Vector& vec2)
{
	f32 angle;
	Vector vec1_cpy(vec1);
	Vector vec2_cpy(vec2);


	/* 零ベクトルの場合 */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		return 0.0f;
	}


	vec1_cpy.Normalize();
	vec2_cpy.Normalize();

	//	cosθ = a・b / |a||b|
	//-----------------------------------------------
	angle = CalcDotProduct(&vec1_cpy, &vec2_cpy) / 1.0f;

// 	if( 1.0f < angle ) {
// 		angle = 1.0f;
// 	}
// 	if( angle < -1.0f ) {
// 		angle = -1.0f;
// 	}

	return acos(angle);
}





//===========================================================================
/*	brief	ベクトルの符号が全部同じか
	param	vec1,vec2:比較するベクトル
	return	true:同じ	false:異なる
*/
//===========================================================================
bool IsSameDirection(const Vector& vec1, const Vector& vec2)
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
#endif

}	// namespace math
}	// namespace nk

