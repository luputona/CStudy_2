#include "StdAfx.h"
#include "Obj.h"


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
