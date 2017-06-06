
#include <stdio.h>
#include <nk/system/system.h>

// test
#include <nk/macros.h>
#include <nk/math/vector.h>
#include <nk/math/matrix.h>

// リリース時にコンソールウインドウを消します
#if defined(_RELEASE)
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

int main( int argc, char* argv[] )
{
	(void)argc;
	(void)argv;

	nk::math::Matrix44	trans	= nk::math::Matrix44::Translation( nk::math::Vec3( 10.0f, 0.0f, 0.0f ) );
	nk::math::Matrix44	scale	= nk::math::Matrix44::Scale( nk::math::Vec3( 10.0f, 20.0f, 30.0f ) );
	nk::math::Matrix44	roty	= nk::math::Matrix44::RotateY( nk::math::Rad( 90.0f ) );

	nk::math::Matrix44	trans2	= nk::math::Matrix44::Translation( nk::math::Vec3( 10.0f, 20.0f, 30.0f ) );

	nk::math::Matrix44	trans12	= trans * trans2;
	
	nk::math::Matrix44	rotra	= roty * trans;
	nk::math::Matrix44	traro	= trans * roty;

	nk::math::Vec3	pos3( 1.0f, 0.0f, 0.0f );
	nk::math::Vec3	pos31	= pos3 * roty * trans;
	nk::math::Vec3	pos32	= pos3 * trans * roty;

	nk::math::Vec4	pos( 1.0f, 0.0f, 0.0f, 2.0f );
	nk::math::Vec4	pos1	= pos * roty * trans;
	nk::math::Vec4	pos2	= pos * trans * roty;
	
	NKPRINTF("%s\n", pos2.ToStr().c_str());
	NKPRINTF("rotra\n");
	rotra.Disp();

	NKPRINTF("traro\n");
	traro.Disp();

	
	nk::math::Vec3	v3_1( 1.0f, 0.0f, 0.0f );
	nk::math::Vec3	v3_2( 1.0f, 0.0f, 0.0f );

	nk::math::Vec3	cross	= nk::math::CrossProduct( nk::math::Vec3::AxisZ(), nk::math::Vec3::AxisY() );

	NKPRINTF("dot = %f\n", nk::math::DotProduct(v3_1, v3_2));
	


	nk::system::InitParam	param( 1024, 768, 32, 0, 60, false, "nk demo" );
	nk::system::System	system( param );
	
	system.Initialize();
	system.Run();
	system.Terminate();
	
	getchar();

	return 0;
}
