#include "StdAfx.h"
#include "MainGame.h"
#include "ObjFactory.h"
#include "Player.h"


CMainGame::CMainGame(void) :
m_pPlayer(NULL)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = CObjFactory<CPlayer>::CreateObj();
	((CPlayer*)m_pPlayer)->SetBullet(&m_pBulletList);



}

void CMainGame::Progress()
{
	m_pPlayer->Progress();

}

void CMainGame::Render()
{
	m_pPlayer->Render(m_hdc);

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
}
