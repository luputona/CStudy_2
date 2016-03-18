#include "StdAfx.h"
#include "Bullet.h"
#include "Player.h"
#include "ObjFactory.h"

CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX  = WINCX /2;
	m_tInfo.fY  = WINCY /2;
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_iSpeed = 10;
	m_fAngle = 0.f;
	m_fDistance = 100.f;

}

void CPlayer::Progress()
{
	CheckKey();
}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc ,
		m_tInfo.fX - m_tInfo.fCX /2,
		m_tInfo.fY - m_tInfo.fCY /2,
		m_tInfo.fX + m_tInfo.fCX /2,
		m_tInfo.fY + m_tInfo.fCY /2);

	MoveToEx(hdc, m_tInfo.fX,m_tInfo.fY,NULL);

	float fx = m_tInfo.fX + cosf(m_fAngle *PI / 180) *m_fDistance;
	float fy = m_tInfo.fY + -sinf(m_fAngle *PI / 180) *m_fDistance;

	LineTo(hdc,fx,fy);





}

void CPlayer::Release()
{

}

void CPlayer::CheckKey()
{

	if(GetAsyncKeyState(VK_LEFT))
		m_fAngle += 5;

	if(GetAsyncKeyState(VK_RIGHT))
		m_fAngle -= 5;


	if(GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fX += cosf(m_fAngle*PI / 180) * m_iSpeed;
		m_tInfo.fY += -sinf(m_fAngle*PI /180) * m_iSpeed;
	}

	if(GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX += cosf(m_fAngle*PI / 180) * -m_iSpeed;
		m_tInfo.fY += -sinf(m_fAngle*PI /180) * -m_iSpeed;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		CObj* pBullet = CObjFactory<CBullet>::CreateObj(m_tInfo.fX,m_tInfo.fY,m_fAngle);
		m_pBulletList->push_back(pBullet);
	}




}
