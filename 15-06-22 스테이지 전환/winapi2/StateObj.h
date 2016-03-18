#pragma once
#include "Define.h"

class CStateObj
{
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;
public:
	CStateObj(void);
	virtual ~CStateObj(void);
};

