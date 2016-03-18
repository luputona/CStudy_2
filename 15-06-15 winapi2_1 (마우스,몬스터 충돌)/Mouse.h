#pragma once
#include "Obj.h"

class CMouse : public CObj
{
private:
	POINT m_ptMouse;
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CMouse(void);
	virtual ~CMouse(void);
};

