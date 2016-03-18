#pragma once
#include "Define.h"

class CObj
{
protected:
	INFO m_tInfo;
public:
	virtual int Fight()
	{
		return m_tInfo.nHp -= m_tInfo.nAttack;
	}

public:
	CObj(void);
	CObj(string _strName,int _nHp,int _nAttack, int _nDef,int _nMoney);
	~CObj(void);
};

