#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
}

CPlayer::CPlayer( string _strName,int _nHp,int _nAttack,int _nDef,int _nMoney ) :
CObj(_strName,_nHp,_nAttack,_nDef,_nMoney)
{

}


CPlayer::~CPlayer(void)
{
}

void CPlayer::SelectJop()
{
	int nInput = 0;

	cout << "������ ������ �ּ��� <1.���� 2.���� 3.������>";
	cin >> nInput;

	switch(nInput)
	{
	case 1:
		m_tInfo.strName = "����";
		m_tInfo.nHp = 150;
		m_tInfo.nDef = 3;
		m_tInfo.nAttack = 10;
		m_tInfo.nMoney = 15000;
		break;
	case 2:
		m_tInfo.strName = "����";
		m_tInfo.nHp = 140;
		m_tInfo.nDef = 2;
		m_tInfo.nAttack = 10;
		m_tInfo.nMoney = 20000;
		break;
	case 3:
		m_tInfo.strName = "����";
		m_tInfo.nHp = 120;
		m_tInfo.nDef = 1;
		m_tInfo.nAttack = 15;
		m_tInfo.nMoney = 15000;
		break;
	}

}

void CPlayer::Render()
{
	cout << "���� : "<<m_tInfo.strName <<"\tü�� : "<<m_tInfo.nHp<<endl;
	cout <<"���ݷ� : "<<m_tInfo.nAttack<<"\t���� : "<<m_tInfo.nDef<<endl;
	cout <<"������ : "<<m_tInfo.nMoney<<endl;
	cout <<"=============================================================\n";
}
