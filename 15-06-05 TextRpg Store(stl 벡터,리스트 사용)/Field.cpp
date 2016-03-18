#include "StdAfx.h"
#include "Field.h"
#include "Player.h"
#include "Monster.h"

CField::CField(void) :
m_pPlayer(NULL)
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
		m_pMonList.push_back(new CMonster("�ʺ���",30,3,1000,3));		
		break;
	case 2:
		m_pMonList.push_back( new CMonster("�߼���",60,6,2000,6));	
		break;
	case 3:
		m_pMonList.push_back(new CMonster("�����",90,9,3000,9));	
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
		m_pMonList.front()->Render();
		cout <<"1.���� 2.���� : ";
		cin >>nInput;

		if (nInput == 1)
		{
			m_pPlayer->SetDamage(m_pMonList.front()->GetInfo().nAttack);
			m_pMonList.front()->SetDamage(m_pPlayer->GetInfo().nAttack);

			if (m_pPlayer->GetInfo().nHp <= 0)
			{
				((CPlayer*)m_pPlayer)->SetHp(100);
				break;
			}

			if (m_pMonList.front()->GetInfo().nHp <= 0)
			{
				((CPlayer*)m_pPlayer)->SetMoney(m_pMonList.front()->GetInfo().nMoney);
				SAFE_DELETE(m_pMonList.front());
				m_pMonList.clear();
				break;
			}
		}
		if (nInput == 2)
		{
			break;
		}
	}
}
