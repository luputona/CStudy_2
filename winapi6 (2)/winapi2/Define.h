#pragma once

const int WINCX = 800;
const int WINCY = 600;

//외부파일까지도 연결되서 데이타가 공유
extern HWND g_hWnd;

const float	PI = 3.141592f;

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
}INFO;

template <typename T>
static inline void Safe_Delete(T& temp)
{
	if(temp)
	{
		delete temp;
		temp = NULL;
	}
}
