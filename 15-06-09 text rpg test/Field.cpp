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
	cout <<"1.사냥터 2.상점 3.인벤 4.종료 :";
	

	
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
	//		cout << "1.싸운다 2.도망";
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
