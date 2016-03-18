#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"
#include "ObjFactory.h"
#include "Define.h"
#include "LineEdit.h"

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

	m_ObjList[OBJ_LINEEDIT].push_back(CObjFactory<CLineEdit>::CreateObj());
	


}

void CMainGame::Progress()
{
	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();
		}
	}
	


}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);

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

	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			Safe_Delete(*iter);
		}
		m_ObjList[i].clear();
	}
}
