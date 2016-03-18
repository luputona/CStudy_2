#include "StdAfx.h"
#include "Obj.h"


CObj::CObj(void)
{
}


CObj::~CObj(void)
{
}

void CObj::SetPos( int _fX,int _fY )
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}
