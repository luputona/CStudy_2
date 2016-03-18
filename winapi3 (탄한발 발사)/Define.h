#pragma once

const int WINCX = 800;
const int WINCY = 600;

//외부파일까지도 연결되서 데이타가 공유
extern HWND g_hWnd;

typedef struct tagInfo
{
	int		iX;
	int		iY;
	int		iCX;
	int		iCY;
}INFO;
