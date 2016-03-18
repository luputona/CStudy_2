#pragma once
#include "StateObj.h"

class CStage2 : public CStateObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CStage2(void);
	virtual ~CStage2(void);
};

