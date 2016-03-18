#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"

CMainGame::CMainGame(void) : 
m_pPlayer(NULL)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initalize()
{
	m_hdc = GetDC(g_hWnd);

	if (m_pPlayer == NULL)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initalize();
		((CPlayer*)m_pPlayer)->SetBullet(&m_BulletList);
	}		
}

void CMainGame::Progress()
{
	m_pPlayer->Progress();

}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);

	m_pPlayer->Render(m_hdc);
}
void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
}
