#include "StdAfx.h"
#include "Bullet.h"


CBullet::CBullet(void) :
m_fAngle(0.f)
{
}


CBullet::~CBullet(void)
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 20;
	m_tInfo.fCY = 20;

	m_iSpeed = 15;

}

void CBullet::Progress()
{
	m_tInfo.fX += cosf(m_fAngle * PI /180)* m_iSpeed;
	m_tInfo.fY += -sinf(m_fAngle * PI / 180) * m_iSpeed;


}

void CBullet::Render( HDC hdc )
{
	Ellipse(hdc,
		m_tInfo.fX - m_tInfo.fCX / 2,
		m_tInfo.fY - m_tInfo.fCY / 2,
		m_tInfo.fX + m_tInfo.fCX / 2,
		m_tInfo.fY + m_tInfo.fCY / 2
		);
}

void CBullet::Release()
{

}
