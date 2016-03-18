#include "StdAfx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbStractFactory.h"

CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initalize()
{
	m_tInfo = INFO(WINCX/2,500 ,100,100);

	m_nSpeed = 10;
}

void CPlayer::Progress()
{
	Checkkey();
}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc,m_tInfo.fX - m_tInfo.nCX/2,
		m_tInfo.fY - m_tInfo.nCY/2,
		m_tInfo.fX + m_tInfo.nCX/2,
		m_tInfo.fY + m_tInfo.nCY/2);
}

void CPlayer::Release()
{
	
}

void CPlayer::Checkkey()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_nSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_nSpeed;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_nSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_nSpeed;
	}

	if (GetAsyncKeyState('W'))
	{
		CObj* pBullet = new CBullet;
		pBullet->Initalize();
		pBullet->SetPos(m_tInfo.fX,m_tInfo.fY);
		((CBullet*)pBullet)->SetDir(DIR_UP);

		m_pBulletList->push_back(pBullet);

	}

	if (GetAsyncKeyState('S'))
	{
		m_pBulletList->push_back(CreateBullet(DIR_DOWN));
	}
	if (GetAsyncKeyState('A'))
	{
		m_pBulletList->push_back(CreateBullet(DIR_LEFT));
	}

	if (GetAsyncKeyState('D'))
	{
		m_pBulletList->push_back(CreateBullet(DIR_RIGHT));
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBulletList->push_back(CreateBullet(DIR_UP));
		//m_pBulletList->push_back(CreateBullet(DIR_LU));
		//m_pBulletList->push_back(CreateBullet(DIR_RU));
	}


}

CObj* CPlayer::CreateBullet( DIRECTION _edir )
{
	CObj* pBullet = CAbStractFactory<CBullet>::CreateObj(); //할당이 되면서 초기화 되서 들어옴 

	pBullet->SetPos(m_tInfo.fX,m_tInfo.fY); // 플레이어 좌표 넣음
	((CBullet*)pBullet)->SetDir(_edir); // 총알 방향 


	return pBullet;
}
