#include "StdAfx.h"
#include "MainGame.h"
#include "ObjFactory.h"
#include "Player.h"
#include "Monster.h"
#include "ColMgr.h"

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

	m_pPlayer = CObjFactory<CPlayer>::CreateObj();
		
	((CPlayer*)m_pPlayer)->SetBullet(&m_ObjList[OBJ_BULLET]);

	m_ObjList[OBJ_PLAYER].push_back(m_pPlayer);

	for (int i = 0; i<10; ++i)
	{		
		m_ObjList[OBJ_MONSTER].push_back(CObjFactory<CMonster>::CreateObj());
	}

}

void CMainGame::Progress()
{
	m_pPlayer->Progress();

	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();
		}
	}

	CColMgr::ColRect(&m_ObjList[OBJ_MONSTER],&m_ObjList[OBJ_BULLET]);


	 





	//for (list<CObj*>::iterator iter = m_BulletList.begin(); iter != m_BulletList.end(); ++iter)
	//{
	//	(*iter)->Progress();
	//}


	//for (list<CObj*>::iterator iter = m_MonsterList.begin(); iter != m_MonsterList.end(); ++iter)
	//{
	//	(*iter)->Progress();
	//}

	/*RECT rc;

	for (list<CObj*>::iterator iter1 = m_MonsterList.begin(); iter1 != m_MonsterList.end(); ++iter1)
	{
	for (list<CObj*>::iterator iter2 = m_BulletList.begin(); iter2 != m_BulletList.end(); )
	{
	if (IntersectRect(&rc,&(*iter1)->GetRect(),&(*iter2)->GetRect()))
	{
	Safe_Delete(*iter1);
	Safe_Delete(*iter2);

	iter1 = m_MonsterList.erase(iter1);
	iter2 = m_BulletList.erase(iter2);
	}
	else
	{
	++iter2;
	}
	if (iter1 == m_MonsterList.end())
	{
	break;
	}
	}
	if (iter1 == m_MonsterList.end())
	{
	break;
	}
	}*/


}

void CMainGame::Render()
{
	Rectangle(m_hdc,0,0,WINCX,WINCY);
	
	//m_pPlayer->Render(m_hdc);

	for (int i = 0; i<OBJ_END; ++i)
	{
		for (list<CObj*>::iterator iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_hdc);
		}
	}


	/*for (list<CObj*>::iterator iter = m_BulletList.begin(); iter != m_BulletList.end(); ++iter)
	{
	(*iter)->Render(m_hdc);
	}


	for (list<CObj*>::iterator iter = m_MonsterList.begin(); iter != m_MonsterList.end(); ++iter)
	{
	(*iter)->Render(m_hdc);
	}*/
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
