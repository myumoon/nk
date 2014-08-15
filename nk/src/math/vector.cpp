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
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec2::Vec2()
{
	x	= 0.0f;
	y	= 0.0f;
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec2::Vec2( f32 x, f32 y )
{
	this->x	= x;
	this->y	= y;
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec2::Vec2( f32* ary2 )
{
	x	= ary2[0];
	y	= ary2[1];
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec2::Vec2( const Vec2& vec2 )
{
	VecCopy( *this, vec2 );
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec2::Vec2( const Vec3& vec3 )
{
	VecCopy( *this, vec3 );
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec2::Vec2( const Vec4& vec4 )
{
	VecCopy( *this, vec4 );
}














//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec3::Vec3()
{
	x	= 0.0f;
	y	= 0.0f;
	z	= 0.0f;
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec3::Vec3( f32 x, f32 y, f32 z )
{
	this->x	= x;
	this->y	= y;
	this->z	= z;
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec3::Vec3( f32* ary3 )
{
	x	= ary3[0];
	y	= ary3[1];
	z	= ary3[2];
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec3::Vec3( const Vec2& vec2 )
{
	VecCopy( *this, vec2 );
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec3::Vec3( const Vec3& vec3 )
{
	VecCopy( *this, vec3 );
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec3::Vec3( const Vec4& vec4 )
{
	VecCopy( *this, vec4 );
}


//===========================================================================
/*	brief	�x�N�g���̊O�ς��v�Z
	param	vec1,vec2:�x�N�g��
	return	�Q�x�N�g���ɐ����Ńm������|vec1||vec2|sin�Ƃ̃x�N�g��
	note	�m�����͌v�Z���Ȃ�
*/
//===========================================================================
Vec3 CrossProduct( const Vec3& vec1, const Vec3& vec2 )
{
	NKASSERT( !vec1.IsZero(), "vec1 is zero vector" );
	NKASSERT( !vec2.IsZero(), "vec2 is zero vector" );
	
	Vec3	vec1_cpy( vec1 );
	Vec3	vec2_cpy( vec2 );
	
	
	// �O�ς̌v�Z
	// (y1*z2-z1y2, z1*x2-x1*z2, x1*y2-y1*x2)
	// �m������ |v1||v2|sin��
	// �����͍��W�n�ɂ��قȂ�
	Vec3	closs;
	closs.x	= vec1_cpy.y * vec2_cpy.z - vec1_cpy.z * vec2_cpy.y;
	closs.y	= vec1_cpy.z * vec2_cpy.x - vec1_cpy.x * vec2_cpy.z;
	closs.z	= vec1_cpy.x * vec2_cpy.y - vec1_cpy.y * vec2_cpy.x;

	return closs;
}


//===========================================================================
/*	brief	�x�N�g���̂Ȃ��p���v�Z
	param	vec1,vec2:�v�Z����x�N�g��
	return	�Ȃ��p
*/
//===========================================================================
f32 CalcAngle( const Vec3& begin, const Vec2& end )
{
	NKASSERT( !begin.IsZero(),	"vec1 is zero vector" );
	NKASSERT( !end.IsZero(),		"vec2 is zero vector" );
	
	const Vec3 n_begin		= begin.GetNormalized();
	const Vec3 n_end		= end.GetNormalized();

	// cos�� = a�Eb / |a||b|
	//-----------------------------------------------
	const f32	angle = DotProduct( n_begin, n_end ) / 1.0f;

	return acos(angle);
}







//===========================================================================
/*	brief	�R���X�g���N�^
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
/*	brief	�R���X�g���N�^
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
/*	brief	�R���X�g���N�^
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
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec4::Vec4( const Vec2& vec2 )
{
	VecCopy( *this, vec2 );
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec4::Vec4( const Vec3& vec3 )
{
	VecCopy( *this, vec3 );
}


//===========================================================================
/*	brief	�R���X�g���N�^
*/
//===========================================================================
Vec4::Vec4( const Vec4& vec4 )
{
	VecCopy( *this, vec4 );
}











#if 0

//===========================================================================
/*	brief	�R���X�g���N�^
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
/*	brief	�R���X�g���N�^
	param	vec:����������x�N�g��
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
/*	brief	�f�X�g���N�^
	param	
*/
//===========================================================================
Vector::~Vector()
{

}



//===========================================================================
/*	brief	0�N���A
	param	�Ȃ�
	return	�Ȃ�
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
/*	brief	�l���Z�b�g
	param	vx,vy,vz:�Z�b�g����l
	return	�Ȃ�
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
/*	brief	�x�N�g�����Z�b�g
	param	v:�Z�b�g����x�N�g��
	return	�Ȃ�
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
/*	brief	���K��
	param	�Ȃ�
	return	�Ȃ�
*/
//===========================================================================
void Vector::Normalize()
{
	
	if( IsVectorZero() ) {
		return;
	}

	const f32	norm	= GetNorm();	// �x�N�g���̑傫�������߂�

	x /= norm;
	y /= norm;
	z /= norm;
	w = 0.0f;
}



//===========================================================================
/*	brief	�����x�N�g�����擾
	param	�Ȃ�
	return	�Ȃ�
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
/*	brief	�m�������擾
	param	�Ȃ�
	return	�m����
*/
//===========================================================================
f32 Vector::GetNorm() const
{

	return sqrt(x * x + y * y + z * z);
}


//===========================================================================
/*	brief	�m������2����擾
	param	�Ȃ�
	return	�m������2��
*/
//===========================================================================
f32 Vector::GetNorm2() const
{

	return x * x + y * y + z * z;
}



//===========================================================================
/*	brief	�x�N�g���̕������t�ɂ���
	param	�Ȃ�
	return	�Ȃ�
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
/*	brief	�[���x�N�g�����ǂ����𔻒f
	param	
	return	
*/
//===========================================================================
bool Vector::IsVectorZero( void ) const
{
	const f32	errorRange	= 0.000000f;	// �덷
	
	return	((-errorRange <= x) && (x <= errorRange)) &&
			((-errorRange <= y) && (y <= errorRange)) &&
			((-errorRange <= z) && (z <= errorRange)) &&
			((-errorRange <= w) && (w <= errorRange));
}

#if defined(NK_USE_EXP_OPERATOR)
//===========================================================================
/*	brief	+���Z�q�̃I�[�o�[���[�h
	param	rhs		�x�N�g��
	return	���Z
*/
//===========================================================================
Exp<Vector, OpPlus, Vector> Vector::operator+( const Vector& rhs ) const
{
	return Exp<Vector, OpPlus, Vector>( *this, rhs );
}


//===========================================================================
/*	brief	-���Z�q�̃I�[�o�[���[�h
	param	rhs		�x�N�g��
	return	���Z
*/
//===========================================================================
Exp<Vector, OpMinus, Vector> Vector::operator-( const Vector& rhs ) const
{
	return Exp<Vector, OpMinus, Vector>( *this, rhs );
}


//===========================================================================
/*	brief	*���Z�q�̃I�[�o�[���[�h
	param	rhs		�X�J���[�l
	return	���Z
*/
//===========================================================================
Exp<Vector, OpMul, ExpScalar<f32> > Vector::operator*( f32 rhs ) const
{
	return Exp<Vector, OpMul, ExpScalar<f32> >( *this, ExpScalar<f32>(rhs) );
}
	
//===========================================================================
/*	brief	+���Z�q�̃I�[�o�[���[�h
	param	vec:�����x�N�g��
	return	����������
*/
//===========================================================================
//Vector Vector::operator +(const Vector &vec) const
//{
//	return Vector(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
//}
#endif

#if !defined(NK_USE_EXP_OPERATOR)
	
//===========================================================================
/*	brief	+���Z�q�̃I�[�o�[���[�h
	param	vec:�����x�N�g��
	return	����������
*/
//===========================================================================
Vector Vector::operator +(const Vector &vec) const
{
	return Vector(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}
#endif
	
//===========================================================================
/*	brief	+=���Z�q�̃I�[�o�[���[�h
	param	vec:������x�N�g��
	return	����������
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
/*	brief	+=���Z�q�̃I�[�o�[���[�h
	param	a:�����l
	return	����������
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
/*	brief	�P��-���Z�q�̃I�[�o�[���[�h
	param	�Ȃ�
	return	����
*/
//===========================================================================
Vector Vector::operator -() const
{
	return Vector(-x, -y, -z, -w);


}


#if !defined(NK_USE_EXP_OPERATOR)
//===========================================================================
/*	brief	-���Z�q�̃I�[�o�[���[�h
	param	vec:�����x�N�g��
	return	����������
*/
//===========================================================================
Vector Vector::operator -(const Vector &vec) const
{
	return ( Vector(x - vec.x, y - vec.y, z - vec.z, w - vec.w) );
}


//===========================================================================
/*	brief	*���Z�q�̃I�[�o�[���[�h
	param	num:�|����l
	return	�|��������
*/
//===========================================================================
Vector Vector::operator *(f32 num) const
{
	return Vector(x * num, y * num, z * num, w * num);
}
#endif



//===========================================================================
/*	brief	-=���Z�q�̃I�[�o�[���[�h
	param	vec:�����x�N�g��
	return	����������
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
/*	brief	-=���Z�q�̃I�[�o�[���[�h
	param	a:�����l
	return	����������
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
/*	brief	*=���Z�q�̃I�[�o�[���[�h
	param	num:�|����l
	return	�|��������
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
/*	brief	/���Z�q�̃I�[�o�[���[�h
	param	scalar:����l
	return	����������
*/
//===========================================================================
Vector Vector::operator /(f32 scalar) const
{

	return Vector(x / scalar, y / scalar, z / scalar, w / scalar);
}


//===========================================================================
/*	brief	/=���Z�q�̃I�[�o�[���[�h
	param	scalar:����l
	return	����������
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
/*	brief	�x�N�g���̔�r
	param	vec:��r����x�N�g��
	return	true:��v	false:�s��v
	note	FLT_EPSILON�̌덷�͈�v�Ƃ���
*/
//===========================================================================
bool Vector::operator ==(const Vector &vec) const
{

	return (x - FLT_EPSILON < vec.x && vec.x < x + FLT_EPSILON) && (y - FLT_EPSILON < vec.y && vec.y < y + FLT_EPSILON) && (z - FLT_EPSILON < vec.z && vec.z < z + FLT_EPSILON);
}


//===========================================================================
/*	brief	�x�N�g���̔�r
	param	vec:��r����x�N�g��
	return	true:��v	false:�s��v
	note	FLT_EPSILON�̌덷�͋��e�͈�
*/
//===========================================================================
bool Vector::operator !=(const Vector &vec) const
{
	
	//return !((x - FLT_EPSILON < vec.x && vec.x < x + FLT_EPSILON) && (y - FLT_EPSILON < vec.y && vec.y < y + FLT_EPSILON) && (z - FLT_EPSILON < vec.z && vec.z < z + FLT_EPSILON));
	return (this->operator==( vec ) == false);
}


//===========================================================================
/*	brief	���ς��v�Z
	param	vec1,vec2:�x�N�g��
	return	����
*/
//===========================================================================
f32 CalcDotProduct(const Vector *vec1, const Vector *vec2)
{

	return vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
}


//===========================================================================
/*	brief	���ς��v�Z
	param	vec1,vec2:�x�N�g��
	return	����
*/
//===========================================================================
f32 CalcDotProduct(const Vector& vec1, const Vector& vec2)
{

	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}



//===========================================================================
/*	brief	�x�N�g���̊O�ς��v�Z
	param	vec1,vec2:�x�N�g��
	return	�Q�x�N�g���ɐ����Ńm������|vec1||vec2|sin�Ƃ̃x�N�g��
	\note	�m�����͌v�Z���Ȃ�
*/
//===========================================================================
Vector CalcCrossProduct(const Vector *vec1, const Vector *vec2)
{
	Vector vec1_cpy(*vec1);
	Vector vec2_cpy(*vec2);
	Vector closs_product;		// �O��


	/* ��x�N�g���̏ꍇ */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		closs_product.SetVector(0.0, 0.0, 0.0);
		return closs_product;
	}



	//			�O�ς̌v�Z
	//	(y1*z2-z1y2, z1*x2-x1*z2, x1*y2-y1*x2)
	//	�m������ |v1||v2|sin��
	//	�����͍��W�n�ɂ��قȂ�
	closs_product.x = vec1_cpy.y * vec2_cpy.z - vec1_cpy.z * vec2_cpy.y;
	closs_product.y = vec1_cpy.z * vec2_cpy.x - vec1_cpy.x * vec2_cpy.z;
	closs_product.z = vec1_cpy.x * vec2_cpy.y - vec1_cpy.y * vec2_cpy.x;

	//closs_product.CalcNorm();


	return closs_product;
}




//===========================================================================
/*	brief	�x�N�g���̊O�ς��v�Z
	param	vec1,vec2:�x�N�g��
	return	�Q�x�N�g���ɐ����Ńm������|vec1||vec2|sin�Ƃ̃x�N�g��
	\note	�m�����͌v�Z���Ȃ�
*/
//===========================================================================
Vector CalcCrossProduct(const Vector& vec1, const Vector& vec2)
{
	Vector vec1_cpy(vec1);
	Vector vec2_cpy(vec2);
	Vector closs_product;		// �O��


	/* ��x�N�g���̏ꍇ */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		closs_product.SetVector(0.0, 0.0, 0.0);
		return closs_product;
	}



	//			�O�ς̌v�Z
	//	(y1*z2-z1y2, z1*x2-x1*z2, x1*y2-y1*x2)
	//	�m������ |v1||v2|sin��
	//	�����͍��W�n�ɂ��قȂ�
	closs_product.x = vec1_cpy.y * vec2_cpy.z - vec1_cpy.z * vec2_cpy.y;
	closs_product.y = vec1_cpy.z * vec2_cpy.x - vec1_cpy.x * vec2_cpy.z;
	closs_product.z = vec1_cpy.x * vec2_cpy.y - vec1_cpy.y * vec2_cpy.x;

	//closs_product.CalcNorm();

	return closs_product;
}



//===========================================================================
/*	brief	�Ȃ��p���v�Z
	param	vec1,vec2:�v�Z���s���x�N�g��
	return	�Ȃ��p
*/
//===========================================================================
f32 CalcVectorAngle(const Vector *vec1, const Vector *vec2)
{
	f32 angle;
	Vector vec1_cpy(*vec1);
	Vector vec2_cpy(*vec2);


	/* ��x�N�g���̏ꍇ */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		return 0.0f;
	}


	vec1_cpy.Normalize();
	vec2_cpy.Normalize();

	//	cos�� = a�Eb / |a||b|
	//-----------------------------------------------
	angle = CalcDotProduct(&vec1_cpy, &vec2_cpy) / (vec1_cpy.GetNorm() * vec2_cpy.GetNorm());


	return acos(angle);
}




//===========================================================================
/*	brief	�x�N�g���̂Ȃ��p���v�Z
	param	vec1,vec2:�v�Z����x�N�g��
	return	�Ȃ��p
*/
//===========================================================================
f32 CalcVectorAngle(const Vector& vec1, const Vector& vec2)
{
	f32 angle;
	Vector vec1_cpy(vec1);
	Vector vec2_cpy(vec2);


	/* ��x�N�g���̏ꍇ */
	if(vec1_cpy.IsVectorZero() || vec2_cpy.IsVectorZero()) {
		return 0.0f;
	}


	vec1_cpy.Normalize();
	vec2_cpy.Normalize();

	//	cos�� = a�Eb / |a||b|
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
/*	brief	�x�N�g���̕������S��������
	param	vec1,vec2:��r����x�N�g��
	return	true:����	false:�قȂ�
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

