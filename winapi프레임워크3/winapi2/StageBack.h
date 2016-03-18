#pragma once
#include "Obj.h"
class CStageBack:public CObj
{
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CStageBack(void);
	~CStageBack(void);
};

