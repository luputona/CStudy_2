#pragma once

const int WINCX = 800;
const int WINCY = 600;

//외부 파일까지도 연결되서 데이터를 공유
extern HWND g_hWnd; //메인으로 넘어감

typedef struct tagInfo
{
	int  nX;
	int  nY;
	int  nCX;
	int  nCY;
}INFO;
