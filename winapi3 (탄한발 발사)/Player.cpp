#include "StdAfx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.iX = WINCX /2;
	m_tInfo.iY = WINCY /2;
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;


	m_iSpeed = 10;


}

void CPlayer::Progress()
{

	if(GetAsyncKeyState(VK_RIGHT))
		m_tInfo.iX += m_iSpeed;


	if(GetAsyncKeyState(VK_LEFT))
		m_tInfo.iX -= m_iSpeed;


	if(GetAsyncKeyState(VK_UP))
		m_tInfo.iY -= m_iSpeed;


	if(GetAsyncKeyState(VK_DOWN))
		m_tInfo.iY += m_iSpeed;


	if (GetAsyncKeyState(VK_SPACE))
	{
		CObj *pBullet = new CBullet;
		//pBullet->
		((CBullet*)pBullet)->SetPos(m_tInfo.iX,m_tInfo.iY);
	}




}

void CPlayer::Render( HDC hdc )
{
	Rectangle(hdc,
		m_tInfo.iX - m_tInfo.iCX /2 ,
		m_tInfo.iY - m_tInfo.iCY /2 ,
		m_tInfo.iX + m_tInfo.iCX /2 ,
		m_tInfo.iY + m_tInfo.iCY /2
		);




}

void CPlayer::Release()
{

}
