#pragma once
#include "Obj.h"
class CPlayer:public CObj
{
private:
	bool m_bJump;
	float m_fTime;
	float m_fOldY;
public:
	void Jump();
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	virtual ~CPlayer(void);
};

