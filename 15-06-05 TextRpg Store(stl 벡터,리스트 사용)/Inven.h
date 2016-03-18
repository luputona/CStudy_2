#pragma once

class CObj;
class CItem;

class CInven
{
private:
	CObj *m_pPlayer;
	CItem *m_pItemSloat[10];
	int m_nCount;
	vector<CItem*> m_pItem;
public:
	void Progress();
	void SetItem(CItem *pItem);
	void SetPlayer(CObj *pPlayer){ m_pPlayer = pPlayer; }

public:
	CInven(void);
	~CInven(void);
};

