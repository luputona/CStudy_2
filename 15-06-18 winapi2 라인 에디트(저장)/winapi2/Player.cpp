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
	m_tInfo = INFO(WINCX/2.0f,WINCY/2.0f,100,100);
	
	m_fSpeed = 10.f;

}

void CPlayer::Progress()
{
	CheckKey();

	
}

void CPlayer::Render( HDC hdc )
{
	Ellipse(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX/2),
		int(m_tInfo.fY - m_tInfo.fCY/2),
		int(m_tInfo.fX + m_tInfo.fCX/2),
		int(m_tInfo.fY + m_tInfo.fCY/2)
		);

}

void CPlayer::Release()
{

}


void CPlayer::CheckKey()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}


}