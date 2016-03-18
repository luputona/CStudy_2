#pragma once
#include "Obj.h"

class CBullet:public CObj
{
public:
	void SetPos(int _ix, int _iy);
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CBullet(void);
	~CBullet(void);
};

