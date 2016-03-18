#pragma once


class CPlayer;
class CField;
class CMonster;
class CMainGame
{
private:
	CPlayer *m_pPlayer;
	CField *m_pField;
	CMonster *m_pMonster;


public:
	void Initalize();
	void Progress();
	void Render();
	void Realese();
public:
	CMainGame(void);
	~CMainGame(void);
};

