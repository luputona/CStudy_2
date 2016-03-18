#include "StdAfx.h"
#include "Player.h"
#include "KeyMgr.h"

CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo   = INFO(WINCX/2,WINCY/2,200,200);
	m_tFrame  = FRAME(0,4,0,100);
	m_dwState = STATE_STAND;

	m_fSpeed = 10.f;
	m_dwKey = 0;
	m_dwTime = GetTickCount();

	m_strDrawID = "Player_DOWN";

}

int CPlayer::Progress()
{
	KeyCheck();
	Frame();
	Direction();
	Motion();
	return 0;
}

void CPlayer::Render( HDC hdc )
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX /2),
		int(m_tInfo.fY - m_tInfo.fCY /2),
		(int)m_tInfo.fCX,(int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strDrawID]->GetMemDC(),
		int(m_tInfo.fCX * m_tFrame.iStart),
		int(m_tInfo.fCY * m_tFrame.iScene),
		(int)m_tInfo.fCX,(int)m_tInfo.fCY,
		RGB(0,0,0));

}

void CPlayer::Release()
{

}

void CPlayer::KeyCheck()
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if(m_dwKey & KEY_UP)
		m_tInfo.fY -= m_fSpeed;
	if(m_dwKey & KEY_DOWN)
		m_tInfo.fY += m_fSpeed;
	if(m_dwKey & KEY_LEFT)
		m_tInfo.fX -= m_fSpeed;
	if(m_dwKey & KEY_RIGHT)
		m_tInfo.fX += m_fSpeed;

	if (m_dwKey & KEY_SPACE)
	{
		m_dwState = STATE_ATT;
	}

	

}

void CPlayer::Frame()
{
	if(m_dwTime + m_tFrame.dwTime < GetTickCount())
	{
		m_dwTime = GetTickCount();

		++m_tFrame.iStart;

		if(m_tFrame.iStart >= m_tFrame.iLast)
		{
			if(m_dwState != STATE_STAND )
				m_dwState = STATE_STAND;

			m_tFrame.iStart = 0;
		}
	}
}

void CPlayer::Direction()
{
	if(KEY_LEFT & m_dwKey && KEY_UP & m_dwKey)
	{
		m_strDrawID = "Player_LU";
		return;
	}

	if(KEY_RIGHT & m_dwKey && KEY_UP & m_dwKey)
	{
		m_strDrawID = "Player_RU";
		return;
	}

	if(KEY_LEFT & m_dwKey && KEY_DOWN & m_dwKey)
	{
		m_strDrawID = "Player_LD";
		return;
	}

	if(KEY_RIGHT & m_dwKey && KEY_DOWN & m_dwKey)
	{
		m_strDrawID = "Player_RD";
		return;
	}

	if(KEY_LEFT & m_dwKey)
		m_strDrawID = "Player_LEFT";
	if(KEY_RIGHT & m_dwKey)
		m_strDrawID = "Player_RIGHT";
	if(KEY_UP & m_dwKey)
		m_strDrawID = "Player_UP";
	if(KEY_DOWN & m_dwKey)
		m_strDrawID = "Player_DOWN";



}

void CPlayer::Motion()
{
	if (m_dwKey && m_dwState != STATE_ATT)
	{
		m_dwState = STATE_WALK;
	}

	if(!m_dwState)
		m_dwState = STATE_STAND;

	if (m_dwState & STATE_STAND)
	{
		if (m_tFrame.iScene != 0)
		{
			m_tFrame.iStart = 0;
		}

		m_tFrame.iLast = 4;
		m_tFrame.iScene = 0;
		m_tFrame.dwTime = 150;
	}
	


	if(m_dwState & STATE_WALK)
	{
		if (m_tFrame.iScene != 1)
		{
			m_tFrame.iStart = 0;
		}
		m_tFrame.iLast = 6;
		m_tFrame.iScene = 1;
		m_tFrame.dwTime = 100;
	}


	if(m_dwState & STATE_ATT)
	{
		if (m_tFrame.iScene != 2)
		{
			m_tFrame.iStart = 0;
		}
		m_tFrame.iLast = 6;
		m_tFrame.iScene = 2;
		m_tFrame.dwTime = 100;
	}

}
