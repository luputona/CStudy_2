#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
private:
	OBJLIST* m_pBulletList;
public:
	void SetBullet(OBJLIST* _pBullet) { m_pBulletList = _pBullet; }
private:
	void Checkkey();
	CObj* CreateBullet(DIRECTION _edir);
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	CPlayer(void);
	~CPlayer(void);
};

