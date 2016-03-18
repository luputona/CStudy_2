#pragma once
#include "Include.h"

class CObj
{
protected:
	INFO m_tInfo;
	static map<string,CBitMap*>* m_pMapBmp;
public:
	INFO GetInfo(void)const {return m_tInfo;}
	RECT GetRect();

public:
	void SetPos(float _fx, float _fy);
	static void SetBmp(map<string,CBitMap*>* _pMapBmp){m_pMapBmp = _pMapBmp;}
public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Release()PURE;

public:
	CObj(void);
	virtual ~CObj(void);
};

