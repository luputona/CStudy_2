#include "StdAfx.h"
#include "MainGame.h"
#include "BitMap.h"
#include "StateObj.h"
#include "StateMgr.h"

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

	CStateMgr::GetInst()->SetState(IDS_STAGE1);	

}

void CMainGame::Progress()
{
	CStateMgr::GetInst()->GetState()->Progress();

}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);
	CStateMgr::GetInst()->GetState()->Render(m_hdc);

	


}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);

	CStateMgr::GetInst()->DestroyInst();
}
