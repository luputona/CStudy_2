#pragma once
#include "Define.h"

class CItem
{
protected:
	ITEM m_tItem;
	int m_nItemType;
	
public:
	virtual void Render() = 0;
public:
	ITEM GetItem() const
	{
		return m_tItem;
	}
	int GetType() 
	{
		return m_nItemType; //포션 종류 체크
	}
public:
	CItem(void);
	CItem(string _strItemName,int _nOption, int _nPrice, ITTYPE _eType);
	~CItem(void);
};

