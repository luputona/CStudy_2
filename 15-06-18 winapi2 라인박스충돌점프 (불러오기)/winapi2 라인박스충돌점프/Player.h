#pragma once
#include "Obj.h"
class CPlayer:public CObj
{
private:
	bool m_bJump;
	float m_fTime;
	float m_fOldY;
	float m_fSpeed;
	float m_OffSetPosx;

private:
	list<LINE*>* m_pLineList;
	CObj* m_pBox;
public:
	void Scroll();

public:
	void SetLine(list<LINE*>* _pLineList){ m_pLineList = _pLineList; }
	void SetBox(CObj* _pBox){ m_pBox = _pBox; }

public:
	void CheckKey();
	void LineCol();
	void BoxCol();
	void Jump();
public:
	void SetY(float _fy){ m_tInfo.fY = _fy; }
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	virtual ~CPlayer(void);
};

