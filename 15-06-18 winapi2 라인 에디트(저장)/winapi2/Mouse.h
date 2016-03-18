#pragma once
#include "Obj.h"
#include "Define.h"
class CMouse : public CObj
{
public:
	static POINTFLOAT GetPos()
	{
		POINT tPoint;
		GetCursorPos(&tPoint);
		ScreenToClient(g_hWnd,&tPoint);

		POINTFLOAT tfPoint= {(float)tPoint.x,(float)tPoint.y};

		return tfPoint;
	}

public:
	CMouse(void);
	~CMouse(void);
};

