#pragma once
#include "Define.h"

class CObj;
class CItem;
class CInven;
class CStore
{
private:
	CObj *m_pPlayer;
	//CItem *m_pWeapon[EA];
	//CItem *m_pArmor[EA];
	//CItem *m_pPotion[EA];
	CInven *m_pInven;

	vector<CItem*> m_vecItem[ITEND];
public:
	void Progress();
	void DrawMenu();
	//void WeaponStore(ITTYPE eType);
	void CreateItem(ITTYPE eType);
	//void ArmorStore(ITTYPE eType);
	void PotionStore(ITTYPE eType);
	void ItemStore(ITTYPE eType);

public:
	void SetPlayer(CObj *pPlayer)
	{
		m_pPlayer = pPlayer;
	}
	void SetInven(CInven *pInven)
	{
		m_pInven = pInven;
	}
public:
	CStore(void);
	~CStore(void);
};

