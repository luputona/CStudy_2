#include "StdAfx.h"
#include "Obj.h"


CObj::CObj(void)
{
}

CObj::CObj( string _strName,int _nHp,int _nAttack, int _nDef,int _nMoney )
{
	m_tInfo.strName = _strName;
	m_tInfo.nHp = _nHp;
	m_tInfo.nDef = _nDef;
	m_tInfo.nAttack = _nAttack;
	m_tInfo.nMoney = _nMoney;
}


CObj::~CObj(void)
{
}

