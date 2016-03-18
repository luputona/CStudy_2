#pragma once
#include "Define.h"

class CObj;
class CItem;
class CStore
{
private:
	CObj *m_pPlayer;
	CItem *m_pWeapon[EA];
	CItem *m_pArmor[EA];
public:
	void Progress();
	void DrawMenu();
	void WeaponStore(ITTYPE eType);
	void CreateItem(ITTYPE eType);
	void ArmorStore(ITTYPE eType);

public:
	void SetPlayer(CObj *pPlayer)
	{
		m_pPlayer = pPlayer;
	}

public:
	CStore(void);
	~CStore(void);
};

