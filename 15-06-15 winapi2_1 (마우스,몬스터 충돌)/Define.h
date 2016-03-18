#pragma once

const int WINCX = 800;
const int WINCY = 600;

//�ܺ����ϱ����� ����Ǽ� ����Ÿ�� ����
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