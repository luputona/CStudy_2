#include "StdAfx.h"
#include "Obj.h"


CObj::CObj(void)
{
}


CObj::~CObj(void)
{
}

void CObj::SetPos( int _nX,int _nY )
{
	m_tInfo.nX = _nX;
	m_tInfo.nY = _nY;
}
