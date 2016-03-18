#pragma once

class CPlayer;
class CField;
class CStore;
class CObj;
class CMainGame
{
private:
	CObj *m_pPlayer;
	CField *m_pField;
	CStore *m_pStore;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

