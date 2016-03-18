#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
private:
	list<CObj*>* m_pBulletList;	
	float m_fAngle;
	float m_fDistance;
public:
	void SetBullet(list<CObj*>* _pBullet) { m_pBulletList = _pBullet; }

private:
	void CheckKey();
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();


public:
	CPlayer(void);
	~CPlayer(void);
};

