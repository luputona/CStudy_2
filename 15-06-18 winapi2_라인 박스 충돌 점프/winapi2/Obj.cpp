#include "StdAfx.h"
#include "Obj.h"


CObj::CObj(void)
{
}


CObj::~CObj(void)
{
}

RECT CObj::GetRect()
{
	RECT rc =
	{
		int(m_tInfo.fX - m_tInfo.fCX / 2),
		int(m_tInfo.fY - m_tInfo.fCY / 2),
		int(m_tInfo.fX + m_tInfo.fCX / 2),
		int(m_tInfo.fY + m_tInfo.fCY / 2)
	};

	return rc;
}
