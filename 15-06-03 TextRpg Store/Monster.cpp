#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}

CMonster::CMonster( string _strName,int _nHp,int _nAttack,int _nMoney,int _nDef ) :
CObj(_strName,_nHp,_nAttack,_nMoney,_nDef)
{

}


CMonster::~CMonster(void)
{
}

void CMonster::Render()
{
	cout <<"==========================================\n";
	cout <<"���� �̸� : "<<m_tInfo.strName <<"\t ������ : "<<m_tInfo.nMoney<<endl;
	cout <<"ü�� : "<<m_tInfo.nHp<<"\t ���ݷ� : "<<m_tInfo.nAttack <<"\t ���� : "<<m_tInfo.nDef<<endl;
}
