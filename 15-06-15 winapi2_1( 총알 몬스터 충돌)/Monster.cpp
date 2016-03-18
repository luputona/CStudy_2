#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}


CMonster::~CMonster(void)
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 80;
	m_tInfo.fCY = 80;
}

void CMonster::Progress()
{

}

void CMonster::Render( HDC hdc )
{
	Ellipse(hdc,
		int(m_tInfo.fX - m_tInfo.fCX / 2),
		int(m_tInfo.fY - m_tInfo.fCY / 2),
		int(m_tInfo.fX + m_tInfo.fCX / 2),
		int(m_tInfo.fY + m_tInfo.fCY / 2)
		);
}

void CMonster::Release()
{

}
