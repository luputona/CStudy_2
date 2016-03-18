#pragma once
#include "Define.h"

class CMainGame
{
private:
	HDC    m_hdc;


public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

