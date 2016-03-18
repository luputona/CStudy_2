#pragma once

const int WINCX = 800;
const int WINCY = 600;

#define PURE = 0

//외부파일까지도 연결되서 데이타가 공유
extern HWND g_hWnd;


typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;

	tagInfo(){}
	tagInfo(float _fx, float _fy, float _fcx, float _fcy) :
	fX(_fx), fY(_fy), fCX(_fcx), fCY(_fcy)
	{

	}	
}INFO;

const int TILEX = 30;
const int TILEY = 20;

const int TILECX = 64;
const int TILECY = 64;

typedef struct tagTile
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;
	int		nOption;
	int		nDrawID;
}TILE;







template <typename T>
static inline void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = NULL;
	}
};


enum OBJ
{
	OBJ_END
};