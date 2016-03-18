#include "StdAfx.h"
#include "Box.h"


CBox::CBox(void)
{
}


CBox::~CBox(void)
{
}

void CBox::Initialize()
{
	m_tInfo = INFO(WINCX/2,WINCY/2,150,200);
}

void CBox::Progress()
{

}

void CBox::Render( HDC hdc )
{
	Rectangle(hdc, 
		int(m_tInfo.fX - m_tInfo.fCX /2),
		int(m_tInfo.fY - m_tInfo.fCY /2),
		int(m_tInfo.fX + m_tInfo.fCX /2),
		int(m_tInfo.fY + m_tInfo.fCY /2)
		);


}

void CBox::Release()
{

}
