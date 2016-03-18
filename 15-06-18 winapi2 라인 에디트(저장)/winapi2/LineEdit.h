#pragma once
#include "Obj.h"

class CLineEdit : public CObj
{
private:
	bool m_bStart;
	POINTFLOAT m_tStartPoint;
	POINTFLOAT m_tLPoint;
	POINTFLOAT m_tRPoint;

	POINTFLOAT m_tScrollPos;
	float m_fSpeed;
	list<LINE*> m_LineList;
public:
	void WriteData();
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CLineEdit(void);
	~CLineEdit(void);
};

