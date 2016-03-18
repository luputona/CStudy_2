// 15-06-09 text rpg test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainGame.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMainGame cMainGame;

	cMainGame.Initalize();
	cMainGame.Progress();


	return 0;
}

