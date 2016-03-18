#include "StdAfx.h"
#include "MainGame.h"
#include "AbStractFactory.h"
#include "Player.h"
#include "Bullet.h"

CMainGame::CMainGame(void) :
m_pPlayer(NULL),
m_iFps(0)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	m_dwTime  = GetTickCount();
	if (m_pPlayer == NULL)
	{
		m_pPlayer = CAbStractFactory<CPlayer>::CreateObj();
		((CPlayer*)m_pPlayer)->SetBullet(&m_BulletList);
	}

}

void CMainGame::Progress()
{
	m_pPlayer->Progress();

	for (OBJITER iter = m_BulletList.begin(); iter != m_BulletList.end(); )
	{
		(*iter)->Progress();

		if ((*iter)->GetInfo().nX<0 || (*iter)->GetInfo().nX>WINCX 
			|| (*iter)->GetInfo().nY<0 || (*iter)->GetInfo().nY>WINCY)
		{
			Safe_Delete(*iter);
			iter = m_BulletList.erase(iter);
		}
		else
			++iter;
	}

}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);
	
	m_pPlayer->Render(m_hdc);

	for (OBJITER iter= m_BulletList.begin(); iter != m_BulletList.end(); ++iter)
	{
		(*iter)->Render(m_hdc);
	}

	++m_iFps;

	if (m_dwTime + 1000 < GetTickCount()) //1초가 되면 0 세팅
	{
		m_dwTime = GetTickCount();
		wsprintf(szFps,L"FPS : %d",m_iFps); //  와이드 바이트 캐릭터 TCHAR   w 영문자 2바이트 한글자도 2바이트 
		
		m_iFps = 0;
	}

	SetWindowText(g_hWnd,szFps);
	TextOut(m_hdc,WINCX/2,100,szFps,lstrlen(szFps));

	RECT rc = {200,200,400,400};

	TCHAR szBuf[128] = L"";

	wsprintf(szBuf,L"BULLET : %d", m_BulletList.size());
	TextOut(m_hdc,100,100,szBuf,lstrlen(szBuf));

}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd,m_hdc);

	SAFE_DELETE(m_pPlayer);

	//for (OBJITER iter = m_BulletList.begin(); iter != m_BulletList.end(); ++iter)
	//{
	//	::Safe_Delete(*iter);
	//}
	
	for_each(m_BulletList.begin(),m_BulletList.end(),ObjDelete());

	m_BulletList.clear();
}
