#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"

CMainGame::CMainGame(void):m_pPlayer(NULL)
{

}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	if(m_pPlayer == NULL)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
		((CPlayer*)m_pPlayer)->SetBullet(&m_BulletList);
	}




}

void CMainGame::Progress()
{

	m_pPlayer->Progress();

	//중요 
	for (list <CObj*>::iterator iter = m_BulletList.begin(); iter != m_BulletList.end(); )
	{
		(*iter)->Progress();

		if ((*iter)->GetInfo().iY < 0)
		{
			delete *iter;
			*iter = NULL;
			iter = m_BulletList.erase(iter); // 지우면서 ++iter됨 
		}
		else
		{
			++iter;
		}
	}

}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);

	m_pPlayer->Render(m_hdc);

	for (list<CObj*>::iterator iter = m_BulletList.begin(); iter != m_BulletList.end(); ++iter)
	{
		(*iter)->Render(m_hdc);
	}

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
}
