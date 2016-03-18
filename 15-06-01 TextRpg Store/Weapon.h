#pragma once
#include "Define.h"
#include "Item.h"

class CWeapon
{
private:
	ITEM m_tItem;
public:
	void Render();
public:
	ITEM GetItem()
	{
		return m_tItem;
	}
public:
	CWeapon(void);
	CWeapon(string _strItName,int _nOption,int _nPrice);
	~CWeapon(void);
};

