#pragma once
#include "Obj.h"

class CBullet : public CObj
{
public:
	void SetPos(int _nX,int _nY);
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CBullet(void);
	~CBullet(void);
};

