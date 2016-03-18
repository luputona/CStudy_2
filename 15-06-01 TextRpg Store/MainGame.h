#pragma once

class CPlayer;
class CField;
class CStore;
class CMainGame
{
private:
	CPlayer *m_pPlayer;
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

