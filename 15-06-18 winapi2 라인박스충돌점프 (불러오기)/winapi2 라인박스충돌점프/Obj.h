#pragma once
#include "Define.h"

class CObj
{
protected:
	INFO m_tInfo;	
	static POINTFLOAT m_tScroll;
public:
	static POINTFLOAT GetScroll(){ return m_tScroll;}
public:
	INFO GetInfo()const {return m_tInfo; }
	void SetPos(float _x, float _y){ m_tInfo.fX  = _x ; m_tInfo.fY = _y; }
	RECT GetRect();
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;
public:
	CObj(void);
	virtual ~CObj(void);
};

