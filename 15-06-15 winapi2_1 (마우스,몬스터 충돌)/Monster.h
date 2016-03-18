#pragma once
#include "Obj.h"
class CMonster : public CObj
{
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CMonster(void);
	virtual ~CMonster(void);
};

