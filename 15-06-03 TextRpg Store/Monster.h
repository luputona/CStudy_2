#pragma once

#include "Obj.h"

class CMonster : public CObj
{
public:
	void Render();
	
public:
	CMonster(void);
	CMonster(string _strName,int _nHp,int _nAttack,int _nMoney,int _nDef);
	~CMonster(void);
};

