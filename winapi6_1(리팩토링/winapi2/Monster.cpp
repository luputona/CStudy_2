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
	m_tInfo.fX = float(rand() % WINCX);
	m_tInfo.fY = float(rand() % WINCY);
	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;
}

void CMonster::Progress()
{

}

void CMonster::Render( HDC hdc )
{
	Rectangle(hdc,
		m_tInfo.fX - m_tInfo.fCX / 2,
		m_tInfo.fY - m_tInfo.fCY / 2,
		m_tInfo.fX + m_tInfo.fCX / 2,
		m_tInfo.fY + m_tInfo.fCY / 2
		);
}

void CMonster::Release()
{

}
