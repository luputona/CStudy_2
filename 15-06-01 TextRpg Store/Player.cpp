#include "StdAfx.h"
#include "Player.h"


CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
}

void CPlayer::SelectJob()
{
	cout << "직업을 입력 하세요 (1.전사 2.도둑 3.마법사) : ";
	int nInput = 0;
	cin >> nInput;


	switch(nInput)
	{
	case 1:
		m_tInfo.strName = " 전사";
		m_tInfo.nHp = 150;
		m_tInfo.nAttack = 10;
		m_tInfo.nMoney = 10000;
		break;
	case 2:
		m_tInfo.strName = " 도둑";
		m_tInfo.nHp = 130;
		m_tInfo.nAttack = 8;
		m_tInfo.nMoney = 15000;
		break;
	case 3:
		m_tInfo.strName = " 마법사";
		m_tInfo.nHp = 100;
		m_tInfo.nAttack = 15;
		m_tInfo.nMoney = 10000;
		break;
	}
}

void CPlayer::Render()
{
	cout <<"==========================================\n";
	cout <<"직업 이름 : "<<m_tInfo.strName <<"\t 소지금 : "<<m_tInfo.nMoney<<endl;
	cout <<"체력 : "<<m_tInfo.nHp<<"\t 공격력 : "<<m_tInfo.nAttack<<endl;
}
