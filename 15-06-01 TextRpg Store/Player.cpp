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
	cout << "������ �Է� �ϼ��� (1.���� 2.���� 3.������) : ";
	int nInput = 0;
	cin >> nInput;


	switch(nInput)
	{
	case 1:
		m_tInfo.strName = " ����";
		m_tInfo.nHp = 150;
		m_tInfo.nAttack = 10;
		m_tInfo.nMoney = 10000;
		break;
	case 2:
		m_tInfo.strName = " ����";
		m_tInfo.nHp = 130;
		m_tInfo.nAttack = 8;
		m_tInfo.nMoney = 15000;
		break;
	case 3:
		m_tInfo.strName = " ������";
		m_tInfo.nHp = 100;
		m_tInfo.nAttack = 15;
		m_tInfo.nMoney = 10000;
		break;
	}
}

void CPlayer::Render()
{
	cout <<"==========================================\n";
	cout <<"���� �̸� : "<<m_tInfo.strName <<"\t ������ : "<<m_tInfo.nMoney<<endl;
	cout <<"ü�� : "<<m_tInfo.nHp<<"\t ���ݷ� : "<<m_tInfo.nAttack<<endl;
}
