#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"
#include "Box.h"

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

	m_pBox = new CBox;
	m_pBox->Initialize();

	POINTFLOAT tPoint[4] = 
	{
		{100,500},
		{300,500},
		{500,300},
		{700,300}
	};

	m_LineList.push_back(new LINE(tPoint[0],tPoint[1]));
	m_LineList.push_back(new LINE(tPoint[1],tPoint[2]));
	m_LineList.push_back(new LINE(tPoint[2],tPoint[3]));


	((CPlayer*)m_pPlayer)->SetLine(&m_LineList);
	((CPlayer*)m_pPlayer)->SetBox(m_pBox);

}

void CMainGame::Progress()
{
	m_pPlayer->Progress();

	m_pBox->Progress();
	


}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);

	m_pPlayer->Render(m_hdc);

	m_pBox->Render(m_hdc);
	MoveToEx(m_hdc,(int)m_LineList.front()->tLPoint.x,
		(int)m_LineList.front()->tLPoint.y,NULL);


	for (list<LINE*>::iterator iter = m_LineList.begin(); iter != m_LineList.end(); ++iter)
	{
		LineTo(m_hdc,(int)(*iter)->tRPoint.x,(int)(*iter)->tRPoint.y);
	}

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
	Safe_Delete(m_pPlayer);

	for(list<LINE*>::iterator iter = m_LineList.begin(); 
		iter != m_LineList.end(); ++iter)
	{
		Safe_Delete(*iter);
	}

	m_LineList.clear();
}
