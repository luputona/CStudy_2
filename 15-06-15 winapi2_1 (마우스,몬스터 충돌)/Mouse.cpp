#include "StdAfx.h"
#include "Mouse.h"


CMouse::CMouse(void)
{
}


CMouse::~CMouse(void)
{
	Release();
}

void CMouse::Initalize()
{
	m_tInfo.fCX = 80;
	m_tInfo.fCY = 80;
}

void CMouse::Progress()
{
	GetCursorPos(&m_ptMouse); // 스크린 전체에서 값을 가져옴 

	ScreenToClient(g_hWnd,&m_ptMouse); //클라이언트에서 값을 가져옴

	m_tInfo.fX = (float)m_ptMouse.x;
	m_tInfo.fY = (float)m_ptMouse.y;

}

void CMouse::Render( HDC hdc )
{
	Ellipse(hdc,
		int(m_tInfo.fX - m_tInfo.fCX / 2),
		int(m_tInfo.fY - m_tInfo.fCY / 2),
		int(m_tInfo.fX + m_tInfo.fCX / 2),
		int(m_tInfo.fY + m_tInfo.fCY / 2)
		);
}

void CMouse::Release()
{

}
