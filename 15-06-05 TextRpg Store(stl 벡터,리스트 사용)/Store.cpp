#include "StdAfx.h"
#include "Store.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Inven.h"
#include "Potion.h"

CStore::CStore(void) : 
m_pPlayer(NULL),
m_pInven(NULL)
{
	/*memset(m_pWeapon,0,sizeof(m_pWeapon));
	memset(m_pArmor,0,sizeof(m_pArmor));
	memset(m_pPotion,0,sizeof(m_pPotion));*/
}

CStore::~CStore(void)
{
	/*for (int i =0; i<EA; ++i)
	{
		SAFE_DELETE(m_pWeapon[i]);
	}
	for (int i =0; i<EA; ++i)
	{
		SAFE_DELETE(m_pArmor[i]);
	}
	for (int i = 0; i<EA; ++i)
	{
		SAFE_DELETE(m_pPotion[i]);
	}*/

	for (int i = 0; i<ITEND; ++i)
	{
		for (int j = 0;j<m_vecItem[i].size(); ++j)
		{
			SAFE_DELETE(m_vecItem[i][j]);
			
		}
		m_vecItem[i].clear();
	}
}

void CStore::Progress()
{
	int nInput = 0;

	while(true)
	{
		system("cls");
		m_pPlayer->Render();
		DrawMenu();
		cin >> nInput;

		if (nInput == 4)
		{
			break;
		}
		switch(nInput)
		{
		case 1:
			//WeaponStore(ITWEAPON);
			ItemStore(ITWEAPON);
			break;
		case 2:
			//ArmorStore(ITARMOR);
			ItemStore(ITARMOR);
			break;
		case 3:
			ItemStore(ITPOTION);
			//PotionStore(ITPOTION);
			break;
		}
	}
}

void CStore::DrawMenu()
{
	cout <<"1.���ⱸ ���� "<<endl;
	cout <<"2.�� ���� "<<endl;
	cout <<"3.����   ���� "<<endl;
	cout <<"4.���ܰ� "<<endl;
	cout <<"==================\n";
	cout <<"�޴��� �Է� �ϼ��� : ";	
}
//
//void CStore::WeaponStore(ITTYPE eType)
//{
//	if (m_pWeapon[0] == NULL)
//	{
//		CreateItem(eType);
//	}
//	int nInput = 0;
//
//	while(true)
//	{
//		system("cls");
//		m_pPlayer->Render();
//		for (int i = 0; i<EA; i++)
//		{
//			cout << i + 1<<". ";
//			m_pWeapon[i]->Render();
//		}
//		cout<< "=============================================\n";
//		cout <<EA + 1<<". ���ܰ�"<<endl;
//		cout <<"=============================================\n";
//		cout <<"������ ������ ���� : ";
//		cin >> nInput;
//		if (EA + 1 == nInput)
//		{
//			break;
//		}
//		else if (nInput <= EA)
//		{
//			if (m_pPlayer->GetInfo().nMoney >= m_pWeapon[nInput - 1]->GetItem().nPrice)
//			{
//				((CPlayer*)m_pPlayer)->SetBuyMoney(m_pWeapon[nInput - 1]->GetItem().nPrice);
//				m_pInven->SetItem(m_pWeapon[nInput - 1]);
//			}
//			else
//			{
//				cout <<"���� ���� �մϴ�. "<<endl;
//				int nKey = 0;
//				cout <<"1.���ܰ� : ";
//				cin >> nKey;
//				if (nKey == 1)
//				{
//					break;
//				}
//			}
//		}
//	}
//
//}

void CStore::CreateItem(ITTYPE eType)
{
	switch(eType)
	{
	case ITWEAPON:
		m_vecItem[ITWEAPON].reserve(3);
		m_vecItem[ITWEAPON].push_back(new CWeapon("�ʺ���",3,1000,ITWEAPON));
		m_vecItem[ITWEAPON].push_back(new CWeapon("�߼���",6,5000,ITWEAPON)); 
		m_vecItem[ITWEAPON].push_back(new CWeapon("�����",10,10000,ITWEAPON));
		break;
	case ITARMOR:
		m_vecItem[ITARMOR].reserve(3);
		m_vecItem[ITARMOR].push_back(new CArmor("�ʺ�����",2,1000,ITARMOR));
		m_vecItem[ITARMOR].push_back(new CArmor("�߼�����",4,3000,ITARMOR)); 
		m_vecItem[ITARMOR].push_back(new CArmor("�������",5,5000,ITARMOR));
		break;
	case ITPOTION:
		m_vecItem[ITPOTION].reserve(3);
		m_vecItem[ITPOTION].push_back(new CPotion("�ʱ� ����",20,500,ITPOTION));
		m_vecItem[ITPOTION].push_back(new CPotion("�߱� ����",40,1500,ITPOTION)); 
		m_vecItem[ITPOTION].push_back(new CPotion("��� ����",60,2500,ITPOTION));
		//m_pPotion[0] = new CPotion("�ʱ� ����",20,500,ITPOTION);
		//m_pPotion[1] = new CPotion("�߱� ����",40,1500,ITPOTION);
		//m_pPotion[2] = new CPotion("��� ����",60,2500,ITPOTION);
		break;
	}

}

