#include <stdio.h>
#include <windows.h>
#include <nk/macros.h>

#ifdef _NK_DISP_CONSOLE
int main( int argc, char* argv[] )
#else
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
#endif
{
	(void)hInstance;
	(void)hPrevInstance;
	(void)lpCmdLine;
	(void)nCmdShow;
	
	getchar();

	return 0;
}