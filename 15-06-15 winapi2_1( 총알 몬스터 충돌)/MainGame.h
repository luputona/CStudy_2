#pragma once
#include "Define.h"

class CObj;
class CMainGame
{
private:
	HDC    m_hdc;
	CObj*  m_pPlayer;
	DWORD  m_dwTime;
	int	   m_iFps;
	TCHAR  szFps[128];
	
	OBJLIST m_BulletList;
	OBJLIST m_MonsterList;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

