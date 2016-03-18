#pragma once
#include "Define.h"

class CPlayer;
class CWeapon;
class CStore
{
private:
	CPlayer *m_pPlayer;
	CWeapon *m_pWeapon[EA];
public:
	void Progress();
	void DrawMenu();
	void WeaponStore();
	void CreateItem();

public:
	void SetPlayer(CPlayer *pPlayer)
	{
		m_pPlayer = pPlayer;
	}

public:
	CStore(void);
	~CStore(void);
};

