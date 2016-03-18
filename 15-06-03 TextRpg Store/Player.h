#pragma once

#include "Obj.h"


class CItem;
class CPlayer : public CObj
{
private:
	CItem *m_pItem[ITEND];
	CItem *m_pItem2;
	int m_nEquipAtt;
	int m_nEquipDef;

public:
	void SetHp(int nHp){ m_tInfo.nHp = nHp;}
	void SetMoney(int nMoney){m_tInfo.nMoney += nMoney;}
	void SetBuyMoney(int nMoney){m_tInfo.nMoney -= nMoney;}
	void SetEquipItem(CItem *pItem);
public:
	void SelectJob();	
	void Render();


public:
	CPlayer(void);
	CPlayer(string _strName,int _nHp,int _nAttack,int _nMoney, int _nDef);
	~CPlayer(void);
};

