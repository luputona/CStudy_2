#pragma once
#include "Define.h"
class CObj;
class CMainGame
{
private:
	HDC    m_hdc;
	list<CObj*> m_ObjList[OBJ_END];

public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

