#include "StdAfx.h"
#include "Bullet.h"


CBullet::CBullet(void)
{
}


CBullet::~CBullet(void)
{
}

void CBullet::Initialize()
{

}

void CBullet::Progress()
{
	m_tInfo.iY -= m_iSpeed;
}

void CBullet::Render( HDC hdc )
{
	Ellipse(hdc,m_tInfo.iX - m_tInfo.iCX/2,
		m_tInfo.iY - m_tInfo.iCY/2,	
		m_tInfo.iX + m_tInfo.iCX/2,
		m_tInfo.iY + m_tInfo.iCY/2);
}

void CBullet::Release()
{

}

void CBullet::SetPos( int _ix, int _iy )
{

}
