#include "StdAfx.h"
#include "Field.h"
#include "Player.h"
#include "Monster.h"

CField::CField(void) :
m_pPlayer(NULL),
m_pMonster(NULL)
{
}


CField::~CField(void)
{
}

void CField::Progerss()
{
	int nInput = 0;

	while(true)
	{
		system("cls");
		m_pPlayer->Render();
		DrawMap();
		cin >> nInput;

		if (nInput == 4)
		{
			break;
		}
		else if (nInput <= 3)
		{
			CreateMonster(nInput);
			Fight();
		}
	}
}

void CField::DrawMap()
{
	cout <<"1.�ʺ��� \n";
	cout <<"2.�߼��� \n";
	cout <<"3.����� \n";
	cout <<"4.���ܰ� \n";
	cout <<"=============================\n";
	cout <<"���� ���� �ϼ���: ";


}

void CField::CreateMonster( int nInput )
{
	switch(nInput)
	{
	case 1:
		m_pMonster = new CMonster("�ʺ���",30,3,1000);
		break;
	case 2:
		m_pMonster = new CMonster("�߼���",60,6,2000);
		break;
	case 3:
		m_pMonster = new CMonster("�����",90,9,3000);
		break;

	}
}

void CField::Fight()
{
	int nInput = 0;
	while(true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();

		cout << "1.���� 2.���� : ";
		cin >>nInput;

		if (nInput == 1)
		{
			m_pPlayer->SetDamage(m_pMonster->GetMonster().nAttack);
			m_pMonster->SetDamage(m_pPlayer->GetPlayer().nAttack);

			if (m_pPlayer->GetPlayer().nHp <= 0)
			{
				m_pPlayer->SetHp(100);
				break;
			}

			if (m_pMonster->GetMonster().nHp <= 0)
			{
				m_pPlayer->SetMoney(m_pMonster->GetMonster().nMoney);

				delete m_pMonster;
				m_pMonster = NULL;
				break;
			}
		}
		if (nInput == 2)
		{
			break;
		}
	}
}
