#pragma once
#include "obj.h"

class CPlayer:public CObj
{
private:
	string m_strDrawID;
	float  m_fSpeed;
	DWORD  m_dwKey;
	DWORD  m_dwTime;
	DWORD  m_dwState;
	FRAME  m_tFrame;
public:
	void KeyCheck();
	void Frame();
	void Direction();
	void Motion();
	
public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CPlayer(void);
	~CPlayer(void);
};

