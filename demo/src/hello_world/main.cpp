
#include <stdio.h>

// #include <windows.h>
// #include <GL/glfw.h>
// #include <GL/glut.h>
#include <nk/system/system.h>
#include <nk/macros.h>

int main( int argc, char* argv[] )
{
	(void)argc;
	(void)argv;
	nk::system::InitParam	param( 1024, 768, 32, 0, 60, false, "nk demo" );
	nk::system::System	system( param );
	
	system.Initialize();
	system.Run();
	system.Terminate();

// 	int running = GL_TRUE;
// 
// 	//ウィンドウタイトルの設定
// 	glEnable(GL_DEPTH_TEST);
// 	while(running)
// 	{
// 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 		//描画
// 		glBegin(GL_POLYGON);
// 		glColor3d(1.0, 0.0, 0.0);
// 		glVertex2d(-0.9, -0.9);
// 		glColor3d(0.0, 1.0, 0.0);
// 		glVertex2d(0.9, -0.9);
// 		glColor3d(0.0, 0.0, 1.0);
// 		glVertex2d(0.9, 0.9);
// 		glColor3d(1.0, 1.0, 0.0);
// 		glVertex2d(-0.9, 0.9);
// 		glEnd();
// 		//ダブルバッファリングのバッファの交換
// 		glfwSwapBuffers();
// 		//ESCキーかXボタンで終了
// 		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
// 	}

	

	

	getchar();

	return 0;
}
