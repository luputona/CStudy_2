#pragma once

#include "Obj.h"
class CPlayer : public CObj
{
public:
	void SetHp(int nHp){ m_tInfo.nHp = nHp;}
	void SetMoney(int nMoney){m_tInfo.nMoney += nMoney;}
	void SetBuyMoney(int nMoney){m_tInfo.nMoney -= nMoney;}
public:
	void SelectJob();	
	void Render();


public:
	CPlayer(void);
	CPlayer(string _strName,int _nHp,int _nAttack,int _nMoney);
	~CPlayer(void);
};

