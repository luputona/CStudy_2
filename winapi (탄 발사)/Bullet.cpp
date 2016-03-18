#include "StdAfx.h"
#include "Bullet.h"


CBullet::CBullet(void)
{
}

CBullet::~CBullet(void)
{
	Release();
}

void CBullet::Initalize()
{
	m_tInfo.nCX = 30;
	m_tInfo.nCY = 30;

	m_nSpeed = 15;

}

void CBullet::Progress()
{
	switch(m_eDir)
	{
	case DIR_UP:
		m_tInfo.nY -= m_nSpeed;
		break;
	case DIR_DOWN:
		m_tInfo.nY +=m_nSpeed;
		break;
	case DIR_LEFT:
		m_tInfo.nX -= m_nSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.nX += m_nSpeed;
		break;
	case DIR_LU:
		m_tInfo.nX -= m_nSpeed;
		m_tInfo.nY -= m_nSpeed;
		break;
	case DIR_RU:
		m_tInfo.nX += m_nSpeed;
		m_tInfo.nY -= m_nSpeed;
		break;

	}

}

void CBullet::Render( HDC hdc )
{
	Ellipse(hdc, 
		m_tInfo.nX - m_tInfo.nCX/2,
		m_tInfo.nY - m_tInfo.nCY/2,
		m_tInfo.nX + m_tInfo.nCX/2,
		m_tInfo.nY + m_tInfo.nCY/2);
}

void CBullet::Release()
{

}
