#pragma once
#include "Obj.h"

class CBullet : public CObj
{
private:
	DIRECTION m_eDir;
public:
	void SetDir(DIRECTION _edir) { m_eDir = _edir; } // ������ �޴� �Լ� 
public:
	virtual void Initalize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CBullet(void);
	~CBullet(void);
};

