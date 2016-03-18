#pragma once

#include "Item.h"

class CWeapon : public CItem
{
public:
	void Render();

public:
	CWeapon(void);
	CWeapon(const CWeapon& rWeapon);
	CWeapon(string _strItName,int _nOption,int _nPrice,ITTYPE _eType,int _nItemType);
	~CWeapon(void);
};

