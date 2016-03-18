#pragma once
#include "Define.h"

class CObj
{
public:
	void SetHp(int nHp)
	{
		m_tInfo.nHp = nHp;
	}
protected:
	INFO m_tInfo;
public:
	INFO GetInfo()
	{
		return m_tInfo;
	}
	void SetDamage(int nAttack)
	{
		m_tInfo.nHp = m_tInfo.nHp + m_tInfo.nDef;
		m_tInfo.nHp = m_tInfo.nHp - nAttack;
	}
public:
	virtual void Render() = 0;
public:
	CObj(void);
	CObj(string _strName,int _nHp,int _nAttack,int _nMoney,int _nDef);
	virtual ~CObj(void);
};

