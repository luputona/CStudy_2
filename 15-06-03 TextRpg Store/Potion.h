#pragma once
#include "Item.h"

class CPotion : public CItem
{
public:
	void Render();
public:
	CPotion(void);
	CPotion::CPotion( string _strItName,int _nOption,int _nPrice,ITTYPE _eType );
	~CPotion(void);
};

