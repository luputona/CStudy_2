#include "StdAfx.h"
#include "Field.h"
#include "Monster.h"
#include "Player.h"

CField::CField(void) :
m_pMonster(NULL),
m_pPlayer(NULL)
{
	if (m_pMonster == NULL)
	{
		m_pMonster = new CMonster;
	}
	if (m_pPlayer == NULL)
	{
		m_pPlayer = new CPlayer;
	}
}


CField::~CField(void)
{
}

void CField::Render()
{
	
}

void CField::Progress()
{
	int nInput = 0;
	//m_pPlayer->Render();
	cout <<"1.����� 2.���� 3.�κ� 4.���� :";
	

	
	//if (nInput == 4)
	//{
	//	return;
	//}
	//else if (nInput == 1)
	//{
	//	m_pMonster->CreateMonster();
	//	m_pMonster->Render();
	//	
	//	while(true)
	//	{
	//		cout << "1.�ο�� 2.����";
	//		cin >> nInput;
	//		system("cls");
	//		if (nInput == 1)
	//		{	
	//			m_pPlayer->Render();
	//			m_pMonster->Fight();
	//			m_pMonster->Render();
	//			
	//			if (m_tInfo.nHp == 0)
	//			{
	//				break;
	//			}
	//		}
	//		else
	//			break;
	//	}
	//	
	//	
	//}
}
