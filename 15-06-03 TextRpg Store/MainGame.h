#pragma once

class CPlayer;
class CField;
class CStore;
class CObj;
class CInven;
class CMainGame
{
private:
	CObj *m_pPlayer;
	CField *m_pField;
	CStore *m_pStore;
	CInven *m_pInven;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};

