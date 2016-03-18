#include "StdAfx.h"
#include "MainGame.h"
#include "Ball.h"

CMainGame::CMainGame(void):m_pBall(NULL)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	if(m_pBall == NULL)
	{
		m_pBall = new CBall;
		m_pBall->Initialize();
	}
}

void CMainGame::Progress()
{
	m_pBall->Progress();
}

void CMainGame::Render()
{
	m_pBall->Render();
}

void CMainGame::Release()
{
	delete m_pBall;
	m_pBall = NULL;
}
