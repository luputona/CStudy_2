#pragma once
#include "Obj.h"

class CPlayer:public CObj
{
private:
	RECT m_Rect;
	list<CObj*>*	m_pBulletList;
public:
	void SetBullet(list<CObj*>* _pbullet){ m_pBulletList = _pbullet; }

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CPlayer(void);
	~CPlayer(void);
};

