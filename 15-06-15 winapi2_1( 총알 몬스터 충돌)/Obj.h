#pragma once
#include "Define.h"
class CObj
{
protected:
	INFO m_tInfo;
	int  m_iSpeed;
public:
	INFO GetInfo(){ return m_tInfo;}
public:
	void SetPos(float _fx, float _fy);
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;

public:
	CObj(void);
	virtual ~CObj(void);
};

