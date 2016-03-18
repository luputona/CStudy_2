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
	cout <<"1.무기구 상점 "<<endl;
	cout <<"2.방어구 상점 "<<endl;
	cout <<"3.포션   상점 "<<endl;
	cout <<"4.전단계 "<<endl;
	cout <<"==================\n";
	cout <<"메뉴를 입력 하세요 : ";

	
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
		cout << EA + 1 <<", 전단계"<<endl;
		cout <<"구매할 무기를 선택 하세요 : ";
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
	m_pWeapon[0] = new CWeapon("초보검",3,1000);
	m_pWeapon[1] = new CWeapon("중수검",4,2000);
	m_pWeapon[2] = new CWeapon("영겁의 서리검",6,3000);


}
