#pragma once

const int WINCX = 800;
const int WINCY = 600;

//외부파일까지도 연결되서 데이타가 공유
extern HWND g_hWnd;

template <typename T>
inline void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = NULL;
	}
}

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
}INFO;