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
	m_tInfo.fX = WINCX / 2.f;
	m_tInfo.fY = WINCY /2.f;
	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;

	m_fSpeed = 10;
	m_fAngle = 0.f;

	m_bJump = false;
	m_fTime = 0.0f;

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
	Jump();

	if (m_bJump== true)
	{
		m_fTime += 0.1f;
		m_tInfo.fY += -sinf(90 * PI /180) * 10 + (0.98f * m_fTime * m_fTime)/2;

		if (m_fOldY < m_tInfo.fY)
		{
			m_fTime = 0.0f;
			m_bJump = false;
			m_tInfo.fY = m_fOldY;
		}

	}
}

void CPlayer::Render( HDC hdc )
{
	Ellipse(hdc, int(m_tInfo.fX - m_tInfo.fCX/2),
				 int(m_tInfo.fY - m_tInfo.fCY/2),
				 int(m_tInfo.fX + m_tInfo.fCX/2),
				 int(m_tInfo.fY + m_tInfo.fCY/2));

}

void CPlayer::Release()
{

}

void CPlayer::Jump()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (m_bJump)
		{
			return;
		}
		m_bJump = true;
		m_fOldY = m_tInfo.fY;
	}

}
