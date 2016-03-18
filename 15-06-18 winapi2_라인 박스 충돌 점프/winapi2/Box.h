#pragma once
#include "Obj.h"

class CBox : public CObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CBox(void);
	virtual ~CBox(void);
};

