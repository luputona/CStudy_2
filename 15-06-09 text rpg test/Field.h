#pragma once
#include "Obj.h"

class CMonster;
class CPlayer;
class CField : public CObj
{
private:
	CMonster *m_pMonster;
	CPlayer *m_pPlayer;
public:	
	void Progress();
	void Render();
public:
	

public:
	CField(void);
	~CField(void);
};