void CStore::ItemStore( ITTYPE eType )
{
	if (m_vecItem[eType].empty())
	{
		CreateItem(eType);
	}

	int nInput = 0;

	while(true)
	{
		system("cls");
		m_pPlayer->Render();
		for (int i = 0; i<EA; i++)
		{
			cout << i + 1<<". ";
			m_vecItem[eType][i]->Render();
		}
		cout<< "=============================================\n";
		cout <<m_vecItem[eType].size() + 1<<". ���ܰ�"<<endl;
		cout <<"=============================================\n";
		cout <<"������ ������ ���� : ";
		cin >> nInput;

		if (m_vecItem[eType].size() + 1 == nInput)
		{
			break;
		}
		else if (nInput <= m_vecItem[eType].size())
		{
			if (m_pPlayer->GetInfo().nMoney >= m_vecItem[eType][nInput - 1]->GetItem().nPrice)
			{
				((CPlayer*)m_pPlayer)->SetBuyMoney(m_vecItem[eType][nInput - 1]->GetItem().nPrice);
				m_pInven->SetItem(m_vecItem[eType][nInput - 1]);
			}
			else
			{
				cout <<"���� ���� �մϴ�. "<<endl;
				int nKey = 0;
				cout <<"1.���ܰ� : ";
				cin >> nKey;
				if (nKey == 1)
				{
					break;
				}
			}
		}


	}


}

//
//void CStore::ArmorStore( ITTYPE eType )
//{
//	if (m_pArmor[0] == NULL)
//	{
//		CreateItem(eType);
//	}
//
//	int nInput = 0;
//
//	while(true)
//	{
//		system("cls");
//		m_pPlayer->Render();
//		for (int i = 0; i<EA; i++)
//		{
//			cout << i + 1<<". ";
//			m_pArmor[i]->Render();
//		}
//		cout<< "=============================================\n";
//		cout <<EA + 1<<". ���ܰ�"<<endl;
//		cout <<"=============================================\n";
//		cout <<"������ ������ ���� : ";
//		cin >> nInput;
//
//		if (EA + 1 == nInput)
//		{
//			break;
//		}
//		else if (nInput <= EA)
//		{
//			if (m_pPlayer->GetInfo().nMoney >= m_pArmor[nInput - 1]->GetItem().nPrice)
//			{
//				((CPlayer*)m_pPlayer)->SetBuyMoney(m_pArmor[nInput - 1]->GetItem().nPrice);
//				m_pInven->SetItem(m_pArmor[nInput - 1]);
//			}
//			else
//			{
//				cout <<"���� ���� �մϴ�. "<<endl;
//				int nKey = 0;
//				cout <<"1.���ܰ� : ";
//				cin >> nKey;
//				if (nKey == 1)
//				{
//					break;
//				}
//			}
//		}
//	}
//
//}
//
//void CStore::PotionStore( ITTYPE eType )
//{
//	if (m_pPotion[0] == NULL)
//	{
//		CreateItem(eType);
//	}
//
//	int nInput = 0;
//
//	while(true)
//	{
//		system("cls");
//		m_pPlayer->Render();
//		for (int i = 0; i<EA; i++)
//		{
//			cout << i + 1<<". ";
//			m_pPotion[i]->Render();
//		}
//		cout<< "=============================================\n";
//		cout <<EA + 1<<". ���ܰ�"<<endl;
//		cout <<"=============================================\n";
//		cout <<"������ ������ ���� : ";
//		cin >> nInput;
//
//		if (EA + 1 == nInput)
//		{
//			break;
//		}
//		else if (nInput <= EA)
//		{
//			if (m_pPlayer->GetInfo().nMoney >= m_pPotion[nInput - 1]->GetItem().nPrice)
//			{
//				((CPlayer*)m_pPlayer)->SetBuyMoney(m_pPotion[nInput - 1]->GetItem().nPrice);
//				m_pInven->SetItem(m_pPotion[nInput - 1]);
//			}
//			else
//			{
//				cout <<"���� ���� �մϴ�. "<<endl;
//				int nKey = 0;
//				cout <<"1.���ܰ� : ";
//				cin >> nKey;
//				if (nKey == 1)
//				{
//					break;
//				}
//			}
//		}
//	}
//}
