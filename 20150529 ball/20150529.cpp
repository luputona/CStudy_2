// 20150529.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MainGame.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMainGame MainGame;

	MainGame.Initialize();

	DWORD dwTime = GetTickCount();

	while(true)
	{
		if(dwTime +10 <GetTickCount())
		{
			dwTime = GetTickCount();

			MainGame.Progress();
			MainGame.Render();

		}
	}
	




	return 0;
}

