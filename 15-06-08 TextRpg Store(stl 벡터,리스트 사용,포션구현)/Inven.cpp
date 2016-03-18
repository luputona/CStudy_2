#include "StdAfx.h"
#include "Inven.h"
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

CInven::CInven(void) :
m_pPlayer(NULL)
{
	//memset(m_pItemSloat,0,sizeof(m_pItemSloat));
	memset(m_nPotionCnt,0,sizeof(m_nPotionCnt));
}


CInven::~CInven(void)
{
}

void CInven::Progress()
{
	int nInput = 0;
	while(true)
	{
		system("cls");
		m_pPlayer->Render();

		int nIndex = 0;
		for (list<CItem*>::iterator iter = m_pItemsloat.begin(); iter != m_pItemsloat.end(); ++iter,++nIndex)
		{
			cout << nIndex + 1<<". ";
			(*iter)->Render(); //인벤 내부 출력

			if ((*iter)->GetItem().eType == ITPOTION)
			{
				cout <<"포션의 갯수 : "<<m_nPotionCnt[(*iter)->GetType()] << endl; //자기 종류에 누적 출력
			}
		}

		cout << nIndex + 1 <<". 전단계"<<endl;
		cout <<"==================================\n";
		cout <<"장착할 아이템을 선택 하세요 : ";
		cin >>nInput;

		if (nInput == nIndex + 1)
		{
			break;
		}
		else if (nInput == 0 || nInput >= nIndex + 2)
		{
			continue;
		}
		else
		{
			list<CItem*>::iterator iter = m_pItemsloat.begin();
			for (int i = 0; i< nInput - 1; ++i)
			{
				++iter;
			}
			((CPlayer*)m_pPlayer)->SetEquipItem(*iter);
			if ((*iter)->GetItem().eType == ITPOTION)
			{
				if (m_nPotionCnt[(*iter)->GetType()] > 1)
				{
					--m_nPotionCnt[(*iter)->GetType()];
				}
				else
				{
					m_nPotionCnt[(*iter)->GetType()] = 0;
					SAFE_DELETE(*iter);
					iter = m_pItemsloat.erase(iter);
				}
			}
			else
			{
				SAFE_DELETE(*iter);
				iter = m_pItemsloat.erase(iter);
			}
		}		
	}
}

void CInven::AddItem( CItem *pItem,ITTYPE eType )
{
	CItem* ppItem = NULL;

	switch(eType)
	{
	case ITWEAPON:
		ppItem = new CWeapon(*((CWeapon*)pItem) ); //복사생성을해서 넣기위해 다운캐스팅해서 복사 
		SetItem(ppItem,WEAPONT_EA,eType);
		break;
	case ITARMOR:
		ppItem = new CArmor(*((CArmor*)pItem) );
		SetItem(ppItem,ARMOR_EA,eType);
		break;
	case ITPOTION:
		ppItem = new CPotion(*((CPotion*)pItem) );
		SetItem(ppItem,POTION_EA,eType);
		break;

	}
}

void CInven::SetItem( CItem *pItem,int nMaxSize, ITTYPE eType )
{
	
	if (pItem->GetItem().eType != ITPOTION)
	{
		m_pItemsloat.push_back(pItem);
	}
	else
	{
		if (m_nPotionCnt[pItem->GetType()] == 0) //포션종류에 대한 물약 갯수가 0일경우 
		{
			m_pItemsloat.push_back(pItem);
			++m_nPotionCnt[pItem->GetType()];
		}
		else if (m_nPotionCnt[pItem->GetType()] < nMaxSize) // 물약갯수가 적을경우  
		{
			++m_nPotionCnt[pItem->GetType()];
		}
		else
		{
			m_pItemsloat.push_back(pItem);
			++m_nPotionCnt[pItem->GetType()];			
		}
	}
}

void CInven::MapSort()
{


}
