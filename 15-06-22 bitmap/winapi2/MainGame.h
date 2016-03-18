#pragma once
#include "Define.h"

class CBitMap;
class CMainGame
{
private:
	HDC    m_hdc;
	INFO m_tinfo;
	vector<CBitMap*> m_BitMap;


public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

