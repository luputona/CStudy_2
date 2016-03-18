#pragma once
#include "Include.h"
class CStateObj
{
protected:
	map<string,CBitMap*>  m_MapBmp;
public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release();
public:
	CStateObj(void);
	virtual ~CStateObj(void);
};

