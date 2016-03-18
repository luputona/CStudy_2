#pragma once
#include "Define.h"

class CObj
{
protected:
	INFO m_tInfo;
	list<CObj*> m_ObjList[OBJ_END];

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;


public:
	CObj(void);
	~CObj(void);
};

