#pragma once
#include "Define.h"
class CObj
{
protected:
	INFO m_tInfo;
	int m_nSpeed;

public:
	INFO GetInfo() { return m_tInfo; }
public:
	void SetPos(int _nX,int _nY);
public:
	virtual void Initalize()PURE;
	virtual void Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;

public:
	CObj(void);
	virtual ~CObj(void);
};

