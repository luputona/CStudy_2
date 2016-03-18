#pragma once
#include "Define.h"
#include "Item.h"


class CAmor : public CItem
{
private:
	ITEM m_tAmor;
public:
	void Render();
public:
	ITEM GetAmor()
	{
		return m_tAmor; 
	}
public:
	CAmor(void);
	CAmor(string _strAmName,int _nOption,int nPrice);
	~CAmor(void);
};

