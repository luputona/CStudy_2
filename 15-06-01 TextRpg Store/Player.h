#pragma once
#include "Define.h"
class CPlayer
{
private:
	INFO m_tInfo;
public:
	INFO GetPlayer()
	{
		return m_tInfo;
	}
	void SetDamage(int nAttack)
	{
		m_tInfo.nHp -= nAttack;
	}
	void SetHp(int nHp)
	{
		m_tInfo.nHp = nHp;
	}
	void SetMoney(int nMoney)
	{
		m_tInfo.nMoney += nMoney;
	}
	void SetBuyMoney(int nMoney)
	{
		m_tInfo.nMoney -= nMoney;
	}
public:
	void SelectJob();
	void Render();

public:
	CPlayer(void);
	~CPlayer(void);
};

