#include "StdAfx.h"
#include "Inven.h"
#include "Player.h"
#include "Item.h"

CInven::CInven(void) :
m_pPlayer(NULL),
m_nCount(0)
{
	memset(m_pItemSloat,0,sizeof(m_pItemSloat));
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

		for (int i = 0; i< m_nCount; ++i)
		{
			cout << i + 1 <<". ";
			m_pItemSloat[i]->Render();
		}
		cout << m_nCount + 1 <<". 전단계"<<endl;
		cout <<"==================================\n";
		cout <<"장착할 아이템을 선택 하세요 : ";
		cin >>nInput;

		if (nInput == m_nCount + 1)
		{
			break;
		}
		else if (nInput <= m_nCount)
		{
			((CPlayer*)m_pPlayer)->SetEquipItem(m_pItemSloat[nInput - 1]);
		}
		
	}

}

void CInven::SetItem( CItem *pItem )
{
	m_pItemSloat[m_nCount] = pItem;
	m_nCount++;
}
