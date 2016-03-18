#pragma once
#include "Define.h"


class CObj
{
protected:
	INFO m_tInfo;
public:
	INFO GetInfo(void) const { return m_tInfo; }
public:
	void SetPos(float _fx, float _fy);
public:
	virtual void Initalize()=0;
	virtual void Progress()=0;
	virtual void Render(HDC hdc)=0;
	virtual void Release()=0;		
public:
	CObj(void);
	virtual ~CObj(void);
};

