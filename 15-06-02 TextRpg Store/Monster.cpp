#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}

CMonster::CMonster( string _strName,int _nHp,int _nAttack,int _nMoney ) :
CObj(_strName,_nHp,_nAttack,_nMoney)
{

}


CMonster::~CMonster(void)
{
}

void CMonster::Render()
{
	cout <<"==========================================\n";
	cout <<"직업 이름 : "<<m_tInfo.strName <<"\t 소지금 : "<<m_tInfo.nMoney<<endl;
	cout <<"체력 : "<<m_tInfo.nHp<<"\t 공격력 : "<<m_tInfo.nAttack<<endl;
}
