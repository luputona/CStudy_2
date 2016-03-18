#pragma once
#include "Obj.h"
class CPlayer:public CObj
{
private:
	list<CObj*>*   m_pBulletList;
	float m_fAngle;
	float m_fDistance;
public:
	void SetBullet(list<CObj*>* _pbullet){ m_pBulletList = _pbullet; }
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

