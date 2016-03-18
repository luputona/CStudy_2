#include "StdAfx.h"
#include "Obj.h"
map<string,CBitMap*>* CObj::m_pMapBmp = NULL;

CObj::CObj(void)
{
}


CObj::~CObj(void)
{
}

void CObj::SetPos( float _fx, float _fy )
{
	m_tInfo.fX = _fx;
	m_tInfo.fY = _fy;
}

RECT CObj::GetRect()
{
	RECT rc = {
		m_tInfo.fX - m_tInfo.fCX/2,
		m_tInfo.fY - m_tInfo.fCY/2,
		m_tInfo.fX + m_tInfo.fCX/2,
		m_tInfo.fY + m_tInfo.fCY/2
	};

	return rc;
}
