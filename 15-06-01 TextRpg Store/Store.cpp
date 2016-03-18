#include "StdAfx.h"
#include "Store.h"
#include "Player.h"
#include "Weapon.h"

CStore::CStore(void) : 
m_pPlayer(NULL)
{
	memset(m_pWeapon,0,sizeof(m_pWeapon));
}

CStore::~CStore(void)
{
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
			WeaponStore();
			break;
		case 2:
			break;
		case 3:
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

void CStore::WeaponStore()
{
	if (m_pWeapon[0] == NULL)
	{
		CreateItem();
	}

	int nInput = 0;

	while(true)
	{
		system("cls");

		m_pPlayer->Render();
		for (int i = 0; i<EA; ++i)
		{
			cout << i + 1 <<", "; 
			m_pWeapon[i]->Render();
		}
		cout << EA + 1 <<", ���ܰ�"<<endl;
		cout <<"������ ���⸦ ���� �ϼ��� : ";
		cin >> nInput;

		if ( nInput == EA + 1)
		{
			break;
		}
		if (nInput <= 3)
		{
			m_pPlayer->SetBuyMoney(m_pWeapon[nInput - 1]->GetItem().nPrice);
		}

	}

}

void CStore::CreateItem()
{
	m_pWeapon[0] = new CWeapon("�ʺ���",3,1000);
	m_pWeapon[1] = new CWeapon("�߼���",4,2000);
	m_pWeapon[2] = new CWeapon("������ ������",6,3000);


}
