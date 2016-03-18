#include "StdAfx.h"
#include "MyMenu.h"

#include "Obj.h"
#include "BackGround.h"
#include "ObjFactory.h"
#include "MyButton.h"
#include "StateMgr.h"

CMyMenu::CMyMenu(void):m_pBackGround(NULL)
{
}


CMyMenu::~CMyMenu(void)
{
	Release();
}

void CMyMenu::Initialize()
{
	m_MapBmp["BackBuffer"] = (new CBitMap)->LoadBmp(L"../Texture/BackBuffer.bmp");
	m_MapBmp["BackGround"] = (new CBitMap)->LoadBmp(L"../Texture/Menu/Back/BackGround.bmp");
	m_MapBmp["Start"] = (new CBitMap)->LoadBmp(L"../Texture/Menu/Button/Start.bmp");
	m_MapBmp["Edit"] = (new CBitMap)->LoadBmp(L"../Texture/Menu/Button/Edit.bmp");
	m_MapBmp["Exit"] = (new CBitMap)->LoadBmp(L"../Texture/Menu/Button/Exit.bmp");

	m_pBackGround = new CBackGround;

	m_ButtonList.push_back(CreateButton(200,500,"Start"));
	m_ButtonList.push_back(CreateButton(400,500,"Edit"));
	m_ButtonList.push_back(CreateButton(600,500,"Exit"));

	CObj::SetBmp(&m_MapBmp);

}

int CMyMenu::Progress()
{
	int iResult =0;
	for(list<CObj*>::iterator iter = m_ButtonList.begin(); 
		iter != m_ButtonList.end(); ++iter)
	{
		iResult = (*iter)->Progress();

		if(iResult == 1)
		{
			CStateMgr::GetInst()->SetState(IDS_STAGE);
			return 0;
		}
		else if(iResult == 2)
		{
			CStateMgr::GetInst()->SetState(IDS_LOGO);
			return 0;
		}
		else if(iResult == 3)
		{
			DestroyWindow(g_hWnd);
			return 0;
		}

	}

	return 0;
}

void CMyMenu::Render( HDC hdc )
{
	m_pBackGround->Render(m_MapBmp["BackBuffer"]->GetMemDC());

	for(list<CObj*>::iterator iter = m_ButtonList.begin(); 
		iter != m_ButtonList.end(); ++iter)
	{
		(*iter)->Render(m_MapBmp["BackBuffer"]->GetMemDC());
	}

	//�����
	BitBlt(hdc,0,0,WINCX,WINCY, m_MapBmp["BackBuffer"]->GetMemDC(),0,0,SRCCOPY);


}

void CMyMenu::Release()
{
	CStateObj::Release();
	Safe_Delete(m_pBackGround);

	for(list<CObj*>::iterator iter = m_ButtonList.begin(); 
		iter != m_ButtonList.end(); ++iter)
	{
			Safe_Delete(*iter);
	}
	
	m_ButtonList.clear();
	
}

CObj* CMyMenu::CreateButton( float _fx, float _fy,string _DrawId )
{
	CObj* pButton = CObjFactory<CMyButton>::CreateObj(_fx,_fy);
	((CMyButton*)pButton)->SetDrawId(_DrawId);

	return pButton;
}
