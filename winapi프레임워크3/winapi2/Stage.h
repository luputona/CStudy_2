#pragma once
#include "StateObj.h"
class CObj;
class CStage:public CStateObj
{
private:
	CObj*  m_pBackGround;
	list<CObj*>	m_ObjList[OBJ_END];
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CStage(void);
	virtual ~CStage(void);
};

