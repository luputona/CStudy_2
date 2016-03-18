#pragma once

class CObj;
class CItem;

class CInven
{
private:
	CObj *m_pPlayer;
	CItem *m_pItemSloat[10];
	int m_nCount;
public:
	void Progress();
	void SetItem(CItem *pItem);
	void SetPlayer(CObj *pPlayer){ m_pPlayer = pPlayer; }

public:
	CInven(void);
	~CInven(void);
};

