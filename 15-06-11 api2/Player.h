#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
private:
	RECT m_Rect;
	list<CObj*>* m_pBulletList;
public:
	void SetBullet(list<CObj*>* _pBullet){ m_pBulletList = _pBullet; }
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	~CPlayer(void);
};

