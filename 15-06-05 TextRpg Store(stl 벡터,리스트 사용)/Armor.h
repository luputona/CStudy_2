#pragma once
#include "Define.h"
#include "Item.h"


class CArmor : public CItem
{
public:
	void Render();

public:
	CArmor(void);
	CArmor(string _strAmName,int _nOption,int _nPrice,ITTYPE _eType);
	~CArmor(void);
};

