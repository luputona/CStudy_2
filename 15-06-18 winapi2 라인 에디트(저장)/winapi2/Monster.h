#pragma once
#include "Obj.h"
class CMonster:public CObj
{
private:
	CObj* m_pPlayer;

public:
	void SetPlayer(CObj* _player){ m_pPlayer = _player; }

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render(HDC hdc);
	virtual void Release();
public:
	CMonster(void);
	~CMonster(void);
};

