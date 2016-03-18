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

void CPlayer::Initialize()
{

	/*m_tInfo.iX = WINCX /2;
	m_tInfo.iY = WINCY/2;
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;*/

	m_tInfo  =  INFO(WINCX/2, WINCY/2, 100,100);

	m_iSpeed = 10;
}

void CPlayer::Progress()
{
	CheckKey();
}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc,int(m_tInfo.fX  - m_tInfo.fCX /2),
				  int(m_tInfo.fY  - m_tInfo.fCY /2),
				  int(m_tInfo.fX  + m_tInfo.fCX /2),
				  int(m_tInfo.fY  + m_tInfo.fCY /2)
				  );
}

void CPlayer::Release()
{

}

void CPlayer::CheckKey()
{
	if(GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_iSpeed;

	if(GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_iSpeed;

	if(GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_iSpeed;

	if(GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_iSpeed;


	if(GetAsyncKeyState('W'))
	{
		CObj* pBullet = new CBullet;
		pBullet->Initialize();
		pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);
		((CBullet*)pBullet)->SetDir(DIR_UP);

		m_pBulletList->push_back(pBullet);
	}

	if(GetAsyncKeyState('S'))
	{
		m_pBulletList->push_back(CreateBullet(DIR_DOWN));
	}

	if(GetAsyncKeyState('A'))
	{
		m_pBulletList->push_back(CreateBullet(DIR_LEFT));
	}

	if(GetAsyncKeyState('D'))
	{
		m_pBulletList->push_back(CreateBullet(DIR_RIGHT));
	}

	if(GetAsyncKeyState(VK_SPACE))
	{
		m_pBulletList->push_back(CreateBullet(DIR_UP));
		m_pBulletList->push_back(CreateBullet(DIR_LU));
		m_pBulletList->push_back(CreateBullet(DIR_RU));
	}



}

CObj* CPlayer::CreateBullet( DIRECTION _edir )
{
	CObj* pBullet = CAbStractFactory<CBullet>::CreateObj();

	pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);
	((CBullet*)pBullet)->SetDir(_edir);

	return pBullet;
}
