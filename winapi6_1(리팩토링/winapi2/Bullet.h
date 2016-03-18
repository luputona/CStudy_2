#pragma once
#include "Obj.h"

class CBullet : public CObj
{
private:
	float m_fAngle;
	
public:
	void SetAngle(float _fAngle) { m_fAngle = _fAngle; }
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CBullet(void);
	virtual ~CBullet(void);
};

