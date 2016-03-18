#include "StdAfx.h"
#include "Bullet.h"


CBullet::CBullet(void)
{
}


CBullet::~CBullet(void)
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30;
	m_tInfo.fCY = 30;


	m_iSpeed = 15;

}

void CBullet::Progress()
{
	switch(m_eDir)
	{
	case DIR_UP:
		m_tInfo.fY -= m_iSpeed;
		break;
	case DIR_DOWN:
		m_tInfo.fY += m_iSpeed;
		break;
	case DIR_LEFT:
		m_tInfo.fX -= m_iSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.fX += m_iSpeed;
		break;
	case DIR_LU:
		m_tInfo.fX -= m_iSpeed;
		m_tInfo.fY -= m_iSpeed;
		break;
	case DIR_RU:
		m_tInfo.fX += m_iSpeed;
		m_tInfo.fY -= m_iSpeed;
		break;
	}
}

void CBullet::Render( HDC hdc )
{
	Ellipse(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2),
		int(m_tInfo.fY - m_tInfo.fCY /2),
		int(m_tInfo.fX + m_tInfo.fCX /2),
		int(m_tInfo.fY + m_tInfo.fCY /2)
		);

}

void CBullet::Release()
{

}
