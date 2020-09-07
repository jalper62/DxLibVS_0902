#include "DxLib.h"

#define GAME_WIDTH			800	
#define GAME_HEIGHT			600	
#define GAME_COLOR			32	

#define GAME_WINDOW_BAR		0	
#define GAME_WINDOW_NAME	"GAME TITLE"



#define MOVIE_PATH			".\\MOVIE\\Fireworks.mp4"	

int handle = -1;	


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);				
	ChangeWindowMode(TRUE);								
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	
	SetWindowStyleMode(GAME_WINDOW_BAR);				
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			
	SetAlwaysRunFlag(TRUE);								

	if (DxLib_Init() == -1) { return -1; }	//�c�w���C�u��������������


	handle = LoadGraph(MOVIE_PATH);


	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	
		if (ClearDrawScreen() != 0) { break; }	


		if (GetMovieStateToGraph(handle) == 0)
		{
			SeekMovieToGraph(handle, 0);	
			PlayMovieToGraph(handle);		
		}

		DrawGraph(0, 0, handle, FALSE);



		DrawString(0, 0, "������Đ����Ă��܂��E�E�E", GetColor(255, 255, 255));

		ScreenFlip();		
	}

	DxLib_End();	


	DeleteGraph(handle);	


	return 0;
}