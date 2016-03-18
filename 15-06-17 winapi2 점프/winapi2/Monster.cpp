#include "StdAfx.h"
#include "Monster.h"
#include "MathMgr.h"

CMonster::CMonster(void)
{
}


CMonster::~CMonster(void)
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 100;
	m_tInfo.fCY = 100;

	m_fAngle = 0.f;
	m_fSpeed = 5;

}

void CMonster::Progress()
{

	
	m_fAngle = CMathMgr::GetAngle(m_pPlayer,this);


	m_tInfo.fX += cosf(m_fAngle * PI/ 180) *m_fSpeed;
	m_tInfo.fY += -sinf(m_fAngle *PI/ 180) *m_fSpeed;


}

void CMonster::Render( HDC hdc )
{
	Rectangle(hdc,
		int(m_tInfo.fX - m_tInfo.fCX/2),
		int(m_tInfo.fY - m_tInfo.fCY/2),
		int(m_tInfo.fX + m_tInfo.fCX/2),
		int(m_tInfo.fY + m_tInfo.fCY/2)
		
		);


}

void CMonster::Release()
{

}
