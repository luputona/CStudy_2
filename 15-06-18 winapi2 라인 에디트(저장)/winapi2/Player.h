#pragma once
#include "Obj.h"
class CPlayer:public CObj
{
private:
	void CheckKey();
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	virtual ~CPlayer(void);
};

