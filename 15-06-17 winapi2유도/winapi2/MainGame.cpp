#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	//m_ObjList[OBJ_PLAYER].push_back(m_pPlayer);

	CObj* pMonster = new CMonster;
	pMonster->Initialize();
	pMonster->SetPos(100,100);
	((CMonster*)pMonster)->SetPlayer(m_pPlayer);
	
	m_ObjList[OBJ_MONSTER].push_back(pMonster);
	
	pMonster = new CMonster;
	pMonster->Initialize();
	pMonster->SetPos(100,500);
	((CMonster*)pMonster)->SetPlayer(m_pPlayer);

	m_ObjList[OBJ_MONSTER].push_back(pMonster);

}

void CMainGame::Progress()
{
	m_pPlayer->Progress();


	for(int i =0; i<OBJ_END; ++i)
	{
		for(list<CObj*>::iterator iter = m_ObjList[i].begin(); 
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();
		}
	}



	



}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);


	m_pPlayer->Render(m_hdc);


	for(int i =0; i<OBJ_END; ++i)
	{
		for(list<CObj*>::iterator iter = m_ObjList[i].begin(); 
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_hdc);
		}
	}
	
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
}
