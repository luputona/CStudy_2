#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}

CMonster::CMonster( string _strName,int _nHp,int _nAttack,int _nMoney ) :
m_tMonster(_strName,_nHp,_nAttack,_nMoney)
{

}


CMonster::~CMonster(void)
{
}

void CMonster::Render()
{
	cout <<"==========================================\n";
	cout <<"���� �̸� : "<<m_tMonster.strName <<"\t ������ : "<<m_tMonster.nMoney<<endl;
	cout <<"ü�� : "<<m_tMonster.nHp<<"\t ���ݷ� : "<<m_tMonster.nAttack<<endl;
}
