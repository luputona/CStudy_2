#pragma once
#include "Obj.h"
#include "Define.h"


class CMonster : public CObj
{

public:
	void CreateMonster();
	void Render();
	virtual int Fight()
	{
		return m_tInfo.nHp -= m_tInfo.nAttack;
	}
	
public:
	CMonster(void);
	CMonster( string _strName,int _nHp,int _nAttack,int _nDef,int _nMoney );
	~CMonster(void);
};

