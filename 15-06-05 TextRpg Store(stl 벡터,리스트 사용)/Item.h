#pragma once
#include "Define.h"

class CItem
{
protected:
	ITEM m_tItem;
	
public:
	virtual void Render() = 0;
public:
	ITEM GetItem() const
	{
		return m_tItem;
	}
public:
	CItem(void);
	CItem(string _strItemName,int _nOption, int _nPrice, ITTYPE _eType);
	~CItem(void);
};

