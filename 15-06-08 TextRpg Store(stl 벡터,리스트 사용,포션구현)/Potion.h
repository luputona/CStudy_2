#pragma once
#include "Item.h"

class CPotion : public CItem
{
public:
	virtual void Render();
public:
	CPotion(void);
	CPotion(const CPotion& rPotion);
	CPotion::CPotion( string _strItName,int _nOption,int _nPrice,ITTYPE _eType, int _nItemType );
	~CPotion(void);
};

