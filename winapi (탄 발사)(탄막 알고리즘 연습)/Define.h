#pragma once

const int WINCX = 800;
const int WINCY = 600;
const int PI = 3.141592;
//외부파일까지도 연결되서 데이타가 공유
extern HWND g_hWnd;

#define PURE = 0
#define SAFE_DELETE(p) if(p) { delete p; p =NULL; }

template<typename T>
static inline void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = NULL;
	}
}

struct ObjDelete
{
	template<typename T>
	inline void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = NULL;
		}
	}
};

enum DIRECTION
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_LU,
	DIR_RU
};

typedef struct tagInfo
{
	float fX;
	float fY;
	float nCX;
	float nCY;

	tagInfo(){}
	tagInfo(int _fX,int _fY) : fX(_fX), fY(_fY){}
	tagInfo(int _fX,int _fY,int _nCX,int _nCY) :
	fX(_fX), fY(_fY), nCX(_nCX),nCY(_nCY)
	{

	}
}INFO;

class CObj;
typedef list<CObj*> OBJLIST;
typedef OBJLIST::iterator OBJITER;