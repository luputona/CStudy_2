#pragma once
#include "Define.h"


class CObj
{
protected:
	INFO m_tInfo;
	int  m_nSpeed;
public:
	INFO GetInfo(void) { return m_tInfo; }

public:
	virtual void Initalize() = 0;
	virtual void Progress() = 0;
	virtual void Render(HDC hdc)  = 0;
	virtual void Release() = 0;
	
public:
	CObj(void);
	virtual ~CObj(void);
};

