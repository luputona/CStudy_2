#pragma once
#include "Define.h"
class CObj;
class CMainGame
{
private:
	HDC    m_hdc;
	CObj*  m_pPlayer;
	CObj* m_pBox;
	list<LINE*> m_LineList;

public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

