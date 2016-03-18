#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initalize()
{
	m_tInfo.nX = WINCX /2;
	m_tInfo.nY = WINCY /2;
	m_tInfo.nCX = 100;
	m_tInfo.nCY = 100;

	m_nSpeed = 10;
}

void CPlayer::Progress()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.nCX += m_nSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.nCX -= m_nSpeed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.nCY -= m_nSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.nCY += m_nSpeed;
	}

}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc,
		m_tInfo.nX - m_tInfo.nCX/2, 
		m_tInfo.nY - m_tInfo.nCY/2,
		m_tInfo.nX + m_tInfo.nCX/2, 
		m_tInfo.nY + m_tInfo.nCY/2);
}

void CPlayer::Release()
{

}
