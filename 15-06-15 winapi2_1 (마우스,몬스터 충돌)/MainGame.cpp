#include "StdAfx.h"
#include "MainGame.h"
#include "Monster.h"
#include "Mouse.h"
#include "CollisionMgr.h"


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

	srand(unsigned(time(NULL)));

	m_pMouse = new CMouse;
	m_pMouse->Initalize();

	for (int i = 0; i<7; i++)
	{
		CObj* pMonster = new CMonster;
		pMonster->Initalize();
		pMonster->SetPos(float(rand()%WINCX),float(rand()%WINCY));
		m_MonsterList.push_back(pMonster);
	}

}

void CMainGame::Progress()
{
	m_pMouse->Progress();

	for (list<CObj*>::iterator iter = m_MonsterList.begin(); iter != m_MonsterList.end(); )
	{
		(*iter)->Progress();

		if (CollisionMgr::CircleCol(m_pMouse,(*iter))) // 마우스와 몬스터 연산
		{
			Safe_Delete(*iter); //몬스터를 지운다
			iter = m_MonsterList.erase(iter);
		}
		else
			++iter;
	}

}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);
	m_pMouse->Render(m_hdc);

	for (list<CObj*>::iterator iter = m_MonsterList.begin(); iter != m_MonsterList.end(); ++iter)
	{
		(*iter)->Render(m_hdc);
	}

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
}
