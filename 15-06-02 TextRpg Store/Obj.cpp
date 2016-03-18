#include "StdAfx.h"
#include "Obj.h"


CObj::CObj(void)
{
}

CObj::CObj( string _strName,int _nHp,int _nAttack,int _nMoney ) :
m_tInfo(_strName,_nHp,_nAttack,_nMoney)
{

}


CObj::~CObj(void)
{
}
