#pragma once
#include "Define.h"

class CItem
{
protected:
	ITEM m_tItem;
	
public:
	void Render();
public:
	ITEM GetItem()
	{
		return m_tItem;
	}
public:
	CItem(void);
	CItem(string _strItemName,int _nOption, int _nPrice);
	~CItem(void);
};

