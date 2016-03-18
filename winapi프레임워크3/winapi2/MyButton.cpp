#include "StdAfx.h"
#include "MyButton.h"
#include "Mouse.h"
#include "StateMgr.h"
#include "KeyMgr.h"
CMyButton::CMyButton(void)
{
}


CMyButton::~CMyButton(void)
{
	Release();
}

void CMyButton::Initialize()
{
	m_tInfo.fCX = 150;
	m_tInfo.fCY = 150;
	m_iScene = 0;
}

int CMyButton::Progress()
{
	
	if(PtInRect(&GetRect(),CMouse::GetPos()))
	{
		m_iScene = 1;

		if(CKeyMgr::GetInst()->GetKey() & KEY_LBUTTON)
		{
			if(m_strDrawID == "Start")
			{
				return 1;
			}
			else if(m_strDrawID == "Edit")
			{
				return 2;
			}
			else if(m_strDrawID == "Exit")
			{
				return 3;
			}
		}
	}
	else
	{
		m_iScene = 0;
	}
	return 0;
}

void CMyButton::Render( HDC hdc )
{
	TransparentBlt(hdc,
		int(m_tInfo.fX - m_tInfo.fCX/2),
		int(m_tInfo.fY - m_tInfo.fCY/2),
		(int)m_tInfo.fCX,(int)m_tInfo.fCY,
		(*m_pMapBmp)[m_strDrawID]->GetMemDC(),
		int(m_tInfo.fCX * m_iScene),0,m_tInfo.fCX,m_tInfo.fCY,RGB(255,255,255));
}

void CMyButton::Release()
{

}
