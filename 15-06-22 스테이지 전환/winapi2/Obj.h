#pragma once
#include "Define.h"

class CObj
{
protected:
	INFO m_tInfo;
	list<CObj*> m_ObjList[OBJ_END];
public:
	INFO GetInfo()const { return m_tInfo;}
	void SetPos(float _x, float _y){m_tInfo.fX = _x; m_tInfo.fY = _y;}

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;


public:
	CObj(void);
	~CObj(void);
};

