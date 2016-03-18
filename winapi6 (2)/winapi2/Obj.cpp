#include "StdAfx.h"
#include "Obj.h"


CObj::CObj(void) : 
m_iSpeed(0)
{
}


CObj::~CObj(void)
{
}

RECT CObj::GetRect()
{
	RECT rc = 
	{
		m_tInfo.fX - m_tInfo.fCX /2,
		m_tInfo.fY - m_tInfo.fCY /2,
		m_tInfo.fX + m_tInfo.fCX /2,
		m_tInfo.fY + m_tInfo.fCY /2
	};

	return rc;
}
