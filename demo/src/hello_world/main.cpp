#include <stdio.h>
#include <windows.h>

#include <nk/system/system.h>
#include <nk/macros.h>

int main( int argc, char* argv[] )
{
	nk::system::InitParam	param( argc, argv, 1024, 768, 60, false, "nk demo" );
	nk::system::System	system( param );

	system.Initialize();
	system.Run();
	system.Terminate();

	getchar();

	return 0;
}
