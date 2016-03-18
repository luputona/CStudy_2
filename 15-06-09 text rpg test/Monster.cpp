#include "StdAfx.h"
#include "Monster.h"


CMonster::CMonster(void)
{
}

CMonster::CMonster( string _strName,int _nHp,int _nAttack,int _nDef,int _nMoney ) :
CObj(_strName,_nHp,_nAttack,_nDef,_nMoney)
{

}


CMonster::~CMonster(void)
{
}


void CMonster::Render()
{
	cout << "ÀÌ¸§ : "<<m_tInfo.strName <<"\tÃ¼·Â : "<<m_tInfo.nHp<<endl;
	cout <<"°ø°Ý·Â : "<<m_tInfo.nAttack<<"\t¹æ¾î·Â : "<<m_tInfo.nDef<<endl;
	cout <<"¼ÒÁö±Ý : "<<m_tInfo.nMoney<<endl;
	cout <<"==============================================================\n";

}

void CMonster::CreateMonster()
{
	int nInput = 0;
	
	cout <<"1.ÃÊº¸¸÷\n";
	cout <<"2.Áß¼ö¸÷\n";
	cout <<"3.°í¼ö¸÷\n";
	cin >> nInput;

	switch(nInput)
	{
	case 1:
		m_tInfo.strName = "ÃÊº¸¸÷";
		m_tInfo.nHp = 30;
		m_tInfo.nAttack = 3;
		m_tInfo.nDef = 1;
		m_tInfo.nMoney = 1000;
		break;
	case 2:
		m_tInfo.strName = "Áß¼ö¸÷";
		m_tInfo.nHp = 60;
		m_tInfo.nAttack = 6;
		m_tInfo.nDef = 2;
		m_tInfo.nMoney = 2000;
		break;
	case 3:
		m_tInfo.strName = "°í¼ö¸÷";
		m_tInfo.nHp = 90;
		m_tInfo.nAttack = 9;
		m_tInfo.nDef = 3;
		m_tInfo.nMoney = 3000;
		break;

	}


}
