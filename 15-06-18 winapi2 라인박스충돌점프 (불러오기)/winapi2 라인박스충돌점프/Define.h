#pragma once

#define PURE =0

const int WINCX = 800;
const int WINCY = 600;

//외부파일까지도 연결되서 데이타가 공유
extern HWND g_hWnd;

const float PI = 3.141592f;

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;

	tagInfo(){}
	tagInfo(float _fx, float _fy, float _fcx,float _fcy)
		:fX(_fx),fY(_fy),fCX(_fcx),fCY(_fcy)
	{

	}

}INFO;

typedef struct tagLine
{
	POINTFLOAT tLPoint;
	POINTFLOAT tRPoint;

	tagLine(){}
	tagLine(POINTFLOAT _lpoint, POINTFLOAT _rpoint) :
	tLPoint(_lpoint), tRPoint(_rpoint)
	{

	}
}LINE;




template <typename T>
static inline void Safe_Delete(T& temp)
{
	if(temp)
	{
		delete temp;
		temp = NULL;
	}

};

enum OBJ
{
	OBJ_PLAYER,
	OBJ_MONSTER,
	OBJ_END
};

