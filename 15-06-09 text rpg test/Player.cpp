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

	cout << "직업을 선택해 주세요 <1.전사 2.도적 3.마법사>";
	cin >> nInput;

	switch(nInput)
	{
	case 1:
		m_tInfo.strName = "전사";
		m_tInfo.nHp = 150;
		m_tInfo.nDef = 3;
		m_tInfo.nAttack = 10;
		m_tInfo.nMoney = 15000;
		break;
	case 2:
		m_tInfo.strName = "도적";
		m_tInfo.nHp = 140;
		m_tInfo.nDef = 2;
		m_tInfo.nAttack = 10;
		m_tInfo.nMoney = 20000;
		break;
	case 3:
		m_tInfo.strName = "법사";
		m_tInfo.nHp = 120;
		m_tInfo.nDef = 1;
		m_tInfo.nAttack = 15;
		m_tInfo.nMoney = 15000;
		break;
	}

}

void CPlayer::Render()
{
	cout << "직업 : "<<m_tInfo.strName <<"\t체력 : "<<m_tInfo.nHp<<endl;
	cout <<"공격력 : "<<m_tInfo.nAttack<<"\t방어력 : "<<m_tInfo.nDef<<endl;
	cout <<"소지금 : "<<m_tInfo.nMoney<<endl;
	cout <<"=============================================================\n";
}
