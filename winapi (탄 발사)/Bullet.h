#pragma once
#include "Obj.h"

class CBullet : public CObj
{
private:
	DIRECTION m_eDir;
public:
	void SetDir(DIRECTION _edir) { m_eDir = _edir; } // 방향을 받는 함수 
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CBullet(void);
	~CBullet(void);
};

