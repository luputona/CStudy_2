#pragma once

typedef struct tagInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;

	tagInfo(){};
	tagInfo(float _fx, float _fy)
		:fX(_fx),fY(_fy)
	{

	}
	tagInfo(float _fx, float _fy,float _fcx, float _fcy)
		:fX(_fx),fY(_fy),fCX(_fcx),fCY(_fcy)
	{

	}
}INFO;

typedef struct tagFrame
{
	int iStart;
	int iLast;
	int iScene;
	DWORD dwTime;

	tagFrame(void){}
	tagFrame(int _istart, int _ilast, int _iscene,DWORD _dwtime)
		:iStart(_istart),iLast(_ilast),iScene(_iscene),dwTime(_dwtime){};
}FRAME;

