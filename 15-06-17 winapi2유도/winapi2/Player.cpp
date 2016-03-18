#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 700;
	m_tInfo.fY = WINCY /2.f;
	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;

	m_fSpeed = 10;
	m_fAngle = 0.f;



}

void CPlayer::Progress()
{
	if(GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fX += cosf(m_fAngle *PI /180) *m_fSpeed;
		m_tInfo.fY += -sinf(m_fAngle * PI /180)* m_fSpeed;
	}

	if(GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX += cosf(m_fAngle *PI /180) * -m_fSpeed;
		m_tInfo.fY += -sinf(m_fAngle * PI /180)* -m_fSpeed;
	}

	if(GetAsyncKeyState(VK_LEFT))
	{
		m_fAngle += 5;
	}

	if(GetAsyncKeyState(VK_RIGHT))
	{
		m_fAngle -= 5;
	}





}

void CPlayer::Render( HDC hdc )
{
	Ellipse(hdc, int(m_tInfo.fX - m_tInfo.fCX/2),
				 int(m_tInfo.fY - m_tInfo.fCY/2),
				 int(m_tInfo.fX + m_tInfo.fCX/2),
				 int(m_tInfo.fY + m_tInfo.fCY/2)
		);


	MoveToEx(hdc, m_tInfo.fX , m_tInfo.fY,NULL);

	float fx = m_tInfo.fX + cosf(m_fAngle *PI /180) *100;
	float fy = m_tInfo.fY + -sinf(m_fAngle *PI/180) *100;

	LineTo(hdc,fx,fy);

}

void CPlayer::Release()
{

}
