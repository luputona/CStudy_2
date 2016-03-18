#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "Field.h"
CMainGame::CMainGame(void) : 
m_pPlayer(NULL),
m_pField(NULL),
m_pMonster(NULL)
{
}


CMainGame::~CMainGame(void)
{
}

void CMainGame::Initalize()
{
	if (m_pPlayer == NULL)
	{
		m_pPlayer = new CPlayer;
	}
	if (m_pField == NULL)
	{
		m_pField = new CField;
	}
	if (m_pMonster == NULL)
	{
		m_pMonster = new CMonster;
	}
}

void CMainGame::Progress()
{
	int nInput = 0;
	m_pPlayer->SelectJop();
	system("cls");

	while(true)
	{
		m_pPlayer->Render();
		m_pField->Progress();
		cin >> nInput;
		if (nInput == 4)
		{
			return;
		}
		else if (nInput == 1)
		{
			while(true)
			{
				m_pMonster->CreateMonster();
				m_pMonster->Render();

				cout << "1.½Î¿î´Ù 2.µµ¸Á";
				cin >> nInput;
				if (nInput == 1)
				{	
					m_pMonster->Fight();
					m_pPlayer->Fight();					
				}
				else
				{
					break;
				}
					
			}
			

		}
		system("cls");

		//system("pause");

	}
}

void CMainGame::Render()
{

}

void CMainGame::Realese()
{

}
