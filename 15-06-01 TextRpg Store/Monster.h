#pragma once
#include "Define.h"
class CMonster
{
private:
	INFO m_tMonster;

public:
	INFO GetMonster()
	{
		return m_tMonster;
	}
	void SetDamage(int nAttack)
	{
		m_tMonster.nHp -= nAttack;
	}

public:
	void Render();
	
public:
	CMonster(void);
	CMonster(string _strName,int _nHp,int _nAttack,int _nMoney);

	~CMonster(void);
};

