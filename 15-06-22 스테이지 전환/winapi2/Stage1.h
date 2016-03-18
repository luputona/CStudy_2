#pragma once
#include "StateObj.h"
class CStage1 : public CStateObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CStage1(void);
	virtual ~CStage1(void);
};

