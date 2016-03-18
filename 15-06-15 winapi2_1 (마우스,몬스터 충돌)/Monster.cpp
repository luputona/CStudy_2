#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}


CMonster::~CMonster(void)
{
	Release();
}

void CMonster::Initalize()
{
	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;
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
