#include "StdAfx.h"
#include "Stage.h"
#include "ObjFactory.h"
#include "StageBack.h"
#include "Player.h"

CStage::CStage(void):m_pBackGround(NULL)
{
}


CStage::~CStage(void)
{
	Release();
}

void CStage::Initialize()
{
	m_MapBmp["BackBuffer"] = (new CBitMap)->LoadBmp(L"../Texture/BackBuffer.bmp");
	m_MapBmp["BackGround"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Back/BackGround.bmp");
	//플레이어
	m_MapBmp["Player_UP"]    = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerUP.bmp");
	m_MapBmp["Player_DOWN"]  = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerDOWN.bmp");
	m_MapBmp["Player_LEFT"]  = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerLEFT.bmp");
	m_MapBmp["Player_RIGHT"] = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerRIGHT.bmp");
	m_MapBmp["Player_LD"]    = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerLD.bmp");
	m_MapBmp["Player_LU"]    = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerLU.bmp");
	m_MapBmp["Player_RD"]    = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerRD.bmp");
	m_MapBmp["Player_RU"]    = (new CBitMap)->LoadBmp(L"../Texture/Stage/Player/PlayerRU.bmp");

	m_pBackGround = CObjFactory<CStageBack>::CreateObj();

	CObj* pPlayer = CObjFactory<CPlayer>::CreateObj();
	m_ObjList[OBJ_PLAYER].push_back(pPlayer);

	CObj::SetBmp(&m_MapBmp);
}

int CStage::Progress()
{
	for(int i=0; i<OBJ_END; ++i)
	{
		for(list<CObj*>::iterator iter= m_ObjList[i].begin(); 
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Progress();
		}
	}


	return 0;
}

void CStage::Render( HDC hdc )
{
	m_pBackGround->Render(m_MapBmp["BackBuffer"]->GetMemDC());

	for(int i=0; i<OBJ_END; ++i)
	{
		for(list<CObj*>::iterator iter= m_ObjList[i].begin(); 
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_MapBmp["BackBuffer"]->GetMemDC());
		}
	}


	//백버처
	BitBlt(hdc, 0,0,WINCX,WINCY,
		m_MapBmp["BackBuffer"]->GetMemDC(),0,0,SRCCOPY);

}

void CStage::Release()
{
	CStateObj::Release();
	Safe_Delete(m_pBackGround);

	for(int i= 0; i<OBJ_END; ++i)
	{

		for(list<CObj*>::iterator iter= m_ObjList[i].begin(); 
			iter != m_ObjList[i].end(); ++iter)
		{
			Safe_Delete(*iter);
		}
		m_ObjList[i].clear();
	}


}
