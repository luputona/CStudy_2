#pragma once
#include "Define.h"
class CObj;
class CItem;

class CInven
{
private:
	CObj *m_pPlayer;
	list<CItem*> m_pItemsloat;
	int m_nPotionCnt[ITEND];
	multimap<int,CItem*> m_MapSloat;
	
public:
	void AddItem(CItem *pItem,ITTYPE eType);
	void SetItem(CItem *pItem,int nMaxSize, ITTYPE eType);
	void MapSort();
public:
	void Progress();
	void SetPlayer(CObj *pPlayer){ m_pPlayer = pPlayer; }

public:
	CInven(void);
	~CInven(void);
};

