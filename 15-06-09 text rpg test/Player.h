#pragma once
#include "Obj.h"
#include "Define.h"

class CPlayer : public CObj
{

public:	
	void SelectJop();
	void Render();
	virtual int Fight()
	{
		return m_tInfo.nHp -= m_tInfo.nAttack;
	}
	
	
public:
	CPlayer(void);
	CPlayer(string _strName,int _nHp,int _nAttack,int _nDef,int _nMoney);
	~CPlayer(void);
};

