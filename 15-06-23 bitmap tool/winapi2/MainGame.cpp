#include "StdAfx.h"
#include "MainGame.h"
#include "BitMap.h"
#include "MapEdit.h"

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

	m_pMapEdit = new CMapEdit;
	m_pMapEdit->Initialize();
}

void CMainGame::Progress()
{
	m_pMapEdit->Progress();

}

void CMainGame::Render()
{
	m_pMapEdit->Render(m_hdc);



	


}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);
	Safe_Delete(m_pMapEdit);
}
