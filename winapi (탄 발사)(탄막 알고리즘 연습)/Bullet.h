#pragma once
#include "Obj.h"

class CBullet : public CObj
{
private:
	DIRECTION m_eDir;
	
	float m_fAngle[2];
	float m_fSpeed;
	float m_fAngleRate[2];
	float m_fSpeedRate;
	
	int m_nCount;

	int m_nTime;
	int m_nInterval;

	float m_fBulletAngleRate;
	float m_fBulletSpeedRate;

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

