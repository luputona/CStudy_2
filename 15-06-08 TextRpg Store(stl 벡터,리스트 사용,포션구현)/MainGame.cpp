#include "StdAfx.h"
#include "MainGame.h"
#include "Player.h"
#include "Field.h"
#include "Store.h"
#include "Define.h"
#include "Inven.h"

CMainGame::CMainGame(void) : 
m_pPlayer(NULL),
m_pField(NULL),
m_pStore(NULL),
m_pInven(NULL)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}

void CMainGame::Initialize()
{
	if (m_pPlayer == NULL)
	{
		m_pPlayer = new CPlayer;		
	}

	((CPlayer*)m_pPlayer)->SelectJob();

	if (m_pInven == NULL)
	{
		m_pInven = new CInven;
		m_pInven->SetPlayer(m_pPlayer);
	}
}


void CMainGame::Progress()
{
	int nInput =0;

	while(true)
	{
		system("cls");
		m_pPlayer->Render();
		cout <<"1.사냥터 2.상점 3.인벤 4.종료 : ";
		cin >>nInput;

		if (nInput == 4)
		{
			break;
		}

		switch(nInput)
		{
		case 1:
			if (m_pField == NULL)
			{
				m_pField = new CField;
				m_pField->SetPlayer(m_pPlayer);
			}
			m_pField->Progerss();
			break;
		case 2:
			if (m_pStore == NULL)
			{
				m_pStore = new CStore;
				m_pStore->SetPlayer(m_pPlayer);
				m_pStore->SetInven(m_pInven);
			}
			m_pStore->Progress();
			break;
		case 3:
			m_pInven->Progress();
			break;
		}
	}
}

void CMainGame::Render()
{

}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pStore);
	SAFE_DELETE(m_pInven);
}
